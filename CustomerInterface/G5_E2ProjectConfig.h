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
 * This header file bundles the generic EEPROM configuration with the project
 * specific definitions. Thus, it represents the EEPROM configuration in the
 * context of the given project.
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Author:   </td> <td> RF, DUS-E-RLS  </td></tr>
 * </table>
 * \n
 */
/* * Date      VerNo  Auth         Description                                         */
/*09.11.15   VCO_282    NB    All:Add spare LIN IDs in the EEPROM                      */
/* 07.12.17     VCO_462    HB    FIAT 330 interfaces: parallel branch                  */

#ifndef G5_E2PROJECT_CONFIG_h
#define G5_E2PROJECT_CONFIG_h

#include "G5_projectDefs.h"

#if (defined FERRARI) || (defined GEN3_5A_FCA)
#include "G5_diagnose_FERRARI_ProjectConfig.h"
#elif defined FIAT_330
#include "G5_diagnose_FIAT_330_ProjectConfig.h"
#elif defined GEELY_RS
#include "G5_diagnose_GEELY_ProjectConfig.h"
#elif defined TESLA
#include "G5_diagnose_TESLA_ProjectConfig.h"
#elif defined HAITEC
#include "G5_diagnose_HAITEC_ProjectConfig.h"
#elif defined FOTON_S700
#include "G5_diagnose_FOTON_S700_ProjectConfig.h"
#elif defined FORD
#include "G5_diagnose_Ford_ProjectConfig.h"
#elif defined BRILLIANCE_M8X
#include "G5_diagnose_BRILLIANCE_M8X_ProjectConfig.h"
#elif defined BAICYX_G20
#include "G5_diagnose_BAICYX_G20_ProjectConfig.h"
#elif defined CTCS_M31T
#include "G5_diagnose_CTCS_M31T_ProjectConfig.h"
#elif defined FARADAY
#include "G5_diagnose_FARADAY_ProjectConfig.h"
#elif defined GEELY_NL_3A
#include "G5_diagnose_GEELY_NL_3A_ProjectConfig.h"
#elif defined BAICYX_H50
#include "G5_diagnose_BAICYX_H50_ProjectConfig.h"
#elif defined NL_5
#include "G5_diagnose_GEELY_NL_5_ProjectConfig.h"
#elif defined ZOTYE_A40
#include "G5_diagnose_ZOTYE_A40_ProjectConfig.h"
#elif DFLQ_RLFSS
#include "G5_diagnose_DFLQ_RLFSS_ProjectConfig.h"
#elif defined Zoety_A10
#include "G5_diagnose_Zoety_A10_ProjectConfig.h"
#elif defined Chery_T18
#include "G5_diagnose_Chery_T18_ProjectConfig.h"
#elif defined CHJ_M01
#include "G5_diagnose_CHJ_M01_ProjectConfig.h"
#elif defined Chery_KX63
#include "G5_diagnose_Chery_KX63_ProjectConfig.h"
#elif defined GREAT_WALL_CH071
#include "G5_diagnose_Great_Wall_CH071_ProjectConfig.h"
#elif defined GEELY_FS11
#include "G5_diagnose_GEELY_FS11_ProjectConfig.h"
#elif defined GEELY_FS11_NOLIGHT
#include "G5_diagnose_GEELY_FS11_NoLight_ProjectConfig.h"  
#elif defined ZOTYE_B01_NEW
#include "G5_diagnose_ZOTYE_B01_NEW_ProjectConfig.h"
#elif defined BYTON
#include "G5_diagnose_BYTON_ProjectConfig.h"
#elif defined GEELY2DOT0
#include "G5_diagnose_GEELY2DOT0_ProjectConfig.h"
#else
#include "G5_diagnose_ProjectConfig.h"/* for _VW_KONZERNSENSOR_ */
#endif

#include "G5_DiagE2_projectconfig.h"


#endif  /* G5_E2PROJECT_CONFIG_h */
