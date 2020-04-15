#ifndef G5_DIAGNOSE_FERRARI_PROJECTCONFIG_H
#define G5_DIAGNOSE_FERRARI_PROJECTCONFIG_H
/**************VALEO WIPER SYSTEMS**SMART*SENSORS************************
*                                                                       *
*  HEADER FILE NAME : G5_diagnose_FERRARI_ProjectConfig.h       	*
*                                                                       *
*  LIBRARY ID       :                                                   *
*                                                                       *
*  DESCRIPTION      : project specific definitions                      *
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
* 23.11.00   1.0   Initial Release				JS      *
*									*
************************************************************************/
/*12.05.15   VCO_243     NB      Implement Function ID and Variant ID in the EEPROM PD section */
/*29.06.15   VCO_256     NB      Introduce systembezeichnung G397_RLSS and set invalid as default  */
/*12.05.16   VCO_325     NB      FCA:Integration VCO to merge the changes from Audi 002 baseline to FCA 004 baseline*/
/*30.05.16   VDR_983     NB      Sporadic illegale instruction reset in the startup                              */
/************************************************************************/


// ------------------ configuration for FERRARI Diagnose --------------

#define _SUPPORTSERVICE1A_
#define _SUPPORTCODING3B_
#define _SUPPORTCODING2E_
#define _SUPPORTSERVICE21_
#define _SUPPORTSERVICE22_
#undef _SUPPORTMWLLIGHT_
#define _DIAGREQLENGTHCHECK_
#define NOT_SUPPORT_SERVICE_1519TO1525

#define cb_INITAL_TARGET_ADDRESS_s      0x04

// ------------------ defines for FERRARI Diagnose --------------
#if defined GEN3_5A_FCA
#define cb_SOFTWARESTAND_0_g  'X'
#define cb_SOFTWARESTAND_1_g  '0'
#define cb_SOFTWARESTAND_2_g  '1'
#define cb_SOFTWARESTAND_3_g  '3'
#define cb_SWSTAND_ADD_ON_g   'B'      /* increase for subversion can be read out at adress 58*/
#else
#define cb_SOFTWARESTAND_0_g  'X'
#define cb_SOFTWARESTAND_1_g  '0'
#define cb_SOFTWARESTAND_2_g  '0'
#define cb_SOFTWARESTAND_3_g  '7'
#define cb_SWSTAND_ADD_ON_g   'B'      /* increase for subversion can be read out at adress 58*/
#endif
#define cb_HARDWARESTAND_g  'H'
#define cb_HARDWARESTAND_0_g  '0'
#define cb_HARDWARESTAND_1_g  '1'
   

#define cw_SupplierID_g             0x0066

/*--------
 00001111
 0000FLSR
 --------*/
#define SYSTEM_NAMES_RLS                                      \
/* {ID  ,   Name}  at least one entry should exist*/          \
  {0x01,"RS_FCA         "}, /* Rain*/                         \
  {0x04,"LS_FCA         "}, /* Light*/                        \
  {0x05,"RLS_FCA        "}, /* Light, Rain*/                  \
  {0x07,"RLSS_FCA       "}, /* Light,Solar, Rain*/            \
  {0x08,"HS_FCA         "}, /* Humidity */                    \
  {0x0C,"LHS_FCA        "}, /* Humidity,Light */              \
  {0x0D,"RLHS_FCA       "}, /* Humidity,Light,Rain */         \
  {0x0E,"LHSS_FCA       "}, /* Humidity,Light,Solar */        \
  {0x0F,"RLHSS_FCA      "}  /* Humidity,Light,solar,Rain */   

   


#endif /*G5_DIAGNOSE_FERRARI_PROJECTCONFIG_H*/