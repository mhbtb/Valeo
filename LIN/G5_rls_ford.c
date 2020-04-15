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
MEMORY_FAR _c_RSM_L8_FrP02_buf RSM_L8_FrP02;
MEMORY_FAR _c_RSM_L8_FrP01_buf RSM_L8_FrP01;
MEMORY_FAR _c_RSM_L8_FrP00_buf RSM_L8_FrP00;

MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;

/*************************************************************/
/* Databuffer for receive objects                            */
/*************************************************************/
MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
MEMORY_FAR _c_BCM_L8_FrP01_buf BCM_L8_FrP01;
MEMORY_FAR _c_BCM_L8_FrP03_buf BCM_L8_FrP03;
MEMORY_FAR _c_WMM_L8_FrP00_buf WMM_L8_FrP00;


/*************************************************************/
/* Send structures                                           */
/*************************************************************/
canuint8 MEMORY_ROM cabLinTxDataLenTbl[kLinNumberOfTxObjects] = {
  8    /* id: 0x03D "LinRespCmd" */
 ,8    /* id: 0x035 "RSM_L8_FrP02" */
 ,8    /* id: 0x031 "RSM_L8_FrP01" */
 ,2    /* id: 0x005 "RSM_L8_FrP00" */
 ,8      /* 0x13"ASIC_Frame_04" */
 ,8      /* 0x12"ASIC_Frame_03" */
 ,8      /* 0x11"ASIC_Frame_02" */
 ,8      /* 0x10"ASIC_Frame_01" */
};

canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects] = {
   (canuint8*)LinRespCmd._c    /* id: 0x03D "LinRespCmd" */
  ,(canuint8*)RSM_L8_FrP02._c    /* id: 0x035 "RSM_L8_FrP02" */
  ,(canuint8*)RSM_L8_FrP01._c    /* id: 0x031 "RSM_L8_FrP01" */
  ,(canuint8*)RSM_L8_FrP00._c    /* id: 0x005 "RSM_L8_FrP00" */
  ,(canuint8*)ASIC_Frame_04._c      /* 0x13"ASIC_Frame_04" */
  ,(canuint8*)ASIC_Frame_03._c      /* 0x12"ASIC_Frame_03" */
  ,(canuint8*)ASIC_Frame_02._c      /* 0x11"ASIC_Frame_02" */
  ,(canuint8*)ASIC_Frame_01._c      /* 0x10"ASIC_Frame_01" */    
};




/*************************************************************/
/* Databuffer for confirmationflags                          */
/*************************************************************/

canuint8 MEMORY_ROM cabLinConfirmationOffset[kLinNumberOfTxObjects] = {
     0  ,  0  ,  0  ,  0  ,  0  ,  0  ,  0  ,  0
};

canuint8 MEMORY_ROM cabLinConfirmationMask[kLinNumberOfTxObjects] = {
   0x01  ,0x02  ,0x04  ,0x08, 0x10, 0x20, 0x40, 0x80
};


/*************************************************************/
/* Receive structures                                        */
/*************************************************************/

canuint8 MEMORY_ROM cabLinRxDataLenTbl[kLinNumberOfRxObjects] = {
   8    /* id: 0x03C "LinReqCmd" */
  ,4    /* id: 0x020 "BCM_L8_FrP01" */
  ,2    /* id: 0x006 "BCM_L8_FrP03" */
  ,2    /* id: 0x002 "WMM_L8_FrP00" */
};

canuint8 MEMORY_ROM cabLinRxDLCTbl[kLinNumberOfRxObjects] = {
   8    /* id: 0x03C "LinReqCmd" */
  ,4    /* id: 0x020 "BCM_L8_FrP01" */
  ,2    /* id: 0x006 "BCM_L8_FrP03" */
  ,2    /* id: 0x002 "WMM_L8_FrP00" */
};


canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects] = {
   (canuint8*)LinReqCmd._c    /* id: 0x03C "LinReqCmd" */
  ,(canuint8*)BCM_L8_FrP01._c    /* id: 0x020 "BCM_L8_FrP01" */
  ,(canuint8*)BCM_L8_FrP03._c    /* id: 0x006 "BCM_L8_FrP03" */
  ,(canuint8*)WMM_L8_FrP00._c    /* id: 0x002 "WMM_L8_FrP00" */
};







/*************************************************************/
/* Databuffer for indicationflags                                */
/*************************************************************/
canuint8 MEMORY_ROM cabLinIndicationOffset[kLinNumberOfRxObjects] = {
     0  ,  0  ,  0  , 0
};

canuint8 MEMORY_ROM cabLinIndicationMask[kLinNumberOfRxObjects] = {
   0x01  ,0x02  ,0x04 ,0x08
};

/* Default values for messages */
#if defined(L_ENABLE_INIT_DEFAULT_DATA) || defined(L_ENABLE_START_DEFAULT_DATA) || defined(L_ENABLE_STOP_DEFAULT_DATA)
canuint8 MEMORY_ROM LinMsgDefault_LinReqCmd[8] = {0,0,0,0,0,0,0,0};     /* id: 0x03C "LinReqCmd" */
canuint8 MEMORY_ROM LinMsgDefault_BCM_L8_FrP01[4] = {0,0,0,0};     /* id: 0x020 "BCM_L8_FrP01" */
canuint8 MEMORY_ROM LinMsgDefault_BCM_L8_FrP03[2] = {0,0};     /* id: 0x006 "BCM_L8_FrP03" */

canuint8 MEMORY_ROM LinMsgDefault_LinRespCmd[8] = {0,0,0,0,0,0,0,0};     /* id: 0x03D "LinRespCmd" */
canuint8 MEMORY_ROM LinMsgDefault_RSM_L8_FrP02[8] = {0,0,0,0,0,0,0,0};     /* id: 0x035 "RSM_L8_FrP02" */
canuint8 MEMORY_ROM LinMsgDefault_RSM_L8_FrP01[8] = {0,0,0,0,0,0,0,0};     /* id: 0x031 "RSM_L8_FrP01" */
canuint8 MEMORY_ROM LinMsgDefault_RSM_L8_FrP00[2] = {0,0};     /* id: 0x005 "RSM_L8_FrP00" */

#endif

#ifdef NODECONFIGURATION
            
 canuint8 rabRAMLinMsgIDToHandleTbl[0x40];


canuint16 MEMORY_ROM cawLINMessageID[kLinNumberOfObjects] = {
    0           /* 0x3D"LinRespCmd" */
   ,0x1035      /* RSM_L8_FrP02" */
   ,0x1031      /* id: 0x031 "RSM_L8_FrP01" */
   ,0x1005      /* id: 0x005 "RSM_L8_FrP00" */
   ,0x1013      /* 0x13"ASIC_Frame_04" */
   ,0x1012      /* 0x12"ASIC_Frame_03" */
   ,0x1011      /* 0x11"ASIC_Frame_02" */
   ,0x1010      /* 0x10"ASIC_Frame_01" */
   ,0          /* 0x3C"LinReqCmd" */
   ,0x1020     /* id: 0x020 "BCM_L8_FrP01" */
   ,0x1006     /* "BCM_L8_FrP03"" */
   ,0x1002     /* "L8_FrP00"" */
};


#else
canuint8 MEMORY_ROM cabLinMsgIDToHandleTbl[0x40] = {
   0xff
  ,0xff
  ,0x7    /* id: 0x002 "WMM_L8_FrP00" */
  ,0xff
  ,0xff
  ,0x3    /* id: 0x005 "RSM_L8_FrP00" */
  ,0x6    /* id: 0x006 "BCM_L8_FrP03" */
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0x8    /* id: 0x0D "BMS_L8_FrP00" */
  ,0x9    /* id: 0x0E "BMS_L8_FrP01" */
  ,0xa    /* id: 0x0F "BMS_L8_FrP02" */
  ,0xb    /* id: 0x10 "BCM_L8_FrP02" */
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xc    /* id: 0x17 "BMS_L8_FrP03" */
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0x5    /* id: 0x020 "BCM_L8_FrP01" */
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xd    /* id: 0x26 "BMS_L8_FrP04" */
  ,0xe    /* id: 0x27 "BMS_L8_FrP05" */
  ,0xff
  ,0xff
  ,0xf    /* id: 0x2A "BMS_L8_FrP06" */
  ,0x10    /* id: 0x2B "BMS_L8_FrP07" */
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0x2    /* id: 0x031 "RSM_L8_FrP01" */
  ,0xff
  ,0xff
  ,0xff
  ,0x1    /* id: 0x035 "RSM_L8_FrP02" */
  ,0x11    /* id: 0x36 "WMM_L8_FrP02" */
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0xff
  ,0x4    /* id: 0x03C "LinReqCmd" */
  ,0x0    /* id: 0x03D "LinRespCmd" */
  ,0xff
  ,0xff
};
#endif

/*************************************************************/
/* list of handles for all messages                              */
/*************************************************************/
canuint8 MEMORY_ROM cabLinMsgHandleTbl[kLinNumberOfObjects] = {
   0    /* id: 0x03D "LinRespCmd" */
  ,1    /* id: 0x035 "RSM_L8_FrP02" */
  ,2    /* id: 0x031 "RSM_L8_FrP01" */
  ,3    /* id: 0x005 "RSM_L8_FrP00" */
  ,4      /* 0x13"ASIC_Frame_04" */
  ,5      /* 0x12"ASIC_Frame_03" */
  ,6      /* 0x11"ASIC_Frame_02" */
  ,7      /* 0x10"ASIC_Frame_01" */
  ,0    /* id: 0x03C "LinReqCmd" */
  ,1    /* id: 0x020 "BCM_L8_FrP01" */
  ,2    /* id: 0x006 "BCM_L8_FrP03" */
  ,3    /* id: 0x002 "WMM_L8_FrP00" */

};


#ifdef L_ENABLE_T_FRAME_MAX

canuint8 MEMORY_ROM cabLinMsgTimeoutTbl[kLinNumberOfRxObjects + kLinNumberOfTxObjects] = {
   (kLinTFrame8 - kLinTHeaderMax)    /* id: 0x03D "LinRespCmd" */
  ,(kLinTFrame8 - kLinTHeaderMax)    /* id: 0x035 "RSM_L8_FrP02" */
  ,(kLinTFrame8 - kLinTHeaderMax)    /* id: 0x031 "RSM_L8_FrP01" */
  ,(kLinTFrame2 - kLinTHeaderMax)    /* id: 0x005 "RSM_L8_FrP00" */
  ,(kLinTFrame8 - kLinTHeaderMax)    /* id: 0x03C "LinReqCmd" */
  ,(kLinTFrame4 - kLinTHeaderMax)    /* id: 0x020 "BCM_L8_FrP01" */
  ,(kLinTFrame2 - kLinTHeaderMax)    /* id: 0x006 "BCM_L8_FrP03" */
};
#endif





