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
MEMORY_FAR _c_AUTOWIPE_buf AUTOWIPE;

/******************************************************************************/
/*                        Databuffer for receive objects                      */
/******************************************************************************/

MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
MEMORY_FAR _c_MOTOR_buf MOTOR;
MEMORY_FAR _c_WIPESW_buf WIPESW;

/******************************************************************************/
/*                               Send structures                              */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinTxDataLenTbl[kLinNumberOfTxObjects] = {
     8      /* 0x3D"LinRespCmd" */
    ,8      /* 0x17"ASIC_Frame_04" */
    ,8      /* 0x19"ASIC_Frame_03" */
    ,8      /* 0x18"ASIC_Frame_02" */
    ,8      /* 0x14"ASIC_Frame_01" */
    ,2      /* 0x10"AUTOWIPE" */
};

canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects] = {
     (canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x17"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x19"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x18"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x14"ASIC_Frame_01" */
    ,(canuint8*)AUTOWIPE._c      /* 0x10"AUTOWIPE" */
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
    ,2      /* 0x12"MOTOR" */
    ,2      /* 0x11"WIPESW" */
};

canuint8 MEMORY_ROM cabLinRxDLCTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,2      /* 0x12"MOTOR" */
    ,2      /* 0x11"WIPESW" */
};

canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects] = {
     (canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)MOTOR._c      /* 0x12"MOTOR" */
    ,(canuint8*)WIPESW._c      /* 0x11"WIPESW" */
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
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_03[8] = {0,0,0,0,0,0,0,0};    /* 0x19"ASIC_Frame_03" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_02[8] = {0,0,0,0,0,0,0,0};    /* 0x18"ASIC_Frame_02" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_01[8] = {0,0,0,0,0,0,0,0};    /* 0x14"ASIC_Frame_01" */
canuint8 MEMORY_ROM LinMsgDefault_AUTOWIPE[2] = {0,0};    /* 0x10"AUTOWIPE" */

canuint8 MEMORY_ROM LinMsgDefault_LinReqCmd[8] = {0,0,0,0,0,0,0,0};    /* 0x3C"LinReqCmd" */
canuint8 MEMORY_ROM LinMsgDefault_MOTOR[2] = {0,0};    /* 0x12"MOTOR" */
canuint8 MEMORY_ROM LinMsgDefault_WIPESW[2] = {0,0};    /* 0x11"WIPESW" */

canuint8* MEMORY_ROM capbLinTxDefaultDataPtrTbl[kLinNumberOfTxObjects] = {
    ,(canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x17"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x19"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x18"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x14"ASIC_Frame_01" */
     (canuint8*)AUTOWIPE._c      /* 0x10"AUTOWIPE" */
};

canuint8* MEMORY_ROM capbLinRxDefaultDataPtrTbl[kLinNumberOfRxObjects] = {
    ,(canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)MOTOR._c      /* 0x12"MOTOR" */
     (canuint8*)WIPESW._c      /* 0x11"WIPESW" */
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
   ,0x0017      /* 0x17"ASIC_Frame_04" */
   ,0x0016      /* 0x16"ASIC_Frame_03" */
   ,0x0015      /* 0x15"ASIC_Frame_02" */
   ,0x0014      /* 0x14"ASIC_Frame_01" */
   ,0x0010      /* 0x10"AUTOWIPE" */
   ,0          /* 0x3C"LinReqCmd" */
   ,0x0012     /* 0x12"MOTOR" */
   ,0x0011     /* 0x11"WIPESW" */
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
    ,0x05      /* 0x10"AUTOWIPE" */
    ,0x08      /* 0x11"WIPESW" */
    ,0x07      /* 0x12"MOTOR" */
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
   ,1      /* 0x17"ASIC_Frame_04" */
   ,2      /* 0x19"ASIC_Frame_03" */
   ,3      /* 0x18"ASIC_Frame_02" */
   ,4      /* 0x14"ASIC_Frame_01" */
   ,5      /* 0x10"AUTOWIPE" */
   ,0      /* 0x3C"LinReqCmd" */
   ,1      /* 0x12"MOTOR" */
   ,2      /* 0x11"WIPESW" */
};



/******************************************************************************/
/*                       Buffer with message timeout values                   */
/******************************************************************************/

#ifdef L_ENABLE_T_FRAME_MAX

canuint8 MEMORY_ROM cabLinMsgTimeoutTbl[kLinNumberOfObjects] = {
    (kLinTFrame8 - kLinTHeaderMax)      /* 0x3D"LinRespCmd" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x17"ASIC_Frame_04" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x19"ASIC_Frame_03" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x18"ASIC_Frame_02" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x14"ASIC_Frame_01" */
   ,(kLinTFrame2 - kLinTHeaderMax)      /* 0x10"AUTOWIPE" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x3C"LinReqCmd" */
   ,(kLinTFrame2 - kLinTHeaderMax)      /* 0x12"MOTOR" */
   ,(kLinTFrame2 - kLinTHeaderMax)      /* 0x11"WIPESW" */
};


#endif

