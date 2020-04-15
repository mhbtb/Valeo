/******************************************************************************/
/*                                                                            */
/*   Valeo Schalter und Sensoren GmbH                                         */
/*   Stuttgarter Str. 119                                                     */
/*   74321 Bietigheim-Bissingen                                               */
/*                                                                            */
/*   All rights reserved. Distribution or duplication without previous        */
/*   written agreement of the owner prohibited.                               */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*   MODULE:                                                                  */
/*   FILE:                                                                    */
/******************************************************************************/
/*                                                                            */
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date         VDR_Number  Author       Description                                       */
/*----------------------------------------------------------------------------*/
/* 29.04.10     VDR_507           provide MSG ID to other dunctions*/
/* 03.02.08     VDR_87            Misra Warning for MISRA Rule 109*/
/* 19.08.2014   VDR_799    NB     LIN_ResponeError on LIN_NOResponse */
/* 27.11.2014   VCO_200    NB      move rb_LimitMemomryNoWiperReaction_g variable from G5_sci.h to G5_rs_mem_40.h */
/******************************************************************************/

/* PRQA S 0635 EOF *//*<< automatic generated code  >>*/
/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/

#ifndef I_SCI_H
#define I_SCI_H
#ifdef _sci_c_
#define EXTERN /**/
#else
#define EXTERN  extern
#endif

#undef LINSCI_ENABLE       // Im anderen Modus funktioniert break-Erzeugung nicht!

/******************************************************************************/
EXTERN void sci_init(byte rb_WakeUpFrame_l) ;
EXTERN void sci_Communication(void);
EXTERN __callt void sci_FastTask(void);
EXTERN void ApplLinProtocolError(byte error);
EXTERN __callt void ApplLinSlavePreCopy(byte rb_MessageID_l);
EXTERN __callt byte ApplLinSlaveCmdFrmFct(void);
EXTERN void ApplLinMasterReqFrmFct(void);
EXTERN void ApplLinBusSleep(void);
EXTERN void ApplLinWakeUp(void);
EXTERN byte sci_GetLINMsgID(void); /*VDR_507 */

EXTERN __callt byte sci_CheckParity(byte rb_Data);
/******************************************************************************/
/*        Hardware register and IO ports                                      */
/******************************************************************************/
#define MEMORY_NEAR  __saddr
#define MEMORY_FAR   /* */
#define MEMORY_ROM   const



/******************************************************************************/


/* 8-Bit qualifier */
typedef signed char    cansint8;
typedef unsigned char  canuint8;

/* 16-Bit qualifier */
typedef signed short   cansint16;
typedef unsigned short canuint16;

/* 32-Bit qualifier */
typedef signed long    cansint32;
typedef unsigned long  canuint32;


typedef unsigned char *TxDataPtr;              /* ptr to transmission data buffer */
typedef unsigned char *RxDataPtr;              /* ptr to receiving data buffer    */

typedef unsigned char    canbittype;

struct _c_bits8
{
  canbittype  b0:1;  /* LSB-Bits (lower adr!) */
  canbittype  b1:1;
  canbittype  b2:1;
  canbittype  b3:1;
  canbittype  b4:1;
  canbittype  b5:1;
  canbittype  b6:1;
  canbittype  b7:1;  /* MSB-Bits (higher address) unused */
};

struct _c_bits16
{
  canbittype  b0:1;  /* lower adr */
  canbittype  b1:1;
  canbittype  b2:1;
  canbittype  b3:1;
  canbittype  b4:1;
  canbittype  b5:1;
  canbittype  b6:1;
  canbittype  b7:1;
  
  canbittype  b10:1; /* higher adr */
  canbittype  b11:1;
  canbittype  b12:1;
  canbittype  b13:1;
  canbittype  b14:1;
  canbittype  b15:1;
  canbittype  b16:1;
  canbittype  b17:1;
};

#if( kLinNumberOfIndFlags > 8 )

union tLinIndicationBits {
  canuint8 _c[(kLinNumberOfIndFlags + 7)/8];
  struct _c_bits16 w[(kLinNumberOfIndFlags + 15)/16];
};

#else

union tLinIndicationBits {
  canuint8 _c[1];
  struct _c_bits8 w[1];
};

#endif

EXTERN MEMORY_NEAR union tLinIndicationBits uLinIndicationFlags;

#if( kLinNumberOfConfFlags > 8 )

union tLinConfirmationBits {
  canuint8 _c[(kLinNumberOfConfFlags + 7)/8];
  struct _c_bits16 w[(kLinNumberOfConfFlags + 15)/16];
};

#else

union tLinConfirmationBits {
  canuint8 _c[1];
  struct _c_bits8 w[1];
};

#endif /* #if defined( L_ENABLE_ST_CONFIRMATION_FLAG ) */

EXTERN MEMORY_NEAR union tLinConfirmationBits uLinConfirmationFlags;
extern MEMORY_ROM canuint8 cabLinIndicationOffset[kLinNumberOfRxObjects];
extern MEMORY_ROM canuint8 cabLinIndicationMask[kLinNumberOfRxObjects];

extern canuint8 MEMORY_ROM cabLinConfirmationOffset[kLinNumberOfTxObjects];
extern canuint8 MEMORY_ROM cabLinConfirmationMask[kLinNumberOfTxObjects];



EXTERN   byte rb_WBPosition_mg;
EXTERN  byte rb_MessageLength_mg;
EXTERN byte rb_SynchBitCounter_g;
EXTERN byte rb_SCI_CurrentLINID_g;
EXTERN byte rb_WakeupCounter_mg;
EXTERN byte rb_SCI_Error_g;
#define cb_LIN_NOERROR_g            (byte) 0x00
#define cb_LIN_BITERROR_g           (byte) 0x01
#define cb_LIN_IDPARITYERROR_g      (byte) 0x02
#define cb_LIN_OVERTFRAMEMAX_g      (byte) 0x04
#define cb_LIN_INCOMPLETEMSGERROR_g (byte) 0x08
#define cb_LIN_CHECKSUMERROR_g      (byte) 0x10
#define cb_LIN_OVERTHEADERMAX_g     (byte) 0x20
#define cb_LIN_NORESPONSE_g         (byte) 0x40
#define cb_LIN_FRAMINGERROR_g       (byte) 0x80
#define cb_LIN_PHYSICALBUSERROR_g   (byte) 0x81



EXTERN SHORT_MEMORY volatile Flag uF_sciState_mg;
#define rbi_StartTransmission_mg        uF_sciState_mg.Bit.B4
#define rbi_FrameValid_mg               uF_sciState_mg.Bit.B7


EXTERN byte rb_ResponseToSend_g;
/* PRQA S 3412 2 *//*<< code is OK  >>*/
#define    DISABLE_SCIINTERRUPT()   LTMK0 = 1U;   // enable recieve interrupt
#define    ENABLE_SCIINTERRUPT()    LTMK0 = 0U;   // enable recieve interrupt


EXTERN byte rb_LIN_BIT_ERROR_COUNTER_g;
EXTERN byte rb_LIN_OVERTHEADERMAX_COUNTER_g;
EXTERN byte rb_LIN_CHECKSUMERROR_COUNTER_g;
EXTERN byte rb_LIN_OVERTFRAMEMAX_COUNTER_g;
EXTERN byte rb_LIN_NORESPONSE_COUNTER_g;
EXTERN byte rb_LIN_FRAMINGERROR_COUNTER_g;
EXTERN byte rb_ResponseTime_g; /* VDR_799 */

/******************************************************************************/
#undef EXTERN
#endif /* I_SCI_H */
/******************************************************************************/
/* END Source: D:/ldws/software/ecu/sci.h  */
/******************************************************************************/
