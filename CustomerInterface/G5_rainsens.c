/*************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : Rainsens.c

Documentation reference : Rainsensor Software Integration
Overview of the component : interface to the standard Valeo rs-tasks

Evolution of the component : see PVCS Version control system

Initials   date   modification

*************************************************************************/

/*************************************************************************
**                   Common and module include-file                     **
**************************************************************************/
/* History*/
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*-DD.MM.YY---------------------------------------------------------------------------*/
/* 30.08.10  VC075    AL    short interval*/
/* 25.Jun.10 VDR_540  FS    ParkPosition updated to run Butterfly Wipers*/
/* 03.05.10  VDR511   AL    Code improvement*/
/* 18.12.09  VDR_357  FS    define _FORD_ implemented for under- or overvoltage "keep wiping"*/
/* 11.11.09  VDR_373  FS    Adaptation to Single or DOuble Overwiped Function*/
/* 18.09.09  VDR_357  FS    No function of Under Voltage Fixed Intervall --> Corrected*/
/* 24.06.08  VDR_240  FS    Make use of rb_RLTPositionnearParkposition_E2_g --> 
                            Seat-Parameter should be usable in TMC-SW for Tata*/
/* 01.02.08  VDR_130        use standard algorithm for undervoltage interval*/
/* 01.04.15  VDR_866  MP    Remove of rainsens.c for no-rain-variants*/
/* 13.07.15  VDR_868  NB    QAC and Polyspace fixing for SW009 Release       */
/* 12.05.16  VCO_326  NB    All:Update of default Software part number and other configuration   */
/*----------------------------------------------------------------------------*/

/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 3138 EOF */ /* << using of macros from automatic generated code >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/* PRQA S 5900,5565,5540,5560 EOF *//*<< Data needs to be verified  >>*/

#include "G5_projectDefs.h"



#include "ior5f109be.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_Check_sr.h"
#include "G5_rls_linst.h"
#define _rainsens_c_                //Define for Single include of Global Header rainsens.h
#include "G5_rainsens.h"
/* PRQA S 0841 1 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef _rainsens_c_
#ifndef _NO_RAIN_
#include "G5_rs_lib.h"

#include "G5_rs_task.h"
#include "G5_rs_empf.h"
/*************************************************************************
**                   Other files included                               **
**************************************************************************/
#include "G5_Appli_main.h"
#include "G5_io.h"

#include "G5_rs_def.h"
#include "G5_IRlight.h"
#include "G5_Appli_timer.h"

/*************************************************************************
**                   Compile options                                    **
**************************************************************************/



/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/

/** Module-global Variables **/

#if defined(RSS_INKREMENTWIPE)
static byte rb_oldRSPotiStage_mg;              // old Potistage to make wipe at increase
#endif

#if defined(RSS_INKREMENTWIPE_OFF_TO_AUTO)
#define AUTO_VALUE 4
#define INVALID_VALUE 7
static byte OFF_to_AUTO_old;
#endif

/*************************************************************************
**                   Declaration of local module macros                 **
**************************************************************************/


#define cw_LONGINITTIME_RS_mg    (word) 300   // 3 s

#define cb_DELAYRESETWIPERSPEED_mg  (byte) 3

// for debug
// defines for LastStatusWipingSystem
#define cb_NOWIPING_mg    (byte) 0
#define cb_INTERMITTED_mg  (byte) 1
#define cb_LOWSPEED_mg    (byte) 2
#define cb_HIGHSPEED_mg    (byte) 3

#define CB_ERROR_INTERVAL 88

#define cw_TIME_TO_INITALIZE_RS_mg   (byte) 90   /* 800ms-900ms to be sure that no phantomwipe at startup for Fiat SWX004*/

byte rb_ALInitTimer_g = cw_TIME_TO_INITALIZE_RS_mg;

/*************************************************************************
**                   Declaration of local module prototypes             **
**************************************************************************/

static void Rainsensor_generate_output(void);
static byte Rainsensor_EvaluateWiperSpeed(void);
static void Rainsensor_Limit_StX_Speicher(void);
static void Rainsensor_init(void);
/**************************************************************************
Syntax   : void  Rainsensor_init(void)
Object   : Rainsensor_init()
Parameters : none
Return  : none
Calls   : in main.c
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : function to initialsize the Rainsensor modules
**************************************************************************/
static void Rainsensor_init(void)
{
  rbi_RainSensorError = 0;        // reset error bit
  // rub_LengthCounter = 0;    // reset variables no need
  // rub_PulseCounter = 0; 
  rub_IntermDelayTime = 0xFF;
  rub_RSIntermDelayInit = 0xFF;
  rub_WiperMotorTime = 0;
  wwrainse_Init();          // initialization in RS_TASK.C
  
  rbi_LastParkPosition_g = 1;     // initialise last parkposition
  
  
  
#if defined(RSS_INKREMENTWIPE)
  rb_oldRSPotiStage_mg = rb_PotiStageFromBox_g; // initialise ols potistage
#endif

#if defined(RSS_INKREMENTWIPE_OFF_TO_AUTO)
  OFF_to_AUTO_old = OFF_to_AUTO;              // old Potistage to make wipe at increase
#endif
  rb_AfterWashingTimer_mg = 255;   //initialise time after washing
}

/**************************************************************************
Syntax   : void  Rainsensor_evaluation(void)
Object   : Rainsensor_inactive()
Parameters : none
Return  : none
Calls   : in main.c
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : function to call the basic rainsensor routines anr to create
the interface variables
**************************************************************************/
void Rainsensor_evaluation(void)        // to be called every 10ms
{
  static byte rb_RSEvalTaskStatus_mg;            // Counter to create 40ms task from 10ms task
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_ /*VDR_540*/
  static byte rb_noObereWendelageCounter_mg=200;    //Diagnsosis of wendelage!
  static byte rb_noWendelageOutParkCounter_mg=200;  //Diagnsosis of wendelage!
  static byte rb_noWendelageinParkCounter_mg=200;  //Diagnsosis of wendelage!
#else
  static byte rb_noObereWendelageCounter_mg;    //Diagnsosis of wendelage!
  static byte rb_noWendelageOutParkCounter_mg;   //Diagnsosis of wendelage!
  static byte rb_noWendelageinParkCounter_mg;  //Diagnsosis of wendelage!
#endif
  
  word ruw_sigLengthTemp_l;
  byte rub_sigLength_scaled_l;
  
  Rainsensor_AfterLowVoltage();      // check for over and undervoltage
  wwrainse_Task10ms();            // 10ms-Task in RS_TASK.C
  
  
  if ((rbi_WashingActive_g==0)&&(rbi_RainSensorEnable == 1))  // do this only if RS is activ
  {
    
    if (((rw_rain_intensitiy_g>>11)<1 )&& (rub_SigLength == 0)) //immer aufrunden!
    {
      if (rw_rain_intensitiy_g > 0)
      {
        rw_rain_intensitiy_g--;
      }
    }
    else
    {
      ruw_sigLengthTemp_l = ((((word)(rb_880nm_Transmission_g*3)+130)>>1)*rub_SigLength);
      rub_sigLength_scaled_l = (byte)((64+ruw_sigLengthTemp_l)>>7); //Runden und Skalieren der Zwischenwerte /*VDR511*/
      rw_rain_intensitiy_g = ((rw_rain_intensitiy_g) - (rw_rain_intensitiy_g>>11)) + (rub_sigLength_scaled_l);
      
    }
  }
  
  rb_RSEvalTaskStatus_mg++;
  if (rb_RSEvalTaskStatus_mg > 3)   // time for 40ms task?
  {
    rb_RSEvalTaskStatus_mg = 0;      // reset TaskStatus
    
    // Copy Input-Variables for wwrainsens_Task40ms e.g. PotiStage ...
    
    
    rbi_Night=rbi_night_g;     // Not the higest poti stage and night bit set?
    rub_PotiStage = rb_PotiStageFromBox_g;
    
    
    wwrainse_Task40ms();          // 40ms-Task in RS_TASK.C
    
    
    
    
    if ((rub_IntermDelayTime > 0) && (rb_WiperSpeed_g == 0))
    {
      if (rbi_WischerWendelage_g == FALSE)  // Wendelage -> Parkt nicht in Wendelage!
      {
        if (rb_noWendelageinParkCounter_mg < 0xff)
        {
          rb_noWendelageinParkCounter_mg ++;
        }
      }
      else
      {
        rb_noWendelageinParkCounter_mg = 0;
      }
    }
    else if (rub_WiperMotorTime > 0)
    {
      if (rbi_WischerWendelage_g == TRUE)  // Wendelage -> Wendelage geht nicht weg!
      {
        if (rb_noWendelageOutParkCounter_mg < 0xff)
        {
          rb_noWendelageOutParkCounter_mg ++;
        }
      }
      else
      {
        rb_noWendelageOutParkCounter_mg = 0;
      }
      
      if (((rbi_checkWischerWendelage_old_g == FALSE)&&(rbi_WischerWendelage_g == TRUE)) //obere Wendelage kommt nicht!
          ||((rbi_checkWischerWendelage_old_g == TRUE)&&(rbi_WischerWendelage_g == FALSE)))
      {
        rb_noObereWendelageCounter_mg = 0;
      }
      else
      {
        if (rb_noObereWendelageCounter_mg < 0xff)
        {
          rb_noObereWendelageCounter_mg ++;
        }
      }
    }
    else
    {
      /* For not to violate MISRA */
    }
    rbi_checkWischerWendelage_old_g = rbi_WischerWendelage_g;
    
    
    
    // Increase WiperMotorTime-Counter
    /* PRQA S 4112 2 */ /* << there is no left hand oparand>>*/
    if (/*3*/ (rub_WiperMotorTime < 0xFF) && (/*2*/ (rbi_ParkPosition_g == 0)
       || (/*1*/ (rbi_ParkPosition_NearRLTPosition_g==0)&&(rb_RLTPositionnearParkposition_E2_g>0) /*1*/) /*2*/) /*3*/) 
    {
      rub_WiperMotorTime ++;
      
      //check if rbi_WischerWendelage_g is valid!
      if ((rb_noObereWendelageCounter_mg > 200)
          ||((rb_noWendelageOutParkCounter_mg > 200)
             ||(rb_noWendelageinParkCounter_mg > 200)))
      {
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_ /*VDR_540*/
        if (
            ( (rb_WiperPosition_g == CB_PARKTOWENDELAGEOBEN_S)
             &&((rb_LastWiperMotorTime_g>>1) < rub_WiperMotorTime)
               &&(rbi_ButterflyIsEquipped<1) )                       /*Normal Wiper*/
              ||( (rb_WiperPosition_g == CB_PARKTOWENDELAGEOBEN_S)
                 &&( ((rb_LastWiperMotorTime_g>>1)+(Threshold_AfterWiperMotorTime>>1)) <rub_WiperMotorTime)
                   &&(rbi_ButterflyIsEquipped>0) )     /*Butterfly, do not care about one time or two time overwiped*/
                )
#else
          if ((rb_WiperPosition_g == CB_PARKTOWENDELAGEOBEN_S)
              &&((rb_LastWiperMotorTime_g>>1) < rub_WiperMotorTime))
#endif
          {
            rb_WiperPosition_g = CB_WENDELAGEOBENTOPARK_S;
          }
      }
      else
      {
        if ((rb_WiperPosition_g == CB_PARKTOWENDELAGEOBEN_S)
            &&(rbi_WischerWendelage_g == TRUE))
        {
          rb_WiperPosition_g = CB_WENDELAGEOBENTOPARK_S;
        }
      }
      
    }
     /* in park ? */
    /* PRQA S 4112 1 */ /* << there is no left hand oparand>>*/
    if ((rbi_ParkPosition_g > 0)||((rbi_ParkPosition_NearRLTPosition_g>0)&&(rb_RLTPositionnearParkposition_E2_g>0)))
    {
      if (rbi_LastParkPosition_g == 0)     // Clear WiperMotorTime-Counter
      {
        rb_LastWiperMotorTime_g = rub_WiperMotorTime; //store last wipermotortime for simulate "wendelage"
        rub_WiperMotorTime = 0;
      }
      if (rub_IntermDelayTime < 0xFF)      // Increase IntermDelayTime-Counter
      {
        rub_IntermDelayTime ++;
      }
      rb_WiperPosition_g = CB_INPARKPOSITION_S;
    }
    else if (rbi_LastParkPosition_g == 1)
    {
      rub_IntermDelayTime_LalstWipe_g = rub_IntermDelayTime;
      rub_IntermDelayTime = 0;
      rb_WiperPosition_g = CB_PARKTOWENDELAGEOBEN_S;
    }
    else
    {
      /* Not to Violate MISRA */
    }
    Rainsensor_generate_output();  // generate signals for LIN communication
    // Store in old ParkPosition
    rbi_LastParkPosition_g = rbi_ParkPosition_g;    // is needed also in Rainsensor_generate_output
  }
  
  
  if (rbi_RainSensorEnable == 1)
  {
    if (rbi_AutomaticWipingMode_g == 0)  // sensor to be turned off
    {
      Rainsensor_inactive();        // clear RS enable flag
    }
  }
  else if (rbi_AutomaticWipingMode_g == 1)// RS to be turned on
  {
    
    if (rw_InitTimer_mg >= cw_TIME_TO_INITALIZE_RS_mg)
    {
      Rainsensor_init();      // initialize RS software
      Rainsensor_active();      // set flag after the needed initalization time
      rw_InitTimer_mg = 0;    // reset Init Timer
      
    }
    /*  else if (rw_InitTimer_mg == 0)  // Init Timer is 0
    {
    Rainsensor_on();      // switch on rain sensor
    rw_InitTimer_mg ++;      // increase init timer
  }*/
    else
    {  
      rw_InitTimer_mg ++;      // increase init timer
    }
    // Leave off
    rb_WiperSpeed_g = 0;            // no wiping
    //        rbi_Directmode_g = 0;
    //        rbi_Intermitted_g = 0;          // used for display status
    
  }
  else                                // sensor off
  {
    
    rw_InitTimer_mg = 0;        // initialize init timer
    Rainsensor_inactive();        // clear rainsensor enable flag
    rbi_RainSensorError = 0;        // clear rain sensor error flag if SCS is off
    // Switch off
    rb_WiperSpeed_g = 0;            // no wiping
    //      rbi_Directmode_g = 0;
    //      rbi_Intermitted_g = 0;          // used for display status
    
  }
  
  rb_WDG_RainsensorTaskCounter_g++;   // checkcounter for rainsens.c
  
}


/**************************************************************************
Syntax   : void  Rainsensor_generate_output(void)
Object   : Rainsensor_generate_output()
Parameters : none
Return  : none
Calls   : in rainsens.c
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : function to convert internal commands to external
*************************************************************************/
static void Rainsensor_generate_output(void)    // to be called every 40ms
{
  
  static byte rb_IntervaltimeBeforeError_g;
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
  byte rb_WiperSpeedresultTemp_l;
#endif
  
#if defined(RSS_INKREMENTWIPE)
  static byte rb_inkWipeRequest_s = 0;
  static byte rb_StartDelay_s;
  
  if (rb_StartDelay_s < 255)
  {
    rb_StartDelay_s++;
  }
  if(rbi_Ignition_g == FALSE) 
  {
    rb_StartDelay_s = 0;
  }
#endif
  /*  VDR_130        use standard algorithm for undervoltage interval*/
  if ((rbi_RainSensorError)||(bi_ROM_CHECK_FAILURE_g)||(bi_RAM_CHECK_FAILURE_g)||(rbi_Check_LS_NoCommunication_g)
      ||(rbi_LS_Error_Vref_g)||(rbi_OverVoltage_g)||(rbi_UnderVoltage_g))  
  {
      
      rb_SplashLSWipe_g = FALSE;     // clear to have fixed interval time at rs_error
      rbi_RSWipeFastDmd = rbi_ContSP2WipeBeforeError_g;
      rbi_RSWipeSlowDmd = rbi_ContWipeBeforeError_g;
      if ((rbi_OverVoltage_g)||(rbi_UnderVoltage_g))
      {
        if (rb_IntervaltimeBeforeError_g < 175)
        {
          rub_RSIntermDelayInit =  rb_IntervaltimeBeforeError_g;
        }
        else
        {
          rub_RSIntermDelayInit = 255;   //no wipe
        }
      }
      else
      {
        if (rb_IntervaltimeBeforeError_g < CB_ERROR_INTERVAL)
        {
          rub_RSIntermDelayInit =  rb_IntervaltimeBeforeError_g;
        }
        else
        {
          rub_RSIntermDelayInit = CB_ERROR_INTERVAL;   // fixed intermitted mode with 3,5s intermittence time
        }
      }
    }
    else if(rub_Dia_Count < 10) //-> 100ms store interval time before rain sensor error!
    {
      if (rub_IntermDelayTime > rub_IntermDelayTime_LalstWipe_g)
      {
        rb_IntervaltimeBeforeError_g = rub_IntermDelayTime;
      }
      else
      {
        rb_IntervaltimeBeforeError_g = rub_IntermDelayTime_LalstWipe_g;
      }
      rbi_ContWipeBeforeError_g = rbi_RSWipeSlowDmd;
      rbi_ContSP2WipeBeforeError_g = (rbi_RSWipeFastDmd);
    }
    else
    {
      /* not to violate MISRA */
    }
    
    
    if (rbi_RSWipeFastDmd == 1)             // high speed wiping
    {
      rb_WiperSpeed_g = 7;
      //        rbi_Intermitted_g = 0;            // used for display status
      //        rbi_Directmode_g = 0;             //continous wipes
      rb_SplashLSWipe_g = FALSE;
      
    }
    else if (rbi_RSWipeSlowDmd == 1)        // low speed wiping
    {
      rb_SplashLSWipe_g = FALSE;
      

#ifdef SHORT_INTERVAL_VERSION /*VC075*/
      rb_WiperSpeedresultTemp_l = Rainsensor_EvaluateWiperSpeed();            // Speed 1 wiping
      if (/*rbi_IntervalForSpeedOne_g  == */TRUE)
      {
        if (rb_WiperSpeedresultTemp_l <= 0) 
        {  
          if (rub_IntermDelayTime > 6)
          {
            rb_WiperSpeed_g = 2;
          }
          else if ((rub_WiperMotorTime > cb_DELAYRESETWIPERSPEED_mg) || (rub_WiperMotorTime == 0))
          {
            rb_WiperSpeed_g = 0;        // no wiping Delay not reached
          }
        }
        else
        {
          rb_WiperSpeed_g = rb_WiperSpeedresultTemp_l; 
        }
      }
      else if (rb_WiperSpeedresultTemp_l == 0) //function is off!
      {  
        rb_WiperSpeed_g = 1; 
      }
      else
      {
        rb_WiperSpeed_g = rb_WiperSpeedresultTemp_l; 
      }
#else
      rb_WiperSpeed_g = Rainsensor_EvaluateWiperSpeed();            // Speed 1 wiping
#endif

      Rainsensor_Limit_StX_Speicher();    //linitation for StX_Speicher
      
    }
#if defined(RSS_INKREMENTWIPE)
#if defined(RSS_INKREMENTWIPE_OFF_TO_AUTO)
	else if ((rb_StartDelay_s > 100) && ((rb_PotiStageFromBox_g > rb_oldRSPotiStage_mg) || ((OFF_to_AUTO == AUTO_VALUE) && (OFF_to_AUTO != OFF_to_AUTO_old) && (OFF_to_AUTO_old != INVALID_VALUE))))
#else
    else if ((rb_StartDelay_s > 100) && (rb_PotiStageFromBox_g > rb_oldRSPotiStage_mg)) // Imediate wipe if user increses RS sensitivity
#endif
    {
      rb_inkWipeRequest_s = 1;
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
      rbi_NotWipingInVeryShortInterval_g = 0;
#endif
      if ((rub_Ovr_Speicher > CB_STUFE1_MIN_UG)|| (rub_Int_Speicher > CB_STUFE1_MIN_UG))
      {
        rb_WiperSpeed_g = 2;            // intermitted wiping
      }
      else
      {
        rb_WiperSpeed_g = 1;            // intermitted wiping
      }
    }
#endif
    else                          // intermitted mode
    {
      if (((rub_IntermDelayTime <= rub_RSIntermDelayInit))
          && ((rb_SplashLSWipe_g == 0) || (((rb_SplashLSWipe_g & 0x80) > 0) && (rub_IntermDelayTime <= 10)))
#if defined(RSS_INKREMENTWIPE)
            &&(rb_inkWipeRequest_s == 0))
#else
            )
#endif            
      {
        if ((rub_WiperMotorTime > cb_DELAYRESETWIPERSPEED_mg) || (rub_WiperMotorTime == 0))
        {
          rb_WiperSpeed_g = 0;        // no wiping Delay not reached
          //            rbi_Directmode_g = 0;
        }
        
      }
      else if (rub_WiperMotorTime > cb_DELAYRESETWIPERSPEED_mg)   // Clear signals if out of parkposition
      {
        if (rb_SplashLSWipe_g > 0)
        {
          rb_SplashLSWipe_g = 0x80;  //one Splash wipe done ->cleared in Betrieb.c
        }
        #if defined(RSS_INKREMENTWIPE)	  		  
        rb_inkWipeRequest_s = 0;   /*clear additional flag to keep wiper speed active until park position is left */
        #endif         
        rb_WiperSpeed_g = 0;        // no wiping
        //                  rbi_Directmode_g = 0;
      }
      else                                // next wipe
      {
        //        rbi_Directmode_g = 1;
        //        rbi_Intermitted_g = 1;          // used for display status
        
        if (ruw_StX_Speicher > CB_STXSPEICHER_INTERVAL_MAX)
        {
          ruw_StX_Speicher = CB_STXSPEICHER_INTERVAL_MAX;
        }
        /*   if ((rub_Ovr_Speicher > CB_STUFE1_UG)|| (rub_Int_Speicher > CB_STUFE1_UG))
        {
        rb_WiperSpeed_g = 3;            // intermitted wiping
      }*/

        
        if (((rub_Ovr_Speicher >  rb_Stufe1_UG_g)|| (rub_Int_Speicher > rb_Stufe1_UG_g))|| ((rb_SplashLSWipe_g & 0x80) > 0))
          
        {
          rb_WiperSpeed_g = 2;            // intermitted wiping
        }
        else

        {
          rb_WiperSpeed_g = 1;            // intermitted wiping
        }
        
        
      }
    }
#if defined(RSS_INKREMENTWIPE)
    rb_oldRSPotiStage_mg = rb_PotiStageFromBox_g;   // Store old Potistage for Iniwpe at Increment of SCS
#endif

#if defined(RSS_INKREMENTWIPE_OFF_TO_AUTO)
  OFF_to_AUTO_old = OFF_to_AUTO;
#endif
  }

/**************************************************************************
Syntax   : void  Rainsensor_EvaluateWiperSpeed(void)
Object   : Rainsensor_EvaluateWiperSpeed()
Parameters : none
Return  : none
Calls   : in rainsens.c Rainsensor_generate_output()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Function to evaluate from the Variable ruw_StX_Speicher
The Wiper Speed for a multi Speed Wiper Motor The Wiper Speed is
calculated with a hysteresys and splittet in 6 different Speeds
Speed 7 is calculatet in an special routine and is based on the high
speed calculation
*************************************************************************/
static byte Rainsensor_EvaluateWiperSpeed(void)
{
  byte rb_LocalEvaluateWiperSpeed_l;
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
  if ((rub_Ovr_Speicher > rb_Stufe1_OG_g) || (rbi_NotWipingInVeryShortInterval_g))
#endif
  {
    if ((ruw_StX_Speicher > CW_SCHWELLE_STUFE7)
        ||((ruw_StX_Speicher > (CW_SCHWELLE_STUFE7-CW_SCHWELLE_STUFEX_OFFSETT))&&(rb_WiperSpeed_g >6)))
    {
      rb_LocalEvaluateWiperSpeed_l = 7;            // Speed 7 wiping
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
      rbi_NotWipingInVeryShortInterval_g = 1; 
#endif
    }
    else if ((ruw_StX_Speicher > CW_SCHWELLE_STUFE6)
             ||((ruw_StX_Speicher > (CW_SCHWELLE_STUFE6-CW_SCHWELLE_STUFEX_OFFSETT))&&(rb_WiperSpeed_g >5)))
    {
      rb_LocalEvaluateWiperSpeed_l = 6;            // Speed 6 wiping
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
      rbi_NotWipingInVeryShortInterval_g = 1; 
#endif
    }
    else if ((ruw_StX_Speicher > CW_SCHWELLE_STUFE5)
             ||((ruw_StX_Speicher > (CW_SCHWELLE_STUFE5-CW_SCHWELLE_STUFEX_OFFSETT))&&(rb_WiperSpeed_g >4)))
    {
      rb_LocalEvaluateWiperSpeed_l = 5;            // Speed 5 wiping
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
      rbi_NotWipingInVeryShortInterval_g = 1; 
#endif
    }
    else if ((ruw_StX_Speicher > CW_SCHWELLE_STUFE4)
             ||((ruw_StX_Speicher > (CW_SCHWELLE_STUFE4-CW_SCHWELLE_STUFEX_OFFSETT))&&(rb_WiperSpeed_g >3)))
    {
      rb_LocalEvaluateWiperSpeed_l = 4;            // Speed 4 wiping
#ifdef SHORT_INTERVAL_VERSION
      rbi_NotWipingInVeryShortInterval_g = 1; 
#endif
    }
#ifdef SHORT_INTERVAL_VERSION
    else if ((ruw_StX_Speicher > CW_SCHWELLE_STUFE3)
             ||((ruw_StX_Speicher > (CW_SCHWELLE_STUFE3-CW_SCHWELLE_STUFEX_OFFSETT))&&(rb_WiperSpeed_g >2)&&(rbi_NotWipingInVeryShortInterval_g==1)))
#else
    else if ((ruw_StX_Speicher > CW_SCHWELLE_STUFE3)
             ||((ruw_StX_Speicher > (CW_SCHWELLE_STUFE3-CW_SCHWELLE_STUFEX_OFFSETT))&&(rb_WiperSpeed_g >2)))
#endif
    {
      rb_LocalEvaluateWiperSpeed_l = 3;            // Speed 3 wiping
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
      rbi_NotWipingInVeryShortInterval_g = 1; 
#endif
    }
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
    else if ((ruw_StX_Speicher > CW_SCHWELLE_STUFE2)
             ||((ruw_StX_Speicher > (CW_SCHWELLE_STUFE2-CW_SCHWELLE_STUFEX_OFFSETT))&&(rb_WiperSpeed_g >1)&&(rbi_NotWipingInVeryShortInterval_g==1)))
#else
    else if ((ruw_StX_Speicher > CW_SCHWELLE_STUFE2)
             ||((ruw_StX_Speicher > (CW_SCHWELLE_STUFE2-CW_SCHWELLE_STUFEX_OFFSETT))&&(rb_WiperSpeed_g >1)))
#endif
    {
      rb_LocalEvaluateWiperSpeed_l = 2;            // Speed 2 wiping
#ifdef SHORT_INTERVAL_VERSION
      rbi_NotWipingInVeryShortInterval_g = 1; 
#endif
    }
    else
        {  
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
      if ((ruw_StX_Speicher > CW_SCHWELLE_STUFE1)
          ||(((ruw_StX_Speicher > (CW_SCHWELLE_STUFE1-CW_SCHWELLE_STUFEX_OFFSETT))&&((rb_WiperSpeed_g > 0)&&(rbi_NotWipingInVeryShortInterval_g==1)))))
    {
#endif
        
  
        rb_LocalEvaluateWiperSpeed_l = 1;            // Speed 1 wiping
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
        rbi_NotWipingInVeryShortInterval_g = 1; 
#endif
      }
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
      else
      {
        rbi_NotWipingInVeryShortInterval_g = 0; 
        rb_LocalEvaluateWiperSpeed_l = 0;            // Speed 1 wiping
      }
#endif    
  }
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
  else
  {
    rbi_NotWipingInVeryShortInterval_g = 0; 
    rb_LocalEvaluateWiperSpeed_l = 0;            // Speed 1 wiping
  }
#endif
  return (rb_LocalEvaluateWiperSpeed_l);
}
/**************************************************************************
Syntax   : void  Rainsensor_Limit_StX_Speicher(void)
Object   : Rainsensor_Limit_StX_Speicher()
Parameters : none
Return  : none
Calls   : in rainsens.c Rainsensor_generate_output()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Function to reduce the value ruw_StX_Speicher by a
limitation depending on the variable rub_Int_Speicher -> this function is
responsible for the harmonic switch from continous wipin in interval
wiping
*************************************************************************/
static void Rainsensor_Limit_StX_Speicher(void)
{
  
  byte rb_Stuf1_ug_og_Distance_l;
  
  
  rb_Stuf1_ug_og_Distance_l =  ((rb_Stufe1_OG_g-rb_Stufe1_UG_g)/5);
  
  
  if ((rub_Int_Speicher < (rb_Stufe1_UG_g+((rb_Stuf1_ug_og_Distance_l)))))                                            // Interval Memory < Go out Threshold for Wiper Speed 2 ?
  {
    if  (ruw_StX_Speicher > (CW_SCHWELLE_STUFE2-CW_SCHWELLE_STUFEX_OFFSETT))   // Limit ruw_StX_Speicher to lower level of Speed 2
    {   ruw_StX_Speicher = CW_SCHWELLE_STUFE2-CW_SCHWELLE_STUFEX_OFFSETT;}
  }
  //    else if (rb_Stuf1_ug_og_Distance_l < (2*rb_Stuf1_ug_og_Distance_l))                                       // Interval Memory < Go out Threshold for Wiper Speed 3
  if ((rub_Int_Speicher < (rb_Stufe1_UG_g+((2*rb_Stuf1_ug_og_Distance_l)))))
  {
    if  (ruw_StX_Speicher > (CW_SCHWELLE_STUFE3-CW_SCHWELLE_STUFEX_OFFSETT))   // Limit ruw_StX_Speicher to lower level of Speed 3
    {                    ruw_StX_Speicher = CW_SCHWELLE_STUFE3-CW_SCHWELLE_STUFEX_OFFSETT;  }
  }
  //    else if (rb_Stuf1_ug_og_Distance_l < (3*rb_Stuf1_ug_og_Distance_l))                                         // Interval Memory < Go out Threshold for Wiper Speed 4
  if ((rub_Int_Speicher < (rb_Stufe1_UG_g+((3*rb_Stuf1_ug_og_Distance_l)))))
  {
    if  (ruw_StX_Speicher > (CW_SCHWELLE_STUFE4-CW_SCHWELLE_STUFEX_OFFSETT))   // Limit ruw_StX_Speicher to lower level of Speed 4
    {              ruw_StX_Speicher = CW_SCHWELLE_STUFE4-CW_SCHWELLE_STUFEX_OFFSETT;}
  }
  if ((rub_Int_Speicher < (rb_Stufe1_UG_g+((4*rb_Stuf1_ug_og_Distance_l)))))
  {
    if  (ruw_StX_Speicher > (CW_SCHWELLE_STUFE5-CW_SCHWELLE_STUFEX_OFFSETT))   // Limit ruw_StX_Speicher to lower level of Speed 5
    {                    ruw_StX_Speicher = CW_SCHWELLE_STUFE5-CW_SCHWELLE_STUFEX_OFFSETT;                }
  }
  if ((rub_Int_Speicher < (rb_Stufe1_UG_g+((5*rb_Stuf1_ug_og_Distance_l)))))
  {
    if  (ruw_StX_Speicher > (CW_SCHWELLE_STUFE6-CW_SCHWELLE_STUFEX_OFFSETT))   // Limit ruw_StX_Speicher to lower level of Speed 6
    {                ruw_StX_Speicher = CW_SCHWELLE_STUFE6-CW_SCHWELLE_STUFEX_OFFSETT;}
  }
}




/**************************************************************************
Syntax   : void  Rainsensor_AfterLowVoltage(void)
Object   : Rainsensor_AfterLowVoltage()
Parameters : none
Return  : none
Calls   : in timA.c
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : function creates delay after switching aSIC in Normal mode
**************************************************************************/

void Rainsensor_AfterLowVoltage(void)
{
  if ((rb_AfterVddPowerFailDelay_g> 0)||(rbi_UnderVoltage_g>0)||(rbi_OverVoltage_g > 0))
  {
    rw_InitTimer_mg = 0;
    rb_ALInitTimer_g = 0;    // increase init timer
    rbi_LowVoltage = 1;         //
  }
  if (rb_ALInitTimer_g >= cw_TIME_TO_INITALIZE_RS_mg) // InitTimer > TimetoInitialize
  {
    rbi_LowVoltage = 0;        // give RS Software free
  }
  else
  {
    rw_InitTimer_mg=0;
    rb_ALInitTimer_g ++;      // increase init timer
    rbi_LowVoltage = 1;         //
  }
}

#endif /*_NO_RAIN_*/