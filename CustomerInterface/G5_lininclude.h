/******************************************************************************/
/*                                                                            */
/*   Valeo Schalter und Sensoren GmbH                                         */
/*   Stuttgarter Str. 119                                                     */
/*   74321 Bietigheim-Bissingen                                               */
/*                                                                            */
/*   All rights reserved. Distribution or duplication without previous        */
/*   written agreement of the owner prohibited.                               */
/*                                                                            */
/******************************************************************************/
/*   Source: D:/ldws/software/ecu/linconf.h  */
/*   Revision:   1.7   */
/*   Author:   SBA272   */
/*   Date:   Sep 08 2003 10:58:24   */
/******************************************************************************/
/*   MODULE:                                                                  */
/*   FILE:                                                                    */
/******************************************************************************/
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                       */
/*----------------------------------------------------------------------------*/
/* 25.11.2014   VCO_200    NB     Include G5_lininclude.h instead rls.h and linconf.h  */
/* 28.08.2015   VCO_268    SP     Cleanup the LIN modules  */
/* 09.11.15     VCO_282    NB    All:Add spare LIN IDs in the EEPROM                   */
/* 07.12.17     VCO_462    HB    FIAT 330 interfaces: parallel branch                  */
/******************************************************************************/
#ifndef I_LININC_H
#define I_LININC_H

#include "G5_projectDefs.h"


#if defined AUDI_C6_KS_LIN1_3
#include "G5_linconf_c6.h"
#elif (defined FERRARI) || (defined GEN3_5A_FCA)
#include "G5_linconf_Ferrari.h"
#elif defined FIAT_330
#include "G5_linconf_Fiat_330.h"
#elif defined GEELY_RS
#include "G5_linconf_geely.h"
#elif defined TESLA
#include "G5_linconf_Tesla.h"
#elif defined HAITEC
#include "G5_linconf_HAITEC.h"
#elif defined FOTON_S700
#include "G5_linconf_FOTON_S700.h"
#elif defined FORD
#include "G5_linconf_ford.h"
#elif defined BRILLIANCE_M8X
#include "G5_linconf_BRILLIANCE_M8X.h"
#elif defined BAICYX_G20
#include "G5_linconf_BAICYX_G20.h"
#elif defined CTCS_M31T
#include "G5_linconf_CTCS_M31T.h"
#elif defined FARADAY
#include "G5_linconf_Faraday.h"
#elif defined GEELY_NL_3A
#include "G5_linconf_GEELY_NL_3A.h"
#elif defined BAICYX_H50
#include "G5_linconf_BAICYX_H50.h"
#elif defined NL_5
#include "G5_linconf_NL_5.h"
#elif defined ZOTYE_A40
#include "gen_linconf_ZOTYE_A40.h"
#elif defined DFLQ_RLFSS
#include "G5_linconf_DFLQ_RLFSS.h"
#elif defined Zoety_A10
#include "G5_linconf_Zoety_A10.h"
#elif defined Chery_T18
#include "G5_linconf_Chery_T18.h"
#elif defined Chery_T1A_35A_Standby
#include "G5_linconf_Chery_T1A_3.5A_Standby.h"
#elif defined CHJ_M01
#include "G5_linconf_CHJ_M01.h"
#elif defined Chery_KX63
#include "G5_linconf_Chery_KX63.h"
#elif defined GREAT_WALL_CH071
#include "gen_linconf_Great_Wall_CH071.h"
#elif defined GEELY_FS11
#include "G5_linconf_GEELY_FS11.h"
#elif defined GEELY_FS11_NOLIGHT
#include "G5_linconf_GEELY_FS11_NoLight.h"
#elif defined ZOTYE_B01_NEW
#include "gen_linconf_ZOTYE_B01_NEW.h"
#elif defined BYTON
#include "G5_linconf_BYTON.h"
#elif defined GEELY2DOT0
#include "G5_linconf_GEELY2DOT0.h"
#elif defined SOKON
#include "G5_linconf_SOKON.h"
#elif defined GAC_RLS
#include "G5_linconf_GAC_RLS.h"
#elif defined ZOTYE_B21
#include "G5_linconf_ZOTYE_B21.h"
#elif defined CHANG_AN_S311
#include "gen_linconf_CHANGAN_S311.h"
#elif defined BYD_HC
#include "G5_linconf_BYD_HC.h"
#else
#include "G5_linconf.h" /* for _FEUCHTE_ */
#endif

#include "G5_LINsci_sr.h"
#include "G5_rls_linst.h"


#if defined AUDI_C6_KS_LIN1_3
#include "G5_rlsc6.h"
#elif (defined FERRARI) || (defined GEN3_5A_FCA)
#include "G5_rls_Ferrari.h"
#elif defined FIAT_330
#include "G5_rls_Fiat_330.h"
#elif defined GEELY_RS
#include "G5_rlsGeely.h"
#elif defined TESLA
#include "G5_rls_Tesla.h"
#elif defined HAITEC
#include "G5_rlsHAITEC.h"
#elif defined FOTON_S700
#include "G5_rls_FOTON_S700.h"
#elif defined FORD
#include "G5_rls_ford.h"
#elif defined BRILLIANCE_M8X
#include "G5_rls_BRILLIANCE_M8X.h"
#elif defined BAICYX_G20
#include "G5_rls_BAICYX_G20.h"
#elif defined CTCS_M31T
#include "G5_rls_CTCS_M31T.h"
#elif defined FARADAY
#include "G5_rls_Faraday.h"
#elif defined GEELY_NL_3A
#include "G5_rls_Geely_NL_3A.h"
#elif defined BAICYX_H50
#include "G5_rls_BAICYX_H50.h"
#elif defined NL_5
#include "G5_rls_NL_5.h"
#elif defined ZOTYE_A40
#include "G5_rls_ZOTYE_A40.h"
#elif defined DFLQ_RLFSS
#include "G5_rls_DFLQ_RLFSS.h"
#elif defined Zoety_A10
#include "G5_rls_Zoety_A10.h"
#elif defined Chery_T18
#include "G5_rls_Chery_T18.h"
#elif defined Chery_T1A_35A_Standby
#include "G5_rls_Chery_T1A_3.5A_Standby.h"
#elif defined CHJ_M01
#include "G5_rls_CHJ_M01.h"
#elif defined Chery_KX63
#include "G5_rls_Chery_KX63.h"
#elif defined GREAT_WALL_CH071
#include "G5_rls_Great_Wall_CH071.h"
#elif defined GEELY_FS11
#include "G5_rls_GEELY_FS11.h"
#elif defined GEELY_FS11_NOLIGHT
#include "G5_rls_GEELY_FS11_NoLight.h"
#elif defined ZOTYE_B01_NEW
#include "G5_rls_ZOTYE_B01_NEW.h"
#elif defined BYTON
#include "G5_rls_BYTON.h"
#elif defined GEELY2DOT0
#include "G5_rls_GEELY2DOT0.h"
#elif defined SOKON
#include "G5_rls_SOKON.h"
#elif defined GAC_RLS
#include "G5_rls_GAC_RLS.h"
#elif defined ZOTYE_B21
#include "G5_rls_ZOTYE_B21.h"
#elif defined CHANG_AN_S311
#include "G5_rls_CHANGAN_S311.h"
#elif defined BYD_HC
#include "G5_rls_BYD_HC.h"
#else
#include "G5_rls.h"
#endif



/******************************************************************************/
/*                    Declaration of exported variables                       */
/******************************************************************************/




#endif


