#ifndef G5_APPLI_TIMER_H
#define G5_APPLI_TIMER_H

/*  Datum: Mittwoch, 6. Oktober 1999 und File: Timer.h
******************************************************************************
*    Modul: <Timer>
******************************************************************************
*
*    Description: Header file for timer modul
*
******************************************************************************
*/
/*************************************************************************

Company : Valeo Switches and Detection Systems

Project : RLT Sensor Generation 3.5

Component : G5_Appli_timer.h

Documentation reference : System Architectur spec.
---------------------------------------------------------------------------
Overview of the component : This module includes the hardware specific
---------------------------------------------------------------------------
Evolution of the component : */
/*----------------------------------------------------------------------------*/
/* Date         VDR_Number         Name          Description                                */
/*----------------------------------------------------------------------------*/
/* 24.03.2015   VCO_237           MP            Supplyvoltage should not be monitored on no rain variants*/
/*13.07.15      VDR_868           NB           QAC and Polyspace fixing for SW009 Release                */
/* 23.11.2015 VDR_927             NB           Wiper speed is valid on the bus only after 1.35 sec  */

/* PRQA S 0759 EOF *//*<< 0759:union needed to reduce RAM usage >>*/

#ifndef _timer_
#define _timer_
#endif

#ifdef _timer_c_
#define EXTERN	/**/
#else
#define EXTERN	extern
#endif

#define cb_ADC_ERROR_CNT_THRESHOLD_g  5
#define cb_CLOCKFREQ_ERROR_CNT_THRESHOLD_g 5

#define cb_TIME_TO_WAIT_FOR_VDD_g 3
#define cb_TIME_TO_WAIT_LONG_FOR_VDD_g 5

/*VCO_237 Supplyvoltage should not be monitored on no rain variants*/
/*default value for supply voltage for no rain variants*/

#define cb_SUPPLYVOLTAGE_DEF_g  160


EXTERN SHORT_MEMORY unsigned char rb_10msTimer_s;
/* Global Interface Variables */

EXTERN SHORT_MEMORY volatile Flag uF_Timer_g;              /* variable for flag for timer */


/* for debugging global */
EXTERN byte rb_ADC_Error_cnt_g;
EXTERN byte rb_ClockFreq_Error_cnt_g;
EXTERN byte rb_AfterVddPowerFailDelay_g;

/* #define rbi_TimeBase_OK_g	   uF_Timer_g.Bit.B0  */           /* flag for 30ms is over */
#define rbi_Timer10ms_OK_g	   (uF_Timer_g.Bit.B1)             /* flag for 10ms are over*/
#define rbi_Timer1s_OK_g           (uF_Timer_g.Bit.B2)             /* flag for 1 sec*/


EXTERN Flag uF_uC_Error_g;
#define rbi_ADC_Error_g            (uF_uC_Error_g.Bit.B0)   /* internal reference voltage of A/D are checked */
#define rbi_ClockFreq_Error_g      (uF_uC_Error_g.Bit.B1)   /* clock frequency error */

/** Function Prototypes **/

EXTERN __callt void AD_ConversionPerIntStart(byte rb_channel_l);
EXTERN void Change_DigitalPortToAnalog(void);
EXTERN void Change_AnalogPortToDigital(void);
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN

#endif