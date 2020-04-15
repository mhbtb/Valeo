#ifndef G5_IRLIGHT_H
#define G5_IRLIGHT_H

/*************************************************************************

  Company : Valeo Wiper Systems 

  Project : RLT Sensor, RDN Sensor

  Component : IRLight.h

  Documentation reference : Lightsensor Software Stategy

  Overview of the component : variable and prottype declaration
                              for IRLight.c
   Evolution of the component : see PVCS Version control system

                Initials   date   modification

*****************************************************************************/
/**************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  NAME Description                                       */
/*----------------------------------------------------------------------------*/
/* 10.03.11  VDR_638   AL   MISRA OPTIMISATION with corrections in Source code */
/* 21.02.11  VCO_094   AL   Tunnel detection improvement*/
/* 22.11.10  VCO_087   AL   Delay for nightmode adapted*/
/* 04.Aug.10 VCO_69    PCG  moved light mode constants: cb_NIGHT_mg, cb_DAY_mg, 
                            cb_DARKSTART_mg and cb_TUNNEL_mg from irlight.c */
/* 30.Apr10  VDR_473   FS   QA-C*/
/* 24.02.10  VCO_031   AL   new adjustable values over EEPROM*/
/* 22.01.10  VCO_27    AL   rainlight switch of time independend from potistage*/
/* 08.06.09  VDR_330        Shift parameters into header, EEPROM-RainLight defines to be set here*/
/* 07.Apr-08 VDR_175        RLS_ALL ReInit LS-Algorithm with define _REINIT_LSALGO_*/
/* 26.06.08  VCO_08   AL    Add twilight Values for FAW Twilight detection*/
/* 20.08.08  VDR_24   FS    Implement Gen 3.0 Light Thresholds */
/****************************************************************************/
/** Definition for Mono-Inclusion **/
/****************************************************************************/

#include "G5_projectDefs.h"
#ifdef _light_c_
/* PRQA S 0883 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#define EXTERN /**/
#else
#define EXTERN  extern
#endif

#ifdef PC_simulation
#include "PcSimuTypes.h"
#endif




/****************************************************************************/
/** Global Variables **/
/****************************************************************************/
#ifdef PC_simulation
EXTERN byte rb_tunnel_threshold_ambient2_l;

#endif //PC_simulation

EXTERN  word rw_FW_Day_Threshold_g;
EXTERN  word rw_Amb_Day_Threshold_g;
EXTERN  word rw_Amb_DayHigh_Threshold_g;
EXTERN  word rw_FW_DayHigh_Threshold_g;
EXTERN  word rw_dayCounter_mg;
EXTERN  word rw_nightCounter_mg;
/* brief Debounce counter for the InTunneldistance */
EXTERN word rw_InTunnelDistance_mg;
EXTERN  byte rb_speed_in_kmh_g;                // car speed  in Km/h
EXTERN  byte rb_WipeCounter_g; 
EXTERN  byte rb_IR_Day_Threshold_g;
EXTERN  byte rb_Amb_Night_Threshold_g;
EXTERN  byte rb_Amb_NightLow_Threshold_g;
EXTERN  byte rb_IR_DayHigh_Threshold_g;
EXTERN  byte rb_FW_Night_Threshold_g;
EXTERN  byte rb_IR_Night_Threshold_g;
EXTERN  byte rb_FW_NightLow_Threshold_g;
EXTERN  byte rb_IR_NightLow_Threshold_g;
EXTERN  byte rb_LSPotiStage_g;                           // Sensitivity for Day Night
EXTERN  byte rb_FW_tunnel_threshold_mg;        // only for debugging as global!! //Tunnel Thrshold for forward wide
EXTERN  byte rb_FW_Tunnel_high_TempThresh_l;     // only for debugging as global!!
EXTERN  byte rb_IrLightTunnelThreshDyn_g;

#if defined (LIGHT_BASED_ON_FW_AND_IR)
//EXTERN  word rw_IRlight_low_256mean_slow_mg; /* slow mean value of IRlight_low*/
//#define rb_IRlight_low_mean_slow_mg   (byte)(rw_IRlight_low_256mean_slow_mg >> 8)

EXTERN  word rw_IRlight_high_256mean_slow_mg; /* slow mean value of IRlight_high*/
#define rb_IRlight_high_mean_slow_mg  (byte)(rw_IRlight_high_256mean_slow_mg >> 8)

EXTERN  word rw_IRlight_low_256mean_fast_mg; /* fast mean value IRlight_low*/
#define rb_IRlight_low_mean_fast_mg     (byte)(rw_IRlight_low_256mean_fast_mg >> 8)

EXTERN  word rw_IRlight_high_256mean_fast_mg; /* slow mean value of IRlight_high*/
#define rb_IRlight_high_mean_fast_mg  (byte)(rw_IRlight_high_256mean_fast_mg >> 8)

EXTERN  byte rb_IR_TunnelHighTmpThresh_l;          // for day to tunnel calculation

EXTERN  byte rb_tunnel_threshold_IR;
#endif
/****************************************************************************/
// Global Contants for Light Modes 
/****************************************************************************/
#define cb_DAY_mg    (byte)   0
#define cb_DARKSTART_mg    (byte) 1
#define cb_NIGHT_mg     (byte) 2
#define cb_TUNNEL_mg    (byte) 4
/* other defines for this are in irlight.c*/

/****************************************************************************/
// Contants for Highway (lighton) detection
/****************************************************************************/
#define cb_MEAN_HIGHWAY_LIGHT_SPEED_DEF_mg   (byte)140//155 change for VW
#define cb_TIMETOREACH_FASTHIGHWAY_MODE_Def_mg  208  //to switch light on!
#define cw_TIME_TO_REACH_NORMAL_MODE_DEF_mg      (int) 2400  // 120s -> From Highway Mode
#define cb_MIN_HIGHWAY_SPEED_DEF_mg          (byte)65

#define CB_DEF_VERYBRIGHTINTUNL_DIST_THRS_g 70 /*VCO_094 Thresehold Set for VeryBrightTunnelDetection*/
#define CB_MIN_VERYBRIGHTINTUNL_DIST_THRS_g 20  /*VCO_094 Thresehold Set for VeryBrightTunnelDetection*/
#define CB_MAX_VERYBRIGHTINTUNL_DIST_THRS_g 255 /*VCO_094 Thresehold Set for VeryBrightTunnelDetection*/

#define cw_NIGHT_DELAY_DEF_s          (word)(2*3000)  //Delay to reach night mode from day mode
#define cw_DAY_DELAY_DEF_s            (word)(2*3000)  //Delay to reach day mode from night mode

#define cb_AMB_NIGHT_THRESHOLD_DEF_s 135
#define cb_AMB_DAY_THRESHOLD_DEF_s   187

#define cb_FW_NIGHT_THRESHOLD_DEF_s  135
#define cb_FW_DAY_THRESHOLD_DEF_s    180

#define cb_IR_NIGHT_THRESHOLD_DEF_s  68
#define cb_IR_DAY_THRESHOLD_DEF_s    90

/*VDR_330 To use cb_WIPETHRESHOLD_mg in Flash EEPROM defines needed to be global defines
 * --> Formerly located in c-file, now located in header*/


#define cb_WIPETHRESHOLD_RAINLIGHT_DARK_mg             cb_WIPETHRESHOLD_RAINLIGHT_DARK_KS_mg
#define cb_WIPETHRESHOLD_RAINLIGHT_BRIGHT_mg           cb_WIPETHRESHOLD_RAINLIGHT_BRIGHT_KS_mg

/****************************************************************************/
/** structure for 16bit value with 8bit access !!!!!!!Compilerdendent! **/
/****************************************************************************/

EXTERN  word rw_AmbLightMul32MeanSlow_g; /*slow mean value of Amblight_high*/
#define rb_AmbLightDiv8MeanSlow_g  (byte)(rw_AmbLightMul32MeanSlow_g >> 8)
#define rw_AmbLightMeanSlow_g  (rw_AmbLightMul32MeanSlow_g >> 5) /* 11 bit value of AMB-Light slow filtered*/

EXTERN  word rw_AmbLightMul32MeanFast_g; /* slow mean value of IRlight_high*/
#define rw_AmbLightMeanFast_g  (rw_AmbLightMul32MeanFast_g >> 5) /* 10 bit value of AMB-Light fast filtered*/

EXTERN  word rw_FwLightMul64MeanFast_g; /* fast mean value forwardlight_high*/
#define rb_FwLightDiv4MeanFast_g   (byte)(rw_FwLightMul64MeanFast_g >> 8)

EXTERN  word rw_FwLightMul64MeanSlow_g; /* slow mean value forwardlight_high*/
#define rb_FwLightDiv4MeanSlow_g   (byte)(rw_FwLightMul64MeanSlow_g >> 8)

// calculation from high to rb_FwLightMeanSlow_g
#define rb_FwLightMeanSlow_g  ((rb_FwLightDiv4MeanSlow_g >= 64)? (byte)(0xff):(rb_FwLightDiv4MeanSlow_g<<2))
#define rw_FwLightMeanSlow_g  (rw_FwLightMul64MeanSlow_g >> 6) /* 10 bit value of FW-Light slow filtered*/

/****************************************************************************/
/** Global Flags **/
/****************************************************************************/
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN  Flag uF_Check_lightsensor_g;                 // do not change bit assignment used for error memory
#define rbi_SoftwareBug_g                   uF_Check_lightsensor_g.Bit.B4
#define rbi_Check_LS_NoCommunication_g      (uF_Check_lightsensor_g.Bit.B3)

/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN  Flag uF_modi_lightsens_g;
  // Bits of uF_modi_lightsens_g                 // do not change bit assignment
#define rbi_modi_lightsens_darkStart_g   (uF_modi_lightsens_g.Bit.B0)
#define rbi_modi_lightsens_night_g      uF_modi_lightsens_g.Bit.B1
#define rbi_modi_lightsens_tunnel_g      uF_modi_lightsens_g.Bit.B2
/*Bit 3 not used*/
/*#define rbi_modi_lightsens_beforeTunnel_g   uF_modi_lightsens_g.Bit.B3*/
#define rbi_modi_lightsens_rain_g      uF_modi_lightsens_g.Bit.B4
/*Bit 5 not used*/
/*#define rbi_modi_lightsens_forest_g     uF_modi_lightsens_g.Bit.B5*/

/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN  Flag uF_modi_lightsens_inv_g;
// Bits of uF_modi_lightsens_inv_g                 // do not change bit assignment
#define rbi_modi_lightsens_darkStart_inv_g   uF_modi_lightsens_inv_g.Bit.B0
#define rbi_modi_lightsens_night_inv_g      uF_modi_lightsens_inv_g.Bit.B1
#define rbi_modi_lightsens_tunnel_inv_g      uF_modi_lightsens_inv_g.Bit.B2
#define rbi_modi_lightsens_beforeTunnel_inv_g   uF_modi_lightsens_inv_g.Bit.B3
#define rbi_modi_lightsens_rain_inv_g      uF_modi_lightsens_inv_g.Bit.B4
#define rbi_modi_lightsens_forest_inv_g     uF_modi_lightsens_inv_g.Bit.B5

/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN  Flag uF_LightInternalStatus_g;

#define rbi_LightSensorActive_g         (uF_LightInternalStatus_g.Bit.B0)
#define rbi_LightSensorVetoConflict_g   (uF_LightInternalStatus_g.Bit.B1)
#define rbi_DoNormalCalculation_g       (uF_LightInternalStatus_g.Bit.B2)
#define rbi_night_g                     (uF_LightInternalStatus_g.Bit.B3)
#define rbi_FastHighwayMode_g           (uF_LightInternalStatus_g.Bit.B4)
#define rbi_LightSensorError_g          (uF_LightInternalStatus_g.Bit.B5)

#define rbi_Regulation48LightOnFlag_g  (uF_LightInternalStatus_g.Bit.B6)

#define rbi_SensitivityTreatmentError_g    (uF_LightInternalStatus_g.Bit.B7) /*VDR_129 Variable declaration*/

/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN  Flag uf_LightAlgoReInit_g;
#define rbi_LS_reinit_g   uf_LightAlgoReInit_g.Bit.B0
#define rbi_LSPotiStageChanged_g   uf_LightAlgoReInit_g.Bit.B1
#define rbi_LightSensorActiveChange_FromBus_g uf_LightAlgoReInit_g.Bit.B2
#define rbi_LS_reinit_init_g uf_LightAlgoReInit_g.Bit.B3


/****************************************************************************/
// Variables for bus communication
/****************************************************************************/

/** Global Constants **/

/*************************************************************************
                Declaration of exported functions
**************************************************************************/
EXTERN void light_init(void);
EXTERN void light_circulating_air_calc(void);
EXTERN void lightScheduler(void);
EXTERN word getNightCounter(void);
EXTERN word getDayCounter(void);
EXTERN word getRegulation48OffCounter(void);
EXTERN byte getRegulation48OnCounter(void);
EXTERN word getVeryBrightInTunnelDistance(void);
EXTERN word getBrightInTunnelDistance(void);


/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN
#endif
