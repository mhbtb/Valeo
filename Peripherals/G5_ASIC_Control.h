/*************************************************************************

Company : Valeo Switches and Detection Systems

Project : RLT Sensor Generation 5 (16 bit Micro Controller)

Component : ASIC_Control.h

*************************************************************************/

/*! \file G5_ASIC_CONTROL.h
 *   This Module contains data and function declarations for Global usage sankar.
 *   It is intended that other components will use them.
 *   Documentation reference : ASIC_Specification
 */ 

#ifndef G5_ASIC_CONTROL_H
#define G5_ASIC_CONTROL_H

/* History                                                                       */
/*-------------------------------------------------------------------------------*/
/* Date      VDR_Number  Name    Description                                     */
/*-------------------------------------------------------------------------------*/
/*07.11.13   RLS_VCO_128 MPI     initial version (split non-safety from safety)  */
/*18.03.15   RLS_VDR_856 MPI     Min period to run the gain adjustment measurements is restricted to 10sec*/

/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/

#ifdef _G5_ASIC_Control_c_
#define EXTERN /**/
#else
#define EXTERN  extern
#endif

/****************************************************************************/
/** Global Variables **/
/****************************************************************************/
/*if the rain functionality is enabled*/
//#ifndef _NO_RAIN_

/*! Threshold for window comparator (1LSB = (1/255)*5V))*/
#define CB_RS_WINDOW_COMP_THRESHOLD rb_rs_WINDOW_COMP_THRESHOLD_g

/*! Standby mode detection threshold*/
#ifndef  BYD_HC 
#define cb_THRES_RSACTION_mg 50
#endif
/*VDR_856 Min period to run the gain adjustment measurements is restricted to 10sec*/
/*! Threshold counter for no rain to start a WS measurement*/
#define CW_NO_RAIN_PRESENT_THRSH_g ((word)(((word)CW_NO_RAIN_PRESENT_THRSH_HB_g<<8)+CW_NO_RAIN_PRESENT_THRSH_LB_g)>10?\
(word)(((word)CW_NO_RAIN_PRESENT_THRSH_HB_g<<8)+CW_NO_RAIN_PRESENT_THRSH_LB_g):10)

/*! Gain adjustment for ASIC*/
EXTERN byte rb_ASICGainSetup_g;
EXTERN byte rb_Start_STBY_Meas_g;

/*! Debug information to evaluate the reason to close the window in standby mode*/
EXTERN byte rb_CloseTypeStandby_g;
EXTERN word rw_Stby10msTimer_g;

/*! Voltage of rain sensor signal one Task before*/
EXTERN  byte rb_RS_SigVoltage_alt_g;
EXTERN byte rb_RainMeas_cnt_g;

/* Rain intensity Signal voltage: VCO_423 */ 
#ifdef RAIN_INTENSITY
EXTERN byte rb_RS_SigVoltage_neg_g;
EXTERN byte rb_RS_SigVoltage_abs_g;
#endif

//#endif /*_NO_RAIN_*/
EXTERN SHORT_MEMORY Flag uF_ASIC_ControlFlags_2_g;


/*! Delay for diagnostic pulse*/
EXTERN word rw_DiagRequestCounter_g;
EXTERN word rw_INTV10bit_min_g;
EXTERN word rw_INTV10bit_max_g;
EXTERN word rw_REGV_min_g;
EXTERN word rw_REGV_max_g;
EXTERN word rw_LIN_INTV10bit_min_g;
EXTERN word rw_LIN_INTV10bit_max_g;
/*! TimoutCounter for standby mode*/
EXTERN word rw_StandbyTimeOutCnt_g;
/*! Time without rain; 1 increment/sec*/
EXTERN word rw_NoRainPresentCnt_g;
EXTERN word rw_WasRainingCounter_g;


EXTERN byte rb_DiagRain_HighTime_g;
EXTERN word rw_DiagRain_LowTime_g;

EXTERN volatile unsigned char rub_real_LengthCounter;
EXTERN volatile unsigned char rub_real_PulseCounter;
EXTERN volatile unsigned char rub_LengthCounter;   //Counter of Lowtime for Rainsensor Signals freerunning


/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

EXTERN __callt void ASIC_Control_meas_Intout(void); /*measures Intout and window comparator function*/
EXTERN void ASIC_Control_RS_Meas(void);
EXTERN void ASIC_Control_MeasureStandbyMode(void);
EXTERN void ASIC_Control_CalcRSGain(void);
EXTERN byte ASIC_Control_STBCheckRain(void);
#endif


#undef EXTERN
#endif
