
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
/*                                            */
/*      Source:         FlashE2.h       */
/*      Revision:             */
/*      Author:         <author name>                                         */
/*      UserID:         SBA294       */
/*      Date                  */
/*                                                                            */
/*                                              */
/******************************************************************************/
/*   MODULE: FlashE2                                                          */
/*   FILE:   FlashE2.h                                                        */
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  NAME Description                                       */
/*----------------------------------------------------------------------------*/
/* 05.05.10  VDR_505       function declaration */
/* 12.08.14  VDR_797     NB   Watchdog reset due to High CPU load while erasing the EEPROM cluster */
/* 24.03.2016 VCO_316   NB   No_init RAM values shall be used to connect  bootload mode instead of EEPROM */
/**

 * \brief H File for the Flash Emulated EEPROM Handling "FlashE2 Modul"
 *
 *  Contains all puplic elements like functions etc. for the application.
 *

*/

#ifndef G5_FLASHE2_H
#define G5_FLASHE2_H

#ifdef _flashE2_c_
/** \brief Defines EXTERN as comment if h-File is included by own module FlashE2.c to declare variables*/
#define EXTERN /**/
#else
/** brief Defines EXTERN as extern if h-File is included by another module 
than FlashE2.c to refer variables as external*/
#define EXTERN  extern
#endif
#include "pfdl.h"
/******************************************************************************/
/*                 Definition of exported symbolic constants                   */
/******************************************************************************/
/*  Comment:  EEPROM Error Code (rb_EEPROMErrFlag_g)              */
/*  Range  :  0 to 255                                                           */
/** \brief Defines error code for rb_EEPROMErrFlag_g 'no error' */
#define cb_EEPROM_NOERROR_g                         0
/** \brief Defines error code for rb_EEPROMErrFlag_g 'single error' */
#define cb_EEPROM_SINGLEERROR_CORRECTED_g           1
/** \brief Defines error code for rb_EEPROMErrFlag_g 'double error' */
#define cb_EEPROM_DOUBLEERROR_INVALIDCORRECTION_g   2
/** \brief Defines error code for rb_EEPROMErrFlag_g 'can not read error' */
#define cb_EEPROM_CANTREAD_g                        4
/** \brief Defines error code for reading of 0xff (empty cell) */
#define cb_EEPROM_CELLEMPTY_g                       8

/*  Comment:  EEPROM Error Code (rb_EEPROM_Status_g)              */
/*  Range  :  0 to 255                                                           */
/** \brief EEPROM is not loaded   */
#define cb_E2STATUS_NOTLOADED_g        0
/** \brief EEPROM is now initializing    */
#define cb_E2STATUS_INITIALIZATION_g   1
/** \brief EEPROM is like a virgin (nothing is in the eeprom)   */
#define cb_E2STATUS_LIKEAVIRGIN_g      2
/** \brief EEPROM is initialised and in autoinitialising data set is noting */
#define cb_E2STATUS_INITIALIZED_g      3
/** \brief EEPROM is initialised and the data are not default*/
#define cb_E2STATUS_NONDEFAULT_g       4
/** \brief EEPROM is initialised and the data are not default*/
#define cb_E2STATUS_CLUSTERINIT_g      5

/** \brief number of areas in EEPROM (AD,PD, RD)*/
#define cb_NUM_EEPROM_AREAS_g                 (byte)3

/** \brief defines for range selection */
#define cw_ADRPRE_PD_mg         (word)0x0100
#define cw_ADRPRE_AD_mg         (word)0x0200
#define cw_ADRPRE_RD_mg         (word)0x0300
/** \brief mask for range selection */
#define cw_ADRSELMASK_mg        (word)0x0300

#define cw_ADREEPROM_START_g          (word)0x100
#define cw_ADREEPROM_END_g            (word)0x3FF

/** \brief defines for area index */
#define cb_AREA_PD_g    (byte)0x00
#define cb_AREA_AD_g    (byte)0x01
#define cb_AREA_RD_g    (byte)0x02

/** \brief Number of EEPROM Clusters */
#define cb_NUM_CLUSTER_mg   (byte)4

/******************************************************************************/
/*                Definition of exported function like macros                 */
/******************************************************************************/

/******************************************************************************/
/*          Definition of exported types (typdefs, enums, struct, union)      */
/******************************************************************************/

/******************************************************************************/
/*                    Declaration of exported variables                       */
/******************************************************************************/
/**

 
 * \ingroup external
 * \brief exported variable Error flag, will be written in DTC if set
 * See alsoe defines for rb_EEPROMErrFlag_g */

EXTERN pfdl_descriptor_t pfdl_descriptor;
EXTERN pfdl_request_t pfdl_request;

EXTERN   byte rb_EEPROMErrFlag_g;

/**
 * \ingroup external
 * this variable allows to read the used number of bytes in the emulated eeprom
 * do not write in this variable from extern*/
EXTERN  word rw_EEPROMPointer_g[cb_NUM_EEPROM_AREAS_g];
/** \brief Status of the cluster*/
EXTERN byte rb_ClusterStatus_mg[cb_NUM_CLUSTER_mg];
/**
 * \ingroup external
 * \brief Control flags to show internal states or problems */
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN  volatile Flag uF_E2Flag_g;

#define rbi_ChangingCluster_mg      uF_E2Flag_g.Bit.B1
#define rbi_ClearCluster_mg         uF_E2Flag_g.Bit.B2
#define rbi_ClearNewCluster_mg      uF_E2Flag_g.Bit.B3
#define rbi_BlankCell_mg            uF_E2Flag_g.Bit.B4
#define rbi_DefaultValues_mg        uF_E2Flag_g.Bit.B6
#define rbi_NonDefaultValues_mg     uF_E2Flag_g.Bit.B7

/** \brief Are for which the cluster should be changed*/
EXTERN byte rb_ChangeCluster_mg;
#define cb_ChangeCluster_PD_mg  (byte)0x01
#define cb_ChangeCluster_AD_mg  (byte)0x02
#define cb_ChangeCluster_RD_mg  (byte)0x04



/**
 * \ingroup external
 * \brief Error flags to show emulated EEPROM problems */
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN   volatile Flag uF_E2ConfigErrorFlags_g;
#define rbi_WriteError_g              uF_E2ConfigErrorFlags_g.Bit.B0
#define rbi_EraseError_g              uF_E2ConfigErrorFlags_g.Bit.B1
#define rbi_OutOfRangeError_g         uF_E2ConfigErrorFlags_g.Bit.B2
#define rbi_ClusterError_g            uF_E2ConfigErrorFlags_g.Bit.B3
#define rbi_BlankBetweenError_g       uF_E2ConfigErrorFlags_g.Bit.B4
#define rbi_HammingWarning_g          uF_E2ConfigErrorFlags_g.Bit.B5
#define rbi_HammingError_g            uF_E2ConfigErrorFlags_g.Bit.B6
#define rbi_ClusterFormatError_g      uF_E2ConfigErrorFlags_g.Bit.B7

/**
 * \ingroup external
 * \brief shows status of write process  */
EXTERN  byte rb_EEPROM_WriteStatus_g;
/**
 * \ingroup external
 * \brief shows status of erase process  */
EXTERN  byte rb_EraseStatus_g;

/**
 * \ingroup external
 * \brief shows status of eeprom process  */
EXTERN  byte rb_EEPROM_Status_g;

EXTERN  byte rb_EEPROM_EraseOngoing_g;  /* VDR_797 */

/******************************************************************************/
/*                  Declaration of exported constant data                     */
/******************************************************************************/

/******************************************************************************/
/*               Declaration of exported function prototypes                  */
/******************************************************************************/
EXTERN void EEProm_LoadInit(void);
EXTERN byte EEProm_InitCluster(void);
EXTERN void EEProm_Load(void);
EXTERN void EEProm_PreInitDefault(void);
EXTERN void EEProm_LoadDefault(void);
EXTERN byte EEProm_WriteCodedByte(byte ByteToWrite, word AddressToWrite);
EXTERN void EEProm_ChangeClusterStart(void);
EXTERN void EEProm_ChangeCluster(void);
EXTERN void EEProm_ClearCluster(void);
EXTERN void Enter_BootLoad_Mode(void);
EXTERN void ClearValidateString(void);
/******************************************************************************/
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN

#define CLEAR_EEPROM     0xff
#define INIT_E2VARIABLES 0x00
/******************************************************************************/
/*                                            */
/* END  Source:         FlashE2.h       */
/*                                              */
/******************************************************************************/

#endif /* G5_FLASHE2_H */
