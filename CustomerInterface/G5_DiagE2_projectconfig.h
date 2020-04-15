/**************VALEO Switches and Detection Systems**SMART*SENSORS*******
*                                                                       *
*  HEADER FILE NAME : DiagE2_projectconfig.h                      *
*                                                                       *
*  LIBRARY ID       :                                                   *
*                                                                       *
*  DESCRIPTION      : - interface for all projects, when                *
*                        define "__USE_OLD_DIAGE2CONFIG_H__" is not set *
*                     - sets all EEPROM header files project related    *
*                     - sets error when project is unknown              *
*                                                                       *
*  SPECIAL LOGIC    :                                                   *
*                                                                       *
*************************************************************************
*                                                                       *
*                         MODIFICATION LOG                              *
*                                                                       *
* Date      VerNo  Description                                 Auth     *
* DD.MM.YY  -----  ------------------------------------------  -------- */
/* 27.11.2014   VCO_200    NB     Include structure  */
/* 09.11.15      VCO_282 NB      All:Add spare LIN IDs in the EEPROM    */
/* 07.12.17     VCO_462    HB    FIAT 330 interfaces: parallel branch   */
/************************************************************************/
#ifndef _DIAGE2_PROJECTCONFIG_H_
#define _DIAGE2_PROJECTCONFIG_H_

#include "G5_projectDefs.h"


/* Include PD first place */
#if (defined FERRARI) || (defined GEN3_5A_FCA)
#include "G5_FERRARI_DiagE2Mapping_PD.h"
#elif defined FIAT_330
#include "G5_FIAT_330_DiagE2Mapping_PD.h"
#elif defined AUDI_C6_KS_LIN1_3
#include "G5_AUDI_C6_DiagE2Mapping_PD.h"
#elif defined GEELY_RS
#include "G5_GEELY_DiagE2Mapping_PD.h"
#elif defined TESLA
#include "G5_TESLA_DiagE2Mapping_PD.h"
#elif defined HAITEC
#include "G5_HAITEC_DiagE2Mapping_PD.h"
#elif defined FOTON_S700
#include "G5_FOTON_S700_DiagE2Mapping_PD.h"
#elif defined FORD
#include "G5_Ford_DiagE2Mapping_PD.h"
#elif defined BRILLIANCE_M8X
#include "G5_BRILLIANCE_M8X_DiagE2Mapping_PD.h"
#elif defined BAICYX_G20
#include "G5_BAICYX_G20_DiagE2Mapping_PD.h"
#elif defined CTCS_M31T
#include "G5_CTCS_M31T_DiagE2Mapping_PD.h"
#elif defined FARADAY
#include "G5_FARADAY_DiagE2Mapping_PD.h"
#elif defined GEELY_NL_3A
#include "G5_GEELY_NL_3A_DiagE2Mapping_PD.h"
#elif defined BAICYX_H50
#include "G5_BAICYX_H50_DiagE2Mapping_PD.h"
#elif defined NL_5
#include "G5_GEELY_NL_5_DiagE2Mapping_PD.h"
#elif defined ZOTYE_A40
#include "G5_DiagE2_ZOTYE_A40_Mapping_PD.h"
#elif DFLQ_RLFSS
#include "G5_DiagE2_DFLQ_RLFSS_Mapping_PD.h"
#elif defined Zoety_A10
#include "G5_DiagE2_Zoety_A10_Mapping_PD.h"
#elif defined Chery_T18
#include "G5_DiagE2_Chery_T18_Mapping_PD.h"
#elif defined Chery_T1A_35A_Standby
#include "G5_DiagE2_Chery_T1A_3.5A_Standby_Mapping_PD.h"
#elif defined CHJ_M01
#include "G5_DiagE2_CHJ_M01_Mapping_PD.h"
#elif defined Chery_KX63
#include "G5_DiagE2_Chery_KX63_Mapping_PD.h"
#elif defined GREAT_WALL_CH071
#include "G5_DiagE2_Great_Wall_CH071_Mapping_PD.h"
#elif defined GEELY_FS11
#include "G5_GEELY_FS11_DiagE2Mapping_PD.h"
#elif defined GEELY_FS11_NOLIGHT
#include "G5_GEELY_FS11_NoLight_DiagE2Mapping_PD.h"
#elif defined ZOTYE_B01_NEW
#include "G5_DiagE2_ZOTYE_B01_NEW_Mapping_PD.h"
#elif defined BYTON
#include "G5_DiagE2_BYTON_Mapping_PD.h"
#elif defined GEELY2DOT0
#include "G5_GEELY2DOT0_DiagE2Mapping_PD.h"
#elif defined SOKON
#include "G5_SOKON_DiagE2Mapping_PD.h"
#elif defined GAC_RLS
#include "G5_DiagE2_GAC_RLS_Mapping_PD.h"
#elif defined ZOTYE_B21
#include "G5_DiagE2_ZOTYE_B21_Mapping_PD.h"
#elif defined CHANG_AN_S311
#include "G5_CHANGAN_S311_DiagE2Mapping_PD.h"
#elif defined BYD_HC
#include "G5_DiagE2_BYD_HC_Mapping_PD.h"
#else
#include "G5_DiagE2Mapping_PD.h"
#endif

/* Include AD second place */
#include "G5_DiagE2Mapping_AD.h"

/* Include RD Third place */
#include "G5_DiagE2Mapping_RD.h"



#endif
