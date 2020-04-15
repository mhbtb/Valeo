/* PRQA S 0434,0436,0781,4130 EOF */ /* << 0434,0436 usage of SFR >> */
/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/
/* PRQA S 841,781 EOF *//*<< 841:use of #undef needed, Unions needed  >>*/
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 5540,5560,5565,5900 EOF *//*<< Data needs to be verified  >>*/
/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
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
/*   Source: d:/ldws/software/ecu/eeprom.c  */
/*   Revision:   1.6   */
/*   Author:   SBA272   */
/*   Date:   Apr 13 2004 14:20:52   */
/******************************************************************************/
/*   MODULE: Flash Emulated EEPROM Handling                                   */
/*   FILE:                                                                    */
/******************************************************************************/
/*                                                                            */
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 25.11.10  VDR_579        use actual error not to use all following EEPROM Data*/
/* 05.05.10  VCO_029        initialise EEPROM correct*/
/* 05.05.10  VDR_505        rework function for flexible usage */
/* 08.03.10  VCO_40         improve speed of hamming decoding*/
/* 03.02.08  VDR_87         Misra Warning for MISRA Rule 101*/
/* 03.02.08  VDR_87         Misra Warning for MISRA Rule 101*/
/* 04.02.08  VDR_131        use erase counter in EEPROM */

/* 17.03.14  VDR_765      NB    Internal watchdog reset while storing Error codes into EEPROM */
/* 12.08.14  VDR_797     NB   Watchdog reset due to High CPU load while erasing the EEPROM cluster */
/* 24.09.14  VCO_183     NB   Rearrangement of EEPROM */
/* 18.11.14  VCO_195     NB   Correction of QAC warnings */
/* 07.04.15  VDR_868     NB   Polyspace correction */
/*03.07.2015 VCO_258    NB    Use 4 bytes of cluster ID for PD,AD and RD sections */
/* 02.10.2015 VCO_276   NB      Initialise LIN ID's after loading PD section */
/* 20.11.2015 VDR_928   NB   Internal Reset is not detected when both bootloader and application is flashed together */
/* 10.12.2015 VDR_941   NB   PFDL library shall be initialised before operation */
/* 04.03.2016 VCO_316   NB   No_init RAM values shall be used to connect  bootload mode instead of EEPROM */
/* 24.03.2016 VCO_316   NB   No_init RAM values shall be used to connect  bootload mode instead of EEPROM */
/* 24.03.2016 VDR_966   NB   PFDL library shall be opened and closed when required to improve the initialisation time */
/* 13.04.2017 VDR_1032   NB   Discard EEPROM record if there is a blank between errors */
/******************************************************************************/
/******************************************************************************/
/*                      Common and module include file                        */
/******************************************************************************/

/**
* \mainpage Flash Emulated EEPROM Handling "FlashE2 Modul"
<!-- * \htmlinclude spic.html           -->
* \section intro_sec Introduction
*
* This document is generated automatically with doxygen, with the help of tags in
* the source code.
*
* \section install_sec Description of the different tabs
*
* \subsection step1 Main Page:
* The main tab contains a small introduction over the contents of this file.
*
* \subsection step2 Module / Interface Specification:
* Gives an overview over the Interface should be renamed to Interface Specification,
  but at the moment it is not possible to rename it.
*
* \subsection step3 Data Structures:
* The Data Structures tab contains a brief description of all specified data structures and data fields.
*
* \subsection step4 Files:
* The Files tab contains a brief description of all module files.
*
* \subsection step5 Related Pages:
* The Related Pages contains all existing pages for the FlashE2 module e.g. Integration Guidline, Compile Options,... .
*
* \file FlashE2.c
* \brief C File for the Emulated EEPROM Handling "FlashE2 Modul".
*
* This module managed the communication between the Application emulated EEPROM in the Flash
* Read Values from EEPROM decode Hamming coding and detect errors and compensate single bit errors\n
* Hamming coding of EEPROM cells \n
* Writing EEPROM cells into emulated EEPROM \n
* Clusterchange of EEPROM if Cluster is nearly full \n
*
* <!--  -->
* b Source:     FlashE2.c
* version       1.12
* author        Schenk Jochen
* author        SBA294
* date          26-JUL-2007 08:08:38
* todo          Still open points here
* <!--  -->
*/

/******************************************************************************/
/*                  Integration Guidline                                      */
/******************************************************************************/

/**
* \page integration Integration Guidline
* </p>
* <h2>Function calls</h2>
* <p>
* The application calls the function EEProm_LoadInit() during initialization
* To load the parameters the function EEProm_Load() have to be called
* till the bit rbi_EEPROMLoad_g is set from TRUE to false.
* </p>
* <p>
* To write a EEPROM cell the function EEProm_WriteCodedByte() have to be used
* </p>
* <p>
* To change the cluster the EEProm_ChangeClusterStart(void) followed by the
* function EEProm_ChangeCluster(void) have to be called.
* to delete a cluster the function  EEProm_ClearCluster() have to be called.
* </p>
* <h2>Output variables</h2>
* <p>
* Errors are monitored eighter in the deticated return value or in the global
* error flags rb_EEPROMErrFlag_g and uF_E2ConfigErrorFlags_g
* </p>
*/

/******************************************************************************/
/*                             Compile options                                */
/******************************************************************************/

/**
* \page  Compile options
* </p>
* <h2>none compile options </h2>
* <p>
* no compile options
* </p>

*/


/******************************************************************************/
/*              Include of common and projekt definitions header              */
/******************************************************************************/
#include "ior5f109be.h" /* Standarddefinitions */
#include "G5_projectDefs.h"
#define _flashE2_c_
#include "G5_flashe2.h"   /* Own includefile */
#undef _flashE2_c_

/******************************************************************************/
/*                           Other files included                             */
/******************************************************************************/
#include "G5_io_sen.h" 
#include "G5_Appli_main.h" 
#include "G5_E2Handler.h"
#include "G5_E2ProjectConfig.h"
#include "G5_diagnose.h"    /* Diagnostic header file*/
#include "G5_lininclude.h"
#include "pfdl.h"   /* timer include file */


#define CLK_FREQUENCY 16


/******************************************************************************/
/*                     Declaration of local module macros                     */
/******************************************************************************/
 pfdl_descriptor_t pfdl_descriptor;
 pfdl_request_t pfdl_request;

__no_init byte rb_ValidateString_mg[8] @ 0xFFD20; /* do not change this address.Required to bootload */
/** \brief Hamming checkbits for coding and decoding*/
static const byte cab_CheckBits_mg[16] = { 0x80,0x31,0x52,0xE3,
0x64,0xD5,0xB6,0x07,
0xF8,0x49,0x2A,0x9B,
0x1C,0xAD,0xCE,0x7F};

static byte rb_PfdlData_mg[4];
/******************************************************************************/
/*                 Definition of symolic constants                   */
/******************************************************************************/
/*  Comment: cb_SPAREBEFORCHANGE_mg               */
/*  Range  :  4-100 should be multiple of four            */
/** \brief sets left space in EEPROM cluster  */
#define cb_SPAREBEFORCHANGE_mg   (byte)20

/*  Comment: cb_MAXERASERETRYS_mg              */
/*  Range  :  4-100 should be multiple of four              */
/** \brief maximum number of retries for erase  */
#define cb_MAXERASERETRYS_mg  (byte)10

/*  Comment: cb_DATASIZE_mg            */
/*  Range  :  4 (no other value)       */
/** \brief number of bits for hamming coding */
#define cb_DATASIZE_mg      (byte)4



/** \brief Defines for Cluster status */
#define cb_CL_EMPTY_mg          (byte)0xFF
#define cb_CL_TOBECLEAR_mg      (byte)0xCC
#define cb_CL_IDX_PD_mg         (byte)cb_AREA_PD_g
#define cb_CL_IDX_AD_mg         (byte)cb_AREA_AD_g
#define cb_CL_IDX_RD_mg         (byte)cb_AREA_RD_g

/** \brief Define for rb_ClusterIdxMap_mg */
#define cb_NO_CLUSTER_ASSIGNED_mg   (byte)0xEE


/** \brief Magic word for detecting cluster type */
static const byte cb_MagicWord_mg[3][4] = { {0x0f,0xf5,0xe7,0x00},
                                            {0xE1,0x1E,0xE1,0x01},
                                            {0xD2,0x2D,0xD2,0x02} };
/** \brief Start Adress of Emulated EEPROM Clusters */
static const word cw_FLASHCLUSTERSTART_mg[cb_NUM_CLUSTER_mg] = {0x000,0x400,0x800,0xC00};
/** \brief End Adress of Emulated EEPROM Clusters */
/* Last 4 bytes needed to write boot load string */
static const word cw_FLASHCLUSTEREND_mg[cb_NUM_CLUSTER_mg] = {0x3FB,0x7FB,0xBFB,0xFFB}; 

/******************************************************************************/
/*                   Declaration of local module variables                    */
/******************************************************************************/

/** \brief counter for erase retrys */
static  byte rb_ClEraseRetry_mg;

/** \brief  Write buffer for data transfer to selflib needs 4 bytes for selflib */
static  byte rb_WriteBuffer_mg[4];


/** \brief  storage of last written cell*/
static  word rw_EEPROMLastEntryPointer_mg[cb_NUM_EEPROM_AREAS_g];


/** \brief Mapping between AreaIdx to cluster idx */
static byte rb_ClusterIdxMap_mg[cb_NUM_EEPROM_AREAS_g];


/** \brief cluster idx of unsused cluster, only valid while changing cluster*/
static byte rb_ClusterIdxFree_mg;

/** \brief counter for used clusters*/
static byte rb_UsedClusterCnt_mg;

/** \brief marker for area index of clusters to be changed*/
static byte rb_ChangeClusterSrcArea_mg;

/** \brief memorize source cluster idx*/
static byte rb_ChangeClusterSrcCluster_mg;
static byte rb_PFDL_Open_mg;

static word rw_EEPROMAdr_mg;
/******************************************************************************/
/*                     Prototypes of local functions                          */
/******************************************************************************/

static byte EEPROM_OddParity(byte rb_Code_l);
static byte EEPROM_Decode(byte rb_Code_l);
static byte EEProm_Read(word rw_EepromAddress_l,byte *pb_Address_l, byte *pb_Data_l);
static byte EEProm_Write4Bytes(word rw_EEPROMAddress_l, byte *pb_ByteToWrite_l);


static void RLS_PFDL_Open(void);
static void RLS_PFDL_Close(void);


/**************************************************************************
Syntax   :    void EEProm_Init(void)
Object   :    EEProm_Init()
Parameters :  none
Return  :     none
Calls   :     main.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************/
/**
* \brief
*  The needed variables for the FlashE2.c are set to init state.
*  This function decides which EEPROM Cluster is active. If neccessary the
*  flags to change the clusters are set.
*
* \pre         none
* \param[in]   none
* \return      none
*
*/

void EEProm_LoadInit(void)
{
  
  word rw_Offset_l;
  word rw_LowerBoarder_l;
  word rw_UpperBoarder_l;
  byte rb_Idx_l;
  byte rb_ClearCluster_l;
  byte rb_DoubleClusterA_l;
  byte rb_DoubleClusterB_l;
  byte rb_EEPROMPointerA_l;
  byte rb_EEPROMPointerB_l;
  byte rb_ClusterAreaId_l; 
  
  byte rb_ClusterStart_l[cb_NUM_CLUSTER_mg][4];
  byte rb_ClusterEnd_l[cb_NUM_CLUSTER_mg];
  
  
  rb_ChangeCluster_mg = 0;
  
  rb_EEPROM_Status_g = cb_E2STATUS_NOTLOADED_g;
  rbi_NonDefaultValues_mg = FALSE;
  rbi_BlankBetweenError_g = FALSE;
  rbi_BlankCell_mg = FALSE;
  
  pfdl_descriptor.fx_MHz_u08 = CLK_FREQUENCY;
  pfdl_descriptor.wide_voltage_mode_u08 = 0x00; /* Full speed mode */
  pfdl_request.data_pu08 = &rb_PfdlData_mg[0];
  
  RLS_PFDL_Open();
  
  for (rb_Idx_l=0;rb_Idx_l < cb_NUM_CLUSTER_mg;rb_Idx_l++)
  {
    /* Read first 4 bytes from EEPROM cluster */
    pfdl_request.command_enu = PFDL_CMD_READ_BYTES;
    pfdl_request.bytecount_u16 = 4;
    pfdl_request.data_pu08 = &rb_ClusterStart_l[rb_Idx_l][0];
    pfdl_request.index_u16 = cw_FLASHCLUSTERSTART_mg[rb_Idx_l];
    (void)PFDL_Execute(&pfdl_request);
    
    /* Read last byte of the EEPROM cluster */
    pfdl_request.command_enu = PFDL_CMD_READ_BYTES;
    pfdl_request.bytecount_u16 = 1;
    pfdl_request.data_pu08 = &rb_ClusterEnd_l[rb_Idx_l];
    pfdl_request.index_u16 = cw_FLASHCLUSTEREND_mg[rb_Idx_l];
    (void)PFDL_Execute(&pfdl_request);
  }
  
  /* Clear Cluster Mapping lookup table */
  for (rb_Idx_l=0;rb_Idx_l < cb_NUM_EEPROM_AREAS_g;rb_Idx_l++)
  {
    rb_ClusterIdxMap_mg[rb_Idx_l] = cb_NO_CLUSTER_ASSIGNED_mg;
  }
  
  
  /* Map clusters */
  
  rb_UsedClusterCnt_mg = 0;
  
  for (rb_Idx_l=0;rb_Idx_l < cb_NUM_CLUSTER_mg;rb_Idx_l++)
  {
    rb_ClusterAreaId_l = rb_ClusterStart_l[rb_Idx_l][3]; /* get the cluster area ID */
    if (rb_ClusterEnd_l[rb_Idx_l] == 0xdd) /* clearing not finished */
    {
      rb_ClusterStatus_mg[rb_Idx_l] = cb_CL_TOBECLEAR_mg;
      rbi_ClearCluster_mg = TRUE;
    }    
    else if ((rb_ClusterStart_l[rb_Idx_l][0] == 0xFF) && (rb_ClusterStart_l[rb_Idx_l][1] == 0xFF) /* empty cluster */
             && (rb_ClusterStart_l[rb_Idx_l][2] == 0xFF) && (rb_ClusterStart_l[rb_Idx_l][3] == 0xFF))
    {
      rb_ClusterStatus_mg[rb_Idx_l] = cb_CL_EMPTY_mg;
    }
    else if ((rb_ClusterStart_l[rb_Idx_l][0] == cb_MagicWord_mg[rb_ClusterAreaId_l][0]) /* magic word correct? */
             && (rb_ClusterStart_l[rb_Idx_l][1] == cb_MagicWord_mg[rb_ClusterAreaId_l][1])
               && (rb_ClusterStart_l[rb_Idx_l][2] == cb_MagicWord_mg[rb_ClusterAreaId_l][2])
                 && (rb_ClusterStart_l[rb_Idx_l][3] == cb_MagicWord_mg[rb_ClusterAreaId_l][3]))
    {
      /* rb_ClusterStart_l[3] contains E2AreaID */
      rb_ClusterStatus_mg[rb_Idx_l] = rb_ClusterStart_l[rb_Idx_l][3];
      
      if (rb_ClusterIdxMap_mg[rb_ClusterStart_l[rb_Idx_l][3]&0x03] == cb_NO_CLUSTER_ASSIGNED_mg)
      {
        rb_ClusterIdxMap_mg[rb_ClusterStart_l[rb_Idx_l][3]&0x03] = rb_Idx_l;
        rw_EEPROMPointer_g[rb_ClusterStart_l[rb_Idx_l][3]&0x03] = cw_FLASHCLUSTERSTART_mg[rb_Idx_l] + 4;
        rb_UsedClusterCnt_mg ++;
      }
      else
      {
        rbi_ClusterError_g = TRUE;
        /* Error two clusters with same ID */
        rb_DoubleClusterA_l = rb_ClusterIdxMap_mg[rb_ClusterStart_l[rb_Idx_l][3]&0x03];
        rb_DoubleClusterB_l = rb_Idx_l;
        
        /*  search cluster with more bytes filled, clear cluster with less data, start cluster change again */
        rb_ClearCluster_l = 0xff;     /* set variables to init values */
        rw_LowerBoarder_l = 0;
        rw_UpperBoarder_l = cw_FLASHCLUSTEREND_mg[0]-cw_FLASHCLUSTERSTART_mg[0];
        
        do
        {
          rw_Offset_l = ((rw_UpperBoarder_l-rw_LowerBoarder_l) >> 1)+rw_LowerBoarder_l;  /* calculate new offset */
          
          pfdl_request.command_enu = PFDL_CMD_READ_BYTES;
          pfdl_request.bytecount_u16 = 1;
          pfdl_request.index_u16 = cw_FLASHCLUSTERSTART_mg[rb_DoubleClusterA_l]+rw_Offset_l;
          (void)PFDL_Execute(&pfdl_request);
          rb_EEPROMPointerA_l = pfdl_request.data_pu08[0];
          
          pfdl_request.index_u16 = cw_FLASHCLUSTERSTART_mg[rb_DoubleClusterB_l]+rw_Offset_l;
          (void)PFDL_Execute(&pfdl_request);
          rb_EEPROMPointerB_l = pfdl_request.data_pu08[0];
          
          rb_ClearCluster_l--; /* decrease Timeout Counter */
          if ((rb_EEPROMPointerA_l != 0xFF) && (rb_EEPROMPointerB_l != 0xFF)) /* empty space behind both pointer? */
          {
            rw_LowerBoarder_l = rw_Offset_l;    /* set lower boarder */
          }
          else if ((rb_EEPROMPointerA_l == 0xFF) && (rb_EEPROMPointerB_l == 0xFF))/* empty space before both pointer? */
          {
            rw_UpperBoarder_l = rw_Offset_l;    /* set upper boarder */
          }
          else if ((rb_EEPROMPointerA_l != 0xFF) && (rb_EEPROMPointerB_l == 0xFF))/* Cluster A contains more data?*/
          {
            /* use cluster A */
            rb_ClusterStatus_mg[rb_DoubleClusterA_l] = rb_ClusterStart_l[rb_Idx_l][3];
            /* clear cluster B */
            rb_ClusterStatus_mg[rb_DoubleClusterB_l] = cb_CL_TOBECLEAR_mg;
            rbi_ClearCluster_mg = TRUE;
            rb_ClearCluster_l = 0; /* exit loop */
          }
          else  /* Cluster B contains more data */
          {
            /* use Cluster B */
            rb_ClusterStatus_mg[rb_DoubleClusterB_l] = rb_ClusterStart_l[rb_Idx_l][3];
            rb_ClusterIdxMap_mg[rb_ClusterStart_l[rb_Idx_l][3]&0x03] = rb_DoubleClusterB_l;
            rw_EEPROMPointer_g[rb_ClusterStart_l[rb_Idx_l][3]&0x03] = cw_FLASHCLUSTERSTART_mg[rb_Idx_l] + 4;
            /* clear cluster A */
            rb_ClusterStatus_mg[rb_DoubleClusterA_l] = cb_CL_TOBECLEAR_mg;
            rbi_ClearCluster_mg = TRUE;
            rb_ClearCluster_l = 0; /* exit loop */
          }
          
          if ((rw_UpperBoarder_l-rw_LowerBoarder_l) < 2)     /* upper and lower boarder nearly the same? */
          {
            /* use Cluster B */
            rb_ClusterStatus_mg[rb_DoubleClusterB_l] = rb_ClusterStart_l[rb_Idx_l][3];
            rb_ClusterIdxMap_mg[rb_ClusterStart_l[rb_Idx_l][3]&0x03] = rb_DoubleClusterB_l;
            rw_EEPROMPointer_g[rb_ClusterStart_l[rb_Idx_l][3]&0x03] = cw_FLASHCLUSTERSTART_mg[rb_Idx_l] + 4;
            /* clear cluster A */
            rb_ClusterStatus_mg[rb_DoubleClusterA_l] = cb_CL_TOBECLEAR_mg;
            rbi_ClearCluster_mg = TRUE;
            /* both have the same size, could not decide which to use */
            rbi_ClusterError_g = TRUE;       /* set Errorflag */
            rb_ClearCluster_l = 0;  /* exit Loop */
          }
          
        } while (rb_ClearCluster_l > 0);
        
      }
    }
    else
    {
      rbi_ClusterFormatError_g = TRUE;
      
      rb_ClusterStatus_mg[rb_Idx_l] = cb_CL_TOBECLEAR_mg;
      rbi_ClearCluster_mg = TRUE;
    }
  }
  RLS_PFDL_Close();
  
  
  for (rb_Idx_l=0;rb_Idx_l < cb_NUM_EEPROM_AREAS_g;rb_Idx_l++)
  {
    rw_EEPROMLastEntryPointer_mg[rb_Idx_l] = rw_EEPROMPointer_g[rb_Idx_l]; 
  }    
  
  /* not all expected clusters found */
  if (rb_UsedClusterCnt_mg != cb_NUM_EEPROM_AREAS_g)
  {
    rb_EEPROM_Status_g = cb_E2STATUS_CLUSTERINIT_g;
  }
  
  rbi_EEPROMLoad_g = TRUE;
  rbi_ChangingCluster_mg = 0;
  rb_ClEraseRetry_mg = 0;
  
  
}


/**************************************************************************
Syntax   :    void EEProm_InitCluster(void)
Object   :    EEProm_InitCluster(void)
Parameters :  none
Return  :     none
Calls   :     EEProm_Load.c
***************************************************************************
Inputs validation conditions: none
initialises EEPROM Cluster with magic word, change rb_EEPROM_Status_g if
all clusters are initalized
***************************************************************************/
/**
* \brief
* writes the magic word in a free cluster, change rb_EEPROM_Status_g if
* all clusters are initalized
*
* \pre         none
* \param[in]   none
* \return      error code
*
*/
byte EEProm_InitCluster(void)
{
  byte rb_Idx_l;
  byte rb_Error_l;
  byte rb_E2AreaID_l;
  
  
  rb_Error_l = 0;
  rb_E2AreaID_l = 0;
  
  while ((rb_E2AreaID_l < cb_NUM_EEPROM_AREAS_g) && (rb_ClusterIdxMap_mg[rb_E2AreaID_l] != cb_NO_CLUSTER_ASSIGNED_mg))
  {
    rb_E2AreaID_l++;
  }
  
  if (rb_E2AreaID_l < cb_NUM_EEPROM_AREAS_g)
  {
    rb_Idx_l = 0;
    while (rb_Idx_l < cb_NUM_CLUSTER_mg)
    {
      if (rb_ClusterStatus_mg[rb_Idx_l] == cb_CL_EMPTY_mg)
      {
        rb_WriteBuffer_mg[0] = cb_MagicWord_mg[rb_E2AreaID_l][0];
        rb_WriteBuffer_mg[1] = cb_MagicWord_mg[rb_E2AreaID_l][1];
        rb_WriteBuffer_mg[2] = cb_MagicWord_mg[rb_E2AreaID_l][2];
        rb_WriteBuffer_mg[3] = rb_E2AreaID_l;
        
        rb_Error_l = EEProm_Write4Bytes(cw_FLASHCLUSTERSTART_mg[rb_Idx_l], rb_WriteBuffer_mg);
        rb_ClusterStatus_mg[rb_Idx_l] = rb_E2AreaID_l;
         /* PRQA S 3689  3 *//*<< cannot be out of bound because it is checked before  >>*/
        rb_ClusterIdxMap_mg[rb_E2AreaID_l] = rb_Idx_l;
        rw_EEPROMPointer_g[rb_E2AreaID_l] = cw_FLASHCLUSTERSTART_mg[rb_Idx_l] + 4;
        rw_EEPROMLastEntryPointer_mg[rb_E2AreaID_l] = rw_EEPROMPointer_g[rb_E2AreaID_l];
        rb_UsedClusterCnt_mg ++;
        rb_Idx_l = 0xEE; /* Exit loop */
      }
      else
      {
        rb_Idx_l++;
      }
    }
    
    if (rb_Idx_l != 0xEE)
    {
      rbi_ClusterError_g = TRUE;
      rb_Error_l = 0x40;  /* set error "No empty cluster" */
    }
    
  }
  else
  {
    rb_EEPROM_Status_g = cb_E2STATUS_NOTLOADED_g;    
  }
  
  return (rb_Error_l);
}



/**************************************************************************
Syntax   :    void EEProm_PreInitDefault(void)
Object   :    EEProm_PreInitDefault()
Parameters :  none
Return  :     none
Calls   :     EEProm_Load.c
***************************************************************************
Inputs validation conditions: none
initialises EEPROM from default Values in Flash all parameters
***************************************************************************/
/**
* \brief
* loads default eeprom data into RAM Mirror of emulated EEPROM.
*
* \pre         none
* \param[in]   none
* \return      none
*
*/
void EEProm_PreInitDefault(void)
{
  byte rb_E2InitAddress_l;
  /* load default values */
  pfdl_descriptor.fx_MHz_u08 = CLK_FREQUENCY;
  pfdl_descriptor.wide_voltage_mode_u08 = 0x00;/* Full speed mode */
  pfdl_request.data_pu08 = &rb_PfdlData_mg[0];
  
  rb_EEPROM_EraseOngoing_g = FALSE;
  
  /* load default Parameters in RAM */
  for( rb_E2InitAddress_l = 0; rb_E2InitAddress_l < cb_NumberofEEPROMCells_PD_g; rb_E2InitAddress_l++ )
  {
    EEPROM_Struct_PD._c[rb_E2InitAddress_l] = cb_EEPROMDataDefaultMinMax_PD_g[rb_E2InitAddress_l][cb_DEFAULT_g];
  }
  for( rb_E2InitAddress_l = 0; rb_E2InitAddress_l < cb_NumberofEEPROMCells_AD_g; rb_E2InitAddress_l++ )
  {
    EEPROM_Struct_AD._c[rb_E2InitAddress_l] = cb_EEPROMDataDefaultMinMax_AD_g[rb_E2InitAddress_l][cb_DEFAULT_g];
  }
  for( rb_E2InitAddress_l = 0; rb_E2InitAddress_l < cb_NumberofEEPROMCells_RD_g; rb_E2InitAddress_l++ )
  {
    EEPROM_Struct_RD._c[rb_E2InitAddress_l] = cb_EEPROMDataDefaultMinMax_RD_g[rb_E2InitAddress_l][cb_DEFAULT_g];
  }
}


/**************************************************************************
Syntax   :    void EEProm_LoadDefault(void)
Object   :    EEProm_LoadDefault()
Parameters :  none
Return  :     none
Calls   :     EEProm_Load.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************/
/**
* \brief
* loads default eeprom data into RAM Mirror of emulated EEPROM.
*
* \pre         none
* \param[in]   none
* \return      none
*
*/
void EEProm_LoadDefault(void)
{
  byte rb_E2Address_l;
  /* load default values */
  
  rb_EEPROM_Status_g = cb_E2STATUS_INITIALIZATION_g;
  uF_E2ConfigErrorFlags_g.AllBit = 0;
  /* - do not load production parameter */
  for( rb_E2Address_l = 0; rb_E2Address_l < cb_NumberofEEPROMCells_AD_g; rb_E2Address_l++ )
  {
    EEPROM_Struct_AD._c[rb_E2Address_l] = cb_EEPROMDataDefaultMinMax_AD_g[rb_E2Address_l][cb_DEFAULT_g];
  }
  for( rb_E2Address_l = 0; rb_E2Address_l < cb_NumberofEEPROMCells_RD_g; rb_E2Address_l++ )
  {
    EEPROM_Struct_RD._c[rb_E2Address_l] = cb_EEPROMDataDefaultMinMax_RD_g[rb_E2Address_l][cb_DEFAULT_g];
  }
  rb_ChangeCluster_mg = cb_ChangeCluster_AD_mg | cb_ChangeCluster_RD_mg;
  
}

/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      void EEProm_Load(void)                                                */
/*                                                                            */
/*  Description:                                                              */
/*                                                                            */
/*  Routine to read the Emulated EEPROM contents from the beginning           */
/*  to the last address.                                                      */
/*  Hamming deciding, errors will be detected and corrected if possible.      */
/*  ther routine have to be called since the                                  */
/*  bye rb_EEPROM_Status_g is cb_E2STATUS_NOTLOADED_g.                        */
/*  Errorflags are signalising different errors:                              */
/*                                                                            */
/*  Input parameters:                                                         */
/*    none                                                                    */
/*                                                                            */
/*  Output parameters:                                                        */
/*    global: Errorflags in uF_E2ConfigErrorFlags_g                           */
/*            rab_EEPROM_ProductionData_g[]                                   */
/*            I2C_EEPROM_Struct._c[]                                          */
/*                                                                            */
/*  Preconditions:                                                            */
/*    EEProm_LoadInit() was called once a transmission                        */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief Routine to read the Emulated EEPROM contents from the beginning to the last address.
* Hamming deciding, errors will be detected and corrected if possible.
* ther routine have to be called since the bye rb_EEPROM_Status_g is cb_E2STATUS_NOTLOADED_g.
* Errorflags are signalising different errors:
* rbi_OutOfRangeError_g:      Variable out of min and max-value
* rbi_BlankBetweenError_g:    Blank is in cluster between datas
* rbi_HammingWarning_g:       Hamming error correct
* rbi_HammingError_g:         Hamming error could not been corrected -> Default Data
*
* \pre         EEProm_LoadInit() has to be called before
* \param[in]   none
* \return      global
* Errorflags in uF_E2ConfigErrorFlags_g
*            rab_EEPROM_ProductionData_g[]
*            I2C_EEPROM_Struct._c[]
*/
void EEProm_Load(void)
{
  
  byte rb_E2Address_l;
  byte rb_E2Data_l;
  byte rb_MemError_l;
  
  
  pfdl_descriptor.fx_MHz_u08 = 16;
  pfdl_descriptor.wide_voltage_mode_u08 = 0x00; /* 00H: Full speed mode */
   RLS_PFDL_Open();
  
  if (rw_EEPROMPointer_g[cb_CL_IDX_PD_mg] < (cw_FLASHCLUSTEREND_mg[rb_ClusterIdxMap_mg[cb_CL_IDX_PD_mg]]-4) )
  {
    rb_MemError_l = EEProm_Read(rw_EEPROMPointer_g[cb_CL_IDX_PD_mg],&rb_E2Address_l,&rb_E2Data_l);
    if (rb_MemError_l == cb_EEPROM_CELLEMPTY_g)
    {
      /* Clear error flag, because this is normal at the end of the filled area, 
         if a blank cell is in between rbi_BlankBetweenError_g is set later */
      rb_MemError_l = 0;  
      rbi_BlankCell_mg = TRUE; 
    }
    else if (rb_MemError_l >= cb_EEPROM_DOUBLEERROR_INVALIDCORRECTION_g)
    {
      rbi_HammingError_g = 1; /* set hamming error flag for storage in EEPROM */
    }
    else
    {
      /*VDR_579 use actual error - data and address valid? (1bit error (corrected) allowed)*/
      if (rb_MemError_l >= cb_EEPROM_SINGLEERROR_CORRECTED_g)
      {
        rbi_HammingWarning_g = 1; /* set hamming error flag for storage in EEPROM */
      }
      
      if (rb_E2Address_l < cb_NumberofEEPROMCells_PD_g)
      {
        /*VDR_579 use actual error -  value within boarder?*/
        if ((rb_E2Data_l >= cb_EEPROMDataDefaultMinMax_PD_g[rb_E2Address_l][cb_CHK_MIN_g])
            && (rb_E2Data_l <= cb_EEPROMDataDefaultMinMax_PD_g[rb_E2Address_l][cb_CHK_MAX_g]))
        {
          EEPROM_Struct_PD._c[rb_E2Address_l] = rb_E2Data_l;   /* write new value in RAM mirror */
          rbi_DefaultValues_mg = TRUE;
        }
        else
        {
          rbi_OutOfRangeError_g = 1;
        }
      }
      /* store pointer of next free position*/
      rw_EEPROMLastEntryPointer_mg[cb_CL_IDX_PD_mg] = rw_EEPROMPointer_g[cb_CL_IDX_PD_mg]+4;   
      if (rbi_BlankCell_mg == TRUE)
      {
        rbi_BlankBetweenError_g = TRUE;     /* set flag for found blank */        
      }
      
    }
    rw_EEPROMPointer_g[cb_CL_IDX_PD_mg] += 4;
    rb_EEPROMErrFlag_g |= rb_MemError_l;
    
#ifndef FORD /*RLS_VDR_1010 RLS_FORD_C1MCA: RSM Partnumber not correctly send on Bus*/
    if (rw_EEPROMPointer_g[cb_CL_IDX_PD_mg] > (cw_FLASHCLUSTEREND_mg[rb_ClusterIdxMap_mg[cb_CL_IDX_PD_mg]]-4) )
     {
       rbi_ReInitTable_g = 1; /* Initialise the LIN ID table because loading of PD section finished */
     }
#endif /*FORD*/
  }
  else if (rw_EEPROMPointer_g[cb_CL_IDX_AD_mg] < (cw_FLASHCLUSTEREND_mg[rb_ClusterIdxMap_mg[cb_CL_IDX_AD_mg]]-4) )
  {
    if (rw_EEPROMPointer_g[cb_CL_IDX_AD_mg] == (cw_FLASHCLUSTERSTART_mg[rb_ClusterIdxMap_mg[cb_CL_IDX_AD_mg]]+4) )
    {
      rbi_BlankCell_mg = FALSE;
    }
    
    rb_MemError_l = EEProm_Read(rw_EEPROMPointer_g[cb_CL_IDX_AD_mg],&rb_E2Address_l,&rb_E2Data_l);
    if (rb_MemError_l == cb_EEPROM_CELLEMPTY_g)
    {
      rbi_BlankCell_mg = TRUE;
      /* Clear error flag, because this is normal at the end of the filled area, 
         if a blank cell is in between rbi_BlankBetweenError_g is set later */
      rb_MemError_l = 0;  
    }
    else if (rb_MemError_l >= cb_EEPROM_DOUBLEERROR_INVALIDCORRECTION_g)
    {
      rbi_HammingError_g = 1; /* set hamming error flag for storage in EEPROM */
    }
    else
    {
      /*VDR_579 use actual error - data and address valid? (1bit error (corrected) allowed)*/
      if (rb_MemError_l >= cb_EEPROM_SINGLEERROR_CORRECTED_g)
      {
        rbi_HammingWarning_g = 1; /* set hamming error flag for storage in EEPROM */
      }
      
      if (rb_E2Address_l < cb_NumberofEEPROMCells_AD_g)
      {
        /*VDR_579 use actual error -  value within boarder?*/
        if ((rb_E2Data_l >= cb_EEPROMDataDefaultMinMax_AD_g[rb_E2Address_l][cb_CHK_MIN_g])
            && (rb_E2Data_l <= cb_EEPROMDataDefaultMinMax_AD_g[rb_E2Address_l][cb_CHK_MAX_g]))
        {
          EEPROM_Struct_AD._c[rb_E2Address_l] = rb_E2Data_l;   /* write new value in RAM mirror */
          if (rb_E2Address_l != (cb_POSITIONDEFAULTSOFTWARE + 1))
          {
            rbi_NonDefaultValues_mg = TRUE;
          }
        }
        else
        {
          rbi_OutOfRangeError_g = 1;
        }
      }
      /* store pointer of next free position */
      rw_EEPROMLastEntryPointer_mg[cb_CL_IDX_AD_mg] = rw_EEPROMPointer_g[cb_CL_IDX_AD_mg]+4;   
      if (rbi_BlankCell_mg == TRUE)
      {
        rbi_BlankBetweenError_g = TRUE;     /* set flag for found blank */   
      }
      
    }
    rw_EEPROMPointer_g[cb_CL_IDX_AD_mg] += 4;
    rb_EEPROMErrFlag_g |= rb_MemError_l;
    
#ifdef FORD /*RLS_VDR_1010 RLS_FORD_C1MCA: RSM Partnumber not correctly send on Bus*/
    if (rw_EEPROMPointer_g[cb_CL_IDX_AD_mg] > (cw_FLASHCLUSTEREND_mg[rb_ClusterIdxMap_mg[cb_CL_IDX_AD_mg]]-4) )
    {
      rbi_ReInitTable_g = 1; /* Initialise the LIN ID table because loading of PD section finished */
    }
#endif /*FORD*/
    
  }
  else if (rw_EEPROMPointer_g[cb_CL_IDX_RD_mg] < (cw_FLASHCLUSTEREND_mg[rb_ClusterIdxMap_mg[cb_CL_IDX_RD_mg]] - 4) )
  {
    if (rw_EEPROMPointer_g[cb_CL_IDX_RD_mg] == (cw_FLASHCLUSTERSTART_mg[rb_ClusterIdxMap_mg[cb_CL_IDX_RD_mg]] + 4) )
    {
      rbi_BlankCell_mg = FALSE;
    }
    
    rb_MemError_l = EEProm_Read(rw_EEPROMPointer_g[cb_CL_IDX_RD_mg],&rb_E2Address_l,&rb_E2Data_l);
    if (rb_MemError_l == cb_EEPROM_CELLEMPTY_g)
    {
      rbi_BlankCell_mg = TRUE;
      /* Clear error flag, because this is normal at the end of the filled area, 
         if a blank cell is in between rbi_BlankBetweenError_g is set later */ 
      rb_MemError_l = 0; 
    }
    else if (rb_MemError_l >= cb_EEPROM_DOUBLEERROR_INVALIDCORRECTION_g)
    {
      rbi_HammingError_g = 1; /* set hamming error flag for storage in EEPROM */
    }
    else
    {
      /*VDR_579 use actual error - data and address valid? (1bit error (corrected) allowed)*/
      if (rb_MemError_l >= cb_EEPROM_SINGLEERROR_CORRECTED_g)
      {
        rbi_HammingWarning_g = 1; /* set hamming error flag for storage in EEPROM */
      }
      
      if (rb_E2Address_l < cb_NumberofEEPROMCells_RD_g)
      {
        /*VDR_579 use actual error -  value within boarder?*/
        if ((rb_E2Data_l >= cb_EEPROMDataDefaultMinMax_RD_g[rb_E2Address_l][cb_CHK_MIN_g])
            && (rb_E2Data_l <= cb_EEPROMDataDefaultMinMax_RD_g[rb_E2Address_l][cb_CHK_MAX_g]))
        {
          EEPROM_Struct_RD._c[rb_E2Address_l] = rb_E2Data_l;   /* write new value in RAM mirror */
          rbi_NonDefaultValues_mg = TRUE;
        }
        else
        {
          rbi_OutOfRangeError_g = 1;
        }
      }
      /* store pointer of next free position */
      rw_EEPROMLastEntryPointer_mg[cb_CL_IDX_RD_mg] = rw_EEPROMPointer_g[cb_CL_IDX_RD_mg]+4;   
      if (rbi_BlankCell_mg == TRUE)
      {
        rbi_BlankBetweenError_g = TRUE;     /* set flag for found blank */       
      }
    }
    rw_EEPROMPointer_g[cb_CL_IDX_RD_mg] += 4;
    rb_EEPROMErrFlag_g |= rb_MemError_l;
  }
  else
  {
    /* set eeprom pointer to next free address */
    rw_EEPROMPointer_g[cb_CL_IDX_PD_mg] = rw_EEPROMLastEntryPointer_mg[cb_CL_IDX_PD_mg];
    rw_EEPROMPointer_g[cb_CL_IDX_AD_mg] = rw_EEPROMLastEntryPointer_mg[cb_CL_IDX_AD_mg];
    rw_EEPROMPointer_g[cb_CL_IDX_RD_mg] = rw_EEPROMLastEntryPointer_mg[cb_CL_IDX_RD_mg];
    
    /* Check SW Version */
    /* SW-Version in ROM not the same than in E2? */
    if (rab_SoftwareStand_g(3) != cb_EEPROMDataDefaultMinMax_AD_g[cb_POSITIONDEFAULTSOFTWARE][cb_DEFAULT_g])
    {
      if (rw_EEPROMLastEntryPointer_mg[cb_CL_IDX_AD_mg] == (cw_FLASHCLUSTERSTART_mg[rb_ClusterIdxMap_mg[cb_CL_IDX_AD_mg]] + 4 )) /* no valid entry in AD segment? */
      {
        /* write address and value of sw version in new cluster */
        if ((EEProm_WriteCodedByte(cb_SWSTANDEEPROM_23_g,cw_ADRPRE_AD_mg + (cb_POSITIONDEFAULTSOFTWARE+1)))>0)
        {
          EEProm_LoadDefault(); /*Problems Writing EEPROM*/
        }
        else
        {
          EEPROM_Struct_AD._c[(cb_POSITIONDEFAULTSOFTWARE+1)] = cb_SWSTANDEEPROM_23_g;
          rb_EEPROM_Status_g = cb_E2STATUS_LIKEAVIRGIN_g;
        }
      }
      else
      {
        EEProm_LoadDefault();
      }
    }
    else if (rbi_NonDefaultValues_mg == TRUE)
    {
      rb_EEPROM_Status_g = cb_E2STATUS_NONDEFAULT_g;
    }
    else if (rbi_DefaultValues_mg == TRUE)
    {
      rb_EEPROM_Status_g = cb_E2STATUS_INITIALIZED_g;
    }
    else
    {
      rb_EEPROM_Status_g = cb_E2STATUS_LIKEAVIRGIN_g;
    }
    
    rbi_EEPROMLoad_g = FALSE;    /* set marker for load complete */
    RLS_PFDL_Close(); /* close once only after loading EEPROM */
  }
  

}

/**************************************************************************
Syntax   :    byte EEProm_Read(word rw_EepromAddress_l,byte *pb_Address_l, byte *pb_Data_l)
Object   :    EEProm_Read()
Parameters :  none
Return  :     none
Calls   :     main_EEPROM_Loader.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************/
/**
* \brief
*  This function read 4 bytes from the EEPROM area and decodes address and data
*
* \pre         PFDL_Open() have to be called before
* \param[in]   rw_EepromAddress_l absolute address to read from
* \param[out]  pb_Address_l pointer to byte where to store the read EEPROM Mirror address
* \param[out]  pb_Data_l pointer to byte where to store the read EEPROM Mirror data
* \return      error flag
*
*/

static byte EEProm_Read(word rw_EepromAddress_l,byte *pb_Address_l, byte *pb_Data_l)
{
  byte rb_Data_l[4];
  byte rb_Error_l;
  byte rb_idx_l;
  RLS_PFDL_Open();
  pfdl_request.command_enu = PFDL_CMD_READ_BYTES;
  pfdl_request.bytecount_u16 = 4;
  pfdl_request.data_pu08 = &rb_PfdlData_mg[0];
  pfdl_request.index_u16 = rw_EepromAddress_l;
  (void)PFDL_Execute(&pfdl_request);
  
  rb_Error_l = 0;
  /* VDR_1032*/
  if ((pfdl_request.data_pu08[0] != 0xFF)&&(pfdl_request.data_pu08[1] != 0xFF)&&
      (pfdl_request.data_pu08[2] != 0xFF)&&(pfdl_request.data_pu08[3] != 0xFF))
  {
    for (rb_idx_l=0;rb_idx_l<4;rb_idx_l++)
    {
      if (cab_CheckBits_mg[pfdl_request.data_pu08[rb_idx_l]&0x0f] ==(pfdl_request.data_pu08[rb_idx_l]))
      {
        rb_Data_l[rb_idx_l] = pfdl_request.data_pu08[rb_idx_l]&0x0f;
      }
      else
      {
        rb_Data_l[rb_idx_l] = EEPROM_Decode(pfdl_request.data_pu08[rb_idx_l]); /* read & decode HN of address */
        rb_Error_l |= rb_EEPROMErrFlag_g;     /* store Error Flag */
      }
    }
    
    *pb_Address_l = ((rb_Data_l[0]<<4)&0xF0) + (rb_Data_l[1]&0x0F);
    *pb_Data_l    = ((rb_Data_l[2]<<4)&0xF0) + (rb_Data_l[3]&0x0F);
  }
  else
  {
    *pb_Address_l = 0xFF;
    *pb_Data_l = 0xFF;
    rb_Error_l = cb_EEPROM_CELLEMPTY_g;
  }
    return(rb_Error_l);
}

/**************************************************************************
Syntax   :    void EEProm_ChangeClusterStart(void)
Object   :    EEProm_ChangeClusterStart()
Parameters :  none
Return  :     none
Calls   :     main_EEPROM_Loader.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************/
/**
* \brief
*  This function have to be called before EEProm_ChangeCluster() to initialise
*  the data
*
* \pre         EEPROM_load() have to be called before
* \param[in]   none
* \return      none
*
*/

void EEProm_ChangeClusterStart(void)
{
  byte rb_Error_l;
  byte rb_Area_l;
  byte rb_ClusterIdx_l;
  
  rb_Area_l = cb_CL_IDX_RD_mg;
  
  if ((rb_ChangeCluster_mg & cb_ChangeCluster_PD_mg) > 0)
  {
    rb_Area_l = cb_CL_IDX_PD_mg;
  }
  else if ((rb_ChangeCluster_mg & cb_ChangeCluster_AD_mg) > 0)
  {
    rb_Area_l = cb_CL_IDX_AD_mg;
  }
  else if ((rb_ChangeCluster_mg & cb_ChangeCluster_RD_mg) > 0)
  {
    rb_Area_l = cb_CL_IDX_RD_mg;
  }
  else
  {
  }
  
  rb_ChangeClusterSrcArea_mg = rb_Area_l;
  
  rbi_ChangingCluster_mg = TRUE;   /* set flag "changing cluster" */
  
  rb_ClusterIdx_l = 0;
  
  while ((rb_ClusterIdx_l < cb_NUM_CLUSTER_mg) && (rb_ClusterStatus_mg[rb_ClusterIdx_l] != cb_CL_EMPTY_mg))
  {
    rb_ClusterIdx_l++;
  }
   
  if (rb_ClusterIdx_l < cb_NUM_CLUSTER_mg)
  {
    rb_ClusterIdxFree_mg = rb_ClusterIdx_l;
    /* Write header to new cluster */
    rb_WriteBuffer_mg[0] = cb_MagicWord_mg[rb_ChangeClusterSrcArea_mg][0];
    rb_WriteBuffer_mg[1] = cb_MagicWord_mg[rb_ChangeClusterSrcArea_mg][1];
    rb_WriteBuffer_mg[2] = cb_MagicWord_mg[rb_ChangeClusterSrcArea_mg][2];
    rb_WriteBuffer_mg[3] = rb_ChangeClusterSrcArea_mg;
    
    rb_Error_l = EEProm_Write4Bytes(cw_FLASHCLUSTERSTART_mg[rb_ClusterIdxFree_mg], rb_WriteBuffer_mg);
    if (rb_Error_l > 0)
    {
      rbi_ClusterFormatError_g = TRUE;
      rbi_ChangingCluster_mg = FALSE;
      /* erase this cluster again */           
      rb_ClusterStatus_mg[rb_ClusterIdxFree_mg] = cb_CL_TOBECLEAR_mg;
      rbi_ClearCluster_mg = TRUE;
      
      
    }
    else
    {
      /* set EEPROM pointer of the area to start of empty segment */
      rw_EEPROMPointer_g[rb_ChangeClusterSrcArea_mg] = cw_FLASHCLUSTERSTART_mg[rb_ClusterIdxFree_mg] + 4;
      /* assign new cluster in look up table */
      rb_ChangeClusterSrcCluster_mg = rb_ClusterIdxMap_mg[rb_ChangeClusterSrcArea_mg];
      rb_ClusterIdxMap_mg[rb_ChangeClusterSrcArea_mg] = rb_ClusterIdxFree_mg;            
      /* set startaddress for copy procedure */
      rw_EEPROMAdr_mg = (((word)(rb_ChangeClusterSrcArea_mg+1))<<8);   /* init eeprom address */
    }
  }
  else
  {
    /* Todo Error no free cluster */
    rbi_ClusterError_g = TRUE;
    rbi_ChangingCluster_mg = FALSE;
  }
}

/**************************************************************************
Syntax   :    void EEProm_ChangeCluster(void)
Object   :    EEProm_ChangeCluster()
Parameters :  none
Return  :     none
Calls   :     main_EEPROM_Loader.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************/
/**
* \brief
*  This copys the data in the new cluster and erases the old cluster
*
* \pre         EEProm_ChangeClusterStart() have to be called before
* \param[in]   none
* \return      none
*
*/

void EEProm_ChangeCluster(void)
{
  /* declaration of local variables */
  byte rb_WriteErrStatus_l;
  byte rb_AreaAddress_l;
  byte rb_AreaIdx_l;
  byte rb_AreaNumCells_l = 0;
  
  rb_WriteErrStatus_l = 0;
  if (rbi_ClearCluster_mg == FALSE)   /* in copy phase? */
  {
    rb_AreaIdx_l = ((rw_EEPROMAdr_mg >> 8) & 0x3) - 1;
    rb_AreaAddress_l = rw_EEPROMAdr_mg & 0x0ff;
    
    if (rb_AreaIdx_l == cb_CL_IDX_PD_mg)  /* EEPROM address in range of production data? */
    {
      /* value is not default? */
      if (EEPROM_Struct_PD._c[rb_AreaAddress_l] != cb_EEPROMDataDefaultMinMax_PD_g[rb_AreaAddress_l][cb_DEFAULT_g])
      {
        /* write address and value in new cluster*/
        rb_WriteErrStatus_l = EEProm_WriteCodedByte(EEPROM_Struct_PD._c[rb_AreaAddress_l],rw_EEPROMAdr_mg);
      }
      
      rb_AreaNumCells_l = cb_NumberofEEPROMCells_PD_g;
    }
    else if (rb_AreaIdx_l == cb_CL_IDX_AD_mg)  /* EEPROM address in range of algorithm data? */
    {/* Address of Software version? (only relative address is checked, area is known and fix) */
      if ((rb_AreaAddress_l) == (cb_POSITIONDEFAULTSOFTWARE+1)) 
      {
        /* write address and value of sw version in new cluster */
        EEPROM_Struct_AD._c[rb_AreaAddress_l] = cb_SWSTANDEEPROM_23_g;
        rb_WriteErrStatus_l = EEProm_WriteCodedByte(cb_SWSTANDEEPROM_23_g,rw_EEPROMAdr_mg);
        
      }
      /* value is not default? */
      else if (EEPROM_Struct_AD._c[rb_AreaAddress_l] != cb_EEPROMDataDefaultMinMax_AD_g[rb_AreaAddress_l][cb_DEFAULT_g])
      {
        /* write address and value in new cluster*/
        rb_WriteErrStatus_l = EEProm_WriteCodedByte(EEPROM_Struct_AD._c[rb_AreaAddress_l],rw_EEPROMAdr_mg);
      }
      else
      {}
      rb_AreaNumCells_l = cb_NumberofEEPROMCells_AD_g;
    }
    else if (rb_AreaIdx_l == cb_CL_IDX_RD_mg)  /* EEPROM address in range of runtime data? */
    {
      /* value is not default? */
      if (EEPROM_Struct_RD._c[rb_AreaAddress_l] != cb_EEPROMDataDefaultMinMax_RD_g[rb_AreaAddress_l][cb_DEFAULT_g])
      {
        /* write address and value in new cluster*/
        rb_WriteErrStatus_l = EEProm_WriteCodedByte(EEPROM_Struct_RD._c[rb_AreaAddress_l],rw_EEPROMAdr_mg);
      }
      rb_AreaNumCells_l = cb_NumberofEEPROMCells_RD_g;
    }
    else
    {}
    
    rw_EEPROMAdr_mg++;    /* increase Address */
    if ((rw_EEPROMAdr_mg&0x0FF) >= rb_AreaNumCells_l)
    {
      rb_WriteBuffer_mg[0] = 0xAA;
      rb_WriteBuffer_mg[1] = 0xBB;
      rb_WriteBuffer_mg[2] = 0xCC;
      rb_WriteBuffer_mg[3] = 0xDD;      
      
      rb_WriteErrStatus_l = EEProm_Write4Bytes(cw_FLASHCLUSTEREND_mg[rb_ChangeClusterSrcCluster_mg]-3,rb_WriteBuffer_mg);     /* write marker at end of cluster */
      rbi_ChangingCluster_mg = FALSE;  /* clear flag "changing cluster" */
      
      rb_ChangeCluster_mg &= (byte)(~((byte)(0x01 << rb_ChangeClusterSrcArea_mg)));    /* clear request for "changing cluster" */
      
      
      /* set status of old cluster to "to be cleared" */
      rb_ClusterStatus_mg[rb_ChangeClusterSrcCluster_mg] = cb_CL_TOBECLEAR_mg;
      rbi_ClearCluster_mg = TRUE;      /* set flag "delete old cluster" */
      /* set staus of new cluster to area code */
      rb_ClusterStatus_mg[rb_ClusterIdxFree_mg] = rb_ChangeClusterSrcArea_mg;
      
      if (rb_EEPROM_Status_g == cb_E2STATUS_INITIALIZATION_g)
      {
        rb_EEPROM_Status_g = cb_E2STATUS_INITIALIZED_g;
      }
      
    }
    
  }
  
  if (rb_WriteErrStatus_l != 0)  /* Error during writing occured? */
  {
    rbi_WriteError_g = 1;    /* set write error flag */
  }
  
  
}

void EEProm_ClearCluster(void)
{
  /** \brief cluster idx cluster to clear, only valid while clearing cluster*/
  static byte rb_ClearClusterIdx_mg;
  /* declaration of local variables */
  byte rb_Block_l;
  byte rb_FlashStatus_l;
  byte rb_ClusterIdx_l;
  
  if(rb_EEPROM_EraseOngoing_g == FALSE) /* VDR_797 */
  {
    RLS_PFDL_Open();
    rb_EraseStatus_g = PFDL_Handler();
    if(rb_EraseStatus_g == PFDL_IDLE)  
    {
      rb_ClusterIdx_l = 0;
      while ((rb_ClusterIdx_l < cb_NUM_CLUSTER_mg) && (rb_ClusterStatus_mg[rb_ClusterIdx_l] != cb_CL_TOBECLEAR_mg))
      {
        rb_ClusterIdx_l++;
      }
      
      if (rb_ClusterIdx_l < cb_NUM_CLUSTER_mg)
      {
        rb_ClearClusterIdx_mg = rb_ClusterIdx_l;
        rb_Block_l = cw_FLASHCLUSTERSTART_mg[rb_ClearClusterIdx_mg]/0x400; /* calculate block number */
        pfdl_request.index_u16 = rb_Block_l;
        pfdl_request.command_enu = PFDL_CMD_ERASE_BLOCK;
        rb_EEPROM_EraseOngoing_g = TRUE;
        rb_FlashStatus_l = PFDL_Execute(&pfdl_request);    /* erase block */
        rb_FlashStatus_l = PFDL_Handler();
      }
      else
      {
        rbi_ClearCluster_mg = FALSE;  /* clear request for "clearing cluster" */
      }
    }
    
  }
  else
  {
    rb_FlashStatus_l = PFDL_Handler();
    if(rb_FlashStatus_l == PFDL_BUSY)
    {
      /*do nothing. come again in next 10ms to check the status*/
    }
    else
    {
      rb_EraseStatus_g = rb_FlashStatus_l;
      if (rb_EraseStatus_g == PFDL_OK)    /* erase successful? */
      {
        rb_ClusterStatus_mg[rb_ClearClusterIdx_mg] = cb_CL_EMPTY_mg;
        rbi_ClearCluster_mg = FALSE;  /* clear request for "clearing cluster" */
        rb_ClEraseRetry_mg = 0;
        
        /* Increase Area erase counter */
        if (rab_Erase_counter_g(rb_ClearClusterIdx_mg) < 255) /* VDR_131 is EEPROM erase counter < 255*/
        {
          rb_I2C_EEPROM_bytesToWrite_g = 1;
          rw_EEPROM_Address_to_Write_g = CW_E2_ERASECOUNTER_ADRESS + rb_ClearClusterIdx_mg;
          rab_EEPROM_Bytes_toWrite_g[0] = rab_Erase_counter_g(rb_ClearClusterIdx_mg) + 1;     // set data to write
          rbi_EEPROMBytesWritten_g = FALSE; /* VDR 262 AL  Reset Status bit*/
          rbi_EEPROMBytesToWrite_g = TRUE;          //set flag for bytes to write              
        }          
        
        
      }
      else      /* return value other than command interrupted? */
      {
        if (rb_ClEraseRetry_mg > cb_MAXERASERETRYS_mg)
        {
          rbi_EraseError_g = 1;   /* set erase error flag */
          rb_ClusterStatus_mg[rb_ClearClusterIdx_mg] = cb_CL_EMPTY_mg;
          rbi_ClearCluster_mg = FALSE;  /* clear request for "clearing cluster" */
          rb_ClEraseRetry_mg = 0;
        }
        else
        {
          rb_ClEraseRetry_mg ++;
        }
      }
      rb_EEPROM_EraseOngoing_g = FALSE;
      RLS_PFDL_Close();               /* close SelfLib */
      
    }
  }
  
  /* check if there are other clusters to be cleared */
  rb_ClusterIdx_l = 0;
  while ((rbi_ClearCluster_mg == FALSE) && (rb_ClusterIdx_l < cb_NUM_CLUSTER_mg))
  {
    if (rb_ClusterStatus_mg[rb_ClusterIdx_l] == cb_CL_TOBECLEAR_mg)
    {
      rbi_ClearCluster_mg = TRUE;  /* other cluster to be cleared found */
    }
    else
    {
      rb_ClusterIdx_l++;
    }
  }
  
}

/**************************************************************************
Syntax   :    byte EEProm_Write4Bytes(word rw_EEPROMAddress_l, byte *pb_ByteToWrite_l)
Object   :    byte EEProm_Write4Bytes(word rw_EEPROMAddress_l, byte *pb_ByteToWrite_l)
Parameters :  ByteToWrite ,AddressToWrite
Return  :     Errorcode from SelfLib_EepWrite() ( 0 = success, 1= error)
Calls   :     main_EEPROM_Loader.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************/
/**
* \brief
*  This function codes a byte and the adress by hamming and wirtes thy byte
*  by usage od the selflib into the emulated eeprom (duration about 2ms)
*
* \pre         pfdl_descriptor filled with data
* \param[in]   rw_EEPROMAddress_l ,pb_ByteToWrite_l Address and Data
* \return      Errorcode from PFDL_Handler() ( 0 = success, 1= error)
*
*/
static byte EEProm_Write4Bytes(word rw_EEPROMAddress_l, byte *pb_ByteToWrite_l)
{
  /* declaration of local variables */
  byte rb_Data_l;
  if(rb_EEPROM_EraseOngoing_g == FALSE)/* VDR_797 */
  {
    RLS_PFDL_Open();
    
    pfdl_request.command_enu = PFDL_CMD_WRITE_BYTES;
    pfdl_request.bytecount_u16 = 4;
    pfdl_request.data_pu08 = &pb_ByteToWrite_l[0];
    pfdl_request.index_u16 = rw_EEPROMAddress_l ;
    rb_Data_l = PFDL_Execute(&pfdl_request);
    if( rb_Data_l == PFDL_BUSY )
    {
      do
      {
        rb_Data_l = PFDL_Handler();
      }while((rb_Data_l == PFDL_BUSY));
    }
    
    pfdl_request.command_enu = PFDL_CMD_READ_BYTES;
    pfdl_request.bytecount_u16 = 4;
    pfdl_request.data_pu08 = &rb_PfdlData_mg[0];
    pfdl_request.index_u16 = rw_EEPROMAddress_l;
    (void)PFDL_Execute(&pfdl_request);
    
    if ((pfdl_request.data_pu08[0] !=  pb_ByteToWrite_l[0])
        ||(pfdl_request.data_pu08[1] !=   pb_ByteToWrite_l[1])
          ||(pfdl_request.data_pu08[2] !=   pb_ByteToWrite_l[2])
            ||(pfdl_request.data_pu08[3] !=   pb_ByteToWrite_l[3]))
    {
      rb_Data_l |= 0x80;
    }
    
    
    RLS_PFDL_Close();  /* close SelfLib */
  }
  else
  {
    rb_Data_l = 1; /* set error*/
  }
  
  return(rb_Data_l);   /* return error code */
  
}

/**************************************************************************
Syntax   :    byte EEProm_WriteCodedByte(byte ByteToWrite, byte AddressToWrite)
Object   :    byte EEProm_WriteCodedByte(byte ByteToWrite, byte AddressToWrite)
Parameters :  ByteToWrite ,AddressToWrite
Return  :     Errorcode from SelfLib_EepWrite() ( 0 = success, 1= error)
Calls   :     main_EEPROM_Loader.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************/
/**
* \brief
*  This function codes a byte and the adress by hamming and wirtes thy byte
*  by usage od the selflib into the emulated eeprom (duration about 2ms)
*
* \pre         EEProm_Load have to be called before
* \param[in]   Data ,Address (2 words (hamming coded) are written)
* \return      Errorcode from SelfLib_EepWrite() ( 0 = success, 1= error)
*
*/
byte EEProm_WriteCodedByte(byte ByteToWrite, word AddressToWrite)
{
  /* declaration of local variables */
  byte rb_Data_l;
  byte rb_Area_l;
  byte rb_Cluster_l;
  
  
  if(rb_EEPROM_EraseOngoing_g == FALSE)/* VDR_797 */
  {
    RLS_PFDL_Open();
    
    if ((AddressToWrite < cw_ADREEPROM_START_g) || (AddressToWrite > cw_ADREEPROM_END_g))
    {
      rb_Data_l = 2; /* set error*/  
    }
    else
    {
      
      rb_Area_l = ((AddressToWrite>>8) & 0x03)-1;
      rb_Cluster_l = rb_ClusterIdxMap_mg[rb_Area_l];
      
      /* hamming coded address */
      rb_Data_l = (AddressToWrite>>4) & 0x0F;
      rb_WriteBuffer_mg[0] = cab_CheckBits_mg[rb_Data_l];
      rb_Data_l = AddressToWrite & 0x0F;
      rb_WriteBuffer_mg[1] = cab_CheckBits_mg[rb_Data_l];
      /* and hamming coded data */
      rb_Data_l = (ByteToWrite>>4) & 0x0F;
      rb_WriteBuffer_mg[2] = cab_CheckBits_mg[rb_Data_l];
      rb_Data_l = ByteToWrite & 0x0F;
      rb_WriteBuffer_mg[3] = cab_CheckBits_mg[rb_Data_l];
      
      pfdl_request.command_enu = PFDL_CMD_WRITE_BYTES;
      pfdl_request.bytecount_u16 = 4;
      pfdl_request.data_pu08 = &rb_WriteBuffer_mg[0];
      pfdl_request.index_u16 = rw_EEPROMPointer_g[rb_Area_l];
      rb_Data_l = PFDL_Execute(&pfdl_request);
      if( rb_Data_l == PFDL_BUSY )
      {
        do
        {
          rb_Data_l = PFDL_Handler();
        }while((rb_Data_l == PFDL_BUSY));
      }
      
      pfdl_request.command_enu = PFDL_CMD_READ_BYTES;
      pfdl_request.bytecount_u16 = 4;
      pfdl_request.data_pu08 = &rb_PfdlData_mg[0];
      pfdl_request.index_u16 = rw_EEPROMPointer_g[rb_Area_l];
      (void)PFDL_Execute(&pfdl_request);
      
      if ((pfdl_request.data_pu08[0] !=  rb_WriteBuffer_mg[0])
          ||(pfdl_request.data_pu08[1] !=   rb_WriteBuffer_mg[1])
            ||(pfdl_request.data_pu08[2] !=   rb_WriteBuffer_mg[2])
              ||(pfdl_request.data_pu08[3] !=   rb_WriteBuffer_mg[3]))
      {
        rb_Data_l |= 0x80;
      }
      
      
      RLS_PFDL_Close();  /* close SelfLib */
      
      if ((AddressToWrite & cw_ADRSELMASK_mg)  != cw_ADRPRE_PD_mg)
      {
        if (AddressToWrite != ((cw_ADRPRE_AD_mg + cb_POSITIONDEFAULTSOFTWARE) - 1))
        {
          rb_EEPROM_Status_g = cb_E2STATUS_NONDEFAULT_g;
        }
        
      }
      else if (rb_EEPROM_Status_g == cb_E2STATUS_LIKEAVIRGIN_g)
      {
        rb_EEPROM_Status_g = cb_E2STATUS_INITIALIZED_g;
      }
      else
      {}
      
      rw_EEPROMPointer_g[rb_Area_l] += 4;   /* increase addresspointer */
      /* end of cluster reached? */
      if(rw_EEPROMPointer_g[rb_Area_l] > (cw_FLASHCLUSTEREND_mg[rb_Cluster_l]-cb_SPAREBEFORCHANGE_mg))
      {
        rb_ChangeCluster_mg = (0x01 << rb_Area_l);
      }
    }
  }
  else
  {
    rb_Data_l = 1; /* set error*/
  }
  
  return(rb_Data_l);   /* return error code */
  
}

/* ------------------------------------------------------------------------------------------------- */
/* Error Correction Algorithm */
/* ------------------------------------------------------------------------------------------------- */

/**************************************************************************
Syntax   :    EEPROM_OddParity(byte rb_Code_l)
Object   :    EEPROM_OddParity(byte rb_Code_l)
Parameters :  Data to analyse
Return  :     Returns TRUE if Code is odd parity, otherwise returns FALSE
Calls   :     main_EEPROM_Loader.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************/
/**
* \brief
*  This function checks if the parity of the data is odd
*
* \pre         none
* \param[in]   Data to analyse
* \return      Returns TRUE if Code is odd parity, otherwise returns FALSE
*
*/
static byte EEPROM_OddParity(byte rb_Code_l)
{
  byte rb_Result_l;
  
  rb_Result_l=TRUE;
  while (rb_Code_l!=0)
  {
    if ((rb_Code_l & 1)>0)
    {
      rb_Result_l=!rb_Result_l;
    }
    
    rb_Code_l>>=1;
  }
  return(rb_Result_l);
}


/**************************************************************************
Syntax   :    EEPROM_Decode(byte rb_Code_l)
Object   :    EEPROM_Decode(byte rb_Code_l)
Parameters :  coded Data
Return  :     decoded data
Calls   :     main_EEPROM_Loader.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************/
/**
* \brief
*  Returns the error corrected data word, decoded from <Code>.
*  Uses global variable <DataSize> to determine position of the
*  check bits in <Code>.
*  Updates global variable <ErrFlag> to indicate error status
*  i.e.:
*  ErrFlag Status
*  0 No errors found
*  1 Single error corrected
*  2 Double error - invalid correction
*
* \pre         none
* \param[in]   Data to analyse
* \return      Returns TRUE if Code is odd parity, otherwise returns FALSE
*
*/
static byte EEPROM_Decode(byte rb_Code_l)
{
  byte rb_ParityBit_l,rb_Data_l,rb_Check_l,rb_ErrorCheck_l,rb_Syndrome_l;
  byte rb_DataPos_l,rb_CheckPos_l,H,rb_DataBit_l;
  
  rb_EEPROMErrFlag_g=0;
  
  rb_ParityBit_l = rb_Code_l & 0x80;  /* Extract parity bit */
  rb_Data_l = rb_Code_l & 0x0F; /* Extract data bits. */
  rb_Check_l = (rb_Code_l >> cb_DATASIZE_mg) & 0x07;  /* extract check bits ignoring parity. */
  
  rb_ErrorCheck_l = (cab_CheckBits_mg[rb_Data_l] >> cb_DATASIZE_mg) & 0x07;
  rb_Syndrome_l = rb_Check_l ^ rb_ErrorCheck_l; /* Get bit position of error. */
  
  if (rb_Syndrome_l>0)
  {
    rb_EEPROMErrFlag_g++; /* Increment flag if error exists */
    
    H = 0;
    rb_DataPos_l = 0;
    rb_CheckPos_l = cb_DATASIZE_mg;
    rb_DataBit_l = TRUE;
    
    while ((H != rb_Syndrome_l) && (rb_DataPos_l<cb_DATASIZE_mg)) /* Identify which data or */
    {
      H++; /* code bit is in error. */
      
      if ((H==1) || (H==2) || (H==4) || (H==8))
      {
        rb_CheckPos_l++;
        rb_DataBit_l = FALSE;
      }
      else
      {
        rb_DataPos_l++;
        rb_DataBit_l = TRUE;
      }
    }
    
    if (rb_DataBit_l > 0)
    {
      rb_Code_l ^= (byte)(0x01 << (rb_DataPos_l-1));
    }
    else
    {
      rb_Code_l ^= (byte)(0x01 << (rb_CheckPos_l-1));
    }
    rb_Code_l |= rb_ParityBit_l;
  }
  
  
  if ((EEPROM_OddParity(rb_Code_l)) > 0 )
  {
    rb_EEPROMErrFlag_g++;
  }
  
  return((rb_Code_l & 0x0F));
}

/**************************************************************************
Syntax   : void Enter_BootLoad_Mode(void)
Object   : Enter_BootLoad_Mode()
Parameters : none
Return  : none
Calls   : G5_APPli_main.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code :
*************************************************************************/
void Enter_BootLoad_Mode(void)
{
  byte rb_LoopCnt_l;
  
  rb_ValidateString_mg[0]= 0xA0;  /* write some byte to  read in boot loader */
  rb_ValidateString_mg[1]= 0x01;
  rb_ValidateString_mg[2]= 0x55;
  rb_ValidateString_mg[3]= 'V';
  rb_ValidateString_mg[4]= 'a'; 
  rb_ValidateString_mg[5]= 'L';
  rb_ValidateString_mg[6]= 'e';
  rb_ValidateString_mg[7]= 'O';
    
        while(TRUE)  /* do the force reset */
        {
          REFRESH_EXTERNAL_WATCHDOG();
          for(rb_LoopCnt_l = 0;rb_LoopCnt_l <10;rb_LoopCnt_l++)
          {
            NOP();
          }
          SETLOW_EXTERNAL_WATCHDOG();
        }

  }

/**************************************************************************
Syntax   : void ClearValidateString(void)
Object   : ClearValidateString()
Parameters : none
Return  : none
Calls   : G5_APPli_main.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code :
*************************************************************************/
void ClearValidateString(void)
{
  byte rb_LoopCnt_l;
  for(rb_LoopCnt_l = 0;rb_LoopCnt_l<8;rb_LoopCnt_l++)
  {
  rb_ValidateString_mg[rb_LoopCnt_l]= 0x00;  
 
  }
}

/**************************************************************************
Syntax   :    void RLS_PFDL_Open(void)
Object   :    RLS_PFDL_Open()
Parameters :  none
Return  :     none
Calls   :     G5_FlashE2.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************/
/**
* \brief
* To check the status of RLS_PFDL_Open 
* \pre         none
* \param[in]   none
* \return      none
*
*/

void RLS_PFDL_Open(void)
{
  if(rb_PFDL_Open_mg == FALSE)
  {
    (void)PFDL_Open(&pfdl_descriptor);
    rb_PFDL_Open_mg = TRUE;
  }
  
}
/**************************************************************************
Syntax   :    void RLS_PFDL_Close(void)
Object   :    RLS_PFDL_Close()
Parameters :  none
Return  :     none
Calls   :     G5_FlashE2.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************/
/**
* \brief
* To check the status of RLS_PFDL_Open and then to close 
*
* \pre         none
* \param[in]   none
* \return      none
*
*/

void RLS_PFDL_Close(void)
{
  if(rb_PFDL_Open_mg == TRUE)
  {
    (void)  PFDL_Close();
    rb_PFDL_Open_mg = FALSE;
  }
  
}