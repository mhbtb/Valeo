/**************************************************************
*  File d:\Temp\rls940.h
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

/* PRQA S 750,759,635 EOF */ /* <<union definition and bit fields are required>> */
/* PRQA S 3458,3412 EOF */ /* <<macro definion needed>> */
/* PRQA S 3410,3412 EOF */ /* <<Generated macro are OK >> */
/* PRQA S 2210 EOF */ /* <<Generated code and TAB are used to indent are OK >> */
/* PRQA S 2217 EOF */ /* <<line lenth exceeds 120 are OK >> */
/* PRQA S 857 EOF */ /* <<number of macro exceeds 1024 are OK >> */
/* PRQA S 602 EOF */ /* <<Generated code starts with underscore are OK >> */

#ifndef LIN_RLS_H
#define LIN_RLS_H

#define __RLS__

/* start skeleton LIN H-File ----------------------------------------*/


#define cb_HANDLE_LinRespCmd_g              0
#define cb_HANDLE_ASIC_Frame_04_g           1
#define cb_HANDLE_ASIC_Frame_03_g           2
#define cb_HANDLE_ASIC_Frame_02_g           3
#define cb_HANDLE_ASIC_Frame_01_g           4
#define cb_HANDLE_FSdataEnhanced_g          5
#define cb_HANDLE_FSs_01_g                  6 /* cb_HANDLE_FSdata_g */
#define cb_HANDLE_SoSes_01                  7 /* cb_HANDLE_SoSe_g */
#define cb_HANDLE_RLSs_01_g                 8 /* cb_HANDLE_RLSData_g */
#define cb_HANDLE_LinReqCmd_g               9
#define cb_HANDLE_BCM1_LIN1_01_g            10 /* cb_HANDLE_ComToRLS_g */
#define cb_HANDLE_WWSs_01_g                 11 /* cb_HANDLE_RLSCfgData_g */


extern MEMORY_ROM canuint8 cabLinRxDLCTbl[kLinNumberOfRxObjects];
extern canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects];
extern MEMORY_ROM canuint8 cabLinTxDataLenTbl[kLinNumberOfTxObjects];
extern canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects];
extern MEMORY_ROM canuint8 cabLinMsgIDToHandleTbl[0x40];
extern MEMORY_ROM canuint8 cabLinRxDataLenTbl[kLinNumberOfRxObjects];
extern MEMORY_ROM canuint8 cabLinRxDLCTbl[kLinNumberOfRxObjects];
extern canuint8 MEMORY_ROM cabLinMsgHandleTbl[kLinNumberOfObjects];

#ifdef NODECONFIGURATION
extern canuint8 rabRAMLinMsgIDToHandleTbl[0x40];
extern canuint16 MEMORY_ROM cawLINMessageID[kLinNumberOfObjects];
#else
extern MEMORY_ROM canuint8 cabLinMsgIDToHandleTbl[0x40];
#endif

/* end   skeleton LIN H-File ----------------------------------------*/


/*************************************************************/
/* Signal structures                                          */
/*************************************************************/

/* Send messages */

typedef struct {
	canbittype                    SlaveRespB0: 8;
	canbittype                    SlaveRespB1: 8;
	canbittype                    SlaveRespB2: 8;
	canbittype                    SlaveRespB3: 8;
	canbittype                    SlaveRespB4: 8;
	canbittype                    SlaveRespB5: 8;
	canbittype                    SlaveRespB6: 8;
	canbittype                    SlaveRespB7: 8;
} _c_LinRespCmd_msgType;

typedef struct {
	canbittype                        unused0: 3;
	canbittype             LightSensorFailSts: 1;
	canbittype              RainSensorFailSts: 1;
	canbittype            HeadLampsActivation: 1;
	canbittype                      WiperMode: 1;
	canbittype                   WiperSpeed_0: 1;
	canbittype                   WiperSpeed_1: 2;
	canbittype            LightSensorSelected: 1;
	canbittype             RainSensorSelected: 1;
	canbittype            ResponseErrorStsRLS: 1;
	canbittype              GenericFailStsRLS: 1;
	canbittype              CurrentFailStsRLS: 1;
	canbittype                   KeepAliveRLS: 1;
} _c_RLSData_msgType;

/* Receive messages */

typedef struct {
	canbittype                    MasterReqB0: 8;
	canbittype                    MasterReqB1: 8;
	canbittype                    MasterReqB2: 8;
	canbittype                    MasterReqB3: 8;
	canbittype                    MasterReqB4: 8;
	canbittype                    MasterReqB5: 8;
	canbittype                    MasterReqB6: 8;
	canbittype                    MasterReqB7: 8;
} _c_LinReqCmd_msgType;

typedef struct {
	canbittype                        unused0: 6;
	canbittype         SelectedSensitivityL_0: 2;
	canbittype         SelectedSensitivityL_1: 1;
	canbittype              LightSensorActive: 1;
	canbittype               RainSensorActive: 1;
	canbittype           SelectedSensitivityR: 3;
	canbittype              WiperWasherActive: 1;
	canbittype                    WiperInPark: 1;
	canbittype                 VehicleSpeed_0: 8;
	canbittype                 VehicleSpeed_1: 5;
	canbittype              GenericFailStsBCM: 1;
	canbittype              CurrentFailStsBCM: 1;
	canbittype                   KeepAliveBCM: 1;
} _c_ComToRLS_msgType;

typedef struct {
	canbittype                          unused0: 8;
	canbittype             FW_550nmTransmission: 4;
	canbittype             IR_880nmTransmission: 4;
} _c_RLSCfgData_msgType;

typedef struct {
  canbittype                               GlassTmp_0: 8;
  canbittype                               GlassTmp_1: 3;
  canbittype                           HumSns_Int_flt: 1;
  canbittype                            RsErr_HumSnsr: 1;
  canbittype                                  unused0: 3;
  canbittype                         HumidityAirTmp_0: 8;
  canbittype                         HumidityAirTmp_1: 3;
  canbittype                                  unused1: 5;
  canbittype                            DewpointTmp_0: 8;
  canbittype                            DewpointTmp_1: 3;
  canbittype                                  unused2: 5;
  canbittype                              RelHumidity: 8;
  canbittype                                  unused3: 8;
} _c_FSdataEnhanced_msgType;

typedef struct {
  canbittype                               GLASS_TEMP: 8;
  canbittype                          HumidityAirTemp: 8;
  canbittype                             DewpointTemp: 8;
  canbittype                             REL_HUMIDITY: 8;
  canbittype                           RsErr_HumSense: 1;
  canbittype                          Hum_Sns_Int_flt: 1;
  canbittype                                  unused0: 6;
} _c_FSdata_msgType;

typedef struct {
  canbittype                        SoSe_SunInt_2D_Li: 8;
  canbittype                        SoSe_SunInt_2D_Re: 8;
  canbittype                     rw_FW_light16bit_g_0: 8;
  canbittype                     rw_FW_light16bit_g_1: 8;
  canbittype                     rw_IR_light16bit_g_0: 8;
  canbittype                     rw_IR_light16bit_g_1: 8;
  canbittype                    rw_Amb_light16bit_g_0: 8;
  canbittype                    rw_Amb_light16bit_g_1: 8;
} _c_SoSe_msgType;


typedef struct {
  canbittype                     LIN_rw_Vref_ASIC_g_0: 8;
  canbittype                     LIN_rw_Vref_ASIC_g_1: 2;
  canbittype                     LIN_rw_VDDA_ASIC_g_0: 6;
  canbittype                     LIN_rw_VDDA_ASIC_g_1: 4;
  canbittype                     LIN_rw_VDDD_ASIC_g_0: 4;
  canbittype                     LIN_rw_VDDD_ASIC_g_1: 6;
  canbittype           LW_rw_VILO_ICALLO_GHI_ASIC_g_0: 2;
  canbittype           LW_rw_VILO_ICALLO_GHI_ASIC_g_1: 8;
  canbittype                  LIN_rw_REGV_Voltage_g_0: 8;
  canbittype                  LIN_rw_REGV_Voltage_g_1: 4;
  canbittype                                  unused0: 4;
  canbittype         LIN_rb_ASICReg_NoValidVals_cnt_g: 8;
} _c_ASIC_Frame_04_msgType;

typedef struct {
  canbittype            LIN_rw_Solar_light16bit_1_g_0: 8;
  canbittype            LIN_rw_Solar_light16bit_1_g_1: 8;
  canbittype            LIN_rw_Solar_light16bit_2_g_0: 8;
  canbittype            LIN_rw_Solar_light16bit_2_g_1: 8;
  canbittype                 LIN_rw_FW_light16bit_g_0: 8;
  canbittype                 LIN_rw_FW_light16bit_g_1: 8;
  canbittype                 LIN_rw_IR_light16bit_g_0: 8;
  canbittype                 LIN_rw_IR_light16bit_g_1: 8;
} _c_ASIC_Frame_03_msgType;

typedef struct {
  canbittype                 LIN_rw_INTV10bit_max_g_0: 8;
  canbittype                 LIN_rw_INTV10bit_max_g_1: 2;
  canbittype                 LIN_rw_INTV10bit_min_g_0: 6;
  canbittype                 LIN_rw_INTV10bit_min_g_1: 4;
  canbittype          LIN_rw_VICALLO_ILO_GHI_ASIC_g_0: 4;
  canbittype          LIN_rw_VICALLO_ILO_GHI_ASIC_g_1: 6;
  canbittype                    LIN_rw_VTEMP_ASIC_g_0: 2;
  canbittype                    LIN_rw_VTEMP_ASIC_g_1: 8;
  canbittype       LIN_rb_SPI_Active_ProblemCounter_g: 8;
  canbittype       LIN_rb_StaticHumTempErrorCounter_g: 8;
  canbittype                       LIN_rb_STATH_Reg_g: 8;
} _c_ASIC_Frame_02_msgType;

typedef struct {
  canbittype                  LIN_rb_SupplyVoltage_mg: 8;
  canbittype          LIN_rb_MaxLightSignalErrorCnt_g: 8;
  canbittype      LIN_rb_StaticNoCommunicationCounter: 8;
  canbittype                     LIN_rw_ALS2_ASIC_g_0: 8;
  canbittype                     LIN_rw_ALS2_ASIC_g_1: 2;
  canbittype                     LIN_rw_ALS5_ASIC_g_0: 6;
  canbittype                     LIN_rw_ALS5_ASIC_g_1: 4;
  canbittype                LIN_rw_Amb_light16bit_g_0: 4;
  canbittype                LIN_rw_Amb_light16bit_g_1: 6;
  canbittype                    LIN_rw_INREC_ASIC_g_0: 2;
  canbittype                    LIN_rw_INREC_ASIC_g_1: 8;
} _c_ASIC_Frame_01_msgType;


/*************************************************************/
/* Message unions              */
/*************************************************************/

/* Send messages */

typedef union {
	unsigned char _c[8];
   _c_LinRespCmd_msgType linrespcmd;
} _c_LinRespCmd_buf;

typedef union {
	unsigned char _c[2];
	_c_RLSData_msgType	rlsdata;
} _c_RLSData_buf;

typedef union {
    unsigned char _c[8];
    _c_FSdataEnhanced_msgType fsdataenhanced;
} _c_FSdataEnhanced_buf;

typedef union {
    unsigned char _c[5];
    _c_FSdata_msgType fsdata;
} _c_FSdata_buf;

typedef union {
    unsigned char _c[8];
    _c_SoSe_msgType sose;
} _c_SoSe_buf;

/* Receive messages */

typedef union {
	unsigned char _c[8];
   _c_LinReqCmd_msgType  linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
	unsigned char _c[4];
	_c_ComToRLS_msgType	comtorls;
} _c_ComToRLS_buf;

typedef union {
	unsigned char _c[2];
	_c_RLSCfgData_msgType	rlscfgdata;
} _c_RLSCfgData_buf;


typedef union {
    unsigned char _c[8];
    _c_ASIC_Frame_04_msgType asic_frame_04;
} _c_ASIC_Frame_04_buf;

typedef union {
    unsigned char _c[8];
    _c_ASIC_Frame_03_msgType asic_frame_03;
} _c_ASIC_Frame_03_buf;

typedef union {
    unsigned char _c[8];
    _c_ASIC_Frame_02_msgType asic_frame_02;
} _c_ASIC_Frame_02_buf;

typedef union {
    unsigned char _c[8];
    _c_ASIC_Frame_01_msgType asic_frame_01;
} _c_ASIC_Frame_01_buf;

/* Pretransmit functions */

/* Confirmation functions */


/* Precopy functions */


/* Indication functions */


/*************************************************************/
/* Databuffer for send objects                               */
/*************************************************************/
extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_FSdataEnhanced_buf FSdataEnhanced;
extern MEMORY_FAR _c_FSdata_buf FSdata;
extern MEMORY_FAR _c_SoSe_buf SoSe;
extern MEMORY_FAR _c_RLSData_buf RLSData;
/*************************************************************/
/* Byte access to databuffer of send objects                 */
/*************************************************************/
#define c1_LinRespCmd_c		LinRespCmd._c[0]
#define c2_LinRespCmd_c		LinRespCmd._c[1]
#define c3_LinRespCmd_c		LinRespCmd._c[2]
#define c4_LinRespCmd_c		LinRespCmd._c[3]
#define c5_LinRespCmd_c		LinRespCmd._c[4]
#define c6_LinRespCmd_c		LinRespCmd._c[5]
#define c7_LinRespCmd_c		LinRespCmd._c[6]
#define c8_LinRespCmd_c		LinRespCmd._c[7]

#define c1_RLSData_c		RLSData._c[0]
#define c2_RLSData_c		RLSData._c[1]


/*************************************************************/
/* Handles of send objects                                   */
/*************************************************************/

#define LinTxLinRespCmd	0
#define LinTxRLSData	1


/*************************************************************/
/* Databuffer for confirmationflags                          */
/*************************************************************/

#define LinRespCmd_conf_b             uLinConfirmationFlags.w[0].b0
#define l_flg_tst_LinRespCmd()       (LinRespCmd_conf_b != 0)
#define l_flg_clr_LinRespCmd()       {LinRespCmd_conf_b = 0;}
#define ASIC_Frame_04_conf_b             uLinConfirmationFlags.w[0].b1
#define l_flg_tst_ASIC_Frame_04()       (ASIC_Frame_04_conf_b != 0)
#define l_flg_clr_ASIC_Frame_04()       {ASIC_Frame_04_conf_b = 0;}
#define ASIC_Frame_03_conf_b             uLinConfirmationFlags.w[0].b2
#define l_flg_tst_ASIC_Frame_03()       (ASIC_Frame_03_conf_b != 0)
#define l_flg_clr_ASIC_Frame_03()       {ASIC_Frame_03_conf_b = 0;}
#define ASIC_Frame_02_conf_b             uLinConfirmationFlags.w[0].b3
#define l_flg_tst_ASIC_Frame_02()       (ASIC_Frame_02_conf_b != 0)
#define l_flg_clr_ASIC_Frame_02()       {ASIC_Frame_02_conf_b = 0;}
#define ASIC_Frame_01_conf_b             uLinConfirmationFlags.w[0].b4
#define l_flg_tst_ASIC_Frame_01()       (ASIC_Frame_01_conf_b != 0)
#define l_flg_clr_ASIC_Frame_01()       {ASIC_Frame_01_conf_b = 0;}
#define FSdataEnhanced_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_FSdataEnhanced()       (FSdataEnhanced_conf_b != 0)
#define l_flg_clr_FSdataEnhanced()       {FSdataEnhanced_conf_b = 0;}
#define FSdata_conf_b             uLinConfirmationFlags.w[0].b6
#define l_flg_tst_FSdata()       (FSdata_conf_b != 0)
#define l_flg_clr_FSdata()       {FSdata_conf_b = 0;}
#define SoSe_conf_b             uLinConfirmationFlags.w[0].b7
#define l_flg_tst_SoSe()       (SoSe_conf_b != 0)
#define l_flg_clr_SoSe()       {SoSe_conf_b = 0;}
#define RLSData_conf_b             uLinConfirmationFlags.w[0].b8
#define l_flg_tst_RLSData()       (RLSData_conf_b != 0)
#define l_flg_clr_RLSData()       {RLSData_conf_b = 0;}


/*************************************************************/
/* Databuffer for receive objects                            */
/*************************************************************/
extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_ComToRLS_buf ComToRLS;
extern MEMORY_FAR _c_RLSCfgData_buf RLSCfgData;



/*************************************************************/
/* Handles of  receive objects                               */
/*************************************************************/

#define LinRxLinReqCmd	2
#define LinRxComToRLS	3
#define LinRxRLSCfgData	4


/*************************************************************/
/* Databuffer for indicationflags                                */
/*************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define ComToRLS_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_ComToRLS()       (ComToRLS_ind_b != 0)
#define l_flg_clr_ComToRLS()       {ComToRLS_ind_b = 0;}
#define RLSCfgData_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_RLSDCfgData()       (RLSCfgData_ind_b != 0)
#define l_flg_clr_RLSDCfgData()       {RLSCfgData_ind_b = 0;}


/*************************************************************/
/* Signals of send messages                                  */
/*************************************************************/

#define SlaveRespB0                                                  LinRespCmd.linrespcmd.SlaveRespB0
#define SlaveRespB1                                                  LinRespCmd.linrespcmd.SlaveRespB1
#define SlaveRespB2                                                  LinRespCmd.linrespcmd.SlaveRespB2
#define SlaveRespB3                                                  LinRespCmd.linrespcmd.SlaveRespB3
#define SlaveRespB4                                                  LinRespCmd.linrespcmd.SlaveRespB4
#define SlaveRespB5                                                  LinRespCmd.linrespcmd.SlaveRespB5
#define SlaveRespB6                                                  LinRespCmd.linrespcmd.SlaveRespB6
#define SlaveRespB7                                                  LinRespCmd.linrespcmd.SlaveRespB7

#define l_u8_rd_SlaveRespB0()                                      SlaveRespB0
#define l_u8_wr_SlaveRespB0(a)                                     {SlaveRespB0 = a;}
#define l_u8_rd_SlaveRespB1()                                      SlaveRespB1
#define l_u8_wr_SlaveRespB1(a)                                     {SlaveRespB1 = a;}
#define l_u8_rd_SlaveRespB2()                                      SlaveRespB2
#define l_u8_wr_SlaveRespB2(a)                                     {SlaveRespB2 = a;}
#define l_u8_rd_SlaveRespB3()                                      SlaveRespB3
#define l_u8_wr_SlaveRespB3(a)                                     {SlaveRespB3 = a;}
#define l_u8_rd_SlaveRespB4()                                      SlaveRespB4
#define l_u8_wr_SlaveRespB4(a)                                     {SlaveRespB4 = a;}
#define l_u8_rd_SlaveRespB5()                                      SlaveRespB5
#define l_u8_wr_SlaveRespB5(a)                                     {SlaveRespB5 = a;}
#define l_u8_rd_SlaveRespB6()                                      SlaveRespB6
#define l_u8_wr_SlaveRespB6(a)                                     {SlaveRespB6 = a;}
#define l_u8_rd_SlaveRespB7()                                      SlaveRespB7
#define l_u8_wr_SlaveRespB7(a)                                     {SlaveRespB7 = a;}


#define WiperSpeed_0                                                 RLSData.rlsdata.WiperSpeed_0
#define WiperSpeed_1                                                 RLSData.rlsdata.WiperSpeed_1
#define WiperSpeed(c)                                                { WiperSpeed_0 = (uint8)(((uint16)(c) & 0x1));\
                                                                       WiperSpeed_1 = (uint8)(((uint16)(c) & 0x1fe) >> 1);\
                                                                     }
#define LightSensorSelected                                          RLSData.rlsdata.LightSensorSelected
#define RainSensorSelected                                           RLSData.rlsdata.RainSensorSelected
#define ResponseErrorStsRLS                                          RLSData.rlsdata.ResponseErrorStsRLS
#define GenericFailStsRLS                                            RLSData.rlsdata.GenericFailStsRLS
#define CurrentFailStsRLS                                            RLSData.rlsdata.CurrentFailStsRLS
#define KeepAliveRLS                                                 RLSData.rlsdata.KeepAliveRLS
/*#define TwilightSensorLevel_0                                       RLSData.rlsdata.TwilightSensorLevel_0
#define TwilightSensorLevel_1                                       RLSData.rlsdata.TwilightSensorLevel_1*/
/*#define TwilightSensorLevel(c)                                       { TwilightSensorLevel_0 = (uint8)(((uint16)(c) & 0x3));\
                                                                       TwilightSensorLevel_1 = (uint8)(((uint16)(c) & 0x3fc) >> 2);\
                                                                     }*/
#define HeadLampsActivation                                          RLSData.rlsdata.HeadLampsActivation
#define WiperMode                                                    RLSData.rlsdata.WiperMode
#define LightSensorFailSts                                           RLSData.rlsdata.LightSensorFailSts
#define RainSensorFailSts                                            RLSData.rlsdata.RainSensorFailSts


#define l_u8_rd_WiperSpeed()                                        (canuint16)(((canuint16)(WiperSpeed_1) << 1)\
                                                                  | (WiperSpeed_0))
#define l_u8_wr_WiperSpeed(a)                                       {WiperSpeed_0  = ((canuint8)(a & 0x01));\
                                                                     WiperSpeed_1 = ((canuint8)((a >>1) & 0x03));}
/*#define l_u8_wr_WiperSpeed(a)                                       {WiperSpeed_1 = ((canuint8)(a >> 1));\
                                                                  WiperSpeed_0 = ((canuint8)a);}*/

#define l_bool_rd_LightSensorSelected()                            LightSensorSelected
#define l_bool_wr_LightSensorSelected(a)                           {LightSensorSelected = a;}
#define l_bool_rd_RainSensorSelected()                             RainSensorSelected
#define l_bool_wr_RainSensorSelected(a)                            {RainSensorSelected = a;}
#define l_bool_rd_ResponseErrorStsRLS()                              ResponseErrorStsRLS
#define l_bool_wr_ResponseErrorStsRLS(a)                             {ResponseErrorStsRLS = a;}
#define l_bool_rd_RLSGenericFailSts()                              GenericFailStsRLS
#define l_bool_wr_RLSGenericFailSts(a)                             {GenericFailStsRLS = a;}
#define l_bool_rd_RLSCurrentFailSts()                              CurrentFailStsRLS
#define l_bool_wr_RLSCurrentFailSts(a)                             {CurrentFailStsRLS = a;}
#define l_bool_rd_KeepAliveRLS()                                   KeepAliveRLS
#define l_bool_wr_KeepAliveRLS(a)                                  {KeepAliveRLS = a;}
/*#define l_u8_rd_TwilightSensorLevel()                               (canuint16)(((canuint16)(TwilightSensorLevel_1) << 3)\
                                                                  | (TwilightSensorLevel_0))
#define l_u8_wr_TwilightSensorLevel(a)                              {TwilightSensorLevel_1 = ((canuint8)(a >> 3));\
                                                                  TwilightSensorLevel_0 = ((canuint8)a);}*/
#define l_bool_rd_HeadLampsActivation()                            HeadLampsActivation
#define l_bool_wr_HeadLampsActivation(a)                           {HeadLampsActivation = a;}
#define l_bool_rd_WiperMode()                                      WiperMode
#define l_bool_wr_WiperMode(a)                                     {WiperMode = a;}
#define l_bool_rd_LightSensorFailSts()                             LightSensorFailSts
#define l_bool_wr_LightSensorFailSts(a)                            {LightSensorFailSts = a;}
#define l_bool_rd_RainSensorFailSts()                              RainSensorFailSts
#define l_bool_wr_RainSensorFailSts(a)                             {RainSensorFailSts = a;}

/*************************************************************/
/* Signals of receive messages                               */
/*************************************************************/

#define MasterReqB0                                                  LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                  LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                  LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                  LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                  LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                  LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                  LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                  LinReqCmd.linreqcmd.MasterReqB7

#define l_u8_rd_MasterReqB0()                                      MasterReqB0
#define l_u8_wr_MasterReqB0(a)                                     {MasterReqB0 = a;}
#define l_u8_rd_MasterReqB1()                                      MasterReqB1
#define l_u8_wr_MasterReqB1(a)                                     {MasterReqB1 = a;}
#define l_u8_rd_MasterReqB2()                                      MasterReqB2
#define l_u8_wr_MasterReqB2(a)                                     {MasterReqB2 = a;}
#define l_u8_rd_MasterReqB3()                                      MasterReqB3
#define l_u8_wr_MasterReqB3(a)                                     {MasterReqB3 = a;}
#define l_u8_rd_MasterReqB4()                                      MasterReqB4
#define l_u8_wr_MasterReqB4(a)                                     {MasterReqB4 = a;}
#define l_u8_rd_MasterReqB5()                                      MasterReqB5
#define l_u8_wr_MasterReqB5(a)                                     {MasterReqB5 = a;}
#define l_u8_rd_MasterReqB6()                                      MasterReqB6
#define l_u8_wr_MasterReqB6(a)                                     {MasterReqB6 = a;}
#define l_u8_rd_MasterReqB7()                                      MasterReqB7
#define l_u8_wr_MasterReqB7(a)                                     {MasterReqB7 = a;}

#define VehicleSpeed_0                                              ComToRLS.comtorls.VehicleSpeed_0
#define VehicleSpeed_1                                              ComToRLS.comtorls.VehicleSpeed_1
#define VehicleSpeed                                                (uint16)(((uint16)(VehicleSpeed_1) << 8)\
                                                                  | (VehicleSpeed_0))
#define BCMGenericFailSts                                            ComToRLS.comtorls.GenericFailStsBCM
#define BCMCurrentFailSts                                            ComToRLS.comtorls.CurrentFailStsBCM
#define KeepAliveBCM                                                 ComToRLS.comtorls.KeepAliveBCM
#define SelectedSensitivityL_0                                      ComToRLS.comtorls.SelectedSensitivityL_0
#define SelectedSensitivityL_1                                      ComToRLS.comtorls.SelectedSensitivityL_1
#define SelectedSensitivityL                                        (uint16)(((uint16)(SelectedSensitivityL_1) << 2)\
                                                                  | (SelectedSensitivityL_0))
#define LightSensorActive                                            ComToRLS.comtorls.LightSensorActive
#define RainSensorActive                                             ComToRLS.comtorls.RainSensorActive
#define SelectedSensitivityR                                         ComToRLS.comtorls.SelectedSensitivityR
#define WiperWasherActive                                            ComToRLS.comtorls.WiperWasherActive
#define WiperInPark                                                  ComToRLS.comtorls.WiperInPark

#define FW_550nmTransmission                                           RLSCfgData.rlscfgdata.FW_550nmTransmission
#define IR_880nmTransmission                                           RLSCfgData.rlscfgdata.IR_880nmTransmission


#define GlassTmp_0                                                            FSdataEnhanced.fsdataenhanced.GlassTmp_0
#define GlassTmp_1                                                            FSdataEnhanced.fsdataenhanced.GlassTmp_1
#define GlassTmp(c)                                                           { GlassTmp_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                GlassTmp_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define HumSns_Int_flt                                                        FSdataEnhanced.fsdataenhanced.HumSns_Int_flt
#define RsErr_HumSnsr                                                         FSdataEnhanced.fsdataenhanced.RsErr_HumSnsr
#define HumidityAirTmp_0                                                      FSdataEnhanced.fsdataenhanced.HumidityAirTmp_0
#define HumidityAirTmp_1                                                      FSdataEnhanced.fsdataenhanced.HumidityAirTmp_1
#define HumidityAirTmp(c)                                                     { HumidityAirTmp_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                HumidityAirTmp_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define DewpointTmp_0                                                         FSdataEnhanced.fsdataenhanced.DewpointTmp_0
#define DewpointTmp_1                                                         FSdataEnhanced.fsdataenhanced.DewpointTmp_1
#define DewpointTmp(c)                                                        { DewpointTmp_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                DewpointTmp_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define RelHumidity                                                           FSdataEnhanced.fsdataenhanced.RelHumidity




#define GLASS_TEMP                                                            FSdata.fsdata.GLASS_TEMP
#define HumidityAirTemp                                                       FSdata.fsdata.HumidityAirTemp
#define DewpointTemp                                                          FSdata.fsdata.DewpointTemp
#define REL_HUMIDITY                                                          FSdata.fsdata.REL_HUMIDITY
#define RsErr_HumSense                                                        FSdata.fsdata.RsErr_HumSense
#define Hum_Sns_Int_flt                                                       FSdata.fsdata.Hum_Sns_Int_flt
#define SoSe_SunInt_2D_Li                                                     SoSe.sose.SoSe_SunInt_2D_Li
#define SoSe_SunInt_2D_Re                                                     SoSe.sose.SoSe_SunInt_2D_Re
#define rw_FW_light16bit_g_0                                                  SoSe.sose.rw_FW_light16bit_g_0
#define rw_FW_light16bit_g_1                                                  SoSe.sose.rw_FW_light16bit_g_1
#define rw_FW_light16bit_g(c)                                                 { rw_FW_light16bit_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                rw_FW_light16bit_g_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define rw_IR_light16bit_g_0                                                  SoSe.sose.rw_IR_light16bit_g_0
#define rw_IR_light16bit_g_1                                                  SoSe.sose.rw_IR_light16bit_g_1
#define rw_IR_light16bit_g(c)                                                 { rw_IR_light16bit_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                rw_IR_light16bit_g_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define rw_Amb_light16bit_g_0                                                 SoSe.sose.rw_Amb_light16bit_g_0
#define rw_Amb_light16bit_g_1                                                 SoSe.sose.rw_Amb_light16bit_g_1
#define rw_Amb_light16bit_g(c)                                                { rw_Amb_light16bit_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                rw_Amb_light16bit_g_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }

#define l_u16_rd_VehicleSpeed()                                     (canuint16)(((canuint16)(VehicleSpeed_1) << 8)\
                                                                  | (VehicleSpeed_0))
#define l_u16_wr_VehicleSpeed(a)                                    {VehicleSpeed_1 = ((canuint8)(a >> 8));\
                                                                  VehicleSpeed_0 = ((canuint8)a);}
#define l_bool_rd_BCMGenericFailSts()                              BCMGenericFailSts
#define l_bool_wr_BCMGenericFailSts(a)                             {BCMGenericFailSts = a;}
#define l_bool_rd_BCMCurrentFailSts()                              BCMCurrentFailSts
#define l_bool_wr_BCMCurrentFailSts(a)                             {BCMCurrentFailSts = a;}
#define l_bool_rd_KeepAliveBCM()                                   KeepAliveBCM
#define l_bool_wr_KeepAliveBCM(a)                                  {KeepAliveBCM = a;}
#define l_u8_rd_SelectedSensitivityL()                              (canuint16)(((canuint16)(SelectedSensitivityL_1) << 2)\
                                                                  | (SelectedSensitivityL_0))
#define l_u8_wr_SelectedSensitivityL(a)                             {SelectedSensitivityL_1 = ((canuint8)(a >> 2));\
                                                                  SelectedSensitivityL_0 = ((canuint8)a);}
#define l_bool_rd_LightSensorActive()                              LightSensorActive
#define l_bool_wr_LightSensorActive(a)                             {LightSensorActive = a;}
#define l_bool_rd_RainSensorActive()                               RainSensorActive
#define l_bool_wr_RainSensorActive(a)                              {RainSensorActive = a;}
#define l_u8_rd_SelectedSensitivityR()                             SelectedSensitivityR
#define l_u8_wr_SelectedSensitivityR(a)                            {SelectedSensitivityR = a;}
#define l_bool_rd_WiperWasherActive()                              WiperWasherActive
#define l_bool_wr_WiperWasherActive(a)                             {WiperWasherActive = a;}
#define l_bool_rd_WiperInPark()                                    WiperInPark
#define l_bool_wr_WiperInPark(a)                                   {WiperInPark = a;}

#define l_u8_rd_FW_550nmTransmission()                               FW_550nmTransmission
#define l_u8_wr_FW_550nmTransmission(a)                              {FW_550nmTransmission = a;}
#define l_u8_rd_IR_880nmTransmission()                               IR_880nmTransmission
#define l_u8_wr_IR_880nmTransmission(a)                              {IR_880nmTransmission = a;}

#define l_u16_rd_GlassTmp()                                                   (canuint16)(GlassTmp_0)\
                                                                                | ((canuint16)(GlassTmp_1)<<8)
#define l_u16_wr_GlassTmp(a)                                                  {GlassTmp_0 = ((canuint8)(a));\
                                                                                 GlassTmp_1 = ((canuint8)((a)>>8));}
#define l_bool_rd_HumSns_Int_flt()                                              HumSns_Int_flt
#define l_bool_wr_HumSns_Int_flt(a)                                             {HumSns_Int_flt = a;}
#define l_bool_rd_RsErr_HumSnsr()                                               RsErr_HumSnsr
#define l_bool_wr_RsErr_HumSnsr(a)                                              {RsErr_HumSnsr = a;}
#define l_u16_rd_HumidityAirTmp()                                             (canuint16)(HumidityAirTmp_0)\
                                                                                | ((canuint16)(HumidityAirTmp_1)<<8)
#define l_u16_wr_HumidityAirTmp(a)                                            {HumidityAirTmp_0 = ((canuint8)(a));\
                                                                                 HumidityAirTmp_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_DewpointTmp()                                                (canuint16)(DewpointTmp_0)\
                                                                                | ((canuint16)(DewpointTmp_1)<<8)
#define l_u16_wr_DewpointTmp(a)                                               {DewpointTmp_0 = ((canuint8)(a));\
                                                                                 DewpointTmp_1 = ((canuint8)((a)>>8));}
#define l_u8_rd_RelHumidity()                                               RelHumidity
#define l_u8_wr_RelHumidity(a)                                              {RelHumidity = a;}

#define l_u8_rd_GLASS_TEMP()                                                GLASS_TEMP
#define l_u8_wr_GLASS_TEMP(a)                                               {GLASS_TEMP = (a);}
#define l_u8_rd_HumidityAirTemp()                                           HumidityAirTemp
#define l_u8_wr_HumidityAirTemp(a)                                          {HumidityAirTemp = (a);}
#define l_u8_rd_DewpointTemp()                                              DewpointTemp
#define l_u8_wr_DewpointTemp(a)                                             {DewpointTemp = (a);}
#define l_u8_rd_REL_HUMIDITY()                                              REL_HUMIDITY
#define l_u8_wr_REL_HUMIDITY(a)                                             {REL_HUMIDITY = (a);}
#define l_bool_rd_RsErr_HumSense()                                              RsErr_HumSense
#define l_bool_wr_RsErr_HumSense(a)                                             {RsErr_HumSense = (a);}
#define l_bool_rd_Hum_Sns_Int_flt()                                             Hum_Sns_Int_flt
#define l_bool_wr_Hum_Sns_Int_flt(a)                                            {Hum_Sns_Int_flt = (a);}
#define l_u8_rd_SoSe_SunInt_2D_Li()                                         SoSe_SunInt_2D_Li
#define l_u8_wr_SoSe_SunInt_2D_Li(a)                                        {SoSe_SunInt_2D_Li = (a);}
#define l_u8_rd_SoSe_SunInt_2D_Re()                                         SoSe_SunInt_2D_Re
#define l_u8_wr_SoSe_SunInt_2D_Re(a)                                        {SoSe_SunInt_2D_Re = (a);}
#define l_u16_rd_rw_FW_light16bit_g()                                         (canuint16)(rw_FW_light16bit_g_0)\
                                                                                | ((canuint16)(rw_FW_light16bit_g_1)<<8)
#define l_u16_wr_rw_FW_light16bit_g(a)                                        {rw_FW_light16bit_g_0 = ((canuint8)(a));\
                                                                                 rw_FW_light16bit_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_rw_IR_light16bit_g()                                         (canuint16)(rw_IR_light16bit_g_0)\
                                                                                | ((canuint16)(rw_IR_light16bit_g_1)<<8)
#define l_u16_wr_rw_IR_light16bit_g(a)                                        {rw_IR_light16bit_g_0 = ((canuint8)(a));\
                                                                                 rw_IR_light16bit_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_rw_Amb_light16bit_g()                                        (canuint16)(rw_Amb_light16bit_g_0)\
                                                                                | ((canuint16)(rw_Amb_light16bit_g_1)<<8)
#define l_u16_wr_rw_Amb_light16bit_g(a)                                       {rw_Amb_light16bit_g_0 = ((canuint8)(a));\
                                                                                 rw_Amb_light16bit_g_1 = ((canuint8)((a)>>8));}
																				 
#define LIN_rw_Vref_ASIC_g_0                                                  ASIC_Frame_04.asic_frame_04.LIN_rw_Vref_ASIC_g_0
#define LIN_rw_Vref_ASIC_g_1                                                  ASIC_Frame_04.asic_frame_04.LIN_rw_Vref_ASIC_g_1
#define LIN_rw_Vref_ASIC_g(c)                                                 { LIN_rw_Vref_ASIC_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_Vref_ASIC_g_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define LIN_rw_VDDA_ASIC_g_0                                                  ASIC_Frame_04.asic_frame_04.LIN_rw_VDDA_ASIC_g_0
#define LIN_rw_VDDA_ASIC_g_1                                                  ASIC_Frame_04.asic_frame_04.LIN_rw_VDDA_ASIC_g_1
#define LIN_rw_VDDA_ASIC_g(c)                                                 { LIN_rw_VDDA_ASIC_g_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                LIN_rw_VDDA_ASIC_g_1= (uint8)(((uint16)(c) & 0x0F) >> 6);\
                                                                              }
#define LIN_rw_VDDD_ASIC_g_0                                                  ASIC_Frame_04.asic_frame_04.LIN_rw_VDDD_ASIC_g_0
#define LIN_rw_VDDD_ASIC_g_1                                                  ASIC_Frame_04.asic_frame_04.LIN_rw_VDDD_ASIC_g_1
#define LIN_rw_VDDD_ASIC_g(c)                                                 { LIN_rw_VDDD_ASIC_g_0= (uint8)(((uint16)(c) & 0x0F));\
                                                                                LIN_rw_VDDD_ASIC_g_1= (uint8)(((uint16)(c) & 0x3F) >> 4);\
                                                                              }
#define LW_rw_VILO_ICALLO_GHI_ASIC_g_0                                        ASIC_Frame_04.asic_frame_04.LW_rw_VILO_ICALLO_GHI_ASIC_g_0
#define LW_rw_VILO_ICALLO_GHI_ASIC_g_1                                        ASIC_Frame_04.asic_frame_04.LW_rw_VILO_ICALLO_GHI_ASIC_g_1
#define LW_rw_VILO_ICALLO_GHI_ASIC_g(c)                                       { LW_rw_VILO_ICALLO_GHI_ASIC_g_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                LW_rw_VILO_ICALLO_GHI_ASIC_g_1= (uint8)(((uint16)(c) & 0xFF) >> 2);\
                                                                              }
#define LIN_rw_REGV_Voltage_g_0                                               ASIC_Frame_04.asic_frame_04.LIN_rw_REGV_Voltage_g_0
#define LIN_rw_REGV_Voltage_g_1                                               ASIC_Frame_04.asic_frame_04.LIN_rw_REGV_Voltage_g_1
#define LIN_rw_REGV_Voltage_g(c)                                              { LIN_rw_REGV_Voltage_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_REGV_Voltage_g_1= (uint8)(((uint16)(c) & 0x0F) >> 8);\
                                                                              }
#define LIN_rb_ASICReg_NoValidVals_cnt_g                                      ASIC_Frame_04.asic_frame_04.LIN_rb_ASICReg_NoValidVals_cnt_g
#define LIN_rw_Solar_light16bit_1_g_0                                         ASIC_Frame_03.asic_frame_03.LIN_rw_Solar_light16bit_1_g_0
#define LIN_rw_Solar_light16bit_1_g_1                                         ASIC_Frame_03.asic_frame_03.LIN_rw_Solar_light16bit_1_g_1
#define LIN_rw_Solar_light16bit_1_g(c)                                        { LIN_rw_Solar_light16bit_1_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_Solar_light16bit_1_g_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define LIN_rw_Solar_light16bit_2_g_0                                         ASIC_Frame_03.asic_frame_03.LIN_rw_Solar_light16bit_2_g_0
#define LIN_rw_Solar_light16bit_2_g_1                                         ASIC_Frame_03.asic_frame_03.LIN_rw_Solar_light16bit_2_g_1
#define LIN_rw_Solar_light16bit_2_g(c)                                        { LIN_rw_Solar_light16bit_2_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_Solar_light16bit_2_g_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define LIN_rw_FW_light16bit_g_0                                              ASIC_Frame_03.asic_frame_03.LIN_rw_FW_light16bit_g_0
#define LIN_rw_FW_light16bit_g_1                                              ASIC_Frame_03.asic_frame_03.LIN_rw_FW_light16bit_g_1
#define LIN_rw_FW_light16bit_g(c)                                             { LIN_rw_FW_light16bit_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_FW_light16bit_g_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define LIN_rw_IR_light16bit_g_0                                              ASIC_Frame_03.asic_frame_03.LIN_rw_IR_light16bit_g_0
#define LIN_rw_IR_light16bit_g_1                                              ASIC_Frame_03.asic_frame_03.LIN_rw_IR_light16bit_g_1
#define LIN_rw_IR_light16bit_g(c)                                             { LIN_rw_IR_light16bit_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_IR_light16bit_g_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define LIN_rw_INTV10bit_max_g_0                                              ASIC_Frame_02.asic_frame_02.LIN_rw_INTV10bit_max_g_0
#define LIN_rw_INTV10bit_max_g_1                                              ASIC_Frame_02.asic_frame_02.LIN_rw_INTV10bit_max_g_1
#define LIN_rw_INTV10bit_max_g(c)                                             { LIN_rw_INTV10bit_max_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_INTV10bit_max_g_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define LIN_rw_INTV10bit_min_g_0                                              ASIC_Frame_02.asic_frame_02.LIN_rw_INTV10bit_min_g_0
#define LIN_rw_INTV10bit_min_g_1                                              ASIC_Frame_02.asic_frame_02.LIN_rw_INTV10bit_min_g_1
#define LIN_rw_INTV10bit_min_g(c)                                             { LIN_rw_INTV10bit_min_g_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                LIN_rw_INTV10bit_min_g_1= (uint8)(((uint16)(c) & 0x0F) >> 6);\
                                                                              }
#define LIN_rw_VICALLO_ILO_GHI_ASIC_g_0                                       ASIC_Frame_02.asic_frame_02.LIN_rw_VICALLO_ILO_GHI_ASIC_g_0
#define LIN_rw_VICALLO_ILO_GHI_ASIC_g_1                                       ASIC_Frame_02.asic_frame_02.LIN_rw_VICALLO_ILO_GHI_ASIC_g_1
#define LIN_rw_VICALLO_ILO_GHI_ASIC_g(c)                                      { LIN_rw_VICALLO_ILO_GHI_ASIC_g_0= (uint8)(((uint16)(c) & 0x0F));\
                                                                                LIN_rw_VICALLO_ILO_GHI_ASIC_g_1= (uint8)(((uint16)(c) & 0x3F) >> 4);\
                                                                              }
#define LIN_rw_VTEMP_ASIC_g_0                                                 ASIC_Frame_02.asic_frame_02.LIN_rw_VTEMP_ASIC_g_0
#define LIN_rw_VTEMP_ASIC_g_1                                                 ASIC_Frame_02.asic_frame_02.LIN_rw_VTEMP_ASIC_g_1
#define LIN_rw_VTEMP_ASIC_g(c)                                                { LIN_rw_VTEMP_ASIC_g_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                LIN_rw_VTEMP_ASIC_g_1= (uint8)(((uint16)(c) & 0xFF) >> 2);\
                                                                              }
#define LIN_rb_SPI_Active_ProblemCounter_g                                    ASIC_Frame_02.asic_frame_02.LIN_rb_SPI_Active_ProblemCounter_g
#define LIN_rb_StaticHumTempErrorCounter_g                                    ASIC_Frame_02.asic_frame_02.LIN_rb_StaticHumTempErrorCounter_g
#define LIN_rb_STATH_Reg_g                                                    ASIC_Frame_02.asic_frame_02.LIN_rb_STATH_Reg_g
#define LIN_rb_SupplyVoltage_mg                                               ASIC_Frame_01.asic_frame_01.LIN_rb_SupplyVoltage_mg
#define LIN_rb_MaxLightSignalErrorCnt_g                                       ASIC_Frame_01.asic_frame_01.LIN_rb_MaxLightSignalErrorCnt_g
#define LIN_rb_StaticNoCommunicationCounter                                   ASIC_Frame_01.asic_frame_01.LIN_rb_StaticNoCommunicationCounter
#define LIN_rw_ALS2_ASIC_g_0                                                  ASIC_Frame_01.asic_frame_01.LIN_rw_ALS2_ASIC_g_0
#define LIN_rw_ALS2_ASIC_g_1                                                  ASIC_Frame_01.asic_frame_01.LIN_rw_ALS2_ASIC_g_1
#define LIN_rw_ALS2_ASIC_g(c)                                                 { LIN_rw_ALS2_ASIC_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_ALS2_ASIC_g_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define LIN_rw_ALS5_ASIC_g_0                                                  ASIC_Frame_01.asic_frame_01.LIN_rw_ALS5_ASIC_g_0
#define LIN_rw_ALS5_ASIC_g_1                                                  ASIC_Frame_01.asic_frame_01.LIN_rw_ALS5_ASIC_g_1
#define LIN_rw_ALS5_ASIC_g(c)                                                 { LIN_rw_ALS5_ASIC_g_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                LIN_rw_ALS5_ASIC_g_1= (uint8)(((uint16)(c) & 0x0F) >> 6);\
                                                                              }
#define LIN_rw_Amb_light16bit_g_0                                             ASIC_Frame_01.asic_frame_01.LIN_rw_Amb_light16bit_g_0
#define LIN_rw_Amb_light16bit_g_1                                             ASIC_Frame_01.asic_frame_01.LIN_rw_Amb_light16bit_g_1
#define LIN_rw_Amb_light16bit_g(c)                                            { LIN_rw_Amb_light16bit_g_0= (uint8)(((uint16)(c) & 0x0F));\
                                                                                LIN_rw_Amb_light16bit_g_1= (uint8)(((uint16)(c) & 0x3F) >> 4);\
                                                                              }
#define LIN_rw_INREC_ASIC_g_0                                                 ASIC_Frame_01.asic_frame_01.LIN_rw_INREC_ASIC_g_0
#define LIN_rw_INREC_ASIC_g_1                                                 ASIC_Frame_01.asic_frame_01.LIN_rw_INREC_ASIC_g_1
#define LIN_rw_INREC_ASIC_g(c)                                                { LIN_rw_INREC_ASIC_g_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                LIN_rw_INREC_ASIC_g_1= (uint8)(((uint16)(c) & 0xFF) >> 2);\
                                                                              }
#define l_u16_rd_LIN_rw_Vref_ASIC_g()                                         (canuint16)(LIN_rw_Vref_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_Vref_ASIC_g_1)<<8)
#define l_u16_wr_LIN_rw_Vref_ASIC_g(a)                                        {LIN_rw_Vref_ASIC_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_Vref_ASIC_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_LIN_rw_VDDA_ASIC_g()                                         (canuint16)(LIN_rw_VDDA_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VDDA_ASIC_g_1)<<6)
#define l_u16_wr_LIN_rw_VDDA_ASIC_g(a)                                        {LIN_rw_VDDA_ASIC_g_0 = ((canuint8)((a) & 0x3F));\
                                                                                 LIN_rw_VDDA_ASIC_g_1 = ((canuint8)((a)>>6));}
#define l_u16_rd_LIN_rw_VDDD_ASIC_g()                                         (canuint16)(LIN_rw_VDDD_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VDDD_ASIC_g_1)<<4)
#define l_u16_wr_LIN_rw_VDDD_ASIC_g(a)                                        {LIN_rw_VDDD_ASIC_g_0 = ((canuint8)((a) & 0x0F));\
                                                                                 LIN_rw_VDDD_ASIC_g_1 = ((canuint8)((a)>>4));}
#define l_u16_rd_LW_rw_VILO_ICALLO_GHI_ASIC_g()                               (canuint16)(LW_rw_VILO_ICALLO_GHI_ASIC_g_0)\
                                                                                | ((canuint16)(LW_rw_VILO_ICALLO_GHI_ASIC_g_1)<<2)
#define l_u16_wr_LW_rw_VILO_ICALLO_GHI_ASIC_g(a)                              {LW_rw_VILO_ICALLO_GHI_ASIC_g_0 = ((canuint8)(a));\
                                                                                 LW_rw_VILO_ICALLO_GHI_ASIC_g_1 = ((canuint8)((a)>>2));}
#define l_u16_rd_LIN_rw_REGV_Voltage_g()                                      (canuint16)(LIN_rw_REGV_Voltage_g_0)\
                                                                                | ((canuint16)(LIN_rw_REGV_Voltage_g_1)<<8)
#define l_u16_wr_LIN_rw_REGV_Voltage_g(a)                                     {LIN_rw_REGV_Voltage_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_REGV_Voltage_g_1 = ((canuint8)((a)>>8));}
#define l_u8_rd_LIN_rb_ASICReg_NoValidVals_cnt_g()                          LIN_rb_ASICReg_NoValidVals_cnt_g
#define l_u8_wr_LIN_rb_ASICReg_NoValidVals_cnt_g(a)                         {LIN_rb_ASICReg_NoValidVals_cnt_g = (a);}
#define l_u16_rd_LIN_rw_Solar_light16bit_1_g()                                (canuint16)(LIN_rw_Solar_light16bit_1_g_0)\
                                                                                | ((canuint16)(LIN_rw_Solar_light16bit_1_g_1)<<8)
#define l_u16_wr_LIN_rw_Solar_light16bit_1_g(a)                               {LIN_rw_Solar_light16bit_1_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_Solar_light16bit_1_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_LIN_rw_Solar_light16bit_2_g()                                (canuint16)(LIN_rw_Solar_light16bit_2_g_0)\
                                                                                | ((canuint16)(LIN_rw_Solar_light16bit_2_g_1)<<8)
#define l_u16_wr_LIN_rw_Solar_light16bit_2_g(a)                               {LIN_rw_Solar_light16bit_2_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_Solar_light16bit_2_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_LIN_rw_FW_light16bit_g()                                     (canuint16)(LIN_rw_FW_light16bit_g_0)\
                                                                                | ((canuint16)(LIN_rw_FW_light16bit_g_1)<<8)
#define l_u16_wr_LIN_rw_FW_light16bit_g(a)                                    {LIN_rw_FW_light16bit_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_FW_light16bit_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_LIN_rw_IR_light16bit_g()                                     (canuint16)(LIN_rw_IR_light16bit_g_0)\
                                                                                | ((canuint16)(LIN_rw_IR_light16bit_g_1)<<8)
#define l_u16_wr_LIN_rw_IR_light16bit_g(a)                                    {LIN_rw_IR_light16bit_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_IR_light16bit_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_LIN_rw_INTV10bit_max_g()                                     (canuint16)(LIN_rw_INTV10bit_max_g_0)\
                                                                                | ((canuint16)(LIN_rw_INTV10bit_max_g_1)<<8)
#define l_u16_wr_LIN_rw_INTV10bit_max_g(a)                                    {LIN_rw_INTV10bit_max_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_INTV10bit_max_g_1 = ((canuint8)((a)>>8));}


#define l_u16_rd_LIN_rw_INTV10bit_min_g()                                     (canuint16)(LIN_rw_INTV10bit_min_g_0)\
                                                                                | ((canuint16)(LIN_rw_INTV10bit_min_g_1)<<6)
#define l_u16_wr_LIN_rw_INTV10bit_min_g(a)                                    {LIN_rw_INTV10bit_min_g_0 = ((canuint8)((a) & 0x3F));\
                                                                                 LIN_rw_INTV10bit_min_g_1 = ((canuint8)((a)>>6));}
#define l_u16_rd_LIN_rw_VICALLO_ILO_GHI_ASIC_g()                              (canuint16)(LIN_rw_VICALLO_ILO_GHI_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VICALLO_ILO_GHI_ASIC_g_1)<<4)
#define l_u16_wr_LIN_rw_VICALLO_ILO_GHI_ASIC_g(a)                             {LIN_rw_VICALLO_ILO_GHI_ASIC_g_0 = ((canuint8)((a) & 0x0F));\
                                                                                 LIN_rw_VICALLO_ILO_GHI_ASIC_g_1 = ((canuint8)((a)>>4));}
#define l_u16_rd_LIN_rw_VTEMP_ASIC_g()                                        (canuint16)(LIN_rw_VTEMP_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VTEMP_ASIC_g_1)<<2)
#define l_u16_wr_LIN_rw_VTEMP_ASIC_g(a)                                       {LIN_rw_VTEMP_ASIC_g_0 = ((canuint8)((a) & 0x03));\
                                                                                 LIN_rw_VTEMP_ASIC_g_1 = ((canuint8)((a)>>2));}



#define l_u8_rd_LIN_rb_SPI_Active_ProblemCounter_g()                        LIN_rb_SPI_Active_ProblemCounter_g
#define l_u8_wr_LIN_rb_SPI_Active_ProblemCounter_g(a)                       {LIN_rb_SPI_Active_ProblemCounter_g = (a);}
#define l_u8_rd_LIN_rb_StaticHumTempErrorCounter_g()                        LIN_rb_StaticHumTempErrorCounter_g
#define l_u8_wr_LIN_rb_StaticHumTempErrorCounter_g(a)                       {LIN_rb_StaticHumTempErrorCounter_g = (a);}
#define l_u8_rd_LIN_rb_STATH_Reg_g()                                        LIN_rb_STATH_Reg_g
#define l_u8_wr_LIN_rb_STATH_Reg_g(a)                                       {LIN_rb_STATH_Reg_g = (a);}
#define l_u8_rd_LIN_rb_SupplyVoltage_mg()                                   LIN_rb_SupplyVoltage_mg
#define l_u8_wr_LIN_rb_SupplyVoltage_mg(a)                                  {LIN_rb_SupplyVoltage_mg = (a);}
#define l_u8_rd_LIN_rb_MaxLightSignalErrorCnt_g()                           LIN_rb_MaxLightSignalErrorCnt_g
#define l_u8_wr_LIN_rb_MaxLightSignalErrorCnt_g(a)                          {LIN_rb_MaxLightSignalErrorCnt_g = (a);}
#define l_u8_rd_LIN_rb_StaticNoCommunicationCounter()                       LIN_rb_StaticNoCommunicationCounter
#define l_u8_wr_LIN_rb_StaticNoCommunicationCounter(a)                      {LIN_rb_StaticNoCommunicationCounter = (a);}
#define l_u16_rd_LIN_rw_ALS2_ASIC_g()                                         (canuint16)(LIN_rw_ALS2_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_ALS2_ASIC_g_1)<<8)
#define l_u16_wr_LIN_rw_ALS2_ASIC_g(a)                                        {LIN_rw_ALS2_ASIC_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_ALS2_ASIC_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_LIN_rw_ALS5_ASIC_g()                                         (canuint16)(LIN_rw_ALS5_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_ALS5_ASIC_g_1)<<6)
#define l_u16_wr_LIN_rw_ALS5_ASIC_g(a)                                        {LIN_rw_ALS5_ASIC_g_0 = ((canuint8)((a) & 0x3F));\
                                                                                 LIN_rw_ALS5_ASIC_g_1 = ((canuint8)((a)>>6));}
#define l_u16_rd_LIN_rw_Amb_light16bit_g()                                    (canuint16)(LIN_rw_Amb_light16bit_g_0)\
                                                                                | ((canuint16)(LIN_rw_Amb_light16bit_g_1)<<4)
#define l_u16_wr_LIN_rw_Amb_light16bit_g(a)                                   {LIN_rw_Amb_light16bit_g_0 = ((canuint8)((a) & 0x0F));\
                                                                                 LIN_rw_Amb_light16bit_g_1 = ((canuint8)((a)>>4));}
#define l_u16_rd_LIN_rw_INREC_ASIC_g()                                        (canuint16)(LIN_rw_INREC_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_INREC_ASIC_g_1)<<2)
#define l_u16_wr_LIN_rw_INREC_ASIC_g(a)                                       {LIN_rw_INREC_ASIC_g_0 = ((canuint8)((a) & 0x03));\
                                                                                 LIN_rw_INREC_ASIC_g_1 = ((canuint8)((a)>>2));}

#endif

