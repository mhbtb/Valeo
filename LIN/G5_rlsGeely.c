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

#ifdef __COMPILER_DEFINES_IN_EXTRA_HEADER_FILE__
#include "../compiler_defines_projconf.h"
#endif
#ifdef __QACCHECK__
#include "../predef_macros_projconf.h"
#endif

#include "ior5f109be.h"
#include "ior5f109be_ext.h"

#include "G5_lininclude.h"


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
MEMORY_FAR _c_RS_01_buf RS_01;

/******************************************************************************/
/*                        Databuffer for receive objects                      */
/******************************************************************************/

MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
MEMORY_FAR _c_BCM_02_buf BCM_02;
MEMORY_FAR _c_BCM_01_buf BCM_01;

/******************************************************************************/
/*                               Send structures                              */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinTxDataLenTbl[kLinNumberOfTxObjects] = {
     8      /* 0x3D"LinRespCmd" */
    ,8      /* 0x3B"ASIC_Frame_04" */
    ,8      /* 0x3A"ASIC_Frame_03" */
    ,8      /* 0x39"ASIC_Frame_02" */
    ,8      /* 0x38"ASIC_Frame_01" */
    ,8      /* 0x15"RS_01" */
};

canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects] = {
     (canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x3B"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x3A"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x39"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x38"ASIC_Frame_01" */
    ,(canuint8*)RS_01._c      /* 0x15"RS_01" */
};


/******************************************************************************/
/*                      Databuffer for confirmationflags                      */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinConfirmationOffset[kLinNumberOfTxObjects] = {
       0,    0,    0,    0,    0,    0
};

canuint8 MEMORY_ROM cabLinConfirmationMask[kLinNumberOfTxObjects] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20
};


/******************************************************************************/
/*                             Receive structures                             */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinRxDataLenTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,4      /* 0x32"BCM_02" */
    ,8      /* 0x31"BCM_01" */
};

canuint8 MEMORY_ROM cabLinRxDLCTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,4      /* 0x32"BCM_02" */
    ,8      /* 0x31"BCM_01" */
};

canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects] = {
     (canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)BCM_02._c      /* 0x32"BCM_02" */
    ,(canuint8*)BCM_01._c      /* 0x31"BCM_01" */
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
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_04[8] = {0,0,0,0,0,0,0,0};    /* 0x3B"ASIC_Frame_04" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_03[8] = {0,0,0,0,0,0,0,0};    /* 0x3A"ASIC_Frame_03" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_02[8] = {0,0,0,0,0,0,0,0};    /* 0x39"ASIC_Frame_02" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_01[8] = {0,0,0,0,0,0,0,0};    /* 0x38"ASIC_Frame_01" */
canuint8 MEMORY_ROM LinMsgDefault_RS_01[8] = {48,3,255,0,0,0,0,0};    /* 0x15"RS_01" */

canuint8 MEMORY_ROM LinMsgDefault_LinReqCmd[8] = {0,0,0,0,0,0,0,0};    /* 0x3C"LinReqCmd" */
canuint8 MEMORY_ROM LinMsgDefault_BCM_02[4] = {3,0,0,0};    /* 0x32"BCM_02" */
canuint8 MEMORY_ROM LinMsgDefault_BCM_01[8] = {0,0,0,0,0,0,0,0};    /* 0x31"BCM_01" */

canuint8* MEMORY_ROM capbLinTxDefaultDataPtrTbl[kLinNumberOfTxObjects] = {
    ,(canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x3B"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x3A"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x39"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x38"ASIC_Frame_01" */
     (canuint8*)RS_01._c      /* 0x15"RS_01" */
};

canuint8* MEMORY_ROM capbLinRxDefaultDataPtrTbl[kLinNumberOfRxObjects] = {
    ,(canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)BCM_02._c      /* 0x32"BCM_02" */
     (canuint8*)BCM_01._c      /* 0x31"BCM_01" */
};


#endif /*L_ENABLE_INIT_DEFAULT_DATA */


/******************************************************************************/
/*                    Databuffer for IDs to handle table                      */
/******************************************************************************/

#ifdef NODECONFIGURATION
   
canuint8 rabRAMLinMsgIDToHandleTbl[0x40];
#pragma dataseg=default

canuint16 MEMORY_ROM cawLINMessageID[kLinNumberOfObjects] = {
    0           /* 0x3D"LinRespCmd" */
   ,0x1041      /* 0x3B"ASIC_Frame_04" */
   ,0x1040      /* 0x3A"ASIC_Frame_03" */
   ,0x1039      /* 0x39"ASIC_Frame_02" */
   ,0x1038      /* 0x38"ASIC_Frame_01" */
   ,0x1015      /* 0x15"RS_01" */
   ,0          /* 0x3C"LinReqCmd" */
   ,0x1032     /* 0x32"BCM_02" */
   ,0x1031     /* 0x31"BCM_01" */
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
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x05      /* 0x15"RS_01" */
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
    ,0xff
    ,0xff
    ,0x08      /* 0x31"BCM_01" */
    ,0x07      /* 0x32"BCM_02" */
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x04      /* 0x38"ASIC_Frame_01" */
    ,0x03      /* 0x39"ASIC_Frame_02" */
    ,0x02      /* 0x3A"ASIC_Frame_03" */
    ,0x01      /* 0x3B"ASIC_Frame_04" */
    ,0x06      /* 0x3C"LinReqCmd" */
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
   ,1      /* 0x3B"ASIC_Frame_04" */
   ,2      /* 0x3A"ASIC_Frame_03" */
   ,3      /* 0x39"ASIC_Frame_02" */
   ,4      /* 0x38"ASIC_Frame_01" */
   ,5      /* 0x15"RS_01" */
   ,0      /* 0x3C"LinReqCmd" */
   ,1      /* 0x32"BCM_02" */
   ,2      /* 0x31"BCM_01" */
};



/******************************************************************************/
/*                       Buffer with message timeout values                   */
/******************************************************************************/

#ifdef L_ENABLE_T_FRAME_MAX

canuint8 MEMORY_ROM cabLinMsgTimeoutTbl[kLinNumberOfObjects] = {
    (kLinTFrame8 - kLinTHeaderMax)      /* 0x3D"LinRespCmd" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x3B"ASIC_Frame_04" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x3A"ASIC_Frame_03" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x39"ASIC_Frame_02" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x38"ASIC_Frame_01" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x15"RS_01" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x3C"LinReqCmd" */
   ,(kLinTFrame4 - kLinTHeaderMax)      /* 0x32"BCM_02" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x31"BCM_01" */
};


#endif

