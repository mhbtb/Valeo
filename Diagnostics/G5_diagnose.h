/* PRQA S 3619 EOF */ /* << 2010 01 08, compiler allows whitespaces:due to readable code, keep whitespaces! >> */
/* PRQA S 3453 EOF *//*<< Macro is more readle and convinient in this situation >>*/
/* PRQA S 0750,759 EOF *//*<< 0759:union needed to reduce RAM usage >>*/
/**************VALEO WIPER SYSTEMS**SMART*SENSORS************************
*                                                                       *
*  HEADER FILE NAME : rls_lin.h                      *
*                                                                       *
*  LIBRARY ID       :                                                   *
*                                                                       *
*  DESCRIPTION      : interface LIN                                     *
*                  *
*                  *
*                                                                       *
*  SPECIAL LOGIC    :                                                   *
*                                                                       *
*************************************************************************
*                                                                       *
*                         MODIFICATION LOG                              *
*                                                                       *
* Date      VerNo     Auth   Description                                *
* --------  -----  ------------------------------------------  -------- */
/* 28.11.14 VCO_200   NB include structure update                       */
/* 09.04.15   VCO_242    NB     Remove length check of cb_REQLENGTHSID22_Multi_s for service 22 */
/*10.06.2015 VCO_254    NB    Checking of CRC over light area shall be done cyclically  */
/*06.08.15      VCO_264 NB      Implement common part in diagnostic file                                        */
/*28.08.15      VCO_268 SP      Cleanup the LIN modules  */
/* 07.12.17     VCO_462    HB    FIAT 330 interfaces: parallel branch                  */
/************************************************************************/

#ifndef _DIAGNOSE_H_ /*QAC Message 883 --> protect header file against repeated implementation*/
#define _DIAGNOSE_H_ /*QAC Message 883 --> protect header file against repeated implementation*/

#include "G5_projectDefs.h"
//#include "G5_E2ProjectConfig.h"

#ifdef _DIAGNOSE_c_
#define EXTERN /**/
#else
#define EXTERN  extern
#endif


EXTERN word rw_DiagnoseStepResponseAnswer_g;


EXTERN  volatile Flag uF_LIN_Diagnosis_mg;

#define rbi_CodingRequest_mg                 uF_LIN_Diagnosis_mg.Bit.B0
#define rbi_WiperMotorMessageFlag_mg        uF_LIN_Diagnosis_mg.Bit.B1
#define rbi_MasterMessageFlag_mg            uF_LIN_Diagnosis_mg.Bit.B2
#define rbi_DiagnoseWriteEEPROM_g           uF_LIN_Diagnosis_mg.Bit.B3
#define rbi_DiagnoseReadEEPROM_g            uF_LIN_Diagnosis_mg.Bit.B4
#define rbi_ResponsePending_g               uF_LIN_Diagnosis_mg.Bit.B5

#define rbi_enable_Programming_EEPROM_g     uF_LIN_Diagnosis_mg.Bit.B7

/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN  volatile Flag uF_LIN_DiagReq2_mg;
#define rbi_DiagnosisPulseValid_g            uF_LIN_DiagReq2_mg.Bit.B0
#define rbi_CRC_ChangedByDiagnostic_g        uF_LIN_DiagReq2_mg.Bit.B1
#define rbi_ASICgainAdjustRunning_g          uF_LIN_DiagReq2_mg.Bit.B5
#define rbi_AminuBMaxPositiv_g               uF_LIN_DiagReq2_mg.Bit.B6
#define rbi_LastAminuBMaxPositiv_g           uF_LIN_DiagReq2_mg.Bit.B7


EXTERN byte rb_ResponseToSend_g;
EXTERN  byte rb_Diagnosticstate_g;

#ifdef _SUPPORTSERVICE1A_
EXTERN byte Diagnose_Read_SteuergIdent(void);
EXTERN byte Diagnose_Read_Audi_Partnumber(void);
EXTERN byte Diagnose_ReadExtECUIdent(void);
#endif

#ifdef _SUPPORTSERVICE21_
EXTERN void Diagnose_ReadDataByLocalID(void);
#endif

#ifdef _SUPPORTSERVICE22_
EXTERN void Diagnose_ReadDataByIdentifier(void);
#endif

#ifdef _SUPPORTSERVICE23_
EXTERN byte Diagnose_ReadMemoryByAddress(void);  /*VDR_233 Rework diagnostic*/
EXTERN byte rb_LINRequest_4470_g; /*VDR_334*/
#endif

#ifdef _SUPPORTSERVICE3D_
EXTERN void Diagnose_WriteMemoryByAddress(void);
#endif

#ifdef _SUPPORTSERVICE19_
EXTERN void Diagnose_ReadDTC(void);
#endif

#ifdef _SUPPORTSERVICE14_
EXTERN void Diagnose_ClearDTC(void);
#endif

#ifdef _SUPPORTMWLLIGHT_
EXTERN void Diagnose_ReadMem_Init(void);
EXTERN void Diagnose_ReadMem_Command(void);
EXTERN void Diagnose_ReadMem_Send(void);
#endif

#ifdef NODECONFIGURATION
EXTERN void Diagnose_ReadByIdentifier(void);
EXTERN void Diagnose_AssignIdentifier(void);
#endif

#ifdef NODECONFIGURATION
#ifdef _SUPPORTASSIGNNAD_
void Diagnose_AssignNAD(void);
#endif
#endif

#ifdef NODECONFIGURATION
#ifdef _SUPPORTLINDATADUMP_
void Diagnose_LINDATADUMP(void);
#endif
#endif
#ifdef _SUPPORTCODING3B_
EXTERN void Diagnose_Write_Codierinfo(void);
#endif

#ifdef _SUPPORTCODING2E_
EXTERN void Diagnose_Write_CodierinfoB8(void);
#endif

#ifdef _SUPPORTJ2602ECURESET_/*VCO_11*/
EXTERN void Diagnose_ECUReset(void);
#ifdef _ECURESETCALLBACKFKT_
extern byte ApplEcuReset(void);  /* Callbackfunction for service ECU reset (reset of variables, status etc.)*/
                                 /*   returns TRUE if reset has been performed. */
#endif /*_ECURESETCALLBACKFKT_*/
#endif

EXTERN void diagnose_ASICstepResponse(void);

EXTERN void Diagnose_ClearCodingResult(void);

EXTERN byte Diagnosis_BCDtoASCII(byte rb_Input_l);

#if (defined FERRARI) || (defined GEN3_5A_FCA) || (defined FIAT_330)
EXTERN void Diagnose_ECUInfo(void);         /*  Diag Service C0 for Chrysler PF*/
EXTERN void Diagnose_PartNumber1To6(void);  /*  Diag Service C7 for Chrysler PF*/
EXTERN void Diagnose_PartNumber7To10(void); /*  Diag Service C8 for Chrysler PF*/
#endif


/*************************************************************************
**                   Defines for Diagnosis                              **
*************************************************************************/

#define cb_TA_DEVELOPEMENT_s          0xA0

#ifdef _SUPPORTASSIGNNAD_
#define cb_TARGET_ADDRESS_s         rb_NAD_g    // use EEPROM value
#else
#define cb_TARGET_ADDRESS_s         cb_INITAL_TARGET_ADDRESS_s     // use ROM value
#endif

#define cb_OTHER_TARGET_ADDRESS_s       0xF0
#define cb_TRANSFER_DATA_REQUEST_s      0x36
#define cb_REQUEST_UPLOAD_s             0x35
#define cb_REQUEST_DOWNLOAD_s           0x34

#ifdef NODECONFIGURATION
#define cb_REQLENGTHSIDB0_s   6
#define cb_REQLENGTHSIDB1_s   6
#ifdef GAC_RLS
#define cb_REQLENGTHSIDB2_s   2
#else
#define cb_REQLENGTHSIDB2_s   6
#endif
#define cb_REQLENGTHSIDB3_s   6
#endif

#define cb_REQLENGTHSID34_s   5
#define cb_REQLENGTHSID35_s   5



///////////////////////////////////////////////
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN
#endif /*QAC Message 883 --> protect header file against repeated implementation*/
