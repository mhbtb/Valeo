#ifndef G5_RAINSENS_H
#define G5_RAINSENS_H
/*****************************************************************************************************************

Company : Valeo Wiper Systems

Project : RLT Sensor, RDN Sensor

Component : Rainsens.h

Documentation reference :Rainsensor Software Integration

Overview of the component : variable and prottype declaration
for rainsens.c
Evolution of the component : see PVCS Version control system

Initials   date   modification
*****************************************************************************************************************/

/****************************************************************************************************************/
/****************************************************************************************************************/
/* History                                                                                                      */
/*--------------------------------------------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                                                         */
/*-DD.MM.YY-----------------------------------------------------------------------------------------------------*/
/*17.11.09      VDR_373    FS      Adaptation Sinle or DOuble Overwiped Function                                */
/*18.09.09      VDR_357    FS      No function of Under Voltage Fixed Intervall --> Corrected                   */
/*24.06.08      VDR_240    FS      Define rbi_ParkPosition_NearRLTPosition_g -->                                */
/***********************************Seat-Parameter should be usable in TMC-SW for Tata                          */
/*01.04.15      VDR_866    MP      Remove of rainsens.c for no-rain-variants                                    */
/*13.05.15      VCO_192    NB      Audi: Activation and deactivation of Interval Operation                      */
/*09.06.15      VCO_192    NB      Audi: Activation and deactivation of Interval Operation                      */
/*13.07.15      VCO_260    MP      Tunnel wipe activation and delay according to                                */
/***********************************Tunnel Verzoegerung and Aktivierung parameters                              */
/****************************************************************************************************************/
/****************************************************************************************************************/
/* Definition for Mono-Inclusion                                                                                */
/****************************************************************************************************************/



#ifdef _rainsens_c_
#define EXTERN /**/

#else // End include declaration for RS-Software rain_c
#ifdef PC_simulation // define for PC_Simulation
#define EXTERN extern "C"
#define SHORT_MEMORY /**/

#else
#define EXTERN extern
#endif
#endif


/*************************************************************************
**                   Compile options                                    **
**************************************************************************/

/*************************************************************************
**                   Declaration of exported constants                  **
**************************************************************************/
#include "ior5f109be.h"
#include "G5_rs_lib.h"
#include "G5_rs_ext.h"


// declaration of variables used by RS-Module in rs_task
EXTERN unsigned char rub_WiperMotorTime;     //Time the Wiper Motor is runneing since last park
EXTERN unsigned char rub_IntermDelayTime;    //initialed in Rainsensor_init
EXTERN unsigned char rub_PotiStage;          //RS-Sensitivity 0-X
EXTERN volatile unsigned char rub_LengthCounterHB;   /*VCO_108 counter for XY Table measurement*/
EXTERN volatile unsigned char rub_PulseCounter;    //Counter for Pulses of Rainsensor Signals freerunning


EXTERN unsigned char rb_PotiStageFromBox_g;
EXTERN unsigned char rb_SplashLSWipe_g;

EXTERN byte rb_LastWiperMotorTime_g; /* VDR_373 byte to simulate wendelage!*/
EXTERN byte rb_ALInitTimer_g;

#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
EXTERN byte Threshold_FirstOverwipe_Start;
EXTERN byte Threshold_FirstOverwipe_End;

EXTERN byte rub_debugEmpf_Faktor;
#endif
EXTERN word rw_InitTimer_mg;                   // timer to create RS-Inidelay
EXTERN word rw_rain_intensitiy_g;
//Input Variables for Rain Sensor
#define  rbi_WashingActive_g     rbi_WashingActive

/* In and Outputs*/
/*******************/
/* PRQA S 0759 10*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN SHORT_MEMORY Flag uF_StatusRainsensor_mg;
// To be set if steering column switch is in intermittent mode
#define rbi_AutomaticWipingMode_g              uF_StatusRainsensor_mg.Bit.B0  
//#define rbi_Directmode_g                        uF_StatusRainsensor_mg.Bit.B1
#define rbi_ContSP2WipeBeforeError_g              uF_StatusRainsensor_mg.Bit.B1
#define rbi_WischerWendelage_g                  uF_StatusRainsensor_mg.Bit.B2
#define rbi_checkWischerWendelage_old_g         uF_StatusRainsensor_mg.Bit.B3
#define rbi_AutomaticWipingModeInv_g            uF_StatusRainsensor_mg.Bit.B4
#define rbi_ContWipeBeforeError_g              uF_StatusRainsensor_mg.Bit.B5
// Last Parkposition to create Wipermotor time
#define rbi_LastParkPosition_g                  uF_StatusRainsensor_mg.Bit.B6 
#define rbi_ParkPosition_g                      uF_StatusRainsensor_mg.Bit.B7
/* PRQA S 0759 10*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN SHORT_MEMORY Flag uF_StatusRainsensor2_mg;
#define rbi_ParkPosition_NearRLTPosition_g        uF_StatusRainsensor2_mg.Bit.B0 /*VDR_240*/
#ifdef SHORT_INTERVAL_VERSION /*VC075*/
#define rbi_NotWipingInVeryShortInterval_g         uF_StatusRainsensor2_mg.Bit.B1 /*VDR_240*/
#endif
#define rbi_Relase_FixedIntervalTime_g             uF_StatusRainsensor2_mg.Bit.B2 /*VCO_192*/
#define rbi_Write_ReleaseMarker_g                  uF_StatusRainsensor2_mg.Bit.B3 /*VCO_192*/
EXTERN byte rb_WiperPosition_g;
// Defines for WiperPositionOn windshield
#define CB_INPARKPOSITION_S 0
#define CB_PARKTOWENDELAGEOBEN_S 1
#define CB_WENDELAGEOBENTOPARK_S 2

#define cb_IGNORE_IGNITION_SPEED 4  /*VCO_083 ignore ignition off if speed higher 4km/h*/

EXTERN byte rb_WiperSpeed_g;
/*VCO_260 Tunnel wipe activation and delay according to Tunnel Verzoegerung and Aktivierung parameters*/
EXTERN byte rb_WiperSpeedAlt_g;



/*************************************************************************
Declaration of exported functions
**************************************************************************/
#ifndef _NO_RAIN_
EXTERN void Rainsensor_evaluation(void);

EXTERN void Rainsensor_AfterLowVoltage(void);


/* PRQA S 3458 5 *//*<< required for readability  >>*/
//function to deactivate the Rainsensor modules
#define Rainsensor_inactive()  {rbi_RainSensorEnable = FALSE; rw_InitTimer_mg = 0;}
#define Rainsensor_active()    {rbi_RainSensorEnable = TRUE;} //function to activate the Rainsensor modules

#endif /*_NO_RAIN_*/

/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN
#endif