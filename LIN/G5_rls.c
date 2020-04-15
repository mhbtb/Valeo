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
 * Template for LIN configuration and message definitions 
 * used with RLT-DIagnose.exe
 *
 * 
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> G5_rls.c                  </td></tr>
 * <tr> <td> Revision: </td> <td> 1.4                  </td></tr>
 * <tr> <td> Status:   </td> <td> ACCEPTED                  </td></tr>
 * <tr> <td> Author:   </td> <td> Jochen Schenk, VDS-E-PUS  </td></tr>
 * <tr> <td> Date:     </td> <td> 30-SEP-2013 14:04:58                 </td></tr>
 * </table>
 * 
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> RLS_LIN </td></tr>
 * <tr> <td> TARGET:    </td> <td> NEC     </td></tr>
 * </table>
 */
/* Date      VDR_Number Initials    Description                                       */
/*13.07.2015 VDR_868    NB     QAC and Polyspace fixing for SW009 Release  */

/******************************************************************************/
/*                      Include headers of the component                      */
/******************************************************************************/

/* PRQA S 0781,759,436,434 EOF */ /* << 0781,436 03 03, unions needed >> */
/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/

#include "ior5f109be.h"
#include "G5_lininclude.h"


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
MEMORY_FAR _c_SoSes_01_buf SoSes_01;
MEMORY_FAR _c_RLSs_01_buf RLSs_01;
MEMORY_FAR _c_FSs_01_buf FSs_01;

/******************************************************************************/
/*                        Databuffer for receive objects                      */
/******************************************************************************/

MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
MEMORY_FAR _c_WWSs_01_buf WWSs_01;
MEMORY_FAR _c_BCM1_LIN1_01_buf BCM1_LIN1_01;

/******************************************************************************/
/*                               Send structures                              */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinTxDataLenTbl[kLinNumberOfTxObjects] = {
     8      /* 0x3D"LinRespCmd" */
    ,8      /* 0x13"ASIC_Frame_04" */
    ,8      /* 0x12"ASIC_Frame_03" */
    ,8      /* 0x11"ASIC_Frame_02" */
    ,8      /* 0x10"ASIC_Frame_01" */
    ,8      /* 0x30"SoSes_01" */
    ,8      /* 0x23"RLSs_01" */
    ,8      /* 0x29"FSs_01" */
};

canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects] = {
     (canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x13"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x12"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x11"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x10"ASIC_Frame_01" */
    ,(canuint8*)SoSes_01._c      /* 0x30"SoSes_01" */
    ,(canuint8*)RLSs_01._c      /* 0x23"RLSs_01" */
    ,(canuint8*)FSs_01._c      /* 0x29"FSs_01" */
};


/******************************************************************************/
/*                      Databuffer for confirmationflags                      */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinConfirmationOffset[kLinNumberOfTxObjects] = {
  0,    0,    0,    0,    0,    0,    0,    0
    ,
};

canuint8 MEMORY_ROM cabLinConfirmationMask[kLinNumberOfTxObjects] = {
  0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
    ,
};


/******************************************************************************/
/*                             Receive structures                             */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinRxDataLenTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,6      /* 0x32"WWSs_01" */
    ,8      /* 0x31"BCM1_LIN1_01" */
};

canuint8 MEMORY_ROM cabLinRxDLCTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,6      /* 0x32"WWSs_01" */
    ,8      /* 0x31"BCM1_LIN1_01" */
};

canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects] = {
     (canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)WWSs_01._c      /* 0x32"WWSs_01" */
    ,(canuint8*)BCM1_LIN1_01._c      /* 0x31"BCM1_LIN1_01" */
};


/******************************************************************************/
/*                        Databuffer for indicationflags                      */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinIndicationOffset[kLinNumberOfRxObjects] = {
  0,    0,    0
};

canuint8 MEMORY_ROM cabLinIndicationMask[kLinNumberOfRxObjects] = {
  0x01, 0x02, 0x04
};


/******************************************************************************/
/*                  Databuffer with message default values                    */
/******************************************************************************/

/* Default values for messages */
#if defined(L_ENABLE_INIT_DEFAULT_DATA)

canuint8 MEMORY_ROM LinMsgDefault_LinRespCmd[8] = {0,0,0,0,0,0,0,0};    /* 0x3D"LinRespCmd" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_04[8] = {0,0,0,0,0,0,0,0};    /* 0x13"ASIC_Frame_04" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_03[8] = {0,0,0,0,0,0,0,0};    /* 0x12"ASIC_Frame_03" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_02[8] = {0,0,0,0,0,0,0,0};    /* 0x11"ASIC_Frame_02" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_01[8] = {0,0,0,0,0,0,0,0};    /* 0x10"ASIC_Frame_01" */
canuint8 MEMORY_ROM LinMsgDefault_SoSes_01[8] = {254,254,0,0,0,0,0,0};    /* 0x30"SoSes_01" */
canuint8 MEMORY_ROM LinMsgDefault_RLSs_01[8] = {0,16,0,254,254,227,0,254};    /* 0x23"RLSs_01" */
canuint8 MEMORY_ROM LinMsgDefault_FSs_01[8] = {0,0,0,0,0,0,0,0};    /* 0x29"FSs_01" */

canuint8 MEMORY_ROM LinMsgDefault_LinReqCmd[8] = {0,0,0,0,0,0,0,0};    /* 0x3C"LinReqCmd" */
canuint8 MEMORY_ROM LinMsgDefault_WWSs_01[6] = {0,0,0,0,62,254};    /* 0x32"WWSs_01" */
canuint8 MEMORY_ROM LinMsgDefault_BCM1_LIN1_01[8] = {0,0,96,0,254,254,51,252};    /* 0x31"BCM1_LIN1_01" */

canuint8* MEMORY_ROM capbLinTxDefaultDataPtrTbl[kLinNumberOfTxObjects] = {
    ,(canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x13"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x12"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x11"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x10"ASIC_Frame_01" */
    ,(canuint8*)SoSes_01._c      /* 0x30"SoSes_01" */
    ,(canuint8*)RLSs_01._c      /* 0x23"RLSs_01" */
     (canuint8*)FSs_01._c      /* 0x29"FSs_01" */
};

canuint8* MEMORY_ROM capbLinRxDefaultDataPtrTbl[kLinNumberOfRxObjects] = {
    ,(canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)WWSs_01._c      /* 0x32"WWSs_01" */
     (canuint8*)BCM1_LIN1_01._c      /* 0x31"BCM1_LIN1_01" */
};


#endif /*L_ENABLE_INIT_DEFAULT_DATA */


/******************************************************************************/
/*                    Databuffer for IDs to handle table                      */
/******************************************************************************/

#ifdef NODECONFIGURATION

//#pragma dataseg="IXRAM"              
 canuint8 rabRAMLinMsgIDToHandleTbl[0x40];
#pragma dataseg=default

canuint16 MEMORY_ROM cawLINMessageID[kLinNumberOfObjects] = {
    0           /* 0x3D"LinRespCmd" */
   ,0x1013      /* 0x13"ASIC_Frame_04" */
   ,0x1012      /* 0x12"ASIC_Frame_03" */
   ,0x1011      /* 0x11"ASIC_Frame_02" */
   ,0x1010      /* 0x10"ASIC_Frame_01" */
   ,0x4030      /* 0x30"SoSes_01" */
   ,0x1023      /* 0x23"RLSs_01" */
   ,0x2029      /* 0x29"FSs_01" */
   ,0          /* 0x3C"LinReqCmd" */
   ,0x1032     /* 0x32"WWSs_01" */
   ,0x1031     /* 0x31"BCM1_LIN1_01" */
};


#else

canuint8 MEMORY_ROM cabLinMsgIDToHandleTbl[0x40] = {
     0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x04      /* 0x10"ASIC_Frame_01" */
    ,0x03      /* 0x11"ASIC_Frame_02" */
    ,0x02      /* 0x12"ASIC_Frame_03" */
    ,0x01      /* 0x13"ASIC_Frame_04" */
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x06      /* 0x23"RLSs_01" */
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x07      /* 0x29"FSs_01" */
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x05      /* 0x30"SoSes_01" */
    ,0x0A      /* 0x31"BCM1_LIN1_01" */
    ,0x09      /* 0x32"WWSs_01" */
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x08      /* 0x3C"LinReqCmd" */
    ,0x00      /* 0x3D"LinRespCmd" */
    ,0xff
    ,0xff
};


#endif

/******************************************************************************/
/*                      List of handles for all messages                      */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinMsgHandleTbl[kLinNumberOfObjects] = {
    0      /* 0x3D"LinRespCmd" */
   ,1      /* 0x13"ASIC_Frame_04" */
   ,2      /* 0x12"ASIC_Frame_03" */
   ,3      /* 0x11"ASIC_Frame_02" */
   ,4      /* 0x10"ASIC_Frame_01" */
   ,5      /* 0x30"SoSes_01" */
   ,6      /* 0x23"RLSs_01" */
   ,7      /* 0x29"FSs_01" */
   ,0      /* 0x3C"LinReqCmd" */
   ,1      /* 0x32"WWSs_01" */
   ,2      /* 0x31"BCM1_LIN1_01" */
};



/******************************************************************************/
/*                       Buffer with message timeout values                   */
/******************************************************************************/

#ifdef L_ENABLE_T_FRAME_MAX

canuint8 MEMORY_ROM cabLinMsgTimeoutTbl[kLinNumberOfObjects] = {
    (kLinTFrame8 - kLinTHeaderMax)      /* 0x3D"LinRespCmd" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x13"ASIC_Frame_04" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x12"ASIC_Frame_03" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x11"ASIC_Frame_02" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x10"ASIC_Frame_01" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x30"SoSes_01" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x23"RLSs_01" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x29"FSs_01" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x3C"LinReqCmd" */
   ,(kLinTFrame6 - kLinTHeaderMax)      /* 0x32"WWSs_01" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x31"BCM1_LIN1_01" */
};


#endif

