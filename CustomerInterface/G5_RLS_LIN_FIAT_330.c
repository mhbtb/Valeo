/*************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : RLS_LINST.c

Documentation reference   : Software Requrement Specification
Overview of the component : interface to the electronics

Evolution of the component : see PVCS Version control system

Initials   date   modification

*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  NAME Description                                       */
/*----------------------------------------------------------------------------*/
/* 07Apr08   VCO_005     FS   Make use of VDR_175 to do LSAlgo ReInit*/
/* 17Apr08   VDR_197     FS   Make use of AUDI B8 LIN Interface Sensitivity treatment as template, 
                              otherwise flashing of Headlamps can appear*/
/* 02.12.2014  VDR_199  NB  Fiat: Adaptation of Gen5.6 software to Fiat LIN interface */
/* 15.01.2015  VCO_208  NB  Fiat:Rain sensor shall be active all the time after ignition, 
                            but transmitt info in LIN only if rain sensor is active */
/*20.03.2015 VCO_232  NB  FCA:Develop common software for FCA group*/
/*12.05.2015 VDR_878  NB  ADC Error shall be removed from the LS error and included only for RS_error */
/*06.08.2015 VDR_873  NB  FCA:Wrong Dewpoint calculation when a relative humidity range 0..3 and temperature 0..3 set */
/*06.08.2015 VDR_873  NB  FCA:implement Diagnostic service for FCA project */
/*06.08.2015 VCO_262  NB  FCA:Remove duplicate code */
/*28.08.2015 VCO_268  SP  Cleanup the LIN modules  */
/*02.10.2015 VDR_911    SP      HammingErr shld be part of RS_Error/LS_Error and shld not be used for Active Err*/
/*12.05.16   VCO_325    NB      FCA:Integration VCO to merge the changes from Audi 002 baseline to FCA 004 baseline*/
/*12.05.16   VDR_975    NB      FCA:Error Counter Debounce is not used to switch off light*/
/*30.05.16   VDR_983    NB      Sporadic illegale instruction reset in the startup */
/*26.07.16   VDR_985    NB      FCA:Use regulation 48 bit to switch the the light ON */
/*16.08.16   VCO_440    NB      FCA:Adapt Light sensitiviy matrix as in Generic implementation */
/*16.08.16   VDR_1055   NB      FCA: Signal "HumSns_Int_flt" shall be set in case of Humidity temerature failure */
/*04.04.18   VDR_1065    HB      Fix tunnel delay for FIAT 330                              */
/*************************************************************************
**                   Common and module include-file                     **
**************************************************************************/

/* PRQA S 3138 EOF */ /* <<needed at this level for better debugging>> */
/* PRQA S 2217 EOF */ /* <<line lenth exceeds 120 are OK >> */
/* PRQA S 5900,5560,5565 EOF */ /* <<coding rules, are OK >> */

#include "ior5f109be.h"
#include "G5_projectDefs.h"

#include "G5_Appli_main.h"
#define _RLS_LIN_c_         //Define for Single include of Global Header rls_linst.h
#include "G5_lininclude.h"
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef  _RLS_LIN_c_
/*************************************************************************
**                   Other files included                               **
**************************************************************************/
#include "G5_rs_def.h"
#include "G5_Appli_lowinit.h"
#include "G5_io.h"
#include "G5_Appli_Timer.h"
#include "G5_check_sr.h"
#include "G5_rainsens.h"
#include "G5_diagnose.h"
#include "G5_E2Handler.h"
#include "G5_flashe2.h"
#include "G5_DippedBeam_sr.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_spi_sr.h"
#include "G5_IRlight.h"
#include "G5_HumTemp.h"

#ifdef ASIC_TEST
#include "G5_AsicFramesLin.h"
#endif //ASIC_TEST

#define RAINSENSOR_ALWAYS_ACTIVE

#define cb_WIPER_OUT_SIDE_PARK     0
#define cb_WIPER_IN_SIDE_PARK      1

#define cb_SOLAR_MAX_mg          (240)
#define cb_DEWPOINT_MAX_mg       (250)     /*VDR_154 change of max value from 1022 to 1000*/
#define cb_INIT                  (252)
#define cb_VALUE_EXCEEDS_LIMIT   (253)
#define cb_ERROR                 (254) 
#define cb_SNA                   (255) 

#define cw_INIT_1                  (2044)
#define cw_VALUE_EXCEEDS_LIMIT_1   (2045)
#define cw_ERROR_1                 (2046) 
#define cw_SNA_1                   (2047) 
#define cw_DEWPOINT_MAX_1_mg       (1250)     /*VDR_154 change of max value from 1022 to 1000*/


#define cw_IR_LIGHT_MAX_mg       (0x7FFFU)
#define cw_FW_LIGHT_MAX_mg       (0x7FFFU)
#define cw_AMB_LIGHT_MAX_mg      (0x7FFFU)
#define cw_INIT                  (0xFFFCU)
#define cw_VALUE_EXCEEDS_LIMIT   (0xFFFDU)
#define cw_ERROR                 (0xFFFEU)

#define cw_CLEARWIPE_DELAY_s 400 /* 4 seconds (400*10ms)*/

/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/
//extern unsigned char rub_WiperMotorTime;

 static word rw_WipeCommandTimOut_mg;                     //timout for requested wipe
/* PRQA S 3408,3218 4 */ /* <<needed at this level for better debugging>> */
const byte cab_WiperMotorRunntime_mg[8] = {142,142,133,125,117,111,105,100}; //simulierte Wischzeit bei LSS aus
static const byte cab_PotistageMapping_mg[8] = {4,5,6,7,3,2,1,0}; /*mapping for LightSensorPotistages from EEPROM (3bit) rb_LightSensorCoding_g!*/
const word caw_DeppressedParkDelayTable_g[4] = {500,1000,1500,2000};

#ifdef _INITWITHDEFAULT_
const byte LinMsgDefault_FSs_01[8]  = {0x00,0xFC,0x00,0xFC,0x00,0x00,0xFF,0xFF}; 		/* id: 0x029 "FSs_01" */
const byte LinMsgDefault_RLSs_01[8] = {0x00,0xD0,0xF0,0xFE,0xFE,0xEF,0xFF,0xFF}; 		/* id: 0x023 "RLSs_01" */
#endif

#define cb_FOUR_SECOND_DELAY_mg   25
#define cw_CLEARWIPE_DELAY_s 400 // 4 seconds (400*10ms)
#define CW_LIN1_3_IDLE_TIMOUT 130
#define CW_LIN2_0_IDLE_TIMOUT 400
#define cb_DEPRESSED_PARK_DEBOUNCE_s 18


/* PRQA S 3408,3218 1 */ /* <<needed at this level for better debugging>> */
static const byte  cab_PotistageMap_g[8] = {0,1,2,3,4,5,6,6};       /*mapping of RainSensorSensitivitys*/

//#define cw_IR_LIGHT_TO_SCALING_FAKT_FIAT  2880


/******************************************************************************/
/*                      Definition of exported variables                      */
/******************************************************************************/

/*************************************************************************
**                   Declaration of local module Functions              **
*************************************************************************/

#define CB_BRIGHTNESS_MAX_VALUE_s 7   //Max Value for Helligkeit
#define cb_BRIGHTNESSSCALING_FAKT_s 3 //Scaling fakt x  2^x


/* PRQA S 3218,3408 1 */ /* <<needed at this level for better debugging>> */
static byte rb_AnyErrorCounterDebounce_mg;


//---------------------------------------------------------------------------------------
/**************************************************************************
Syntax   : void  GetLeWWS(void)
Object   : GetLeWWS()
Parameters : none
Return  : none
Calls   : in main.c cyclic 10ms
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : schreibt die Eingangsdaten vom Schaltermoduls von den
entsprechenden Puffern des Vector Bus Treiber in die RAM-Zellen und
setzt die internen Daten gemaess SRS um.
**************************************************************************/
void GetLeWWS(void)
{
  
  static byte rb_init_counter;
  static byte rb_parkpositioncounter_s;
  byte rb_Empfindlichkeit_LS_l;
  
  rbi_LINRainsensorDisabled_g = FALSE;
  
  if (l_flg_tst_ComToRLS())               //Master Request?
  {
    // l_flg_clr_ComToRLS();                 Clearing flag is done at the end of the function/*delete flag */
    rbi_RLSDCfgData_ComToRLS_g = TRUE;
    rb_LIN_SensitivityShift_g = 7;       /*adaptation Variable for sensitivity factor*/
    rw_NoCommunicationCounter_g = 0;        // reset no communication counter
    rbi_ConnectedToMaster_g = TRUE;
    rbi_Ignition_g = TRUE;
    /* set rbi_AutomaticWipingMode_g to TRUE instead of l_bool_rd_RainSensorActive(), because Rainsensor alwyas active */
    if((rb_Proj_Specific_config_g & 0x01) == 0x01) /* Bit 0 used for rain configuration*/
    {
      rbi_AutomaticWipingMode_g = TRUE; /* Rain sensor diodes active all the time*/
    }
    else
    {
      rbi_AutomaticWipingMode_g = l_bool_rd_RainSensorActive_RLS(); /* Rain sensor diodes active from LIN */
    }
    if (rb_init_counter >= 3)  /*VDR_265*/  /* delete debounce because it causes a switch on delay of 2s after reset*/
    {
      rbi_LS_reinit_init_g = 0;
    }
    else
    {
      rb_init_counter++;
    }
    if (rbi_LightSensorActiveFromLin_mg == 1)
    {
      rbi_LS_reinit_g=0;        /*Reset Flag to Init Darkstart mode*/
    }
    else if ((rbi_LightSensorActiveFromLin_mg == 0)&&(l_bool_rd_LightSensorSelected_RLS()==0)&&(rbi_LightSensorActive_g > 0 )&&(rbi_EEPROMLoad_g==0)&&(rbi_LS_reinit_init_g==0)) /*Wait on Reset for LightSensorSelcted()*/
    {
      rbi_LS_reinit_g=1;        /*Init Darkstart mode*/
    }
    else 
    {
      /*This else for the case rbi_LightSensorActiveFromLin_mg == 0 UND l_bool_rd_LightSensorSelected == 1 
      --> LightSensorAlgo should run for this case*/
      rbi_LS_reinit_g=0;        /*Reset Flag to Init Darkstart mode*/
    }
    
    if((rb_Proj_Specific_config_g & 0x02) == 0x02) /* Bit 1 used for light configuration*/
    {
      rbi_LightSensorActiveFromLin_mg = TRUE; /* LIGHT SENSOR ALWAYS ACTIVE */
    }
    else
    {
      rbi_LightSensorActiveFromLin_mg = l_bool_rd_LightSensorActive_RLS(); /* Light sensor active from LIN */
    }
 
    /*Speed*/
    if ((l_u16_rd_VehicleSpeed_RLS()>>4) > 0xFF)
    {
      rb_speed_in_kmh_g  = 255;                            // set speed to (255 km/h)
    }
    else
    {
      rb_speed_in_kmh_g  = (byte) (l_u16_rd_VehicleSpeed_RLS()>>4);

      if(rb_speed_in_kmh_g>=10)
      {
        rbi_speedWasAbove10kmh_g = TRUE; /* for windshield calibration */
      }
    }
    /*Washing*/
    if (l_bool_rd_WiperWasherActive_RLS()  == TRUE)   // Waschpumpe aktiv?
    {
      rbi_WashingActive_g = TRUE;             // Washing aktiv bit setzen
    }
    else if (rbi_ParkPosition_g == cb_WIPER_IN_SIDE_PARK)          // In Parkposition ?
    {
      rbi_WashingActive_g = FALSE;              // Clear Washing aktive bit
    }
    else
    {
    }
    
    if (l_u8_rd_SelectedSensitivityL_RLS()>6)     /*  CHANGE FIAT_330*/
    {
      rb_Empfindlichkeit_LS_l = 6;
    }
    else
    {
      rb_Empfindlichkeit_LS_l = l_u8_rd_SelectedSensitivityL_RLS();
    }
    
  if((cab_PotistageMapping_mg[rb_LightSensorCoding_g]+rb_Empfindlichkeit_LS_l)>3)
  {
    rb_LSPotiStage_g = (cab_PotistageMapping_mg[rb_LightSensorCoding_g]+rb_Empfindlichkeit_LS_l)-3;
    if(rb_LSPotiStage_g>7)
    {
      rb_LSPotiStage_g=7;
    }
  }
  else
  {
    rb_LSPotiStage_g = 0;
  }
 
    /*RSEmpfindlichkeit*/
    rb_PotiStageFromBox_g = cab_PotistageMap_g [l_u8_rd_SelectedSensitivityR_RLS()];
    
    /*Parkposition*/
    if (l_bool_rd_WiperInPark_RLS()== FALSE)        /* In Parklagensignal ?*/
    {
      rbi_RealParkContact_g = cb_WIPER_IN_SIDE_PARK;
    }
    else
    {
      rbi_RealParkContact_g = cb_WIPER_OUT_SIDE_PARK;
    }
  }
  else if (l_flg_tst_ComToHRLS())  // Master Request from HRLS frame
  {
    //l_flg_clr_ComToHRLS();                 /*deletion of flag will be done in GetLsWWS() */
    rbi_RLSDCfgData_ComToRLS_g = TRUE;
    rb_LIN_SensitivityShift_g = 7;       /*adaptation Variable for sensitivity factor*/
    rw_NoCommunicationCounter_g = 0;        // reset no communication counter
    rbi_ConnectedToMaster_g = TRUE;
    rbi_Ignition_g = TRUE;
    if((rb_Proj_Specific_config_g & 0x01) == 0x01) /* Bit 0 used for rain configuration*/
    {
      rbi_AutomaticWipingMode_g = TRUE; /* Rain sensor diodes active all the time*/
    }
    else
    {
      rbi_AutomaticWipingMode_g = l_bool_rd_RainSensorActive_HRLS(); /* Rain sensor diodes active from LIN */
    }
    if (rb_init_counter >= 3)  /*VDR_265*/  /* delete debounce because it causes a switch on delay of 2s after reset*/
    {
      rbi_LS_reinit_init_g = 0;
    }
    else
    {
      rb_init_counter++;
    }
    if (rbi_LightSensorActiveFromLin_mg == 1)
    {
      rbi_LS_reinit_g=0;        /*Reset Flag to Init Darkstart mode*/
    }
    else if ((rbi_LightSensorActiveFromLin_mg == 0)&&(l_bool_rd_LightSensorSelected_HRLS()==0)&&(rbi_LightSensorActive_g > 0 )&&(rbi_EEPROMLoad_g==0)&&(rbi_LS_reinit_init_g==0)) /*Wait on Reset for LightSensorSelcted()*/
    {
      rbi_LS_reinit_g=1;        /*Init Darkstart mode*/
    }
    else 
    {
      /*This else for the case rbi_LightSensorActiveFromLin_mg == 0 UND l_bool_rd_LightSensorSelected == 1 
      --> LightSensorAlgo should run for this case*/
      rbi_LS_reinit_g=0;        /*Reset Flag to Init Darkstart mode*/
    }
    
    if((rb_Proj_Specific_config_g & 0x02) == 0x02) /* Bit 1 used for light configuration*/
    {
      rbi_LightSensorActiveFromLin_mg = TRUE; /* LIGHT SENSOR ALWAYS ACTIVE */
    }
    else
    {
      rbi_LightSensorActiveFromLin_mg = l_bool_rd_LightSensorActive_HRLS(); /* Light sensor active from LIN */
    }
 
    /*Speed*/
    if ((l_u16_rd_VehicleSpeed_HRLS()>>4) > 0xFF)
    {
      rb_speed_in_kmh_g  = 255;                            // set speed to (255 km/h)
    }
    else
    {
      rb_speed_in_kmh_g  = (byte) (l_u16_rd_VehicleSpeed_HRLS()>>4);

      if(rb_speed_in_kmh_g>=10)
      {
        rbi_speedWasAbove10kmh_g = TRUE; /* for windshield calibration */
      }
    }
    /*Washing*/
    if (l_bool_rd_WiperWasherActive_HRLS()  == TRUE)   // Waschpumpe aktiv?
    {
      rbi_WashingActive_g = TRUE;             // Washing aktiv bit setzen
    }
    else if (rbi_ParkPosition_g == cb_WIPER_IN_SIDE_PARK)          // In Parkposition ?
    {
      rbi_WashingActive_g = FALSE;              // Clear Washing aktive bit
    }
    else
    {
    }
    
    if (l_u8_rd_SelectedSensitivityL_HRLS()>6)     /*  CHANGE FIAT_330*/
    {
      rb_Empfindlichkeit_LS_l = 6;
    }
    else
    {
      rb_Empfindlichkeit_LS_l = l_u8_rd_SelectedSensitivityL_HRLS();
    }
    
  if((cab_PotistageMapping_mg[rb_LightSensorCoding_g]+rb_Empfindlichkeit_LS_l)>3)
  {
    rb_LSPotiStage_g = (cab_PotistageMapping_mg[rb_LightSensorCoding_g]+rb_Empfindlichkeit_LS_l)-3;
    if(rb_LSPotiStage_g>7)
    {
      rb_LSPotiStage_g=7;
    }
  }
  else
  {
    rb_LSPotiStage_g = 0;
  }
 
    /*RSEmpfindlichkeit*/
    rb_PotiStageFromBox_g = cab_PotistageMap_g [l_u8_rd_SelectedSensitivityR_HRLS()];
    
    /*Parkposition*/
    if (l_bool_rd_WiperInPark_HRLS()== FALSE)        /* In Parklagensignal ?*/
    {
      rbi_RealParkContact_g = cb_WIPER_IN_SIDE_PARK;
    }
    else
    {
      rbi_RealParkContact_g = cb_WIPER_OUT_SIDE_PARK;
    }
   }
  
  
  else  /*keine neue Master Nachricht!*/
  {
    if (rw_NoCommunicationCounter_g < CW_LIN2_0_IDLE_TIMOUT)  // No Communication Counter Higher than 250
    {
      rw_NoCommunicationCounter_g ++;     // increment No Communication Counter
      rbi_GotoSleep_g = FALSE;         // Was Connected to Master
    }
    else
    {
      rbi_GotoSleep_g = TRUE;         // Was Connected to Master
      rbi_Ignition_g = 0;             // clear rbi_Ignition_g
      rbi_ASICStandByModeRequest_g = 0;   // Set Request for Standby Mode
      rbi_ConnectedToMaster_g = 0;         // clear connected to Master
    }
    
  }
  if (rbi_RealParkContact_g == cb_WIPER_IN_SIDE_PARK)        // In Parklagensignal ?
  {
    if (rbi_ParkPosition_g == cb_WIPER_OUT_SIDE_PARK )
    {
      rb_parkpositioncounter_s=0;                 /* Parkpositioncounter zurucksetzen */
    }
    else if (rb_parkpositioncounter_s < 255)
    {
      rb_parkpositioncounter_s++;
    }
    else
    {
    }
    rbi_ParkPosition_g = cb_WIPER_IN_SIDE_PARK;                     // Parkposition True
  }
  else
  {
    if (rb_parkpositioncounter_s>8)            /* Parkpositioncounter grosser 8 */
    {
      rbi_ParkPosition_g = cb_WIPER_OUT_SIDE_PARK;                 /*delete bit for Parkposition */
    }
    else
    {
      rb_parkpositioncounter_s++;             // inkrementiere Parkpositionscounter
    }
  }
  
  /* start of Removal of wiper speed command if wiper motor doesnot move */
  
  if ((rb_WiperSpeed_g > 0)&&(rbi_RealParkContact_g == cb_WIPER_IN_SIDE_PARK))
  {
    
    if (rw_WipeCommandTimOut_mg <= cw_CLEARWIPE_DELAY_s)
    {
      rw_WipeCommandTimOut_mg ++;                /* reset Timout if wiper motor wants not wipe */
    }
    else
    {
      rb_LimitMemomryNoWiperReaction_g = TRUE;
    }
    
    
  }
  
  
  if(((l_bool_rd_RainSensorActive_RLS() == FALSE )&& (rbi_ParkPosition_g == cb_WIPER_IN_SIDE_PARK)) && (TRUE==l_flg_tst_ComToRLS())||
     ((l_bool_rd_RainSensorActive_HRLS() == FALSE )&& (rbi_ParkPosition_g == cb_WIPER_IN_SIDE_PARK)) && (TRUE==l_flg_tst_ComToHRLS())||    
     (rw_WipeCommandTimOut_mg > cw_CLEARWIPE_DELAY_s))
  {
    if((rb_WiperSpeed_g > 0)||(rbi_ParkPosition_g == cb_WIPER_OUT_SIDE_PARK))
    {
      if(rb_parkpositioncounter_s>10)            /* Parkpositioncounter groesser 10 */
      {
        rbi_ParkPosition_g = cb_WIPER_OUT_SIDE_PARK;                 /* loesche bit fuer Parkposition */
      }
      rb_parkpositioncounter_s++;             /* inkrementiere Parkpositionscounter */
    }
    
    if(rb_parkpositioncounter_s > (140))/* Time to reset the wiper speed command */
    {
      rw_WipeCommandTimOut_mg = 0;
      rbi_ParkPosition_g = cb_WIPER_IN_SIDE_PARK;               /* loesche bit fuer Parkposition */
      rb_parkpositioncounter_s = 0;            
    }
  }
  else
    
  {
    if((rbi_ParkPosition_g == cb_WIPER_OUT_SIDE_PARK )&&(rb_WiperSpeed_g > 0))
    {
      rbi_WiperStarted_g = TRUE;
    }
    
    if(rbi_ParkPosition_g == cb_WIPER_IN_SIDE_PARK )        /* In Parklagensignal ? */
    {
      if(rbi_ParkPosition_g == cb_WIPER_OUT_SIDE_PARK)
      {
        rb_parkpositioncounter_s=0;                 /* Parkpositioncounter zuruecksetzen */
      }
      else
      {
        if(rb_parkpositioncounter_s < 255)
        {
          rb_parkpositioncounter_s++;
        }
      }
      rbi_ParkPosition_g = TRUE;                     /* Parkposition True */
      if (rub_IntermDelayTime > 5)       /* clear option for Wiper Started Flag! */
      {
        rbi_WiperStarted_g = FALSE;
      }
    }
    else
    {
      rb_LimitMemomryNoWiperReaction_g = FALSE;
      rbi_WiperStarted_g = FALSE;
      rw_WipeCommandTimOut_mg = 0;                /* reset Timout if wiper motor wants not wipe */
      if(rb_parkpositioncounter_s>7)            /* Parkpositioncounter groesser 8 */
      {
        rbi_WiperStarted_g = FALSE;
        rbi_ParkPosition_g = cb_WIPER_OUT_SIDE_PARK;                 /* loesche bit fuer Parkposition */
      }
      else
      {
        rb_parkpositioncounter_s++;             /* inkrementiere Parkpositionscounter */
      }
    }
  }
  l_flg_clr_ComToRLS();
  
  /* End of Removal of wiper speed command if wiper motor doesnot move */
}
/**************************************************************************
Syntax   : void  GetLsWWS(void)
Object   : GetLsWWS()
Parameters : none
Return  : none
Calls   : in main.c cyclic 10ms
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : schreibt die Eingangsdaten vom Wischermotorin von den
entsprechenden Puffern des Vector Bus Treiber in die RAM-Zellen und
setzt die internen Daten gemaess SRS um.
**************************************************************************/
void GetLsWWS(void)
{

  byte rb_550nm_Transmission_local;

  byte rb_880nm_Transmission_local;
  
 if(l_flg_tst_RLSDCfgData() || l_flg_tst_ComToHRLS() )
  {
    rbi_RLSDCfgData_recieved_g = TRUE;
    
    rw_NoCommunicationCounter_g = 0; // reset no communication counter
    rbi_ConnectedToMaster_g = 1; // set connected to Master
    
    rbi_Ignition_g = TRUE;
    
    
    if (l_flg_tst_RLSDCfgData())
    {
      l_flg_clr_RLSDCfgData();
    rb_550nm_Transmission_local = 2+(l_u8_rd_FW_550nmTransmission_RLSCfg()*7);

    rb_880nm_Transmission_local = 2+(l_u8_rd_IR_880nmTransmission_RLSCfg()*7);
    
    }
    
    else 
    {
     l_flg_clr_ComToHRLS();
     rb_550nm_Transmission_local = 2+(l_u8_rd_Transmission_550nm_ComHRLS()*7);

     rb_880nm_Transmission_local = 2+(l_u8_rd_Transmission_880nm_ComHRLS()*7);
    
    }
    
    //Check, if LIN-transmission values are invalid
    if((rb_880nm_Transmission_local >=CB_MIN_880NM_TRANSMISSION)&&(rb_880nm_Transmission_local <=CB_MAX_880NM_TRANSMISSION) &&\
      (rb_550nm_Transmission_local >=CB_MIN_550NM_TRANSMISSION)&&(rb_550nm_Transmission_local <=CB_MAX_550NM_TRANSMISSION))

        
    {
      
      if(rb_550nm_Transmission_local > 14)
      {
        rb_550nm_Transmission_local = ((rb_550nm_Transmission_local - 14) / 5);
        
        if(rb_550nm_Transmission_local > 15)
        {
          rb_550nm_Transmission_local = 15;
        }
      }
      else
      {
        rb_550nm_Transmission_local = 0;
      }
      
      if(rb_880nm_Transmission_local > 14)
      {
        rb_880nm_Transmission_local = (((rb_880nm_Transmission_local - 14) / 5));
        
        if(rb_880nm_Transmission_local > 15)
        {
          rb_880nm_Transmission_local = 15;
        }
        rb_880nm_Transmission_local = (rb_880nm_Transmission_local<<4); 
      }
      else
      {
        rb_880nm_Transmission_local = 0;
      }
      
      if((rb_Kodierbyte2_g != (rb_550nm_Transmission_local | rb_880nm_Transmission_local)) && ((rbi_EEPROMBytesToWrite_g == FALSE)||(rbi_EEPROMBytesWritten_g == TRUE)))
      {
        rab_EEPROM_Bytes_toWrite_g[0] = (rb_550nm_Transmission_local | rb_880nm_Transmission_local);
        rw_EEPROM_Address_to_Write_g = cw_EEPROM_CODING_ADDRESS_g; /*set adress to write*/
        rb_I2C_EEPROM_bytesToWrite_g = 1;         /*set number of bytes to 1*/
        rbi_EEPROMBytesToWrite_g = TRUE;
        rbi_EEPROMBytesWritten_g = FALSE;
      }
    }
  }
}

/**************************************************************************
Syntax   : void  CopyRLSData(void)
Object   : CopyRLSData()
Parameters : none
Return  : none
Calls   : in main.c
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : schreibt die Ausgangsdaten des Sensors in den
Ausgangsdatenpuffer des Vector Bus Treiber und setzt die internen Daten
gemaess SRS um.
**************************************************************************/
void CopyRLSData(void)
{
  
  static byte rb_debounce_LSselected_OFFtoON;
  static byte rb_debounce_LSselected_ONtoOFF;
  static byte rb_sendWiperSpeed_s;
  static byte rb_InitLightValCnt_l=100;
  byte rb_TempLightOn_l;
  
  Check_StartupActiveErrors();
  
  
  
  // copy transmit data
  l_bool_wr_KeepAliveRLS(FALSE); /* this msg exists only for ComToRLS */
  
  /*   l_u8_wr_TwilightSensorLevel((rw_ForwLightWideHigh256MFast_mg >> 8)); */ 
  /*Due to FIAT dbc changes, TwilightLevel is not sent anymore 20July2007 */
  if (rbi_LightSensorInactive_g>0)
  {
    l_bool_wr_LightSensorSelected_RLS (0);
  }
  else if ( (rbi_LightSensorActiveFromLin_mg > 0)&&(rbi_LightSensorActive_g > 0 )&&(rbi_EEPROMLoad_g==0)&&(rbi_LS_reinit_init_g==0)/*NOT NEEDED because same as LightSensorActiveFromLin &&(rbi_LS_reinit_g==0)*/ )
  {
    if (rb_debounce_LSselected_OFFtoON >9)
    {
      l_bool_wr_LightSensorSelected_RLS (1);
    }
    else
    {
      rb_debounce_LSselected_OFFtoON++;
    }
    rb_debounce_LSselected_ONtoOFF=0;
  }
  else
  {
    rb_debounce_LSselected_OFFtoON = 0;
    if (rb_debounce_LSselected_ONtoOFF >9)
    {
      l_bool_wr_LightSensorSelected_RLS (0);
    }
    else
    {
      rb_debounce_LSselected_ONtoOFF++;
    }
  }
  
  /*EEPROM Fehler oder Spannung am  Micro Controller NIO*/
  if ((get_rb_VDD_LightSignalErrorCnt_g() > CB_VDDX_ERRORCNT_THRESHOLD_MG))
  {
    l_bool_wr_RainSensorFailSts_RLS(1); // setze Lichtsensor RS-Fehler nach SRS
    l_bool_wr_LightSensorFailSts_RLS(1); // setze Lichtsensor Fehler nach SRS
    
  }
  else
  {
    /*VCO_154 Safety:SM139, SM140:Implement RS_Error_Aktiv,LS_Error_Aktiv flag  to 
    check after Reset if a error was active before the sensor goes to sleep or reset*/
    rb_RS_LS_Error1_g = (bi_ROM_CHECK_FAILURE_g | 
                         (bi_RAM_CHECK_FAILURE_g<<1) | 
                           (rbi_Check_LS_NoCommunication_g<<2) | 
                             (rbi_LS_Error_Vref_g<<3) | 
                               (rbi_ASIC_FreqTrimming_error_g<<4) | 
                                 (rbi_ASIC_SPI_Error_g<<5) | 
                                   (rbi_ASIC_NoValidAD_Error_g<<6) | 
                                     (rbi_ASICReg_NoValidVals_Error_g<<7));
    /*VCO_220 VIrefLo/Hi monitoring*/ /*VDR_878*/
    rb_RS_LS_Error2_g = (rbi_VDD_LightSignalError_g | 
                         (rbi_ClockFreq_Error_g<<1) | 
                           (rbi_LEDx_LStop_error_g<<2) |
                             (rbi_ASIC_initTimeout_err_g<<3) |
                               (rbi_VIref_Error_g<<4));
    
    /*VCO_225 RS functionality detection - error when not available*/
    rb_RainS_Error1_g = (rbi_RainSensorError | 
                         (rbi_REGV_OSAT_Error_g<<1) |
                           (rbi_LEDx_LClosed_error_g<<2)|
                             (bi_RS_VariantError_g<<3)|
                               (rbi_ADC_Error_g<<4));  
    
    rb_LightS_Error1_g = (rbi_LightSensorError_g | 
                          (rb_ASIC_ALSx_ShortDetected_Error_g<<1) | 
                            (bi_CALIB_CHECK_FAILURE_g<<2) | 
                              (rbi_LS_Error_VCalib_meas_g<<3)| 
                                (bi_RAM_GUARD_Error_g << 4));
    
    /* VCO132: SM210 - ASIC Frequency Check (done at startup) - LS,RS_Failure */
    /* VCO 140: SM150 - ADC test */
    /* setze Lichtsensor RS-Fehler nach SRS */
    /*SM240*/
    l_bool_wr_RainSensorFailSts_RLS((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_RainS_Error1_g != 0)||(rbi_HammingError_g != 0));
    
    /* setze Lichtsensor Fehler nach SRS*/
    /* VDR 757 - SM200 */
    /*SM240*/
    l_bool_wr_LightSensorFailSts_RLS((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(rbi_HammingError_g != 0)||(rbi_CRC_ChangedByDiagnostic_g));
  }
  /* PRQA S 3415,4112 10 */ /* <<no side effects>> */
  if ((((((IS_LS_ANY_ERRORCOUNTER()) > 0))||((l_bool_rd_LightSensorFailSts_RLS()) > 0))||(((rbi_UnderVoltage_g) == TRUE))
       || ((rbi_OverVoltage_g) == TRUE)))
  {
    rb_AnyErrorCounterDebounce_mg = 250;
  }
  else
  {
    if (rb_AnyErrorCounterDebounce_mg > 0)
    {
      rb_AnyErrorCounterDebounce_mg -- ;
    }
  }
  
  
  
  if (l_bool_rd_LightSensorFailSts_RLS() == TRUE)  /*rbi_Check_LS_NoCommunication_g from RainSensorFailSts is also checked with rbi_LightSensorError_g*/
  {
    rb_TempLightOn_l = TRUE;
  }
  else if ( ((uF_modi_lightsens_g.AllBit & 0x2F)>0) || ((uF_modi_lightsens_inv_g.AllBit & 0x2F)< 0x2F) || (rbi_InternalResetOccured_g > 0)||(rbi_Regulation48LightOnFlag_g !=0)) 
  {
    rb_TempLightOn_l = TRUE;
  }
  else
  {
    if ( (rbi_Freewaylight_enabled_g==TRUE) && (rbi_FastHighwayMode_g == TRUE) ) /*VDR_197 use Sensitivity Treatment*/
    {
      rb_TempLightOn_l = TRUE;
    }
    else if ( ((rbi_modi_lightsens_rain_g == TRUE)||(rbi_modi_lightsens_rain_inv_g == FALSE)) && (rbi_RainLight_enabled_g == TRUE) ) /*VDR_197 use Sensitivity Treatment*/
    {
      rb_TempLightOn_l = TRUE;
    }
      /* PRQA S 3415 1 */ /* <<no side effects>> */
    else if ((rb_AnyErrorCounterDebounce_mg ==0)&&(get_rb_LightVetoCounter_g()==0)) /*VCO_093 use Veto of Lightsensor*/
    {
      rb_TempLightOn_l = FALSE;
    }
    else
    {
      rb_TempLightOn_l = l_bool_rd_HeadLampsActivation_RLS(); /* stay in old light mode and do */
    }
    
  }
  if(((rbi_UnderVoltage_g == TRUE) || (rbi_OverVoltage_g == TRUE)) && (l_bool_rd_HeadLampsActivation_RLS() == TRUE))
  {
    rb_TempLightOn_l = TRUE;
  }
  
  //***************************
  if (l_bool_rd_LightSensorSelected_RLS() > 0)
  {
    l_bool_wr_HeadLampsActivation_RLS(rb_TempLightOn_l||rbi_LightSensorInactive_g);		/*Set always HeadLampsActivation when Fiat199, or use TempLightOn*/
    
  }
  else
  {
    l_bool_wr_HeadLampsActivation_RLS(rbi_LightSensorInactive_g);		/*Set always HeadLampsActivation when Fiat199, or use TempLightOn*/
  }
  
  l_bool_wr_RainSensorSelected_RLS(l_bool_rd_RainSensorActive_RLS());
  
  if ((rbi_RainSensorEnable == 0) || (l_bool_rd_RainSensorActive_RLS() == FALSE))
  {
    l_u8_wr_WiperSpeed_RLS(0);
    
    l_bool_wr_WiperMode(FALSE);	// single Wipe
    rb_sendWiperSpeed_s = 0;
  }
  else
  {
    // l_bool_wr_RainSensorSelected(TRUE) ;
    if (((rbi_RSWipeFastDmd == 1)                                            // Splash-> High Speed
         || ((rb_WiperSpeed_g > 3) && (rbi_ParkPosition_g ==cb_WIPER_OUT_SIDE_PARK) && (rb_sendWiperSpeed_s == 2)))     // Stop high speed in parkposition
        || (((rb_WiperSpeed_g == 7)&& (rbi_ParkPosition_g == cb_WIPER_IN_SIDE_PARK ))
            || ((rb_sendWiperSpeed_s == 2) && (rb_WiperSpeed_g > 5))))
    {
      rb_sendWiperSpeed_s = 2;
      l_u8_wr_WiperSpeed_RLS(2);
      l_bool_wr_WiperMode(TRUE);
    }
    else if (rbi_RSWipeSlowDmd == 1)       // Splash-> High Speed
    {
      rb_sendWiperSpeed_s = 1;
      l_u8_wr_WiperSpeed_RLS(1);
      l_bool_wr_WiperMode(TRUE);	// copy single Wipe
    }
    else if (((rb_WiperSpeed_g == 0) && (rbi_ParkPosition_g == cb_WIPER_OUT_SIDE_PARK))
             || (rw_WipeCommandTimOut_mg > cw_CLEARWIPE_DELAY_s))    //no wiping
    {
      rb_sendWiperSpeed_s = 0;
      l_bool_wr_WiperMode(FALSE);	// single Wipe
      l_u8_wr_WiperSpeed_RLS(0);
    }
    else if ((rb_WiperSpeed_g != 0) )            // single Wipe in Low Speed
    {
      rb_sendWiperSpeed_s = 1;
      l_bool_wr_WiperMode(FALSE);
      l_u8_wr_WiperSpeed_RLS(1);
    }
    else
    {
      /* QAC*/
    }
  }
  
  l_bool_wr_RLSGenericFailSts((rbi_RainSensorError) || (bi_ROM_CHECK_FAILURE_g) || (bi_RAM_CHECK_FAILURE_g) || (rbi_Check_LS_NoCommunication_g) || (rbi_LS_Error_Vref_g) || (rbi_ADC_Error_g) ||(uF_ASIC_Error_Flags_g.AllBit > 0));
  l_bool_wr_RLSCurrentFailSts((rbi_RainSensorError) || (bi_ROM_CHECK_FAILURE_g) || (bi_RAM_CHECK_FAILURE_g) || (rbi_Check_LS_NoCommunication_g) || (rbi_LS_Error_Vref_g) || (rbi_ADC_Error_g) ||(uF_ASIC_Error_Flags_g.AllBit > 0));
  
  if((rbi_LightValuesInitialised_g == FALSE)|| (rbi_EEPROMLoad_g == TRUE))
  {
    /*hold the previous values*/
    if(rb_InitLightValCnt_l<100)
    {
      rb_InitLightValCnt_l++;
    }
    else
    {
      
    }
  }
  else
   {
    rb_InitLightValCnt_l=0;
    }
    
     
  /*   l_u8_wr_TwilightSensorLevel((rw_ForwLightWideHigh256MFast_mg >> 8)); */ 
  /*Due to FIAT dbc changes, TwilightLevel is not sent anymore 20July2007 */
  if (rbi_LightSensorInactive_g>0)
  {
    l_bool_wr_LightSensorSelected_HRLS (0);
  }
  else if ( (rbi_LightSensorActiveFromLin_mg > 0)&&(rbi_LightSensorActive_g > 0 )&&(rbi_EEPROMLoad_g==0)&&(rbi_LS_reinit_init_g==0)/*NOT NEEDED because same as LightSensorActiveFromLin &&(rbi_LS_reinit_g==0)*/ )
  {
    if (rb_debounce_LSselected_OFFtoON >9)
    {
      l_bool_wr_LightSensorSelected_HRLS (1);
    }
    else
    {
      rb_debounce_LSselected_OFFtoON++;
    }
    rb_debounce_LSselected_ONtoOFF=0;
  }
  else
  {
    rb_debounce_LSselected_OFFtoON = 0;
    if (rb_debounce_LSselected_ONtoOFF >9)
    {
      l_bool_wr_LightSensorSelected_HRLS (0);
    }
    else
    {
      rb_debounce_LSselected_ONtoOFF++;
    }
  }
  
  /*EEPROM Fehler oder Spannung am  Micro Controller NIO*/
  if ((get_rb_VDD_LightSignalErrorCnt_g() > CB_VDDX_ERRORCNT_THRESHOLD_MG))
  {
    l_bool_wr_RainSensorFailSts_HRLS(1); // setze Lichtsensor RS-Fehler nach SRS
    l_bool_wr_LightSensorFailSts_HRLS(1); // setze Lichtsensor Fehler nach SRS
    
  }
  else
  {
    /*VCO_154 Safety:SM139, SM140:Implement RS_Error_Aktiv,LS_Error_Aktiv flag  to 
    check after Reset if a error was active before the sensor goes to sleep or reset*/
    rb_RS_LS_Error1_g = (bi_ROM_CHECK_FAILURE_g | 
                         (bi_RAM_CHECK_FAILURE_g<<1) | 
                           (rbi_Check_LS_NoCommunication_g<<2) | 
                             (rbi_LS_Error_Vref_g<<3) | 
                               (rbi_ASIC_FreqTrimming_error_g<<4) | 
                                 (rbi_ASIC_SPI_Error_g<<5) | 
                                   (rbi_ASIC_NoValidAD_Error_g<<6) | 
                                     (rbi_ASICReg_NoValidVals_Error_g<<7));
    /*VCO_220 VIrefLo/Hi monitoring*/ /*VDR_878*/
    rb_RS_LS_Error2_g = (rbi_VDD_LightSignalError_g | 
                         (rbi_ClockFreq_Error_g<<1) | 
                           (rbi_LEDx_LStop_error_g<<2) |
                             (rbi_ASIC_initTimeout_err_g<<3) |
                               (rbi_VIref_Error_g<<4));
    
    /*VCO_225 RS functionality detection - error when not available*/
    rb_RainS_Error1_g = (rbi_RainSensorError | 
                         (rbi_REGV_OSAT_Error_g<<1) |
                           (rbi_LEDx_LClosed_error_g<<2)|
                             (bi_RS_VariantError_g<<3)|
                               (rbi_ADC_Error_g<<4));  
    
    rb_LightS_Error1_g = (rbi_LightSensorError_g | 
                          (rb_ASIC_ALSx_ShortDetected_Error_g<<1) | 
                            (bi_CALIB_CHECK_FAILURE_g<<2) | 
                              (rbi_LS_Error_VCalib_meas_g<<3)| 
                                (bi_RAM_GUARD_Error_g << 4));
    
    /* VCO132: SM210 - ASIC Frequency Check (done at startup) - LS,RS_Failure */
    /* VCO 140: SM150 - ADC test */
    /* setze Lichtsensor RS-Fehler nach SRS */
    /*SM240*/
    l_bool_wr_RainSensorFailSts_HRLS((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_RainS_Error1_g != 0)||(rbi_HammingError_g != 0));
    
    /* setze Lichtsensor Fehler nach SRS*/
    /* VDR 757 - SM200 */
    /*SM240*/
    l_bool_wr_LightSensorFailSts_HRLS((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(rbi_HammingError_g != 0)||(rbi_CRC_ChangedByDiagnostic_g));
  }
  /* PRQA S 3415,4112 10 */ /* <<no side effects>> */
  if ((((((IS_LS_ANY_ERRORCOUNTER()) > 0))||((l_bool_rd_LightSensorFailSts_HRLS()) > 0))||(((rbi_UnderVoltage_g) == TRUE))
       || ((rbi_OverVoltage_g) == TRUE)))
  {
    rb_AnyErrorCounterDebounce_mg = 250;
  }
  else
  {
    if (rb_AnyErrorCounterDebounce_mg > 0)
    {
      rb_AnyErrorCounterDebounce_mg -- ;
    }
  }
  
  
  
  if (l_bool_rd_LightSensorFailSts_HRLS() == TRUE)  /*rbi_Check_LS_NoCommunication_g from RainSensorFailSts is also checked with rbi_LightSensorError_g*/
  {
    rb_TempLightOn_l = TRUE;
  }
  else if ( ((uF_modi_lightsens_g.AllBit & 0x2F)>0) || ((uF_modi_lightsens_inv_g.AllBit & 0x2F)< 0x2F) || (rbi_InternalResetOccured_g > 0)||(rbi_Regulation48LightOnFlag_g !=0)) 
  {
    rb_TempLightOn_l = TRUE;
  }
  else
  {
    if ( (rbi_Freewaylight_enabled_g==TRUE) && (rbi_FastHighwayMode_g == TRUE) ) /*VDR_197 use Sensitivity Treatment*/
    {
      rb_TempLightOn_l = TRUE;
    }
    else if ( ((rbi_modi_lightsens_rain_g == TRUE)||(rbi_modi_lightsens_rain_inv_g == FALSE)) && (rbi_RainLight_enabled_g == TRUE) ) /*VDR_197 use Sensitivity Treatment*/
    {
      rb_TempLightOn_l = TRUE;
    }
      /* PRQA S 3415 1 */ /* <<no side effects>> */
    else if ((rb_AnyErrorCounterDebounce_mg ==0)&&(get_rb_LightVetoCounter_g()==0)) /*VCO_093 use Veto of Lightsensor*/
    {
      rb_TempLightOn_l = FALSE;
    }
    else
    {
      rb_TempLightOn_l = l_bool_rd_HeadLampsActivation_HRLS(); /* stay in old light mode and do */
    }
    
  }
  if(((rbi_UnderVoltage_g == TRUE) || (rbi_OverVoltage_g == TRUE)) && (l_bool_rd_HeadLampsActivation_HRLS() == TRUE))
  {
    rb_TempLightOn_l = TRUE;
  }
  
  //***************************
  if (l_bool_rd_LightSensorSelected_HRLS() > 0)
  {
    l_bool_wr_HeadLampsActivation_HRLS(rb_TempLightOn_l||rbi_LightSensorInactive_g);		/*Set always HeadLampsActivation when Fiat199, or use TempLightOn*/
    
  }
  else
  {
    l_bool_wr_HeadLampsActivation_HRLS(rbi_LightSensorInactive_g);		/*Set always HeadLampsActivation when Fiat199, or use TempLightOn*/
  }
  
  l_bool_wr_RainSensorSelected_HRLS(l_bool_rd_RainSensorActive_HRLS());
  if ((rbi_RainSensorEnable == 0) || (l_bool_rd_RainSensorActive_HRLS() == FALSE))
  {
    l_u8_wr_WiperSpeed_HRLS(0);
    
    rb_sendWiperSpeed_s = 0;
  }
  else
  {
    // l_bool_wr_RainSensorSelected(TRUE) ;
    if (((rbi_RSWipeFastDmd == 1)                                            // Splash-> High Speed
         || ((rb_WiperSpeed_g > 3) && (rbi_ParkPosition_g ==cb_WIPER_OUT_SIDE_PARK) && (rb_sendWiperSpeed_s == 2)))     // Stop high speed in parkposition
        || (((rb_WiperSpeed_g == 7)&& (rbi_ParkPosition_g == cb_WIPER_IN_SIDE_PARK ))
            || ((rb_sendWiperSpeed_s == 2) && (rb_WiperSpeed_g > 5))))
    {
      rb_sendWiperSpeed_s = 2;
      l_u8_wr_WiperSpeed_HRLS(2);
    }
    else if (rbi_RSWipeSlowDmd == 1)       // Splash-> High Speed
    {
      rb_sendWiperSpeed_s = 1;
      l_u8_wr_WiperSpeed_HRLS(1);
    }
    else if (((rb_WiperSpeed_g == 0) && (rbi_ParkPosition_g == cb_WIPER_OUT_SIDE_PARK))
             || (rw_WipeCommandTimOut_mg > cw_CLEARWIPE_DELAY_s))    //no wiping
    {
      rb_sendWiperSpeed_s = 0;
      l_u8_wr_WiperSpeed_HRLS(0);
    }
    else if ((rb_WiperSpeed_g != 0) )            // single Wipe in Low Speed
    {
      rb_sendWiperSpeed_s = 1;
      l_u8_wr_WiperSpeed_HRLS(1);
    }
    else
    {
      /* QAC*/
    }
  }
  
  if((rbi_LightValuesInitialised_g == FALSE)|| (rbi_EEPROMLoad_g == TRUE))
  {
    /*hold the previous values*/
    if(rb_InitLightValCnt_l<100)
    {
      rb_InitLightValCnt_l++;
    }
    else
    {
      l_u8_wr_SolarSensorLeft(cb_INIT); // Init/nicht verfuegbar 
      l_u8_wr_SolarSensorRight(cb_INIT); // Init/nicht verfuegbar 
      
    }
  }
  else
  {
    rb_InitLightValCnt_l=0;
    if(l_bool_rd_LightSensorFailSts_HRLS() == TRUE) /*  VDR469   set for error*/
    {
      l_u8_wr_SolarSensorLeft(cb_ERROR);
      l_u8_wr_SolarSensorRight(cb_ERROR);
    }
    else
    {
      if((rbi_SoSe_Enabled_g == TRUE) && (TRUE == rbi_SolarValuesInitialised_g))
      {
        if((rw_Solar_light16bit_2_g/2) <= cb_SOLAR_MAX_mg )
        {
          l_u8_wr_SolarSensorLeft((byte)(rw_Solar_light16bit_2_g/2));
        }
        else
        {
          l_u8_wr_SolarSensorLeft(cb_VALUE_EXCEEDS_LIMIT); /* Value Exceeds Limit */
        }
        
        if((rw_Solar_light16bit_1_g/2) <= cb_SOLAR_MAX_mg)
        {
          l_u8_wr_SolarSensorRight((byte)(rw_Solar_light16bit_1_g/2));
        }
        else
        {
          l_u8_wr_SolarSensorRight(cb_VALUE_EXCEEDS_LIMIT); /* Value Exceeds Limit */
        }
      }
      else
      {
        l_u8_wr_SolarSensorLeft(cb_INIT); /* Init/nicht verfuegbar */
        l_u8_wr_SolarSensorRight(cb_INIT); /* Init/nicht verfuegbar */
        
      }
    }
    
  }
  if (FALSE == rbi_HumTemp_Module_enabled_g)
  {
    DISABLE_SCIINTERRUPT();
    l_u16_wr_GlassTemp(cw_SNA_1);
    l_u16_wr_DewpointTmp(cw_SNA_1);
    ENABLE_SCIINTERRUPT();
    l_u8_wr_RelHumidity(cb_SNA);
    l_bool_wr_HumSns_Int_flt(FALSE);
  }
  
  else 
  {
    
  
  if (rbi_HumTempComError_g != 0)
  {
    l_bool_wr_HumSns_Int_flt(TRUE);
    l_u8_wr_RelHumidity(cb_ERROR);
    DISABLE_SCIINTERRUPT();
    l_u16_wr_DewpointTmp(cw_ERROR_1);
    l_u16_wr_GlassTemp(cw_ERROR_1);
    ENABLE_SCIINTERRUPT();
    
  }
  else
  {
    l_bool_wr_HumSns_Int_flt(FALSE);
    
    if (rw_DewPoint_g == cw_HUMTEMP_INIT_g)    // init?
    {
      DISABLE_SCIINTERRUPT();
      l_u16_wr_DewpointTmp(cw_INIT_1);
      ENABLE_SCIINTERRUPT();
    }
    
    
    else
    {
      if ((rw_DewPoint_g+4) <=  cw_DEWPOINT_MAX_1_mg )
      {
        DISABLE_SCIINTERRUPT();
        l_u16_wr_DewpointTmp(rw_DewPoint_g+4); 
        ENABLE_SCIINTERRUPT();
      }
      
      else
      {
        DISABLE_SCIINTERRUPT();
        l_u16_wr_DewpointTmp(cw_VALUE_EXCEEDS_LIMIT_1);
        ENABLE_SCIINTERRUPT();
      }
    }
    
    
    if (rb_Humidity_g == cw_HUMTEMP_INIT_g)    /* init?*/ /*VCO_061 name hase changed*/
    {
      l_u8_wr_RelHumidity(cb_INIT);
    }    
    else if(rb_Humidity_g == cb_HUMI_ERROR_g)
    {        
      l_u8_wr_RelHumidity(cb_ERROR);
    }
    else
    {
      l_u8_wr_RelHumidity(rb_Humidity_g-1);
    }
    
    
    if(rw_Temperature_raw_g == cw_HUMTEMP_INIT_g)
    {
      DISABLE_SCIINTERRUPT();
      l_u16_wr_GlassTemp(cw_INIT_1);
      ENABLE_SCIINTERRUPT();
    }
    else
    { 
      /* raw value less than -40 or Greater than 85 degree */
      if((rw_Temperature_raw_g < 685) ||  (rw_Temperature_raw_g > 13185))
      {
        DISABLE_SCIINTERRUPT();
        l_u16_wr_GlassTemp(cw_VALUE_EXCEEDS_LIMIT_1); /* Value Exceeds Limit */
        ENABLE_SCIINTERRUPT();
      }
      else
      {
        DISABLE_SCIINTERRUPT();
        l_u16_wr_GlassTemp(((rw_Temperature_raw_g - 685)/10));
        ENABLE_SCIINTERRUPT();
      }
    }
    
  } 
 
   }
  
#if defined (ASIC_TEST)
  CopyRLSDataAsic();
#endif  
  rb_WDG_BusTaskCounter_g++;      //increment test counter for bus
}



void ApplLinInit(byte rb_LIN_State_l)
{
#ifdef _INITWITHDEFAULT_ 
   //init unused bits to 1
  byte rb_Index_l;

  rb_Index_l = 0;
  do
  {                          
    RLSData._c[rb_Index_l] = LinMsgDefault_RLSData[rb_Index_l];
    rb_Index_l++;
  } while (rb_Index_l < 2);

#endif /* _INITWITHDEFAULT_ */

#ifdef _SUPPORTMWLLIGHT_
  Diagnose_ReadMem_Init();
#endif
  sci_init(0);
  rbi_RealParkContact_g = cb_WIPER_OUT_SIDE_PARK;
  rbi_ParkPosition_g = cb_WIPER_IN_SIDE_PARK;


}                                              //ApplLinInit


__callt void ApplLinSlavePreCopy(byte rb_MessageID_l)    /* callt function (faster */
{
  /* if (rbi_latched_ResponseError_mg > 0)

   {    rbi_latched_ResponseErrorHRLS__mg = TRUE;
        rbi_latched_ResponseErrorRLS__mg = TRUE;
        rbi_latched_ResponseError_mg=FALSE;

  }
   if((rb_MessageID_l == (rb_IDRLSs_01_g & 0x3F)))
  {
    l_bool_wr_ResponseErrorStsRLS(rbi_latched_ResponseErrorRLS__mg);
    rbi_latched_ResponseErrorRLS__mg = FALSE;
  }
  else    if((rb_MessageID_l == (rb_IDHRLSs_01_g & 0x3F)))
  {
    l_bool_wr_ResponseErrorStsRLS(rbi_latched_ResponseErrorHRLS__mg);
    rbi_latched_ResponseErrorHRLS__mg = FALSE;
  }
  */  /*********************************** TO BE VERIFIED HAYTHEM ********************/
  
  
  /* if((rb_MessageID_l == (rb_IDRLSs_01_g & 0x3F)) &&((rb_RSControlFlags_g & 0x80) == FALSE))
  {
    l_bool_wr_ResponseErrorStsRLS(rbi_latched_ResponseError_mg);
    rbi_latched_ResponseError_mg = FALSE;
  }
  else if((rb_MessageID_l == (rb_IDFSs_01_g & 0x3F))&&((rb_RSControlFlags_g & 0x80) == FALSE)) // rb_IDFSs_01_g ==> HRLSDATA in FIAT_330
  {
    l_bool_wr_ResponseErrorStsHRLS(rbi_latched_ResponseError_mg);
    rbi_latched_ResponseError_mg = FALSE;
  } */
  
  if(((rb_MessageID_l == (rb_IDRLSs_01_g & 0x3F)) || (rb_MessageID_l == (rb_IDFSs_01_g & 0x3F)) )&&((rb_RSControlFlags_g & 0x80) == FALSE))
  {
    l_bool_wr_ResponseErrorStsRLS(rbi_latched_ResponseError_mg);
    l_bool_wr_ResponseErrorStsHRLS(rbi_latched_ResponseError_mg);
    rbi_latched_ResponseError_mg = FALSE;
  }
  
  else
  {
    /* Not Relevant for FIAT_330, we don't have a frame dedicated to Humidity + variant Humidity only */ 
    /* if((rb_RSControlFlags_g & 0x80) != 0)
    {
      if(rb_MessageID_l == (rb_IDFSs_01_g & 0x3F)&&(rb_IDFSs_01_g != 0x40))
      {
        // send response error in FS message if only humidity sensor is active 
        // l_bool_wr_RsErr_HumSense(rbi_latched_ResponseError_mg);  No variant for Humidity only in case of Fiat_330 
        rbi_latched_ResponseError_mg = FALSE;
      }
      
      if(rb_MessageID_l == (rb_IDFSs_Enh_01_g & 0x3F)&&(rb_IDFSs_Enh_01_g != 0x40))
      {
        // send response error in FS message if only humidity sensor is active 
        // l_bool_wr_RsErr_HumSnsr(rbi_latched_ResponseError_mg);  No variant for Humidity only in case of Fiat_330 
        rbi_latched_ResponseError_mg = FALSE;
      } 
      
    }*/ 
  }
}





