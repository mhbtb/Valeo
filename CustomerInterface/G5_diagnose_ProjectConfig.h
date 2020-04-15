#ifndef G5_DIAGNOSE_PROJECTCONFIG_H
#define G5_DIAGNOSE_PROJECTCONFIG_H
/**************VALEO WIPER SYSTEMS**SMART*SENSORS************************
*                                                                       *
*  HEADER FILE NAME : DiagnoseVWK.h              				*
*                                                                       *
*  LIBRARY ID       :                                                   *
*                                                                       *
*  DESCRIPTION      : interface LIN                                     *
*									*
*									*
*                                                                       *
*  SPECIAL LOGIC    :                                                   *
*                                                                       *
*************************************************************************
*                                                                       *
*                         MODIFICATION LOG                              *
*                                                                       *
* Date      VerNo  Description                                 Auth     *
* --------  -----  ------------------------------------------  -------- *
* 27.06.11  VDR_671  new release label                            AL    *
* 13.12.10  RLS_VCO_90  AL RS-Error Classification                      *
* 18.11.10  VCO_086  AL    implement FS-Services for Diagnostics        *
* 23.11.00   1.0   Initial Release				JS      *
* 29.02.08        VDR_152 , VDR155 new function ID              AL      *
* 10.03.08        VDR_157 , Dewpoint not set correct            AL      *
* 20.10.08  VCO_12    SW-Partnumber index and Humidity disable   AL     *
* 29.09.09  VDR_376 new version for AUDI Konzernsensor          AL      *
* 10.07.10 "RLS_VCO_63","RLS_VCO_64", AL use two default variables for RLS and RLF */
/* 22.09.14 RLS_VCO_152 : Customenr part number shall be stored in EEPROM */
/*14.04.15   VCO_243     NB      Implement Function ID and Variant ID in the EEPROM PD section */
/*29.06.15  VCO_256  NB  Introduce systembezeichnung G397_RLSS and set invalid as default      */
/*19.02.16  VCO_313  NB  Create new variant Feuchte_Solar and Rain_Light_solar for SEAT        */
/*25.02.16  VCO_313  NB  Create new variant Feuchte_Solar and Rain_Light_solar for SEAT        */ 
/*06.02.17  VCO_376  NB  Seat:Implement seat LID for service 0x22                              */ 
/************************************************************************/

#include "G5_projectDefs.h"

// ------------------ configuration for AUDI B8 Diagnose --------------

#define _SUPPORTSERVICE21_
#define _SUPPORTSERVICE22_
#if defined AUDI_C6_KS_LIN1_3
#define NOT_SUPPORT_SERVICE_1519TO1525
#else 
#define _SUPPORTMWLLIGHT_
#endif
#define _SUPPORTCODING2E_
#define _SUPPORTSERVICE3D_



#ifdef _SUPPORTCODING3B_
#error not used 
#endif

#ifdef _SUPPORTSERVICE1A_
#error not used 
#endif

#define _SUPPORTASSIGNNAD_

#define cb_INITAL_TARGET_ADDRESS_s    0x02

// ------------------ defines for AUDI B8 Diagnose --------------

#define cb_SOFTWARESTAND_0_g  '0'
#define cb_SOFTWARESTAND_1_g  '0'
#define cb_SOFTWARESTAND_2_g  '7'

#define cb_SOFTWARESTAND_3_g            '1'
#define cb_SWSTAND_ADD_ON_WITH_RAIN_g   ' '      /* increase for subversion can be read out at address 80 */
#define cb_SWSTAND_ADD_ON_NO_RAIN_g   (cb_SWSTAND_ADD_ON_WITH_RAIN_g+32)

/*is rain function */
#ifndef _NO_RAIN_
#define cb_SWSTAND_ADD_ON_g     cb_SWSTAND_ADD_ON_WITH_RAIN_g
#else
#define cb_SWSTAND_ADD_ON_g     cb_SWSTAND_ADD_ON_NO_RAIN_g
#endif /*_NO_RAIN_*/


#define cb_HARDWARESTAND_g    'H'
#define cb_HARDWARESTAND_0_g  '0'
#define cb_HARDWARESTAND_1_g  '6'


#define cw_SupplierID_g             0x0066

/*--------
 00001111
 0000FLSR
Bit 7 dedicated for Response_error. if set, error shall be sent in FS frame else in RLS frame
 --------*/
#define SYSTEM_NAMES_RLS                                       \
/* {ID  ,   Name}  at least one entry should exist*/           \
  {0x01,"G397_RS         "}, /* Rain*/                         \
  {0x04,"G397_LS         "}, /* Light*/                        \
  {0x05,"G397_RLS        "}, /* Light, Rain*/                  \
  {0x07,"G397_RLSS       "}, /* Light,Solar, Rain*/            \
  {0x98,"G355_FeuchteS   "}, /* Humidity */                    \
  {0x8A,"G397_FSS        "}, /* Humidity,Solar */              \
  {0x0C,"G397_LFS        "}, /* Humidity,Light */              \
  {0x0D,"G397_RLFS       "}, /* Humidity,Light,Rain */         \
  {0x0E,"G397_LFSS       "}, /* Humidity,Light,Solar */        \
  {0x0F,"G397_RLFSS      "}  /* Humidity,Light,solar,Rain */   


#endif /* G5_DIAGNOSE_PROJECTCONFIG_H*/
