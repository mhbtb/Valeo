/**************************************************************
*  File d:\Temp\rls940.c
*  generated at Thu May 10 15:50:01 2007
*             Toolversion:   359
*               Bussystem:   Lin
*
*  generated out of CANdb:   C:\Tools\CANalyzer 5.1\Exec32\ldf2dbcAlt\LIN_RLS V1_0.dbc
*            Manufacturer:   Unknown
*                for node:   RLS
*   Generation parameters:   Target system = ST7
*                            Compiler      = Cosmic
*
* License information:
*   -    Serialnumber:       CBD0100045
*   - Date of license:       18.5.2001
*
***************************************************************
Software is licensed for:
Volkswagen AG
GenerationTool: SingleChannel
Controller: ST7
Compiler: Cosmic
Bussystem: CAN and LIN
**************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Author   Description                                       */
/*-DD.MM.YY-------------------------------------------------------------------*/

/*12.05.16   VCO_325     NB      FCA:Integration VCO to merge the changes from Audi 002 baseline to FCA 004 baseline*/
/*30.05.16   VDR_983     NB      Sporadic illegale instruction reset in the startup */


/* PRQA S 0750,759,635 EOF *//*<< 0759:union needed to reduce RAM usage and bit fields are required >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/

#include "ior5f109be.h"
#include "G5_lininclude.h"


/* start skeleton LIN    C-File ----------------------------------------*/

/* end   skeleton LIN    C-File ----------------------------------------*/


/*************************************************************/
/* Databuffer for send objects                               */
/*************************************************************/
MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
MEMORY_FAR _c_FSdataEnhanced_buf FSdataEnhanced;
MEMORY_FAR _c_FSdata_buf FSdata;
MEMORY_FAR _c_SoSe_buf SoSe;
MEMORY_FAR _c_RLSData_buf RLSData;


/*************************************************************/
/* Databuffer for receive objects                            */
/*************************************************************/
MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
MEMORY_FAR _c_ComToRLS_buf ComToRLS;
MEMORY_FAR _c_RLSCfgData_buf RLSCfgData;


/*************************************************************/
/* Send structures                                           */
/*************************************************************/
canuint8 MEMORY_ROM cabLinTxDataLenTbl[kLinNumberOfTxObjects] = {
     8      /* 0x3D"LinRespCmd" */
    ,8      /* 0x13"ASIC_Frame_04" */
    ,8      /* 0x12"ASIC_Frame_03" */
    ,8      /* 0x11"ASIC_Frame_02" */
    ,8      /* 0x10"ASIC_Frame_01" */
    ,8      /* 0x24"FSdataEnhanced" */
    ,5      /* 0x23"FSdata" */
    ,8      /* 0x32"SoSe" */
    ,2      /* 0x29"RLSData" */
};

canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects] = {
     (canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x13"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x12"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x11"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x10"ASIC_Frame_01" */
    ,(canuint8*)FSdataEnhanced._c      /* 0x24"FSdataEnhanced" */
    ,(canuint8*)FSdata._c      /* 0x23"FSdata" */
    ,(canuint8*)SoSe._c      /* 0x32"SoSe" */
    ,(canuint8*)RLSData._c      /* 0x29"RLSData" */
};



/*************************************************************/
/* Databuffer for confirmationflags                          */
/*************************************************************/

canuint8 MEMORY_ROM cabLinConfirmationOffset[kLinNumberOfTxObjects] = {
       0,    0,    0,    0,    0,    0,    0,    0
   ,   1
};

canuint8 MEMORY_ROM cabLinConfirmationMask[kLinNumberOfTxObjects] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
   ,0x01
};


/******************************************************************************/
/* Receive structures                                        */
/*************************************************************/

canuint8 MEMORY_ROM cabLinRxDataLenTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,4      /* 0x26"ComToRLS" */
    ,2      /* 0x1D"RLSCfgData" */
};

canuint8 MEMORY_ROM cabLinRxDLCTbl[kLinNumberOfRxObjects] = {
     8      /* 0x3C"LinReqCmd" */
    ,4      /* 0x26"ComToRLS" */
    ,2      /* 0x1D"RLSCfgData" */
};

canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects] = {
     (canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)ComToRLS._c      /* 0x26"ComToRLS" */
    ,(canuint8*)RLSCfgData._c      /* 0x1D"RLSCfgData" */
};



/*************************************************************/
/* Databuffer for indicationflags                                */
/*************************************************************/
canuint8 MEMORY_ROM cabLinIndicationOffset[kLinNumberOfRxObjects] = {
       0,    0,    0
};

canuint8 MEMORY_ROM cabLinIndicationMask[kLinNumberOfRxObjects] = {
    0x01, 0x02, 0x04
};


/* Default values for messages */
#if defined(L_ENABLE_INIT_DEFAULT_DATA) || defined(L_ENABLE_START_DEFAULT_DATA) || defined(L_ENABLE_STOP_DEFAULT_DATA)
canuint8 MEMORY_ROM LinMsgDefault_LinRespCmd[8] = {0,0,0,0,0,0,0,0};    /* 0x3D"LinRespCmd" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_04[8] = {0,0,0,0,0,0,0,0};    /* 0x13"ASIC_Frame_04" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_03[8] = {0,0,0,0,0,0,0,0};    /* 0x12"ASIC_Frame_03" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_02[8] = {0,0,0,0,0,0,0,0};    /* 0x11"ASIC_Frame_02" */
canuint8 MEMORY_ROM LinMsgDefault_ASIC_Frame_01[8] = {0,0,0,0,0,0,0,0};    /* 0x10"ASIC_Frame_01" */
canuint8 MEMORY_ROM LinMsgDefault_FSdataEnhanced[8] = {255,7,255,7,255,7,255,0};    /* 0x24"FSdataEnhanced" */
canuint8 MEMORY_ROM LinMsgDefault_FSdata[5] = {255,255,255,255,0};    /* 0x23"FSdata" */
canuint8 MEMORY_ROM LinMsgDefault_SoSe[8] = {0,0,255,255,255,255,255,255};    /* 0x32"SoSe" */
canuint8 MEMORY_ROM LinMsgDefault_RLSData[2] = {0,0};    /* 0x29"RLSData" */

canuint8 MEMORY_ROM LinMsgDefault_LinReqCmd[8] = {0,0,0,0,0,0,0,0};    /* 0x3C"LinReqCmd" */
canuint8 MEMORY_ROM LinMsgDefault_ComToRLS[4] = {0,0,0,0};    /* 0x26"ComToRLS" */
canuint8 MEMORY_ROM LinMsgDefault_RLSCfgData[2] = {0,0};    /* 0x1D"RLSCfgData" */

canuint8* MEMORY_ROM capbLinTxDefaultDataPtrTbl[kLinNumberOfTxObjects] = {
    ,(canuint8*)LinRespCmd._c      /* 0x3D"LinRespCmd" */
    ,(canuint8*)ASIC_Frame_04._c      /* 0x13"ASIC_Frame_04" */
    ,(canuint8*)ASIC_Frame_03._c      /* 0x12"ASIC_Frame_03" */
    ,(canuint8*)ASIC_Frame_02._c      /* 0x11"ASIC_Frame_02" */
    ,(canuint8*)ASIC_Frame_01._c      /* 0x10"ASIC_Frame_01" */
    ,(canuint8*)FSdataEnhanced._c      /* 0x24"FSdataEnhanced" */
    ,(canuint8*)FSdata._c      /* 0x23"FSdata" */
    ,(canuint8*)SoSe._c      /* 0x32"SoSe" */
     (canuint8*)RLSData._c      /* 0x29"RLSData" */
};

canuint8* MEMORY_ROM capbLinRxDefaultDataPtrTbl[kLinNumberOfRxObjects] = {
    ,(canuint8*)LinReqCmd._c      /* 0x3C"LinReqCmd" */
    ,(canuint8*)ComToRLS._c      /* 0x26"ComToRLS" */
     (canuint8*)RLSCfgData._c      /* 0x1D"RLSCfgData" */
};
#endif

#ifdef NODECONFIGURATION
canuint8 rabRAMLinMsgIDToHandleTbl[0x40];
#pragma dataseg=default

canuint16 MEMORY_ROM cawLINMessageID[kLinNumberOfObjects] = {
    0           /* 0x3D"LinRespCmd" */
   ,0x1013      /* 0x13"ASIC_Frame_04" */
   ,0x1012      /* 0x12"ASIC_Frame_03" */
   ,0x1011      /* 0x11"ASIC_Frame_02" */
   ,0x1010      /* 0x10"ASIC_Frame_01" */
   ,0x0024      /* 0x24"FSdataEnhanced" */
   ,0x0023      /* 0x23"FSdata" */
   ,0x0032      /* 0x32"SoSe" */
   ,0x0029      /* 0x29"RLSData" */
   ,0          /* 0x3C"LinReqCmd" */
   ,0x0026     /* 0x26"ComToRLS" */
   ,0x001D     /* 0x1D"RLSCfgData" */
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
    ,0x0B      /* 0x1D"RLSCfgData" */
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x06      /* 0x23"FSdata" */
    ,0x05      /* 0x24"FSdataEnhanced" */
    ,0xff
    ,0x0A      /* 0x26"ComToRLS" */
    ,0xff
    ,0xff
    ,0x08      /* 0x29"RLSData" */
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x07      /* 0x32"SoSe" */
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0xff
    ,0x09      /* 0x3C"LinReqCmd" */
    ,0x00      /* 0x3D"LinRespCmd" */
    ,0xff
    ,0xff
};

#endif

/*************************************************************/
/* list of handles for all messages                              */
/*************************************************************/
canuint8 MEMORY_ROM cabLinMsgHandleTbl[kLinNumberOfObjects] = {
    0      /* 0x3D"LinRespCmd" */
   ,1      /* 0x13"ASIC_Frame_04" */
   ,2      /* 0x12"ASIC_Frame_03" */
   ,3      /* 0x11"ASIC_Frame_02" */
   ,4      /* 0x10"ASIC_Frame_01" */
   ,5      /* 0x24"FSdataEnhanced" */
   ,6      /* 0x23"FSdata" */
   ,7      /* 0x32"SoSe" */
   ,8      /* 0x29"RLSData" */
   ,0      /* 0x3C"LinReqCmd" */
   ,1      /* 0x26"ComToRLS" */
   ,2      /* 0x1D"RLSCfgData" */
};


#ifdef L_ENABLE_T_FRAME_MAX

canuint8 MEMORY_ROM cabLinMsgTimeoutTbl[kLinNumberOfRxObjects + kLinNumberOfTxObjects] = {
	 (kLinTFrame8 - kLinTHeaderMax)		/* id: 0x03D "LinRespCmd" */
	,(kLinTFrame4 - kLinTHeaderMax)		/* id: 0x029 "RLSData" */
	,(kLinTFrame8 - kLinTHeaderMax)		/* id: 0x03C "LinReqCmd" */
	,(kLinTFrame4 - kLinTHeaderMax)		/* id: 0x026 "ComToRLS" */
	,(kLinTFrame2 - kLinTHeaderMax)		/* id: 0x01D "RLSCfgData" */
};
#endif



