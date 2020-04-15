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
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 19.08.2014   VDR_799    NB     LIN_ResponeError on LIN_NOResponse */
/* 28.08.2015   VCO_268    SP     Cleanup the LIN modules  */
/* 03.09.2015   VDR_904    NB     Response error is set when invalid LIN header is received  */
/* 09.11.15     VCO_282    NB    All:Add spare LIN IDs in the EEPROM             */
/******************************************************************************/

#ifndef G5_LINSCI_SR_H
#define G5_LINSCI_SR_H

#ifdef G5_Linsci_sr_c
#define EXTERN /**/
#else
#define EXTERN  extern
#endif


/******************************************************************************/
EXTERN void sci_init(byte rb_WakeUpFrame_l) ;
EXTERN void sci_Communication(void);
EXTERN byte sci_GetLINMsgID(void); /*VDR_507 */
EXTERN __callt byte sci_CheckParity(byte rb_Data);

EXTERN void ApplLinProtocolError(byte error);
EXTERN __callt void ApplLinSlavePreCopy(byte rb_MessageID_l);
EXTERN __callt byte ApplLinSlaveCmdFrmFct(void);
EXTERN void ApplLinMasterReqFrmFct(void);
EXTERN void ApplLinBusSleep(void);



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
  canbittype  b8:1; /* higher adr */
  canbittype  b9:1;
  canbittype  b10:1;
  canbittype  b11:1;
  canbittype  b12:1;
  canbittype  b13:1;
  canbittype  b14:1;
  canbittype  b15:1;
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



EXTERN byte rb_WBPosition_mg;
EXTERN byte rb_MessageLength_mg;
EXTERN byte rb_WakeupCounter_mg;
EXTERN byte rb_ResponseTime_g; /* VDR_799 */

EXTERN SHORT_MEMORY volatile Flag uF_sciState_mg;
#define rbi_HeaderExpected_mg           uF_sciState_mg.Bit.B3
#define rbi_StartTransmission_mg        uF_sciState_mg.Bit.B4
#define rbi_FrameValid_mg               uF_sciState_mg.Bit.B7


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


#define kLinTHeaderMax  3
#define kLinTFrame0  4
#define kLinTFrame1  5
#define kLinTFrame2  5
#define kLinTFrame3  6
#define kLinTFrame4  7
#define kLinTFrame5  7
#define kLinTFrame6  8
#define kLinTFrame7  9
#define kLinTFrame8  10
#define kLinTWakeup0  17  /*VDR_517 increase timing to be in tolerance*/
#define kLinTWakeup3  159 /*VDR_517 increase timing to be in tolerance*/
#define kLinTBusIdle  130

// counter steps for TFrameMaxTimeoutTimer (without break and -4 (Timer starts at 0xFFFC))


/* PRQA S 3412 2 *//*<< code is OK  >>*/
#define    DISABLE_SCIINTERRUPT()   LTMK0 = 1U;   // enable recieve interrupt
#define    ENABLE_SCIINTERRUPT()    LTMK0 = 0U;   // enable recieve interrupt







#undef EXTERN       

/******************************************************************************/

/******************************************************************************/
/*        Hardware register and IO ports                                      */
/******************************************************************************/




/******************************************************************************/


/******************************************************************************/
#undef EXTERN
#endif /* G5_LINSCI_SR_H */
/******************************************************************************/
/* END Source: G5_LINsci_sr.h  */
/******************************************************************************/
