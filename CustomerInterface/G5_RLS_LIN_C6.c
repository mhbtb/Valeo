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


/*12.05.2015 VDR_878    NB     ADC Error shall be removed from the LS error and included only for RS_error */
/*28.08.2015 VCO_268    SP     Cleanup the LIN modules  */
/*18.09.2015 VCO_274    NB     Audi C6:Synchronise the LIN interface file for audi B8 and C6 project   */
/* 21.09.2015   VDR_909    NB     Fixed interval operation not started after lapsing the ignition delay         */ 
/*                                and activating again                                                          */
/*02.10.2015 VDR_911    SP      HammingErr shld be part of RS_Error/LS_Error and shld not be used for Active Err*/
/*30.05.2016 VDR_983    NB      Sporadic illegale instruction reset in the startup                              */
/*************************************************************************
**                   Common and module include-file                     **
**************************************************************************/

#include "ior5f109be.h"
#include "G5_projectDefs.h"
#include "G5_E2ProjectConfig.h"

#include "G5_Appli_main.h"
#define _RLS_LIN_c_         /*Define for Single include of Global Header rls_linst.h*/
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

#include "G5_IRlight.h"
#include "G5_DippedBeam_sr.h"
#include "G5_ASIC_Control.h"
#include "G5_ASIC_Control_sr.h"
/** /brief Declarations of modul specific parameters and variables*/
#include "G5_spi_sr.h"

#include "G5_AsicFramesLin.h"

#define rb_HelligkeitSkaling_E2_g  3


/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/
static  byte rb_IgnitionOndelay_mg;
/* PRQA S 3218 7 */ /* <<needed at this level for better debugging>> */
static byte rb_Verglasun_offenDebounce_mg,rb_Verglasun_ClosedDebounce_mg;

static  word rw_AfterRSWipeCounter_mg;                   /* Time after last wipe from RS*/
static  word rw_AfterRSWipeCounterAlt_mg;                /* Time to the last wipe from RS*/
static  word rw_AfterWWSWipeCounter_mg;                  /* Time after last wipe from WWS*/
static word rw_CommandCloseWindowTimout_mg;
static word rw_WipeCommandTimOut_mg;                     /*timout for requested wipe*/


/* PRQA S 3218 7 */ /* <<needed at this level for better debugging>> */
static const byte cab_AUDI_SenMapping[16] = {0,0,0,2,2,2,2,2,3,3,3,5,5,5,5,3};
/* PRQA S 3218 7 */ /* <<needed at this level for better debugging>> */
static const byte cab_PotistageMapping_mg[8] = {4,5,6,7,3,2,1,0}; /*mapping for potistages!*/


static const word caw_DeppressedParkDelayTable_g[4] = {500,1000,1500,2000};

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
static byte LIN_ScaleBrightness (void); /*Function to scale the brightness for the bus*/
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
  byte rb_PotiStageFromBoxTemp_l;
  static byte rb_AfterResetCounter_l;

  if (l_bool_rd_Verglasung_offen()==TRUE )
  {
    if (rbi_Ignition_g == FALSE) /* VCO_028*/
    {
      if (rb_Verglasun_offenDebounce_mg < 0xff)
      {
        rb_Verglasun_offenDebounce_mg ++;
      }
    }
    rb_Verglasun_ClosedDebounce_mg = 0;
  }
  else
  {
    if (rb_Verglasun_ClosedDebounce_mg < 0xff)
    {
      rb_Verglasun_ClosedDebounce_mg ++;
    }
    rb_Verglasun_offenDebounce_mg = 0;
  }
  if (l_flg_tst_BCM1s_01())               /*Master Request?*/
  {
    l_flg_clr_BCM1s_01();                 /*loesche flag*/
    rbi_LightSensitivityRecieved_g = TRUE; 
    rbi_ConnectedToMaster_g = 1;            // set connected to Master Bit
    
    if (l_bool_rd_LSS_Frontwaschen() == TRUE)   /* Waschpumpe aktiv?*/
    {
      rbi_WashingActive_g = TRUE;             /* Washing aktiv bit setzen*/
    }
    else
    {
      if(rbi_ParkPosition_g == TRUE)          /* In Parkposition ?*/
      {
        rbi_WashingActive_g = FALSE;               /* Clear Washing aktive bit*/
      }
    }
    
     /* ignore ignition off if speed higher 4km/h*/
    if((l_bool_rd_Klemme_15() == TRUE)||(rb_speed_in_kmh_g > cb_IGNORE_IGNITION_SPEED)) /*VCO_083*/
    {
      rbi_Ignition_g = TRUE;
      rw_StandbyTimeOutCnt_g = 0;
      rbi_WindowOpenIgnitionWasOn_g = TRUE;   /*store window state at ignition on to off!*/
      rw_IgnitionOffDelay_mg = 0;
      if(rb_IgnitionOndelay_mg < 250)
      {
        rb_IgnitionOndelay_mg++;
      }
      
      if ((rbi_RainsensorDisabled_g == FALSE)&&(rb_AfterResetCounter_l> 10))
      {
        if((l_bool_rd_LSS_Intervall() != FALSE) 
           || (l_bool_rd_LSS_WischerStufe_1() != FALSE)
           || (l_bool_rd_LSS_WischerStufe_2() != FALSE) 
           || (rbi_RainsensorAlwaysOn_g != FALSE))
        {
          rbi_AutomaticWipingMode_g = TRUE;            /*Rainsensor always active!*/
        }
        else
        {
          rbi_AutomaticWipingMode_g = FALSE;           /*Rainsensor off!*/
        }
      }
      else
      {
        rbi_AutomaticWipingMode_g = FALSE;           //Rainsensor off!
      }
      
      
      if (l_bool_rd_LSS_Intervall()== TRUE) // copy automatic wiping mode
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
    
    
    if (l_u8_rd_FzgGeschw() < 199)/*Check for max value   speed faster than 200 (255km/h) */
    {
      rb_speed_in_kmh_g  = (byte)(((word)(l_u8_rd_FzgGeschw())*41)>>5); /*recalibrate Data multily by 1,28*/

    }
    else
    {   
if(l_u8_rd_FzgGeschw() == 0xFF)
    {
      rb_speed_in_kmh_g  = 75;                           /* set speed to (75 km/h)*/
    }
    else
    {
    	if(l_u8_rd_FzgGeschw() < 0xFE)
        {
          rb_speed_in_kmh_g  = 255;                           // set speed to (255 km/h)
        }
      }
    }
    
if(l_u8_rd_FzgGeschw() != 0xFF)
    {
      if(rb_speed_in_kmh_g>=10)
      {
        rbi_speedWasAbove10kmh_g = TRUE;
      }
    }

    if (l_u8_rd_LSS_Int_Time() > 0) /*VDR_408 do not update if init*/
    {
      rb_PotiStageFromBoxTemp_l = cab_AUDI_SenMapping[l_u8_rd_LSS_Int_Time()];
      if(rb_PotiStageFromBoxTemp_l>7)
      {
        rb_PotiStageFromBox_g = 7;
      }
      else
      {
        rb_PotiStageFromBox_g = rb_PotiStageFromBoxTemp_l ;
      }
    }
    
     rb_LIN_SensitivityShift_g = 7;       //adaptation Variable for sensitivity factor 
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
        if ((l_bool_rd_Verglasung_offen()==FALSE)||(rw_CommandCloseWindowTimout_mg > 6000))
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

    
 

  rb_LSPotiStage_g = cab_PotistageMapping_mg[rb_LightSensorCoding_g];                   // set LSS to 3

  
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
  
  if (l_flg_tst_WWSs_01())                  //Wischermotor request?
  {
    l_flg_clr_WWSs_01();                  //loesche flag
    rbi_RealParkContact_g = l_bool_rd_Parklagensignal();
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
  }
  
  if ((rb_WiperSpeed_g > 0)&&(l_bool_rd_Parklagensignal()== TRUE))
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
  
  
  if (((l_bool_rd_LSS_Intervall() == FALSE)
       && (LSS_WischerStufe_1 == FALSE)
         && (LSS_WischerStufe_2 == FALSE)
           && (l_bool_rd_Parklagensignal()== TRUE))
      ||(rw_WipeCommandTimOut_mg > cw_CLEARWIPE_DELAY_s))
  {
    if ((rb_WiperSpeed_g > 0)||(rbi_ParkPosition_g == FALSE))
    {
      if(rb_parkpositioncounter_s>10)            // Parkpositioncounter groesser 10
      {
        rbi_ParkPosition_g = FALSE;                 // loesche bit fuer Parkposition
      }
      rb_parkpositioncounter_s++;             // inkrementiere Parkpositionscounter
    }
    
    if (rb_parkpositioncounter_s > (cab_WiperMotorRunntime_mg[rb_WiperSpeed_g]))
    {
      rw_WipeCommandTimOut_mg = 0;
      rbi_ParkPosition_g = TRUE;               // loesche bit fuer Parkposition
      rb_parkpositioncounter_s = 0;            //
    }
  }
  else
    
    
  {


    rbi_WiperStarted_g = FALSE;

    if (l_bool_rd_Parklagensignal() == TRUE)        // In Parklagensignal ?
    {
      if (rbi_ParkPosition_g == FALSE)
      {
        rb_parkpositioncounter_s=0;                 // Parkpositioncounter zuruecksetzen
      }
      else
      {
        if (rb_parkpositioncounter_s < 255)
        {
          rb_parkpositioncounter_s++;
        }
      }
      rbi_ParkPosition_g = TRUE;                     // Parkposition True
    }
    else
    {
      rb_LimitMemomryNoWiperReaction_g = FALSE;
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
  rbi_WischerWendelage_g = l_bool_rd_Wendelagensignal();            // In Wendelagensignal ?
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
  static byte rb_OutOffParkCounter_mg;
  static byte rb_RLS_Botschaft_s;
  static byte rb_underVoltageTimer_s;
  static byte rb_TunnelWipeTimeOut_mg;
  static byte rb_InitLightValCnt_l=100;
  byte rb_AnyErrorCounterDebounce_l; 
  byte rb_TempLightOn_l;
  byte rb_TempLightOnInv_l;
  word rw_tunnelWischVerzoegerung_l=(((word)CB_TUNWISCHVERZ_MG)*100);
  word rw_tunnelWischAktivierung_l=(((word)CB_TUNWISCHAKTIV_MG)*100);
  static byte rb_tunnelWipeActive_g;
  
  Check_StartupActiveErrors();
  
  LIN_CalculateFixIntervalTime();
  
  if ((rb_IgnitionOndelay_mg<50)/*||(rbi_ConnectedToMaster_g = 0)*/)
  {
    rw_rain_intensitiy_g = 0;
    rw_AfterRSWipeCounter_mg = 50000;
  }
  if (rbi_RealParkContact_g == FALSE)     //Auserhalb vom Parkkontakt
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
  
  
  if(l_flg_tst_RLSs_01())                            // pruefen ob eigene Nachricht korrekt empfangen wurde
  {
    l_flg_clr_RLSs_01() ;                          // loeschen des Pruefflags
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
    rb_RLS_Botschaft_s++;                          // Incrementierung des Botschaftszaeheler
    
    rbi_oneTimeAnswerd_g = TRUE;
  }
  
   //----------LSRLS_2!!!!!!!!!!
  if (l_flg_tst_LsRLS_2())                            // prüfen ob eigene Nachricht korrekt empfangen wurde
  {
    l_flg_clr_LsRLS_2() ;                          // löschen des Prüfflags
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
  }
   
  l_u8_wr_RLS_Botschaftszaehler(rb_RLS_Botschaft_s); // Botschaftszähler übergeben
  
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
    l_u8_wr_Wischergeschwindigkeit(1);
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
    l_u8_wr_Wischergeschwindigkeit(1);
  }
  else
  {
    /*VCO_166 wiper speed limited to 1, when interval is not selected*/
    if(((l_bool_rd_LSS_WischerStufe_1()==TRUE) || (l_bool_rd_LSS_WischerStufe_2()==TRUE))&&(rb_WiperSpeed_g > 1))
    {
      l_u8_wr_Wischergeschwindigkeit(1);   // Wischergeschwindigkeit uebergeben
      l_bool_wr_RS_Schwall(0);            // Schwall bit setzen
    }
    else
    {
      l_u8_wr_Wischergeschwindigkeit(rb_WiperSpeed_g);   // Wischergeschwindigkeit uebergeben
      /*VDR_859 Interval wipe in manual mode for no rain variant*/
      /*is RS functionality enabled?*/
#ifndef _NO_RAIN_
      l_bool_wr_RS_Schwall(rbi_RSWipeFastDmd);            // Schwall bit setzen
#else
      l_bool_wr_RS_Schwall(0);            // Schwall bit setzen
#endif/*_NO_RAIN_*/
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
    l_bool_wr_RS_Err((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_RainS_Error1_g != 0)||(rbi_HammingError_g != 0));
  }
  else
  {
    /*only RAM/ROM error and RS version error*/
    l_bool_wr_RS_Err(((rb_RS_LS_Error1_g&0x3) != 0)||(TRUE==bi_RS_VariantError_g)||(rbi_HammingError_g != 0));
  }
  
#else
  /*only RAM/ROM error and RS version error*/
  l_bool_wr_RS_Err(((rb_RS_LS_Error1_g&0x3) != 0)||(TRUE==bi_RS_VariantError_g)||(rbi_HammingError_g != 0));
#endif /*_NO_RAIN_*/
    
    /* setze Lichtsensor Fehler nach SRS*/
    /* VDR 757 - SM200 */
    /*SM240*/
  l_bool_wr_LS_Err((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(rbi_HammingError_g != 0)||(rbi_CRC_ChangedByDiagnostic_g));

  
  /* PRQA S 3415, 4112 1 */ /* << Getter functions must not have side effects >>*/
  if ((((((IS_LS_ANY_ERRORCOUNTER()) > 0))||((l_bool_rd_LS_Err()) > 0))||(((rbi_UnderVoltage_g) == TRUE))
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

  l_bool_wr_RLS_Adaptierung_Err(0); //Error in EEPROM 
  rb_AnyErrorCounterDebounce_l = rb_AnyErrorCounterDebounce_mg; 
  
  if(l_bool_rd_LS_Err() == TRUE)
  {
    rb_TempLightOn_l = 1;
  }
  /*VCO_50*//*VDR_129 use Sensitivity Treatment*/
  else if(((uF_modi_lightsens_g.AllBit & 0x2F)>0)||(rbi_InternalResetOccured_g > 0)||(rbi_Regulation48LightOnFlag_g !=0))
  {
    rb_TempLightOn_l = TRUE;
    l_bool_wr_Dunkel_Hell(TRUE);                                                  // set bit for darkness
  }
  /*VDR_129 use Sensitivity Treatment*/
  else if((((rbi_Freewaylight_enabled_g==TRUE))&& (rbi_FastHighwayMode_g == TRUE))
          ||(((rbi_modi_lightsens_rain_g == TRUE)&& (rbi_RainLight_enabled_g == TRUE))))
  {
    rb_TempLightOn_l = TRUE;
    l_bool_wr_Dunkel_Hell(FALSE);                                                 // clear bit for darkness
  }
  else
  { /* PRQA S 3415 1 */ /* << Swapping expressions not feasible for performance >>*/
    if ((rb_AnyErrorCounterDebounce_l ==0)&&(get_rb_LightVetoCounter_g()==0)) /*VCO_093 use Veto of Lightsensor*/
    {
      rb_TempLightOn_l = FALSE;
    }
    else
    {
      rb_TempLightOn_l = l_bool_rd_Licht_ein() ; /* stay in old light mode and do */
    }
    l_bool_wr_Dunkel_Hell(FALSE);                                                  // clear bit for darkness
  }
  
  
  /*VDR_671 remove singularity*/
  if(l_bool_rd_LS_Err() != FALSE)
  {
    rb_TempLightOnInv_l = FALSE;
  }
  /*VCO_50*//*VDR_129 use Sensitivity Treatment*/
  else if(((uF_modi_lightsens_inv_g.AllBit & 0x2F)< 0x2F)
          ||(rbi_InternalResetOccured_g != 0)
            ||(rbi_Regulation48LightOnFlag_g >0))
  {
    rb_TempLightOnInv_l = FALSE;                                                  // set bit for darkness
  }
  /*VDR_129 use Sensitivity Treatment*/
  else if((((rbi_Freewaylight_enabled_g != FALSE)) && (rbi_FastHighwayMode_g != FALSE))
          ||(((rbi_modi_lightsens_rain_inv_g == FALSE)&& (rbi_RainLight_enabled_g != FALSE))))
  {
    rb_TempLightOnInv_l = FALSE;
  }
  else
  {     /*VCO_093 use Veto of Lightsensor*/
    /* PRQA S 3415 1 */ /* << Swapping expressions not feasible for performance >>*/
    if ((rb_AnyErrorCounterDebounce_l  != FALSE)||(get_rb_LightVetoCounter_g() != FALSE)) 
    {
      rb_TempLightOnInv_l = l_bool_rd_Licht_ein_invers() ; /* stay in old light mode and do */
    }
    else
    {
      rb_TempLightOnInv_l = TRUE; /*signal to switch light off*/
    }
  }
  
  /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
  DISABLE_SCIINTERRUPT();
  l_bool_wr_Licht_ein(rb_TempLightOn_l);                      // Licht ein = TRUE
  l_bool_wr_Licht_ein_invers(rb_TempLightOnInv_l);               // Licht eine invers = FALSE
  /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
  ENABLE_SCIINTERRUPT();
  
  if(((rbi_LightSensorActive_g == TRUE) && (rbi_EEPROMLoad_g == FALSE))&& (rbi_oneTimeAnswerd_g == TRUE))
  {
    l_bool_wr_RLS_Err_Aktiv(TRUE);
  }
  else
  {
    l_bool_wr_RLS_Err_Aktiv(FALSE);
  }
  
  
  
  if (rbi_RainsensorDisabled_g == TRUE)
  {
    l_bool_wr_RS_Direktmodus(0);                                                       // nicht in depressed park bei festem Interval
  }
  else
  {
    if(rw_AfterWWSWipeCounter_mg > caw_DeppressedParkDelayTable_g[rb_delay_depressed_park_pointer_g])
    {
      l_bool_wr_RS_Direktmodus(1);   // Direktmodus Depressed Park bit übergeben
    }
    else
    {
      l_bool_wr_RS_Direktmodus(0);   // Direktmodus Depressed Park bit übergeben
    }
  }
  
  if ((l_bool_rd_RS_Err()==FALSE) && ((rbi_WindowOpenIgnitionWasOn_g == TRUE) && (rbi_Ignition_g== FALSE)) &&((rb_Verglasun_offenDebounce_mg > cb_VERGLSUNG_OPEN_DELAY_mg)&& (rbi_StandbyFunction_enabled_g == TRUE)))
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
    l_bool_wr_Verglasung_schliessen(TRUE);                // setzen von Verglasung Schliessen
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
    l_bool_wr_Verglasung_schliessen(0);             // setzen von Verglasung Schliessen
  }
  
  
  l_bool_wr_RLS_Ueberspannung(rbi_OverVoltage_g);
  
  if (rbi_UnderVoltage_g == TRUE)  //undervoltage, Overvoltage ?
  {
    if (rb_underVoltageTimer_s>249)                              // undervoltagetimer > 249 -> 2500 ms abwarten
    {
      rbi_LongUnderVoltage_g = 1;         // setze Fehlerbits
      l_bool_wr_RLS_Unterspannung(rbi_UnderVoltage_g);         // setze Fehlerbits
    }
    else
    {
      rb_underVoltageTimer_s++;                                // inkrementiere undervoltagetimer
      l_bool_wr_RLS_Unterspannung(0);                          // lösche Fehlerbits
    }
  }
  else
  {
    rb_underVoltageTimer_s=0;             // loesche Timer
    rbi_LongUnderVoltage_g = 0;
    l_bool_wr_RLS_Unterspannung(0);                              // lösche Fehlerbits
  }
  
  l_u8_wr_Helligkeit (LIN_ScaleBrightness());
  
  l_bool_wr_Adaptierung_Err_Aktiv(rbi_RainSensorEnable);
  
  
  if ((rw_rain_intensitiy_g>>10)>7)                               // Regenmenge zu hoch ?
  {
    l_u8_wr_Regenmenge(7);                                     // Anschlag
  }
  else
  {
    l_u8_wr_Regenmenge(rw_rain_intensitiy_g>>10);               //schreib egeschätzte Regenmenge
  }
  

  
  if(((rbi_LightValuesInitialised_g == FALSE)|| (rbi_EEPROMLoad_g == TRUE)))
  {
    /*hold the previous values*/
    if(rb_InitLightValCnt_l<100)
    {
      rb_InitLightValCnt_l++;
    }
    else
    {
      l_u8_wr_Helligkeit_IR(0xFE);     // IR Helligkeit Init/nicht verfügbar
      l_u16_wr_Helligkeit_FW(0x03FE);  // FW Helligkeit Init/nicht verfügbar
    }
  }
  else
  {
    rb_InitLightValCnt_l = 0;
    if(l_bool_rd_LS_Err() == TRUE)
    {
      l_u8_wr_Helligkeit_IR(0xFF);     // IR Helligkeit Fehler
      l_u16_wr_Helligkeit_FW(0x03FF);  // FW Helligkeit Fehler
    }
    else
    {
      if(rb_IrLightDiv8_g < 0xFD)
      {
        l_u8_wr_Helligkeit_IR(rb_IrLightDiv8_g);
      }
      else
      {
        l_u8_wr_Helligkeit_IR(0xFD);     // IR Helligkeit max
      }
      
      if(get_rw_FW_light16bit_g() < 0x03FD)
      {
        l_u16_wr_Helligkeit_FW(get_rw_FW_light16bit_g());
      }
      else
      {
        l_u16_wr_Helligkeit_FW(0x03FD);   // FW Helligkeit max
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
  byte rb_Index_l;
  static const byte LinMsgDefault_RLSs_01[4] = {0,2,0,0};    /* 0x22"RLSs_01" */
  static const byte LinMsgDefault_LsRLS_2[3] = {0,0,0};    /* 0x23"LsRLS_2" */

  rb_Index_l = 0;
  do
  {
    RLSs_01._c[rb_Index_l] = LinMsgDefault_RLSs_01[rb_Index_l];
    rb_Index_l++;
  } while (rb_Index_l < 4);
    
  rb_Index_l = 0;
   do
  {
    LsRLS_2._c[rb_Index_l] = LinMsgDefault_LsRLS_2[rb_Index_l]; /* VCO_219 */
    rb_Index_l++;
  } while (rb_Index_l < 3);
  
  rw_AfterRSWipeCounter_mg = 50000;
  rw_AfterRSWipeCounterAlt_mg = 50000;
  rw_AfterWWSWipeCounter_mg = 50000;          //Direktbitdelay bei Kl15 Aus hochsetzen!
  sci_init(rb_LIN_State_l);
  rbi_RealParkContact_g = TRUE;
  rbi_ParkPosition_g = TRUE;
  rb_PotiStageFromBox_g = 3; /*VDR_408 use init value*/
  rb_AnyErrorCounterDebounce_mg = 200;
  
}                                              //ApplLinInit

__callt void ApplLinSlavePreCopy(byte rb_MessageID_l)
{
    if(rb_MessageID_l == (rb_IDRLSs_01_g & 0x3F))
  {
    l_bool_wr_RLS_Kommunikation(rbi_latched_ResponseError_mg);
    rbi_latched_ResponseError_mg = FALSE;
  }

}

/**************************************************************************
  Syntax   : void  LIN_ScaleBrightness(void)
  Object   : LIN_ScaleBrightness()
  Parameters : none
  Return  : none
  Calls   : in CopyRLSData modul
***************************************************************************
  Inputs validation conditions:
  none
***************************************************************************
  Pseudo-code : Scalierung des Helligkeitswerts
**************************************************************************/

byte LIN_ScaleBrightness(void)
{
word rw_Helligkeit_temp_l;

#ifdef FW_RAINER
    if (rb_IrLightDiv8_g > rb_FwLight_g)
#endif
    {
           rw_Helligkeit_temp_l = (rb_IrLightDiv8_g);                       //rb_IRLight_low_g
    }
#ifdef FW_RAINER
    else
    {
          rw_Helligkeit_temp_l = (rb_FwLight_g );                       //rb_IRLight_low_g
    }
#endif
if (rbi_VW_BritghtnessScaling_g == TRUE)
{
    rw_Helligkeit_temp_l = rw_Helligkeit_temp_l/3; // scale for VW _ Tuareg SWA
}
    rw_Helligkeit_temp_l = (rw_Helligkeit_temp_l * (rb_HelligkeitSkaling_E2_g)>>(2+cb_BRIGHTNESSSCALING_FAKT_s));
    if (rw_Helligkeit_temp_l > 0)
    {
            rw_Helligkeit_temp_l --;
    }
    if (rw_Helligkeit_temp_l > CB_BRIGHTNESS_MAX_VALUE_s)
    {
      rw_Helligkeit_temp_l = 0x07;
    }
    return ((byte)(rw_Helligkeit_temp_l));
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
  
  /*VCO_192*/
  rw_temporary_WH_State_l = ((l_u8_rd_LSS_Int_Time()) | (l_bool_rd_LSS_Intervall() << 4) | 
                             (l_bool_rd_LSS_WischerStufe_1() << 5) | (l_bool_rd_LSS_WischerStufe_2() << 6) | 
                               (l_bool_rd_LSS_Frontwaschen() << 7));
 if(rbi_MasterMessageRecieved_g == TRUE)
 {
   if((rw_WH_State_l_old_mg != rw_temporary_WH_State_l) && ((rw_WH_State_l_old_mg & 0x00FF)>0) && 
      (((rbi_RainsensorDisabled_g == TRUE) && (l_bool_rd_Klemme_15() == TRUE))) )
   {
     rbi_Relase_FixedIntervalTime_g = TRUE;  /* clear this after 10s IGN Off set it after change on signals see_682 doors Req */
   }
 }
  rw_WH_State_l_old_mg = rw_temporary_WH_State_l;
  
  /* wipe Decision and Set!*/
  if(((((rbi_RainsensorDisabled_g == TRUE)&&(rbi_EEPROMLoad_g == FALSE))) && (l_bool_rd_Klemme_15() == TRUE))&&
     ((rbi_Relase_FixedIntervalTime_g == TRUE) || ((rb_Release_IntervalMarker_g == 0x0A)&&((rb_Release_IntervalMarker_Update_g&0xA0)!= 0xA0))))
  {
    if(l_bool_rd_LSS_Intervall() == TRUE)
    {
      if(rb_speed_in_kmh_g <= 4)
      {
        rb_intervaltime_rainSensorOff_g = cab_FixIntervtim_bel4kmph_mg[(l_u8_rd_LSS_Int_Time()>>2)];
      }
      else if(rb_speed_in_kmh_g < 200)
      {
        rb_intervaltime_rainSensorOff_g = cab_FixIntervtim_Offsett_mg[(l_u8_rd_LSS_Int_Time()>>2)]
          -(byte)((((word)(rb_speed_in_kmh_g)*6)/cab_FixIntervtim_Devider_mg[(l_u8_rd_LSS_Int_Time()>>2)]));
      }
      else
      {
        rb_intervaltime_rainSensorOff_g = cab_FixIntervtim_a200kmph_mg[(l_u8_rd_LSS_Int_Time()>>2)];
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
      if((l_bool_rd_LSS_WischerStufe_1() == TRUE)||(l_bool_rd_LSS_WischerStufe_2() == TRUE)) 
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
