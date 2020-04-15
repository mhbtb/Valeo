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
/* 29.09.09  VDR_362  FS    Implement wipe cancelg when 4 seconds wiper has not moved*/
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
#define cw_DEWPOINT_MAX_mg        (1395)     /*VDR_154 change of max value from 1022 to 1000*/
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

void StandByMode(void);
void VoltageDetect(void);
void SendDefault(void);

static byte rb_Verglasun_offenDebounce_mg,rb_Verglasun_ClosedDebounce_mg;
static word rw_CommandCloseWindowTimout_mg;
static byte rb_KL15_mg;

static word rw_AfterRSWipeCounter_mg;                   // Time after last wipe from RS
static word rw_AfterRSWipeCounterAlt_mg;              //Time to the last wipe from RS
static word rw_AfterWWSWipeCounter_mg;                  // Time after last wipe from WWS
static word rw_WipeCommandTimOut_mg;                    //timout for requested wipe
static  byte rb_IgnitionOndelay_mg = 0;


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
  byte Standby_Switch;
  byte rb_Kodierbyte0_Update_g;
  
/***********************Add the Auto_Close_Window Function in Rain Condition*************************/   
#ifdef CS_STANDBY  
  rb_Kodierbyte0_Update_g = rb_Kodierbyte0_g;
  Standby_Switch = l_u8_rd_L_RLS_ModeEnableReserved();                      //0=no change 1=off 2= on 
  if((Standby_Switch > 0) && (Standby_Switch < 3))
  {                                                                 //If it is not the same statue as previous ,then write the different value into EEPROM
    if(rbi_StandbyFunction_enabled_g != (Standby_Switch - 1))
    {
      if((Standby_Switch - 1) > 0)                                  //StandBy Mode on
      {
        rb_Kodierbyte0_Update_g |= 0x04; 
      }
      else if((Standby_Switch - 1) == 0)                            //StandBy Mode off
      {
        rb_Kodierbyte0_Update_g &= 0xFB; 
      }
      rab_EEPROM_Bytes_toWrite_g[0] = rb_Kodierbyte0_Update_g;
      rw_EEPROM_Address_to_Write_g = cw_EEPROM_CODING_ADDRESS_g + 2; /*set adress to write*/
      rb_I2C_EEPROM_bytesToWrite_g = 1;                              /*set number of bytes to 1*/
      rbi_EEPROMBytesToWrite_g = TRUE;
      rbi_EEPROMBytesWritten_g = FALSE;         
    }   
  }
   
  if (l_u8_rd_L_All_Wdw_ClosedReserved()== 0)                        /*Window Open*/
  {
    if (rbi_Ignition_g == FALSE)                                     /* VCO_028*/
    {
      if (rb_Verglasun_offenDebounce_mg < 0xff)
      {
        rb_Verglasun_offenDebounce_mg ++;
      }
    }
    rb_Verglasun_ClosedDebounce_mg = 0;
  }
  else if(l_u8_rd_L_All_Wdw_ClosedReserved() == 1)
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

  if(l_flg_tst_WMMLin1Fr01())
  { 
    l_flg_clr_WMMLin1Fr01();
    rbi_ConnectedToMaster_g = 1;
    rbi_RealParkContact_g = !(l_bool_rd_WiprInWipgAr());        // wiper position
  }
  
  if(l_flg_tst_BCMLin1Fr02())
  { 
    l_flg_clr_BCMLin1Fr02();
    rw_NoCommunicationCounter_g = 0;                                 // reset no communication counter
    rbi_ConnectedToMaster_g = 1;                                     // set connected to Master  
    rbi_LightSensitivityRecieved_g = TRUE;    
        
    rb_speed_in_kmh_g  = (l_u16_rd_L_BCM_VehicleSpeed()+(l_u16_rd_L_BCM_VehicleSpeed()>>3))/20;// N*0.05625      
    if((l_u16_rd_L_BCM_VehicleSpeed())> 4533)
    {
      rb_speed_in_kmh_g = 255;
    }
    else {}
    
   
    if(l_u16_rd_L_BCM_VehicleSpeed() == 8191)
    {
      rb_speed_in_kmh_g = 0;
    }
    
    if(rb_speed_in_kmh_g >= 10)
    {
      rbi_speedWasAbove10kmh_g = TRUE;
    }
        
    rb_KL15_mg=((l_u8_rd_L_PEPS_PowerModeValidity() & 0x02) 
                && ((l_u8_rd_L_PEPS_PowerMode1() ==1) || (l_u8_rd_L_PEPS_PowerMode1() ==2) || (l_u8_rd_L_PEPS_PowerMode1() ==4)));
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
        if((l_u8_rd_L_BCM_RS_RainSwSts() == 5)                         //automatic
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
      
      if(l_u8_rd_L_BCM_RS_RainSwSts() == 5)                            // copy automatic wiping mode
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

    rb_PotiStageFromBox_g = (l_u8_rd_L_Rain_Sensitivity() > 7)?7:(l_u8_rd_L_Rain_Sensitivity());
    
    if (l_bool_rd_L_BCM_RS_ManWaInfo())                                 /* Washpump activ? 0x5:Front washing*/
    {
      rbi_WashingActive_g = TRUE;                                       /* set Washing activ bit */
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
        if ((l_u8_rd_L_All_Wdw_ClosedReserved()== 1)||(rw_CommandCloseWindowTimout_mg > 6000))
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

  if(    ((l_u8_rd_L_BCM_RS_RainSwSts() != 5)    //auto wiper  xsy 20180523
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
  
  if(l_flg_tst_RS_SENSOR_02())
  {
    l_flg_clr_RS_SENSOR_02() ;
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
  
  RainFunction();                              //Tunnel wiper,auto wiper,rain level, splash mode, rain sonser error
  CheckErrors();                               //Other error signals send in this function
  VoltageDetect();                             //Send high/low voltage error  
  SendDefault();
#ifdef CS_STANDBY
  StandByMode();                               //Auto close window
#endif    
  
  
#if defined (ASIC_TEST)
  CopyRLSDataAsic();
#endif

  rb_WDG_BusTaskCounter_g++;                   //increment test counter for bus
}

/*0x0£ºOFF "WipgSpd0Rpm";
0x1£ºLow speed "WipgSpd40Rpm";
0x2£ºHigh speed "WipgSpd60Rpm";
0x3£ºwipe speed "WipgSpd43Rpm";
0x4£ºwipe speed"WipgSpd46Rpm";
0x5£ºwipe speed "WipgSpd50Rpm";
0x6£ºwipe speed "WipgSpd54Rpm";
0x7£ºwipe speed "WipgSpd57Rpm";
0x8~0xE£ºcurrently not used*/

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
  
  if(l_flg_tst_RS_SENSOR_01())
  {
    l_flg_clr_RS_SENSOR_01() ;
    rbi_ConnectedToMaster_g = 1;                 // set connected to Master   
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

    l_u8_wr_L_RS_WiperAutoSpReq(1);
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
    l_u8_wr_L_RS_WiperAutoSpReq(1);
  }
  else
  {
    if(l_u8_rd_L_BCM_RS_RainSwSts() == 5)
    {
      if(rb_WiperSpeed_g!=0)
      {
        if ((rbi_RSWipeSlowDmd==0)&&(rbi_RSWipeFastDmd==0))
        {
          newWiperSpeedLin = 1; //interval
        }
        else
        {
          if(rb_WiperSpeed_g == 1)
          {
             newWiperSpeedLin = 1;
          }
          else  if(rb_WiperSpeed_g == 7)
          {
             newWiperSpeedLin = 2;
          }
          else
          {
            newWiperSpeedLin = rb_WiperSpeed_g+1;
          }
        }  
      }
      else
      {
        newWiperSpeedLin = 0;
      } 
      if(newWiperSpeedLin > 7)
      {
        newWiperSpeedLin = 7;
      }
      l_u8_wr_L_RS_WiperAutoSpReq(newWiperSpeedLin);   // wiper request
    }
    else
    {
      l_u8_wr_L_RS_WiperAutoSpReq(0); // add 20180604
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
  rbi_modi_lightsens_tunnel_alt_mg = rbi_modi_lightsens_tunnel_g;  
  
#ifndef _NO_RAIN_
  /* VDR_124 set rain intensity to init if rain sensor is off*/
  if(((rbi_OverVoltage_g) || (rbi_LongUnderVoltage_g))||(rbi_AutomaticWipingMode_g==FALSE) || (rbi_WashingActive_g == 1)) 
  {
    l_u8_wr_L_RS_RainfallLevel(0);          
  }
  else if(rbi_RainSensorError > 0)
  {
    l_u8_wr_L_RS_RainfallLevel(0);        
  }
  else if((rw_rain_intensitiy_g>>9)>6)                             
  {
    l_u8_wr_L_RS_RainfallLevel(3);                                
  }
  else if((rw_rain_intensitiy_g>>9)>3) 
  {
    l_u8_wr_L_RS_RainfallLevel(2);  
  }
  else if((rw_rain_intensitiy_g>>9)>1)
  {
    l_u8_wr_L_RS_RainfallLevel(1); 
  }
  else
  {
    l_u8_wr_L_RS_RainfallLevel(0);               
  }
#endif /*_NO_RAIN_*/
  
  if(l_bool_rd_L_RS_RainSensorError()>0)
  {
    l_u8_wr_L_Status_Rain_Sens(0x5);                                                                                    //if RS ERROR then enter to safe mode
  }
  else
  { 
    l_u8_wr_L_Status_Rain_Sens(rbi_RSWipeFastDmd);                                                                      //splash mode
  }   
}


// Those function have not ,so send default value xsy add 20180522
void SendDefault(void)
{
  
  l_u8_wr_L_Light_Switch_Reason(0);
  l_u8_wr_L_Light_Switch_Request(0); 
  l_u8_wr_L_Light_HudBrightnessValue(0);        // hud Init
  l_u8_wr_L_Light_HudBrightnessUnit(0);
  l_u8_wr_L_Value_Solar_Right_Sens(0);         // Init 
  l_u8_wr_L_Value_Solar_Left_Sens(0);          // Init
  l_u16_wr_L_DP_Temp(0);                       //dew point temperature
  l_u8_wr_L_RH_Sens(0);                        //relative Humidity
  l_u16_wr_L_Window_Temp(0);                   //window temperature    

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

  if(rbi_Command_CloseWindows_g == TRUE)               // send close window command
  {
   
     l_u8_wr_L_Sunroof_Win_CloseReqreserved(1); 
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
    l_u8_wr_L_Sunroof_Win_CloseReqreserved(0);
  }
  
  if(rbi_StandbyFunction_enabled_g == TRUE)               //send standby function status
  {
    l_bool_wr_L_RLS_ModeStsreserved(TRUE);
  }
  else if(rbi_StandbyFunction_enabled_g == FALSE)
  {
    l_bool_wr_L_RLS_ModeStsreserved(FALSE);
  }
  else{}
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
 
  
}


#pragma inline=forced
static void CheckErrors(void)
{
 
  l_u8_wr_L_Err_State_Cal_RS(1);   //custorm defined, but we do not support
  l_u8_wr_L_Err_State_Coding(0);   //custorm defined, but we do not support
  
  // ONLY check RS Error xsy add  20180522
  /*VCO_224 RS_Error should be set only by RAM/ROM error, when RS function is coded as inactive in kodierbyte0*/
   l_bool_wr_L_RS_RainSensorError((bi_ROM_CHECK_FAILURE_g)||(bi_RAM_CHECK_FAILURE_g)||rbi_RainSensorError || rbi_ADC_Error_g ||rbi_HammingError_g  
                              || (get_rb_VDD_LightSignalErrorCnt_g() > CB_VDDX_ERRORCNT_THRESHOLD_MG));  
  l_u8_wr_L_Err_State_Light_Sens(0);
  l_u8_wr_L_Status_Light_Sens(0);
  l_bool_wr_L_RS_SolarSensorError(0);
  
  // volt error send
  if(rbi_UnderVoltage_g == TRUE)
  {
      //l_u8_wr_L_Err_State_Volt(rbi_UnderVoltage_g);    //voltage error statue
  }
  else if(rbi_OverVoltage_g == TRUE)
  {
    l_u8_wr_L_Err_State_Over_Volt(1);  //voltage error statue
  }
  else
  {
    l_u8_wr_L_Err_State_Over_Volt(0)
  }       
  
 }

void ApplLinInit(byte rb_LIN_State_l)
{
  
  // init unused bits to 1
  byte rb_Index_l; 
  static const byte LinMsgDefault_RLSs_01[8] = {0x00,0x0,0x0,0x0c,0x72,0xb0,0xff,0xff};   /* id: 0x015 "RLSs_01" */
  static const byte LinMsgDefault_RLSs_02[8] = {0xff,0xff,0x01,0x0f,0x00,0x00,0x00,0x00}; /* id: 0x016 "RLSs_02" */
  
  rb_Index_l = 0;
  do
  {
    RS_SENSOR_01._c[rb_Index_l] = LinMsgDefault_RLSs_01[rb_Index_l];
    RS_SENSOR_02._c[rb_Index_l] = LinMsgDefault_RLSs_02[rb_Index_l];
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
 
}

__callt void ApplLinSlavePreCopy(byte rb_MessageID_l)                                     /* callt function faster */
{
  
  if(rb_MessageID_l == (rb_IDRLSs_01_g & 0x3F))
  {
       l_bool_wr_RS_Sensor_01_LIN_Response_Error(rbi_latched_ResponseError_mg);
       l_u8_wr_L_Signal_Error(rbi_latched_ResponseError_mg);
       rbi_latched_ResponseError_mg = FALSE;
  } 
}

