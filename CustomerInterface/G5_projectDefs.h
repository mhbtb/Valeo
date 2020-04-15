/******************************************************************************/
/*                                                                            */
/*   Valeo Schalter und Sensoren GmbH                                         */
/*   Laiernstrasse 12                                                         */
/*   74321 Bietigheim-Bissingen                                               */
/*                                                                            */
/*   All rights reserved. Distribution or duplication without previous        */
/*   written agreement of the owner prohibited.                               */
/*                                                                            */
/******************************************************************************/

/** \file
 *
 *  This file is designed to contain all RLS projects in order to define compiler
 * switches for the RELEASE configuration. The purpose is to have the project -
 * feature relation stored in one header file and thus available for all compilers
 * and third party tools.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: template.h %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.8 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> R.Fichtner, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:57 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> SCOPE:     </td> <td> <Public/Private/Component>      </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All/Freescale S12X/S12XE/...>  </td></tr>
 * </table>
 */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                */
/*----------------------------------------------------------------------------*/
/*09.19.17   VCO_451    NB    All:Add spare LIN IDs in the EEPROM             */
/*07.12.17   VCO_462    HB    FIAT 330: parallel branch                       */
/******************************************************************************/
/*For check in RLFSs*/

#ifndef G5_PROJECT_DEFS_H
#define G5_PROJECT_DEFS_H

#ifdef AUDI_B8_KS
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
#define CS_HT_MODULE
#define CS_SOLAR
#define ASIC_TEST
//#define STARTUP_WIPE
#define RAIN_INTENSITY

#elif defined NL_5
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
#define CS_HT_MODULE
#define CS_SOLAR
#define CS_TWILIGHT_TO_DARK
#define CS_OUTPUT_BRIGHTNESS
#define CS_STANDBY
#define RSS_INKREMENTWIPE
#define ASIC_TEST

#elif defined DFLQ_RLFSS
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
#define CS_HT_MODULE
#define CS_SOLAR
#define CS_TWILIGHT_TO_DARK
#define CS_OUTPUT_BRIGHTNESS
#define RSS_INKREMENTWIPE
#define ASIC_TEST

#elif defined AUDI_C6_KS_LIN1_3
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
#define CS_SOLAR


#elif defined AUDI_B8_KS_NO_RAIN
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
#define CS_HT_MODULE
#define CS_SOLAR
#define ASIC_TEST
#define _NO_RAIN_

#elif defined GEELY_RS
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
#define GEN_35A
#define NO_AMB_DIODE
#define NO_FW_DIODE
#define ASIC_TEST

#elif defined GEN3_5A_AUDI
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
//#define CS_HT_MODULE
//#define CS_SOLAR
#define LIGHT_BASED_ON_FW_AND_IR
#define GEN_35A
#define ASIC_TEST

#elif defined FERRARI
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
#define CS_HT_MODULE
#define CS_HT_ENH_MODULE /* Enhanced HT message*/
#define CS_SOLAR
#define ASIC_TEST

#elif defined FIAT_330
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
#define CS_HT_MODULE
// #define CS_HT_ENH_MODULE /* Enhanced HT message*/
#define CS_SOLAR
#define ASIC_TEST

#elif defined GEN3_5A_FCA
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
#define GEN_35A
#define LIGHT_BASED_ON_FW_AND_IR
#define ASIC_TEST

#elif defined TESLA
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
#define CS_HT_MODULE
#define CS_HT_ENH_MODULE /* Enhanced HT message*/
#define CS_SOLAR
#define CS_ERR_FRAME
#define CS_TWILIGHT_TO_DARK
#define ASIC_TEST

#elif defined HAITEC
#define AUDI_B8
#define ASIC_TEST

#elif defined FOTON_S700
#define AUDI_B8
#define GEN_35A
#define ASIC_TEST

#elif defined FORD
#define AUDI_B8  
#define RLFS_TO_FS_ENBLED 
#define CS_PART_NUMBER_FRAME 
#define CS_HT_ENH_MODULE /* used for wiper motor frame WMM_L8_FrP00 */
#define CS_ERR_FRAME  
#define GEN_35A 
#define ASIC_TEST 
#define _ONETIME_OR_DOUBLE_OVERWIPED_
#define LIGHT_BASED_ON_FW_AND_IR

#elif defined BRILLIANCE_M8X
#define AUDI_B8
#define GEN_35A
#define ASIC_TEST

#elif defined BAICYX_G20
#define AUDI_B8
#define GEN_35A
#define ASIC_TEST

#elif defined CTCS_M31T
#define AUDI_B8
#define GEN_35A
#define ASIC_TEST

#elif defined FARADAY
#define AUDI_B8 
#define RLFS_TO_FS_ENBLED 
#define CS_HT_MODULE 
#define CS_HT_ENH_MODULE
#define CS_SOLAR 
#define ASIC_TEST 
#define CS_TWILIGHT_TO_DARK
#elif defined GEELY_NL_3A

#define AUDI_B8
#define GEN_35A
#define ASIC_TEST

#elif defined BAICYX_H50

#define AUDI_B8
#define GEN_35A
#define ASIC_TEST

#elif defined ZOTYE_A40
#define AUDI_B8
#define ASIC_TEST
#define GEN_35A

#elif defined Zoety_A10
#define AUDI_B8
#define CS_RAIN
#define CS_LIGHT
#define CS_TWILIGHT_TO_DARK
#define CS_STANDBY
#define ASIC_TEST
#define RSS_INKREMENTWIPE


#elif defined Chery_T18
#define AUDI_B8
#define ASIC_TEST
#define CS_RAIN
#define CS_LIGHT
#define GEN_35A


#elif defined CHJ_M01
#define AUDI_B8
#define CS_TWILIGHT_TO_DARK
#define CS_STANDBY
#define CS_RAIN
#define CS_LIGHT
#define ASIC_TEST
#define CS_OUTPUT_BRIGHTNESS
#define CS_SOLAR


#elif defined BYTON
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
#define CS_HT_MODULE
#define CS_SOLAR
#define CS_LIGHT
#define CS_RAIN
#define CS_STANDBY
#define CS_OUTPUT_BRIGHTNESS
#define CS_TWILIGHT_TO_DARK
#define RAIN_INTENSITY
#define ASIC_TEST


#elif defined Chery_KX63
#define AUDI_B8
#define ASIC_TEST
#define CS_RAIN
#define CS_LIGHT
#define GEN_35A

#elif defined GREAT_WALL_CH071
#define AUDI_B8
#define ASIC_TEST

#elif defined GEELY_FS11
#define AUDI_B8
#define CS_OUTPUT_BRIGHTNESS
#define CS_STANDBY
#define RSS_INKREMENTWIPE
#define ASIC_TEST
#define HUD_FUNCTION
#define STANDBY_LIN_WAKE_UP_ISSUE

#elif defined GEELY_FS11_NOLIGHT
#define AUDI_B8
#define CS_STANDBY
#define RSS_INKREMENTWIPE
#define ASIC_TEST
#define STANDBY_LIN_WAKE_UP_ISSUE

#elif defined ZOTYE_B01_NEW
#define AUDI_B8
#define ASIC_TEST

#elif GEELY2DOT0
#define AUDI_B8
#define RLFS_TO_FS_ENBLED
#define CS_HT_MODULE
#define CS_SOLAR
#define CS_OUTPUT_BRIGHTNESS
#define CS_STANDBY
//#define ASIC_TEST
#define HUD_FUNCTION
#define STANDBY_LIN_WAKE_UP_ISSUE
#define RAIN_INTENSITY
#define G6_Standby  
#define RSS_INKREMENTWIPE_FIX_CONTINUOUS


#endif
#endif //G5_PROJECT_DEFS_H
