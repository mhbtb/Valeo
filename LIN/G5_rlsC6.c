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
MEMORY_FAR _c_LsRLS_2_buf LsRLS_2;
MEMORY_FAR _c_RLSs_01_buf RLSs_01;

/******************************************************************************/
/*                        Databuffer for receive objects                      */
/******************************************************************************/

MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
MEMORY_FAR _c_WWSs_01_buf WWSs_01;
MEMORY_FAR _c_BCM1s_01_buf BCM1s_01;

/******************************************************************************/
/*                               Send structures                              */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinTxDataLenTbl[kLinNumberOfTxObjects] = {
     8      /* 0x3D"LinRespCmd" */
    ,3      /* 0x23"LsRLS_2" */
    ,4      /* 0x22"RLSs_01" */
};

canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects] = {
     (canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)LsRLS_2._c      /* 0x23"LsRLS_2" */
    ,(canuint8*)RLSs_01._c      /* 0x22"RLSs_01" */
};


/******************************************************************************/
/*                      Databuffer for confirmationflags                      */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinConfirmationOffset[kLinNumberOfTxObjects] = {
       0,    0,    0
};

canuint8 MEMORY_ROM cabLinConfirmationMask[kLinNumberOfTxObjects] = {
    0x01, 0x02, 0x04
};


/******************************************************************************/
/*                             Receive structures                             */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinRxDataLenTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,5      /* 0x31"WWSs_01" */
    ,5      /* 0x30"BCM1s_01" */
};

canuint8 MEMORY_ROM cabLinRxDLCTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,5      /* 0x31"WWSs_01" */
    ,5      /* 0x30"BCM1s_01" */
};

canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects] = {
     (canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)WWSs_01._c      /* 0x31"WWSs_01" */
    ,(canuint8*)BCM1s_01._c      /* 0x30"BCM1s_01" */
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
canuint8 MEMORY_ROM LinMsgDefault_LsRLS_2[3] = {0,0,0};    /* 0x23"LsRLS_2" */
canuint8 MEMORY_ROM LinMsgDefault_RLSs_01[4] = {0,2,0,0};    /* 0x22"RLSs_01" */

canuint8 MEMORY_ROM LinMsgDefault_LinReqCmd[8] = {0,0,0,0,0,0,0,0};    /* 0x3C"LinReqCmd" */
canuint8 MEMORY_ROM LinMsgDefault_WWSs_01[5] = {0,0,0,0,0};    /* 0x31"WWSs_01" */
canuint8 MEMORY_ROM LinMsgDefault_BCM1s_01[5] = {0,0,0,0,0};    /* 0x30"BCM1s_01" */

canuint8* MEMORY_ROM capbLinTxDefaultDataPtrTbl[kLinNumberOfTxObjects] = {
    ,(canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)LsRLS_2._c      /* 0x23"LsRLS_2" */
     (canuint8*)RLSs_01._c      /* 0x22"RLSs_01" */
};

canuint8* MEMORY_ROM capbLinRxDefaultDataPtrTbl[kLinNumberOfRxObjects] = {
    ,(canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)WWSs_01._c      /* 0x31"WWSs_01" */
     (canuint8*)BCM1s_01._c      /* 0x30"BCM1s_01" */
};


#endif /*L_ENABLE_INIT_DEFAULT_DATA */


/******************************************************************************/
/*                    Databuffer for IDs to handle table                      */
/******************************************************************************/

#ifdef NODECONFIGURATION

            
 canuint8 rabRAMLinMsgIDToHandleTbl[0x40];


canuint16 MEMORY_ROM cawLINMessageID[kLinNumberOfObjects] = {
    0           /* 0x3D"LinRespCmd" */
   ,0x1023      /* 0x23"LsRLS_2" */
   ,0x1022      /* 0x22"RLSs_01" */
   ,0          /* 0x3C"LinReqCmd" */
   ,0x1031     /* 0x31"WWSs_01" */
   ,0x1030     /* 0x30"BCM1s_01" */
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
    ,0x02      /* 0x22"RLSs_01" */
    ,0x01      /* 0x23"LsRLS_2" */
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
    ,0x05      /* 0x30"BCM1s_01" */
    ,0x04      /* 0x31"WWSs_01" */
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
    ,0x03      /* 0x3C"LinReqCmd" */
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
   ,1      /* 0x23"LsRLS_2" */
   ,2      /* 0x22"RLSs_01" */
   ,0      /* 0x3C"LinReqCmd" */
   ,1      /* 0x31"WWSs_01" */
   ,2      /* 0x30"BCM1s_01" */
};



/******************************************************************************/
/*                       Buffer with message timeout values                   */
/******************************************************************************/

#ifdef L_ENABLE_T_FRAME_MAX

canuint8 MEMORY_ROM cabLinMsgTimeoutTbl[kLinNumberOfObjects] = {
    (kLinTFrame8 - kLinTHeaderMax)      /* 0x3D"LinRespCmd" */
   ,(kLinTFrame3 - kLinTHeaderMax)      /* 0x23"LsRLS_2" */
   ,(kLinTFrame4 - kLinTHeaderMax)      /* 0x22"RLSs_01" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x3C"LinReqCmd" */
   ,(kLinTFrame5 - kLinTHeaderMax)      /* 0x31"WWSs_01" */
   ,(kLinTFrame5 - kLinTHeaderMax)      /* 0x30"BCM1s_01" */
};


#endif

