
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
/*   MODULE:                                         */
/*   FILE:                                                                    */
/******************************************************************************/
/* Hystory                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                       */
/*----------------------------------------------------------------------------*/
/* 19.08.2014   VDR_799    NB     LIN_ResponeError on LIN_NOResponse */
/* 20.08.2014   VDR_799    NB     LIN_ResponeError on LIN_NOResponse */
/* 25.11.2014   VCO_200    NB     Include G5_lininclude.h instead rls.h and linconf.h  */
/* 08.12.2014   VDR_829    NB     Response error shall be set if there is a error in the receive Frame  */
/* 28.01.2015   VDR_837    NB     During startup the Response error is not set if there is a disturbance 
                                  in the stop bit of first byte */
/* 03.03.2015   VCO_227    NB     Implement RAM Guard function */
/* 09.03.2015   VCO_227    NB     Implement RAM Guard function */
/* 05.03.2015  VCO_248    NB     Unit Testing: Create/Adapt unit test scripts to new project settings*/
/* 08.06.2015  VDR_882    NB     Audi LIN test */
/* 09.06.2015 VDR_868    NB    All:QAC and Polyspace fixing for SW009 Release  */
/* 28.08.2015 VCO_268    SP    Cleanup the LIN modules  */
/* 03.09.2015 VDR_904    NB    Response error is set when invalid LIN header is received  */
/* 16.10.2015 VDR_904    NB    Response error is set when invalid LIN header is received  */
/* 11.11.2015 VDR_923    NB    move the #endif of VECTORCAST of  Lin r_uartf0_interrupt_send 
                               after the definition so that unit test shall be run  */
/*24.03.16    VCO_320   NB      LIN response shall not be sent untill EEPROM is loaded                         */ 
/******************************************************************************/


/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/
/* PRQA S 0781,750,759,436,434 EOF */ /* << 0781,436 03 03, unions needed >> */
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/******************************************************************************/
/*                      Common and module include file                        */
/******************************************************************************/
#include "ior5f109be.h"
#include "ior5f109be_ext.h"

#define G5_Linsci_sr_c
#include "G5_lininclude.h"
#include "G5_LINsci_sr.h"
#undef G5_Linsci_sr_c

#include "G5_Check_sr.h"
#include "G5_flashe2.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_io.h"
#include "G5_Appli_main.h"
/******************************************************************************/
/*                           Other files included                             */
/******************************************************************************/


/******************************************************************************/
/*                     Declaration of local module defines and macros                     */
/******************************************************************************/

#define NC_ID_PARITY_ERROR 0x4000 /* VDR_799 */
#define NC_CHECKSUM_ERROR 0x2000

#define NC_DATA_CONSISTANCY_ERROR 0x0008
#define NC_PARITY_ERROR 0x0004
#define NC_FRAMING_ERROR 0x0002
#define NC_OVERRUN_ERROR 0x0001
/* Detect following error: ID parity,checksum,data consistancy,Parity, Framing and overrunn */
#define NC_ERROR_MASK    0x600F

#define cb_WAKEUP_FASTRETRIES_mg    3
                                    
                               
#define SendWakeUpFrame()      LTMK0 = 0U; UF0TXE = 0; UF0OPT1 &= (0xF9); UF0TXE = 1; UF0TXB = 0x80; rbi_StartTransmission_mg = 0 /* write data to SCI data register */
                                    
/******************************************************************************/
/*                   Declaration of local module variables                    */
/******************************************************************************/
#define  cb_FLASH_SCI_WRITEBUFFERSIZE_mg (byte) 12 /* Attention this buffer is also used for LIN 3+8+1 bytes*/
#define  cb_FLASH_SCI_READBUFFERSIZE_mg  (byte) 12

#pragma dataseg="RAM_GUARD"          
static __no_init byte rab_ReadBuffer_mg[cb_FLASH_SCI_READBUFFERSIZE_mg];
static __no_init byte rab_WriteBuffer_mg[cb_FLASH_SCI_WRITEBUFFERSIZE_mg];
#pragma dataseg=default

static  byte rb_MsgHandle_mg;
static byte rb_ResponseTimeMax_mg;

static byte rb_WakeupTimer_mg;



/******************************************************************************/
/*                     Prototypes of local functions                          */
/******************************************************************************/

static __callt  void sci_WriteMessage(byte rb_MessageID);/*VDR_526*/
static __callt  void sci_CopyReceiveBuffer(void);/*VDR_526*/
static void set_rab_ReadBuffer_mg(byte rb_position_l, byte rb_value_l);
static void set_rab_WriteBuffer_mg(byte rb_position_l, byte rb_value_l);


#if ((LINBAUDRATE != 19200) && (LINBAUDRATE != 9600))
#error "Baudrate not supported"
#endif

static void set_rab_ReadBuffer_mg(byte rb_position_l, byte rb_value_l)
{
  DisableRamGuard();
  rab_ReadBuffer_mg[rb_position_l] = rb_value_l;
  EnableRamGuard(); 
}


static void set_rab_WriteBuffer_mg(byte rb_position_l, byte rb_value_l)
{
  DisableRamGuard();
  rab_WriteBuffer_mg[rb_position_l] = rb_value_l;
  EnableRamGuard(); 
}


/**************************************************************************
Syntax   : void sci_init(byte rb_WakeUpFrame_l)
Object   : sci_init()
Parameters : Send WakupFrame yes/no
Return  : none
Calls   : main.c (to be called once at init)
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code :
*************************************************************************/


void sci_init(byte rb_WakeUpFrame_l)  
{
  
  // rb_bytes_to_send_mg = 0;
  rb_WBPosition_mg = 0;
  uF_sciState_mg.AllBit = 0;
  
  //rb_SCI_Error_g = cb_LIN_NOERROR_g;
  rb_MessageLength_mg = 0;
  
  po_LINTx_g = 1;
  
  // init schedule table
  
  if (rb_WakeUpFrame_l == 1)
  {
    SendWakeUpFrame();
    rw_NoCommunicationCounter_g = 0; // init to 0 not to go in sleep mode
    rb_WakeupCounter_mg = 2;
    rb_WakeupTimer_mg = kLinTWakeup0;
  }
  
}

/**************************************************************************
Syntax   : void sci_Communication(void)
Object   : sci_Communication()
Parameters : none
Return  : none
Calls   : main.c (to be called every 10ms)
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code :
*************************************************************************/

void sci_Communication(void)
{
  if (rb_WakeupCounter_mg > 0)    // master still in sleep?
  {
    rb_WakeupTimer_mg --;   // decrement timeout timer
    
    if (rb_WakeupTimer_mg == 0)  // timeout expired?
    {
      
      {
        SendWakeUpFrame();      // send next wakeup frame
        rw_NoCommunicationCounter_g = 0; // init to 0 not to go in sleep mode
      }
      if (rb_WakeupCounter_mg >= cb_WAKEUP_FASTRETRIES_mg) // all wakeup frames with fast retry time sent?
      {
        rb_WakeupTimer_mg = kLinTWakeup3;   // long time for next retry
        rb_WakeupCounter_mg = 1;
      }
      else
      {
        rb_WakeupTimer_mg = kLinTWakeup0;   // fast time for next retry
        rb_WakeupCounter_mg++;  // increase counter for wakeupframes
      }
    }
  }
  
  rb_WDG_SCITaskCounter_g ++; 
}




/**************************************************************************
Syntax   : void sci_GetLINMsgID(void)
Object   : sci_GetLINMsgID()
Parameters : none
Return  : none
Calls   : LINsci.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code : get lin MSG_ID of last or actual frame
*************************************************************************/

byte sci_GetLINMsgID(void) /*VDR_507 provide MSG ID to other functions*/
{
  return ((rab_ReadBuffer_mg[1] & 0x3F));    // calculate message ID)
}


/**************************************************************************
Syntax   : void sci_CheckParity(void)
Object   : sci_CheckParity()
Parameters : byte with Identifier and Parity
Return  : none (rbi_FrameValid_mg is cleared if Parity niO)
Calls   : LINsci.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code :
*************************************************************************/

__callt byte sci_CheckParity(byte rb_Data)
{
  byte rb_Result_l, rb_TempData_l;
  byte rb_TestOK_l;
  
  rb_TestOK_l = TRUE;
  rb_TempData_l = rb_Data;
  //rb_Result_l = 0;
  
  rb_Result_l = (rb_TempData_l & 0x01);  // Bit 0
  
  rb_TempData_l = rb_TempData_l >> 1;
  rb_Result_l += (rb_TempData_l & 0x01);  // Bit 1
  
  rb_TempData_l = rb_TempData_l >> 1;
  rb_Result_l += (rb_TempData_l & 0x01);  // Bit 2
  
  rb_TempData_l = rb_TempData_l >> 2;
  rb_Result_l += (rb_TempData_l & 0x01);  // Bit 4
  
  rb_Result_l = (rb_Result_l & 0x01) << 6;
  
  if ((rb_Data & 0x40) != rb_Result_l)
  {
    rbi_FrameValid_mg = 0;
    rb_TestOK_l = FALSE;
  }
  else
  {
    rb_TempData_l = rb_Data;
    //rb_Result_l = 1;    // Parity bit inverted
    
    rb_TempData_l = rb_TempData_l >> 1;
    rb_Result_l = 1+(rb_TempData_l & 0x01);  // Bit 1
    
    rb_TempData_l = rb_TempData_l >> 2;
    rb_Result_l += (rb_TempData_l & 0x01);  // Bit 3
    
    rb_TempData_l = rb_TempData_l >> 1;
    rb_Result_l += (rb_TempData_l & 0x01);  // Bit 4
    
    rb_TempData_l = rb_TempData_l >> 1;
    rb_Result_l += (rb_TempData_l & 0x01);  // Bit 5
    
    
    rb_Result_l = (rb_Result_l & 0x01) << 7;
    if ((rb_Data & 0x80) != rb_Result_l)
    {
      rbi_FrameValid_mg = 0;
      rb_TestOK_l = FALSE;
    }
  }
  return (rb_TestOK_l);
  
  
}



/**************************************************************************
Syntax   : interrupt [INTSRE6_vect]using[1] void SCIVLIN_NEC_errorInterrupt(void)
Object   : SCIVLIN_NEC_errorInterrupt()
Parameters : none
Return  : none
Calls   : vector.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code : handling of communication errors
*************************************************************************/
#ifdef VECTORCAST
void SCIVLIN_NEC_errorInterrupt(void);
void SCIVLIN_NEC_errorInterrupt(void)
#else
#pragma bank = 1                               /*switch bank to 1*/
#pragma vector = INTLS_vect
__interrupt void SCIVLIN_NEC_errorInterrupt(void);
__interrupt void SCIVLIN_NEC_errorInterrupt(void)
#endif
{
  
  word rw_err_typ_l;
  byte rb_temp_l;
  byte rb_LoopBrake_1;
  
  rw_err_typ_l=UF0STR; 
  rb_temp_l = UF0RXB; /* read sci data register */
  UF0STC = 0x7F1F; /* clear flag */
  rbi_FrameValid_mg = 0;
  rb_LoopBrake_1 = 0;  
  if((rw_err_typ_l & NC_FRAMING_ERROR) > 0)
  {
    if((rw_err_typ_l & NC_ID_PARITY_ERROR) > 0) /* VDR_882 */
    {
     ApplLinProtocolError(cb_LIN_IDPARITYERROR_g); /* Incase of ID Error response bit shall not be set */
    }
    /* check is it really framing error or framing error due to NO_RESPONSE */
    else if(rb_ResponseTime_g > rb_ResponseTimeMax_mg) /* VDR_799 */
    {
      /* check if there is a partial response or no response ? */  
      /* if the received length greater than 1 then there is a partial response else No response
      the byte 00 in the UART buffer comes from Break field */
      if (((UF0BUCTL&0x000F)>1) && (rbi_StartTransmission_mg == TRUE)) /* VDR_829 */ /* VDR_882 */
      { 
        if(rbi_HeaderExpected_mg == FALSE)/* Set error only during response and ignore if it is in header reception*/
        {          
          ApplLinProtocolError(cb_LIN_INCOMPLETEMSGERROR_g);
        }
      }
      else
      {
        ApplLinProtocolError(cb_LIN_NORESPONSE_g);
      }
    }
    else
    {
      if(rbi_HeaderExpected_mg == FALSE )/* Set error only during response and ignore if it is in header reception*/
      {
        ApplLinProtocolError(cb_LIN_FRAMINGERROR_g); 
      }
    }
    rb_ResponseTime_g = 0;
  }
  else
  {
    rw_err_typ_l = rw_err_typ_l & NC_ERROR_MASK;
    
    for(rb_temp_l = 0; ((rb_temp_l < 16)&&(rb_LoopBrake_1 == 0)) ; rb_temp_l++)
    {
      switch(rw_err_typ_l & ((word)(0x0001) << rb_temp_l) )
      {
      case NC_CHECKSUM_ERROR: /* checksum error */
        ApplLinProtocolError(cb_LIN_CHECKSUMERROR_g);
        rb_LoopBrake_1 = 1;
        break;
        
      case NC_ID_PARITY_ERROR:
        ApplLinProtocolError(cb_LIN_IDPARITYERROR_g);
        rb_LoopBrake_1 = 1;
        break;
        
      case NC_DATA_CONSISTANCY_ERROR:
        ApplLinProtocolError(cb_LIN_BITERROR_g);
        rb_LoopBrake_1 = 1;
        break;
        
      case NC_PARITY_ERROR:
        ApplLinProtocolError(cb_LIN_BITERROR_g);
        rb_LoopBrake_1 = 1;
        break;        

      case NC_OVERRUN_ERROR: /* Framing error already handled above */   
        ApplLinProtocolError(cb_LIN_FRAMINGERROR_g);
        rb_LoopBrake_1 = 1;
        break;
        
      default: /* more than one error */
        
        break;
      }
      
    }  
  }
  
  rbi_StartTransmission_mg = 0;  
  
}


/**************************************************************************
Syntax   : void SCI_Interrupt(void)
Object   : SCI_Interrupt()
Parameters : none
Return  : none
Calls   : vector.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code :
*************************************************************************/
#ifdef VECTORCAST
void SioInterrupt(void);
void SioInterrupt(void) 
#else
#pragma bank = 1                              /*switch bank to 1*/

#pragma vector = INTLR_vect
__interrupt void SioInterrupt(void);
__interrupt void SioInterrupt(void) 
#endif
{
  word rb_K_Factor_l;
  byte rb_Message_ID_l;
  byte rb_EnterBootLoad_l;
  unsigned char __far * RcvPtr;
  int rb_LoopCount_l;
  
  static const unsigned char cab_EnterBootloadMessage_mg[8] = {0xA0,0x01,0x55,'V','a','L','e','O'};  
  
  
  if((UF0TXE != 0) && ((UF0OPT1&0x06) != 0x06))
  {
    UF0TXE = 0;
    UF0OPT1 |= 0x06;
    UF0STC = 0x7F1F; /* clear flag */
    UF0TXE = 1;
    rb_WakeupCounter_mg=0;
  }
  else
  {
    rbi_LIN_CommunicationEvent_g = TRUE;  /* clear flag for LIN-Interrupt */
    rb_ResponseTime_g = 0;
    if((UF0STR & 0x0800) > 0 ) /* Read UF0HDC flag */
    {
      UF0STC = (UF0STC | 0x0800); /* clear UF0HDC flag */
      set_rab_ReadBuffer_mg(1,UF0ID); /* copy identifier to the read buffer */
      rbi_FrameValid_mg = 1;  /* every frame check function can clear this flag (set to 1 only here)*/
      (void)sci_CheckParity(rab_ReadBuffer_mg[1]);  /* check identifiers parity bits */
      if(rbi_FrameValid_mg == 0)   /* Parity check not OK? */
      {
        ApplLinProtocolError(cb_LIN_IDPARITYERROR_g);   /* call protocoll error function "Parity Error" */
      }
      
      rw_NoCommunicationCounter_g = 0;
      rbi_HeaderExpected_mg = FALSE;
      rb_Message_ID_l = (rab_ReadBuffer_mg[1] & 0x3F);    /* calculate message ID */
#ifdef NODECONFIGURATION
      rb_MsgHandle_mg = rabRAMLinMsgIDToHandleTbl[rb_Message_ID_l] & 0x3F;   /* and handle (use table in RAM)*/
#else
      rb_MsgHandle_mg = cabLinMsgIDToHandleTbl[rb_Message_ID_l] & 0x3F;   /* and handle (use table in ROM)*/
#endif
      if(rb_MsgHandle_mg >= (kLinNumberOfRxObjects + kLinNumberOfTxObjects) || (rbi_LINTableInitialised_g == FALSE)) 
      { /* message to ignore */
        UF0BUCTL =  0x0040; /* set UF0NO to 1 */
        rbi_HeaderExpected_mg = TRUE;
      }
      else
      {
        if(rb_MsgHandle_mg < kLinNumberOfTxObjects)  /* message to transmitt? */
        {
          rb_MessageLength_mg = cabLinTxDataLenTbl[rb_MsgHandle_mg];
          sci_WriteMessage(rb_Message_ID_l);   /* write Message in buffer */
        }
        else  /* message to receive */
        {
          rbi_StartTransmission_mg = 0;
          rb_MessageLength_mg = cabLinRxDLCTbl[rb_MsgHandle_mg-kLinNumberOfTxObjects];
          UF0OPT1_bit.no3 = 1;
          if(rab_ReadBuffer_mg[1] == 0x3C)
          { /*use classic checksum*/
            UF0BUCTL =  0x0020|(word)rb_MessageLength_mg; /* set UF0RRQ to 1 */        
          }
          else
          {
#ifdef LIN20CHECKSUM
            UF0BUCTL =  0x00A0|(word)rb_MessageLength_mg; /* set UF0RRQ to 1 */
#else
            UF0BUCTL =  0x0020|(word)rb_MessageLength_mg; /* set UF0RRQ to 1 */
#endif          
          }
        }/* VDR_837*/
        /* Baud rate is = FUCLK/2*K */
        /* FUCLK = 16Mhz and K is obtained as below */
        rb_K_Factor_l = UF0CTL1;
        rb_K_Factor_l = (rb_K_Factor_l & 0x0FFF);
        /* T_Frame_min = 10*NDATA (without header) */
        /* T_Frame_max = T_Frame_min * 1.4 */
        /* Number of ticks calculated as below with 0.5ms task for given baudrate */
        rb_ResponseTimeMax_mg = ((long)rb_MessageLength_mg * rb_K_Factor_l*14)/4000; /* VDR_799 */
      }      
    }
    
    if((UF0STR & 0x0400) > 0) /* Message transmitted flag */
    {
      /* PRQA S 306 2 *//*<< 306:Pointer cast needed  >>*/
      RcvPtr =(  unsigned  char __far * ) 0xF052FU;
      for (rb_LoopCount_l = 0; rb_LoopCount_l < rb_MessageLength_mg ; rb_LoopCount_l++)
      {
        /* PRQA S 488 2 *//*<< 488:Pointer arithmatic needed  >>*/
        set_rab_ReadBuffer_mg((2 + rb_LoopCount_l),(byte)(*(RcvPtr + rb_LoopCount_l)));
      }
      sci_CopyReceiveBuffer();
      
      rbi_HeaderExpected_mg = TRUE;
      rb_WakeupCounter_mg = 0;    /* stop sending of wakeup frames */
      rb_EnterBootLoad_l = 1;
      for (rb_LoopCount_l = 0; (rb_LoopCount_l < 8) && (rb_EnterBootLoad_l==1); rb_LoopCount_l++)
      {
        if (rab_ReadBuffer_mg[ 2 + rb_LoopCount_l] != cab_EnterBootloadMessage_mg[rb_LoopCount_l] )
        {
          rb_EnterBootLoad_l = 0; /* set flag to invalid */
        }
      }
      if(rb_EnterBootLoad_l == 1)
      {
        Enter_BootLoad_Mode();
      }      
    }
  }
    UF0STC = 0x7F1F; /* clear flag */        
}

#ifdef VECTORCAST
void r_uartf0_interrupt_send(void);
void r_uartf0_interrupt_send(void) 
#else
#pragma bank = 1                              /*switch bank to 1*/
#pragma vector = INTLT_vect
__interrupt static void r_uartf0_interrupt_send(void);
__interrupt static void r_uartf0_interrupt_send(void)
#endif
{
  UF0STC = 0x7F1F; /* clear flag */
  rbi_StartTransmission_mg = 0;
  rbi_HeaderExpected_mg = TRUE;
  rb_ResponseTime_g = 0;
}

/**************************************************************************
Syntax   : void sci_CopyReceiveBuffer(void)
Object   : sci_CopyReceiveBuffer()
Parameters : none
Return  : none
Calls   : LINsci.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code :
*************************************************************************/

static __callt  void sci_CopyReceiveBuffer(void)
{
  byte rb_Message_ID_l;
  byte rb_Length_l;
  
  rb_Message_ID_l = rab_ReadBuffer_mg[1] & 0x3F;  // read identifier field
  
  
#ifdef NODECONFIGURATION
  rb_MsgHandle_mg = cabLinMsgHandleTbl[rabRAMLinMsgIDToHandleTbl[rb_Message_ID_l]&0x3F];      // (use table in RAM)
#else
  rb_MsgHandle_mg = cabLinMsgHandleTbl[cabLinMsgIDToHandleTbl[rb_Message_ID_l]&0x3F];         // (use table in ROM)
#endif
  
  rb_Length_l = cabLinRxDLCTbl[rb_MsgHandle_mg];
  
  
  if (rbi_FrameValid_mg == 1)
  {
    rbi_FrameValid_mg = 0; 
    // copy data
    rb_Length_l = cabLinRxDataLenTbl[rb_MsgHandle_mg];
    
    while(rb_Length_l >0)
    {
      rb_Length_l--;
      capbLinRxDataPtrTbl[rb_MsgHandle_mg][rb_Length_l] = rab_ReadBuffer_mg[rb_Length_l+2];
    }    /* VDR_123 additional MISRA correction*/
    if (rb_Message_ID_l == 0x3C)
    {
      if (rab_ReadBuffer_mg[2] == 0)   // sleep mode frame received?
      {
        ApplLinBusSleep();
      }
      else
      {
        ApplLinMasterReqFrmFct();
      }
    }
    else
    {
      uLinIndicationFlags._c[cabLinIndicationOffset[rb_MsgHandle_mg]] |= cabLinIndicationMask[rb_MsgHandle_mg];
    }
  }
  else
  {
    ApplLinProtocolError(cb_LIN_IDPARITYERROR_g);
  }
  
  
}

/**************************************************************************
Syntax   : void sci_WriteMessage(void)
Object   : sci_WriteMessage()
Parameters : message ID
Return  : none
Calls   : LINsci.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code :
*************************************************************************/

static __callt void sci_WriteMessage(byte rb_MessageID)
{
  int rb_LoopCount_l;
  word rb_Length_l;
  word rb_Checksum_l;
  byte rb_Send_l;
  unsigned char __far * RcvPtr ;
  
  rb_Length_l = cabLinTxDataLenTbl[rb_MsgHandle_mg];
  
  if(rb_MessageID == 0x3D)
  {
    
    rb_Send_l = ApplLinSlaveCmdFrmFct();
    
  }
  else
  {
    ApplLinSlavePreCopy(rb_MessageID);
    rb_Send_l = 1;
  }
  
  if(rb_Send_l == 1)
  {
    
    
#ifdef LIN20CHECKSUM
    if (rb_MessageID >= 0x3C)   //  ID >= 0x3C
    {
      rb_Checksum_l = 0x0000;      // classic checksum
      
    }
    else
    {
      rb_Checksum_l = 0x0080;   // lin 2.0 checksum
    }
#else
    rb_Checksum_l = 0;
#endif
    
    while(rb_Length_l > 0)
    {
      rb_Length_l--;
      set_rab_WriteBuffer_mg((rb_Length_l+1), (capbLinTxDataPtrTbl[rb_MsgHandle_mg][rb_Length_l]));
    }
    
    //    TransmitMessage();  // send first byte
    rb_Length_l = cabLinTxDataLenTbl[rb_MsgHandle_mg];
    
    rb_WBPosition_mg = 1;
    /* PRQA S 306 2 *//*<< 306:Pointer cast needed  >>*/
    RcvPtr = (unsigned char __far *)0xF052F ;
    for (rb_LoopCount_l = 0; rb_LoopCount_l < rb_Length_l ; rb_LoopCount_l++)
    {
      /* PRQA S 488 2 *//*<< 488:Pointer arithmatic needed  >>*/
      *(RcvPtr + rb_LoopCount_l)= rab_WriteBuffer_mg[rb_WBPosition_mg]; 
      rb_WBPosition_mg++;
    }
    
    UF0OPT1_bit.no3 = 1; /* Enables automatic checksum calculation */
    UF0BUCTL =  (0x0210 | rb_Checksum_l | rb_Length_l); /* set UF0TRQ to 1 */
    
    rbi_StartTransmission_mg = 1;
    
    uLinConfirmationFlags._c[cabLinConfirmationOffset[rb_MsgHandle_mg]] |= cabLinConfirmationMask[rb_MsgHandle_mg];
    // rab_WriteBuffer_mg[cabLinTxDataLenTbl[rb_MsgHandle_mg]+1] = 0xFF - rb_Checksum_l;
  }
  else
  {
    UF0BUCTL =  0x0040; /* set UF0NO to 1 *//* No response expected for the LIN ID */
  }
  
}