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
* 10.07.10 "RLS_VCO_63","RLS_VCO_64", AL use two default variables for RLS and RLF*
* 22.09.14 RLS_VCO_152 : Customenr part number shall be stored in EEPROM
*									*
************************************************************************/
/* 13.05.15   VCO_243 NB Implement Function ID and Variant ID in the EEPROM PD section */
/* 29.06.15   VCO_256 NB Introduce systembezeichnung G397_RLSS and set invalid as default  */



// ------------------ configuration for AUDI B8 Diagnose --------------

#define _SUPPORTSERVICE21_
#define _SUPPORTSERVICE22_
#define _SUPPORTMWLLIGHT_
#define _SUPPORTCODING2E_
#define _SUPPORTSERVICE3D_
#undef _SUPPORTMWLLIGHT_
#define NOT_SUPPORT_SERVICE_1519TO1525

#ifdef _SUPPORTCODING3B_
#error not used 
#endif

#ifdef _SUPPORTSERVICE1A_
#error not used 
#endif

#define _SUPPORTASSIGNNAD_

#define cb_INITAL_TARGET_ADDRESS_s    0x02

// ------------------ defines for AUDI B8 Diagnose --------------

#define cb_SOFTWARESTAND_0_g  'X'
#define cb_SOFTWARESTAND_1_g  '0'
#define cb_SOFTWARESTAND_2_g  '1'

#define cb_SOFTWARESTAND_3_g            '0'
#define cb_SWSTAND_ADD_ON_WITH_RAIN_g   'A'      /* increase for subversion can be read out at address 80 */
#define cb_SWSTAND_ADD_ON_NO_RAIN_g   (cb_SWSTAND_ADD_ON_WITH_RAIN_g+32)

/*is rain function */
#ifndef _NO_RAIN_
#define cb_SWSTAND_ADD_ON_g     cb_SWSTAND_ADD_ON_WITH_RAIN_g
#else
#define cb_SWSTAND_ADD_ON_g     cb_SWSTAND_ADD_ON_NO_RAIN_g
#endif /*_NO_RAIN_*/


#define cb_HARDWARESTAND_g    'H'
#define cb_HARDWARESTAND_0_g  '0'
#define cb_HARDWARESTAND_1_g  '1'



/*--------
 00001111
 0000FLSR
 --------*/
#define SYSTEM_NAMES_RLS                                       \
/* {ID  ,   Name}  at least one entry should exist*/           \
  {0x01,"RAINSENSOR      "} /* Rain*/                         


#endif /* G5_DIAGNOSE_PROJECTCONFIG_H*/
