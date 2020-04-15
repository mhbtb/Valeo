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

//#ifdef __COMPILER_DEFINES_IN_EXTRA_HEADER_FILE__
//#include "../compiler_defines_projconf.h"
//#endif
//#ifdef __QACCHECK__
//#include "../predef_macros_projconf.h"
//#endif
//
//#ifdef NEC
//#pragma language = extended /*Compile Option*/
//#include "..\io78f051344.h"
//#include "..\lininclude.h"
//#else
//#include "lib.h"
//#include "lininclude.h"
//#endif

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
MEMORY_FAR _c_RLSData_buf RLSData;
MEMORY_FAR _c_HRLSData_buf HRLSData;

/******************************************************************************/
/*                        Databuffer for receive objects                      */
/******************************************************************************/

MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
MEMORY_FAR _c_RLSCfgData_buf RLSCfgData;
MEMORY_FAR _c_ComToRLS_buf ComToRLS;
MEMORY_FAR _c_ComToHRLS_buf ComToHRLS;

/******************************************************************************/
/*                               Send structures                              */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinTxDataLenTbl[kLinNumberOfTxObjects] = {
     8      /* 0x3D"LinRespCmd" */
    ,8      /* 0x13"ASIC_Frame_04" */
    ,8      /* 0x12"ASIC_Frame_03" */
    ,8      /* 0x11"ASIC_Frame_02" */
    ,8      /* 0x10"ASIC_Frame_01" */
    ,2      /* 0x29"RLSData" */
    ,8      /* 0x15"HRLSData" */
};

canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects] = {
     (canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x13"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x12"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x11"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x10"ASIC_Frame_01" */
    ,(canuint8*)RLSData._c      /* 0x29"RLSData" */
    ,(canuint8*)HRLSData._c      /* 0x15"HRLSData" */
};


/******************************************************************************/
/*                      Databuffer for confirmationflags                      */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinConfirmationOffset[kLinNumberOfTxObjects] = {
       0,    0,    0,    0,    0,    0,    0
};

canuint8 MEMORY_ROM cabLinConfirmationMask[kLinNumberOfTxObjects] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40
};


/******************************************************************************/
/*                             Receive structures                             */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinRxDataLenTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,2      /* 0x1D"RLSCfgData" */
    ,4      /* 0x26"ComToRLS" */
    ,8      /* 0x16"ComToHRLS" */
};

canuint8 MEMORY_ROM cabLinRxDLCTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,2      /* 0x1D"RLSCfgData" */
    ,4      /* 0x26"ComToRLS" */
    ,8      /* 0x16"ComToHRLS" */
};

canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects] = {
     (canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)RLSCfgData._c      /* 0x1D"RLSCfgData" */
    ,(canuint8*)ComToRLS._c      /* 0x26"ComToRLS" */
    ,(canuint8*)ComToHRLS._c      /* 0x16"ComToHRLS" */
};


/******************************************************************************/
/*                        Databuffer for indicationflags                      */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinIndicationOffset[kLinNumberOfRxObjects] = {
       0,    0,    0,    0
};

canuint8 MEMORY_ROM cabLinIndicationMask[kLinNumberOfRxObjects] = {
    0x01, 0x02, 0x04, 0x08
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
canuint8 MEMORY_ROM LinMsgDefault_RLSData[2] = {0,0};    /* 0x29"RLSData" */
canuint8 MEMORY_ROM LinMsgDefault_HRLSData[8] = {0,0,0,0,0,0,0,0};    /* 0x15"HRLSData" */

canuint8 MEMORY_ROM LinMsgDefault_LinReqCmd[8] = {0,0,0,0,0,0,0,0};    /* 0x3C"LinReqCmd" */
canuint8 MEMORY_ROM LinMsgDefault_RLSCfgData[2] = {0,0};    /* 0x1D"RLSCfgData" */
canuint8 MEMORY_ROM LinMsgDefault_ComToRLS[4] = {0,0,0,0};    /* 0x26"ComToRLS" */
canuint8 MEMORY_ROM LinMsgDefault_ComToHRLS[8] = {0,0,0,0,0,0,0,0};    /* 0x16"ComToHRLS" */

canuint8* MEMORY_ROM capbLinTxDefaultDataPtrTbl[kLinNumberOfTxObjects] = {
    ,(canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x13"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x12"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x11"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x10"ASIC_Frame_01" */
    ,(canuint8*)RLSData._c      /* 0x29"RLSData" */
     (canuint8*)HRLSData._c      /* 0x15"HRLSData" */
};

canuint8* MEMORY_ROM capbLinRxDefaultDataPtrTbl[kLinNumberOfRxObjects] = {
    ,(canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)RLSCfgData._c      /* 0x1D"RLSCfgData" */
    ,(canuint8*)ComToRLS._c      /* 0x26"ComToRLS" */
     (canuint8*)ComToHRLS._c      /* 0x16"ComToHRLS" */
};


#endif /*L_ENABLE_INIT_DEFAULT_DATA */


/******************************************************************************/
/*                    Databuffer for IDs to handle table                      */
/******************************************************************************/

#ifdef NODECONFIGURATION

// #pragma dataseg="IXRAM"              
__no_init canuint8 rabRAMLinMsgIDToHandleTbl[0x40];
#pragma dataseg=default

canuint16 MEMORY_ROM cawLINMessageID[kLinNumberOfObjects] = {
    0           /* 0x3D"LinRespCmd" */
   ,0x1013      /* 0x13"ASIC_Frame_04" */
   ,0x1012      /* 0x12"ASIC_Frame_03" */
   ,0x1011      /* 0x11"ASIC_Frame_02" */
   ,0x1010      /* 0x10"ASIC_Frame_01" */
   ,0x0029      /* 0x29"RLSData" */
   ,0x0015      /* 0x15"HRLSData" */
   ,0          /* 0x3C"LinReqCmd" */
   ,0x001D     /* 0x1D"RLSCfgData" */
   ,0x0026     /* 0x26"ComToRLS" */
   ,0x0016     /* 0x16"ComToHRLS" */
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
    ,0x06      /* 0x15"HRLSData" */
    ,0x0A      /* 0x16"ComToHRLS" */
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x08      /* 0x1D"RLSCfgData" */
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x09      /* 0x26"ComToRLS" */
    ,0xff
    ,0xff
    ,0x05      /* 0x29"RLSData" */
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
    ,0x07      /* 0x3C"LinReqCmd" */
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
   ,5      /* 0x29"RLSData" */
   ,6      /* 0x15"HRLSData" */
   ,0      /* 0x3C"LinReqCmd" */
   ,1      /* 0x1D"RLSCfgData" */
   ,2      /* 0x26"ComToRLS" */
   ,3      /* 0x16"ComToHRLS" */
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
   ,(kLinTFrame2 - kLinTHeaderMax)      /* 0x29"RLSData" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x15"HRLSData" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x3C"LinReqCmd" */
   ,(kLinTFrame2 - kLinTHeaderMax)      /* 0x1D"RLSCfgData" */
   ,(kLinTFrame4 - kLinTHeaderMax)      /* 0x26"ComToRLS" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x16"ComToHRLS" */
};


#endif

