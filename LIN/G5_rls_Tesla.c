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
MEMORY_FAR _c_SOLAR_DATA_buf SOLAR_DATA;
MEMORY_FAR _c_RAIN_LIGHT_DATA_buf RAIN_LIGHT_DATA;
MEMORY_FAR _c_LIGHT_DATA_RAW_buf LIGHT_DATA_RAW;
MEMORY_FAR _c_CLIMATE_DATA_buf CLIMATE_DATA;
MEMORY_FAR _c_ERROR_DATA_RLS_buf ERROR_DATA_RLS;

/******************************************************************************/
/*                        Databuffer for receive objects                      */
/******************************************************************************/

MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
MEMORY_FAR _c_SENS_CONFIG_DATA_buf SENS_CONFIG_DATA;
MEMORY_FAR _c_VEH_DATA_buf VEH_DATA;

/******************************************************************************/
/*                               Send structures                              */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinTxDataLenTbl[kLinNumberOfTxObjects] = {
     8      /* 0x3D"LinRespCmd" */
    ,8      /* 0x13"ASIC_Frame_04" */
    ,8      /* 0x14"ASIC_Frame_03" */
    ,8      /* 0x11"ASIC_Frame_02" */
    ,8      /* 0x10"ASIC_Frame_01" */
    ,2      /* 0x12"SOLAR_DATA" */
    ,8      /* 0x0B"RAIN_LIGHT_DATA" */
    ,2      /* 0x0A"LIGHT_DATA_RAW" */
    ,2      /* 0x05"CLIMATE_DATA" */
    ,2      /* 0x00"ERROR_DATA_RLS" */
};

canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects] = {
     (canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x13"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x14"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x11"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x10"ASIC_Frame_01" */
    ,(canuint8*)SOLAR_DATA._c      /* 0x12"SOLAR_DATA" */
    ,(canuint8*)RAIN_LIGHT_DATA._c      /* 0x0B"RAIN_LIGHT_DATA" */
    ,(canuint8*)LIGHT_DATA_RAW._c      /* 0x0A"LIGHT_DATA_RAW" */
    ,(canuint8*)CLIMATE_DATA._c      /* 0x05"CLIMATE_DATA" */
    ,(canuint8*)ERROR_DATA_RLS._c      /* 0x00"ERROR_DATA_RLS" */
};


/******************************************************************************/
/*                      Databuffer for confirmationflags                      */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinConfirmationOffset[kLinNumberOfTxObjects] = {
       0,    0,    0,    0,    0,    0,    0,    0
   ,   1,    1
};

canuint8 MEMORY_ROM cabLinConfirmationMask[kLinNumberOfTxObjects] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
   ,0x01, 0x02
};


/******************************************************************************/
/*                             Receive structures                             */
/******************************************************************************/

canuint8 MEMORY_ROM cabLinRxDataLenTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,8      /* 0x02"SENS_CONFIG_DATA" */
    ,8      /* 0x07"VEH_DATA" */
};

canuint8 MEMORY_ROM cabLinRxDLCTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,8      /* 0x02"SENS_CONFIG_DATA" */
    ,8      /* 0x07"VEH_DATA" */
};

canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects] = {
     (canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)SENS_CONFIG_DATA._c      /* 0x02"SENS_CONFIG_DATA" */
    ,(canuint8*)VEH_DATA._c      /* 0x07"VEH_DATA" */
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
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_03[8] = {0,0,0,0,0,0,0,0};    /* 0x14"ASIC_Frame_03" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_02[8] = {0,0,0,0,0,0,0,0};    /* 0x11"ASIC_Frame_02" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_01[8] = {0,0,0,0,0,0,0,0};    /* 0x10"ASIC_Frame_01" */
canuint8 MEMORY_ROM LinMsgDefault_SOLAR_DATA[2] = {255,255};    /* 0x12"SOLAR_DATA" */
canuint8 MEMORY_ROM LinMsgDefault_RAIN_LIGHT_DATA[8] = {255,255,255,0,63,0,0,0};    /* 0x0B"RAIN_LIGHT_DATA" */
canuint8 MEMORY_ROM LinMsgDefault_LIGHT_DATA_RAW[2] = {255,255};    /* 0x0A"LIGHT_DATA_RAW" */
canuint8 MEMORY_ROM LinMsgDefault_CLIMATE_DATA[2] = {255,255};    /* 0x05"CLIMATE_DATA" */
canuint8 MEMORY_ROM LinMsgDefault_ERROR_DATA_RLS[2] = {255,255};    /* 0x00"ERROR_DATA_RLS" */

canuint8 MEMORY_ROM LinMsgDefault_LinReqCmd[8] = {0,0,0,0,0,0,0,0};    /* 0x3C"LinReqCmd" */
canuint8 MEMORY_ROM LinMsgDefault_SENS_CONFIG_DATA[8] = {255,255,7,0,0,0,0,0};    /* 0x02"SENS_CONFIG_DATA" */
canuint8 MEMORY_ROM LinMsgDefault_VEH_DATA[8] = {255,240,207,255,255,15,15,0};    /* 0x07"VEH_DATA" */

canuint8* MEMORY_ROM capbLinTxDefaultDataPtrTbl[kLinNumberOfTxObjects] = {
    ,(canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x13"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x14"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x11"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x10"ASIC_Frame_01" */
    ,(canuint8*)SOLAR_DATA._c      /* 0x12"SOLAR_DATA" */
    ,(canuint8*)RAIN_LIGHT_DATA._c      /* 0x0B"RAIN_LIGHT_DATA" */
    ,(canuint8*)LIGHT_DATA_RAW._c      /* 0x0A"LIGHT_DATA_RAW" */
    ,(canuint8*)CLIMATE_DATA._c      /* 0x05"CLIMATE_DATA" */
     (canuint8*)ERROR_DATA_RLS._c      /* 0x00"ERROR_DATA_RLS" */
};

canuint8* MEMORY_ROM capbLinRxDefaultDataPtrTbl[kLinNumberOfRxObjects] = {
    ,(canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)SENS_CONFIG_DATA._c      /* 0x02"SENS_CONFIG_DATA" */
     (canuint8*)VEH_DATA._c      /* 0x07"VEH_DATA" */
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
   ,0x1013      /* 0x13"ASIC_Frame_04" */
   ,0x1012      /* 0x14"ASIC_Frame_03" */
   ,0x1011      /* 0x11"ASIC_Frame_02" */
   ,0x1010      /* 0x10"ASIC_Frame_01" */
   ,0x1204      /* 0x12"SOLAR_DATA" */
   ,0x1203      /* 0x0B"RAIN_LIGHT_DATA" */
   ,0x1202      /* 0x0A"LIGHT_DATA_RAW" */
   ,0x1205      /* 0x05"CLIMATE_DATA" */
   ,0x1201      /* 0x00"ERROR_DATA_RLS" */
   ,0          /* 0x3C"LinReqCmd" */
   ,0x1206     /* 0x02"SENS_CONFIG_DATA" */
   ,0x1200     /* 0x07"VEH_DATA" */
};


#else

canuint8 MEMORY_ROM cabLinMsgIDToHandleTbl[0x40] = {
     0x09      /* 0x00"ERROR_DATA_RLS" */
    ,0xff
    ,0x0B      /* 0x02"SENS_CONFIG_DATA" */
    ,0xff
    ,0xff
    ,0x08      /* 0x05"CLIMATE_DATA" */
    ,0xff
    ,0x0C      /* 0x07"VEH_DATA" */
    ,0xff
    ,0xff
    ,0x07      /* 0x0A"LIGHT_DATA_RAW" */
    ,0x06      /* 0x0B"RAIN_LIGHT_DATA" */
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x04      /* 0x10"ASIC_Frame_01" */
    ,0x03      /* 0x11"ASIC_Frame_02" */
    ,0x05      /* 0x12"SOLAR_DATA" */
    ,0x01      /* 0x13"ASIC_Frame_04" */
    ,0x02      /* 0x14"ASIC_Frame_03" */
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
    ,0xff
    ,0xff
    ,0xff
    ,0x0A      /* 0x3C"LinReqCmd" */
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
   ,2      /* 0x14"ASIC_Frame_03" */
   ,3      /* 0x11"ASIC_Frame_02" */
   ,4      /* 0x10"ASIC_Frame_01" */
   ,5      /* 0x12"SOLAR_DATA" */
   ,6      /* 0x0B"RAIN_LIGHT_DATA" */
   ,7      /* 0x0A"LIGHT_DATA_RAW" */
   ,8      /* 0x05"CLIMATE_DATA" */
   ,9      /* 0x00"ERROR_DATA_RLS" */
   ,0      /* 0x3C"LinReqCmd" */
   ,1      /* 0x02"SENS_CONFIG_DATA" */
   ,2      /* 0x07"VEH_DATA" */
};



/******************************************************************************/
/*                       Buffer with message timeout values                   */
/******************************************************************************/

#ifdef L_ENABLE_T_FRAME_MAX

canuint8 MEMORY_ROM cabLinMsgTimeoutTbl[kLinNumberOfObjects] = {
    (kLinTFrame8 - kLinTHeaderMax)      /* 0x3D"LinRespCmd" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x13"ASIC_Frame_04" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x14"ASIC_Frame_03" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x11"ASIC_Frame_02" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x10"ASIC_Frame_01" */
   ,(kLinTFrame2 - kLinTHeaderMax)      /* 0x12"SOLAR_DATA" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x0B"RAIN_LIGHT_DATA" */
   ,(kLinTFrame2 - kLinTHeaderMax)      /* 0x0A"LIGHT_DATA_RAW" */
   ,(kLinTFrame2 - kLinTHeaderMax)      /* 0x05"CLIMATE_DATA" */
   ,(kLinTFrame2 - kLinTHeaderMax)      /* 0x00"ERROR_DATA_RLS" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x3C"LinReqCmd" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x02"SENS_CONFIG_DATA" */
   ,(kLinTFrame8 - kLinTHeaderMax)      /* 0x07"VEH_DATA" */
};


#endif

