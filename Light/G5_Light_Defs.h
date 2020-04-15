#ifndef G5_LIGHT_DEFS_H
#define G5_LIGHT_DEFS_H

/*************************************************************************

  Company : Valeo Wiper Systems 

  Project : RLT Sensor, RDN Sensor

  Component : G5_Light_Defs.h

  Documentation reference : Lightsensor Software Stategy

  Overview of the component : variable and prottype declaration
                              for G5 light component
   Evolution of the component : see PVCS Version control system

                Initials   date   modification

*****************************************************************************/
/**************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  NAME Description                                       */
/*----------------------------------------------------------------------------*/
/* 18.09.13  -            NB  initial version                                 */
/* 17.11.15  -            SP  VDR_926. Default init value of wipe counter is set to 0   */
/****************************************************************************/
/** Definition for Mono-Inclusion **/
/****************************************************************************/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
    
    
#include "G5_projectDefs.h"
#if defined (_borland_cpp_) || defined (__QACCHECK__)
#define INLINE
#else
#define INLINE inline
#endif

#ifdef _light_defs_c_
/* PRQA S 0883 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#define EXTERN /**/
#else
#define EXTERN  extern
#endif

#ifdef PC_simulation
#include "PcSimuTypes.h"
#include "RltLightSimu.h"
#endif

/*VCO_077  adapt tunnel detection threshold*/ 
//#define rb_FwLightTunnelThresholdMax_g                       (byte) 70 //Tunnel Threshold for Forward
//#define rb_FwLightTunnelThreshodBase_g                  (byte) 25//9 //Min Threshold for Forward
//#define rb_AmbLightTunnelThresholdMin_g                  (byte) 25 
#define cb_TUNNEL_TRESHOLD_NO_SLOPE_FORWARD_MIN_mg         (byte) 10//8 //Without Slope
#define cab_FW_TUNNEL_TO_DAY_THRESHOLD_s    (rb_FW_NightLow_Threshold_g+10)


EXTERN byte rb_PosSlopeCountFWLight_mg;
#define rb_BEFORESTARTCOUNTER_mg rb_PosSlopeCountFWLight_mg 


/****************************************************************************/
// Contants for Darkstart detection
/****************************************************************************/
#define cw_DARKSTART_NIGHT_DELAY_s  (word)500  /*Delay to reach night mode from darkstart*/
#define cw_DARKSTART_DAY_DELAY_s   (byte)200     /*Delay to reach day mode from darkstart*/
#define cw_SPEED_DARKSTART_s     (byte)30        /*Speed to get out of the darkstart mode*/


/*************************************************************************
**                   Declaration of  macros                 **
**************************************************************************/

// Bits for Lightsensormode to reWrite all Bits or to check state

// Defines for Rain Light On
#define cb_WIPECOUNTERINI_mg    (byte) 0        /* Ini Value for WiperCounter*/

#define cw_RAIN_ON_DELAY_mg     (word) (cw_RAIN_ON_DELAY_KS_g)      /* Delay to switch in Rainmode*/
#define cb_RainDetectionBrightness_mg   cb_RAIN_ON_BRIGHTNESS_KS_g   /* Threshold for Rain at bright day*/
#define cab_RAIN_OFF_DELAY_mg 79 /*VCO_27 only one delay for all potistages */

//DelayTime after Reset to establish stable state
#define cb_BEFORESTARTTIME_mg    (byte) 50       // Waittime to be sure that the ASIC is on
#define cb_WAITFORCOMMUNICATIONTIME_mg  60       //Waittime to be sure that the ASIC is on

/* typ 15 sec. Times for Wipes after Washing    (bo count for rainlight wipes)*/
#define cw_DURATION_WIPE_AFTER_WASH_mg  rw_p_t_frontwaschen_Ausblend_g   

#ifdef PC_simulation /*VDR_369*/
/*VCO_077 adapt for offline simulation*/ 
#define rw_p_t_frontwaschen_Ausblend_g 300
#define rb_VeryBrightInTunnelDelay_g CB_DEF_VERYBRIGHTINTUNL_DIST_THRS_g  /*VCO_094 provide Variable for Simulation*/
#define rb_AfterTunnelThrsIsNightThrs_g 1 /*only for Simulation set to 1*/ /*VCO_094 provide Variable for Simulation*/
#define rbi_LightSensitivityRecieved_g 1
#define cb_AUDI_KS_THRESHOLD_RS_NIGHT_MODE_mg 10
#define cb_AUDI_KS_THRESHOLD_RS_DAY_MODE_mg 15
#define rb_p_v_autobahn_off_kmph_g cb_MIN_HIGHWAY_SPEED_DEF_mg /*VCO_094 use Define */
#define cw_RAIN_ON_DELAY_KS_g 600
#define cb_WIPETHRESHOLD_RAINLIGHT_BRIGHT_KS_mg 6
#define cb_WIPETHRESHOLD_RAINLIGHT_DARK_KS_mg 12
#define cb_RAIN_ON_BRIGHTNESS_KS_g 80
#define rb_Amb_TunnelThresholdScaling_g 8
#define rb_FW_TunnelThresholdScaling_g 8
#define rb_IR_TunnelThresholdScaling_g 8
#define rbi_RainLight_enabled_g 0
byte rb_WDG_LightsensorTaskCounter_g;
#define rbi_LightConfigRecieved 1
#define rbi_RealParkContact_g 1
#define rbi_UnderVoltage_g 0
#define rbi_Ignition_g 1
#define rb_AfterVddPowerFailDelay_g 0
#define rb_ROM_CheckFailureCounter_g 0
#define rbi_Powerfail_g 0
byte rbi_WashingActive_g;

// EEPROM variables
#define cb_Regulation48LightOnTime_g 0x6C
#define rb_Regulation48Threshold_g ((0x65>>4)*5) /*(about 810 lux---Value corrected for 80% transmission through glass)---(Previous Value about 1250 lux)----KI*/
#define rb_Regulation48_FW_Threshold_g ((0x65 & 0x0f) *5)  /*(FW Diode Threshold----to avoid unnecessary switching ON of Lights)----KI*/
#define rb_Night_Delay_g (cw_NIGHT_DELAY_DEF_s>>6)
#define rb_Day_Delay_g (cw_DAY_DELAY_DEF_s >> 6)
#define rb_AfterTunnelDelayOffs_g (byte) 71 // actually it is 77 but due to 10% sampling losses
#define CB_DEF_TUNNELDEBOUNCEFACTOR         45
#define rw_TimeToReachFastHighwayMode_g   cb_TIMETOREACH_FASTHIGHWAY_MODE_Def_mg
#define rw_TimeToReachNormalSpeedMode_g   cw_TIME_TO_REACH_NORMAL_MODE_DEF_mg
#define  rb_Mean_HighwayLightOnSpeed_g cb_MEAN_HIGHWAY_LIGHT_SPEED_DEF_mg
#define rb_Amb_Base_Day_Threshold_g     cb_AMB_DAY_THRESHOLD_DEF_s
#define rb_Amb_Base_Night_Threshold_g   cb_AMB_NIGHT_THRESHOLD_DEF_s
#define rb_FW_Base_Day_Threshold_g  cb_FW_DAY_THRESHOLD_DEF_s
#define rb_IR_Base_Day_Threshold_g  cb_IR_DAY_THRESHOLD_DEF_s
#define rb_FW_Base_Night_Threshold_g    cb_FW_NIGHT_THRESHOLD_DEF_s
#define rb_IR_Base_Night_Threshold_g    cb_IR_NIGHT_THRESHOLD_DEF_s

//for 0x04 it is 0x4 *2 = 8
#define rb_IrLightTunnelThreshodLow_g 8
//for 0x84 it is 8 + 2 *8 = 24
#define rb_IrLightTunnelThreshodHigh_g  24

// for 0xC4 is 4 *3 = 12
#define rb_FwLightTunnelThresholdBase_g  12
// for 0xC4 is 12 +12*5= 72
#define rb_FwLightTunnelThresholdMax_g   72

//for 0x0C it is 0xC *2 = 24
#define rb_AmbLightTunnelThresholdMin_g  24
#endif //PC_simulation


/** \brief Low Value to go into Night mode without other reciever */
#define cab_SECURE_AMB_NIGHT_THRESHOLD_s                      (byte)10   /*VDR_369*/ 
/** \brief Low Value to go into Night mode without other reciever*/
#define cab_SECURE_IR_NIGHT_THRESHOLD_s                       (byte)4    
/** \brief Low Value to go into Night mode without other reciever*/
#define cab_SECURE_NIGHT_THRESHOLD_s                          (byte)10

#define cb_IR_NIGHT_THRESHOLD_s                            (byte)10    //IR Night Threshold

/****************************************************************************/
// Contants for Night detection
/****************************************************************************/


/** \brief Delay to reach night mode from day mode*/
#define cw_NIGHT_DELAY_s          ((word)(rb_Night_Delay_g)<<6)  
/** \brief Delay to reach day mode from night mode*/
#define cw_DAY_DELAY_s            ((word)(rb_Day_Delay_g)<<6)  

/** \brief Delay to detect night in a tunnel*/
#define cw_TUNNEL_TO_NIGHT_DELAY_s       cw_NIGHT_DELAY_s  
/** \brief increment for tunnel to night if mean values are low*/
#define cb_TUNNEL_TO_NIGHT_MEAN_INC_s     500       
/** \brief Speed to count faster into night mode*/
#define cb_MIN_SPEED_FASTERCOUNTING_s    (byte)10    


/****************************************************************************/
// Contants for Darkstart detection
/****************************************************************************/



/****************************************************************************/
// Contants for Tunnel detection
/****************************************************************************/

#define cb_TUNNELMINIMUMSPEED_s               (byte)7  /*VDR_369*/ //Speed minimum to detect tunnel
#define cb_TUNNEL_MIN_TRESHOLD_AMBIENT_s      (byte)25
#define cb_IR_LONG_TUNNEL_THRESHOLD_AMBIENT_s (byte)4  //Threshold for long Tunnel
#define cw_MIN_INTUNNEL_LENGTH_s      (word)400  //Delay to reach tunnel mode in m * 72
#define cb_AFTERTUNNEL_DELAY_s           (byte)30  //Delay to get out of tunnel mode

#define CW_AFTERTUNNELDELAY_G      (cb_AFTERTUNNEL_DELAY_s+(rb_AfterTunnelDelayOffs_g))


#define CHECK_VETO_COUNTER() rbi_LightSensorVetoConflict_g=((get_rb_LightVetoCounter_g() > 0)? 1:rbi_LightSensorVetoConflict_g)



/****************************************************************************/
// Contants for Highway (lighton) detection
/****************************************************************************/

#define cb_MIN_HIGHWAY_SPEED_mg rb_p_v_autobahn_off_kmph_g

#define cb_TIME_TO_REACH_FASTHIGHWAY_MODE_mg rw_TimeToReachFastHighwayMode_g
#define cw_TIME_TO_REACH_NORMAL_MODE_mg    rw_TimeToReachNormalSpeedMode_g
#define cb_MEAN_HIGHWAY_LIGHT_SPEED_mg   rb_Mean_HighwayLightOnSpeed_g 

#define BELOW_NIGHT_THRESHOLDS() (((get_rw_Amb_light16bit_g() < rb_Amb_Night_Threshold_g) \
  &&(get_rw_FW_light16bit_g() < rb_FW_Night_Threshold_g))||((get_rw_FW_light16bit_g() < cab_SECURE_NIGHT_THRESHOLD_s)\
    ||((get_rw_Amb_light16bit_g() < cab_SECURE_AMB_NIGHT_THRESHOLD_s)\
      ||(get_rw_IR_light16bit_g() < cab_SECURE_IR_NIGHT_THRESHOLD_s)))) /*VDR_369*/



/*VCO_093 to be sure that for Day detection every light value is over night threshold */
#define ABOVE_NIGHT_THRESHOLD  ((get_rw_Amb_light16bit_g() > rb_Amb_Night_Threshold_g) \
  &&(get_rw_FW_light16bit_g() > rb_FW_Night_Threshold_g)) 

/*VCO_93 use improved avarage Value*/
#define ABOVE_DAY_THRS_VAR_ONE   ((rw_FwLightMeanSlow_g>rw_FW_Day_Threshold_g) \
  &&(rw_AmbLightMeanSlow_g > rw_Amb_Day_Threshold_g)) 


/****************************************************************************/
// General Contants
/****************************************************************************/

/****************************************************************************/
// Contants for Rainsensor Nightbit detection
/****************************************************************************/

#define cb_THRESHOLD_RS_NIGHT_MODE_mg   cb_AUDI_KS_THRESHOLD_RS_NIGHT_MODE_mg
#define cb_THRESHOLD_RS_DAY_MODE_mg     cb_AUDI_KS_THRESHOLD_RS_DAY_MODE_mg

#define cb_NIGHTBITDELAY_mg              (byte)250


/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/


//word rw_dayCounter_mg;
#define rw_AFTERTUNNELCOUNTER_mg rw_dayCounter_mg
//word rw_nightCounter_mg;
#define rw_TUNNEL_TO_NIGHT_COUNTER_mg rw_nightCounter_mg


/* brief Debounce counter to decrease of thresholds at normal Vehicle speed and to switch of the highway mode 
RLS_VCO_97 */  
EXTERN  word rw_highwayOFFtimer_mg; 
/* brief Debounce counter to activate the highway mode RLS_VCO_97*/  
EXTERN  word rw_Fasthighwaytimer_s;

/****************************************************************************/
/** Global Variables **/
/****************************************************************************/
EXTERN  word rw_WipeTime_g;
EXTERN  word rw_NoWipeTime_g;

EXTERN  byte rb_DARKSTARTDELAYCOUNTER_mg;  
EXTERN byte rb_LS_Potistage_alt_g; /*VCO_41 variable needed*/



/****************************************************************************/
// Contants for Highway (lighton) detection
/****************************************************************************/

EXTERN void light_IniToDarkstart(void);  
EXTERN void light_darkstart_calc(void); 
EXTERN void light_day_to_night_calc(void);  
EXTERN void light_night_to_day_calc(void);
EXTERN void light_tunnel_to_night_calc(void); 
EXTERN void light_day_to_tunnel_calc(void); 
EXTERN void light_tunnel_to_day_calc(void); 
EXTERN void light_rain_lighton_calculation(void); 
EXTERN void light_day_to_night_calc(void); 
EXTERN void light_highway_detection(void); 
EXTERN void light_ambientlight_mean_calc(void);    /*Umgebungshelligkeitmittelung schnell und langsam*/   
/*after Ireland test drive where dipped beam was turned off too late*/
EXTERN INLINE int light_isAboveDayThresholdVar2(void);
EXTERN int light_isAboveDayThresholdVar4(void);
/*VDR_369*/ /*VCO_093 to be sure that for Day detection every light value is over night threshold */
EXTERN INLINE int light_isAboveDayThreshold(void);
EXTERN INLINE int light_isAboveDarkstartThresholds(void);

EXTERN INLINE void light_Regulation48(void);
EXTERN void light_Threshold_cac(void);
EXTERN void IO_CalculateWiperActivity(void);

EXTERN void MODI_LIGHTSENS_RAIN_CLEAR(void);                                                                  
EXTERN void MODI_LIGHTSENS_NIGHT_DARKST_CLEAR(void);                                                          
EXTERN void MODI_LIGHTSENS_TUNNEL_SET(void); 
EXTERN void MODI_LIGHTSENS_TUNNEL_CLEAR(int doCheckLightVeto);      

EXTERN void MODI_LIGHTSENS_RAIN_SET(void);                                                                    
EXTERN void MODI_LIGHTSENS_NIGHT_BIT_SET(void);                                                               
EXTERN void MODI_LIGHTSENS_NIGHT_BIT_CLEAR(void);    

/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN
#endif
