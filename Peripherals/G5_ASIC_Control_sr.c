/*************************************************************************

Company : Valeo Schalter und Sensoren

Project : RLT Sensor Generation 5

Component : ASIC_Control_sr.c

Documentation reference : ASIC_Specification
---------------------------------------------------------------------------
Overview of the component : This module organises the interface to the ASIC
the following functions are included:
-> scheduling for light and calibration measurment
-> correction of light values
-> delogarithm of light values
-> scheduling of sensor modes init-> normal-> Standby -> Sleep
-> standby mode organisation and scheduling
-> standby mode decision

The suffix _sr means "safety relevance".
Code should be included if it is has kind of safety importance only.
---------------------------------------------------------------------------

*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Name    Description                                  */
/*----------------------------------------------------------------------------*/
/* 13.12.10  VCO_090    AL    RS_error Classification*/
/* 29.10.10  VDR_590    JS     retry once the step response if length is 0, store every length */
/* 11.Jun.10 VDR_484   FS     __callt eliminated by ASIC_Control_measure()*/
/* 29.04.10  VDR517    AL     Standby mode adapted for wake maximum time 60s*/
/* 29.04.10  VDR511_1  AL     Polyspace error 1 Correction*/
/* 14.04.10  VDR_502   FS     Use _FEUCHTE_-define instead of _VW_KONZERNSENSOR_-define*/
/* 25.03.10  VDR_446   FS     ASIC-Frequency work around update for all*/
/* 24.03.10  VDR_446   FS     ASIC-Frequency work around update for Konzernsensor*/
/* 23.03.10  VDR_446   FS     ASIC-Frequency work around*/
/* 18.03.10  VDR_446   FS       Reimplement old ASIC-Clk Trimming*/
/* 02.03.10  VCO_028   AL     Integrate Standby - Mode*/
/* 22.02.10  VDR_349   FS     Switch OFF ASIC-Frequency-Trimming with define*/
/* 16.02.10  VDR_438        adapt voltage level for Hardware H02 avoid Problems
                             at short voltage interrupts*/
/* 02.02.10  VDR_436   AL      solve Problem with undervoltage detection*/
/* 18.01.10  VDR_424   AL      increase time to change rainsensor measurement scheduling*/
/* 11.01.10  VDR_419   AL      NFW-Light Value INREC2 not correct initialised */
/* 18.12.09  VDR_398   FS      No change, just to implement latest version for Ford*/
/* 17.11.09  VDR_400   AL      FW-Light Value INAM2 not correct initialised */
/* 24.09.09  VDR_372   AL      Mesurment of NTC and usage of new microC Ports
         PWM could be switched to portpin by EEPROM
         Usage of EEPROM Cell for Amb Night and DayThreshold
         Remove EEPROM valeo for IR and FW scaling for VWK*/
/* 02.09.09  VDR_365   AL   Mesurment scheduling and calculation for INAMB
                 Spot and coupling measurement       */
/* 26.01.09  VDR_306     FS     ASIC Frequency trimming Rework*/
/* 03.12.08  VDR_285     FS     ASIC Frequency trimming*/
/* 03.02.08  VDR_87      AL     Misra Warning for MISRA Rule 52*/
/* 04.02.08  VDR_131     AL     use only 8Bit for b-correction -> reimplement VWK function*/
/* 05.02.08  VDR_132     AL     improved rain sensor error detection implement timer after fastloop*/
/****************************************************************************************************************/
/****************************************************************************************************************/
/*07.11.13  VCO_128     MP      Split of safety from non-safety functionalities.                                */
/*                              "Source code refactoring according to ASIL B                                    */
/*                              critical path separation SM135"                                                 */
/*23.09.2014 VCO_187    MP      SM 251 - detection of short on ALSx Enhanced pins                               */
/*01.10.2014 VCO_167    MP      Automatic windshield calibration                                                */
/*01.10.2014 VCO_188    AL      Implement coding of Solar sensor based on 880nm transmission                    */
/*18.11.2014 VDR_823    MP      Increase robustness of ASIC handling                                            */
/*18.11.2014 VDR_824    MP      Error counter for too long init of ASIC                                         */
/*05.02.2015 VDR_839    MP      SM250: Error counter not incrementing properly for calibration values           */
/*06.02.2015 VDR_841    MP      Diagnose pulse and extended diagnose pulse have great values sometimes          */
/*09.02.2015 VCO_220    MP      VIrefLo/Hi monitoring                                                           */
/*13.02.2015 VDR_842    MP      SignalIntegral increments once after gain adjustment measurement                */
/*03.03.2015 VCO_227    NB      Implement RAM Guard function                                                    */
/*10.03.2015 VCO_227    NB      Implement RAM Guard function                                                    */
/*16.03.2015 VDR_855    MP      Fix of the findings from the review of ASIC_Control_sr                          */
/*19.03.2015 VDR_858    NB      Remove disable/enable ramguard for non RAM_GUARD variable                       */
/*24.03.2015 VDR_862    MP      Read of ALSx after 1,5ms after setting the MUX                                  */
/*01.04.2015 VCO_239    MP      Light values filter defined in EEPROM                                           */
/*04.05.2015 VDR_871    NB      Safety: all reset sources from RESF should be used except the voltage           */
/********************************detector flag                                                                  */
/*11.05.2015 VDR_875    MP      Error flag for wrong mux resets before the error counter was 0                  */
/*13.05.2015 VDR_880    MP      Current consumption and wakeup fast response in standby mode                    */
/*21.05.2015 VCO_253    MP      Measurement of optical coupling at start up                                     */
/*13.07.2015 VDR_891    MP      SWITS_635: SPI communication error not set when the ASIC mode is corrupted      */
/********************************only once per cycle                                                            */
/*14.07.2015 VDR_893    MP      When short of LEDA or LEDB to GND, ASIC resets continuously                     */
/*19.11.2015 VDR_928    NB     Internal Reset is not detected when both bootloader and application is flashed together*/
/*11.04.17   VDR_1029 NB     LIN communication failure during battery voltage ramp test */

/****************************************************************************************************************/
/****************************************************************************************************************/
/**
* \mainpage Rain Light Anti-Fogging Sensor
<!-- * \htmlinclude ASIC_Controlc.html           -->
* \section intro_sec Introduction
*
* This document is generated automatically with doxygen, with the help of tags in
* the source code.
*
* \section install_sec Description of the different tabs
*
* \subsection step1 Main Page:
* The main tab contains a small introduction over the contents of this file.
*
* \subsection step2 Module / Interface Specification:
* Gives an overview over the Interface should be renamed to Interface Specification,
* but at the moment it is not possible to rename it.
*
* \subsection step3 Data Structures:
* The Data Structures tab contains a brief description of all specified data structures and data fields.
*
* \subsection step4 Files:
* The Files tab contains a brief description of all module files.
*
* \subsection step5 Related Pages:
* The Related Pages contains all existing pages for the FlashE2 module e.g. Integration Guidline, Compile Options,... .
*
* \file ASIC_Control.c
* \brief C File for the Emulated EEPROM Handling "ASIC_Control Modul".
*
* This module managed the communication between the ASIC E101.12 and the microController
* This component is responsible for the handling of the rain light sensor ASIC E101.12.
* The function ASIC_Control_init() of this component is called from main_loop or from the 500 microSec interrupt.
* <!--  -->
* _b Source:     ASIC_Control.c
* _version       1.12
* _author        Andreas Laegler
* _author        SBA294
* _date          26-JUL-2007 08:08:38
* _todo          Still open points here
* <!--  -->

*/
/******************************************************************************/
/*                  Integration Guidline                                      */
/******************************************************************************/

/**
* \page integration Integration Guidline
* </p>
* <h2>Function calls</h2>
* <p>
* The application calls the function ASIC_Control_init() during cyclic all 10ms
* the function ASIC_Control_dot5msTask(void)have to be called every 500 microSec.
* the function  ASIC_Control_meas_Intout() have to be called every 1000 microSec if the modulator is active.
*
* For the AD-Concersion the ADC-Interrupt is used, the communication to the AD-Interrupt is done by global variables
*
* </p>
* <h2>Output variables</h2>
* <p>
* Errors are monitored eighter in the deticated return values or in the global
* variables.
*
* </p>
*/

/******************************************************************************/
/*                             Compile options                                */
/******************************************************************************/

/**
* \page compileoptions Compile options
* </p>
* <h2>none compile options</h2>
* <p>
* </p>
*
* </p>
*/
/* PRQA S 0434,0436,0781,4130 EOF */
/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/* PRQA S 5540,5560,5565,5900 EOF *//*<< Data needs to be verified  >>*/
/* PRQA S 3138 EOF */ /* << using of macros from automatic generated code >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/

/*************************************************************************
**                   Common and module include-file                     **
**************************************************************************/
#include "ior5f109be.h"    /*common header file*/
//#include <intrinsics.h>
#include "G5_projectDefs.h"

#define _G5_ASIC_Control_Defs_sr_
#define _G5_ASIC_Control_sr_c_

#include "G5_ASIC_Control_sr.h"
#include "G5_ASIC_Control_Defs_sr.h"

#undef _G5_ASIC_Control_sr_c_
#undef _G5_ASIC_Control_Defs_sr_

/*************************************************************************
**                   Other files included                               **
**************************************************************************/
#include "G5_ASIC_Control.h"
#include "G5_Appli_timer.h"
#include "G5_io_sen.h"
#include "G5_io.h"
#include "G5_spi_sr.h"
#include "G5_rainsens.h"
#include "G5_rls_linst.h"
#include "G5_Appli_main.h"
#include "G5_Appli_lowinit.h"
#include "G5_rs_def.h"
#include "G5_diagnose.h"

#include "G5_flashe2.h"

#include "G5_Check_sr.h"
#include "ior5f109be_ext.h"
#include "G5_E2Handler.h"
#include <intrinsics.h>
#ifdef STANDBY_LIN_WAKE_UP_ISSUE //VCO_477  added this for can not be waked up when it is in standby mode
#include "G5_lininclude.h"
#endif
/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/

/*! Variable to control the light measured Value*/
static byte rb_Asic_measureMode_mg;
static byte rb_old_ASIC_Sched_Config_g;

/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

static byte rb_wait500us_g = 0;
/*flag for LEDA and LEDB measurements*/
static byte rb_VLEDx_inLClosed_g;
static byte rb_LEDx_newval_g;

#endif /*_NO_RAIN_*/
byte rb_STATH_Reg_g=0;
byte rb_STATL_Reg_g=0;

/*! Next command that needs to be sent immediatly via SPI*/
byte rb_NextSPI_Request_g=CB_NO_NEXT_RQ;
/*! Next MUX config to be sent to SPI*/
byte rb_NextMUXCfg_g = NO_CURRENT_MEAS;
byte rb_CrtMUXCfg_g = NO_CURRENT_MEAS;
/*! New AD conversion was read out through SPI*/
byte rb_newADconvRcv_g=0;
/*! Counter for no AD conversion received*/
byte rb_StaticNoValidAD_cnt_g = 0;
/*! Incremental counters for not trimming to specified ASIC frequency*/
byte rb_FreqNotTrimmedCounter_g=0;
/*! Incremental counters for not having the expected values for the ASIC registers*/
byte rb_ASICReg_NoValidVals_cnt_g = 0;

/*! ASCI current and previous mode*/
byte rb_CurMode_g = 0;
byte rb_PrevMode_g = 0xFF;

/*!new VDDx received flag*/
byte rb_VDDx_received_g;

/*! Maximum number of Error Counter for Light Signals for debugging*/
byte rb_Vref_LightSignalErrorCnt_g;
/*! Maximum number of Error Counter for Light Signals for debugging*/
byte rb_VDD_LightSignalErrorCnt_g;
byte rb_LightSignalErrorCnt_g;
/*! Variable to calculate possible frequency-trimming, used to differ, if frequency trimming or diagnostics has changed EEPROM */
byte rb_MaxLightSignalErrorCnt_g;
byte rab_IntegrationTimePointer_mg;  /*VCO_028 reduce sample time if not stable*/


byte rb_Startup_STBY_meas_on_l=TRUE;
#ifdef STARTUP_WIPE 
word rw_Nom_deltaINTV_l;
word rw_ref2_deltaINTV_g;
word rw_ref_deltaINTV_l;
word rw_deltaINTV_Comp_l;
byte rb_Startup_Wipe_g = FALSE;
byte rb_Startup_Wipe_detected_g = 0;
byte rw_ref_deltaINTV_cnt_l;
word aw_ref_deltaINTV_buffer[4] = {0x00, 0x00, 0x00, 0x00};
byte rd_Aussentemp_g;
#endif

#pragma dataseg="RAM_GUARD"
/*! Error when the checksum for read commands contains additional 0x55 (depending on errors in ASIC STAT registers)*/
__no_init byte rb_ASIC_SPI_ErrorFlag_g;
/*! Error counter for V_LEDx in LStop*/
static __no_init byte rb_LEDx_LStop_error_cnt_g;
/*! 16bit Value for Ambient-Light*/
static __no_init word rw_Amb_light16bit_g;
/*! 16bit Value for Ambient-Light with V_INC*/
static __no_init word rw_Amb_INC_light16bit_g;
/*! 16bit Value for FW-Light*/
static __no_init word rw_FW_light16bit_g;
#ifdef HUD_FUNCTION
static __no_init unsigned long rl_HUD_light32bit_g;/*VCO_477 Blake_Used for HUD*/
#endif
/*! 16bit Value for FW-Light with V_INC*/
static __no_init word rw_FW_INC_light16bit_g;
/*! 16bit Value for IR-Light*/
static __no_init word rw_IR_light16bit_g;
/*! 16bit Value for IR-Light with V_INC*/
static __no_init word rw_IR_INC_light16bit_g;
/*! ASIC instant and average AD results for the ALSx*/
static __no_init ASIC_ALSxADval_t ras_ASIC_ALSxADval_g[CB_SIZE_OF_ASIC_ALSx_g];
/*! ASIC instant and average AD results during ALI calibration*/
static __no_init ASIC_ALI_Meas_t ras_ASIC_ALI_CalibAD_g[CB_SIZE_OF_ASIC_CALIB_g];
#pragma dataseg=default

/*! 16bit threshold for Ambient-Light with V_INC*/
static word rw_Amb_INC_light16bit_thrs_g;
/*! 16bit threshold for FW-Light with V_INC*/
static word rw_FW_INC_light16bit_thrs_g;
/*! 16bit threshold for IR-Light with V_INC*/
static word rw_IR_INC_light16bit_thrs_g;
/*! Timout counter, used for several wait functions*/
word rw_TimeOutCounter_s;
/*! Array to store the ADC-Results*/
static word raw_ANALO_INPUT_ASIC_x_g[CB_NUMBER_OF_AOUT_SIG]; /*VDR_372*/

/*! Average Value of VIcal and VIref used for compensation of Voff*/
static word rw_Vref_plusVoff_g;

#ifdef SECOND_ENTER_STANDBY
static word rw_TIME_FOR_RAINSENSOR_INIT = 120; // first is low , 
#endif
/*if the rain functionality is disabled*/
#ifdef _NO_RAIN_

/*! ASIC registers' addresses, values and access type (r/w)*/
ASIC_Reg_t ras_ASIC_CtrReg_g[CB_NUMBER_OF_REG_ASIC10113_g] = {
  /*    MCTR              ACTR                STATH             STATL             TRIM        */
  {0x2,0x0,0x0},     {0x3,0x85,0x1},      {0x10,0x0,0x2},   {0x11,0x0,0x2},   {0x12,0x80,0x1},
  /*    ADCVH             ADCVL             AVGVH             AVGVL   */
  {0x18,0xFF,0x2},  {0x19,0xFF,0x2},   {0x1A,0xFF,0x2}, {0x1B,0xFF,0x2},
};
/*! init values for the ASIC's registers*/
static byte rab_ASIC_CtrReg_DEFAULT[CB_NUMBER_OF_REG_ASIC10113_g] = {0x0,0x85,0x0,0x0,0x80,0xFF,0xFF,0xFF,0xFF,};

#else

static word rw_NoRainPresentCntThrsh_g;


/*! ASIC registers' addresses, values and access type (r/w)*/
ASIC_Reg_t ras_ASIC_CtrReg_g[CB_NUMBER_OF_REG_ASIC10112_g] = {
  /*    GCTR              HCTR              MCTR              ACTR    */
  {0x0,0x0,0x0},    {0x1,0x24,0x0},   {0x2,0x0,0x0},     {0x3,0x85,0x0},
  /*    LCTR              RCTR              PCO              ICO1H    */
  {0x4,0x0,0x0},    {0x5,0x80,0x0},   {0x6,0x80,0x0},   {0x7,0x80,0x0},    
  /*    ICO1L             ICO2H             ICO2L             RREGH   */
  {0x8,0x0,0x0},    {0x9,0x80,0x0},   {0xA,0x0,0x0},    {0xB,0x80,0x0},    
  /*    RREGL             REGVH             REGVL             DIAGV   */
  {0xC,0x0,0x0},   {0xD,0x80,0x0},   {0xE,0x0,0x0},    {0xF,0x80,0x1},    
  /*    STATH             STATL             TRIM              RFCTR   */
  {0x10,0x0,0x2},   {0x11,0x0,0x2},   {0x12,0x80,0x0},  {0x13,0x81,0x0},    
  /*    INTVH             INTVL             INTCO             AFSTHR  */
  {0x14,0x80,0x0},   {0x15,0x0,0x0},  {0x16,0x80,0x0},  {0x17,0xFF,0x1},  
  /*    ADCVH             ADCVL             AVGVH             AVGVL   */
  {0x18,0xFF,0x2},  {0x19,0xFF,0x2},   {0x1A,0xFF,0x2}, {0x1B,0xFF,0x2},
};
/*! Init values for the ASIC's registers*/
static byte rab_ASIC_CtrReg_DEFAULT[CB_NUMBER_OF_REG_ASIC10112_g] = {0x80,0x24,0x0,0x85,0x0, 0x80,0x80,0x80,0x0,0x80, 0x0,0x80,0x0,0x80,0x0,
                                           0x80,0x0,0x0,0x80,0x81, 0x80,0x0,0xFF,0x80,0xFF, 0xFF,0xFF,0xFF,};
#endif
static const __far ASIC_ALI_CalibAD_Limits_t caw_ASIC_ALI_CalibAD_Limits_g[11] = { {148, 476}, {606, 947}, {155, 538},
                                                                       {546, 942}, {591, 882}, {141, 537}, {160, 487},
                                                                       {619, 957}, {558, 952}, {153, 548}, {168, 548},};

/*************************************************************************
**                   Declaration of local module functions              **
**************************************************************************/
static void ASIC_Control_NormalOperation(void);
static void ASIC_Control_ALS1_LightValScl(byte rb_filter_l);
static void ASIC_Control_ALS2_LightValScl(byte rb_filter_l);
static word ASIC_Control_ALS2_INC_LightValScl(byte rb_filter_l, word rw_temp_ALS2_INC_ASIC_l);/*SM260: Light values from ALSx_INC used in the veto_counter*/
static void ASIC_Control_ALS5_LightValScl(byte rb_filter_l);
#ifdef HUD_FUNCTION
static void ASIC_Control_HUD_LightValScl(byte rb_filter_l);  /**VCO_477Blake_Used_For_HUD*/
#endif
static word ASIC_Control_ALS5_INC_LightValScl(byte rb_filter_l, word rw_temp_ALS5_INC_ASIC_l);/*SM260: Light values from ALSx_INC used in the veto_counter*/
static void ASIC_Control_ALS6_LightValScl(byte rb_filter_l);
static void ASIC_Control_INMODON_LightValScl(void); /*VDR_365 implement coupling measurement*/
static void ASIC_Control_INREC_LightValScl(byte rb_filterInrec_l);
static word ASIC_Control_INREC_INC_LightValScl(byte rb_filterInrec_l, word rw_temp_REC_INC_ASIC_l);/*SM260: Light values from ALSx_INC used in the veto_counter*/

static unsigned long ASIC_Control_DelogLightValue(word rw_CorrectedVoltage_l, word u32_PotenzScalingfaktor_l, byte rb_WindshieldTransPerCent_l,byte rb_negativeSign_l );
static word ASIC_Control_LightValueCorrect(word rw_LightVoltage_l, word rw_a_Faktor_l, byte rb_MUX_cfg_ALSx_l);
static void ASIC_Control_Signal_Check(void);
static void ASIC_Control_init(void);

static void ASIC_Control_Delay(byte rb_Delay_l);
static void ASIC_Control_LIN_GoToSleep(void);

/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
static void ASIC_Control_LoadEEP_RegDefVal(void);
static void ASIC_Control_LoopMode(void);
static void ASIC_Control_STBY_Meas(void);

#endif /*_NO_RAIN_*/

static void ASIC_Control_SendReadADCmd(void);
//void ASIC_Control_AsicStatus(void);
static void ASIC_Control_StoreADVal(void);
//void ASIC_Control_ASIC_ErrFlags_Check(void);
//void ASIC_Control_ChangeModeCmd(const byte next_mode);
static void ASIC_Control_ALSxINCShortDetect(void);
static void ASIC_Control_Startup_Init(void);
static void ASIC_Control_measure(void);

static void set_rw_Amb_light16bit_g(word rw_Value_l);
static void set_rw_FW_light16bit_g(word rw_Value_l);
#ifdef HUD_FUNCTION
static void set_rl_HUD_light32bit_g(unsigned long rw_Value_l);  /*VCO_477 Blake used for HUD*/
#endif
static void set_rw_IR_light16bit_g(word rw_Value_l);
static void set_rw_Amb_INC_light16bit_g(word rw_Value_l);
static void set_rw_FW_INC_light16bit_g(word rw_Value_l);
static void set_rw_IR_INC_light16bit_g(word rw_Value_l);
static void set_ras_ASIC_ALSxADval_g_AD(byte rb_position_l, word rw_value_l);
static void set_ras_ASIC_ALSxADval_g_AVG(byte rb_position_l, word rw_value_l);
static void set_ras_ASIC_ALSxADval_g_INC_AD(byte rb_position_l, word rw_value_l);
static void set_ras_ASIC_ALSxADval_g_INC_AVG(byte rb_position_l, word rw_value_l);
static void set_ras_ASIC_ALI_CalibAD_g_AD(byte rb_position_l, word rw_value_l);
static void set_ras_ASIC_ALI_CalibAD_g_AVG(byte rb_position_l, word rw_value_l);

/*************************************************************************
**                   Declaration of local module macros                 **
**************************************************************************/


 
/*! Macro to read AD Result*/
#define rw_INREC_ASIC_g                 ras_ASIC_ALSxADval_g[IDX_INREC_AD].avg
/*! Macro to read AD Result*/
#define rw_INREC_INC_ASIC_g             ras_ASIC_ALSxADval_g[IDX_INREC_AD].avginc
/*! Macro to read AD Result*/
#define rw_ALS2_ASIC_g                  ras_ASIC_ALSxADval_g[IDX_ALS2_AD].avg
/** \brief macro to read AD Result*/
#define rw_ALS2_INC_ASIC_g              ras_ASIC_ALSxADval_g[IDX_ALS2_AD].avginc
/*! Macro to read AD Result*/
/*#define rw_ALS4_ASIC_g                  ras_ASIC_ALSxADval_g[IDX_ALS4_AD].avg*/
/*! Macro to read AD Result*/
/*#define rw_ALS4_INC_ASIC_g              ras_ASIC_ALSxADval_g[IDX_ALS4_AD].avginc*/
/*! Macro to read AD Result*/
#define rw_ALS5_ASIC_g                  ras_ASIC_ALSxADval_g[IDX_ALS5_AD].avg
/** \brief macro to read AD Result*/
#define rw_ALS5_INC_ASIC_g              ras_ASIC_ALSxADval_g[IDX_ALS5_AD].avginc
/*! Macro to read AD Result*/
#define rw_ALS1_ASIC_g                  ras_ASIC_ALSxADval_g[IDX_ALS1_AD].avg
/*! Macro to read AD Result*/
/*#define rw_ALS3_ASIC_g                  ras_ASIC_ALSxADval_g[IDX_ALS3_AD].avg*/
/*! Macro to read AD Result*/
#define rw_ALS6_ASIC_g                  ras_ASIC_ALSxADval_g[IDX_ALS6_AD].avg

/*! Macro to read AD Result*/
#define rw_VILO_IHI_GLO_ASIC_g                  ras_ASIC_ALI_CalibAD_g[IDX_CAL_ILO_IHI_GLO_AD].avg
/*! Macro to read AD Result*/
#define rw_VIHI_ILO_GLO_ASIC_g                  ras_ASIC_ALI_CalibAD_g[IDX_CAL_IHI_ILO_GLO_AD].avg
/** \brief macro to read AD Result*/
#define rw_VILO_ICALLO_GHI_ASIC_g               ras_ASIC_ALI_CalibAD_g[IDX_CAL_ILO_ICALLO_GHI_AD].avg
/*! Macro to read AD Result*/
#define rw_VIHI_ICALHI_GHI_ASIC_g               ras_ASIC_ALI_CalibAD_g[IDX_CAL_IHI_ICALHI_GHI_AD].avg
/*! Macro to read AD Result*/
#define rw_VICALLO_ILO_GHI_ASIC_g               ras_ASIC_ALI_CalibAD_g[IDX_CAL_ICALLO_ILO_GHI_AD].avg
/*! Macro to read AD Result*/
#define rw_VICALHI_IHI_GHI_ASIC_g               ras_ASIC_ALI_CalibAD_g[IDX_CAL_ICALHI_IHI_GHI_AD].avg
/*! Macro to read AD Result*/
#define rw_VILO_IHI_GLO_INC_ASIC_g              ras_ASIC_ALI_CalibAD_g[IDX_CAL_ILO_IHI_GLO_INC_AD].avg
/*! Macro to read AD Result*/
#define rw_VIHI_ILO_GLO_INC_ASIC_g              ras_ASIC_ALI_CalibAD_g[IDX_CAL_IHI_ILO_GLO_INC_AD].avg
/*! Macro to read AD Result*/
#define rw_VIHI_ICALHI_GHI_INC_ASIC_g           ras_ASIC_ALI_CalibAD_g[IDX_CAL_IHI_ICALHI_GHI_INC_AD].avg
/*! Macro to read AD Result*/
#define rw_VICALHI_IHI_GHI_INC_ASIC_g           ras_ASIC_ALI_CalibAD_g[IDX_CAL_ICALHI_IHI_GHI_INC_AD].avg
/*! Macro to read AD Result*/
/*VDR_839 SM250: Error counter not incrementing properly for calibration values*/
/*#define rw_VILO_ICALLO_GHI_INC_ASIC_g           ras_ASIC_ALI_CalibAD_g[IDX_CAL_ILO_ICALLO_GHI_INC_AD].avg*/

/*! Reaching this value the ASIC will be reseted*/
#define CB_LIGHT_ERROR_RESTART_THRS       0x07

/*! Do not use less than 100 (not to lose resolution in delog calc.*/
/*! Skalierwert fuer die Rueckrechnung in den linearen Bereich*100  min (10000- max 0xffff)*/
#define POTENZ_SCALING_INALS1 0xffffU

/*! Skalierwert fuer die Rueckrechnung in den linearen Bereich*100  min (10000- max 0xffff)*/
#define POTENZ_SCALING_INALS2 0xffffU

/*! Skalierwert fuer die Rueckrechnung in den linearen Bereich*100  min (10000- max 0xffff)*/
#define POTENZ_SCALING_INALS5 0xffffU

/*! Skalierwert fuer die Rueckrechnung in den linearen Bereich*100  min (10000- max 0xffff)*/
#define POTENZ_SCALING_INALS6 0xffffU

/*! Skalierwert fuer die Rueckrechnung in den linearen Bereich*100 min (10000- max 640000)*/
#define POTENZ_SCALING_INREC  0xffffU //6000

/** \brief ********** module Global defines ***********/
/** \brief time microcontroller stop measurement in standby mode*/


/* CDIV256 freq and tolerance*/
/*nominal */
#define CB_CDIV256_PERIOD_NOM 0x200           /*8MHz*/
#define CB_CDIV256_PERIOD_MIN 0x1C7           /*9MHz*/
#define CB_CDIV256_PERIOD_MAX 0x249           /*7MHz*/
/* CDIV256 tol: 1.5% from the the nominal 512 is considered*/
#define CB_CDIV256_PERIOD_TOL 8


/*! Timeout in cycles for standby mode  0xffff = disabled!*/
#define CW_STANDBY_TIMOUT 60000
/*! Time for rainsensor initialisation multiplie by 10ms*/
#ifdef  SECOND_ENTER_STANDBY
#define TIME_FOR_RAINSENSOR_INIT   890
#else
#define TIME_FOR_RAINSENSOR_INIT   250
#endif


/*! State for ASIC Control Mode*/
#define CASE_WAIT_INIT_LIGHT 5
/*! State for ASIC Control Mode*/
#define CASE_WAIT_INIT_LIGHT_2 6 /*VDR_365 new state*/
/*! State for ASIC Control Mode*/
#define CASE_WAIT_INIT_LIGHT_3 7 /*VDR_365 new state*/
/*! State for ASIC Control Mode*/
#define CASE_WAIT_INIT_LIGHT_4 8 /*VDR_365 new state*/


// Values to check correct function of the sensor
/*! Value limit for Vref out of boarder*/
#define cw_VREF_MAX_g    613
/*! Value limit for Vref out of boarder*/
#define cw_VREF_MIN_g    542

/*! Max recommended value for VDDA from datasheet*/
#define cw_VDDA_ASIC_RECOM_MAX_g    475
/*! Min recommended value for VDDA from datasheet*/
#define cw_VDDA_ASIC_RECOM_MIN_g    380
/*! Max recommended value for VDDD from datasheet*/
#define cw_VDDD_ASIC_RECOM_MAX_g    (cw_VDDA_ASIC_RECOM_MAX_g+1)
/*! Min recommended value for VDDD from datasheet*/
#define cw_VDDD_ASIC_RECOM_MIN_g    (cw_VDDA_ASIC_RECOM_MIN_g-15)
/*! Min value for VDDA from datasheet*/
/*#define cw_VDDA_ASIC_MIN_g          291*/
/*! Min value for VDDD from datasheet*/
/*#define cw_VDDD_ASIC_MIN_g          264*/


void set_ASIC_ALSxADval_Init(void)
{
  byte rb_loopCnt_l;
  DisableRamGuard();
  for (rb_loopCnt_l = 0 ;rb_loopCnt_l<CB_SIZE_OF_ASIC_ALSx_g ;rb_loopCnt_l++)
  {
    ras_ASIC_ALSxADval_g[rb_loopCnt_l].ad = 0x3FF;
    ras_ASIC_ALSxADval_g[rb_loopCnt_l].adinc = 0x3FF;
    ras_ASIC_ALSxADval_g[rb_loopCnt_l].avg = 0x3FF;
    ras_ASIC_ALSxADval_g[rb_loopCnt_l].avginc = 0x3FF;
  }
  EnableRamGuard(); 
}


word get_rw_Amb_light16bit_g(void){
#if defined (GEN_35A)
  return rw_FW_light16bit_g;
#else  
  return rw_Amb_light16bit_g;
#endif
}

word get_rw_FW_light16bit_g(void){
  return rw_FW_light16bit_g;
}

#ifdef HUD_FUNCTION
/*Blake_Used_For HUD VCO_477*/ 
unsigned long get_rl_HUD_light32bit_g(void){
  return rl_HUD_light32bit_g;
}
#endif

word get_rw_IR_light16bit_g(void){
  return rw_IR_light16bit_g;
}

word get_rw_Amb_INC_light16bit_g(void){
#if defined (GEN_35A)
  return rw_FW_INC_light16bit_g;
#else
  return rw_Amb_INC_light16bit_g;
#endif  
}

word get_rw_Amb_INC_light16bit_thrs_g(void){
#if defined (GEN_35A)  
  return rw_FW_INC_light16bit_thrs_g;
#else  
  return rw_Amb_INC_light16bit_thrs_g;
#endif  
}

word get_rw_FW_INC_light16bit_g(void){
  return rw_FW_INC_light16bit_g;
}

word get_rw_FW_INC_light16bit_thrs_g(void){
  return rw_FW_INC_light16bit_thrs_g;
}

word get_rw_IR_INC_light16bit_g(void){
  return rw_IR_INC_light16bit_g;
}

word get_rw_IR_INC_light16bit_thrs_g(void){
  return rw_IR_INC_light16bit_thrs_g;
}

word get_rw_ALS1_ASIC_g(void){
  return rw_ALS1_ASIC_g;
}

word get_rw_ALS2_ASIC_g(void){
  return rw_ALS2_ASIC_g;
}

word get_rw_ALS2_INC_ASIC_g(void){
  return rw_ALS2_INC_ASIC_g;
}
/*ALS3, ALS4 are not connected*/
/*word get_rw_ALS3_ASIC_g(void){
  return rw_ALS3_ASIC_g;
}*/

/*ALS3, ALS4 are not connected*/
/*word get_rw_ALS4_ASIC_g(void){
  return rw_ALS4_ASIC_g;
}*/

/*ALS3, ALS4 are not connected*/
/*word get_rw_ALS4_INC_ASIC_g(void){
  return rw_ALS4_INC_ASIC_g;
}*/

word get_rw_ALS5_ASIC_g(void){
  return rw_ALS5_ASIC_g;
}

word get_rw_ALS5_INC_ASIC_g(void){
  return rw_ALS5_INC_ASIC_g;
}

word get_rw_ALS6_ASIC_g(void){
  return rw_ALS6_ASIC_g;
}

word get_rw_INREC_ASIC_g(void){
  return rw_INREC_ASIC_g;
}

word get_rw_INREC_INC_ASIC_g(void){
  return rw_INREC_INC_ASIC_g;
}

byte get_rb_LightSignalErrorCnt_g(void){
  return rb_LightSignalErrorCnt_g;
}

void set_rb_LightSignalErrorCnt_g(byte temp_LightSignalErrorCnt){
  rb_LightSignalErrorCnt_g = temp_LightSignalErrorCnt;
}

byte get_rb_MaxLightSignalErrorCnt_g(void){
  return rb_MaxLightSignalErrorCnt_g;
}

byte get_rb_ASICReg_NoValidVals_cnt_g(void){
  return rb_ASICReg_NoValidVals_cnt_g;
}

byte get_rb_Vref_LightSignalErrorCnt_g(void){
  return rb_Vref_LightSignalErrorCnt_g;
}

/*to set the initial value at start-up*/
void set_rb_Vref_LightSignalErrorCnt_g(byte Vref_LightSignalErrorCnt)
{
  rb_Vref_LightSignalErrorCnt_g = Vref_LightSignalErrorCnt;
}

byte get_rb_VDD_LightSignalErrorCnt_g(void)
{
  return rb_VDD_LightSignalErrorCnt_g;
}

void set_rb_VDD_LightSignalErrorCnt_g(byte a)
{
  rb_VDD_LightSignalErrorCnt_g = a;
}

byte get_rb_Asic_measureMode_mg(void)
{
  return rb_Asic_measureMode_mg;
}

void set_rb_Asic_measureMode_mg(byte a)
{
  rb_Asic_measureMode_mg = a;
}

byte get_rb_LEDx_LStop_error_cnt_g(void)
{
  return rb_LEDx_LStop_error_cnt_g;
}

void set_rb_LEDx_LStop_error_cnt_g(byte a)
{
  DisableRamGuard();
  rb_LEDx_LStop_error_cnt_g = a;
  EnableRamGuard(); 
}

static void set_rw_Amb_light16bit_g(word rw_Value_l)
{
  DisableRamGuard();
  rw_Amb_light16bit_g = rw_Value_l;
  EnableRamGuard();
}
static void set_rw_FW_light16bit_g(word rw_Value_l)
{
  DisableRamGuard();
  rw_FW_light16bit_g = rw_Value_l;
  EnableRamGuard();
}
#ifdef HUD_FUNCTION
/**Blake used for HUD VCO_477**/
static void set_rl_HUD_light32bit_g(unsigned long rw_Value_l)
{
  DisableRamGuard();
  rl_HUD_light32bit_g = rw_Value_l; 
  EnableRamGuard();
}
#endif

static void set_rw_IR_light16bit_g(word rw_Value_l)
{
  DisableRamGuard();
  rw_IR_light16bit_g = rw_Value_l;
  EnableRamGuard();
}

static void set_rw_Amb_INC_light16bit_g(word rw_Value_l)
{
  DisableRamGuard();
  rw_Amb_INC_light16bit_g = rw_Value_l;
  EnableRamGuard();
}
static void set_rw_FW_INC_light16bit_g(word rw_Value_l)
{
  DisableRamGuard();
  rw_FW_INC_light16bit_g = rw_Value_l;
  EnableRamGuard();
}
static void set_rw_IR_INC_light16bit_g(word rw_Value_l)
{
  DisableRamGuard();
  rw_IR_INC_light16bit_g = rw_Value_l;
  EnableRamGuard();
}

static void set_ras_ASIC_ALSxADval_g_AD(byte rb_position_l, word rw_value_l)
{
  DisableRamGuard();
  ras_ASIC_ALSxADval_g[rb_position_l].ad = rw_value_l;
  EnableRamGuard();
}


static void set_ras_ASIC_ALSxADval_g_AVG(byte rb_position_l, word rw_value_l)
{
  DisableRamGuard();
  ras_ASIC_ALSxADval_g[rb_position_l].avg = rw_value_l;
  EnableRamGuard();
}

static void set_ras_ASIC_ALSxADval_g_INC_AD(byte rb_position_l, word rw_value_l)
{
  DisableRamGuard();
  ras_ASIC_ALSxADval_g[rb_position_l].adinc = rw_value_l;
  EnableRamGuard();
}


static void set_ras_ASIC_ALSxADval_g_INC_AVG(byte rb_position_l, word rw_value_l)
{
  DisableRamGuard();
  ras_ASIC_ALSxADval_g[rb_position_l].avginc = rw_value_l;
  EnableRamGuard();
}



static void set_ras_ASIC_ALI_CalibAD_g_AD(byte rb_position_l, word rw_value_l)
{
  DisableRamGuard();
  ras_ASIC_ALI_CalibAD_g[rb_position_l].ad = rw_value_l;
  EnableRamGuard();
}
static void set_ras_ASIC_ALI_CalibAD_g_AVG(byte rb_position_l, word rw_value_l)
{
  DisableRamGuard();
  ras_ASIC_ALI_CalibAD_g[rb_position_l].avg = rw_value_l;
  EnableRamGuard();
}

word get_rw_VILO_IHI_GLO_ASIC_g(void)       
{
return(rw_VILO_IHI_GLO_ASIC_g);
}
word get_rw_VIHI_ILO_GLO_ASIC_g(void)       
{
return(rw_VIHI_ILO_GLO_ASIC_g);
}
word get_rw_VILO_ICALLO_GHI_ASIC_g(void)    
{
return(rw_VILO_ICALLO_GHI_ASIC_g);
}
word get_rw_VIHI_ICALHI_GHI_ASIC_g(void)    
{
return(rw_VIHI_ICALHI_GHI_ASIC_g);
}
word get_rw_VICALLO_ILO_GHI_ASIC_g(void)    
{
return(rw_VICALLO_ILO_GHI_ASIC_g);
}
word get_rw_VICALHI_IHI_GHI_ASIC_g(void)    
{
return(rw_VICALHI_IHI_GHI_ASIC_g);
}
word get_rw_VILO_IHI_GLO_INC_ASIC_g(void)   
{
return(rw_VILO_IHI_GLO_INC_ASIC_g);
}
word get_rw_VIHI_ILO_GLO_INC_ASIC_g(void)   
{
return(rw_VIHI_ILO_GLO_INC_ASIC_g);
}
word get_rw_VIHI_ICALHI_GHI_INC_ASIC_g(void)
{
return(rw_VIHI_ICALHI_GHI_INC_ASIC_g);
}
word get_rw_VICALHI_IHI_GHI_INC_ASIC_g(void)
{
return(rw_VICALHI_IHI_GHI_INC_ASIC_g);
}


/*!
* \fn      void ASIC_Control_LoadEEP_RegDefVal(void)
* \brief   Loads the default values for the ASIC's Reg from EEPROM
*        
* \param   void 
* \return  void 
*/
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
static void ASIC_Control_LoadEEP_RegDefVal(void)
{
      ras_ASIC_CtrReg_g[IDX_GCTR_REG].val = rb_ASICGainSetup_g;
      rab_ASIC_CtrReg_DEFAULT[IDX_GCTR_REG] = rb_ASICGainSetup_g;
      
      ras_ASIC_CtrReg_g[IDX_REGVH_REG].val = 0x80;
      rab_ASIC_CtrReg_DEFAULT[IDX_REGVH_REG] = 0x80;
      
      ras_ASIC_CtrReg_g[IDX_DIAGV_REG].val = (rb_ASIC_DIAGV_g & 0xF8);
      rab_ASIC_CtrReg_DEFAULT[IDX_DIAGV_REG] = (rb_ASIC_DIAGV_g & 0xF8);
        
      ras_ASIC_CtrReg_g[IDX_HCTR_REG].val = rb_HALIOS_Clock_Control_Reg_g;
      rab_ASIC_CtrReg_DEFAULT[IDX_HCTR_REG] = rb_HALIOS_Clock_Control_Reg_g;
      
      ras_ASIC_CtrReg_g[IDX_ACTR_REG].val = (rb_ACTR_Reg_g&0xBF);
      rab_ASIC_CtrReg_DEFAULT[IDX_ACTR_REG] = (rb_ACTR_Reg_g&0xBF);
      
      ras_ASIC_CtrReg_g[IDX_PCO_REG].val = rb_PCO_PI_Regulator_g;
      rab_ASIC_CtrReg_DEFAULT[IDX_PCO_REG] = rb_PCO_PI_Regulator_g;
      
      ras_ASIC_CtrReg_g[IDX_ICO1H_REG].val = rb_ICO1H_g;
      rab_ASIC_CtrReg_DEFAULT[IDX_ICO1H_REG] = rb_ICO1H_g;
      
      ras_ASIC_CtrReg_g[IDX_ICO1L_REG].val = rb_ICO1L_g & 0xF0;
      rab_ASIC_CtrReg_DEFAULT[IDX_ICO1L_REG] = rb_ICO1L_g & 0xF0;
      
      ras_ASIC_CtrReg_g[IDX_ICO2H_REG].val = rb_ICO2H_g;
      rab_ASIC_CtrReg_DEFAULT[IDX_ICO2H_REG] = rb_ICO2H_g;
      
      ras_ASIC_CtrReg_g[IDX_ICO2L_REG].val = rb_ICO2L_g & 0xF0;
      rab_ASIC_CtrReg_DEFAULT[IDX_ICO2L_REG] = rb_ICO2L_g & 0xF0;
      
      ras_ASIC_CtrReg_g[IDX_LCTR_REG].val = (byte)((rb_FOSC_LEDUL_g&0x3)<<2);
      rab_ASIC_CtrReg_DEFAULT[IDX_LCTR_REG] = (byte)((rb_FOSC_LEDUL_g&0x3)<<2);

      ras_ASIC_CtrReg_g[IDX_TRIM_REG].val = (byte)(rb_FOSC_LEDUL_g&0x0F8);
      rab_ASIC_CtrReg_DEFAULT[IDX_TRIM_REG] = (byte)(rb_FOSC_LEDUL_g&0x0F8);
      
      ras_ASIC_CtrReg_g[IDX_INTCO_REG].val = rb_INTCO_g;
      rab_ASIC_CtrReg_DEFAULT[IDX_INTCO_REG] = rb_INTCO_g;
      
      ras_ASIC_CtrReg_g[IDX_RCTR_REG].val = (rb_ASIC_RCTR_REG_g&0xFC);
      rab_ASIC_CtrReg_DEFAULT[IDX_RCTR_REG] = (rb_ASIC_RCTR_REG_g&0xFC);
      
      ras_ASIC_CtrReg_g[IDX_RFCTR_REG].val = rb_ASIC_RFCTR_REG_g;
      rab_ASIC_CtrReg_DEFAULT[IDX_RFCTR_REG] = rb_ASIC_RFCTR_REG_g;
      
      ras_ASIC_CtrReg_g[IDX_AFSTHR_REG].val = rb_ASIC_AFSTHR_REG_g;
      rab_ASIC_CtrReg_DEFAULT[IDX_AFSTHR_REG] = rb_ASIC_AFSTHR_REG_g;
      
      if((rb_ASIC_Sched_Config_g & 0x40) == 0x40)
      {
        ras_ASIC_CtrReg_g[IDX_LCTR_REG].val = (rb_ASIC_LCTR_g & 0xF0)|((rb_FOSC_LEDUL_g&0x3)<<2);
        rab_ASIC_CtrReg_DEFAULT[IDX_LCTR_REG] = ras_ASIC_CtrReg_g[IDX_LCTR_REG].val;
      }
      
}

#endif /*_NO_RAIN_*/


/*!
* \fn     void ASIC_Control_SendReadADCmd(void)
* \brief  Sends the reading command of the AD registers for the instant and average values
*        
* \param  void 
* \return void  
*/
static void ASIC_Control_SendReadADCmd(void)
{
  if((rb_ASIC_ControlMode_g!=CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD)&&(rb_ASIC_ControlMode_g!=CASE_ASIC_CNT_MD_STANDBY)&&(rb_ASIC_ControlMode_g!=CASE_ASIC_CNT_MD_PRE_STANDBY))
  {
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

    if ( ((rb_NextMUXCfg_g < 0x80) && ((rb_NextMUXCfg_g>>2) %8 != 0))  || ((rb_NextMUXCfg_g >= 0x80) && (rb_NextMUXCfg_g < 0xC0)) || (((rb_NextMUXCfg_g >= 0xDC) && (rb_NextMUXCfg_g <= 0xE4))&&(rb_VLEDx_inLClosed_g==FALSE)) )
    {
      rb_wait500us_g = 0;
    }
#endif /*_NO_RAIN_*/
    rb_newADconvRcv_g = FALSE;
    /*Read2 command to read 2 registers at once*/
    rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_ADCVH_REG].addr<<1)|0x81); /*0x81 - Read2 Mask for writing the registers*/
    rab_SPI_ASICWriteBuffer_mg[1] = 0x2A;
    rab_SPI_ASICWriteBuffer_mg[2] = 0x2A;
    rab_SPI_ASICWriteBuffer_mg[3] = (byte)((ras_ASIC_CtrReg_g[IDX_AVGVH_REG].addr<<1)|0x81); /*0x81 - Read2 Mask for writing the registers*/
    rab_SPI_ASICWriteBuffer_mg[4] = 0x2A;
    rab_SPI_ASICWriteBuffer_mg[5] = 0x2A;
    rab_SPI_ASICWriteBuffer_mg[6] = 0x2A;                                         /*NOP byte sent to ASIC during which the last checksum is received*/
    rb_SPI_Data_to_send_g = 6;
    
    if(rb_NextSPI_Request_g == CB_CHG_MUX_STMEAS_RQ)
    {
      /*0x40 - Write1 Mask for writing the registers*/
      rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] =(byte)((ras_ASIC_CtrReg_g[IDX_MCTR_REG].addr<<1)|0x40);
      rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g+1] = rb_NextMUXCfg_g;
      rb_SPI_Data_to_send_g += 2;
      
      if((rb_ASIC_Sched_Config_g & 0x20) == 0)
      {
        if (CB_ASIC_LOPEN_MD == rb_CurMode_g)
        {
          rbi_StandbyModulatorIntegrating_g = TRUE;
        }
        /*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
        
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = 0x16;
#else
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = ASIC_START_MEAS;
#endif /*_NO_RAIN_*/
      }
      else
      {
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = ASIC_START_MEAS;
      }
      rb_NextSPI_Request_g = CB_NO_NEXT_RQ;
      rb_SPI_Data_to_send_g+=1;
    }
    else if(rb_NextSPI_Request_g == CB_STMEAS_RQ)
    {
      if((rb_ASIC_Sched_Config_g & 0x20) == 0)
      {
        if (CB_ASIC_LOPEN_MD == rb_CurMode_g)
        {
          rbi_StandbyModulatorIntegrating_g = TRUE;
        }
        /*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
        
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = 0x16;
#else
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = ASIC_START_MEAS;
#endif /*_NO_RAIN_*/
      }
      else
      {
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = ASIC_START_MEAS;
      }
      rb_SPI_Data_to_send_g += 1;
      rb_NextSPI_Request_g = CB_NO_NEXT_RQ;
    }
    else
    {
      rb_SPI_Data_to_send_g++;
    }
    SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
  }
}


/*!
* \fn     void ASIC_Control_AsicStatus(void)
* \brief  Reads the STATH and STATL registers of the ASIC for checking the flags
*        
* \param  void 
* \return void  
*/
void ASIC_Control_AsicStatus(void)
{
  if(CB_ASIC_SLEEP_MD != rb_CurMode_g)
  {
    rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_STATH_REG].addr<<1)|0x81); /*0x81 - Read2 Mask for writing the registers*/
    rab_SPI_ASICWriteBuffer_mg[1] = 0x2A;
    rab_SPI_ASICWriteBuffer_mg[2] = 0x2A;
    rab_SPI_ASICWriteBuffer_mg[3] = 0x2A;                                         /*NOP byte sent to ASIC during which the last checksum is received*/
    rb_SPI_Data_to_send_g = 3;
    
    if(rb_NextSPI_Request_g == CB_STMEAS_RQ)
    {
      if((rb_ASIC_Sched_Config_g & 0x20) == 0)
      {
        if (CB_ASIC_LOPEN_MD == rb_CurMode_g)
        {
          rbi_StandbyModulatorIntegrating_g = TRUE;
        }
        /*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
        
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = 0x16;
#else
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = ASIC_START_MEAS;
#endif /*_NO_RAIN_*/
      }
      else
      {
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = ASIC_START_MEAS;
      }
      rb_NextSPI_Request_g = CB_NO_NEXT_RQ;
    }
    else
    {    }
    rb_SPI_Data_to_send_g++;
    SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
  }
}


/*!
* \fn     void ASIC_Control_StoreADVal(void)
* \brief  Stores the AD registers for the instant and average values and checks the mux position
*        
* \param  void 
* \return void  
*/
static void ASIC_Control_StoreADVal(void)
{
  byte idx_l=0;
  
  rb_STATH_Reg_g = ((rb_STATH_Reg_g & 0x1F) | ras_ASIC_CtrReg_g[IDX_STATH_REG].val);
  rb_STATL_Reg_g |= ras_ASIC_CtrReg_g[IDX_STATL_REG].val;
  rb_LIN_STATH_Reg_g = ((rb_LIN_STATH_Reg_g & 0x1F) | ras_ASIC_CtrReg_g[IDX_STATH_REG].val);
  
  if(rb_CrtMUXCfg_g != NO_CURRENT_MEAS)
  {
    idx_l=(rb_CrtMUXCfg_g>>2);
    /* SM225 - ADC and averaged ADC values are identified by theirs multiplexer settings - LS,RS_failure */
    if(((((ras_ASIC_CtrReg_g[IDX_ADCVH_REG].val>>2)&0x3F)==idx_l) && (((ras_ASIC_CtrReg_g[IDX_AVGVH_REG].val>>2)&0x3F)==idx_l)) && 
       (rb_newADconvRcv_g == TRUE))
    {
      
      if(CHG_MUX_ALS1 == rb_CrtMUXCfg_g)
      {
        rb_ASIC_ALSx_Ready_g |= ASIC_ALS1_READY_FLG;
      }
      else if(CHG_MUX_ALS2 == rb_CrtMUXCfg_g)
      {
        rb_ASIC_ALSx_Ready_g |= ASIC_ALS2_READY_FLG;
				if (rb_ASIC_ALSx_Shortcut_Asked_g & ASIC_ALS2_READY_FLG)
				{
					rb_ASIC_ALSx_Shortcut_Ready_g |= ASIC_ALS2_READY_FLG;
					rb_ASIC_ALSx_Shortcut_Asked_g &= ~ASIC_ALS2_READY_FLG;
				}
      }
      else if(CHG_MUX_ALS5 == rb_CrtMUXCfg_g)
      {
        rb_ASIC_ALSx_Ready_g |= ASIC_ALS5_READY_FLG;
        if (rb_ASIC_ALSx_Shortcut_Asked_g & ASIC_ALS5_READY_FLG)
        {
          rb_ASIC_ALSx_Shortcut_Ready_g |= ASIC_ALS5_READY_FLG;
          rb_ASIC_ALSx_Shortcut_Asked_g &= ~ASIC_ALS5_READY_FLG;
        }
      }
      else if(CHG_MUX_ALS6 == rb_CrtMUXCfg_g)
      {
        rb_ASIC_ALSx_Ready_g |= ASIC_ALS6_READY_FLG;
      }
      else if(CHG_MUX_REC == rb_CrtMUXCfg_g)
      {
        rb_ASIC_ALSx_Ready_g |= ASIC_REC_READY_FLG;
        if (rb_ASIC_ALSx_Shortcut_Asked_g & ASIC_REC_READY_FLG)
        {
          rb_ASIC_ALSx_Shortcut_Ready_g |= ASIC_REC_READY_FLG;
          rb_ASIC_ALSx_Shortcut_Asked_g &= ~ASIC_REC_READY_FLG;
        }
      }
      else if(CHG_MUX_ALS2_INC == rb_CrtMUXCfg_g)
      {
        rb_ASIC_ALSx_Shortcut_INC_Ready_g |= ASIC_ALS2_INC_READY_FLG;
      }
      /*ALS4 not connected*/
      /*
      else if(CHG_MUX_ALS4_INC == rb_CrtMUXCfg_g)
      {
        rb_ASIC_ALSx_INC_Ready_g |= ASIC_ALS4_INC_READY_FLG;
      }
      */
      else if(CHG_MUX_ALS5_INC == rb_CrtMUXCfg_g)
      {
        rb_ASIC_ALSx_Shortcut_INC_Ready_g |= ASIC_ALS5_INC_READY_FLG;
      }
      else if(CHG_MUX_REC_INC == rb_CrtMUXCfg_g)
      {
        rb_ASIC_ALSx_Shortcut_INC_Ready_g |= ASIC_REC_INC_READY_FLG;
      }
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
      else if (MEAS_VDIAG_LEDB == rb_CrtMUXCfg_g)
      {
        rb_LEDx_newval_g = TRUE;
      }
#endif /*_NO_RAIN_*/
      else
      {// satisfy coding rules
      }
      
      rb_CrtMUXCfg_g = NO_CURRENT_MEAS;
      rb_newADconvRcv_g = FALSE;
      if((idx_l<0x20) && (idx_l%8!=0))
      {
        idx_l %= 8;
        idx_l -= 1;
        set_ras_ASIC_ALSxADval_g_AD(idx_l,((word)(ras_ASIC_CtrReg_g[IDX_ADCVH_REG].val&0x3)<<8)+ras_ASIC_CtrReg_g[IDX_ADCVL_REG].val);
        set_ras_ASIC_ALSxADval_g_AVG(idx_l,((word)(ras_ASIC_CtrReg_g[IDX_AVGVH_REG].val&0x3)<<8)+ras_ASIC_CtrReg_g[IDX_AVGVL_REG].val);
        
      }
      else if((idx_l<0x20) && (idx_l%8==0))
      {
        idx_l /= 8;
        set_ras_ASIC_ALI_CalibAD_g_AD(idx_l,((word)(ras_ASIC_CtrReg_g[IDX_ADCVH_REG].val&0x3)<<8)+ras_ASIC_CtrReg_g[IDX_ADCVL_REG].val);
        set_ras_ASIC_ALI_CalibAD_g_AVG(idx_l,((word)(ras_ASIC_CtrReg_g[IDX_AVGVH_REG].val&0x3)<<8)+ras_ASIC_CtrReg_g[IDX_AVGVL_REG].val);
 
      }
      else if((idx_l>=0x20) && (idx_l<0x30))
      {
        if (idx_l<0x24)
        {
          idx_l = IDX_ALS2_AD;
        }
        else if ((idx_l>=0x28) && (idx_l<0x2C))
        {
          idx_l = IDX_ALS5_AD;
        }
        else if((idx_l>=0x2C) && (idx_l<0x30))
        {
          idx_l = IDX_INREC_AD;
        }
        else
        {
          idx_l = IDX_INVALID_AD;
        }
        if(IDX_INVALID_AD!=idx_l)
        {
          set_ras_ASIC_ALSxADval_g_INC_AD(idx_l, (((word)(ras_ASIC_CtrReg_g[IDX_ADCVH_REG].val&0x3)<<8)+ras_ASIC_CtrReg_g[IDX_ADCVL_REG].val));
          set_ras_ASIC_ALSxADval_g_INC_AVG(idx_l, (((word)(ras_ASIC_CtrReg_g[IDX_AVGVH_REG].val&0x3)<<8)+ras_ASIC_CtrReg_g[IDX_AVGVL_REG].val));
        }
      }
      /*VDR_839 SM250: Error counter not incrementing properly for calibration values*/
      else if((idx_l>=0x30) && (idx_l<0x36))
      {
        idx_l -= 0x2C;
        set_ras_ASIC_ALI_CalibAD_g_AD(idx_l,(((word)(ras_ASIC_CtrReg_g[IDX_ADCVH_REG].val&0x3)<<8)+ras_ASIC_CtrReg_g[IDX_ADCVL_REG].val));
        set_ras_ASIC_ALI_CalibAD_g_AVG(idx_l,(((word)(ras_ASIC_CtrReg_g[IDX_AVGVH_REG].val&0x3)<<8)+ras_ASIC_CtrReg_g[IDX_AVGVL_REG].val));
      }
      else if((idx_l>=0x37)&&(idx_l<=0x3F))
      {
        idx_l -= 0x37;
        if((IDX_VDDA_AD == idx_l) || (IDX_VDDD_AD == idx_l))
        {
          rb_VDDx_received_g = TRUE;
        }
        ras_ASIC_MUX_MeasAD_g[idx_l].ad = ((word)(ras_ASIC_CtrReg_g[IDX_ADCVH_REG].val&0x3)<<8)+ras_ASIC_CtrReg_g[IDX_ADCVL_REG].val;
        ras_ASIC_MUX_MeasAD_g[idx_l].avg = ((word)(ras_ASIC_CtrReg_g[IDX_AVGVH_REG].val&0x3)<<8)+ras_ASIC_CtrReg_g[IDX_AVGVL_REG].val;
      }
      else
      {
        /* SM225 - ADC and averaged ADC values are identified by theirs multiplexer settings - LS,RS_failure*/
        if(rb_StaticNoValidAD_cnt_g<CB_ASIC_NOVALID_ADVALUES_THRSHD)
        {
          rb_StaticNoValidAD_cnt_g++;
          if(rb_StaticNoValidAD_cnt_g == CB_ASIC_NOVALID_ADVALUES_THRSHD/2)
          {
            /*VDR 760: SM225*/
            rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;        /*set case CASE_ASIC_CNT_MD_RESET*/            
          }
        }
        rb_CrtMUXCfg_g = NO_CURRENT_MEAS;
        rb_newADconvRcv_g = FALSE;
      }
    }
    else
    {
      /* SM225 - ADC and averaged ADC values are identified by theirs multiplexer settings - LS,RS_failure*/
      if (TRUE == rb_newADconvRcv_g)
      {
        if(rb_StaticNoValidAD_cnt_g<CB_ASIC_NOVALID_ADVALUES_THRSHD)
        {
          rb_StaticNoValidAD_cnt_g++;
          
          if(rb_StaticNoValidAD_cnt_g == CB_ASIC_NOVALID_ADVALUES_THRSHD/2)
          {
            /*VDR 760: SM225*/
            rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;        /*set case CASE_ASIC_CNT_MD_RESET*/            
          }
        }
        else
        {
          rbi_ASIC_NoValidAD_Error_g = TRUE;
        }
        rb_CrtMUXCfg_g = NO_CURRENT_MEAS;
        rb_newADconvRcv_g = FALSE;
      }
    }
  }
}


/**************************************************************************
Syntax   : void  ASIC_Control_ChangeMUXCmd(const byte )
Object   : 
Parameters : const byte mux_value
Return  : none
***************************************************************************
Inputs validation conditions:
none
***************************************************************************/
/**
* \brief
* Sends the change MUX command for using other inputs for measurements
*/

//static void ASIC_Control_ChangeMUXCmd(const byte mux_value)
//{
//  if(mux_value <= 0x3F)
//  {
//    if(mux_value <= 0x36)
//    {
//      rb_wait500us_g = 0;
//    }
//    rb_NextMUXCfg_g = mux_value;
//    rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_MCTR_REG].addr<<1)|0x40); /*0x40 - Write1 Mask for writing the registers*/
//    rab_SPI_ASICWriteBuffer_mg[1] = mux_value;
//    SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),2);
//  }
//
//}

/*!
* \fn      void ASIC_Control_ChangeModeCmd(const byte next_mode)
* \brief   Sends the change MODE command for the ASIC
*        
* \param   void 
* \return  void 
*/
void ASIC_Control_ChangeModeCmd(const byte next_mode)
{

  if(next_mode != rb_CurMode_g)
  {
    SPI_Write_Byte(((next_mode<<1)|0xC0));
  }
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

  if(CB_ASIC_LSTOP_MD == next_mode)
  {
    rb_wait500us_g = 0;
  }
#endif /*_NO_RAIN_*/
  if(CB_ASIC_SLEEP_MD == next_mode)
  {
    rb_PrevMode_g = rb_CurMode_g;
    rb_CurMode_g = CB_ASIC_SLEEP_MD;
  }
}


/*!
* \fn    void ASIC_Control_init_Caller(void)
* \brief State machine to control the ASIC funtions
* The module is responsible for the following modes
* -> initialisation of ASIC
* -> Gainset of ASIC
* -> Frequency measurment of ASIC
* -> checking for Sleep Mode and standby mode
* -> Standby mode initialisation and rain checking
* -> sleep mode
* This module have to be called cyclic every 10ms the flow control is done due to
* external variables
* \param  void 
* \return void 
*/
/* PRQA :  << Function needs external linkage>> */
void ASIC_Control_init_Caller(void)
{
  if (rb_AfterVddPowerFailDelay_g == 0)/* 3,3 Voltage in range?*/
  {
    ASIC_Control_init();              /* do light sensor measuring only for Vdd in correct range!*/
  }
  else
  {
    /*Not connected to Master? AND Old Cluster cleared?*/
    if ((rbi_ConnectedToMaster_g == FALSE)&&(rbi_GotoSleep_g == TRUE))
    {
      if (rb_ASIC_ControlMode_g != CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD) /*Allow to go to reset!*/
      {
        rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_NORMAL;  /*Allow to go to reset!*/
      }
      ASIC_Control_init();              /* do light sensor measuring only for Vdd in correct range!*/
    }
    else /*no Sleep and powerfail or Slowtimer*/
    {
      ASIC_Control_Signal_Check();
      //rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;    /*reset ASIC Control mode;*/
      /*Count IORefreshTaskCounter also on undervoltage.
      Otherwise EOL detects error when Pruefablauf is started (CPU load too high)*/
      rb_WDG_IORefreshTaskCounter_g++;
    }
  }
}

/*!
* \fn    void ASIC_Control_init(void)
* \brief 
*        
* \param  void 
* \return void  
*/
byte Enter_Prestandby_Flag = 0;
#if defined BYD_HC
static void ASIC_Control_init(void)
{
  
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
static byte Ignore_First_Prestandby_Flag = 0;
  /** \brief timout counter for standby mode*/
  static word rw_StandbyTimoutCounter_l;
  /** \brief set gain in ASIC */
  static byte rb_Set_ASIC_Gaindef_g;
#endif /*_NO_RAIN_*/  
  
  switch (rb_ASIC_ControlMode_g)	/*switch by state of Rainsensor Mode*/
  {
  case CASE_ASIC_CNT_MD_RESET:		  /*CASE_WAIT_INIT_LIGHT -> ASIC Control Mode after Reset*/
	/*rb_LightValueToConvert_g = 255;	  *//*stop data Aquisation*/
	if(rbi_GotoSleep_g == TRUE)
	{
	  ASIC_Control_LIN_GoToSleep(); /* RLS_VDR_1029 */
	}
	else
	{
	rw_Loop1DelayCount_mg = 0;
	/*	  rw_FastloopDelayCount_mg = 0;*/ /*VDR_365 correct variable name*/
	if (rbi_FreqMeasureDone == TRUE)
	{
	  rbi_FreqMeasureDone = FALSE;			/*VDR_285*/
	  rb_Asic_measureMode_mg = 0; /*Reinit 0,5ms variable here*/
	}
	if (rbi_LightValuesMeasured_mg == TRUE)
	{
	  rbi_LightValuesMeasured_mg = FALSE;	  /* set flag for fast light initialisation*/
	  rb_Asic_measureMode_mg = 0; /*Reinit 0,5ms variable here*/
	}

	rb_ALInitTimer_g = 0;	 /* reset Init Timer*/
	rb_FreqNotTrimmedCounter_g = 0;
	rb_ASIC_ControlMode_g= CASE_WAIT_INIT_LIGHT;	  /*set case CASE_WAIT_INIT_LIGHT*/
	}
	break;
	
  case CASE_WAIT_INIT_LIGHT:  /*CASE_WAIT_INIT_LIGHT -> Initailisation of light values*/
	/*Light_Values not initialised?*/
	if ((rbi_LightValuesMeasured_mg != FALSE)&&((rbi_EEPROMLoad_g == FALSE)||(rbi_BlankBetweenError_g == TRUE)))
	{
	  rbi_ASIC_initTimeout_err_g = FALSE;
	  rb_ASIC_initTimeout_g = 0;
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

	  ASIC_Control_CalcRSGain();							/* calculate gainsetup from gain and transmission*/
#endif /*_NO_RAIN_*/
	  rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT_2;		/*set case CASE_ASIC_CNT_TEST_EN_RESET*/
	  /*VCO_239 Light values filter defined in EEPROM*/
	  ASIC_Control_ALS5_LightValScl(0); 					/*calculate to linear light value without filter*/
#ifdef HUD_FUNCTION
	  ASIC_Control_HUD_LightValScl(0);						/*VCO_477 Blake_Used_For_HUD*/
#endif
	}
	else if(rbi_GotoSleep_g == TRUE)
	{
	  ASIC_Control_LIN_GoToSleep(); /* RLS_VDR_1029 */
	}
	else
	{
	  if(rb_ASIC_initTimeout_g < cb_ASIC_INITTIMEOUT_THRSH_g)
	  {
		rb_ASIC_initTimeout_g++;
	  }
	  else
	  {
		rbi_ASIC_initTimeout_err_g = TRUE;
	  }
	}
	break;
  case CASE_WAIT_INIT_LIGHT_2:
	rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT_3; 		 /*set case CASE_ASIC_CNT_TEST_EN_RESET*/
	/*VCO_239 Light values filter defined in EEPROM*/
	ASIC_Control_ALS2_LightValScl(0); /*calculate to linear Inrec light value without filter*/
	break;
  case CASE_WAIT_INIT_LIGHT_3:
	rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT_4; 		 /*set case CASE_ASIC_CNT_TEST_EN_RESET*/
	/*VCO_239 Light values filter defined in EEPROM*/
	ASIC_Control_INREC_LightValScl(0); /*calculate to linear Inrec light value without filter*/
	rbi_LightValuesInitialised_g = TRUE;
	break;
  case CASE_WAIT_INIT_LIGHT_4:
	rb_ASIC_ControlMode_g = CASE_ASIC_CNT_TEST_EN_RESET;		  /*set case CASE_ASIC_CNT_TEST_EN_RESET*/
	/*VCO_239 Light values filter defined in EEPROM*/
	ASIC_Control_ALS1_LightValScl(0); /*calculate to linear Inrec light value without filter*/
	break;
  case CASE_ASIC_CNT_TEST_EN_RESET: /*CASE_ASIC_CNT_TEST_EN_RESET -> to test enable for Frequ. measurment*/
	/*VCO_239 Light values filter defined in EEPROM*/
	ASIC_Control_ALS6_LightValScl(0);						/*calculate to linear light value without filter*/
	rbi_SolarValuesInitialised_g = TRUE;
	rbi_Modulator_On_g =TRUE;									/*Modulator on*/
	/*	  rw_FastloopDelayCount_mg = 0; 							 //clear fastloop DelayCounter*/
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

	rb_Set_ASIC_Gaindef_g = rb_ASICGainSetup_g; 				/*copy RS gain preset*/
#endif /*_NO_RAIN_*/
	rb_ASIC_ControlMode_g= CASE_ASIC_CNT_MD_NORMAL;
	rw_TimeOutCounter_s = TIME_FOR_STANDBY_NORMAL_MEASURE;
	rw_LengthSum_s = 0;
	break;
	
  case CASE_ASIC_CNT_MD_NORMAL:  /*CASE_ASIC_CNT_MD_NORMAL -> Normal Operation*/
    Ignore_First_Prestandby_Flag = 1;
	/*Not connected to Master? AND Old Cluster cleared?*/
	if ((rbi_ConnectedToMaster_g == FALSE)&&(rbi_GotoSleep_g == TRUE))
	{
	  
	  if ((((rbi_EEPROMBytesToWrite_g == TRUE)&&(rbi_EEPROMBytesWritten_g == TRUE))||
		   (rbi_EEPROMBytesToWrite_g == FALSE))&&(rbi_ClearCluster_mg == FALSE))
		
	  {
		if (rbi_ASICStandByModeRequest_g == TRUE)	 /*request for Standby Mode ?*/
		{
		  /*rbi_Command_CloseWindows_g = FALSE;*/  /*reset close window command in case of LIN-Wakup*/
		  if ((rb_AfterVddPowerFailDelay_g > 0)|| (rbi_UnderVoltage_g == TRUE))
		  {
			rb_ASIC_ControlMode_g =  CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD; /*Close window due to undervoltage*/
		  }
		  else
		  {
			rw_TimeOutCounter_s = TIME_FOR_STANDBY_NORMAL_MEASURE;	 /*initialise Timoutdelay for first raincheck*/
			rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_PRE_STANDBY;	 /*set case CASE_ASIC_CNT_MD_PRE_STANDBY*/
			rw_LengthSum_s = 0;
		  }
		}
		else
		{
		  ASIC_Control_LIN_GoToSleep(); /* RLS_VDR_1029 */	/*GoTo Sleep Mode*/
		}
	  }
	}
	ASIC_Control_NormalOperation(); 	/*do ASIC_Control_NormalOperation();*/
	
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

	if (rbi_ASICStandByModeRequest_g == TRUE)
	{
	  if (rw_StandbyTimoutCounter_l >= 6000)
	  {
		rw_StandbyTimoutCounter_l = 0;
		rw_StandbyTimeOutCnt_g ++;
	  }
	  else
	  {
		rw_StandbyTimoutCounter_l ++;
	  }
	  
	  if (rw_TimeOutCounter_s > 0)
	  {
		rw_TimeOutCounter_s--;
	  }
	  /* Delay time for initialisation ready?*/
	  if (rw_TimeOutCounter_s < (TIME_FOR_STANDBY_NORMAL_MEASURE - (PreStandby_Init_time_g * 10)))
	  {
		if (ASIC_Control_STBCheckRain()!=FALSE)
		{
		  /*set case CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD -> Wake bus and Close Windows*/
		  rbi_Command_CloseWindows_g = TRUE;
		}
	  }
	  rb_LastLengthCounter_s = rub_LengthCounter;  /* store LengthCounter*/
	}
	else
	{
	  rw_StandbyTimoutCounter_l = 0;
	  /*initialise Timoutdelay for first raincheck*/
	  rw_TimeOutCounter_s = TIME_FOR_STANDBY_NORMAL_MEASURE+50;
	  rw_LengthSum_s = 0;
	}
	
	/*Use this line, when Automatic Clk Trimming should NOT be used*/
	if (rb_Set_ASIC_Gaindef_g != rb_ASICGainSetup_g) /*VDR_446*/  /*check if gain setup has changed or clk*/
	  
	{
	  rbi_RainSensorEnable = FALSE; 			   /* start initialisation time again*/
	  rw_InitTimer_mg = 0;	  /* reset Init Timer*/
	  rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;  /*reinit with new gain*/
	}
#endif /*_NO_RAIN_*/
	
	break;
	
	/*CASE_ASIC_CNT_MD_PRE_STANDBY->  Check before and after standby Mode event*/
  case CASE_ASIC_CNT_MD_PRE_STANDBY:
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

	if (rbi_ConnectedToMaster_g == TRUE)	/*Connected to Master?*/
	{
	  /*set case CASE_ASIC_CNT_MD_RESET switch back to normal Operation->  reinit all states*/
	  rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;
	}
	else
	{    
          if(Enter_Prestandby_Flag == 1)
          {  
            rw_TimeOutCounter_s = 1000;
            Enter_Prestandby_Flag = 0;
          }        
        
          
	  rw_TimeOutCounter_s --;	 /*decrement timoutcounter*/
          
          
	  if(Ignore_First_Prestandby_Flag == 1)
	  {
	  	rw_TimeOutCounter_s = 0;
		Ignore_First_Prestandby_Flag = 0;
	  }
	  else
	  {
	  	ASIC_Control_NormalOperation();
	  }

	  if (rw_TimeOutCounter_s < (TIME_FOR_STANDBY_NORMAL_MEASURE - (PreStandby_Init_time_g * 10)))
	  {
		if (rw_TimeOutCounter_s > 0)   /*Timout not completed?*/
		{
		  if (ASIC_Control_STBCheckRain()!=FALSE)
		  {
			/*set case CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD -> Wake bus and Close Windows*/
			rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;
			rb_CloseTypeStandby_g = 2;
		  }
		}
		else
		{
		  rbi_LIN_CommunicationEvent_g = FALSE;  /* clear flag for LIN-Interrupt*/
		  rb_StandbyTimeOutSecCnt_g += (TIME_FOR_STANDBY_NORMAL_MEASURE / 100); /* increment second to timout*/
		  /*set case CASE_ASIC_CNT_MD_STANDBY go (back) to standby mode*/
		  rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY;
		  rw_TimeOutCounter_s = TIME_FOR_STANDBY_NORMAL_MEASURE; /* initialise Timoutdelay for first raincheck*/
		}
	  }
	  else
	  {
		rw_LengthSum_s = 0; 			/*clear sum of length*/
	  }
	  rb_LastLengthCounter_s = rub_LengthCounter;  /* store LengthCounter*/
	}
#else
	rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;
#endif /*_NO_RAIN_*/
	break;
  case CASE_ASIC_CNT_MD_STANDBY:	/*CASE_ASIC_CNT_MD_STANDBY ->  measure Loopvoltage and applie to DAC*/
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

	if((rbi_LIN_CommunicationEvent_g==FALSE)&&(FALSE == rbi_UnderVoltage_g))
	{
	  if((rb_SevenToZeroCounter_g == (cb_WDGCALLCOUNTERCYCLE_mg-2))/* && (rb_WDG_500usTaskCounter_g<=20)*/)
	  {
		R_TAU0_Channel0_Stop();
		R_TAU0_Channel5_Stop();
		R_ADC_Stop();
		po_DVoltageRegulatorEnable_g = OUTPUT;
		po_VoltageRegulatorEnable_g = FALSE;
		R_IT_Start();
		__stop();
	  }
	}
	else if(rb_SevenToZeroCounter_g == (cb_WDGCALLCOUNTERCYCLE_mg-1))
	{
	  po_DVoltageRegulatorEnable_g = OUTPUT;
	  po_VoltageRegulatorEnable_g = TRUE;
	  R_TAU0_Channel0_Start();
	  R_IT_Stop();
	  R_TAU0_Channel5_Start();
	  R_ADC_Start();
	  rw_TimeOutCounter_s = TIME_FOR_STANDBY_NORMAL_MEASURE+50;
	  ASIC_Control_ChangeModeCmd(CB_ASIC_WAKEUP_MD);
	  rb_firstReadComm_g = TRUE;
	  STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
	  ASIC_Control_ChangeModeCmd(CB_ASIC_INIT_MD);
	  STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
	  ASIC_Control_AsicStatus();
	  STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
	  rb_newAsicSTAT_g=FALSE;
	  set_rb_ASIC_SPI_ErrorFlag_g(FALSE);
	  rb_WDG_RainsensorTaskCounter_g ++;
	  rb_WDG_LightsensorTaskCounter_g ++;
	  rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;		/*set case CASE_ASIC_CNT_MD_RESET*/
	  
	  if(TRUE == rbi_UnderVoltage_g)
	  {
		rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;
	  }
	}
	else
	{	 }
	
  
#else
	rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;
#endif /*_NO_RAIN_*/
	break;
  case CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD: /*CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD -> rain detected in Standby*/
	rbi_SendWakeUpFrame_g = TRUE;	  /*request wake up frame*/
	rbi_Command_CloseWindows_g = TRUE;/*close windows*/
	rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET; 	   /*set case CASE_ASIC_CNT_MD_RESET*/
	rbi_GotoSleep_g = FALSE;
	break;
  default:			 /* default -> wrong state reset state machine*/
	rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET; /*set case CASE_ASIC_CNT_MD_RESET*/
	break;
  }
  rb_WDG_IORefreshTaskCounter_g++;
}
#else
static void ASIC_Control_init(void)
{
  
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

  /** \brief timout counter for standby mode*/
  static word rw_StandbyTimoutCounter_l;
  /** \brief set gain in ASIC */
  static byte rb_Set_ASIC_Gaindef_g;
#endif /*_NO_RAIN_*/  
  
  switch (rb_ASIC_ControlMode_g)	/*switch by state of Rainsensor Mode*/
  {
  case CASE_ASIC_CNT_MD_RESET:		  /*CASE_WAIT_INIT_LIGHT -> ASIC Control Mode after Reset*/
	/*rb_LightValueToConvert_g = 255;	  *//*stop data Aquisation*/
	if(rbi_GotoSleep_g == TRUE)
	{
	  ASIC_Control_LIN_GoToSleep(); /* RLS_VDR_1029 */
	}
	else
	{
	rw_Loop1DelayCount_mg = 0;
	/*	  rw_FastloopDelayCount_mg = 0;*/ /*VDR_365 correct variable name*/
	if (rbi_FreqMeasureDone == TRUE)
	{
	  rbi_FreqMeasureDone = FALSE;			/*VDR_285*/
	  rb_Asic_measureMode_mg = 0; /*Reinit 0,5ms variable here*/
	}
	if (rbi_LightValuesMeasured_mg == TRUE)
	{
	  rbi_LightValuesMeasured_mg = FALSE;	  /* set flag for fast light initialisation*/
	  rb_Asic_measureMode_mg = 0; /*Reinit 0,5ms variable here*/
	}

	rb_ALInitTimer_g = 0;	 /* reset Init Timer*/
	rb_FreqNotTrimmedCounter_g = 0;
	rb_ASIC_ControlMode_g= CASE_WAIT_INIT_LIGHT;	  /*set case CASE_WAIT_INIT_LIGHT*/
	}
	break;
	
  case CASE_WAIT_INIT_LIGHT:  /*CASE_WAIT_INIT_LIGHT -> Initailisation of light values*/
	/*Light_Values not initialised?*/
	if ((rbi_LightValuesMeasured_mg != FALSE)&&((rbi_EEPROMLoad_g == FALSE)||(rbi_BlankBetweenError_g == TRUE)))
	{
	  rbi_ASIC_initTimeout_err_g = FALSE;
	  rb_ASIC_initTimeout_g = 0;
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

	  ASIC_Control_CalcRSGain();							/* calculate gainsetup from gain and transmission*/
#endif /*_NO_RAIN_*/
	  rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT_2;		/*set case CASE_ASIC_CNT_TEST_EN_RESET*/
	  /*VCO_239 Light values filter defined in EEPROM*/
	  ASIC_Control_ALS5_LightValScl(0); 					/*calculate to linear light value without filter*/
	}
	else if(rbi_GotoSleep_g == TRUE)
	{
	  ASIC_Control_LIN_GoToSleep(); /* RLS_VDR_1029 */
	}
	else
	{
	  if(rb_ASIC_initTimeout_g < cb_ASIC_INITTIMEOUT_THRSH_g)
	  {
		rb_ASIC_initTimeout_g++;
	  }
	  else
	  {
		rbi_ASIC_initTimeout_err_g = TRUE;
	  }
	}
	break;
  case CASE_WAIT_INIT_LIGHT_2:
	rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT_3; 		 /*set case CASE_ASIC_CNT_TEST_EN_RESET*/
	/*VCO_239 Light values filter defined in EEPROM*/
	ASIC_Control_ALS2_LightValScl(0); /*calculate to linear Inrec light value without filter*/
	break;
  case CASE_WAIT_INIT_LIGHT_3:
	rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT_4; 		 /*set case CASE_ASIC_CNT_TEST_EN_RESET*/
	/*VCO_239 Light values filter defined in EEPROM*/
	ASIC_Control_INREC_LightValScl(0); /*calculate to linear Inrec light value without filter*/
	rbi_LightValuesInitialised_g = TRUE;
	break;
  case CASE_WAIT_INIT_LIGHT_4:
	rb_ASIC_ControlMode_g = CASE_ASIC_CNT_TEST_EN_RESET;		  /*set case CASE_ASIC_CNT_TEST_EN_RESET*/
	/*VCO_239 Light values filter defined in EEPROM*/
	ASIC_Control_ALS1_LightValScl(0); /*calculate to linear Inrec light value without filter*/
	break;
  case CASE_ASIC_CNT_TEST_EN_RESET: /*CASE_ASIC_CNT_TEST_EN_RESET -> to test enable for Frequ. measurment*/
	/*VCO_239 Light values filter defined in EEPROM*/
	ASIC_Control_ALS6_LightValScl(0);						/*calculate to linear light value without filter*/
	
	rbi_Modulator_On_g =TRUE;									/*Modulator on*/
	/*	  rw_FastloopDelayCount_mg = 0; 							 //clear fastloop DelayCounter*/
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

	rb_Set_ASIC_Gaindef_g = rb_ASICGainSetup_g; 				/*copy RS gain preset*/
#endif /*_NO_RAIN_*/
	rb_ASIC_ControlMode_g= CASE_ASIC_CNT_MD_NORMAL;
	rw_TimeOutCounter_s = TIME_FOR_STANDBY_NORMAL_MEASURE;
	rw_LengthSum_s = 0;
	break;
	
  case CASE_ASIC_CNT_MD_NORMAL:  /*CASE_ASIC_CNT_MD_NORMAL -> Normal Operation*/
	/*Not connected to Master? AND Old Cluster cleared?*/
	if ((rbi_ConnectedToMaster_g == FALSE)&&(rbi_GotoSleep_g == TRUE))
	{
	  
	  if ((((rbi_EEPROMBytesToWrite_g == TRUE)&&(rbi_EEPROMBytesWritten_g == TRUE))||
		   (rbi_EEPROMBytesToWrite_g == FALSE))&&(rbi_ClearCluster_mg == FALSE))
		
	  {
		if (rbi_ASICStandByModeRequest_g == TRUE)	 /*request for Standby Mode ?*/
		{
		  /*rbi_Command_CloseWindows_g = FALSE;*/  /*reset close window command in case of LIN-Wakup*/
		  if ((rb_AfterVddPowerFailDelay_g > 0)|| (rbi_UnderVoltage_g == TRUE))
		  {
			rb_ASIC_ControlMode_g =  CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD; /*Close window due to undervoltage*/
		  }
		  else
		  {
			rw_TimeOutCounter_s = TIME_FOR_STANDBY_NORMAL_MEASURE;	 /*initialise Timoutdelay for first raincheck*/
			rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_PRE_STANDBY;	 /*set case CASE_ASIC_CNT_MD_PRE_STANDBY*/
			rw_LengthSum_s = 0;
		  }
		}
		else
		{
		  ASIC_Control_LIN_GoToSleep(); /* RLS_VDR_1029 */	/*GoTo Sleep Mode*/
		}
	  }
	}
	ASIC_Control_NormalOperation(); 	/*do ASIC_Control_NormalOperation();*/
	
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

	if (rbi_ASICStandByModeRequest_g == TRUE)
	{
	  if (rw_StandbyTimoutCounter_l >= 6000)
	  {
		rw_StandbyTimoutCounter_l = 0;
		rw_StandbyTimeOutCnt_g ++;
	  }
	  else
	  {
		rw_StandbyTimoutCounter_l ++;
	  }
	  
	  if (rw_TimeOutCounter_s > 0)
	  {
		rw_TimeOutCounter_s--;
	  }
	  /* Delay time for initialisation ready?*/
	  if (rw_TimeOutCounter_s < (TIME_FOR_STANDBY_NORMAL_MEASURE - TIME_FOR_RAINSENSOR_INIT))
	  {
		if (ASIC_Control_STBCheckRain()!=FALSE)
		{
		  /*set case CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD -> Wake bus and Close Windows*/
		  rbi_Command_CloseWindows_g = TRUE;
		}
	  }
	  rb_LastLengthCounter_s = rub_LengthCounter;  /* store LengthCounter*/
	}
	else
	{
	  rw_StandbyTimoutCounter_l = 0;
	  /*initialise Timoutdelay for first raincheck*/
	  rw_TimeOutCounter_s = TIME_FOR_STANDBY_NORMAL_MEASURE+50;
	  rw_LengthSum_s = 0;
	}
	
	/*Use this line, when Automatic Clk Trimming should NOT be used*/
	if (rb_Set_ASIC_Gaindef_g != rb_ASICGainSetup_g) /*VDR_446*/  /*check if gain setup has changed or clk*/
	  
	{
	  rbi_RainSensorEnable = FALSE; 			   /* start initialisation time again*/
	  rw_InitTimer_mg = 0;	  /* reset Init Timer*/
	  rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;  /*reinit with new gain*/
	}
#endif /*_NO_RAIN_*/
	
	break;
	
	/*CASE_ASIC_CNT_MD_PRE_STANDBY->  Check before and after standby Mode event*/
  case CASE_ASIC_CNT_MD_PRE_STANDBY:
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

	if (rbi_ConnectedToMaster_g == TRUE)	/*Connected to Master?*/
	{
	  /*set case CASE_ASIC_CNT_MD_RESET switch back to normal Operation->  reinit all states*/
	  rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;
	}
	else
	{
	  rw_TimeOutCounter_s --;	 /*decrement timoutcounter*/
	  ASIC_Control_NormalOperation();	/* bring ASIC in correct mode to check for rain;*/
	  /* Delay time for initialisation ready?*/
	  if (rw_TimeOutCounter_s < (TIME_FOR_STANDBY_NORMAL_MEASURE - TIME_FOR_RAINSENSOR_INIT))
	  {
		if (rw_TimeOutCounter_s > 0)   /*Timout not completed?*/
		{
		  if (ASIC_Control_STBCheckRain()!=FALSE)
		  {
			/*set case CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD -> Wake bus and Close Windows*/
			rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;
			rb_CloseTypeStandby_g = 2;
		  }
		}
		else
		{
		  rbi_LIN_CommunicationEvent_g = FALSE;  /* clear flag for LIN-Interrupt*/
		  rb_StandbyTimeOutSecCnt_g += (TIME_FOR_STANDBY_NORMAL_MEASURE / 100); /* increment second to timout*/
		  /*set case CASE_ASIC_CNT_MD_STANDBY go (back) to standby mode*/
		  rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY;
		  rw_TimeOutCounter_s = TIME_FOR_STANDBY_NORMAL_MEASURE; /* initialise Timoutdelay for first raincheck*/
		}
	  }
	  else
	  {
		rw_LengthSum_s = 0; 			/*clear sum of length*/
	  }
	  rb_LastLengthCounter_s = rub_LengthCounter;  /* store LengthCounter*/
	}
#else
	rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;
#endif /*_NO_RAIN_*/
	break;
  case CASE_ASIC_CNT_MD_STANDBY:	/*CASE_ASIC_CNT_MD_STANDBY ->  measure Loopvoltage and applie to DAC*/
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

	if((rbi_LIN_CommunicationEvent_g==FALSE)&&(FALSE == rbi_UnderVoltage_g))
	{
	  if((rb_SevenToZeroCounter_g == (cb_WDGCALLCOUNTERCYCLE_mg-2))/* && (rb_WDG_500usTaskCounter_g<=20)*/)
	  {
		R_TAU0_Channel0_Stop();
		R_TAU0_Channel5_Stop();
		R_ADC_Stop();
		po_DVoltageRegulatorEnable_g = OUTPUT;
		po_VoltageRegulatorEnable_g = FALSE;
		R_IT_Start();
		__stop();
	  }
	}
	else if(rb_SevenToZeroCounter_g == (cb_WDGCALLCOUNTERCYCLE_mg-1))
	{
	  po_DVoltageRegulatorEnable_g = OUTPUT;
	  po_VoltageRegulatorEnable_g = TRUE;
	  R_TAU0_Channel0_Start();
	  R_IT_Stop();
	  R_TAU0_Channel5_Start();
	  R_ADC_Start();
	  rw_TimeOutCounter_s = TIME_FOR_STANDBY_NORMAL_MEASURE+50;
	  ASIC_Control_ChangeModeCmd(CB_ASIC_WAKEUP_MD);
	  rb_firstReadComm_g = TRUE;
	  STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
	  ASIC_Control_ChangeModeCmd(CB_ASIC_INIT_MD);
	  STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
	  ASIC_Control_AsicStatus();
	  STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
	  rb_newAsicSTAT_g=FALSE;
	  set_rb_ASIC_SPI_ErrorFlag_g(FALSE);
	  rb_WDG_RainsensorTaskCounter_g ++;
	  rb_WDG_LightsensorTaskCounter_g ++;
	  rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;		/*set case CASE_ASIC_CNT_MD_RESET*/
	  
	  if(TRUE == rbi_UnderVoltage_g)
	  {
		rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;
	  }
	}
	else
	{	 }
	
  
#else
	rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;
#endif /*_NO_RAIN_*/
	break;
  case CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD: /*CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD -> rain detected in Standby*/
	rbi_SendWakeUpFrame_g = TRUE;	  /*request wake up frame*/
	rbi_Command_CloseWindows_g = TRUE;/*close windows*/
	rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET; 	   /*set case CASE_ASIC_CNT_MD_RESET*/
	rbi_GotoSleep_g = FALSE;
	break;
  default:			 /* default -> wrong state reset state machine*/
	rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET; /*set case CASE_ASIC_CNT_MD_RESET*/
	break;
  }
  rb_WDG_IORefreshTaskCounter_g++;
}

#endif  //#ifdef NL_5

/*!
* \fn     void ASIC_Control_NormalOperation(void)
* \brief  Pseudo-code : Controls normal Operatons of ASIC, Responsible for:
* -> Modulator ON/ OFF
* -> Light measurement
* -> fastloop
* \param  void 
* \return void 
*/
static void ASIC_Control_NormalOperation(void)
{
  /** \brief counter to organise the scheduling 50ms*/
  static byte rb_to4Counter_l;
  byte ASIC_temp_Rdy_flg_l;
  
  if (((rbi_AutomaticWipingMode_g == TRUE)||(rbi_ASICStandByModeRequest_g == TRUE))&&((rbi_UnderVoltage_g == FALSE)&&(rbi_OverVoltage_g == FALSE)))  /*automatic wiping mode or rbi_ASICStandByModeRequest_g requested*/
  {
    rbi_Modulator_On_g = TRUE;                         /*activate modulator*/
  }
  else  /* light measurement without rainsensor function*/
  {
    rbi_Modulator_On_g = FALSE;          /* switch modulator off*/
/*    rw_Loop1DelayCount_mg = 0;     //clear fastloop DelayCounter*/
  }
  if (rbi_LightValuesMeasured_mg == 0 )
  {
    rbi_LightValuesInitialised_g = FALSE;
    rbi_SolarValuesInitialised_g = FALSE;
    rub_Dia_Count_dyna_Stop = 0;
  }
  else
  {

/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
    if(rb_to4Counter_l==0)
    {
      ASIC_Control_CalcRSGain();                            /* calculate gainsetup from gain and transmission*/
    }
    else
#endif /*_NO_RAIN_*/
    {
      if(rb_to4Counter_l==4)
      {
        
        if (rbi_Coupling_measurement_to_linearise_g == TRUE)
        {
          rbi_Coupling_measurement_to_linearise_g = FALSE;
          ASIC_Control_INMODON_LightValScl();
        }
        
        ASIC_Control_Signal_Check();
        if (((rb_LightSignalErrorCnt_g & CB_LIGHT_ERROR_RESTART_THRS) == CB_LIGHT_ERROR_RESTART_THRS)
            ||((get_rb_Vref_LightSignalErrorCnt_g() & CB_LIGHT_ERROR_RESTART_THRS) == CB_LIGHT_ERROR_RESTART_THRS)) /*Try to recover ASIC Measurment in case of measuring Problems*/
        {
          rub_Dia_Count_dyna_Stop = 0;
          /* Reset ASIC to recover function!*/
          rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;
        }
      }
    }
    if(rb_to4Counter_l<4)
    {
      rb_to4Counter_l++;
    }
    else
    {
      rb_to4Counter_l=0;
    }
    
    if((rb_ASIC_ALSx_Ready_g & ASIC_ALS2_READY_FLG) == ASIC_ALS2_READY_FLG)
    {
      /*VCO_239 Light values filter defined in EEPROM*/
      ASIC_Control_ALS2_LightValScl(rb_ALSx_Filter_g);                             /* calculate to linear light value*/
      ASIC_temp_Rdy_flg_l = ASIC_ALS2_READY_FLG;
      rb_ASIC_ALSx_Ready_g &= (byte)(~ASIC_temp_Rdy_flg_l);
    }
    
    if((rb_ASIC_ALSx_Ready_g & ASIC_ALS5_READY_FLG) == ASIC_ALS5_READY_FLG)
    {
      /*VCO_239 Light values filter defined in EEPROM*/
      ASIC_Control_ALS5_LightValScl(rb_ALSx_Filter_g);                             /* calculate to linear light value*/
#ifdef HUD_FUNCTION
      ASIC_Control_HUD_LightValScl(rb_ALSx_Filter_g);                              /*Blake_Used_for HUD VCO_477*/
#endif
      ASIC_temp_Rdy_flg_l = ASIC_ALS5_READY_FLG;
      rb_ASIC_ALSx_Ready_g &= (byte)(~ASIC_temp_Rdy_flg_l);
    }
    
    if((rb_ASIC_ALSx_Ready_g & ASIC_REC_READY_FLG) == ASIC_REC_READY_FLG)
    {
      /*VCO_239 Light values filter defined in EEPROM*/
      ASIC_Control_INREC_LightValScl(rb_ALSx_Filter_g);                             /* calculate to linear light value*/
      ASIC_temp_Rdy_flg_l = ASIC_REC_READY_FLG;
      rb_ASIC_ALSx_Ready_g &= (byte)(~ASIC_temp_Rdy_flg_l);
    }
    
    /*calculate the light values from ALSx INC and check against short circuits*/
    ASIC_Control_ALSxINCShortDetect();

    
    if((rb_ASIC_ALSx_Ready_g & ASIC_ALS1_READY_FLG) == ASIC_ALS1_READY_FLG)
    {
      /*VCO_239 Light values filter defined in EEPROM*/
      ASIC_Control_ALS1_LightValScl(rb_ALSx_Filter_g);                             /* calculate to linear light value*/
      ASIC_temp_Rdy_flg_l = ASIC_ALS1_READY_FLG;
      rb_ASIC_ALSx_Ready_g &= (byte)(~ASIC_temp_Rdy_flg_l);
    }
    else if((rb_ASIC_ALSx_Ready_g & ASIC_ALS6_READY_FLG) == ASIC_ALS6_READY_FLG)
    {
      /*VCO_239 Light values filter defined in EEPROM*/
      ASIC_Control_ALS6_LightValScl(rb_ALSx_Filter_g);                             /* calculate to linear light value*/
      ASIC_temp_Rdy_flg_l = ASIC_ALS6_READY_FLG;
      rb_ASIC_ALSx_Ready_g &= (byte)(~ASIC_temp_Rdy_flg_l);
      rbi_LightValuesInitialised_g = TRUE;

    }
    else
    {// satisfy coding rules
    }
  }
#ifndef _NO_RAIN_
  if (rub_Dia_Count_dyna_Stop < 0xff)/*VDR_132 do not count and not reset during fastloop*/
  {
    rub_Dia_Count_dyna_Stop++;       /*VDR_132 increment counter for error detection*/
  }
  if ((rub_Dia_Count == (CW_DIA_TIMEOUT/2))
      ||(rub_Dia_Count == (3*CW_DIA_TIMEOUT/4)))
  {
    rub_Dia_Count += 1;
    rub_Dia_Count_dyna_Stop = 0;
    Rainsensor_inactive();
    rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;          /* Reset ASIC to recover function!*/
  }
#endif /*_NO_RAIN_*/
}


/*!
* \fn     void ASIC_Control_LoopMode(void) 
* \brief  Changes the modes of the ASIC to start rain measurements
*        
* \param   void 
* \return  void   
*/
#ifndef _NO_RAIN_

static void ASIC_Control_LoopMode(void)
{
  static byte rb_delay_LClosed_l;
  static byte rb_delay_LClosed_calc_l;
  word rw_tempVal_l;
  
  /*modulator active?*/
  if ((rbi_Modulator_On_g == TRUE) && ((rb_ASIC_Sched_Config_g & 0x40) == 0))
  {
    if ((rb_wait500us_g == 2) && (rbi_SPI_activ_g == FALSE) && (rb_delay_LClosed_l==0))
    {
      if (((rb_CurMode_g == CB_ASIC_LSTOP_MD) && (rw_Loop1DelayCount_mg < LOOP1_ON_DELAY)))
      {
        /*return to the previous mode*/
        ASIC_Control_ChangeModeCmd(CB_ASIC_LOOP1_MD);
      }
      else if ((((rb_CurMode_g == CB_ASIC_LOOP1_MD) || (rb_CurMode_g == CB_ASIC_LSTOP_MD)) && (rb_PrevMode_g != CB_ASIC_INIT_MD)) && (rw_Loop1DelayCount_mg >= LOOP1_ON_DELAY))
      {
        ASIC_Control_ChangeModeCmd(CB_ASIC_LRAMP_MD);
      }
      else
      {// satisfy coding rules
      }

      rb_wait500us_g = 2;
    }
    else
    {
      if(rb_wait500us_g < 2)
      {
        rb_wait500us_g ++;
      }
    }

    if(rb_CurMode_g == CB_ASIC_LSTOP_MD)
    {
      if (rb_delay_LClosed_l>0)
      {
        rb_delay_LClosed_l--;
      }
    }
    else if (CB_ASIC_LOOP2_MD == rb_CurMode_g)
    {
      
      /*calculate the duty cycle for RS every 1 sec*/
      if (rbi_Timer1s_OK_g == TRUE)
      {
        
        rbi_Timer1s_OK_g = FALSE;
        /*if temperature too high, reduce the duty cycle to protect the transistors*/
        /* check the internal temperature or the ASIC's temperature*/
        if( ((rb_InternalTemperature_g < cb_TEMP_uC_AD65DEGREES_THRS_g) || (rw_VTEMP_ASIC_g < cb_TEMP_ASIC_AD65DEGREES_THRS_g)) )
        {
          rw_tempVal_l = ((word)229*rb_InternalTemperature_g)/384;
          
          if(rw_tempVal_l > 48)
          {
            rw_tempVal_l = 0;
          }
          else
          {
            rw_tempVal_l = 48 - rw_tempVal_l;
          }
          
          rb_delay_LClosed_calc_l = rw_tempVal_l;
          
          rw_tempVal_l = ((word)4*rw_VTEMP_ASIC_g)/33;
          
          if(rw_tempVal_l>70)
          {
            rw_tempVal_l = 0;
          }
          else
          {
            rw_tempVal_l = 70 - rw_tempVal_l;
          }
          
          /*use the highest value, to wait to change to loop closed*/
          if(rb_delay_LClosed_calc_l < rw_tempVal_l)
          {
            rb_delay_LClosed_calc_l = rw_tempVal_l;
          }
          
          /*maximum value for the duty cycle is 45%*/
          if(rb_delay_LClosed_calc_l > cb_LCLOSED_45perCent_THRS_g)
          {
            rb_delay_LClosed_calc_l = cb_LCLOSED_45perCent_THRS_g;
          }
          
        }
        else 
        {
          /*temperature is not above 65 degrees*/
          rb_delay_LClosed_calc_l = 0;
        }
      }
      /*update the delay to change to loop closed*/
      rb_delay_LClosed_l = rb_delay_LClosed_calc_l;
    }
    else
    {// satisfy coding rules
    }

    if(rw_Loop1DelayCount_mg <= LOOP1_ON_DELAY)
    {
      /*increment counter*/
      rw_Loop1DelayCount_mg++;
    }
  }
  else           // modulator off measure Vref without gainadjustment
  {
  }
}
#endif /*_NO_RAIN_*/


/*!
* \fn      void ASIC_Control_Startup_Init(void)
* \brief   Initial configuration of the ASIC
*          First verifications
*          Setting up and check all of the registers
*          Measure the frequency and the light/rain diodes         
* \param   void 
* \return  void 
*/
static void ASIC_Control_Startup_Init(void)
{
  byte rb_idx_reg_l;
  byte rw_tempvalue_l;
  byte rb_temp_ASICReg_NoValidVals_Error_l;
  static byte rb_i_write_l=0;
  static byte rb_i_read_l=0;
  
  rb_temp_ASICReg_NoValidVals_Error_l=0;
  rw_Loop1DelayCount_mg = 0;
  
  ASIC_Control_StoreADVal();
  rb_CrtMUXCfg_g = rb_NextMUXCfg_g;
  
  if (rb_Asic_measureMode_mg == 2)  /* switch to low power mode*/
  {
    if(rb_ASICResetCnt_g<0xFF)
    {
      rb_ASICResetCnt_g++;
    }
    ASIC_Control_ChangeModeCmd(CB_ASIC_SLEEP_MD);
  }
  else if (rb_Asic_measureMode_mg == 5)  /* start in Init Mode, passing the Wake Up mode*/
  {
    for(rb_idx_reg_l=0;rb_idx_reg_l<CB_SIZEOF_ASIC_CTRREG_G;rb_idx_reg_l++)
    {
      ras_ASIC_CtrReg_g[rb_idx_reg_l].val = rab_ASIC_CtrReg_DEFAULT[rb_idx_reg_l];
    }
    ASIC_Control_ChangeModeCmd(CB_ASIC_WAKEUP_MD);
  }
  else if (rb_Asic_measureMode_mg == 6)  /* start in Init Mode, passing the Wake Up mode*/
  {
    /*redundant change command*/
    ASIC_Control_ChangeModeCmd(CB_ASIC_INIT_MD);
  }
  else if (rb_Asic_measureMode_mg == 8)
  {
    rb_firstReadComm_g=TRUE;
    ASIC_Control_AsicStatus();
  }
  else if (rb_Asic_measureMode_mg == 10)
  {
    rb_firstReadComm_g=FALSE;
    
#ifdef _NO_RAIN_
    
    /*check if the E2PROM data has been loaded*/
    if(rbi_EEPROMLoad_g == FALSE)
    {      
      ras_ASIC_CtrReg_g[IDX_ACTR_REG].val = (rb_ACTR_Reg_g&0xBF);
      rab_ASIC_CtrReg_DEFAULT[IDX_ACTR_REG] = (rb_ACTR_Reg_g&0xBF);
      
      ras_ASIC_CtrReg_g[IDX_TRIM_REG].val = (byte)(rb_FOSC_LEDUL_g&0x0F8);
      rab_ASIC_CtrReg_DEFAULT[IDX_TRIM_REG] = (byte)(rb_FOSC_LEDUL_g&0x0F8);
      
      /*set TSTEN*/
      SPI_Write_Byte(CB_ASIC_SET_TEST_ENABLE);
    }
    else
    {
      rb_Asic_measureMode_mg = 9;
    }
    
#else
    
    /*check if the E2PROM data has been loaded*/
    if(rbi_EEPROMLoad_g == FALSE)
    {
      /*init of the threshold for no rain present, during stby measurements*/
      rw_NoRainPresentCntThrsh_g = CW_NO_RAIN_PRESENT_THRSH_g;
      rb_GainOffset_g = rb_GainOffsetE2_g;
      /*calculate gainsetup from gain and transmission*/
      ASIC_Control_CalcRSGain();
      
      /*Use the default values from EEPROM for setting the registers*/
      ASIC_Control_LoadEEP_RegDefVal();
      
      /*set TSTEN*/
      SPI_Write_Byte(CB_ASIC_SET_TEST_ENABLE);
    }
    else
    {
      rb_Asic_measureMode_mg = 9;
    }
    
#endif
  }
  /*write all registers*/
  else if ( (rb_Asic_measureMode_mg == 11) || 
           (rb_Asic_measureMode_mg == 12) || 
             (rb_Asic_measureMode_mg == 13) )
  {
    for(;rb_i_write_l<CB_SIZEOF_ASIC_CTRREG_G; rb_i_write_l++)
    {
      /*Write2 command for setting the initial values for 2 registers at once*/
      if((ras_ASIC_CtrReg_g[rb_i_write_l].accs==0)&&(ras_ASIC_CtrReg_g[rb_i_write_l].addr%2==0))
      {
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = (byte)((ras_ASIC_CtrReg_g[rb_i_write_l].addr<<1)|0x41); /*0x41 - Write2 Mask for writing the registers*/
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g+1] = ras_ASIC_CtrReg_g[rb_i_write_l].val;
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g+2] = ras_ASIC_CtrReg_g[rb_i_write_l+1].val;
        rb_SPI_Data_to_send_g += 3;
      }
      else
      {
        /*Write1 command for setting the initial values for 1 register at a time*/
        if((ras_ASIC_CtrReg_g[rb_i_write_l].accs==1)&&(ras_ASIC_CtrReg_g[rb_i_write_l].addr%2==0))
        {
          rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = (byte)((ras_ASIC_CtrReg_g[rb_i_write_l].addr<<1)|0x40); /*0x40 - Write1 Mask for writing the registers*/
          rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g+1] = ras_ASIC_CtrReg_g[rb_i_write_l].val;
          rb_SPI_Data_to_send_g += 2;
        }
      }
      /*don't send more than 16 bytes*/
      if(rb_SPI_Data_to_send_g >= 11)
      {
        rb_i_write_l++;
        break;
      }
    }
    if(rb_Asic_measureMode_mg == 13)
    {
      rb_i_write_l = 0;
    }
    
    SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
    rb_SPI_Data_to_send_g = 0;
  }
  /* VCO132: trim frequency and measure it - SM210 - LS,RS_Failure*/
  else if (rb_Asic_measureMode_mg == 15)
  {
    rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_TRIM_REG].addr<<1)|0x40); /*0x40 - Write1 Mask for writing the TRIM register*/
    rab_SPI_ASICWriteBuffer_mg[1] = ras_ASIC_CtrReg_g[IDX_TRIM_REG].val | 0x02; /*request the CDIV256, Halios freq*/
    rb_SPI_Data_to_send_g = 2;
    SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
  }
  else if (rb_Asic_measureMode_mg == 17)
  {
    R_TAU0_Channel6_Stop();
    rw_CDIV256_period_g = TDR06;
    rw_CDIV256_period_g += 1;
    rb_CDIV256_OVF_g = (byte)(TSR06);
    
    if((rw_CDIV256_period_g < (CB_CDIV256_PERIOD_NOM - CB_CDIV256_PERIOD_TOL)) || (rw_CDIV256_period_g > (CB_CDIV256_PERIOD_NOM + CB_CDIV256_PERIOD_TOL)) || (rb_CDIV256_OVF_g != 0))
    {
      if( rb_FreqNotTrimmedCounter_g < CB_FREQ_NOTTRIMMED_CNT_THRSHD)
      {
        rb_FreqNotTrimmedCounter_g ++;
      }
      else
      {
        /* VCO132: SM210 - LS,RS_Failure*/
        rbi_ASIC_FreqTrimming_error_g = TRUE;
        if(rw_CDIV256_period_g < CB_CDIV256_PERIOD_NOM - CB_CDIV256_PERIOD_TOL)
        {
          rb_ASIC_FREQ_invalid_LOW_g = TRUE;
        }
        else
        {
          rb_ASIC_FREQ_invalid_HIGH_g = TRUE;
        }
      }
      /*if outside the specified range, then reset, else trim*/
      if((rw_CDIV256_period_g > CB_CDIV256_PERIOD_MIN) && (rw_CDIV256_period_g < CB_CDIV256_PERIOD_MAX))
      {
        rb_Asic_measureMode_mg = 13;
        if(CB_CDIV256_PERIOD_NOM>rw_CDIV256_period_g)
        {
          rw_tempvalue_l = ((200*(CB_CDIV256_PERIOD_NOM-rw_CDIV256_period_g))/CB_CDIV256_PERIOD_NOM)/3;
          ras_ASIC_CtrReg_g[IDX_TRIM_REG].val -= (rw_tempvalue_l<<3);
        }
        else
        {
          rw_tempvalue_l = ((200*(rw_CDIV256_period_g-CB_CDIV256_PERIOD_NOM))/CB_CDIV256_PERIOD_NOM)/3;
          ras_ASIC_CtrReg_g[IDX_TRIM_REG].val += (rw_tempvalue_l<<3);
        }
        rab_ASIC_CtrReg_DEFAULT[IDX_TRIM_REG] = ras_ASIC_CtrReg_g[IDX_TRIM_REG].val;
      }
      else
      {
        rb_Asic_measureMode_mg = 13;
        if((rw_CDIV256_period_g < CB_CDIV256_PERIOD_MIN)&&((ras_ASIC_CtrReg_g[IDX_TRIM_REG].val>>3)>0))
        {
          ras_ASIC_CtrReg_g[IDX_TRIM_REG].val -= 0x8;
          rab_ASIC_CtrReg_DEFAULT[IDX_TRIM_REG] = ras_ASIC_CtrReg_g[IDX_TRIM_REG].val;
        }
        else if((rw_CDIV256_period_g > CB_CDIV256_PERIOD_MAX)&&((ras_ASIC_CtrReg_g[IDX_TRIM_REG].val>>3)<0x1F))
        {
          ras_ASIC_CtrReg_g[IDX_TRIM_REG].val += 0x8;
          rab_ASIC_CtrReg_DEFAULT[IDX_TRIM_REG] = ras_ASIC_CtrReg_g[IDX_TRIM_REG].val;
        }
        else
        {
          rb_Asic_measureMode_mg = 0;
          ras_ASIC_CtrReg_g[IDX_TRIM_REG].val = (byte)(rb_FOSC_LEDUL_g&0x0F8);
          rab_ASIC_CtrReg_DEFAULT[IDX_TRIM_REG] = (byte)(rb_FOSC_LEDUL_g&0x0F8);
        }
      }
    }
    else
    {
      /*if((ras_ASIC_CtrReg_g[IDX_TRIM_REG].val & 0xF8) != (rb_FOSC_LEDUL_g&0x0F8))
      {
      EEProm_WriteCodedByte(ras_ASIC_CtrReg_g[IDX_TRIM_REG].val|(rb_FOSC_LEDUL_g&0x07),CB_FOSC_LEDUL_ADDR_g);
    }*/
      rbi_ASIC_FreqTrimming_error_g = FALSE;
    }
    /*set trim register with MISO - normal functionality*/
    rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_TRIM_REG].addr<<1)|0x40); /*0x40 - Write1 Mask for writing the TRIM register*/
    rab_SPI_ASICWriteBuffer_mg[1] = ras_ASIC_CtrReg_g[IDX_TRIM_REG].val;
    rb_SPI_Data_to_send_g = 2;
    SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
  }
  else if (rb_Asic_measureMode_mg == 19)
  {
    /*clear TSTEN*/
    SPI_Write_Byte(CB_ASIC_CLEAR_TEST_ENABLE);
  }
  /*read all written registers*/
  else if ( (rb_Asic_measureMode_mg == 21) ||
           (rb_Asic_measureMode_mg == 24) ||
             (rb_Asic_measureMode_mg == 27) )
  {
    rb_SPI_Data_to_send_g=0;
    for(;rb_i_read_l<CB_SIZEOF_ASIC_CTRREG_G; rb_i_read_l++)
    {
      if(   ((ras_ASIC_CtrReg_g[rb_i_read_l].accs==0) || 
             (ras_ASIC_CtrReg_g[rb_i_read_l].accs==2))&&
         (ras_ASIC_CtrReg_g[rb_i_read_l].addr%2==0)    )
      {
        /*Read2 command to read 2 registers at once*/
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = (byte)((ras_ASIC_CtrReg_g[rb_i_read_l].addr<<1)|0x81); /*0x81 - Read2 Mask for writing the registers*/
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g+1] = 0x2A;
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g+2] = 0x2A;
        rb_SPI_Data_to_send_g +=3;
      }
      else
      {
        if(ras_ASIC_CtrReg_g[rb_i_read_l].addr%2==0)
        {
          /*Read1 command to read 1 register at a time*/
          rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = (byte)((ras_ASIC_CtrReg_g[rb_i_read_l].addr<<1)|0x80); /*0x80 - Read1 Mask for writing the registers*/
          rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g+1] = 0x2A;
          rb_SPI_Data_to_send_g +=2;
        }
      }
      if(rb_i_read_l==CB_SIZEOF_ASIC_CTRREG_G-1)
      {
        if(rb_SPI_Data_to_send_g>0)
        {
          rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = 0x2A;
          ++rb_SPI_Data_to_send_g;
        }
      }
      else if(rb_SPI_Data_to_send_g >= 13) /*don't send more than 16 bytes*/
      {
        rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = 0x2A;
        ++rb_SPI_Data_to_send_g;
        rb_i_read_l++;
        break;
      }
      else
      {// satisfy coding rules
      }
      
    }
    
    if(rb_Asic_measureMode_mg == 27)
    {
      rb_i_read_l = 0;
    }
    
    SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
  }
  /*switch to Loop-Stop*/
  else if (rb_Asic_measureMode_mg == 30)
  {
    
#ifdef _NO_RAIN_
    if ((ras_ASIC_CtrReg_g[IDX_MCTR_REG].val != rab_ASIC_CtrReg_DEFAULT[IDX_MCTR_REG]) || 
        (ras_ASIC_CtrReg_g[IDX_ACTR_REG].val != rab_ASIC_CtrReg_DEFAULT[IDX_ACTR_REG])||
          (ras_ASIC_CtrReg_g[IDX_TRIM_REG].val != rab_ASIC_CtrReg_DEFAULT[IDX_TRIM_REG]))
    {
      rb_temp_ASICReg_NoValidVals_Error_l = TRUE;
      rb_Asic_measureMode_mg = 0;
    }
    
#else
    for(rb_idx_reg_l=0;rb_idx_reg_l<CB_SIZEOF_ASIC_CTRREG_G;rb_idx_reg_l++)
    {
      /*check if the registers have the expected values*/
      if ( (((ras_ASIC_CtrReg_g[rb_idx_reg_l].val != rab_ASIC_CtrReg_DEFAULT[rb_idx_reg_l]) && (IDX_RFCTR_REG!=rb_idx_reg_l)) ||
            (IDX_RFCTR_REG==rb_idx_reg_l) && ((((rab_ASIC_CtrReg_DEFAULT[rb_idx_reg_l]&0x80) != 0x80)&&(ras_ASIC_CtrReg_g[rb_idx_reg_l].val != (rab_ASIC_CtrReg_DEFAULT[rb_idx_reg_l]&0xFE))) ||
                                              (((rab_ASIC_CtrReg_DEFAULT[rb_idx_reg_l]&0x80) == 0x80)&&((ras_ASIC_CtrReg_g[rb_idx_reg_l].val&0xE0) != rab_ASIC_CtrReg_DEFAULT[rb_idx_reg_l])))) &&
          (ras_ASIC_CtrReg_g[rb_idx_reg_l].accs!=2) &&
            (rb_idx_reg_l != IDX_REGVH_REG) && (rb_idx_reg_l != IDX_REGVL_REG) &&
              (rb_idx_reg_l != IDX_INTVH_REG) && (rb_idx_reg_l != IDX_INTVL_REG))
      {
        rb_temp_ASICReg_NoValidVals_Error_l = TRUE;
        rb_Asic_measureMode_mg = 0;
        break;
      }
    }
#endif
    
    if(rb_temp_ASICReg_NoValidVals_Error_l == TRUE)
    {
      if(rb_ASICReg_NoValidVals_cnt_g < 255)
      {
        rb_ASICReg_NoValidVals_cnt_g ++;
      }
      else
      {
        rbi_ASICReg_NoValidVals_Error_g = TRUE;
      }
    }
    else
    {
      if(rb_ASICReg_NoValidVals_cnt_g > 0)
      {
        rb_ASICReg_NoValidVals_cnt_g --;
      }
      else
      {
        rbi_ASICReg_NoValidVals_Error_g = FALSE;
      }
    }
    ASIC_Control_ChangeModeCmd(CB_ASIC_LSTOP_MD);
  }
    
  /*Start the Calibration measurements*/
  else if (rb_Asic_measureMode_mg == 33)
  {
    /*start measurement*/
    rb_NextMUXCfg_g = CAL_ILO_IHI_GLO;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 35)
  {
    /*switch the MUX to the ALI CAL Iref Hi-Lo, G Lo, Vref*/
    rb_NextMUXCfg_g = CAL_IHI_ILO_GLO;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read out the AD values for ALI CAL Iref Lo-Hi, G Lo, Vref*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 37)
  {
    /*switch the MUX to the ALI CAL Iref Lo - Ical Lo, G Hi, Vref*/
    rb_NextMUXCfg_g = CAL_ILO_ICALLO_GHI;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read out the AD values for ALI CAL Iref Hi-Lo, G Lo, Vref*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 39)
  {
    /*switch the MUX to the ALI CAL Iref Hi - Ical Hi, G Hi, Vref*/
    rb_NextMUXCfg_g = CAL_IHI_ICALHI_GHI;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read out the AD values for ALI CAL Iref Lo - Ical Lo, G Hi, Vref*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 41)
  {
    /*switch the MUX to the ALI CAL Ical Lo - Iref Lo, G Hi, Vref*/
    rb_NextMUXCfg_g = CAL_ICALLO_ILO_GHI;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read out the AD values for ALI CAL Iref Hi - Ical Hi, G Hi, Vref*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 43)
  {
    /*switch the MUX to the ALI CAL Ical Hi - Iref Hi, G Hi, Vref*/
    rb_NextMUXCfg_g = CAL_ICALHI_IHI_GHI;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read out the AD values for ALI CAL Ical Lo - Iref Lo, G Hi, Vref*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 45)
  {
    /*switch the MUX to the ALI CAL Iref Lo - Iref Hi, G Lo, Vref Inc*/
    rb_NextMUXCfg_g = CAL_ILO_IHI_GLO_INC;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read out the AD values for ALI CAL Ical Hi - Iref Hi, G Hi, Vref*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 47)
  {
    /*switch the MUX to the ALI CAL Iref Hi - Iref Lo, G Lo, Vref Inc*/
    rb_NextMUXCfg_g = CAL_IHI_ILO_GLO_INC;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read out the AD values for ALI CAL Iref Lo - Iref Hi, G Lo, Vref Inc*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 49)
  {
    /*switch the MUX to the ALI CAL Iref Hi - Ical Hi, G Hi, Vref Inc*/
    rb_NextMUXCfg_g = CAL_IHI_ICALHI_GHI_INC;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read out the AD values for ALI CAL Iref Hi - Iref Lo, G Lo, Vref Inc*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 51)
  {
    /*switch the MUX to the ALI CAL Ical Hi - Iref Hi, G Hi, Vref Inc*/
    rb_NextMUXCfg_g = CAL_ICALHI_IHI_GHI_INC;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read out the AD values for ALI CAL Iref Hi - Ical Hi, G Hi, Vref Inc*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 53)
  {
    /*switch the MUX to the ALS1*/
    rb_NextMUXCfg_g = CHG_MUX_ALS1;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read out the AD values for ALI CAL Iref Lo - Ical Lo, G Hi, Vref Inc*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 55)
  {
    /*switch the MUX to the ALS2*/
    rb_NextMUXCfg_g = CHG_MUX_ALS2;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read out the AD values for ALS1*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 57)
  {
    /*switch the MUX to the ALS2 with INC*/
    rb_NextMUXCfg_g = CHG_MUX_ALS2_INC;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read ALS2*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 59)
  {
    /*switch the MUX to the ALS5*/
    rb_NextMUXCfg_g = CHG_MUX_ALS5;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read ALS4 with INC*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 61)
  {
    /*switch the MUX to the ALS5 with INC*/
    rb_NextMUXCfg_g = CHG_MUX_ALS5_INC;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read ALS5*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 63)
  {
    /*switch the MUX to the ALS6*/
    rb_NextMUXCfg_g = CHG_MUX_ALS6;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read ALS5 with INC*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 65)
  {
    /*switch the MUX to the INREC*/
    rb_NextMUXCfg_g = CHG_MUX_REC;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read ALS6*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 67)
  {
    /*switch the MUX to the INREC with INC*/
    rb_NextMUXCfg_g = CHG_MUX_REC_INC;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read INREC*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 69)
  {
#ifndef _NO_RAIN_
    /*switch the MUX to V Diag, LED A; pos DAC output*/
    rb_NextMUXCfg_g = MEAS_VDIAG_LEDA;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read V Diag, LED A; pos DAC output*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 71)
  {
    /*switch the MUX to V Diag, LED B; neg DAC output*/
    rb_NextMUXCfg_g = MEAS_VDIAG_LEDB;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read V Diag, LED A; pos DAC output*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 73)
  {
#endif
    /*switch the MUX to Vtemp*/
    rb_NextMUXCfg_g = MEAS_VTEMP;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read V Diag, LED B; neg DAC output*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 75)
  {
    /*switch the MUX to VREF*/
    rb_NextMUXCfg_g = MEAS_VDIAG_VREF;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read Vtemp*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 77)
  {
    /*switch the MUX to VIREF,LO*/
    rb_NextMUXCfg_g = MEAS_V_IREF_LO;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read VREF*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 79)
  {
    /*switch the MUX to VIREF,HI*/
    rb_NextMUXCfg_g = MEAS_V_IREF_HI;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read VIREF,LO*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 81)
  {
    /*switch the MUX to VDDA*/
    rb_NextMUXCfg_g = MEAS_VDIAG_VDDA;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read VIREF,HI*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 83)
  {
    /*switch the MUX to VDDD*/
    rb_NextMUXCfg_g = MEAS_VDIAG_VDDD;
    rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
    /*read VDDA*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 85)
  {
    /*read VDDD*/
    ASIC_Control_SendReadADCmd();
  }
  else if (rb_Asic_measureMode_mg == 87)
  {
    /*Read the ID of the ASIC*/
    rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = 0xD0; 
    rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g+1] = 0x2A;
    rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g+2] = 0x2A;
    rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g+3] = 0x2A;
    rb_SPI_Data_to_send_g +=4;
    SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
  }
#ifndef _NO_RAIN_
  else if ((rb_Asic_measureMode_mg == 89) && ((rb_ASIC_Sched_Config_g & 0x40) != 0))
  {
    ASIC_Control_ChangeModeCmd(CB_ASIC_INIT_MD);
  }
  else if ((rb_Asic_measureMode_mg == 90) && ((rb_ASIC_Sched_Config_g & 0x40) != 0))
  {
    ASIC_Control_ChangeModeCmd(CB_ASIC_LOPEN_MD);
  }
#endif
  else if (rb_Asic_measureMode_mg == 91)
  {
    rbi_FreqMeasureDone = TRUE;
    rbi_LightValuesMeasured_mg = TRUE;
    
    ASIC_Control_AsicStatus();
  }
  else
  {// satisfy coding rules
  }
  
  if (rb_Asic_measureMode_mg >= 91)
  {
    if(rbi_VDD_LightSignalError_g==TRUE)
    {
      rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;        /*set case CASE_ASIC_CNT_MD_RESET*/
    }
    /*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
    
    rb_Start_STBY_Meas_g = FALSE;
#endif /*_NO_RAIN_*/
    rb_old_ASIC_Sched_Config_g = rb_ASIC_Sched_Config_g;
    rb_Asic_measureMode_mg = 0;
    /*reset flag to measure LEDA and LEDB once after startup*/
    rbi_Modulator_On_g = FALSE;
    rw_InitTimer_mg = 0;
    /*      rb_LEDx_error_g = FALSE;*/
  }
  else
  {
    rb_Asic_measureMode_mg++;
  }
}


/*!
* \fn     void ASIC_Control_measure(void) 
* \brief  Pseudo-code :Scheduling of the following measurement and light correction and
*         Linearisation calls:
* # Vref
* # Vical
* # VInamb1
* # Vinrec
* call for:
* -> correction of VInamb1
* -> delog of VInamb1
* -> correction of VInrec
* -> delog of VInrec
* \param  void 
* \return void  
*/
static void ASIC_Control_measure(void)
{
  static byte send_ASIC_to_sleep_ok = 1;
  static byte rb_OldStaticNoValidAD_cnt_l=0;
  static byte rb_SPIRecoverReset_l=0;

/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

  static byte rb_LClosed_dur_cnt_l;
  static byte rb_tempLClosed_dur_total_l;
  static byte rb_tempRainMeas_cnt_l;
  static byte RSI_out=0;
#endif /*_NO_RAIN_*/

    /*store the last read AD values*/
    ASIC_Control_StoreADVal();
    rb_CrtMUXCfg_g = rb_NextMUXCfg_g;
    
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

    if(CB_ASIC_LOOP2_MD == rb_CurMode_g)
    {
      rb_LClosed_dur_cnt_l ++;
    }
    else if(CB_ASIC_LSTOP_MD == rb_CurMode_g)
    {
      if(rb_LClosed_dur_cnt_l > rb_LClosed_dur_max_g)
      {
        rb_LClosed_dur_max_g = rb_LClosed_dur_cnt_l;
      }
      
      if(rb_RainMeas_cnt_g > rb_RainMeas_cnt_max_g)
      {
        rb_RainMeas_cnt_max_g = rb_RainMeas_cnt_g;
      }
      
      rb_tempLClosed_dur_total_l += rb_LClosed_dur_cnt_l;
      rb_tempRainMeas_cnt_l += rb_RainMeas_cnt_g;
      rb_RainMeas_cnt_g = 0;
      rb_LClosed_dur_cnt_l=0;
    }
    else
    {// satisfy coding rules
    }

#endif /*_NO_RAIN_*/
    
    if (send_ASIC_to_sleep_ok == 0)
    {
      send_ASIC_to_sleep_ok=1;
      ASIC_Control_ChangeModeCmd(CB_ASIC_SLEEP_MD);
    }
    
    if (((rb_old_ASIC_Sched_Config_g ^ rb_ASIC_Sched_Config_g) != 0))
    {
      /* Reset ASIC to recover function!*/
      rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;
    }
    else
    {
    }
    
    if(((rw_SPINoCommCounter_g>=(MAX_SPI_NO_COMM_CNT/2)) && (FALSE == rb_SPIRecoverReset_l))
       || (rw_SPINoCommCounter_g >= (MAX_SPI_NO_COMM_CNT-SPI_NO_COMM_INCREMENT)))
    {
      /* Reset ASIC to recover function!*/
      rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;
      rb_SPIRecoverReset_l = TRUE;
    }
    else if(rw_SPINoCommCounter_g == 0)
    {
      rb_SPIRecoverReset_l = FALSE;
    }
    
    rb_old_ASIC_Sched_Config_g = rb_ASIC_Sched_Config_g;

/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
    if( (rbi_ASICgainAdjustRunning_g == TRUE) && (rb_CurMode_g != CB_ASIC_LSTOP_MD) )
    {
      if((rb_Asic_measureMode_mg < 192) || (rb_Asic_measureMode_mg > 198))
      {
        rb_Asic_measureMode_mg = 192;
      }
    }

    if((rb_ASIC_Sched_Config_g & 0x8) != 0)
    {
      
      if ((CB_ASIC_LOOP2_MD == rb_CurMode_g)&&(rbi_RainSensorEnable==1))
      {
        rb_Asic_measureMode_mg=200;
        
        if (RSI_out==1)
        {
          RSI_out=2;
          /*0x40 - Write1 Mask for writing the TRIM register*/
          rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_TRIM_REG].addr<<1)|0x40);
          rab_SPI_ASICWriteBuffer_mg[1] = (byte)(ras_ASIC_CtrReg_g[IDX_TRIM_REG].val|0x5);
          rb_SPI_Data_to_send_g = 2;
          SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
        }
        else if (RSI_out==0)
        {
          RSI_out=1;
          SPI_Write_Byte(CB_ASIC_SET_TEST_ENABLE);
        }
        else
        {// satisfy coding rules
        }
      }
      else
      {
        RSI_out=0;
      }
    }
#endif /*_NO_RAIN_*/
    
    
/*if the rain functionality is disabled*/
#ifdef _NO_RAIN_
    switch (rb_Asic_measureMode_mg)
    {
    /*VDR_862 Read of ALSx after 1,5ms after setting the MUX*/
    case 0:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        /*change MUX to ALS1*/
        rb_NextMUXCfg_g = CHG_MUX_ALS1;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 3:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef Hi-Lo, gain Low */
        rb_NextMUXCfg_g = CAL_IHI_ILO_GLO;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
      }
      ASIC_Control_SendReadADCmd();
      break;
      
    case 5:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        if ((rb_ASIC_ALS2Amb_ShortDetected_cnt_g < rb_SC_order1_g)
             ||((rb_ASIC_ALS2Amb_ShortDetected_cnt_g >= rb_SC_order2_g)
               &&(rb_ASIC_ALS2Amb_ShortDetected_cnt_g < rb_SC_order3_g)))
        {
        	/* Normal measurement order */
	        /*change MUX to ALS2*/
	        rb_NextMUXCfg_g = CHG_MUX_ALS2;
	        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
	        ASIC_Control_SendReadADCmd();
					rb_ASIC_ALSx_Shortcut_Asked_g |= ASIC_ALS2_READY_FLG;
        }
				else
				{
          /* Inverted measurement order */
          /*change MUX to ALS2 with INC*/
          rb_NextMUXCfg_g = CHG_MUX_ALS2_INC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
				}
      }
      break;
    case 8:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        if (   (rb_ASIC_ALS2Amb_ShortDetected_cnt_g < rb_SC_order1_g)
            || (   (rb_ASIC_ALS2Amb_ShortDetected_cnt_g >= rb_SC_order2_g)
                && (rb_ASIC_ALS2Amb_ShortDetected_cnt_g < rb_SC_order3_g)
               )
           )
        {
          /* Normal measurement order */
          /*change MUX to ALS2 with INC*/
          rb_NextMUXCfg_g = CHG_MUX_ALS2_INC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
        }
        else
        {
          /* Inverted measurement order */
          /*change MUX to ALS2*/
          rb_NextMUXCfg_g = CHG_MUX_ALS2;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
          rb_ASIC_ALSx_Shortcut_Asked_g |= ASIC_ALS2_READY_FLG;
        }
      }
      break;
    case 11:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef Lo-Hi, gain Low */
        rb_NextMUXCfg_g = CAL_ILO_IHI_GLO;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read the ad values for ALS2*/
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 13:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        /*change MUX value to ALS5*/
        rb_NextMUXCfg_g = CHG_MUX_ALS5;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 16:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to V IRef_Low*/
        rb_NextMUXCfg_g = MEAS_V_IREF_LO;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 18:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to V IRef_High*/
        rb_NextMUXCfg_g = MEAS_V_IREF_HI;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
      }
      ASIC_Control_SendReadADCmd();
      break;
      
    case 20:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        /*change MUX value to ALS6*/
        rb_NextMUXCfg_g = CHG_MUX_ALS6;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 23:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef Low - ICal Low, gain High */
        rb_NextMUXCfg_g = CAL_ILO_ICALLO_GHI;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 25:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef Hi - ICal HI, gain High */
        rb_NextMUXCfg_g = CAL_IHI_ICALHI_GHI;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read the ad values for INREC with INC*/
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 27:
      if (((rb_ASIC_Sched_Config_g & /*0xC0*/0xC1) == 0) || ((rb_ASIC_Sched_Config_g & 0x20) == 0x20))
      {
        /*change MUX value to INREC*/
        rb_NextMUXCfg_g = CHG_MUX_REC;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read V TEMP*/
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 30:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration ICal Low - IRef Low, gain High */
        rb_NextMUXCfg_g = CAL_ICALLO_ILO_GHI;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 32:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        /*change MUX to ALS1*/
        rb_NextMUXCfg_g = CHG_MUX_ALS1;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;

    case 35:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to V Ref*/
        rb_NextMUXCfg_g = MEAS_VDIAG_VREF;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 37:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        /*change MUX to ALS2*/
        rb_NextMUXCfg_g = CHG_MUX_ALS2;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 40:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration ICal Hi - IRef HI, gain High */
        rb_NextMUXCfg_g = CAL_ICALHI_IHI_GHI;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read the ad values for ALS2 with INC*/
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 42:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef Lo - IRef HI, gain Low, with INC */
        rb_NextMUXCfg_g = CAL_ILO_IHI_GLO_INC;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read the ad values for ALS4*/
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 44:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        if (   (rb_ASIC_ALS5FW_ShortDetected_cnt_g < rb_SC_order1_g)
            || (   (rb_ASIC_ALS5FW_ShortDetected_cnt_g >= rb_SC_order2_g)
                && (rb_ASIC_ALS5FW_ShortDetected_cnt_g < rb_SC_order3_g)
               )
           )
        {
          /* Normal measurement order */
          /*change MUX value to ALS5*/
          rb_NextMUXCfg_g = CHG_MUX_ALS5;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
          rb_ASIC_ALSx_Shortcut_Asked_g |= ASIC_ALS5_READY_FLG;
        }
        else
        {
          /* Inverted measurement order */
          /*change MUX value to ALS5 with INC*/
          rb_NextMUXCfg_g = CHG_MUX_ALS5_INC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
        }
      }
      break;
    case 47:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        if (   (rb_ASIC_ALS5FW_ShortDetected_cnt_g < rb_SC_order1_g)
            || (   (rb_ASIC_ALS5FW_ShortDetected_cnt_g >= rb_SC_order2_g)
                && (rb_ASIC_ALS5FW_ShortDetected_cnt_g < rb_SC_order3_g)
               )
           )
        {
          /* Normal measurement order */
          /*change MUX value to ALS5 with INC*/
          rb_NextMUXCfg_g = CHG_MUX_ALS5_INC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
        }
        else
        {
          /* Inverted measurement order */
          /*change MUX value to ALS5*/
          rb_NextMUXCfg_g = CHG_MUX_ALS5;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
          rb_ASIC_ALSx_Shortcut_Asked_g |= ASIC_ALS5_READY_FLG;
        }
      }
      break;
    case 50:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef High - IRef Low, gain Low, with INC */
        rb_NextMUXCfg_g = CAL_IHI_ILO_GLO_INC;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 52:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef High - ICal HI, gain High, with INC */
        rb_NextMUXCfg_g = CAL_IHI_ICALHI_GHI_INC;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read the ad values for ALS5 with INC*/
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 54:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        /*change MUX value to ALS6*/
        rb_NextMUXCfg_g = CHG_MUX_ALS6;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 57:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to VDIAG VDDA*/
        rb_NextMUXCfg_g = MEAS_VDIAG_VDDA;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 59:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to VDIAG VDDD*/
        rb_NextMUXCfg_g = MEAS_VDIAG_VDDD;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read the ad values for INREC*/
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 61:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration ICal High - IRef HI, gain High, with INC */
        rb_NextMUXCfg_g = CAL_ICALHI_IHI_GHI_INC;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 63:
      if (((rb_ASIC_Sched_Config_g & /*0xC0*/0xC1) == 0) || ((rb_ASIC_Sched_Config_g & 0x20) == 0x20))
      {
        if (   (rb_ASIC_INRECIR_ShortDetected_cnt_g < rb_SC_order1_g)
            || (   (rb_ASIC_INRECIR_ShortDetected_cnt_g >= rb_SC_order2_g)
                && (rb_ASIC_INRECIR_ShortDetected_cnt_g < rb_SC_order3_g)
               )
           )
        {
          /*change MUX value to INREC*/
          rb_NextMUXCfg_g = CHG_MUX_REC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          /*read VDIAG VDDA*/
          ASIC_Control_SendReadADCmd();
          rb_ASIC_ALSx_Shortcut_Asked_g |= ASIC_REC_READY_FLG;
        }
        else
        {
          /*change MUX value to INREC with INC*/
          rb_NextMUXCfg_g = CHG_MUX_REC_INC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
        }
      }
      break;
    case 66:
      if (((rb_ASIC_Sched_Config_g & /*0xC0*/0xC1) == 0) || ((rb_ASIC_Sched_Config_g & 0x20) == 0x20))
      {
        if (   (rb_ASIC_INRECIR_ShortDetected_cnt_g < rb_SC_order1_g)
            || (   (rb_ASIC_INRECIR_ShortDetected_cnt_g >= rb_SC_order2_g)
                && (rb_ASIC_INRECIR_ShortDetected_cnt_g < rb_SC_order3_g)
               )
           )
        {
          /*change MUX value to INREC with INC*/
          rb_NextMUXCfg_g = CHG_MUX_REC_INC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
        }
        else
        {
          /*change MUX value to INREC*/
          rb_NextMUXCfg_g = CHG_MUX_REC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          /*read VDIAG VDDA*/
          ASIC_Control_SendReadADCmd();
          rb_ASIC_ALSx_Shortcut_Asked_g |= ASIC_REC_READY_FLG;
        }
      }
      break;
    case 69:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef Low - ICal Low, gain Low, with INC*/
        rb_NextMUXCfg_g = MEAS_VTEMP;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    default:
  
      if (rb_Asic_measureMode_mg == 71)
      {
        ASIC_Control_AsicStatus();
        rb_NextSPI_Request_g = CB_STMEAS_RQ;
      }
      else
      {
      }
      break;
    }
#else /*rain functionality is enabled*/
    switch (rb_Asic_measureMode_mg)
    {
    case 0:
      rb_RainMeas_cnt_min_g = 100;
      rb_RainMeas_cnt_max_g = 0;
      rb_LClosed_dur_min_g = 100;
      rb_LClosed_dur_max_g = 0;
      /*fall through*/
    case 20:
      /*fall through*/
    case 40:
      /*fall through*/
    case 60:
      /*fall through*/
    case 80:
      /*fall through*/
    case 100:
      /*fall through*/
    case 120:
      /*fall through*/
    case 140:
      /*fall through*/
    case 160:
      /*fall through*/
    case 180:
      
      if(rb_RainMeas_cnt_g < rb_RainMeas_cnt_min_g)
      {
        rb_RainMeas_cnt_min_g = rb_RainMeas_cnt_g;
      }
      
      if(rb_LClosed_dur_cnt_l < rb_LClosed_dur_min_g)
      {
        rb_LClosed_dur_min_g = rb_LClosed_dur_cnt_l;
      }
      
      if((rb_ASIC_Sched_Config_g & 0xC0) == 0)
      {
        ASIC_Control_ChangeModeCmd(CB_ASIC_LSTOP_MD);
      }
      if(CB_NO_NEXT_RQ==rb_NextSPI_Request_g)
      {
        rb_NextSPI_Request_g = CB_STMEAS_RQ;
      }
      break;
      
    case 1:
      
      rb_LClosed_dur_total_g = rb_tempLClosed_dur_total_l;
      rb_RainMeas_cnt_total_g = rb_tempRainMeas_cnt_l;
      
      rb_tempRainMeas_cnt_l = 0;
      rb_tempLClosed_dur_total_l = 0;
      
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        /*change MUX to ALS1*/
        rb_NextMUXCfg_g = CHG_MUX_ALS1;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 3:
      if ((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to V RSI*/
        rb_NextMUXCfg_g = MEAS_RSI_AMP;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
      }
      ASIC_Control_SendReadADCmd();
      break;
    case 5:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        rb_wait500us_g = 0;
        /*change MUX value to V LEDA*/
        rb_NextMUXCfg_g = MEAS_VDIAG_LEDA;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
      }
      ASIC_Control_SendReadADCmd();
      break; 
    case 7:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        rb_wait500us_g = 0;
        /*change MUX value to V LEDB*/
        rb_NextMUXCfg_g = MEAS_VDIAG_LEDB;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        if(CB_ASIC_LSTOP_MD == rb_CurMode_g)
        {
          rb_VLEDx_inLClosed_g = FALSE;
        }
      }
      ASIC_Control_SendReadADCmd();
      break; 
    case 9:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef Hi-Lo, gain Low */
        rb_NextMUXCfg_g = CAL_IHI_ILO_GLO;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
      }
      ASIC_Control_SendReadADCmd();
      break;
      
    case 19:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        if (   (rb_ASIC_ALS2Amb_ShortDetected_cnt_g < rb_SC_order1_g)
            || (   (rb_ASIC_ALS2Amb_ShortDetected_cnt_g >= rb_SC_order2_g)
                && (rb_ASIC_ALS2Amb_ShortDetected_cnt_g < rb_SC_order3_g)
               )
           )
        {
          /* Normal measurement order */
          /*change MUX to ALS2*/
          rb_NextMUXCfg_g = CHG_MUX_ALS2;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
          rb_ASIC_ALSx_Shortcut_Asked_g |= ASIC_ALS2_READY_FLG;
        }
        else
        {
          /* Inverted measurement order */
          /*change MUX to ALS2 with INC*/
          rb_NextMUXCfg_g = CHG_MUX_ALS2_INC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
        }
      }
      break;
    case 21:
      rb_wait500us_g = 0;
      break;
    case 23:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        if (   (rb_ASIC_ALS2Amb_ShortDetected_cnt_g < rb_SC_order1_g)
            || (   (rb_ASIC_ALS2Amb_ShortDetected_cnt_g >= rb_SC_order2_g)
                && (rb_ASIC_ALS2Amb_ShortDetected_cnt_g < rb_SC_order3_g)
               )
           )
        {
          /* Normal measurement order */
          /*change MUX to ALS2 with INC*/
          rb_NextMUXCfg_g = CHG_MUX_ALS2_INC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
        }
        else
        {
          /* Inverted measurement order */
          /*change MUX to ALS2*/
          rb_NextMUXCfg_g = CHG_MUX_ALS2;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
          rb_ASIC_ALSx_Shortcut_Asked_g |= ASIC_ALS2_READY_FLG;
        }
      }
      break;
    case 25:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef Lo-Hi, gain Low */
        rb_NextMUXCfg_g = CAL_ILO_IHI_GLO;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read the ad values for ALS2*/
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 39:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        /*change MUX value to ALS5*/
        rb_NextMUXCfg_g = CHG_MUX_ALS5;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 41:
      rb_wait500us_g = 0;
      break;
    case 43:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        rb_wait500us_g = 0;
        /*change MUX value to V IRef_Low*/
        rb_NextMUXCfg_g = MEAS_V_IREF_LO;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 45:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to V IRef_High*/
        rb_NextMUXCfg_g = MEAS_V_IREF_HI;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
      }
      ASIC_Control_SendReadADCmd();
      break;
      
    case 59:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        /*change MUX value to ALS6*/
        rb_NextMUXCfg_g = CHG_MUX_ALS6;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 61:
      rb_wait500us_g = 0;
      break;
    case 63:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef Low - ICal Low, gain High */
        rb_NextMUXCfg_g = CAL_ILO_ICALLO_GHI;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 65:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef Hi - ICal HI, gain High */
        rb_NextMUXCfg_g = CAL_IHI_ICALHI_GHI;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read the ad values for INREC with INC*/
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 81:
      if (((rb_ASIC_Sched_Config_g & /*0xC0*/0xC1) == 0) || ((rb_ASIC_Sched_Config_g & 0x20) == 0x20))
      {
        /*change MUX value to INREC*/
        rb_NextMUXCfg_g = CHG_MUX_REC;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read V TEMP*/
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 83:
      rb_wait500us_g = 0;
      break;
    case 85:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration ICal Low - IRef Low, gain High */
        rb_NextMUXCfg_g = CAL_ICALLO_ILO_GHI;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 87:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to VDIAG VDDD*/
        rb_NextMUXCfg_g = MEAS_VDIAG_VDDD;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 101:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        /*change MUX to ALS1*/
        rb_NextMUXCfg_g = CHG_MUX_ALS1;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;

    case 103:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to V Ref*/
        rb_NextMUXCfg_g = MEAS_VDIAG_VREF;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 119:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        /*change MUX to ALS2*/
        rb_NextMUXCfg_g = CHG_MUX_ALS2;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 121:
      rb_wait500us_g = 0;
      break;
    case 123:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration ICal Hi - IRef HI, gain High */
        rb_NextMUXCfg_g = CAL_ICALHI_IHI_GHI;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read the ad values for ALS2 with INC*/
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 125:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef Lo - IRef HI, gain Low, with INC */
        rb_NextMUXCfg_g = CAL_ILO_IHI_GLO_INC;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read the ad values for ALS4*/
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 127:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to VDIAG VDDA*/
        rb_NextMUXCfg_g = MEAS_VDIAG_VDDA;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 139:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        if (   (rb_ASIC_ALS5FW_ShortDetected_cnt_g < rb_SC_order1_g)
            || (   (rb_ASIC_ALS5FW_ShortDetected_cnt_g >= rb_SC_order2_g)
                && (rb_ASIC_ALS5FW_ShortDetected_cnt_g < rb_SC_order3_g)
               )
           )
        {
          /* Normal measurement order */
          /*change MUX value to ALS5*/
          rb_NextMUXCfg_g = CHG_MUX_ALS5;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
          rb_ASIC_ALSx_Shortcut_Asked_g |= ASIC_ALS5_READY_FLG;
        }
        else
        {
          /* Inverted measurement order */
          /*change MUX value to ALS5 with INC*/
          rb_NextMUXCfg_g = CHG_MUX_ALS5_INC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
        }
      }
      break;
    case 141:
      rb_wait500us_g = 0;
      break;
    case 143:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        if (   (rb_ASIC_ALS5FW_ShortDetected_cnt_g < rb_SC_order1_g)
            || (   (rb_ASIC_ALS5FW_ShortDetected_cnt_g >= rb_SC_order2_g)
                && (rb_ASIC_ALS5FW_ShortDetected_cnt_g < rb_SC_order3_g)
               )
           )
        {
          /* Normal measurement order */
          /*change MUX value to ALS5 with INC*/
          rb_NextMUXCfg_g = CHG_MUX_ALS5_INC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
        }
        else
        {
          /* Inverted measurement order */
          /*change MUX value to ALS5*/
          rb_NextMUXCfg_g = CHG_MUX_ALS5;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
          rb_ASIC_ALSx_Shortcut_Asked_g |= ASIC_ALS5_READY_FLG;
        }
      }
      break;
    case 145:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration IRef High - IRef Low, gain Low, with INC */
        rb_NextMUXCfg_g = CAL_IHI_ILO_GLO_INC;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 147:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*VDR_841 Diagnose pulse and extended diagnose pulse have great values sometimes*/
        /*change MUX value to calibration IRef High - ICal HI, gain High, with INC */
        rb_NextMUXCfg_g = MEAS_VTEMP;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read the ad values for ALS5 with INC*/
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 159:
      if((rb_ASIC_Sched_Config_g & 0x1) != 1)
      {
        /*change MUX value to ALS6*/
        rb_NextMUXCfg_g = CHG_MUX_ALS6;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 161:
      rb_wait500us_g = 0;
      break;
    case 163:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to VDIAG VDDA*/
        rb_NextMUXCfg_g = MEAS_VDIAG_VDDA;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 165:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to VDIAG VDDD*/
        rb_NextMUXCfg_g = MEAS_VDIAG_VDDD;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        /*read the ad values for INREC*/
        ASIC_Control_SendReadADCmd();
      }
      break;
    case 167:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*change MUX value to calibration ICal High - IRef HI, gain High, with INC */
        rb_NextMUXCfg_g = CAL_ICALHI_IHI_GHI_INC;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    case 181:
      if (((rb_ASIC_Sched_Config_g & /*0xC0*/0xC1) == 0) || ((rb_ASIC_Sched_Config_g & 0x20) == 0x20))
      {
        if (   (rb_ASIC_INRECIR_ShortDetected_cnt_g < rb_SC_order1_g)
            || (   (rb_ASIC_INRECIR_ShortDetected_cnt_g >= rb_SC_order2_g)
                && (rb_ASIC_INRECIR_ShortDetected_cnt_g < rb_SC_order3_g)
               )
           )
        {
          /*change MUX value to INREC*/
          rb_NextMUXCfg_g = CHG_MUX_REC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          /*read VDIAG VDDA*/
          ASIC_Control_SendReadADCmd();
          rb_ASIC_ALSx_Shortcut_Asked_g |= ASIC_REC_READY_FLG;
        }
        else
        {
          /*change MUX value to INREC with INC*/
          rb_NextMUXCfg_g = CHG_MUX_REC_INC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
        }
      }
      break;
    case 183:
      rb_wait500us_g = 0;
      break;
    case 185:
      if (((rb_ASIC_Sched_Config_g & /*0xC0*/0xC1) == 0) || ((rb_ASIC_Sched_Config_g & 0x20) == 0x20))
      {
        if (   (rb_ASIC_INRECIR_ShortDetected_cnt_g < rb_SC_order1_g)
            || (   (rb_ASIC_INRECIR_ShortDetected_cnt_g >= rb_SC_order2_g)
                && (rb_ASIC_INRECIR_ShortDetected_cnt_g < rb_SC_order3_g)
               )
           )
        {
          /*change MUX value to INREC with INC*/
          rb_NextMUXCfg_g = CHG_MUX_REC_INC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          ASIC_Control_SendReadADCmd();
        }
        else
        {
          /*change MUX value to INREC*/
          rb_NextMUXCfg_g = CHG_MUX_REC;
          rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
          /*read VDIAG VDDA*/
          ASIC_Control_SendReadADCmd();
          rb_ASIC_ALSx_Shortcut_Asked_g |= ASIC_REC_READY_FLG;
        }
      }
      break;
    case 187:
      if((rb_ASIC_Sched_Config_g & 0x2) != 2)
      {
        /*VDR_841 Diagnose pulse and extended diagnose pulse have great values sometimes*/
        /*change MUX value to calibration IRef Low - ICal Low, gain Low, with INC*/
        rb_NextMUXCfg_g = CAL_IHI_ICALHI_GHI_INC;
        rb_NextSPI_Request_g = CB_CHG_MUX_STMEAS_RQ;
        ASIC_Control_SendReadADCmd();
      }
      break;
      
    default:
  
      if (rb_Asic_measureMode_mg == 191)
      {
        if (rbi_ASICgainAdjustRunning_g != TRUE)
        {
          ASIC_Control_AsicStatus();
          rb_NextSPI_Request_g = CB_STMEAS_RQ;
        }
      }
      else
      {
        if (rb_Asic_measureMode_mg % 2 == 1)
        {
          ASIC_Control_RS_Meas();          
        }
      }
      
      if ( ((CB_ASIC_LOOP1_MD==rb_CurMode_g) || (CB_ASIC_LOOP2_MD==rb_CurMode_g)) && (rb_newRSconvRcv_g==TRUE) )
      {
        rb_newRSconvRcv_g = FALSE;
        
        if (rb_REGV_OSAT_g != FALSE)
        {
          /* check if the OSAT flag is true for more than 2000ms*/
          if(rw_REGV_OSAT_cnt_g < CW_REGV_OSAT_CNT_THRSHD)
          {
            rw_REGV_OSAT_cnt_g++;
          }
          else
          {
            /* SM230 - When reading INTV the Regulator Output Saturation Flag is read too - RS_failure*/
            rbi_REGV_OSAT_Error_g = TRUE;
          }
        }
        else
        {
          if(rw_REGV_OSAT_cnt_g>0)
          {
            rw_REGV_OSAT_cnt_g--;
          }
          else
          {
            rbi_REGV_OSAT_Error_g = FALSE;
          }
        }
      }
      break;
    }
#endif /*_NO_RAIN_*/
    
    
/*if the rain functionality is disabled*/
#ifdef _NO_RAIN_
    if (rb_Asic_measureMode_mg >= 72)
#else
    if (rb_Asic_measureMode_mg >= 199)
#endif /*_NO_RAIN_*/
    {
      
      rb_Asic_measureMode_mg = 0;
      /*VDR 875: SM225*/
      if(rb_StaticNoValidAD_cnt_g>0) 
      {
        if(((rb_StaticNoValidAD_cnt_g ^ rb_OldStaticNoValidAD_cnt_l) == 0))
        {
          rb_StaticNoValidAD_cnt_g--;
        }
        else {}
      }
      else
      {
        rbi_ASIC_NoValidAD_Error_g = FALSE;
      }
      rb_OldStaticNoValidAD_cnt_l = rb_StaticNoValidAD_cnt_g;
      
    }
    else
    {
      rb_Asic_measureMode_mg++;
    }
  
}


/*!
* \fn     void ASIC_Control_dot5msTask(void)
* \brief  Measures time critical signals in 0.5ms task.The signals have to be
*         measured and the ASIC switched back in next mode.
*        
* \param  void 
* \return void  
*/
__callt void ASIC_Control_dot5msTask(void)
{
  if ((rbi_Powerfail_g == FALSE)/*&&(rb_AfterVddPowerFailDelay_g ==0)*/ )
  {
    /*are light values initialised?*/
    if ((rbi_LightValuesMeasured_mg == TRUE) && (rbi_FreqMeasureDone == TRUE))
    {
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

      if((rb_ASIC_Sched_Config_g & 0x4) != 4)
      {
        ASIC_Control_STBY_Meas();
      }
      if(rb_Start_STBY_Meas_g==FALSE)
      {
#endif /*_NO_RAIN_*/
        ASIC_Control_measure();
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

        ASIC_Control_LoopMode();
      }
#endif /*_NO_RAIN_*/
    }
    else
    {
      /* Initialisation of variables Run at startup or after powerfail*/
      ASIC_Control_Startup_Init();
    }
  }
  else
  {
    ASIC_Control_RESET_ASIC_ControlMode();
  }
}


/*!
* \fn     void ASIC_Control_Signal_Check(void)
* \brief  Pseudo-code : Checks the Voltages of the ASIC
*        
* \param  void 
* \return void  
*/
static void ASIC_Control_Signal_Check(void)
{
  byte rb_temp_LS_Error_VCalib_meas_l=0;
  byte rb_idx_reg_l;
  
  if ((rbi_UnderVoltage_g == TRUE)&&(rb_LightSignalErrorCnt_g < CB_LIGHT_ERROR_THRESHOLD_MG)) // reset error counter for logamp signals for undervoltage and no present error
  {
    rb_LightSignalErrorCnt_g = 0;
  }
  else if (rbi_LightValuesMeasured_mg == TRUE)
  {
    /* additianal detection of Vref Problems*/
    /* VCO132: Safety Mechanism SM200 -> LS,RS_Failure*/
    if ((rw_Vref_ASIC_g > cw_VREF_MAX_g)||(rw_Vref_ASIC_g < cw_VREF_MIN_g) ||
        (ras_ASIC_MUX_MeasAD_g[IDX_VREF_AD].ad > cw_VREF_MAX_g) || (ras_ASIC_MUX_MeasAD_g[IDX_VREF_AD].ad < cw_VREF_MIN_g))
    {
      if (get_rb_Vref_LightSignalErrorCnt_g() > CB_LIGHT_ERROR_THRESHOLD_MG)
      {

        /* VCO132: Safety Mechanism SM200 -> LS,RS_Failure*/
        rbi_LS_Error_Vref_g = TRUE;
      }
      else
      {
        rb_Vref_LightSignalErrorCnt_g++;
      }
    }
    else
    {
      if(rb_Vref_LightSignalErrorCnt_g>0)
      {
        rb_Vref_LightSignalErrorCnt_g--; /*No Vref Problem*/
      }
      else
      {
        rbi_LS_Error_Vref_g = FALSE;
      }
    }
    
    
    /* Safety Mechanism SM250 -> LS_Failure*/
    /*VDR_839 SM250: Error counter not incrementing properly for calibration values*/
    rb_temp_LS_Error_VCalib_meas_l = FALSE;
    for (rb_idx_reg_l=0; rb_idx_reg_l < (CB_SIZE_OF_ASIC_CALIB_g); rb_idx_reg_l++)
    {
      if ((ras_ASIC_ALI_CalibAD_g[rb_idx_reg_l].avg > caw_ASIC_ALI_CalibAD_Limits_g[rb_idx_reg_l].MAX)||(ras_ASIC_ALI_CalibAD_g[rb_idx_reg_l].avg < caw_ASIC_ALI_CalibAD_Limits_g[rb_idx_reg_l].MIN) || 
          (ras_ASIC_ALI_CalibAD_g[rb_idx_reg_l].ad > caw_ASIC_ALI_CalibAD_Limits_g[rb_idx_reg_l].MAX)||(ras_ASIC_ALI_CalibAD_g[rb_idx_reg_l].ad < caw_ASIC_ALI_CalibAD_Limits_g[rb_idx_reg_l].MIN))
      {
        rb_temp_LS_Error_VCalib_meas_l = TRUE;
      }
    }

    if(rb_temp_LS_Error_VCalib_meas_l==FALSE)
    {
      if(rb_LightSignalErrorCnt_g>0)
      {
        rb_LightSignalErrorCnt_g--;
      }
      else
      {
        rbi_LS_Error_VCalib_meas_g=FALSE;
      }
    }
    else
    {
      
      if (rb_LightSignalErrorCnt_g > CB_LIGHT_ERROR_THRESHOLD_MG)
      {
        rbi_LS_Error_VCalib_meas_g  = TRUE;
      }
      else
      {
        rb_LightSignalErrorCnt_g++;
      }
    }
  }
  else {} /*Misra Rule 14.10*/
  
  
  /*SM240 - Check Supply of ASIC (Single and averaged ADC measurements on diagnostic voltage VDIAG,VDDA / VDDD) - LS,RS_failure*/
  if((rw_VDDD_ASIC_g < cw_VDDD_ASIC_RECOM_MIN_g) || (ras_ASIC_MUX_MeasAD_g[IDX_VDDD_AD].ad < cw_VDDD_ASIC_RECOM_MIN_g) ||
     (rw_VDDA_ASIC_g < cw_VDDA_ASIC_RECOM_MIN_g) || (ras_ASIC_MUX_MeasAD_g[IDX_VDDA_AD].ad < cw_VDDA_ASIC_RECOM_MIN_g) ||
       (rb_ASIC_Reset_Flag_g == TRUE) ||
         (rw_VDDD_ASIC_g > cw_VDDD_ASIC_RECOM_MAX_g) || (ras_ASIC_MUX_MeasAD_g[IDX_VDDD_AD].ad > cw_VDDD_ASIC_RECOM_MAX_g) ||
           (rw_VDDA_ASIC_g > cw_VDDA_ASIC_RECOM_MAX_g) || (ras_ASIC_MUX_MeasAD_g[IDX_VDDA_AD].ad > cw_VDDA_ASIC_RECOM_MAX_g) ||
             (rb_ASIC_SUPVMON_Flag_g == TRUE))
  {

    if(TRUE==rb_VDDx_received_g)
    {
      rb_VDDx_received_g = FALSE;
      /*outside the ELMOS recommended range in datasheet*/
      /*SM240*/
      if (rb_VDD_LightSignalErrorCnt_g > CB_VDDX_ERRORCNT_THRESHOLD_MG)
      {
        rbi_VDD_LightSignalError_g = TRUE;
      }
      else
      {
        rb_VDD_LightSignalErrorCnt_g+=2;
      }
    }
  }
  else if(TRUE==rb_VDDx_received_g)
  {
    rb_VDDx_received_g = FALSE;
    if(rb_VDD_LightSignalErrorCnt_g>0)
    {
      rb_VDD_LightSignalErrorCnt_g--;
    }
    else
    {
      rbi_VDD_LightSignalError_g = FALSE;
    }
  }
  /*VCO_220 VIrefLo/Hi monitoring*/
  if((rw_VIrefLo_ASIC_g<cw_VIREFLO_MIN_g)||(rw_VIrefLo_ASIC_g>cw_VIREFLO_MAX_g) ||
     (ras_ASIC_MUX_MeasAD_g[IDX_VIREF_LO_AD].ad<cw_VIREFLO_MIN_g)||
       (ras_ASIC_MUX_MeasAD_g[IDX_VIREF_LO_AD].ad>cw_VIREFLO_MAX_g) ||
         (rw_VIrefHi_ASIC_g<cw_VIREFHI_MIN_g)||(rw_VIrefHi_ASIC_g>cw_VIREFHI_MAX_g) ||
           (ras_ASIC_MUX_MeasAD_g[IDX_VIREF_HI_AD].ad<cw_VIREFHI_MIN_g)||
             (ras_ASIC_MUX_MeasAD_g[IDX_VIREF_HI_AD].ad>cw_VIREFHI_MAX_g))
  {
    if(rb_VIref_ErrCnt_g < cb_VIREF_ERRCNT_MAX_g)
    {
      rb_VIref_ErrCnt_g+=2;
    }
    else
    {
      rbi_VIref_Error_g = TRUE;
    }
  }
  else if(rb_VIref_ErrCnt_g > 0)
  {
    rb_VIref_ErrCnt_g--;
  }
  else
  {
    rbi_VIref_Error_g = FALSE;
  }

  if ((rbi_UnderVoltage_g == TRUE) || (rbi_OverVoltage_g == TRUE))
  {
    if(rb_VDD_LightSignalErrorCnt_g > CB_VDDX_ERRORCNT_THRESHOLD_MG/2)
    {
      rb_VDD_LightSignalErrorCnt_g = CB_VDDX_ERRORCNT_THRESHOLD_MG/2;
    }      
  }
  
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

  if(rb_LEDx_newval_g==TRUE)
  {
    rb_LEDx_newval_g=FALSE;
    
    if(rb_VLEDx_inLClosed_g==FALSE)
    {
      if ((rw_VLEDA_ASIC_g > (LEDX_LOL_THRS/20)) || (rw_VLEDB_ASIC_g > (LEDX_LOL_THRS/20)))
      {
        if(rb_LEDx_LStop_error_cnt_g<LEDx_CNT_ERR_THRS)
        {
          set_rb_LEDx_LStop_error_cnt_g(rb_LEDx_LStop_error_cnt_g + 3);
        }
        else
        {
          rbi_LEDx_LStop_error_g = TRUE;
        }
      }
      else if(rb_LEDx_LStop_error_cnt_g>0)
      {
        set_rb_LEDx_LStop_error_cnt_g(rb_LEDx_LStop_error_cnt_g - 1 );
       
      }
      else
      {
        rbi_LEDx_LStop_error_g = FALSE;
      }
      
      if ((rb_LEDx_LStop_error_cnt_g==0) && (rbi_Modulator_On_g==TRUE))
      {
        rb_VLEDx_inLClosed_g = TRUE;
      }
    }
    else
    {
      rb_VLEDx_inLClosed_g = FALSE;
      
      if ((rw_VLEDA_ASIC_g < LEDX_LOL_THRS) || ((rw_VLEDB_ASIC_g < LEDX_LOL_THRS)))
      {
        if(rb_LEDx_LClosed_error_cnt_g<LEDx_CNT_ERR_THRS)
        {
          rb_LEDx_LClosed_error_cnt_g ++;
        }
        else
        {
          rbi_LEDx_LClosed_error_g = TRUE;
        }
      }
      else if ( (((rb_FOSC_LEDUL_g&0x3) == 0)&&((rw_VLEDA_ASIC_g > LEDX_UPL_THRS_LEDUL_0) || (rw_VLEDB_ASIC_g > LEDX_UPL_THRS_LEDUL_0))) ||
                (((rb_FOSC_LEDUL_g&0x3) == 1)&&((rw_VLEDA_ASIC_g > LEDX_UPL_THRS_LEDUL_1) || (rw_VLEDB_ASIC_g > LEDX_UPL_THRS_LEDUL_1))) ||
                (((rb_FOSC_LEDUL_g&0x3) == 2)&&((rw_VLEDA_ASIC_g > LEDX_UPL_THRS_LEDUL_2) || (rw_VLEDB_ASIC_g > LEDX_UPL_THRS_LEDUL_2))) ||
                (((rb_FOSC_LEDUL_g&0x3) == 3)&&((rw_VLEDA_ASIC_g > LEDX_UPL_THRS_LEDUL_3) || (rw_VLEDB_ASIC_g > LEDX_UPL_THRS_LEDUL_3))) )
      {
        if(rb_LEDx_LClosed_error_cnt_g<LEDx_CNT_ERR_THRS)
        {
          rb_LEDx_LClosed_error_cnt_g++;
        }
        else
        {
          rbi_LEDx_LClosed_error_g = TRUE;
        }
      }
      else if(rb_LEDx_LClosed_error_cnt_g > 0)
      {
        rb_LEDx_LClosed_error_cnt_g--;
      }
      else
      {
        rbi_LEDx_LClosed_error_g = FALSE;
      }
    }
               
  }
#endif /*_NO_RAIN_*/
  
  if (rb_LightSignalErrorCnt_g > rb_MaxLightSignalErrorCnt_g)
  {
    rb_MaxLightSignalErrorCnt_g = rb_LightSignalErrorCnt_g;
  }
  
  
}


/*!
* \fn     void ASIC_Control_ALS5_LightValScl(byte rb_filter_l)
* \brief  Pseudo-code : calculation according 1 Point calibration for ALS5
*         and copy/scaling for application      
* \param  rb_filter_l
* \return void  
*/
static void ASIC_Control_ALS5_LightValScl(byte rb_filter_l)
{
  unsigned long u32_V_ALS5_ASIC_Corr_Linear_l; /*Variable used to store the delog result of the light value*/
  word rw_V_ALS5_ASIC_Corr_l;                  /*temp  varaible for local usage*/
  
  rw_V_ALS5_ASIC_Corr_l = ASIC_Control_LightValueCorrect(rw_ALS5_ASIC_g,rw_A_Factor_ALS5_g,CHG_MUX_ALS5);  /*VDR_131 2point calibration*/
  u32_V_ALS5_ASIC_Corr_Linear_l = ASIC_Control_DelogLightValue(rw_V_ALS5_ASIC_Corr_l, POTENZ_SCALING_INALS5,  rb_Si_Transmission_g, rbi_negativeSign_mg ); /*delog of logarithmic value for ALS5*/
  
  
  if (u32_V_ALS5_ASIC_Corr_Linear_l < 0x8000U)               /*not over limit for 16bit Value*/ /*VDR_372*/
  {
    rw_V_ALS5_ASIC_Corr_l = (word)u32_V_ALS5_ASIC_Corr_Linear_l;
  }
  else
  {
    rw_V_ALS5_ASIC_Corr_l =  0x7FFF;
  }
  if ((rb_filter_l)&&(rw_V_ALS5_ASIC_Corr_l > 50)) /*VDR_372*/
  {
    set_rw_FW_light16bit_g(((rw_FW_light16bit_g)+(rw_V_ALS5_ASIC_Corr_l))/2); /* VDR_372 scale light value for customer needs with filter*/
  }
  else
  {
    set_rw_FW_light16bit_g(rw_V_ALS5_ASIC_Corr_l);
  }
  
  if(rw_FW_light16bit_g < 64)
  {
    if(rw_FW_light16bit_g>8)
    {
      set_rw_FW_light16bit_g(rw_FW_light16bit_g-(64/rw_FW_light16bit_g));
    }
    else
    {
      set_rw_FW_light16bit_g(0);
    }
  }
  
  /* Scale light value for Application*/  /*VDR_372*/
  if (rw_FW_light16bit_g < 0x3FF)                           /*higher than limit of high value?*/
  {
    rb_FwLightDiv4_g = rw_FW_light16bit_g >> 2 ;   /*copy for LS-Application*/
    if (rw_FW_light16bit_g < 0xff)                   /*higher than limit of low value?*/
    {
      rb_FwLight_g = (byte)rw_FW_light16bit_g;    /* copy into 8 bit variable*/
    }
    else
    {
      rb_FwLight_g = 0xff;        /* set to max value*/
    }
  }
  else
  {
    rb_FwLight_g = 0xff;           /* set to max value*/
    rb_FwLightDiv4_g = 0xff;      /* set to max value*/
  }
  
}

/**** used for HUD  Blake  VCO_477****/
#ifdef HUD_FUNCTION
static void ASIC_Control_HUD_LightValScl(byte rb_filter_l)
{
  unsigned long u32_V_ALS5_ASIC_Corr_Linear_l; /*Variable used to store the delog result of the light value*/
  unsigned long rl_V_ALS5_ASIC_Corr_l;                  /*temp  varaible for local usage*/
  unsigned long HUD_Avg_Brightness;
   
  rl_V_ALS5_ASIC_Corr_l = ASIC_Control_LightValueCorrect(rw_ALS5_ASIC_g,(rw_A_Factor_ALS5_g + rb_HUD_Factor_g),CHG_MUX_ALS5);  /*VDR_131 2point calibration*/
  u32_V_ALS5_ASIC_Corr_Linear_l = ASIC_Control_DelogLightValue(rl_V_ALS5_ASIC_Corr_l, POTENZ_SCALING_INALS5,  rb_Si_Transmission_g, rbi_negativeSign_mg ); /*delog of logarithmic value for ALS5*/
  
  
  if (u32_V_ALS5_ASIC_Corr_Linear_l < 0x14828U)               /*not over limit for 16bit Value*/ /*VDR_372*/
  {
    rl_V_ALS5_ASIC_Corr_l = u32_V_ALS5_ASIC_Corr_Linear_l;
  }
  else
  {
    rl_V_ALS5_ASIC_Corr_l =  0x14828;
  }
   
  
  
  if ((rb_filter_l)&&(rl_V_ALS5_ASIC_Corr_l > 50)) /*VDR_372*/
  {
    HUD_Avg_Brightness = ((rl_HUD_light32bit_g+rl_V_ALS5_ASIC_Corr_l)>>1);
    set_rl_HUD_light32bit_g(HUD_Avg_Brightness); /* VDR_372 scale light value for customer needs with filter*/
  }
  else
  {
    set_rl_HUD_light32bit_g(rl_V_ALS5_ASIC_Corr_l);
  }
   
}
#endif


/*!
* \fn     word ASIC_Control_ALS5_INC_LightValScl(byte rb_filter_l, word rw_temp_ALS5_INC_ASIC_l) 
* \brief  Pseudo-code : calculation according 1 Point calibration for ALS5 with V_INC
* and copy/scaling for application
* \param  rb_filter_l
* \param  rw_temp_ALS5_INC_ASIC_l
* \return word  
*/
/*SM260: Light values from ALSx_INC used in the veto_counter*/
static word ASIC_Control_ALS5_INC_LightValScl(byte rb_filter_l, word rw_temp_ALS5_INC_ASIC_l)
{
  word rw_temp_FW_INC_light16bit_l=0;
  unsigned long u32_V_ALS5_INC_ASIC_Corr_Linear_l; /*Variable used to store the delog result of the light value*/
  word rw_V_ALS5_INC_ASIC_Corr_l;                  /*temp  varaible for local usage*/
  
  rw_V_ALS5_INC_ASIC_Corr_l = ASIC_Control_LightValueCorrect(rw_temp_ALS5_INC_ASIC_l,rw_A_Factor_ALS5_g,CHG_MUX_ALS5_INC);  /*VDR_131 2point calibration*/
  u32_V_ALS5_INC_ASIC_Corr_Linear_l = ASIC_Control_DelogLightValue(rw_V_ALS5_INC_ASIC_Corr_l, POTENZ_SCALING_INALS5,  rb_Si_Transmission_g, rbi_negativeSign_mg ); /*delog of logarithmic value for ALS% with V_INC*/
  
  
  if (u32_V_ALS5_INC_ASIC_Corr_Linear_l < 0x8000U)               /*not over limit for 16bit Value*/ /*VDR_372*/
  {
    rw_V_ALS5_INC_ASIC_Corr_l = (word)u32_V_ALS5_INC_ASIC_Corr_Linear_l;
  }
  else
  {
    rw_V_ALS5_INC_ASIC_Corr_l =  0x7FFF;
  }
  if ((rb_filter_l)&&(rw_V_ALS5_INC_ASIC_Corr_l > 50)) /*VDR_372*/
  {
    rw_temp_FW_INC_light16bit_l = ((rw_FW_INC_light16bit_g)+(rw_V_ALS5_INC_ASIC_Corr_l))/2; /* VDR_372 scale light value for customer needs with filter*/
  }
  else
  {
    rw_temp_FW_INC_light16bit_l = rw_V_ALS5_INC_ASIC_Corr_l;
  }
  
  if(rw_temp_FW_INC_light16bit_l < 64)
  {
    if(rw_temp_FW_INC_light16bit_l>8)
    {
      rw_temp_FW_INC_light16bit_l=rw_temp_FW_INC_light16bit_l-(64/rw_temp_FW_INC_light16bit_l);
    }
    else
    {
      rw_temp_FW_INC_light16bit_l=0;
    }
  }
  return rw_temp_FW_INC_light16bit_l;
}


/*!
* \fn     void ASIC_Control_ALS2_LightValScl(byte rb_filter_l)
* \brief  Pseudo-code : calculation according 2Point calibration for ALS2
* and copy/scaling for application
* \param  rb_filter_l
* \return void   
*/
static void ASIC_Control_ALS2_LightValScl(byte rb_filter_l)
{
  unsigned long u32_V_ALS2_ASIC_Corr_Linear_l; /*Variable used to store the delog result of the light value*/
  /** \brief intermediary result of delogarithm for ALS2*/
  word rw_V_ALS2_ASIC_Corr_l;

  rw_V_ALS2_ASIC_Corr_l =  ASIC_Control_LightValueCorrect(rw_ALS2_ASIC_g,rw_A_Factor_ALS2_g, CHG_MUX_ALS2);  /*VDR131 2point calibration */
  
  u32_V_ALS2_ASIC_Corr_Linear_l = ASIC_Control_DelogLightValue(rw_V_ALS2_ASIC_Corr_l, POTENZ_SCALING_INALS2,  rb_550nm_Transmission_g,rbi_negativeSign_mg ); /*delog of logarithmic value for INREC*/
  
  
  
  if (u32_V_ALS2_ASIC_Corr_Linear_l < 0x8000U)               /*not over limit for 16bit Value*/
  {
    rw_V_ALS2_ASIC_Corr_l = (word)u32_V_ALS2_ASIC_Corr_Linear_l;
  }
  else
  {
    rw_V_ALS2_ASIC_Corr_l =  0x7FFF;
  }
  
  if ((rb_filter_l)&&(rw_V_ALS2_ASIC_Corr_l > 50))
  {
    /* VDR_372 scale light value for customer needs with filter*/
    set_rw_Amb_light16bit_g(((rw_Amb_light16bit_g)+(rw_V_ALS2_ASIC_Corr_l))/2);

  }
  else /* filering*/
  {
    set_rw_Amb_light16bit_g(rw_V_ALS2_ASIC_Corr_l);
   
  }
#ifdef HUD_FUNCTION
  if(rw_Amb_light16bit_g<16)
  {
    if(rw_Amb_light16bit_g>4)
    {
      set_rw_Amb_light16bit_g(rw_Amb_light16bit_g-(16/rw_Amb_light16bit_g));
    }
    else
    {
      set_rw_Amb_light16bit_g(0);
    }
  }
#endif 
}


/*!
* \fn      word ASIC_Control_ALS2_INC_LightValScl(byte rb_filter_l, word rw_temp_ALS2_INC_ASIC_l)
* \brief   Pseudo-code : calculation according 2Point calibration for ALS2 with V_INC
* and copy/scaling for application
* 
* \param   rb_filter_l
* \param   rw_temp_ALS2_INC_ASIC_l
* \return  word 
*/
/*SM260: Light values from ALSx_INC used in the veto_counter*/
static word ASIC_Control_ALS2_INC_LightValScl(byte rb_filter_l, word rw_temp_ALS2_INC_ASIC_l)
{
  word rw_temp_Amb_INC_light16bit_l=0;
  unsigned long u32_V_ALS2_INC_ASIC_Corr_Linear_l; /*Variable used to store the delog result of the light value*/
  /** \brief intermediary result of delogarithm for ALS2*/
  word rw_V_ALS2_INC_ASIC_Corr_l;
  rw_V_ALS2_INC_ASIC_Corr_l =  ASIC_Control_LightValueCorrect(rw_temp_ALS2_INC_ASIC_l,rw_A_Factor_ALS2_g, CHG_MUX_ALS2_INC);  /*VDR131 2point calibration */
  
  u32_V_ALS2_INC_ASIC_Corr_Linear_l = ASIC_Control_DelogLightValue(rw_V_ALS2_INC_ASIC_Corr_l, POTENZ_SCALING_INALS2,  rb_550nm_Transmission_g,rbi_negativeSign_mg ); /*delog of logarithmic value for ALS2 with V_INC*/
  
  
  
  if (u32_V_ALS2_INC_ASIC_Corr_Linear_l < 0x8000U)               /*not over limit for 16bit Value*/
  {
    rw_V_ALS2_INC_ASIC_Corr_l = (word)u32_V_ALS2_INC_ASIC_Corr_Linear_l;
  }
  else
  {
    rw_V_ALS2_INC_ASIC_Corr_l =  0x7FFF;
  }
  
  if ((rb_filter_l)&&(rw_V_ALS2_INC_ASIC_Corr_l > 50))
  {
    rw_temp_Amb_INC_light16bit_l = ((rw_Amb_INC_light16bit_g)+(rw_V_ALS2_INC_ASIC_Corr_l))/2; /* VDR_372 scale light value for customer needs with filter*/
  }
  else /* filering*/
  {
    rw_temp_Amb_INC_light16bit_l = rw_V_ALS2_INC_ASIC_Corr_l;
  }
  
  if(rw_temp_Amb_INC_light16bit_l<16)
  {
    if(rw_temp_Amb_INC_light16bit_l>4)
    {
      rw_temp_Amb_INC_light16bit_l=rw_temp_Amb_INC_light16bit_l-(16/rw_temp_Amb_INC_light16bit_l);
    }
    else
    {
      rw_temp_Amb_INC_light16bit_l=0;
    }
  }
  return rw_temp_Amb_INC_light16bit_l;
}


/*!
* \fn     void ASIC_Control_ALS1_LightValScl(byte rb_filter_l)
* \brief  Pseudo-code : calculation according 2Point calibration for Solar ALS1 (positioned on the driver side - left, and looking to the right)
*         and copy/scaling for application 
* \param  rb_filter_l 
* \return void 
*/
static void ASIC_Control_ALS1_LightValScl(byte rb_filter_l)
{
  unsigned long u32_V_ALS1_ASIC_Corr_Linear_l; /*Variable used to store the delog result of the light value*/
  /** \brief intermediary result of delogarithm for ALS1*/
  word rw_V_ALS1_ASIC_Corr_l;
  rw_V_ALS1_ASIC_Corr_l =  ASIC_Control_LightValueCorrect(rw_ALS1_ASIC_g,rw_A_Factor_ALS1_g, CHG_MUX_ALS1);  /*VDR131 2point calibration */
  
  u32_V_ALS1_ASIC_Corr_Linear_l = ASIC_Control_DelogLightValue(rw_V_ALS1_ASIC_Corr_l, POTENZ_SCALING_INALS1,  rb_880nm_Transmission_g,rbi_negativeSign_mg ); /*delog of logarithmic value for INREC*/
  
  
  if (u32_V_ALS1_ASIC_Corr_Linear_l < 0x8000U)               //not over limit for 16bit Value
  {
    rw_V_ALS1_ASIC_Corr_l = (word)u32_V_ALS1_ASIC_Corr_Linear_l;
  }
  else
  {
    rw_V_ALS1_ASIC_Corr_l =  0x7FFF;
  }
  if ((rb_filter_l)&&(rw_V_ALS1_ASIC_Corr_l > 50))
  {
    rw_Solar_light16bit_1_g = ((rw_Solar_light16bit_1_g)+(rw_V_ALS1_ASIC_Corr_l))/2; // VDR_372 scale light value for customer needs with filter
  }
  else /* filering*/
  {
    rw_Solar_light16bit_1_g = rw_V_ALS1_ASIC_Corr_l;
  }
}


/*!
* \fn       void ASIC_Control_ALS6_LightValScl(byte rb_filter_l)
* \brief    Pseudo-code : Calculation according 2Point calibration for Solar ALS6 (positioned on the passenger side - right, and looking to the left)
*           and copy/scaling for application   
* \param    rb_filter_l  -
* \return   void        
*/
static void ASIC_Control_ALS6_LightValScl(byte rb_filter_l)
{
  unsigned long u32_V_ALS6_ASIC_Corr_Linear_l; /*Variable used to store the delog result of the light value*/
  /** \brief intermediary result of delogarithm for ALS6*/
  word rw_V_ALS6_ASIC_Corr_l;
  rw_V_ALS6_ASIC_Corr_l =  ASIC_Control_LightValueCorrect(rw_ALS6_ASIC_g,rw_A_Factor_ALS6_g, CHG_MUX_ALS6);  /*VDR131 2point calibration */
  
  u32_V_ALS6_ASIC_Corr_Linear_l = ASIC_Control_DelogLightValue(rw_V_ALS6_ASIC_Corr_l, POTENZ_SCALING_INALS6,  rb_880nm_Transmission_g,rbi_negativeSign_mg ); /*delog of logarithmic value for INREC*/
  
  
  if (u32_V_ALS6_ASIC_Corr_Linear_l < 0x8000U)               //not over limit for 16bit Value
  {
    rw_V_ALS6_ASIC_Corr_l = (word)u32_V_ALS6_ASIC_Corr_Linear_l;
  }
  else
  {
    rw_V_ALS6_ASIC_Corr_l =  0x7FFF;
  }
  if ((rb_filter_l)&&(rw_V_ALS6_ASIC_Corr_l > 50))
  {
    rw_Solar_light16bit_2_g = ((rw_Solar_light16bit_2_g)+(rw_V_ALS6_ASIC_Corr_l))/2; // VDR_372 scale light value for customer needs with filter
  }
  else /* filering*/
  {
    rw_Solar_light16bit_2_g = rw_V_ALS6_ASIC_Corr_l;
  }
}


/*!
* \fn    void ASIC_Control_INMODON_LightValScl(void)
* \brief  Pseudo-code : calculation according 2Point calibration for VInrec with modulator on
* and copy/scaling for application, in addition the value for the optical coupling is calculated
* rb_IR_DeltaModON_g
* \param  void 
* \return void 
*/
static void ASIC_Control_INMODON_LightValScl(void)
{
  word rw_V_INREC_MOD_ON_ASIC_Corr_l;
  unsigned long u32_V_INREC_MOD_ON_ASIC_Corr_Linear_l; /*Variable used to store the delog result of the light value*/
  
  rw_V_INREC_MOD_ON_ASIC_Corr_l =  ASIC_Control_LightValueCorrect(rw_INREC_MOD_ON_g,rw_A_Factor_INREC_g,CHG_MUX_REC);           //VDR_131 2-Point calibration
  u32_V_INREC_MOD_ON_ASIC_Corr_Linear_l = ASIC_Control_DelogLightValue(rw_V_INREC_MOD_ON_ASIC_Corr_l, POTENZ_SCALING_INREC,  rb_880nm_Transmission_g,rbi_negativeSign_mg );//delog of logarithmic value for INREC
  
  if (u32_V_INREC_MOD_ON_ASIC_Corr_Linear_l> 0xffffU)
  {
    rw_IR_light16bit_Mod_On_g = 0xffffU;
  }
  else
  {
    rw_IR_light16bit_Mod_On_g = (word)( u32_V_INREC_MOD_ON_ASIC_Corr_Linear_l);
  }
  
  if (rw_IR_light16bit_g < rw_IR_light16bit_Mod_On_g)
  {
    if((rw_IR_light16bit_Mod_On_g - rw_IR_light16bit_g)<255)
    {
      rb_IR_DeltaModON_g = (rw_IR_light16bit_Mod_On_g - rw_IR_light16bit_g);
    }
    else
    {
      rb_IR_DeltaModON_g = 255;
    }
  }
  else
  {
    rb_IR_DeltaModON_g = 0;
  }
}


/*!
* \fn     void ASIC_Control_INREC_LightValScl(byte rb_filterInrec_l)
* \brief  seudo-code : calculation according 2Point calibration for VInrec and copy/scaling for application
*        
* \param  rb_filterInrec_l  - if this value is > 0 the light parameter is TP-filtered with the old value
* \return void 
*/
static void ASIC_Control_INREC_LightValScl(byte rb_filterInrec_l)
{
  
  unsigned long u32_V_INREC_ASIC_Corr_Linear_l; /*Variable used to store the delog result of the light value*/
  /** \brief intermediary result of delogarithm for INREC1*/
  word rw_V_INREC_ASIC_Corr_l;
  
  rw_V_INREC_ASIC_Corr_l =  ASIC_Control_LightValueCorrect(rw_INREC_ASIC_g,rw_A_Factor_INREC_g,CHG_MUX_REC);           /*VDR_131 2-Point calibration*/
  u32_V_INREC_ASIC_Corr_Linear_l = ASIC_Control_DelogLightValue(rw_V_INREC_ASIC_Corr_l, POTENZ_SCALING_INREC,  rb_880nm_Transmission_g,rbi_negativeSign_mg );/*delog of logarithmic value for INRECC*/
  
  
  if (u32_V_INREC_ASIC_Corr_Linear_l < 0x8000U)               /*not over limit for 16bit Value*/
  {
    rw_V_INREC_ASIC_Corr_l = (word)u32_V_INREC_ASIC_Corr_Linear_l;
  }
  else
  {
    rw_V_INREC_ASIC_Corr_l =  0x7FFF;
  }
  if ((rb_filterInrec_l)&&(rw_V_INREC_ASIC_Corr_l > 50))
  {
    set_rw_IR_light16bit_g(((rw_IR_light16bit_g)+(rw_V_INREC_ASIC_Corr_l))/2); /* VDR_372 scale light value for customer needs with filter*/
  }
  else
  {
    set_rw_IR_light16bit_g(rw_V_INREC_ASIC_Corr_l);
  }
  
  if(rw_IR_light16bit_g < 36)
  {
    if(rw_IR_light16bit_g>6)
    {
      set_rw_IR_light16bit_g(rw_IR_light16bit_g-(36/rw_IR_light16bit_g));
    }
    else
    {
      set_rw_IR_light16bit_g(0);
    }
  }

  
  if ((rw_IR_light16bit_g>>3) < 255)         /* higher than limit of high value?*/
  {
    rb_IrLightDiv8_g = (rw_IR_light16bit_g>>3);       /*copy for LS-Application*/
  }
  else
  {
    rb_IrLightDiv8_g = 0xff;                        /* set to max-value*/
  }
}


/*! 
* \fn      word ASIC_Control_INREC_INC_LightValScl(byte rb_filterInrec_l, word rw_temp_REC_INC_ASIC_l)
* \brief   Pseudo-code : Calculation according 2Point calibration for VInrec with V_INC
* and copy/scaling for application
*        
* \param   rb_filterInrec_l        - rb_filterInrec_l: if this value is > 0 the light parameter is TP-filtered with the old value
* \param   rw_temp_REC_INC_ASIC_l  -
* \return  word                    -  
*/
/*SM260: Light values from ALSx_INC used in the veto_counter*/
static word ASIC_Control_INREC_INC_LightValScl(byte rb_filterInrec_l, word rw_temp_REC_INC_ASIC_l)
{
  word rw_temp_IR_INC_light16bit_l=0;
  unsigned long u32_V_INREC_INC_ASIC_Corr_Linear_l; /*Variable used to store the delog result of the light value*/
  /** \brief intermediary result of delogarithm for INREC with V_INC*/
  word rw_V_INREC_INC_ASIC_Corr_l;
  
  rw_V_INREC_INC_ASIC_Corr_l =  ASIC_Control_LightValueCorrect(rw_temp_REC_INC_ASIC_l,rw_A_Factor_INREC_g,CHG_MUX_REC_INC);           /*VDR_131 2-Point calibration*/
  u32_V_INREC_INC_ASIC_Corr_Linear_l = ASIC_Control_DelogLightValue(rw_V_INREC_INC_ASIC_Corr_l, POTENZ_SCALING_INREC,  rb_880nm_Transmission_g,rbi_negativeSign_mg );/*delog of logarithmic value for INREC with V_INC*/
  
  
  if (u32_V_INREC_INC_ASIC_Corr_Linear_l < 0x8000U)               /*not over limit for 16bit Value*/
  {
    rw_V_INREC_INC_ASIC_Corr_l = (word)u32_V_INREC_INC_ASIC_Corr_Linear_l;
  }
  else
  {
    rw_V_INREC_INC_ASIC_Corr_l =  0x7FFF;
  }
  if ((rb_filterInrec_l)&&(rw_V_INREC_INC_ASIC_Corr_l > 50))
  {
    rw_temp_IR_INC_light16bit_l = ((rw_IR_INC_light16bit_g)+(rw_V_INREC_INC_ASIC_Corr_l))/2; /* VDR_372 scale light value for customer needs with filter*/
  }
  else
  {
    rw_temp_IR_INC_light16bit_l = rw_V_INREC_INC_ASIC_Corr_l;
  }
  
  if(rw_temp_IR_INC_light16bit_l < 36)
  {
    if(rw_temp_IR_INC_light16bit_l>6)
    {
      rw_temp_IR_INC_light16bit_l = rw_temp_IR_INC_light16bit_l-(36/rw_temp_IR_INC_light16bit_l);
    }
    else
    {
      rw_temp_IR_INC_light16bit_l=0;
    }
  }
  return rw_temp_IR_INC_light16bit_l;
}


/*!
* \fn   unsigned long ASIC_Control_DelogLightValue(word rw_CorrectedVoltage_l, word rw_PotenzScalingfaktor_l, byte rb_WindshieldTransPerCent_l,byte rb_negativeSign_l )
* \brief Pseudo-code :
* result = (rb_WindshieldTransPerCent_l/100)*u32_PotenzScalingfaktor_l*2^(rw_CorrectedVoltage_l)
*        
* \param   rw_CorrectedVoltage_l        - Corrected voltage of light value
*          rw_PotenzScalingfaktor_l     - Faktor to scale result
*		   rb_WindshieldTransPerCent_l  - Windshield Transmission in percent
*          rb_negativeSign_l            - 
* \return  unsigned long                - Result from calculation:
*/
static unsigned long ASIC_Control_DelogLightValue(word rw_CorrectedVoltage_l, word rw_PotenzScalingfaktor_l, byte rb_WindshieldTransPerCent_l,byte rb_negativeSign_l )
{
  word rw_tempvalue_l;               //declaration local variable
  byte rb_ExpRest_l;
  unsigned long u32_V_ASIC_Corr_Linear_l;
  /** \brief look up table for delog*/
  static __far const byte cab_LookUp2Exp_32tel[32] = {128, 131, 134, 137, 140, 143, 146, 149, 152, 156, 159, 162, 166, 170, 173, 177, 181, 185, 189, 193, 197, 202, 206, 211, 215, 220, 225, 230, 235, 240, 245, 251};
  
  
  
  rw_tempvalue_l = rw_CorrectedVoltage_l >> 5;  //copy integer value of the word into the temp variable
  rb_ExpRest_l = cab_LookUp2Exp_32tel[(byte)((rw_CorrectedVoltage_l)&0x1f)];//calculate the decimal value of the power  (32tel)
  
  // multiply windshield transmission with potenzscaling faktor
  rw_PotenzScalingfaktor_l = ((rw_PotenzScalingfaktor_l)/ rb_WindshieldTransPerCent_l);

  if (rb_negativeSign_l == FALSE)  // negative or positve Exponent?
  {
    
    if ((0xFFFFFFFFU >> rw_tempvalue_l) > (rw_PotenzScalingfaktor_l)) //lower limit for shift operations?
    {
      u32_V_ASIC_Corr_Linear_l =(rb_ExpRest_l*(((unsigned long)(rw_PotenzScalingfaktor_l)) <<(rw_tempvalue_l)))>>7;     //shift left and scale
    }
    else
    {
      u32_V_ASIC_Corr_Linear_l = 0xFFFFFFFFU;     /* write max value*/
    }
  }
  else
  {
    u32_V_ASIC_Corr_Linear_l =((((unsigned long)(rw_PotenzScalingfaktor_l))<<7) >> (rw_tempvalue_l))/rb_ExpRest_l;    //right and scale
  }
  
  return (u32_V_ASIC_Corr_Linear_l); // return linear result
}


/*!
* \fn    word ASIC_Control_LightValueCorrect(word rw_LightVoltage_l, word rw_a_Faktor_l, byte rb_MUX_cfg_ALSx_l)
* \brief  Pseudo-code :
* result = 32*(rw_a_Faktor_l+rb_B_Faktor_l*(rw_LightVoltage_l-Vref)/(Vout(Ical)-Vref)))
* + sign as global variable
* \param  rw_LightVoltage_l  Voltage of measured light value
* \param  rw_a_Faktor_l      correction faktor a for logarithm = 32 * Log2(a)
* \param  rb_MUX_cfg_ALSx_l
* \return  word     result = 32*rw_a_Faktor_l+rb_B_Faktor_l*(rw_LightVoltage_l-Vref)/(Vout(Ical)-Vref))
*                   + sign as global variable
*/
static word ASIC_Control_LightValueCorrect(word rw_LightVoltage_l, word rw_a_Faktor_l, byte rb_MUX_cfg_ALSx_l) /*VDR_131*/
{
  word rw_tempresult_l;            /*declaration local variable*/
  word rw_Vref_minusVcal_l;
  byte rb_B_Faktor_l;
  ASIC_ALI_CalibAD_Limits_t cw_VCAL_Lim_l;
  ASIC_ALI_CalibAD_Limits_t rw_IrefToIcal_Lim_l;
  ASIC_ALI_CalibAD_Limits_t raw_IrefToIcal_Lim_l[7];
  byte rab_B_Faktor_l[4];
  word raw_IrefToIcal_l[7];

  word rw_CalibrationCurrent_l;
  word rw_IrefToIcal_l;
  
  rw_tempresult_l = (rb_MUX_cfg_ALSx_l >> 2);
  
  raw_IrefToIcal_l[0] = ras_ASIC_ALI_CalibAD_g[1].avg;
  raw_IrefToIcal_l[1] = ras_ASIC_ALI_CalibAD_g[0].avg;
  raw_IrefToIcal_l[2] = ras_ASIC_ALI_CalibAD_g[4].avg;
  raw_IrefToIcal_l[3] = ras_ASIC_ALI_CalibAD_g[5].avg;
  raw_IrefToIcal_l[4] = ras_ASIC_ALI_CalibAD_g[7].avg;
  raw_IrefToIcal_l[5] = ras_ASIC_ALI_CalibAD_g[6].avg;
  raw_IrefToIcal_l[6] = ras_ASIC_ALI_CalibAD_g[9].avg;
  
  rab_B_Faktor_l[0] = rb_B_Factor_Iref_Lo_Gain_Lo_g;
  rab_B_Faktor_l[1] = rb_B_Factor_Iref_Hi_Gain_Lo_g;
  rab_B_Faktor_l[2] = rb_B_Factor_Iref_Lo_Gain_Hi_g;
  rab_B_Faktor_l[3] = rb_B_Factor_Iref_Hi_Gain_Hi_g;
  
  raw_IrefToIcal_Lim_l[0] = caw_ASIC_ALI_CalibAD_Limits_g[1];
  raw_IrefToIcal_Lim_l[1] = caw_ASIC_ALI_CalibAD_Limits_g[0];
  raw_IrefToIcal_Lim_l[2] = caw_ASIC_ALI_CalibAD_Limits_g[4];
  raw_IrefToIcal_Lim_l[3] = caw_ASIC_ALI_CalibAD_Limits_g[5];
  raw_IrefToIcal_Lim_l[4] = caw_ASIC_ALI_CalibAD_Limits_g[7];
  raw_IrefToIcal_Lim_l[5] = caw_ASIC_ALI_CalibAD_Limits_g[6];
  raw_IrefToIcal_Lim_l[6] = caw_ASIC_ALI_CalibAD_Limits_g[9];
  
  
  if(rw_tempresult_l<0x20)
  {
    rw_CalibrationCurrent_l = ras_ASIC_ALI_CalibAD_g[rw_tempresult_l/8].avg;
    rw_IrefToIcal_l = raw_IrefToIcal_l[rw_tempresult_l/8];
    
    cw_VCAL_Lim_l = caw_ASIC_ALI_CalibAD_Limits_g[rw_tempresult_l/8];
    rw_IrefToIcal_Lim_l = raw_IrefToIcal_Lim_l[rw_tempresult_l/8];
    /*elimination of offset in amplifier:*/
    rb_B_Faktor_l = rab_B_Faktor_l[(rw_tempresult_l/8)];
  }
  else
  {
    if((rw_tempresult_l&3)!=3)
    {
      rw_CalibrationCurrent_l = ras_ASIC_ALI_CalibAD_g[6+(rw_tempresult_l%4)].avg;
      rw_IrefToIcal_l = raw_IrefToIcal_l[4+(rw_tempresult_l%4)];
      
      cw_VCAL_Lim_l = caw_ASIC_ALI_CalibAD_Limits_g[6+(rw_tempresult_l%4)];
      rw_IrefToIcal_Lim_l = raw_IrefToIcal_Lim_l[4+(rw_tempresult_l%4)];
      /*elimination of offset in amplifier:*/
      rb_B_Faktor_l = rab_B_Faktor_l[rw_tempresult_l%4];
    }
    else
    {
      rw_CalibrationCurrent_l = ras_ASIC_ALI_CalibAD_g[8].avg;
      rw_IrefToIcal_l = raw_IrefToIcal_l[6];
      
      cw_VCAL_Lim_l = caw_ASIC_ALI_CalibAD_Limits_g[8];
      rw_IrefToIcal_Lim_l = raw_IrefToIcal_Lim_l[6];
      /*elimination of offset in amplifier:*/
      rb_B_Faktor_l = rab_B_Faktor_l[rw_tempresult_l%4];
    }
  }
  
  
  if (((rw_CalibrationCurrent_l > cw_VCAL_Lim_l.MAX)||(rw_CalibrationCurrent_l < cw_VCAL_Lim_l.MIN))
      || ((rw_IrefToIcal_l > rw_IrefToIcal_Lim_l.MAX)||(rw_IrefToIcal_l < rw_IrefToIcal_Lim_l.MIN)))            /* are signals out of range!*/
  {
    rbi_negativeSign_mg = TRUE;                /*set positive sign */
    rw_tempresult_l = 512;                     /* use very dark brightness!*/
    rw_Vref_minusVcal_l = 126;                /* use default value*/
  }
  else
  {
    rw_Vref_plusVoff_g = (rw_IrefToIcal_l + rw_CalibrationCurrent_l+1)>>1;
    
    if (rw_LightVoltage_l >= rw_Vref_plusVoff_g)                          /*Vout(INAMB1>=-Vref?*/
    {
      rbi_negativeSign_mg = FALSE;                //set positive sign
      rw_tempresult_l = (rw_LightVoltage_l - rw_Vref_plusVoff_g);          //Result0 = Vref-Vout(INAMB1)
    }
    else
    {
      rbi_negativeSign_mg = TRUE;            //set negative sign
      rw_tempresult_l = (rw_Vref_plusVoff_g-rw_LightVoltage_l);               //Result0 =Vout(INAMB1)-Vref
    }
    
    if (rw_Vref_plusVoff_g > rw_CalibrationCurrent_l)
    {
      rw_Vref_minusVcal_l = rw_Vref_plusVoff_g - rw_CalibrationCurrent_l;
    }
    else
    {
      rbi_negativeSign_mg ^= TRUE;
      rw_Vref_minusVcal_l = rw_CalibrationCurrent_l - rw_Vref_plusVoff_g;
    }
    if (rw_CalibrationCurrent_l < rw_IrefToIcal_l)
    {
      rbi_negativeSign_mg ^= TRUE;
    }

  }

    rw_tempresult_l = (word)(((long)(rw_tempresult_l)*(rb_B_Faktor_l))/(rw_Vref_minusVcal_l)); /*VDR_131*/// Result1=b*32*(Result0/(Vout(Ical)-Vref))
  
  if (rw_a_Faktor_l > 512) // Afactor positive?
  {
    if (rbi_negativeSign_mg == FALSE)              //sign positive?
    {
      rw_tempresult_l = (rw_a_Faktor_l-512)+rw_tempresult_l;     // Result2 = (32*Afactor+Result1)
    }
    else if ((rw_a_Faktor_l - 512) <= rw_tempresult_l)  //AFactor < tempresult   tempresult negative
    {
      rw_tempresult_l = rw_tempresult_l-(rw_a_Faktor_l-512);  //Result2 = Result1-(32*Afactor)
    }
    else
    {
      rbi_negativeSign_mg = FALSE;
      rw_tempresult_l = (rw_a_Faktor_l-512)-(rw_tempresult_l);   //Result2 = (32*Afactor)-Result1
    }
  }
  else
  {
    if (rbi_negativeSign_mg == FALSE) // sign positive?
    {
      if ((512-rw_a_Faktor_l) <= rw_tempresult_l)  //(32*Afactor)<=Result1?
      {
        rw_tempresult_l = rw_tempresult_l -(512-rw_a_Faktor_l);  // Result2 = Result1-(32*Afactor)
      }
      else
      {
        rw_tempresult_l = (512-rw_a_Faktor_l)-rw_tempresult_l; // Result2 = (32*Afactor)-Result1
        rbi_negativeSign_mg = TRUE; // sign change
      }
    }
    else
    {
      rw_tempresult_l =  rw_tempresult_l + (512-rw_a_Faktor_l);    // Result2 = (32*Afactor)+Result1
      
    }
  }

  return(rw_tempresult_l); //return: -> Result2
}


/*!
* \fn     void ASIC_Control_ASIC_ErrFlags_Check(void)
* \brief  - The monitoring of error code (0x55) to the cksum sent back by ASIC when a read command is performed
*         - an attempt of recover is done, by resetting of the ASIC, before setting the LS,RS_Error
* \param  void 
* \return void  
*/
void ASIC_Control_ASIC_ErrFlags_Check(void)
{
  static byte rb_ASIC_SPI_RstToRecoverDone_l = FALSE;

  if(CASE_ASIC_CNT_MD_STANDBY == rb_ASIC_ControlMode_g)
  {
    ras_ASIC_CtrReg_g[IDX_STATH_REG].val &= (0xF7);
  }
  
  if( ((rb_ASIC_SPI_ErrorFlag_g == TRUE) && (CASE_ASIC_CNT_MD_STANDBY != rb_ASIC_ControlMode_g)) ||
        ( (((ras_ASIC_CtrReg_g[IDX_STATH_REG].val & 0x1F) != 0) && (CASE_ASIC_CNT_MD_STANDBY != rb_ASIC_ControlMode_g)) ||
        (((ras_ASIC_CtrReg_g[IDX_STATH_REG].val & 0x17) != 0) && (CASE_ASIC_CNT_MD_STANDBY == rb_ASIC_ControlMode_g)) || 
        ((ras_ASIC_CtrReg_g[IDX_STATL_REG].val & 0xE0) != 0) ) && (TRUE==rb_newAsicSTAT_g)/* && (rbi_FreqMeasureDone == TRUE) && (rbi_LightValuesMeasured_mg == TRUE)*/ )
  {
    
    rb_newAsicSTAT_g = FALSE;
    /*set the error flag also for STATH,L registers and reset it after sending another read command for STATH,L register*/
    set_rb_ASIC_SPI_ErrorFlag_g(TRUE);
    
    /*is reset flag set?*/
    if((ras_ASIC_CtrReg_g[IDX_STATH_REG].val&0x10)==0x10)
    {
      rb_ASIC_SPI_ErrorCodeCnt_g += 5;
      rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;        /*set case CASE_ASIC_CNT_MD_RESET*/
    }

    if(rb_ASIC_SPI_ErrorCodeCnt_g < cb_ASIC_SPI_ERRORCODE_CNT_THRSHD_g)
    {
      rb_ASIC_SPI_ErrorCodeCnt_g += 5;
    }
    else
    {
      /*SM224 - Check for invalid command / Reset or invalid Write Adress and Overvoltage and Test Mode - LS,RS_Error*/
      rbi_ASIC_SPI_Error_g = TRUE;
    }
    if((rb_ASIC_SPI_ErrorCodeCnt_g >= cb_ASIC_SPI_ERRORCODE_CNT_THRSHD_g/2) && (rb_ASIC_SPI_RstToRecoverDone_l == FALSE))
    {
      rb_ASIC_SPI_RstToRecoverDone_l = TRUE;
      /*reset ASIC*/
      rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;        /*set case CASE_ASIC_CNT_MD_RESET*/
    }
  }
  else
  {
  
    if((rb_ASIC_SPI_ErrorFlag_g == FALSE) && (rb_ASIC_SPI_ErrorCodeCnt_g>0))
    {
        rb_ASIC_SPI_ErrorCodeCnt_g--;
    }
    else
    {
        rbi_ASIC_SPI_Error_g = FALSE;
        rb_ASIC_SPI_RstToRecoverDone_l = FALSE;
    }
  }
}


/*if the rain functionality is enabled*/
/*!
* \fn     void ASIC_Control_STBY_Meas(void)
* \brief 
*        
* \param  void 
* \return void  
*/
#ifndef _NO_RAIN_
static void ASIC_Control_STBY_Meas(void)
{

  word rw_deltaINTV_l=0;
  byte rb_tempGainOffset_l=0;
  static word rw_INTV_old_l;
  static word rw_REGV_temp_l;
  static word rw_REGV_old_l;
  static byte rb_Asic_Meas_STBY_l;
  
  static byte rw_STBY_param_OutofRange_cnt_l=0;
  /*static byte rb_ready2WrEEPROMcnt_l;*/
  static byte rb_wait4integration_l=0;
  static byte rb_Timeout_STBY_Meas_l;
  word rw_Stby_DeltaINTV_l = (word)(((((word)rb_STBY_DELTA_INTV_HB_g)<<8)) + rb_STBY_DELTA_INTV_LB_g);
  
   
#ifdef STARTUP_WIPE     
  word rw_Tol_deltaINTV_l;
#endif
  /*minimum 2 seconds for the next coupling measurement*/
  if(rw_NoRainPresentCntThrsh_g<2)
  {
    rw_NoRainPresentCntThrsh_g=2;
  }
  
  if ((rbi_SPI_activ_g == FALSE)
      && (rb_Asic_measureMode_mg == 196)
          && (FALSE == rbi_LowVoltage)
            && (CB_ASIC_LOOP2_MD == rb_CurMode_g)
#ifdef STARTUP_WIPE  
              && (TRUE==rbi_RainSensorEnable)
#endif
              && ((rw_NoRainPresentCnt_g >= rw_NoRainPresentCntThrsh_g) || (rb_Startup_STBY_meas_on_l==TRUE)))
  {
    /*VDR_842 SignalIntegral increments once after gain adjustment measurement*/
    if(rb_Start_STBY_Meas_g==FALSE)
    {
      /*set timeout of the coupling measurement*/
      rb_Timeout_STBY_Meas_l = 35;
    }
    rb_Start_STBY_Meas_g = TRUE;
    rw_NoRainPresentCnt_g = 0;
  }
  else
  {/* satisfy coding rules*/
  }
  
  /*is undervoltage or overvoltage?*/
  if((rb_Start_STBY_Meas_g == TRUE)
     && (FALSE == rbi_UnderVoltage_g)
       && (FALSE == rbi_OverVoltage_g))
  {
    /*set the next threshold for the counter based on previous measurements*/
    rw_NoRainPresentCntThrsh_g = (CW_NO_RAIN_PRESENT_THRSH_g/(rw_STBY_param_OutofRange_cnt_l+1));
    
    if((rb_Asic_measureMode_mg<=196) || (rb_Asic_measureMode_mg>=199))
    {
      rb_Asic_measureMode_mg = 196;
    }
    
    switch(rb_Asic_Meas_STBY_l)
    {
    case 0:
      /*save INTV and REGV to restore them at the end of measurement*/
      rw_INTV_old_l = (word)(((((word)ras_ASIC_CtrReg_g[IDX_INTVH_REG].val)<<4)) + (ras_ASIC_CtrReg_g[IDX_INTVL_REG].val>>4));
      rw_REGV_old_l = rw_REGV_Voltage_g;
      /*change ASIC's mode to LOPEN*/
      ASIC_Control_ChangeModeCmd(CB_ASIC_LOPEN_MD);
      break;
    case 1:
      if(rb_CurMode_g == CB_ASIC_LOPEN_MD)
      {
        /*wait time for integration*/
        if(rb_ASIC_INTCNT_ACTR_g>8)
        {
          rb_wait4integration_l = 4+(rb_ASIC_INTCNT_ACTR_g%8);
        }
        else
        {
          rb_wait4integration_l=4;
        }
        /*create disbalance on REGV*/
        rw_REGV_temp_l = rw_REGV_old_l + (word)(rb_STBY_REGV_Imbalance_g)*4;
        rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_REGVH_REG].addr<<1)|0x41);
        rab_SPI_ASICWriteBuffer_mg[1] = (byte)(rw_REGV_temp_l>>4);
        rab_SPI_ASICWriteBuffer_mg[2] = (byte)(rw_REGV_temp_l<<4);
        rab_SPI_ASICWriteBuffer_mg[3] = (byte)((ras_ASIC_CtrReg_g[IDX_INTVH_REG].addr<<1)|0x41);
        rab_SPI_ASICWriteBuffer_mg[4] = (rw_INTV_old_l>>4);
        rab_SPI_ASICWriteBuffer_mg[5] = (rw_INTV_old_l<<4);
        rab_SPI_ASICWriteBuffer_mg[6] = 0x14;
        rb_SPI_Data_to_send_g = 7;
        SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
        rb_SPI_Data_to_send_g = 0;
      }
      else
      {
        rb_Asic_Meas_STBY_l--;
      }
      break;
    case 2:
      if(rb_wait4integration_l>0)
      {
        rb_wait4integration_l--;
        rb_Asic_Meas_STBY_l--;
        
        if(rb_wait4integration_l==1)
        {
          /*read integration flag CNTRDY*/
          ASIC_Control_RS_Meas();
        }
      }
      break;
    case 3:
      /*is the CNTRDY flag not set?*/
      if (rb_LOpenIntegrationDone_g != TRUE)
      {
        /*was the timer not configured?*/
        if(rb_ASIC_INTCNT_ACTR_g==0)
        {
          rb_LOpenIntegrationDone_g=TRUE;
        }
        else
        {
          rb_Asic_Meas_STBY_l-=3;
        }
      }
      else
      {
        /*clear the integration flag CNTRDY*/
        rb_LOpenIntegrationDone_g = FALSE;
        if(rb_ASIC_INTCNT_ACTR_g>8)
        {
          rb_wait4integration_l = 4+(rb_ASIC_INTCNT_ACTR_g%8);
        }
        else
        {
          rb_wait4integration_l=4;
        }
        /*create disturbance on REGV in the other direction*/
        rw_INTV_STBY_1st_meas_g = (word)(((((word)ras_ASIC_CtrReg_g[IDX_INTVH_REG].val)<<4)) + (ras_ASIC_CtrReg_g[IDX_INTVL_REG].val>>4));
        rw_REGV_temp_l = rw_REGV_old_l - (word)(rb_STBY_REGV_Imbalance_g)*4;
        rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_REGVH_REG].addr<<1)|0x41);
        rab_SPI_ASICWriteBuffer_mg[1] = (byte)(rw_REGV_temp_l>>4);
        rab_SPI_ASICWriteBuffer_mg[2] = (byte)(rw_REGV_temp_l<<4);
        rab_SPI_ASICWriteBuffer_mg[3] = (byte)((ras_ASIC_CtrReg_g[IDX_INTVH_REG].addr<<1)|0x41);
        rab_SPI_ASICWriteBuffer_mg[4] = (rw_INTV_old_l>>4);
        rab_SPI_ASICWriteBuffer_mg[5] = (rw_INTV_old_l<<4);
        rab_SPI_ASICWriteBuffer_mg[6] = 0x14;
        rb_SPI_Data_to_send_g = 7;
        SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
        rb_SPI_Data_to_send_g = 0;
      }
      break;
    case 4:
      if(rb_wait4integration_l>0)
      {
        rb_wait4integration_l--;
        rb_Asic_Meas_STBY_l--;
        
        if(rb_wait4integration_l==1)
        {
          /*read integration flag CNTRDY*/
          ASIC_Control_RS_Meas();
        }
      }
      break;
    case 5:
      /*is the CNTRDY flag not set?*/
      if (rb_LOpenIntegrationDone_g != TRUE)
      {
        if(rb_ASIC_INTCNT_ACTR_g==0)
        {
          rb_LOpenIntegrationDone_g = TRUE;
        }
        else
        {
          rb_Asic_Meas_STBY_l-=3;
        }
      }
      else
      {
        /*restore the old values of INTV and REGV*/
        rb_LOpenIntegrationDone_g = FALSE;
        rw_INTV_STBY_2nd_meas_g = (word)(((((word)ras_ASIC_CtrReg_g[IDX_INTVH_REG].val)<<4)) + (ras_ASIC_CtrReg_g[IDX_INTVL_REG].val>>4));
        rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_REGVH_REG].addr<<1)|0x41);
        rab_SPI_ASICWriteBuffer_mg[1] = (byte)(rw_REGV_old_l>>4);
        rab_SPI_ASICWriteBuffer_mg[2] = (byte)(rw_REGV_old_l<<4);
        rab_SPI_ASICWriteBuffer_mg[3] = (byte)((ras_ASIC_CtrReg_g[IDX_INTVH_REG].addr<<1)|0x41);
        rab_SPI_ASICWriteBuffer_mg[4] = (rw_INTV_old_l>>4);
        rab_SPI_ASICWriteBuffer_mg[5] = (rw_INTV_old_l<<4);
        rb_SPI_Data_to_send_g = 6;
        SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
        rb_SPI_Data_to_send_g = 0;
      }
      break;
    case 6:
      /*change back the mode of the ASIC to LOOP2*/
      ASIC_Control_ChangeModeCmd(CB_ASIC_LOOP2_MD);
      
      if(rw_INTV_STBY_1st_meas_g > rw_INTV_STBY_2nd_meas_g)
      {
        rw_deltaINTV_l = rw_INTV_STBY_1st_meas_g - rw_INTV_STBY_2nd_meas_g;
      }
      else
      {
        rw_deltaINTV_l = rw_INTV_STBY_2nd_meas_g - rw_INTV_STBY_1st_meas_g;
      }
#ifdef STARTUP_WIPE  
      /* Startup-Wipe */
      rw_deltaINTV_Comp_l = rw_deltaINTV_l - 7 *(rw_VTEMP_ASIC_g  - 575);
#endif     
      if(rb_Startup_STBY_meas_on_l==FALSE)
      {
  
#ifdef STARTUP_WIPE          
        /* Startup_Wipe :  Reference calculation */
        if(rw_ref_deltaINTV_cnt_l == 4 )
        {
          rw_ref_deltaINTV_cnt_l = 0;
        }
        
        aw_ref_deltaINTV_buffer[rw_ref_deltaINTV_cnt_l] = rw_deltaINTV_Comp_l;
        rw_ref_deltaINTV_cnt_l ++;
#endif        
        
        /*is the result away from the refrence in EEPROM?*/
        if((rw_deltaINTV_l < ((2*rw_Stby_DeltaINTV_l)/3+100)) || ((rw_deltaINTV_l+200)  > ((4*rw_Stby_DeltaINTV_l)/3)))
        {
          
          if(((rb_ASICGainSetup_g == rab_RS_GainSetupArray(0)) && (rw_deltaINTV_l > rw_Stby_DeltaINTV_l)) || 
             ((rb_ASICGainSetup_g == rab_RS_GainSetupArray(10)) && (rw_deltaINTV_l < rw_Stby_DeltaINTV_l)))
          {
            rw_STBY_param_OutofRange_cnt_l=3;
          }
          /*were performed 4 measurements outside the limits?*/
          if((rw_STBY_param_OutofRange_cnt_l>=3) || ((rb_STBY_DELTA_INTV_HB_g == 0)&&(rb_STBY_DELTA_INTV_LB_g == 0)))
          {
            rw_STBY_param_OutofRange_cnt_l = 0;
            /*decrease gain*/
            if (rw_deltaINTV_l > rw_Stby_DeltaINTV_l)
            {
              /*calculate the offset*/
              rb_tempGainOffset_l = ((((rw_deltaINTV_l+200)*9)/(rw_Stby_DeltaINTV_l+1))+5)/9;
              
              /*the step for the gain can only be 2, if the result was greater than 2, otherwise, no change*/
              if(rb_tempGainOffset_l<=1)
              {
                rb_tempGainOffset_l = 0;
              }
              else
              {
                rb_tempGainOffset_l = 2;
              }
              
              /*is the current gain positive?*/
              if(rb_GainOffset_g<0x80)
              {
                if(rb_GainOffset_g>=rb_tempGainOffset_l)
                {
                  rb_GainOffset_g -= rb_tempGainOffset_l;
                }
                else
                {
                  rb_tempGainOffset_l -= rb_GainOffset_g;
                  rb_GainOffset_g = rb_tempGainOffset_l;
                  /*negative sign*/
                  rb_GainOffset_g |= 0x80;
                }
              }
              else
              {
                rb_GainOffset_g += rb_tempGainOffset_l;
                if((rb_GainOffset_g&0xF)>0xF)
                {
                  rb_GainOffset_g=0xF;
                }
                /*negative sign*/
                rb_GainOffset_g |= 0x80;
              }
            }
            /*increase gain*/
            else
            {
              /*calculate the offset*/
              rb_tempGainOffset_l = ((((rw_Stby_DeltaINTV_l+150)*8)/(rw_deltaINTV_l+1))+5)/9;
              
              /*the step for the gain can only be 2, if the result was greater than 2, otherwise, no change*/
              if(rb_tempGainOffset_l<=1)
              {
                rb_tempGainOffset_l = 0;
              }
              else
              {
                rb_tempGainOffset_l = 2;
              }
              
              /*is the current gain positive?*/
              if(rb_GainOffset_g<0x80)
              {
                rb_GainOffset_g += rb_tempGainOffset_l;
                if(rb_GainOffset_g>0xF)
                {
                  rb_GainOffset_g=0xF;
                }
              }
              else if ((rb_GainOffset_g&0x0F)>rb_tempGainOffset_l)
              {
                rb_GainOffset_g -= rb_tempGainOffset_l;
              }
              else
              {
                rb_tempGainOffset_l -= (rb_GainOffset_g&0x0f);
                rb_GainOffset_g = rb_tempGainOffset_l;
              }
            }
            
            if(rb_GainOffset_g==0x80)
            {
              rb_GainOffset_g=0;
            }
            
            /*is the gain offset greater than 10?*/
            if((rb_GainOffset_g&0x7F)>0x0A)
            {
              rb_GainOffset_g|=0x0A;
              rb_GainOffset_g &= 0x8A;
            }

          }
          else
          {
            rw_STBY_param_OutofRange_cnt_l ++;
          }
        }
        else
        {
          rw_STBY_param_OutofRange_cnt_l = 0;
        }
      }
      else
      {
        rb_Startup_STBY_meas_on_l = FALSE;
        /*VCO_253 Measurement of optical coupling at start up */
        rb_deltaINTV_g = (byte)(rw_deltaINTV_l>>4);
        if(((rw_deltaINTV_l > rw_Stby_DeltaINTV_l + 50) || (rw_deltaINTV_l + 50 < rw_Stby_DeltaINTV_l) ||
            (rw_REGV_old_l > (word)(((((word)rb_STBY_REGV_HB_g)<<8))+rb_STBY_REGV_LB_g) + 20) || 
              (rw_REGV_old_l + 20 < (word)(((((word)rb_STBY_REGV_HB_g)<<8))+rb_STBY_REGV_LB_g))))
        {

        }
#ifdef STARTUP_WIPE       
        /* Startup_Wipe */
        rw_Nom_deltaINTV_l = (word)(rb_NOM_DELTA_INTV_g<<5);
        rw_ref2_deltaINTV_g = rw_Nom_deltaINTV_l;
        rw_Tol_deltaINTV_l = (word)rb_THR_DELTA_INTV_g;   
        
        if(rw_Nom_deltaINTV_l != 0x1FE0)
        {
          if((rw_deltaINTV_Comp_l < (rw_Nom_deltaINTV_l - rw_Tol_deltaINTV_l)) || 
            ((rw_deltaINTV_Comp_l > (rw_Nom_deltaINTV_l + rw_Tol_deltaINTV_l)) && (rb_upperTolerance_StartupWipe_g == TRUE)))    
          {

            /* Temperature threshold. Default: 3deg/C (0x6A). Real Value = Reg Value * 0,5 - 50 */
            if((rd_Aussentemp_g >  rb_Threshold_TempIceRisk_g) && (rd_Aussentemp_g < 0xFE))
            {
              if((rb_Startup_Wipe_detected_g == 0) || (rb_Startup_Wipe_detected_g == 2))
              {
                rb_Startup_Wipe_g = TRUE;
                rb_Startup_Wipe_detected_g++;
              }
            }
          }
        }
#endif
      }
      
      break;
    default:
      break;
    }
    
    if(rb_Asic_Meas_STBY_l<=6)
    {
      rb_Asic_Meas_STBY_l++;
    }
    else
    {
      /*VDR_842 SignalIntegral increments once after gain adjustment measurement*/
      ras_ASIC_CtrReg_g[IDX_INTVH_REG].val = (byte)(rw_INTV_old_l>>4);
      ras_ASIC_CtrReg_g[IDX_INTVL_REG].val = (byte)(rw_INTV_old_l<<4);
      rb_Asic_measureMode_mg = 196;
      rb_Start_STBY_Meas_g = FALSE;
      rb_Asic_Meas_STBY_l = 0;
    }
  }
  else if(rb_Start_STBY_Meas_g == TRUE)
  {
    rb_Start_STBY_Meas_g = FALSE;
    rb_Asic_measureMode_mg = 196;
    rb_Asic_Meas_STBY_l = 0;
    rbi_Modulator_On_g = FALSE;
    ASIC_Control_ChangeModeCmd(CB_ASIC_LOOP2_MD);
  }
  else
  {
    rb_Asic_Meas_STBY_l = 0;
  }
  
  if (rb_Timeout_STBY_Meas_l>0)
  {
    rb_Timeout_STBY_Meas_l--;
  }
  else
  {
    rb_Start_STBY_Meas_g=FALSE;
  }
  
}
#endif /*_NO_RAIN_*/


/*!
* \fn   void ASIC_Control_ALSxINCShortDetect(void)
* \brief - Checks for short circuits of ALSx inputs using the calculation of light from the ALSx with V_INC
*        - Calculates a second set of light values used for the veto function
* \param  void
* \return void 
*/
static void ASIC_Control_ALSxINCShortDetect (void)
{
	/* ALS2 Amb shortcut detection */
	if (	 (rb_ASIC_ALSx_Shortcut_Ready_g & ASIC_ALS2_READY_FLG)
			&& (rb_ASIC_ALSx_Shortcut_INC_Ready_g & ASIC_ALS2_INC_READY_FLG)
		 )
	{
		/* calculate INC linear light value*/
		set_rw_Amb_INC_light16bit_g(ASIC_Control_ALS2_INC_LightValScl(0, (get_rw_ALS2_INC_ASIC_g())));
		/* calculate INC threshold */
		rw_Amb_INC_light16bit_thrs_g = ASIC_Control_ALS2_INC_LightValScl(0, (get_rw_ALS2_ASIC_g() + 50));
		/* Shortcut detection condition */
		if (	 (rw_ALS2_INC_ASIC_g > 250)
				&& (get_rw_Amb_light16bit_g() > cab_AMB_SECURE_DAY_THRESHOLD_s)
				&& ((rw_Amb_INC_light16bit_g + 10) < rw_Amb_INC_light16bit_thrs_g)
			 )
		{
			rb_ASIC_ALS2Amb_ShortDetected_cnt_g++;
			if (rb_ASIC_ALS2Amb_ShortDetected_Debounce_g > 0)
			{
				rb_ASIC_ALS2Amb_ShortDetected_Debounce_g = rb_SC_debounce_g;
			}
		}
		else
		{
			rb_ASIC_ALS2Amb_ShortDetected_cnt_g = 0;
			if (rb_ASIC_ALS2Amb_ShortDetected_Debounce_g > 0)
			{
				rb_ASIC_ALS2Amb_ShortDetected_Debounce_g--;
			}
		}
		/* Comparison with maximum from EEPROM */
		if (rb_ASIC_ALS2Amb_ShortDetected_cnt_g > rb_SC_max_g)
		{
			rb_ASIC_ALS2Amb_ShortDetected_cnt_g = rb_SC_max_g;
			rb_ASIC_ALS2Amb_ShortDetected_Debounce_g = rb_SC_debounce_g;
			rbi_LS_Error_ALS2_g = TRUE; 								/* This is just for eeprom information */
			rb_ASIC_ALSx_ShortDetected_Error_g = TRUE;	/* This propagate error */
		}
		/* Reset testing flags */
		rb_ASIC_ALSx_Shortcut_Ready_g &= ~ASIC_ALS2_READY_FLG;
		rb_ASIC_ALSx_Shortcut_INC_Ready_g &= ~ASIC_ALS2_INC_READY_FLG;
	}

	/* ALS5 FW shortcut detection */
	if (	 (rb_ASIC_ALSx_Shortcut_Ready_g & ASIC_ALS5_READY_FLG)
			&& (rb_ASIC_ALSx_Shortcut_INC_Ready_g & ASIC_ALS5_INC_READY_FLG)
		 )
	{
		/* calculate INC linear light value*/
		set_rw_FW_INC_light16bit_g(ASIC_Control_ALS5_INC_LightValScl(0, (get_rw_ALS5_INC_ASIC_g())));
		/* calculate INC threshold */
		rw_FW_INC_light16bit_thrs_g = ASIC_Control_ALS5_INC_LightValScl(0, ((get_rw_ALS5_ASIC_g()) + 50));
		/* Shortcut detection condition */
		if (	 (rw_ALS5_INC_ASIC_g > 250)
				&& (get_rw_FW_light16bit_g() > cab_FW_SECURE_DAY_THRESHOLD_s)
				&& ((rw_FW_INC_light16bit_g + 10) < rw_FW_INC_light16bit_thrs_g)
			 )
		{
			rb_ASIC_ALS5FW_ShortDetected_cnt_g++;
			if (rb_ASIC_ALS5FW_ShortDetected_Debounce_g > 0)
			{
				rb_ASIC_ALS5FW_ShortDetected_Debounce_g = rb_SC_debounce_g;
			}
		}
		else
		{
			rb_ASIC_ALS5FW_ShortDetected_cnt_g = 0;
			if (rb_ASIC_ALS5FW_ShortDetected_Debounce_g > 0)
			{
				rb_ASIC_ALS5FW_ShortDetected_Debounce_g--;
			}
		}
		/* Comparison with maximum from EEPROM */
		if (rb_ASIC_ALS5FW_ShortDetected_cnt_g > rb_SC_max_g)
		{
			rb_ASIC_ALS5FW_ShortDetected_cnt_g = rb_SC_max_g;
			rb_ASIC_ALS5FW_ShortDetected_Debounce_g = rb_SC_debounce_g;
			rbi_LS_Error_ALS5_g = TRUE; 								/* This is just for eeprom information */
			rb_ASIC_ALSx_ShortDetected_Error_g = TRUE;	/* This propagate error */
		}
		/* Reset testing flags */
		rb_ASIC_ALSx_Shortcut_Ready_g &= ~ASIC_ALS5_READY_FLG;
		rb_ASIC_ALSx_Shortcut_INC_Ready_g &= ~ASIC_ALS5_INC_READY_FLG;
	}

	/* INREC IR shortcut detection */
	if (	 (rb_ASIC_ALSx_Shortcut_Ready_g & ASIC_REC_READY_FLG)
			&& (rb_ASIC_ALSx_Shortcut_INC_Ready_g & ASIC_REC_INC_READY_FLG)
		 )
	{
		/* calculate INC linear light value*/
		set_rw_IR_INC_light16bit_g(ASIC_Control_INREC_INC_LightValScl(0, (get_rw_INREC_INC_ASIC_g())));
		/* calculate INC threshold */
		rw_IR_INC_light16bit_thrs_g = ASIC_Control_INREC_INC_LightValScl(0, ((get_rw_INREC_ASIC_g()) + 50));
		/* Shortcut detection condition */
		if (	 (rw_INREC_INC_ASIC_g > 250)
				&& (get_rw_IR_light16bit_g() > cab_IR_SECURE_DAY_THRESHOLD_s)
				&& ((rw_IR_INC_light16bit_g + 10) < rw_IR_INC_light16bit_thrs_g)
			 )
		{
			rb_ASIC_INRECIR_ShortDetected_cnt_g++;
			if (rb_ASIC_INRECIR_ShortDetected_Debounce_g > 0)
			{
				rb_ASIC_INRECIR_ShortDetected_Debounce_g = rb_SC_debounce_g;
			}
		}
		else
		{
			rb_ASIC_INRECIR_ShortDetected_cnt_g = 0;
			if (rb_ASIC_INRECIR_ShortDetected_Debounce_g > 0)
			{
				rb_ASIC_INRECIR_ShortDetected_Debounce_g--;
			}
		}
		/* Comparison with maximum from EEPROM */
		if (rb_ASIC_INRECIR_ShortDetected_cnt_g > rb_SC_max_g)
		{
			rb_ASIC_INRECIR_ShortDetected_cnt_g = rb_SC_max_g;
			rb_ASIC_INRECIR_ShortDetected_Debounce_g = rb_SC_debounce_g;
			rbi_LS_Error_REC_g = TRUE;								 /* This is just for eeprom information */
			rb_ASIC_ALSx_ShortDetected_Error_g = TRUE;	/* This propagate error */
		}

		/* Reset testing flags */
		rb_ASIC_ALSx_Shortcut_Ready_g &= ~ASIC_REC_READY_FLG;
		rb_ASIC_ALSx_Shortcut_INC_Ready_g &= ~ASIC_REC_INC_READY_FLG;
	}

	/* Error reset */
	if (	 (rb_ASIC_ALS2Amb_ShortDetected_Debounce_g == 0)
			&& (rb_ASIC_ALS5FW_ShortDetected_Debounce_g == 0)
			&& (rb_ASIC_INRECIR_ShortDetected_Debounce_g == 0)
		 )
	{
		rb_ASIC_ALSx_ShortDetected_Error_g = FALSE;
	}

	/* Set rb_ASIC_ALSx_ShortDetected_Max_cnt_g for debug purpose here */
	if (rb_ASIC_ALSx_ShortDetected_Max_cnt_g < rb_ASIC_ALS2Amb_ShortDetected_cnt_g)
	{
		rb_ASIC_ALSx_ShortDetected_Max_cnt_g = rb_ASIC_ALS2Amb_ShortDetected_cnt_g;
	}
	if (rb_ASIC_ALSx_ShortDetected_Max_cnt_g < rb_ASIC_ALS5FW_ShortDetected_cnt_g)
	{
		rb_ASIC_ALSx_ShortDetected_Max_cnt_g = rb_ASIC_ALS5FW_ShortDetected_cnt_g;
	}
	if (rb_ASIC_ALSx_ShortDetected_Max_cnt_g < rb_ASIC_INRECIR_ShortDetected_cnt_g)
	{
		rb_ASIC_ALSx_ShortDetected_Max_cnt_g = rb_ASIC_INRECIR_ShortDetected_cnt_g;
	}
}



/*!
* \fn   void ASIC_Control_LIN_GoToSleep(void)
* \brief - Sensor shall go to sleep mode
*        - 
* \param  void
* \return void 
*/
static void ASIC_Control_LIN_GoToSleep(void) /* RLS_VDR_1029 */
{
do
{
  __disable_interrupt(); /* No interrupt allowed during go to  sleep process */
  po_DVoltageRegulatorEnable_g = OUTPUT;
  
  if(po_VoltageRegulatorEnable_g   == FALSE)
  {
    po_VoltageRegulatorEnable_g   = TRUE;  /* switch Voltage Regulator off */ /* VDR_769*/
    ASIC_Control_Delay(100); /* The required delay is 44 microsec and configured is 100x0.5 = 50 microsec */
  }
  po_VoltageRegulatorEnable_g   = FALSE;  /* switch Voltage Regulator off */ /* VDR_769*/
  /* clear the reset indicator to detect as normal sleep in next wakeup and not due to internal reset */
  rab_InternalResetIndicator[0]=0x00;
  rab_InternalResetIndicator[1]=0x00;
  rab_InternalResetIndicator[2]=0x00;
  rab_InternalResetIndicator[3]=0x00;
  /* Maximum t2STBY time required by SBC to go to sleep is 44 microsec */
  /* The required delay is 44 microsec and configured is 100x0.5 = 50 microsec */
  ASIC_Control_Delay(100);
  po_D_RXD0_g = INPUT; 
  if(po_RXD0_g != FALSE)/* Indicates there is no wake up request */
  {
    po_D_TXD0_g = OUTPUT;
    po_TXD0_g = FALSE;
    do
    {
    }while(TRUE==TRUE);
    
  }
  
}while(TRUE==TRUE);

}

/*!
* \fn   void ASIC_Control_Delay(byte rb_Delay_l)
* \brief - To create delay
*        - 
* \param  rb_Delay_l
* \return void 
*/
#pragma optimize=none
static void ASIC_Control_Delay(byte rb_Delay_l) /* RLS_VDR_1029 */
{
  byte rb_LoopCnt_l;
  /* For loop with 1 NOP() shall take 8 clocks to execute */
  /* Instruction   clock*/
  /*  CMP---compare-------------1*/
  /*  BNC--conditional branch---2*/
  /*  NOP--No operation---------1*/
  /*  INC--increment------------1*/
  /*  BR--Unconditional branch- 3*/
  /* Total 8 clocks at 16Mhz takes 8 * 0.0625 = 0.5 microsec for rb_Delay_l = 1 */
  for(rb_LoopCnt_l = 0;rb_LoopCnt_l <rb_Delay_l; rb_LoopCnt_l++)
  {
    NOP(); /* NOP instruction takes 1 clock at 16 Mhz takes 0.0625 micro second  */
  }
}
