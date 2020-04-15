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
/* PRQA S 841 1 */ /* << #undef is needed for old header implementation, needs update in the near future>> */
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
#include "G5_utilities.h"
#include "G5_AsicFramesLin.h"
/*VDR_362 Carry Over Standard Code*/
#define cb_IGNORE_IGNITION_SPEED 4  /*VCO_083 ignore ignition off if speed higher 4km/h*/
/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/

typedef struct {
  byte max;
  byte min; 
}BytePair;

static  word rw_AfterRSWipeCounter_mg;                   // Time after last wipe from RS
static  word rw_AfterWWSWipeCounter_mg;                  // Time after last wipe from WWS
static  byte rb_IgnitionOndelay_mg;



/*VDR_362*/
static word rw_WipeCommandTimOut_mg;                     /*timeout for requested wipe*/

/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
static volatile Flag uF_StalkInPos_Flags_g;

/******************************************************************************/
/*                      Definition of exported variables                      */
/******************************************************************************/


/*************************************************************************
**                   Declaration of local module Macros **
*************************************************************************/

#define cb_FOUR_SECOND_DELAY_mg   25

#define CW_LIN1_3_IDLE_TIMOUT (2*130)
#define CW_LIN2_0_IDLE_TIMOUT 400
#define cw_CLEARWIPE_DELAY_s 400 // 4 seconds (400*10ms)
#define cb_DEPRESSED_PARK_DEBOUNCE_s 18

#define cb_VERGLSUNG_OPEN_DELAY_mg 100
#define cb_VERGLSUNG_CLOSE_DELAY_mg 100
/*************************************************************************
**                   Declaration of local module Functions              **
*************************************************************************/
static void check_for_errors(void);
static void send_DefaultErrors(void); 
static void send_SoftwareNo(void);
static void send_PartNo(void);
static void LIN_CalculateFixIntervalTime(void);
//static void sendResponseError();Blake_LI Masked it on sep 5th,2017
static byte rb_Verglasun_offenDebounce_mg,rb_Verglasun_ClosedDebounce_mg;
static word rw_CommandCloseWindowTimout_mg;
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
    static word rw_IgnitionOffDelay_mg;
    static byte rb_IntervalOnOndelay_mg;
    static byte rb_AfterResetCounter_l;
    byte Geely_Standby_Switch;
    byte rb_Kodierbyte0_Update_g;
/***********************Add the Auto_Close_Window Function in Rain Condition*************************/   
    rb_Kodierbyte0_Update_g = rb_Kodierbyte0_g;
    Geely_Standby_Switch = l_u8_rd_L_RLS_ModeEnable();  
    if((Geely_Standby_Switch > 0) && (Geely_Standby_Switch < 3))
    {
        if(rbi_StandbyFunction_enabled_g != (Geely_Standby_Switch - 1))
        {
          if((Geely_Standby_Switch - 1) > 0)
          {
          rb_Kodierbyte0_Update_g |= 0x04; 
          }
          else if((Geely_Standby_Switch - 1) == 0)
          {
          rb_Kodierbyte0_Update_g &= 0xFB; 
          }
          rab_EEPROM_Bytes_toWrite_g[0] = rb_Kodierbyte0_Update_g;
          rw_EEPROM_Address_to_Write_g = cw_EEPROM_CODING_ADDRESS_g + 2; /*set adress to write*/
          rb_I2C_EEPROM_bytesToWrite_g = 1;         /*set number of bytes to 1*/
          rbi_EEPROMBytesToWrite_g = TRUE;
          rbi_EEPROMBytesWritten_g = FALSE;         
        }   
    }
   
     if (l_u8_rd_L_All_Wdw_Closed()== 0)  /*Window Open*/
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
   
    
/************************End the function*************************************************************/   
    if(l_flg_tst_BCM_01())
    {
        l_flg_clr_BCM_01();
        rw_NoCommunicationCounter_g = 0;        // reset no communication counter
        rbi_ConnectedToMaster_g = 1;                   // set connected to Master
        
        
        rb_speed_in_kmh_g  = l_u8_rd_L_BCM_VehicleSpeed();                           // set speed
        if(l_u8_rd_L_BCM_VehicleSpeed() == 0xFF)
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

        /* ignore ignition off if speed higher 4km/h*/
        if((l_bool_rd_L_BCM_KL15() == TRUE)||(rb_speed_in_kmh_g > cb_IGNORE_IGNITION_SPEED)) /*VCO_083*/
        {
          rbi_Ignition_g = TRUE;
          rw_StandbyTimeOutCnt_g = 0;
          rbi_WindowOpenIgnitionWasOn_g = TRUE;   /*store window state at ignition on to off!*/
          rw_IgnitionOffDelay_mg = 0;
          if(rb_IgnitionOndelay_mg < 250)
          {
            rb_IgnitionOndelay_mg++;
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
    }

   if(l_flg_tst_RS_SENSOR_01())
   {
      l_flg_clr_RS_SENSOR_01();
      rw_NoCommunicationCounter_g = 0;        // reset no communication counter
      rbi_ConnectedToMaster_g = 1;                   // set connected to Master
      send_SoftwareNo();
      send_PartNo();
      /*sendResponseError(); Blake_LI Masked it on sep 5th,2017*/
    }
    
  if (l_flg_tst_BCM_02())                   /*BCM_02 Request?*/
  {
    l_flg_clr_BCM_02();
    rw_NoCommunicationCounter_g = 0;        // reset no communication counter
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
    
    rbi_RealParkContact_g = (l_u8_rd_L_BCM_WiperPosition() == 2)? 1:0;/*****************No interval bug fix********************/

    /* ignore ignition off if speed higher 4km/h*/
    if((l_bool_rd_L_BCM_KL15() == TRUE)||(rb_speed_in_kmh_g > cb_IGNORE_IGNITION_SPEED)) /*VCO_083*/
    {
        if(((rbi_RainsensorDisabled_g == FALSE) && (l_u8_rd_L_BCM_RainFuncActive() == 0))&&(rb_AfterResetCounter_l> 10))
        {
            if((l_u8_rd_L_BCM_WiperControl() == 1) // interval, automatic
//              || (l_u8_rd_L_BCM_WiperControl() == 2) // low speed
//              || (l_u8_rd_L_BCM_WiperControl() == 3) // high speed
              || (rbi_RainsensorAlwaysOn_g != FALSE))
            {
              rbi_AutomaticWipingMode_g = TRUE;           /*Rainsensor always active!*/
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
      
        if(l_u8_rd_L_BCM_WiperControl() == 1) // copy automatic wiping mode
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

    rb_LIN_SensitivityShift_g =  7;       //adaptation Variable for sensitivity factor

    rb_PotiStageFromBox_g = (l_u8_rd_L_BCM_RainSensitivity() > 7)?7:(l_u8_rd_L_BCM_RainSensitivity());
    if (l_u8_rd_L_BCM_WiperControl() == 0x5)   /* Washpump activ? 0x5:Front washing*/
    {
      rbi_WashingActive_g = TRUE;             /* set Washing activ bit */
    }
    else if (rbi_ParkPosition_g == TRUE)          /* In Parkposition ? */
      {
        rbi_WashingActive_g = FALSE;              /* Clear Washing active bit */
      }
      else
      {
          /*Do nothing, Dummy-else for Misra Check*/
      }

  }
  else  //keine neue Master Nachricht!
  {    // check if system is on -> to switch off 
    if((rw_NoCommunicationCounter_g > CW_LIN_E2_IDLE_TIMOUT))                               /***4S***/
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
        if ((l_u8_rd_L_All_Wdw_Closed()== 1)||(rw_CommandCloseWindowTimout_mg > 6000))
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
  
  if(l_flg_tst_BCM_02())                  //Wischermotor request?
  {
/***********************Masked because No interval wiper***************************/ 
//    l_flg_clr_BCM_02();                  //loesche flag
//    rbi_RealParkContact_g = (l_u8_rd_L_BCM_WiperPosition() == 2)? 1:0;
//    rbi_ConnectedToMaster_g = 1;                   // set connected to Master  
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

  if((((l_u8_rd_L_BCM_WiperControl() != 1) // no interval, automatic
       && (l_u8_rd_L_BCM_WiperControl() != 2)) // no low speed
      && ((l_u8_rd_L_BCM_WiperControl() != 3) // no high speed
          && (rbi_RealParkContact_g == TRUE)))
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
   if((rbi_RealParkContact_g == TRUE)&&(rb_WiperSpeed_g > 0))
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
        rbi_WiperStarted_g = FALSE;
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
  static byte rb_OutOffParkCounter_mg;
  static byte rb_TunnelWipeTimeOut_mg;
  static byte rb_underVoltageTimer_s;
  word newWiperSpeedLin =0;

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
    if (rw_AfterWWSWipeCounter_mg < 50000) //Delay fuer Direktbit (depressed park) hochzaehlen
    {
      rw_AfterWWSWipeCounter_mg++;
    }
  }
  
  if (rw_AfterRSWipeCounter_mg < 50000)  //Delay fuer Tunnelwischung hochzaehlen
  {
    rw_AfterRSWipeCounter_mg++;
    
    
  }

  
  if(l_flg_tst_RS_SENSOR_01())                            // pruefen ob eigene Nachricht korrekt empfangen wurde
  {
    l_flg_clr_RS_SENSOR_01() ;                          // loeschen des Pruefflags
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master   
  }
  
  if( (rw_AfterRSWipeCounter_mg < 1500)        //Afterwipe at tunnel
      &&(rb_speed_in_kmh_g > 29)
      &&(rbi_modi_lightsens_tunnel_g == TRUE)
      &&(rbi_modi_lightsens_tunnel_alt_mg == FALSE)
      &&(rb_WiperSpeed_g == 0))
    {
        rb_TunnelWipeTimeOut_mg = 0;
        rbi_TunnelWipe_mg = TRUE;
        l_u8_wr_L_RS_WiperSpeed(1);   //Wischergeschwindigkeit uebergeben
    }
    else if((rbi_TunnelWipe_mg == TRUE))
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
        l_u8_wr_L_RS_WiperSpeed(1);   //Wischergeschwindigkeit uebergeben
    }
    else
    {
        /*VCO_166 wiper speed limited to 1, when interval is not selected*/
        if(((l_u8_rd_L_BCM_WiperControl() == 2) || (l_u8_rd_L_BCM_WiperControl() == 3))&&(rb_WiperSpeed_g > 1))
        {
            l_u8_wr_L_RS_WiperSpeed(1);   
            l_u8_wr_L_RS_RainSenSts(0);            // Gush bit reset
        }
        else
        {
            // RS will send the proper wiper speed in auto mode only(GEELY)
            if (l_u8_rd_L_BCM_WiperControl() == 1) 
            {
                // require the hysteresis edges between 1 and 7
                newWiperSpeedLin =  wiperSpeed7to2(l_u8_rd_L_RS_WiperSpeed(), rb_WiperSpeed_g, rb_wiperSpeedHysteresis);
            }   
            l_u8_wr_L_RS_WiperSpeed(newWiperSpeedLin);

            /*VDR_859 Interval wipe in manual mode for no rain variant*/
            /*is RS functionality enabled?*/
            l_u8_wr_L_RS_RainSenSts(rbi_RSWipeFastDmd);            // Gush bit set
        }
        if(rb_WiperSpeed_g >0)
        {
            rw_AfterRSWipeCounter_mg =0;
        }
    }
  
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

//  check_for_TunnelWipe();
  check_for_errors();
//  send_SplashRequirement();
  send_DefaultErrors(); 

//  if ((l_u8_rd_L_RS_CollectiveError() == 0) && ((rbi_WindowOpenIgnitionWasOn_g == TRUE) && (rbi_Ignition_g== FALSE)) &&((rb_Verglasun_offenDebounce_mg > cb_VERGLSUNG_OPEN_DELAY_mg)&& (rbi_StandbyFunction_enabled_g == TRUE)))
//  {
//    rbi_ASICStandByModeRequest_g = 1;   // Set Request for Standby Mode
//  }
//  else
//  {
//    rbi_ASICStandByModeRequest_g = 0;
//  }  
 
  if((rb_Verglasun_ClosedDebounce_mg > cb_VERGLSUNG_CLOSE_DELAY_mg)||(rbi_Ignition_g== TRUE)||(rw_CommandCloseWindowTimout_mg > 6000))
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
    l_bool_wr_L_Sunroof_Win_CloseReq(TRUE);                // setzen von Verglasung Schliessen
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
    l_bool_wr_L_Sunroof_Win_CloseReq(FALSE);             // setzen von Verglasung Schliessen
  }
  
  if(rbi_StandbyFunction_enabled_g == TRUE)
  {
    l_bool_wr_L_RLS_ModeSts(TRUE);
  }
  else if(rbi_StandbyFunction_enabled_g == FALSE)
  {
    l_bool_wr_L_RLS_ModeSts(FALSE);
  }
  else
  {
  
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


#if defined (ASIC_TEST)
  CopyRLSDataAsic();
#endif

  rb_WDG_BusTaskCounter_g++;      //increment test counter for bus

}


void ApplLinInit(byte rb_LIN_State_l)
{

  // init unused bits to 1
  byte rb_Index_l;
//  static const byte LinMsgDefault_FSs_01[8]  = {0x00,0x7C,0x00,0xFC,0x00,0x00,0xFF,0xFF}; /* id: 0x029 "FSs_01" */
  static const byte LinMsgDefault_RLSs_01[8] = {0,0,0,0,0,0,0,0}; /* id: 0x023 "RLSs_01" */
  
  rb_Index_l = 0;
  do
  {
    RS_SENSOR_01._c[rb_Index_l] = LinMsgDefault_RLSs_01[rb_Index_l];
    
//    FSs_01._c[rb_Index_l] = LinMsgDefault_FSs_01[rb_Index_l];
    
    rb_Index_l++;
  } while (rb_Index_l < 8);
  
  
#ifdef _SUPPORTMWLLIGHT_
  Diagnose_ReadMem_Init();
#endif
  rw_AfterRSWipeCounter_mg = 50000;
  rw_AfterWWSWipeCounter_mg = 50000;          //Direktbitdelay bei Kl15 Aus hochsetzen!
  sci_init(rb_LIN_State_l);
  rbi_RealParkContact_g = TRUE;
  rbi_ParkPosition_g = TRUE;
  rw_WipeCommandTimOut_mg = 0;
//  rb_LSPotiStage_g = 4; // "4" default value for LS Sensitivity
  rb_PotiStageFromBox_g = 3; /*VDR_408 use init value*/
  //rb_AnyErrorCounterDebounce_mg = 200;

}                                              //ApplLinInit


__callt void ApplLinSlavePreCopy(byte rb_MessageID_l)    /* callt function (faster */
{
  if(rb_MessageID_l == (rb_IDRLSs_01_g & 0x3F))
  {
    l_bool_wr_L_RS_response_error(rbi_latched_ResponseError_mg);
    rbi_latched_ResponseError_mg = FALSE;
    } 

}

/*****Masked by Blake_Li sep 5th,2017******/
//void sendResponseError(){
//  l_bool_wr_L_RS_response_error(rbi_latched_ResponseError_mg);
//  rbi_latched_ResponseError_mg = FALSE;
//}



static void LIN_CalculateFixIntervalTime(void)
{
  
  /*interval times for rain sensor below 4kmph inactive in 100ms*/
  static const byte cab_FixIntervtim_bel4kmph_mg[4] = {240,160,80,40}; 
  /*interval times for rain sensor above 200kmph inactive in 100ms*/
  static const byte cab_FixIntervtim_a200kmph_mg[4] = {70,40,20,10};   
  /*interval times for rain sensor above 200kmph inactive in 100ms*/
  static const byte cab_FixIntervtim_Offsett_mg[4] = {190,120,60,30};  
  /*interval times for rain sensor above 200kmph inactive in 100ms*/
  static const byte cab_FixIntervtim_Devider_mg[4] = {10,15,30,60};
  
  /* wipe Decision and Set!*/
  if(((rbi_LINRainsensorDisabled_g == TRUE)
      || ((rbi_RainsensorDisabled_g == TRUE)&&(rbi_EEPROMLoad_g == FALSE)))
     &&(l_bool_rd_L_BCM_KL15() == TRUE))
  {
    if(l_u8_rd_L_BCM_WiperControl() == 1)
    {
      
      if(rb_speed_in_kmh_g <= 4)
      {
        rb_intervaltime_rainSensorOff_g = cab_FixIntervtim_bel4kmph_mg[(l_u8_rd_L_BCM_RainSensitivity()>>2)];
      }
      else if(rb_speed_in_kmh_g < 200)
      {
        rb_intervaltime_rainSensorOff_g = cab_FixIntervtim_Offsett_mg[(l_u8_rd_L_BCM_RainSensitivity()>>2)]
          -(byte)((((word)(rb_speed_in_kmh_g)*6)/cab_FixIntervtim_Devider_mg[(l_u8_rd_L_BCM_RainSensitivity()>>2)]));
      }
      else
      {
        rb_intervaltime_rainSensorOff_g = cab_FixIntervtim_a200kmph_mg[(l_u8_rd_L_BCM_RainSensitivity()>>2)];
      }
      if((rw_AfterWWSWipeCounter_mg/10) >= rb_intervaltime_rainSensorOff_g) /*VCO_031 correct rainlight*/
        
      {
        //           rb_TunnelWipeTimeOut_mg = 0;
        rbi_TunnelWipe_mg = TRUE;
      }
    }
    else
    {
      /* interval fuer Ampelrueckschaltung wiper control level 1 or 2*/
      if((l_u8_rd_L_BCM_WiperControl() == 2)||(l_u8_rd_L_BCM_WiperControl() == 3)) 
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

#pragma inline=forced
static void send_DefaultErrors(void) 
{
  l_u8_wr_L_RS_StateCalError(0);
  l_u8_wr_L_RS_OverTempError(0);
}

#pragma inline=forced
static void send_SoftwareNo(void)
{
  static byte software_no_idx = 0;

  software_no_idx ++;

  l_u8_wr_L_RS_Software_No_Count(software_no_idx);
  switch(software_no_idx)
  {
    case 1:
      l_u8_wr_L_RS_Software_No1('0');
      break;
    case 2:
      l_u8_wr_L_RS_Software_No1(cb_SOFTWARESTAND_1_g);
      break;
    case 3:
      l_u8_wr_L_RS_Software_No1(cb_SOFTWARESTAND_2_g);
      break;
    case 4:
      l_u8_wr_L_RS_Software_No1(cb_SOFTWARESTAND_3_g);
      break;
    default:
      break;
  }

  if(software_no_idx >= 4){
    software_no_idx = 0;
  }
}

#pragma inline=forced
static void send_PartNo(void)
{
  static byte part_index = 0;
  byte data =0; 

  switch(part_index){
    case 0:
    case 1:
    case 2:
    data = rab_Audi_HW_Partnumber_g(part_index);
    break;
    case 3:
      data = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)>>4);        
      break;
    case 4:
      data = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)&0x0F);
      break;
    case 5:
      data = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(4)>>4);
      break;
    case 6:
      data = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(4)&0x0F);
      break;
    case 7:
      data = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(5)>>4);
      break;
    default:    
      data = ' ';
  }
  l_u8_wr_L_RS_Part_No_Count(part_index +1);
  l_u8_wr_L_RS_Part_No1(data);

  part_index ++;
  if(part_index >= 11){
    part_index = 0;
  }
}


#pragma inline=forced
static void check_for_errors(void)
{
  l_u8_wr_L_RS_RainStateError(rbi_RainSensorError || rbi_ADC_Error_g ||rbi_HammingError_g  
                              || (get_rb_VDD_LightSignalErrorCnt_g() > CB_VDDX_ERRORCNT_THRESHOLD_MG));
    
  l_u8_wr_L_RS_RainSensorHealth((bi_ROM_CHECK_FAILURE_g)||(bi_RAM_CHECK_FAILURE_g));
    
  byte voltageErr = 0;
  if(rbi_OverVoltage_g == TRUE){
    voltageErr = 0x1;
  }else if(rbi_UnderVoltage_g == TRUE) {
    voltageErr = 0x2;
  }
  l_u8_wr_L_RS_VoltError(voltageErr);  

  l_u8_wr_L_RS_CollectiveError(l_u8_rd_L_RS_RainSensorHealth()|| l_u8_rd_L_RS_RainStateError()|| l_u8_rd_L_RS_VoltError());
}
