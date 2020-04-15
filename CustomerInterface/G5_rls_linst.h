#ifndef G5_RLS_LINST_H
#define G5_RLS_LINST_H
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
* Date      VDR  Auth     Description                                 *
* -DD.MM.YY- ---  -- ------------------------------------------  -------- **/
/* 02.Jul.10 VDR_540 FS Butterfly Option implemented*/
/* 14.Jun.10 VCO_49  FS Simulated Park Position*/
/* 29.Apr.10 VDR_473 FS Branch old Version 1.13 with 1.15*/
/* 24.02.10  VCO_031 AL external Variable needed            AL      */
/* 01.10.09  VDR_373 FS Single Or Double Overwiped*/
/* 28.09.09  VDR_368 FS Ford related Bits implemented: CarCode, LightConfigreceived, OneTimeOrDoubleOverwiped*/
/* 24.10.08  VDR_277 FS Sleep Mode without rw_NoCommunicationCounter_g*/
/* 16.10.08  VDR_276 FS  Implement Overwipe Offset*/
/* 23.11.00  Init   JS Initial Release             */


/****************************************************************************************************************/
/* 25.11.2014   VCO_200    NB   add Fiat releated code inside the compiler switch                               */
/* 13.05.2015   VCO_192    NB   Audi: Activation and deactivation of Interval Operation                         */
/* 09.06.2015   VCO_192    NB   Audi: Activation and deactivation of Interval Operation                         */
/* 13.07.2015   VDR_891    MP   SWITS_635: SPI communication error not set when the ASIC mode is corrupted      */
/********************************only once per cycle                                                            */
/* 28.08.2015   VCO_268    SP     Cleanup the LIN modules                                                       */
/* 21.09.2015   VDR_909    NB     Fixed interval operation not started after lapsing the ignition delay         */ 
/*                                and activating again                                                          */
/*24.03.16    VCO_320   NB      LIN response shall not be sent untill EEPROM is loaded                          */ 
/*12.05.16    VCO_326   NB      All:Update of default Software part number and other configuration   */
/* 07.12.17     VCO_462    HB    FIAT 330 interfaces: parallel branch                                           */
/****************************************************************************************************************/

#include "G5_projectDefs.h"

#ifdef _RLS_LIN_c_
#define EXTERN /**/
#else
#define EXTERN  extern
#endif
/* PRQA S 0841 1 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef LIN_INC_H

/*VCO_220 VIrefLo/Hi monitoring*/ /*VDR_878*/
#define IS_LS_ANY_ERRORCOUNTER()    (                                               \
                                        (rw_SPINoCommCounter_g > 0)                 \
                                     || (get_rb_LightVetoCounter_g() > 0)           \
                                     || (get_rb_LightSignalErrorCnt_g() > 0)        \
                                     || (rb_ASIC_SPI_ErrorCodeCnt_g > 0)            \
                                     || (rb_StaticNoValidAD_cnt_g > 0)              \
                                     || (get_rb_VDD_LightSignalErrorCnt_g() > 0)    \
                                     || (get_rb_LEDx_LStop_error_cnt_g() > 0)       \
                                     || (rb_ClockFreq_Error_cnt_g > 0)              \
                                     || (rb_ASIC_ALS2Amb_ShortDetected_cnt_g > 0)   \
                                     || (rb_ASIC_ALS5FW_ShortDetected_cnt_g > 0)    \
                                     || (rb_ASIC_INRECIR_ShortDetected_cnt_g > 0)   \
                                     || (rb_ASIC_initTimeout_g > 0)                 \
                                     || (rb_VIref_ErrCnt_g > 0)                     \
                                    )


/* PRQA S 750,0759 1 *//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN SHORT_MEMORY volatile Flag uF_SCIFlags_mg;


EXTERN byte rb_LIN_BIT_ERROR_COUNTER_g;
EXTERN byte rb_LIN_OVERTHEADERMAX_COUNTER_g;
EXTERN byte rb_LIN_CHECKSUMERROR_COUNTER_g;
EXTERN byte rb_LIN_OVERTFRAMEMAX_COUNTER_g;
EXTERN byte rb_LIN_NORESPONSE_COUNTER_g;
EXTERN byte rb_LIN_FRAMINGERROR_COUNTER_g;


#define rbi_SendWakeUpFrame_g        uF_SCIFlags_mg.Bit.B0
#define rbi_ConnectedToMaster_g      uF_SCIFlags_mg.Bit.B1
#define rbi_GotoSleep_g              uF_SCIFlags_mg.Bit.B2
#define rbi_LINTableInitialised_g    uF_SCIFlags_mg.Bit.B3
#define rbi_Command_CloseWindows_g   uF_SCIFlags_mg.Bit.B4
#define rbi_WrongEEPROM_Parameter_g  uF_SCIFlags_mg.Bit.B5
#define rbi_RealParkContact_g        uF_SCIFlags_mg.Bit.B6
#define rbi_oneTimeAnswerd_g         uF_SCIFlags_mg.Bit.B7
/* PRQA S 750,0759 1 *//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN SHORT_MEMORY Flag uF_Communication_mg;
#if (defined FERRARI) || (defined GEN3_5A_FCA) || (defined FIAT_330)
#define rbi_LightSensorActiveFromLin_mg               uF_Communication_mg.Bit.B0
#endif

#if (defined FERRARI) || (defined GEN3_5A_FCA) || (defined FIAT_330)
#define rbi_LightConfigRecieved TRUE

#define rbi_RLSDCfgData_recieved_g      uF_Communication_mg.Bit.B1
#define rbi_RLSDCfgData_ComToRLS_g      uF_Communication_mg.Bit.B2
#define rbi_LightSensitivityRecieved_g     TRUE
#elif defined (AUDI_B8)
#define rbi_LightSensitivityRecieved_g     uF_Communication_mg.Bit.B1
#define rbi_MasterMessageRecieved_g       rbi_LightSensitivityRecieved_g 
#define rbi_LightConfigRecieved TRUE
#else
#define rbi_LightSensitivityRecieved_g TRUE
#define rbi_LightConfigRecieved TRUE
#endif

#define rbi_TunnelWipe_mg                   uF_Communication_mg.Bit.B3
#define rbi_modi_lightsens_tunnel_alt_mg    uF_Communication_mg.Bit.B4
#define rbi_LINRainsensorDisabled_g         uF_Communication_mg.Bit.B5
#define rbi_latched_ResponseError_mg        uF_Communication_mg.Bit.B6
#define rbi_ReInitTable_g                   uF_Communication_mg.Bit.B7

EXTERN volatile Flag uF_Butterfly_Flags_g;
#define rbi_OneTimeOrDoubleOverwiped            (uF_Butterfly_Flags_g.Bit.B0)
#define rbi_ButterflyIsEquipped                 (uF_Butterfly_Flags_g.Bit.B1)
#define rbi_LessSensitivityLowSCSPotiStage_g    (uF_Butterfly_Flags_g.Bit.B2)
#define rbi_DoubleOverwiped                     (uF_Butterfly_Flags_g.Bit.B3)
#define rbi_Sig_Ansammlung_Ford                 (uF_Butterfly_Flags_g.Bit.B4)
#define rbi_ReduceIntANDOvrMemoryLoading_g      (uF_Butterfly_Flags_g.Bit.B5)
#define rbi_SimulateParkContact_g               (uF_Butterfly_Flags_g.Bit.B6)
#define rbi_CarCode_recieved_g                  (uF_Butterfly_Flags_g.Bit.B7)



#define cb_UNASSIGNED_FRAMEID_g     0x40

EXTERN   byte rb_LastLINErrorCode_g;
EXTERN   word rw_NoCommunicationCounter_g;
EXTERN   byte rb_intervaltime_rainSensorOff_g;
EXTERN   byte rb_Release_IntervalMarker_Update_g; /*VCO_192*/
//EXTERN byte rb_RLS_Botschaft_g;

EXTERN void CopyRLSData(void);
EXTERN void LIN_50ms_Task(void);
// EXTERN void LIN_1ms_Task(void);

EXTERN void ApplLinInit(byte rb_LIN_State_l);
#ifdef NODECONFIGURATION
EXTERN void ApplTableInit(void);
#endif

//EXTERN canuint8 LinStart (void);

EXTERN void Check_StartupActiveErrors(void);

EXTERN void GetLsWWS(void);
EXTERN void GetLeWWS(void);

/* PRQA S 0841 1 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN
#endif
