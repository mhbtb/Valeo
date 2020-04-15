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
#define cw_DEWPOINT_MAX_mg        (1650)     /*VDR_154 change of max value from 1022 to 1000*/
#else
#define cw_DEWPOINT_MAX_mg        (1000+CW_DEWPOINT_OFFSETT_mg)     /*VDR_154 change of max value from 1022 to 1000*/
#endif

#define cb_IGNORE_IGNITION_SPEED   4  /*VCO_083 ignore ignition off if speed higher 4km/h*/

#define cb_ONLY_HUMIDITY           0x98
#define cb_HUMIDITY_SOLAR          0x8A
#define cb_ONLY_RAIN               0x01

#define cw_TEMPSCHEIBE_MAX_mg       (1000+CW_TEMPERATURE_OFFSETT_mg)  /*VDR_154 change of max value from 1022 to 1000*/
#define CW_TEMPERATURE_OFFSETT_mg   4 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define CW_DEWPOINT_OFFSETT_mg      4 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define CW_DEWPOINT_MIN_mg          1 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define CW_TEMPERATURE_MIN_mg       1 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define cb_TEMPSENSOR_MAX_mg        254


#define cb_Night                    0x00 
#define cb_DAY                      0x01
#define cb_TWILIGHT                 0x02
#define cb_TUNNEL                   0x03
#define cb_RAIN_LIGHT               0x04
#define cb_UNDERGROUND              0x10
#define cb_HIGH_SPEED               0x20
#define cb_OTHERRSEAN               0x40
//#define cb_HUD_MEASURING_RANGE_1    0x40
//#define cb_HUD_MEASURING_RANGE_2    0x80

#define  cb_TEMP_uC_AD90DEGREES_THRS_g 63
#define  cb_TEMP_ASIC_AD90DEGREES_THRS_g 485
#define  cb_TEMP_uC_AD95DEGREES_THRS_g 62
#define  cb_TEMP_ASIC_AD95DEGREES_THRS_g 367

#define  cb_NORMAL_WIPE_MODE 1
#define  cb_WINTER_WIPE_MODE 2

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
static const byte cab_PotistageMapping_mg[8] = {4,5,6,7,3,2,1,0}; /*mapping for potistages!*/

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
static byte rb_Verglasun_offenDebounce_mg;
#ifdef CS_STANDBY 
static byte rb_Verglasun_ClosedDebounce_mg;
static word rw_CommandCloseWindowTimout_mg;
#endif
static byte rb_KL15_mg;
static byte rb_AnyErrorCounterDebounce_mg;
static word rw_AfterRSWipeCounter_mg;                   // Time after last wipe from RS
static word rw_AfterRSWipeCounterAlt_mg;              //Time to the last wipe from RS
static word rw_AfterWWSWipeCounter_mg;                  // Time after last wipe from WWS
static  word rw_WipeCommandTimOut_mg;                    //timout for requested wipe
static  byte rb_IgnitionOndelay_mg = 0;
static  byte rb_Err_State_Light_Sens_mg =0;// light error
static  int  rb_OutsideTemp_mg  = 1;
static  byte rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;


/******************For HUD**********************/
#ifdef HUD_FUNCTION
static unsigned long HUDEverageValue[2] = {0,0};//,0,0,0,0,0};
static unsigned long rb_storeHUDValueEvery500ms[10]={0,0,0,0,0,0,0,0,0,0};
static unsigned long rb_storeFW_ValueEvery50ms[10]={0,0,0,0,0,0,0,0,0,0};
static unsigned long rb_storeAMB_ValueEvery50ms[10]={0,0,0,0,0,0,0,0,0,0};


void GetFiveTableValue_500ms(unsigned long rl_HUD_Brightness_100ms);
unsigned long CalcHUDMean_1000ms(void);
void orderHUDValue(int n);
void GetFiveTableValue_50ms(unsigned long Fw,unsigned long Amb);
unsigned long  AdjustOutHudValue(unsigned long rl_CurrentHud);
unsigned char GetUpdateTimeForLightStatus(void);

static unsigned long FW_Average_In_50ms = 0;
static unsigned long AMB_Average_In_50ms = 0;


static  unsigned long FW_Average_In_50ms_Old = 0;
static  unsigned long AMB_Average_In_50ms_Old = 0;

static  unsigned long RW_Amb_Fw_Result_End    = 0;
static  unsigned char rb_hud_data_update      = 0;
static  unsigned char RW_Update_Time_Count = 0;

#endif
/********************End***********************/

byte CRC8SAEJ1850(byte *u8_data,byte u8_len);//crc8saej1850 
byte GetHudCrcj1850(unsigned long hudSrc);
byte GetOutdBriStsCrcj1850(byte OutdBriSts);
void GetLightTransmission(byte trans_550nm,byte trans_880nm);
void Get_BCMVehType(byte CarType);
void Set_BCMLightOffset(byte offset);
void SendRLSSerNo(void);
void SendRLSMPartNo(void);
void SendRLSMPartNo10(void);
void OutPutHudValue(void);
void OutPutHudSendCount(void);
void TemperatureDetect(void);
void WipeWinterModeCheck(void);
byte IsByteOddParity(byte data);

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
  byte rb_BCM_LightSns;
  
 /***********************Add the Auto_Close_Window Function in Rain Condition*************************/   
#ifdef CS_STANDBY 
     
  if (l_bool_rd_EnaOfflineMonitor_CEM_LIN1()== 1)                        //Window Open
  {
    if (rbi_Ignition_g == FALSE)                                     
    {
      if (rb_Verglasun_offenDebounce_mg < 0xff)
      {
        rb_Verglasun_offenDebounce_mg ++;
      }
    }
    rb_Verglasun_ClosedDebounce_mg = 0;
  }
  else if(l_bool_rd_EnaOfflineMonitor_CEM_LIN1() == 0)
  {
    if (rb_Verglasun_ClosedDebounce_mg < 0xff)
    {
      rb_Verglasun_ClosedDebounce_mg ++;
    }
    rb_Verglasun_offenDebounce_mg = 0;
  }
  else
  {
  
  }
#endif

  
  if(l_flg_tst_CemCem_Lin1Fr02_CEM_LIN1())
  {
     l_flg_clr_CemCem_Lin1Fr02_CEM_LIN1();
     rbi_ConnectedToMaster_g = 1;
     rb_OutsideTemp_mg =  l_u8_rd_AmbTForVisy_CEM_LIN1();
     WipeWinterModeCheck(); 
  }
    
  if(l_flg_tst_CemCem_Lin1Fr03_CEM_LIN1())
  {
       l_flg_clr_CemCem_Lin1Fr03_CEM_LIN1();
       rbi_ConnectedToMaster_g = 1;
       
       l_bool_wr_RainSnsrErrCalErrActv_CEM_LIN1(1);     
       Get_BCMVehType(l_u8_rd_VehTyp_CEM_LIN1());
       GetLightTransmission(l_u8_rd_WindCorrnValFrnt_CEM_LIN1(),l_u8_rd_WindCorrnValAmb_CEM_LIN1());
  }
  
  if(l_flg_tst_CemCem_Lin1Fr04_CEM_LIN1())
  {
     l_flg_clr_CemCem_Lin1Fr04_CEM_LIN1();
     rbi_ConnectedToMaster_g = 1;
     rb_BCM_LightSns = l_u8_rd_RainSnsrLiThd_CEM_LIN1();
     Set_BCMLightOffset(rb_BCM_LightSns);
     
  }
  
  
 if( l_flg_tst_CemCem_Lin1Fr05_CEM_LIN1())
 {
    l_flg_clr_CemCem_Lin1Fr05_CEM_LIN1();
    rbi_ConnectedToMaster_g = 1;
  
 }
   
  if(l_flg_tst_CemCem_Lin1Fr06_CEM_LIN1())
  { 
    l_flg_clr_CemCem_Lin1Fr06_CEM_LIN1();
    rbi_ConnectedToMaster_g = 1;
    rbi_RealParkContact_g = !l_bool_rd_WiprInWipgAr_CEM_LIN1();        // wiper position
    
    if (l_bool_rd_WshngCycActv_CEM_LIN1())                                 /* Washpump activ? 0x5:Front washing*/
    {
      rbi_WashingActive_g = TRUE;                                       /* set Washing activ bit */
    }
    else if (rbi_ParkPosition_g == TRUE)                                /* In Parkposition ? */
    {
      rbi_WashingActive_g = FALSE;                                      /* Clear Washing active bit */
    }
    else{}                                                              /*Do nothing, Dummy-else for Misra Check*/
  }
  
  if(l_flg_tst_CemCem_Lin1Fr01_CEM_LIN1())
  { 
    l_flg_clr_CemCem_Lin1Fr01_CEM_LIN1();
    rw_NoCommunicationCounter_g = 0;                                 // reset no communication counter
    rbi_ConnectedToMaster_g = 1;                                     // set connected to Master  
    rbi_LightSensitivityRecieved_g = TRUE;    
    
    rb_speed_in_kmh_g  = l_u8_rd_VehSpdForWipg_CEM_LIN1();   
    if(l_u8_rd_VehSpdForWipg_CEM_LIN1() == 0xFF)
    {
      rb_speed_in_kmh_g = 75;                           /* set speed to (75 km/h)*/
    }
    else 
    {
    }
    if(rb_speed_in_kmh_g>=10)
    {
      rbi_speedWasAbove10kmh_g = TRUE;
    }   
    rb_KL15_mg = (l_u8_rd_WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1()==2);
   /* ignore ignition off if speed higher 4km/h*/
    if((rb_KL15_mg == TRUE)||(rb_speed_in_kmh_g > cb_IGNORE_IGNITION_SPEED)) /*VCO_083*/
    {
      rbi_Ignition_g = TRUE;
      rw_StandbyTimeOutCnt_g = 0;
      rw_IgnitionOffDelay_mg = 0;
      if(rb_IgnitionOndelay_mg < 250)
      {
        rb_IgnitionOndelay_mg++;
      }
          
      if((rbi_RainsensorDisabled_g == FALSE) &&(rb_AfterResetCounter_l> 10))
      {
        if(((l_bool_rd_RainSensActvn_CEM_LIN1() == TRUE)&&(l_bool_rd_WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1()==TRUE))                         //automatic
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
      
      if(l_bool_rd_WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1() == TRUE)                            // copy automatic wiping mode
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

    rb_LIN_SensitivityShift_g =  7;                                     //adaptation Variable for sensitivity factor
    rb_PotiStageFromBox_g = (l_u8_rd_WiprMotIntlCmd_CEM_LIN1() >= 7)?3:(l_u8_rd_WiprMotIntlCmd_CEM_LIN1());
      
    
  }  
  else                                                                  //keine neue Master Nachricht!
  {                                                                     // check if system is on -> to switch off 
    if((rw_NoCommunicationCounter_g > CW_LIN_E2_IDLE_TIMOUT))                               /***4S***/
    {     
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
#ifdef CS_STANDBY                                                       //auto close windows                         
        if ((l_bool_rd_EnaOfflineMonitor_CEM_LIN1()== 0)||(rw_CommandCloseWindowTimout_mg > 6000))
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
#endif
      }
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
  
  rb_Empfindlichkeit_LS_l = 3;
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

  if(    ((l_bool_rd_WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1() == FALSE)    //NO auto wiper
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
    if((rbi_RealParkContact_g == FALSE)&&(rb_WiperSpeed_g > 0))
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
  
  if(l_flg_tst_RlsmCem_Lin1Fr01_CEM_LIN1())
  {
    l_flg_clr_RlsmCem_Lin1Fr01_CEM_LIN1() ;
    rbi_ConnectedToMaster_g = 1; 
    
  }

  if(l_flg_tst_RlsmCem_Lin1Fr02_CEM_LIN1())
  {
    l_flg_clr_RlsmCem_Lin1Fr02_CEM_LIN1() ;
    rbi_ConnectedToMaster_g = 1;
    OutPutHudSendCount();
  }
  
  if(l_flg_tst_RlsmCem_Lin1Fr03_CEM_LIN1())
  {
    l_flg_clr_RlsmCem_Lin1Fr03_CEM_LIN1() ;
    rbi_ConnectedToMaster_g = 1; 
  }
  
  if(l_flg_tst_RlsmCem_Lin1PartNrFr01_CEM_LIN1())
  {
    l_flg_clr_RlsmCem_Lin1PartNrFr01_CEM_LIN1() ;
    rbi_ConnectedToMaster_g = 1;
    SendRLSMPartNo();
  }
  
  if(l_flg_tst_RlsmCem_Lin1PartNrFr02_CEM_LIN1())
  {
    l_flg_clr_RlsmCem_Lin1PartNrFr02_CEM_LIN1() ;
    rbi_ConnectedToMaster_g = 1; 
    SendRLSMPartNo10();
  }
  if(l_flg_tst_RlsmCem_SerNrLin1Fr01_CEM_LIN1())
  {
    l_flg_clr_RlsmCem_SerNrLin1Fr01_CEM_LIN1() ;
    rbi_ConnectedToMaster_g = 1; 
    SendRLSSerNo();
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
  TemperatureDetect();                         //send temperate error
  LightFunction();                             //light request and the reason of light on                            
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

  rb_WDG_BusTaskCounter_g++;                   //increment test counter for bus
}


/*0x0：OFF "WipgSpd0Rpm";
0x1：Low speed "WipgSpd40Rpm";
0x2：wipe speed "WipgSpd43Rpm";
0x3：wipe speed"WipgSpd46Rpm";
0x4：wipe speed "WipgSpd50Rpm";
0x5：wipe speed "WipgSpd54Rpm";
0x6：wipe speed "WipgSpd57Rpm";
0x7：High speed "WipgSpd60Rpm";
0x8~0xE：currently not used*/

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

    l_u8_wr_AutWinWipgCmd_CEM_LIN1(1);
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
    l_u8_wr_AutWinWipgCmd_CEM_LIN1(1);
  }
  else
  {
    if(l_bool_rd_WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1() == TRUE)
    {
      if((rb_WiperSpeed_g != 0) &&(rb_WipeWorkStatus_mg == cb_NORMAL_WIPE_MODE))
      {
        if ((rbi_RSWipeSlowDmd==0)&&(rbi_RSWipeFastDmd==0))
        {
           newWiperSpeedLin = 1; //interval         
        }
        else
        {
           newWiperSpeedLin = rb_WiperSpeed_g;        
        }  
      }
      else
      {
        newWiperSpeedLin = 0;
      } 
    }
    
    l_u8_wr_AutWinWipgCmd_CEM_LIN1(newWiperSpeedLin);   // wiper request  
    l_u8_wr_WipgAutFrntMod_CEM_LIN1(0); 
    
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
  rbi_modi_lightsens_tunnel_alt_mg = rbi_modi_lightsens_tunnel_g;  
     
}

void LightFunction(void)
{
  byte rb_AnyErrorCounterDebounce_l; 
  byte rb_TempLightOn_l;
  byte rb_OpModeState = 0;
  byte rb_crc_StsOutdBriSts = 0;
  
 /* PRQA S 3415, 4112 1 */ /* << Getter functions must not have side effects >>*/
  if ((((((IS_LS_ANY_ERRORCOUNTER()) > 0))||(rb_Err_State_Light_Sens_mg > 0))||(((rbi_UnderVoltage_g) == TRUE))
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
  if(rb_Err_State_Light_Sens_mg == TRUE)                                                                               //sensor in error
  {
     // SWRS3  95106 v3 Failure to detect ambient light data, or to provide a reliable status (Day or Night) after initialization, 
     // shall result in the sensor setting the value to 'Invalid'.
     rb_TempLightOn_l = 3;  
  }
  
  else if(((uF_modi_lightsens_g.AllBit & 0x2F)>0)||(rbi_InternalResetOccured_g > 0)||(rbi_Regulation48LightOnFlag_g !=0)) //darkness/darkstart/tunnel
  {
    rb_TempLightOn_l = 1;
  }
  /*VDR_129 use Sensitivity Treatment*/
  else if((((rbi_Freewaylight_enabled_g==TRUE))&& (rbi_FastHighwayMode_g == TRUE))                                        //highway/rain
          ||(((rbi_modi_lightsens_rain_g == TRUE)&& (rbi_RainLight_enabled_g == TRUE))))
  {
    rb_TempLightOn_l = 1;
  }
  else
  { /* PRQA S 3415 1 */ /* << Swapping expressions not feasible for performance >>*/
    if ((rb_AnyErrorCounterDebounce_l ==0)&&(get_rb_LightVetoCounter_g()==0)) /*VCO_093 use Veto of Lightsensor*/
    {
      rb_TempLightOn_l = 2;
    }
    else
    {
      rb_TempLightOn_l = l_u8_rd_OutdBriSts_CEM_LIN1();                                                               /* stay in old light mode and do */
    }
  }
  
                                                                                                                         /**Send lamp on command**/
  if((rbi_EEPROMLoad_g == FALSE)
      && ((rb_RSControlFlags_g == cb_HUMIDITY_SOLAR )||(rb_RSControlFlags_g == cb_ONLY_HUMIDITY)))
  {
    /*Incase of only Feuchte and solar frame preset then set the light ON, FW and IR to init value for safety reason*/
    l_u8_wr_OutdBriSts_CEM_LIN1(rb_TempLightOn_l);   
  } 
  else
  {
    /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
    DISABLE_SCIINTERRUPT();
    l_u8_wr_OutdBriSts_CEM_LIN1(rb_TempLightOn_l);                                                                    // Turn Light on = TRUE
    ENABLE_SCIINTERRUPT();
  } 
  
   rb_crc_StsOutdBriSts =  GetOutdBriStsCrcj1850(rb_TempLightOn_l);
   l_u8_wr_OutdBriChks_CEM_LIN1(rb_crc_StsOutdBriSts);
   
   if(((rbi_LightSensorActive_g == TRUE) && (rbi_EEPROMLoad_g == FALSE)) && (rb_TempLightOn_l>0))
   {
      if((rbi_modi_lightsens_rain_g == TRUE)&& (rbi_RainLight_enabled_g == TRUE))
      {   
        l_bool_wr_RainLi_CEM_LIN1(1);
      }
      else
      {
        l_bool_wr_RainLi_CEM_LIN1(0);
      }
   }
   else
   {
       l_bool_wr_RainLi_CEM_LIN1(0);
   }
 
   
  switch (uF_modi_lightsens_g.AllBit & 0x0F)   //Switch Lightsensor Mode
  {
    case cb_DARKSTART_mg :              //Case Darkstartmode
      rb_OpModeState = cb_TWILIGHT;
      break;
    case cb_DAY_mg :                    //Case Daymode
      rb_OpModeState = cb_DAY;
      break;
    case cb_NIGHT_mg :                 // Case Nightmode
      rb_OpModeState = cb_Night;
      break;
    case cb_TUNNEL_mg :               // Case Tunnelmode
      rb_OpModeState = cb_TUNNEL;
      break;
    default:
      rb_OpModeState = cb_Night ;
      break;
  }
  l_u8_wr_LiOprnMod_CEM_LIN1(rb_OpModeState); 
  
}

#ifdef CS_HT_MODULE
void Humidity_Function(void)
{
  //static word rw_Temperature_Sensor_g;
  static word rw_Temperature_Scheibe_g;
  
  if (rbi_HumTempComError_g != 0)
  {
  
    if(((rbi_HumTempComError_g&cb_HTERR_HUMIOUTOFRANGE_g) == cb_HTERR_HUMIOUTOFRANGE_g) && ((rbi_HumTempComError_g&cb_HTERR_TEMPOUTOFRANGE_g) == cb_HTERR_TEMPOUTOFRANGE_g))
    {
       l_bool_wr_CmptFrntWindTErr_CEM_LIN1(1);
       l_u8_wr_RelHumSnsrErr_CEM_LIN1(1);
    } 
    else if((rbi_HumTempComError_g&cb_HTERR_HUMIOUTOFRANGE_g) == cb_HTERR_HUMIOUTOFRANGE_g)
    {
       l_bool_wr_CmptFrntWindTErr_CEM_LIN1(0);
       l_u8_wr_RelHumSnsrErr_CEM_LIN1(1);
    }
    else if((rbi_HumTempComError_g&cb_HTERR_TEMPOUTOFRANGE_g) == cb_HTERR_TEMPOUTOFRANGE_g)
    {
       l_bool_wr_CmptFrntWindTErr_CEM_LIN1(1);
       l_u8_wr_RelHumSnsrErr_CEM_LIN1(0);;
    }
    else
    {
       l_bool_wr_CmptFrntWindTErr_CEM_LIN1(1);
       l_u8_wr_RelHumSnsrErr_CEM_LIN1(1);
    }
      
    l_u16_wr_CmptFrntWindT_CEM_LIN1(1650);      //window temperature   
    l_u8_wr_RelHumSnsrRelHum_CEM_LIN1(255);     // relation hum
    l_u16_wr_CmptFrntWindDewT_CEM_LIN1(1650);  //dew point temperature
     
  }
  else
  {
    
    l_bool_wr_CmptFrntWindTErr_CEM_LIN1(0);
    l_u8_wr_RelHumSnsrErr_CEM_LIN1(0);;  
                                                             /*the temperature of screen ,the range is -40~120*/
    if(rw_Temperature_raw_g < 0x2ad)                         // The temperature less than -40 the tool doesnot support 
    {
      rw_Temperature_Scheibe_g = 0x2ad;
    }
    else if(rw_Temperature_raw_g > 0x4321)                   // The temperature greater than 120 the tool doesnot support
    {
      rw_Temperature_Scheibe_g = 0x4321;    
    }
    else
    {
      rw_Temperature_Scheibe_g = rw_Temperature_raw_g;
    }    
           
    if(rw_Temperature_raw_g == cw_HUMTEMP_INIT_g)
    {
      l_u16_wr_CmptFrntWindT_CEM_LIN1(400);
   
    }
    else
    {
      if(((rw_Temperature_Scheibe_g -685)/10) < 1650)
      {        
        l_u16_wr_CmptFrntWindT_CEM_LIN1(((rw_Temperature_Scheibe_g -685)/10));
      }
      else
      {         
        l_u16_wr_CmptFrntWindT_CEM_LIN1(1650);
      }
    } 
  
    if (rw_DewPoint_g == cw_HUMTEMP_INIT_g)
    {
       l_u16_wr_CmptFrntWindDewT_CEM_LIN1(400);
    }    
    else
    {
      if (rw_DewPoint_g < cw_DEWPOINT_MAX_mg )                /* dew point should be less than or equal to Scheibe temperature */
      {                                                                       
        l_u16_wr_CmptFrntWindDewT_CEM_LIN1(rw_DewPoint_g);        
      }
      else
      {
        l_u16_wr_CmptFrntWindDewT_CEM_LIN1(cw_DEWPOINT_MAX_mg);
      }
    }
      
    if (rb_Humidity_g == cw_HUMTEMP_INIT_g)                   /* Relative Humidity output*/ /*VCO_061 name hase changed*/
    {
      l_u8_wr_RelHumSnsrRelHum_CEM_LIN1(0);
    }        
    else
    {        
      l_u8_wr_RelHumSnsrRelHum_CEM_LIN1(rb_Humidity_raw_g);
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
  }
    
  if(rbi_SendWakeUpFrame_g == TRUE)
  {
    ApplLinInit(0x01);                                  // send wakup frame
    rbi_SendWakeUpFrame_g = FALSE;                      
  }

  if(rbi_Command_CloseWindows_g == TRUE)               // send close window command
  {
   
     l_bool_wr_RainDetected_CEM_LIN1(1); 
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
    l_bool_wr_RainDetected_CEM_LIN1(0);
  }
  
}
#endif

void VoltageDetect(void)
{
  static byte rb_underVoltageTimer_s;
  
  if(rbi_UnderVoltage_g == TRUE)                         //undervoltage, Overvoltage ?
  {
    if(rb_underVoltageTimer_s>249)                       // undervoltagetimer > 249 -> 2500 ms abwarten
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
    l_bool_wr_RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1(TRUE);  //voltage error statue
  }
  else
  {
    l_bool_wr_RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1(FALSE);
  }     
}
//SWRS4 89031 v4 Rain Sensor Diagnostics [CS Released]
// 1 (1050mV - (3.6mV x 65))/3300mV  x 256 =63 ===>90
// 1. (1050mV - (3.6mV x 70))/3300mV  x 256 =62 ===>95
// offset 25 ,because Temperature would be 25 deg C  ---> Temperature sensor voltage should be 1050mV 

//2 (1140mV - (3.9mV x 65))/2417mV  x 1024 =485 ===>90
//2. (1140mV - (3.9mV x 70))/2417mV  x 1024 =367 ===>95
// offset 25 ,because Temperature would be 25 deg C  ---> Temperature sensor voltage should be 1140mV 
void TemperatureDetect(void)
{
  static word rb_overTemperatureTimer_s;
  byte rb_temperateOver_l = 0;
  
  if(((rb_InternalTemperature_g > 0) && (rb_InternalTemperature_g < cb_TEMP_uC_AD95DEGREES_THRS_g))  || ((rw_VTEMP_ASIC_g > 0) && (rw_VTEMP_ASIC_g < cb_TEMP_ASIC_AD95DEGREES_THRS_g)))                        //undervoltage, Overvoltage ?
  {
    if(rb_overTemperatureTimer_s>10000)                       
    {
      rb_temperateOver_l = 1;
    }
    else
    {
      rb_overTemperatureTimer_s++;                          
    }
  }
  else if(((rb_InternalTemperature_g > 0) && (rb_InternalTemperature_g< cb_TEMP_uC_AD90DEGREES_THRS_g)) || ((rw_VTEMP_ASIC_g > 0) && (rw_VTEMP_ASIC_g < cb_TEMP_ASIC_AD90DEGREES_THRS_g))) 
  {
    if(rb_overTemperatureTimer_s>10000)                       
    {
      rb_temperateOver_l = 1;//continue on
    }
    else
    {
      rb_overTemperatureTimer_s=0;                            
      rb_temperateOver_l = 0;                         
    }
  }  
  else
  {
    rb_overTemperatureTimer_s=0;                            
    rb_temperateOver_l = 0;
  }
  // ASIC/MCU temperature detect,when over 95 degree,then set.
  l_bool_wr_RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1(rb_temperateOver_l); 
}

#ifdef CS_OUTPUT_BRIGHTNESS

void OutPutHudSendCount(void)
{
     static byte rb_HUD_Cnt_s = 0;
     //cnt count 
    l_u8_wr_AmbIllmnFwdStsCntr_CEM_LIN1(rb_HUD_Cnt_s);
    if(rb_HUD_Cnt_s < 15)
    {
      rb_HUD_Cnt_s ++;
    }
    else
    {
      rb_HUD_Cnt_s = 0;
    }
    
  
}

void OutPutHudValue(void)
{
  
   byte rb_hud_Crc8_l;
   unsigned long rl_hud_Brightness_l;
   unsigned long rl_hud_AMB_Brightness_l;
   unsigned long rl_hud_FW_Brightness_l; 
   unsigned long rl_eeprom_hud_max_l = 0;
   byte rb_hud_Low8Bit_l = 0;
   word rw_hud_high9Bit_l  = 0;
  
   /*****************Get the Real Lux for FW and AMB  Illuminance = FW*6 + AMB*15 *********************/
     
    rl_hud_AMB_Brightness_l = 15*((unsigned long)(get_rw_Amb_light16bit_g()));
    rl_hud_FW_Brightness_l = (unsigned long)((3*((unsigned long)(get_rl_HUD_light32bit_g())))>>1);
    
    /*********Pre-Process for original value get average for "rl_HUD_AMB_Brightness" and "rl_HUD_FW_Brightness"*********/
    /********100ms average for AMB and FW        1000ms for sum average      ******************/
    GetFiveTableValue_50ms(rl_hud_AMB_Brightness_l,rl_hud_FW_Brightness_l);   
    
    /*************5000ms for average output**************/
    rl_hud_Brightness_l  = CalcHUDMean_1000ms();
      
    /***********Output to LIN Interface**************/
    rl_eeprom_hud_max_l = rb_HUD_MAX_Resolution_g*rw_HUD_MAX_Value_g;
    if(rl_hud_Brightness_l >= rl_eeprom_hud_max_l)
    {
         rl_hud_Brightness_l = rl_eeprom_hud_max_l;        
    }
    
    if(rl_hud_Brightness_l > 126000)//currnet send data  length is shorter
    {
       rl_hud_Brightness_l = 126000;
    } 
    rb_hud_Low8Bit_l  = (byte)(rl_hud_Brightness_l&0xFF);
    rw_hud_high9Bit_l = (word)((rl_hud_Brightness_l>>8)&0x1ff);
    l_u8_wr_AmbIllmnFwdStsAmblillmn2_CEM_LIN1(rb_hud_Low8Bit_l);
    l_u16_wr_AmbIllmnFwdStsAmblillmn1_CEM_LIN1(rw_hud_high9Bit_l);
  
    //check crc 
    rb_hud_Crc8_l = GetHudCrcj1850(rl_hud_Brightness_l);
    l_u8_wr_AmbIllmnFwdStsChks_CEM_LIN1(rb_hud_Crc8_l);
    
    /*****************end hud info relation  *********************/  
}

void OutPutTwliBriValue(void)
{
    // AMB 
    if(get_rw_Amb_light16bit_g()*20 < 16383)    
    {
        l_u16_wr_TwliBriRawTwliBriRaw_CEM_LIN1(get_rw_Amb_light16bit_g()*20);
    }
    else
    {
        l_u16_wr_TwliBriRawTwliBriRaw_CEM_LIN1(16383);
    } 
}

void OutPutSolarValue(void)
{
  
#ifdef CS_SOLAR
    word rw_IrLightforSOSE_Corr1_l;
    word rw_IrLightforSOSE_Corr2_l;
    word rw_SoSe_SunInt_2D_Le_l;
    word rw_SoSe_SunInt_2D_Re_l; 
        
    if ((rbi_SoSe_Enabled_g == TRUE) && (TRUE == rbi_SolarValuesInitialised_g))
    {
      if (rb_SolarShadowCorrFactor1_g > 0)
      {
        rw_IrLightforSOSE_Corr1_l= get_rw_IR_light16bit_g()/rb_SolarShadowCorrFactor1_g; 
      }
      else 
      {
        rw_IrLightforSOSE_Corr1_l = 0;  
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
        rw_IrLightforSOSE_Corr2_l = 0;  
      }

      if((rw_IrLightforSOSE_Corr2_l >= rw_SoSe_SunInt_2D_Le_l) && (rw_IrLightforSOSE_Corr2_l >= rw_SoSe_SunInt_2D_Re_l)) 
      {
        rw_SoSe_SunInt_2D_Le_l = rw_IrLightforSOSE_Corr2_l;
        rw_SoSe_SunInt_2D_Re_l = rw_IrLightforSOSE_Corr2_l;
      }
      rw_SoSe_SunInt_2D_Le_l=(rw_SoSe_SunInt_2D_Le_l>>3)*5;
      rw_SoSe_SunInt_2D_Le_l=((rw_SoSe_SunInt_2D_Le_l>240)?240:rw_SoSe_SunInt_2D_Le_l);
      l_u8_wr_SolarSnsrLeValue_CEM_LIN1(rw_SoSe_SunInt_2D_Le_l);

      rw_SoSe_SunInt_2D_Re_l=(rw_SoSe_SunInt_2D_Re_l>>3)*5;
      rw_SoSe_SunInt_2D_Re_l=((rw_SoSe_SunInt_2D_Re_l>240)?240:rw_SoSe_SunInt_2D_Re_l);
      l_u8_wr_SolarSnsrRiValue_CEM_LIN1(rw_SoSe_SunInt_2D_Re_l);       
    }
    else
    {
      l_u8_wr_SolarSnsrLeValue_CEM_LIN1(0xFF); 
      l_u8_wr_SolarSnsrRiValue_CEM_LIN1(0xFF); 
    }
 #endif
}
void OutPutBrightnessValue(void)
{
  static byte rb_InitLightValCnt_l=100;
 
  
  if((rbi_LightValuesInitialised_g == FALSE)|| (rbi_EEPROMLoad_g == TRUE))
  {
                                                                         //hold the previous values
    if(rb_InitLightValCnt_l<100)
    {
      rb_InitLightValCnt_l++;
    }
    else
    { 
       l_u16_wr_AmbIllmnFwdStsAmblillmn1_CEM_LIN1(0);
       l_u8_wr_AmbIllmnFwdStsAmblillmn2_CEM_LIN1(0);
       l_u8_wr_AmbIllmnFwdStsCntr_CEM_LIN1(0);
       l_u16_wr_TwliBriRawTwliBriRaw_CEM_LIN1(0);
       l_u8_wr_SolarSnsrRiValue_CEM_LIN1(0);        // Init 
       l_u8_wr_SolarSnsrLeValue_CEM_LIN1(0);         // Init
    }
  }
  else
  {
    rb_InitLightValCnt_l=0;  
    if(rb_RSControlFlags_g == cb_ONLY_HUMIDITY)
    {
      /*Incase of only Feuchte and solar frame preset then set the light ON, FW and IR to init value for safety reason*/ 
      l_u16_wr_AmbIllmnFwdStsAmblillmn1_CEM_LIN1(0x1FF);
       l_u8_wr_AmbIllmnFwdStsAmblillmn2_CEM_LIN1(0xFF);;
      l_u8_wr_AmbIllmnFwdStsCntr_CEM_LIN1(0);
      l_u16_wr_TwliBriRawTwliBriRaw_CEM_LIN1(16383);
      l_u8_wr_SolarSnsrRiValue_CEM_LIN1(0xFF);       //Blake_Check Even never run here,but make up is better.                      /* Init*/
      l_u8_wr_SolarSnsrLeValue_CEM_LIN1(0xFF);                             /* Init*/
            
    }
    else if(rb_Err_State_Light_Sens_mg == TRUE)                    /*  VDR469   set for error*/
    {
                                    // IR Helligkeit Fehler
       l_u16_wr_AmbIllmnFwdStsAmblillmn1_CEM_LIN1(0x1FF);
       l_u8_wr_AmbIllmnFwdStsAmblillmn2_CEM_LIN1(0xFF);;
       l_u8_wr_AmbIllmnFwdStsCntr_CEM_LIN1(0);
       l_u16_wr_TwliBriRawTwliBriRaw_CEM_LIN1(16383);
       l_u8_wr_SolarSnsrRiValue_CEM_LIN1(0xFF);                            /* Init*/
       l_u8_wr_SolarSnsrLeValue_CEM_LIN1(0xFF);                             /* Init*/
    }
    else
    {  
         OutPutHudValue(); 
         OutPutTwliBriValue();
         OutPutSolarValue();
    }
  } 
}
#endif

#pragma inline=forced
static void CheckErrors(void)
{
  //l_u8_wr_L_Err_State_Cal_RS(1);                                                 //custorm defined, but we do not support
  //l_u8_wr_L_Err_State_Coding(0);
  byte rb_hud_errorParity_l = 0;
  
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
  l_bool_wr_RainSnsrErrRainDetnErrActv_CEM_LIN1(1);  
 #ifndef _NO_RAIN_
  if((TRUE==rbi_RainSensor_enabled_g) && (FALSE==rbi_RainsensorDisabled_g))
  {
    /* VCO132: SM210 - ASIC Frequency Check (done at startup) - LS,RS_Failure */
    /* VCO 140: SM150 - ADC test */
    /* setze Lichtsensor RS-Fehler nach SRS */
    /*SM240*/
    l_bool_wr_RainSnsrErrRainDetnErr_CEM_LIN1((rbi_OverVoltage_g != 0)||(rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_RainS_Error1_g != 0) ||(rbi_HammingError_g != 0));
  }
  else
  {
    /*only RAM/ROM error and RS version error*/
    l_bool_wr_RainSnsrErrRainDetnErr_CEM_LIN1(((rb_RS_LS_Error1_g&0x3) != 0)||(TRUE==bi_RS_VariantError_g)||(rbi_HammingError_g != 0));
  }
  
#else
  /*only RAM/ROM error and RS version error*/
  l_bool_wr_RainSnsrErrRainDetnErr_CEM_LIN1(((rb_RS_LS_Error1_g&0x3) != 0)||(TRUE==bi_RS_VariantError_g)||(rbi_HammingError_g != 0));
#endif /*_NO_RAIN_*/
  
  if(((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(rbi_HammingError_g != 0)||(rbi_CRC_ChangedByDiagnostic_g)))
  {
    rb_Err_State_Light_Sens_mg = TRUE;
  }
  else
  {
    rb_Err_State_Light_Sens_mg = FALSE;
  }
 
  l_u8_wr_SolarSnsrErr_CEM_LIN1(rb_Err_State_Light_Sens_mg);
  if(rbi_LS_Error_ALS2_g != 0)
  {
    l_u8_wr_TwliBriRawQf_CEM_LIN1(2); //AMB ERROR
  }
  else
  {
    l_u8_wr_TwliBriRawQf_CEM_LIN1(3);//NORMAL
  }
  
  l_bool_wr_HudSnsrErrSnsrErr_CEM_LIN1((rbi_LS_Error_ALS2_g != 0) || (rbi_LS_Error_ALS5_g != 0));//AMB and FW error 
  rb_hud_errorParity_l =IsByteOddParity(l_bool_rd_HudSnsrErrSnsrErr_CEM_LIN1());
  l_bool_wr_HudSnsrErrParChk_CEM_LIN1(rb_hud_errorParity_l);
    
}

void ApplLinInit(byte rb_LIN_State_l)
{
  
  // init unused bits to 1
  byte rb_Index_l; 
   
  static const byte LinMsgDefault_RlsmCem_SerNrLin1Fr01_CEM_LIN1[8] = {0,0,0,0,0,0,0,0};    /* 0x22"RlsmCem_SerNrLin1Fr01_CEM_LIN1" */
  static const byte LinMsgDefault_RlsmCem_Lin1PartNrFr02_CEM_LIN1[8] = {0,0,0,0,0,0,0,0};    /* 0x18"RlsmCem_Lin1PartNrFr02_CEM_LIN1" */
  static const byte LinMsgDefault_RlsmCem_Lin1PartNrFr01_CEM_LIN1[8] = {0,0,0,0,0,0,0,0};    /* 0x20"RlsmCem_Lin1PartNrFr01_CEM_LIN1" */
  static const byte LinMsgDefault_RlsmCem_Lin1Fr03_CEM_LIN1[8] = {0,0,0,0,0,0,0,0};          /* 0x02"RlsmCem_Lin1Fr03_CEM_LIN1" */
  static const byte LinMsgDefault_RlsmCem_Lin1Fr02_CEM_LIN1[8] = {144,1,0,0,0,0,50,0};       /* 0x2C"RlsmCem_Lin1Fr02_CEM_LIN1" */
  static const byte LinMsgDefault_RlsmCem_Lin1Fr01_CEM_LIN1[8] = {0,0,0,1,0,0,0,0};         /* 0x15"RlsmCem_Lin1Fr01_CEM_LIN1" */

  rb_Index_l = 0;
  do
  {
    RlsmCem_SerNrLin1Fr01_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_SerNrLin1Fr01_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1PartNrFr02_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1PartNrFr02_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1PartNrFr01_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1PartNrFr01_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1Fr03_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1Fr03_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1Fr02_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1Fr02_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1Fr01_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1Fr01_CEM_LIN1[rb_Index_l];
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
  rb_AnyErrorCounterDebounce_mg = 200;  
  rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;  
}

__callt void ApplLinSlavePreCopy(byte rb_MessageID_l)                                     /* callt function faster */
{
  if(rb_MessageID_l == (rb_IDRLSs_01_g & 0x3F))
  {
    l_bool_wr_ErrRespRLSM_CEM_LIN1(rbi_latched_ResponseError_mg);
    //l_u8_wr_L_Signal_Error(rbi_latched_ResponseError_mg);
    rbi_latched_ResponseError_mg = FALSE;
  } 
}

/******************************HUD Algrithm shenzhen-team 2018-05-05************************/
#ifdef HUD_FUNCTION


void GetFiveTableValue_500ms(unsigned long rl_HUD_Brightness_50ms)
{
  static unsigned char rb_k_cycleIn50ms=0;
  static unsigned char rb_k_cycleIn500ms=0;
  
  rb_storeHUDValueEvery500ms[rb_k_cycleIn50ms] = rl_HUD_Brightness_50ms;
    
  rb_k_cycleIn50ms++;
  if(rb_k_cycleIn50ms >= 10)
  {
    rb_k_cycleIn50ms = 0;
    orderHUDValue(10);
    HUDEverageValue[rb_k_cycleIn500ms]=(rb_storeHUDValueEvery500ms[3]+rb_storeHUDValueEvery500ms[4]+rb_storeHUDValueEvery500ms[5]+rb_storeHUDValueEvery500ms[6]+rb_storeHUDValueEvery500ms[7])/5;
    rb_k_cycleIn500ms++;
    if(rb_k_cycleIn500ms >= 2)
    {
      rb_k_cycleIn500ms=0;  
      rb_hud_data_update = 1;
    }    
  }
}

unsigned long  AdjustOutHudValue(unsigned long rl_CurrentHud)
{
    int currLevel = 0;
    int rw_LastCurrDiff = 0;
    unsigned long  rl_adjustAfterHud=0;
     
    if(rl_CurrentHud >= 100)
    {
      return rl_CurrentHud;
    }
    currLevel = RW_Amb_Fw_Result_End/10;  
    rw_LastCurrDiff = rl_CurrentHud -RW_Amb_Fw_Result_End;
    
    if(rw_LastCurrDiff >=-15 && rw_LastCurrDiff <=15)// less than 15 is 
    {
        return  rl_CurrentHud;
    }
    currLevel = currLevel+rw_LastCurrDiff/15;
    rw_LastCurrDiff = rw_LastCurrDiff%3;
    if(currLevel < 0)
    {   
      rl_adjustAfterHud = 5+rw_LastCurrDiff;
    }
    else if(currLevel > 9)
    {
      rl_adjustAfterHud = 92+rw_LastCurrDiff;
      
    }
    else
    {
      rl_adjustAfterHud = 5+currLevel*10+rw_LastCurrDiff;
    }
    return  rl_adjustAfterHud;    
}

unsigned char GetUpdateTimeForLightStatus(void)
{
   unsigned char  hud_refresh_time = 1;  
    //1 in tunnel and day for 1s  get data;in night and darkstart for 3s  get data 
    //2 if in tunnel and speed less 10,then 3s will upate
   if((rbi_LightSensorActive_g == TRUE) && (rbi_EEPROMLoad_g == FALSE))
   {
        if(uF_modi_lightsens_g.AllBit & cb_NIGHT_mg)
        {
           hud_refresh_time = 3;
        }
        else if (uF_modi_lightsens_g.AllBit & cb_TUNNEL_mg)
        {
          if(rb_speed_in_kmh_g >= 10)
          {
            hud_refresh_time = 1;
          }
          else
          {
            hud_refresh_time = 3;
          }   
        }
        else if (uF_modi_lightsens_g.AllBit & cb_DARKSTART_mg)
        {
          hud_refresh_time = 3;
        }
        else
        {
          hud_refresh_time = 1;  
        }
    }
    else
    {
       hud_refresh_time = 1;  
    }  
    return  hud_refresh_time;
}

unsigned long CalcHUDMean_1000ms(void)
{  
    
    unsigned long  rl_current_hud_lux = 0;
    unsigned char  rb_hud_refresh_time = 1;
      
    if(rb_hud_data_update == 1)
    {
      rb_hud_data_update = 0;
      rb_hud_refresh_time = GetUpdateTimeForLightStatus();
      if(RW_Update_Time_Count < rb_hud_refresh_time)
      {
        RW_Update_Time_Count++;
        rl_current_hud_lux = (HUDEverageValue[0] + HUDEverageValue[1])/2; 
        if((rl_current_hud_lux < 100) && (RW_Amb_Fw_Result_End < 100))
        {        
             rl_current_hud_lux = (RW_Amb_Fw_Result_End +rl_current_hud_lux)/2;
        }
           
      }
     
      if(rb_hud_refresh_time == RW_Update_Time_Count)//refresh time is reached
      {   
         RW_Update_Time_Count = 0;         
         RW_Amb_Fw_Result_End = AdjustOutHudValue(rl_current_hud_lux);        
      }   
    }
    return RW_Amb_Fw_Result_End;//((HUDEverageValue[0] + HUDEverageValue[1])/2);// + HUDEverageValue[2] + HUDEverageValue[3] + HUDEverageValue[4]) / 5);
}


/*****Bubble Sort**********/
void orderHUDValue(int n)
{
  unsigned long rb_temp_l = 0;
  int i =0;
  int j = 0;
  
  for(i=0;i<n;i++)
   for( j=1;j<n-i;j++)
  {    
    if(rb_storeHUDValueEvery500ms[j-1]>rb_storeHUDValueEvery500ms[j])
    {
      rb_temp_l = rb_storeHUDValueEvery500ms[j];
      rb_storeHUDValueEvery500ms[j] = rb_storeHUDValueEvery500ms[j-1];
      rb_storeHUDValueEvery500ms[j-1] = rb_temp_l ;
    }
  }
}

void GetFiveTableValue_50ms(unsigned long Fw,unsigned long Amb)
{
  static unsigned char rb_k_cycleIn50ms=0;
  unsigned char rb_count = 0;
  
  rb_storeFW_ValueEvery50ms[rb_k_cycleIn50ms] = Fw;
  rb_storeAMB_ValueEvery50ms[rb_k_cycleIn50ms] = Amb;
    
  rb_k_cycleIn50ms++;
  if(rb_k_cycleIn50ms >= 5)
  {
    rb_k_cycleIn50ms = 0;
    FW_Average_In_50ms = rb_storeFW_ValueEvery50ms[0];
    for(rb_count = 1;rb_count < 5;rb_count++)
    {
      FW_Average_In_50ms =(FW_Average_In_50ms+ rb_storeFW_ValueEvery50ms[rb_count])/2;
    }
    
    AMB_Average_In_50ms=rb_storeAMB_ValueEvery50ms[0];
    for(rb_count = 1;rb_count < 5;rb_count++)
    {
      AMB_Average_In_50ms =(AMB_Average_In_50ms+ rb_storeAMB_ValueEvery50ms[rb_count])/2;
    } 
    
    FW_Average_In_50ms = (FW_Average_In_50ms_Old+FW_Average_In_50ms)/2 ;
    AMB_Average_In_50ms = (AMB_Average_In_50ms_Old +AMB_Average_In_50ms)/2; 
    GetFiveTableValue_500ms(FW_Average_In_50ms + AMB_Average_In_50ms);
    FW_Average_In_50ms_Old = FW_Average_In_50ms;
    AMB_Average_In_50ms_Old = AMB_Average_In_50ms;
 
   }  
}
#endif
/******************************************End*********************************************/

/*byte resultCrcTest = 0;
void TestCrcJ1850Info(void)
{
    byte buffer[4]={0x00,0x00,0x00,0x00};//0x59
    byte buffer1[3]={0xF2,0x01,0x83};//0x37
    byte buffer2[4]={0x0F,0xAA,0x00,0x55};//0x79
    byte buffer3[4]={0x00,0xFF,0x55,0x11};//0xB8
    byte buffer4[9]={0x33,0x22,0x55,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF};//0xcb
    byte buffer5[3]={0x92,0x6B,0x55};//0x8C
    byte buffer6[4]={0xFF,0xFF,0xFF,0xFF};//0x74
    
    resultCrcTest =  CRC8SAEJ1850(buffer,4); //ok
    resultCrcTest =  CRC8SAEJ1850(buffer1,3);//ok
    resultCrcTest =  CRC8SAEJ1850(buffer2,4);//ok
    resultCrcTest =  CRC8SAEJ1850(buffer3,4);//ok
    resultCrcTest =  CRC8SAEJ1850(buffer4,9);//ok
    resultCrcTest =  CRC8SAEJ1850(buffer5,3);//ok
    resultCrcTest =  CRC8SAEJ1850(buffer6,4);//ok
    
}*/

byte CRC8SAEJ1850(byte *u8_data,byte u8_len)
{
    byte i, j;
    byte u8_crc8;
    byte u8_poly;

    u8_crc8 = 0xFF;
    u8_poly = 0x1D;

    for (i = 0; i < u8_len; i++)
    {
      u8_crc8 ^= u8_data[i];

      for (j = 0; j < 8; j++)
      {
        if (u8_crc8 & 0x80)
        {
          u8_crc8 = (u8_crc8 << 1) ^ u8_poly;
        }
        else
        {
          u8_crc8 <<= 1;
        }
     }
    }
    u8_crc8 ^= (byte)0xFF;
    return u8_crc8;
}

byte GetOutdBriStsCrcj1850(byte OutdBriSts)
{  
      byte buffer[1];
      buffer[0] = OutdBriSts;
      //TestCrcJ1850Info();
      return CRC8SAEJ1850(buffer,1);  
}

byte GetHudCrcj1850(unsigned long hudSrc)
{     
      byte buffer[2];
      buffer[0] = hudSrc&0xFF;
      buffer[1] = (hudSrc>>8)&0xFF;      
      return CRC8SAEJ1850(buffer,2);  
}

void GetLightTransmission(byte trans_550nm,byte trans_880nm)
{
  byte rb_880nm_Transmission_local_Coding = 0;
  byte rb_550nm_Transmission_local_Coding = 0;
  byte rb_550nm_Transmission_local_Coding_outOfRangeFlag = 0;
  byte rb_880nm_Transmission_local_Coding_outOfRangeFlag = 0;
  
  rb_550nm_Transmission_local_Coding = (trans_550nm);
  rb_550nm_Transmission_local_Coding = (((rb_550nm_Transmission_local_Coding > 90) && (rb_550nm_Transmission_local_Coding <= 100))? 90 : rb_550nm_Transmission_local_Coding);
  
  rb_880nm_Transmission_local_Coding = (trans_880nm);
  rb_880nm_Transmission_local_Coding = (((rb_880nm_Transmission_local_Coding > 90) && (rb_880nm_Transmission_local_Coding <= 100))? 90 : rb_880nm_Transmission_local_Coding);
  
  if((rb_550nm_Transmission_local_Coding >= 15) && (rb_550nm_Transmission_local_Coding <= 90))
  {
    rb_550nm_Transmission_local_Coding = ((rb_550nm_Transmission_local_Coding-15) + 2) / 5; 
    rb_550nm_Transmission_local_Coding_outOfRangeFlag = 0;
    
  }
  else
  {
    rb_550nm_Transmission_local_Coding = 0 ; 
    rb_550nm_Transmission_local_Coding_outOfRangeFlag =1;
  }
  
  
  if((rb_880nm_Transmission_local_Coding >= 15) && (rb_880nm_Transmission_local_Coding <= 90))
  {
    rb_880nm_Transmission_local_Coding = ((rb_880nm_Transmission_local_Coding-15) + 2) / 5; 
    rb_880nm_Transmission_local_Coding_outOfRangeFlag = 0;
  }
  else
  {
    rb_880nm_Transmission_local_Coding = 0 ;
    rb_880nm_Transmission_local_Coding_outOfRangeFlag = 1;
  }
  
  if(rb_550nm_Transmission_local_Coding_outOfRangeFlag == 1 || rb_880nm_Transmission_local_Coding_outOfRangeFlag == 1)
  {
      l_bool_wr_RainSnsrErrCalErr_CEM_LIN1(1);    
  }
  else
  {
     l_bool_wr_RainSnsrErrCalErr_CEM_LIN1(0);
  }
  
  
  if(((rb_550nm_Transmission_local_Coding_outOfRangeFlag == 0) && (rb_880nm_Transmission_local_Coding_outOfRangeFlag == 0))
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

void Get_BCMVehType(byte CarType)
{
  
  static byte rb_VehTypeValueDebounce = 0;
  byte rb_Kodierbyte1_Update_g ; 
  byte rb_BaseType ;// 0 to 3 rain config
  
  if(rb_VehTypeValueDebounce < 20)//if 100MS run once ,2s delay check
  {
      rb_VehTypeValueDebounce ++;
      return ;
  }
   /*check if the E2PROM data has been loaded*/
  if(rbi_EEPROMLoad_g == TRUE)
  {
    return ;
  }
  
  rb_Kodierbyte1_Update_g = rb_Kodierbyte1_g;
  rb_BaseType  = CarType/4;
  
  if((rb_BaseType < 4)&& ( ((rb_Kodierbyte1_Update_g & 12)>>2)!= rb_BaseType)&& ((rbi_EEPROMBytesToWrite_g == FALSE)||(rbi_EEPROMBytesWritten_g == TRUE)))
  {
      rb_Kodierbyte1_Update_g &=0xF3; //Clear 2 and 3 bit
      rb_Kodierbyte1_Update_g |=(rb_BaseType << 2); //set
      rab_EEPROM_Bytes_toWrite_g[0] = rb_Kodierbyte1_Update_g;
      rw_EEPROM_Address_to_Write_g = cw_EEPROM_CODING_ADDRESS_g+1; /*set adress to write*/
      rb_I2C_EEPROM_bytesToWrite_g = 1;         /*set number of bytes to 1*/
      rbi_EEPROMBytesToWrite_g = TRUE;
      rbi_EEPROMBytesWritten_g = FALSE;
  }
  
}

void Set_BCMLightOffset(byte offset)
{
  
  static byte rb_lightValueDebounce = 0;
  byte rb_OldSensorLs ;
  byte rb_Kodierbyte0_Update_g; 
   
  if(rb_lightValueDebounce < 20)//if 100MS run once ,2s delay check
  {
      rb_lightValueDebounce ++;
      return ;
  }
  
  /*check if the E2PROM data has been loaded*/
  if(rbi_EEPROMLoad_g == TRUE)
  {
     return ;
  }
  
  rb_OldSensorLs = (rb_Kodierbyte0_g& 0x38)>>3;
  rb_Kodierbyte0_Update_g = rb_Kodierbyte0_g; 
  
  if((offset < 8)&& (rb_OldSensorLs != offset)&& ((rbi_EEPROMBytesToWrite_g == FALSE)||(rbi_EEPROMBytesWritten_g == TRUE)))
  {
      rb_Kodierbyte0_Update_g &=0xC7; 
      rb_Kodierbyte0_Update_g |=(offset << 3); 
      rab_EEPROM_Bytes_toWrite_g[0] = rb_Kodierbyte0_Update_g;
      rw_EEPROM_Address_to_Write_g = cw_EEPROM_CODING_ADDRESS_g+2; 
      rb_I2C_EEPROM_bytesToWrite_g = 1;         
      rbi_EEPROMBytesToWrite_g = TRUE;
      rbi_EEPROMBytesWritten_g = FALSE;
  }
  
}


void SendRLSSerNo(void)
{
    l_u8_wr_RLSMSerNoNr1_CEM_LIN1(rab_Produktionsdaten_g(0));
    l_u8_wr_RLSMSerNoNr2_CEM_LIN1(rab_Produktionsdaten_g(1));
    l_u8_wr_RLSMSerNoNr3_CEM_LIN1(rab_Produktionsdaten_g(2));
    l_u8_wr_RLSMSerNoNr4_CEM_LIN1(rab_Produktionsdaten_g(3));
}


void SendRLSMPartNo(void)
{
    l_u8_wr_RLSMPartNoNr1_CEM_LIN1(rab_Audi_HW_Partnumber_g(0));
    l_u8_wr_RLSMPartNoNr2_CEM_LIN1(rab_Audi_HW_Partnumber_g(1));
    l_u8_wr_RLSMPartNoNr3_CEM_LIN1(rab_Audi_HW_Partnumber_g(2));
    l_u8_wr_RLSMPartNoNr4_CEM_LIN1(rab_Audi_HW_Partnumber_g(3));
    l_u8_wr_RLSMPartNoEndSgn1_CEM_LIN1(rab_Audi_HW_Partnumber_g(5));
    l_u8_wr_RLSMPartNoEndSgn2_CEM_LIN1(rab_Audi_HW_Partnumber_g(6));
    l_u8_wr_RLSMPartNoEndSgn3_CEM_LIN1(rab_Audi_HW_Partnumber_g(7));
}

void SendRLSMPartNo10(void)
{
    l_u8_wr_RLSMPartNo10Nr1_CEM_LIN1(rab_Audi_HW_Partnumber_g(0));
    l_u8_wr_RLSMPartNo10Nr2_CEM_LIN1(rab_Audi_HW_Partnumber_g(1));
    l_u8_wr_RLSMPartNo10Nr3_CEM_LIN1(rab_Audi_HW_Partnumber_g(2));
    l_u8_wr_RLSMPartNo10Nr4_CEM_LIN1(rab_Audi_HW_Partnumber_g(3));
    l_u8_wr_RLSMPartNo10Nr5_CEM_LIN1(rab_Audi_HW_Partnumber_g(4));
    l_u8_wr_RLSMPartNo10EndSgn1_CEM_LIN1(rab_Audi_HW_Partnumber_g(5));
    l_u8_wr_RLSMPartNo10EndSgn2_CEM_LIN1(rab_Audi_HW_Partnumber_g(6));
    l_u8_wr_RLSMPartNo10EndSgn3_CEM_LIN1(rab_Audi_HW_Partnumber_g(7));
}

/************************************************Winter mode check************************************************/
/**************************T < 0 degree and Speed is under 5KM/H.*************************************************/
void WipeWinterModeCheck(void)
{  
  if((rb_speed_in_kmh_g < 5) && (rb_OutsideTemp_mg <= 0))
  {
     rb_WipeWorkStatus_mg = cb_WINTER_WIPE_MODE;
  }
  else
  {
     rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;
  }  
}

/*!
 * @brief 判断当前byte的极性是否为偶
 *
 * @param byte， 待计算奇偶性的数据.
 * @retval false  byte极性(含1的个数)为奇数.
 * @retval ture， byte极性(含1的个数)为偶数.
 */
byte IsByteOddParity(byte data)
{
    byte parity = FALSE;
   
    while (data)
    {
        parity = !parity;
        data &= data - 1;
    }
    return !parity;
}

