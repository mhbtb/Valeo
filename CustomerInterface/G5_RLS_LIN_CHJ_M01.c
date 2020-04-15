/* PRQA S 3619 EOF */ /* << IAR-Compiler allows whitespaces>> */
/* PRQA S 3116 EOF */ /* << pragma directives needed, compiler specific>>*/
/*************************************************************************

  Company : Valeo Wiper System

  Project : RLT Sensor, RDN Sensor

  Component : RLS_LINST.c

  Documentation reference   : Software Requrement Specification
  Overview of the component : LIN- Data Link layer

  Evolution of the component : see PVCS Version control system

                Initials   date   modification

*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/* DD.MM.YY*/
/*----------------------------------------------------------------------------*/
/* 05.09.11 VDR_705  PCG  - Send detection of Rain Sensor at any time not only when active */
/* 31.08.11 VDR_700  PCG  - Set Light Sensitivity "0" like LS "4". Set default to "4" instead of "0" 
                          - Reorganize signals related to Message CEM_L8_FrP04 */
/* 13.05.11 VDR_659  PCG  - QA-C                       */
/* 12.05.11 VDR_634  PCG  - removed changes from 10.May.11 */
/* 10.05.11 VDR_634  PCG  - set adapterrrainsensacrive failure when no master msg is received */
/* 24.03.11 VDR_647  FS   - Variable name changed*/ 
/* 18.03.11 VDR_66   PCG  - RLS_VDR_633 RLS_VOLVO_Y555 the first frame of RSM partnumber is set to 0 at startup */
/* 17.02.11 VCO_70   PCG  - reduced low limit for WS Transmission due to Blue shade band*/
/* 15.02.11 VDR_580  PCG  - splash bit no more depending on directmode */
/* 17.11.10 VDR_583  PCG  - Corrected Volvo Part Number. SWRS-RSM-001:Req14v1  */
/* 04.11.10 VDR_583  PCG  - Corrected Volvo Part Number. SWRS-RSM-001:Req14v1  */
/* 11.08.10 VCO_73   PCG  - Implemented Rain Sensor Sensitivity up to 8 sensitivities. SWRS-RSM-001:Req34v1 */
/* 06.08.10 VCO_71   PCG  - Implemented Rain Sensor Norm Value: adjust RSM sensitivity when placed on 
*                            different vehicles. SWRS-RSM-001: Req38v1  */
/* 06.08.10 VCO_73   PCG  - Implemented VCC Part Number: 31314540. SWRS-RSM-001:Req14v1  */
/* 05.08.10 VCO_72   PCG  - Implemented Light Sensor Sensitivity: RainSnsrLiSnvty. SWRS-RSM-001:Req51v2  */
/* 03.08.10 VCO_69   PCG  - Implemented new output signal RainSnsrLiMod. SWRS-RSM-001:Req39v2 */
/* 03.08.10 VCO_66   PCG  - Implemented CarCode table values according mail 26.03.2010*/
/* 02.08.10 VCO_67   PCG  - Implemented Rain Sensor active when Terminal_X is set regardless 
*                            Switch Position. SWRS-RSM-001:Req31v1 */
/* 02.08.10 VCO_68   PCG  - Implement New message CEM_L8_FrP04. SWRS-RSM-001:Req19v1 */
/* 30.06.10 VDR_540  FS   - Butterfly Option integrated*/
/* 10.06.10 VCO_49   FS   - Implement long EEPROM PLUS Logging Issues from 11.June --> Park Position corrected*/
/* 10.06.10 VCO_59   FS   - Logging files --> Rework ParkPosition Evaluation*/
/* 26.05.10  VCO_055     AL      reomve debouncing of RAM and ROM error*/
/* 29.04.10 VDR_473  FS   - QA-C*/
/* 26.04.10 VCO_48   FS   - Use "AB" Index instead of only "B" of the partnumer within EEPROM*/
/* 26.04.10 VCO_48   FS   - First Frame of Part number not correct*/
/* 26.03.10  VCO_48   FS   - Update due to Test Drive
 *                           Park contact has been send to late via LIN
                         --> Update in this file and trigger on WiperSpeed_Running Signal
                           - Update internal SCS_Signals, that both ldf can work the same*/
/* 25.03.10  VCO_44   FS   - Implement strategy for Partnumber Read Out
 *                         - delete some parts of VCO_33
 *                         - Switch Stalk Information dependent from CarCode*/
/* 11.02.10  VDR_437  FS   - Index of Ford Partnumber from EEPROM included *
  *                        - Mapping of RainSensorSensitivity not in RAM --> in EEPROM*/
/* 19.01.10  VDR_414  FS    Update due to Testdrive*/
/* 23.12.09  VDR_394  FS    REWORK: New CarCode Table to be implemented, Req: Email from 20091218*/
/* 22.12.09  VDR_362  FS    Rework: Overflow of rb_parkpositioncounter_s MUST have been implemented */
/* 18.12.09  VDR_403  FS    - rb_FixedCarCode deleted
 *                          - Set Auxillary Variable constantly to ALL-value that Ford Partnumber
 *                            can be received by Master for all CarCodes*/
/* 19.11.09  VDR_396  FS    RainSensorEnable as required in SRS*/
/* 17.11.09  VDR_394  FS    Default values windshield and comments*/
/* 01.10.09  VDR_373  FS    "OneTime or Double Overwiped"*/
/* 29.09.09  VDR_362  FS    Implement wipe cancelling when 4 seconds wiper has not moved*/
/* 25.09.09  VDR_368  FS    Requirements from FRSI, SRD, ES and Testcases. See comments in code*/
/* 28.09.09  VDR_360  FS    RainSensorDisable implementation for Ford*/
/* 31.07.09  VDR_355  AL    Changes based on results of function test and     *
           & VDR_356        Review of function from Bosch sensor             */

/* 16.07.09  VDR_344 FS     Updating complete first version to                *
                            first release version due to                      *
                            Ford Meeting in Bietigheim                        */
/* 28.08.15  VCO_268 SP     Cleanup the LIN modules  */
/*02.10.2015 VDR_911 SP     HammingErr shld be part of RS_Error/LS_Error and shld not be used for Active Err*/
/*30.05.2016 VDR_983 NB     Sporadic illegale instruction reset in the startup                              */
/******************************************************************************/


/*************************************************************************
**                   Common and module include-file                     **
**************************************************************************/


#include "ior5f109be.h"
#include "G5_projectDefs.h"
#include "G5_E2ProjectConfig.h"

#include "G5_Appli_main.h"
#define _RLS_LIN_c_         /*Define for Single include of Global Header rls_linst.h */
#include "G5_lininclude.h"
#undef  _RLS_LIN_c_
/*************************************************************************
**                   Other files included                               **
**************************************************************************/
#include "G5_io.h"
#include "G5_Appli_timer.h"
#include "G5_Check_sr.h"
#include "G5_rainsens.h"
#include "G5_diagnose.h"
#include "G5_E2Handler.h"
#include "G5_flashe2.h"
#include "G5_rs_task.h"

#include "G5_IRlight.h"
#include "G5_DippedBeam_sr.h"
#include "G5_ASIC_Control.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_spi_sr.h"
#include "G5_utilities.h"
#include "G5_AsicFramesLin.h"

#ifdef CS_TWILIGHT_TO_DARK
#include "G5_TwilightToDark.h"
#endif
/*VDR_362 Carry Over Standard Code*/
/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/
#ifdef SENSIRION_SHT21_USED
#define cw_DEWPOINT_MAX_mg        (1396)     /*VDR_154 change of max value from 1022 to 1000*/
#else
#define cw_DEWPOINT_MAX_mg        (1000+CW_DEWPOINT_OFFSETT_mg)     /*VDR_154 change of max value from 1022 to 1000*/
#endif

#define cb_IGNORE_IGNITION_SPEED   4  /*VCO_083 ignore ignition off if speed higher 4km/h*/

#define cb_ONLY_HUMIDITY           0x98
#define cb_HUMIDITY_SOLAR          0x8A

#define cw_TEMPSCHEIBE_MAX_mg       (1000+CW_TEMPERATURE_OFFSETT_mg)  /*VDR_154 change of max value from 1022 to 1000*/
#define CW_TEMPERATURE_OFFSETT_mg   4 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define CW_DEWPOINT_OFFSETT_mg      4 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define CW_DEWPOINT_MIN_mg          1 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define CW_TEMPERATURE_MIN_mg       1 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define cb_TEMPSENSOR_MAX_mg        254

#define cb_DAY                      0x00
#define cb_TWILIGHT                 0x01
#define cb_DARK                     0x02
#define cb_TUNNEL                   0x03
#define cb_RAIN_LIGHT               0x05
#define cb_UNDERGROUND              0x04
#define cb_HIGH_SPEED               0x06
#define cb_OTHERRSEAN               0x07
//#define cb_HUD_MEASURING_RANGE_1    0x40
//#define cb_HUD_MEASURING_RANGE_2    0x80

/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
static volatile Flag uF_StalkInPos_Flags_g;

/******************************************************************************/
/*                      Definition of exported variables                      */
/******************************************************************************/


/*************************************************************************
**                   Declaration of local module Macros **
*************************************************************************/

#define cb_FOUR_SECOND_DELAY_mg      25
#define CW_LIN1_3_IDLE_TIMOUT        (2*130)
#define CW_LIN2_0_IDLE_TIMOUT        400

#define cw_CLEARWIPE_DELAY_s         400               //4 seconds (400*10ms)
#define cb_DEPRESSED_PARK_DEBOUNCE_s 18

#define cb_VERGLSUNG_OPEN_DELAY_mg   100
#define cb_VERGLSUNG_CLOSE_DELAY_mg  100

/*************************************************************************
**                   Declaration of local module Functions              **
*************************************************************************/
static void CheckErrors(void);
void RainFunction(void);
void LightFunction(void);
void Humidity_Function(void);
void StandByMode(void);
void VoltageDetect(void);
void OutPutBrightnessValue(void);
void getLightTransmission(byte trans_550nm,byte trans_880nm);

#ifdef CS_STANDBY
static byte rb_Verglasun_offenDebounce_mg,rb_Verglasun_ClosedDebounce_mg;
static word rw_CommandCloseWindowTimout_mg;
static byte rb_standbyOff_g = 0;
#endif

static byte rb_KL15_mg;
static byte rb_AnyErrorCounterDebounce_mg;
static word rw_AfterRSWipeCounter_mg;                   // Time after last wipe from RS
static word rw_AfterRSWipeCounterAlt_mg;              //Time to the last wipe from RS
static word rw_AfterWWSWipeCounter_mg;                  // Time after last wipe from WWS
static word rw_WipeCommandTimOut_mg;                    //timout for requested wipe
static  byte rb_IgnitionOndelay_mg = 0;

static const byte cab_PotistageMapping_mg[8] = {4,5,6,7,3,2,1,0}; /*mapping for potistages!*/
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
  static word rw_IgnitionOffDelay_mg;
  static byte rb_IntervalOnOndelay_mg;
  static byte rb_AfterResetCounter_l;
  byte rb_Empfindlichkeit_LS_l = 3;
  static byte rb_KL15_old_mg = 0;
#ifdef CS_STANDBY 
/** open the standby mode on in csv  
  byte rb_Kodierbyte0_Update_g; 
  if(StandbyMode_ON())
  {
    rb_Kodierbyte0_Update_g = (0x04 | rb_Kodierbyte0_g);
  }
  else if(StandbyMode_OFF())
  {
    rb_Kodierbyte0_Update_g = (0XFB & rb_Kodierbyte0_g); 
  }
  else
  {
    rb_Kodierbyte0_Update_g = rb_Kodierbyte0_g;
  }
  
  if(rb_Kodierbyte0_Update_g != rb_Kodierbyte0_g)
  {
    rab_EEPROM_Bytes_toWrite_g[0] = rb_Kodierbyte0_Update_g;
    rw_EEPROM_Address_to_Write_g = cw_EEPROM_CODING_ADDRESS_g + 2; 
    rb_I2C_EEPROM_bytesToWrite_g = 1;                              
    rbi_EEPROMBytesToWrite_g = TRUE;
    rbi_EEPROMBytesWritten_g = FALSE; 
  }
**/
    
  if (IsWdwOpen())                                                 /*Window Open*/
  {
    if(rb_standbyOff_g == 1)
    {
      rb_Verglasun_offenDebounce_mg = 0;
    }
    else
    {
      if (rbi_Ignition_g == FALSE)                                   /* VCO_028*/
      {
        if (rb_Verglasun_offenDebounce_mg < 0xff)
        {
          rb_Verglasun_offenDebounce_mg ++;
        }
      }
      rb_Verglasun_ClosedDebounce_mg = 0;
    }
  }
  else
  {
    if (rb_Verglasun_ClosedDebounce_mg < 0xff)
    {
      rb_Verglasun_ClosedDebounce_mg ++;
    }
    rb_Verglasun_offenDebounce_mg = 0;
  }
#endif   
  
  if(l_flg_tst_BCM_RLSCtrlCmd())
  { 
    l_flg_clr_BCM_RLSCtrlCmd();
    rw_NoCommunicationCounter_g = 0;                                  // reset no communication counter
    rbi_ConnectedToMaster_g = 1;   
    rbi_RealParkContact_g = IsInParkPosition();                       // true=in park position
    rbi_LightSensitivityRecieved_g = TRUE;                            
   
    rb_speed_in_kmh_g  = ReadVehicleSpeed(); 
    
    if(rb_speed_in_kmh_g >= 10)
    {
      rbi_speedWasAbove10kmh_g = TRUE;
    }
             
    rb_KL15_mg = IsIgnitionOn();    
    if((rb_standbyOff_g == 1) && (rb_KL15_mg == 1) && (rb_KL15_old_mg ==0))
    {
      rb_standbyOff_g = 0;
    }    
    rb_KL15_old_mg = rb_KL15_mg;   
    if((rb_KL15_mg == TRUE)||(rb_speed_in_kmh_g > cb_IGNORE_IGNITION_SPEED)) /*VCO_083*/
    {                                                                    /* ignore ignition off if speed higher 4km/h*/
      rbi_Ignition_g = TRUE;
      rw_StandbyTimeOutCnt_g = 0;
      rw_IgnitionOffDelay_mg = 0;
      if(rb_IgnitionOndelay_mg < 250)
      {
        rb_IgnitionOndelay_mg++;
      }
          
      if((rbi_RainsensorDisabled_g == FALSE) &&(rb_AfterResetCounter_l> 10))
      {
        if((IsAutoWiper())                                              //automatic
            || (rbi_RainsensorAlwaysOn_g != FALSE))
        {
          rbi_AutomaticWipingMode_g = TRUE;                            /*Rainsensor always active!*/
        }
        else
        {
          rbi_AutomaticWipingMode_g = FALSE;                           /*Rainsensor off!*/
        }
      }
      else
      {
        rbi_AutomaticWipingMode_g = FALSE;                             //Rainsensor off!
      }
      
      if(IsAutoWiper())                                                // copy automatic wiping mode
      {
        if(rb_IntervalOnOndelay_mg > 15)                               //debound 150ms when turn the auto wiper on
        {
          rbi_LSS_Interval_g = TRUE;
        }
        else
        {
          rb_IntervalOnOndelay_mg++;
        }
      }
      else
      {
        rbi_LSS_Interval_g = FALSE;
        rb_IntervalOnOndelay_mg = 0;
      }
    }
    else
    {          
      rbi_Ignition_g = FALSE;
      rw_AfterWWSWipeCounter_mg = 50000;                                //Direktbitdelay bei Kl15 Aus hochsetzen!
      rw_WipeCommandTimOut_mg = 0;
      rb_IgnitionOndelay_mg = 0;
      rbi_AutomaticWipingMode_g = FALSE;                                //Rainsensor off!
    }

    rb_LIN_SensitivityShift_g =  9;                                     //adaptation Variable for sensitivity factor

    rb_PotiStageFromBox_g = ReadRainSensitivity();
    
    if (IsWashMode())                                         /* Washpump activ? 0x5:Front washing*/
    {
      rbi_WashingActive_g = TRUE;                                       /* set Washing activ bit */
    }
    else if (rbi_ParkPosition_g == TRUE)                                /* In Parkposition ? */
    {
      rbi_WashingActive_g = FALSE;                                      /* Clear Washing active bit */
    }
    else{}                                                              /*Do nothing, Dummy-else for Misra Check*/
    
    getLightTransmission((l_u8_rd_BCM_500nmTransimission()),(l_u8_rd_BCM_800nmTransimission()));
  }  
  else                                                                  //keine neue Master Nachricht!
  {                                                                     // check if system is on -> to switch off 
   if((rw_NoCommunicationCounter_g > CW_LIN_E2_IDLE_TIMOUT))                               /***4S***/
   {
#ifdef CS_STANDBY       
      if ((rbi_Command_CloseWindows_g == FALSE)||( rbi_ASICStandByModeRequest_g == FALSE))  /*VDR_526*/
      {        
        if ( ((rbi_Ignition_g== FALSE)) &&((rb_Verglasun_offenDebounce_mg > cb_VERGLSUNG_OPEN_DELAY_mg) &&
                                           (rbi_StandbyFunction_enabled_g == TRUE)) && (rbi_Command_CloseWindows_g == FALSE) )
        {
          rbi_ASICStandByModeRequest_g = 1;                             // Set Request for Standby Mode
        }
        else
        {
          rbi_ASICStandByModeRequest_g = 0;
        }       
        rbi_GotoSleep_g = TRUE;                                         // Was Connected to Master
      }
      else 
      {
                                                       //auto close windows                         
        if ((!IsWdwOpen()) || (rw_CommandCloseWindowTimout_mg > 6000))
        {
          rbi_GotoSleep_g = TRUE;                                       // no need of Standby mode 
          rbi_ASICStandByModeRequest_g = 0;
          rbi_SendWakeUpFrame_g = FALSE;                                /*VDR_526*/
          rbi_Command_CloseWindows_g = FALSE;                           /*VDR_526*/
          rb_WakeupCounter_mg = 0; 
        }
        else
        {
          if (rb_WakeupCounter_mg == FALSE)                             /*VDR_526*/
          { 
            rbi_SendWakeUpFrame_g = TRUE; 
          }
        }

      }
#else
     rbi_ASICStandByModeRequest_g = 0;
     rbi_GotoSleep_g = TRUE; 
#endif      
      rbi_ConnectedToMaster_g = FALSE;                                  // clear connected to Master
    }
    else
    {
      rbi_SendWakeUpFrame_g = FALSE;                                    /*VDR_526*/
      rw_NoCommunicationCounter_g ++;
      rbi_GotoSleep_g = FALSE;                                          // Was Connected to Master
      if(rw_NoCommunicationCounter_g >= (CW_LIN_E2_IDLE_TIMOUT - 3) )
      {
                                                                        /*clear marker in the EEPROM to indicate there is a normal sleeep command*/
        rb_Release_IntervalMarker_Update_g = 0x00;                      //send sleep command to RS
        rbi_Write_ReleaseMarker_g = TRUE;                               //indicate if rb_Release_IntervalMarker_g sholud be updated in EEPROM
      }
    }
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
  
  if (rb_AfterResetCounter_l<250)
  {
    rb_AfterResetCounter_l++;                                           /* counts calls of routine to delay activation of rainsensor*/
  }
  
  if(rw_IgnitionOffDelay_mg < 1000)                                     /* 10sec delay */
  {
    rw_IgnitionOffDelay_mg++;
  }
  else
  {
    rb_Release_IntervalMarker_Update_g |= 0xA0;
    rbi_Relase_FixedIntervalTime_g = FALSE;
  }
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
  static byte rb_parkpositioncounter_s;
  /*simulierte Wischzeit bei LSS aus*/
  static const byte cab_WiperMotorRunntime_mg[8] ={142,142,133,125,117,111,105,100};
  byte rb_Wischer_Parklage_l;
  
  /* Park position information comes from BCM message */
  rb_Wischer_Parklage_l = IsInParkPosition();
 
#ifdef STARTUP_WIPE  
  /* Startup-Wipe */
  if((rb_WiperSpeed_g==0) && ( rb_Startup_Wipe_g == TRUE))
  {
    rb_WiperSpeed_g = 2;
    rw_StartupWipeCommandTimOut_mg ++;  
  }
  else if(((rb_Startup_Wipe_detected_g == 1)|| (rb_Startup_Wipe_detected_g == 3)) &&( rb_Startup_Wipe_g == TRUE))
  {
    if(rb_Wischer_Parklage_l == FALSE)
    {
      rb_Startup_Wipe_g = FALSE; 
    }
    else
    {
      if (rw_StartupWipeCommandTimOut_mg <= cw_CLEARWIPE_DELAY_s)
      {
        rw_StartupWipeCommandTimOut_mg ++;      // reset Timout if wiper motor wants not wipe
      }
      else
      {
        rb_LimitMemomryNoWiperReaction_g = TRUE;
        rb_Startup_Wipe_g = FALSE; 
        rb_WiperSpeed_g = 0;
        
        if (rb_Startup_Wipe_detected_g == 1)
        {
          rw_StartupWipeCommandTimOut_mg = 0;
          rb_Start_STBY_Meas_g = TRUE;
          rb_Startup_STBY_meas_on_l=TRUE;
        }
        rb_Startup_Wipe_detected_g += 1;
      }
    }
  }
#endif
  if ((rb_WiperSpeed_g > 0)&&(rb_Wischer_Parklage_l== TRUE))
  {
    
    if (rw_WipeCommandTimOut_mg <= cw_CLEARWIPE_DELAY_s)
    {
      rw_WipeCommandTimOut_mg ++;                // reset Timout if wiper motor wants not wipe
    }
    else
    {
      rb_LimitMemomryNoWiperReaction_g = TRUE;
    }
    
  }
  
  if((IsAutoWiper())
     ||(rw_WipeCommandTimOut_mg > cw_CLEARWIPE_DELAY_s))
  {
    if((rb_WiperSpeed_g > 0)||(rbi_ParkPosition_g == FALSE))
    {
      if(rb_parkpositioncounter_s>10)             // Parkpositioncounter groesser 10
      {
        rbi_ParkPosition_g = FALSE;               // loesche bit fuer Parkposition
      }
      rb_parkpositioncounter_s++;                 // inkrementiere Parkpositionscounter
    }
    
    if(rb_parkpositioncounter_s > (cab_WiperMotorRunntime_mg[rb_WiperSpeed_g]))
    {
      rw_WipeCommandTimOut_mg = 0;
      rbi_ParkPosition_g = TRUE;                  // loesche bit fuer Parkposition
      rb_parkpositioncounter_s = 0;               //
    }
  }
  else   
  {
    if(rb_WiperSpeed_g > 0)
    {
      rbi_WiperStarted_g = TRUE;
    }
    
    if(rb_Wischer_Parklage_l == TRUE)               // In Parklagensignal ?
    {
      if(rbi_ParkPosition_g == FALSE)
      {
        rb_parkpositioncounter_s=0;                 // Parkpositioncounter zuruecksetzen
      }
      else
      {
        if(rb_parkpositioncounter_s < 255)
        {
          rb_parkpositioncounter_s++;
        }
      }
      rbi_ParkPosition_g = TRUE;                   // Parkposition True
      if (rub_IntermDelayTime > 5)                 // clear option for Wiper Started Flag!
      {
        rbi_WiperStarted_g = FALSE;
      }
    }
    else
    {
      rb_LimitMemomryNoWiperReaction_g = FALSE;
      rbi_WiperStarted_g = FALSE;
      rw_WipeCommandTimOut_mg = 0;                // reset Timout if wiper motor wants not wipe
      if(rb_parkpositioncounter_s>7)              // Parkpositioncounter groesser 8
      {
        rbi_ParkPosition_g = FALSE;               // loesche bit fuer Parkposition
      }
      else
      {
        rb_parkpositioncounter_s++;               // inkrementiere Parkpositionscounter
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
  Check_StartupActiveErrors();
   
  if(l_flg_tst_RLS_StatusInfo())
  {
    l_flg_clr_RLS_StatusInfo() ;
    rbi_ConnectedToMaster_g = 1; 
  }

  if(FALSE==rbi_EEPROMLoad_g)
  {
#ifndef _NO_RAIN_
    if((FALSE==rbi_RainSensor_enabled_g) && (FALSE==rbi_RainsensorDisabled_g))
#else
    if((TRUE==rbi_RainSensor_enabled_g) || (FALSE==rbi_RainsensorDisabled_g))
#endif /*_NO_RAIN_*/
    {
      /*version error*/
      bi_RS_VariantError_g = TRUE;
    }
    else
    {
      bi_RS_VariantError_g = FALSE;
    }
  }
  
#ifdef CS_RAIN  
  RainFunction();                              //Tunnel wiper,auto wiper,rain level, splash mode, rain sonser error
#endif 
  
  CheckErrors();                               //Other error signals send in this function
  VoltageDetect();                             //Send high/low voltage error
  
#ifdef CS_LIGHT
  LightFunction();                             //light request and the reason of light on 
#endif  
  
#ifdef CS_STANDBY
  StandByMode();                               //Auto close window
#endif    
  
#ifdef CS_OUTPUT_BRIGHTNESS  
  OutPutBrightnessValue();                     //output FW IR SOLAR brightness
#endif  
  
#ifdef CS_HT_MODULE
  Humidity_Function();                         //dew point & Screen temperature & sensor teamperature & relative Humidity
#endif
  
#if defined (ASIC_TEST)
  CopyRLSDataAsic();
#endif
  l_bool_wr_RLS_unused0(1);
  l_bool_wr_RLS_unused1(3);
  rb_WDG_BusTaskCounter_g++;                   //increment test counter for bus
}

#ifdef CS_RAIN
void RainFunction(void)
{
  static byte rb_OutOffParkCounter_mg;
  static byte rb_TunnelWipeTimeOut_mg;  
  word rw_tunnelWischVerzoegerung_l=(((word)CB_TUNWISCHVERZ_MG)*100);
  word rw_tunnelWischAktivierung_l=(((word)CB_TUNWISCHAKTIV_MG)*100);
  static byte rb_tunnelWipeActive_g;
  byte newWiperSpeedLin = 0;
  
  if((rb_IgnitionOndelay_mg<50))
  {
    rw_rain_intensitiy_g = 0;
    rw_AfterRSWipeCounter_mg = 50000;
  }
  if(rbi_RealParkContact_g == FALSE)     
  {                                            //wiper is running 
    if (rb_OutOffParkCounter_mg > cb_DEPRESSED_PARK_DEBOUNCE_s) 
    {
      rw_AfterWWSWipeCounter_mg = 0;
    }
    else
    {
      rb_OutOffParkCounter_mg ++;
    }
  }
  else
  {                                            //wiper in park position
    rb_OutOffParkCounter_mg = 0;
    if (rw_AfterWWSWipeCounter_mg < 50000)
    {
      rw_AfterWWSWipeCounter_mg++;
    }
  }
  
  if (rw_AfterRSWipeCounter_mg < 50000)        //Delay for Tunnel wipe function
  {
    rw_AfterRSWipeCounter_mg++;   
  } 
  
  /*VCO_260 Tunnel wipe activation and delay according to Tunnel Verzoegerung and Aktivierung parameters*/
  /*activation of afterwipe at tunnel*/
  if((rw_AfterRSWipeCounterAlt_mg <= rw_tunnelWischVerzoegerung_l)
     &&(rb_speed_in_kmh_g > 29)
       &&(rbi_modi_lightsens_tunnel_g == TRUE)
         &&(rub_RSIntermDelayInit == 0xFF))
  {
    if ((rbi_modi_lightsens_tunnel_alt_mg == FALSE) && (rw_AfterRSWipeCounter_mg < rw_tunnelWischAktivierung_l))
    {
      rb_tunnelWipeActive_g = TRUE;
    }
  }
  else
  {
    rb_tunnelWipeActive_g = FALSE;
  }

  /*trigger the afterwipe at tunnel*/
  if((rw_AfterRSWipeCounter_mg >= rw_AfterRSWipeCounterAlt_mg)
       &&(rb_tunnelWipeActive_g == TRUE)
         &&(rb_WiperSpeed_g == 0))
  {
    rb_TunnelWipeTimeOut_mg = 0;
    rbi_TunnelWipe_mg = TRUE;
    rb_tunnelWipeActive_g = FALSE;
    rw_AfterRSWipeCounterAlt_mg = 50000;
    rw_AfterRSWipeCounter_mg = 50000;

    l_u8_wr_RLS_WiperSpeed(1);
    l_u8_wr_RLS_wiperSpeed7Level(1);
  }
  else if(rbi_TunnelWipe_mg == TRUE)
  {
    if((rbi_ParkPosition_g == FALSE)||(rb_TunnelWipeTimeOut_mg >= 50))
    {
      rbi_TunnelWipe_mg = FALSE;
      rb_TunnelWipeTimeOut_mg = 0;
    }
    else
    {
      rb_TunnelWipeTimeOut_mg++;
    }
    l_u8_wr_RLS_WiperSpeed(1);
    l_u8_wr_RLS_wiperSpeed7Level(1);
  }
  else  
  {
    if(IsAutoWiper())
    {
      if(rb_WiperSpeed_g!=0)
      { 
         if ((rbi_RSWipeSlowDmd==0)&&(rbi_RSWipeFastDmd==0))
         {
           newWiperSpeedLin = 1; //interval
         }
         else if (wiperSpeed7to2(l_u8_rd_RLS_WiperSpeed(), rb_WiperSpeed_g, rb_wiperSpeedHysteresis) != 0)
         {
           newWiperSpeedLin = wiperSpeed7to2(l_u8_rd_RLS_WiperSpeed(), rb_WiperSpeed_g, rb_wiperSpeedHysteresis);  //continuous mode
         }   
      }
      else
      {
        newWiperSpeedLin = 0;
      }
      l_u8_wr_RLS_wiperSpeed7Level(rb_WiperSpeed_g);
      l_u8_wr_RLS_WiperSpeed(newWiperSpeedLin);    
    }
    else
    {
      l_u8_wr_RLS_WiperSpeed(0);
      l_u8_wr_RLS_wiperSpeed7Level(0);
    }   
    
    if(rb_WiperSpeed_g >0)
    {
      if(rb_WiperSpeedAlt_g == 0)
      {
        rw_AfterRSWipeCounterAlt_mg = rw_AfterRSWipeCounter_mg;
      }
      rw_AfterRSWipeCounter_mg = 0;
    }  
  }

  rb_WiperSpeedAlt_g = rb_WiperSpeed_g;
  rbi_modi_lightsens_tunnel_alt_mg = rbi_modi_lightsens_tunnel_g; //alter wert speichern  
  
  if(rbi_AutomaticWipingMode_g)
  {
    //l_bool_wr_RainSensoractivestatus(1);  
  }
  else
  {
    //l_bool_wr_RainSensoractivestatus(0); 
  }
  
  if(FALSE==rbi_EEPROMLoad_g)
  {
#ifndef _NO_RAIN_
    if((FALSE==rbi_RainSensor_enabled_g) && (FALSE==rbi_RainsensorDisabled_g))
#else
          if((TRUE==rbi_RainSensor_enabled_g) || (FALSE==rbi_RainsensorDisabled_g))
#endif /*_NO_RAIN_*/
    {
      /*version error*/
      bi_RS_VariantError_g = TRUE;
    }
    else
    {
      bi_RS_VariantError_g = FALSE;
    }
  }                                                     //old rbi_modi_lightsens_tunnel_g

#ifndef _NO_RAIN_
  /* VDR_124 set rain intensity to init if rain sensor is off*/
//  if(((rbi_OverVoltage_g) || (rbi_LongUnderVoltage_g))||(rbi_AutomaticWipingMode_g==FALSE) || (rbi_WashingActive_g == 1)) 
//  {
//    l_u8_wr_RLS_Rain_Intensity(0);          
//  }
//  else if(rbi_RainSensorError > 0)
//  {
//    l_u8_wr_RLS_Rain_Intensity(0);        
//  }
//  else if((rw_rain_intensitiy_g>>9)>6)                             
//  {
//    l_u8_wr_RLS_Rain_Intensity(3);                                
//  }
//  else if((rw_rain_intensitiy_g>>9)>3) 
//  {
//    l_u8_wr_RLS_Rain_Intensity(2);  
//  }
//  else if((rw_rain_intensitiy_g>>9)>1)
//  {
//    l_u8_wr_RLS_Rain_Intensity(1); 
//  }
//  else
//  {
//    l_u8_wr_RLS_Rain_Intensity(0);               
//  }
#endif /*_NO_RAIN_*/  
}
#endif 

#ifdef CS_LIGHT
void LightFunction(void)
{
  byte rb_AnyErrorCounterDebounce_l; 
  byte rb_TempLightOn_l;
  byte rb_ReasonForLightOn_l = 0;
  
 /* PRQA S 3415, 4112 1 */ /* << Getter functions must not have side effects >>*/
  if ((((((IS_LS_ANY_ERRORCOUNTER()) > 0))||((l_bool_rd_RLS_LightSensorFault()) > 0))||(((rbi_UnderVoltage_g) == TRUE))
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
    
  rb_AnyErrorCounterDebounce_l = rb_AnyErrorCounterDebounce_mg;   
                                                                                                                          /**The conditions for lamp on**/
  if(l_bool_rd_RLS_LightSensorFault() == TRUE)                                                                                 //sensor in error
  {
    rb_TempLightOn_l = TRUE;
  }
  /*VCO_50*//*VDR_129 use Sensitivity Treatment*/
  else if(((uF_modi_lightsens_g.AllBit & 0x2F)>0)||(rbi_InternalResetOccured_g > 0)||(rbi_Regulation48LightOnFlag_g !=0)) //darkness/darkstart/tunnel
  {
    rb_TempLightOn_l = TRUE;  
  }
  /*VDR_129 use Sensitivity Treatment*/
  else if((((rbi_Freewaylight_enabled_g==TRUE))&& (rbi_FastHighwayMode_g == TRUE))                                        //highway/rain
          ||(((rbi_modi_lightsens_rain_g == TRUE)&& (rbi_RainLight_enabled_g == TRUE))))
  {
    rb_TempLightOn_l = TRUE;
  }
  else
  { /* PRQA S 3415 1 */ /* << Swapping expressions not feasible for performance >>*/
    if ((rb_AnyErrorCounterDebounce_l ==0)&&(get_rb_LightVetoCounter_g()==0)) /*VCO_093 use Veto of Lightsensor*/
    {
      rb_TempLightOn_l = FALSE;
    }
    else
    {
      rb_TempLightOn_l = l_bool_rd_RLS_LowBeamOnReq();                                                               /* stay in old light mode and do */
    }
  }
  
  /**Send lamp on command**/
  if((rbi_EEPROMLoad_g == FALSE)
      && ((rb_RSControlFlags_g == cb_HUMIDITY_SOLAR )||(rb_RSControlFlags_g == cb_ONLY_HUMIDITY)))
  {
    /*Incase of only Feuchte and solar frame preset then set the light ON, FW and IR to init value for safety reason*/
    l_bool_wr_RLS_LowBeamOnReq(TRUE);   
  } 
  else
  {
    /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
    DISABLE_SCIINTERRUPT();
    l_bool_wr_RLS_LowBeamOnReq(rb_TempLightOn_l);  
    l_bool_wr_RLS_PositionLightOnReq(rb_TempLightOn_l);
    ENABLE_SCIINTERRUPT();       
  }  
                                                                                                                    /**Send the reason why should lamp on**/
  if(((rbi_LightSensorActive_g == TRUE) && (rbi_EEPROMLoad_g == FALSE)) && (rb_TempLightOn_l>0))
  { 
    /*
     if((uF_modi_lightsens_g.AllBit & cb_NIGHT_mg) && (isDarkActive() == FALSE)) 
     {
       rb_ReasonForLightOn_l = cb_TWILIGHT;
     }
     else if((uF_modi_lightsens_g.AllBit & cb_NIGHT_mg) && (isDarkActive()))
     {
       rb_ReasonForLightOn_l = cb_DARK;
     }
    */
     if(uF_modi_lightsens_g.AllBit & cb_NIGHT_mg) 
     {
       rb_ReasonForLightOn_l = cb_DARK;
     }
     else if(uF_modi_lightsens_g.AllBit & cb_TUNNEL_mg)
     {
       rb_ReasonForLightOn_l = cb_TUNNEL;
     }
     else if(uF_modi_lightsens_g.AllBit & cb_DARKSTART_mg)
     {
       rb_ReasonForLightOn_l = cb_UNDERGROUND;
     }
     else if((rbi_Freewaylight_enabled_g != FALSE)&& (rbi_FastHighwayMode_g == TRUE))
     {
       rb_ReasonForLightOn_l = cb_HIGH_SPEED;
     } 
     else if((rbi_modi_lightsens_rain_g == TRUE)&& (rbi_RainLight_enabled_g == TRUE))
     {
       rb_ReasonForLightOn_l = cb_RAIN_LIGHT;
     }
     else
     {
        rb_ReasonForLightOn_l = cb_OTHERRSEAN;    
     }
  }
  else
  {
    rb_ReasonForLightOn_l = 0;
  }
  l_u8_wr_RLS_LightSWReason(rb_ReasonForLightOn_l);   
}
#endif

#ifdef CS_HT_MODULE
void Humidity_Function(void)
{
  static word rw_Temperature_Sensor_g;
  //static word rw_Temperature_Scheibe_g;
  
  if (rbi_HumTempComError_g != 0)
  {
    l_u16_wr_RLS2_Status_DewPointTemp_Value(0X3FF);             //dew point temperature
    l_u8_wr_RLS2_Status_RelativeHumidity_Lvl(0XFF);             //relative Humidity
    l_u8_wr_RLS2_Status_WinGlassTemp_Value(0XFF);               //window temperature   
  }
  else
  {
                                                               /*the temperature of screen ,the range is -39.5~60.4*/
//    if(rw_Temperature_raw_g < 0x2D5)                         // The temperature less than -39,5 the tool doesnot support 
//    {
//      rw_Temperature_Scheibe_g = 0x2D5;
//    }
//    else if(rw_Temperature_raw_g > 0x29E5)                   // The temperature greater than 60,4 the tool doesnot support
//    {
//      rw_Temperature_Scheibe_g = 0x29E5;
//      //l_u8_wr_L_Err_State_Over_Temp(1);
//    }
//    else
//    {
//      rw_Temperature_Scheibe_g = rw_Temperature_raw_g;
//      //l_u8_wr_L_Err_State_Over_Temp(0);
//    }    
//           
//    if(rw_Temperature_raw_g == cw_HUMTEMP_INIT_g)
//    {
//      //l_u16_wr_L_Window_Temp(0);
//    }
//    else
//    {
//      if(((rw_Temperature_Scheibe_g -725)/10) < 1000)
//      {        
//        l_u16_wr_RLS2_Status_WinGlassTemp_Value(((rw_Temperature_Scheibe_g -725)/10));
//      }
//      else
//      {         
//        l_u16_wr_RLS2_Status_WinGlassTemp_Value(1000);
//      }
//    } 
    
    
    if (rw_DewPoint_g == cw_HUMTEMP_INIT_g)
    {
      l_u16_wr_RLS2_Status_DewPointTemp_Value(0X3FF);
    }    
    else
    {
      if (rw_DewPoint_g < cw_DEWPOINT_MAX_mg )                /* dew point should be less than or equal to Scheibe temperature */
      {
                                                                       
        l_u16_wr_RLS2_Status_DewPointTemp_Value(rw_DewPoint_g-1); 
        
      }
      else
      {
        l_u16_wr_RLS2_Status_DewPointTemp_Value(cw_DEWPOINT_MAX_mg-1);
      }
    }
        
    if (rb_Humidity_g == cw_HUMTEMP_INIT_g)                   /* Relative Humidity output*/ /*VCO_061 name hase changed*/
    {
      l_u8_wr_RLS2_Status_RelativeHumidity_Lvl(0XFF);
    }        
    else
    {        
      l_u8_wr_RLS2_Status_RelativeHumidity_Lvl(rb_Humidity_g);
    }
   
                                                              /*the temperature of inter sensor , not screen  range -39.5~87.5*/
    if(rw_Temperature_raw_g < 0x2AD) /* The temperature less than -39,5 the tool doesnot support */
    {
      rw_Temperature_Sensor_g = 0x2AD;    
    }
    else if(rw_Temperature_raw_g > 0x3449)/* The temperature greater than 87,5 the tool doesnot support */
    {
      rw_Temperature_Sensor_g = 0x3449;
    }
    else
    {
      rw_Temperature_Sensor_g = rw_Temperature_raw_g;
    }  
    if(rw_Temperature_raw_g == cw_HUMTEMP_INIT_g)
    {
      l_u8_wr_RLS2_Status_WinGlassTemp_Value(0);
    }
    else
    {   
      if(((rw_Temperature_Sensor_g-685)/50) < 250)
      {
        
        l_u8_wr_RLS2_Status_WinGlassTemp_Value(((rw_Temperature_Sensor_g-685)/50)+1);
      }
      else
      {
        l_u8_wr_RLS2_Status_WinGlassTemp_Value(1);
      }
    }        
  }
}
#endif

#ifdef CS_STANDBY
void StandByMode(void)
{
  if((rb_Verglasun_ClosedDebounce_mg > cb_VERGLSUNG_CLOSE_DELAY_mg)||(rbi_Ignition_g== TRUE)||(rw_CommandCloseWindowTimout_mg > 6000))
  {
    rbi_Command_CloseWindows_g = FALSE;
    rbi_ASICStandByModeRequest_g = FALSE;
    if(rw_CommandCloseWindowTimout_mg > 6000)
    {
      rb_standbyOff_g = 1;
    }
  }
    
  if(rbi_SendWakeUpFrame_g == TRUE)
  {
    ApplLinInit(0x01);                                  // send wakup frame
    rbi_SendWakeUpFrame_g = FALSE;                      
  }

  if(rbi_Command_CloseWindows_g == TRUE)
  {
    SendClosedWindowCmd_Close();                        // send close window command
    if (rw_CommandCloseWindowTimout_mg > 6000)          // last for 60s
    {
      rbi_ASICStandByModeRequest_g = 0;
    }
    else
    {
      rw_CommandCloseWindowTimout_mg++;
    }
  }
  else
  {
    if(rw_CommandCloseWindowTimout_mg < 6000)           //in 60s closed window then reset the count else do not handle
    {
      rw_CommandCloseWindowTimout_mg = 0;
    }   
    SendClosedWindowCmd_NClose();
  }
/**
  if(rbi_StandbyFunction_enabled_g == TRUE)               //send standby function status
  {
    SendStandbyMode_ON();
  }
  else if(rbi_StandbyFunction_enabled_g == FALSE)
  {
    SendStandbyMode_OFF();
  }
  else{}
**/
}
#endif

#ifdef CS_OUTPUT_BRIGHTNESS
void OutPutBrightnessValue(void)
{
  static byte rb_InitLightValCnt_l=100;
  byte rb_Helligkeitsboost_l = 15;                                       /*VCO_103 local variable for brightness boost*/ 
  word rw_Hellighkeitsthrs;                                              /*VCO_103 local variable for brightness boost*/
  word rw_IrLightforSOSE_Corr1_l;
  word rw_IrLightforSOSE_Corr2_l;
  word rw_SoSe_SunInt_2D_Le_l;
  word rw_SoSe_SunInt_2D_Re_l;  
  word rw_FW_brightness_l;
  
  if((rbi_LightValuesInitialised_g == FALSE)|| (rbi_EEPROMLoad_g == TRUE))
  {
                                                                         //hold the previous values
    if(rb_InitLightValCnt_l<100)
    {
      rb_InitLightValCnt_l++;
    }
    else
    {      
      l_u16_wr_RLS_FwBrightness(0X7FF);                                  //FW INITIAL
      l_u16_wr_RLS_AmbBrightness(0x3FF);
      l_u8_wr_RLS_IRBrightness(0xFF);      
      l_u8_wr_RLS_SolarRight(0xFF); /* Init/nicht verfuegbar */
      l_u8_wr_RLS_SolarLeft(0xFF); /* Init/nicht verfuegbar */
    }
  }
  else
  {
    rb_InitLightValCnt_l=0;
    if(rb_RSControlFlags_g == cb_ONLY_HUMIDITY)
    {
      /*Incase of only Feuchte and solar frame preset then set the light ON, FW and IR to init value for safety reason*/ 
      l_u16_wr_RLS_FwBrightness(0X7FF);                                  //FW INITIAL
      l_u16_wr_RLS_AmbBrightness(0x3FF);
      l_u8_wr_RLS_IRBrightness(0xFF);      
      l_u8_wr_RLS_SolarRight(0xFF); /* Init/nicht verfuegbar */
      l_u8_wr_RLS_SolarLeft(0xFF); /* Init/nicht verfuegbar */
    }
    else if(l_bool_rd_RLS_LightSensorFault() == TRUE)                    /*  VDR469   set for error*/
    {
      l_u16_wr_RLS_AmbBrightness(0x3FE);
      l_u8_wr_RLS_IRBrightness(0xFE);
      l_u16_wr_RLS_FwBrightness(0X7FE);
      l_u8_wr_RLS_SolarRight(0xFE); /* Init/nicht verfuegbar */
      l_u8_wr_RLS_SolarLeft(0xFE); /* Init/nicht verfuegbar */
    }
    else
    {     
      if(rb_RSControlFlags_g == cb_HUMIDITY_SOLAR )
      {
        l_u16_wr_RLS_FwBrightness(0X7FF);                                  //FW INITIAL
        l_u16_wr_RLS_AmbBrightness(0x3FF);
        l_u8_wr_RLS_IRBrightness(0xFF);      
        l_u8_wr_RLS_SolarRight(0xFF); /* Init/nicht verfuegbar */
        l_u8_wr_RLS_SolarLeft(0xFF); /* Init/nicht verfuegbar */
      }
      else
      {
        if(get_rw_FW_light16bit_g() < 0x7fe)                           /*VCO_031 correct variable 0x03FD*/
        {
           rw_FW_brightness_l = get_rw_FW_light16bit_g();
        }
        else
        {
          rw_FW_brightness_l = 0x7fe;
          rw_Hellighkeitsthrs = 0x7fe;                                /*VCO_103 calculate brightness boost*/ 
          do 
          {
            rw_Hellighkeitsthrs += rw_Hellighkeitsthrs/10;             /*VCO_103 calculate threshold*/ 
            rb_Helligkeitsboost_l-- ;
          }
          while ((get_rw_FW_light16bit_g() >= rw_Hellighkeitsthrs)&&(rb_Helligkeitsboost_l >0));
          
        }
        rw_FW_brightness_l = rw_FW_brightness_l;
        l_u16_wr_RLS_FwBrightness(((rw_FW_brightness_l>2045)?2045:rw_FW_brightness_l));

        if(get_rw_Amb_light16bit_g()/2 < 1021)                           /*VCO_031 correct variable 0x03FD*/
        {
          l_u16_wr_RLS_AmbBrightness(get_rw_Amb_light16bit_g()/2);
        }
        else
        {
          l_u16_wr_RLS_AmbBrightness(1021);
        }        
      }
      
      if(rb_IrLightDiv8_g < 0xFD)
      {
        l_u8_wr_RLS_IRBrightness((byte)rb_IrLightDiv8_g);
      }
      else
      {
        l_u8_wr_RLS_IRBrightness(0xFD);     // IR Helligkeit max
      }
 
#ifdef CS_SOLAR
      if ((rbi_SoSe_Enabled_g == TRUE)&& (TRUE == rbi_SolarValuesInitialised_g))
      {
        if (rb_SolarShadowCorrFactor1_g > 0)
        {
          rw_IrLightforSOSE_Corr1_l= get_rw_IR_light16bit_g()/rb_SolarShadowCorrFactor1_g; 
        }
        else 
        {
          rw_IrLightforSOSE_Corr1_l = 0;  /*Function deactivated*/
        }
        
        if((rw_IrLightforSOSE_Corr1_l) > (rw_Solar_light16bit_2_g))
        {
          rw_SoSe_SunInt_2D_Le_l = rw_IrLightforSOSE_Corr1_l;
        }
        else
        {
          rw_SoSe_SunInt_2D_Le_l = rw_Solar_light16bit_2_g ;
        }
        
        
        if((rw_IrLightforSOSE_Corr1_l) > (rw_Solar_light16bit_1_g))
        {
          rw_SoSe_SunInt_2D_Re_l = rw_IrLightforSOSE_Corr1_l;
        }
        else
        {
          rw_SoSe_SunInt_2D_Re_l = rw_Solar_light16bit_1_g ;
        }    
        
        if (rb_SolarShadowCorrFactor2_g > 0)
        {
          rw_IrLightforSOSE_Corr2_l= get_rw_IR_light16bit_g()/rb_SolarShadowCorrFactor2_g; 
        }
        else 
        {
          rw_IrLightforSOSE_Corr2_l = 0;  /*Function deactivated*/
        }
        
        if((rw_IrLightforSOSE_Corr2_l >= rw_SoSe_SunInt_2D_Le_l) && (rw_IrLightforSOSE_Corr2_l >= rw_SoSe_SunInt_2D_Re_l)) 
        {
          rw_SoSe_SunInt_2D_Le_l = rw_IrLightforSOSE_Corr2_l;
          rw_SoSe_SunInt_2D_Re_l = rw_IrLightforSOSE_Corr2_l;
        }
        rw_SoSe_SunInt_2D_Le_l=(rw_SoSe_SunInt_2D_Le_l>>1);
        rw_SoSe_SunInt_2D_Le_l=((rw_SoSe_SunInt_2D_Le_l>253)?253:rw_SoSe_SunInt_2D_Le_l);
        l_u8_wr_RLS_SolarLeft(rw_SoSe_SunInt_2D_Le_l);
        
        rw_SoSe_SunInt_2D_Re_l=(rw_SoSe_SunInt_2D_Re_l>>1);
        rw_SoSe_SunInt_2D_Re_l=((rw_SoSe_SunInt_2D_Re_l>253)?253:rw_SoSe_SunInt_2D_Re_l);
        l_u8_wr_RLS_SolarRight(rw_SoSe_SunInt_2D_Re_l);       
      }
      else
      {
        l_u8_wr_RLS_SolarRight(0xFE); /* Init/nicht verfuegbar */
        l_u8_wr_RLS_SolarLeft(0xFE); /* Init/nicht verfuegbar */
      }
#endif      
    }
  } 
}
#endif

void VoltageDetect(void)
{
  static byte rb_underVoltageTimer_s;
  
  if(rbi_UnderVoltage_g == TRUE)                         //undervoltage, Overvoltage ?
  {
    if(rb_underVoltageTimer_s>200)                       // undervoltagetimer > 249 -> 2500 ms abwarten
    {
      rbi_LongUnderVoltage_g = 1;
    }
    else
    {
      rb_underVoltageTimer_s++;                          // increase undervoltagetimer
    }
  }
  else
  {
    rb_underVoltageTimer_s=0;                            // loesche Timer
    rbi_LongUnderVoltage_g = 0;
  }
  
  if(rbi_LongUnderVoltage_g == TRUE)
  {
    SendLowVoltageError();
  }
  else if(rbi_OverVoltage_g == TRUE)
  {
    SendHighVoltageError();
  }
  else
  {
    SendNoVoltageError()
  }    
}

void getLightTransmission(byte trans_550nm,byte trans_880nm)
{
  byte rb_880nm_Transmission_local_Coding = 0;
  byte rb_550nm_Transmission_local_Coding = 0;
  
  rb_550nm_Transmission_local_Coding = (trans_550nm);
  rb_550nm_Transmission_local_Coding = (((rb_550nm_Transmission_local_Coding > 90) && (rb_550nm_Transmission_local_Coding <= 100))? 90 : rb_550nm_Transmission_local_Coding);
  
  rb_880nm_Transmission_local_Coding = (trans_880nm);
  rb_880nm_Transmission_local_Coding = (((rb_880nm_Transmission_local_Coding > 90) && (rb_880nm_Transmission_local_Coding <= 100))? 90 : rb_880nm_Transmission_local_Coding);
  
  if((rb_550nm_Transmission_local_Coding >= 15) && (rb_550nm_Transmission_local_Coding <= 90))
  {
    rb_550nm_Transmission_local_Coding = ((rb_550nm_Transmission_local_Coding-15) + 2) / 5; 
  }
  else
  {
    rb_550nm_Transmission_local_Coding = 0 ;
  }
  
  if((rb_880nm_Transmission_local_Coding >= 15) && (rb_880nm_Transmission_local_Coding <= 90))
  {
    rb_880nm_Transmission_local_Coding = ((rb_880nm_Transmission_local_Coding-15) + 2) / 5; 
  }
  else
  {
    rb_880nm_Transmission_local_Coding = 0 ;
  }
  
  if(((rb_880nm_Transmission_local_Coding > 0) && (rb_550nm_Transmission_local_Coding > 0))
         && (rb_Kodierbyte2_g != ((rb_880nm_Transmission_local_Coding << 4) | rb_550nm_Transmission_local_Coding))
         && ((rbi_EEPROMBytesToWrite_g == FALSE)||(rbi_EEPROMBytesWritten_g == TRUE)))
  {
      rab_EEPROM_Bytes_toWrite_g[0] = ((rb_880nm_Transmission_local_Coding << 4) | rb_550nm_Transmission_local_Coding);
      rw_EEPROM_Address_to_Write_g = cw_EEPROM_CODING_ADDRESS_g; /*set adress to write*/
      rb_I2C_EEPROM_bytesToWrite_g = 1;         /*set number of bytes to 1*/
      rbi_EEPROMBytesToWrite_g = TRUE;
      rbi_EEPROMBytesWritten_g = FALSE;
  }
}

#pragma inline=forced
static void CheckErrors(void)
{
  
#ifdef CS_HT_MODULE
  //l_bool_wr_L_Err_State_Humidity_Sens(rbi_HumTempComError_g);                             //Hud error statue
#endif
  
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
  /*VCO_224 RS_Error should be set only by RAM/ROM error, when RS function is coded as inactive in kodierbyte0*/
  l_bool_wr_RLS_RainSensorFault((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_RainS_Error1_g != 0) ||(rbi_HammingError_g != 0));  
  l_bool_wr_RLS_LightSensorFault((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(rbi_HammingError_g != 0)||(rbi_CRC_ChangedByDiagnostic_g));
}

void ApplLinInit(byte rb_LIN_State_l)
{
  
  // init unused bits to 1
  byte rb_Index_l; 
  static const byte LinMsgDefault_RLSs_01[8] = {8,12,255,255,255,199,255,255};   /* id: 0x011 */
  //static const byte LinMsgDefault_RLSs_02[8] = {0x00,0x00,0x00,0xf8,0xfb,0x03,0x00,0x00};   /* id: 0x023 */
  
  rb_Index_l = 0;
  do
  {
    RLS_StatusInfo._c[rb_Index_l] = LinMsgDefault_RLSs_01[rb_Index_l];
    //RLS_02._c[rb_Index_l] = LinMsgDefault_RLSs_02[rb_Index_l];
    rb_Index_l++;
  } while (rb_Index_l < 8);
    
#ifdef _SUPPORTMWLLIGHT_
  Diagnose_ReadMem_Init();
#endif
  rw_AfterRSWipeCounter_mg = 50000;
  rw_AfterRSWipeCounterAlt_mg = 50000;
  rw_AfterWWSWipeCounter_mg = 50000;                                                      //Direktbitdelay bei Kl15 Aus hochsetzen!
  sci_init(rb_LIN_State_l);
  rbi_RealParkContact_g = TRUE;
  rbi_ParkPosition_g = TRUE;
  rb_PotiStageFromBox_g = 3;  
  rw_WipeCommandTimOut_mg = 0;                                                           
  rb_AnyErrorCounterDebounce_mg = 200;                                                    /*VDR_408 use init value*/
  
}

__callt void ApplLinSlavePreCopy(byte rb_MessageID_l)                                     /* callt function faster */
{
  if(rb_MessageID_l == (rb_IDRLSs_01_g & 0x3F))
  {
    l_bool_wr_RLS_ResponseError(rbi_latched_ResponseError_mg);
    rbi_latched_ResponseError_mg = FALSE;
  } 
}