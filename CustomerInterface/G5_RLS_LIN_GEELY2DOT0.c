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
#define _RLS_LIN_c_
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
#define  cb_TEMP_uC_AD90DEGREES_THRS_g 63
#define  cb_TEMP_ASIC_AD90DEGREES_THRS_g 485
#define  cb_TEMP_uC_AD95DEGREES_THRS_g 62
#define  cb_TEMP_ASIC_AD95DEGREES_THRS_g 367
#define  cb_NORMAL_WIPE_MODE 1
#define  cb_WINTER_WIPE_MODE 2
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
//static volatile Flag uF_StalkInPos_Flags_g;


/*************************************************************************
**                   Declaration of local module Macros **
*************************************************************************/
#define cb_FOUR_SECOND_DELAY_mg      25
#define CW_LIN1_3_IDLE_TIMOUT        (2*130)
#define CW_LIN2_0_IDLE_TIMOUT        400
#define cw_CLEARWIPE_DELAY_s         400
#define cb_DEPRESSED_PARK_DEBOUNCE_s 18
#define cb_VERGLSUNG_OPEN_DELAY_mg   100
#define cb_VERGLSUNG_CLOSE_DELAY_mg  100


/*************************************************************************
**                   Declaration of local module Functions              **
*************************************************************************/
#ifdef RAIN_INTENSITY
extern byte rb_RainInt_IntensityOutput_g;
extern word rb_overWipeCoef;
#endif


static void CheckErrors(void);
static void RainFunction(void);
static void LightFunction(void);
static void Humidity_Function(void);
static void StandByMode(void);
static void VoltageDetect(void);
static void OutPutBrightnessValue(void);


#ifdef CS_STANDBY 
static byte rb_Verglasun_ClosedDebounce_mg;
static word rw_CommandCloseWindowTimout_mg;
#endif


static byte rb_AnyErrorCounterDebounce_mg;
static word rw_AfterRSWipeCounter_mg;                   // Time after last wipe from RS
static word rw_AfterRSWipeCounterAlt_mg;              //Time to the last wipe from RS
static word rw_AfterWWSWipeCounter_mg;                  // Time after last wipe from WWS
static  word rw_WipeCommandTimOut_mg;                    //timout for requested wipe
static  byte rb_Err_State_Light_Sens_mg =0;// light error
static  byte  rb_OutsideTemp_mg  = 0;
static  byte rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;


/******************For HUD**********************/
#ifdef HUD_FUNCTION
static unsigned long HUDEverageValue[2] = {0,0};
static unsigned long rb_storeHUDValueEvery500ms[10]={0,0,0,0,0,0,0,0,0,0};
static void GetFiveTableValue_500ms(unsigned long rl_HUD_Brightness_50ms);
static unsigned long CalcHUDMean_1000ms(void);
static void orderHUDValue(int n);
static void GetFiveTableValue_50ms(unsigned long Fw,unsigned long Amb);
static unsigned long  AdjustOutHudValue(unsigned long rl_CurrentHud);
static byte GetUpdateTimeForLightStatus(void);
static  unsigned long RW_Amb_Fw_Result_End    = 0;
static  byte rb_hud_data_update      = 0;
#endif
/********************End***********************/


static void OutPutSolarValue(void);
static void OutPutTwliBriValue(void);
static byte CRC8SAEJ1850(const byte * u8_data,byte u8_len);//crc8saej1850 
static byte GetHudCrcj1850(unsigned long hudSrc);
static byte GetOutdBriStsCrcj1850(byte OutdBriSts,byte OutdBriCounter);
static void GetLightTransmission(byte trans_550nm,byte trans_880nm);
//static void Get_BCMVehType(byte CarType);
static void Set_BCMLightOffset(byte offset);
static void SendRLSSerNo(void);
static void SendRLSMPartNo(void);
static void SendRLSMPartNo10(void);
static void OutPutHudValue(void);
static void OutPutHudSendCount(void);
static void TemperatureDetect(void);
static void WipeWinterModeCheck(void);
static byte IsByteOddParity(byte data);


static void Rain_sensitivity(void);
static void Get_Lin_Signal_From_GetLeWWS(void);
static void Light_Sensitivity_In_GetLeWWS(void);
static void Wiper_and_Park(void);
static void Tunnel_Wipe_Decision(void);
static void Exit_Wipe(void);
static void Rain_Sensitivity_Judge(void);
static void Standby_Judge(void);
static void OutdBriCntr_Counter(void);
static byte CRC8SAEJ1850_00(const byte * u8_data,byte u8_len);
static byte rb_AfterResetCounter_l;
static word rw_IgnitionOffDelay_mg;
static byte rb_tunnelWipeActive_g;  
static byte rb_RLS_Sensitivity_Array_l[7];
static byte rb_Verglasun_offenDebounce_mg;
static byte Vehicle_Speed_Decision_Flag = 0;
static byte Wiperspeed_for_wash = 0;
static byte Wipermode_for_wash = 0;


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
  static byte rb_IgnitionOndelay_mg = 0;
  static byte rb_IntervalOnOndelay_mg;


  if(l_flg_tst_CemCem_Lin1Fr01_CEM_LIN1())
  { 
    l_flg_clr_CemCem_Lin1Fr01_CEM_LIN1();
    rw_NoCommunicationCounter_g = 0;                                 // reset no communication counter
    rbi_ConnectedToMaster_g = 1;                                     // set connected to Master  
    rbi_LightSensitivityRecieved_g = TRUE;    
    rb_speed_in_kmh_g = l_u8_rd_VehSpdForWipg_CEM_LIN1();//needsys   

    
    if(rb_speed_in_kmh_g>=10)
    {
      rbi_speedWasAbove10kmh_g = TRUE;
    }   
    else{}

   
    rbi_Ignition_g = TRUE;
    rw_IgnitionOffDelay_mg = 0;
    if(rb_IgnitionOndelay_mg < 250)
    {
      rb_IgnitionOndelay_mg++;
    }
    else{}
    
    
    if((rbi_RainsensorDisabled_g == FALSE) &&(rb_AfterResetCounter_l> 10))
    {
      if((l_bool_rd_RainSensActvn_CEM_LIN1() == TRUE) || (rbi_RainsensorAlwaysOn_g != FALSE))
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

    if(l_bool_rd_RainSensActvn_CEM_LIN1() == TRUE)                            // copy automatic wiping mode
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

    rb_LIN_SensitivityShift_g =  9;                                     //adaptation Variable for sensitivity factor
    if(l_u8_rd_WiprMotIntlCmd_CEM_LIN1() < 7)
    {
      rb_PotiStageFromBox_g = l_u8_rd_WiprMotIntlCmd_CEM_LIN1();
    }
    else if(l_u8_rd_WiprMotIntlCmd_CEM_LIN1() == 7)
    {
      rb_PotiStageFromBox_g = 3;
    }
    else{}
  }  
  else                                                                  //keine neue Master Nachricht!
  {                                                                     // check if system is on -> to switch off 
    if(rw_NoCommunicationCounter_g > CW_LIN_E2_IDLE_TIMOUT)                               /***4S***/
    {     
      if ((rbi_Command_CloseWindows_g == FALSE)||( rbi_ASICStandByModeRequest_g == FALSE))  /*VDR_526*/
      {
        if ((rb_Verglasun_offenDebounce_mg > cb_VERGLSUNG_OPEN_DELAY_mg) 
            && (rbi_StandbyFunction_enabled_g == TRUE) 
            && (rbi_Command_CloseWindows_g == FALSE))
        {
          rbi_ASICStandByModeRequest_g = 1;                             // Set Request for Standby Mode
          /*******20191112_Zhiyuan HU_Only_for_Winter_Mode********/
          Vehicle_Speed_Decision_Flag = 0;
          /*******************End*******************************/
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
        if ((l_bool_rd_EnaOfflineMonitor_CEM_LIN1() == 0) || (rw_CommandCloseWindowTimout_mg > 6000))
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
        rb_Release_IntervalMarker_Update_g = 0x00;
        rbi_Write_ReleaseMarker_g = TRUE;
      }
    }
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

  Get_Lin_Signal_From_GetLeWWS();
  Standby_Judge();
  Light_Sensitivity_In_GetLeWWS();
  
  
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


  if(((l_bool_rd_RainSensActvn_CEM_LIN1() == FALSE) && (rbi_RealParkContact_g == TRUE))
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
    OutdBriCntr_Counter();
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


  if((First_LIN_Wakeup_Flag == 1) && (LIN_Wakeup_for_Cntr != 1))
	{
		First_LIN_Wakeup_Flag = 0;
		rb_HUD_Cnt_s = 1;
		rb_OutdBri_Cnt_l = 1;		
		l_u8_wr_OutdBriCntr_CEM_LIN1(0);
		l_u8_wr_AmbIllmnFwdStsCntr_CEM_LIN1(0);
	}
	else if((rbi_ConnectedToMaster_g == 0) && (rbi_SendWakeUpFrame_g == 1))
	{
		rb_HUD_Cnt_s = 1;
		rb_OutdBri_Cnt_l = 1;		
		l_u8_wr_OutdBriCntr_CEM_LIN1(0);
		l_u8_wr_AmbIllmnFwdStsCntr_CEM_LIN1(0);
	}

	
#if 0  
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
#endif

  
#ifdef RAIN_INTENSITY  
  /* Rain intensity VCO_423: Interval mode defined*/  
  if(rbi_AutomaticWipingMode_g == TRUE)
  {
    rb_overWipeCoef = rb_Intensity_OverWipeCoef_g;
  }
  else
  {
    rb_overWipeCoef = 100;
  }
#endif
  
  
  RainFunction();//Tunnel wiper,auto wiper,rain level, splash mode, rain sonser error
  CheckErrors();//Other error signals send in this function
  VoltageDetect();//Send high/low voltage error
  TemperatureDetect();//send temperate error
  LightFunction();//light request and the reason of light on                            
#ifdef CS_STANDBY
  StandByMode();//Auto close window
#endif    
  
  
#ifdef CS_OUTPUT_BRIGHTNESS  
  OutPutBrightnessValue();//output FW IR SOLAR brightness
#endif  
  
  
#ifdef CS_HT_MODULE
  Humidity_Function();//dew point & Screen temperature & sensor teamperature & relative Humidity
#endif
  
  
#if defined (ASIC_TEST)
  CopyRLSDataAsic();
#endif

  
  rb_WDG_BusTaskCounter_g++;//increment test counter for bus
}


static void RainFunction(void)
{
  static byte rb_TunnelWipeTimeOut_mg;   
  byte Wiper_speed_l = 0;

	
  Wiper_and_Park();
  Tunnel_Wipe_Decision();
    
    
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
    if(rbi_AutomaticWipingMode_g == TRUE)
    {
      l_u8_wr_WipgAutFrntMod_CEM_LIN1(1);
      l_u8_wr_AutWinWipgCmd_CEM_LIN1(1);
    }
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
    if(rbi_AutomaticWipingMode_g == TRUE)
    {
      l_u8_wr_WipgAutFrntMod_CEM_LIN1(1);
      l_u8_wr_AutWinWipgCmd_CEM_LIN1(1);
    }
  }
  else
  {
    if((rbi_AutomaticWipingMode_g == TRUE) 
       && (rb_WiperSpeed_g != 0) 
         && (rb_WipeWorkStatus_mg == cb_NORMAL_WIPE_MODE))
    {
      if((rbi_RSWipeSlowDmd == 0) && (rbi_RSWipeFastDmd == 0))
      {
        if(rw_AfterWWSWipeCounter_mg > 500)
        {
          l_u8_wr_WipgAutFrntMod_CEM_LIN1(1);
          l_u8_wr_AutWinWipgCmd_CEM_LIN1(1);
        }
        else          
        {
          l_u8_wr_WipgAutFrntMod_CEM_LIN1(2);
          l_u8_wr_AutWinWipgCmd_CEM_LIN1(2);
        }
      }
      else
      {
        l_u8_wr_WipgAutFrntMod_CEM_LIN1(3);
        if(rb_WiperSpeed_g == 1)
        {
          Wiper_speed_l = 2;
        }
        else
        {
          Wiper_speed_l = rb_WiperSpeed_g;
        }
        l_u8_wr_AutWinWipgCmd_CEM_LIN1(Wiper_speed_l);
      }
    }
    else
    {
      Exit_Wipe();
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
  

  if((l_bool_rd_WshngCycActv_CEM_LIN1()) == 1)
  {
    l_u8_wr_AutWinWipgCmd_CEM_LIN1(Wiperspeed_for_wash);
    l_u8_wr_WipgAutFrntMod_CEM_LIN1(Wipermode_for_wash);
  }

  
  rb_WiperSpeedAlt_g = rb_WiperSpeed_g;
  rbi_modi_lightsens_tunnel_alt_mg = rbi_modi_lightsens_tunnel_g;      
  
  
#ifdef RAIN_INTENSITY 
  if(l_bool_rd_RainSnsrErrRainDetnErr_CEM_LIN1() == TRUE)
  {
    l_u8_wr_RainfallAmnt_CEM_LIN1(15);
  }
  else
  {
    l_u8_wr_RainfallAmnt_CEM_LIN1(rb_RainInt_IntensityOutput_g);
  }
#endif
}


static void LightFunction(void)
{
  byte rb_AnyErrorCounterDebounce_l; 
  byte rb_TempLightOn_l = 0;
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
  
  
  if(rb_Err_State_Light_Sens_mg == TRUE)
  {
    rb_TempLightOn_l = 3;  
  }
  else if(((uF_modi_lightsens_g.AllBit & 0x2F) > 0) 
          || (rbi_InternalResetOccured_g > 0) 
            || (rbi_Regulation48LightOnFlag_g !=0))
  {
    rb_TempLightOn_l = 1;
  }
  else
  {
    if ((rb_AnyErrorCounterDebounce_l == 0) && ((get_rb_LightVetoCounter_g()) == 0))
    {
      rb_TempLightOn_l = 2;
    }
    else
    {
      rb_TempLightOn_l = l_u8_rd_OutdBriSts_CEM_LIN1();
    }
  }
  

  if((rbi_EEPROMLoad_g == FALSE)
      && ((rb_RSControlFlags_g == cb_HUMIDITY_SOLAR ) 
          ||(rb_RSControlFlags_g == cb_ONLY_HUMIDITY)))
  {
    rb_TempLightOn_l = 1;
    l_u8_wr_OutdBriSts_CEM_LIN1(rb_TempLightOn_l);   
  } 
  else
  {
    /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
    DISABLE_SCIINTERRUPT();
    l_u8_wr_OutdBriSts_CEM_LIN1(rb_TempLightOn_l);
    ENABLE_SCIINTERRUPT();
  } 
  
  
  if(rbi_LightValuesInitialised_g == FALSE)
  {
    rb_TempLightOn_l = 0;
    l_u8_wr_OutdBriSts_CEM_LIN1(rb_TempLightOn_l);
  }
  else{}
  
  
  rb_crc_StsOutdBriSts =  GetOutdBriStsCrcj1850(rb_TempLightOn_l,l_u8_rd_OutdBriCntr_CEM_LIN1());
  l_u8_wr_OutdBriChks_CEM_LIN1(rb_crc_StsOutdBriSts);


  if((rbi_modi_lightsens_rain_g == TRUE) && (rbi_RainLight_enabled_g == TRUE))
  {
    l_bool_wr_RainLi_CEM_LIN1(1);
  }
  else
  {
    l_bool_wr_RainLi_CEM_LIN1(0);
  }


  if((uF_modi_lightsens_g.AllBit & 0x0F) == cb_DAY_mg)
  {
    rb_OpModeState = 1;
  }
  else if(((uF_modi_lightsens_g.AllBit & 0x0F) == cb_NIGHT_mg) 
          || ((uF_modi_lightsens_g.AllBit & 0x0F) == cb_DARKSTART_mg))
  {
    rb_OpModeState = 0;
  }
  else if((uF_modi_lightsens_g.AllBit & 0x0F) == cb_TUNNEL_mg)
  {
    rb_OpModeState = 3;
  }
  else{}
  l_u8_wr_LiOprnMod_CEM_LIN1(rb_OpModeState);
}


#ifdef CS_HT_MODULE
static void Humidity_Function(void)
{
  //static word rw_Temperature_Sensor_g;
  static word rw_Temperature_Scheibe_g;
  
  
  if (rbi_HumTempComError_g != 0)
  {
    l_bool_wr_RelHumSnsrErr_CEM_LIN1(1);    
    l_u16_wr_CmptFrntWindT_CEM_LIN1(1360);      //window temperature   
    l_u8_wr_RelHumSnsrRelHum_CEM_LIN1(255);     // relation hum
    l_u16_wr_CmptFrntWindDewT_CEM_LIN1(2047);  //dew point temperature    
  }
  else
  {
    //l_bool_wr_CmptFrntWindTErr_CEM_LIN1(0);
    l_bool_wr_RelHumSnsrErr_CEM_LIN1(0);  

    
    if(rw_Temperature_raw_g < 0x2ad)                         // The temperature less than -40 the tool doesnot support 
    {
      rw_Temperature_Scheibe_g = 0x2ad;
    }
    else if(rw_Temperature_raw_g > 0x4321)
    {
      rw_Temperature_Scheibe_g = 0x4321;    
    }
    else
    {
      rw_Temperature_Scheibe_g = rw_Temperature_raw_g;
    }    
      
    
    if(rw_Temperature_raw_g == cw_HUMTEMP_INIT_g)
    {
      l_u16_wr_CmptFrntWindT_CEM_LIN1(600);
    }
    else
    {
      if(((rw_Temperature_Scheibe_g -685)/10) < 1650)
      {        
        l_u16_wr_CmptFrntWindT_CEM_LIN1(((rw_Temperature_Scheibe_g -685)/10));
      }
      else
      {         
        l_u16_wr_CmptFrntWindT_CEM_LIN1(1350);
      }
    } 
  
    
    if (rw_DewPoint_g == cw_HUMTEMP_INIT_g)
    {
      l_u16_wr_CmptFrntWindDewT_CEM_LIN1(650);
    }    
    else
    {
      if (rw_DewPoint_g < 1650)
      {                                                                       
        l_u16_wr_CmptFrntWindDewT_CEM_LIN1((rw_DewPoint_g + 4));        
      }
      else
      {
        l_u16_wr_CmptFrntWindDewT_CEM_LIN1(1650);
      }
    }
      
    
    if (rb_Humidity_g == cw_HUMTEMP_INIT_g)
    {
      l_u8_wr_RelHumSnsrRelHum_CEM_LIN1(80);
    }        
    else
    {        
      l_u8_wr_RelHumSnsrRelHum_CEM_LIN1(rb_Humidity_raw_g - 1);
    }   
  }
}
#endif


#ifdef CS_STANDBY
static void StandByMode(void)
{
  if((rb_Verglasun_ClosedDebounce_mg > cb_VERGLSUNG_CLOSE_DELAY_mg) 
     ||(l_bool_rd_EnaOfflineMonitor_CEM_LIN1() != 1) 
       || (rw_CommandCloseWindowTimout_mg > 6000))
  {
    rbi_Command_CloseWindows_g = FALSE;
    rbi_ASICStandByModeRequest_g = FALSE;
  }
  else{}  
  
  
  if(rbi_SendWakeUpFrame_g == TRUE)
  {
    ApplLinInit(0x01);
    rbi_SendWakeUpFrame_g = FALSE;                      
  }
  else{}
  
  
  if(rbi_Command_CloseWindows_g == TRUE)
  {
    l_bool_wr_RainDetected_CEM_LIN1(1); 
    if (rw_CommandCloseWindowTimout_mg > 6000)
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


static void VoltageDetect(void)
{
  static byte rb_underVoltageTimer_s;
  
  
  if(rbi_UnderVoltage_g == TRUE)
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
  
  
  //if(rbi_UnderVoltage_g == TRUE)
  //{
  //  //l_u8_wr_L_Err_State_Volt(rbi_UnderVoltage_g);    //voltage error statue
  //}
  if(rbi_OverVoltage_g == TRUE)
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
static void TemperatureDetect(void)
{
  static word rb_overTemperatureTimer_s;
  byte rb_temperateOver_l = 0;
  
  
  if(((rb_InternalTemperature_g > 0) && (rb_InternalTemperature_g < cb_TEMP_uC_AD95DEGREES_THRS_g)) 
        || ((rw_VTEMP_ASIC_g > 0) && (rw_VTEMP_ASIC_g < cb_TEMP_ASIC_AD95DEGREES_THRS_g)))
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
  else if(((rb_InternalTemperature_g > 0) && (rb_InternalTemperature_g< cb_TEMP_uC_AD90DEGREES_THRS_g)) 
          || ((rw_VTEMP_ASIC_g > 0) && (rw_VTEMP_ASIC_g < cb_TEMP_ASIC_AD90DEGREES_THRS_g))) 
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
static void OutPutHudSendCount(void)
{
  //static byte rb_HUD_Cnt_s = 1;
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


static void OutPutHudValue(void)
{
  byte rb_hud_Crc8_l;
  unsigned long rl_hud_Brightness_l;
  unsigned long rl_hud_AMB_Brightness_l;
  unsigned long rl_hud_FW_Brightness_l; 
  //unsigned long rl_eeprom_hud_max_l = 0;
  byte rb_hud_High8Bit_l = 0;
  word rw_hud_Low9Bit_l  = 0;

  
  /*Get the Real Lux for FW and AMB  Illuminance = FW*6 + AMB*15*/
  rl_hud_AMB_Brightness_l = 15*((unsigned long)(get_rw_Amb_light16bit_g()));
  rl_hud_FW_Brightness_l = (unsigned long)((3*((unsigned long)(get_rl_HUD_light32bit_g())))>>1);

  
  /*Pre-Process for original value get average for "rl_HUD_AMB_Brightness" and "rl_HUD_FW_Brightness"*/
  /*100ms average for AMB and FW        1000ms for sum average      */
  GetFiveTableValue_50ms(rl_hud_AMB_Brightness_l,rl_hud_FW_Brightness_l);   
    
  
  /*5000ms for average output*/
  rl_hud_Brightness_l  = CalcHUDMean_1000ms();
      
#if 0  
  /*Output to LIN Interface*/
  rl_eeprom_hud_max_l = (unsigned long)((unsigned long)rb_HUD_MAX_Resolution_g * ((unsigned long)rw_HUD_MAX_Value_g));
  if(rl_hud_Brightness_l >= rl_eeprom_hud_max_l)
  {
    rl_hud_Brightness_l = rl_eeprom_hud_max_l;        
  }
  else{}
#endif
  
  if(rl_hud_Brightness_l > 126000)//currnet send data  length is shorter
  {
    rl_hud_Brightness_l = 126000;
  } 
  else{}

  
  rw_hud_Low9Bit_l = (word)((rl_hud_Brightness_l&0x1ff));
  rb_hud_High8Bit_l  = (byte)((rl_hud_Brightness_l>>9)&0xFF);

  
  l_u16_wr_AmbIllmnFwdStsAmblillmn1_CEM_LIN1(rw_hud_Low9Bit_l);
  l_u8_wr_AmbIllmnFwdStsAmblillmn2_CEM_LIN1(rb_hud_High8Bit_l);

  
  //check crc 
  rb_hud_Crc8_l = GetHudCrcj1850(rl_hud_Brightness_l);
  l_u8_wr_AmbIllmnFwdStsChks_CEM_LIN1(rb_hud_Crc8_l);
  /*end hud info relation*/  
}


static void OutPutTwliBriValue(void)
{
  if((get_rw_Amb_light16bit_g() * 20) < 16382)    
  {
    l_u16_wr_TwliBriRawTwliBriRaw_CEM_LIN1((get_rw_Amb_light16bit_g() * 20));
  }
  else
  {
    l_u16_wr_TwliBriRawTwliBriRaw_CEM_LIN1(16382);
  } 
}


static void OutPutSolarValue(void)
{
  
#ifdef CS_SOLAR
  word rw_IrLightforSOSE_Corr1_l;
  word rw_IrLightforSOSE_Corr2_l;
  word rw_SoSe_SunInt_2D_Le_l;
  word rw_SoSe_SunInt_2D_Re_l; 
        
  if (rbi_SoSe_Enabled_g == TRUE)
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
  else{}


  if(rbi_SolarValuesInitialised_g == FALSE)
  {
    l_u8_wr_SolarSnsrLeValue_CEM_LIN1(0x32);
    l_u8_wr_SolarSnsrRiValue_CEM_LIN1(0x32);
  }
#endif
}


static void OutPutBrightnessValue(void)
{
  static byte rb_InitLightValCnt_l=100;
 
  
  if((rbi_LightValuesInitialised_g == FALSE)|| (rbi_EEPROMLoad_g == TRUE))
  {
    if(rb_InitLightValCnt_l<100)
    {
      rb_InitLightValCnt_l++;
    }
    else
    { 
      l_u16_wr_AmbIllmnFwdStsAmblillmn1_CEM_LIN1(0);
      l_u8_wr_AmbIllmnFwdStsAmblillmn2_CEM_LIN1(0);
			l_u8_wr_AmbIllmnFwdStsChks_CEM_LIN1(0xF1);
      l_u16_wr_TwliBriRawTwliBriRaw_CEM_LIN1(0);
      l_u8_wr_TwliBriRawQf_CEM_LIN1(1);
      l_u8_wr_SolarSnsrRiValue_CEM_LIN1(0x32);        // Init 
      l_u8_wr_SolarSnsrLeValue_CEM_LIN1(0x32);         // Init
    }
  }
  else
  {
    rb_InitLightValCnt_l=0;
#if 0
    if(rb_RSControlFlags_g == cb_ONLY_HUMIDITY)
    {
      l_u16_wr_AmbIllmnFwdStsAmblillmn1_CEM_LIN1(0x1FF);
      l_u8_wr_AmbIllmnFwdStsAmblillmn2_CEM_LIN1(0xFF);
      l_u8_wr_AmbIllmnFwdStsChks_CEM_LIN1(0xA3);
      l_u16_wr_TwliBriRawTwliBriRaw_CEM_LIN1(16383);
      l_u8_wr_SolarSnsrRiValue_CEM_LIN1(0xFF);
      l_u8_wr_SolarSnsrLeValue_CEM_LIN1(0xFF);
    }
#endif
    if(rb_Err_State_Light_Sens_mg == TRUE)                    /*  VDR469   set for error*/
    {
      l_u16_wr_AmbIllmnFwdStsAmblillmn1_CEM_LIN1(0x1FF);
      l_u8_wr_AmbIllmnFwdStsAmblillmn2_CEM_LIN1(0xFF);
      l_u8_wr_AmbIllmnFwdStsChks_CEM_LIN1(0xA3);
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
  bi_RS_VariantError_g = 0;
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
  

  l_bool_wr_RainSnsrErrRainDetnErrActv_CEM_LIN1(1);  
  

#ifndef _NO_RAIN_
  //15:RLFS 7:RLS
  if((rb_RSControlFlags_g == 15) || (rb_RSControlFlags_g == 7))
  {
    /* VCO132: SM210 - ASIC Frequency Check (done at startup) - LS,RS_Failure */
    /* VCO 140: SM150 - ADC test */
    /* setze Lichtsensor RS-Fehler nach SRS */
    /*SM240*/
    l_bool_wr_RainSnsrErrRainDetnErr_CEM_LIN1((rb_RS_LS_Error1_g != 0) 
                                                 || (rb_RS_LS_Error2_g != 0) 
                                                   || (rb_RainS_Error1_g != 0) 
                                                     || (rbi_HammingError_g != 0));
  }
#else
  /*only RAM/ROM error and RS version error*/
  l_bool_wr_RainSnsrErrRainDetnErr_CEM_LIN1(((rb_RS_LS_Error1_g&0x3) != 0)||(rbi_HammingError_g != 0));
#endif /*_NO_RAIN_*/
  
  
  if(((rb_RS_LS_Error1_g != 0) 
      || (rb_RS_LS_Error2_g != 0) 
        || (rb_LightS_Error1_g != 0) 
          || (rbi_HammingError_g != 0) 
            || (rbi_CRC_ChangedByDiagnostic_g)))
  {
    rb_Err_State_Light_Sens_mg = 1;
    l_u8_wr_TwliBriRawQf_CEM_LIN1(0);
    l_bool_wr_SolarSnsrErr_CEM_LIN1(TRUE);
    l_bool_wr_HudSnsrErrSnsrErr_CEM_LIN1(TRUE);
  }
  else
  {
    rb_Err_State_Light_Sens_mg = 0;
    l_u8_wr_TwliBriRawQf_CEM_LIN1(3);
    l_bool_wr_SolarSnsrErr_CEM_LIN1(FALSE);
    l_bool_wr_HudSnsrErrSnsrErr_CEM_LIN1(FALSE);
  }
  
  
  rb_hud_errorParity_l = IsByteOddParity(l_bool_rd_HudSnsrErrSnsrErr_CEM_LIN1());
  l_bool_wr_HudSnsrErrParChk_CEM_LIN1(rb_hud_errorParity_l);
}

void ApplLinInit(byte rb_LIN_State_l)
{
  byte rb_Index_l; 
   
  
  static const byte LinMsgDefault_RlsmCem_SerNrLin1Fr01_CEM_LIN1[4] = {0,0,0,0};/*0x22*/
  static const byte LinMsgDefault_RlsmCem_Lin1PartNrFr02_CEM_LIN1[8] = {0,0,0,0,0,0,0,0};/*0x18*/
  static const byte LinMsgDefault_RlsmCem_Lin1PartNrFr01_CEM_LIN1[7] = {0,0,0,0,0,0,0};/*0x20*/
  static const byte LinMsgDefault_RlsmCem_Lin1Fr03_CEM_LIN1[8] = {0,14,50,50,0,0,0,0};/*0x02*/
  static const byte LinMsgDefault_RlsmCem_Lin1Fr02_CEM_LIN1[8] = {88,2,0,0,0,0,75,80};/*0x2C*/
  static const byte LinMsgDefault_RlsmCem_Lin1Fr01_CEM_LIN1[8] = {0,0,0,1,0,0,0,0};/*0x15*/

  
  rb_Index_l = 0;
  do
  {
    //RlsmCem_SerNrLin1Fr01_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_SerNrLin1Fr01_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1PartNrFr02_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1PartNrFr02_CEM_LIN1[rb_Index_l];
    //RlsmCem_Lin1PartNrFr01_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1PartNrFr01_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1Fr03_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1Fr03_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1Fr02_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1Fr02_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1Fr01_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1Fr01_CEM_LIN1[rb_Index_l];
    rb_Index_l++;
  } while (rb_Index_l < 8);
    
  
  rb_Index_l = 0;
  do
  {
    RlsmCem_SerNrLin1Fr01_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_SerNrLin1Fr01_CEM_LIN1[rb_Index_l];
    rb_Index_l++;
  } while (rb_Index_l < 4);

  
  rb_Index_l = 0;
  do
  {
    RlsmCem_Lin1PartNrFr01_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1PartNrFr01_CEM_LIN1[rb_Index_l];
    rb_Index_l++;
  } while (rb_Index_l < 7);

  
#ifdef _SUPPORTMWLLIGHT_
  Diagnose_ReadMem_Init();
#endif
  
  
  rw_AfterRSWipeCounter_mg = 50000;
  rw_AfterRSWipeCounterAlt_mg = 50000;
  rw_AfterWWSWipeCounter_mg = 50000;//Direktbitdelay bei Kl15 Aus hochsetzen!
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
  else{}
}


/*HUD Algrithm shenzhen-team 2018-05-05*/
#ifdef HUD_FUNCTION
static void GetFiveTableValue_500ms(unsigned long rl_HUD_Brightness_50ms)
{
  static byte rb_k_cycleIn50ms=0;
  static byte rb_k_cycleIn500ms=0;
  
  
  rb_storeHUDValueEvery500ms[rb_k_cycleIn50ms] = rl_HUD_Brightness_50ms;
    
  
  rb_k_cycleIn50ms++;
  if(rb_k_cycleIn50ms >= 10)
  {
    rb_k_cycleIn50ms = 0;
    orderHUDValue(10);
    HUDEverageValue[rb_k_cycleIn500ms] = ((rb_storeHUDValueEvery500ms[3] 
                                           + rb_storeHUDValueEvery500ms[4] 
                                             + rb_storeHUDValueEvery500ms[5] 
                                               + rb_storeHUDValueEvery500ms[6] 
                                                 + rb_storeHUDValueEvery500ms[7]) 
                                                   / 5);
    rb_k_cycleIn500ms++;
    if(rb_k_cycleIn500ms >= 2)
    {
      rb_k_cycleIn500ms=0;  
      rb_hud_data_update = 1;
    }    
  }
}


static unsigned long AdjustOutHudValue(unsigned long rl_CurrentHud)
{
  word currLevel = 0;
  word rw_LastCurrDiff = 0;
  unsigned long  rl_adjustAfterHud = 0;

  
  if(rl_CurrentHud >= 100)
  {
    return rl_CurrentHud;
  }
  else{}
  
  
  currLevel = RW_Amb_Fw_Result_End / 10;  
  if(rl_CurrentHud >= RW_Amb_Fw_Result_End)
  {
    rw_LastCurrDiff = rl_CurrentHud - RW_Amb_Fw_Result_End;
  }
  else
  {
    rw_LastCurrDiff = RW_Amb_Fw_Result_End - rl_CurrentHud;
  }
  if(rw_LastCurrDiff <= 15)
  {
    return  rl_CurrentHud;
  }
  else{}
  

  if(rl_CurrentHud >= RW_Amb_Fw_Result_End)
  {
    currLevel = currLevel + (rw_LastCurrDiff / 15);
    rw_LastCurrDiff = rw_LastCurrDiff % 3;
    if(currLevel > 9)
    {
      rl_adjustAfterHud = 92 + (unsigned long)rw_LastCurrDiff;
    }
    else
    {
      rl_adjustAfterHud = 5 + (currLevel * 10) + (unsigned long)rw_LastCurrDiff;
    }
  }
  else
  {
    if(currLevel >= (rw_LastCurrDiff / 15))
    {
      currLevel = currLevel - (rw_LastCurrDiff / 15);
      rw_LastCurrDiff = rw_LastCurrDiff % 3;
      if(currLevel > 9)
      {
        rl_adjustAfterHud = 92 - (unsigned long)rw_LastCurrDiff;
      }
      else
      {
        rl_adjustAfterHud = ((5 + (currLevel * 10)) - (unsigned long)rw_LastCurrDiff);
      }
    }
    else
    {
      rw_LastCurrDiff = rw_LastCurrDiff % 3;
      rl_adjustAfterHud = 5 - (unsigned long)rw_LastCurrDiff;
    }
  }
  
  
  return  rl_adjustAfterHud;    
}


static byte GetUpdateTimeForLightStatus(void)
{
  unsigned char  hud_refresh_time = 1;  
  //1 in tunnel and day for 1s  get data;in night and darkstart for 3s  get data 
  //2 if in tunnel and speed less 10,then 3s will upate
  if((rbi_LightSensorActive_g == TRUE) && (rbi_EEPROMLoad_g == FALSE))
  {
    if((uF_modi_lightsens_g.AllBit & cb_NIGHT_mg) > 0)
    {
      hud_refresh_time = 3;
    }
    else if ((uF_modi_lightsens_g.AllBit & cb_TUNNEL_mg) > 0)
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
    else if ((uF_modi_lightsens_g.AllBit & cb_DARKSTART_mg) > 0)
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


static unsigned long CalcHUDMean_1000ms(void)
{  
  static  unsigned char RW_Update_Time_Count = 0;
  unsigned long  rl_current_hud_lux = 0;
  unsigned char  rb_hud_refresh_time = 1;
      
  if(rb_hud_data_update == 1)
  {
    rb_hud_data_update = 0;
    
    
    rb_hud_refresh_time = GetUpdateTimeForLightStatus();
    if(RW_Update_Time_Count < rb_hud_refresh_time)
    {
      RW_Update_Time_Count++;  
    }
    else{}
     
    
    //internal data updata time is 1s
    //Data send to BCM is decided for  RW_Update_Time_Count and rb_hud_refresh_time
    //if rl_current_hud_lux and RW_Amb_Fw_Result_End  are less than 100, we will get average value
    rl_current_hud_lux = (HUDEverageValue[0] + HUDEverageValue[1])/2; 
    if((rl_current_hud_lux < 100) && (RW_Amb_Fw_Result_End < 100))
    {        
      rl_current_hud_lux = (RW_Amb_Fw_Result_End +rl_current_hud_lux)/2;
    }  
      
    if(rb_hud_refresh_time <= RW_Update_Time_Count)//refresh time is reached
    {   
      RW_Update_Time_Count = 0;        
      RW_Amb_Fw_Result_End = AdjustOutHudValue(rl_current_hud_lux);         
    }
    else{}    
  }  
  return RW_Amb_Fw_Result_End;
}


/*****Bubble Sort**********/
static void orderHUDValue(int n)
{
  unsigned long rb_temp_l = 0;
  int i =0;
  int j = 0;
  
  for(i = 0;i < n;i++)
  {
    for(j = 1;j < (n-i);j++)
    {    
      if(rb_storeHUDValueEvery500ms[j-1] > rb_storeHUDValueEvery500ms[j])
      {
        rb_temp_l = rb_storeHUDValueEvery500ms[j];
        rb_storeHUDValueEvery500ms[j] = rb_storeHUDValueEvery500ms[j-1];
        rb_storeHUDValueEvery500ms[j-1] = rb_temp_l ;
      }
      else{}
    }
  }
}


static void GetFiveTableValue_50ms(unsigned long Fw,unsigned long Amb)
{
  static unsigned long FW_Average_In_50ms = 0;
  static unsigned long AMB_Average_In_50ms = 0;
  static unsigned long FW_Average_In_50ms_Old = 0;
  static unsigned long AMB_Average_In_50ms_Old = 0;
  static unsigned long rb_storeFW_ValueEvery50ms[10]={0,0,0,0,0,0,0,0,0,0};
  static unsigned long rb_storeAMB_ValueEvery50ms[10]={0,0,0,0,0,0,0,0,0,0};
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


static byte CRC8SAEJ1850(const byte * u8_data,byte u8_len)
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
      if ((u8_crc8 & 0x80) > 0)
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


static byte GetOutdBriStsCrcj1850(byte OutdBriSts,byte OutdBriCounter)
{  
  byte buffer[4];
  buffer[0] = 0x42;
  buffer[1] = 0x1F;
  buffer[2] = OutdBriCounter;
  buffer[3] = OutdBriSts;
  //TestCrcJ1850Info();
  return CRC8SAEJ1850_00(buffer,4);  
}

static byte GetHudCrcj1850(unsigned long hudSrc)
{     
  //byte buffer[2];
  //buffer[0] = hudSrc&0xFF;
  //buffer[1] = (hudSrc>>8)&0xFF;      
  //return CRC8SAEJ1850(buffer,2);
  /**********Zhiyuan HU 20190313**************/
  byte buffer[3];
  buffer[0] = hudSrc&0xFF;
  buffer[1] = (hudSrc>>8)&0xFF;
  buffer[2] = (hudSrc>>16)&0xFF;
  return CRC8SAEJ1850(buffer,3);
  /**********Zhiyuan HU 20190313**************/
}


static void GetLightTransmission(byte trans_550nm,byte trans_880nm)
{
  byte rb_880nm_Transmission_local_Coding = 0;
  byte rb_550nm_Transmission_local_Coding = 0;
  //byte rb_550nm_Transmission_local_Coding_outOfRangeFlag = 0;
  //byte rb_880nm_Transmission_local_Coding_outOfRangeFlag = 0;
  l_bool_wr_RainSnsrErrCalErr_CEM_LIN1(0);
  
  
  if(((trans_550nm >= 15) && (trans_550nm <= 90)) && ((trans_880nm >= 15) && (trans_880nm <= 90)))
  {
    rb_550nm_Transmission_local_Coding = ((trans_550nm - 15 ) + 2) / 5;
    rb_880nm_Transmission_local_Coding = ((trans_880nm - 15 ) + 2) / 5;

    if((rb_Kodierbyte2_g != ((rb_880nm_Transmission_local_Coding << 4) | rb_550nm_Transmission_local_Coding)) 
       && ((rbi_EEPROMBytesToWrite_g == FALSE)||(rbi_EEPROMBytesWritten_g == TRUE)))
    {
      rab_EEPROM_Bytes_toWrite_g[0] = ((rb_880nm_Transmission_local_Coding << 4) | rb_550nm_Transmission_local_Coding);
      rw_EEPROM_Address_to_Write_g = cw_EEPROM_CODING_ADDRESS_g; /*set adress to write*/
      rb_I2C_EEPROM_bytesToWrite_g = 1;         /*set number of bytes to 1*/
      rbi_EEPROMBytesToWrite_g = TRUE;
      rbi_EEPROMBytesWritten_g = FALSE;
    }
  }
}

#if 0
static void Get_BCMVehType(byte CarType)
{
  static byte rb_VehTypeValueDebounce = 0;
  byte rb_Kodierbyte1_Update_l;  
  byte rb_BaseType;// 0 to 3 rain config
  
  
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
  
  
  rb_Kodierbyte1_Update_l = rb_Kodierbyte1_g;
  rb_BaseType  = CarType/4;
  
  
  if((rb_BaseType < 4) 
     && (((rb_Kodierbyte1_Update_l & 12)>>2)!= rb_BaseType) 
       && ((rbi_EEPROMBytesToWrite_g == FALSE) || (rbi_EEPROMBytesWritten_g == TRUE)))
  {
    rb_Kodierbyte1_Update_l &=0xF3; //Clear 2 and 3 bit
    rb_Kodierbyte1_Update_l |=((rb_BaseType & 3) << 2); //set
    rab_EEPROM_Bytes_toWrite_g[0] = rb_Kodierbyte1_Update_l;
    rw_EEPROM_Address_to_Write_g = cw_EEPROM_CODING_ADDRESS_g+1; /*set adress to write*/
    rb_I2C_EEPROM_bytesToWrite_g = 1;         /*set number of bytes to 1*/
    rbi_EEPROMBytesToWrite_g = TRUE;
    rbi_EEPROMBytesWritten_g = FALSE;
  }
}
#endif

static void Set_BCMLightOffset(byte offset)
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
  
  
  if((offset < 8) 
     && (rb_OldSensorLs != offset) 
       && ((rbi_EEPROMBytesToWrite_g == FALSE)||(rbi_EEPROMBytesWritten_g == TRUE)))
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


static void SendRLSSerNo(void)
{
  unsigned long d = 0;
  byte a,b,c,e,f,g,h;

  a = (rab_Produktionsdaten_g(0));
  b = a / 16;
  c = a % 16;
  d = (b * 10000000) + (c * 1000000);


  a = (rab_Produktionsdaten_g(1));
  b = a / 16;
  c = a % 16;
  d = (b * 100000) + (c * 10000) + d;


  a = (rab_Produktionsdaten_g(2));
  b = a / 16;
  c = a % 16;
  d = (b * 1000) + (c * 100) + d;


  a = (rab_Produktionsdaten_g(3));
  b = a / 16;
  c = a % 16;
  d = (b * 10) + (c * 1) + d;


  e = (d >> 0) & 0xff;
  f = (d >> 8) & 0xff;
  g = (d >> 16) & 0xff;
  h = (d >> 24) & 0xff;


  l_u8_wr_RLSMSerNoNr1_CEM_LIN1(h);
  l_u8_wr_RLSMSerNoNr2_CEM_LIN1(g);
  l_u8_wr_RLSMSerNoNr3_CEM_LIN1(f);
  l_u8_wr_RLSMSerNoNr4_CEM_LIN1(e);
}


static void SendRLSMPartNo(void)
{
#if 0
    l_u8_wr_RLSMPartNoNr1_CEM_LIN1(rab_Audi_HW_Partnumber_g(0));
    l_u8_wr_RLSMPartNoNr2_CEM_LIN1(rab_Audi_HW_Partnumber_g(1));
    l_u8_wr_RLSMPartNoNr3_CEM_LIN1(rab_Audi_HW_Partnumber_g(2));
    l_u8_wr_RLSMPartNoNr4_CEM_LIN1(rab_Audi_HW_Partnumber_g(3));
    l_u8_wr_RLSMPartNoEndSgn1_CEM_LIN1(rab_Audi_HW_Partnumber_g(5));
    l_u8_wr_RLSMPartNoEndSgn2_CEM_LIN1(rab_Audi_HW_Partnumber_g(6));
    l_u8_wr_RLSMPartNoEndSgn3_CEM_LIN1(rab_Audi_HW_Partnumber_g(7));
#endif

    
  l_u8_wr_RLSMPartNoNr1_CEM_LIN1(0);
  l_u8_wr_RLSMPartNoNr2_CEM_LIN1(0);
  l_u8_wr_RLSMPartNoNr3_CEM_LIN1(0);
  l_u8_wr_RLSMPartNoNr4_CEM_LIN1(0);
  l_u8_wr_RLSMPartNoEndSgn1_CEM_LIN1(0x20);
  l_u8_wr_RLSMPartNoEndSgn2_CEM_LIN1(0x20);
  l_u8_wr_RLSMPartNoEndSgn3_CEM_LIN1(0x20);
}


static void SendRLSMPartNo10(void)
{
  if(rb_RSControlFlags_g == 15)
  {
    //15:RLFS
    l_u8_wr_RLSMPartNo10Nr1_CEM_LIN1(0x88);
    l_u8_wr_RLSMPartNo10Nr2_CEM_LIN1(0x89);
    l_u8_wr_RLSMPartNo10Nr3_CEM_LIN1(0x07);
    l_u8_wr_RLSMPartNo10Nr4_CEM_LIN1(0x24);
    l_u8_wr_RLSMPartNo10Nr5_CEM_LIN1(0x28);
    l_u8_wr_RLSMPartNo10EndSgn1_CEM_LIN1(0x20);
    l_u8_wr_RLSMPartNo10EndSgn2_CEM_LIN1(0x20);
    l_u8_wr_RLSMPartNo10EndSgn3_CEM_LIN1(0x46);
  }
  else if(rb_RSControlFlags_g == 7)
  {
    //7:RLS
    l_u8_wr_RLSMPartNo10Nr1_CEM_LIN1(0x88);
    l_u8_wr_RLSMPartNo10Nr2_CEM_LIN1(0x88);
    l_u8_wr_RLSMPartNo10Nr3_CEM_LIN1(0x99);
    l_u8_wr_RLSMPartNo10Nr4_CEM_LIN1(0x81);
    l_u8_wr_RLSMPartNo10Nr5_CEM_LIN1(0x20);
    l_u8_wr_RLSMPartNo10EndSgn1_CEM_LIN1(0x20);
    l_u8_wr_RLSMPartNo10EndSgn2_CEM_LIN1(0x20);
    l_u8_wr_RLSMPartNo10EndSgn3_CEM_LIN1(66);
  }
  else if(rb_RSControlFlags_g == 14)
  {
    //14:LFS
    l_u8_wr_RLSMPartNo10Nr1_CEM_LIN1(0x88);
    l_u8_wr_RLSMPartNo10Nr2_CEM_LIN1(0x88);
    l_u8_wr_RLSMPartNo10Nr3_CEM_LIN1(0x99);
    l_u8_wr_RLSMPartNo10Nr4_CEM_LIN1(0x81);
    l_u8_wr_RLSMPartNo10Nr5_CEM_LIN1(0x23);
    l_u8_wr_RLSMPartNo10EndSgn1_CEM_LIN1(0x20);
    l_u8_wr_RLSMPartNo10EndSgn2_CEM_LIN1(0x20);
    l_u8_wr_RLSMPartNo10EndSgn3_CEM_LIN1(66);
  }
  else if(rb_RSControlFlags_g == 6)
  {
    //6:LS
    l_u8_wr_RLSMPartNo10Nr1_CEM_LIN1(0x88);
    l_u8_wr_RLSMPartNo10Nr2_CEM_LIN1(0x88);
    l_u8_wr_RLSMPartNo10Nr3_CEM_LIN1(0x99);
    l_u8_wr_RLSMPartNo10Nr4_CEM_LIN1(0x81);
    l_u8_wr_RLSMPartNo10Nr5_CEM_LIN1(0x13);
    l_u8_wr_RLSMPartNo10EndSgn1_CEM_LIN1(0x20);
    l_u8_wr_RLSMPartNo10EndSgn2_CEM_LIN1(0x20);
    l_u8_wr_RLSMPartNo10EndSgn3_CEM_LIN1(66);
  }
  else{}
}


/*T < 0 degree and Speed is under 5KM/H.*/
static void WipeWinterModeCheck(void)
{  
  if(rb_speed_in_kmh_g > 5)
  {
    Vehicle_Speed_Decision_Flag = 1;
  }


  if((Vehicle_Speed_Decision_Flag == 0) && (rb_OutsideTemp_mg < 80))
  {
    rb_WipeWorkStatus_mg = cb_WINTER_WIPE_MODE;
  }
  else
  {
    rb_WipeWorkStatus_mg = cb_NORMAL_WIPE_MODE;
  } 
}


static byte IsByteOddParity(byte data)
{
  byte parity = FALSE;

  
  while (data != 0)
  {
    parity = !parity;
    data = 0;
  }
  return (!parity);
}


static void Rain_sensitivity(void)
{ 
  if(l_u8_rd_RainSnsrSnvtyForUsrSnvty0_CEM_LIN1() == 0)
  {
    rb_RLS_Sensitivity_Array_l[0] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[0] = l_u8_rd_RainSnsrSnvtyForUsrSnvty0_CEM_LIN1()*2;
  }


  if(l_u8_rd_RainSnsrSnvtyForUsrSnvty1_CEM_LIN1() == 0)
  {
    rb_RLS_Sensitivity_Array_l[1] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[1] = l_u8_rd_RainSnsrSnvtyForUsrSnvty1_CEM_LIN1()*2; 
  }


  if(l_u8_rd_RainSnsrSnvtyForUsrSnvty2_CEM_LIN1() == 0)
  {
    rb_RLS_Sensitivity_Array_l[2] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[2] = l_u8_rd_RainSnsrSnvtyForUsrSnvty2_CEM_LIN1()*2;
  }


  if(l_u8_rd_RainSnsrSnvtyForUsrSnvty3_CEM_LIN1() == 0)
  {
    rb_RLS_Sensitivity_Array_l[3] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[3] = l_u8_rd_RainSnsrSnvtyForUsrSnvty3_CEM_LIN1()*2; 
  }


  if(l_u8_rd_RainSnsrSnvtyForUsrSnvty4_CEM_LIN1() == 0)
  {
    rb_RLS_Sensitivity_Array_l[4] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[4] = l_u8_rd_RainSnsrSnvtyForUsrSnvty4_CEM_LIN1()*2;
  }


  if(l_u8_rd_RainSnsrSnvtyForUsrSnvty5_CEM_LIN1() == 0)
  {
    rb_RLS_Sensitivity_Array_l[5] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[5] = l_u8_rd_RainSnsrSnvtyForUsrSnvty5_CEM_LIN1()*2;
  }


  if(l_u8_rd_RainSnsrSnvtyForUsrSnvty6_CEM_LIN1() == 0)
  {
    rb_RLS_Sensitivity_Array_l[6] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[6] = l_u8_rd_RainSnsrSnvtyForUsrSnvty6_CEM_LIN1()*2;
  }      
  
  
  Rain_Sensitivity_Judge();
}


static void Get_Lin_Signal_From_GetLeWWS(void)
{  
  if(l_flg_tst_CemCem_Lin1Fr02_CEM_LIN1())
  {
    l_flg_clr_CemCem_Lin1Fr02_CEM_LIN1();
    rbi_ConnectedToMaster_g = 1;
    if(l_u8_rd_AmbTForVisy_CEM_LIN1() != 255)
    {
      rb_OutsideTemp_mg = l_u8_rd_AmbTForVisy_CEM_LIN1();
    }
    WipeWinterModeCheck();
  }
    
  
  if(l_flg_tst_CemCem_Lin1Fr03_CEM_LIN1())
  {
    l_flg_clr_CemCem_Lin1Fr03_CEM_LIN1();
    rbi_ConnectedToMaster_g = 1;
    l_bool_wr_RainSnsrErrCalErrActv_CEM_LIN1(1);     
    //Get_BCMVehType(l_u8_rd_VehTyp_CEM_LIN1());
    GetLightTransmission(l_u8_rd_WindCorrnValFrnt_CEM_LIN1(),l_u8_rd_WindCorrnValAmb_CEM_LIN1());
    Rain_sensitivity();
  }
  
  
  if(l_flg_tst_CemCem_Lin1Fr04_CEM_LIN1())
  {
    l_flg_clr_CemCem_Lin1Fr04_CEM_LIN1();
    rbi_ConnectedToMaster_g = 1;
    Set_BCMLightOffset(l_u8_rd_RainSnsrLiThd_CEM_LIN1());
  }
  
  
  if(l_flg_tst_CemCem_Lin1Fr05_CEM_LIN1())
  {
    l_flg_clr_CemCem_Lin1Fr05_CEM_LIN1();
    rbi_ConnectedToMaster_g = 1;
  }
  
  
  if(l_flg_tst_CemCem_Lin1Fr06_CEM_LIN1())
  { 
    l_flg_clr_CemCem_Lin1Fr06_CEM_LIN1();
    rbi_ConnectedToMaster_g = 1;
    rbi_RealParkContact_g = !(l_bool_rd_WiprInWipgAr_CEM_LIN1());        // wiper position
    
    
    if (l_bool_rd_WshngCycActv_CEM_LIN1() == 1)                                 /* Washpump activ? 0x5:Front washing*/
    {
      rbi_WashingActive_g = TRUE;                                       /* set Washing activ bit */
    }
    else if (rbi_ParkPosition_g == TRUE)                                /* In Parkposition ? */
    {
      rbi_WashingActive_g = FALSE;                                      /* Clear Washing active bit */
    }
    else{}                                                              /*Do nothing, Dummy-else for Misra Check*/


		if(l_bool_rd_WshngCycActv_CEM_LIN1() != 1)
		{
      Wiperspeed_for_wash = l_u8_rd_AutWinWipgCmd_CEM_LIN1();
      Wipermode_for_wash = l_u8_rd_WipgAutFrntMod_CEM_LIN1();		
		}
  }  
}


static void Light_Sensitivity_In_GetLeWWS(void)
{
  static const byte cab_PotistageMapping_mg[8] = {4,5,6,7,3,2,1,0}; /*mapping for potistages!*/  
  byte rb_Empfindlichkeit_LS_l;
  
  
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
    rb_AfterResetCounter_l++;
  }
  else{}
  
  
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


static void Wiper_and_Park(void)
{
  static byte rb_OutOffParkCounter_mg;
  
  
  if(l_bool_rd_RainSensActvn_CEM_LIN1() == 0)
  {
    rw_AfterRSWipeCounter_mg = 50000;
    rw_AfterWWSWipeCounter_mg = 50000;
    rw_WipeCommandTimOut_mg = 0;
  }
  else{}
  

  if(rbi_RealParkContact_g == FALSE)     
  {
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
}


static void Tunnel_Wipe_Decision(void)
{
  if((rw_AfterRSWipeCounterAlt_mg <= (((word)CB_TUNWISCHVERZ_MG)*100))
     &&(rb_speed_in_kmh_g > 29)
       &&(rbi_modi_lightsens_tunnel_g == TRUE)
         &&(rub_RSIntermDelayInit == 0xFF))
  {
    if ((rbi_modi_lightsens_tunnel_alt_mg == FALSE) && (rw_AfterRSWipeCounter_mg < (((word)CB_TUNWISCHAKTIV_MG)*100)))
    {
      rb_tunnelWipeActive_g = TRUE;
    }
  }
  else
  {
    rb_tunnelWipeActive_g = FALSE;
  }  
}

static void Exit_Wipe(void)
{
  if(rbi_RealParkContact_g == FALSE)
  {
  }
  else
  {
    if(rw_AfterWWSWipeCounter_mg > 3000)
    {
      if(l_u8_rd_WipgAutFrntMod_CEM_LIN1() > 0)
      {
        l_u8_wr_WipgAutFrntMod_CEM_LIN1(0);
      }
    }
    else if(rw_AfterWWSWipeCounter_mg > 500)
    {
      if(l_u8_rd_WipgAutFrntMod_CEM_LIN1() > 1)
      {
        l_u8_wr_WipgAutFrntMod_CEM_LIN1(1);
      }
    }
    else
    {
      if(l_u8_rd_WipgAutFrntMod_CEM_LIN1() > 2)
      {
        l_u8_wr_WipgAutFrntMod_CEM_LIN1(2);
      }
    }
  }
  
  
  if(rbi_AutomaticWipingMode_g == FALSE)
  {
    l_u8_wr_WipgAutFrntMod_CEM_LIN1(0);
  }
  l_u8_wr_AutWinWipgCmd_CEM_LIN1(0);
  
  
  if(rb_WipeWorkStatus_mg == cb_WINTER_WIPE_MODE)
  {
    l_u8_wr_AutWinWipgCmd_CEM_LIN1(0);
    l_u8_wr_WipgAutFrntMod_CEM_LIN1(0);
  }
}


static void Rain_Sensitivity_Judge(void)
{
  byte rb_Loop_Counter = 0;
  
  
  if((rb_RLS_Sensitivity_Array_l[0] < rb_RLS_Sensitivity_Array_l[1]) 
       && (rb_RLS_Sensitivity_Array_l[1] < rb_RLS_Sensitivity_Array_l[2]) 
         && (rb_RLS_Sensitivity_Array_l[2] < rb_RLS_Sensitivity_Array_l[3]) 
           && (rb_RLS_Sensitivity_Array_l[3] < rb_RLS_Sensitivity_Array_l[4])
             && (rb_RLS_Sensitivity_Array_l[4] < rb_RLS_Sensitivity_Array_l[5]) 
               && (rb_RLS_Sensitivity_Array_l[5] < rb_RLS_Sensitivity_Array_l[6]))
  {
    if((rb_RLS_Sensitivity_Array_l[0] != rab_RS_Sensitivity_g[0]) 
        || (rb_RLS_Sensitivity_Array_l[1] != rab_RS_Sensitivity_g[1]) 
          || (rb_RLS_Sensitivity_Array_l[2] != rab_RS_Sensitivity_g[2]) 
            || (rb_RLS_Sensitivity_Array_l[3] != rab_RS_Sensitivity_g[3]) 
              || (rb_RLS_Sensitivity_Array_l[4] != rab_RS_Sensitivity_g[4]))
    {
      if((rbi_EEPROMBytesWritten_g == TRUE) || (rbi_EEPROMBytesToWrite_g == FALSE))
      {
        for(rb_Loop_Counter = 0;rb_Loop_Counter < 5;rb_Loop_Counter++)
        {
          rab_EEPROM_Bytes_toWrite_g[rb_Loop_Counter] = rb_RLS_Sensitivity_Array_l[rb_Loop_Counter];
        }  
        rw_EEPROM_Address_to_Write_g = 597;
        rb_I2C_EEPROM_bytesToWrite_g = 5;         /*set number of bytes to 5*/
        rbi_EEPROMBytesToWrite_g = TRUE;    //set flag for bytes to write
        rbi_EEPROMBytesWritten_g = FALSE;   //clear bytes written (reset EEPROM bytes Written!)          
      }
      else{}
    }
    else{}

  
    if((rb_RLS_Sensitivity_Array_l[5] != rab_RS_Sensitivity_g[5]) 
       || (rb_RLS_Sensitivity_Array_l[6] != rab_RS_Sensitivity_g[6])) 
    {
      if((rbi_EEPROMBytesWritten_g == TRUE) || (rbi_EEPROMBytesToWrite_g == FALSE))
      {
        for(rb_Loop_Counter = 0;rb_Loop_Counter < 2;rb_Loop_Counter++)
        {
          rab_EEPROM_Bytes_toWrite_g[rb_Loop_Counter] = rb_RLS_Sensitivity_Array_l[rb_Loop_Counter + 5];
        }  
        rw_EEPROM_Address_to_Write_g = 602;
        rb_I2C_EEPROM_bytesToWrite_g = 2;         /*set number of bytes to 4*/
        rbi_EEPROMBytesToWrite_g = TRUE;    //set flag for bytes to write
        rbi_EEPROMBytesWritten_g = FALSE;   //clear bytes written (reset EEPROM bytes Written!)      
      }
      else{}
    }
    else{}
  }
  else{}
}


static void Standby_Judge(void)
{
#ifdef CS_STANDBY 
  if (l_bool_rd_EnaOfflineMonitor_CEM_LIN1() == 1)
  {
    if (rb_Verglasun_offenDebounce_mg < 0xff)
    {
      rb_Verglasun_offenDebounce_mg ++;
    }
    rb_Verglasun_ClosedDebounce_mg = 0;
  }
  else if(l_bool_rd_EnaOfflineMonitor_CEM_LIN1() == 0)
  {
    rw_StandbyTimeOutCnt_g = 0;
    if (rb_Verglasun_ClosedDebounce_mg < 0xff)
    {
      rb_Verglasun_ClosedDebounce_mg ++;
    }
    rb_Verglasun_offenDebounce_mg = 0;
  }
  else{}
#endif
}


static void OutdBriCntr_Counter(void)
{
  //static byte rb_OutdBri_Cnt_l = 1;

  l_u8_wr_OutdBriCntr_CEM_LIN1(rb_OutdBri_Cnt_l);
  if(rb_OutdBri_Cnt_l < 14)
  {
    rb_OutdBri_Cnt_l ++;
  }
  else
  {
    rb_OutdBri_Cnt_l = 0;
  }
}


static byte CRC8SAEJ1850_00(const byte * u8_data,byte u8_len)
{
  byte i, j;
  byte u8_crc8;
  byte u8_poly;

  u8_crc8 = 0x00;
  u8_poly = 0x1D;

  for (i = 0; i < u8_len; i++)
  {
    u8_crc8 ^= u8_data[i];

    
    for (j = 0; j < 8; j++)
    {
      if ((u8_crc8 & 0x80) > 0)
      {
        u8_crc8 = (u8_crc8 << 1) ^ u8_poly;
      }
      else
      {
        u8_crc8 <<= 1;
      }
    }
  }
  u8_crc8 ^= (byte)0x00;
  return u8_crc8;
}