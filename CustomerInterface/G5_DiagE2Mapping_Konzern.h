#ifndef G5_DIAGE2MAPPING_KONZERN_H
#define G5_DIAGE2MAPPING_KONZERN_H
/* PRQA S 3619 EOF */ /* << 2010 01 08, compiler allows whitespaces:due to readable code, keep whitespaces! >> */
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */

/* MODULE SPECIFICATION
* %PCMS_HEADER_SUBSTITUTION_START:%
* Name:
* %PID:%
* %PM:%
* Description:
* %PL:%
*
*************************************************/
/* %PCMS_HEADER_SUBSTITUTION_END:% */

/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*-DD.MM.YY-------------------------------------------------------------------*/
/* 12.07.11  VDR_682  AL    Adapt Default Values for Tunneldelay*/
/* 27.06.11  VDR_671  AL    Move Consts to Bootseg2 to have space for changes in RLS_LIN_B8.c*/
/* 21.02.11  VCO_094  AL    Tunnel detection improvement*/
/* 22.10.10  VC0_081  AL    new EEPROM Varaibles for HT-Function, new Default*/
/* 18.11.10  VCO_086  AL    implement FS-Services for Diagnostics*/ 
/* 29.10.10  VDR_592  AL    update Default Variables*/
/* 19.10.10  VC0_081  AL    new EEPROM Varaibles for HT-Function, adpat Default EEPROM parameter*/
/* 30.08.10  VC074    AL    changes to allow compilation with gen3_5*/
/* 27.07.10  VDR_560  AL    use new faktor for 20 lx per digit Amblight*/
/* 20.07.10  VDR_563  AL    New Formula for SI-Transmission*/      
/* 20.07.10  VCO_63, VCO_64  AL  move HW-Partnumber in noninitialised area*/
/* 15.07.10  VDR_560  AL    use bit to adjust after tunnel Threshold*/
/* 15.07.10  VCO_061  AL    new variable*/
/* 10.06.10  VC0_58   AL    flag to adjust interval calculation*/
/* 05.05.10  VDR_505        change declaration to save code*/
/* 04.05.10	 VDR_510  AL    Tunnel thresholds adjustable per EEPROM*/
/* 18.03.10  VDR_468  AL    limit was forgotten*/
/* 15.03.10  VDR_466  AL    correct mask for Autobahnthreshold"*/
/* 15.03.10  VDR_464  AL    wrong range for Aftertunneldelay EEPROM byte"*/
/* 11.03.10  VCO_31   AL    new Service IDs"*/
/* 23.02.10  VCO_34   AL    implementation of incident counters"*/
/* 16.02.10  VCO_31   AL    "Anpassung" for Audi Konzersensor and "Messwert lesen"*/
/* 11.02.10  VCO_33   FS    To keep latest file in history*/
/* 10.02.10  VCO_33   FS    COmpare and Branch with KS-file*/
/* 05.02.10  VCO_33   FS    - EEPROM cells available for all CarCodes
*                          - SensitivityShift via EEPROM --> In the Standard Sensor this signal comes from LIN
*                          - Mapping of RainSensorSensitivity in EEPROM*/
/* 20.01.10  VDR_412  AL    new min and max Values avoid missuse */
/* 12.01.10  VCO_22   AL    New Definition of coding values for Audi Konzernsensor*/
/* 11.01.10  VDR_394  FS    QA-C analysed --> Commented or changed --> compiling ok, no different s19-file! */
/* 23.12.09  VDR_394  FS    REWORK: */
/*  - New CarCode Table: Default Values from EEPROM_new.xls-File reviewed and implemented*/
/*- New Variable Names*/
/* 22.12.09  VDR_395  FS    Function-Bits Max-Value set to 0xff*/
/* 18.12.09  VDR_403  FS    - Implement Max-Values for "Single or Double Overwipe"-function correct
*                          - Possible Overflow done in rs_empf.c*/
/* 18.12.09  VDR_366  FS    Implement VDR_330 due to overwritten DiagE2config-h V1.47 */
/* 17.11.09  VDR_394  FS    Update Default Values of all CarCodes for Ford, Green Glass parameter,
*                          Single or Double Overwipe default values cells 135 and 147*/
/* 09.11.09  VDR_373  FS    Single or Double Overwiped via EA-model*/
/* 26.10.09  VDR_389  AL    Gain Setup Default Variables adapted for Audi*/
/* 05.10.09  VDR_377  AL    new EEPROM parameters*/
/* 28.09.09  VDR_368  FS    Variable name changed due to CarCode related change from FORD*/
/* 17.07.09  VDR_344  FS    Car Code Config via EEPROM*/
/* 15.06.09  VDR_330  FS    RainLight Threshold available in Flash-EEPROM*/
/* 27.11.08  VDR_296  AL       Posche: The Rainsensor should be more sensitive in different conditions*/
/* 20.10.08  VCO_12   AL     SW-Partnumber index*/
/* 16.10.08  VDR_276  FS  Implement Overwipe Offset*/
/* 26.06.08   VCO_08  AL    Add EEPROM Values for FAW Twilight detection*/
/* 24.06.08  VDR_240  FS    Define rb_RLTPositionnearParkposition_E2_g --> */
/* Seat-Parameter should be usable in TMC-SW for Tata*/
/* 23.04.08  VDR_198 FS     for Toyota445L: To chose via EEPROM A,B,C,S */
/* 12.03.08  VDR_159 FS     Dummy to not use new branch */
/* 04.02.08  VDR_131 FS     use erase counter in EEPROM */
/* 01.08.13  VDR_735 NB     EEPROM cell 373,374,375 the Max values are set to 0xFF */
/* 22.07.2014 VDR_794 NB   change of the type of const array "cb_EEPROMDataDefaultMinMax_g"  to "__far" */
/* 24.07.2014 VDR_796 NB   Scaling of rb_si_Transmission_g */
/******************************************************************************/
#ifndef _HUMTEMP_H_ /*include not G5_HumTemp.h if already included*/
#include "G5_HumTemp.h"
#endif

#define ASIC_TEST   1

#ifndef _DIAGE2CONFIG_H_ /*VDR_394 --> QA-C Message 883 --> header protected against repeated implementation*/
#define _DIAGE2CONFIG_H_ /*VDR_394 --> QA-C Message 883*/

#define cb_NumberofEEPROMCells_g 163 //163  


#define cb_NumberofNoOverwriteEEPROMCells_g 64 /*After SW Flashing following Cells are taken as default FROM(!) EEPROM*/

#define cb_DEFAULT_g     0 /*Column for Default Value*/
#define cb_CHK_MIN_g     1 /*Column for Min Value*/
#define cb_CHK_MAX_g     2 /*Column for Max Value*/


#define CB_DEF_KODIERBYTE_2 0x6C
#define CB_MIN_KODIERBYTE_2 0x00
#define CB_MAX_KODIERBYTE_2 0xFF

#define CB_DEF_KODIERBYTE_1 0x00
#define CB_MIN_KODIERBYTE_1 0x00
#define CB_MAX_KODIERBYTE_1 0xFF


#define CB_DEF_KODIERBYTE_0 0x02
#define CB_MIN_KODIERBYTE_0 0x00
#define CB_MAX_KODIERBYTE_0 0x7F

#define CB_DEF_ALS1_4_SETTING 0xF4
#define CB_MIN_ALS1_4_SETTING 0x00  
#define CB_MAX_ALS1_4_SETTING 0xFF

#define CB_DEF_ALS5_6_INREC_SETTING	0x00
#define CB_MIN_ALS5_6_INREC_SETTING	0x00
#define CB_MAX_ALS5_6_INREC_SETTING	0xFF

#define CW_DEF_A_FACTOR_ALS1 (word)0x0164U
#define CW_MIN_A_FACTOR_ALS1 (word)0x0000U
#define CW_MAX_A_FACTOR_ALS1 (word)0xFFFFU 

#define CW_DEF_A_FACTOR_ALS2 (word)0x028CU
#define CW_MIN_A_FACTOR_ALS2 (word)0x0000U
#define CW_MAX_A_FACTOR_ALS2 (word)0xFFFFU 

#define CW_DEF_A_FACTOR_ALS3 (word)0x0200U
#define CW_MIN_A_FACTOR_ALS3 (word)0x0000U
#define CW_MAX_A_FACTOR_ALS3 (word)0xFFFFU 

#define CW_DEF_A_FACTOR_ALS4 (word)0x0200U
#define CW_MIN_A_FACTOR_ALS4 (word)0x0000U
#define CW_MAX_A_FACTOR_ALS4 (word)0xFFFFU

#define CW_DEF_A_FACTOR_ALS5 (word)0x01AAU
#define CW_MIN_A_FACTOR_ALS5 (word)0x0000U
#define CW_MAX_A_FACTOR_ALS5 (word)0xFFFFU

#define CW_DEF_A_FACTOR_ALS6 (word)0x0200U
#define CW_MIN_A_FACTOR_ALS6 (word)0x0000U
#define CW_MAX_A_FACTOR_ALS6 (word)0xFFFFU

#define CW_DEF_A_FACTOR_INREC (word)0x01A8U
#define CW_MIN_A_FACTOR_INREC (word)0x0000U
#define CW_MAX_A_FACTOR_INREC (word)0xFFFFU

#define CB_DEF_B_FACTOR_IREF_LO_GAIN_LO 0xD8
#define CB_MIN_B_FACTOR_IREF_LO_GAIN_LO 0x00
#define CB_MAX_B_FACTOR_IREF_LO_GAIN_LO 0xFF

#define CB_DEF_B_FACTOR_IREF_LO_GAIN_HI	0x40
#define CB_MIN_B_FACTOR_IREF_LO_GAIN_HI 0x00
#define CB_MAX_B_FACTOR_IREF_LO_GAIN_HI 0xFF

#define CB_DEF_B_FACTOR_IREF_HI_GAIN_LO 0xD8
#define CB_MIN_B_FACTOR_IREF_HI_GAIN_LO 0x00
#define CB_MAX_B_FACTOR_IREF_HI_GAIN_LO 0xFF

#define CB_DEF_B_FACTOR_IREF_HI_GAIN_HI	0x40
#define CB_MIN_B_FACTOR_IREF_HI_GAIN_HI 0x00
#define CB_MAX_B_FACTOR_IREF_HI_GAIN_HI 0xFF

#define CW_DEF_CRC_CHECKSUM_CALIBRATION (word)0x0000U
#define CW_MIN_CRC_CHECKSUM_CALIBRATION (word)0x0000U
#define CW_MAX_CRC_CHECKSUM_CALIBRATION (word)0xFFFFU

#define CB_DEF_STANDBY_RAIN_MEASUREMENT_1	0x00
#define CB_MIN_STANDBY_RAIN_MEASUREMENT_1       0x00
#define CB_MAX_STANDBY_RAIN_MEASUREMENT_1       0xFF

#define CB_DEF_STANDBY_RAIN_MEASUREMENT_2   0x00
#define CB_MIN_STANDBY_RAIN_MEASUREMENT_2   0x00
#define CB_MAX_STANDBY_RAIN_MEASUREMENT_2   0xFF

#define CB_DEF_STANDBY_RAIN_MEASUREMENT_3   0x00
#define CB_MIN_STANDBY_RAIN_MEASUREMENT_3   0x00
#define CB_MAX_STANDBY_RAIN_MEASUREMENT_3   0xFF

#define CB_DEF_STANDBY_RAIN_MEASUREMENT_4   0x00
#define CB_MIN_STANDBY_RAIN_MEASUREMENT_4   0x00
#define CB_MAX_STANDBY_RAIN_MEASUREMENT_4   0xFF

#define CB_DEF_STANDBY_RAIN_MEASUREMENT_5   0x00
#define CB_MIN_STANDBY_RAIN_MEASUREMENT_5   0x00
#define CB_MAX_STANDBY_RAIN_MEASUREMENT_5   0xFF

#define CB_DEF_STANDBY_RAIN_MEASUREMENT_6   0x00
#define CB_MIN_STANDBY_RAIN_MEASUREMENT_6   0x00
#define CB_MAX_STANDBY_RAIN_MEASUREMENT_6   0xFF

#define CB_DEF_ASIC_SCHED_CONFIG  0x04
#define CB_MIN_ASIC_SCHED_CONFIG  0x00
#define CB_MAX_ASIC_SCHED_CONFIG  0xFF

#define CB_DEF_ASIC_LCTR	0x00
#define CB_MIN_ASIC_LCTR        0x00
#define CB_MAX_ASIC_LCTR        0xFF

#define CW_DEF_NO_RAIN_PRESENT_THRSH_HB  0x0A
#define CW_MIN_NO_RAIN_PRESENT_THRSH_HB  0x00
#define CW_MAX_NO_RAIN_PRESENT_THRSH_HB  0xFF

#define CW_DEF_NO_RAIN_PRESENT_THRSH_LB  0x00
#define CW_MIN_NO_RAIN_PRESENT_THRSH_LB  0x00
#define CW_MAX_NO_RAIN_PRESENT_THRSH_LB  0xFF

#define CB_DEF_STBY_REGV_IMBALANCE  0x10
#define CB_MIN_STBY_REGV_IMBALANCE  0x00
#define CB_MAX_STBY_REGV_IMBALANCE  0xFF

#define CB_DEF_STBY_REGV_HB  0x00
#define CB_MIN_STBY_REGV_HB  0x00
#define CB_MAX_STBY_REGV_HB  0x10

#define CB_DEF_STBY_REGV_LB  0x00
#define CB_MIN_STBY_REGV_LB  0x00
#define CB_MAX_STBY_REGV_LB  0xFF

#define CB_DEF_STBY_DELTA_INTV_HB  0x00
#define CB_MIN_STBY_DELTA_INTV_HB  0x00
#define CB_MAX_STBY_DELTA_INTV_HB  0x10

#define CB_DEF_STBY_DELTA_INTV_LB  0x00
#define CB_MIN_STBY_DELTA_INTV_LB  0x00
#define CB_MAX_STBY_DELTA_INTV_LB  0xFF

#define CB_DEF_RSCONTROLFLAGS               0x00
#define CB_MIN_RSCONTROLFLAGS               0x00
#define CB_MAX_RSCONTROLFLAGS               0xff


#define CB_DEF_EEPROM_ERASE_COUNTER   0x00
#define CB_MIN_EEPROM_ERASE_COUNTER   0x00
#define CB_MAX_EEPROM_ERASE_COUNTER   0xFF

#define CB_DEF_HARDWARESTAND_0              cb_HARDWARESTAND_0_g
#define CB_MIN_HARDWARESTAND_0              0x00
#define CB_MAX_HARDWARESTAND_0              0xff

#define CB_DEF_HARDWARESTAND_1              cb_HARDWARESTAND_1_g
#define CB_MIN_HARDWARESTAND_1              0x00
#define CB_MAX_HARDWARESTAND_1              0xff

#define CB_DEF_PRODUKTIONSNUMMER_0          0x00
#define CB_MIN_PRODUKTIONSNUMMER_0          0x00
#define CB_MAX_PRODUKTIONSNUMMER_0          0xff

#define CB_DEF_PRODUKTIONSNUMMER_1          0x00
#define CB_MIN_PRODUKTIONSNUMMER_1          0x00
#define CB_MAX_PRODUKTIONSNUMMER_1          0xff

#define CB_DEF_PRODUKTIONSNUMMER_2          0x00
#define CB_MIN_PRODUKTIONSNUMMER_2          0x00
#define CB_MAX_PRODUKTIONSNUMMER_2          0xff

#define CB_DEF_PRODUKTIONSNUMMER_3          0x00
#define CB_MIN_PRODUKTIONSNUMMER_3          0x00
#define CB_MAX_PRODUKTIONSNUMMER_3          0xff

#define CB_DEF_FERTIGUNGSDATUM_TAG          1
#define CB_MIN_FERTIGUNGSDATUM_TAG          1
#define CB_MAX_FERTIGUNGSDATUM_TAG          31

#define CB_DEF_FERTIGUNGSDATUM_MONAT        1
#define CB_MIN_FERTIGUNGSDATUM_MONAT        1
#define CB_MAX_FERTIGUNGSDATUM_MONAT        12

#define CB_DEF_FERTIGUNGSDATUM_JAHR         13
#define CB_MIN_FERTIGUNGSDATUM_JAHR         13
#define CB_MAX_FERTIGUNGSDATUM_JAHR         99

#define CB_DEF_PARAMETERSTAND               CB_SW_TEILENUMMERIDX
#define CB_MIN_PARAMETERSTAND               0
#define CB_MAX_PARAMETERSTAND               0xff

#ifdef CB_DIAG_DEF_NAD
#define CB_DEF_NAD                          CB_DIAG_DEF_NAD
#else /*CB_DIAG_DEF_NAD*/
#define CB_DEF_NAD                          0x02
#endif /*CB_DIAG_DEF_NAD*/
#define CB_MIN_NAD                          0x01
#define CB_MAX_NAD                          0x7E

#ifdef CB_DIAG_DEF_RLSMSG
#define CB_DEF_IDRLSS_01                    CB_DIAG_DEF_RLSMSG
#else /*CB_DIAG_DEF_RLSMSG*/
#define CB_DEF_IDRLSS_01                    0xA3
#endif /*CB_DIAG_DEF_RLSMSG*/
#define CB_MIN_IDRLSS_01                    0
#define CB_MAX_IDRLSS_01                    0xff

#ifdef CB_DIAG_DEF_FSMSG
#define CB_DEF_IDFSS_01                     CB_DIAG_DEF_FSMSG
#else /*CB_DIAG_DEF_FSMSG*/
#define CB_DEF_IDFSS_01                     0xE9
#endif /*CB_DIAG_DEF_FSMSG*/
#define CB_MIN_IDFSS_01                     0
#define CB_MAX_IDFSS_01                     0xff

#ifdef CB_DIAG_DEF_BCMMSG
#define CB_DEF_BCM1_LIN1_01                 CB_DIAG_DEF_BCMMSG
#else /*CB_DIAG_DEF_BCMMSG*/
#define CB_DEF_BCM1_LIN1_01                 0xB1
#endif /*CB_DIAG_DEF_BCMMSG*/
#define CB_MIN_BCM1_LIN1_01                 0
#define CB_MAX_BCM1_LIN1_01                 0xff

#ifdef CB_DIAG_DEF_WWSMSG
#define CB_DEF_WWSS_01                      CB_DIAG_DEF_WWSMSG
#else /*CB_DIAG_DEF_WWSMSG*/
#define CB_DEF_WWSS_01                      0x32
#endif /*CB_DIAG_DEF_WWSMSG*/
#define CB_MIN_WWSS_01                      0
#define CB_MAX_WWSS_01                      0xff

#define CB_DEF_SOSES_01                    0xF0
#define CB_MIN_SOSES_01                    0x00
#define CB_MAX_SOSES_01                    0xFF


#ifdef ASIC_TEST

#define CB_DEF_ASIC_FRAME_01                    0x50
#define CB_MIN_ASIC_FRAME_01                    0x00
#define CB_MAX_ASIC_FRAME_01                    0xFF

#define CB_DEF_ASIC_FRAME_02                    0x11
#define CB_MIN_ASIC_FRAME_02                    0x00
#define CB_MAX_ASIC_FRAME_02                    0xFF

#define CB_DEF_ASIC_FRAME_03                    0x92
#define CB_MIN_ASIC_FRAME_03                    0x00
#define CB_MAX_ASIC_FRAME_03                    0xFF

#define CB_DEF_ASIC_FRAME_04                    0xD3
#define CB_MIN_ASIC_FRAME_04                    0x00
#define CB_MAX_ASIC_FRAME_04                    0xFF
#endif

#define CB_DEF_ASIC_RCTR_REG				0xF4
#define CB_MIN_ASIC_RCTR_REG				0x00
#define CB_MAX_ASIC_RCTR_REG				0xFF

#define CB_DEF_ASIC_RFCTR_REG				0x80
#define CB_MIN_ASIC_RFCTR_REG				0x00
#define CB_MAX_ASIC_RFCTR_REG				0xFF

#define CB_DEF_ERROR_ACTIVE_1				0x00
#define CB_MIN_ERROR_ACTIVE_1				0x00
#define CB_MAX_ERROR_ACTIVE_1				0xFF

#define CB_DEF_ERROR_ACTIVE_2				0x00
#define CB_MIN_ERROR_ACTIVE_2				0x00
#define CB_MAX_ERROR_ACTIVE_2				0xFF

#define CB_DEF_ERROR_ACTIVE_3				0x00
#define CB_MIN_ERROR_ACTIVE_3				0x00
#define CB_MAX_ERROR_ACTIVE_3				0xFF

#define CB_DEF_WATCHDOGRESETCOUNTER         0
#define CB_MIN_WATCHDOGRESETCOUNTER         0
#define CB_MAX_WATCHDOGRESETCOUNTER         0xff

#define CB_DEF_SENSOR_ERRORX                0x00
#define CB_MIN_SENSOR_ERRORX                0x00
#define CB_MAX_SENSOR_ERRORX                0xff

/*Incidence Counter*/ /*VCO_31 definition of default values new EEPROM definition*/
#define CB_DEF_INCIDENTCOUNTER1 0
#define CB_MIN_INCIDENTCOUNTER1 0
#define CB_MAX_INCIDENTCOUNTER1 0xFF
/*Incidence Counter*/
#define CB_DEF_INCIDENTCOUNTER2 0
#define CB_MIN_INCIDENTCOUNTER2 0
#define CB_MAX_INCIDENTCOUNTER2 0xFF
/*Incidence Counter*/
#define CB_DEF_INCIDENTCOUNTER3 0
#define CB_MIN_INCIDENTCOUNTER3 0
#define CB_MAX_INCIDENTCOUNTER3 0xFF
/*Incidence Counter*/
#define CB_DEF_INCIDENTCOUNTER4 0
#define CB_MIN_INCIDENTCOUNTER4 0
#define CB_MAX_INCIDENTCOUNTER4 0xFF
/*Incidence Counter*/
#define CB_DEF_INCIDENTCOUNTER5 0
#define CB_MIN_INCIDENTCOUNTER5 0
#define CB_MAX_INCIDENTCOUNTER5 0xFF
/*Incidence Counter*/
#define CB_DEF_INCIDENTCOUNTER6 0
#define CB_MIN_INCIDENTCOUNTER6 0
#define CB_MAX_INCIDENTCOUNTER6 0xFF
/*Incidence Counter*/
#define CB_DEF_INCIDENTCOUNTER7 0
#define CB_MIN_INCIDENTCOUNTER7 0
#define CB_MAX_INCIDENTCOUNTER7 0xFF

#define CB_DEF_GAINSETUP_0_1                0x12
#define CB_DEF_GAINSETUP_2_3                0x34
#define CB_DEF_GAINSETUP_4_5                0x56
#define CB_DEF_GAINSETUP_6_7                0x78
#define CB_DEF_GAINSETUP_8_9                0x9A
#define CB_DEF_GAINSETUP_10_MOD             0xB0
#define CB_MIN_GAINSETUP                    0x00
#define CB_MAX_GAINSETUP                    0xE0

#define CB_DEF_HALIOS_CLOCK_CONTROL_REG         0x90
#define CB_MIN_HALIOS_CLOCK_CONTROL_REG         0
#define CB_MAX_HALIOS_CLOCK_CONTROL_REG         0xff

#define CB_DEF_ACTR_REG                 0x8F
#define CB_MIN_ACTR_REG                 0
#define CB_MAX_ACTR_REG                 0xff

#define CB_DEF_PCO_PI_REGULATOR         0x60
#define CB_MIN_PCO_PI_REGULATOR         0
#define CB_MAX_PCO_PI_REGULATOR         0xff

#define CB_DEF_FOSC_LEDUL               0x81
#define CB_MIN_FOSC_LEDUL               0
#define CB_MAX_FOSC_LEDUL               0xff

#define CB_DEF_INTCO         0x10
#define CB_MIN_INTCO         0
#define CB_MAX_INTCO         0xff


#define CB_DEF_ICO1H         0xF2
#define CB_MIN_ICO1H         0
#define CB_MAX_ICO1H         0xff

#define CB_DEF_ICO1L         0x80
#define CB_MIN_ICO1L         0
#define CB_MAX_ICO1L         0xff

#define CB_DEF_ICO2H         0
#define CB_MIN_ICO2H         0
#define CB_MAX_ICO2H         0xff

#define CB_DEF_ICO2L         0x70
#define CB_MIN_ICO2L         0
#define CB_MAX_ICO2L         0xff

#define CB_DEF_STANDBYTIMOUT                 43
#define CB_MIN_STANDBYTIMOUT                 0
#define CB_MAX_STANDBYTIMOUT                 0xff

#define CB_DEF_TEILENUMMERN_INDEX           CB_TEILENUMMERIDX
#define CB_MIN_TEILENUMMERN_INDEX           0
#define CB_MAX_TEILENUMMERN_INDEX           0xff

#define CB_DEF_RS_SENSITIVITY_0             CB_EMPF_FAKTOR_E1
#define CB_MIN_RS_SENSITIVITY_0             2
#define CB_MAX_RS_SENSITIVITY_0             35
#define CB_DEF_RS_SENSITIVITY_1             CB_EMPF_FAKTOR_E2
#define CB_MIN_RS_SENSITIVITY_1             2
#define CB_MAX_RS_SENSITIVITY_1             35
#define CB_DEF_RS_SENSITIVITY_2             CB_EMPF_FAKTOR_E3
#define CB_MIN_RS_SENSITIVITY_2             2
#define CB_MAX_RS_SENSITIVITY_2             35
#define CB_DEF_RS_SENSITIVITY_3             CB_EMPF_FAKTOR_E4
#define CB_MIN_RS_SENSITIVITY_3             2
#define CB_MAX_RS_SENSITIVITY_3             40
#define CB_DEF_RS_SENSITIVITY_4             CB_EMPF_FAKTOR_E5
#define CB_MIN_RS_SENSITIVITY_4             2
#define CB_MAX_RS_SENSITIVITY_4             40
#define CB_DEF_RS_SENSITIVITY_5             CB_EMPF_FAKTOR_E6
#define CB_MIN_RS_SENSITIVITY_5             2
#define CB_MAX_RS_SENSITIVITY_5             40
#define CB_DEF_RS_SENSITIVITY_6             CB_EMPF_FAKTOR_E7
#define CB_MIN_RS_SENSITIVITY_6             2
#define CB_MAX_RS_SENSITIVITY_6             40
#define CB_DEF_RS_SENSITIVITY_7             CB_EMPF_FAKTOR_E8
#define CB_MIN_RS_SENSITIVITY_7             2
#define CB_MAX_RS_SENSITIVITY_7             40
#define CB_DEF_RS_SENSITIVITY_8             CB_EMPF_FAKTOR_E9
#define CB_MIN_RS_SENSITIVITY_8             2
#define CB_MAX_RS_SENSITIVITY_8             40

#define CB_DEF_MAXOVERWIPESENSITIVITY       cb_MAX_OVERWIPE_SENSITIVITY
#define CB_MIN_MAXOVERWIPESENSITIVITY       2
#define CB_MAX_MAXOVERWIPESENSITIVITY       35

#define CB_DEF_STUFE1_OG                    CB_STUFE1_OG
#define CB_MIN_STUFE1_OG                    170
#define CB_MAX_STUFE1_OG                    230

#define CB_DEF_STUFE1_UG                    CB_STUFE1_UG_DEFINITION
#define CB_MIN_STUFE1_UG                    150
#define CB_MAX_STUFE1_UG                    210

#define CB_DEF_EP_ST2_EPR_IN_ST2            CB_EP_ST2_EPR_IN_ST2
#define CB_MIN_EP_ST2_EPR_IN_ST2            128
#define CB_MAX_EP_ST2_EPR_IN_ST2            180

#define CB_DEF_SCHWELLE_SCHWALL             (byte)(CW_ST2_OG>>6)
#define CB_MIN_SCHWELLE_SCHWALL             70
#define CB_MAX_SCHWELLE_SCHWALL             140

#define CB_DEF_ANSAMLUN_ADIT_OFFS           CB_ANSAMLUN_ADIT_OFFS_DEF
#define CB_MIN_ANSAMLUN_ADIT_OFFS           0
#define CB_MAX_ANSAMLUN_ADIT_OFFS           180

#define CB_DEF_DEC_INT_SP_OFF               CB_DEC_INT_SP_OFFS_DEF  | 0x20 //reduce window height
#define CB_MIN_DEC_INT_SP_OFF               0x05
#define CB_MAX_DEC_INT_SP_OFF               0xff // rb_rs_WINDOW_COMP_THRESHOLD_g integrated in this variable //25

#define CB_DEF_DEC_STX_SPEICHER             CB_DEC_STX_SPEICHER
#define CB_MIN_DEC_STX_SPEICHER             30
#define CB_MAX_DEC_STX_SPEICHER             100

#define CB_DEF_DEC_OVR_SPEICHER             CB_DEC_OVR_SPEICHER_DEF+((CB_DEPRESSED_PARK_POINTER_DEF)<<5)
#define CB_MIN_DEC_OVR_SPEICHER             6
#define CB_MAX_DEC_OVR_SPEICHER             0x7F

#define CB_DEF_EMPF_FAKTOR_ST2_OFFS         CB_EMPF_FAKTOR_ST2_OFFS_DEF + (CB_TIMFORAFWTHRS_INC_g<<6)
#define CB_MIN_EMPF_FAKTOR_ST2_OFFS         5
#define CB_MAX_EMPF_FAKTOR_ST2_OFFS         0xff

#define CB_DEF_MAX_SIGNALLAENGE             CW_MAX_SIGNALLAENGE_DEF
#define CB_MIN_MAX_SIGNALLAENGE             120
#define CB_MAX_MAX_SIGNALLAENGE             250

#define CB_DEF_RB_STUFE1_WITH_INT_OG        CB_STUFE1_WITH_INT_OG_DEF
#define CB_MIN_RB_STUFE1_WITH_INT_OG        0
#define CB_MAX_RB_STUFE1_WITH_INT_OG        0xff

#define CB_DEF_NACHWISCH_4_ST1_MIN          CB_NACHWISCH_4_DEF+(CB_ST1_NACHWISCH_MIN_DEF<<5)
#define CB_MIN_NACHWISCH_4_ST1_MIN          11
#define CB_MAX_NACHWISCH_4_ST1_MIN          0xFF

#define CB_DEF_NACHWISCH_3                  CB_NACHWISCH_3_DEF | 0x80 /*VC0_58 flag to adjust interval calculation*/
#define CB_MIN_NACHWISCH_3                  11
#define CB_MAX_NACHWISCH_3                  0xFF

#define CB_DEF_NACHWISCH_2                  CB_NACHWISCH_2_DEF
#define CB_MIN_NACHWISCH_2                  11
#define CB_MAX_NACHWISCH_2                  0xFF

#define CB_DEF_RSEMPFFACTORSCALING          0x80+_OVR_INT_SCAL_OFFS+_EMPF_FACTOR_SCAL//Schlierenflag2-> C8
#define CB_MIN_RSEMPFFACTORSCALING          0
#define CB_MAX_RSEMPFFACTORSCALING          255

#define CB_DEF_SCHLIEREN_FLAG    104
#define CB_MIN_SCHLIEREN_FLAG    4
#define CB_MAX_SCHLIEREN_FLAG    255

#define CB_DEF_SIG_ANS_SCHW_OFFS        CB_SIG_ANS_SCHW_OFFS_DEF
#define CB_MIN_SIG_ANS_SCHW_OFFS        10
#define CB_MAX_SIG_ANS_SCHW_OFFS        0xff


#define CB_DEF_STANDBYMODESCANTIME      36
#define CB_MIN_STANDBYMODESCANTIME      0
#define CB_MAX_STANDBYMODESCANTIME      0xff  /*VC0_58 flag to adjust interval calculation*/
/*rain nightbit threshold*/
#define CB_DEF_RAINNIGHTBITTHRS         0x01
#define CB_MIN_RAINNIGHTBITTHRS         0
#define CB_MAX_RAINNIGHTBITTHRS         0xff

#define CB_DEF_AMB_BASE_DAY_THRESHOLD        cb_AMB_DAY_THRESHOLD_DEF_s
#define CB_MIN_AMB_BASE_DAY_THRESHOLD        50 /*VDR_470*/
#define CB_MAX_AMB_BASE_DAY_THRESHOLD        254 /*VDR_470*/

#define CB_DEF_AMB_BASE_NIGHT_THRESHOLD      cb_AMB_NIGHT_THRESHOLD_DEF_s
#define CB_MIN_AMB_BASE_NIGHT_THRESHOLD      40 /*VDR_470*/
#define CB_MAX_AMB_BASE_NIGHT_THRESHOLD      190 /*VDR_470*/

#define CB_DEF_TUNNELDEBOUNCEFACTOR         45
#define CB_MIN_TUNNELDEBOUNCEFACTOR         30
#define CB_MAX_TUNNELDEBOUNCEFACTOR         230

#define CB_DEF_CUSTOMER_FW_SWA_SCALING      128
#define CB_MIN_CUSTOMER_FW_SWA_SCALING      50
#define CB_MAX_CUSTOMER_FW_SWA_SCALING      220

#define CB_DEF_CUSTOMER_IR_SWA_SCALING      128
#define CB_MIN_CUSTOMER_IR_SWA_SCALING      50
#define CB_MAX_CUSTOMER_IR_SWA_SCALING      220

#define CB_DEF_FW_BASE_DAY_THRESHOLD        cb_FW_DAY_THRESHOLD_DEF_s
#define CB_MIN_FW_BASE_DAY_THRESHOLD        70
#define CB_MAX_FW_BASE_DAY_THRESHOLD        210

#define CB_DEF_IR_BASE_DAY_THRESHOLD        cb_IR_DAY_THRESHOLD_DEF_s
#define CB_MIN_IR_BASE_DAY_THRESHOLD        40
#define CB_MAX_IR_BASE_DAY_THRESHOLD        170

#define CB_DEF_FW_BASE_NIGHT_THRESHOLD      cb_FW_NIGHT_THRESHOLD_DEF_s
#define CB_MIN_FW_BASE_NIGHT_THRESHOLD      50
#define CB_MAX_FW_BASE_NIGHT_THRESHOLD      200

#define CB_DEF_IR_BASE_NIGHT_THRESHOLD      cb_IR_NIGHT_THRESHOLD_DEF_s
#define CB_MIN_IR_BASE_NIGHT_THRESHOLD      30
#define CB_MAX_IR_BASE_NIGHT_THRESHOLD      190

#define CB_DEF_DAY_DELAY                    (byte)(cw_DAY_DELAY_DEF_s>>6)
#define CB_MIN_DAY_DELAY                    50
#define CB_MAX_DAY_DELAY                    200

#define CB_DEF_NIGHT_DELAY                  (byte)(cw_NIGHT_DELAY_DEF_s>>6)
#define CB_MIN_NIGHT_DELAY                  50
#define CB_MAX_NIGHT_DELAY                  200

#define CB_DEF_AFTERTUNNELDELAYOFFS         11
#define CB_MAX_AFTERTUNNELDELAYOFFS         0x1f 
#define CB_MIN_AFTERTUNNELDELAYOFFS         0

/*Autobahn_on_off*/ /*VCO_31 definition of default values new EEPROM definition*/
#define CB_DEF_AUTOBAHN_ON_OFF            0x54
#define CB_MIN_AUTOBAHN_ON_OFF            0
#define CB_MAX_AUTOBAHN_ON_OFF            0xFF

/*Autobahn Delay on*/
#define CB_DEF_AUTOBAHN_DELAY_ON          0x49
#define CB_MIN_AUTOBAHN_DELAY_ON          0
#define CB_MAX_AUTOBAHN_DELAY_ON          0xFF

/* Frontwaschen +Autobahndelay*/
#define CB_DEF_FRONTWASCHEN_AUTOBAHNDELAY 0x57
#define CB_MIN_FRONTWASCHEN_AUTOBAHNDELAY 0
#define CB_MAX_FRONTWASCHEN_AUTOBAHNDELAY 0xFF

/*regenlicht_low_high*/
#define CB_DEF_REGENLICHTSCHWELLE_LOW_HIGH 3
#define CB_MIN_REGENLICHTSCHWELLE_LOW_HIGH 0
#define CB_MAX_REGENLICHTSCHWELLE_LOW_HIGH 0xFF

/*regenlicht */
#define CB_DEF_REGENLICHTSCHWELLE_ZEIT 219
#define CB_MIN_REGENLICHTSCHWELLE_ZEIT 0
#define CB_MAX_REGENLICHTSCHWELLE_ZEIT 0xFF

#define CB_DEF_TUNNELTHRESHOLDSCALING 0x44 /*default value for tunnel threshold scaling*/
#define CB_MIN_TUNNELTHRESHOLDSCALING 0
#define CB_MAX_TUNNELTHRESHOLDSCALING 0xff

#define CB_DEF_AMB_TUNNELTHRESHOLDSCALING 0x04 
#define CB_MIN_AMB_TUNNELTHRESHOLDSCALING 0
#define CB_MAX_AMB_TUNNELTHRESHOLDSCALING 0xff

#define CB_DEF_REGULATION48LIGHTONTIME 96
#define CB_MIN_REGULATION48LIGHTONTIME 20
#define CB_MAX_REGULATION48LIGHTONTIME 255

#define CB_DEF_REGULATION48THRESHOLD 0x65 /*(about 810 lux---Value corrected for 80% transmission through glass)---(Previous Value about 1250 lux)----KI*/
#define CB_MIN_REGULATION48THRESHOLD 0
#define CB_MAX_REGULATION48THRESHOLD 255


#define CB_DEF_VERYBRIGHTINTUNNELDELAY CB_DEF_VERYBRIGHTINTUNL_DIST_THRS_g /*VCO_094 Thresehold Set for VeryBrightTunnelDetection*/
#define CB_MIN_VERYBRIGHTINTUNNELDELAY CB_MIN_VERYBRIGHTINTUNL_DIST_THRS_g  /*VCO_094 Thresehold Set for VeryBrightTunnelDetection*/
#define CB_MAX_VERYBRIGHTINTUNNELDELAY CB_MAX_VERYBRIGHTINTUNL_DIST_THRS_g /*VCO_094 Thresehold Set for VeryBrightTunnelDetection*/


#define CB_DEF_COMBINED_FW_AL_THRS 0x00
#define CB_MIN_COMBINED_FW_AL_THRS 0x00
#define CB_MAX_COMBINED_FW_AL_THRS 0xFF

#define CB_DEF_DYN_COMP_CCD_MINUS_1 ((cb_DYN_COMP_CCD_MINUS_neg5to10_DEF<<4)+cb_DYN_COMP_CCD_MINUS_10to25_DEF) /*default value for tunnel threshold scaling*/
#define CB_MIN_DYN_COMP_CCD_MINUS_1  0x00
#define CB_MAX_DYN_COMP_CCD_MINUS_1  0xFF

#define CB_DEF_DYN_COMP_CCD_MINUS_2 ((cb_DYN_COMP_CCD_MINUS_25to40_DEF << 4)+cb_DYN_COMP_CCD_MINUS_above40_DEF) /*default value for tunnel threshold scaling*/
#define CB_MIN_DYN_COMP_CCD_MINUS_2 0x00
#define CB_MAX_DYN_COMP_CCD_MINUS_2 0xFF

#define CB_DEF_MAXTEMPERATUREOFFSETT CB_DEF_MAXTEMPERATUREOFFSET_G
#define CB_MIN_MAXTEMPERATUREOFFSETT 0x00
#define CB_MAX_MAXTEMPERATUREOFFSETT 0xFF

#define CB_DEF_ASIC_AFSTHR_REG 0x99
#define CB_MIN_ASIC_AFSTHR_REG 0x00
#define CB_MAX_ASIC_AFSTHR_REG 0xFF

#define CB_DEF_E2_RESERVED_I2 0x00
#define CB_MIN_E2_RESERVED_I2 0x00
#define CB_MAX_E2_RESERVED_I2 0xFF

#define CB_DEF_E2_RESERVED_I3 0x00
#define CB_MIN_E2_RESERVED_I3 0x00
#define CB_MAX_E2_RESERVED_I3 0xFF

#define CB_DEF_I2C_DEBUG_CONFIG 0x00
#define CB_MIN_I2C_DEBUG_CONFIG 0x00
#define CB_MAX_I2C_DEBUG_CONFIG 0xFF

#define CB_DEF_INC_SPEICHER 0x64
#define CB_MIN_INC_SPEICHER 0x00
#define CB_MAX_INC_SPEICHER 0xFF


#define CB_DEF_SOFTWARESTAND_0              cb_SOFTWARESTAND_0_g
#define CB_MIN_SOFTWARESTAND_0              0
#define CB_MAX_SOFTWARESTAND_0              0xff

#define CB_DEF_SOFTWARESTAND_1              cb_SOFTWARESTAND_1_g
#define CB_MIN_SOFTWARESTAND_1              0
#define CB_MAX_SOFTWARESTAND_1              0xff

#define CB_DEF_SOFTWARESTAND_2              cb_SWSTANDEEPROM_23_g
#define CB_MIN_SOFTWARESTAND_2              0
#define CB_MAX_SOFTWARESTAND_2              0xff

#define CB_DEF_SOFTWARESTAND_3              0
#define CB_MIN_SOFTWARESTAND_3              0
#define CB_MAX_SOFTWARESTAND_3              0xff











#define CB_DEF_ASIC_DIAGV                        0x78
#define CB_MIN_ASIC_DIAGV                        0
#define CB_MAX_ASIC_DIAGV                        0xff


#define CB_DEF_ASIC_GAINSETUP               0x40
#define CB_MIN_ASIC_GAINSETUP               0
#define CB_MAX_ASIC_GAINSETUP               0xfe


#define CB_DEF_TIMETOREACHNORMALSPEEDMODE   ((byte)(cw_TIME_TO_REACH_NORMAL_MODE_DEF_mg>>5))
#define CB_MIN_TIMETOREACHNORMALSPEEDMODE   10
#define CB_MAX_TIMETOREACHNORMALSPEEDMODE   0xff

#define CB_DEF_TIMETOREACHFASTHIGHWAYMODE   ((byte)cb_TIMETOREACH_FASTHIGHWAY_MODE_Def_mg>>4)
#define CB_MIN_TIMETOREACHFASTHIGHWAYMODE   5
#define CB_MAX_TIMETOREACHFASTHIGHWAYMODE   0xff


#define CB_DEF_MEAN_HIGHWAYLIGHTONSPEED     cb_MEAN_HIGHWAY_LIGHT_SPEED_DEF_mg
#define CB_MIN_MEAN_HIGHWAYLIGHTONSPEED     0
#define CB_MAX_MEAN_HIGHWAYLIGHTONSPEED     0xff

#define _EMPF_FACTOR_SCAL    0x07
#define _OVR_INT_SCAL_OFFS   0x40





#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_ /*VDR_403*/
#define CB_DEF_SINGLE_OR_DOUBLE             0x95 /*Low Nibble: rb_Single_Or_Double_Overwipe_dec,
High Nibble: rb_MaxOverwipeSensitivity_g*/ /*VDR_394*/
#define CB_MIN_SINGLE_OR_DOUBLE             0
#define CB_MAX_SINGLE_OR_DOUBLE             0xFF /*( ( (rb_MaxOverwipeSensitivity_g<0x0F)?((rb_MaxOverwipeSensitivity_g<<4):0xFF) )  |0x0F )*/ /*Max for High Nibble results from rb_MaxOverwipeSensitivity_g*/
#endif





#ifdef _DIAGNOSE_c_
#define EXTERN /**/
#pragma constseg="BOOTSEG_TWO"               /* VDR_671 */
const byte __far cb_EEPROMDataDefaultMinMax_g[cb_NumberofEEPROMCells_g][3] = {
  
  {CB_DEF_KODIERBYTE_2                    ,CB_MIN_KODIERBYTE_2                   ,CB_MAX_KODIERBYTE_2                   },      // 256
  {CB_DEF_KODIERBYTE_1                    ,CB_MIN_KODIERBYTE_1                   ,CB_MAX_KODIERBYTE_1                   },      // 257
  {CB_DEF_KODIERBYTE_0                    ,CB_MIN_KODIERBYTE_0                   ,CB_MAX_KODIERBYTE_0                   },      // 258
  {CB_DEF_ALS1_4_SETTING                  ,CB_MIN_ALS1_4_SETTING                 ,CB_MAX_ALS1_4_SETTING                 },      // 259
  {CB_DEF_ALS5_6_INREC_SETTING            ,CB_MIN_ALS5_6_INREC_SETTING           ,CB_MAX_ALS5_6_INREC_SETTING           },      // 260
  {CB_DEF_ASIC_DIAGV                      ,CB_MIN_ASIC_DIAGV                     ,CB_MAX_ASIC_DIAGV                     },      // 261
  {(byte)(CW_DEF_A_FACTOR_ALS1&0xFF)      ,(byte)(CW_MIN_A_FACTOR_ALS1&0xFF)     ,(byte)(CW_MAX_A_FACTOR_ALS1&0xFF)     },      // 262
  {(byte)(CW_DEF_A_FACTOR_ALS1>>8)        ,(byte)(CW_MIN_A_FACTOR_ALS1>>8)       ,(byte)(CW_MAX_A_FACTOR_ALS1>>8)       },      // 263
  {(byte)(CW_DEF_A_FACTOR_ALS2&0xFF)      ,(byte)(CW_MIN_A_FACTOR_ALS2&0xFF)     ,(byte)(CW_MAX_A_FACTOR_ALS2&0xFF)     },      // 264
  {(byte)(CW_DEF_A_FACTOR_ALS2>>8)        ,(byte)(CW_MIN_A_FACTOR_ALS2>>8)       ,(byte)(CW_MAX_A_FACTOR_ALS2>>8)       },      // 265
  {(byte)(CW_DEF_A_FACTOR_ALS3&0xFF)      ,(byte)(CW_MIN_A_FACTOR_ALS3&0xFF)     ,(byte)(CW_MAX_A_FACTOR_ALS3&0xFF)     },      // 266
  {(byte)(CW_DEF_A_FACTOR_ALS3>>8)        ,(byte)(CW_MIN_A_FACTOR_ALS3>>8)       ,(byte)(CW_MAX_A_FACTOR_ALS3>>8)       },      // 267
  {(byte)(CW_DEF_A_FACTOR_ALS4&0xFF)      ,(byte)(CW_MIN_A_FACTOR_ALS4&0xFF)     ,(byte)(CW_MAX_A_FACTOR_ALS4&0xFF)     },      // 268
  {(byte)(CW_DEF_A_FACTOR_ALS4>>8)        ,(byte)(CW_MIN_A_FACTOR_ALS4>>8)       ,(byte)(CW_MAX_A_FACTOR_ALS4>>8)       },      // 269
  {(byte)(CW_DEF_A_FACTOR_ALS5&0xFF)      ,(byte)(CW_MIN_A_FACTOR_ALS5&0xFF)     ,(byte)(CW_MAX_A_FACTOR_ALS5&0xFF)     },      // 270
  {(byte)(CW_DEF_A_FACTOR_ALS5>>8)        ,(byte)(CW_MIN_A_FACTOR_ALS5>>8)       ,(byte)(CW_MAX_A_FACTOR_ALS5>>8)       },      // 271
  {(byte)(CW_DEF_A_FACTOR_ALS6&0xFF)      ,(byte)(CW_MIN_A_FACTOR_ALS6&0xFF)     ,(byte)(CW_MAX_A_FACTOR_ALS6&0xFF)     },      // 272
  {(byte)(CW_DEF_A_FACTOR_ALS6>>8)        ,(byte)(CW_MIN_A_FACTOR_ALS6>>8)       ,(byte)(CW_MAX_A_FACTOR_ALS6>>8)       },      // 273
  {(byte)(CW_DEF_A_FACTOR_INREC&0xFF)     ,(byte)(CW_MIN_A_FACTOR_INREC&0xFF)    ,(byte)(CW_MAX_A_FACTOR_INREC&0xFF)    },      // 274
  {(byte)(CW_DEF_A_FACTOR_INREC>>8)       ,(byte)(CW_MIN_A_FACTOR_INREC>>8)      ,(byte)(CW_MAX_A_FACTOR_INREC>>8)      },      // 275   
  {CB_DEF_B_FACTOR_IREF_LO_GAIN_LO      ,CB_MIN_B_FACTOR_IREF_LO_GAIN_LO     ,CB_MAX_B_FACTOR_IREF_LO_GAIN_LO           },      // 276
  {CB_DEF_B_FACTOR_IREF_LO_GAIN_HI      ,CB_MIN_B_FACTOR_IREF_LO_GAIN_HI     ,CB_MAX_B_FACTOR_IREF_LO_GAIN_HI           },      // 277
  {CB_DEF_B_FACTOR_IREF_HI_GAIN_LO      ,CB_MIN_B_FACTOR_IREF_HI_GAIN_LO     ,CB_MAX_B_FACTOR_IREF_HI_GAIN_LO           },      // 278
  {CB_DEF_B_FACTOR_IREF_HI_GAIN_HI      ,CB_MIN_B_FACTOR_IREF_HI_GAIN_HI     ,CB_MAX_B_FACTOR_IREF_HI_GAIN_HI           },      // 279
  {(byte)(CW_DEF_CRC_CHECKSUM_CALIBRATION&0xFF)     ,(byte)(CW_MIN_CRC_CHECKSUM_CALIBRATION&0xFF)     ,(byte)(CW_MAX_CRC_CHECKSUM_CALIBRATION&0xFF)     },      // 280
  {(byte)(CW_DEF_CRC_CHECKSUM_CALIBRATION>>8)     ,(byte)(CW_MIN_CRC_CHECKSUM_CALIBRATION>>8)     ,(byte)(CW_MAX_CRC_CHECKSUM_CALIBRATION>>8)           },     // 281
  {CB_DEF_STANDBY_RAIN_MEASUREMENT_1     ,CB_MIN_STANDBY_RAIN_MEASUREMENT_1     ,CB_MAX_STANDBY_RAIN_MEASUREMENT_1     },      // 282
  {CB_DEF_STANDBY_RAIN_MEASUREMENT_2     ,CB_MIN_STANDBY_RAIN_MEASUREMENT_2     ,CB_MAX_STANDBY_RAIN_MEASUREMENT_2     },      // 283
  {CB_DEF_STANDBY_RAIN_MEASUREMENT_3     ,CB_MIN_STANDBY_RAIN_MEASUREMENT_3     ,CB_MAX_STANDBY_RAIN_MEASUREMENT_3     },      // 284  
  {CB_DEF_STANDBY_RAIN_MEASUREMENT_4     ,CB_MIN_STANDBY_RAIN_MEASUREMENT_4     ,CB_MAX_STANDBY_RAIN_MEASUREMENT_4     },      // 285  
  {CB_DEF_STANDBY_RAIN_MEASUREMENT_5     ,CB_MIN_STANDBY_RAIN_MEASUREMENT_5     ,CB_MAX_STANDBY_RAIN_MEASUREMENT_5     },      // 286  
  {CB_DEF_STANDBY_RAIN_MEASUREMENT_6     ,CB_MIN_STANDBY_RAIN_MEASUREMENT_6     ,CB_MAX_STANDBY_RAIN_MEASUREMENT_6     },      // 287  
  {CB_DEF_ASIC_SCHED_CONFIG              ,CB_MIN_ASIC_SCHED_CONFIG              ,CB_MAX_ASIC_SCHED_CONFIG              },      // 288  
  {CB_DEF_ASIC_LCTR                      ,CB_MIN_ASIC_LCTR                      ,CB_MAX_ASIC_LCTR                      },      // 289
  {CW_DEF_NO_RAIN_PRESENT_THRSH_HB       ,CW_MIN_NO_RAIN_PRESENT_THRSH_HB       ,CW_MAX_NO_RAIN_PRESENT_THRSH_HB       },      // 290
  {CW_DEF_NO_RAIN_PRESENT_THRSH_LB       ,CW_MIN_NO_RAIN_PRESENT_THRSH_LB       ,CW_MAX_NO_RAIN_PRESENT_THRSH_LB       },      // 291
  {CB_DEF_STBY_REGV_IMBALANCE            ,CB_MIN_STBY_REGV_IMBALANCE            ,CB_MAX_STBY_REGV_IMBALANCE     },      // 292
  {CB_DEF_STBY_REGV_HB                   ,CB_MIN_STBY_REGV_HB                   ,CB_MAX_STBY_REGV_HB     },      // 293
  {CB_DEF_STBY_REGV_LB                   ,CB_MIN_STBY_REGV_LB                   ,CB_MAX_STBY_REGV_LB     },      // 294
  {CB_DEF_STBY_DELTA_INTV_HB             ,CB_MIN_STBY_DELTA_INTV_HB             ,CB_MAX_STBY_DELTA_INTV_HB     },      // 295
  {CB_DEF_STBY_DELTA_INTV_LB             ,CB_MIN_STBY_DELTA_INTV_LB             ,CB_MAX_STBY_DELTA_INTV_LB     },      // 296
  {CB_DEF_RSCONTROLFLAGS                 ,CB_MIN_RSCONTROLFLAGS                 ,CB_MAX_RSCONTROLFLAGS                 },      // 297  
  {CB_DEF_EEPROM_ERASE_COUNTER           ,CB_MIN_EEPROM_ERASE_COUNTER           ,CB_MAX_EEPROM_ERASE_COUNTER           },      // 298
  {CB_DEF_HARDWARESTAND_0                ,CB_MIN_HARDWARESTAND_0                ,CB_MAX_HARDWARESTAND_0                },      // 299
  {CB_DEF_HARDWARESTAND_1                ,CB_MIN_HARDWARESTAND_1                ,CB_MAX_HARDWARESTAND_1                },      // 300
  {CB_DEF_PRODUKTIONSNUMMER_0            ,CB_MIN_PRODUKTIONSNUMMER_0            ,CB_MAX_PRODUKTIONSNUMMER_0            },      // 301
  {CB_DEF_PRODUKTIONSNUMMER_1            ,CB_MIN_PRODUKTIONSNUMMER_1            ,CB_MAX_PRODUKTIONSNUMMER_1            },      // 302
  {CB_DEF_PRODUKTIONSNUMMER_2            ,CB_MIN_PRODUKTIONSNUMMER_2            ,CB_MAX_PRODUKTIONSNUMMER_2            },      // 303
  {CB_DEF_PRODUKTIONSNUMMER_3            ,CB_MIN_PRODUKTIONSNUMMER_3            ,CB_MAX_PRODUKTIONSNUMMER_3            },      // 304
  {CB_DEF_FERTIGUNGSDATUM_TAG            ,CB_MIN_FERTIGUNGSDATUM_TAG            ,CB_MAX_FERTIGUNGSDATUM_TAG            },      // 305
  {CB_DEF_FERTIGUNGSDATUM_MONAT          ,CB_MIN_FERTIGUNGSDATUM_MONAT          ,CB_MAX_FERTIGUNGSDATUM_MONAT          },      // 306
  {CB_DEF_FERTIGUNGSDATUM_JAHR           ,CB_MIN_FERTIGUNGSDATUM_JAHR           ,CB_MAX_FERTIGUNGSDATUM_JAHR           },      // 307
  {CB_DEF_PARAMETERSTAND                 ,CB_MIN_PARAMETERSTAND                 ,CB_MAX_PARAMETERSTAND                 },      // 308
  {CB_DEF_NAD                            ,CB_MIN_NAD                            ,CB_MAX_NAD                            },      // 309
  {CB_DEF_IDFSS_01                       ,CB_MIN_IDFSS_01                       ,CB_MAX_IDFSS_01                       },      // 310
  {CB_DEF_IDRLSS_01                      ,CB_MIN_IDRLSS_01                      ,CB_MAX_IDRLSS_01                      },      // 311
  {CB_DEF_BCM1_LIN1_01                   ,CB_MIN_BCM1_LIN1_01                   ,CB_MAX_BCM1_LIN1_01                   },      // 312
  {CB_DEF_WWSS_01                        ,CB_MIN_WWSS_01                        ,CB_MAX_WWSS_01                        },      // 313
  {CB_DEF_SOSES_01                       ,CB_MIN_SOSES_01                       ,CB_MAX_SOSES_01                       },      // 314
  {CB_DEF_ASIC_RCTR_REG                  ,CB_MIN_ASIC_RCTR_REG                  ,CB_MAX_ASIC_RCTR_REG                  },      // 315
  {CB_DEF_ASIC_RFCTR_REG                 ,CB_MIN_ASIC_RFCTR_REG                 ,CB_MAX_ASIC_RFCTR_REG                 },      // 316  
  {CB_DEF_ERROR_ACTIVE_1                 ,CB_MIN_ERROR_ACTIVE_1                 ,CB_MAX_ERROR_ACTIVE_1                 },      // 317  
  {CB_DEF_ERROR_ACTIVE_2                 ,CB_MIN_ERROR_ACTIVE_2                 ,CB_MAX_ERROR_ACTIVE_2                 },      // 318
  {CB_DEF_ERROR_ACTIVE_3                 ,CB_MIN_ERROR_ACTIVE_3                 ,CB_MAX_ERROR_ACTIVE_3                 },      // 319  
  {CB_DEF_WATCHDOGRESETCOUNTER           ,CB_MIN_WATCHDOGRESETCOUNTER           ,CB_MAX_WATCHDOGRESETCOUNTER           },      // 320
  {CB_DEF_SENSOR_ERRORX                  ,CB_MIN_SENSOR_ERRORX                  ,CB_MAX_SENSOR_ERRORX                  },      // 321
  {CB_DEF_SENSOR_ERRORX                  ,CB_MIN_SENSOR_ERRORX                  ,CB_MAX_SENSOR_ERRORX                  },      // 322
  {CB_DEF_SENSOR_ERRORX                  ,CB_MIN_SENSOR_ERRORX                  ,CB_MAX_SENSOR_ERRORX                  },      // 323
  {CB_DEF_SENSOR_ERRORX                  ,CB_MIN_SENSOR_ERRORX                  ,CB_MAX_SENSOR_ERRORX                  },      // 324
  {CB_DEF_SENSOR_ERRORX                  ,CB_MIN_SENSOR_ERRORX                  ,CB_MAX_SENSOR_ERRORX                  },      // 325
  {CB_DEF_SENSOR_ERRORX                  ,CB_MIN_SENSOR_ERRORX                  ,CB_MAX_SENSOR_ERRORX                  },      // 326
  {CB_DEF_INCIDENTCOUNTER1               ,CB_MIN_INCIDENTCOUNTER1               ,CB_MAX_INCIDENTCOUNTER1               },     // 327
  {CB_DEF_INCIDENTCOUNTER2               ,CB_MIN_INCIDENTCOUNTER2               ,CB_MAX_INCIDENTCOUNTER2               },     // 328
  {CB_DEF_INCIDENTCOUNTER3               ,CB_MIN_INCIDENTCOUNTER3               ,CB_MAX_INCIDENTCOUNTER3               },     // 329
  {CB_DEF_INCIDENTCOUNTER4               ,CB_MIN_INCIDENTCOUNTER4               ,CB_MAX_INCIDENTCOUNTER4               },     // 330
  {CB_DEF_INCIDENTCOUNTER5               ,CB_MIN_INCIDENTCOUNTER5               ,CB_MAX_INCIDENTCOUNTER5               },     // 331
  {CB_DEF_INCIDENTCOUNTER6               ,CB_MIN_INCIDENTCOUNTER6               ,CB_MAX_INCIDENTCOUNTER6               },     // 332      
  {CB_DEF_INCIDENTCOUNTER7               ,CB_MIN_INCIDENTCOUNTER7               ,CB_MAX_INCIDENTCOUNTER7               },     // 333    
  {CB_DEF_GAINSETUP_0_1                  ,CB_MIN_GAINSETUP                      ,CB_MAX_GAINSETUP                      },      // 334
  {CB_DEF_GAINSETUP_2_3                  ,CB_MIN_GAINSETUP                      ,CB_MAX_GAINSETUP                      },      // 335
  {CB_DEF_GAINSETUP_4_5                  ,CB_MIN_GAINSETUP                      ,CB_MAX_GAINSETUP                      },      // 336
  {CB_DEF_GAINSETUP_6_7                  ,CB_MIN_GAINSETUP                      ,CB_MAX_GAINSETUP                      },      // 337
  {CB_DEF_GAINSETUP_8_9                  ,CB_MIN_GAINSETUP                      ,CB_MAX_GAINSETUP                      },      // 338
  {CB_DEF_GAINSETUP_10_MOD               ,CB_MIN_GAINSETUP                      ,CB_MAX_GAINSETUP                      },      // 339
  {CB_DEF_HALIOS_CLOCK_CONTROL_REG       ,CB_MIN_HALIOS_CLOCK_CONTROL_REG       ,CB_MAX_HALIOS_CLOCK_CONTROL_REG       },      // 340
  {CB_DEF_ACTR_REG                       ,CB_MIN_ACTR_REG                       ,CB_MAX_ACTR_REG                       },      // 341
  {CB_DEF_PCO_PI_REGULATOR               ,CB_MIN_PCO_PI_REGULATOR               ,CB_MAX_PCO_PI_REGULATOR               },      // 342
  {CB_DEF_ICO1H                          ,CB_MIN_ICO1H                          ,CB_MAX_ICO1H                          },      // 343
  {CB_DEF_ICO1L                          ,CB_MIN_ICO1L                          ,CB_MAX_ICO1L                          },      // 344
  {CB_DEF_ICO2H                          ,CB_MIN_ICO2H                          ,CB_MAX_ICO2H                          },      // 345
  {CB_DEF_ICO2L                          ,CB_MIN_ICO2L                          ,CB_MAX_ICO2L                          },      // 346
  {CB_DEF_FOSC_LEDUL                     ,CB_MIN_FOSC_LEDUL                     ,CB_MAX_FOSC_LEDUL                     },      // 347
  {CB_DEF_INTCO                          ,CB_MIN_INTCO                          ,CB_MAX_INTCO                          },      // 348
  {CB_DEF_STANDBYTIMOUT                  ,CB_MIN_STANDBYTIMOUT                  ,CB_MAX_STANDBYTIMOUT                  },      // 349
  {CB_DEF_TEILENUMMERN_INDEX             ,CB_MIN_TEILENUMMERN_INDEX             ,CB_MAX_TEILENUMMERN_INDEX             },      // 350
  {cb_DEF_VARIANTE_g                     ,cb_MIN_VARIANTE_g                     ,cb_MAX_VARIANTE_g                     },      // 351 
  {CB_DEF_RS_SENSITIVITY_0               ,CB_MIN_RS_SENSITIVITY_0               ,CB_MAX_RS_SENSITIVITY_0               },      // 352
  {CB_DEF_RS_SENSITIVITY_1               ,CB_MIN_RS_SENSITIVITY_1               ,CB_MAX_RS_SENSITIVITY_1               },      // 353
  {CB_DEF_RS_SENSITIVITY_2               ,CB_MIN_RS_SENSITIVITY_2               ,CB_MAX_RS_SENSITIVITY_2               },      // 354
  {CB_DEF_RS_SENSITIVITY_3               ,CB_MIN_RS_SENSITIVITY_3               ,CB_MAX_RS_SENSITIVITY_3               },      // 355
  {CB_DEF_RS_SENSITIVITY_4               ,CB_MIN_RS_SENSITIVITY_4               ,CB_MAX_RS_SENSITIVITY_4               },      // 356
  {CB_DEF_RS_SENSITIVITY_5               ,CB_MIN_RS_SENSITIVITY_5               ,CB_MAX_RS_SENSITIVITY_5               },      // 357
  {CB_DEF_RS_SENSITIVITY_6               ,CB_MIN_RS_SENSITIVITY_6               ,CB_MAX_RS_SENSITIVITY_6               },      // 358
  {CB_DEF_RS_SENSITIVITY_7               ,CB_MIN_RS_SENSITIVITY_7               ,CB_MAX_RS_SENSITIVITY_7               },      // 359
  {CB_DEF_RS_SENSITIVITY_8               ,CB_MIN_RS_SENSITIVITY_8               ,CB_MAX_RS_SENSITIVITY_8               },      // 360
  {CB_DEF_MAXOVERWIPESENSITIVITY         ,CB_MIN_MAXOVERWIPESENSITIVITY         ,CB_MAX_MAXOVERWIPESENSITIVITY         },      // 361 
  {CB_DEF_STUFE1_OG                      ,CB_MIN_STUFE1_OG                      ,CB_MAX_STUFE1_OG                      },      // 362
  {CB_DEF_STUFE1_UG                      ,CB_MIN_STUFE1_UG                      ,CB_MAX_STUFE1_UG                      },      // 363
  {CB_DEF_EP_ST2_EPR_IN_ST2              ,CB_MIN_EP_ST2_EPR_IN_ST2              ,CB_MAX_EP_ST2_EPR_IN_ST2              },      // 364
  {CB_DEF_SCHWELLE_SCHWALL               ,CB_MIN_SCHWELLE_SCHWALL               ,CB_MAX_SCHWELLE_SCHWALL               },      // 365  
  {CB_DEF_ANSAMLUN_ADIT_OFFS             ,CB_MIN_ANSAMLUN_ADIT_OFFS             ,CB_MAX_ANSAMLUN_ADIT_OFFS             },      // 366
  {CB_DEF_DEC_INT_SP_OFF                 ,CB_MIN_DEC_INT_SP_OFF                 ,CB_MAX_DEC_INT_SP_OFF                 },      // 367
  {CB_DEF_DEC_STX_SPEICHER               ,CB_MIN_DEC_STX_SPEICHER               ,CB_MAX_DEC_STX_SPEICHER               },      // 368
  {CB_DEF_DEC_OVR_SPEICHER               ,CB_MIN_DEC_OVR_SPEICHER               ,CB_MAX_DEC_OVR_SPEICHER               },      // 369
  {CB_DEF_EMPF_FAKTOR_ST2_OFFS           ,CB_MIN_EMPF_FAKTOR_ST2_OFFS           ,CB_MAX_EMPF_FAKTOR_ST2_OFFS           },      // 370
  {CB_DEF_MAX_SIGNALLAENGE               ,CB_MIN_MAX_SIGNALLAENGE               ,CB_MAX_MAX_SIGNALLAENGE               },      // 371
  {CB_DEF_RB_STUFE1_WITH_INT_OG          ,CB_MIN_RB_STUFE1_WITH_INT_OG          ,CB_MAX_RB_STUFE1_WITH_INT_OG          },      // 372
  {CB_DEF_NACHWISCH_4_ST1_MIN            ,CB_MIN_NACHWISCH_4_ST1_MIN            ,CB_MAX_NACHWISCH_4_ST1_MIN            },      // 373
  {CB_DEF_NACHWISCH_3                    ,CB_MIN_NACHWISCH_3                    ,CB_MAX_NACHWISCH_3                    },      // 374
  {CB_DEF_NACHWISCH_2                    ,CB_MIN_NACHWISCH_2                    ,CB_MAX_NACHWISCH_2                    },      // 375
  {CB_DEF_RSEMPFFACTORSCALING            ,CB_MIN_RSEMPFFACTORSCALING            ,CB_MAX_RSEMPFFACTORSCALING            },      // 376    
  {CB_DEF_SCHLIEREN_FLAG                 ,CB_MIN_SCHLIEREN_FLAG                 ,CB_MAX_SCHLIEREN_FLAG                 },      // 377
  {CB_DEF_SIG_ANS_SCHW_OFFS              ,CB_MIN_SIG_ANS_SCHW_OFFS              ,CB_MAX_SIG_ANS_SCHW_OFFS              },      // 378
  {CB_DEF_STANDBYMODESCANTIME            ,CB_MIN_STANDBYMODESCANTIME            ,CB_MAX_STANDBYMODESCANTIME            },      // 379
  {CB_DEF_RAINNIGHTBITTHRS               ,CB_MIN_RAINNIGHTBITTHRS               ,CB_MAX_RAINNIGHTBITTHRS               },      // 380
  {CB_DEF_AMB_BASE_DAY_THRESHOLD         ,CB_MIN_AMB_BASE_DAY_THRESHOLD         ,CB_MAX_AMB_BASE_DAY_THRESHOLD         },      // 381
  {CB_DEF_AMB_BASE_NIGHT_THRESHOLD       ,CB_MIN_AMB_BASE_NIGHT_THRESHOLD       ,CB_MAX_AMB_BASE_NIGHT_THRESHOLD       },      // 382
  {CB_DEF_TUNNELDEBOUNCEFACTOR           ,CB_MIN_TUNNELDEBOUNCEFACTOR           ,CB_MAX_TUNNELDEBOUNCEFACTOR           },      // 383
  {CB_DEF_CUSTOMER_FW_SWA_SCALING        ,CB_MIN_CUSTOMER_FW_SWA_SCALING        ,CB_MAX_CUSTOMER_FW_SWA_SCALING        },      // 384
  {CB_DEF_CUSTOMER_IR_SWA_SCALING        ,CB_MIN_CUSTOMER_IR_SWA_SCALING        ,CB_MAX_CUSTOMER_IR_SWA_SCALING        },      // 385
  {CB_DEF_FW_BASE_DAY_THRESHOLD          ,CB_MIN_FW_BASE_DAY_THRESHOLD          ,CB_MAX_FW_BASE_DAY_THRESHOLD          },      // 386
  {CB_DEF_IR_BASE_DAY_THRESHOLD          ,CB_MIN_IR_BASE_DAY_THRESHOLD          ,CB_MAX_IR_BASE_DAY_THRESHOLD          },      // 387
  {CB_DEF_FW_BASE_NIGHT_THRESHOLD        ,CB_MIN_FW_BASE_NIGHT_THRESHOLD        ,CB_MAX_FW_BASE_NIGHT_THRESHOLD        },      // 388
  {CB_DEF_IR_BASE_NIGHT_THRESHOLD        ,CB_MIN_IR_BASE_NIGHT_THRESHOLD        ,CB_MAX_IR_BASE_NIGHT_THRESHOLD        },      // 389
  {CB_DEF_DAY_DELAY                      ,CB_MIN_DAY_DELAY                      ,CB_MAX_DAY_DELAY                      },      // 390
  {CB_DEF_NIGHT_DELAY                    ,CB_MIN_NIGHT_DELAY                    ,CB_MAX_NIGHT_DELAY                    },      // 391
  {CB_DEF_AFTERTUNNELDELAYOFFS           ,CB_MIN_AFTERTUNNELDELAYOFFS           ,CB_MAX_AFTERTUNNELDELAYOFFS           },      // 392    
  {CB_DEF_AUTOBAHN_ON_OFF                ,CB_MIN_AUTOBAHN_ON_OFF                ,CB_MAX_AUTOBAHN_ON_OFF                },      // 393  
  {CB_DEF_AUTOBAHN_DELAY_ON              ,CB_MIN_AUTOBAHN_DELAY_ON              ,CB_MAX_AUTOBAHN_DELAY_ON              },      // 394
  {CB_DEF_FRONTWASCHEN_AUTOBAHNDELAY     ,CB_MIN_FRONTWASCHEN_AUTOBAHNDELAY     ,CB_MAX_FRONTWASCHEN_AUTOBAHNDELAY     },      // 395  
  {CB_DEF_REGENLICHTSCHWELLE_LOW_HIGH    ,CB_MIN_REGENLICHTSCHWELLE_LOW_HIGH    ,CB_MAX_REGENLICHTSCHWELLE_LOW_HIGH    },      // 396  
  {CB_DEF_REGENLICHTSCHWELLE_ZEIT        ,CB_MIN_REGENLICHTSCHWELLE_ZEIT        ,CB_MAX_REGENLICHTSCHWELLE_ZEIT        },      // 397  
  {CB_DEF_TUNNELTHRESHOLDSCALING         ,CB_MIN_TUNNELTHRESHOLDSCALING         ,CB_MAX_TUNNELTHRESHOLDSCALING         },      // 398
  {CB_DEF_AMB_TUNNELTHRESHOLDSCALING     ,CB_MIN_AMB_TUNNELTHRESHOLDSCALING     ,CB_MAX_AMB_TUNNELTHRESHOLDSCALING     },      // 399
  {CB_DEF_REGULATION48THRESHOLD          ,CB_MIN_REGULATION48THRESHOLD          ,CB_MAX_REGULATION48THRESHOLD          },      // 400
  {CB_DEF_REGULATION48LIGHTONTIME        ,CB_MIN_REGULATION48LIGHTONTIME        ,CB_MAX_REGULATION48LIGHTONTIME        },      // 401
  {CB_DEF_VERYBRIGHTINTUNNELDELAY        ,CB_MIN_VERYBRIGHTINTUNNELDELAY        ,CB_MAX_VERYBRIGHTINTUNNELDELAY        },     // 402
  {CB_DEF_COMBINED_FW_AL_THRS            ,CB_MIN_COMBINED_FW_AL_THRS            ,CB_MAX_COMBINED_FW_AL_THRS            },     // 403  
  {CB_DEF_DYN_COMP_CCD_MINUS_1           ,CB_MIN_DYN_COMP_CCD_MINUS_1           ,CB_MAX_DYN_COMP_CCD_MINUS_1           },     // 404 
  {CB_DEF_DYN_COMP_CCD_MINUS_2           ,CB_MIN_DYN_COMP_CCD_MINUS_2           ,CB_MAX_DYN_COMP_CCD_MINUS_2           },     // 405  
  {CB_DEF_MAXTEMPERATUREOFFSETT          ,CB_MIN_MAXTEMPERATUREOFFSETT          ,CB_MAX_MAXTEMPERATUREOFFSETT          },      // 406   
  {CB_DEF_ASIC_AFSTHR_REG                ,CB_MIN_ASIC_AFSTHR_REG                ,CB_MAX_ASIC_AFSTHR_REG                },      // 407
  {CB_DEF_E2_RESERVED_I2                 ,CB_MIN_E2_RESERVED_I2                 ,CB_MAX_E2_RESERVED_I2                 },      // 408
  {CB_DEF_INC_SPEICHER                   ,CB_MIN_INC_SPEICHER                   ,CB_MAX_INC_SPEICHER                   },      // 409
  {CB_DEF_I2C_DEBUG_CONFIG               ,CB_MIN_I2C_DEBUG_CONFIG               ,CB_MAX_I2C_DEBUG_CONFIG               },      // 410
#ifdef ASIC_TEST
  {CB_DEF_ASIC_FRAME_01                 ,CB_MIN_ASIC_FRAME_01                 ,CB_MAX_ASIC_FRAME_01                 },      // 411
  {CB_DEF_ASIC_FRAME_02                 ,CB_MIN_ASIC_FRAME_02                 ,CB_MAX_ASIC_FRAME_02                 },      // 412
  {CB_DEF_ASIC_FRAME_03                 ,CB_MIN_ASIC_FRAME_03                 ,CB_MAX_ASIC_FRAME_03                 },      // 413
  {CB_DEF_ASIC_FRAME_04                 ,CB_MIN_ASIC_FRAME_04                 ,CB_MAX_ASIC_FRAME_04                 },      // 414
#endif
  {CB_DEF_SOFTWARESTAND_0                ,CB_MIN_SOFTWARESTAND_0                ,CB_MAX_SOFTWARESTAND_0                },      // 415
  {CB_DEF_SOFTWARESTAND_1                ,CB_MIN_SOFTWARESTAND_1                ,CB_MAX_SOFTWARESTAND_1                },      // 416
  {CB_DEF_SOFTWARESTAND_2                ,CB_MIN_SOFTWARESTAND_2                ,CB_MAX_SOFTWARESTAND_2                },      // 417
  {CB_DEF_SOFTWARESTAND_3                ,CB_MIN_SOFTWARESTAND_3                ,CB_MAX_SOFTWARESTAND_3                },       // 418    (Muss immer am Schluss sein!!!)

};
#pragma constseg=default               /* VDR_671 IAR 4xx part*/

const byte cab_SI_Transmission_Offsett[8] = {15,20,25,30,10,6,3,0}; /*definition of Korrekturfaktor Vorfeldempfanger offset*/

#else

extern const byte cab_SI_Transmission_Offsett[8];


extern const byte __far cb_EEPROMDataDefaultMinMax_g[cb_NumberofEEPROMCells_g][3];
#define EXTERN  extern
#endif

#define CB_OFFSETT_ADDIT_NOM  64

typedef struct {
  
  byte EEKodierbyte2_g;               /* 256 fest*/
  byte EEKodierbyte1_g;               /* 257 fest*/
  byte EEKodierbyte0_g;               /* 258 fest */
  byte ALS1_4_Setting_g;              /* 259 fest */
  byte ALS5_6_INREC_Setting_g;        /* 260 */
  byte ASIC_DIAGV_g;                      /* 261 */
  word A_Factor_ALS1_g;               /* 262,263 */
  word A_Factor_ALS2_g;               /* 264,265 */
  word A_Factor_ALS3_g;               /* 266,267 */
  word A_Factor_ALS4_g;               /* 268,269 */
  word A_Factor_ALS5_g;               /* 270,271 */
  word A_Factor_ALS6_g;               /* 272,273 */
  word A_Factor_INREC_g;              /* 274,275 */
  byte B_Factor_Iref_Lo_Gain_Lo_g;    /* 276 */
  byte B_Factor_Iref_Lo_Gain_Hi_g;    /* 277 */
  byte B_Factor_Iref_Hi_Gain_Lo_g;    /* 278 */
  byte B_Factor_Iref_Hi_Gain_Hi_g;    /* 279 */
  word CRC_Checksum_calibration_g;    /* 280,281 */       
  byte Standby_rain_measurement_1_g;  /*282*/
  byte Standby_rain_measurement_2_g;  /*283*/
  byte Standby_rain_measurement_3_g;  /*284*/
  byte Standby_rain_measurement_4_g;  /*285*/
  byte Standby_rain_measurement_5_g;  /*286*/
  byte Standby_rain_measurement_6_g;  /*287*/
  byte ASIC_Sched_Config_g ;            /*288*/ 
  byte ASIC_LCTR_g ;                  /*289*/ 
  byte NO_RAIN_PRESENT_THRSH_HB_g ;            /*290*/ 
  byte NO_RAIN_PRESENT_THRSH_LB_g ;            /*291*/ 
  byte STBY_REGV_Imbalance_g ;            /*292*/ 
  byte STBY_REGV_HB_g ;            /*293*/ 
  byte STBY_REGV_LB_g ;            /*294*/ 
  byte STBY_DELTA_INTV_HB_g ;            /*295*/ 
  byte STBY_DELTA_INTV_LB_g ;            /*296*/ 
  byte RSControlFlags;                /*297*/
  byte EEPROM_Erase_Counter;          /*298  */ 
  byte HardwareStand[2];              /* 299, 300*/          
  byte Produktionsdaten[4];           /* 301, 302, 303, 304 */
  byte Fertigungsdatum[3];            /* 305, 306, 307*/ 
  byte Parameterstand;                /*308*/ 
  byte NAD;                           /*309*/
  byte IDFSs_01;                      /*310*/
  byte IDRLSs_01;                     /*311*/
  byte IDBCM1_LIN1_01;                /*312*/
  byte IDWWSs_01;                     /*313*/
  byte IDSOSES_01 ;                   /*314*/ 
  byte ASIC_RCTR_REG_g ;              /*315*/ 
  byte ASIC_RFCTR_REG_g ;             /*316*/ 
  byte Error_Active_1_g ;             /*317*/   
  byte Error_Active_2_g ;             /*318*/   
  byte Error_Active_3_g ;             /*319*/   
  byte WatchdogResetCounter;          /*320*/  
  byte E2_Sensor_Error1_g;            /*321*/
  byte E2_Sensor_Error2_g;            /*322*/
  byte E2_Sensor_Error3_g;            /*323*/
  byte E2_Sensor_Error4_g;            /*324*/ 
  byte E2_Sensor_Error5_g;            /*325*/
  byte E2_Sensor_Error6_g;            /*326*/  
  byte IncidentCounter1_g;            /*327*/  
  byte IncidentCounter2_g;            /*328*/  
  byte IncidentCounter3_g;            /*329*/  
  byte IncidentCounter4_g;            /*330*/  
  byte IncidentCounter5_g;            /*331*/  
  byte IncidentCounter6_g;            /*332*/  
  byte IncidentCounter7_g;            /*333*/ 
  byte RS_GainSetupArray[6];          /*334,335,336,337,338,339*/    
  byte HALIOS_Clock_Control_Reg_g;    /*340*/
  byte ACTR_Reg_g;                    /*341*/
  byte PCO_PI_Regulator_g;            /*342*/
  byte ICO1H_g;                       /*343*/  
  byte ICO1L_g;                       /*344*/  
  byte ICO2H_g;                       /*345*/  
  byte ICO2L_g;                       /*346*/  
  byte FOSC_LEDUL_g;                  /*347*/ 
  byte INTCO_g;                       /*348*/  
  byte StandbyTimout;                 /*349*/ 
  byte Teilenummerindex;              /*350*/
  byte LIN_2_0_Variant_ID;            /*351*/ 
  byte RS_Sensitivity[9];             /*352,353,354,355,356,357,358,359,360*/            
  byte MaxOverwipeSensitivity;        /*361*/
  byte Stufe1_OG;                     /*362*/
  byte Stufe1_UG;                     /*363*/
  byte Ep_St2_Epr_In_St2;             /*364*/
  byte Schwelle_Schwall;              /*365*/  
  byte CW_AnsamlungAdditOffset;       /*366*/ 
  byte dec_Int_Sp_off;                /*367*/
  byte Dec_Stx_Speicher;              /*368*/
  byte dec_Ovr_Speicher;              /*369*/ 
  byte Empf_Faktor_ST2_Offs;          /*370*/
  byte Max_Signallaenge;              /*371*/
  byte rb_Stufe1_with_Int_og;         /*372*/
  byte Nachwisch_4_ST1_min;           /*373*/
  byte Nachwisch_3;                   /*374*/
  byte Nachwisch_2;                   /*375*/
  byte RSEmpfFactorScaling;           /*376*/   
  byte SchlierenFlag1;                /*377*/
  byte sig_ans_schw_offs;             /*378*/  
  byte StandbyModeScanTime_g;         /*379*/ 
  byte RainNightBitThrs_g;            /*380*/
  byte Amb_Base_Day_Threshold;        /*381*/
  byte Amb_Base_Night_Threshold;      /*382*/   
  byte TunnelDebounceFactor;          /*383*/                           
  byte Customer_FW_SWA_Scaling;       /*384*/
  byte Customer_IR_SWA_Scaling;       /*385*/
  byte FW_Base_Day_Threshold;         /*386*/
  byte IR_Base_Day_Threshold;         /*387*/
  byte FW_Base_Night_Threshold;       /*388*/
  byte IR_Base_Night_Threshold;       /*389*/    
  byte Day_Delay;                     /*390*/
  byte Night_Delay;                   /*391*/
  byte AfterTunnelDelayOffs;          /*392*/ 
  byte p_v_autobahn_on_off_g;         /*393*/
  byte p_t_autobahn_delay_on_g;       /*394*/
  byte Frontwaschen_Autobahndelay_g;    /*395*/  
  byte p_n_regenlichtschwelle_low_high_g;/*396*/ 
  byte p_n_regenlichtschwelle_Zeit_g;   /*397*/ 
  byte TunnelThresholdScaling_g;      /*398*/ 
  byte Amb_TunnelThresholdScaling_g;  /*399*/ 
  byte Regulation48Threshold_g;       /*400*/
  byte Regulation48LightOnTime_g;     /*401*/ 
  byte VeryBrightInTunnelDelay_g;     /*402*/ 
  byte Combined_FW_AL_THRs_g;         /*403*/ 
  byte DYN_COMP_CCD_MINUS_1_g;        /*404*/  
  byte DYN_COMP_CCD_MINUS_2_g;        /*405*/
  byte maxTemperatureOffsett_g;       /*406*/ 
  byte ASIC_AFSTHR_REG_g;              /*407*/ 
  byte GainOffsetE2_g;              /*408*/ 
  byte cb_inc_speicher_g;              /*409*/ 
  byte I2C_Debug_Config_g;            /*410*/ 

#ifdef ASIC_TEST
  byte ASIC_Frame_01_g;               /*411*/ 
  byte ASIC_Frame_02_g;               /*412*/ 
  byte ASIC_Frame_03_g;               /*413*/ 
  byte ASIC_Frame_04_g;               /*414*/ 
#endif
  
  byte SoftwareStand[4];              /* 415,416,417,418 */ 
  
} s_rb_I2CEEPROMStruct_g;






// Byte 44 CounterForWatchdogreset
// Byte 60 FehlerBild2!
// Byte 61 FehlerBild1!
// Byte 62 ASIC Mode
// Byte 63 ASIC Clock


/* PRQA S 750 6 *//*<< 0750:union needed to reduce RAM usage >>*/
typedef union {
  unsigned char _c[cb_NumberofEEPROMCells_g];
  s_rb_I2CEEPROMStruct_g I2CEEPROMStruct;
} s_rb_I2CEEPROMStruct_buff_g;


#define cb_NUMBER_OF_PROD_DATA_g 12
#define cb_PROD_DATA_START_ADRESS_g (498-256)

/* PRQA S 3116,0759 4*//*<< 3116:#pragma needed for IAR compiler and MISRA, 0759:union needed to reduce RAM usage >>*/

EXTERN  s_rb_I2CEEPROMStruct_buff_g I2C_EEPROM_Struct;
EXTERN  byte rab_EEPROM_ProductionData_g[cb_NUMBER_OF_PROD_DATA_g];

#define rb_Kodierbyte0_g                                I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte0_g //Address 128
#define rb_Kodierbyte1_g                                I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte1_g //Address 129
#define rb_Kodierbyte2_g                                I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte2_g //Address 130
#define rb_ALS1_4_Setting_g                             I2C_EEPROM_Struct.I2CEEPROMStruct.ALS1_4_Setting_g //Address 131
#define rb_ALS5_6_INREC_Setting_g                       I2C_EEPROM_Struct.I2CEEPROMStruct.ALS5_6_INREC_Setting_g //Address 132
#define rb_ASIC_DIAGV_g                                 I2C_EEPROM_Struct.I2CEEPROMStruct.ASIC_DIAGV_g //Address 133
#define rw_A_Factor_ALS1_g                              I2C_EEPROM_Struct.I2CEEPROMStruct.A_Factor_ALS1_g //Address 134,135
#define rw_A_Factor_ALS2_g                              I2C_EEPROM_Struct.I2CEEPROMStruct.A_Factor_ALS2_g //Address 136,137
#define rw_A_Factor_ALS3_g                              I2C_EEPROM_Struct.I2CEEPROMStruct.A_Factor_ALS3_g //Address 138,139
#define rw_A_Factor_ALS4_g                              I2C_EEPROM_Struct.I2CEEPROMStruct.A_Factor_ALS4_g //Address 140,141
#define rw_A_Factor_ALS5_g                              I2C_EEPROM_Struct.I2CEEPROMStruct.A_Factor_ALS5_g //Address 142,143
#define rw_A_Factor_ALS6_g                              I2C_EEPROM_Struct.I2CEEPROMStruct.A_Factor_ALS6_g //Address 144,145
#define rw_A_Factor_INREC_g                             I2C_EEPROM_Struct.I2CEEPROMStruct.A_Factor_INREC_g //Address 146,147
#define rb_B_Factor_Iref_Lo_Gain_Lo_g                   I2C_EEPROM_Struct.I2CEEPROMStruct.B_Factor_Iref_Lo_Gain_Lo_g //Address 148
#define rb_B_Factor_Iref_Lo_Gain_Hi_g                   I2C_EEPROM_Struct.I2CEEPROMStruct.B_Factor_Iref_Lo_Gain_Hi_g //Address 149
#define rb_B_Factor_Iref_Hi_Gain_Lo_g                   I2C_EEPROM_Struct.I2CEEPROMStruct.B_Factor_Iref_Hi_Gain_Lo_g //Address 150
#define rb_B_Factor_Iref_Hi_Gain_Hi_g                   I2C_EEPROM_Struct.I2CEEPROMStruct.B_Factor_Iref_Hi_Gain_Hi_g //Address 151
#define rb_CRC_Checksum_calibration_g                   I2C_EEPROM_Struct.I2CEEPROMStruct.CRC_Checksum_calibration_g //Address 152,153
#define rb_Standby_rain_measurement_1_g                 I2C_EEPROM_Struct.I2CEEPROMStruct.Standby_rain_measurement_1_g // Address 154
#define rb_Standby_rain_measurement_2_g                 I2C_EEPROM_Struct.I2CEEPROMStruct.Standby_rain_measurement_2_g // Address 155
#define rb_Standby_rain_measurement_3_g                 I2C_EEPROM_Struct.I2CEEPROMStruct.Standby_rain_measurement_3_g // Address 156
#define rb_Standby_rain_measurement_4_g                 I2C_EEPROM_Struct.I2CEEPROMStruct.Standby_rain_measurement_4_g // Address 157
#define rb_Standby_rain_measurement_5_g                 I2C_EEPROM_Struct.I2CEEPROMStruct.Standby_rain_measurement_5_g // Address 158
#define rb_Standby_rain_measurement_6_g                 I2C_EEPROM_Struct.I2CEEPROMStruct.Standby_rain_measurement_6_g // Address 159
#define rb_ASIC_Sched_Config_g                          I2C_EEPROM_Struct.I2CEEPROMStruct.ASIC_Sched_Config_g  //  Address 160
#define rb_ASIC_LCTR_g                                  I2C_EEPROM_Struct.I2CEEPROMStruct.ASIC_LCTR_g  //  Address 161
#define CW_NO_RAIN_PRESENT_THRSH_HB_g                   I2C_EEPROM_Struct.I2CEEPROMStruct.NO_RAIN_PRESENT_THRSH_HB_g  //  Address 162
#define CW_NO_RAIN_PRESENT_THRSH_LB_g                   I2C_EEPROM_Struct.I2CEEPROMStruct.NO_RAIN_PRESENT_THRSH_LB_g  //  Address 163
#define rb_STBY_REGV_Imbalance_g                        I2C_EEPROM_Struct.I2CEEPROMStruct.STBY_REGV_Imbalance_g  //  Address 164
#define rw_STBY_REGV_HB_g                               I2C_EEPROM_Struct.I2CEEPROMStruct.STBY_REGV_HB_g  //  Address 165
#define rw_STBY_REGV_LB_g                               I2C_EEPROM_Struct.I2CEEPROMStruct.STBY_REGV_LB_g  //  Address 166
#define rw_STBY_DELTA_INTV_HB_g                         I2C_EEPROM_Struct.I2CEEPROMStruct.STBY_DELTA_INTV_HB_g  //  Address 167
#define rw_STBY_DELTA_INTV_LB_g                         I2C_EEPROM_Struct.I2CEEPROMStruct.STBY_DELTA_INTV_LB_g  //  Address 168
#define rb_RSControlFlags_g                             I2C_EEPROM_Struct.I2CEEPROMStruct.RSControlFlags  // Address 169
#define rb_EEPROM_Erase_Counter_g                       I2C_EEPROM_Struct.I2CEEPROMStruct.EEPROM_Erase_Counter // Address 170
#define rab_HardwareStand_g(a)                          (I2C_EEPROM_Struct.I2CEEPROMStruct.HardwareStand[(a)])// Address 171,172
#define rab_Produktionsdaten_g(a)                       (I2C_EEPROM_Struct.I2CEEPROMStruct.Produktionsdaten[(a)])//Address 173,174,175,176
#define rab_Fertigungsdatum_g(a)                        (I2C_EEPROM_Struct.I2CEEPROMStruct.Fertigungsdatum[(a)])//Address 177,178,179
#define rb_TeilenummerindexE2_g                         I2C_EEPROM_Struct.I2CEEPROMStruct.Parameterstand //Address 180
#define rb_NAD_g                                        I2C_EEPROM_Struct.I2CEEPROMStruct.NAD //Address 181
#define rb_IDFSs_01_g                                   I2C_EEPROM_Struct.I2CEEPROMStruct.IDFSs_01 //Address 182
#define rb_IDRLSs_01_g                                  I2C_EEPROM_Struct.I2CEEPROMStruct.IDRLSs_01 //Address 183
#define rb_IDBCM1_LIN1_01_g                             I2C_EEPROM_Struct.I2CEEPROMStruct.IDBCM1_LIN1_01 //Address 184
#define rb_IDWWSs_01_g                                  I2C_EEPROM_Struct.I2CEEPROMStruct.IDWWSs_01 //Address 185
#define rb_IDSOSES_01_g                                 I2C_EEPROM_Struct.I2CEEPROMStruct.IDSOSES_01  //  Address 186
#define rb_ASIC_RCTR_REG_g                              I2C_EEPROM_Struct.I2CEEPROMStruct.ASIC_RCTR_REG_g  //  Address 187
#define rb_ASIC_RFCTR_REG_g                             I2C_EEPROM_Struct.I2CEEPROMStruct.ASIC_RFCTR_REG_g  //  Address 188
#define rb_Error_Active_1_g                             I2C_EEPROM_Struct.I2CEEPROMStruct.Error_Active_1_g  //  Address 189
#define rb_Error_Active_2_g                             I2C_EEPROM_Struct.I2CEEPROMStruct.Error_Active_2_g  //  Address 190
#define rb_Error_Active_3_g                             I2C_EEPROM_Struct.I2CEEPROMStruct.Error_Active_3_g  //  Address 191
#define rb_WatchdogResetCounter_g                       I2C_EEPROM_Struct.I2CEEPROMStruct.WatchdogResetCounter  //  Address 192
#define rb_E2_Sensor_Error1_g                           I2C_EEPROM_Struct.I2CEEPROMStruct.E2_Sensor_Error1_g //  Address 193
#define rb_E2_Sensor_Error2_g                           I2C_EEPROM_Struct.I2CEEPROMStruct.E2_Sensor_Error2_g //  Address 194
#define rb_E2_Sensor_Error3_g                           I2C_EEPROM_Struct.I2CEEPROMStruct.E2_Sensor_Error3_g //  Address 195
#define rb_E2_Sensor_Error4_g                           I2C_EEPROM_Struct.I2CEEPROMStruct.E2_Sensor_Error4_g //  Address 196
#define rb_E2_Sensor_Error5_g                           I2C_EEPROM_Struct.I2CEEPROMStruct.E2_Sensor_Error5_g //  Address 197
#define rb_E2_Sensor_Error6_g                           I2C_EEPROM_Struct.I2CEEPROMStruct.E2_Sensor_Error6_g //  Address 198
#define rb_IncidentCounter1_g 				I2C_EEPROM_Struct.I2CEEPROMStruct.IncidentCounter1_g  //  Address 199
#define rb_IncidentCounter2_g 			        I2C_EEPROM_Struct.I2CEEPROMStruct.IncidentCounter2_g  //  Address 200
#define rb_IncidentCounter3_g 				I2C_EEPROM_Struct.I2CEEPROMStruct.IncidentCounter3_g  //  Address 201
#define rb_IncidentCounter4_g 				I2C_EEPROM_Struct.I2CEEPROMStruct.IncidentCounter4_g  //  Address 202
#define rb_IncidentCounter5_g 				I2C_EEPROM_Struct.I2CEEPROMStruct.IncidentCounter5_g  //  Address 203
#define rb_IncidentCounter6_g 				I2C_EEPROM_Struct.I2CEEPROMStruct.IncidentCounter6_g  //  Address 204
#define rb_IncidentCounter7_g 				I2C_EEPROM_Struct.I2CEEPROMStruct.IncidentCounter7_g  //  Address 205
/* PRQA S 3453 1*/ /*<< Function type is required by MISRA, but unions are already used! >>*/
#define rab_RS_GainSetupArray(a)                        ((((I2C_EEPROM_Struct.I2CEEPROMStruct.RS_GainSetupArray[((a)/2)])<<(((a)&0x01)*4))&0xF0)|((I2C_EEPROM_Struct.I2CEEPROMStruct.RS_GainSetupArray[5])&0x0F)) //  Address 206,207,208,209,210,211
#define rb_HALIOS_Clock_Control_Reg_g 			I2C_EEPROM_Struct.I2CEEPROMStruct.HALIOS_Clock_Control_Reg_g  //  Address 212
#define rb_ACTR_Reg_g					I2C_EEPROM_Struct.I2CEEPROMStruct.ACTR_Reg_g  //  Address 213
#define rb_PCO_PI_Regulator_g				I2C_EEPROM_Struct.I2CEEPROMStruct.PCO_PI_Regulator_g  //  Address 214
#define rb_ICO1H_g					I2C_EEPROM_Struct.I2CEEPROMStruct.ICO1H_g  //  Address 215
#define rb_ICO1L_g					I2C_EEPROM_Struct.I2CEEPROMStruct.ICO1L_g  //  Address 216
#define rb_ICO2H_g					I2C_EEPROM_Struct.I2CEEPROMStruct.ICO2H_g  //  Address 217
#define rb_ICO2L_g					I2C_EEPROM_Struct.I2CEEPROMStruct.ICO2L_g  //  Address 218
#define rb_FOSC_LEDUL_g					I2C_EEPROM_Struct.I2CEEPROMStruct.FOSC_LEDUL_g  //  Address 219
#define rb_INTCO_g       				I2C_EEPROM_Struct.I2CEEPROMStruct.INTCO_g  //  Address 220
#define rb_StandbyTimout_g                              (I2C_EEPROM_Struct.I2CEEPROMStruct.StandbyTimout & 0x07) //  Address 221
#define rb_SW_TeilenummerindexE2_g                      I2C_EEPROM_Struct.I2CEEPROMStruct.Teilenummerindex //  Address 222
#define rb_LIN_2_0_Variant_ID_g                         I2C_EEPROM_Struct.I2CEEPROMStruct.LIN_2_0_Variant_ID //  Address 223
#define rab_RS_Sensitivity_g                            I2C_EEPROM_Struct.I2CEEPROMStruct.RS_Sensitivity  //  Address 224,225,226,227,228,229,230,231,232
#define rb_MaxOverwipeSensitivity_g                	(I2C_EEPROM_Struct.I2CEEPROMStruct.MaxOverwipeSensitivity&0x1F) //  Address 233
#define rb_Stufe1_OG_g                              	I2C_EEPROM_Struct.I2CEEPROMStruct.Stufe1_OG //  Address 234
#define rb_Stufe1_UG_g                              	I2C_EEPROM_Struct.I2CEEPROMStruct.Stufe1_UG //  Address 235
#define rb_Ep_St2_Epr_In_St2_g                          I2C_EEPROM_Struct.I2CEEPROMStruct.Ep_St2_Epr_In_St2 //  Address 236
#define rb_Schwelle_Schwall_g                           I2C_EEPROM_Struct.I2CEEPROMStruct.Schwelle_Schwall //  Address 237
#define rb_CW_AnsamlungAdditOffsett_g                   I2C_EEPROM_Struct.I2CEEPROMStruct.CW_AnsamlungAdditOffset //  Address 238
#define rb_dec_Int_Sp_off_g                             (I2C_EEPROM_Struct.I2CEEPROMStruct.dec_Int_Sp_off & 0x1F)  //  Address 239   
#define rb_Dec_Stx_Speicher_g                           I2C_EEPROM_Struct.I2CEEPROMStruct.Dec_Stx_Speicher //  Address 240   
#define rb_dec_Ovr_Speicher_g                           ((I2C_EEPROM_Struct.I2CEEPROMStruct.dec_Ovr_Speicher)&0x1F) //  Address 241  
#define rb_Empf_Faktor_ST2_Offs_g                       (I2C_EEPROM_Struct.I2CEEPROMStruct.Empf_Faktor_ST2_Offs &0x3F) //  Address 242  
#define rb_Max_Signallaenge_g                           I2C_EEPROM_Struct.I2CEEPROMStruct.Max_Signallaenge //  Address 243  
#define rb_Stufe1_with_Int_og_g                         I2C_EEPROM_Struct.I2CEEPROMStruct.rb_Stufe1_with_Int_og //  Address 244  
#define rb_Nachwisch_4_g                                ((I2C_EEPROM_Struct.I2CEEPROMStruct.Nachwisch_4_ST1_min)& 0x1F) //  Address 245  
#define rb_Nachwisch_3_g                                (I2C_EEPROM_Struct.I2CEEPROMStruct.Nachwisch_3&0x7F) //  Address 246  
#define rb_Nachwisch_2_g                                (I2C_EEPROM_Struct.I2CEEPROMStruct.Nachwisch_2 & 0x7F) //  Address 247  
#define rb_RSEmpfFactorScaling_g                        (I2C_EEPROM_Struct.I2CEEPROMStruct.RSEmpfFactorScaling&0x0f) //  Address 248  
#define rb_SchlierenFlag1_g              		        I2C_EEPROM_Struct.I2CEEPROMStruct.SchlierenFlag1 //  Address 249  
#define rb_sig_ans_schw_offs_g                          I2C_EEPROM_Struct.I2CEEPROMStruct.sig_ans_schw_offs //  Address 250  
#define rb_StandbyModeScanTime_g                        I2C_EEPROM_Struct.I2CEEPROMStruct.StandbyModeScanTime_g //  Address 251  
#define rb_RainNightBitThrs_g                           I2C_EEPROM_Struct.I2CEEPROMStruct.RainNightBitThrs_g //  Address 252  
#define rb_Amb_Base_Day_Threshold_g                     I2C_EEPROM_Struct.I2CEEPROMStruct.Amb_Base_Day_Threshold //  Address 253  
#define rb_Amb_Base_Night_Threshold_g                   I2C_EEPROM_Struct.I2CEEPROMStruct.Amb_Base_Night_Threshold //  Address 254
#define rb_TunnelDebounceFactor_g                       I2C_EEPROM_Struct.I2CEEPROMStruct.TunnelDebounceFactor  //  Address 255
#define rb_Customer_FW_SWA_Scaling_g                    I2C_EEPROM_Struct.I2CEEPROMStruct.Customer_FW_SWA_Scaling  //  Address 256
#define rb_Customer_IR_SWA_Scaling_g                    I2C_EEPROM_Struct.I2CEEPROMStruct.Customer_IR_SWA_Scaling //  Address 257
#define rb_FW_Base_Day_Threshold_g                      I2C_EEPROM_Struct.I2CEEPROMStruct.FW_Base_Day_Threshold //  Address 258
#define rb_IR_Base_Day_Threshold_g                      I2C_EEPROM_Struct.I2CEEPROMStruct.IR_Base_Day_Threshold //  Address 259
#define rb_FW_Base_Night_Threshold_g                    I2C_EEPROM_Struct.I2CEEPROMStruct.FW_Base_Night_Threshold //  Address 260
#define rb_IR_Base_Night_Threshold_g                    I2C_EEPROM_Struct.I2CEEPROMStruct.IR_Base_Night_Threshold //  Address 261
#define rb_Day_Delay_g                                  I2C_EEPROM_Struct.I2CEEPROMStruct.Day_Delay //  Address 262
#define rb_Night_Delay_g                                I2C_EEPROM_Struct.I2CEEPROMStruct.Night_Delay //  Address 263
#define rb_AfterTunnelDelayOffs_g                       (((((word)I2C_EEPROM_Struct.I2CEEPROMStruct.AfterTunnelDelayOffs*25))>120)? ((((word)I2C_EEPROM_Struct.I2CEEPROMStruct.AfterTunnelDelayOffs*25)-120)>>1):0) //  Address 264
#define rb_p_v_autobahn_on_off_g                        (I2C_EEPROM_Struct.I2CEEPROMStruct.p_v_autobahn_on_off_g) //  Address 265
#define rb_p_t_autobahn_delay_on_g                      ((I2C_EEPROM_Struct.I2CEEPROMStruct.p_t_autobahn_delay_on_g)&0x1F) //  Address 266
#define rb_Frontwaschen_Autobahndelay_g                 (I2C_EEPROM_Struct.I2CEEPROMStruct.Frontwaschen_Autobahndelay_g) //  Address 267 ;
#define rb_p_n_regenlichtschwelle_low_high_g            (I2C_EEPROM_Struct.I2CEEPROMStruct.p_n_regenlichtschwelle_low_high_g & 0x3F)  //  Address 268
#define rb_p_n_regenlichtschwelle_Zeit_g                (I2C_EEPROM_Struct.I2CEEPROMStruct.p_n_regenlichtschwelle_Zeit_g)  //  Address 269
#define rb_TunnelThresholdScaling_g                     I2C_EEPROM_Struct.I2CEEPROMStruct.TunnelThresholdScaling_g  //  Address 270
#define rb_Amb_TunnelThresholdScaling_g                 ((I2C_EEPROM_Struct.I2CEEPROMStruct.Amb_TunnelThresholdScaling_g&0x0F)+4)  //  Address 271
#define cb_Regulation48LightOnTime_g                    I2C_EEPROM_Struct.I2CEEPROMStruct.Regulation48LightOnTime_g
#define rb_Regulation48Threshold_g                      ((I2C_EEPROM_Struct.I2CEEPROMStruct.Regulation48Threshold_g>>4)*10) /*(about 810 lux---Value corrected for 80% transmission through glass)---(Previous Value about 1250 lux)----KI*/
#define rb_Regulation48_FW_Threshold_g                  ((I2C_EEPROM_Struct.I2CEEPROMStruct.Regulation48Threshold_g & 0x0f) *10)  /*(FW Diode Threshold----to avoid unnecessary switching ON of Lights)----KI*/
#define rb_VeryBrightInTunnelDelay_g                    (I2C_EEPROM_Struct.I2CEEPROMStruct.VeryBrightInTunnelDelay_g)  //  Address 274
#define rb_Combined_FW_AL_THRs_g                        (I2C_EEPROM_Struct.I2CEEPROMStruct.Combined_FW_AL_THRs_g)  //  Address 275
#define rb_DYN_COMP_CCD_MINUS_1_g                       (I2C_EEPROM_Struct.I2CEEPROMStruct.DYN_COMP_CCD_MINUS_1_g) //  Address 276
#define rb_DYN_COMP_CCD_MINUS_2_g                       (I2C_EEPROM_Struct.I2CEEPROMStruct.DYN_COMP_CCD_MINUS_2_g) //  Address 277
#define rb_maxTemperatureOffsett_g                      (I2C_EEPROM_Struct.I2CEEPROMStruct.maxTemperatureOffsett_g ) //  Address 278   
#define rb_ASIC_AFSTHR_REG_g                            (I2C_EEPROM_Struct.I2CEEPROMStruct.ASIC_AFSTHR_REG_g ) //  Address 279   
#define rb_GainOffsetE2_g                               (I2C_EEPROM_Struct.I2CEEPROMStruct.GainOffsetE2_g ) //  Address 280   
#define rb_inc_int_speicher_g                           ((I2C_EEPROM_Struct.I2CEEPROMStruct.cb_inc_speicher_g )>>4) //  Address 281   
#define rb_inc_ovr_speicher_g                           ((I2C_EEPROM_Struct.I2CEEPROMStruct.cb_inc_speicher_g )& 0x0F) //  Address 281  

#define rb_I2C_Debug_Config_g                           (I2C_EEPROM_Struct.I2CEEPROMStruct.I2C_Debug_Config_g ) //  Address 282  

#ifdef ASIC_TEST
#define rb_ASIC_Frame_01_g                               I2C_EEPROM_Struct.I2CEEPROMStruct.ASIC_Frame_01_g //Address 182
#define rb_ASIC_Frame_02_g                               I2C_EEPROM_Struct.I2CEEPROMStruct.ASIC_Frame_02_g //Address 183
#define rb_ASIC_Frame_03_g                               I2C_EEPROM_Struct.I2CEEPROMStruct.ASIC_Frame_03_g //Address 184
#define rb_ASIC_Frame_04_g                               I2C_EEPROM_Struct.I2CEEPROMStruct.ASIC_Frame_04_g //Address 184
#endif

#define rab_SoftwareStand_g(a)                          (I2C_EEPROM_Struct.I2CEEPROMStruct.SoftwareStand[(a)]) //  Address 283,284,285,286 





#define rb_IR_TunnelThresholdScaling_g                  (((I2C_EEPROM_Struct.I2CEEPROMStruct.TunnelThresholdScaling_g&0xF0)>>4)+4) 
#define rb_FW_TunnelThresholdScaling_g                  ((I2C_EEPROM_Struct.I2CEEPROMStruct.TunnelThresholdScaling_g&0x0F)+4) 
#define rb_IntSpInc_Scal_g 				(I2C_EEPROM_Struct.I2CEEPROMStruct.SchlierenFlag1&0x03)
#define rb_OvrInc_Scal_g 				(((I2C_EEPROM_Struct.I2CEEPROMStruct.SchlierenFlag1)>>2)& 0x03)
#define rb_Speedreduct_g 				(((I2C_EEPROM_Struct.I2CEEPROMStruct.SchlierenFlag1)&0x10)> 0)
#define rbi_smearingreduct_upDown_Enabled               (((I2C_EEPROM_Struct.I2CEEPROMStruct.SchlierenFlag1)&0x20)> 0)
#define rbi_SpeicherDecAtDryWipe_g                      (((I2C_EEPROM_Struct.I2CEEPROMStruct.SchlierenFlag1)&0x40)> 0)
#define rbi_MeanPulsLengthOverwipeEmpfreduction_g       (((I2C_EEPROM_Struct.I2CEEPROMStruct.SchlierenFlag1)&0x80)> 0)
#define rb_p_t_rs_abfragezyklus_g                       (I2C_EEPROM_Struct.I2CEEPROMStruct.StandbyModeScanTime_g&0x1F)
#define rb_IntervalTimereductLimitFact_g                ((I2C_EEPROM_Struct.I2CEEPROMStruct.StandbyModeScanTime_g>>5)+1) /*VC0_58 byte to adjust interval calculation*/
#define p_lx_rs_day                                       (I2C_EEPROM_Struct.I2CEEPROMStruct.RainNightBitThrs_g&0x0F)
#define p_lx_rs_dawn                                      (I2C_EEPROM_Struct.I2CEEPROMStruct.RainNightBitThrs_g>>4)
/* Byte 0*/
#define rbi_Freewaylight_enabled_g                      ((I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte0_g & 0x01)>0)
#define rbi_RainLight_enabled_g                         ((I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte0_g & 0x02)>0)
#define rbi_StandbyFunction_enabled_g                   ((I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte0_g & 0x04)>0)
#define rb_LightSensorCoding_g                          ((I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte0_g & 0x38)>>3)
#define rbi_RainsensorDisabled_g                        ((I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte0_g & 0x40)>0)
/* Byte 1*/
#define rb_Regensensorposition_horizontal_g             ((I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte1_g & 0x01)>0)
#define rb_Regensensorposition_vertikal_g               ((I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte1_g & 0x02)>0)
#define rb_Parametersatz_Regensensorik_g                ((I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte1_g & 12)>>2)
#define rb_Gegenlaufwischeranlage_g                     ((I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte1_g & 0x10)>0)

#define rb_p_v_autobahn_on_g                            (rb_p_v_autobahn_on_off_g&0x0f)
#define rb_p_v_autobahn_off_g                           (rb_p_v_autobahn_on_off_g>>4)
#define rb_p_v_autobahn_off_kmph_g                      (40+(rb_p_v_autobahn_off_g*5))
#define rb_p_t_autobahn_delay_off_g                      ((I2C_EEPROM_Struct.I2CEEPROMStruct.Frontwaschen_Autobahndelay_g)&0x0F)
#define rb_p_t_frontwaschen_g                            ((I2C_EEPROM_Struct.I2CEEPROMStruct.Frontwaschen_Autobahndelay_g>>4)&0x0F)
#define rw_p_t_frontwaschen_Ausblend_g                   ((((word)(rb_p_t_frontwaschen_g)*1)+10)*20)
#define rb_p_t_lin_idle_g                                ((I2C_EEPROM_Struct.I2CEEPROMStruct.p_t_autobahn_delay_on_g>>cb_EEPROM_0X1529__POSITION_g)&0x07)
#define CW_LIN_E2_IDLE_TIMOUT                            ((rb_p_t_lin_idle_g*100)+200) /*VCO_31 new EEPROM definition*/
#define rb_p_t_tunnel_delay_g                            ((I2C_EEPROM_Struct.I2CEEPROMStruct.AfterTunnelDelayOffs >> 3)&0x03)

#define rb_DYN_COMP_CCD_MINUS_belowneg5_g               ((I2C_EEPROM_Struct.I2CEEPROMStruct.Amb_TunnelThresholdScaling_g&0xF0)>>4) /*VCO_061 new variable*/
#define rb_DYN_COMP_CCD_MINUS_neg5to10_g                ((I2C_EEPROM_Struct.I2CEEPROMStruct.DYN_COMP_CCD_MINUS_1_g&0xF0)>>4) /*VCO_061 new variable*/
#define rb_DYN_COMP_CCD_MINUS_10to25_g                  ((I2C_EEPROM_Struct.I2CEEPROMStruct.DYN_COMP_CCD_MINUS_1_g&0x0F)) /*VCO_061 new variable*/
#define rb_DYN_COMP_CCD_MINUS_25to40_g                  ((I2C_EEPROM_Struct.I2CEEPROMStruct.DYN_COMP_CCD_MINUS_2_g&0xF0)>>4) /*VCO_061 new variable*/
#define rb_DYN_COMP_CCD_MINUS_above40_g                 ((I2C_EEPROM_Struct.I2CEEPROMStruct.DYN_COMP_CCD_MINUS_2_g&0x0F)) /*VCO_061 new variable*/

#define rb_p_n_regenlichtschwelle_high_g                (I2C_EEPROM_Struct.I2CEEPROMStruct.p_n_regenlichtschwelle_low_high_g & 0x07)
#define rb_p_n_regenlichtschwelle_low_g                 ((I2C_EEPROM_Struct.I2CEEPROMStruct.p_n_regenlichtschwelle_low_high_g >>3)& 0x07)
/*VCO_31 new EEPROM definition*/
#define CB_AMBLIGHT_100lx                                (byte)5    /*value to adjust the lux based thresholds VDR_560 use new faktor for 20lx per digit*/
#define CB_ANBHIGH_TO_LOW_FAKT                            8

#define cb_WIPETHRESHOLD_RAINLIGHT_BRIGHT_KS_mg           (rb_p_n_regenlichtschwelle_high_g+9)
#define cb_WIPETHRESHOLD_RAINLIGHT_DARK_KS_mg             (rb_p_n_regenlichtschwelle_high_g+3)

#define cb_RAIN_ON_BRIGHTNESS_KS_g                     (byte)( (((I2C_EEPROM_Struct.I2CEEPROMStruct.p_n_regenlichtschwelle_Zeit_g&0x0f)*((5*CB_AMBLIGHT_100lx)/CB_ANBHIGH_TO_LOW_FAKT))+((word)(40*CB_AMBLIGHT_100lx)/CB_ANBHIGH_TO_LOW_FAKT)))
#define cw_RAIN_ON_DELAY_KS_g                             (((I2C_EEPROM_Struct.I2CEEPROMStruct.p_n_regenlichtschwelle_Zeit_g>>4)*100)+200)

#define cb_AUDI_KS_THRESHOLD_RS_NIGHT_MODE_mg             (CB_AMBLIGHT_100lx*(p_lx_rs_dawn+1))
#define cb_AUDI_KS_THRESHOLD_RS_DAY_MODE_mg               (CB_AMBLIGHT_100lx*(p_lx_rs_day+1))

#define CB_EEPROM_INCIDENT1_ADDRESS (327&0xFF)
#define rb_RainSensorIncidentCounter_g (rb_IncidentCounter1_g&0x0F )
#define rb_LightSensorIncidentCounter_g  (rb_IncidentCounter1_g>>4)
#define INREASE_RAIN_INCIDENT()  rb_IncidentCounter1_g+=1
#define INREASE_LIGHT_INCIDENT() rb_IncidentCounter1_g+=0x10
#define CB_EEPROM_INCIDENT2_ADDRESS (328&0xFF)
#define rb_CntProSeqIncidentCounter_g (rb_IncidentCounter2_g&0x0F )
#define rb_CntMemoryIncidentCounter_g  (rb_IncidentCounter2_g>>4)
#define INREASE_CNTPROSEQ_INCIDENT()  rb_IncidentCounter2_g+=1
#define INREASE_CNTMEMORY_INCIDENT() rb_IncidentCounter2_g+=0x10
#define CB_EEPROM_INCIDENT3_ADDRESS (329&0xFF)
#define rb_VoltSupplyIncidentCounter_g (rb_IncidentCounter3_g&0x0F )
#define rb_WDGIncidentCounter_g  (rb_IncidentCounter3_g>>4)
#define INREASE_VOLTSUPPLY_INCIDENT()  rb_IncidentCounter3_g+=1
#define INREASE_WDG_INCIDENT() rb_IncidentCounter3_g+=0x10
#define CB_EEPROM_INCIDENT4_ADDRESS (330&0xFF)
#define rb_ASICIncidentCounter_g (rb_IncidentCounter4_g&0x0F )
#define rb_CPUIncidentCounter_g  (rb_IncidentCounter4_g>>4)
#define INREASE_ASIC_INCIDENT()  rb_IncidentCounter4_g+=1
#define INREASE_CPU_INCIDENT() rb_IncidentCounter4_g+=0x10
#define CB_EEPROM_INCIDENT5_ADDRESS (331&0xFF)
#define rb_TempIncidentCounter_g (rb_IncidentCounter5_g&0x0F )
#define rb_HumIncidentCounter_g  (rb_IncidentCounter5_g>>4)
#define INREASE_TEMP_INCIDENT()  rb_IncidentCounter5_g+=1
#define INREASE_HUM_INCIDENT() rb_IncidentCounter5_g+=0x10
#define CB_EEPROM_INCIDENT6_ADDRESS (332&0xFF)
#define rb_DewPointIncidentCounter_g (rb_IncidentCounter6_g&0x0F )
#define rb_HT_COMIncidentCounter_g  (rb_IncidentCounter6_g>>4)
#define INREASE_DEWPOINT_INCIDENT()  rb_IncidentCounter6_g+=1
#define INREASE_HT_COM_INCIDENT() rb_IncidentCounter6_g+=0x10
#define STBY_REGV_HBYTE_ADDRESS (293&0xFF)
#define STBY_REGV_LBYTE_ADDRESS (294&0xFF)
#define STBY_DELTA_INTV_HBYTE_ADDRESS (295&0xFF)
#define STBY_DELTA_INTV_LBYTE_ADDRESS (296&0xFF)
#define GAINOFFSET_ADDRESS (byte)(408&0xFF)


/*VCO_31 values to write into EEPROM per service 0x2E*/
#define cb_EEPROM_0X1525__BYTES_g  1
#define cb_EEPROM_0X1525__ADDRESS_g 369
#define cb_EEPROM_0X1525__POSITION_g 5
#define cb_EEPROM_0X1525__MAX_g    3 /*VDR_468 was forgotten*/
#define cb_EEPROM_0X1525__MASK_g 0x60

#define cb_EEPROM_0X1526__BYTES_g  1
#define cb_EEPROM_0X1526__ADDRESS_g 379
#define cb_EEPROM_0X1526__POSITION_g 0
#define cb_EEPROM_0X1526__MAX_g 19
#define cb_EEPROM_0X1526__MASK_g 0x1F

#define cb_EEPROM_0X1527__BYTES_g  3
#define cb_EEPROM_0X1527_1__ADDRESS_g 393
#define cb_EEPROM_0X1527_1_On__MAX_g 5
#define cb_EEPROM_0X1527_1_Off__MAX_g 10
#define cb_EEPROM_0X1527_1__POSITION_g 0
#define cb_EEPROM_0X1527_1__MASK_g 0xFF

#define cb_EEPROM_0X1527_2__ADDRESS_g 394
#define cb_EEPROM_0X1527_2__POSITION_g 0
#define cb_EEPROM_0X1527_2__MAX_g 19
#define cb_EEPROM_0X1527_2__MASK_g 0x1F

#define cb_EEPROM_0X1527_3__ADDRESS_g 395
#define cb_EEPROM_0X1527_3__POSITION_g 0
#define cb_EEPROM_0X1527_3__MAX_g 10
#define cb_EEPROM_0X1527_3__MASK_g 0x0F

#define cb_EEPROM_0X1528__BYTES_g  1
#define cb_EEPROM_0X1528__ADDRESS_g 395
#define cb_EEPROM_0X1528__MAX_g 10
#define cb_EEPROM_0X1528__POSITION_g 4
#define cb_EEPROM_0X1528__MASK_g 0xF0

#define cb_EEPROM_0X1529__BYTES_g  1
#define cb_EEPROM_0X1529__ADDRESS_g 394
#define cb_EEPROM_0X1529__POSITION_g 5
#define cb_EEPROM_0X1529__MAX_g 4 /*max valeu for rb_p_t_lin_idle_g*/
#define cb_EEPROM_0X1529__MASK_g 0xE0

#define cb_EEPROM_0X152A__BYTES_g  1
#define cb_EEPROM_0X152A__ADDRESS_g 392
#define cb_EEPROM_0X152A__POSITION_g 3
#define cb_EEPROM_0X152A__MAX_g 3
#define cb_EEPROM_0X152A__MASK_g 0x18

#define cb_EEPROM_0X152B__BYTES_g  2
#define cb_EEPROM_0X152B_1__ADDRESS_g 396
#define cb_EEPROM_0X152B_1__POSITION_g 0
#define cb_EEPROM_0X152B_1_HighDelay_Max  6
#define cb_EEPROM_0X152B_1_LOWDelay_Max  7
#define cb_EEPROM_0X152B_1__MASK_g 0x3F

#define cb_EEPROM_0X152B_2__ADDRESS_g 397
#define cb_EEPROM_0X152B_2__POSITION_g 0
#define cb_EEPROM_0X152B_2_THRESH_Max  8
#define cb_EEPROM_0X152B_2_OFFDELAY_Max  8
#define cb_EEPROM_0X152B_2__MASK_g 0xFF

#define cb_EEPROM_0X152C__BYTES_g  1
#define cb_EEPROM_0X152C__ADDRESS_g 380
#define cb_EEPROM_0X152C__POSITION_g 0
#define cb_EEPROM_0X152C__MAX_g 0xFF
#define cb_EEPROM_0X152C__MASK_g 0xFF

/* betrachtung fur Wischanlage Parkposition unten*/
#define rb_SchwelleInWipeLow_g                          ((rb_Regensensorposition_horizontal_g == 0)&& \
  (rb_Regensensorposition_vertikal_g == 1))
#define rb_WiperAPillarParkposition_E2_g                ((rb_Regensensorposition_horizontal_g == 0)&& \
  (rb_Regensensorposition_vertikal_g == 1))
#define rb_RLTPositionnearParkposition_E2_g              ((rb_Regensensorposition_horizontal_g == 0)&& \
  (rb_Regensensorposition_vertikal_g == 1))

#define rb_SI_Transmission_Korrektur_g                  ((I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte1_g & 0xE0)>>5)


#define rb_Si_Transmission_1_g    (byte)((((word)(rb_550nm_Transmission_g + (cab_SI_Transmission_Offsett[rb_SI_Transmission_Korrektur_g]-15)) )*9)/(15)) 

#define rb_Si_Transmission_g            ((rb_Si_Transmission_1_g >= 5)?  rb_Si_Transmission_1_g: 5) /* VDR_796 */

/* Byte 2*/
#define rb_550nm_Transmission_g         (((I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte2_g & 0x0F)*5)+15)
#define rb_880nm_Transmission_g         ((((I2C_EEPROM_Struct.I2CEEPROMStruct.EEKodierbyte2_g & 0xF0)>>4)*5)+15)

#define rb_SI_880nmWavelenght_factor_g                 0xFF
#define rw_a_Correction_Inrec_g                        0xFF
#define rb_b_Correction_Inamb1_g                       0xFF
#define rb_b_Correction_Inrec_g                        0xFF
#define rw_a_Correction_Inamb2_g                        0xFF
#define rb_b_Correction_Inamb2_g                        0xFF
#define rw_a_Correction_Inamb1_g                        0xFF
#define rbi_ModulatorOff_ForINAMB1_meas_g               0xFF
#define rbi_LightSensorInactive_g                       0xFF

#define rb_2_5SecondsDelay_g                       ((I2C_EEPROM_Struct.I2CEEPROMStruct.StandbyTimout & 0xF8)>>3)

#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
#define rb_Single_Or_Double_Overwipe_dec    ( (I2C_EEPROM_Struct.I2CEEPROMStruct.single_or_double & 0x0F))
/*In the Following: Bit4,5,6,7 (0-7)*/ /*VDR_373*/
#define rb_OffsMaxOverwipeSensContWipSpd_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.single_or_double & 0xF0)>>4)
#endif














#define rb_rs_WINDOW_COMP_THRESHOLD_g           (((I2C_EEPROM_Struct.I2CEEPROMStruct.dec_Int_Sp_off & 0xE0)>>4) + 18)

#define rbi_I2C_OUTPUT_Enabled_g                    ((I2C_EEPROM_Struct.I2CEEPROMStruct.MaxOverwipeSensitivity&0x40)>0)
#define rbi_PWM_OUTPUT_Enabled_g                    ((I2C_EEPROM_Struct.I2CEEPROMStruct.MaxOverwipeSensitivity&0x80)>0)

#define rb_delay_depressed_park_pointer_g           (((I2C_EEPROM_Struct.I2CEEPROMStruct.dec_Ovr_Speicher)&0x60)>>5)


/* PRQA S 3453 5*/ /*<< Function type is required by MISRA, but unions are already used! >>*/
/*VDR_131 Following 4 lines correct MISRA Rule 96*/


#define rb_Mean_HighwayLightOnSpeed_g        ((rb_p_v_autobahn_on_g*10)+100)
#define rw_TimeToReachFastHighwayMode_g      ((((word)(rb_p_t_autobahn_delay_on_g*1)+1)*20))
#define rw_TimeToReachNormalSpeedMode_g      ((((word)(rb_p_t_autobahn_delay_off_g*10)+50)*20))

#define rb_TimeForAfterwipeThrs_DelayScal_g  (((I2C_EEPROM_Struct.I2CEEPROMStruct.Empf_Faktor_ST2_Offs & 0xC0)>>6)+1)
#define rb_ST1_Nachwisch_min_g               (((I2C_EEPROM_Struct.I2CEEPROMStruct.Nachwisch_4_ST1_min)& 0x60)>>5)
#define rb_AfterTunnelThrsIsNightThrs_g      ((I2C_EEPROM_Struct.I2CEEPROMStruct.Nachwisch_2 & 0x80) > 0)
#define rw_St2_OG_g                                          (((word)(rb_Schwelle_Schwall_g))<<6)
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/ 
#define  rbi_RLFS_is_FS_g                                    ((rb_RSControlFlags_g & 0x40)>0)
#endif
#define  rbi_Coupling_measurement_enabled_g        ((rb_RSControlFlags_g & 0x10)>0)
#define rbi_AlwaysIntervalThrs_g                             ((rb_RSControlFlags_g & 0x80)>0)
#define rbi_HumTemp_Module_disabled_g                          ((rb_RSControlFlags_g & 0x08)>0)

/*VDR_276*/
#define rbi_RainsensorAlwaysOn_g                             ((rb_RSControlFlags_g & 0x04)>0)
#define rbi_VW_BritghtnessScaling_g                             ((rb_RSControlFlags_g & 0x01)>0)

#ifdef AUDIC6
#define rb_HelligkeitSkaling_E2_g                            I2C_EEPROM_Struct.I2CEEPROMStruct.HelligkeitSkaling_E2
#endif

#define rub_TropfenMerkerOffsettShift_g (((I2C_EEPROM_Struct.I2CEEPROMStruct.RSEmpfFactorScaling&0x70)>>4)+1)
#define rbi_IntSpInc_Scal_longerInt_enabled_g ((I2C_EEPROM_Struct.I2CEEPROMStruct.RSEmpfFactorScaling&0x80)> 0 )

#ifdef FAW_RLT /*VCO_08 add EEPROM values*/
#define rb_FAW_Twilight_ON_ThrsFkt_g  (I2C_EEPROM_Struct.I2CEEPROMStruct.FAW_Twilight_ON_ThrsFkt)
#define rb_FAW_Twilight_OFF_ThrsFkt_g  (I2C_EEPROM_Struct.I2CEEPROMStruct.FAW_Twilight_OFF_ThrsFkt)
#endif

#ifdef _FORD_ /*VCO_33*/
#define rb_EEPROM_RS_Sens_Mapping_g     (I2C_EEPROM_Struct.I2CEEPROMStruct.EEPROM_BYTE138)
#define rb_EEPROM_SensitivityShift_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.EEPROM_BYTE134 & 0x07)+6) /*like Standard Sensor*/
#define rb_FORD_CarCode00_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode00)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode00_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode00)&0x0F)*5)+20)
#define rb_FORD_CarCode01_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode01)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode01_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode01)&0x0F)*5)+20)
#define rb_FORD_CarCode02_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.p_v_autobahn_on_off_g)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode02_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.p_v_autobahn_on_off_g)&0x0F)*5)+20)
#define rb_FORD_CarCode03_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode03)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode03_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode03)&0x0F)*5)+20)
#define rb_FORD_CarCode04_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode04)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode04_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode04)&0x0F)*5)+20)
#define rb_FORD_CarCode05_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.p_t_autobahn_delay_on_g)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode05_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.p_t_autobahn_delay_on_g)&0x0F)*5)+20)
#define rb_FORD_CarCode06_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode06)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode06_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode06)&0x0F)*5)+20)
#define rb_FORD_CarCode07_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode07)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode07_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode07)&0x0F)*5)+20)
#define rb_FORD_CarCode08_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode08)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode08_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode08)&0x0F)*5)+20)
#define rb_FORD_CarCode09_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode09)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode09_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode09)&0x0F)*5)+20)
#define rb_FORD_CarCode10_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.Frontwaschen_Autobahndelay_g)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode10_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.Frontwaschen_Autobahndelay_g)&0x0F)*5)+20)
#define rb_FORD_CarCode11_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode11)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode11_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode11)&0x0F)*5)+20)
#define rb_FORD_CarCode12_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.p_n_regenlichtschwelle_low_high_g)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode12_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.p_n_regenlichtschwelle_low_high_g)&0x0F)*5)+20)
#define rb_FORD_CarCode13_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode13)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode13_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode13)&0x0F)*5)+20)
#define rb_FORD_CarCode14_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode14)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode14_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode14)&0x0F)*5)+20)
#define rb_FORD_CarCode15_550nm_g  (((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode15)&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode15_880nm_g  ((((I2C_EEPROM_Struct.I2CEEPROMStruct.CarCode15)&0x0F)*5)+20)
/*For CarCode 01,05,07,09,13,14,15*/
#define rb_FORD_OneTimeOrDoubled00_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_1)&0x01)>0
#define rb_FORD_OneTimeOrDoubled01_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_1)&0x02)>0
#define rb_FORD_OneTimeOrDoubled02_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_1)&0x04)>0
#define rb_FORD_OneTimeOrDoubled03_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_1)&0x08)>0
#define rb_FORD_OneTimeOrDoubled04_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_1)&0x10)>0
#define rb_FORD_OneTimeOrDoubled05_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_1)&0x20)>0
#define rb_FORD_OneTimeOrDoubled06_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_1)&0x40)>0
#define rb_FORD_OneTimeOrDoubled07_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_1)&0x80)>0
#define rb_FORD_OneTimeOrDoubled08_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_2)&0x01)>0
#define rb_FORD_OneTimeOrDoubled09_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_2)&0x02)>0
#define rb_FORD_OneTimeOrDoubled10_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_2)&0x04)>0
#define rb_FORD_OneTimeOrDoubled11_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_2)&0x08)>0
#define rb_FORD_OneTimeOrDoubled12_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_2)&0x10)>0
#define rb_FORD_OneTimeOrDoubled13_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_2)&0x20)>0
#define rb_FORD_OneTimeOrDoubled14_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_2)&0x40)>0
#define rb_FORD_OneTimeOrDoubled15_g  ((I2C_EEPROM_Struct.I2CEEPROMStruct.OneTimeOrDouble_2)&0x80)>0


#endif

// special single byte access adresses
#define CB_E2_WATCHDOGRESETCOUTERADRESS   (64)  //Counts the Watchdog Resets
#define CB_E2_SENSOR_ERROR1_ADRESS   65
#define CB_E2_SENSOR_ERROR2_ADRESS   (byte)(66)  //Errorflags
#define CB_E2_SENSOR_ERROR3_ADRESS   67
#define CB_E2_SENSOR_ERROR4_ADRESS   68  //Errorflags
#define CB_E2_SENSOR_ERROR5_ADRESS   69  //Errorflags
#define CB_E2_SENSOR_ERROR6_ADRESS   70  //Errorflags

#define CB_E2_NAD_ADRESS              53

#define CB_E2_IDFSS_01_ADRESS         54

#define CB_E2_IDRLSS_01_ADRESS        55
#define CB_E2_IDBCM1_LIN1_01_ADRESS   56
#define CB_E2_IDWWSS_01_ADRESS        57
#define CB_E2_IDSOSES_01_ADRESS       58

#define CB_E2_880NMTRANSM_ADRESS      0
#define CB_E2_550NMTRANSM_ADRESS      1
#define cb_POSITIONDEFAULTSOFTWARE (cb_NumberofEEPROMCells_g-2)     // CB_DEF_SOFTWARESTAND_2

#define cb_EEPROM_CODING_ADDRESS_g 0

#define CB_FOSC_LEDUL_ADDR_g      (347-256)
#endif /*VDR_394 QA-C Message 883 */

#endif
