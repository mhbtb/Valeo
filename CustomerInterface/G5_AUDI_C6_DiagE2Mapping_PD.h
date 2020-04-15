#ifndef G5_DIAGE2MAPPING_PD_H
#define G5_DIAGE2MAPPING_PD_H
/* PRQA S 3619 EOF */ /* << 2010 01 08, compiler allows whitespaces:due to readable code, keep whitespaces! >> */
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
/* PRQA S 3453 EOF *//*<< Macro is more readle and convinient in this situation >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/


/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Author   Description                                       */
/*-DD.MM.YY-------------------------------------------------------------------*/
/* see G5_DiagE2Mapping_Konzern.h for old history */
/* 15.09.14   VCO_183 NB  Rearrangement of EEPROM */
/* 15.09.14   VCO_184 NB Checksum for calibration data */
/* 22.09.14   VCO_152 NB Customenr part number shall be stored in EEPROM */
/* 29.09.14   VCO_172 NB AUDI_Coding of Parkposition on LIN */
/* 18.03.15   VCO_231 MP Default values of the Kodierbyte_0 and RSControlFlags for no-rain-variants*/
/* 20.03.15   VCO_215 NB All: Project specific extensions in the main stream Release 8 */
/*14.04.15   VCO_243     NB      Implement Function ID and Variant ID in the EEPROM PD section */
/* 10.11.15     VCO_282    NB    All:Add spare LIN IDs in the EEPROM             */

#include "G5_projectDefs.h"

#define cb_NumberofEEPROMCells_PD_g 92  

#define CB_DEF_ZUSPLATE         0x00
#define CB_MIN_ZUSPLATE         0x00
#define CB_MAX_ZUSPLATE         0xFF
#define CB_DEF_PROD_DATA        0x00
#define CB_MIN_PROD_DATA        0x00
#define CB_MAX_PROD_DATA        0xFF
#define CB_DEF_SERIAL_NUMMER    0x00
#define CB_MIN_SERIAL_NUMMER    0x00
#define CB_MAX_SERIAL_NUMMER    0xFF
#define CB_DEF_SPARE            0x00
#define CB_MIN_SPARE            0x00
#define CB_MAX_SPARE            0xFF

#define CB_DEF_KODIERBYTE_2 0x6C
#define CB_MIN_KODIERBYTE_2 0x00
#define CB_MAX_KODIERBYTE_2 0xFF

#define CB_DEF_KODIERBYTE_1 0x00
#define CB_MIN_KODIERBYTE_1 0x00
#define CB_MAX_KODIERBYTE_1 0xFF

/*VCO_231 Default values of the Kodierbyte_0 and RSControlFlags for no-rain-variants*/
/*is RS enabled?*/
#ifndef _NO_RAIN_
#define CB_DEF_KODIERBYTE_0 0x00
#else
#define CB_DEF_KODIERBYTE_0 0x40
#endif /*_NO_RAIN_*/
#define CB_MIN_KODIERBYTE_0 0x00
#define CB_MAX_KODIERBYTE_0 0xFF

#define CB_DEF_ALS1_4_SETTING 0x24
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

#define CW_DEF_CRC_CHECKSUM_CALIBRATION (word)0xFFFFU /* calculated using RLT Diag from default values */
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

#define CB_DEF_ASIC_SCHED_CONFIG  0x00
#define CB_MIN_ASIC_SCHED_CONFIG  0x00
#define CB_MAX_ASIC_SCHED_CONFIG  0xFF

#define CB_DEF_ASIC_LCTR	0x00
#define CB_MIN_ASIC_LCTR        0x00
#define CB_MAX_ASIC_LCTR        0xFF

#define CW_DEF_NO_RAIN_PRESENT_THRSH_HB  0x01
#define CW_MIN_NO_RAIN_PRESENT_THRSH_HB  0x00
#define CW_MAX_NO_RAIN_PRESENT_THRSH_HB  0xFF

#define CW_DEF_NO_RAIN_PRESENT_THRSH_LB  0x2C
#define CW_MIN_NO_RAIN_PRESENT_THRSH_LB  0x00
#define CW_MAX_NO_RAIN_PRESENT_THRSH_LB  0xFF

#define CB_DEF_STBY_REGV_IMBALANCE  0x14
#define CB_MIN_STBY_REGV_IMBALANCE  0x00
#define CB_MAX_STBY_REGV_IMBALANCE  0xFF

/*VCO_231 Default values of the Kodierbyte_0 and RSControlFlags for no-rain-variants*/
/*is RS enabled?*/
#ifndef _NO_RAIN_
#define CB_DEF_RSCONTROLFLAGS               0x05
#else
#define CB_DEF_RSCONTROLFLAGS               0x0E
#endif/*_NO_RAIN_*/
#define CB_MIN_RSCONTROLFLAGS               0x00
#define CB_MAX_RSCONTROLFLAGS               0xff



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


#define CB_DEF_NAD                          0x02
#define CB_MIN_NAD                          0x01
#define CB_MAX_NAD                          0x7E

#define CB_DEF_IDRLSS_01                    0xE2
#define CB_MIN_IDRLSS_01                    0
#define CB_MAX_IDRLSS_01                    0xff

#define CB_DEF_IDFSS_ENH_01                 0x40
#define CB_MIN_IDFSS_ENH_01                 0x00
#define CB_MAX_IDFSS_ENH_01                 0xFF

#define CB_DEF_IDFSS_01                     0x40
#define CB_MIN_IDFSS_01                     0
#define CB_MAX_IDFSS_01                     0xff

#define CB_DEF_BCM1_LIN1_01                 0xF0
#define CB_MIN_BCM1_LIN1_01                 0
#define CB_MAX_BCM1_LIN1_01                 0xff

#define CB_DEF_WWSS_01                      0xB1
#define CB_MIN_WWSS_01                      0
#define CB_MAX_WWSS_01                      0xff

#define CB_DEF_SOSES_01                    0xA3
#define CB_MIN_SOSES_01                    0x00
#define CB_MAX_SOSES_01                    0xFF

#define CB_DEF_ERR_DATA_01                    0x40
#define CB_MIN_ERR_DATA_01                    0x00
#define CB_MAX_ERR_DATA_01                    0xFF

#define CB_DEF_LINID_SPARE_01                  0x40
#define CB_MIN_LINID_SPARE_01                  0x00
#define CB_MAX_LINID_SPARE_01                  0xFF

#ifdef ASIC_TEST

#define CB_DEF_ASIC_FRAME_01                    0x40/*0x50*/
#define CB_MIN_ASIC_FRAME_01                    0x00
#define CB_MAX_ASIC_FRAME_01                    0xFF

#define CB_DEF_ASIC_FRAME_02                    0x40/*0x11*/
#define CB_MIN_ASIC_FRAME_02                    0x00
#define CB_MAX_ASIC_FRAME_02                    0xFF

#define CB_DEF_ASIC_FRAME_03                    0x40/*0x92*/
#define CB_MIN_ASIC_FRAME_03                    0x00
#define CB_MAX_ASIC_FRAME_03                    0xFF

#define CB_DEF_ASIC_FRAME_04                    0x40/*0xD3*/
#define CB_MIN_ASIC_FRAME_04                    0x00
#define CB_MAX_ASIC_FRAME_04                    0xFF

#endif

#define CB_DEF_ASIC_RCTR_REG				0xA4
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

#define CB_DEF_ASIC_DIAGV                        0x78
#define CB_MIN_ASIC_DIAGV                        0
#define CB_MAX_ASIC_DIAGV                        0xff

#define CB_DEF_AUDI_HW_PART_NUMBER_1  '8'
#define CB_MIN_AUDI_HW_PART_NUMBER_1  0x00
#define CB_MAX_AUDI_HW_PART_NUMBER_1  0xFF

#define CB_DEF_AUDI_HW_PART_NUMBER_2  '1'
#define CB_MIN_AUDI_HW_PART_NUMBER_2  0x00
#define CB_MAX_AUDI_HW_PART_NUMBER_2  0xFF

#define CB_DEF_AUDI_HW_PART_NUMBER_3  'A'
#define CB_MIN_AUDI_HW_PART_NUMBER_3  0x00
#define CB_MAX_AUDI_HW_PART_NUMBER_3  0xFF

#define CB_DEF_AUDI_HW_PART_NUMBER_4_5  0x95
#define CB_MIN_AUDI_HW_PART_NUMBER_4_5  0x00
#define CB_MAX_AUDI_HW_PART_NUMBER_4_5  0xFF


#define CB_DEF_AUDI_HW_PART_NUMBER_6_7  0x55
#define CB_MIN_AUDI_HW_PART_NUMBER_6_7  0x00
#define CB_MAX_AUDI_HW_PART_NUMBER_6_7  0xFF


#define CB_DEF_AUDI_HW_PART_NUMBER_8_9  0x55
#define CB_MIN_AUDI_HW_PART_NUMBER_8_9  0x00
#define CB_MAX_AUDI_HW_PART_NUMBER_8_9  0xFF

#define CB_DEF_AUDI_HW_PART_NUMBER_10_INDEX  ' '
#define CB_MIN_AUDI_HW_PART_NUMBER_10_INDEX  0x00
#define CB_MAX_AUDI_HW_PART_NUMBER_10_INDEX  0xFF

#define CB_DEF_AUDI_HW_PART_NUMBER_11_INDEX  ' '
#define CB_MIN_AUDI_HW_PART_NUMBER_11_INDEX  0x00
#define CB_MAX_AUDI_HW_PART_NUMBER_11_INDEX  0xFF

#define CB_DEF_ERASE_COUNTER 0x00
#define CB_MIN_ERASE_COUNTER 0x00
#define CB_MAX_ERASE_COUNTER 0xFF

#define CB_DEF_VARIANT_ID          0x01
#define CB_MIN_VARIANT_ID          0x00
#define CB_MAX_VARIANT_ID          0xFF

#define CW_DEF_FUNCTION_ID         0x000BU
#define CW_MIN_FUNCTION_ID         0x0000U
#define CW_MAX_FUNCTION_ID         0xFFFFU


#define CW_EEPROM_PD_START_ADR  256
#define CW_CALIB_CRC_START      271
#define CW_CALIB_CRC_END        291

#define cw_ALS1_4_SETTING_ADDRESS_g 271
#define cw_ALS5_6_INREC_SETTING_ADDRESS_g 272

#ifdef _DIAGNOSE_c_
#define EXTERN /**/
#pragma constseg="BOOTSEG_TWO"               /* VDR_671 */
const byte __far cb_EEPROMDataDefaultMinMax_PD_g[cb_NumberofEEPROMCells_PD_g][3] = {
  
  {CB_DEF_ZUSPLATE                        ,CB_MIN_ZUSPLATE                       ,CB_MAX_ZUSPLATE                       },      /*256*/
  {CB_DEF_ZUSPLATE                        ,CB_MIN_ZUSPLATE                       ,CB_MAX_ZUSPLATE                       },      /*257*/
  {CB_DEF_ZUSPLATE                        ,CB_MIN_ZUSPLATE                       ,CB_MAX_ZUSPLATE                       },      /*258*/
  {CB_DEF_ZUSPLATE                        ,CB_MIN_ZUSPLATE                       ,CB_MAX_ZUSPLATE                       },      /*259*/
  {CB_DEF_PROD_DATA                       ,CB_MIN_PROD_DATA                      ,CB_MAX_PROD_DATA                      },      /*260*/     
  {CB_DEF_PROD_DATA                       ,CB_MIN_PROD_DATA                      ,CB_MAX_PROD_DATA                      },      /*261*/   
  {CB_DEF_PROD_DATA                       ,CB_MIN_PROD_DATA                      ,CB_MAX_PROD_DATA                      },      /*262*/   
  {CB_DEF_SERIAL_NUMMER                   ,CB_MIN_SERIAL_NUMMER                  ,CB_MAX_SERIAL_NUMMER                  },      /*263*/   
  {CB_DEF_SERIAL_NUMMER                   ,CB_MIN_SERIAL_NUMMER                  ,CB_MAX_SERIAL_NUMMER                  },      /*264*/   
  {CB_DEF_SERIAL_NUMMER                   ,CB_MIN_SERIAL_NUMMER                  ,CB_MAX_SERIAL_NUMMER                  },      /*265*/   
  {CB_DEF_SPARE                           ,CB_MIN_SPARE                          ,CB_MAX_SPARE                          },      /*266*/ 
  {CB_DEF_SPARE                           ,CB_MIN_SPARE                          ,CB_MAX_SPARE                          },      /*267*/   
      
  {CB_DEF_KODIERBYTE_2                    ,CB_MIN_KODIERBYTE_2                   ,CB_MAX_KODIERBYTE_2                   },      /*268*/
  {CB_DEF_KODIERBYTE_1                    ,CB_MIN_KODIERBYTE_1                   ,CB_MAX_KODIERBYTE_1                   },      /*269*/
  {CB_DEF_KODIERBYTE_0                    ,CB_MIN_KODIERBYTE_0                   ,CB_MAX_KODIERBYTE_0                   },      /*270*/
  {CB_DEF_ALS1_4_SETTING                  ,CB_MIN_ALS1_4_SETTING                 ,CB_MAX_ALS1_4_SETTING                 },      /*271*/
  {CB_DEF_ALS5_6_INREC_SETTING            ,CB_MIN_ALS5_6_INREC_SETTING           ,CB_MAX_ALS5_6_INREC_SETTING           },      /*272*/
  {CB_DEF_ASIC_DIAGV                      ,CB_MIN_ASIC_DIAGV                     ,CB_MAX_ASIC_DIAGV                     },      /*273*/
  {(byte)(CW_DEF_A_FACTOR_ALS1&0xFF)      ,(byte)(CW_MIN_A_FACTOR_ALS1&0xFF)     ,(byte)(CW_MAX_A_FACTOR_ALS1&0xFF)     },      /*274*/
  {(byte)(CW_DEF_A_FACTOR_ALS1>>8)        ,(byte)(CW_MIN_A_FACTOR_ALS1>>8)       ,(byte)(CW_MAX_A_FACTOR_ALS1>>8)       },      /*275*/
  {(byte)(CW_DEF_A_FACTOR_ALS2&0xFF)      ,(byte)(CW_MIN_A_FACTOR_ALS2&0xFF)     ,(byte)(CW_MAX_A_FACTOR_ALS2&0xFF)     },      /*276*/
  {(byte)(CW_DEF_A_FACTOR_ALS2>>8)        ,(byte)(CW_MIN_A_FACTOR_ALS2>>8)       ,(byte)(CW_MAX_A_FACTOR_ALS2>>8)       },      /*277*/
  {(byte)(CW_DEF_A_FACTOR_ALS3&0xFF)      ,(byte)(CW_MIN_A_FACTOR_ALS3&0xFF)     ,(byte)(CW_MAX_A_FACTOR_ALS3&0xFF)     },      /*278*/
  {(byte)(CW_DEF_A_FACTOR_ALS3>>8)        ,(byte)(CW_MIN_A_FACTOR_ALS3>>8)       ,(byte)(CW_MAX_A_FACTOR_ALS3>>8)       },      /*279*/
  {(byte)(CW_DEF_A_FACTOR_ALS4&0xFF)      ,(byte)(CW_MIN_A_FACTOR_ALS4&0xFF)     ,(byte)(CW_MAX_A_FACTOR_ALS4&0xFF)     },      /*280*/
  {(byte)(CW_DEF_A_FACTOR_ALS4>>8)        ,(byte)(CW_MIN_A_FACTOR_ALS4>>8)       ,(byte)(CW_MAX_A_FACTOR_ALS4>>8)       },      /*281*/
  {(byte)(CW_DEF_A_FACTOR_ALS5&0xFF)      ,(byte)(CW_MIN_A_FACTOR_ALS5&0xFF)     ,(byte)(CW_MAX_A_FACTOR_ALS5&0xFF)     },      /*282*/
  {(byte)(CW_DEF_A_FACTOR_ALS5>>8)        ,(byte)(CW_MIN_A_FACTOR_ALS5>>8)       ,(byte)(CW_MAX_A_FACTOR_ALS5>>8)       },      /*283*/
  {(byte)(CW_DEF_A_FACTOR_ALS6&0xFF)      ,(byte)(CW_MIN_A_FACTOR_ALS6&0xFF)     ,(byte)(CW_MAX_A_FACTOR_ALS6&0xFF)     },      /*284*/
  {(byte)(CW_DEF_A_FACTOR_ALS6>>8)        ,(byte)(CW_MIN_A_FACTOR_ALS6>>8)       ,(byte)(CW_MAX_A_FACTOR_ALS6>>8)       },      /*285*/
  {(byte)(CW_DEF_A_FACTOR_INREC&0xFF)     ,(byte)(CW_MIN_A_FACTOR_INREC&0xFF)    ,(byte)(CW_MAX_A_FACTOR_INREC&0xFF)    },      /*286*/
  {(byte)(CW_DEF_A_FACTOR_INREC>>8)       ,(byte)(CW_MIN_A_FACTOR_INREC>>8)      ,(byte)(CW_MAX_A_FACTOR_INREC>>8)      },      /*287*/ 
  {CB_DEF_B_FACTOR_IREF_LO_GAIN_LO      ,CB_MIN_B_FACTOR_IREF_LO_GAIN_LO     ,CB_MAX_B_FACTOR_IREF_LO_GAIN_LO           },      /*288*/
  {CB_DEF_B_FACTOR_IREF_LO_GAIN_HI      ,CB_MIN_B_FACTOR_IREF_LO_GAIN_HI     ,CB_MAX_B_FACTOR_IREF_LO_GAIN_HI           },      /*289*/
  {CB_DEF_B_FACTOR_IREF_HI_GAIN_LO      ,CB_MIN_B_FACTOR_IREF_HI_GAIN_LO     ,CB_MAX_B_FACTOR_IREF_HI_GAIN_LO           },      /*290*/
  {CB_DEF_B_FACTOR_IREF_HI_GAIN_HI      ,CB_MIN_B_FACTOR_IREF_HI_GAIN_HI     ,CB_MAX_B_FACTOR_IREF_HI_GAIN_HI           },      /*291*/
  {(byte)(CW_DEF_CRC_CHECKSUM_CALIBRATION&0xFF)     ,(byte)(CW_MIN_CRC_CHECKSUM_CALIBRATION&0xFF)     ,(byte)(CW_MAX_CRC_CHECKSUM_CALIBRATION&0xFF)     },      /*292*/
  {(byte)(CW_DEF_CRC_CHECKSUM_CALIBRATION>>8)     ,(byte)(CW_MIN_CRC_CHECKSUM_CALIBRATION>>8)     ,(byte)(CW_MAX_CRC_CHECKSUM_CALIBRATION>>8)           },     /*293*/
  {CB_DEF_STANDBY_RAIN_MEASUREMENT_1     ,CB_MIN_STANDBY_RAIN_MEASUREMENT_1     ,CB_MAX_STANDBY_RAIN_MEASUREMENT_1     },      /*294*/
  {CB_DEF_STANDBY_RAIN_MEASUREMENT_2     ,CB_MIN_STANDBY_RAIN_MEASUREMENT_2     ,CB_MAX_STANDBY_RAIN_MEASUREMENT_2     },      /*295*/
  {CB_DEF_STANDBY_RAIN_MEASUREMENT_3     ,CB_MIN_STANDBY_RAIN_MEASUREMENT_3     ,CB_MAX_STANDBY_RAIN_MEASUREMENT_3     },      /*296*/
  {CB_DEF_STANDBY_RAIN_MEASUREMENT_4     ,CB_MIN_STANDBY_RAIN_MEASUREMENT_4     ,CB_MAX_STANDBY_RAIN_MEASUREMENT_4     },      /*297*/  
  {CB_DEF_STANDBY_RAIN_MEASUREMENT_5     ,CB_MIN_STANDBY_RAIN_MEASUREMENT_5     ,CB_MAX_STANDBY_RAIN_MEASUREMENT_5     },      /*298*/  
  {CB_DEF_STANDBY_RAIN_MEASUREMENT_6     ,CB_MIN_STANDBY_RAIN_MEASUREMENT_6     ,CB_MAX_STANDBY_RAIN_MEASUREMENT_6     },      /*299*/  
  {CB_DEF_ASIC_SCHED_CONFIG              ,CB_MIN_ASIC_SCHED_CONFIG              ,CB_MAX_ASIC_SCHED_CONFIG              },      /*300*/  
  {CB_DEF_ASIC_LCTR                      ,CB_MIN_ASIC_LCTR                      ,CB_MAX_ASIC_LCTR                      },      /*301*/
  {CW_DEF_NO_RAIN_PRESENT_THRSH_HB       ,CW_MIN_NO_RAIN_PRESENT_THRSH_HB       ,CW_MAX_NO_RAIN_PRESENT_THRSH_HB       },      /*302*/
  {CW_DEF_NO_RAIN_PRESENT_THRSH_LB       ,CW_MIN_NO_RAIN_PRESENT_THRSH_LB       ,CW_MAX_NO_RAIN_PRESENT_THRSH_LB       },      /*303*/
  {CB_DEF_STBY_REGV_IMBALANCE            ,CB_MIN_STBY_REGV_IMBALANCE            ,CB_MAX_STBY_REGV_IMBALANCE            },      /*304*/
  {CB_DEF_RSCONTROLFLAGS                 ,CB_MIN_RSCONTROLFLAGS                 ,CB_MAX_RSCONTROLFLAGS                 },      /*305*/  
  {CB_DEF_IDFSS_ENH_01                   ,CB_MIN_IDFSS_ENH_01                   ,CB_MAX_IDFSS_ENH_01                   },      /*306*/
  {CB_DEF_HARDWARESTAND_0                ,CB_MIN_HARDWARESTAND_0                ,CB_MAX_HARDWARESTAND_0                },      /*307*/
  {CB_DEF_HARDWARESTAND_1                ,CB_MIN_HARDWARESTAND_1                ,CB_MAX_HARDWARESTAND_1                },      /*308*/
  {CB_DEF_PRODUKTIONSNUMMER_0            ,CB_MIN_PRODUKTIONSNUMMER_0            ,CB_MAX_PRODUKTIONSNUMMER_0            },      /*309*/
  {CB_DEF_PRODUKTIONSNUMMER_1            ,CB_MIN_PRODUKTIONSNUMMER_1            ,CB_MAX_PRODUKTIONSNUMMER_1            },      /*310*/
  {CB_DEF_PRODUKTIONSNUMMER_2            ,CB_MIN_PRODUKTIONSNUMMER_2            ,CB_MAX_PRODUKTIONSNUMMER_2            },      /*311*/
  {CB_DEF_PRODUKTIONSNUMMER_3            ,CB_MIN_PRODUKTIONSNUMMER_3            ,CB_MAX_PRODUKTIONSNUMMER_3            },      /*312*/
  {CB_DEF_FERTIGUNGSDATUM_TAG            ,CB_MIN_FERTIGUNGSDATUM_TAG            ,CB_MAX_FERTIGUNGSDATUM_TAG            },      /*313*/
  {CB_DEF_FERTIGUNGSDATUM_MONAT          ,CB_MIN_FERTIGUNGSDATUM_MONAT          ,CB_MAX_FERTIGUNGSDATUM_MONAT          },      /*314*/
  {CB_DEF_FERTIGUNGSDATUM_JAHR           ,CB_MIN_FERTIGUNGSDATUM_JAHR           ,CB_MAX_FERTIGUNGSDATUM_JAHR           },      /*315*/
  {CB_DEF_AUDI_HW_PART_NUMBER_1          ,CB_MIN_AUDI_HW_PART_NUMBER_1          ,CB_MAX_AUDI_HW_PART_NUMBER_1          },      /*316*/
  {CB_DEF_AUDI_HW_PART_NUMBER_2          ,CB_MIN_AUDI_HW_PART_NUMBER_2          ,CB_MAX_AUDI_HW_PART_NUMBER_2          },      /*317*/
  {CB_DEF_AUDI_HW_PART_NUMBER_3          ,CB_MIN_AUDI_HW_PART_NUMBER_3          ,CB_MAX_AUDI_HW_PART_NUMBER_3          },      /*318*/
  {CB_DEF_AUDI_HW_PART_NUMBER_4_5        ,CB_MIN_AUDI_HW_PART_NUMBER_4_5        ,CB_MAX_AUDI_HW_PART_NUMBER_4_5        },      /*319*/
  {CB_DEF_AUDI_HW_PART_NUMBER_6_7        ,CB_MIN_AUDI_HW_PART_NUMBER_6_7        ,CB_MAX_AUDI_HW_PART_NUMBER_6_7        },      /*320*/
  {CB_DEF_AUDI_HW_PART_NUMBER_8_9        ,CB_MIN_AUDI_HW_PART_NUMBER_8_9        ,CB_MAX_AUDI_HW_PART_NUMBER_8_9        },      /*321*/
  {CB_DEF_AUDI_HW_PART_NUMBER_10_INDEX   ,CB_MIN_AUDI_HW_PART_NUMBER_10_INDEX   ,CB_MAX_AUDI_HW_PART_NUMBER_10_INDEX   },      /*322*/
  {CB_DEF_AUDI_HW_PART_NUMBER_11_INDEX   ,CB_MIN_AUDI_HW_PART_NUMBER_11_INDEX   ,CB_MAX_AUDI_HW_PART_NUMBER_11_INDEX   },      /*323*/
  {CB_DEF_NAD                            ,CB_MIN_NAD                            ,CB_MAX_NAD                            },      /*324*/
  {CB_DEF_IDFSS_01                       ,CB_MIN_IDFSS_01                       ,CB_MAX_IDFSS_01                       },      /*325*/
  {CB_DEF_IDRLSS_01                      ,CB_MIN_IDRLSS_01                      ,CB_MAX_IDRLSS_01                      },      /*326*/
  {CB_DEF_BCM1_LIN1_01                   ,CB_MIN_BCM1_LIN1_01                   ,CB_MAX_BCM1_LIN1_01                   },      /*327*/
  {CB_DEF_WWSS_01                        ,CB_MIN_WWSS_01                        ,CB_MAX_WWSS_01                        },      /*328*/
  {CB_DEF_SOSES_01                       ,CB_MIN_SOSES_01                       ,CB_MAX_SOSES_01                       },      /*329*/
#ifdef ASIC_TEST 
  {CB_DEF_ASIC_FRAME_01                 ,CB_MIN_ASIC_FRAME_01                 ,CB_MAX_ASIC_FRAME_01                    },      /*330*/
  {CB_DEF_ASIC_FRAME_02                 ,CB_MIN_ASIC_FRAME_02                 ,CB_MAX_ASIC_FRAME_02                    },      /*331*/
  {CB_DEF_ASIC_FRAME_03                 ,CB_MIN_ASIC_FRAME_03                 ,CB_MAX_ASIC_FRAME_03                    },      /*332*/
  {CB_DEF_ASIC_FRAME_04                 ,CB_MIN_ASIC_FRAME_04                 ,CB_MAX_ASIC_FRAME_04                    },      /*333*/
#endif
  {CB_DEF_ASIC_RCTR_REG                  ,CB_MIN_ASIC_RCTR_REG                  ,CB_MAX_ASIC_RCTR_REG                  },      /*334*/
  {CB_DEF_ASIC_RFCTR_REG                 ,CB_MIN_ASIC_RFCTR_REG                 ,CB_MAX_ASIC_RFCTR_REG                 },      /*335*/  
  {CB_DEF_ERROR_ACTIVE_1                 ,CB_MIN_ERROR_ACTIVE_1                 ,CB_MAX_ERROR_ACTIVE_1                 },      /*336*/  
  {CB_DEF_ERROR_ACTIVE_2                 ,CB_MIN_ERROR_ACTIVE_2                 ,CB_MAX_ERROR_ACTIVE_2                 },      /*337*/
  {CB_DEF_ERROR_ACTIVE_3                 ,CB_MIN_ERROR_ACTIVE_3                 ,CB_MAX_ERROR_ACTIVE_3                 },      /*338*/  
  {CB_DEF_ERASE_COUNTER                 ,CB_MIN_ERASE_COUNTER                 ,CB_MAX_ERASE_COUNTER                 },      /*339*/  
  {CB_DEF_ERASE_COUNTER                 ,CB_MIN_ERASE_COUNTER                 ,CB_MAX_ERASE_COUNTER                 },      /*340*/  
  {CB_DEF_ERASE_COUNTER                 ,CB_MIN_ERASE_COUNTER                 ,CB_MAX_ERASE_COUNTER                 },      /*341*/  
  {CB_DEF_ERASE_COUNTER                 ,CB_MIN_ERASE_COUNTER                 ,CB_MAX_ERASE_COUNTER                 },      /*342*/  
  {CB_DEF_VARIANT_ID                     ,CB_MIN_VARIANT_ID                     ,CB_MAX_VARIANT_ID                     },      /*343*/  
  {(byte)(CW_DEF_FUNCTION_ID&0xFF)       ,(byte)(CW_MIN_FUNCTION_ID&0xFF)       ,(byte)(CW_MAX_FUNCTION_ID&0xFF)       },      /*344*/
  {(byte)(CW_DEF_FUNCTION_ID>>8)         ,(byte)(CW_MIN_FUNCTION_ID>>8)         ,(byte)(CW_MAX_FUNCTION_ID>>8)         },      /*345*/
  {CB_DEF_ERR_DATA_01                    ,CB_MIN_ERR_DATA_01                    ,CB_MAX_ERR_DATA_01                    },      /*346*/
  {CB_DEF_LINID_SPARE_01                 ,CB_MIN_LINID_SPARE_01                 ,CB_MAX_LINID_SPARE_01                 },      /*347*/
  
};
#pragma constseg=default               /* VDR_671 IAR 4xx part*/

const byte cab_SI_Transmission_Offsett[8] = {15,20,25,30,10,6,3,0}; /*definition of Korrekturfaktor Vorfeldempfanger offset*/

#else

extern const byte cab_SI_Transmission_Offsett[8];


extern const byte __far cb_EEPROMDataDefaultMinMax_PD_g[cb_NumberofEEPROMCells_PD_g][3];
#define EXTERN  extern
#endif


typedef struct {
  byte ProductionData_g[12];          /* 256-267 */
  byte EEKodierbyte2_g;               /* 268 */
  byte EEKodierbyte1_g;               /* 269  */
  byte EEKodierbyte0_g;               /* 270  */
  byte ALS1_4_Setting_g;              /* 271 */
  byte ALS5_6_INREC_Setting_g;        /* 272 */
  byte ASIC_DIAGV_g;                  /* 273 */
  word A_Factor_ALS1_g;               /* 274,275 */
  word A_Factor_ALS2_g;               /* 276,277 */
  word A_Factor_ALS3_g;               /* 278,279 */
  word A_Factor_ALS4_g;               /* 280,281 */
  word A_Factor_ALS5_g;               /* 282,283 */
  word A_Factor_ALS6_g;               /* 284,285 */
  word A_Factor_INREC_g;              /* 286,287 */
  byte B_Factor_Iref_Lo_Gain_Lo_g;    /* 288 */
  byte B_Factor_Iref_Lo_Gain_Hi_g;    /* 289 */
  byte B_Factor_Iref_Hi_Gain_Lo_g;    /* 290 */
  byte B_Factor_Iref_Hi_Gain_Hi_g;    /* 291 */
  word CRC_Checksum_calibration_g;    /* 292,293 */       
  byte Standby_rain_measurement_1_g;  /*294*/
  byte Standby_rain_measurement_2_g;  /*295*/
  byte Standby_rain_measurement_3_g;  /*296*/
  byte Standby_rain_measurement_4_g;  /*297*/
  byte Standby_rain_measurement_5_g;  /*298*/
  byte Standby_rain_measurement_6_g;  /*299*/
  byte ASIC_Sched_Config_g ;          /*300*/ 
  byte ASIC_LCTR_g ;                  /*301*/ 
  byte NO_RAIN_PRESENT_THRSH_HB_g ;   /*302*/ 
  byte NO_RAIN_PRESENT_THRSH_LB_g ;   /*303*/ 
  byte STBY_REGV_Imbalance_g ;        /*304*/ 
  byte RSControlFlags;                /*305*/
  byte IDFSs_Enh_01_g;          /*306  */ 
  byte HardwareStand[2];              /* 307, 308*/          
  byte Produktionsdaten[4];           /* 309, 310, 311, 312 */
  byte Fertigungsdatum[3];            /* 313, 314, 315*/ 
  byte Audi_HW_Partnumber[8];          /*316,317,318,319,320,321,322,323*/ 
  byte NAD;                           /*324*/
  byte IDFSs_01;                      /*325*/
  byte IDRLSs_01;                     /*326*/
  byte IDBCM1_LIN1_01;                /*327*/
  byte IDWWSs_01;                     /*328*/
  byte IDSOSES_01 ;                   /*329*/ 
#ifdef ASIC_TEST
  byte ASIC_Frame_01_g;               /*330*/ 
  byte ASIC_Frame_02_g;               /*331*/ 
  byte ASIC_Frame_03_g;               /*332*/ 
  byte ASIC_Frame_04_g;               /*333*/ 
#endif
  byte ASIC_RCTR_REG_g ;              /*334*/ 
  byte ASIC_RFCTR_REG_g ;             /*335*/ 
  byte Error_Active_1_g ;             /*336*/   
  byte Error_Active_2_g ;             /*337*/   
  byte Error_Active_3_g ;             /*338*/    
  byte Erase_counter[4] ;             /*339*/  
  byte VariantID_g;            /*343*/ 
  word FunctionID_g;           /*344,345*/ 
  byte IDERRDATA_01 ;                /*346*/ 
  byte IDSPARE_01 ;                /*347*/ 
} s_rb_EEPROMStruct_PD_g;



typedef union {
  unsigned char _c[cb_NumberofEEPROMCells_PD_g];
  s_rb_EEPROMStruct_PD_g EEPROMStructPD;
} s_rb_EEPROMStructPD_buff_g;



/* PRQA S 3116,0759 4*//*<< 3116:#pragma needed for IAR compiler and MISRA, 0759:union needed to reduce RAM usage >>*/

EXTERN  s_rb_EEPROMStructPD_buff_g EEPROM_Struct_PD;

#define rb_Kodierbyte0_g                                EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte0_g 
#define rb_Kodierbyte1_g                                EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte1_g 
#define rb_Kodierbyte2_g                                EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte2_g 
#define rb_ALS1_4_Setting_g                             EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g 
#define rb_ALS5_6_INREC_Setting_g                       EEPROM_Struct_PD.EEPROMStructPD.ALS5_6_INREC_Setting_g 
#define rb_ASIC_DIAGV_g                                 EEPROM_Struct_PD.EEPROMStructPD.ASIC_DIAGV_g 
#define rw_A_Factor_ALS1_g                              EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS1_g 
#define rw_A_Factor_ALS2_g                              EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS2_g 
#define rw_A_Factor_ALS3_g                              EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS3_g 
#define rw_A_Factor_ALS4_g                              EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS4_g 
#define rw_A_Factor_ALS5_g                              EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS5_g 
#define rw_A_Factor_ALS6_g                              EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS6_g
#define rw_A_Factor_INREC_g                             EEPROM_Struct_PD.EEPROMStructPD.A_Factor_INREC_g 
#define rb_B_Factor_Iref_Lo_Gain_Lo_g                   EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Lo_g
#define rb_B_Factor_Iref_Lo_Gain_Hi_g                   EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g 
#define rb_B_Factor_Iref_Hi_Gain_Lo_g                   EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Lo_g 
#define rb_B_Factor_Iref_Hi_Gain_Hi_g                   EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g 
#define rb_CRC_Checksum_calibration_g                   EEPROM_Struct_PD.EEPROMStructPD.CRC_Checksum_calibration_g 
#define rb_Standby_rain_measurement_1_g                 EEPROM_Struct_PD.EEPROMStructPD.Standby_rain_measurement_1_g 
#define rb_Standby_rain_measurement_2_g                 EEPROM_Struct_PD.EEPROMStructPD.Standby_rain_measurement_2_g 
#define rb_Standby_rain_measurement_3_g                 EEPROM_Struct_PD.EEPROMStructPD.Standby_rain_measurement_3_g 
#define rb_Standby_rain_measurement_4_g                 EEPROM_Struct_PD.EEPROMStructPD.Standby_rain_measurement_4_g 
#define rb_Standby_rain_measurement_5_g                 EEPROM_Struct_PD.EEPROMStructPD.Standby_rain_measurement_5_g 
#define rb_Standby_rain_measurement_6_g                 EEPROM_Struct_PD.EEPROMStructPD.Standby_rain_measurement_6_g 
#define rb_ASIC_Sched_Config_g                          EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g  
#define rb_ASIC_LCTR_g                                  EEPROM_Struct_PD.EEPROMStructPD.ASIC_LCTR_g  
#define CW_NO_RAIN_PRESENT_THRSH_HB_g                   EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g  
#define CW_NO_RAIN_PRESENT_THRSH_LB_g                   EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g  
#define rb_STBY_REGV_Imbalance_g                        EEPROM_Struct_PD.EEPROMStructPD.STBY_REGV_Imbalance_g 
#define rb_RSControlFlags_g                             EEPROM_Struct_PD.EEPROMStructPD.RSControlFlags  
#define rb_IDFSs_Enh_01_g                               EEPROM_Struct_PD.EEPROMStructPD.IDFSs_Enh_01_g 
#define rab_HardwareStand_g(a)                          (EEPROM_Struct_PD.EEPROMStructPD.HardwareStand[(a)])
#define rab_Produktionsdaten_g(a)                       (EEPROM_Struct_PD.EEPROMStructPD.Produktionsdaten[(a)])
#define rab_Fertigungsdatum_g(a)                        (EEPROM_Struct_PD.EEPROMStructPD.Fertigungsdatum[(a)])
#define rab_Audi_HW_Partnumber_g(a)                     (EEPROM_Struct_PD.EEPROMStructPD.Audi_HW_Partnumber[(a)])
#define rb_NAD_g                                        EEPROM_Struct_PD.EEPROMStructPD.NAD 
#define rb_IDFSs_01_g                                   EEPROM_Struct_PD.EEPROMStructPD.IDFSs_01 
#define rb_IDRLSs_01_g                                  EEPROM_Struct_PD.EEPROMStructPD.IDRLSs_01 
#define rb_IDBCM1_LIN1_01_g                             EEPROM_Struct_PD.EEPROMStructPD.IDBCM1_LIN1_01 
#define rb_IDWWSs_01_g                                  EEPROM_Struct_PD.EEPROMStructPD.IDWWSs_01 
#define rb_IDSOSES_01_g                                 EEPROM_Struct_PD.EEPROMStructPD.IDSOSES_01  
#define rb_IDERRDATA_01_g                               EEPROM_Struct_PD.EEPROMStructPD.IDERRDATA_01  
#define rb_IDSPARE_01_g                                 EEPROM_Struct_PD.EEPROMStructPD.IDSPARE_01  

#define rb_ASIC_RCTR_REG_g                              EEPROM_Struct_PD.EEPROMStructPD.ASIC_RCTR_REG_g  
#define rb_ASIC_RFCTR_REG_g                             EEPROM_Struct_PD.EEPROMStructPD.ASIC_RFCTR_REG_g  
#define rb_Error_Active_1_g                             EEPROM_Struct_PD.EEPROMStructPD.Error_Active_1_g  
#define rb_Error_Active_2_g                             EEPROM_Struct_PD.EEPROMStructPD.Error_Active_2_g  
#define rb_Error_Active_3_g                             EEPROM_Struct_PD.EEPROMStructPD.Error_Active_3_g  
#define rab_Erase_counter_g(a)                          EEPROM_Struct_PD.EEPROMStructPD.Erase_counter[a]  
/* PRQA S 3453 1*/ /*<< Function type is required by MISRA, but unions are already used! >>*/

#ifdef ASIC_TEST
#define rb_ASIC_Frame_01_g                               EEPROM_Struct_PD.EEPROMStructPD.ASIC_Frame_01_g 
#define rb_ASIC_Frame_02_g                               EEPROM_Struct_PD.EEPROMStructPD.ASIC_Frame_02_g 
#define rb_ASIC_Frame_03_g                               EEPROM_Struct_PD.EEPROMStructPD.ASIC_Frame_03_g 
#define rb_ASIC_Frame_04_g                               EEPROM_Struct_PD.EEPROMStructPD.ASIC_Frame_04_g 
#endif


#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/ 
#define  rbi_RLFS_is_FS_g                                    ((rb_RSControlFlags_g & 0x10)>0)
#endif
#define rbi_AlwaysIntervalThrs_g                             ((rb_RSControlFlags_g & 0x80)>0)
#define rbi_HumTemp_Module_enabled_g                         ((rb_RSControlFlags_g & 0x08)>0)
#define rbi_RainSensor_enabled_g                             (rb_RSControlFlags_g & 0x01)
/*VDR_276*/
#define rbi_RainsensorAlwaysOn_g                             ((rb_RSControlFlags_g & 0x40)>0)
#define rbi_VW_BritghtnessScaling_g                          ((rb_RSControlFlags_g & 0x01)>0)

#define rbi_SoSe_Enabled_g                                   ((rb_RSControlFlags_g & 0x02)>0)


/* Byte 0*/
#define rbi_Freewaylight_enabled_g                      ((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte0_g & 0x01)>0)
#define rbi_RainLight_enabled_g                         ((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte0_g & 0x02)>0)
#define rbi_StandbyFunction_enabled_g                   ((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte0_g & 0x04)>0)
#define rb_LightSensorCoding_g                          ((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte0_g & 0x38)>>3)
#define rbi_RainsensorDisabled_g                        ((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte0_g & 0x40)>0)
#define rbi_SignalQuelleWischerParklage_g               ((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte0_g & 0x80)>0)
/* Byte 1*/
#define rb_Regensensorposition_horizontal_g             ((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte1_g & 0x01)>0)
#define rb_Regensensorposition_vertikal_g               ((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte1_g & 0x02)>0)
#define rb_Parametersatz_Regensensorik_g                ((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte1_g & 12)>>2)
#define rb_Gegenlaufwischeranlage_g                     ((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte1_g & 0x10)>0)

#define rb_VariantID_g                                  EEPROM_Struct_PD.EEPROMStructPD.VariantID_g 
#define rw_FunctionID_g                                 EEPROM_Struct_PD.EEPROMStructPD.FunctionID_g 

#define rb_SI_Transmission_Korrektur_g                  ((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte1_g & 0xE0)>>5)


#define rb_Si_Transmission_1_g    (byte)((((word)(rb_550nm_Transmission_g + (cab_SI_Transmission_Offsett[rb_SI_Transmission_Korrektur_g]-15)) )*9)/(15)) 

#define rb_Si_Transmission_g            ((rb_Si_Transmission_1_g >= 5)?  rb_Si_Transmission_1_g: 5) /* VDR_796 */

/* Byte 2*/
#define rb_550nm_Transmission_g         (((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte2_g & 0x0F)*5)+15)
#define rb_880nm_Transmission_g         ((((EEPROM_Struct_PD.EEPROMStructPD.EEKodierbyte2_g & 0xF0)>>4)*5)+15)

#define rb_SI_880nmWavelenght_factor_g                 0xFF
#define rw_a_Correction_Inrec_g                        0xFF
#define rb_b_Correction_Inamb1_g                       0xFF
#define rb_b_Correction_Inrec_g                        0xFF
#define rw_a_Correction_Inamb2_g                        0xFF
#define rb_b_Correction_Inamb2_g                        0xFF
#define rw_a_Correction_Inamb1_g                        0xFF
#define rbi_ModulatorOff_ForINAMB1_meas_g               0xFF
#define rbi_LightSensorInactive_g                       0xFF



#define CW_E2_NAD_ADRESS              (324)
#define CW_E2_IDFSS_01_ADRESS         (325)
#define CW_E2_IDRLSS_01_ADRESS        (326)
#define CW_E2_IDBCM1_LIN1_01_ADRESS   (327)
#define CW_E2_IDWWSS_01_ADRESS        (328)
#define CW_E2_IDSOSES_01_ADRESS       (329)
#define CW_E2_IDFSS_ENH_01_ADRESS     (306)
#define CW_E2_IDFSS_ERR_DATA_ADRESS   (346)

#define CW_E2_ERASECOUNTER_ADRESS     (339)


#define cw_EEPROM_CODING_ADDRESS_g    (268)



#endif
