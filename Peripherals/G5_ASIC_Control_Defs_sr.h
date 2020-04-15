#ifndef G5_ASIC_CONTROL_DEFS_SR_H
#define G5_ASIC_CONTROL_DEFS_SR_H

/*************************************************************************

  Company : Valeo Wiper System

  Project : RLT Sensor, RDN Sensor

  Component : ASIC_Control.h

  Documentation reference : Software Specification
  Overview of the component : interface to the electronics

  Evolution of the component : see Dimensions Version control system

                Initials   date   modification
*******************************************************************************/
/*!
 * \defgroup external Interface Description
 * \file ASIC_Control_Defs_sr.h
 * \brief H File ASIC Handling "ASIC_Control Modul"
 *        Contains all public elements like functions etc. for the application.
*/

/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number    Name    Description                                */
/*----------------------------------------------------------------------------*/
/*07.10.13   VCO_128    RFI     initial version                            */
/*07.11.13   VCO_128    MPI     separation of all safety declarations      */
/*09.02.15   VCO_220    MPI     VIrefLo/Hi monitoring*/
/*03.03.15   VCO_227    NB     Implement RAM Guard function */
/* 13.12.10  VCO_090    AL    parameter for RS_error Classification*/
/* 29.10.10  VDR_590 JS store result of all step response pulses, number of pulses per request reduced to 2 */
/* 29.04.10  VDR511_4 AL increase arry for Analog values*/
/* 25.03.10  VDR_446  FS  Update for all projects with _NO_ASIC_CLK_TRIMMING_USED */
/* 19.03.10  VDR_446 FS  Just to get latest Header-FIle in Project --> No change in file*/
/* 22.02.10  VDR_349 FS  No change: Just to have this header in the project*/
/* 18.12.09  VDR_398   FS      No change, just to implement latest version for Ford*/
/* 24.09.09   VDR_372   AL     Mesurment of NTC and usage of new microC Ports
                 PWM could be switched to portpin by EEPROM
                 Usage of EEPROM Cell for Amb Night and DayThreshold
                 Remove EEPROM valeo for IR and FW scaling for VWK*/
/* 02.09.09   VDR_365   AL     Mesurment scheduling and calculation for INAMB
                 Spot and coupling measurement       */
/*16.03.15   VDR_855 MP      Fix of the findings from the review of ASIC_Control_sr*/


/****************************************************************************/
/** Definition for Mono-Inclusion **/
/****************************************************************************/
#ifdef _G5_ASIC_Control_Defs_sr_
#define EXTERN /**/
#else

#endif

/****************************************************************************/
/** Global Variables **/
/****************************************************************************/

#define CB_NUMBER_OF_AOUT_SIG 23 /*VDR511_4 check number of bytes!*/

/*! Delay time for Fastloop on multiplied by 0.5ms*/
#define LOOP1_ON_DELAY 600

/*! Threshold ASIC Frequency Low*/
#define CB_ASIC_FREQUENCY_LOW 56
/*! Threshold ASIC Frequency High*/
#define CB_ASIC_FREQUENCY_HIGH 80
/*! Threshold ASIC Frequency Referenz*/
#define CB_ASIC_FREQUENCY_REF 64
/*! Threshold ASIC Frequency Invalid low*/
#define CB_ASIC_FREQUENCY_INVALID_LOW 6
/*! Threshold ASIC Frequency Invalid High*/
#define CB_ASIC_FREQUENCY_INVALID_HIGH 96

/*! Pointer for AD-Result*/
#define CB_INREC_MOD_ON_AD_POINTER   5

/*VCO_220 VIrefLo/Hi monitoring*/
/*definition for V_Iref_Lo/Hi limits*/
#define cw_VIREFLO_MIN_g        231
#define cw_VIREFLO_MAX_g        484
#define cw_VIREFHI_MIN_g        254
#define cw_VIREFHI_MAX_g        531

/*! Macro to read AD Result*/
#define rw_INREC_MOD_ON_g        raw_ANALO_INPUT_ASIC_x_g[CB_INREC_MOD_ON_AD_POINTER]

/*! RESET flag from the ASIC STATH register*/
#define rb_ASIC_Reset_Flag_g        (byte)((ras_ASIC_CtrReg_g[IDX_STATH_REG].val>>4)&0x1)
/*! WAKEUP flag from the ASIC STATH register*/
#define rb_ASIC_WAKEUP_Flag_g       (byte)((ras_ASIC_CtrReg_g[IDX_STATH_REG].val>>3)&0x1)
/*! SUPVMON flag (when overvoltage of VDDA) from the ASIC STATH register*/
#define rb_ASIC_SUPVMON_Flag_g      (byte)((ras_ASIC_CtrReg_g[IDX_STATH_REG].val>>2)&0x1)
/*! ADCMON flag (when ADC ref outside range) from the ASIC STATH register*/
#define rb_ASIC_ADCMON_Flag_g       (byte)((ras_ASIC_CtrReg_g[IDX_STATH_REG].val>>1)&0x1)
/*! IREFMON flag (when overvoltage of IREF) from the ASIC STATH register*/
#define rb_ASIC_IREFMON_Flag_g      (byte)((ras_ASIC_CtrReg_g[IDX_STATH_REG].val>>0)&0x1)

#define CB_SIZE_OF_ASIC_ALSx_g          7
#define CB_SIZE_OF_ASIC_CALIB_g         10

/****************************************************************************/
//              Global Contants and Makros
/****************************************************************************/

/*! Set test enable => TSTEN=1 see Spec. E101.12*/
#define CB_ASIC_SET_TEST_ENABLE   0x1A
/*! Reset test enable => TSTEN=0 see Spec. E101.12*/
#define CB_ASIC_CLEAR_TEST_ENABLE   0x18 /*VDR_306 check page 16/60 of ASIC Spec*/

/********************     Ambient Light Interface Macros      ****************/

           /****   Calibration definitions - Multiplexer control          ****/

/*        -- command type: CAL - calibration; MEAS = measurement
         |    -- OP2 input current: ILO/IHI/ICALLO/ICALHI = I_REF_ALI/I_CAL_ALI LO/HI
         |   |    -- OP1 input current: ILO/IHI/ICALLO/ICALHI = I_REF_ALI/I_CAL_ALI LO/HI
         |   |   |                      ALSx = I_PH_ALSx; REC = I_PH_REC
         |   |   |    -- gain: GLO/GHI = low/high gain
         |   |   |   |      */
#define CAL_ILO_IHI_GLO                         0x00
#define CAL_IHI_ILO_GLO                         0x20
#define CAL_ILO_ICALLO_GHI                      0x40
#define CAL_IHI_ICALHI_GHI                      0x60
#define CAL_ICALLO_ILO_GHI                      0xC0
#define CAL_ICALHI_IHI_GHI                      0xC4
#define CAL_ILO_IHI_GLO_INC                     0xC8
#define CAL_IHI_ILO_GLO_INC                     0xCC
#define CAL_IHI_ICALHI_GHI_INC                  0xD0
#define CAL_ICALHI_IHI_GHI_INC                  0xD4
/*Remove of unnecessary measurements*/
/*#define CAL_ILO_ICALLO_GHI_INC                  0xD8*/

           /****   Measurement definitions - Multiplexer control          ****/
/** measurement of ALSx, IREF low, gain low and VREF **/
#define MEAS_ILO_ALS1_GLO                       0x04
#define MEAS_ILO_ALS2_GLO                       0x08
#define MEAS_ILO_ALS3_GLO                       0x0C
#define MEAS_ILO_ALS4_GLO                       0x10
#define MEAS_ILO_ALS5_GLO                       0x14
#define MEAS_ILO_ALS6_GLO                       0x18
#define MEAS_ILO_REC_GLO                        0x1C
/** measurement of ALSx, IREF high, gain low and VREF **/
#define MEAS_IHI_ALS1_GLO                       0x24
#define MEAS_IHI_ALS2_GLO                       0x28
#define MEAS_IHI_ALS3_GLO                       0x2C
#define MEAS_IHI_ALS4_GLO                       0x30
#define MEAS_IHI_ALS5_GLO                       0x34
#define MEAS_IHI_ALS6_GLO                       0x38
#define MEAS_IHI_REC_GLO                        0x3C
/** measurement of ALSx, IREF low, gain high and VREF **/
#define MEAS_ILO_ALS1_GHI                       0x44
#define MEAS_ILO_ALS2_GHI                       0x48
#define MEAS_ILO_ALS3_GHI                       0x4C
#define MEAS_ILO_ALS4_GHI                       0x50
#define MEAS_ILO_ALS5_GHI                       0x54
#define MEAS_ILO_ALS6_GHI                       0x58
#define MEAS_ILO_REC_GHI                        0x5C
/** measurement of ALSx, IREF high, gain high and VREF **/
#define MEAS_IHI_ALS1_GHI                       0x64
#define MEAS_IHI_ALS2_GHI                       0x68
#define MEAS_IHI_ALS3_GHI                       0x6C
#define MEAS_IHI_ALS4_GHI                       0x70
#define MEAS_IHI_ALS5_GHI                       0x74
#define MEAS_IHI_ALS6_GHI                       0x78
#define MEAS_IHI_REC_GHI                        0x7C
/** measurement of ALSx, IREF low, gain low and VREF_INC **/
#define MEAS_ILO_ALS2_GLO_INC                   0x80
#define MEAS_ILO_ALS4_GLO_INC                   0x90
#define MEAS_ILO_ALS5_GLO_INC                   0xA0
#define MEAS_ILO_REC_GLO_INC                    0xB0
/** measurement of ALSx, IREF high, gain low and VREF_INC **/
#define MEAS_IHI_ALS2_GLO_INC                   0x84
#define MEAS_IHI_ALS4_GLO_INC                   0x94
#define MEAS_IHI_ALS5_GLO_INC                   0xA4
#define MEAS_IHI_REC_GLO_INC                    0xB4
/** measurement of ALSx, IREF low, gain high and VREF_INC **/
#define MEAS_ILO_ALS2_GHI_INC                   0x88
#define MEAS_ILO_ALS4_GHI_INC                   0x98
#define MEAS_ILO_ALS5_GHI_INC                   0xA8
#define MEAS_ILO_REC_GHI_INC                    0xB8
/** measurement of ALSx, IREF high, gain high and VREF_INC **/
#define MEAS_IHI_ALS2_GHI_INC                   0x8C
#define MEAS_IHI_ALS4_GHI_INC                   0x9C
#define MEAS_IHI_ALS5_GHI_INC                   0xAC
#define MEAS_IHI_REC_GHI_INC                    0xBC

#define MEAS_RSI_AMP                            0xDC
#define MEAS_VDIAG_LEDA                         0xE0
#define MEAS_VDIAG_LEDB                         0xE4
#define MEAS_VTEMP                              0xE8
#define MEAS_VDIAG_VREF                         0xEC
#define MEAS_V_IREF_LO                          0xF0
#define MEAS_V_IREF_HI                          0xF4
#define MEAS_VDIAG_VDDA                         0xF8
#define MEAS_VDIAG_VDDD                         0xFC


#define CHG_MUX_ALS1                            (byte)((((rb_ALS1_4_Setting_g&0x03)<<5)+4))
#define CHG_MUX_ALS2                            (byte)((((rb_ALS1_4_Setting_g&0x0C)<<3)+8))
/*ALS3, ALS4 are not connected*/
/*
#define CHG_MUX_ALS3                            (byte)((((rb_ALS1_4_Setting_g&0x30)<<1)+0x0C))
#define CHG_MUX_ALS4                            (byte)((((rb_ALS1_4_Setting_g&0xC0)>>1)+0x10))
*/
#define CHG_MUX_ALS5                            (byte)((((rb_ALS5_6_INREC_Setting_g&0x03)<<5)+0x14))
#define CHG_MUX_ALS6                            (byte)((((rb_ALS5_6_INREC_Setting_g&0x0C)<<3)+0x18))
#define CHG_MUX_REC                             (byte)((((rb_ALS5_6_INREC_Setting_g&0x30)<<1)+0x1C))
#define CHG_MUX_ALS2_INC                        (byte)(0x80+((rb_ALS1_4_Setting_g&0x0C)))
/*ALS3, ALS4 are not connected*/
/*
#define CHG_MUX_ALS4_INC                        (byte)(0x90+((rb_ALS1_4_Setting_g&0xC0)>>4))
*/
#define CHG_MUX_ALS5_INC                        (byte)(0xA0+((rb_ALS5_6_INREC_Setting_g&0x3)<<2))
#define CHG_MUX_REC_INC                         (byte)(0xB0+((rb_ALS5_6_INREC_Setting_g&0x30)>>2))

#define LEDX_LOL_THRS                           (word)(251)
#define LEDX_UPL_THRS_LEDUL_0                   (word)(531)
#define LEDX_UPL_THRS_LEDUL_1                   (word)(708)
#define LEDX_UPL_THRS_LEDUL_2                   (word)(907)
#define LEDX_UPL_THRS_LEDUL_3                   (word)(1084)


/*************************************************************************
                Declaration of none exported functions
**************************************************************************/

#undef EXTERN

#endif
