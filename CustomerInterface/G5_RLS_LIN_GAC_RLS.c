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
#define cb_NIGHT                    0x02
#define cb_RAIN_LIGHT               0x03
#define cb_TWILIGHT_RAIN_LIGHT      0x04
#define cb_NIGHT_RAIN_LIGHT         0x05
#define cb_TUNNEL                   0x06
#define cb_TUNNEL_RAIN_LIGHT        0x07
#define cb_UNDERGROUND              0x08
#define cb_UNDERGROUND_RAIN_LIGHT   0x09
#define cb_HIGH_SPEED               0x0A
#define cb_ECE48                    0x0B
#define cb_Error                    0x0C
#define cb_OTHERRSEAN               0x0D
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

#define cb_NORMAL_WIPE_MODE   1
#define cb_LIMITED_SPEED_MODE 2
#define cb_SPLASH_WIPE_MODE   3
#define cb_WINTER_WIPE_MODE   4
#define cb_TRAFFIC_LIGHT_MODE 5

#define cb_OTHER 0
#define cb_AUTO  1

#define cb_VECHILE_INVAILD   0x0 
#define cb_A86_BIT   0x1 
#define cb_A39_BIT   0x2
#define cb_A90_BIT   0x3

#define cb_A86   0x93 
#define cb_A39   0x1A 
#define cb_A90   0x94
#define cb_Vehicle_MAX 3

/*0%,20%,40%,60%,-15%,-30%,-45%,-60%*/
//static const byte cab_PotistageMapping_mg[8] = {4,5,6,7,3,2,1,0}; /*mapping for potistages!*/

/*-60%,-45%,-30%,-15%,%0,%20,40%,60%*/
static const byte cab_PotistageMapping_mg[8] = {0,1,2,3,5,4,6,7}; /*mapping for potistages!*/

static const byte cab_Transmissonion550[4] ={75,75,75,85};
static const byte cab_Transmissonion880[4] ={45,45,45,35};

//static const byte cab_Vehicle_Type[3] ={0x93,0x1A,0x94};
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
byte WipeSpeedStrategyEvaluation(byte rb_CurrSpeed);
void GetRainPotiStage(byte rb_PotiStageCurrent);
void SetRainSplashStatus(byte status);
void CheckBCMTransmission(void);
void CheckBCMVehicle(void);
byte WiperSwitchChangeRequest(byte rb_CurrSpeed);
byte TunnelWipeCheck(void);
void NormalWipeActionCheckSend(void);
void WipeNormalModeCheck(void);
void WipeWinterModeCheck(void);
void WipeSplashModeCheck(void);
void WipeTrafficModeCheck(void);
void WipeLimitModeCheck(void);


//static byte rb_Verglasun_offenDebounce_mg,rb_Verglasun_ClosedDebounce_mg;
//static word rw_CommandCloseWindowTimout_mg;
static byte rb_KL15_mg;
static byte rb_AnyErrorCounterDebounce_mg;
static word rw_AfterRSWipeCounter_mg;                   // Time after last wipe from RS
static word rw_AfterRSWipeCounterAlt_mg;              //Time to the last wipe from RS
static word rw_AfterWWSWipeCounter_mg;                  // Time after last wipe from WWS
static word rw_WipeCommandTimOut_mg;                    //timout for requested wipe
static byte rb_IgnitionOndelay_mg = 0;
static byte rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;
static byte rb_TunnelWipeModeFlag_mg = 0;
static byte  rb_WipeSpeedIsReally_mg = 0;//
static byte  rb_WipeSpeedLastRun_mg = 0;
static byte  rb_PotiStageIncreaseFlag = 0;
static byte  rb_oldRainPotiStage_mg = 0;   
static byte rb_RLS_msgCounter_g =0;
static byte rb_WipeSpeedIsValid_mg =0;
static byte rb_FirstEnterWinterMode_mg =0;
static byte rb_CurrentSpeed_mg = 0;
static byte rb_TrafficWipeStart_mg = 0;
static byte rb_OtherWipeTimeOut_mg = 0;
static byte rb_OutsideTempVD_mg = 0;
static int  rb_OutsideTemp_mg  = 1;
static byte rb_OldwiperSwitchStatus_mg = 0;   //staus 

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
  byte rb_Empfindlichkeit_LS_l;
 
  if(l_flg_tst_BCM_LIN1_1())
  { 
    l_flg_clr_BCM_LIN1_1();
    rw_NoCommunicationCounter_g = 0;                                 // reset no communication counter
    rbi_ConnectedToMaster_g = 1;   
    
    if(l_u8_rd_BCM_RTSWiperPark() == 2)
    {
       rbi_RealParkContact_g = 1;            
    }
    else if(l_u8_rd_BCM_RTSWiperPark() == 1)
    {
       rbi_RealParkContact_g = 0;   
    }
    else
    {
      
    }
    rb_OutsideTempVD_mg = l_bool_rd_HVAC_CorrectedExterTempVD();
    rb_OutsideTemp_mg = l_u8_rd_HVAC_CorrectedExterTemp() -40;
    rbi_LightSensitivityRecieved_g = TRUE;    
    rb_speed_in_kmh_g  = ((l_u16_rd_BCS_VehSpd())+((l_u16_rd_BCS_VehSpd())>>3))/20;// N*0.05625      
    if((l_u16_rd_BCS_VehSpd()) > 4266)
    {
      rb_speed_in_kmh_g = 240;
    }
    else {}
    
    rb_WipeSpeedIsValid_mg = l_bool_rd_BCS_VehSpdVD();
    if(rb_WipeSpeedIsValid_mg == 0)
    {
        rb_speed_in_kmh_g = 80;                           /* set speed to (80 km/h)*/
    }
    
    if(rb_speed_in_kmh_g >= 10)
    {
      rbi_speedWasAbove10kmh_g = TRUE;
    }
        
    rb_KL15_mg=((l_u8_rd_BCM_KeySt() == 2)?1:0);                            
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
        if((l_u8_rd_BCM_WiperCtr() == 1)                         //automatic
            || (rbi_RainsensorAlwaysOn_g != FALSE))
        {
          rbi_AutomaticWipingMode_g = TRUE;                            /*Rainsensor always active!*/
          rb_OldwiperSwitchStatus_mg = cb_AUTO;              //SEVEN
        }
        else
        {
          rbi_AutomaticWipingMode_g = FALSE;                           /*Rainsensor off!*/
          rb_OldwiperSwitchStatus_mg = cb_OTHER;
        }
      }
      else
      {
        rbi_AutomaticWipingMode_g = FALSE;                             //Rainsensor off!
        rb_OldwiperSwitchStatus_mg = cb_OTHER;
      }
      
      if(l_u8_rd_BCM_WiperCtr() == 1)                            // copy automatic wiping mode
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
    
    rb_LIN_SensitivityShift_g =  7;//adaptation Variable for sensitivity factor  
    GetRainPotiStage(l_u8_rd_BCM_RSSens());
     
    rb_Empfindlichkeit_LS_l = 3; //light sensor sensitivity adjust 
    if((cab_PotistageMapping_mg[l_u16_rd_BCM_LSSens()]+rb_Empfindlichkeit_LS_l)>3)
    {
      rb_LSPotiStage_g = (cab_PotistageMapping_mg[l_u16_rd_BCM_LSSens()]+rb_Empfindlichkeit_LS_l)-3;
      if(rb_LSPotiStage_g>7)
      {
        rb_LSPotiStage_g=7;
      }
    }
    else
    {
      rb_LSPotiStage_g = 0;
    }
    CheckBCMVehicle();
    //CheckBCMTransmission();
    
    if (l_u8_rd_BCM_WiperCtr()==5)                                 /* Washpump activ? 0x5:Front washing*/
    {
      rbi_WashingActive_g = TRUE;                                       /* set Washing activ bit */
      if(rb_OldwiperSwitchStatus_mg == cb_AUTO)                        /* set Washing activ and rainwipe active */
      {
        rbi_AutomaticWipingMode_g = TRUE;
      }
      else
      {
        rbi_AutomaticWipingMode_g = FALSE;
      }
        
    }
    else if (rbi_ParkPosition_g == TRUE)                                /* In Parkposition ? */
    {
      rbi_WashingActive_g = FALSE;                                      /* Clear Washing active bit */
    }
    else{}                                                              /*Do nothing, Dummy-else for Misra Check*/
 
  }  
  else                                                                  //keine neue Master Nachricht!
  {                                                                     // check if system is on -> to switch off 
    if((rw_NoCommunicationCounter_g > CW_LIN_E2_IDLE_TIMOUT))                               /***4S***/
    {   
      rbi_ASICStandByModeRequest_g = FALSE;
      rbi_GotoSleep_g = TRUE; 
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
  
  if ((rb_WiperSpeed_g > 0)&&(rbi_RealParkContact_g== TRUE))
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

  if(    ((l_u8_rd_BCM_WiperCtr() != 1)    //auto wiper
       && (rbi_RealParkContact_g == TRUE))
       ||(rw_WipeCommandTimOut_mg > cw_CLEARWIPE_DELAY_s))
  {
    if((rb_WiperSpeed_g > 0)||(rbi_ParkPosition_g == FALSE))
    {
      if(rb_parkpositioncounter_s>10)            // Parkpositioncounter groesser 10
      {
        rbi_ParkPosition_g = FALSE;              // delete bit for Parkposition
      }
      rb_parkpositioncounter_s++;                // increase Parkpositionscounter
    }
    
    if(rb_parkpositioncounter_s > (cab_WiperMotorRunntime_mg[rb_WiperSpeed_g]))
    {
      rw_WipeCommandTimOut_mg = 0;
      rbi_ParkPosition_g = TRUE;               
      rb_parkpositioncounter_s = 0;            
    }
  }
  else    
  {
    if(rb_WiperSpeed_g > 0)
    {
      rbi_WiperStarted_g = TRUE;
    }
    
    if(rbi_RealParkContact_g == TRUE)            // In Parklagensignal ?
    {
      if(rbi_ParkPosition_g == FALSE)
      {
        rb_parkpositioncounter_s=0;              // Parkpositioncounter zuruecksetzen
      }
      else
      {
        if(rb_parkpositioncounter_s < 255)
        {
          rb_parkpositioncounter_s++;
        }
      }
      rbi_ParkPosition_g = TRUE;                 // Parkposition True
      if (rub_IntermDelayTime > 5)               // clear option for Wiper Started Flag!
      {
        rbi_WiperStarted_g = FALSE;
      }
    }
    else
    {
      rb_LimitMemomryNoWiperReaction_g = FALSE;
      rbi_WiperStarted_g = FALSE;
      rw_WipeCommandTimOut_mg = 0;               // reset Timout if wiper motor wants not wipe
      if(rb_parkpositioncounter_s>7)             // Parkpositioncounter groesser 8
      {
        rbi_WiperStarted_g = FALSE;
        rbi_ParkPosition_g = FALSE;              // loesche bit fuer Parkposition
      }
      else
      {
        rb_parkpositioncounter_s++;              // inkrementiere Parkpositionscounter
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
  
  if(l_flg_tst_RLS_2())
  {
    l_flg_clr_RLS_2() ;
    rbi_ConnectedToMaster_g = 1; 
  }
  if(l_flg_tst_RLS_1())
  {
    
    l_flg_clr_RLS_1() ;
    rbi_ConnectedToMaster_g = 1; 
    if( rb_RLS_msgCounter_g > 0)
    {
      rb_RLS_msgCounter_g--;
    }
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
  
  RainFunction();                              //Tunnel wiper,auto wiper,rain level, splash mode, rain sonser error
  CheckErrors();                               //Other error signals send in this function
  VoltageDetect();                             //Send high/low voltage error
  LightFunction();                             //light request and the reason of light on 
#ifdef CS_STANDBY
  StandByMode();                               //Auto close window
#endif    
  
#ifdef CS_OUTPUT_BRIGHTNESS  
  OutPutBrightnessValue();                     //output FW IR SOLAR brightness
#endif  
 
  
#if defined (ASIC_TEST)
  CopyRLSDataAsic();
#endif

  rb_WDG_BusTaskCounter_g++;                   //increment test counter for bus
}

void RainFunction(void)
{
  static byte rb_OutOffParkCounter_mg;
  static byte rb_TunnelWipeTimeOut_mg;  
  static byte rb_tunnelWipeActive_g;
  
  word rw_tunnelWischVerzoegerung_l=(((word)CB_TUNWISCHVERZ_MG)*100);
  word rw_tunnelWischAktivierung_l=(((word)CB_TUNWISCHAKTIV_MG)*100);
  byte newWiperSpeedLin = 0;
  
  if((rb_IgnitionOndelay_mg <50))
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

    l_u8_wr_RLS_WiperSpd(1); //l_u8_wr_RLS_WiperSpd
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
    l_u8_wr_RLS_WiperSpd(1);
  }
  else  
  {
    if(l_u8_rd_BCM_WiperCtr() == 1)
    {
      if(rb_WiperSpeed_g!=0)
      {
         if ((rbi_RSWipeSlowDmd==0)&&(rbi_RSWipeFastDmd==0))
         {
           newWiperSpeedLin = 1; //interval
         }
         else if (wiperSpeed7to2(l_u8_rd_RLS_WiperSpd(), rb_WiperSpeed_g, rb_wiperSpeedHysteresis) != 0)
         {
           newWiperSpeedLin = wiperSpeed7to2(l_u8_rd_RLS_WiperSpd(), rb_WiperSpeed_g, rb_wiperSpeedHysteresis);  //continuous mode
         }   
      }
      else
      {
        newWiperSpeedLin = 0;
      }        
    }
    else
    {
      newWiperSpeedLin = 0;
    }
       
    newWiperSpeedLin    = WiperSwitchChangeRequest(newWiperSpeedLin);
    rb_WipeSpeedLastRun_mg    = WipeSpeedStrategyEvaluation(newWiperSpeedLin);  
    if(rb_WipeSpeedLastRun_mg >0)
    {
      if(rb_WiperSpeedAlt_g == 0)
      {
        rw_AfterRSWipeCounterAlt_mg = rw_AfterRSWipeCounter_mg;
      }
      rw_AfterRSWipeCounter_mg = 0;
    }
    
    //if rain speed need to run and is not Sensitivity change 
    if((rb_WipeSpeedLastRun_mg != 0) && (rb_WiperSpeed_g!=0)&& (FALSE == rb_PotiStageIncreaseFlag))
    {
       rb_WipeSpeedIsReally_mg = TRUE;
    }
    
    //Sensitivity change  need to clean
    if((TRUE == rb_PotiStageIncreaseFlag)&&(rb_WiperSpeedAlt_g != 0)&& (rb_WipeSpeedLastRun_mg==0))
    {
      rb_PotiStageIncreaseFlag = FALSE;
    }
    
  }
  
  // for sending wiper request at least 4 times
  if((rb_WipeSpeedLastRun_mg > 0) && (rb_WiperSpeedAlt_g == 0))
  {
    rb_RLS_msgCounter_g = 3;                                      
  }
  
  if((rb_RLS_msgCounter_g != 0) && (rb_WipeSpeedLastRun_mg == 0))
  {
     l_u8_wr_RLS_WiperSpd(1);
  }
  
  rb_WiperSpeedAlt_g = rb_WipeSpeedLastRun_mg;
  rbi_modi_lightsens_tunnel_alt_mg = rbi_modi_lightsens_tunnel_g; //alter wert speichern  
    
}

void LightFunction(void)
{
  byte rb_AnyErrorCounterDebounce_l; 
  byte rb_TempLightOn_l;
  byte rb_ReasonForLightOn_l = 0;
  
 /* PRQA S 3415, 4112 1 */ /* << Getter functions must not have side effects >>*/
  if ((((((IS_LS_ANY_ERRORCOUNTER()) > 0))||((l_bool_rd_RLS_LSErr()) > 0))||(((rbi_UnderVoltage_g) == TRUE))
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
  if(l_bool_rd_RLS_LSErr() == TRUE)                                                                                 //sensor in error
  {
    rb_TempLightOn_l = TRUE;
  }
  /*VCO_50*//*VDR_129 use Sensitivity Treatment*/
  else if(((uF_modi_lightsens_g.AllBit & 0x2F)>0)||(rbi_InternalResetOccured_g > 0)||(rbi_Regulation48LightOnFlag_g !=0)) //darkness/darkstart/tunnel
  {
    rb_TempLightOn_l = TRUE;  
  }
  /*VDR_129 use Sensitivity Treatment*/
  else if((((rbi_Freewaylight_enabled_g==TRUE))&& (rbi_FastHighwayMode_g == TRUE)&&(l_bool_rd_BCM_SpeedLight()== TRUE))                                        //highway/rain
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
      rb_TempLightOn_l = l_bool_rd_RLS_LightOnReq();                                                                      /* stay in old light mode and do */
    }
  } 
    
  /**Send lamp on command**/
  if((rbi_EEPROMLoad_g == FALSE)
      && ((rb_RSControlFlags_g == cb_HUMIDITY_SOLAR )||(rb_RSControlFlags_g == cb_ONLY_HUMIDITY)))
  {
    /*Incase of only Feuchte and solar frame preset then set the light ON, FW and IR to init value for safety reason*/
    l_bool_wr_RLS_LightOnReq(TRUE);   
    l_bool_wr_RLS_PositionLightSt(TRUE);
  } 
  else
  {
    /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
      DISABLE_SCIINTERRUPT();
      l_bool_wr_RLS_LightOnReq(rb_TempLightOn_l); 
      l_bool_wr_RLS_PositionLightSt(rb_TempLightOn_l);
      ENABLE_SCIINTERRUPT();
  }
                                                                                                                          /**Send the reason why should lamp on**/
 if(((rbi_LightSensorActive_g == TRUE) && (rbi_EEPROMLoad_g == FALSE)) && (rb_TempLightOn_l>0))
 {        
     /*if((uF_modi_lightsens_g.AllBit & cb_NIGHT_mg) && (isDarkActive() == FALSE)) 
     {
       rb_ReasonForLightOn_l = cb_TWILIGHT;
     }
    else*/ 
    if(l_bool_rd_RLS_LSErr() == TRUE)
    {
      rb_ReasonForLightOn_l = cb_Error;
    }
    else if((rbi_Freewaylight_enabled_g != FALSE)&& (rbi_FastHighwayMode_g == TRUE))
    {
      rb_ReasonForLightOn_l = cb_HIGH_SPEED;
    } 
    else if((uF_modi_lightsens_g.AllBit & cb_DARKSTART_mg)&&(rbi_modi_lightsens_rain_g == TRUE)&& (rbi_RainLight_enabled_g == TRUE))
    {
      rb_ReasonForLightOn_l = cb_UNDERGROUND_RAIN_LIGHT;
    }
    else if((uF_modi_lightsens_g.AllBit & cb_TUNNEL_mg)&&(rbi_modi_lightsens_rain_g == TRUE)&& (rbi_RainLight_enabled_g == TRUE))
    {
      rb_ReasonForLightOn_l = cb_TUNNEL_RAIN_LIGHT;
    }
    else if((uF_modi_lightsens_g.AllBit & cb_NIGHT_mg)&&(rbi_modi_lightsens_rain_g == TRUE)&& (rbi_RainLight_enabled_g == TRUE))
    {
      rb_ReasonForLightOn_l = cb_NIGHT_RAIN_LIGHT;
    }
    else if((rbi_modi_lightsens_rain_g == TRUE)&& (rbi_RainLight_enabled_g == TRUE))
    {
      rb_ReasonForLightOn_l = cb_RAIN_LIGHT;
    }
    else if(uF_modi_lightsens_g.AllBit & cb_DARKSTART_mg)
    {
      rb_ReasonForLightOn_l = cb_UNDERGROUND;
    }
    else if(uF_modi_lightsens_g.AllBit & cb_TUNNEL_mg)
    {
      rb_ReasonForLightOn_l = cb_TUNNEL;
    }
    else if(rbi_Regulation48LightOnFlag_g ==TRUE)
    {
      rb_ReasonForLightOn_l = cb_ECE48;
    }
    else if((uF_modi_lightsens_g.AllBit & cb_NIGHT_mg)) //&& (isDarkActive()))
    {
      rb_ReasonForLightOn_l = cb_NIGHT;
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
  l_u8_wr_RLS_LightSwithReason(rb_ReasonForLightOn_l);   
}


#ifdef CS_STANDBY
void StandByMode(void)
{
  if((rb_Verglasun_ClosedDebounce_mg > cb_VERGLSUNG_CLOSE_DELAY_mg)||(rbi_Ignition_g== TRUE)||(rw_CommandCloseWindowTimout_mg > 6000))
  {
    rbi_Command_CloseWindows_g = FALSE;
    rbi_ASICStandByModeRequest_g = FALSE;
  }
    
  if(rbi_SendWakeUpFrame_g == TRUE)
  {
    ApplLinInit(0x01);                                  // send wakup frame
    rbi_SendWakeUpFrame_g = FALSE;                      
  }

  if(rbi_Command_CloseWindows_g == TRUE)
  {
    l_u8_wr_L_Sunroof_Win_CloseReq(1);                  // send close window command
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
    rw_CommandCloseWindowTimout_mg = 0;
    l_u8_wr_L_Sunroof_Win_CloseReq(0);
  }
  
  if(rbi_StandbyFunction_enabled_g == TRUE)               //send standby function status
  {
    l_bool_wr_L_RLS_ModeSts(TRUE);
  }
  else if(rbi_StandbyFunction_enabled_g == FALSE)
  {
    l_bool_wr_L_RLS_ModeSts(FALSE);
  }
  else{}
}
#endif

void VoltageDetect(void)
{
  static byte rb_underVoltageTimer_s;
  
  if(rbi_UnderVoltage_g == TRUE)                         //undervoltage, Overvoltage ?
  {
    if(rb_underVoltageTimer_s>249)               // undervoltagetimer > 249 -> 2500 ms abwarten
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
  if(rbi_UnderVoltage_g == TRUE)
  {
      //l_u8_wr_L_Err_State_Volt(rbi_UnderVoltage_g);    //voltage error statue
  }
  else if(rbi_OverVoltage_g == TRUE)
  {
      l_u8_wr_RLS_OverVoltErr(2);  //voltage error statue
  }
  else
  {
      l_u8_wr_RLS_OverVoltErr(0); 
  }    
}

#ifdef CS_OUTPUT_BRIGHTNESS
void OutPutBrightnessValue(void)
{
  static byte rb_InitLightValCnt_l=100;
  byte rb_Helligkeitsboost_l = 15;                                       /*VCO_103 local variable for brightness boost*/ 
  word rw_Hellighkeitsthrs;                                              /*VCO_103 local variable for brightness boost*/  
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
      l_u16_wr_RLS_LuxValueHorizontal(0X7FE);//FW invailed
      l_u16_wr_RLS_LuxValueSky(0X7FE);//RLS_LuxValueSky
     
    }
  }
  else
  {
    rb_InitLightValCnt_l=0;
    if(rb_RSControlFlags_g == cb_ONLY_HUMIDITY)
    {
      /*Incase of only Feuchte and solar frame preset then set the light ON, FW and IR to init value for safety reason*/ 
      l_u16_wr_RLS_LuxValueHorizontal(0X7FF);                                  //FW invailed
      l_u16_wr_RLS_LuxValueSky(0X7FF);  
     
    }
    else if(l_bool_rd_RLS_LSErr() == TRUE)                    /*  VDR469   set for error*/
    {
      l_u16_wr_RLS_LuxValueSky(0X7FF);                                  // IR Helligkeit Fehler
      l_u16_wr_RLS_LuxValueHorizontal(0X7FF);
 
    }
    else
    {
      if(rb_RSControlFlags_g == cb_HUMIDITY_SOLAR )
      {
        l_u16_wr_RLS_LuxValueHorizontal(0X7FF);
        l_u16_wr_RLS_LuxValueSky(0X7FF); //RLS_LuxValueSky
      }
      else
      {
        if(get_rw_FW_light16bit_g() < 0x640)                           /*VCO_031 correct variable 0x03FD*/
        {
           rw_FW_brightness_l = get_rw_FW_light16bit_g();
        }
        else
        {
          rw_FW_brightness_l = 0x640;
          rw_Hellighkeitsthrs = 0x640;                                /*VCO_103 calculate brightness boost*/ 
          do 
          {
            rw_Hellighkeitsthrs += rw_Hellighkeitsthrs/10;             /*VCO_103 calculate threshold*/ 
            rb_Helligkeitsboost_l-- ;
          }
          while ((get_rw_FW_light16bit_g() >= rw_Hellighkeitsthrs)&&(rb_Helligkeitsboost_l >0));
          
        }
         rw_FW_brightness_l = rw_FW_brightness_l;
        l_u16_wr_RLS_LuxValueHorizontal((rw_FW_brightness_l>0X7FD)?0X7FD:rw_FW_brightness_l);
              
      }
      
      if(rb_IrLightDiv8_g <= 0xFD)
      {
        l_u16_wr_RLS_LuxValueSky((byte)rb_IrLightDiv8_g*8);
      }
      else
      {
        l_u16_wr_RLS_LuxValueSky(0X7FD);     // IR Helligkeit max
      }

    }
  } 
}
#endif

#pragma inline=forced
static void CheckErrors(void)
{
  
  
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
  l_bool_wr_RLS_RSErr((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_RainS_Error1_g != 0) ||(rbi_HammingError_g != 0));  
  l_bool_wr_RLS_LSErr((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(rbi_HammingError_g != 0)||(rbi_CRC_ChangedByDiagnostic_g));
    
  
  if(l_bool_rd_RLS_LSErr()>0)
  {
    l_bool_wr_RLS_LightSnsSt(1);
  }
  else
  { 
    l_bool_wr_RLS_LightSnsSt(0);                          
  } 
  
  // ASIC/MCU temperature detect,when over 65 degree,then set.
  if(((rb_InternalTemperature_g > 0) && (rb_InternalTemperature_g < cb_TEMP_uC_AD65DEGREES_THRS_g))  || ((rw_VTEMP_ASIC_g > 0) && (rw_VTEMP_ASIC_g < cb_TEMP_ASIC_AD65DEGREES_THRS_g)))
  {
    l_u8_wr_RLS_OverTempErr(0);//default
  }
  else
  {
    l_u8_wr_RLS_OverTempErr(0);
  }
  
 }

void ApplLinInit(byte rb_LIN_State_l)
{
  
  // init unused bits to 1
   byte rb_Index_l; 
   static const byte LinMsgDefault_RLS_2[8] = {0,0,0,0,0,0,0,0};    /* 0x18"RLS_2" */
   static const byte LinMsgDefault_RLS_1[8] = {0,0,0,0,120,0,0,0};    /* 0x29"RLS_1" */

  
  rb_Index_l = 0;
  do
  {
    RLS_1._c[rb_Index_l] = LinMsgDefault_RLS_1[rb_Index_l];
    RLS_2._c[rb_Index_l] = LinMsgDefault_RLS_2[rb_Index_l];
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
  rb_FirstEnterWinterMode_mg = 0; //witer mode reset 
  rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;//reset noraml mode
  
}

__callt void ApplLinSlavePreCopy(byte rb_MessageID_l)                                     /* callt function faster */
{
  if(rb_MessageID_l == (rb_IDRLSs_01_g & 0x3F))
  {
    l_bool_wr_RLS_LINCommErr(rbi_latched_ResponseError_mg);
    l_u8_wr_RLS_SignalErr(rbi_latched_ResponseError_mg);
    rbi_latched_ResponseError_mg = FALSE;
  } 
}


void GetRainPotiStage(byte rb_PotiStageCurrent)
{   
    static byte rb_RsChangeCount = 0;
    
    if(rb_PotiStageCurrent == 0)
    {
      rb_PotiStageCurrent = 7;
    }
    
    if(rb_PotiStageFromBox_g != rb_PotiStageCurrent)
    {
        rb_RsChangeCount++; 
    }
    else
    {
       rb_RsChangeCount = 0;
    }
    //New sensitivity  
    if(rb_RsChangeCount >= 2)
    {
     
      rb_PotiStageFromBox_g = rb_PotiStageCurrent; 
      if(rb_PotiStageFromBox_g > 7)
      {
        rb_PotiStageFromBox_g = 7;
      }  
    }
   
    if(rb_PotiStageFromBox_g > rb_oldRainPotiStage_mg && rb_IgnitionOndelay_mg>=50)
    {
        rb_PotiStageIncreaseFlag = TRUE;
    }
    rb_oldRainPotiStage_mg = rb_PotiStageFromBox_g ;
    
    
}

byte WipeSpeedFlagState(void)
{
   if((rb_WipeSpeedIsReally_mg == TRUE) && (rw_AfterRSWipeCounter_mg >3000))
   {
      rb_WipeSpeedIsReally_mg = FALSE;
   }
   
   return rb_WipeSpeedIsReally_mg;
}

void WipeNormalModeCheck(void)
{
  if (TRUE == rb_WipeSpeedIsValid_mg)
  {
      if(rb_speed_in_kmh_g < 5)
      { 
         //Below 5 km/h the splash dectection shall be deactivated.
         //The splash function shall only be disabled if the vehicle speed is valid (LIN signal ¡°BCM_VehSpdVD¡±)
         if(TRUE == rbi_RSWipeFastDmd)
         {
           if(rb_CurrentSpeed_mg >= 2)//limited
           {
             rb_CurrentSpeed_mg = 1;
           } 
         }
         SetRainSplashStatus(0);//normal
         rb_WipeWorkStatus_mg = cb_LIMITED_SPEED_MODE;
      }
      else
      {
        if(TRUE == rbi_RSWipeFastDmd)
        {
           rb_WipeWorkStatus_mg = cb_SPLASH_WIPE_MODE;
        }    
      }
  }
  else
  {
    rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;
  }
   
  if(rb_speed_in_kmh_g >= 5)
  {
     SetRainSplashStatus(rbi_RSWipeFastDmd);//splash, 
  }
  
  // if time out traffic ,clean flag 
  WipeSpeedFlagState();
}

// back winter mode 
void WipeWinterModeCheck(void)
{
  
  if (TRUE == rb_WipeSpeedIsValid_mg)
  {   
      if((rb_speed_in_kmh_g < 5) && (rb_OutsideTempVD_mg ==TRUE) && (rb_OutsideTemp_mg <= 0))
      {
         rb_CurrentSpeed_mg = 0;
         rb_WipeWorkStatus_mg = cb_WINTER_WIPE_MODE;
      }
      else
      {
        rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;
      }
  }
  else
  {
     rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;
  }
  
}

// enter winter mode
byte CheckIsWinterMode(void)
{
    byte rb_winterFlag = 0;
   
    if((rb_OutsideTempVD_mg ==TRUE) && (rb_OutsideTemp_mg <= 0)&& (rb_FirstEnterWinterMode_mg == 0))
    {
         rb_WipeWorkStatus_mg = cb_WINTER_WIPE_MODE;
         rb_FirstEnterWinterMode_mg = 1;
         rb_winterFlag = 1;
    }
    return rb_winterFlag;
}

void WipeSplashModeCheck(void)
{
    if((FALSE == rbi_RSWipeFastDmd)||((TRUE == rb_WipeSpeedIsValid_mg) && (rb_speed_in_kmh_g < 5)))
    {
       rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE; 
    }
    else
    {
      rb_WipeWorkStatus_mg = cb_SPLASH_WIPE_MODE; 
    }
    SetRainSplashStatus(rbi_RSWipeFastDmd);//normal
  
}

void WipeLimitModeCheck(void)
{
  
  if (TRUE == rb_WipeSpeedIsValid_mg)
  {
      if(rb_speed_in_kmh_g >= 5)
      {
         rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;
      }
      else
      {
        //The winter mode shall be entered if the vehicle speed is below 5 km/h and external temperature is <=0    
        if(CheckIsWinterMode() == 1)
        {
          return ;
        }
        else
        {
           if(rb_CurrentSpeed_mg > 1)
           {
             rb_CurrentSpeed_mg = 1;
           }  
           
           // only send once if rain happen 
           if(WipeSpeedFlagState()== FALSE)
           {
             return ;
           }
           // will enter trffic check
           if( (rb_speed_in_kmh_g <= 3)&& (rw_AfterRSWipeCounter_mg <3000)&&(rb_CurrentSpeed_mg == 0) && (rb_TrafficWipeStart_mg == 0))
           {
              rb_WipeWorkStatus_mg = cb_TRAFFIC_LIGHT_MODE;
           }         
        } 
      }
  }
  else
  {
     rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE; 
  } 
}

//traffic mode check
void WipeTrafficModeCheck(void)
{ 
  
  if((rb_TrafficWipeStart_mg==1) || (rw_AfterRSWipeCounter_mg >=3000))
  {
     rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;
     return ; 
  }
  
  if (TRUE == rb_WipeSpeedIsValid_mg)
  {          
     if (rb_speed_in_kmh_g <= 3)//
     {
        if(rb_CurrentSpeed_mg > 1)
        {
          rb_CurrentSpeed_mg = 1;
        }        
        CheckIsWinterMode();
        
     }
     else
     {
       if(rb_speed_in_kmh_g >=5 )
       {
         rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;
       }
       else
       {
         CheckIsWinterMode(); 
       }
     }
     
     if((rb_speed_in_kmh_g>3) && (rw_AfterRSWipeCounter_mg <3000)&& (rb_CurrentSpeed_mg == 0)&&(rb_TrafficWipeStart_mg == 0) )
     {  
       rb_TrafficWipeStart_mg = 1;
       rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;
       rb_WipeSpeedIsReally_mg = FALSE ;// set this flag is Flase,only active once.
     }
  }
  else
  {
    rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;
  }
}

//1 Tunnel wiping The rain shall request a additional wipe cycle 
//when the rain sensor is active, a tunnel is detected and the last wipe 
//cycle has been requested within 30 seconds before entering the tunnel.
//2 Delay between last interval wipe (outside the tunnel )and the tunnel wipe shall be at least 6s. 
byte TunnelWipeCheck(void)
{
  
  // wait wipe active complete
  if((rb_TunnelWipeModeFlag_mg == 2) ||(rw_AfterRSWipeCounter_mg >= 3000))
  {
    return 1;
  }
  
  if((rbi_modi_lightsens_tunnel_alt_mg==FALSE)&&(rbi_modi_lightsens_tunnel_g == TRUE)&&(rb_TunnelWipeModeFlag_mg== 0)&& (rb_CurrentSpeed_mg == 0) )
  {
    if( (rw_AfterRSWipeCounter_mg >=600)&& (rw_AfterRSWipeCounter_mg <3000))
    {
       rb_TunnelWipeModeFlag_mg = 2;
       
    }
    else if(rw_AfterRSWipeCounter_mg < 600)
    {
       rb_TunnelWipeModeFlag_mg = 1;
    }
    else
    {
      rb_TunnelWipeModeFlag_mg = 0;
    }
  }
  else if((rb_TunnelWipeModeFlag_mg ==1)&&(rbi_modi_lightsens_tunnel_g == TRUE)&& (rb_CurrentSpeed_mg == 0))
  {
    if( (rw_AfterRSWipeCounter_mg >=600)&& (rw_AfterRSWipeCounter_mg <3000))
    {
       rb_TunnelWipeModeFlag_mg = 2;
       
    }
    else if(rw_AfterRSWipeCounter_mg >= 3000)
    {
       rb_TunnelWipeModeFlag_mg = 0;
    }
    else // wait time arrive
    {
      
    }
  }
  else 
  {
    rb_TunnelWipeModeFlag_mg = 0;
  }
  return 0;
}

// wipe send no include Winter Mode Status
void NormalWipeActionCheckSend(void)
{    
    if((rb_TrafficWipeStart_mg == 1|| rb_TunnelWipeModeFlag_mg == 2)&& (rbi_ParkPosition_g == TRUE) && (rb_CurrentSpeed_mg == 0) && (rb_KL15_mg == TRUE))
    {
        if((rbi_ParkPosition_g == FALSE)||(rb_OtherWipeTimeOut_mg >= 100))
        {
           rb_TunnelWipeModeFlag_mg = 0;
           rb_TrafficWipeStart_mg = 0;
           rb_OtherWipeTimeOut_mg = 0;
        }
        else
        {
           rb_OtherWipeTimeOut_mg++;
        }
        l_u8_wr_RLS_WiperSpd(1);
        rb_CurrentSpeed_mg = 1;       
    }
    else
    {
      if(rb_TunnelWipeModeFlag_mg == 2)
      {
        rb_TunnelWipeModeFlag_mg = 0;
      }       
      rb_TrafficWipeStart_mg = 0;
      rb_OtherWipeTimeOut_mg = 0;
      if(rb_CurrentSpeed_mg == 2)
      {
        rb_CurrentSpeed_mg = 14;
        l_u8_wr_RLS_WiperSpd(14);//GAC 14 is high speed 
      }
      else
      {
        l_u8_wr_RLS_WiperSpd(rb_CurrentSpeed_mg);
      }     
    } 
   
}

byte WipeSpeedStrategyEvaluation(byte rb_CurrSpeed)
{
   
  rb_CurrentSpeed_mg = rb_CurrSpeed; 
  switch(rb_WipeWorkStatus_mg)
  {
    case cb_NORMAL_WIPE_MODE:
      WipeNormalModeCheck();
      break;
    case cb_LIMITED_SPEED_MODE:
      WipeLimitModeCheck();
      break;
    case cb_SPLASH_WIPE_MODE:
      WipeSplashModeCheck();
      break;
    case cb_WINTER_WIPE_MODE:
      WipeWinterModeCheck();
      break;
    case cb_TRAFFIC_LIGHT_MODE:
      WipeTrafficModeCheck();
      break;
    default:
      rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;
      break;     
  }
    
   if(rb_WipeWorkStatus_mg == cb_WINTER_WIPE_MODE)
   {
       rb_TrafficWipeStart_mg = 0;
       rb_TunnelWipeModeFlag_mg = 0;
       rb_OtherWipeTimeOut_mg = 0;
       rb_CurrentSpeed_mg = 0;
       l_u8_wr_RLS_WiperSpd(0);
   }
   else
   { 
      TunnelWipeCheck();  
      NormalWipeActionCheckSend();
      
   } 
  return  rb_CurrentSpeed_mg ;
}

byte WiperSwitchChangeRequest(byte rb_CurrSpeed)
{
  
    static byte rb_wiperInital_Counter_s = 0;
    static byte rb_wiperStatue_old_g = 0;
    static byte rb_wipeForHanderChanged = 0;
    static byte rb_wipeForHanderChangedCounter = 0;
  
    if(rb_wiperInital_Counter_s < 100)     //if wiper hander changed from off to on then wipe once
    {
      rb_wiperInital_Counter_s++;    
    }
    else
    {
      if((rb_wiperStatue_old_g == 0) && (l_u8_rd_BCM_WiperCtr() == 1) && (rb_CurrSpeed == 0))
      {
        rb_wipeForHanderChanged = 1;
        rb_wipeForHanderChangedCounter = 100;
      }
      
      if((rb_wipeForHanderChanged == 1) && (rbi_ParkPosition_g == TRUE) && (rb_wipeForHanderChangedCounter > 0) && (rb_CurrSpeed == 0) && ((rb_KL15_mg) == TRUE))
      {
         rb_wipeForHanderChangedCounter --;
         rb_CurrSpeed = 1; 
      }
      else
      {
        rb_wipeForHanderChanged = 0;
        rb_wipeForHanderChangedCounter = 0;
      }
    }
   rb_wiperStatue_old_g = l_u8_rd_BCM_WiperCtr();//If the wiper switch change from OFF to Auto-mode the sensor shall request one single wipe.
   return rb_CurrSpeed;
}

void SetRainSplashStatus(byte status)
{
  if(l_bool_rd_RLS_RSErr()>0)
  {
    l_u8_wr_RLS_RainSnsSt(0x2);                                             //if RS ERROR then enter to safe mode
  }
  else
  { 
    l_u8_wr_RLS_RainSnsSt(status);                                          //splash mode
  }  
}



void CheckBCMTransmission(void)
{
   byte  offset  =  0;
   byte  VehMode =  0;
   byte  screen  =  0;
   static byte rb_TransmissionValueDebounce = 0;
   byte  rb_550nm_Transmission_local_Coding;
   byte  rb_880nm_Transmission_local_Coding;
   
   VehMode = l_u8_rd_BCM_VehModel();
   screen  =  l_u8_rd_BCM_ScreenType();
   
   if(VehMode == 0)
   {
     return ;
   }
   if(screen == 1)
   {
     if(VehMode == 1)
     {
        offset = 3;
     }
     else if(VehMode == 2)
     {
       offset = 0;
     }
     else if(VehMode == 3)
     {
       offset = 2;
     }
     
   }
   else if(screen == 2)
   {
     if(VehMode == 2)
     {
       offset = 1;
     }
   }
   rb_550nm_Transmission_local_Coding = ((cab_Transmissonion550[offset]-15)+2)/5;
   rb_880nm_Transmission_local_Coding = ((cab_Transmissonion880[offset]-15)+2)/5;
   
  if(rb_TransmissionValueDebounce < 20)//if 100ms run once ,2s delay check
  {
      rb_TransmissionValueDebounce ++;
      return ;
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

void CheckBCMVehicle(void)
{
  static byte rb_Vehicle_NEWType_l = 0;
  static byte rb_VehTypeValueDebounce = 0;
  static byte rb_Vehicl_l = 0 ;
  
  
  rb_Vehicle_NEWType_l = l_u8_rd_BCM_VehModel();
  
  
  if(rb_Vehicle_NEWType_l == cb_A86_BIT)
  {
    rb_Vehicl_l = cb_A86; 
  }
  else if(rb_Vehicle_NEWType_l == cb_A39_BIT)
  {
    rb_Vehicl_l = cb_A39; 
  }
  else if(rb_Vehicle_NEWType_l == cb_A90_BIT)
  {
    rb_Vehicl_l = cb_A90; 
  }
  else
  {
    return ;
  }
  
  if(rb_VehTypeValueDebounce < 20)//if 100ms run once ,2s delay check
  {
      rb_VehTypeValueDebounce ++;
      return ;
  }
  if(rbi_EEPROMLoad_g == TRUE)
  {
    return ;
  }
  
  if((rb_GAC_Vehicle_Type!= rb_Vehicl_l) &&
     (rb_Vehicle_NEWType_l < cb_Vehicle_MAX+1)&&
     (rb_Vehicle_NEWType_l > 0)&& 
     ((rbi_EEPROMBytesToWrite_g == FALSE)||(rbi_EEPROMBytesWritten_g == TRUE)))
  {
    rab_EEPROM_Bytes_toWrite_g[0] = rb_Vehicl_l ; // set data to write
    rw_EEPROM_Address_to_Write_g = cw_E2_VEHICLE_CODING_ADDRESS_g; /*set address to write*/
    rb_I2C_EEPROM_bytesToWrite_g = 1;         /*set number of bytes to 1*/
    rbi_EEPROMBytesToWrite_g = TRUE;
    rbi_EEPROMBytesWritten_g = FALSE;
    
  }
    
}