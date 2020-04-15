/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/
/* PRQA S 0781,759,436,434 EOF */ /* << 0781,436 03 03, unions needed >> */
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 5900,5565,5540 EOF *//*<< Data needs to be verified  >>*/
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
/*   MODULE: Evaluation Sensor Signals                                        */
/*   FILE:                                                                    */
/******************************************************************************/
/* Hystory                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 31.03.11  VCO_092   AL   Add additional counters for SW-Watchdog */
/* 14.Mar11  VSC_4     FS   Update due to predef_macro_projconf-file and compiler defines in extra header*/
/* 22.07.10  VDR_526     AL      clear nocommunication counter after wake up*/
/* 26.05.10  VDR_526     AL      Wake bus for sleep without closing window */
/* 29.04.10  VDR_507        provide MSG ID to other dunctions*/
/* 28.04.10  VDR_505        RLS_All: no answer after Break field without synch, after next header*/
/* 23.01.08  VDR_123        RLS_ALL_LIN2.0_NO_RESPONSE_ERROR_set_at_checksum_error in sended Frame */

/* 29.07.2013  VDR_738  NB   RLS Zaehler counts sometimes twice */
/* 11.10.2013  VDR_749  NB  Response Error for Diagnostic ID */
/*09.06.2015 VDR_868    NB    All:QAC and Polyspace fixing for SW009 Release  */
/******************************************************************************/



/******************************************************************************/
/*                      Common and module include file                        */
/******************************************************************************/
#include "ior5f109be.h"
#include "ior5f109be_ext.h"

#define _sci_c_
#include "G5_lininclude.h"
#undef _sci_c_

/******************************************************************************/
/*                           Other files included                             */
/******************************************************************************/

#include "G5_io.h"
#include "G5_Appli_main.h"
#include "G5_sci.h"


/******************************************************************************/
/*                     Declaration of local module macros                     */
/******************************************************************************/

#define SendWakeUpFrame()      LTMK0 = 0U; UF0TXE = 0; UF0OPT1 &= (0xF9); UF0TXE = 1; UF0TXB = 0x80; rbi_StartTransmission_mg = 0 /* write data to SCI data register */

/******************************************************************************/
/*                   Declaration of local module variables                    */
/******************************************************************************/


// variables for wakeup handling

static byte rb_WakeupTimer_mg;

#define cb_WAKEUP_FASTRETRIES_mg    3
#ifdef BUS_IDLE_DETECTION_ENABLED
static word rw_LINIdleTimer_mg;
#endif

#ifdef MASTER_ENABLED
#error: take care master node not supported at the moment 
// variables for schedule table
static byte rb_ActiveScheduleTable_g;   // active schedule table
static byte rb_PosInTable_g;            // Current Position
#endif


/******************************************************************************/
/*                     Prototypes of local functions                          */
/******************************************************************************/

#ifdef MASTER_NODE
static void sci_SendBreak(void);
#error: take care master node not supported at the moment 
#endif



#if ((LINBAUDRATE != 19200) && (LINBAUDRATE != 9600))
#error "Baudrate not supported"
#endif

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
  
  rb_SCI_Error_g = cb_LIN_NOERROR_g;
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
#ifdef BUS_IDLE_DETECTION_ENABLED
  
  rw_LINIdleTimer_mg = kLinTBusIdle;  // reset bus idle timer
#endif
  
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
  
#ifdef BUS_IDLE_DETECTION_ENABLED
  if (rw_LINIdleTimer_mg > 0)     // Idle timer running?
  {
    rw_LINIdleTimer_mg --;      // decrement idle timer
  }
  else
  {
    ApplLinBusSleep();          // call application notification function
  }
#endif
  rb_WDG_SCITaskCounter_g ++; 
}

/**************************************************************************
Syntax   : void sci_FastTask(void)
Object   : sci_FastTask()
Parameters : none
Return  : none
Calls   : (to be called every 1ms)
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code :
*************************************************************************/

__callt void sci_FastTask(void)
{
#ifdef MASTER_ENABLED
#error: take care master node not supported at the moment 
  static byte rb_TFrameMax_s;
  byte rb_Message_ID_l;
#endif
  
#ifdef MASTER_ENABLED
#error: take care master node not supported at the moment 
  if (rb_LINPhasis_g == cb_LIN_NORMAL_g)
  {
    if (rb_TFrameMax_s > 0)
    {
      rb_TFrameMax_s--;
    }
    else // TFrameMax over?
    {
      if ((rbi_WaitForSlavesResponse_mg == 1) || (rbi_StartTransmission_mg > 0))  // waiting for response on ID?
      {
        if (rbi_StartTransmission_mg > 0)   // Identifier not received
        {
          rb_SCI_Error_g |= cb_LIN_PHYSICALBUSERROR_g;    // set error flag
        }
        else // if ((rbi_IdentifierChecked_mg == 1) && (rbi_MessageReceived_mg == 0))
        {
          if (rb_RBPosition_mg < 2) // no data received from slave?
          {
            rb_SCI_Error_g |= cb_LIN_NORESPONSEERROR_g;    // set error flag
          }
          else
          {
            rb_SCI_Error_g |= cb_LIN_OVERTFRAMEMAX_g;    // set error flag
            rb_TFrameMax_s = 1;
          }
        }
        rbi_WaitForSlavesResponse_mg = 0;
        rbi_StartTransmission_mg = 0;
      }
      else if ((rbi_StartTransmission_mg == 0) && (rbi_WaitForSlavesResponse_mg == 0) && (rbi_StopCommunication_g == 0)) // No transmission in progress?
      {
        rb_PosInTable_g ++;     // next position in schedule table
        
        if (rb_PosInTable_g >= cab_LengthScheduleTabels_g[rb_ActiveScheduleTable_g]) // index not in table?
        {
          rb_PosInTable_g = 0;    // jump to first entry
        }
        
        // if (rb_LDWSState_g == cb_SYSTEM_DIAGNOSIS_g)
        {
          if (((cab_ScheduleTabels_g[rb_ActiveScheduleTable_g][rb_PosInTable_g]&0x3F) == cb_DIAGNOSIS_RESPONSE_g)
              && (rbi_DiagWaitForResponse_g == 0))      // don't Request response if there was no request
          {
            rb_PosInTable_g ++;     // next position in schedule table
            if (rb_PosInTable_g >= cab_LengthScheduleTabels_g[rb_ActiveScheduleTable_g]) // index not in table?
            {
              rb_PosInTable_g = 0;    // jump to first entry
            }
          }
          
          if ((cab_ScheduleTabels_g[rb_ActiveScheduleTable_g][rb_PosInTable_g] == cb_DIAGNOSIS_REQUEST_g)
              && ((rb_LINDiagRequest_g == 0) || (rbi_DiagWaitForResponse_g == 1)))      // don't send Request if there is none
          {
            rb_PosInTable_g ++;     // next position in schedule table
            if (rb_PosInTable_g >= cab_LengthScheduleTabels_g[rb_ActiveScheduleTable_g]) // index not in table?
            {
              rb_PosInTable_g = 0;    // jump to first entry
            }
          }
        }
        
        rab_WriteBuffer_mg[0] = cab_ScheduleTabels_g[rb_ActiveScheduleTable_g][rb_PosInTable_g];    // write ID in buffer
        
        // Set TFrameMax
        rb_Message_ID_l = (rab_WriteBuffer_mg[0] >> 3) & 0x07;
        
        rb_TFrameMax_s =  cab_TFrameMax_mg[cab_LinTxDataLen_g[rb_Message_ID_l]];
        
        //rb_bytes_to_send_mg = 1;
        TransmitIdentifier();   // start transmission of identifier
        TIMA_Start(cab_LinTxDataLen_g[rb_Message_ID_l]);   // start timeout counter
        rbi_WaitForSlavesResponse_mg = 1;
      }
    }
    // End Masters master task
  }
#endif
}

#ifdef MASTER_NODE
#error: take care master node not supported at the moment 
void sci_SendBreak(void)
{
  
#ifdef LINSCI_ENABLE
  LINSCICR2 |= 1; // set SBK-Bit to send break
  while (LINSCICR2 & 0x01 == 0);  // wait until SBK-Bit set
  LINSCICR2 &= ~1; // clear SBK-Bit
#else
  LINSCICR2 &= ~0x0C; // clear TE and RE
  LINSCI2ETPR=26;  //   9600baud
  LINSCIDR = 0x00;
  LINSCICR2 |= 0x0C;  // set TE and RE
#endif
}
#endif






