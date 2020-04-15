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
/*14.01.2016 VCO_304    NB      TESLA:Implementation of response wipe and Ice detection                         */
/*15.01.2016 VCO_304    NB      TESLA:Implementation of response wipe and Ice detection                         */
/*25.01.2016 VCO_304    NB      TESLA:Implementation of response wipe and Ice detection                         */
/*16.02.2016 VCO_304    NB      TESLA:Implementation of response wipe and Ice detection                         */
/*16.02.2016 VDR_946    MP      Confirmation wipe set only when ignition is on*/
/*16.02.2016 VDR_946    MP      Rain_Sensitivity adapted for 880nm 85% and 0 is ignored*/
/*22.02.2016 VDR_948    NB      TESLA:During Splash wiperspeed set to 14 in case of multispeed wiperb           */
/*26.02.2016 VDR_946    NB      Confirmation wipe set only when ignition is on                                  */
/*26.02.2016 VDR_946    NB      Light switch reason not set in case of highway mode                             */
/*26.02.2016 VDR_945    NB      Signal Invalid shall not be considered                                          */
/*04.03.2016 VDR_945    NB      TESLA:Handling of Signal Invalid case for all signals                           */
/*15.03.2016 VDR_945    NB      TESLA:Handling of Signal Invalid case for all signals                           */
/*30.05.2016 VDR_983    NB      Sporadic illegale instruction reset in the startup                              */

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
#include "G5_TwilightToDark.h"

#include "G5_AsicFramesLin.h"

#ifdef SENSIRION_SHT21_USED
#define cw_DEWPOINT_MAX_mg    (1000)     /*VDR_154 change of max value from 1022 to 1000*/
#else
#define cw_DEWPOINT_MAX_mg    (1000+CW_DEWPOINT_OFFSETT_mg)     /*VDR_154 change of max value from 1022 to 1000*/
#endif

#define cb_GREEN_GLASS 0
#define cb_CLEAR_GLASS 1

#define HIGH_SPEED  14
#define LOW_SPEED   1 

#define cw_TEMPSCHEIBE_MAX_mg (1000+CW_TEMPERATURE_OFFSETT_mg)  /*VDR_154 change of max value from 1022 to 1000*/
#define CW_TEMPERATURE_OFFSETT_mg 4 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define CW_DEWPOINT_OFFSETT_mg 4 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define CW_DEWPOINT_MIN_mg 1 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define CW_TEMPERATURE_MIN_mg 1 /*VDR_154 change of min value from -39.9GradC to -39.5GradC*/
#define cb_TEMPSENSOR_MAX_mg 254

#define WIPER_OUT_OF_PARK_POSITION 13
#define WIPER_IN_PARK_POSITION 14
#define NO_ACTION                  0
#define AUTO_MODE                  1
#define MANUAL_LOW_SPEED           2
#define MANUAL_HIGH_SPEED          3
#define FRONT_WASH                 16
#define SIGNAL_INVALID            0xFF

#define cb_DAY                      0x00
#define cb_TWILIGHT                 0x01
#define cb_DARK                     0x02
#define cb_RAIN_LIGHT               0x04
#define cb_TUNNEL                   0x08
#define cb_UNDERGROUND              0x10
#define cb_HIGH_SPEED               0x20
#define cb_HUD_MEASURING_RANGE_1    0x40
#define cb_HUD_MEASURING_RANGE_2    0x80


/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/
static byte rb_IgnitionOndelay_mg;
/* PRQA S 3218 7 */ /* <<needed at this level for better debugging>> */
static byte rb_Verglasun_offenDebounce_mg,rb_Verglasun_ClosedDebounce_mg;

static word rw_AfterRSWipeCounter_mg;                   /* Time after last wipe from RS*/
static word rw_AfterRSWipeCounterAlt_mg;                /* Time to the last wipe from RS*/
static word rw_AfterWWSWipeCounter_mg;                  /* Time after last wipe from WWS*/
static word rw_CommandCloseWindowTimout_mg;
static word rw_WipeCommandTimOut_mg;                     /*timout for requested wipe*/

static byte rb_RainSensitivity_mg = 0xF ;
static byte rb_RainSensitivityPrev_mg = 0xF;

/* PRQA S 3218 7 */ /* <<needed at this level for better debugging>> */
//static const byte cab_AUDI_SenMapping[16] = {0,0,0,2,2,2,2,2,3,3,3,5,5,5,5,3};
/* PRQA S 3218 7 */ /* <<needed at this level for better debugging>> */
static const byte cab_PotistageMapping_mg[8] = {4,5,6,7,3,2,1,0}; /*mapping for potistages!*/


//static const word caw_DeppressedParkDelayTable_g[4] = {500,1000,1500,2000};

#define cb_VERGLSUNG_CLOSE_DELAY_mg 100
#define cb_VERGLSUNG_OPEN_DELAY_mg 100
#define cb_FOUR_SECOND_DELAY_mg   25
#define cw_CLEARWIPE_DELAY_s 400 /* 4 seconds (400*10ms)*/
#define cb_DEPRESSED_PARK_DEBOUNCE_s 18



static byte rb_AnyErrorCounterDebounce_mg;

/******************************************************************************/
/*                      Definition of exported variables                      */
/******************************************************************************/


/*************************************************************************
**                   Declaration of local module Functions              **
*************************************************************************/

#define CB_BRIGHTNESS_MAX_VALUE_s 7   /*Max Value for Helligkeit*/
#define cb_BRIGHTNESSSCALING_FAKT_s 3 /*Scaling fakt x  2^x*/

static void LIN_CalculateFixIntervalTime(void);

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
  static byte rb_speed_1kmh_Reached_g = 0;

  
  if(l_flg_tst_VEH_DATA())               /*Master Request?*/
  {
    l_flg_clr_VEH_DATA();                 /*loesche flag*/
    rbi_LightSensitivityRecieved_g = TRUE; 
    if(l_u8_rd_WIPER_POSITION() == WIPER_IN_PARK_POSITION)
    {
      /* Park position information comes from BCM message */
      rbi_RealParkContact_g = TRUE;
    }
    else
    {
      rbi_RealParkContact_g  = FALSE;
    }
    
    if(l_u8_rd_WIPER_CONTROL() == FRONT_WASH)   /* Waschpumpe aktiv?*/
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

    
    /* ignore ignition off if speed higher 4km/h*/
    if((l_u8_rd_STATE_IGNITION() == 10)||(rb_speed_in_kmh_g > cb_IGNORE_IGNITION_SPEED)) /*VCO_083*/
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
        if((l_u8_rd_WIPER_CONTROL() == AUTO_MODE )
           || (l_u8_rd_WIPER_CONTROL() == MANUAL_LOW_SPEED)
             || (l_u8_rd_WIPER_CONTROL() == MANUAL_HIGH_SPEED))
        {
          if((rb_speed_1kmh_Reached_g == 1) || ((l_u8_rd_TEMP_EX() > rb_iceDetectionTemperature_g) && (l_u8_rd_TEMP_EX() != SIGNAL_INVALID)) )
          {
            rbi_AutomaticWipingMode_g = TRUE;           /*Rainsensor always active!*/
          }
          else
          {
	    rbi_AutomaticWipingModeInv_g = FALSE;
            rbi_AutomaticWipingMode_g = FALSE;           /*Rainsensor off!*/
          }
        }
        else
        {
          if(NO_ACTION == l_u8_rd_WIPER_CONTROL())
          {
            rbi_AutomaticWipingModeInv_g = TRUE;
            rbi_AutomaticWipingMode_g = FALSE;           /*Rainsensor off!*/
        }
      }
      }
      else
      {
        if((rb_speed_1kmh_Reached_g == 1) || ((l_u8_rd_TEMP_EX() > rb_iceDetectionTemperature_g) && (l_u8_rd_TEMP_EX() != SIGNAL_INVALID)))
        {
          rbi_AutomaticWipingModeInv_g = TRUE;
        }
        else
        {
          rbi_AutomaticWipingModeInv_g = FALSE;
        }
        rbi_AutomaticWipingMode_g = FALSE;           //Rainsensor off!
      }
      
      
      if(l_u8_rd_WIPER_CONTROL()== AUTO_MODE) // copy automatic wiping mode
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
    if(l_u16_rd_VEH_SPEED() != 4095)
    {
    if(l_u16_rd_VEH_SPEED() < 1023)/*Check for max value   speed faster than 200 (255km/h) */
    {
      rb_speed_in_kmh_g = (byte)((word)(l_u16_rd_VEH_SPEED())/4); /*recalibrate Data */
      if(rb_speed_in_kmh_g >= 1)
      {
        rb_speed_1kmh_Reached_g = 1;
      }
      if(rb_speed_in_kmh_g>=10)
      {
        rbi_speedWasAbove10kmh_g = TRUE;
      }
    }
    else 
    {
      rb_speed_in_kmh_g = 255;                           /* set speed to (255 km/h)*/
      rb_speed_1kmh_Reached_g = 1;
    }
    
    }
    if(l_u8_rd_RAIN_SENSITIVITY() != 0x0F) /* Signal invalid shall be rejected*/
    {
      if(l_u8_rd_RAIN_SENSITIVITY()>0) /*no update if init*/
      {
        
        rb_PotiStageFromBoxTemp_l = l_u8_rd_RAIN_SENSITIVITY() - 1;
        
        if(rb_PotiStageFromBoxTemp_l>7)
        {
          rb_PotiStageFromBox_g = 7;
        }
        else
        {
          rb_PotiStageFromBox_g = rb_PotiStageFromBoxTemp_l ;
        }
      }
      
      rb_RainSensitivity_mg = l_u8_rd_RAIN_SENSITIVITY();
    }
    
    if(((rbi_AutomaticWipingModeInv_g == TRUE) || (rb_RainSensitivity_mg > rb_RainSensitivityPrev_mg))&& (rbi_AutomaticWipingMode_g == TRUE))
      {
      rbi_AutomaticWipingModeInv_g = FALSE;
        rbi_TunnelWipe_mg = 1; /* make a single wipe incase of increased sensitivity */ 
      }
      
      rb_RainSensitivityPrev_mg = rb_RainSensitivity_mg;
    
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
      
      if ((rbi_Command_CloseWindows_g == FALSE)||( rbi_ASICStandByModeRequest_g == FALSE))  /*VDR_526*/
      {
        if ( ((rbi_Ignition_g== FALSE)) &&((rb_Verglasun_offenDebounce_mg > cb_VERGLSUNG_OPEN_DELAY_mg) &&
                                           (rbi_StandbyFunction_enabled_g == TRUE)) && (rbi_Command_CloseWindows_g == FALSE) )
        {
          rbi_ASICStandByModeRequest_g = 1;   // Set Request for Standby Mode
        }
        else
        {
          rbi_ASICStandByModeRequest_g = 0;
        }
        
        rbi_GotoSleep_g = TRUE;         // Was Connected to Master
      }
      else 
      {
        if (/*(l_bool_rd_Verglasung_offen()==FALSE)||*/(rw_CommandCloseWindowTimout_mg > 6000))
        {
          rbi_GotoSleep_g = TRUE;         // no need of Standby mode 
          rbi_ASICStandByModeRequest_g = 0;
          rbi_SendWakeUpFrame_g = FALSE;  /*VDR_526*/
          rbi_Command_CloseWindows_g = FALSE; /*VDR_526*/
          rb_WakeupCounter_mg = 0; 
        }
        else
        {
          if (rb_WakeupCounter_mg == FALSE) /*VDR_526*/
          { 
            rbi_SendWakeUpFrame_g = TRUE; 
          }
        }
      }
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
  
  if(((rab_SensConfigData_g(2)&0x07) != 7) && (rbi_EEPROMLoad_g == FALSE))
  {
  if ((rab_SensConfigData_g(2)&0x07)>5) 
  {
    rb_Empfindlichkeit_LS_l = 5;
  }
  else
  {
    rb_Empfindlichkeit_LS_l = (rab_SensConfigData_g(2)&0x07);
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
  
  
  if(l_flg_tst_SENS_CONFIG_DATA())                  //Wischermotor request?
  {
    l_flg_clr_SENS_CONFIG_DATA();                  //loesche flag
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
    if(rbi_EEPROMLoad_g == FALSE)/* EEPROM load finished */
    {
    if((SENS_CONFIG_DATA._c[0] != (rab_SensConfigData_g(0))) ||
       (SENS_CONFIG_DATA._c[1] != (rab_SensConfigData_g(1))) || 
         (SENS_CONFIG_DATA._c[2] != (rab_SensConfigData_g(2))) )
    {
      rab_EEPROM_Bytes_toWrite_g[0] = SENS_CONFIG_DATA._c[0];
      rab_EEPROM_Bytes_toWrite_g[1] = SENS_CONFIG_DATA._c[1] ;
      rab_EEPROM_Bytes_toWrite_g[2] = SENS_CONFIG_DATA._c[2];
      rw_EEPROM_Address_to_Write_g = CW_SENS_CONFIG_DATA_ADRESS; /*set adress to write*/
      rb_I2C_EEPROM_bytesToWrite_g = 3;         /*set number of bytes to 1*/
      rbi_EEPROMBytesToWrite_g = TRUE;
      rbi_EEPROMBytesWritten_g = FALSE;
    }
  }
  }
     
  
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
  
  if(((l_u8_rd_WIPER_CONTROL() == NO_ACTION )       
      && (rbi_RealParkContact_g == TRUE))
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
    if((rbi_RealParkContact_g == FALSE)&&(rb_WiperSpeed_g > 0))
    {
      rbi_WiperStarted_g = TRUE;
    }
    
    if(rbi_RealParkContact_g == TRUE)        // In Parklagensignal ?
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
  static word rw_Temperature_Sensor_g;
  //static word rw_Temperature_Scheibe_g;
  static byte rb_OutOffParkCounter_mg;
  static byte rb_RLS_Botschaft_s;
  static byte rb_underVoltageTimer_s;
  static byte rb_TunnelWipeTimeOut_mg;
  static byte rb_InitLightValCnt_l=100;
  static byte rb_tunnelWipeActive_g;
   byte rb_newWiperSpeedLin_l;
   byte rb_CurrentWiperSpeedLin_l;
 // word rw_Hellighkeitsthrs; /*VCO_103 local variable for brightness boost*/
  word rw_IrLightforSOSE_Corr1_l;
  word rw_IrLightforSOSE_Corr2_l;
  word rw_SoSe_SunInt_2D_Le_l;
  word rw_SoSe_SunInt_2D_Re_l;
  /*VCO_260 Tunnel wipe activation and delay according to Tunnel Verzoegerung and Aktivierung parameters*/
  word rw_tunnelWischVerzoegerung_l=(((word)CB_TUNWISCHVERZ_MG)*100);
  word rw_tunnelWischAktivierung_l=(((word)CB_TUNWISCHAKTIV_MG)*100);

  byte rb_AnyErrorCounterDebounce_l; 
  byte rb_TempLightOn_l;
  byte rb_lightSwitchingReason;
  byte rb_Freewaylight_enabled_l;
  //byte rb_TempLightOnInv_l;
  //byte rb_Helligkeitsboost_l; /*VCO_103 local variable for brightness boost*/ 
  if((rab_SensConfigData_g(1) & 0xC0) != 0xC0)
  {
  rb_Freewaylight_enabled_l = (rab_SensConfigData_g(1) & 0xC0); /* get highway light configuration*/
  }
#ifndef SENSIRION_SHT21_USED
  word rw_SensorTemp_l;
#endif
  
  Check_StartupActiveErrors();
  
  LIN_CalculateFixIntervalTime();
  
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
  
   l_u8_wr_ERR_STATE_CAL_RAIN_SENS(0);
  l_u8_wr_ERR_STATE_CODING(0); 
  l_u8_wr_ERR_STATE_OVER_VOLT(rbi_OverVoltage_g);
  
  if(l_flg_tst_RAIN_LIGHT_DATA())                            // pruefen ob eigene Nachricht korrekt empfangen wurde
  {
    l_flg_clr_RAIN_LIGHT_DATA() ;                          // loeschen des Pruefflags
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
    rb_RLS_Botschaft_s++;                          // Incrementierung des Botschaftszaeheler
    
    rbi_oneTimeAnswerd_g = TRUE;
    
  }
  if(((((rab_SensConfigData_g(1))>>2)&0x03) != 3 ) && (rbi_EEPROMLoad_g == FALSE))
  {
    if(((((rab_SensConfigData_g(1))>>2)&0x03) == 0 ))
    {
      rbi_LINRainsensorDisabled_g = FALSE; /* Rain function active */
    }
    else
    {
      rbi_LINRainsensorDisabled_g = TRUE; /* Rain function disabled */
    }
  } 
  if (l_flg_tst_SOLAR_DATA() )
  {
    
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
    l_flg_clr_SOLAR_DATA();
  } 
  if (l_flg_tst_LIGHT_DATA_RAW() )
  {
  
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
    l_flg_clr_LIGHT_DATA_RAW();
  }   
  
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
    l_u8_wr_WIPER_SPEED(1);
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
    l_u8_wr_WIPER_SPEED(1);
    l_u8_wr_STATUS_RAIN_SENS(1); /*Normal wiping */ 
  }
  else
  {
    /*VCO_166 wiper speed limited to 1, when interval is not selected*/
    if(((l_u8_rd_WIPER_CONTROL()== MANUAL_LOW_SPEED) || (l_u8_rd_WIPER_CONTROL()== MANUAL_HIGH_SPEED))&&(rb_WiperSpeed_g > 1))
    {
      l_u8_wr_WIPER_SPEED(1);   // Wischergeschwindigkeit uebergeben
      l_u8_wr_STATUS_RAIN_SENS(1); /*Normal wiping */ 
    }
    else
    {
      if(((rab_SensConfigData_g(1)&0x03) != 3 ) && ((rbi_EEPROMLoad_g == FALSE)))
      {
      if((rab_SensConfigData_g(1)&0x03) == 0 ) 
      {
        if(l_u8_rd_WIPER_SPEED() == HIGH_SPEED)
        {
          rb_CurrentWiperSpeedLin_l = 2;
        }
        else
        {
          rb_CurrentWiperSpeedLin_l  = l_u8_rd_WIPER_SPEED();
        }
        rb_newWiperSpeedLin_l =  wiperSpeed7to2(rb_CurrentWiperSpeedLin_l, rb_WiperSpeed_g, rb_wiperSpeedHysteresis);
        if(rb_newWiperSpeedLin_l == 2)
        {
        l_u8_wr_WIPER_SPEED(HIGH_SPEED); /* two step wiper*/
        }
        else
        {
          l_u8_wr_WIPER_SPEED(rb_newWiperSpeedLin_l); /* two step wiper*/
        }
      }
      else
      {
        l_u8_wr_WIPER_SPEED(rb_WiperSpeed_g); /* Multi step wiper*/
      }
      /*VDR_859 Interval wipe in manual mode for no rain variant*/
      /*is RS functionality enabled?*/
      if(rbi_RSWipeFastDmd == TRUE)
      {
        l_u8_wr_STATUS_RAIN_SENS(2);   /* gush of water*/
        if((rab_SensConfigData_g(1)&0x03) == 0) 
        {
          l_u8_wr_WIPER_SPEED(HIGH_SPEED);
        }
        else
        {
          l_u8_wr_WIPER_SPEED(7);/* set to max speed */
        }
      }
      else if (rb_WiperSpeed_g >0)
      {
        l_u8_wr_STATUS_RAIN_SENS(1); /*Normal wiping */  
      }
      else
      {
        l_u8_wr_STATUS_RAIN_SENS(0); /*No wiping */ 
      }
    }
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
  
  
  if(FALSE==rbi_EEPROMLoad_g)
  {
    if((FALSE==rbi_RainSensor_enabled_g) && (FALSE==rbi_RainsensorDisabled_g))
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
  

  if((TRUE==rbi_RainSensor_enabled_g) && (FALSE==rbi_RainsensorDisabled_g))
  {
    /* VCO132: SM210 - ASIC Frequency Check (done at startup) - LS,RS_Failure */
    /* VCO 140: SM150 - ADC test */
    /* setze Lichtsensor RS-Fehler nach SRS */
    /*SM240*/
    l_u8_wr_ERR_STATE_RAIN_SENS((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_RainS_Error1_g != 0));
    
    if((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_RainS_Error1_g != 0))
    {
      l_u8_wr_STATUS_RAIN_SENS(8); /* Rain Sensor in Fail-Safe */
    } 
  }
  else
  {
    /*only RAM/ROM error and RS version error*/
    l_u8_wr_ERR_STATE_RAIN_SENS(((rb_RS_LS_Error1_g&0x3) != 0)||(TRUE==bi_RS_VariantError_g));
    if(((rb_RS_LS_Error1_g&0x3) != 0)||(TRUE==bi_RS_VariantError_g))
    {
      l_u8_wr_STATUS_RAIN_SENS(8); /* Rain Sensor in Fail-Safe */
    }
  }
    
  /* setze Lichtsensor Fehler nach SRS*/
  /* VDR 757 - SM200 */
    /*SM240*/
  
  l_u8_wr_STATUS_LIGHT_SENS((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(rbi_CRC_ChangedByDiagnostic_g));
  if((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(rbi_CRC_ChangedByDiagnostic_g))
  {
    l_u8_wr_ERR_STATE_LIGHT_SENS(TRUE);
  }
  else
  {
    l_u8_wr_ERR_STATE_LIGHT_SENS(FALSE);
  }
  /* PRQA S 3415, 4112 1 */ /* << Getter functions must not have side effects >>*/
  if ((((((IS_LS_ANY_ERRORCOUNTER()) > 0))||((l_u8_rd_STATUS_LIGHT_SENS()) > 0))||(((rbi_UnderVoltage_g) == TRUE))
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
  
  //l_bool_wr_RS_AdaptierungError(0); //Error in EEPROM
  // End of Generate Initialwipe Switching the Rainsensore on
  
  //l_bool_wr_RS_Regenfahrlicht(rbi_modi_lightsens_rain_g); /*copy data for rainlight */
  //l_bool_wr_LS_Autobahnfahrlicht(rbi_FastHighwayMode_g);   /*copy data for highwaylight*/
  
  
  
  rb_AnyErrorCounterDebounce_l = rb_AnyErrorCounterDebounce_mg; 
  
  if(l_u8_rd_STATUS_LIGHT_SENS() == TRUE)
  {
    rb_TempLightOn_l = 1;
  }
  /*VCO_50*//*VDR_129 use Sensitivity Treatment*/
  else if(((uF_modi_lightsens_g.AllBit & 0x2F)>0)||(rbi_InternalResetOccured_g > 0)||(rbi_Regulation48LightOnFlag_g !=0))
  {
    rb_TempLightOn_l = TRUE;
    //l_bool_wr_LS_Dunkel(TRUE);             // set bit for darkness
  }
  /*VDR_129 use Sensitivity Treatment*/
  else if((((rb_Freewaylight_enabled_l != FALSE))&& (rbi_FastHighwayMode_g == TRUE))
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
      rb_TempLightOn_l = l_u8_rd_LIGHT_SWITCH_REQUEST() ; /* stay in old light mode and do */
    }
  }
  
  
  
  /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
  DISABLE_SCIINTERRUPT();
  l_u8_wr_LIGHT_SWITCH_REQUEST(rb_TempLightOn_l);                      // Licht ein = TRUE
  //l_bool_wr_LS_Licht_ein_invers(rb_TempLightOnInv_l);               // Licht eine invers = FALSE
  /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
  ENABLE_SCIINTERRUPT();
  
   if(((rbi_LightSensorActive_g == TRUE) && (rbi_EEPROMLoad_g == FALSE))&& (rbi_oneTimeAnswerd_g == TRUE))
   {
     
     rb_lightSwitchingReason = cb_DAY;
     
     if((uF_modi_lightsens_g.AllBit & cb_NIGHT_mg) && (isDarkActive() == FALSE)) 
     {
       rb_lightSwitchingReason = cb_TWILIGHT;
     }
     else if((uF_modi_lightsens_g.AllBit & cb_NIGHT_mg) && (isDarkActive()))
     {
       rb_lightSwitchingReason = cb_DARK;
     }
     else if(uF_modi_lightsens_g.AllBit & cb_TUNNEL_mg)
     {
       rb_lightSwitchingReason = cb_TUNNEL;
     }
     else if(uF_modi_lightsens_g.AllBit & cb_DARKSTART_mg)
     {
       rb_lightSwitchingReason = cb_UNDERGROUND;
     }
     else if((rb_Freewaylight_enabled_l != FALSE)&& (rbi_FastHighwayMode_g == TRUE))
     {
       rb_lightSwitchingReason = cb_HIGH_SPEED;
     } 
     else if((rbi_modi_lightsens_rain_g == TRUE)&& (rbi_RainLight_enabled_g == TRUE))
     {
       rb_lightSwitchingReason = cb_RAIN_LIGHT;
     }
     else{}
   }
   else
   {
     rb_lightSwitchingReason = SIGNAL_INVALID;
   }
  l_u8_wr_LIGHT_SWITCH_REASON(rb_lightSwitchingReason|cb_HUD_MEASURING_RANGE_1);
  
  
  if ((l_u8_rd_ERR_STATE_RAIN_SENS()==FALSE) && ((rbi_WindowOpenIgnitionWasOn_g == TRUE) && (rbi_Ignition_g== FALSE)) &&((rb_Verglasun_offenDebounce_mg > cb_VERGLSUNG_OPEN_DELAY_mg)&& (rbi_StandbyFunction_enabled_g == TRUE)))
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
  
  if(rbi_SendWakeUpFrame_g == TRUE)                       // Anforderung fuer WakeUpFrame ?
  {
    ApplLinInit(0x01);                              // send wakup frame
    rbi_SendWakeUpFrame_g = FALSE;                      // ruecksetzen des Wake up bits
  }
  if(rbi_Command_CloseWindows_g == TRUE)
  {
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
  }
  
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
   
  if((rbi_LightValuesInitialised_g == FALSE)|| (rbi_EEPROMLoad_g == TRUE))
  {
    /*hold the previous values*/
    if(rb_InitLightValCnt_l<100)
    {
      rb_InitLightValCnt_l++;
    }
    else
    {
      l_u8_wr_VALUE_SOLAR_LEFT_SENS(0xFF); /* Init/nicht verfuegbar */
      l_u8_wr_VALUE_SOLAR_RIGHT_SENS(0xFF); /* Init/nicht verfuegbar */
      l_u8_wr_ERR_STATE_SOL_SENS(0);
      l_u8_wr_ERR_STATE_OVER_VOLT(0);
      l_u8_wr_VALUE_LIGHT_AMBIENT(0xFF);
      l_u8_wr_VALUE_LIGHT_FRONT(0xFF);
      l_u8_wr_VALUE_HUD_SENS(0xFF);
    }
  }
  else
  {
    rb_InitLightValCnt_l=0;
    if(l_u8_rd_STATUS_LIGHT_SENS() == TRUE) /*  VDR469   set for error*/
    {
      l_u8_wr_VALUE_SOLAR_LEFT_SENS(0xFF);
      l_u8_wr_VALUE_SOLAR_RIGHT_SENS(0xFF);
      l_u8_wr_ERR_STATE_SOL_SENS(1);
      l_u8_wr_VALUE_LIGHT_AMBIENT(0xFF);
      l_u8_wr_VALUE_LIGHT_FRONT(0xFF);
      l_u8_wr_VALUE_HUD_SENS(0xFF);
    }
    else
    {
      l_u8_wr_ERR_STATE_SOL_SENS(0);
      
          if(((get_rw_Amb_light16bit_g())/16) < 0xFF)
      {
              l_u8_wr_VALUE_LIGHT_AMBIENT((byte)((get_rw_Amb_light16bit_g())/16));
      }
      else
      {
              l_u8_wr_VALUE_LIGHT_AMBIENT(0xFE);     // IR Helligkeit max
      }
      
      if(((get_rw_FW_light16bit_g())/8) < 0xFF) /*VCO_031 correct variable*/
      {
              l_u8_wr_VALUE_LIGHT_FRONT((byte)((get_rw_FW_light16bit_g())/8));
              l_u8_wr_VALUE_HUD_SENS(((get_rw_FW_light16bit_g())/8));
      }
      else
      {
              l_u8_wr_VALUE_LIGHT_FRONT(0xFE); 
              l_u8_wr_VALUE_HUD_SENS(0xFE);
      }
      
      if ((rbi_SoSe_Enabled_g == TRUE) && (TRUE == rbi_SolarValuesInitialised_g))
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
        
        if((rw_SoSe_SunInt_2D_Le_l/2) <= 254)
        { 
          l_u8_wr_VALUE_SOLAR_LEFT_SENS((byte)(rw_SoSe_SunInt_2D_Le_l/2));
        }
        else
        {
          l_u8_wr_VALUE_SOLAR_LEFT_SENS(254) /* Maximum value */
        }
        
        if((rw_SoSe_SunInt_2D_Re_l/2) <= 254)
        {
          l_u8_wr_VALUE_SOLAR_RIGHT_SENS((byte)(rw_SoSe_SunInt_2D_Re_l/2));
        }
        else
        {
          l_u8_wr_VALUE_SOLAR_RIGHT_SENS(254); /* Maximum value */
        }
        
      }
      else
      {
        l_u8_wr_VALUE_SOLAR_LEFT_SENS(0xFF); /* Init/nicht verfuegbar */
        l_u8_wr_VALUE_SOLAR_RIGHT_SENS(0xFF); /* Init/nicht verfuegbar */
      }
    }
    
  }
  //l_u4_wr_LS_Helligkeit_FW_boost(rb_Helligkeitsboost_l);
 
  
   if (l_flg_tst_ERROR_DATA_RLS() )
  {
    
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
    l_flg_clr_ERROR_DATA_RLS();
  }   
 l_u8_wr_SIGNAL_ERROR(0); 
  
  if (l_flg_tst_CLIMATE_DATA() )
  {
    
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
    l_flg_clr_CLIMATE_DATA();
  }
  if (rbi_HumTempComError_g != 0)
  {
    l_u8_wr_WINDSHIELD_HUMIDITY(255);
    l_u8_wr_WINDSHIELD_TEMPERATURE(255);
    l_u8_wr_ERR_STATE_HUM_SENS(1);
    l_u8_wr_ERR_STATE_OVER_TEMP(1);
    
  }
  else
  {
    l_u8_wr_ERR_STATE_HUM_SENS(0);
    if(rw_Temperature_raw_g < 0x2AD) /* The temperature less than -39,5 the tool doesnot support */
    {
      rw_Temperature_Sensor_g = 0x2AD;    
    }
    else if(rw_Temperature_raw_g > 0x3449)/* The temperature greater than 87,5 the tool doesnot support */
    {
      rw_Temperature_Sensor_g = 0x3449;
      l_u8_wr_ERR_STATE_HUM_SENS(1);
    }
    else
    {
      rw_Temperature_Sensor_g = rw_Temperature_raw_g;
    }    
    if (rb_Humidity_g == cw_HUMTEMP_INIT_g)    /* init?*/ /*VCO_061 name hase changed*/
    {
      l_u8_wr_WINDSHIELD_HUMIDITY(252);/* not ready */
      l_u8_wr_ERR_STATE_HUM_SENS(0);
    }    
    
    else
    {  if(rb_Humidity_raw_g <= 200)
    {      
      l_u8_wr_WINDSHIELD_HUMIDITY(rb_Humidity_raw_g);
    }
    }
    
    /*
    in ECU (sensor) 
    Temp is - 46.85 to 128.85 
    hex is : 0 to   0x44A2 
    the resolution is 0.01 
    
    Assume  = X 
    
    in tool the formula is 
    0:not valid 
    1023: failure 
    valid is from 1 to 1000 ( -39.5 to 60.4)  :   
    Assume  = Y 
    
    that is 0.1* raw - 39.6 
    
    
    Resolution mismatch is 0.1 
    
    Y = X 
    
    Y - 39.5 = X- 46.85 
    
    Y = X - 7.25   in Physical relation 
    
    Y = X / 10  - 72   Hex value  a) 
    
    Eg Assume that X is 60.4  equivalent hex is 10725 
    
    According to above eq a)  10725 / 10  - 73 =>  1000  which is 60.4 in Y
    or
    (X-725)/10
    
    */

    
    if(rw_Temperature_g == cw_HUMTEMP_INIT_g)
    {
      l_u8_wr_WINDSHIELD_TEMPERATURE(252);/* not ready */
      l_u8_wr_ERR_STATE_OVER_TEMP(0);
    }
    else
    {   
      if(((rw_Temperature_Sensor_g-685)/50) <= 250)
      {
        l_u8_wr_WINDSHIELD_TEMPERATURE(((rw_Temperature_Sensor_g-685)/50));
      }
      else
      {
        l_u8_wr_ERR_STATE_OVER_TEMP(1);
        l_u8_wr_WINDSHIELD_TEMPERATURE(253);/*Value exceeds limit*/
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
  
  // init unused bits to 1
  byte rb_Index_l;
  static const byte LinMsgDefault_CLIMATE_DATA[8] = {255,255,255,255,255,255,255,255};    /* 0x05"CLIMATE_DATA" */
  static const byte LinMsgDefault_RAIN_LIGHT_DATA[8] = {255,255,255,0,60,0,0,0};    /* 0x0B"RAIN_LIGHT_DATA" */
  static const byte LinMsgDefault_SOLAR_DATA[8] = {255,255,255,255,255,255,255,255};    /* 0x12"SOLAR_DATA" */
  static const byte LinMsgDefault_ERROR_DATA_RLS[8] = {255,255,255,255,255,255,255,255};    /* 0x00"ERROR_DATA_RLS" */
  
  for(rb_Index_l = 0;rb_Index_l < 8;rb_Index_l++)
  {
    RAIN_LIGHT_DATA._c[rb_Index_l] = LinMsgDefault_RAIN_LIGHT_DATA[rb_Index_l];
  };
  
  for(rb_Index_l = 0;rb_Index_l < 2;rb_Index_l++)
  {
    ERROR_DATA_RLS._c[rb_Index_l] = LinMsgDefault_ERROR_DATA_RLS[rb_Index_l]; 
    CLIMATE_DATA._c[rb_Index_l] = LinMsgDefault_CLIMATE_DATA[rb_Index_l];
    SOLAR_DATA._c[rb_Index_l] = LinMsgDefault_SOLAR_DATA[rb_Index_l]; 
  };
  
  rw_AfterRSWipeCounter_mg = 50000;
  rw_AfterRSWipeCounterAlt_mg = 50000;
  rw_AfterWWSWipeCounter_mg = 50000;          //Direktbitdelay bei Kl15 Aus hochsetzen!
  sci_init(rb_LIN_State_l);
  rbi_RealParkContact_g = TRUE;
  rbi_ParkPosition_g = TRUE;
  rb_PotiStageFromBox_g = 3; /*VDR_408 use init value*/
  rb_AnyErrorCounterDebounce_mg = 200;
  
}                                              //ApplLinInit


__callt void ApplLinSlavePreCopy(byte rb_MessageID_l)    /* callt function (faster */
{
  if(rb_MessageID_l == (rb_IDRLSs_01_g & 0x3F))
  {
    l_bool_wr_COMM_ERROR(rbi_latched_ResponseError_mg);
    rbi_latched_ResponseError_mg = FALSE;
  }
  else
  {
    if((rb_MessageID_l == (rb_IDFSs_01_g & 0x3F))&&(rb_RSControlFlags_g == 0x18))
    {
      /* send response error in FS message if only humidity sensor is active */
      l_bool_wr_COMM_ERROR(rbi_latched_ResponseError_mg);
      rbi_latched_ResponseError_mg = FALSE;
    } 
  }
}

static void LIN_CalculateFixIntervalTime(void)
{
  word rw_temporary_WH_State_l;  
  static word rw_WH_State_l_old_mg;
  
  /*interval times for rain sensor below 4kmph inactive in 100ms*/
  static const byte cab_FixIntervtim_bel4kmph_mg[4] = {240,160,80,40}; 
  /*interval times for rain sensor above 200kmph inactive in 100ms*/
  static const byte cab_FixIntervtim_a200kmph_mg[4] = {70,40,20,10};   
  /*interval times for rain sensor above 200kmph inactive in 100ms*/
  static const byte cab_FixIntervtim_Offsett_mg[4] = {190,120,60,30};  
  /*interval times for rain sensor above 200kmph inactive in 100ms*/
  static const byte cab_FixIntervtim_Devider_mg[4] = {10,15,30,60};
  /* Bits 0-3 WH_Intervallstufe, Bit 4: WH_Interval , Bit 5:WH_WischerStufe1, Bit 6:WH_WischerStufe2,
  Bit 7: WH_Frontwaschen, Bit 8: Deaktivierung_RS,  */
  static byte rb_RainSensitivityFixdInt_mg;
  static byte tempFixInt_l;
  

  if(l_u8_rd_RAIN_SENSITIVITY() != 0x0F)
  {
    rb_RainSensitivityFixdInt_mg = l_u8_rd_RAIN_SENSITIVITY();
    
    tempFixInt_l = l_u8_rd_RAIN_SENSITIVITY()/2;
    
    if (tempFixInt_l > 3)
    {
      tempFixInt_l = 3;
    }
    else
    {}
  }
  
  /*VCO_192*/
  rw_temporary_WH_State_l = ((rb_RainSensitivityFixdInt_mg) | ((l_u8_rd_WIPER_CONTROL() == AUTO_MODE) << 4) | 
                             ((l_u8_rd_WIPER_CONTROL()== MANUAL_LOW_SPEED) << 5) | ((l_u8_rd_WIPER_CONTROL()== MANUAL_HIGH_SPEED) << 6) | 
                               ((l_u8_rd_WIPER_CONTROL()== FRONT_WASH) << 7) );
      
  if(rbi_MasterMessageRecieved_g == TRUE)
  {
    if((rw_WH_State_l_old_mg != rw_temporary_WH_State_l) && ((rw_WH_State_l_old_mg & 0xFF)>0) && 
       ((rbi_LINRainsensorDisabled_g == TRUE)|| ((rbi_RainsensorDisabled_g == TRUE) && (l_u8_rd_STATE_IGNITION() == 10))) )
    {
      rbi_Relase_FixedIntervalTime_g = TRUE;  /* clear this after 10s IGN Off set it after change on signals see_682 doors Req */
    }
    
  }
  rw_WH_State_l_old_mg = rw_temporary_WH_State_l;
  
  /* wipe Decision and Set!*/
  if((((rbi_LINRainsensorDisabled_g == TRUE) || ((rbi_RainsensorDisabled_g == TRUE)&&(rbi_EEPROMLoad_g == FALSE))) 
      && (l_u8_rd_STATE_IGNITION() == 10))&&
     ((rbi_Relase_FixedIntervalTime_g == TRUE) || ((rb_Release_IntervalMarker_g == 0x0A)
                                                   &&((rb_Release_IntervalMarker_Update_g&0xA0)!= 0xA0))))
  {
    if((l_u8_rd_WIPER_CONTROL() == AUTO_MODE))
    {
      if(rb_speed_in_kmh_g <= 4)
      {
        rb_intervaltime_rainSensorOff_g = cab_FixIntervtim_bel4kmph_mg[(tempFixInt_l)];
      }
      else if(rb_speed_in_kmh_g < 200)
      {
        rb_intervaltime_rainSensorOff_g = cab_FixIntervtim_Offsett_mg[(tempFixInt_l)]
          -(byte)((((word)(rb_speed_in_kmh_g)*6)/cab_FixIntervtim_Devider_mg[(tempFixInt_l)]));
      }
      else
      {
        rb_intervaltime_rainSensorOff_g = cab_FixIntervtim_a200kmph_mg[(tempFixInt_l)];
      }
      if((rw_AfterWWSWipeCounter_mg/10) >= rb_intervaltime_rainSensorOff_g) /*VCO_031 correct rainlight*/
      {
        //           rb_TunnelWipeTimeOut_mg = 0;
        rbi_TunnelWipe_mg = TRUE;
      }
      /* Update marker in the EEPROM to indicate there is release interval is activated */
      /* donot update if LIN going to sleep Release_IntervalMarker is set to 0 */
      if(rw_NoCommunicationCounter_g <= (CW_LIN_E2_IDLE_TIMOUT - 3) )
      {
        rb_Release_IntervalMarker_Update_g = 0x0A;
        rbi_Write_ReleaseMarker_g = TRUE;
      }
      
    }
    else
    {
      /* interval fuer Ampelrueckschaltung*/
      if((l_u8_rd_WIPER_CONTROL() == MANUAL_LOW_SPEED)||(l_u8_rd_WIPER_CONTROL() == MANUAL_HIGH_SPEED))  
      {
        if((rw_AfterWWSWipeCounter_mg>>4) >= cb_FOUR_SECOND_DELAY_mg)
        {
          //           rb_TunnelWipeTimeOut_mg = 0;
          rbi_TunnelWipe_mg = TRUE;
        }
      }
    }
  }
}

