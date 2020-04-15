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
 * <tr> <td> Source:   </td> <td> template_rls.c                  </td></tr>
 * <tr> <td> Revision: </td> <td> 1.0                  </td></tr>
 * <tr> <td> Status:   </td> <td> STORED                  </td></tr>
 * <tr> <td> Author:   </td> <td> Jochen Schenk, VDS-E-PUS  </td></tr>
 * <tr> <td> Date:     </td> <td> 07-APR-2014 07:47:16                 </td></tr>
 * </table>
 * 
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> RLS_LIN </td></tr>
 * <tr> <td> TARGET:    </td> <td> NEC     </td></tr>
 * </table>
 */

/******************************************************************************/
/*                      Include headers of the component                      */
/******************************************************************************/

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
MEMORY_FAR _c_RLS_LIN_3_buf RLS_LIN_3;
MEMORY_FAR _c_RLS_LIN_2_buf RLS_LIN_2;
MEMORY_FAR _c_RLS_LIN_1_buf RLS_LIN_1;

/******************************************************************************/
/*                        Databuffer for receive objects                      */
/******************************************************************************/

MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
MEMORY_FAR _c_BCM_LIN_2_buf BCM_LIN_2;
MEMORY_FAR _c_BCM_LIN_1_buf BCM_LIN_1;

/******************************************************************************/
/*                               Send structures                              */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinTxDataLenTbl[kLinNumberOfTxObjects] = {
     8      /* 0x3D"LinRespCmd" */
    ,8      /* 0x17"ASIC_Frame_04" */
    ,8      /* 0x16"ASIC_Frame_03" */
    ,8      /* 0x15"ASIC_Frame_02" */
    ,8      /* 0x14"ASIC_Frame_01" */
    ,8      /* 0x0B"RLS_LIN_3" */
    ,5      /* 0x22"RLS_LIN_2" */
    ,5      /* 0x11"RLS_LIN_1" */
};

canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects] = {
     (canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x17"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x16"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x15"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x14"ASIC_Frame_01" */
    ,(canuint8*)RLS_LIN_3._c      /* 0x0B"RLS_LIN_3" */
    ,(canuint8*)RLS_LIN_2._c      /* 0x22"RLS_LIN_2" */
    ,(canuint8*)RLS_LIN_1._c      /* 0x11"RLS_LIN_1" */
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
    ,8      /* 0x07"BCM_LIN_2" */
    ,8      /* 0x10"BCM_LIN_1" */
};

canuint8 MEMORY_ROM cabLinRxDLCTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,8      /* 0x07"BCM_LIN_2" */
    ,8      /* 0x10"BCM_LIN_1" */
};

canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects] = {
     (canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)BCM_LIN_2._c      /* 0x07"BCM_LIN_2" */
    ,(canuint8*)BCM_LIN_1._c      /* 0x10"BCM_LIN_1" */
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
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_04[8] = {0,0,0,0,0,0,0,0};    /* 0x17"ASIC_Frame_04" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_03[8] = {0,0,0,0,0,0,0,0};    /* 0x16"ASIC_Frame_03" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_02[8] = {0,0,0,0,0,0,0,0};    /* 0x15"ASIC_Frame_02" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_01[8] = {0,0,0,0,0,0,0,0};    /* 0x14"ASIC_Frame_01" */
canuint8 MEMORY_ROM LinMsgDefault_RLS_LIN_3[8] = {0,0,0,0,0,0,0,0};    /* 0x0B"RLS_LIN_3" */
canuint8 MEMORY_ROM LinMsgDefault_RLS_LIN_2[8] = {0,0,0,0,0,0,0,0};    /* 0x22"RLS_LIN_2" */
canuint8 MEMORY_ROM LinMsgDefault_RLS_LIN_1[8] = {0,0,0,0,0,0,0,0};    /* 0x11"RLS_LIN_1" */

canuint8 MEMORY_ROM LinMsgDefault_LinReqCmd[8] = {0,0,0,0,0,0,0,0};    /* 0x3C"LinReqCmd" */
canuint8 MEMORY_ROM LinMsgDefault_BCM_LIN_2[8] = {0,0,0,0,0,0,0,0};    /* 0x07"BCM_LIN_2" */
canuint8 MEMORY_ROM LinMsgDefault_BCM_LIN_1[8] = {0,0,0,0,0,0,0,0};    /* 0x10"BCM_LIN_1" */

canuint8* MEMORY_ROM capbLinTxDefaultDataPtrTbl[kLinNumberOfTxObjects] = {
    ,(canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x17"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x16"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x15"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x14"ASIC_Frame_01" */
    ,(canuint8*)RLS_LIN_3._c      /* 0x0B"RLS_LIN_3" */
    ,(canuint8*)RLS_LIN_2._c      /* 0x22"RLS_LIN_2" */
     (canuint8*)RLS_LIN_1._c      /* 0x11"RLS_LIN_1" */
};

canuint8* MEMORY_ROM capbLinRxDefaultDataPtrTbl[kLinNumberOfRxObjects] = {
    ,(canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)BCM_LIN_2._c      /* 0x07"BCM_LIN_2" */
     (canuint8*)BCM_LIN_1._c      /* 0x10"BCM_LIN_1" */
};


#endif /*L_ENABLE_INIT_DEFAULT_DATA */


/******************************************************************************/
/*                    Databuffer for IDs to handle table                      */
/******************************************************************************/

#ifdef NODECONFIGURATION

//#pragma dataseg="IXRAM"              
__no_init canuint8 rabRAMLinMsgIDToHandleTbl[0x40];
#pragma dataseg=default

canuint16 MEMORY_ROM cawLINMessageID[kLinNumberOfObjects] = {
    0           /* 0x3D"LinRespCmd" */
   ,0x0000      /* 0x17"ASIC_Frame_04" */
   ,0x0000      /* 0x16"ASIC_Frame_03" */
   ,0x0000      /* 0x15"ASIC_Frame_02" */
   ,0x0000      /* 0x14"ASIC_Frame_01" */
   ,0x0000      /* 0x0B"RLS_LIN_3" */
   ,0x0000      /* 0x22"RLS_LIN_2" */
   ,0x0000      /* 0x11"RLS_LIN_1" */
   ,0          /* 0x3C"LinReqCmd" */
   ,0x0000     /* 0x07"BCM_LIN_2" */
   ,0x0000     /* 0x10"BCM_LIN_1" */
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
    ,0x09      /* 0x07"BCM_LIN_2" */
    ,0xff
    ,0xff
    ,0xff
    ,0x05      /* 0x0B"RLS_LIN_3" */
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x0A      /* 0x10"BCM_LIN_1" */
    ,0x07      /* 0x11"RLS_LIN_1" */
    ,0xff
    ,0xff
    ,0x04      /* 0x14"ASIC_Frame_01" */
    ,0x03      /* 0x15"ASIC_Frame_02" */
    ,0x02      /* 0x16"ASIC_Frame_03" */
    ,0x01      /* 0x17"ASIC_Frame_04" */
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
    ,0x06      /* 0x22"RLS_LIN_2" */
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
   ,1      /* 0x17"ASIC_Frame_04" */
   ,2      /* 0x16"ASIC_Frame_03" */
   ,3      /* 0x15"ASIC_Frame_02" */
   ,4      /* 0x14"ASIC_Frame_01" */
   ,5      /* 0x0B"RLS_LIN_3" */
   ,6      /* 0x22"RLS_LIN_2" */
   ,7      /* 0x11"RLS_LIN_1" */
   ,0      /* 0x3C"LinReqCmd" */
   ,1      /* 0x07"BCM_LIN_2" */
   ,2      /* 0x10"BCM_LIN_1" */
};



/******************************************************************************/
/*                       Buffer with message timeout values                   */
/******************************************************************************/

#ifdef L_ENABLE_T_FRAME_MAX

canuint8 MEMORY_ROM cabLinMsgTimeoutTbl[kLinNumberOfObjects] = {
    (kLinTFrame8 - kLinTHeaderMax)      /* 0x3D"LinRespCmd" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x17"ASIC_Frame_04" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x16"ASIC_Frame_03" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x15"ASIC_Frame_02" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x14"ASIC_Frame_01" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x0B"RLS_LIN_3" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x22"RLS_LIN_2" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x11"RLS_LIN_1" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x3C"LinReqCmd" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x07"BCM_LIN_2" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x10"BCM_LIN_1" */
};


#endif

