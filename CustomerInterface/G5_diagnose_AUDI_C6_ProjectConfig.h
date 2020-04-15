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
/*14.04.15   VCO_243     NB      Implement Function ID and Variant ID in the EEPROM PD section */
/*29.06.15   VCO_256     NB      Introduce systembezeichnung G397_RLSS and set invalid as default  */

#ifdef _DIAGNOSE_c_
#define EXTERN /**/
#else
#define EXTERN  extern
#endif

// ------------------ configuration for AUDI B8 Diagnose --------------

#define _SUPPORTSERVICE21_
#define _SUPPORTSERVICE22_
//#define _SUPPORTMWLLIGHT_
#define _SUPPORTCODING2E_
#define _SUPPORTSERVICE3D_
#define NOT_SUPPORT_SERVICE_1519TO1525

#ifdef _SUPPORTCODING3B_
#error not used 
#endif

#ifdef _SUPPORTSERVICE1A_
#error not used 
#endif

#define _SUPPORTASSIGNNAD_


// ------------------ defines for AUDI B8 Diagnose --------------

#define cb_SOFTWARE_TYP_g      1
#define cb_SOFTWARESTAND_0_g  'X'
#define cb_SOFTWARESTAND_1_g  '0'
#define cb_SOFTWARESTAND_2_g  '0'

/*is rain function */
#ifndef _NO_RAIN_
#define cb_SOFTWARESTAND_3_g  '8'
#define cb_SWSTAND_ADD_ON_g   'H'      /* increase for subversion can be read out at adress 74 */
#else
#define cb_SOFTWARESTAND_3_g  '8'
#define cb_SWSTAND_ADD_ON_g   ('H'+32)      /* increase for subversion can be read out at adress 74 */
#endif /*_NO_RAIN_*/

#define cb_HARDWARESTAND_g    'H'
#define cb_HARDWARESTAND_0_g  '0'
#define cb_HARDWARESTAND_1_g  '1'


#define cw_SupplierID_g             0x0066

#define cb_INITAL_TARGET_ADDRESS_s    0x02

#ifdef _DIAGNOSE_c_


#ifdef DIAG_ZSB_ENABLED   
const byte cab_ZSB_Teilenummer_mitF_g[11] = "81A955555  ";
#endif



#ifdef DIAG_ZSB_ENABLED   
#define cab_ZSB_Teilenummer_g(a)    cab_ZSB_Teilenummer_mitF_g[a]
#endif

/*--------
 00001111
 0000FLSR
 --------*/

typedef struct 
{
  byte Id;
  byte SystemName[16];
}Systembezeichnung_t;

EXTERN const Systembezeichnung_t  Systembezeichnung[] = {
  /* ID     Name */
  {0x01,"G397_RS         "}, /* Rain*/
  {0x04,"G397_LS         "}, /* Light*/
  {0x05,"G397_RLS        "}, /* Light, Rain*/
  {0x07,"G397_RLSS       "}, /* Light,Solar, Rain*/
  {0x08,"G355_FeuchteS   "}, /* Humidity */
  {0x0C,"G397_LFS        "}, /* Humidity,Light */
  {0x0D,"G397_RLFS       "}, /* Humidity,Light,Rain */
  {0x0E,"G397_LFSS       "}, /* Humidity,Light,Solar */
  {0x0F,"G397_RLFSS      "}  /* Humidity,Light,solar,Rain */
};


/*This are the default Partnumbers if the value is adjusted to 0*/

#ifdef _SUPPORTSERVICE1A_
#define cab_Coustomer_Teilenummer_g(a)     cab_HW_Teilenummer_g[a]
#define cab_Coustomer_VAG_Teilenummer_g(a) cab_HW_Teilenummer_g[a]
#endif
   
#endif

#endif /* G5_DIAGNOSE_PROJECTCONFIG_H*/
