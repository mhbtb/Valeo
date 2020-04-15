#ifndef G5_ASIC_CONTROL_SR_H
#define G5_ASIC_CONTROL_SR_H
/*************************************************************************

Company : Valeo Schalter und Sensoren

Project : RLT Sensor Generation 5 (16 bit Micro Controller)

Component : ASIC_Control_sr.h

Documentation reference : ASIC_Specification
---------------------------------------------------------------------------
Overview of the component : This module contains data and function declarations for global usage.
It is intended that other components will use them. The suffix _sr means "safety relevance".
---------------------------------------------------------------------------

*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Name    Description                                  */
/*----------------------------------------------------------------------------*/
/*07.10.13   VCO_128 RFI     item creation                                */
/*07.11.13   VCO_128 MPI     defs, macros used globally                   */
/*09.02.15   VCO_220 MPI     VIrefLo/Hi monitoring*/
/*03.03.15   VCO_227 NB      Implement RAM Guard function */
/*16.03.15   VDR_855 MP      Fix of the findings from the review of ASIC_Control_sr*/
/*01.04.15   VDR_866 MP      Remove of rainsens.c for no-rain-variants*/

/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/

#ifdef _G5_ASIC_Control_sr_c_
#define EXTERN /**/
#else
#define EXTERN  extern
#endif
EXTERN byte Enter_Prestandby_Flag;

typedef struct {
  const byte addr;  /*!< Address of the ASIC register*/  
  byte val;         /*!< Value of the ASIC register*/
  const byte accs;  /*!< Access type: b00 - Read2/Write2 cmd possible; b01 - no Read2/Write2 cmds; b10 - only Read cmds*/
} ASIC_Reg_t;

typedef struct {
  word ad;
  word avg;
  word adinc;
  word avginc;
} ASIC_ALSxADval_t;

typedef struct {
  word ad;
  word avg;
} ASIC_ALI_Meas_t;

typedef struct {
  word MIN;
  word MAX;
} ASIC_ALI_CalibAD_Limits_t;


EXTERN unsigned char rub_Dia_Count_dyna_Stop;          /* VDR_132 erlaubt kein reset und zahlen des DiaCount bei < 150*/
EXTERN unsigned short int rub_Dia_Count;		        //Diagnose-Zaehler fuer "Signal-Uebertraege"

EXTERN byte rb_newAsicSTAT_g;
EXTERN byte rb_firstReadComm_g;

/*! Offset for the calc of RS gain*/
EXTERN byte rb_GainOffset_g;

/*coutners to measure the duration of the loop closed and number of rain measurements during loop closed*/

#ifdef STARTUP_WIPE 
EXTERN word rw_Nom_deltaINTV_l;
EXTERN word rw_ref2_deltaINTV_g;
EXTERN word rw_ref_deltaINTV_l;
EXTERN word rw_deltaINTV_Comp_l;
EXTERN byte rw_ref_deltaINTV_cnt_l;
extern byte rb_Startup_Wipe_g;
extern byte rb_Startup_Wipe_detected_g;
extern word aw_ref_deltaINTV_buffer[4];
EXTERN byte rd_Aussentemp_g;
#endif


EXTERN byte rb_ASICResetCnt_g;
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
#define CB_NUMBER_OF_REG_ASIC10112_g    ((byte)28)
#define CB_SIZEOF_ASIC_CTRREG_G         CB_NUMBER_OF_REG_ASIC10112_g
EXTERN byte rb_RainMeas_cnt_total_g;
EXTERN byte rb_RainMeas_cnt_min_g;
EXTERN byte rb_RainMeas_cnt_max_g;
EXTERN byte rb_LClosed_dur_total_g;
EXTERN byte rb_LClosed_dur_min_g;
EXTERN byte rb_LClosed_dur_max_g;

EXTERN ASIC_Reg_t ras_ASIC_CtrReg_g[CB_NUMBER_OF_REG_ASIC10112_g];

#else
#define CB_NUMBER_OF_REG_ASIC10113_g    ((byte)9)
#define CB_SIZEOF_ASIC_CTRREG_G         CB_NUMBER_OF_REG_ASIC10113_g
EXTERN ASIC_Reg_t ras_ASIC_CtrReg_g[CB_NUMBER_OF_REG_ASIC10113_g];
#endif /*_NO_RAIN_*/


EXTERN byte rb_ASIC_ALSx_ShortDetected_Max_cnt_g;
EXTERN byte rb_ASIC_ALSx_ShortDetected_Error_g;

/*20200402_Zhiyuan_HU*/
EXTERN byte rb_ASIC_ALS2Amb_ShortDetected_cnt_g;
EXTERN byte rb_ASIC_ALS5FW_ShortDetected_cnt_g;
EXTERN byte rb_ASIC_INRECIR_ShortDetected_cnt_g;
EXTERN byte rb_ASIC_ALS2Amb_ShortDetected_Debounce_g;
EXTERN byte rb_ASIC_ALS5FW_ShortDetected_Debounce_g;
EXTERN byte rb_ASIC_INRECIR_ShortDetected_Debounce_g;


EXTERN Flag uF_ASIC_ControlFlags_g;
EXTERN Flag uF_GainAdjustFlags_g;
/*! Flags for detected errors in ASIC Logamp*/
EXTERN  Flag uF_ASIC_Error_Flags_g;
/*VCO_220 VIrefLo/Hi monitoring*/
EXTERN  Flag uF_ASIC_Error_Flags1_g;
EXTERN  Flag uF_ASIC_Ctrl_Error_Flags_g;


/*! CDIV256 period measured*/
EXTERN word rw_CDIV256_period_g;
/*CDIV256 period measured; OVF flag*/
EXTERN byte rb_CDIV256_OVF_g;
EXTERN byte rb_ASIC_ID_g[3];

/*! 16bit Value for Solar-Light on driver side*/
EXTERN  word rw_Solar_light16bit_1_g;
/*! 16bit Value for Solar-Light on passenger side*/
EXTERN  word rw_Solar_light16bit_2_g;

EXTERN  byte rb_FwLight_g;       // brightness from the front with wide spot
EXTERN  byte rb_FwLightDiv4_g;  // brightness from the front with wide spot up to 40klx
EXTERN byte rb_IrLightDiv8_g;

#define CB_SIZE_OF_MUX_MEASAD_g         9
/*! ASIC instant and average AD results for voltage measurements like: temp, DAC output, V Iref Lo/Hi, VDDD, VDDA, rain sensor amplifier output*/
EXTERN ASIC_ALI_Meas_t ras_ASIC_MUX_MeasAD_g[CB_SIZE_OF_MUX_MEASAD_g];

EXTERN SHORT_MEMORY Flag uF_ASIC_Calc_Flags_g;

#define cb_TEMP_ASIC_AD65DEGREES_THRS_g      527     /*AD value for 65 degrees measured by the ASIC*/
#define cb_TEMP_uC_AD65DEGREES_THRS_g        70      /*AD value for 65 degrees measured by the uC*/
#define cb_LCLOSED_45perCent_THRS_g          10      /*45% for the duty cycle to keep the loop closed*/
/*! Time to measure for rain if rain is detected in standby mode*/
#define TIME_FOR_STANDBY_NORMAL_MEASURE 1000


/*! Sign of value for delogarithm*/
#define rbi_negativeSign_mg         uF_ASIC_Calc_Flags_g.Bit.B0
/*! Flag to monitore that the light value is minimum one time measured*/
#define rbi_LightValuesMeasured_mg  uF_ASIC_Calc_Flags_g.Bit.B1
/*! Flag that the freq. measurement is done one time*/
#define rbi_FreqMeasureDone         uF_ASIC_Calc_Flags_g.Bit.B4

/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
/*! AD value for INTV register*/
#define rb_RS_SigVoltage_g      ras_ASIC_CtrReg_g[IDX_INTVH_REG].val
#define rw_INTV10bit_g          (word)((ras_ASIC_CtrReg_g[IDX_INTVH_REG].val<<2) + (ras_ASIC_CtrReg_g[IDX_INTVL_REG].val>>6))
#define rb_REGV_OSAT_g          (byte)((ras_ASIC_CtrReg_g[IDX_INTVL_REG].val>>1)&0x01)
#define rb_ASIC_INTCNT_ACTR_g   (byte)(ras_ASIC_CtrReg_g[IDX_ACTR_REG].val&0x0F)

#else

#define rb_RS_SigVoltage_g                        0
#endif /*_NO_RAIN_*/

/*! Flag to control the ASIC modulator*/
#define rbi_Modulator_On_g                                      uF_ASIC_ControlFlags_g.Bit.B0
/*! Flag to monitor it the light values are initialised*/
#define rbi_LightValuesInitialised_g                            uF_ASIC_ControlFlags_g.Bit.B1
/*! Flag to monitor it the solar values are initialised*/
#define rbi_SolarValuesInitialised_g                            uF_ASIC_ControlFlags_g.Bit.B2
/*! Flag to show if in Standby mode the LIN was active*/
#define rbi_LIN_CommunicationEvent_g                            uF_ASIC_ControlFlags_g.Bit.B3
/*! Flag to bring the Sensor into standby mode*/
#define rbi_ASICStandByModeRequest_g                            uF_ASIC_ControlFlags_g.Bit.B4
/*! Bit to make workaround after INREC measurment use 8bit command to restart modulator*/
#define rbi_Req_InrecWorkaround_g                               uF_ASIC_ControlFlags_g.Bit.B5
/*! Bit to request a LOW CSB from the SPI*/
#define rbi_SPI_LOW_CSB_g                                       uF_ASIC_ControlFlags_g.Bit.B6


/*! Bit for rain present*/
#define rbi_RainIsPresent_g                                     uF_GainAdjustFlags_g.Bit.B0
/*! Bit for reaching once the vehicle speed 10km/h*/
#define rbi_speedWasAbove10kmh_g                                uF_GainAdjustFlags_g.Bit.B1

/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_



#else
#define rw_INTV10bit_g          0

#endif /*_NO_RAIN_*/

#define rb_STATH_flags_g        (byte)(ras_ASIC_CtrReg_g[IDX_STATH_REG].val&0x1F)

#if defined (ZOTYE_B01_NEW)
#define cab_IR_SECURE_DAY_THRESHOLD_s                       (byte) 10  /*VCO_093 fix Parameter for VETO Function */
#define cab_FW_SECURE_DAY_THRESHOLD_s                       (byte) 30  /*VCO_093 fix Parameter for VETO Function */
#define cab_AMB_SECURE_DAY_THRESHOLD_s                      (byte) 30  /*VCO_093 fix Parameter for VETO Function */
#else
#define cab_IR_SECURE_DAY_THRESHOLD_s                       (byte) 15  /*VCO_093 fix Parameter for VETO Function */
#define cab_FW_SECURE_DAY_THRESHOLD_s                       (byte) 50  /*VCO_093 fix Parameter for VETO Function */
#define cab_AMB_SECURE_DAY_THRESHOLD_s                      (byte) 50  /*VCO_093 fix Parameter for VETO Function */
#endif



/*if the rain functionality is disabled*/
#ifdef _NO_RAIN_
#define rw_REGV_Voltage_g                      0
#else
/*!  AD value for REGV HB register*/
#define rw_REGV_Voltage_g                      ((word)(ras_ASIC_CtrReg_g[IDX_REGVH_REG].val<<4) + (ras_ASIC_CtrReg_g[IDX_REGVL_REG].val>>4))
#endif

/*!  Error with VinALS1 out of specification*/
/*#define rbi_LS_Error_VinALS1_g              uF_ASIC_Error_Flags_g.Bit.B0*/
/*!  Error with VinALS2 out of specification*/
#define rbi_LS_Error_ALS2_g              uF_ASIC_Error_Flags_g.Bit.B0
/*!  Error with VinALS5 out of specification*/
#define rbi_LS_Error_ALS5_g              uF_ASIC_Error_Flags_g.Bit.B1
/*!  Error with VinALS6 out of specification*/
/*#define rbi_LS_Error_VinALS6_g              uF_ASIC_Error_Flags_g.Bit.B2*/
/*!  Error with Vinrec out of specification*/
#define rbi_LS_Error_REC_g               uF_ASIC_Error_Flags_g.Bit.B2
/*!  Error with Vref out of specification*/
#define rbi_LS_Error_Vref_g                 uF_ASIC_Error_Flags_g.Bit.B3
/*!  Error with ras_ASIC_ALI_CalibAD_g[] out of specification*/
#define rbi_LS_Error_VCalib_meas_g          uF_ASIC_Error_Flags_g.Bit.B4
/*!  Error when LEDx voltages are different then expected in LStop*/
#define rbi_LEDx_LStop_error_g              uF_ASIC_Error_Flags_g.Bit.B5
/*!  Error when LEDx voltages are different then expected in LClosed*/
#define rbi_LEDx_LClosed_error_g            uF_ASIC_Error_Flags_g.Bit.B6
/*!  Timeout Error for the init of the ASIC*/
#define rbi_ASIC_initTimeout_err_g          uF_ASIC_Error_Flags_g.Bit.B7
/* ASIC frequency out of range - not trimmed*/
#define rbi_ASIC_SPI_Error_g                     uF_ASIC_Ctrl_Error_Flags_g.Bit.B0
#define rbi_ASIC_NoValidAD_Error_g               uF_ASIC_Ctrl_Error_Flags_g.Bit.B1
#define rbi_REGV_OSAT_Error_g                    uF_ASIC_Ctrl_Error_Flags_g.Bit.B2
#define rbi_VDD_LightSignalError_g               uF_ASIC_Ctrl_Error_Flags_g.Bit.B3
#define rbi_ASICReg_NoValidVals_Error_g          uF_ASIC_Ctrl_Error_Flags_g.Bit.B4
#define rbi_ASIC_FreqTrimming_error_g           uF_ASIC_Ctrl_Error_Flags_g.Bit.B5
/*variables to store how is the ASIC frequency measured from the nominal, when not trimmed*/
#define rb_ASIC_FREQ_invalid_LOW_g              uF_ASIC_Ctrl_Error_Flags_g.Bit.B6
#define rb_ASIC_FREQ_invalid_HIGH_g             uF_ASIC_Ctrl_Error_Flags_g.Bit.B7

/*VCO_220 VIrefLo/Hi monitoring*/
#define rbi_VIref_Error_g                       uF_ASIC_Error_Flags1_g.Bit.B0


#define CB_FREQ_NOTTRIMMED_CNT_THRSHD   100
#define CW_REGV_OSAT_CNT_THRSHD         (word)(1400)
#define CB_ASIC_NOVALID_ADVALUES_THRSHD        9

#define LEDx_CNT_ERR_THRS (byte)20


/*indexes for the diag AD voltages*/
#define IDX_RSI_AD         0
#define IDX_VDIAG_LEDA_AD  1
#define IDX_VDIAG_LEDB_AD  2
#define IDX_VTEMP_AD       3
#define IDX_VREF_AD        4
#define IDX_VIREF_LO_AD    5
#define IDX_VIREF_HI_AD    6
#define IDX_VDDA_AD        7
#define IDX_VDDD_AD        8

#define IDX_CAL_ILO_IHI_GLO_AD                         0
#define IDX_CAL_IHI_ILO_GLO_AD                         1
#define IDX_CAL_ILO_ICALLO_GHI_AD                      2
#define IDX_CAL_IHI_ICALHI_GHI_AD                      3
#define IDX_CAL_ICALLO_ILO_GHI_AD                      4
#define IDX_CAL_ICALHI_IHI_GHI_AD                      5
#define IDX_CAL_ILO_IHI_GLO_INC_AD                     6
#define IDX_CAL_IHI_ILO_GLO_INC_AD                     7
#define IDX_CAL_IHI_ICALHI_GHI_INC_AD                  8
#define IDX_CAL_ICALHI_IHI_GHI_INC_AD                  9
/*VDR_839 SM250: Error counter not incrementing properly for calibration values*/
/*#define IDX_CAL_ILO_ICALLO_GHI_INC_AD                  10*/

//#define ASIC_CHD_MODE_CMD(a)  (0xC0|(a<<1))
/* possible mode selection for ASIC*/
#define CB_ASIC_INIT_MD   0
#define CB_ASIC_LOOP1_MD  1
#define CB_ASIC_LOOP2_MD  2
#define CB_ASIC_LRAMP_MD  3
#define CB_ASIC_LSTOP_MD  4
#define CB_ASIC_LOPEN_MD  5
#define CB_ASIC_WAKEUP_MD 6
#define CB_ASIC_SLEEP_MD  7

#define CB_ASIC_LRETURN   0xC6

/*indexes for the ALSx AD voltages*/
#define IDX_ALS1_AD        0
#define IDX_ALS2_AD        1
/*#define IDX_ALS3_AD        2*/
/*#define IDX_ALS4_AD        3*/
#define IDX_ALS5_AD        4
#define IDX_ALS6_AD        5
#define IDX_INREC_AD       6
#define IDX_INVALID_AD       255

#ifdef _NO_RAIN_
/*indexes for the ASIC registers*/
#define IDX_MCTR_REG        0x0    /*address 0x02*/
#define IDX_ACTR_REG        0x1    /*address 0x03*/
#define IDX_STATH_REG       0x2   /*address 0x10*/
#define IDX_STATL_REG       0x3   /*address 0x11*/
#define IDX_TRIM_REG        0x4   /*address 0x12*/
#define IDX_ADCVH_REG       0x5    /*address 0x18*/
#define IDX_ADCVL_REG       0x6    /*address 0x19*/
#define IDX_AVGVH_REG       0x7    /*address 0x1A*/
#define IDX_AVGVL_REG       0x8    /*address 0x1B*/
#else

/*indexes for the ASIC registers*/
#define IDX_GCTR_REG        0x0    /*address 0x00*/
#define IDX_HCTR_REG        0x1    /*address 0x01*/
#define IDX_MCTR_REG        0x2    /*address 0x02*/
#define IDX_ACTR_REG        0x3    /*address 0x03*/
#define IDX_LCTR_REG        0x4    /*address 0x04*/

#define IDX_RCTR_REG        0x5    /*address 0x05*/

#define IDX_PCO_REG         0x6    /*address 0x06*/
#define IDX_ICO1H_REG       0x7    /*address 0x07*/
#define IDX_ICO1L_REG       0x8    /*address 0x08*/
#define IDX_ICO2H_REG       0x9    /*address 0x09*/
#define IDX_ICO2L_REG       0xA    /*address 0x0A*/
#define IDX_RREGH_REG       0xB    /*address 0x0B*/
#define IDX_RREGL_REG       0xC    /*address 0x0C*/
#define IDX_REGVH_REG       0xD    /*address 0x0D*/
#define IDX_REGVL_REG       0xE    /*address 0x0E*/
#define IDX_DIAGV_REG       0xF    /*address 0x0F*/
#define IDX_STATH_REG       0x10   /*address 0x10*/
#define IDX_STATL_REG       0x11   /*address 0x11*/
#define IDX_TRIM_REG        0x12   /*address 0x12*/

#define IDX_RFCTR_REG       0x13   /*address 0x13*/

#define IDX_INTVH_REG       0x14    /*address 0x14*/
#define IDX_INTVL_REG       0x15    /*address 0x15*/
#define IDX_INTCO_REG       0x16    /*address 0x16*/

#define IDX_AFSTHR_REG      0x17   /*address 0x17*/

#define IDX_ADCVH_REG       0x18    /*address 0x18*/
#define IDX_ADCVL_REG       0x19    /*address 0x19*/
#define IDX_AVGVH_REG       0x1A    /*address 0x1A*/
#define IDX_AVGVL_REG       0x1B    /*address 0x1B*/

#endif


/*!  Macro to read AD Result*/
#define rw_VRSI_ASIC_g                  ras_ASIC_MUX_MeasAD_g[IDX_RSI_AD].avg
/*!  Macro to read AD Result*/
#define rw_VLEDA_ASIC_g                 ras_ASIC_MUX_MeasAD_g[IDX_VDIAG_LEDA_AD].avg
/*!  Macro to read AD Result*/
#define rw_VLEDB_ASIC_g                 ras_ASIC_MUX_MeasAD_g[IDX_VDIAG_LEDB_AD].avg
/*!  Macro to read AD Result*/
#define rw_VTEMP_ASIC_g                 ras_ASIC_MUX_MeasAD_g[IDX_VTEMP_AD].avg /*VDR_372*/
/*!  Macro to read AD Result*/
#define rw_Vref_ASIC_g                  ras_ASIC_MUX_MeasAD_g[IDX_VREF_AD].avg
/*!  Macro to read AD Result*/
#define rw_VIrefLo_ASIC_g               ras_ASIC_MUX_MeasAD_g[IDX_VIREF_LO_AD].avg
/*!  Macro to read AD Result*/
#define rw_VIrefHi_ASIC_g               ras_ASIC_MUX_MeasAD_g[IDX_VIREF_HI_AD].avg
/*!  Macro to read AD Result*/
#define rw_VDDA_ASIC_g                  ras_ASIC_MUX_MeasAD_g[IDX_VDDA_AD].avg
/*!  Macro to read AD Result*/
#define rw_VDDD_ASIC_g                  ras_ASIC_MUX_MeasAD_g[IDX_VDDD_AD].avg




/*!  State for ASIC Control Mode*/
#define CASE_ASIC_CNT_TEST_EN_RESET 10 /*VDR_365 new state*/
/*!  State for ASIC Control Mode*/
#define CASE_ASIC_CNT_MD_NORMAL 12
/*!  State for ASIC Control Mode*/
#define CASE_ASIC_CNT_MD_PRE_STANDBY 50
/*! State for ASIC Control Mode*/
#define CASE_ASIC_CNT_MD_STANDBY 51
/*!  State for ASIC Control Mode*/
#define CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD 60

#define ASIC_ALS1_READY_FLG (byte)(1<<0)
#define ASIC_ALS2_READY_FLG (byte)(1<<1)
/*#define ASIC_ALS3_READY_FLG (byte)(1<<2)
#define ASIC_ALS4_READY_FLG (byte)(1<<3)*/
#define ASIC_ALS5_READY_FLG (byte)(1<<4)
#define ASIC_ALS6_READY_FLG (byte)(1<<5)
#define ASIC_REC_READY_FLG  (byte)(1<<6)

#define ASIC_ALS2_INC_READY_FLG (byte)(1<<1)
/*#define ASIC_ALS4_INC_READY_FLG (byte)(1<<3)*/
#define ASIC_ALS5_INC_READY_FLG (byte)(1<<4)
#define ASIC_REC_INC_READY_FLG  (byte)(1<<6)


/*!  AD value for TRIM register*/
#define rb_ASIC_TRIM_Reg_g                      ras_ASIC_CtrReg_g[IDX_TRIM_REG].val

#define NO_CURRENT_MEAS        0xFF
#define CB_CHG_MUX_STMEAS_RQ  (byte)0x0C
#define CB_STMEAS_RQ          (byte)0x3
#define CB_NO_NEXT_RQ         (byte)0x0

/*! Start measurement of the ASIC Osc Frequency*/
#define ASIC_MEAS_FREQ         0x64

/*! Number of step response pulses per diag request */
#define CB_STEPRESPPERREQUEST_G     2

/*! Wait flag to enable coupling measurement*/
//#define rbi_Coupling_measurement_enabled_g uF_ASIC_ControlFlags_2_g.Bit.B0
/*! Wait flag to enable coupling measurement*/
#define rbi_Coupling_measurement_active_g uF_ASIC_ControlFlags_2_g.Bit.B1
/*! Wait flag to enable linearisation of measured signal*/
#define rbi_Coupling_measurement_to_linearise_g uF_ASIC_ControlFlags_2_g.Bit.B2

/*! Wait Error with loop comes not to normal point*/
#define rbi_RS_Error_Loop_g            uF_ASIC_ControlFlags_2_g.Bit.B3  /*VCO_090 */

#define UCONTROLLER_STANDBY_SLEEP_TIME (rb_p_t_rs_abfragezyklus_g+1)

// Defines for Standby Mode:
/*! Timeout if waiting for SPI*/
#define CW_WAIT_FOR_SPI_TIMOUT 200
/*! Wait for standby time */
#define CW_WAIT_FOR_STANDBY 1000 //400
/*! Wait macro to wait in Standby till the SPI is ready*/
  /* PRQA S 3412 3 *//*<< required for readability  >>*/
#define STANDBY_WAIT_FOR_FREE_SPI() rw_TimeOutCounter_s = CW_WAIT_FOR_SPI_TIMOUT;                                       \
  while ((rbi_SPI_activ_g == TRUE)&&(rw_TimeOutCounter_s > 0) || (rw_TimeOutCounter_s > (CW_WAIT_FOR_SPI_TIMOUT-80)))   \
    {rw_TimeOutCounter_s --; NOP(); NOP(); NOP(); NOP(); if (rw_TimeOutCounter_s == 1) {rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD; }}

/*! State for ASIC Control Mode*/
#define CASE_ASIC_CNT_MD_RESET 0
/*! upper boarder to allow standby measurment*/
#define CB_INREC_ABS_UPPER1_LEVEL (200)
/*! lower boarder to allow standby measurment*/
#define CB_INREC_ABS_LOWER1_LEVEL (50)
/*! upper boarder to allow standby measurment*/
#define CB_INREC_ABS_UPPER_LEVEL (255 - (1.5*CB_STANDBY_THRESHOLD))
/*! Lower boarder to allow standby measurment*/
#define CB_INREC_ABS_LOWER_LEVEL (1.5*CB_STANDBY_THRESHOLD)
/*! Threshold for standby detection*/
#define CB_STANDBY_THRESHOLD 20 /*VCO_028 */
/*! Set the DIAG bit of STATL register*/
#define CB_ASIC_SET_DIAG          0x0A
/*! Clear the DIAG bit of STATL register*/
#define CB_ASIC_CLEAR_DIAG          0x08
/*! Threshold for the error-code (0x55) counter (error code added to cksum, when an error occured on ASIC)*/
#define cb_ASIC_SPI_ERRORCODE_CNT_THRSHD_g 100
/*! Error threshold for incorrect VDDx values*/
#define CB_VDDX_ERRORCNT_THRESHOLD_MG 40

/*! Error Threshold for incorrect light values*/
#define CB_LIGHT_ERROR_THRESHOLD_MG 40
/*! Threshold for detection of short circuit on ALSx or REC inputs ~1.5sec*/
//#define cb_ASIC_ALSx_SHORTDET_THS_g 60
/*! Threshold for Timeout for the init of the ASIC*/
#define cb_ASIC_INITTIMEOUT_THRSH_g 200

#define cb_VIREF_ERRCNT_MAX_g   50
  
  
/*! Timeout for the init of the ASIC*/
EXTERN byte rb_ASIC_initTimeout_g;

/*! VCO_220 VIrefLo/Hi monitoring*/
/*! Definition for V_Iref_Lo/Hi limits*/
EXTERN byte rb_VIref_ErrCnt_g;

/*! IR_LightMod on  value*/ /*VDR_365***********************/
EXTERN  word rw_IR_light16bit_Mod_On_g;

/*! New INTV measurement was read out through SPI*/
EXTERN byte rb_newRSconvRcv_g;
EXTERN byte rb_LOpenIntegrationDone_g;

/*! Counter to delay the fastloop switch off*/
EXTERN word rw_Loop1DelayCount_mg; /*VDR_365 correct name of variable*/
/*! Measurements of WS coupling*/
EXTERN  word rw_INTV_STBY_1st_meas_g;
EXTERN  word rw_INTV_STBY_2nd_meas_g;
EXTERN  word  rw_TimeOutCounter_s;
/*! Store a value for every step response answer */
EXTERN  word rw_StepResponseRes_g[CB_STEPRESPPERREQUEST_G];    /* VDR_590 */
/*! Old value of length counter*/
EXTERN  word rb_LastLengthCounter_s;
/*! Rain signal sum used for standby*/
EXTERN  word rw_LengthSum_s;

/*! value for optical coupling measurement*/
EXTERN byte rb_deltaINTV_g;
EXTERN byte rb_IR_DeltaModON_g;
/*! Old value of ASIC loop in used in Standby function*/
EXTERN byte rb_STB_LoopIn_ASIC_old_g;
EXTERN byte rab_IntegrationTimePointer_mg;  /*VCO_028 reduce sample time if not stable*/
/*! TimoutCounter for standby mode*/
EXTERN byte rb_StandbyTimeOutSecCnt_g;
/*! Difference to old loop voltage*/
EXTERN byte rb_STB_LoopIn_ASIC_difference_g;
/*! Error when the checksum for read commands contains additional 0x55 (depending on errors in ASIC STAT registers)*/
EXTERN byte rb_ASIC_SPI_ErrorFlag_g;
EXTERN byte rb_ASIC_SPI_ErrorCodeCnt_g;

/*! Error counter for V_LEDx in Loop Closed*/
EXTERN byte rb_LEDx_LClosed_error_cnt_g;

/*! Current & Previous Mode of the ASIC*/
EXTERN byte rb_CurMode_g;
EXTERN byte rb_PrevMode_g;
EXTERN byte rb_STATH_Reg_g;
EXTERN byte rb_STATL_Reg_g;
EXTERN byte rb_LIN_STATH_Reg_g;
EXTERN byte rb_NextSPI_Request_g;
EXTERN byte rb_NextMUXCfg_g;
EXTERN byte rb_CrtMUXCfg_g;
EXTERN byte rb_newADconvRcv_g;
/*! Number of bytes to send with SPI to ASIC*/
EXTERN  byte rb_SPI_Data_to_send_g;
/*! Write Buffer for SPI-Signals*/
EXTERN byte rab_SPI_ASICWriteBuffer_mg[16];
/*! Control/Status byte for the funtion ASIC_Control_init()*/
EXTERN  byte rb_ASIC_ControlMode_g;
EXTERN byte rb_StaticNoValidAD_cnt_g;
EXTERN byte rb_FreqNotTrimmedCounter_g;
EXTERN byte rb_ASICReg_NoValidVals_cnt_g;
EXTERN byte rb_ASIC_ALSx_Ready_g;
EXTERN byte rb_ASIC_ALSx_Shortcut_Asked_g;
EXTERN byte rb_ASIC_ALSx_Shortcut_Ready_g;
EXTERN byte rb_ASIC_ALSx_Shortcut_INC_Ready_g;
EXTERN word rw_REGV_OSAT_cnt_g;

/*! Loop Voltage of sensor for */
EXTERN  byte rb_LoopVoltage_ASIC_g;
/*! ASIC loop in used in Standby function*/
EXTERN byte rb_STB_LoopIn_ASIC_g;

/*************************************************************************
Declaration of exported functions
**************************************************************************/

EXTERN __callt void ASIC_Control_dot5msTask(void); // 0.5ms routine to measure light values

EXTERN void ASIC_Control_init_Caller(void);  /*VDR_436*/
EXTERN word get_rw_Amb_light16bit_g(void);
EXTERN word get_rw_FW_light16bit_g(void);
#ifdef HUD_FUNCTION
/*VCO_477 Blake_Used_For HUD*/
EXTERN unsigned long get_rl_HUD_light32bit_g(void);
#endif

EXTERN word get_rw_IR_light16bit_g(void);
EXTERN word get_rw_Amb_INC_light16bit_g(void);
EXTERN word get_rw_Amb_INC_light16bit_thrs_g(void);
EXTERN word get_rw_FW_INC_light16bit_g(void);
EXTERN word get_rw_FW_INC_light16bit_thrs_g(void);
EXTERN word get_rw_IR_INC_light16bit_g(void);
EXTERN word get_rw_IR_INC_light16bit_thrs_g(void);

EXTERN word get_rw_ALS1_ASIC_g(void);
EXTERN word get_rw_ALS2_ASIC_g(void);
EXTERN word get_rw_ALS2_INC_ASIC_g(void);
/*ALS3, ALS4 are not connected*/
/*
EXTERN word get_rw_ALS3_ASIC_g(void);
EXTERN word get_rw_ALS4_ASIC_g(void);
EXTERN word get_rw_ALS4_INC_ASIC_g(void);
*/
EXTERN word get_rw_ALS5_ASIC_g(void);
EXTERN word get_rw_ALS5_INC_ASIC_g(void);
EXTERN word get_rw_ALS6_ASIC_g(void);
EXTERN word get_rw_INREC_ASIC_g(void);
EXTERN word get_rw_INREC_INC_ASIC_g(void);
EXTERN byte get_rb_LightSignalErrorCnt_g(void);
EXTERN byte get_rb_MaxLightSignalErrorCnt_g(void);
EXTERN byte get_rb_ASICReg_NoValidVals_cnt_g(void);
EXTERN byte get_rb_Vref_LightSignalErrorCnt_g(void);
EXTERN byte get_rb_VDD_LightSignalErrorCnt_g(void);
EXTERN void set_rb_VDD_LightSignalErrorCnt_g(byte a);
EXTERN void ASIC_Control_ASIC_ErrFlags_Check(void);
EXTERN void set_rb_Asic_measureMode_mg(byte a);
EXTERN byte get_rb_Asic_measureMode_mg(void);
EXTERN void set_rb_Vref_LightSignalErrorCnt_g(byte Vref_LightSignalErrorCnt);
EXTERN void set_rb_LightSignalErrorCnt_g(byte temp_LightSignalErrorCnt);
EXTERN byte get_rb_LEDx_LStop_error_cnt_g(void);
EXTERN void set_rb_LEDx_LStop_error_cnt_g(byte a);
EXTERN void ASIC_Control_ChangeModeCmd(const byte next_mode);
EXTERN void ASIC_Control_AsicStatus(void);


EXTERN word get_rw_VILO_IHI_GLO_ASIC_g(void);
EXTERN word get_rw_VIHI_ILO_GLO_ASIC_g(void);
EXTERN word get_rw_VILO_ICALLO_GHI_ASIC_g(void);
EXTERN word get_rw_VIHI_ICALHI_GHI_ASIC_g(void);
EXTERN word get_rw_VICALLO_ILO_GHI_ASIC_g(void);
EXTERN word get_rw_VICALHI_IHI_GHI_ASIC_g(void);
EXTERN word get_rw_VILO_IHI_GLO_INC_ASIC_g(void);
EXTERN word get_rw_VIHI_ILO_GLO_INC_ASIC_g(void);
EXTERN word get_rw_VIHI_ICALHI_GHI_INC_ASIC_g(void);
EXTERN word get_rw_VICALHI_IHI_GHI_INC_ASIC_g(void);
EXTERN void set_ASIC_ALSxADval_Init(void);


#ifndef _NO_RAIN_
/* PRQA S 3458 2 *//*<< required for readability  >>*/
#define ASIC_Control_PAUSE_RS_Function()      {rbi_Modulator_On_g = FALSE; rb_ALInitTimer_g = 0;}
#endif /*_NO_RAIN_*/
#define ASIC_Control_RESET_ASIC_ControlMode()   {rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;\
  if ((rbi_VDD_LightSignalError_g==FALSE)&&(get_rb_Asic_measureMode_mg()>=4))\
    { set_rb_Asic_measureMode_mg(0);} /*Reinit 0,5ms variable here*/ rw_Loop1DelayCount_mg = 0; }

#undef EXTERN

#endif
