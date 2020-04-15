/* PRQA S 0759 EOF */ /* << union is sopported by this compiler>>*/
/* PRQA S 3138 EOF */ /* << using of macros from automatic generated code >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 5540,5560,5565,5900 EOF *//*<< Data needs to be verified  >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/*****************************************************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : RLS_LINST.c

Documentation reference   : Software Requrement Specification
Overview of the component : interface to the electronics

Evolution of the component : see PVCS Version control system

Initials   date   modification
*****************************************************************************************************************/

/****************************************************************************************************************/
/****************************************************************************************************************/
/* Date      VDR_Number  Name   Description                                                                     */
/****************************************************************************************************************/
/* 27.06.11  VDR_671     AL      remove singularity for light on signals                                        */
/* 10.03.11  VDR_638     AL      MISRA OPTIMISATION with corrections in Source code                             */
/* 15.11.10  VCO_093     AL      VCO_095 use compensated humidity and temperatur                                */
/* 15.11.10  VCO_093     AL      implement Veto Function into interface file                                    */
/* 15.11.10  VCO_083     AL      ignore ignition off if speed is higher 4km/h                                   */
/* 22.07.10  VDR_526     AL      clear standby Signals at sleep command                                         */
/* 16.07.10  VCO_061     AL      name has of interface variable has changed                                     */
/* 26.05.10  VCO_050     AL      switch light on for one cylce after watchdog reset                             */
/* 26.05.10  VCO_055     AL      reomve debouncing of RAM and ROM error                                         */
/* 26.05.10  VDR_526     AL      Wake bus for sleep without closing window                                      */
/* 29.04.10  VDR_517     AL      maximum wake time of 60sec                                                     */
/* 29.04.10  VDR_507     AL      block diagnostics on corrupt response                                          */
/* 18.03.10  VDR469      AL      set for error                                                                  */
/* 02.03.10  VCO_028     AL      Adaptations for standby mode                                                   */
/* 24.02.10  VCO_031     AL      use for sleep the EEPROM idle time,actvate Standby mode                        */
/* 22.01.10  VCO_27      AL      rainlight switch of time independend from potistage                            */
/* 14.01.10  VCO_026     AL      block switching light of for any error                                         */
/* 12.01.10  VDR_408     AL      use 0 as init value for rain sensor sensitivity                                */
/* 12.01.10  VCO_24      AL      new Interval time for Konzersensor rain sensor inactive                        */
/* 23.01.08  VDR_124     AL      set rain intensity to init if rain sensor is off                               */
/* 01.02.08  VDR_129     AL      use standard algorithm for undervoltage interval                               */
/* 29.02.08  VDR_154     AL      VDR_154 change of max value from 1022 to 1000                                  */
/* 10.03.08  VDR_157     AL      Dewpoint not set correct                                                       */
/* 26.06.08  VCO_08      AL	 Add FAW Twilight detection                                                     */
/* 23.10.09  VDR_388     AL      Response Error on No Response for VW_Konzernsensor                             */
/****************************************************************************************************************/
/*29.07.2014 VDR_737    NB      In case of negative temperature the sensor sends wrong value                    */
/*11.10.2013 VDR_749    NB      Response Error for Diagnostic ID                                                */
/*04.02.2014 VCO_111    NB      SM138:Saftey:Frequency detection function                                       */
/*15.09.2014 VCO_184    NB      Checksum for calibration data                                                   */
/*17.09.2014 VCO_184    NB      Checksum for calibration data (removed calib error from rain sensor error)      */
/*22.09.2014 VCO_152    NB      Customenr part number shall be stored in EEPROM                                 */
/*24.09.2014 VCO_152    NB      LIN Conformance Test                                                            */
/*29.09.2014 VCO_172    NB      AUDI_Coding of Parkposition on LIN                                              */
/*29.09.2014 VCO_154    MP      Safety:SM139,SM140:Implement RS_Error_Aktiv,LS_Error_Aktiv flag to check after  */
/********************************Reset if an error was active before the sensor goes to sleep or reset          */
/*16.10.2014 VCO_172    NB      AUDI_Coding of Parkposition on LIN                                              */
/*18.11.2014 VDR_824    MP      Error counter for too long init of ASIC                                         */
/*19.11.2014 VCO_195    NB      QAC warning                                                                     */
/*09.02.2015 VCO_220    MP      VIrefLo/Hi monitoring                                                           */
/*11.02.2015 VCO_219    NB      Unused LIN-Bits should be recessiv (1),for solar frame.                         */
/*24.02.2015 VDR_850    NB      After removing HT module from sensor,                                           */
/********************************the HT error displayed after 40s in the LIN Bus                                */
/*25.02.2015 VDR_852    MP      Error bit of ASIC VDDx failure not stored to EEPROM                             */
/*25.02.2015 VCO_224    MP      RS_Error should be set only by RAM/ROM error,                                   */
/********************************when RS function is coded as inactive in kodierbyte0                           */
/*25.02.2015 VCO_225    MP      RS functionality detection - error when not available                           */
/*03.03.2015 VCO_227    NB      Implement RAM Guard function                                                    */
/*18.03.2015 VDR_857    MP      Phantom wipes with the no RS variants                                           */
/*24.03.2015 VDR_859    MP      Interval wipe in manual mode for no rain variant                                */
/*09.04.2015 VCO_241    NB      Implement test function for RAM Guard with one dedicated cell                   */
/*10.04.2015 VCO_241    NB      Implement test function for RAM Guard with one dedicated cell                   */
/*04.05.2015 VDR_871    NB      Safety: all reset sources from RESF should be used,                             */
/********************************except the voltage detector flag                                               */
/*12.05.2015 VDR_878    NB      ADC Error shall be removed from the LS error and included only for RS_error     */
/*13.05.2015 VCO_192    NB      Audi: Activation and deactivation of Interval Operation                         */
/*09.06.2015 VCO_192    NB      Audi: Activation and deactivation of Interval Operation                         */
/*09.06.2015 VDR_868    NB      All:QAC and Polyspace fixing for SW009 Release                                  */
/*10.06.2015 VCO_254    NB      Checking of CRC over light area shall be done cyclically                        */
/*13.07.2015 VCO_260    MP      Tunnel wipe activation and delay according to                                   */
/********************************Tunnel Verzoegerung and Aktivierung parameters                                 */
/*21.09.2015 VDR_909    NB      Fixed interval operation not started after lapsing the ignition delay           */ 
/*                                and activating again                                                          */
/*02.10.2015 VDR_911    SP      HammingErr shld be part of RS_Error/LS_Error and shld not be used for Active Err*/
/*07.10.2015 VCO_278    NB      Solar shadow correction                                                         */
/*08.10.2015 VCO_278    NB      Solar shadow correction                                                         */
/*16.11.2015 VDR_926    SP      Add Compulsary wipe when RS is deaktivated(via LIN Deaktivierung_RS             */
/*                              and Fixed Interval continuous wiping should be active when KL15=0 and speed>4kmh*/
/*25.02.16    VCO_313   NB      Create new variant Feuchte_Solar and Rain_Light_solar for SEAT            */ 
/*24.03.16    VCO_320   NB      LIN response shall not be sent untill EEPROM is loaded                         */ 
/****************************************************************************************************************/
/*                   Common and module include-file                                                             */
/****************************************************************************************************************/


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
#include "G5_utilities.h" 

#include "G5_IRlight.h"
#include "G5_DippedBeam_sr.h"
#include "G5_ASIC_Control.h"
#include "G5_ASIC_Control_sr.h"
/** /brief Declarations of modul specific parameters and variables*/
#include "G5_spi_sr.h"

#include "G5_AsicFramesLin.h"

#ifdef SENSIRION_SHT21_USED
#define cw_DEWPOINT_MAX_mg    (1000)     /*VDR_154 change of max value from 1022 to 1000*/
#else
#define cw_DEWPOINT_MAX_mg    (1000+CW_DEWPOINT_OFFSETT_mg)     /*VDR_154 change of max value from 1022 to 1000*/
#endif

#define cb_ONLY_HUMIDITY    0x98
#define cb_HUMIDITY_SOLAR   0x8A

#define cw_TEMPSCHEIBE_MAX_mg (1000+CW_TEMPERATURE_OFFSETT_mg)  /*VDR_154 change of max value from 1022 to 1000*/
#define CW_TEMPERATURE_OFFSETT_mg 4 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define CW_DEWPOINT_OFFSETT_mg 4 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define CW_DEWPOINT_MIN_mg 1 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define CW_TEMPERATURE_MIN_mg 1 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define cb_TEMPSENSOR_MAX_mg 254

/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/
static byte rb_IgnitionOndelay_mg;
/* PRQA S 3218 7 */ /* <<needed at this level for better debugging>> */
static byte rb_Verglasun_offenDebounce_mg,rb_Verglasun_ClosedDebounce_mg;

static word rw_AfterRSWipeCounter_mg;                   /* Time after last wipe from RS*/
static word rw_AfterRSWipeCounterAlt_mg;                /* Time to the last wipe from RS*/
static word rw_AfterWWSWipeCounter_mg;                  /* Time after last wipe from WWS*/
//static word rw_CommandCloseWindowTimout_mg;
static word rw_WipeCommandTimOut_mg;                     /*timout for requested wipe*/


/* PRQA S 3218 7 */ /* <<needed at this level for better debugging>> */
static const byte cab_AUDI_SenMapping[16] = {0,0,0,2,2,2,2,3,3,3,4,4,5,5,5,3};
/* PRQA S 3218 7 */ /* <<needed at this level for better debugging>> */
static const byte cab_PotistageMapping_mg[8] = {4,5,6,7,3,2,1,0}; /*mapping for potistages!*/


//static const word caw_DeppressedParkDelayTable_g[4] = {500,1000,1500,2000};

#define cb_VERGLSUNG_CLOSE_DELAY_mg 100
#define cb_VERGLSUNG_OPEN_DELAY_mg 100
#define cb_FOUR_SECOND_DELAY_mg   25
#define cw_CLEARWIPE_DELAY_s 400 /* 4 seconds (400*10ms)*/
#define cb_DEPRESSED_PARK_DEBOUNCE_s 18



//static byte rb_AnyErrorCounterDebounce_mg;

/******************************************************************************/
/*                      Definition of exported variables                      */
/******************************************************************************/


/*************************************************************************
**                   Declaration of local module Functions              **
*************************************************************************/

#define CB_BRIGHTNESS_MAX_VALUE_s 7   /*Max Value for Helligkeit*/
#define cb_BRIGHTNESSSCALING_FAKT_s 3 /*Scaling fakt x  2^x*/

//static void LIN_CalculateFixIntervalTime(void);
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
void GetLeWWS(void) /*Information from SCS*/
{
  static word rw_IgnitionOffDelay_mg;
  static byte rb_IntervalOnOndelay_mg;
  byte rb_PotiStageFromBoxTemp_l,rb_Empfindlichkeit_LS_l;
  static byte rb_AfterResetCounter_l;
  static unsigned char rbi_Klemme_15_g;
  static byte rb_delay_g; 
  static byte rain_sensor_sensitivity_g;

//  if (l_bool_rd_Verglasung_offen()==TRUE)
//  {
//    if (rbi_Ignition_g == FALSE) /* VCO_028*/
//    {
//      if (rb_Verglasun_offenDebounce_mg < 0xff)
//      {
//        rb_Verglasun_offenDebounce_mg ++;
//      }
//    }
//    rb_Verglasun_ClosedDebounce_mg = 0;
//  }
//  else
//  {
//    if (rb_Verglasun_ClosedDebounce_mg < 0xff)
//    {
//      rb_Verglasun_ClosedDebounce_mg ++;
//    }
//    rb_Verglasun_offenDebounce_mg = 0;
//  } 

  if(l_flg_tst_FBCM_ControlCommand())               /*Master Request?*/
  {
    l_flg_clr_FBCM_ControlCommand();                 /*loesche flag*/
    rbi_LightSensitivityRecieved_g = TRUE; 
//    if(rbi_SignalQuelleWischerParklage_g == TRUE)
//    {
//      /* Park position information comes from BCM message */
    if(l_u8_rd_BCM_WprPkSwSts() == 0)
        rbi_RealParkContact_g = 1;
    else if(l_u8_rd_BCM_WprPkSwSts() == 1)
        rbi_RealParkContact_g = 0;   
//      rbi_RealParkContact_g = l_bool_rd_BCM_Wischer_Parklage();
//    }
      
    if(l_bool_rd_BCM_WndShldWashSwSts() == TRUE)   /* Waschpumpe aktiv?*/
    {
      rbi_WashingActive_g = TRUE;             /* Washing aktiv bit setzen*/
    }
    else
    {
      if(rbi_ParkPosition_g == TRUE)          /* In Parkposition ?*/
      {
        rbi_WashingActive_g = FALSE;              /* Clear Washing aktive bit*/
      }
    }
//    if(l_u8_rd_Deaktivierung_RS() > FALSE)
//    {
//      rbi_LINRainsensorDisabled_g = TRUE;
//    }
//    else
//    {
      rbi_LINRainsensorDisabled_g = FALSE;
//    }
        
    if(l_u8_rd_FBCM_IGN_State() > 0)
    {
      if(rb_delay_g <= 5)
      {
    	  rb_delay_g++;
      }
      else
      {
    	  rbi_Klemme_15_g = TRUE;
      }
    }
    else
    {
    	rb_delay_g = 0;
    	rbi_Klemme_15_g = FALSE;
     }
    
    
    /* ignore ignition off if speed higher 4km/h*/
    if((rbi_Klemme_15_g == TRUE)||(rb_speed_in_kmh_g > cb_IGNORE_IGNITION_SPEED)) /*VCO_083*/
    {
      rbi_Ignition_g = TRUE;
      rw_StandbyTimeOutCnt_g = 0;
      rbi_WindowOpenIgnitionWasOn_g = TRUE;   /*store window state at ignition on to off!*/
      rw_IgnitionOffDelay_mg = 0;
      if(rb_IgnitionOndelay_mg < 250)
      {
        rb_IgnitionOndelay_mg++;
      }
      
      if(((rbi_RainsensorDisabled_g == FALSE) && (rbi_LINRainsensorDisabled_g == FALSE))&&(rb_AfterResetCounter_l> 10))
      {         
        if((l_u8_rd_BCM_WiperSts() == TRUE)
               || (rbi_RainsensorAlwaysOn_g != FALSE))
        {
          rbi_AutomaticWipingMode_g = TRUE;           /*Rainsensor always active!*/
          l_u8_wr_RS_RSensSts(1);
        }
        else
        {
          rbi_AutomaticWipingMode_g = FALSE;           /*Rainsensor off!*/
          l_u8_wr_RS_RSensSts(0);
        }
      }
      else
      {
        rbi_AutomaticWipingMode_g = FALSE;           //Rainsensor off!
        l_u8_wr_RS_RSensSts(0);
      }
      
      
      if(l_u8_rd_BCM_WiperSts()== TRUE) // copy automatic wiping mode
      {
        if(rb_IntervalOnOndelay_mg > 15)   //150ms Delay fuer Potiinkrementierungsblocking!
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
      rw_AfterWWSWipeCounter_mg = 50000;          //Direktbitdelay bei Kl15 Aus hochsetzen!
      rw_WipeCommandTimOut_mg = 0;
      rb_IgnitionOndelay_mg = 0;
      rbi_AutomaticWipingMode_g = FALSE;           //Rainsensor off!
    }
    
    if(l_u8_rd_FBCM_VehSpdLgt() < 255)/*Check for max value   speed faster than 200 (255km/h) */
    {
      rb_speed_in_kmh_g = l_u8_rd_FBCM_VehSpdLgt(); /*recalibrate Data multily by 2,56*/
    }
    else
    {
      if(l_u8_rd_FBCM_VehSpdLgt() == 255)
      {
        rb_speed_in_kmh_g = 75;                           /* set speed to (75 km/h)*/
      }
    }
    
    if(l_u8_rd_FBCM_VehSpdLgt() != 255)
    {
      if(rb_speed_in_kmh_g>=10)
      {
        rbi_speedWasAbove10kmh_g = TRUE;
      }
    }
 
    rain_sensor_sensitivity_g = l_u8_rd_BCM_RSensSenstvtySts();
    
    
    if (rain_sensor_sensitivity_g <= 4)/*VDR_408 do not update if init*/
    {
      rb_PotiStageFromBoxTemp_l = cab_AUDI_SenMapping[rain_sensor_sensitivity_g*3 + 1];
      if(rb_PotiStageFromBoxTemp_l>7)
      {
        rb_PotiStageFromBox_g = 7;
      }
      else
      {
        rb_PotiStageFromBox_g = rb_PotiStageFromBoxTemp_l ;
      }
    }
    else if(rain_sensor_sensitivity_g == 5)
    {
        rb_PotiStageFromBox_g = 3 ;
    }
      
    rb_LIN_SensitivityShift_g =  9;       //adaptation Variable for sensitivity factor
#ifndef AUDI_B8
    error "__Error_ AUDI_B8 have to be defined for this feature"
#endif
      // Datas to switch off the sensor
      
      rbi_ConnectedToMaster_g = TRUE;            // set connected to Master Bit
  }
  else  //keine neue Master Nachricht!
  {    // check if system is on -> to switch off
    
    if((rw_NoCommunicationCounter_g > CW_LIN_E2_IDLE_TIMOUT))
    {     
//      if ((rbi_Command_CloseWindows_g == FALSE)||( rbi_ASICStandByModeRequest_g == FALSE))  /*VDR_526*/
//      {
//        if ( ((rbi_Ignition_g== FALSE)) &&((rb_Verglasun_offenDebounce_mg > cb_VERGLSUNG_OPEN_DELAY_mg) &&
//                                           (rbi_StandbyFunction_enabled_g == TRUE)) && (rbi_Command_CloseWindows_g == FALSE) )
//        {
//          rbi_ASICStandByModeRequest_g = 1;   // Set Request for Standby Mode
//        }
//        else
//        {
//          rbi_ASICStandByModeRequest_g = 0;
//        }
//        
        rbi_GotoSleep_g = TRUE;         // Was Connected to Master
//      }
//      else 
//      {
//        if ((l_bool_rd_Verglasung_offen()==FALSE)||(rw_CommandCloseWindowTimout_mg > 6000))
//        {
//          rbi_GotoSleep_g = TRUE;         // no need of Standby mode 
//          rbi_ASICStandByModeRequest_g = 0;
//          rbi_SendWakeUpFrame_g = FALSE;  /*VDR_526*/
//          rbi_Command_CloseWindows_g = FALSE; /*VDR_526*/
//          rb_WakeupCounter_mg = 0; 
//        }
//        else
//        {
//          if (rb_WakeupCounter_mg == FALSE) /*VDR_526*/
//          { 
//            rbi_SendWakeUpFrame_g = TRUE; 
//          }
//        }
//      }
      rbi_ConnectedToMaster_g = FALSE;         // clear connected to Master
    }
    else
    {
      rbi_SendWakeUpFrame_g = FALSE;  /*VDR_526*/
      rw_NoCommunicationCounter_g ++;
      rbi_GotoSleep_g = FALSE;         // Was Connected to Master
      if(rw_NoCommunicationCounter_g >= (CW_LIN_E2_IDLE_TIMOUT - 3) )
      {
        /* clear marker in the EEPROM to indicate there is a normal sleeep command*/
        rb_Release_IntervalMarker_Update_g = 0x00;
        rbi_Write_ReleaseMarker_g = TRUE;
      }
    }
  }
  
  /* rb_LSPotiStage_g = cab_PotistageMapping_mg[((rb_FunctionBits_g&0x38)>>3)];  // set LSS to 3 */
//  if (l_u8_rd_Empfindlichkeit_LS()>6)
//  {
//    rb_Empfindlichkeit_LS_l = 6;
//  }
//  else
//  {
    rb_Empfindlichkeit_LS_l = 3;
//  }
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
    rb_AfterResetCounter_l++; /* counts calls of routine to delay activation of rainsensor*/
  }
  
   if(rw_IgnitionOffDelay_mg < 1000) /* 10sec delay */
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
  
//  if(rbi_SignalQuelleWischerParklage_g == FALSE)
//  {
//    /* Park position information comes from wiper message */
  if(l_u8_rd_BCM_WprPkSwSts() == 0)
    rb_Wischer_Parklage_l = 1;
  else if(l_u8_rd_BCM_WprPkSwSts() == 1)
    rb_Wischer_Parklage_l = 0; 
//    rb_Wischer_Parklage_l = l_bool_rd_Wischer_Parklage();
//  }
//  else
//  {
//    /* Park position information comes from BCM message */
//    rb_Wischer_Parklage_l = l_bool_rd_BCM_Wischer_Parklage();
//  }
//  
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
  
  if(((l_u8_rd_BCM_WiperSts() != TRUE)
          && (rb_Wischer_Parklage_l == TRUE))
     ||(rw_WipeCommandTimOut_mg > cw_CLEARWIPE_DELAY_s))
  {
    if((rb_WiperSpeed_g > 0)||(rbi_ParkPosition_g == FALSE))
    {
      if(rb_parkpositioncounter_s>10)            // Parkpositioncounter groesser 10
      {
        rbi_ParkPosition_g = FALSE;                 // loesche bit fuer Parkposition
      }
      rb_parkpositioncounter_s++;             // inkrementiere Parkpositionscounter
    }
    
    if(rb_parkpositioncounter_s > (cab_WiperMotorRunntime_mg[rb_WiperSpeed_g]))
    {
      rw_WipeCommandTimOut_mg = 0;
      rbi_ParkPosition_g = TRUE;               // loesche bit fuer Parkposition
      rb_parkpositioncounter_s = 0;            //
    }
  }
  else
      
  {
//    if((l_bool_rd_Wischer_aktiv() == FALSE)&&(rb_WiperSpeed_g > 0))
//    {
//      rbi_WiperStarted_g = TRUE;
//    }
    
    if(rb_Wischer_Parklage_l == TRUE)        // In Parklagensignal ?
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
      rbi_ParkPosition_g = TRUE;                     // Parkposition True
      if (rub_IntermDelayTime > 5)       // clear option for Wiper Started Flag!
      {
        rbi_WiperStarted_g = FALSE;
      }
    }
    else
    {
      rb_LimitMemomryNoWiperReaction_g = FALSE;
      rbi_WiperStarted_g = FALSE;
      rw_WipeCommandTimOut_mg = 0;                // reset Timout if wiper motor wants not wipe
      if(rb_parkpositioncounter_s>7)            // Parkpositioncounter groesser 8
      {
        rbi_ParkPosition_g = FALSE;                 // loesche bit fuer Parkposition
      }
      else
      {
        rb_parkpositioncounter_s++;             // inkrementiere Parkpositionscounter
      }
    }
  }
  
//  if(rbi_SignalQuelleWischerParklage_g == FALSE)
//  {
//    /* Wiper turning position information comes from wiper message */
//    rbi_WischerWendelage_g = l_bool_rd_Wischer_Wendelage(); 
//  }
//  else
//  {
//    /* Wiper turning position information comes from BCM message */
//    rbi_WischerWendelage_g = l_bool_rd_BCM_Wischer_Wendelage();
//  }
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
//  static word rw_Temperature_Sensor_g;
//  static word rw_Temperature_Scheibe_g;
  static byte rb_OutOffParkCounter_mg;
  static byte rb_RLS_Botschaft_s;
  static byte rb_underVoltageTimer_s;
  static byte rb_TunnelWipeTimeOut_mg;
//  static byte rb_InitLightValCnt_l=100;
  static byte rb_tunnelWipeActive_g;
 
//  word rw_Hellighkeitsthrs; /*VCO_103 local variable for brightness boost*/
//  word rw_IrLightforSOSE_Corr1_l;
//  word rw_IrLightforSOSE_Corr2_l;
//  word rw_SoSe_SunInt_2D_Le_l;
//  word rw_SoSe_SunInt_2D_Re_l;
  /*VCO_260 Tunnel wipe activation and delay according to Tunnel Verzoegerung and Aktivierung parameters*/
  word rw_tunnelWischVerzoegerung_l=(((word)CB_TUNWISCHVERZ_MG)*100);
  word rw_tunnelWischAktivierung_l=(((word)CB_TUNWISCHAKTIV_MG)*100);

//  byte rb_AnyErrorCounterDebounce_l; 
//  byte rb_TempLightOn_l;
//  byte rb_TempLightOnInv_l;
//  byte rb_Helligkeitsboost_l; /*VCO_103 local variable for brightness boost*/ 

  
#ifndef SENSIRION_SHT21_USED
  word rw_SensorTemp_l;
#endif
  word newWiperSpeedLin =0;
  word rain_sensor_status_flag;
  
  Check_StartupActiveErrors();
  
//  LIN_CalculateFixIntervalTime();
  
  if((rb_IgnitionOndelay_mg<50)/*||(rbi_ConnectedToMaster_g = 0)*/)
  {
    rw_rain_intensitiy_g = 0;
    rw_AfterRSWipeCounter_mg = 50000;
  }
  if(rbi_RealParkContact_g == FALSE)     //Auserhalb vom Parkkontakt
  {
    if (rb_OutOffParkCounter_mg > cb_DEPRESSED_PARK_DEBOUNCE_s) //debounce the parkposition for depressed park
    {
      rw_AfterWWSWipeCounter_mg = 0;      //Direktbit (depressed park) zuruecksetzen
    }
    else
    {
      rb_OutOffParkCounter_mg ++;
    }
  }
  else
  {
    rb_OutOffParkCounter_mg = 0;
    if(rw_AfterWWSWipeCounter_mg < 50000) //Delay fuer Direktbit (depressed park) hochzaehlen
    {
      rw_AfterWWSWipeCounter_mg++;
    }
  }
  
  if(rw_AfterRSWipeCounter_mg < 50000)  //Delay fuer Tunnelwischung hochzaehlen
  {
    rw_AfterRSWipeCounter_mg++;
  }
  
  
  if(l_flg_tst_RS())                            // pruefen ob eigene Nachricht korrekt empfangen wurde
  {
    l_flg_clr_RS() ;                          // loeschen des Pruefflags
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
    rb_RLS_Botschaft_s++;                          // Incrementierung des Botschaftszaeheler
    
    rbi_oneTimeAnswerd_g = TRUE;
//    Diagnose_ReadMem_Send();                       // Send response on Read Memory
  }
//  if (l_flg_tst_SoSes_01() )
//  {
//    
//    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
//    l_flg_clr_SoSes_01();
//  } 
//  
//  
//  l_u8_wr_RLS_Zaehler(rb_RLS_Botschaft_s); // Botschaftszaehler uebergeben
  
  /*VCO_260 Tunnel wipe activation and delay according to Tunnel Verzoegerung and Aktivierung parameters*/
  /*activation of afterwipe at tunnel*/
  if((rw_AfterRSWipeCounterAlt_mg <= rw_tunnelWischVerzoegerung_l)
     &&(rb_speed_in_kmh_g > 30)
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
    
    /*Wischergeschwindigkeit uebergeben*/
    l_u8_wr_RS_WprSpdRqst(1);
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
    
    /*Wischergeschwindigkeit uebergeben*/
    l_u8_wr_RS_WprSpdRqst(1);
  }
  else
  {
    if(l_u8_rd_BCM_WiperSts() == TRUE)
    {      
      if(rb_WiperSpeed_g!=0)
      {
        if ((rbi_RSWipeSlowDmd==0)&&(rbi_RSWipeFastDmd==0))
        {
           newWiperSpeedLin = 1; //interval
        }
        else if (wiperSpeed7to2(l_u8_rd_RS_WprSpdRqst(), rb_WiperSpeed_g, rb_wiperSpeedHysteresis) != 0)
        {
          newWiperSpeedLin = wiperSpeed7to2(l_u8_rd_RS_WprSpdRqst(), rb_WiperSpeed_g, rb_wiperSpeedHysteresis);  //continuous mode
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
    l_u8_wr_RS_WprSpdRqst(newWiperSpeedLin);   // Wischergeschwindigkeit uebergeben 
    
    /*VCO_166 wiper speed limited to 1, when interval is not selected*/
//    if(rb_WiperSpeed_g > 1)
//    {
//      l_u8_wr_RS_Wischergeschwindigkeit(1);   // Wischergeschwindigkeit uebergeben
//      l_bool_wr_RS_Schwall(0);            // Schwall bit setzen
//    }
//    else
//    {
//      l_u8_wr_RS_Wischergeschwindigkeit(rb_WiperSpeed_g);   // Wischergeschwindigkeit uebergeben
      /*VDR_859 Interval wipe in manual mode for no rain variant*/
      /*is RS functionality enabled?*/
#ifndef _NO_RAIN_
      l_bool_wr_RS_WndShldWashSwStsRsp(rbi_RSWipeFastDmd);            // Schwall bit setzen
#else
      l_bool_wr_RS_WndShldWashSwStsRsp(0);            // Schwall bit setzen
#endif/*_NO_RAIN_*/
//    }
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
  /*VCO_224 RS_Error should be set only by RAM/ROM error, when RS function is coded as inactive in kodierbyte0*/
  
#ifndef _NO_RAIN_
  if((TRUE==rbi_RainSensor_enabled_g) && (FALSE==rbi_RainsensorDisabled_g))
  {
    /* VCO132: SM210 - ASIC Frequency Check (done at startup) - LS,RS_Failure */
    /* VCO 140: SM150 - ADC test */
    /* setze Lichtsensor RS-Fehler nach SRS */
    /*SM240*/
//    l_bool_wr_RS_Error((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_RainS_Error1_g != 0) ||(rbi_HammingError_g != 0));
    rain_sensor_status_flag =  (rb_RS_LS_Error1_g | rb_RS_LS_Error2_g | rb_RainS_Error1_g | rbi_HammingError_g);
    if(rain_sensor_status_flag > 0)
    {
      l_u8_wr_RS_RSensSts(2);
    }
    else
    {
    
    }    
  }
//  else
//  {
//    /*only RAM/ROM error and RS version error*/
//    l_bool_wr_RS_Error(((rb_RS_LS_Error1_g&0x3) != 0)||(TRUE==bi_RS_VariantError_g)||(rbi_HammingError_g != 0));
//  }
  
#else
  /*only RAM/ROM error and RS version error*/
//  l_bool_wr_RS_Error(((rb_RS_LS_Error1_g&0x3) != 0)||(TRUE==bi_RS_VariantError_g)||(rbi_HammingError_g != 0));
#endif /*_NO_RAIN_*/
  
  /* setze Lichtsensor Fehler nach SRS*/
  /* VDR 757 - SM200 */
  /*SM240*/
//  l_bool_wr_LS_Error((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(rbi_HammingError_g != 0)||(rbi_CRC_ChangedByDiagnostic_g));
  
  /* PRQA S 3415, 4112 1 */ /* << Getter functions must not have side effects >>*/
//  if ((((((IS_LS_ANY_ERRORCOUNTER()) > 0))||((l_bool_rd_LS_Error()) > 0))||(((rbi_UnderVoltage_g) == TRUE))
//       || ((rbi_OverVoltage_g) == TRUE)))
//  {
//    rb_AnyErrorCounterDebounce_mg = 250;
//  }
//  else
//  {
//    if (rb_AnyErrorCounterDebounce_mg > 0)
//    {
//      rb_AnyErrorCounterDebounce_mg -- ;
//    }
//  }
//  
//  l_bool_wr_RS_AdaptierungError(0); //Error in EEPROM
//  // End of Generate Initialwipe Switching the Rainsensore on
//  
//  l_bool_wr_RS_Regenfahrlicht(rbi_modi_lightsens_rain_g); /*copy data for rainlight */
//  l_bool_wr_LS_Autobahnfahrlicht(rbi_FastHighwayMode_g);   /*copy data for highwaylight*/
  
//  rb_AnyErrorCounterDebounce_l = rb_AnyErrorCounterDebounce_mg; 
  
//  if(l_bool_rd_LS_Error() == TRUE)
//  {
//    rb_TempLightOn_l = 1;
//  }
//  /*VCO_50*//*VDR_129 use Sensitivity Treatment*/
//  else if(((uF_modi_lightsens_g.AllBit & 0x2F)>0)||(rbi_InternalResetOccured_g > 0)||(rbi_Regulation48LightOnFlag_g !=0))
//  {
//    rb_TempLightOn_l = TRUE;
//    l_bool_wr_LS_Dunkel(TRUE);             // set bit for darkness
//  }
//  /*VDR_129 use Sensitivity Treatment*/
//  else if((((rbi_Freewaylight_enabled_g==TRUE))&& (rbi_FastHighwayMode_g == TRUE))
//          ||(((rbi_modi_lightsens_rain_g == TRUE)&& (rbi_RainLight_enabled_g == TRUE))))
//  {
//    rb_TempLightOn_l = TRUE;
//    l_bool_wr_LS_Dunkel(FALSE);                                                 // clear bit for darkness
//  }
//  else
//  { /* PRQA S 3415 1 */ /* << Swapping expressions not feasible for performance >>*/
//    if ((rb_AnyErrorCounterDebounce_l ==0)&&(get_rb_LightVetoCounter_g()==0)) /*VCO_093 use Veto of Lightsensor*/
//    {
//      rb_TempLightOn_l = FALSE;
//    }
//    else
//    {
//      rb_TempLightOn_l = l_bool_rd_LS_Licht_ein() ; /* stay in old light mode and do */
//    }
//    l_bool_wr_LS_Dunkel(FALSE);                                                  // clear bit for darkness
//  }
//  
//  
//  /*VDR_671 remove singularity*/
//  if(l_bool_rd_LS_Error() != FALSE)
//  {
//    rb_TempLightOnInv_l = FALSE;
//  }
//  /*VCO_50*//*VDR_129 use Sensitivity Treatment*/
//  else if(((uF_modi_lightsens_inv_g.AllBit & 0x2F)< 0x2F)
//          ||(rbi_InternalResetOccured_g != 0)
//            ||(rbi_Regulation48LightOnFlag_g >0))
//  {
//    rb_TempLightOnInv_l = FALSE;                                                  // set bit for darkness
//  }
//  /*VDR_129 use Sensitivity Treatment*/
//  else if((((rbi_Freewaylight_enabled_g != FALSE)) && (rbi_FastHighwayMode_g != FALSE))
//          ||(((rbi_modi_lightsens_rain_inv_g == FALSE)&& (rbi_RainLight_enabled_g != FALSE))))
//  {
//    rb_TempLightOnInv_l = FALSE;
//  }
//  else
//  {     /*VCO_093 use Veto of Lightsensor*/
//    /* PRQA S 3415 1 */ /* << Swapping expressions not feasible for performance >>*/
//    if ((rb_AnyErrorCounterDebounce_l  != FALSE)||(get_rb_LightVetoCounter_g() != FALSE)) 
//    {
//      rb_TempLightOnInv_l = l_bool_rd_LS_Licht_ein_invers() ; /* stay in old light mode and do */
//    }
//    else
//    {
//      rb_TempLightOnInv_l = TRUE; /*signal to switch light off*/
//    }
//  }
//  
  if((rbi_EEPROMLoad_g == FALSE)
      && ((rb_RSControlFlags_g == cb_HUMIDITY_SOLAR )||(rb_RSControlFlags_g == cb_ONLY_HUMIDITY)))
  {
    /*Incase of only Feuchte and solar frame preset then set the light ON, FW and IR to init value for safety reason*/
//    l_bool_wr_LS_Licht_ein(TRUE);                     
//    l_bool_wr_LS_Licht_ein_invers(FALSE);   
  } 
  else
  {
    /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
    DISABLE_SCIINTERRUPT();
//    l_bool_wr_LS_Licht_ein(rb_TempLightOn_l);                      // Licht ein = TRUE
//    l_bool_wr_LS_Licht_ein_invers(rb_TempLightOnInv_l);               // Licht eine invers = FALSE
    /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
    ENABLE_SCIINTERRUPT();
  }
  
//  if(((rbi_LightSensorActive_g == TRUE) && (rbi_EEPROMLoad_g == FALSE))&& (rbi_oneTimeAnswerd_g == TRUE))
//  {
//    l_bool_wr_RLS_Qualifizierungsbit(TRUE);
//  }
//  else
//  {
//    l_bool_wr_RLS_Qualifizierungsbit(FALSE);
//  }
//  
  
  
//  if((rbi_RainsensorDisabled_g == TRUE) || (rbi_LINRainsensorDisabled_g == TRUE))
//  {
////    l_bool_wr_RS_versParklage_Wischer(0);    // nicht in depressed park bei festem Interval
//  }
//  else
//  {
//    if(rw_AfterWWSWipeCounter_mg > caw_DeppressedParkDelayTable_g[rb_delay_depressed_park_pointer_g])
//    {
////      l_bool_wr_RS_versParklage_Wischer(1);   // Direktmodus Depressed Park bit uebergeben
//    }
//    else
//    {
////      l_bool_wr_RS_versParklage_Wischer(0);   // Direktmodus Depressed Park bit uebergeben
//    }
//  }
  
  if ((l_u8_rd_RS_RSensSts() == TRUE) && ((rbi_WindowOpenIgnitionWasOn_g == TRUE) && (rbi_Ignition_g== FALSE)) &&((rb_Verglasun_offenDebounce_mg > cb_VERGLSUNG_OPEN_DELAY_mg)&& (rbi_StandbyFunction_enabled_g == TRUE)))
  {
    rbi_ASICStandByModeRequest_g = 1;   // Set Request for Standby Mode
  }
  else
  {
    rbi_ASICStandByModeRequest_g = 0;
  }  
  
  if((rb_Verglasun_ClosedDebounce_mg > cb_VERGLSUNG_CLOSE_DELAY_mg)||(rbi_Ignition_g== TRUE))
  {
    rbi_Command_CloseWindows_g = FALSE;
    rbi_ASICStandByModeRequest_g = FALSE;
  }
  
//  if(rbi_SendWakeUpFrame_g == TRUE)                       // Anforderung fuer WakeUpFrame ?
//  {
//    ApplLinInit(0x01);                              // send wakup frame
//    rbi_SendWakeUpFrame_g = FALSE;                      // ruecksetzen des Wake up bits
//  }
//  if(rbi_Command_CloseWindows_g == TRUE)
//  {
//    l_bool_wr_RS_Verglasung_schliesen(TRUE);                // setzen von Verglasung Schliessen
//    if (rw_CommandCloseWindowTimout_mg > 6000)
//    {
//      rbi_ASICStandByModeRequest_g = 0;
//    }
//    else
//    {
//      rw_CommandCloseWindowTimout_mg++;
//    }
//  }
//  else
//  {
//    rw_CommandCloseWindowTimout_mg = 0;
//    l_bool_wr_RS_Verglasung_schliesen(FALSE);             // setzen von Verglasung Schliessen
//  }
  
  if(rbi_UnderVoltage_g == TRUE)  //undervoltage, Overvoltage ?
  {
    if(rb_underVoltageTimer_s>249)        // undervoltagetimer > 249 -> 2500 ms abwarten
    {
      rbi_LongUnderVoltage_g = 1;         // setze Fehlerbits
    }
    else
    {
      rb_underVoltageTimer_s++;           // inkrementiere undervoltagetimer
    }
  }
  else
  {
    rb_underVoltageTimer_s=0;             // loesche Timer
    rbi_LongUnderVoltage_g = 0;
  }
  
  /*VDR_859 Interval wipe in manual mode for no rain variant*/
  /*is rain function enabled?*/
#ifndef _NO_RAIN_
  /* VDR_124 set rain intensity to init if rain sensor is off*/
  if(((rbi_OverVoltage_g) || (rbi_LongUnderVoltage_g))||(rbi_AutomaticWipingMode_g==FALSE))
  {
    l_bool_wr_RS_RainSts(0);          // No rain
  }
  else if(rbi_RainSensorError > 0)
  {
    l_bool_wr_RS_RainSts(0);
  }
  else if((rw_rain_intensitiy_g >> 9) > 1)
  {
    l_bool_wr_RS_RainSts(1);
  }else
  {
    l_bool_wr_RS_RainSts(0);
  } 
//  if(((rbi_OverVoltage_g) || (rbi_LongUnderVoltage_g))||(rbi_AutomaticWipingMode_g==FALSE)) 
//  {
//    l_u8_wr_RS_Regenmenge(14);          // Regenmenge nicht verfuegbar
//  }
//  else if(rbi_RainSensorError > 0)
//  {
//    l_u8_wr_RS_Regenmenge(15);          // Regenmenge Fehler
//  }
//  else if((rw_rain_intensitiy_g>>9)>10)                               // Regenmenge zu hoch ?
//  {
//    l_u8_wr_RS_Regenmenge(10);                                   // Anschlag
//  }
//  else
//  {
//    l_u8_wr_RS_Regenmenge(rw_rain_intensitiy_g>>9);               //schreib egeschaetzte Regenmenge
//  }
  /*VDR_859 Interval wipe in manual mode for no rain variant*/
#else/*rain function is disabled*/
  l_u8_wr_RS_Regenmenge(14);          /*Regenmenge nicht verfuegbar*/
#endif /*_NO_RAIN_*/
  
//  rb_Helligkeitsboost_l=15; /*VCO_103 initialisation*/ 
//  if((rbi_LightValuesInitialised_g == FALSE)|| (rbi_EEPROMLoad_g == TRUE))
//  {
//    /*hold the previous values*/
//    if(rb_InitLightValCnt_l<100)
//    {
//      rb_InitLightValCnt_l++;
//    }
//    else
//    {
////      l_u8_wr_LS_Helligkeit_IR(0xFE);     // IR Helligkeit Init/nicht verfuegbar
////      l_u16_wr_LS_Helligkeit_FW(0x03FE);  // FW Helligkeit Init/nicht verfuegbar
////      l_u8_wr_SoSe_SunInt_2D_Li(0xFE); /* Init/nicht verfuegbar */
////      l_u8_wr_SoSe_SunInt_2D_Re(0xFE); /* Init/nicht verfuegbar */
//    }
//  }
//  else
//  {
//    rb_InitLightValCnt_l=0;
//    if(rb_RSControlFlags_g == cb_ONLY_HUMIDITY)
//    {
//      /*Incase of only Feuchte and solar frame preset then set the light ON, FW and IR to init value for safety reason*/
//      
////      l_u16_wr_LS_Helligkeit_FW(0x03FE);  /* Init/nicht verfuegbar */
//      if(rb_RSControlFlags_g == cb_ONLY_HUMIDITY)
//      {
//        /* Set IR to init value in case of only humidity sensor */
////        l_u8_wr_LS_Helligkeit_IR(0xFE);     /* Init/nicht verfuegbar */
//      }
//      
//    }
//    else if(l_bool_rd_LS_Error() == TRUE) /*  VDR469   set for error*/
//    {
//      l_u8_wr_LS_Helligkeit_IR(0xFF);     // IR Helligkeit Fehler
//      l_u16_wr_LS_Helligkeit_FW(0x03FF);  // FW Helligkeit Fehler
//      l_u8_wr_SoSe_SunInt_2D_Li(0xFF);
//      l_u8_wr_SoSe_SunInt_2D_Re(0xFF);
//    }
//    else
//    {
//      if(rb_RSControlFlags_g == cb_HUMIDITY_SOLAR )
//      {
//        l_u16_wr_LS_Helligkeit_FW(0x03FE);  /* Init/nicht verfuegbar */
//      }
//      else
//      {
//        if(get_rw_FW_light16bit_g() < 0x03FD) /*VCO_031 correct variable*/
//        {
//          l_u16_wr_LS_Helligkeit_FW(get_rw_FW_light16bit_g());
//        }
//        else
//        {
//          l_u16_wr_LS_Helligkeit_FW(0x03FD);   // FW Helligkeit max
//          rw_Hellighkeitsthrs = 0x03FD; /*VCO_103 calculate brightness boost*/ 
//          do 
//          {
//            rw_Hellighkeitsthrs += rw_Hellighkeitsthrs/10; /*VCO_103 calculate threshold*/ 
//            rb_Helligkeitsboost_l-- ;
//          }
//          while ((get_rw_FW_light16bit_g() >= rw_Hellighkeitsthrs)&&(rb_Helligkeitsboost_l >0));
//          
//        }
//      }
//      
//      if(rb_IrLightDiv8_g < 0xFD)
//      {
//        l_u8_wr_LS_Helligkeit_IR((byte)rb_IrLightDiv8_g);
//      }
//      else
//      {
//        l_u8_wr_LS_Helligkeit_IR(0xFD);     // IR Helligkeit max
//      }
//      
//      
//      
//      if ((rbi_SoSe_Enabled_g == TRUE) && (TRUE == rbi_SolarValuesInitialised_g))
//      {
//        if (rb_SolarShadowCorrFactor1_g > 0)
//        {
//          rw_IrLightforSOSE_Corr1_l= get_rw_IR_light16bit_g()/rb_SolarShadowCorrFactor1_g; 
//        }
//        else 
//        {
//          rw_IrLightforSOSE_Corr1_l = 0;  /*Function deactivated*/
//        }
//        
//        if((rw_IrLightforSOSE_Corr1_l) > (rw_Solar_light16bit_2_g))
//        {
//          rw_SoSe_SunInt_2D_Le_l = rw_IrLightforSOSE_Corr1_l;
//        }
//        else
//        {
//          rw_SoSe_SunInt_2D_Le_l = rw_Solar_light16bit_2_g ;
//        }
//        
//        
//        if((rw_IrLightforSOSE_Corr1_l) > (rw_Solar_light16bit_1_g))
//        {
//          rw_SoSe_SunInt_2D_Re_l = rw_IrLightforSOSE_Corr1_l;
//        }
//        else
//        {
//          rw_SoSe_SunInt_2D_Re_l = rw_Solar_light16bit_1_g ;
//        }    
//        
//        if (rb_SolarShadowCorrFactor2_g > 0)
//        {
//          rw_IrLightforSOSE_Corr2_l= get_rw_IR_light16bit_g()/rb_SolarShadowCorrFactor2_g; 
//        }
//        else 
//        {
//          rw_IrLightforSOSE_Corr2_l = 0;  /*Function deactivated*/
//        }
//        
//        if((rw_IrLightforSOSE_Corr2_l >= rw_SoSe_SunInt_2D_Le_l) && (rw_IrLightforSOSE_Corr2_l >= rw_SoSe_SunInt_2D_Re_l)) 
//        {
//          rw_SoSe_SunInt_2D_Le_l = rw_IrLightforSOSE_Corr2_l;
//          rw_SoSe_SunInt_2D_Re_l = rw_IrLightforSOSE_Corr2_l;
//        }
//        
//        if((rw_SoSe_SunInt_2D_Le_l/2) <= 240)
//        { 
//          l_u8_wr_SoSe_SunInt_2D_Li((byte)(rw_SoSe_SunInt_2D_Le_l/2));
//        }
//        else
//        {
//          l_u8_wr_SoSe_SunInt_2D_Li(240); /* Maximum value */
//        }
//        
//        if((rw_SoSe_SunInt_2D_Re_l/2) <= 240)
//        {
//          l_u8_wr_SoSe_SunInt_2D_Re((byte)(rw_SoSe_SunInt_2D_Re_l/2));
//        }
//        else
//        {
//          l_u8_wr_SoSe_SunInt_2D_Re(240); /* Maximum value */
//        }
//        
//      }
//      else
//      {
//        l_u8_wr_SoSe_SunInt_2D_Li(0xFE); /* Init/nicht verfuegbar */
//        l_u8_wr_SoSe_SunInt_2D_Re(0xFE); /* Init/nicht verfuegbar */
//      }
//    }
//    
//  }
//  l_u4_wr_LS_Helligkeit_FW_boost(rb_Helligkeitsboost_l);
  
  
  
//#ifdef SENSIRION_SHT21_USED
//  if (l_flg_tst_FSs_01() )
//  {
//    
//    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
//    l_flg_clr_FSs_01();
//  }
//
//  if (rbi_HumTempComError_g != 0)
//  {
//    l_u16_wr_FS_Taupunkt(1023);
//    l_u8_wr_FS_Luftfeuchte_rel(255);
//    l_u16_wr_FS_Temp_Scheibe(1023);
//    l_u8_wr_FS_Temp_Sensor(255);
//    
//  }
//  else
//  {
//    if(rw_Temperature_raw_g < 0x2D5)/* The temperature less than -39,5 the tool doesnot support */
//    {
//      rw_Temperature_Scheibe_g = 0x2D5;
//    }
//    else if(rw_Temperature_raw_g > 0x29E5)/* The temperature greater than 60,4 the tool doesnot support */
//    {
//      rw_Temperature_Scheibe_g = 0x29E5;
//    }
//    else
//    {
//      rw_Temperature_Scheibe_g = rw_Temperature_raw_g;
//    }
//    
//    if(rw_Temperature_raw_g < 0x2AD) /* The temperature less than -39,5 the tool doesnot support */
//    {
//      rw_Temperature_Sensor_g = 0x2AD;    
//    }
//    else if(rw_Temperature_raw_g > 0x3449)/* The temperature greater than 87,5 the tool doesnot support */
//    {
//      rw_Temperature_Sensor_g = 0x3449;
//    }
//    else
//    {
//      rw_Temperature_Sensor_g = rw_Temperature_raw_g;
//    }
//    
//    
//    
//    if (rw_DewPoint_g == cw_HUMTEMP_INIT_g)    // init?
//    {
//      l_u16_wr_FS_Taupunkt(0);
//    }
//    
//    else
//    {
//      if (rw_DewPoint_g < cw_DEWPOINT_MAX_mg )
//      {
//        /* dew point should be less than or equal to Scheibe temperature */
//        
//        l_u16_wr_FS_Taupunkt(rw_DewPoint_g); 
//        
//      }
//      else
//      {
//        l_u16_wr_FS_Taupunkt(cw_DEWPOINT_MAX_mg);
//      }
//    }
//    
//    
//    if (rb_Humidity_g == cw_HUMTEMP_INIT_g)    /* init?*/ /*VCO_061 name hase changed*/
//    {
//      l_u8_wr_FS_Luftfeuchte_rel(0);
//    }    
//    
//    else
//    {        
//      l_u8_wr_FS_Luftfeuchte_rel(rb_Humidity_g);
//    }
//    
//    /*
//    in ECU (sensor) 
//    Temp is - 46.85 to 128.85 
//    hex is : 0 to   0x44A2 
//    the resolution is 0.01 
//    
//    Assume  = X 
//    
//    in tool the formula is 
//    0:not valid 
//    1023: failure 
//    valid is from 1 to 1000 ( -39.5 to 60.4)  :   
//    Assume  = Y 
//    
//    that is 0.1* raw - 39.6 
//    
//    
//    Resolution mismatch is 0.1 
//    
//    Y = X 
//    
//    Y - 39.5 = X- 46.85 
//    
//    Y = X - 7.25   in Physical relation 
//    
//    Y = X / 10  - 72   Hex value  a) 
//    
//    Eg Assume that X is 60.4  equivalent hex is 10725 
//    
//    According to above eq a)  10725 / 10  - 73 =>  1000  which is 60.4 in Y
//    or
//    (X-725)/10
//    
//    */
//    if(rw_Temperature_raw_g == cw_HUMTEMP_INIT_g)
//    {
//      l_u16_wr_FS_Temp_Scheibe(0);
//    }
//    else
//    {
//      if(((rw_Temperature_Scheibe_g -725)/10)< 1)
//      {
//        l_u16_wr_FS_Temp_Scheibe(1);
//      }
//      else
//      {   
//        l_u16_wr_FS_Temp_Scheibe(((rw_Temperature_Scheibe_g -725)/10));
//      }
//    }
//    
//    if(rw_Temperature_raw_g == cw_HUMTEMP_INIT_g)
//    {
//      l_u8_wr_FS_Temp_Sensor(0);
//    }
//    else
//    {   
//      if(((rw_Temperature_Sensor_g-685)/50) < 1)
//      {
//        l_u8_wr_FS_Temp_Sensor(1);
//      }
//      else
//      {
//        l_u8_wr_FS_Temp_Sensor(((rw_Temperature_Sensor_g-685)/50));
//      }
//    }   
//    
//  }  
//#else
//  if (l_flg_tst_FSs_01() )
//  {
//    
//    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
//    l_flg_clr_FSs_01();
//  }
//
//  if (rbi_HumTempComError_g != 0)
//  {
//    l_u16_wr_FS_Taupunkt(1023);
//    l_u8_wr_FS_Luftfeuchte_rel(255);
//    l_u16_wr_FS_Temp_Scheibe(1023);
//    l_u8_wr_FS_Temp_Sensor(255);
//    
//  }
//  else
//  {
//    if (rw_DewPoint_g == cw_HUMTEMP_INIT_g)    // init?
//    {
//      l_u16_wr_FS_Taupunkt(0);
//    }
//    else
//    {
//      if (rw_DewPoint_g < cw_DEWPOINT_MAX_mg )
//      {
//        /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
//        if (rw_DewPoint_g > (CW_DEWPOINT_OFFSETT_mg+1))   
//        {
//          /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/ /* VDR_157 Dewpoint not set correct */
//          l_u16_wr_FS_Taupunkt((rw_DewPoint_g-CW_DEWPOINT_OFFSETT_mg));  
//        }
//        else
//        {
//          l_u16_wr_FS_Taupunkt(CW_DEWPOINT_MIN_mg);          /* VDR_157 Dewpoint not set correct */
//        }
//      }
//      else
//      {
//        l_u16_wr_FS_Taupunkt((cw_DEWPOINT_MAX_mg-CW_DEWPOINT_OFFSETT_mg));
//      }
//    }
//    if (rb_Humidity_g == cw_HUMTEMP_INIT_g)    /* init?*/ /*VCO_061 name hase changed*/
//    {
//      l_u8_wr_FS_Luftfeuchte_rel(0);
//    }
//    else
//    { /*VCO_095 use compensated humidity*/
//      if (rb_CompensatedSelfheatHumidity_g < 201) /*VCO_061 name hase changed*/
//      {
//        l_u8_wr_FS_Luftfeuchte_rel(rb_CompensatedSelfheatHumidity_g); /*VCO_061 name hase changed*/
//      }
//      else
//      {
//        l_u8_wr_FS_Luftfeuchte_rel(201);
//      }
//    }
//    if (rw_CompensatedSelfheatTemperature_g == cw_HUMTEMP_INIT_g)    // init?
//    {
//      l_u16_wr_FS_Temp_Scheibe(0);
//      l_u8_wr_FS_Temp_Sensor(0);
//    }
//    else
//    {
//      /*VCO_095 use compensated temperature*/
//      if (rw_CompensatedSelfheatTemperature_g < cw_TEMPSCHEIBE_MAX_mg)
//      {
//        /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
//        if (rw_CompensatedSelfheatTemperature_g > (CW_TEMPERATURE_OFFSETT_mg+1))   
//        {
//          /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
//          l_u16_wr_FS_Temp_Scheibe((rw_CompensatedSelfheatTemperature_g-CW_TEMPERATURE_OFFSETT_mg));  
//        }
//        else
//        {
//          l_u16_wr_FS_Temp_Scheibe(CW_TEMPERATURE_MIN_mg);
//        }
//      }
//      else
//      {
//        l_u16_wr_FS_Temp_Scheibe((cw_TEMPSCHEIBE_MAX_mg-CW_TEMPERATURE_OFFSETT_mg));
//      }
//      
//      rw_SensorTemp_l = (((rw_CompensatedSelfheatTemperature_g+2)/5)); //scale for light value
//      if (rw_SensorTemp_l < cb_TEMPSENSOR_MAX_mg)
//      {
//        if (rw_SensorTemp_l < CW_TEMPERATURE_MIN_mg)
//        {
//          l_u8_wr_FS_Temp_Sensor(((byte)(CW_TEMPERATURE_MIN_mg)));
//        }
//        else
//        {
//          l_u8_wr_FS_Temp_Sensor(((byte)(rw_SensorTemp_l)));
//        }
//      }
//      else
//      {
//        l_u8_wr_FS_Temp_Sensor(cb_TEMPSENSOR_MAX_mg);
//      }
//    }
//  }
//#endif 
  if (rbi_OverVoltage_g > 0)
  {
    l_u8_wr_RS_VoltFailSts(1);                  // Overvoltage
  }
  else if(rbi_UnderVoltage_g >0)
  {
    l_u8_wr_RS_VoltFailSts(2); 
  }
  else
  {
    l_u8_wr_RS_VoltFailSts(0); 
  }  
#if defined (ASIC_TEST)
  CopyRLSDataAsic();
#endif  
  
  rb_WDG_BusTaskCounter_g++;      //increment test counter for bus
}


void ApplLinInit(byte rb_LIN_State_l)
{
  
  // init unused bits to 1
  byte rb_Index_l;
  static const byte LinMsgDefault_RLSs_01[4] = {0,0,0,0}; /* id: 0x023 "RLSs_01" */
  
  rb_Index_l = 0;
  do
  {
    RS._c[rb_Index_l] = LinMsgDefault_RLSs_01[rb_Index_l];
    rb_Index_l++;
  } while (rb_Index_l < 4);
  
//  Diagnose_ReadMem_Init();
  rw_AfterRSWipeCounter_mg = 50000;
  rw_AfterRSWipeCounterAlt_mg = 50000;
  rw_AfterWWSWipeCounter_mg = 50000;          //Direktbitdelay bei Kl15 Aus hochsetzen!
  sci_init(rb_LIN_State_l);
  rbi_RealParkContact_g = TRUE;
  rbi_ParkPosition_g = TRUE;
  rb_PotiStageFromBox_g = 3; /*VDR_408 use init value*/
//  rb_AnyErrorCounterDebounce_mg = 200;
  
}                                              


__callt void ApplLinSlavePreCopy(byte rb_MessageID_l)    /* callt function (faster */
{
  if((rb_MessageID_l == (rb_IDRLSs_01_g & 0x3F))&&((rb_RSControlFlags_g & 0x80) == FALSE))
  {
    l_bool_wr_RS_ResponseError(rbi_latched_ResponseError_mg);
    rbi_latched_ResponseError_mg = FALSE;
  }
  else
  {
    if((rb_MessageID_l == (rb_IDFSs_01_g & 0x3F))&&((rb_RSControlFlags_g & 0x80) != FALSE))
    {
      /* send response error in FS message if only humidity sensor is active */
      l_bool_wr_RS_ResponseError(rbi_latched_ResponseError_mg);
      rbi_latched_ResponseError_mg = FALSE;
    } 
  }
}

//static void LIN_CalculateFixIntervalTime(void)
//{
//  word rw_temporary_WH_State_l;  
//  static word rw_WH_State_l_old_mg;
//  static byte rb_Deaktivierung_RS_mg;
//  /*interval times for rain sensor below 4kmph inactive in 100ms*/
//  static const byte cab_FixIntervtim_bel4kmph_mg[4] = {240,160,80,40}; 
//  /*interval times for rain sensor above 200kmph inactive in 100ms*/
//  static const byte cab_FixIntervtim_a200kmph_mg[4] = {70,40,20,10};   
//  /*interval times for rain sensor above 200kmph inactive in 100ms*/
//  static const byte cab_FixIntervtim_Offsett_mg[4] = {190,120,60,30};  
//  /*interval times for rain sensor above 200kmph inactive in 100ms*/
//  static const byte cab_FixIntervtim_Devider_mg[4] = {10,15,30,60};
//  /* Bits 0-3 WH_Intervallstufe, Bit 4: WH_Interval , Bit 5:WH_WischerStufe1, Bit 6:WH_WischerStufe2,
//  Bit 7: WH_Frontwaschen, Bit 8: Deaktivierung_RS,  */
//  
//  /*VCO_192*/
//  rw_temporary_WH_State_l = ((l_u8_rd_WH_Intervallstufe()) | (l_bool_rd_WH_Intervall() << 4) | 
//                             (l_bool_rd_WH_WischerStufe1() << 5) | (l_bool_rd_WH_WischerStufe2() << 6) | 
//                               (l_bool_rd_BCM_WndShldWashSwSts() << 7) | (((word)(l_u8_rd_Deaktivierung_RS())) << 8) );
//  if(rbi_MasterMessageRecieved_g == TRUE)
//  {
//    if((rw_WH_State_l_old_mg != rw_temporary_WH_State_l) && ((rw_WH_State_l_old_mg & 0x01FF)>0) && 
//       ((rbi_LINRainsensorDisabled_g == TRUE)|| ((rbi_RainsensorDisabled_g == TRUE) && (rbi_Ignition_g == TRUE))) )
//    {
//      rbi_Relase_FixedIntervalTime_g = TRUE;  /* clear this after 10s IGN Off set it after change on signals see_682 doors Req */
//    }
//    
//  }
//  rw_WH_State_l_old_mg = rw_temporary_WH_State_l;
//  
//  /* wipe Decision and Set!*/
//  if((((rbi_LINRainsensorDisabled_g == TRUE) || ((rbi_RainsensorDisabled_g == TRUE)&&(rbi_EEPROMLoad_g == FALSE))) && (rbi_Ignition_g == TRUE))&&
//     ((rbi_Relase_FixedIntervalTime_g == TRUE) || ((rb_Release_IntervalMarker_g == 0x0A)&&((rb_Release_IntervalMarker_Update_g&0xA0)!= 0xA0))))
//  {
//    if(l_bool_rd_WH_Intervall() == TRUE)
//    {
//      if(rb_speed_in_kmh_g <= 4)
//      {
//        rb_intervaltime_rainSensorOff_g = cab_FixIntervtim_bel4kmph_mg[(l_u8_rd_WH_Intervallstufe()>>2)];
//      }
//      else if(rb_speed_in_kmh_g < 200)
//      {
//        rb_intervaltime_rainSensorOff_g = cab_FixIntervtim_Offsett_mg[(l_u8_rd_WH_Intervallstufe()>>2)]
//          -(byte)((((word)(rb_speed_in_kmh_g)*6)/cab_FixIntervtim_Devider_mg[(l_u8_rd_WH_Intervallstufe()>>2)]));
//      }
//      else
//      {
//        rb_intervaltime_rainSensorOff_g = cab_FixIntervtim_a200kmph_mg[(l_u8_rd_WH_Intervallstufe()>>2)];
//      }
//      if((rw_AfterWWSWipeCounter_mg/10) >= rb_intervaltime_rainSensorOff_g) /*VCO_031 correct rainlight*/
//      {
//        
//        rbi_TunnelWipe_mg = TRUE;
//      }
//      if((rb_Deaktivierung_RS_mg == 0)&&(l_u8_rd_Deaktivierung_RS() == TRUE))
//      {
//        rbi_TunnelWipe_mg = TRUE;
//      }
//      
//      
//      /* Update marker in the EEPROM to indicate there is release interval is activated */
//      /* donot update if LIN going to sleep Release_IntervalMarker is set to 0 */
//      if(rw_NoCommunicationCounter_g <= (CW_LIN_E2_IDLE_TIMOUT - 3) )
//      {
//        rb_Release_IntervalMarker_Update_g = 0x0A;
//        rbi_Write_ReleaseMarker_g = TRUE;
//      }
//      
//    }
//    else
//    {
//      /* interval fuer Ampelrueckschaltung*/
//      if((l_bool_rd_WH_WischerStufe1() == TRUE)||(l_bool_rd_WH_WischerStufe2() == TRUE)) 
//      {
//        if((rw_AfterWWSWipeCounter_mg>>4) >= cb_FOUR_SECOND_DELAY_mg)
//        {
//          
//          rbi_TunnelWipe_mg = TRUE;
//        }
//      }
//    }
//  }
//  rb_Deaktivierung_RS_mg = l_u8_rd_Deaktivierung_RS();
//}
