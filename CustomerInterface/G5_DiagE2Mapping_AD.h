#ifndef G5_DIAGE2MAPPING_AD_H
#define G5_DIAGE2MAPPING_AD_H
/* PRQA S 3619 EOF */ /* << 2010 01 08, compiler allows whitespaces:due to readable code, keep whitespaces! >> */
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
/* PRQA S 3453 EOF *//*<< Macro is more readle and convinient in this situation >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/****************************************************************************************************************/
/* History                                                                                                      */
/****************************************************************************************************************/
/* Date         VDR_Number     Description                                                                      */
/*18.11.14      VCO_189                 DEBUG:Change the I2C debug data mapping                                 */
/*27.11.14      VDR_825         MP      Diagnostic pulse - change the wait time                                 */
/*09.12.14      VCO_204         NB      Project specific extensions in the main stream                          */
/*01.04.15      VCO_239         MP      Light values filter defined in EEPROM                                   */
/*14.04.15      VCO_243         NB      Implement Function ID and Variant ID in the EEPROM PD section           */
/*09.07.15      VCO_259         NB      change the minimal value of rb_TunnelDebounceFactor_g to 0              */
/*13.07.15      VCO_260         MP      Tunnel wipe activation and delay according to                           */
/****************************************Tunnel Verzoegerung and Aktivierung parameters                         */
/*07.10.15      VCO_277         SP      Modify the SHT Error Debonunce Jitter as an EEPROM parameter            */
/*07.10.15      VCO_278         NB      Solar shadow correction                                                 */
/*08.10.15      VCO_278         NB      Solar shadow correction                                                 */
/*11.11.15      VCO_285         NB      Adapt the default parameter for the combined solar sender optimis       */
/*13.11.15      VDR_924         SP      Licht An bei Regen - Anpass parameters are not correctly used           */
/*13.11.15      VCO_286         SP      Modify the Default EEPROM Parameter of SHT module communication Retry Counter */
/*02.12.15      VDR_939         NB      Improvement of SHT module measurement */
/*14.01.16      VCO_304         NB      Default values for solar correction factor changed for tesla         */
/*26.02.16      VCO_308         NB      EEPROM AD extension for twilight                                     */
/*12.05.16      VCO_326         NB      All:Update of default Software part number and other configuration   */
/*16.08.16      VCO_339         NB      Change the default value of EEPROM parameter                         */
/****************************************************************************************************************/

#include "G5_projectDefs.h"
#include "G5_HumTemp.h"


#define cb_NumberofEEPROMCells_AD_g 194


#define cb_DEFAULT_g     0 /*Column for Default Value*/
#define cb_CHK_MIN_g     1 /*Column for Min Value*/
#define cb_CHK_MAX_g     2 /*Column for Max Value*/

#define CB_TIMFORAFWTHRS_INC_g 2
#define CB_DEPRESSED_PARK_POINTER_DEF 2 /*VCO_49 Default Value for Depressed Park need to be set longer*/


#if defined (GEN_35A)
#define CB_DEF_GAINSETUP_0_1                0x23
#define CB_DEF_GAINSETUP_2_3                0x45
#define CB_DEF_GAINSETUP_4_5                0x67
#define CB_DEF_GAINSETUP_6_7                0x89
#define CB_DEF_GAINSETUP_8_9                0xAB
#define CB_DEF_GAINSETUP_10_MOD             0xC0
#elif (FERRARI || FIAT_330) 
#define CB_DEF_GAINSETUP_0_1                0x12
#define CB_DEF_GAINSETUP_2_3                0x34
#define CB_DEF_GAINSETUP_4_5                0x56
#define CB_DEF_GAINSETUP_6_7                0x78
#define CB_DEF_GAINSETUP_8_9                0x9A
#define CB_DEF_GAINSETUP_10_MOD             0xB0
#else
#define CB_DEF_GAINSETUP_0_1                0x01
#define CB_DEF_GAINSETUP_2_3                0x23
#define CB_DEF_GAINSETUP_4_5                0x45
#define CB_DEF_GAINSETUP_6_7                0x67
#define CB_DEF_GAINSETUP_8_9                0x89
#define CB_DEF_GAINSETUP_10_MOD             0xA0
#endif //GEN_35A
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


#define CB_DEF_ICO1H         0x00
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
#define CB_MIN_SCHWELLE_SCHWALL             25
#define CB_MAX_SCHWELLE_SCHWALL             140

#define CB_DEF_ANSAMLUN_ADIT_OFFS           0
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
#define CB_MIN_EMPF_FAKTOR_ST2_OFFS         3
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

/*RS empfindlichkeit scaling faktor for Parametersatz 0*/
#define CB_DEF_RSEMPFFACTORSCALING          (0x80+_OVR_INT_SCAL_OFFS+_EMPF_FACTOR_SCAL)//Schlierenflag2-> C8
/*RS empfindlichkeit scaling faktor for Parametersatz 1*/
#define CB_DEF_RSEMPFFACTORSCALING_1        (0x80+_OVR_INT_SCAL_OFFS+_EMPF_FACTOR_SCAL_1)
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
#define CB_MIN_TUNNELDEBOUNCEFACTOR         0 /*VCO_259*/
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

#if (defined FERRARI) || (defined GEN3_5A_FCA) || (defined FIAT_330)
#define CB_DEF_AFTERTUNNELDELAYOFFS         27
#define CB_MAX_AFTERTUNNELDELAYOFFS         0x1f 
#define CB_MIN_AFTERTUNNELDELAYOFFS         0
#else
#define CB_DEF_AFTERTUNNELDELAYOFFS         11
#define CB_MAX_AFTERTUNNELDELAYOFFS         0x1f 
#define CB_MIN_AFTERTUNNELDELAYOFFS         0
#endif
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
#define CB_DEF_REGENLICHTSCHWELLE_LOW_HIGH 0x1B
#define CB_MIN_REGENLICHTSCHWELLE_LOW_HIGH 0
#define CB_MAX_REGENLICHTSCHWELLE_LOW_HIGH 0xFF

/*regenlicht */
#define CB_DEF_REGENLICHTSCHWELLE_ZEIT 68
#define CB_MIN_REGENLICHTSCHWELLE_ZEIT 0
#define CB_MAX_REGENLICHTSCHWELLE_ZEIT 0xFF

#define CB_DEF_TUNNELTHRESHOLDSCALING 0x44 /*default value for tunnel threshold scaling*/
#define CB_MIN_TUNNELTHRESHOLDSCALING 0
#define CB_MAX_TUNNELTHRESHOLDSCALING 0xff

#define CB_DEF_AMB_TUNNELTHRESHOLDSCALING 0x04 
#define CB_MIN_AMB_TUNNELTHRESHOLDSCALING 0
#define CB_MAX_AMB_TUNNELTHRESHOLDSCALING 0xff

#if (defined FERRARI) || (defined GEN3_5A_FCA) || (defined FIAT_330)

#define CB_DEF_REGULATION48LIGHTONTIME 0x46
#define CB_MIN_REGULATION48LIGHTONTIME 20
#define CB_MAX_REGULATION48LIGHTONTIME 255

#define CB_DEF_REGULATION48THRESHOLD_AMB 0x3C
#define CB_MIN_REGULATION48THRESHOLD_AMB 0
#define CB_MAX_REGULATION48THRESHOLD_AMB 255

#define CB_DEF_REGULATION48THRESHOLD_FW 0x41
#define CB_MIN_REGULATION48THRESHOLD_FW 0
#define CB_MAX_REGULATION48THRESHOLD_FW 255

#elif defined FORD

#define CB_DEF_REGULATION48LIGHTONTIME 0x6C
#define CB_MIN_REGULATION48LIGHTONTIME 20
#define CB_MAX_REGULATION48LIGHTONTIME 255

// this is the new way with 8 bit resolution for thresholds
#define CB_DEF_REGULATION48THRESHOLD_AMB 25
#define CB_MIN_REGULATION48THRESHOLD_AMB 0
#define CB_MAX_REGULATION48THRESHOLD_AMB 255

#define CB_DEF_REGULATION48THRESHOLD_FW 25
#define CB_MIN_REGULATION48THRESHOLD_FW 0
#define CB_MAX_REGULATION48THRESHOLD_FW 255

#else

#define CB_DEF_REGULATION48LIGHTONTIME 0x6C
#define CB_MIN_REGULATION48LIGHTONTIME 20
#define CB_MAX_REGULATION48LIGHTONTIME 255

/*(about 810 lux---Value corrected for 80% transmission through glass)---(Previous Value about 1250 lux)----KI*/
// this is the old way with 4 bit resolution for thresholds
//#define CB_DEF_REGULATION48THRESHOLD 0x65
//#define CB_MIN_REGULATION48THRESHOLD 0
//#define CB_MAX_REGULATION48THRESHOLD 255

// this is the new way with 8 bit resolution for thresholds
#define CB_DEF_REGULATION48THRESHOLD_AMB 30
#define CB_MIN_REGULATION48THRESHOLD_AMB 0
#define CB_MAX_REGULATION48THRESHOLD_AMB 255

#define CB_DEF_REGULATION48THRESHOLD_FW 25
#define CB_MIN_REGULATION48THRESHOLD_FW 0
#define CB_MAX_REGULATION48THRESHOLD_FW 255
#endif
/*VCO_094 Thresehold Set for VeryBrightTunnelDetection*/
#define CB_DEF_VERYBRIGHTINTUNNELDELAY CB_DEF_VERYBRIGHTINTUNL_DIST_THRS_g
#define CB_MIN_VERYBRIGHTINTUNNELDELAY CB_MIN_VERYBRIGHTINTUNL_DIST_THRS_g
#define CB_MAX_VERYBRIGHTINTUNNELDELAY CB_MAX_VERYBRIGHTINTUNL_DIST_THRS_g


#define CB_DEF_COMBINED_FW_AL_THRS 0x00
#define CB_MIN_COMBINED_FW_AL_THRS 0x00
#define CB_MAX_COMBINED_FW_AL_THRS 0xFF

/*default value for tunnel threshold scaling*/
#define CB_DEF_DYN_COMP_CCD_MINUS_1 ((cb_DYN_COMP_CCD_MINUS_neg5to10_DEF<<4)+cb_DYN_COMP_CCD_MINUS_10to25_DEF)
#define CB_MIN_DYN_COMP_CCD_MINUS_1  0x00
#define CB_MAX_DYN_COMP_CCD_MINUS_1  0xFF

/*default value for tunnel threshold scaling*/
#define CB_DEF_DYN_COMP_CCD_MINUS_2 ((cb_DYN_COMP_CCD_MINUS_25to40_DEF << 4)+cb_DYN_COMP_CCD_MINUS_above40_DEF)
#define CB_MIN_DYN_COMP_CCD_MINUS_2 0x00
#define CB_MAX_DYN_COMP_CCD_MINUS_2 0xFF

#define CB_DEF_MAXTEMPERATUREOFFSETT CB_DEF_MAXTEMPERATUREOFFSET_G
#define CB_MIN_MAXTEMPERATUREOFFSETT 0x00
#define CB_MAX_MAXTEMPERATUREOFFSETT 0xFF

#define CB_DEF_ASIC_AFSTHR_REG 0x99
#define CB_MIN_ASIC_AFSTHR_REG 0x00
#define CB_MAX_ASIC_AFSTHR_REG 0xFF

#define CB_DEF_DIAG_REQUEST_FACTOR 0x07
#define CB_MIN_DIAG_REQUEST_FACTOR 0x05
#define CB_MAX_DIAG_REQUEST_FACTOR 0x10

#define CB_DEF_ALSX_FILTER      0x01
#define CB_MIN_ALSX_FILTER      0x00
#define CB_MAX_ALSX_FILTER      0x01

#define CB_DEF_LIGHT_CTRL_SETTINGS1      0x84
#define CB_MIN_LIGHT_CTRL_SETTINGS1      0x01
#define CB_MAX_LIGHT_CTRL_SETTINGS1      0xFF

#define CB_DEF_LIGHT_CTRL_SETTINGS2      0xC4
#define CB_MIN_LIGHT_CTRL_SETTINGS2      0x01
#define CB_MAX_LIGHT_CTRL_SETTINGS2      0xFF

#define CB_DEF_LIGHT_CTRL_SETTINGS3      0x8C
#define CB_MIN_LIGHT_CTRL_SETTINGS3      0x01
#define CB_MAX_LIGHT_CTRL_SETTINGS3      0xFF

/*VCO_260 Tunnel wipe activation and delay according to Tunnel Verzoegerung and Aktivierung parameters*/
#define CB_DEF_TUNWISCHVERZAKTIV         0x88
#define CB_MIN_TUNWISCHVERZAKTIV         0x00
#define CB_MAX_TUNWISCHVERZAKTIV         0xFF


#define CB_DEF_SHTERRDEBOUNCEJITTER        60
#define CB_MIN_SHTERRDEBOUNCEJITTER        0x00
#define CB_MAX_SHTERRDEBOUNCEJITTER        0xFF

#define CB_DEF_DEC_ST2_SPEICHER         31
#define CB_MIN_DEC_ST2_SPEICHER         10
#define CB_MAX_DEC_ST2_SPEICHER         255

#define CB_DEF_E2_RESERVED 0x00
#define CB_MIN_E2_RESERVED 0x00
#define CB_MAX_E2_RESERVED 0xFF

#ifdef TESLA
#define CB_DEF_SLOAR_SHADOW_CORR_FACTOR1 7 
#else
#define CB_DEF_SLOAR_SHADOW_CORR_FACTOR1 0
#endif
#define CB_MIN_SLOAR_SHADOW_CORR_FACTOR1 0x00
#define CB_MAX_SLOAR_SHADOW_CORR_FACTOR1 0xFF


#ifdef TESLA
#define CB_DEF_SLOAR_SHADOW_CORR_FACTOR2 0
#else
#define CB_DEF_SLOAR_SHADOW_CORR_FACTOR2 7
#endif
#define CB_MIN_SLOAR_SHADOW_CORR_FACTOR2 0x00
#define CB_MAX_SLOAR_SHADOW_CORR_FACTOR2 0xFF

#define CB_DEF_I2C_DEBUG_CONFIG 0xFF
#define CB_MIN_I2C_DEBUG_CONFIG 0x00
#define CB_MAX_I2C_DEBUG_CONFIG 0xFF

#define CB_DEF_INC_SPEICHER 0x64
#define CB_MIN_INC_SPEICHER 0x00
#define CB_MAX_INC_SPEICHER 0xFF
#ifdef TESLA

#define CB_DEF_AUDI_SW_PART_NUMBER_1  '1'
#define CB_MIN_AUDI_SW_PART_NUMBER_1  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_1  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_2  '0'
#define CB_MIN_AUDI_SW_PART_NUMBER_2  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_2  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_3  '6'
#define CB_MIN_AUDI_SW_PART_NUMBER_3  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_3  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_4_5  0x69
#define CB_MIN_AUDI_SW_PART_NUMBER_4_5  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_4_5  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_6_7  0x90
#define CB_MIN_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_6_7  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MIN_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_8_9  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX  '-'
#define CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX  'A'
#define CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX  0xFF

#elif (defined FERRARI) || (defined GEN3_5A_FCA) || (defined FIAT_330)

#define CB_DEF_AUDI_SW_PART_NUMBER_1  0x30
#define CB_MIN_AUDI_SW_PART_NUMBER_1  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_1  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_2  0x30
#define CB_MIN_AUDI_SW_PART_NUMBER_2  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_2  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_3  0x35
#define CB_MIN_AUDI_SW_PART_NUMBER_3  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_3  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_4_5  0x05
#define CB_MIN_AUDI_SW_PART_NUMBER_4_5  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_4_5  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_6_7  0x36
#define CB_MIN_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_6_7  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_8_9  0x65
#define CB_MIN_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_8_9  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX  0x38
#define CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX  0x30
#define CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX  0xFF

#elif (HAITEC)

#define CB_DEF_AUDI_SW_PART_NUMBER_1  '8'
#define CB_MIN_AUDI_SW_PART_NUMBER_1  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_1  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_2  '1'
#define CB_MIN_AUDI_SW_PART_NUMBER_2  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_2  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_3  'A'
#define CB_MIN_AUDI_SW_PART_NUMBER_3  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_3  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_4_5  0x95
#define CB_MIN_AUDI_SW_PART_NUMBER_4_5  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_4_5  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_6_7  0x44
#define CB_MIN_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_6_7  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_8_9  0x44
#define CB_MIN_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_8_9  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX  'A'
#define CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX  ' '
#define CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX  0xFF

#elif (FOTON_S700) 

#define CB_DEF_AUDI_SW_PART_NUMBER_1  '8'
#define CB_MIN_AUDI_SW_PART_NUMBER_1  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_1  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_2  '1'
#define CB_MIN_AUDI_SW_PART_NUMBER_2  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_2  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_3  'A'
#define CB_MIN_AUDI_SW_PART_NUMBER_3  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_3  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_4_5  0x95
#define CB_MIN_AUDI_SW_PART_NUMBER_4_5  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_4_5  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_6_7  0x33
#define CB_MIN_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_6_7  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_8_9  0x33
#define CB_MIN_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_8_9  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX  'A'
#define CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX  ' '
#define CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX  0xFF

#elif (FORD) 

#define CB_DEF_AUDI_SW_PART_NUMBER_1  'F'
#define CB_MIN_AUDI_SW_PART_NUMBER_1  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_1  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_2  '1'
#define CB_MIN_AUDI_SW_PART_NUMBER_2  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_2  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_3  'E'
#define CB_MIN_AUDI_SW_PART_NUMBER_3  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_3  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_4_5  0x54
#define CB_MIN_AUDI_SW_PART_NUMBER_4_5  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_4_5  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MIN_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_6_7  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MIN_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_8_9  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX  'A'
#define CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX  'B'
#define CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX  0xFF

#elif (FARADAY) 

#define CB_DEF_AUDI_SW_PART_NUMBER_1  '3'
#define CB_MIN_AUDI_SW_PART_NUMBER_1  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_1  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_2  '1'
#define CB_MIN_AUDI_SW_PART_NUMBER_2  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_2  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_3  '3'
#define CB_MIN_AUDI_SW_PART_NUMBER_3  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_3  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_4_5  0x95
#define CB_MIN_AUDI_SW_PART_NUMBER_4_5  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_4_5  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_6_7  0x30
#define CB_MIN_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_6_7  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MIN_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_8_9  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX  ' '
#define CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX  ' '
#define CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX  0xFF

#elif (BRILLIANCE_M8X) 

#define CB_DEF_AUDI_SW_PART_NUMBER_1  0x00
#define CB_MIN_AUDI_SW_PART_NUMBER_1  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_1  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_2  0x00
#define CB_MIN_AUDI_SW_PART_NUMBER_2  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_2  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_3  0x00
#define CB_MIN_AUDI_SW_PART_NUMBER_3  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_3  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_4_5  0x00
#define CB_MIN_AUDI_SW_PART_NUMBER_4_5  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_4_5  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MIN_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_6_7  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MIN_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_8_9  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX  0x00
#define CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX  0x00
#define CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX  0xFF

#elif (CTCS_M31T)

#define CB_DEF_AUDI_SW_PART_NUMBER_1  '8'
#define CB_MIN_AUDI_SW_PART_NUMBER_1  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_1  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_2  '1'
#define CB_MIN_AUDI_SW_PART_NUMBER_2  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_2  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_3  'A'
#define CB_MIN_AUDI_SW_PART_NUMBER_3  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_3  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_4_5  0x95
#define CB_MIN_AUDI_SW_PART_NUMBER_4_5  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_4_5  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_6_7  0x66
#define CB_MIN_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_6_7  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_8_9  0x66
#define CB_MIN_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_8_9  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX  ' '
#define CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX  ' '
#define CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX  0xFF

#elif (GEELY_NL_3A)

#define CB_DEF_AUDI_SW_PART_NUMBER_1  '0'
#define CB_MIN_AUDI_SW_PART_NUMBER_1  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_1  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_2  '1'
#define CB_MIN_AUDI_SW_PART_NUMBER_2  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_2  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_3  '7'
#define CB_MIN_AUDI_SW_PART_NUMBER_3  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_3  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_4_5  0x72
#define CB_MIN_AUDI_SW_PART_NUMBER_4_5  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_4_5  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_6_7  0x07
#define CB_MIN_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_6_7  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_8_9  0x90        /***Only used '9'***/
#define CB_MIN_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_8_9  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX  ' '
#define CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX  ' '
#define CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX  0xFF

#elif (BAICYX_H50)

#define CB_DEF_AUDI_SW_PART_NUMBER_1  '8'
#define CB_MIN_AUDI_SW_PART_NUMBER_1  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_1  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_2  '1'
#define CB_MIN_AUDI_SW_PART_NUMBER_2  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_2  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_3  'D'
#define CB_MIN_AUDI_SW_PART_NUMBER_3  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_3  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_4_5  0x33
#define CB_MIN_AUDI_SW_PART_NUMBER_4_5  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_4_5  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_6_7  0x22
#define CB_MIN_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_6_7  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_8_9  0x11
#define CB_MIN_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_8_9  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX  ' '
#define CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX  ' '
#define CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX  0xFF

#else

#define CB_DEF_AUDI_SW_PART_NUMBER_1  '8'
#define CB_MIN_AUDI_SW_PART_NUMBER_1  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_1  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_2  '1'
#define CB_MIN_AUDI_SW_PART_NUMBER_2  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_2  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_3  'A'
#define CB_MIN_AUDI_SW_PART_NUMBER_3  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_3  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_4_5  0x95
#define CB_MIN_AUDI_SW_PART_NUMBER_4_5  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_4_5  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_6_7  0x55
#define CB_MIN_AUDI_SW_PART_NUMBER_6_7  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_6_7  0xFF


#define CB_DEF_AUDI_SW_PART_NUMBER_8_9  0x55
#define CB_MIN_AUDI_SW_PART_NUMBER_8_9  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_8_9  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX  ' '
#define CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX  0xFF

#define CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX  ' '
#define CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX  0x00
#define CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX  0xFF
#endif
/*high nibble: right edge leading from low to high speed
low nibble: left edge leading from high to low speed
*/
#define CB_DEF_WIPER_SPEED_HYSTERESIS 0x64
#define CB_MIN_WIPER_SPEED_HYSTERESIS 0x11
#define CB_MAX_WIPER_SPEED_HYSTERESIS 0x77

#define CB_DEF_PRJ_SPECIFIC_CONFIG 0x03
#define CB_MIN_PRJ_SPECIFIC_CONFIG 0x00
#define CB_MAX_PRJ_SPECIFIC_CONFIG 0xFF

#define CB_DEF_E2_MAXST2SIGNALLAENGE 140
#define CB_MIN_E2_MAXST2SIGNALLAENGE 20
#define CB_MAX_E2_MAXST2SIGNALLAENGE 255

#define cb_SWSTANDEEPROM_23_g    (((cb_SOFTWARESTAND_2_g-'0')*16)+(cb_SOFTWARESTAND_3_g-'0'))

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


#if (defined FERRARI) || (defined GEN3_5A_FCA) || (defined FIAT_330) || (defined FIAT_330)
#define _EMPF_FACTOR_SCAL    0x09
#else
#define _EMPF_FACTOR_SCAL    0x07
#endif

#define _EMPF_FACTOR_SCAL_1  0x09
#define _OVR_INT_SCAL_OFFS   0x40

#define CB_DEF_DARK_TO_TWILIGHT_TIME 15   /* default value seconds*/
#define CB_MIN_DARK_TO_TWILIGHT_TIME 0x01 /* since this is controlling the twilight
                                          to dark state machine it cannot be zero
                                          as the state machine has defined states*/
#define CB_MAX_DARK_TO_TWILIGHT_TIME 0xFF

#define CB_DEF_TWILIGHT_TO_DARK_TIME 37   /* default value seconds*/
#define CB_MIN_TWILIGHT_TO_DARK_TIME 0x01 /* since this is controlling the twilight
                                          to dark state machine it cannot be zero
                                          as the state machine has defined states*/
#define CB_MAX_TWILIGHT_TO_DARK_TIME 0xFF

#define CB_DEF_DARK_TO_TWILIGHT_THRESH_FW 10
#define CB_MIN_DARK_TO_TWILIGHT_THRESH_FW 1
#define CB_MAX_DARK_TO_TWILIGHT_THRESH_FW 255

#define CB_DEF_DARK_TO_TWILIGHT_THRESH_AMB 10
#define CB_MIN_DARK_TO_TWILIGHT_THRESH_AMB 1
#define CB_MAX_DARK_TO_TWILIGHT_THRESH_AMB 255

#define CB_DEF_TWILIGHT_TO_DARK_THRESH_FW 4
#define CB_MIN_TWILIGHT_TO_DARK_THRESH_FW 1
#define CB_MAX_TWILIGHT_TO_DARK_THRESH_FW 255

#define CB_DEF_TWILIGHT_TO_DARK_THRESH_AMB 4
#define CB_MIN_TWILIGHT_TO_DARK_THRESH_AMB 1
#define CB_MAX_TWILIGHT_TO_DARK_THRESH_AMB 255

#define CB_DEF_ICE_DETECTION_TEMPERATURE 80
#define CB_MIN_ICE_DETECTION_TEMPERATURE 0
#define CB_MAX_ICE_DETECTION_TEMPERATURE 255

#if defined FORD
#define CB_DEF_CAR_CODE_00 0xC6
#define CB_MIN_CAR_CODE_00 0
#define CB_MAX_CAR_CODE_00 255

#define CB_DEF_CAR_CODE_01 0xD3
#define CB_MIN_CAR_CODE_01 0
#define CB_MAX_CAR_CODE_01 255

#define CB_DEF_CAR_CODE_02 0xE6
#define CB_MIN_CAR_CODE_02 0
#define CB_MAX_CAR_CODE_02 255

#define CB_DEF_CAR_CODE_03 0xD8
#define CB_MIN_CAR_CODE_03 0
#define CB_MAX_CAR_CODE_03 255

#define CB_DEF_CAR_CODE_04 0xE6
#define CB_MIN_CAR_CODE_04 0
#define CB_MAX_CAR_CODE_04 255

#define CB_DEF_CAR_CODE_05 0xC2
#define CB_MIN_CAR_CODE_05 0
#define CB_MAX_CAR_CODE_05 255

#define CB_DEF_CAR_CODE_06 0xFD
#define CB_MIN_CAR_CODE_06 0
#define CB_MAX_CAR_CODE_06 255

#define CB_DEF_CAR_CODE_07 0xC3
#define CB_MIN_CAR_CODE_07 0
#define CB_MAX_CAR_CODE_07 255

#define CB_DEF_CAR_CODE_08 0xFD
#define CB_MIN_CAR_CODE_08 0
#define CB_MAX_CAR_CODE_08 255

#define CB_DEF_CAR_CODE_09 0xD4
#define CB_MIN_CAR_CODE_09 0
#define CB_MAX_CAR_CODE_09 255

#define CB_DEF_CAR_CODE_10 0xD4
#define CB_MIN_CAR_CODE_10 0
#define CB_MAX_CAR_CODE_10 255

#define CB_DEF_CAR_CODE_11 0xD3
#define CB_MIN_CAR_CODE_11 0
#define CB_MAX_CAR_CODE_11 255

#define CB_DEF_CAR_CODE_12 0xE6
#define CB_MIN_CAR_CODE_12 0
#define CB_MAX_CAR_CODE_12 255

#define CB_DEF_CAR_CODE_13 0xD6
#define CB_MIN_CAR_CODE_13 0
#define CB_MAX_CAR_CODE_13 255

#define CB_DEF_CAR_CODE_14 0xD6
#define CB_MIN_CAR_CODE_14 0
#define CB_MAX_CAR_CODE_14 255

#define CB_DEF_CAR_CODE_15 0xD6
#define CB_MIN_CAR_CODE_15 0
#define CB_MAX_CAR_CODE_15 255

#define CB_DEF_DOUBLE_OVER_WIPED_0_7 0
#define CB_MIN_DOUBLE_OVER_WIPED_0_7 0
#define CB_MAX_DOUBLE_OVER_WIPED_0_7 255

#define CB_DEF_DOUBLE_OVER_WIPED_8_15 0x0A
#define CB_MIN_DOUBLE_OVER_WIPED_8_15 0
#define CB_MAX_DOUBLE_OVER_WIPED_8_15 255

#define CB_DEF_BUTTERFLY_0_7 0x46
#define CB_MIN_BUTTERFLY_0_7 0
#define CB_MAX_BUTTERFLY_0_7 255

#define CB_DEF_BUTTERFLY_8_15 0x0E
#define CB_MIN_BUTTERFLY_8_15 0
#define CB_MAX_BUTTERFLY_8_15 255

#define CB_DEF_RSCONFIG 0x13
#define CB_MIN_RSCONFIG 0
#define CB_MAX_RSCONFIG 255

#define CB_DEF_RSSENSMAPPING 0x7B
#define CB_MIN_RSSENSMAPPING 0x3F
#define CB_MAX_RSSENSMAPPING 0xFC

#define CB_DEF_WIPERSIGNAL 0x41
#define CB_MIN_WIPERSIGNAL 0
#define CB_MAX_WIPERSIGNAL 255

#define CB_DEF_WIPERMOTORTIME 0x53
#define CB_MIN_WIPERMOTORTIME 0
#define CB_MAX_WIPERMOTORTIME 255

#define CB_DEF_PARTNUMBER_1 0x41
#define CB_MIN_PARTNUMBER_1 0
#define CB_MAX_PARTNUMBER_1 255
#define cb_PartNumberPart1_g 183

#define CB_DEF_PARTNUMBER_2 0x41
#define CB_MIN_PARTNUMBER_2 0
#define CB_MAX_PARTNUMBER_2 255
#define cb_PartNumberPart2_g 184

#define CB_DEF_PARTNUMBER_3 0x41
#define CB_MIN_PARTNUMBER_3 0
#define CB_MAX_PARTNUMBER_3 255
#define cb_PartNumberPart3_g 185

#define CB_DEF_PARTNUMBER_4 0x41
#define CB_MIN_PARTNUMBER_4 0
#define CB_MAX_PARTNUMBER_4 255
#define cb_PartNumberPart4_g 186

#define CB_DEF_PARTNUMBER_5 'A'
#define CB_MIN_PARTNUMBER_5 0
#define CB_MAX_PARTNUMBER_5 255

#define CB_DEF_PARTNUMBER_6 'B'
#define CB_MIN_PARTNUMBER_6 0
#define CB_MAX_PARTNUMBER_6 255


#define CB_DEF_OVERWIPE 0x8B
#define CB_MIN_OVERWIPE 0
#define CB_MAX_OVERWIPE 255

#define CB_DEF_FADEOUT 0xF9
#define CB_MIN_FADEOUT 0
#define CB_MAX_FADEOUT 255

#define CB_DEF_SENSITIVITYBARRIER 0x01
#define CB_MIN_SENSITIVITYBARRIER 0
#define CB_MAX_SENSITIVITYBARRIER 255

/*HighNibble: -, LowNibble: EEPROM_Threshold_FirstOverwipe_Start*/
#define CB_DEF_THRESHOLD_FIRSTOWIPE_START 0x01
#define CB_MIN_THRESHOLD_FIRSTOWIPE_START 0x00
#define CB_MAX_THRESHOLD_FIRSTOWIPE_START 0xFF

/*HighNibble: EEPROM_Threshold_FirstOverwipe_End_DoubleOverwiped_OFFSET, LowNibble: EEPROM_Threshold_FirstOverwipe_End*/
#define CB_DEF_THRESHOLD_FIRSTOWIPE_END 0x35
#define CB_MIN_THRESHOLD_FIRSTOWIPE_END 0x00
#define CB_MAX_THRESHOLD_FIRSTOWIPE_END 0xFF
  
/*HighNibble: EEPROM_Threshold_AfterWiperMotorTime, LowNibble: EEPROM_Threshold_SecondOverwipe_Start*/
#define CB_DEF_THRESHOLD_OVERWIPE 0x19
#define CB_MIN_THRESHOLD_OVERWIPE 0x00
#define CB_MAX_THRESHOLD_OVERWIPE 0xFF

#endif
#define UNUSED 0xFF

#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_ /*VDR_403*/
#define CB_DEF_SINGLE_OR_DOUBLE             0x95 /*Low Nibble: rb_Single_Or_Double_Overwipe_dec,
High Nibble: rb_MaxOverwipeSensitivity_g*/ /*VDR_394*/
#define CB_MIN_SINGLE_OR_DOUBLE             0
#define CB_MAX_SINGLE_OR_DOUBLE             0xFF /*( ( (rb_MaxOverwipeSensitivity_g<0x0F)?((rb_MaxOverwipeSensitivity_g<<4):0xFF) )  |0x0F )*/ /*Max for High Nibble results from rb_MaxOverwipeSensitivity_g*/
#endif

#define CB_OFFSETT_ADDIT_NOM  64


#define CB_DEF_THRESHOLD_TEMPICERISK 0x6A
#define CB_MIN_THRESHOLD_TEMPICERISK 0x00
#define CB_MAX_THRESHOLD_TEMPICERISK 0xFF

#define CB_DEF_UPPER_TOL_SUW 0x00
#define CB_MIN_UPPER_TOL_SUW 0x00
#define CB_MAX_UPPER_TOL_SUW 0x01

#ifdef _DIAGNOSE_c_
#define EXTERN /**/
#pragma constseg="BOOTSEG_TWO"               /* VDR_671 */
const byte __far cb_EEPROMDataDefaultMinMax_AD_g[cb_NumberofEEPROMCells_AD_g][3] = {
  
  
 /* For Parameter 0 */
  {CB_DEF_STUFE1_OG                      ,CB_MIN_STUFE1_OG                      ,CB_MAX_STUFE1_OG                      },       /*512*/
  {CB_DEF_STUFE1_UG                      ,CB_MIN_STUFE1_UG                      ,CB_MAX_STUFE1_UG                      },       /*513*/
  {CB_DEF_EP_ST2_EPR_IN_ST2              ,CB_MIN_EP_ST2_EPR_IN_ST2              ,CB_MAX_EP_ST2_EPR_IN_ST2              },       /*514*/
  {CB_DEF_SCHWELLE_SCHWALL               ,CB_MIN_SCHWELLE_SCHWALL               ,CB_MAX_SCHWELLE_SCHWALL               },       /*515*/  
  {CB_DEF_ANSAMLUN_ADIT_OFFS             ,CB_MIN_ANSAMLUN_ADIT_OFFS             ,CB_MAX_ANSAMLUN_ADIT_OFFS             },       /*516*/
  {CB_DEF_DEC_INT_SP_OFF                 ,CB_MIN_DEC_INT_SP_OFF                 ,CB_MAX_DEC_INT_SP_OFF                 },       /*517*/
  {CB_DEF_DEC_STX_SPEICHER               ,CB_MIN_DEC_STX_SPEICHER               ,CB_MAX_DEC_STX_SPEICHER               },       /*518*/
  {CB_DEF_DEC_OVR_SPEICHER               ,CB_MIN_DEC_OVR_SPEICHER               ,CB_MAX_DEC_OVR_SPEICHER               },       /*519*/
  {CB_DEF_EMPF_FAKTOR_ST2_OFFS           ,CB_MIN_EMPF_FAKTOR_ST2_OFFS           ,CB_MAX_EMPF_FAKTOR_ST2_OFFS           },       /*520*/
  {CB_DEF_MAX_SIGNALLAENGE               ,CB_MIN_MAX_SIGNALLAENGE               ,CB_MAX_MAX_SIGNALLAENGE               },       /*521*/
  {CB_DEF_RB_STUFE1_WITH_INT_OG          ,CB_MIN_RB_STUFE1_WITH_INT_OG          ,CB_MAX_RB_STUFE1_WITH_INT_OG          },      /*522*/
  {CB_DEF_NACHWISCH_4_ST1_MIN            ,CB_MIN_NACHWISCH_4_ST1_MIN            ,CB_MAX_NACHWISCH_4_ST1_MIN            },      /*523*/
  {CB_DEF_NACHWISCH_3                    ,CB_MIN_NACHWISCH_3                    ,CB_MAX_NACHWISCH_3                    },      /*524*/
  {CB_DEF_NACHWISCH_2                    ,CB_MIN_NACHWISCH_2                    ,CB_MAX_NACHWISCH_2                    },      /*525*/
  {CB_DEF_RSEMPFFACTORSCALING            ,CB_MIN_RSEMPFFACTORSCALING            ,CB_MAX_RSEMPFFACTORSCALING            },      /*526*/
  {CB_DEF_SCHLIEREN_FLAG                 ,CB_MIN_SCHLIEREN_FLAG                 ,CB_MAX_SCHLIEREN_FLAG                 },      /*527*/
  {CB_DEF_SIG_ANS_SCHW_OFFS              ,CB_MIN_SIG_ANS_SCHW_OFFS              ,CB_MAX_SIG_ANS_SCHW_OFFS              },      /*528*/
 
 /* For Parameter 1 */  
  {CB_DEF_STUFE1_OG                      ,CB_MIN_STUFE1_OG                      ,CB_MAX_STUFE1_OG                      },      /*529*/
  {CB_DEF_STUFE1_UG                      ,CB_MIN_STUFE1_UG                      ,CB_MAX_STUFE1_UG                      },      /*530*/
  {CB_DEF_EP_ST2_EPR_IN_ST2              ,CB_MIN_EP_ST2_EPR_IN_ST2              ,CB_MAX_EP_ST2_EPR_IN_ST2              },      /*531*/
  {CB_DEF_SCHWELLE_SCHWALL               ,CB_MIN_SCHWELLE_SCHWALL               ,CB_MAX_SCHWELLE_SCHWALL               },      /*532*/  
  {CB_DEF_ANSAMLUN_ADIT_OFFS             ,CB_MIN_ANSAMLUN_ADIT_OFFS             ,CB_MAX_ANSAMLUN_ADIT_OFFS             },      /*533*/
  {CB_DEF_DEC_INT_SP_OFF                 ,CB_MIN_DEC_INT_SP_OFF                 ,CB_MAX_DEC_INT_SP_OFF                 },      /*534*/
  {CB_DEF_DEC_STX_SPEICHER               ,CB_MIN_DEC_STX_SPEICHER               ,CB_MAX_DEC_STX_SPEICHER               },      /*535*/
  {CB_DEF_DEC_OVR_SPEICHER               ,CB_MIN_DEC_OVR_SPEICHER               ,CB_MAX_DEC_OVR_SPEICHER               },      /*536*/
  {CB_DEF_EMPF_FAKTOR_ST2_OFFS           ,CB_MIN_EMPF_FAKTOR_ST2_OFFS           ,CB_MAX_EMPF_FAKTOR_ST2_OFFS           },      /*537*/
  {CB_DEF_MAX_SIGNALLAENGE               ,CB_MIN_MAX_SIGNALLAENGE               ,CB_MAX_MAX_SIGNALLAENGE               },      /*538*/
  {CB_DEF_RB_STUFE1_WITH_INT_OG          ,CB_MIN_RB_STUFE1_WITH_INT_OG          ,CB_MAX_RB_STUFE1_WITH_INT_OG          },      /*539*/
  {CB_DEF_NACHWISCH_4_ST1_MIN            ,CB_MIN_NACHWISCH_4_ST1_MIN            ,CB_MAX_NACHWISCH_4_ST1_MIN            },      /*540*/
  {CB_DEF_NACHWISCH_3                    ,CB_MIN_NACHWISCH_3                    ,CB_MAX_NACHWISCH_3                    },      /*541*/
  {CB_DEF_NACHWISCH_2                    ,CB_MIN_NACHWISCH_2                    ,CB_MAX_NACHWISCH_2                    },      /*542*/
  {CB_DEF_RSEMPFFACTORSCALING_1          ,CB_MIN_RSEMPFFACTORSCALING            ,CB_MAX_RSEMPFFACTORSCALING            },      /*543*/    
  {CB_DEF_SCHLIEREN_FLAG                 ,CB_MIN_SCHLIEREN_FLAG                 ,CB_MAX_SCHLIEREN_FLAG                 },      /*544*/
  {CB_DEF_SIG_ANS_SCHW_OFFS              ,CB_MIN_SIG_ANS_SCHW_OFFS              ,CB_MAX_SIG_ANS_SCHW_OFFS              },      /*545*/
 
 /* For Parameter 2 */ 
  {CB_DEF_STUFE1_OG                      ,CB_MIN_STUFE1_OG                      ,CB_MAX_STUFE1_OG                      },      /*546*/
  {CB_DEF_STUFE1_UG                      ,CB_MIN_STUFE1_UG                      ,CB_MAX_STUFE1_UG                      },      /*547*/
  {CB_DEF_EP_ST2_EPR_IN_ST2              ,CB_MIN_EP_ST2_EPR_IN_ST2              ,CB_MAX_EP_ST2_EPR_IN_ST2              },      /*548*/
  {CB_DEF_SCHWELLE_SCHWALL               ,CB_MIN_SCHWELLE_SCHWALL               ,CB_MAX_SCHWELLE_SCHWALL               },      /*549*/  
  {CB_DEF_ANSAMLUN_ADIT_OFFS             ,CB_MIN_ANSAMLUN_ADIT_OFFS             ,CB_MAX_ANSAMLUN_ADIT_OFFS             },      /*550*/
  {CB_DEF_DEC_INT_SP_OFF                 ,CB_MIN_DEC_INT_SP_OFF                 ,CB_MAX_DEC_INT_SP_OFF                 },      /*551*/
  {CB_DEF_DEC_STX_SPEICHER               ,CB_MIN_DEC_STX_SPEICHER               ,CB_MAX_DEC_STX_SPEICHER               },      /*552*/
  {CB_DEF_DEC_OVR_SPEICHER               ,CB_MIN_DEC_OVR_SPEICHER               ,CB_MAX_DEC_OVR_SPEICHER               },      /*553*/
  {CB_DEF_EMPF_FAKTOR_ST2_OFFS           ,CB_MIN_EMPF_FAKTOR_ST2_OFFS           ,CB_MAX_EMPF_FAKTOR_ST2_OFFS           },      /*554*/
  {CB_DEF_MAX_SIGNALLAENGE               ,CB_MIN_MAX_SIGNALLAENGE               ,CB_MAX_MAX_SIGNALLAENGE               },      /*555*/
  {CB_DEF_RB_STUFE1_WITH_INT_OG          ,CB_MIN_RB_STUFE1_WITH_INT_OG          ,CB_MAX_RB_STUFE1_WITH_INT_OG          },      /*556*/
  {CB_DEF_NACHWISCH_4_ST1_MIN            ,CB_MIN_NACHWISCH_4_ST1_MIN            ,CB_MAX_NACHWISCH_4_ST1_MIN            },      /*557*/
  {CB_DEF_NACHWISCH_3                    ,CB_MIN_NACHWISCH_3                    ,CB_MAX_NACHWISCH_3                    },      /*558*/
  {CB_DEF_NACHWISCH_2                    ,CB_MIN_NACHWISCH_2                    ,CB_MAX_NACHWISCH_2                    },      /*559*/
  {CB_DEF_RSEMPFFACTORSCALING            ,CB_MIN_RSEMPFFACTORSCALING            ,CB_MAX_RSEMPFFACTORSCALING            },      /*560*/   
  {CB_DEF_SCHLIEREN_FLAG                 ,CB_MIN_SCHLIEREN_FLAG                 ,CB_MAX_SCHLIEREN_FLAG                 },      /*561*/
  {CB_DEF_SIG_ANS_SCHW_OFFS              ,CB_MIN_SIG_ANS_SCHW_OFFS              ,CB_MAX_SIG_ANS_SCHW_OFFS              },      /*562*/

  /* For Parameter 3 */ 
  {CB_DEF_STUFE1_OG                      ,CB_MIN_STUFE1_OG                      ,CB_MAX_STUFE1_OG                      },      /*563*/
  {CB_DEF_STUFE1_UG                      ,CB_MIN_STUFE1_UG                      ,CB_MAX_STUFE1_UG                      },      /*564*/
  {CB_DEF_EP_ST2_EPR_IN_ST2              ,CB_MIN_EP_ST2_EPR_IN_ST2              ,CB_MAX_EP_ST2_EPR_IN_ST2              },      /*565*/
  {CB_DEF_SCHWELLE_SCHWALL               ,CB_MIN_SCHWELLE_SCHWALL               ,CB_MAX_SCHWELLE_SCHWALL               },      /*566*/  
  {CB_DEF_ANSAMLUN_ADIT_OFFS             ,CB_MIN_ANSAMLUN_ADIT_OFFS             ,CB_MAX_ANSAMLUN_ADIT_OFFS             },      /*567*/
  {CB_DEF_DEC_INT_SP_OFF                 ,CB_MIN_DEC_INT_SP_OFF                 ,CB_MAX_DEC_INT_SP_OFF                 },      /*568*/
  {CB_DEF_DEC_STX_SPEICHER               ,CB_MIN_DEC_STX_SPEICHER               ,CB_MAX_DEC_STX_SPEICHER               },      /*569*/
  {CB_DEF_DEC_OVR_SPEICHER               ,CB_MIN_DEC_OVR_SPEICHER               ,CB_MAX_DEC_OVR_SPEICHER               },      /*570*/
  {CB_DEF_EMPF_FAKTOR_ST2_OFFS           ,CB_MIN_EMPF_FAKTOR_ST2_OFFS           ,CB_MAX_EMPF_FAKTOR_ST2_OFFS           },      /*571*/
  {CB_DEF_MAX_SIGNALLAENGE               ,CB_MIN_MAX_SIGNALLAENGE               ,CB_MAX_MAX_SIGNALLAENGE               },      /*572*/
  {CB_DEF_RB_STUFE1_WITH_INT_OG          ,CB_MIN_RB_STUFE1_WITH_INT_OG          ,CB_MAX_RB_STUFE1_WITH_INT_OG          },      /*573*/
  {CB_DEF_NACHWISCH_4_ST1_MIN            ,CB_MIN_NACHWISCH_4_ST1_MIN            ,CB_MAX_NACHWISCH_4_ST1_MIN            },      /*574*/
  {CB_DEF_NACHWISCH_3                    ,CB_MIN_NACHWISCH_3                    ,CB_MAX_NACHWISCH_3                    },      /*575*/
  {CB_DEF_NACHWISCH_2                    ,CB_MIN_NACHWISCH_2                    ,CB_MAX_NACHWISCH_2                    },      /*576*/
  {CB_DEF_RSEMPFFACTORSCALING_1          ,CB_MIN_RSEMPFFACTORSCALING            ,CB_MAX_RSEMPFFACTORSCALING            },      /*577*/    
  {CB_DEF_SCHLIEREN_FLAG                 ,CB_MIN_SCHLIEREN_FLAG                 ,CB_MAX_SCHLIEREN_FLAG                 },      /*578*/
  {CB_DEF_SIG_ANS_SCHW_OFFS              ,CB_MIN_SIG_ANS_SCHW_OFFS              ,CB_MAX_SIG_ANS_SCHW_OFFS              },      /*579*/

  {CB_DEF_GAINSETUP_0_1                  ,CB_MIN_GAINSETUP                      ,CB_MAX_GAINSETUP                      },       /*580*/
  {CB_DEF_GAINSETUP_2_3                  ,CB_MIN_GAINSETUP                      ,CB_MAX_GAINSETUP                      },       /*581*/
  {CB_DEF_GAINSETUP_4_5                  ,CB_MIN_GAINSETUP                      ,CB_MAX_GAINSETUP                      },       /*582*/
  {CB_DEF_GAINSETUP_6_7                  ,CB_MIN_GAINSETUP                      ,CB_MAX_GAINSETUP                      },       /*583*/
  {CB_DEF_GAINSETUP_8_9                  ,CB_MIN_GAINSETUP                      ,CB_MAX_GAINSETUP                      },       /*584*/
  {CB_DEF_GAINSETUP_10_MOD               ,CB_MIN_GAINSETUP                      ,CB_MAX_GAINSETUP                      },       /*585*/
  {CB_DEF_HALIOS_CLOCK_CONTROL_REG       ,CB_MIN_HALIOS_CLOCK_CONTROL_REG       ,CB_MAX_HALIOS_CLOCK_CONTROL_REG       },       /*586*/
  {CB_DEF_ACTR_REG                       ,CB_MIN_ACTR_REG                       ,CB_MAX_ACTR_REG                       },       /*587*/
  {CB_DEF_PCO_PI_REGULATOR               ,CB_MIN_PCO_PI_REGULATOR               ,CB_MAX_PCO_PI_REGULATOR               },       /*588*/
  {CB_DEF_ICO1H                          ,CB_MIN_ICO1H                          ,CB_MAX_ICO1H                          },       /*589*/
  {CB_DEF_ICO1L                          ,CB_MIN_ICO1L                          ,CB_MAX_ICO1L                          },       /*590*/
  {CB_DEF_ICO2H                          ,CB_MIN_ICO2H                          ,CB_MAX_ICO2H                          },       /*591*/
  {CB_DEF_ICO2L                          ,CB_MIN_ICO2L                          ,CB_MAX_ICO2L                          },       /*592*/
  {CB_DEF_FOSC_LEDUL                     ,CB_MIN_FOSC_LEDUL                     ,CB_MAX_FOSC_LEDUL                     },       /*593*/
  {CB_DEF_INTCO                          ,CB_MIN_INTCO                          ,CB_MAX_INTCO                          },       /*594*/
  {CB_DEF_STANDBYTIMOUT                  ,CB_MIN_STANDBYTIMOUT                  ,CB_MAX_STANDBYTIMOUT                  },       /*595*/
  {CB_DEF_DEC_ST2_SPEICHER               ,CB_MIN_DEC_ST2_SPEICHER               ,CB_MAX_DEC_ST2_SPEICHER               },       /*596*/ 
  {CB_DEF_RS_SENSITIVITY_0               ,CB_MIN_RS_SENSITIVITY_0               ,CB_MAX_RS_SENSITIVITY_0               },       /*597*/
  {CB_DEF_RS_SENSITIVITY_1               ,CB_MIN_RS_SENSITIVITY_1               ,CB_MAX_RS_SENSITIVITY_1               },       /*598*/
  {CB_DEF_RS_SENSITIVITY_2               ,CB_MIN_RS_SENSITIVITY_2               ,CB_MAX_RS_SENSITIVITY_2               },       /*599*/
  {CB_DEF_RS_SENSITIVITY_3               ,CB_MIN_RS_SENSITIVITY_3               ,CB_MAX_RS_SENSITIVITY_3               },       /*600*/
  {CB_DEF_RS_SENSITIVITY_4               ,CB_MIN_RS_SENSITIVITY_4               ,CB_MAX_RS_SENSITIVITY_4               },       /*601*/
  {CB_DEF_RS_SENSITIVITY_5               ,CB_MIN_RS_SENSITIVITY_5               ,CB_MAX_RS_SENSITIVITY_5               },       /*602*/
  {CB_DEF_RS_SENSITIVITY_6               ,CB_MIN_RS_SENSITIVITY_6               ,CB_MAX_RS_SENSITIVITY_6               },       /*603*/
  {CB_DEF_RS_SENSITIVITY_7               ,CB_MIN_RS_SENSITIVITY_7               ,CB_MAX_RS_SENSITIVITY_7               },       /*604*/
  {CB_DEF_RS_SENSITIVITY_8               ,CB_MIN_RS_SENSITIVITY_8               ,CB_MAX_RS_SENSITIVITY_8               },       /*605*/
  {CB_DEF_MAXOVERWIPESENSITIVITY         ,CB_MIN_MAXOVERWIPESENSITIVITY         ,CB_MAX_MAXOVERWIPESENSITIVITY         },       /*606*/ 
  {CB_DEF_STANDBYMODESCANTIME            ,CB_MIN_STANDBYMODESCANTIME            ,CB_MAX_STANDBYMODESCANTIME            },       /*607*/
  {CB_DEF_RAINNIGHTBITTHRS               ,CB_MIN_RAINNIGHTBITTHRS               ,CB_MAX_RAINNIGHTBITTHRS               },       /*608*/
  {CB_DEF_AMB_BASE_DAY_THRESHOLD         ,CB_MIN_AMB_BASE_DAY_THRESHOLD         ,CB_MAX_AMB_BASE_DAY_THRESHOLD         },       /*609*/
  {CB_DEF_AMB_BASE_NIGHT_THRESHOLD       ,CB_MIN_AMB_BASE_NIGHT_THRESHOLD       ,CB_MAX_AMB_BASE_NIGHT_THRESHOLD       },       /*610*/
  {CB_DEF_TUNNELDEBOUNCEFACTOR           ,CB_MIN_TUNNELDEBOUNCEFACTOR           ,CB_MAX_TUNNELDEBOUNCEFACTOR           },       /*611*/
  {CB_DEF_CUSTOMER_FW_SWA_SCALING        ,CB_MIN_CUSTOMER_FW_SWA_SCALING        ,CB_MAX_CUSTOMER_FW_SWA_SCALING        },       /*612*/
  {CB_DEF_CUSTOMER_IR_SWA_SCALING        ,CB_MIN_CUSTOMER_IR_SWA_SCALING        ,CB_MAX_CUSTOMER_IR_SWA_SCALING        },       /*613*/
  {CB_DEF_FW_BASE_DAY_THRESHOLD          ,CB_MIN_FW_BASE_DAY_THRESHOLD          ,CB_MAX_FW_BASE_DAY_THRESHOLD          },       /*614*/
  {CB_DEF_IR_BASE_DAY_THRESHOLD          ,CB_MIN_IR_BASE_DAY_THRESHOLD          ,CB_MAX_IR_BASE_DAY_THRESHOLD          },       /*615*/
  {CB_DEF_FW_BASE_NIGHT_THRESHOLD        ,CB_MIN_FW_BASE_NIGHT_THRESHOLD        ,CB_MAX_FW_BASE_NIGHT_THRESHOLD        },       /*616*/
  {CB_DEF_IR_BASE_NIGHT_THRESHOLD        ,CB_MIN_IR_BASE_NIGHT_THRESHOLD        ,CB_MAX_IR_BASE_NIGHT_THRESHOLD        },       /*617*/
  {CB_DEF_DAY_DELAY                      ,CB_MIN_DAY_DELAY                      ,CB_MAX_DAY_DELAY                      },       /*618*/
  {CB_DEF_NIGHT_DELAY                    ,CB_MIN_NIGHT_DELAY                    ,CB_MAX_NIGHT_DELAY                    },       /*619*/
  {CB_DEF_AFTERTUNNELDELAYOFFS           ,CB_MIN_AFTERTUNNELDELAYOFFS           ,CB_MAX_AFTERTUNNELDELAYOFFS           },       /*620*/    
  {CB_DEF_AUTOBAHN_ON_OFF                ,CB_MIN_AUTOBAHN_ON_OFF                ,CB_MAX_AUTOBAHN_ON_OFF                },       /*621*/  
  {CB_DEF_AUTOBAHN_DELAY_ON              ,CB_MIN_AUTOBAHN_DELAY_ON              ,CB_MAX_AUTOBAHN_DELAY_ON              },       /*622*/
  {CB_DEF_FRONTWASCHEN_AUTOBAHNDELAY     ,CB_MIN_FRONTWASCHEN_AUTOBAHNDELAY     ,CB_MAX_FRONTWASCHEN_AUTOBAHNDELAY     },       /*623*/  
  {CB_DEF_REGENLICHTSCHWELLE_LOW_HIGH    ,CB_MIN_REGENLICHTSCHWELLE_LOW_HIGH    ,CB_MAX_REGENLICHTSCHWELLE_LOW_HIGH    },       /*624*/  
  {CB_DEF_REGENLICHTSCHWELLE_ZEIT        ,CB_MIN_REGENLICHTSCHWELLE_ZEIT        ,CB_MAX_REGENLICHTSCHWELLE_ZEIT        },       /*625*/  
  {CB_DEF_TUNNELTHRESHOLDSCALING         ,CB_MIN_TUNNELTHRESHOLDSCALING         ,CB_MAX_TUNNELTHRESHOLDSCALING         },       /*626*/
  {CB_DEF_AMB_TUNNELTHRESHOLDSCALING     ,CB_MIN_AMB_TUNNELTHRESHOLDSCALING     ,CB_MAX_AMB_TUNNELTHRESHOLDSCALING     },       /*627*/
  {UNUSED          ,UNUSED          ,UNUSED          },       /*628*/
  {CB_DEF_REGULATION48LIGHTONTIME        ,CB_MIN_REGULATION48LIGHTONTIME        ,CB_MAX_REGULATION48LIGHTONTIME        },       /*629*/
  {CB_DEF_VERYBRIGHTINTUNNELDELAY        ,CB_MIN_VERYBRIGHTINTUNNELDELAY        ,CB_MAX_VERYBRIGHTINTUNNELDELAY        },       /*630*/
  {CB_DEF_COMBINED_FW_AL_THRS            ,CB_MIN_COMBINED_FW_AL_THRS            ,CB_MAX_COMBINED_FW_AL_THRS            },       /*631*/  
  {CB_DEF_DYN_COMP_CCD_MINUS_1           ,CB_MIN_DYN_COMP_CCD_MINUS_1           ,CB_MAX_DYN_COMP_CCD_MINUS_1           },       /*632*/ 
  {CB_DEF_DYN_COMP_CCD_MINUS_2           ,CB_MIN_DYN_COMP_CCD_MINUS_2           ,CB_MAX_DYN_COMP_CCD_MINUS_2           },       /*633*/  
  {CB_DEF_MAXTEMPERATUREOFFSETT          ,CB_MIN_MAXTEMPERATUREOFFSETT          ,CB_MAX_MAXTEMPERATUREOFFSETT          },       /*634*/   
  {CB_DEF_ASIC_AFSTHR_REG                ,CB_MIN_ASIC_AFSTHR_REG                ,CB_MAX_ASIC_AFSTHR_REG                },       /*635*/
  {CB_DEF_DIAG_REQUEST_FACTOR            ,CB_MIN_DIAG_REQUEST_FACTOR            ,CB_MAX_DIAG_REQUEST_FACTOR            },       /*636*/
  {CB_DEF_INC_SPEICHER                   ,CB_MIN_INC_SPEICHER                   ,CB_MAX_INC_SPEICHER                   },       /*637*/
  {CB_DEF_I2C_DEBUG_CONFIG               ,CB_MIN_I2C_DEBUG_CONFIG               ,CB_MAX_I2C_DEBUG_CONFIG               },       /*638*/
  {CB_DEF_AUDI_SW_PART_NUMBER_1          ,CB_MIN_AUDI_SW_PART_NUMBER_1          ,CB_MAX_AUDI_SW_PART_NUMBER_1          },       /*639*/
  {CB_DEF_AUDI_SW_PART_NUMBER_2          ,CB_MIN_AUDI_SW_PART_NUMBER_2          ,CB_MAX_AUDI_SW_PART_NUMBER_2          },       /*640*/
  {CB_DEF_AUDI_SW_PART_NUMBER_3          ,CB_MIN_AUDI_SW_PART_NUMBER_3          ,CB_MAX_AUDI_SW_PART_NUMBER_3          },       /*641*/
  {CB_DEF_AUDI_SW_PART_NUMBER_4_5        ,CB_MIN_AUDI_SW_PART_NUMBER_4_5        ,CB_MAX_AUDI_SW_PART_NUMBER_4_5        },       /*642*/
  {CB_DEF_AUDI_SW_PART_NUMBER_6_7        ,CB_MIN_AUDI_SW_PART_NUMBER_6_7        ,CB_MAX_AUDI_SW_PART_NUMBER_6_7        },       /*643*/
  {CB_DEF_AUDI_SW_PART_NUMBER_8_9        ,CB_MIN_AUDI_SW_PART_NUMBER_8_9        ,CB_MAX_AUDI_SW_PART_NUMBER_8_9        },       /*644*/
  {CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX   ,CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX   ,CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX   },       /*645*/
  {CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX   ,CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX   ,CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX   },       /*646*/

  {CB_DEF_WIPER_SPEED_HYSTERESIS         ,CB_MIN_WIPER_SPEED_HYSTERESIS         ,CB_MAX_WIPER_SPEED_HYSTERESIS         },       /*647*/ 
  {CB_DEF_PRJ_SPECIFIC_CONFIG            ,CB_MIN_PRJ_SPECIFIC_CONFIG            ,CB_MAX_PRJ_SPECIFIC_CONFIG            },       /*648*/ 
  {CB_DEF_ALSX_FILTER                    ,CB_MIN_ALSX_FILTER                    ,CB_MAX_ALSX_FILTER                    },       /*649*/ 
  {CB_DEF_LIGHT_CTRL_SETTINGS1           ,CB_MIN_LIGHT_CTRL_SETTINGS1           ,CB_MAX_LIGHT_CTRL_SETTINGS1           },       /*650*/ 
  {CB_DEF_LIGHT_CTRL_SETTINGS2           ,CB_MIN_LIGHT_CTRL_SETTINGS2           ,CB_MAX_LIGHT_CTRL_SETTINGS2           },       /*651*/ 
  {CB_DEF_LIGHT_CTRL_SETTINGS3           ,CB_MIN_LIGHT_CTRL_SETTINGS3           ,CB_MAX_LIGHT_CTRL_SETTINGS3           },       /*652*/ 
  /*VCO_260 Tunnel wipe activation and delay according to Tunnel Verzoegerung and Aktivierung parameters*/
  {CB_DEF_TUNWISCHVERZAKTIV              ,CB_MIN_TUNWISCHVERZAKTIV              ,CB_MAX_TUNWISCHVERZAKTIV              },       /*653*/ 
  {CB_DEF_SHTERRDEBOUNCEJITTER           ,CB_MIN_SHTERRDEBOUNCEJITTER           ,CB_MAX_SHTERRDEBOUNCEJITTER           },       /*654*/ 
  {CB_DEF_SLOAR_SHADOW_CORR_FACTOR1      ,CB_MIN_SLOAR_SHADOW_CORR_FACTOR1      ,CB_MAX_SLOAR_SHADOW_CORR_FACTOR1      },       /*655*/ 
  {CB_DEF_SLOAR_SHADOW_CORR_FACTOR2      ,CB_MIN_SLOAR_SHADOW_CORR_FACTOR2      ,CB_MAX_SLOAR_SHADOW_CORR_FACTOR2      },       /*656*/ 
  {CB_DEF_E2_MAXST2SIGNALLAENGE          ,CB_MIN_E2_MAXST2SIGNALLAENGE          ,CB_MAX_E2_MAXST2SIGNALLAENGE          },       /*657*/ 
  
  {CB_DEF_SOFTWARESTAND_0                ,CB_MIN_SOFTWARESTAND_0                ,CB_MAX_SOFTWARESTAND_0                },       /*658*/
  {CB_DEF_SOFTWARESTAND_1                ,CB_MIN_SOFTWARESTAND_1                ,CB_MAX_SOFTWARESTAND_1                },       /*659*/
  {CB_DEF_SOFTWARESTAND_2                ,CB_MIN_SOFTWARESTAND_2                ,CB_MAX_SOFTWARESTAND_2                },       /*660*/
  {CB_DEF_SOFTWARESTAND_3                ,CB_MIN_SOFTWARESTAND_3                ,CB_MAX_SOFTWARESTAND_3                },       /*661*/    /*(Muss immer am Schluss sein!!!)*/
  
  {CB_DEF_DARK_TO_TWILIGHT_TIME          ,CB_MIN_DARK_TO_TWILIGHT_TIME          ,CB_MAX_DARK_TO_TWILIGHT_TIME          },       /*662*/    
  {CB_DEF_TWILIGHT_TO_DARK_TIME          ,CB_MIN_TWILIGHT_TO_DARK_TIME          ,CB_MAX_TWILIGHT_TO_DARK_TIME          },       /*663*/
  
  {CB_DEF_DARK_TO_TWILIGHT_THRESH_FW     ,CB_MIN_DARK_TO_TWILIGHT_THRESH_FW     ,CB_MAX_DARK_TO_TWILIGHT_THRESH_FW     },       /*664*/    
  {CB_DEF_DARK_TO_TWILIGHT_THRESH_AMB    ,CB_MIN_DARK_TO_TWILIGHT_THRESH_AMB    ,CB_MAX_DARK_TO_TWILIGHT_THRESH_AMB    },       /*665*/    
  
  {CB_DEF_TWILIGHT_TO_DARK_THRESH_FW     ,CB_MIN_TWILIGHT_TO_DARK_THRESH_FW     ,CB_MAX_TWILIGHT_TO_DARK_THRESH_FW     },       /*666*/    
  {CB_DEF_TWILIGHT_TO_DARK_THRESH_AMB    ,CB_MIN_TWILIGHT_TO_DARK_THRESH_AMB    ,CB_MAX_TWILIGHT_TO_DARK_THRESH_AMB    },       /*667*/
  {CB_DEF_ICE_DETECTION_TEMPERATURE      ,CB_MIN_ICE_DETECTION_TEMPERATURE      ,CB_MAX_ICE_DETECTION_TEMPERATURE      },       /*668*/    
  {CB_DEF_REGULATION48THRESHOLD_AMB      ,CB_MIN_REGULATION48THRESHOLD_AMB      ,CB_MAX_REGULATION48THRESHOLD_AMB      },       /*669*/    
  {CB_DEF_REGULATION48THRESHOLD_FW       ,CB_MIN_REGULATION48THRESHOLD_FW       ,CB_MAX_REGULATION48THRESHOLD_FW       },       /*670*/    
#if defined FORD
  
  {CB_DEF_CAR_CODE_00                    ,CB_MIN_CAR_CODE_00                    ,CB_MAX_CAR_CODE_00                    },       /*671*/    
  {CB_DEF_CAR_CODE_01                    ,CB_MIN_CAR_CODE_01                    ,CB_MAX_CAR_CODE_01                    },       /*672*/    
  {CB_DEF_CAR_CODE_02                    ,CB_MIN_CAR_CODE_02                    ,CB_MAX_CAR_CODE_02                    },       /*673*/    
  {CB_DEF_CAR_CODE_03                    ,CB_MIN_CAR_CODE_03                    ,CB_MAX_CAR_CODE_03                    },       /*674*/    
  {CB_DEF_CAR_CODE_04                    ,CB_MIN_CAR_CODE_04                    ,CB_MAX_CAR_CODE_04                    },       /*675*/    
  {CB_DEF_CAR_CODE_05                    ,CB_MIN_CAR_CODE_05                    ,CB_MAX_CAR_CODE_05                    },       /*676*/    
  {CB_DEF_CAR_CODE_06                    ,CB_MIN_CAR_CODE_06                    ,CB_MAX_CAR_CODE_06                    },       /*677*/    
  {CB_DEF_CAR_CODE_07                    ,CB_MIN_CAR_CODE_07                    ,CB_MAX_CAR_CODE_07                    },       /*678*/    
  {CB_DEF_CAR_CODE_08                    ,CB_MIN_CAR_CODE_08                    ,CB_MAX_CAR_CODE_08                    },       /*679*/    
  {CB_DEF_CAR_CODE_09                    ,CB_MIN_CAR_CODE_09                    ,CB_MAX_CAR_CODE_09                    },       /*680*/    
  {CB_DEF_CAR_CODE_10                    ,CB_MIN_CAR_CODE_10                    ,CB_MAX_CAR_CODE_10                    },       /*681*/    
  {CB_DEF_CAR_CODE_11                    ,CB_MIN_CAR_CODE_11                    ,CB_MAX_CAR_CODE_11                    },       /*682*/    
  {CB_DEF_CAR_CODE_12                    ,CB_MIN_CAR_CODE_12                    ,CB_MAX_CAR_CODE_12                    },       /*683*/    
  {CB_DEF_CAR_CODE_13                    ,CB_MIN_CAR_CODE_13                    ,CB_MAX_CAR_CODE_13                    },       /*684*/    
  {CB_DEF_CAR_CODE_14                    ,CB_MIN_CAR_CODE_14                    ,CB_MAX_CAR_CODE_14                    },       /*685*/    
  {CB_DEF_CAR_CODE_15                    ,CB_MIN_CAR_CODE_15                    ,CB_MAX_CAR_CODE_15                    },       /*686*/    
  {CB_DEF_DOUBLE_OVER_WIPED_0_7          ,CB_MIN_DOUBLE_OVER_WIPED_0_7          ,CB_MAX_DOUBLE_OVER_WIPED_0_7          },       /*687*/    
  {CB_DEF_DOUBLE_OVER_WIPED_8_15         ,CB_MIN_DOUBLE_OVER_WIPED_8_15         ,CB_MAX_DOUBLE_OVER_WIPED_8_15         },       /*688*/    
  {CB_DEF_BUTTERFLY_0_7                  ,CB_MIN_BUTTERFLY_0_7                  ,CB_MAX_BUTTERFLY_0_7                  },       /*689*/    
  {CB_DEF_BUTTERFLY_8_15                 ,CB_MIN_BUTTERFLY_8_15                 ,CB_MAX_BUTTERFLY_8_15                 },       /*690*/    
  {CB_DEF_RSCONFIG                       ,CB_MIN_RSCONFIG                       ,CB_MAX_RSCONFIG                       },       /*691*/    
  {CB_DEF_RSSENSMAPPING                  ,CB_MIN_RSSENSMAPPING                  ,CB_MAX_RSSENSMAPPING                  },       /*692*/    
  {CB_DEF_WIPERSIGNAL                    ,CB_MIN_WIPERSIGNAL                    ,CB_MAX_WIPERSIGNAL                    },       /*693*/    
  {CB_DEF_WIPERMOTORTIME                 ,CB_MIN_WIPERMOTORTIME                 ,CB_MAX_WIPERMOTORTIME                 },       /*694*/    
  {CB_DEF_PARTNUMBER_1                   ,CB_MIN_PARTNUMBER_1                   ,CB_MAX_PARTNUMBER_1                   },       /*695*/    
  {CB_DEF_PARTNUMBER_2                   ,CB_MIN_PARTNUMBER_2                   ,CB_MAX_PARTNUMBER_2                   },       /*696*/    
  {CB_DEF_PARTNUMBER_3                   ,CB_MIN_PARTNUMBER_3                   ,CB_MAX_PARTNUMBER_3                   },       /*697*/    
  {CB_DEF_PARTNUMBER_4                   ,CB_MIN_PARTNUMBER_4                   ,CB_MAX_PARTNUMBER_4                   },       /*698*/    
  {CB_DEF_PARTNUMBER_5                   ,CB_MIN_PARTNUMBER_5                   ,CB_MAX_PARTNUMBER_5                   },       /*699*/    
  {CB_DEF_PARTNUMBER_5                   ,CB_MIN_PARTNUMBER_5                   ,CB_MAX_PARTNUMBER_5                   },       /*700*/    
  {CB_DEF_FADEOUT                        ,CB_MIN_FADEOUT                        ,CB_MAX_FADEOUT                        },       /*701*/    
  {CB_DEF_SENSITIVITYBARRIER             ,CB_MIN_SENSITIVITYBARRIER             ,CB_MAX_SENSITIVITYBARRIER             },       /*702*/
  {CB_DEF_THRESHOLD_FIRSTOWIPE_START     ,CB_MIN_THRESHOLD_FIRSTOWIPE_START     ,CB_MAX_THRESHOLD_FIRSTOWIPE_START     },       /*703*/
  {CB_DEF_THRESHOLD_FIRSTOWIPE_END       ,CB_MIN_THRESHOLD_FIRSTOWIPE_END       ,CB_MAX_THRESHOLD_FIRSTOWIPE_END       },       /*704*/
  {CB_DEF_THRESHOLD_OVERWIPE             ,CB_MIN_THRESHOLD_OVERWIPE             ,CB_MAX_THRESHOLD_OVERWIPE             },       /*705*/
 
#else
  
  {CB_DEF_THRESHOLD_TEMPICERISK          ,CB_MIN_THRESHOLD_TEMPICERISK          ,CB_MAX_THRESHOLD_TEMPICERISK          },       /*671*/      
  {CB_DEF_UPPER_TOL_SUW                  ,CB_MIN_UPPER_TOL_SUW                  ,CB_MAX_UPPER_TOL_SUW                  },       /*672*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*673*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*674*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*675*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*676*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*677*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*678*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*679*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*680*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*681*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*682*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*683*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*684*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*685*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*686*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*687*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*688*/    
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*689*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*690*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*691*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*692*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*693*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*694*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*695*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*696*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*697*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*698*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*699*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*700*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*701*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*702*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*703*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*704*/  
  {UNUSED                                ,UNUSED                                ,UNUSED                                },       /*705*/   
#endif  
};


#else

extern const byte __far cb_EEPROMDataDefaultMinMax_AD_g[cb_NumberofEEPROMCells_AD_g][3];
#define EXTERN  extern
#endif

typedef struct {
 
  byte Stufe1_OG;                     
  byte Stufe1_UG;                     
  byte Ep_St2_Epr_In_St2;             
  byte Schwelle_Schwall;             
  byte CW_AnsamlungAdditOffset;      
  byte dec_Int_Sp_off;                
  byte Dec_Stx_Speicher;             
  byte dec_Ovr_Speicher;               
  byte Empf_Faktor_ST2_Offs;          
  byte Max_Signallaenge;              
  byte rb_Stufe1_with_Int_og;         
  byte Nachwisch_4_ST1_min;           
  byte Nachwisch_3;                   
  byte Nachwisch_2;                   
  byte RSEmpfFactorScaling;           
  byte SchlierenFlag1;                
  byte sig_ans_schw_offs;            
  
}s_rb_PrametersStruct_g;



typedef struct {
 s_rb_PrametersStruct_g PrametersStruct[4]; /* 512 to 579 */
  byte RS_GainSetupArray[6];          /*580,581,582,583,584,585*/    
  byte HALIOS_Clock_Control_Reg_g;    /*586*/
  byte ACTR_Reg_g;                    /*587*/
  byte PCO_PI_Regulator_g;            /*588*/
  byte ICO1H_g;                       /*589*/  
  byte ICO1L_g;                       /*590*/  
  byte ICO2H_g;                       /*591*/  
  byte ICO2L_g;                       /*592*/  
  byte FOSC_LEDUL_g;                  /*593*/ 
  byte INTCO_g;                       /*594*/  
  byte StandbyTimout;                 /*595*/ 
  byte dec_st2_speicher;              /*596*/ 
  byte RS_Sensitivity[9];             /*597,598,599,600,601,602,603,604,605*/            
  byte MaxOverwipeSensitivity;        /*606*/  
  byte StandbyModeScanTime_g;         /*607*/ 
  byte RainNightBitThrs_g;            /*608*/
  byte Amb_Base_Day_Threshold;        /*609*/
  byte Amb_Base_Night_Threshold;      /*610*/   
  byte TunnelDebounceFactor;          /*611*/                           
  byte Customer_FW_SWA_Scaling;       /*612*/
  byte Customer_IR_SWA_Scaling;       /*613*/
  byte FW_Base_Day_Threshold;         /*614*/
  byte IR_Base_Day_Threshold;         /*615*/
  byte FW_Base_Night_Threshold;       /*616*/
  byte IR_Base_Night_Threshold;       /*617*/    
  byte Day_Delay;                     /*618*/
  byte Night_Delay;                   /*619*/
  byte AfterTunnelDelayOffs;          /*620*/ 
  byte p_v_autobahn_on_off_g;         /*621*/
  byte p_t_autobahn_delay_on_g;       /*622*/
  byte Frontwaschen_Autobahndelay_g;    /*623*/  
  byte p_n_regenlichtschwelle_low_high_g;/*624*/ 
  byte p_n_regenlichtschwelle_Zeit_g;   /*625*/ 
  byte TunnelThresholdScaling_g;      /*626*/ 
  byte Amb_TunnelThresholdScaling_g;  /*627*/ 
  byte spare;                         /*628*/ /* old: Regulation48Threshold_g */
  byte Regulation48LightOnTime_g;     /*629*/ 
  byte VeryBrightInTunnelDelay_g;     /*630*/ 
  byte Combined_FW_AL_THRs_g;         /*631*/ 
  byte DYN_COMP_CCD_MINUS_1_g;        /*632*/  
  byte DYN_COMP_CCD_MINUS_2_g;        /*633*/
  byte maxTemperatureOffsett_g;       /*634*/ 
  byte ASIC_AFSTHR_REG_g;              /*635*/ 
  byte Diag_Request_Factor_g;          /*636*/ 
  byte cb_inc_speicher_g;              /*637*/ 
  byte I2C_Debug_Config_g;             /*638*/ 
  byte Audi_SW_Partnumber[8];          /*639,640,641,642,643,644,645,646*/ 
  byte wiperSpeedHysteresis;           /*647*/   
  byte Proj_Specific_config;           /*648*/   
  byte ALSx_Filter_g;                  /*649*/   
  byte IrLightTunnelThreshodRng;       /*650*/   
  byte FwLightTunnelThresholdRng;      /*651*/   
  byte AmbLightTunnelThresholdRng;     /*652*/
  /*VCO_260 Tunnel wipe activation and delay according to Tunnel Verzoegerung and Aktivierung parameters*/
  byte TunWischVerzAktiv;              /*653*/   
  byte SHTErrorDebounceJitter;         /*654*/   
  byte SolarShadowCorrFactor1;         /*655*/   
  byte SolarShadowCorrFactor2;         /*656*/   
  byte E2_MaxSt2SignalLaenge;          /*657*/   
      
  byte SoftwareStand[4];              /* 658,659,660,661 */
  
  byte twilightToDarkTime;              /*662*/
  byte darkToTwilightTime;              /*663*/
  
  byte darkToTwilightThreshFW;          /*664*/
  byte darkToTwilightThreshAMB;         /*665*/
  
  byte twilightToDarkThreshFW;          /*666*/
  byte twilightToDarkThreshAMB;         /*667*/
  byte iceDetectionTemperature;         /*668*/
  byte Regulation48ThresholdAmb_g;      /*669*/  
  byte Regulation48ThresholdFw_g;       /*670*/ 
#if defined FORD
  byte CarCode[16];                     /*671-686*/
  byte DoubleOverwiped[2];              /*687-688*/ 
  byte Butterfly[2];                    /*689-690*/ 
  byte RsConfig;                        /*691*/ 
  byte RsSensMapping;                   /*692*/ 
  byte WiperSignal;                     /*693*/ 
  byte WiperMotorTime;                  /*694*/ 
  byte PartNumber[6];                   /*695-700*/ 
  byte FadeOut;                         /*701*/ 
  byte SensitivityBarrier;              /*702*/
  byte Threshold_FirstOverwipe_Start;   /*703*/
  byte Threshold_FirstOverwipe_End;     /*704*/
  byte Threshold_Overwipe;              /*705*/
#else
  byte Threshold_TempIceRisk;           /*671*/ 
  byte upperTolerance_StartupWipe;      /*672*/   
  byte unused[33];
#endif  

} s_rb_EEPROMStruct_AD_g;



typedef union {
  unsigned char _c[cb_NumberofEEPROMCells_AD_g];
  s_rb_EEPROMStruct_AD_g EEPROMStructAD;
} s_rb_EEPROMStructAD_buff_g;




/* PRQA S 3116,0759 4*//*<< 3116:#pragma needed for IAR compiler and MISRA, 0759:union needed to reduce RAM usage >>*/

EXTERN  s_rb_EEPROMStructAD_buff_g EEPROM_Struct_AD;


/* PRQA S 3453 1*/ /*<< Function type is required by MISRA, but unions are already used! >>*/
#define rab_RS_GainSetupArray(a)                        ((((EEPROM_Struct_AD.EEPROMStructAD.RS_GainSetupArray[((a)/2)])<<(((a)&0x01)*4))&0xF0)|((EEPROM_Struct_AD.EEPROMStructAD.RS_GainSetupArray[5])&0x0F)) 
#define rb_HALIOS_Clock_Control_Reg_g 			EEPROM_Struct_AD.EEPROMStructAD.HALIOS_Clock_Control_Reg_g  
#define rb_ACTR_Reg_g					EEPROM_Struct_AD.EEPROMStructAD.ACTR_Reg_g  
#define rb_PCO_PI_Regulator_g				EEPROM_Struct_AD.EEPROMStructAD.PCO_PI_Regulator_g  
#define rb_ICO1H_g					EEPROM_Struct_AD.EEPROMStructAD.ICO1H_g  
#define rb_ICO1L_g					EEPROM_Struct_AD.EEPROMStructAD.ICO1L_g 
#define rb_ICO2H_g					EEPROM_Struct_AD.EEPROMStructAD.ICO2H_g  
#define rb_ICO2L_g					EEPROM_Struct_AD.EEPROMStructAD.ICO2L_g  
#define rb_FOSC_LEDUL_g					EEPROM_Struct_AD.EEPROMStructAD.FOSC_LEDUL_g  
#define rb_INTCO_g       				EEPROM_Struct_AD.EEPROMStructAD.INTCO_g  
#define rb_StandbyTimout_g                              (EEPROM_Struct_AD.EEPROMStructAD.StandbyTimout & 0x07)
#define rb_SW_TeilenummerindexE2_g                      EEPROM_Struct_AD.EEPROMStructAD.Teilenummerindex 
#define rab_RS_Sensitivity_g                            EEPROM_Struct_AD.EEPROMStructAD.RS_Sensitivity  
#define rb_MaxOverwipeSensitivity_g                	(EEPROM_Struct_AD.EEPROMStructAD.MaxOverwipeSensitivity&0x1F)
#define rb_Stufe1_OG_g                              	EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].Stufe1_OG 
#define rb_Stufe1_UG_g                              	EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].Stufe1_UG 
#define rb_Ep_St2_Epr_In_St2_g                       EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].Ep_St2_Epr_In_St2 
#define rb_Schwelle_Schwall_g                        EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].Schwelle_Schwall 
#define rb_CW_AnsamlungAdditOffsett_g                EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].CW_AnsamlungAdditOffset 
#define rb_dec_Int_Sp_off_g                         (EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].dec_Int_Sp_off & 0x1F) 
#define rb_Dec_Stx_Speicher_g                        EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].Dec_Stx_Speicher 
#define rb_dec_Ovr_Speicher_g                        ((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].dec_Ovr_Speicher)&0x1F) 
#define rb_Empf_Faktor_ST2_Offs_g                     (EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].Empf_Faktor_ST2_Offs &0x3F) 
#define rb_Max_Signallaenge_g                         EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].Max_Signallaenge 
#define rb_Stufe1_with_Int_og_g                      EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].rb_Stufe1_with_Int_og
#define rb_Nachwisch_4_g                              ((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].Nachwisch_4_ST1_min)& 0x1F) 
#define rb_Nachwisch_3_g                             (EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].Nachwisch_3&0x7F)
#define rb_Nachwisch_2_g                              (EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].Nachwisch_2 & 0x7F) 
#define rb_RSEmpfFactorScaling_g                      (EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].RSEmpfFactorScaling&0x0f) 
#define rb_SchlierenFlag1_g        		        EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].SchlierenFlag1 
#define rb_sig_ans_schw_offs_g                        EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].sig_ans_schw_offs 
#define rb_StandbyModeScanTime_g                        EEPROM_Struct_AD.EEPROMStructAD.StandbyModeScanTime_g 
#define rb_RainNightBitThrs_g                           EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g 
#define rb_Amb_Base_Day_Threshold_g                     EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold 
#define rb_Amb_Base_Night_Threshold_g                   EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold 
#define rb_TunnelDebounceFactor_g                       EEPROM_Struct_AD.EEPROMStructAD.TunnelDebounceFactor  
#define rb_Customer_FW_SWA_Scaling_g                    EEPROM_Struct_AD.EEPROMStructAD.Customer_FW_SWA_Scaling  
#define rb_Customer_IR_SWA_Scaling_g                    EEPROM_Struct_AD.EEPROMStructAD.Customer_IR_SWA_Scaling 
#define rb_FW_Base_Day_Threshold_g                      EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold 
#define rb_IR_Base_Day_Threshold_g                      EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold 
#define rb_FW_Base_Night_Threshold_g                    EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold 
#define rb_IR_Base_Night_Threshold_g                    EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold 
#define rb_Day_Delay_g                                  EEPROM_Struct_AD.EEPROMStructAD.Day_Delay 
#define rb_Night_Delay_g                                EEPROM_Struct_AD.EEPROMStructAD.Night_Delay 
#define rb_AfterTunnelDelayOffs_g                       (((((word)EEPROM_Struct_AD.EEPROMStructAD.AfterTunnelDelayOffs*25))>120)? ((((word)EEPROM_Struct_AD.EEPROMStructAD.AfterTunnelDelayOffs*25)-120)>>1):0) 
#define rb_p_v_autobahn_on_off_g                        (EEPROM_Struct_AD.EEPROMStructAD.p_v_autobahn_on_off_g) 
#define rb_p_t_autobahn_delay_on_g                      ((EEPROM_Struct_AD.EEPROMStructAD.p_t_autobahn_delay_on_g)&0x1F) 
#define rb_Frontwaschen_Autobahndelay_g                 (EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g)
#define rb_p_n_regenlichtschwelle_low_high_g            (EEPROM_Struct_AD.EEPROMStructAD.p_n_regenlichtschwelle_low_high_g & 0x3F) 
#define rb_p_n_regenlichtschwelle_Zeit_g                (EEPROM_Struct_AD.EEPROMStructAD.p_n_regenlichtschwelle_Zeit_g)  
#define rb_TunnelThresholdScaling_g                     EEPROM_Struct_AD.EEPROMStructAD.TunnelThresholdScaling_g  
#define rb_Amb_TunnelThresholdScaling_g                 ((EEPROM_Struct_AD.EEPROMStructAD.Amb_TunnelThresholdScaling_g&0x0F)+4)  
#define cb_Regulation48LightOnTime_g                    EEPROM_Struct_AD.EEPROMStructAD.Regulation48LightOnTime_g
/*(about 810 lux---Value corrected for 80% transmission through glass)---(Previous Value about 1250 lux)----KI*/
#define rb_Regulation48Threshold_g                      (EEPROM_Struct_AD.EEPROMStructAD.Regulation48ThresholdAmb_g)
#define rb_Regulation48_FW_Threshold_g                  (EEPROM_Struct_AD.EEPROMStructAD.Regulation48ThresholdFw_g)  /*(FW Diode Threshold----to avoid unnecessary switching ON of Lights)----KI*/
#define rb_VeryBrightInTunnelDelay_g                    (EEPROM_Struct_AD.EEPROMStructAD.VeryBrightInTunnelDelay_g)  
#define rb_Combined_FW_AL_THRs_g                        (EEPROM_Struct_AD.EEPROMStructAD.Combined_FW_AL_THRs_g)  
#define rb_DYN_COMP_CCD_MINUS_1_g                       (EEPROM_Struct_AD.EEPROMStructAD.DYN_COMP_CCD_MINUS_1_g) 
#define rb_DYN_COMP_CCD_MINUS_2_g                       (EEPROM_Struct_AD.EEPROMStructAD.DYN_COMP_CCD_MINUS_2_g) 
#define rb_maxTemperatureOffsett_g                      (EEPROM_Struct_AD.EEPROMStructAD.maxTemperatureOffsett_g ) 
#define rb_ASIC_AFSTHR_REG_g                            (EEPROM_Struct_AD.EEPROMStructAD.ASIC_AFSTHR_REG_g ) 
#define rb_Diag_Request_Factor_g                        (EEPROM_Struct_AD.EEPROMStructAD.Diag_Request_Factor_g ) 
#define rb_inc_int_speicher_g                           ((EEPROM_Struct_AD.EEPROMStructAD.cb_inc_speicher_g )>>4)   
#define rb_inc_ovr_speicher_g                           ((EEPROM_Struct_AD.EEPROMStructAD.cb_inc_speicher_g )& 0x0F)  

#define rb_I2C_Debug_Config_g                           (EEPROM_Struct_AD.EEPROMStructAD.I2C_Debug_Config_g )   

#define rab_Audi_SW_Partnumber_g(a)                     (EEPROM_Struct_AD.EEPROMStructAD.Audi_SW_Partnumber[(a)])
#define rb_wiperSpeedHysteresis                         (EEPROM_Struct_AD.EEPROMStructAD.wiperSpeedHysteresis )   
#define rb_Proj_Specific_config_g                       (EEPROM_Struct_AD.EEPROMStructAD.Proj_Specific_config )
#define rb_ALSx_Filter_g                                (EEPROM_Struct_AD.EEPROMStructAD.ALSx_Filter_g )
#define rb_SolarShadowCorrFactor1_g                     (EEPROM_Struct_AD.EEPROMStructAD.SolarShadowCorrFactor1 ) 
#define rb_SolarShadowCorrFactor2_g                     (EEPROM_Struct_AD.EEPROMStructAD.SolarShadowCorrFactor2 ) 

#define cb_E2_MaxSt2SignalLaenge_g                      (EEPROM_Struct_AD.EEPROMStructAD.E2_MaxSt2SignalLaenge)
//for 0x84 it is 0x4 *2 = 8
#define rb_IrLightTunnelThreshodLow_g                   ((EEPROM_Struct_AD.EEPROMStructAD.IrLightTunnelThreshodRng & 0xF) *2 )
//for 0x84 it is 8 + 2 *8 = 24
#define rb_IrLightTunnelThreshodHigh_g                  (rb_IrLightTunnelThreshodLow_g + ((EEPROM_Struct_AD.EEPROMStructAD.IrLightTunnelThreshodRng >> 4) *2 ))
 
// for 0xC4 is 4 *3 = 12
#define rb_FwLightTunnelThresholdBase_g                  ((EEPROM_Struct_AD.EEPROMStructAD.FwLightTunnelThresholdRng & 0xF) *3 )
// for 0xC4 is 12 +12*5= 72
#define rb_FwLightTunnelThresholdMax_g                  (rb_FwLightTunnelThresholdBase_g +((EEPROM_Struct_AD.EEPROMStructAD.FwLightTunnelThresholdRng >> 4) *5 ))

//for 0x0C it is 24
#define rb_AmbLightTunnelThresholdMin_g                 ((EEPROM_Struct_AD.EEPROMStructAD.AmbLightTunnelThresholdRng & 0xF) *2 )
#define rb_AfterTunnelThrsIsNightThrs_g                 (EEPROM_Struct_AD.EEPROMStructAD.AmbLightTunnelThresholdRng & 0x80)

#define rab_SoftwareStand_g(a)                          (EEPROM_Struct_AD.EEPROMStructAD.SoftwareStand[(a)]) 

#define rw_TwilightToDarkTime_g                         ((word)(EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime * 40))              
#define rw_DarkToTwilightTime_g                         ((word)(EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime * 20))             
  
#define rw_DarkToTwilightThreshFW_g                     ((word)(EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshFW * 3))
#define rw_DarkToTwilightThreshAMB_g                    ((word)(EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshAMB * 3))
  
#define rw_TwilightToDarkThreshFW_g                     ((word)(EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW * 3))
#define rw_TwilightToDarkThreshAMB_g                    ((word)(EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB * 3))

#define rb_iceDetectionTemperature_g                    (EEPROM_Struct_AD.EEPROMStructAD.iceDetectionTemperature)

#define rb_IR_TunnelThresholdScaling_g                  (((EEPROM_Struct_AD.EEPROMStructAD.TunnelThresholdScaling_g&0xF0)>>4)+4) 
#define rb_FW_TunnelThresholdScaling_g                  ((EEPROM_Struct_AD.EEPROMStructAD.TunnelThresholdScaling_g&0x0F)+4) 
#define rb_IntSpInc_Scal_g 				(EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].SchlierenFlag1&0x03)
#define rb_OvrInc_Scal_g 				(((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].SchlierenFlag1)>>2)& 0x03)
#define rb_Speedreduct_g 				(((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].SchlierenFlag1)&0x10)> 0)
#define rbi_smearingreduct_upDown_Enabled               (((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].SchlierenFlag1)&0x20)> 0)
#define rbi_SpeicherDecAtDryWipe_g                      (((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].SchlierenFlag1)&0x40)> 0)
#define rbi_MeanPulsLengthOverwipeEmpfreduction_g       (((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].SchlierenFlag1)&0x80)> 0)
#define rb_p_t_rs_abfragezyklus_g                       (EEPROM_Struct_AD.EEPROMStructAD.StandbyModeScanTime_g&0x1F)
#define rb_IntervalTimereductLimitFact_g                ((EEPROM_Struct_AD.EEPROMStructAD.StandbyModeScanTime_g>>5)+1) /*VC0_58 byte to adjust interval calculation*/
#define p_lx_rs_day                                       (EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g&0x0F)
#define p_lx_rs_dawn                                      (EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g>>4)

#define rb_p_v_autobahn_on_g                            (rb_p_v_autobahn_on_off_g&0x0f)
#define rb_p_v_autobahn_off_g                           (rb_p_v_autobahn_on_off_g>>4)
#define rb_p_v_autobahn_off_kmph_g                      (40+(rb_p_v_autobahn_off_g*5))
#define rb_p_t_autobahn_delay_off_g                      ((EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g)&0x0F)
#define rb_p_t_frontwaschen_g                            ((EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g>>4)&0x0F)
#define rw_p_t_frontwaschen_Ausblend_g                   ((((word)(rb_p_t_frontwaschen_g)*1)+10)*20)
#define rb_p_t_lin_idle_g                                ((EEPROM_Struct_AD.EEPROMStructAD.p_t_autobahn_delay_on_g>>cb_EEPROM_0X1529__POSITION_g)&0x07)
#define CW_LIN_E2_IDLE_TIMOUT                            ((rb_p_t_lin_idle_g*100)+200) /*VCO_31 new EEPROM definition*/
#define rb_p_t_tunnel_delay_g                            ((EEPROM_Struct_AD.EEPROMStructAD.AfterTunnelDelayOffs >> 3)&0x03)

#define rb_DYN_COMP_CCD_MINUS_belowneg5_g               ((EEPROM_Struct_AD.EEPROMStructAD.Amb_TunnelThresholdScaling_g&0xF0)>>4) /*VCO_061 new variable*/
#define rb_DYN_COMP_CCD_MINUS_neg5to10_g                ((EEPROM_Struct_AD.EEPROMStructAD.DYN_COMP_CCD_MINUS_1_g&0xF0)>>4) /*VCO_061 new variable*/
#define rb_DYN_COMP_CCD_MINUS_10to25_g                  ((EEPROM_Struct_AD.EEPROMStructAD.DYN_COMP_CCD_MINUS_1_g&0x0F)) /*VCO_061 new variable*/
#define rb_DYN_COMP_CCD_MINUS_25to40_g                  ((EEPROM_Struct_AD.EEPROMStructAD.DYN_COMP_CCD_MINUS_2_g&0xF0)>>4) /*VCO_061 new variable*/
#define rb_DYN_COMP_CCD_MINUS_above40_g                 ((EEPROM_Struct_AD.EEPROMStructAD.DYN_COMP_CCD_MINUS_2_g&0x0F)) /*VCO_061 new variable*/

#define rb_p_n_regenlichtschwelle_high_g                (EEPROM_Struct_AD.EEPROMStructAD.p_n_regenlichtschwelle_low_high_g & 0x07)
#define rb_p_n_regenlichtschwelle_low_g                 ((EEPROM_Struct_AD.EEPROMStructAD.p_n_regenlichtschwelle_low_high_g >>3)& 0x07)
/*VCO_31 new EEPROM definition*/
#define CB_AMBLIGHT_100lx                                (byte)5    /*value to adjust the lux based thresholds VDR_560 use new faktor for 20lx per digit*/
#define CB_ANBHIGH_TO_LOW_FAKT                            8

#define cb_WIPETHRESHOLD_RAINLIGHT_BRIGHT_KS_mg           (rb_p_n_regenlichtschwelle_high_g+9)
#define cb_WIPETHRESHOLD_RAINLIGHT_DARK_KS_mg             (rb_p_n_regenlichtschwelle_low_g+3)

#define cb_RAIN_ON_BRIGHTNESS_KS_g                     (byte)( (((EEPROM_Struct_AD.EEPROMStructAD.p_n_regenlichtschwelle_Zeit_g&0x0f)*((5*CB_AMBLIGHT_100lx)/CB_ANBHIGH_TO_LOW_FAKT))+((word)(40*CB_AMBLIGHT_100lx)/CB_ANBHIGH_TO_LOW_FAKT)))
#define cw_RAIN_ON_DELAY_KS_g                             (((EEPROM_Struct_AD.EEPROMStructAD.p_n_regenlichtschwelle_Zeit_g>>4)*100)+200)

#define CB_TUNWISCHAKTIV_MG                             (EEPROM_Struct_AD.EEPROMStructAD.TunWischVerzAktiv&0x0F)
#define CB_TUNWISCHVERZ_MG                              (EEPROM_Struct_AD.EEPROMStructAD.TunWischVerzAktiv>>4)

#define rb_SHTErrorDebounceJitter_g                     (EEPROM_Struct_AD.EEPROMStructAD.SHTErrorDebounceJitter)

#define rb_dec_st2_speicher_g                           (EEPROM_Struct_AD.EEPROMStructAD.dec_st2_speicher)
#define rb_Threshold_TempIceRisk_g                      (EEPROM_Struct_AD.EEPROMStructAD.Threshold_TempIceRisk)
#define rb_upperTolerance_StartupWipe_g                      (EEPROM_Struct_AD.EEPROMStructAD.upperTolerance_StartupWipe)

#define cb_AUDI_KS_THRESHOLD_RS_NIGHT_MODE_mg             (CB_AMBLIGHT_100lx*(p_lx_rs_dawn+1))
#define cb_AUDI_KS_THRESHOLD_RS_DAY_MODE_mg               (CB_AMBLIGHT_100lx*(p_lx_rs_day+1))

#if defined FORD
#define rb_FORD_CarCode00_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[0])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode00_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[0])&0x0F)*5)+20)
#define rb_FORD_CarCode01_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[1])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode01_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[1])&0x0F)*5)+20)
#define rb_FORD_CarCode02_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[2])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode02_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[2])&0x0F)*5)+20)
#define rb_FORD_CarCode03_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[3])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode03_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[3])&0x0F)*5)+20)
#define rb_FORD_CarCode04_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[4])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode04_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[4])&0x0F)*5)+20)
#define rb_FORD_CarCode05_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[5])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode05_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[5])&0x0F)*5)+20)
#define rb_FORD_CarCode06_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[6])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode06_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[6])&0x0F)*5)+20)
#define rb_FORD_CarCode07_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[7])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode07_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[7])&0x0F)*5)+20)
#define rb_FORD_CarCode08_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[8])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode08_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[8])&0x0F)*5)+20)
#define rb_FORD_CarCode09_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[9])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode09_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[9])&0x0F)*5)+20)
#define rb_FORD_CarCode10_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[10])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode10_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[10])&0x0F)*5)+20)
#define rb_FORD_CarCode11_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[11])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode11_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[11])&0x0F)*5)+20)
#define rb_FORD_CarCode12_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[12])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode12_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[12])&0x0F)*5)+20)
#define rb_FORD_CarCode13_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[13])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode13_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[13])&0x0F)*5)+20)
#define rb_FORD_CarCode14_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[14])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode14_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[14])&0x0F)*5)+20)
#define rb_FORD_CarCode15_550nm_g  (((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[15])&0xF0)>>4)*5)+20)
#define rb_FORD_CarCode15_880nm_g  ((((EEPROM_Struct_AD.EEPROMStructAD.CarCode[15])&0x0F)*5)+20)

/*For CarCode 01,05,07,09,13,14,15*/ 
#define rb_FORD_DoubleOverwiped00_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[0])&0x01)>0
#define rb_FORD_DoubleOverwiped01_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[0])&0x02)>0
#define rb_FORD_DoubleOverwiped02_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[0])&0x04)>0
#define rb_FORD_DoubleOverwiped03_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[0])&0x08)>0
#define rb_FORD_DoubleOverwiped04_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[0])&0x10)>0
#define rb_FORD_DoubleOverwiped05_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[0])&0x20)>0
#define rb_FORD_DoubleOverwiped06_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[0])&0x40)>0
#define rb_FORD_DoubleOverwiped07_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[0])&0x80)>0
#define rb_FORD_DoubleOverwiped08_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[1])&0x01)>0
#define rb_FORD_DoubleOverwiped09_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[1])&0x02)>0
#define rb_FORD_DoubleOverwiped10_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[1])&0x04)>0
#define rb_FORD_DoubleOverwiped11_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[1])&0x08)>0
#define rb_FORD_DoubleOverwiped12_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[1])&0x10)>0
#define rb_FORD_DoubleOverwiped13_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[1])&0x20)>0
#define rb_FORD_DoubleOverwiped14_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[1])&0x40)>0
#define rb_FORD_DoubleOverwiped15_g  ((EEPROM_Struct_AD.EEPROMStructAD.DoubleOverwiped[1])&0x80)>0

#define rb_FORD_Butterfly_00_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[0])&0x01)>0
#define rb_FORD_Butterfly_01_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[0])&0x02)>0
#define rb_FORD_Butterfly_02_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[0])&0x04)>0
#define rb_FORD_Butterfly_03_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[0])&0x08)>0
#define rb_FORD_Butterfly_04_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[0])&0x10)>0
#define rb_FORD_Butterfly_05_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[0])&0x20)>0
#define rb_FORD_Butterfly_06_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[0])&0x40)>0
#define rb_FORD_Butterfly_07_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[0])&0x80)>0
#define rb_FORD_Butterfly_08_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[1])&0x01)>0
#define rb_FORD_Butterfly_09_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[1])&0x02)>0
#define rb_FORD_Butterfly_10_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[1])&0x04)>0
#define rb_FORD_Butterfly_11_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[1])&0x08)>0
#define rb_FORD_Butterfly_12_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[1])&0x10)>0
#define rb_FORD_Butterfly_13_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[1])&0x20)>0
#define rb_FORD_Butterfly_14_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[1])&0x40)>0
#define rb_FORD_Butterfly_15_g  ((EEPROM_Struct_AD.EEPROMStructAD.Butterfly[1])&0x80)>0

#define rb_EEPROM_SensitivityShift_g  ((EEPROM_Struct_AD.EEPROMStructAD.RsConfig & 0x07)+6)
#define EEP_ValeoPartNumberSwitch ((EEPROM_Struct_AD.EEPROMStructAD.RsConfig & 0x08))
/*StalkInPos Bitwise means 0, StalkInPos Compact means 1*/
#define rb_EEPROM_ldfUsedInCar_g      ((EEPROM_Struct_AD.EEPROMStructAD.RsConfig & 0x10)>>4)
#define rb_EEPROM_RS_Sens_Mapping_g     (EEPROM_Struct_AD.EEPROMStructAD.RsSensMapping)

#define rb_Single_Or_Double_Overwipe_dec              ((EEPROM_Struct_AD.EEPROMStructAD.WiperSignal & 0x0F))
#define EEPR_DepressedParkDelay_Shifter               ((EEPROM_Struct_AD.EEPROMStructAD.WiperSignal & 0x30)>>4)
#define EEPROM_OffsetButterflyDoubleOverwipe_SigSp1   ((EEPROM_Struct_AD.EEPROMStructAD.WiperSignal & 0xC0)>>6)


#define EEPROM_Threshold_FirstOverwipe_Start (( ((EEPROM_Struct_AD.EEPROMStructAD.Threshold_FirstOverwipe_Start)&0x0F)*3 )+10)
#define EEPROM_Threshold_FirstOverwipe_End (( ((EEPROM_Struct_AD.EEPROMStructAD.Threshold_FirstOverwipe_End)&0x0F)*3 )+10)
#define EEPROM_Threshold_FirstOverwipe_End_DoubleOverwiped_OFFSET \
  (((EEPROM_Struct_AD.EEPROMStructAD.Threshold_FirstOverwipe_End)&0xF0)>>3)/*twice the higher nibble*/
#define EEPROM_Threshold_FirstOverwipe_End_DoubleOverwiped \
    (EEPROM_Threshold_FirstOverwipe_End+EEPROM_Threshold_FirstOverwipe_End_DoubleOverwiped_OFFSET)

/*LowNibble: EEPROM_Threshold_SecondOverwipe_Start*/
#define EEPROM_Threshold_SecondOverwipe_Start   (( ((EEPROM_Struct_AD.EEPROMStructAD.Threshold_Overwipe)&0x0F)*3 )+55)
#define EEPROM_Threshold_AfterWiperMotorTime           (((EEPROM_Struct_AD.EEPROMStructAD.Threshold_Overwipe)&0xF0)*3)

#define EEPROM_OffsetButterflyDoubleOverwipe_Tropf     ((((EEPROM_Struct_AD.EEPROMStructAD.WiperMotorTime)&0x30)>>4 ) +1)
#define EEPROM_OffsetButterflyDoubleOverwipe_Sig       ((((EEPROM_Struct_AD.EEPROMStructAD.WiperMotorTime)&0xC0)>>6)+3 )


/*High Nibble: Overwipe Threshold Fade Out for Butterfly --> replaces CB_DEC_SCHWELLE*/
#define EEPROM_OverwipeThres_FadeOut_Butterfly       ( (( ((EEPROM_Struct_AD.EEPROMStructAD.FadeOut)&0xF0)>>4 )+1) *10)
#define EEPROM_OverwipeThres_FadeOut_StandardWiper  ((((EEPROM_Struct_AD.EEPROMStructAD.FadeOut) &0x0F)+1) *10)
#define EEPR_SensitivityBarrier                  ( (( (EEPROM_Struct_AD.EEPROMStructAD.SensitivityBarrier) &0x0C)>>2)+2 )


#define EEPR_FirstPrefixOfPartNumber     (EEPROM_Struct_AD.EEPROMStructAD.PartNumber[0])
#define EEPR_SecondPrefixOfPartNumber    (EEPROM_Struct_AD.EEPROMStructAD.PartNumber[1])
#define EEPR_ThirdPrefixOfPartNumber     (EEPROM_Struct_AD.EEPROMStructAD.PartNumber[2])
#define EEPR_FourthPrefixOfPartNumber    (EEPROM_Struct_AD.EEPROMStructAD.PartNumber[3])
#define rb_Teilenummerindex2_g           (EEPROM_Struct_AD.EEPROMStructAD.PartNumber[4])
#define rb_Teilenummerindex_g            (EEPROM_Struct_AD.EEPROMStructAD.PartNumber[5])
#else

#define rb_Threshold_TempIceRisk_g                      (EEPROM_Struct_AD.EEPROMStructAD.Threshold_TempIceRisk)
#endif

/*VCO_31 values to write into EEPROM per service 0x2E*/     
#define cb_EEPROM_0X1525__BYTES_g  1
#define cw_EEPROM_0X1525__ADDRESS_g (519 + (rb_Parametersatz_Regensensorik_g * 17)) /* Address will change according to the selected parameter */
#define cb_EEPROM_0X1525__POSITION_g 5
#define cb_EEPROM_0X1525__MAX_g    3 /*VDR_468 was forgotten*/
#define cb_EEPROM_0X1525__MASK_g 0x60

#define cb_EEPROM_0X1526__BYTES_g  1
#define cw_EEPROM_0X1526__ADDRESS_g 607
#define cb_EEPROM_0X1526__POSITION_g 0
#define cb_EEPROM_0X1526__MAX_g 19
#define cb_EEPROM_0X1526__MASK_g 0x1F

#define cb_EEPROM_0X1527__BYTES_g  3
#define cw_EEPROM_0X1527_1__ADDRESS_g 621
#define cb_EEPROM_0X1527_1_On__MAX_g 5
#define cb_EEPROM_0X1527_1_Off__MAX_g 10
#define cb_EEPROM_0X1527_1__POSITION_g 0
#define cb_EEPROM_0X1527_1__MASK_g 0xFF

#define cw_EEPROM_0X1527_2__ADDRESS_g 622
#define cb_EEPROM_0X1527_2__POSITION_g 0
#define cb_EEPROM_0X1527_2__MAX_g 19
#define cb_EEPROM_0X1527_2__MASK_g 0x1F

#define cw_EEPROM_0X1527_3__ADDRESS_g 623
#define cb_EEPROM_0X1527_3__POSITION_g 0
#define cb_EEPROM_0X1527_3__MAX_g 10
#define cb_EEPROM_0X1527_3__MASK_g 0x0F

#define cb_EEPROM_0X1528__BYTES_g  1
#define cw_EEPROM_0X1528__ADDRESS_g 623
#define cb_EEPROM_0X1528__MAX_g 10
#define cb_EEPROM_0X1528__POSITION_g 4
#define cb_EEPROM_0X1528__MASK_g 0xF0

#define cb_EEPROM_0X1529__BYTES_g  1
#define cw_EEPROM_0X1529__ADDRESS_g 622
#define cb_EEPROM_0X1529__POSITION_g 5
#define cb_EEPROM_0X1529__MAX_g 4 /*max valeu for rb_p_t_lin_idle_g*/
#define cb_EEPROM_0X1529__MASK_g 0xE0

#define cb_EEPROM_0X152A__BYTES_g  1
#define cw_EEPROM_0X152A__ADDRESS_g 620
#define cb_EEPROM_0X152A__POSITION_g 3
#define cb_EEPROM_0X152A__MAX_g 3
#define cb_EEPROM_0X152A__MASK_g 0x18

#define cb_EEPROM_0X152B__BYTES_g  2
#define cw_EEPROM_0X152B_1__ADDRESS_g 624
#define cb_EEPROM_0X152B_1__POSITION_g 0
#define cb_EEPROM_0X152B_1_HighDelay_Max  6
#define cb_EEPROM_0X152B_1_LOWDelay_Max  7
#define cb_EEPROM_0X152B_1__MASK_g 0x3F

#define cw_EEPROM_0X152B_2__ADDRESS_g 625
#define cb_EEPROM_0X152B_2__POSITION_g 0
#define cb_EEPROM_0X152B_2_THRESH_Max  8
#define cb_EEPROM_0X152B_2_OFFDELAY_Max  8
#define cb_EEPROM_0X152B_2__MASK_g 0xFF

#define cb_EEPROM_0X152C__BYTES_g  1
#define cw_EEPROM_0X152C__ADDRESS_g 608
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



#define rb_2_5SecondsDelay_g                       ((EEPROM_Struct_AD.EEPROMStructAD.StandbyTimout & 0xF8)>>3)

#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
#define rb_Single_Or_Double_Overwipe_dec    ( (EEPROM_Struct_AD.EEPROMStructAD.single_or_double & 0x0F))
/*In the Following: Bit4,5,6,7 (0-7)*/ /*VDR_373*/
#define rb_OffsMaxOverwipeSensContWipSpd_g  1/*((EEPROM_Struct_AD.EEPROMStructAD.single_or_double & 0xF0)>>4)*/
#endif


#define rb_rs_WINDOW_COMP_THRESHOLD_g           (((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].dec_Int_Sp_off & 0xE0)>>4) + 18)

#define rbi_I2C_OUTPUT_Enabled_g                    ((EEPROM_Struct_AD.EEPROMStructAD.MaxOverwipeSensitivity&0x40)>0)
#define rbi_PWM_OUTPUT_Enabled_g                    ((EEPROM_Struct_AD.EEPROMStructAD.MaxOverwipeSensitivity&0x80)>0)

#define rb_delay_depressed_park_pointer_g           (((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].dec_Ovr_Speicher)&0x60)>>5)


/* PRQA S 3453 5*/ /*<< Function type is required by MISRA, but unions are already used! >>*/
/*VDR_131 Following 4 lines correct MISRA Rule 96*/


#define rb_Mean_HighwayLightOnSpeed_g        ((rb_p_v_autobahn_on_g*10)+100)
#define rw_TimeToReachFastHighwayMode_g      ((((word)(rb_p_t_autobahn_delay_on_g*1)+1)*20))
#define rw_TimeToReachNormalSpeedMode_g      ((((word)(rb_p_t_autobahn_delay_off_g*10)+50)*20))

#define rb_TimeForAfterwipeThrs_DelayScal_g  (((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].Empf_Faktor_ST2_Offs & 0xC0)>>6)+1)
#define rb_ST1_Nachwisch_min_g               (((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].Nachwisch_4_ST1_min)& 0x60)>>5)
#define rw_St2_OG_g                                          (((word)(rb_Schwelle_Schwall_g))<<6)


#define rub_TropfenMerkerOffsettShift_g (((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].RSEmpfFactorScaling&0x70)>>4)+1)
#define rbi_IntSpInc_Scal_longerInt_enabled_g ((EEPROM_Struct_AD.EEPROMStructAD.PrametersStruct[rb_Parametersatz_Regensensorik_g].RSEmpfFactorScaling&0x80)> 0 )

#define cb_POSITIONDEFAULTSOFTWARE (148)     // addr of CB_DEF_SOFTWARESTAND_2 - AD's first address (512)



#define CW_FOSC_LEDUL_ADDR_g      (593)


#endif
