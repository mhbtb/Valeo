/*****************************************************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : SPI.c

Documentation reference : ASIC specification E.140.17A
Overview of the component : SPI interface to the RS ASIC

Evolution of the component : see PVCS Version control system

Initials   date   modification
*****************************************************************************************************************/
/****************************************************************************************************************/
/* History                                                                                                      */
/****************************************************************************************************************/
/* Date      VDR_Number     Description                                                                         */
/****************************************************************************************************************/
/* 18.03.10  VDR469     AL      do not recover SPI error                                                        */
/* 03.02.08  VDR_87             Misra Warning for MISRA Rule 101                                                */
/* 14.11.14  VCO_195    MP      QAC correction and checkin of Hex and map files for X007 release                */
/* 03.03.15  VCO_227    NB      Implement RAM Guard function                                                    */
/* 10.03.15  VCO_227    NB      Implement RAM Guard function                                                    */
/* 16.03.15  VDR_855    MP      Fix of the findings from the review of ASIC_Control_sr                          */
/* 24.03.15  VDR_861    MP      Inverted bytes when writing on spi are not checked                              */
/* 13.07.15  VDR_891    MP      SWITS_635: SPI communication error not set when the ASIC mode is corrupted      */
/********************************only once per cycle                                                            */
/****************************************************************************************************************/

/**
* \mainpage Rain Light Anti-Fogging Sensor
<!-- * \htmlinclude spi.c.html           -->
* \section intro_sec Introduction
*
* This document is generated automatically with doxygen, with the help of tags in
* the source code.
*
* \section install_sec Description of the different tabs
*
* \subsection step1 Main Page:
* The main tab contains a small introduction over the contents of this file.
*
* \subsection step2 Module / Interface Specification:
* Gives an overview over the Interface should be renamed to Interface Specification,
* but at the moment it is not possible to rename it.
* \subsection step3 Data Structures:
* The Data Structures tab contains a brief description of all specified data structures and data fields.
*
* \subsection step4 Files:
* The Files tab contains a brief description of all module files.
*
* \subsection step5 Related Pages:
* The Related Pages contains all existing pages for the FlashE2 module e.g. Integration Guidline, Compile Options,... .
*
* \file SPI.c
* \brief C File for the serieal peripheral interface "SPI.c".
*
* This module managed the communication on hardware layer between the ASIC E101.12 and the microController
* This component is responsible for the data transfer on the SPI interface.
* The SPI interface has to be used according the E101.12 specification. The microController is Master.
* The data interface to the ASIC_Control.c module is done via global variables.

* <!--  -->
* _b Source:     SPI.c
* _version       1.12
* _author        Andreas Laegler
* _author        SBA294
* _date          26-JUL-2007 08:08:38
* _todo          Still open points here
* <!--  -->

*****************************************************************************************************************/
/****************************************************************************************************************/
/*                  Integration Guidline                                                                        */
/****************************************************************************************************************/

/*****************************************************************************************************************
* \page integration Integration Guidline
* </p>
* <h2>Function calls</h2>
* <p>
* The application calls the function spi_init() once for initialisation.
* The functions SPI_Write_Byte() or SPI_WriteBlock() can be called for block or byte data transfer.
* The interrupt scheduling is done automaticaly, the flag rbi_SPI_activ_g monitors if the communication
* is active or completed.
* Commands and changes on AOUT can be seen on rb_ASIC_AnalogOutput_g.
*
*
* </p>
* <h2>Output variables</h2>
* <p>
* Errors are monitored eighter in the deticated return values or in the global
* variables.
*
* </p>
*****************************************************************************************************************/
/****************************************************************************************************************/
/*                             Compile options                                                                  */
/****************************************************************************************************************/
/*****************************************************************************************************************
* \page compileoptions Compile options
* </p>
* <h2>none compile options</h2>
* <p>
* </p>
*
* </p>
*/
/****************************************************************************************************************/
/*                   Common and module include-file                                                             */
/****************************************************************************************************************/
/* PRQA S 0781,759,436,434 EOF */ /* << 0781,436 03 03, unions needed >> */
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/* PRQA S 715 EOF *//*<< Data needs to be verified  >>*/
/* PRQA S 5900,5565,5540 EOF *//*<< Data needs to be verified  >>*/
/* PRQA S 0861,0862,5560,5830 EOF */ /* << Compiler specific Includes cannot be analysed by QA-C>> */
/** Include Files **/
/** /brief microController specific general defines include file*/
#include "ior5f109be.h"
#include "ior5f109be_ext.h"
/** /brief Declarations of intrinsic function*/
#include <intrinsics.h>
/** /brief Declarations input and output ports*/
#include "G5_projectDefs.h"
#include "G5_io.h"
#include "G5_check_sr.h"
#define _spi_sr_h_         /*Define for Single include of Global Header G5_spi.h*/

/** /brief Declarations of modul specific parameters and variables*/
#include "G5_spi_sr.h"
/** /brief Declarations variables used for lightsensor*/
#include "G5_IRlight.h"
/** /brief Declarations variables used ASIC Communication*/
#include "G5_ASIC_Control.h"
#include "G5_ASIC_Control_sr.h"
/** /brief Declarations macros used for SPI communication*/
#include "G5_Appli_lowinit.h"

#include "G5_DiagE2_projectconfig.h"


#undef _spi_sr_h_

/****************************************************************************************************************/
/*                   Declaration of local module variables                                                      */
/****************************************************************************************************************/
/** Module-global Constants **/
/** /brief Size of SPI Writebuffer*/
#define cb_SPI_WRITEBUFFERSIZE_mg (byte)16
/** /brief Size of SPI Readbuffer*/
#define cb_SPI_READBUFFERSIZE_mg  (byte)16
/** Module-global Variables **/

#pragma dataseg="RAM_GUARD" 
__no_init  byte rab_SPI_WriteBuffer_mg[cb_SPI_WRITEBUFFERSIZE_mg];
/** /brief SPI Readbuffer for Data transfer*/
__no_init  byte rab_SPI_ReadBuffer_mg[cb_SPI_READBUFFERSIZE_mg];
#pragma dataseg=default

/** /brief Number of Bytes to send from SPI_Writebuffer*/
static  byte rb_SPI_bytes_to_send_mg;
/** /brief Position in SPI_Writebuffer during data transfer*/
static  byte rb_SPI_WBPosition_mg ;
/** /brief Counter for Communication without SPI Errors*/
static  byte rb_communication_retries_mg;
/** Interface Functions **/


/****************************************************************************************************************/
/*                   Declaration of local module functions                                                      */
/****************************************************************************************************************/
static void spi_CommunicationFaultHandl(void);
__interrupt  void SPI_Interrupt(void);
void  SPI_int(void);
/** \brief Macro to start SPI-Communication*/
#define SPIStart()        po_Slave_Select_g=0; CSIIF00 = 0U; CSIMK00 = TRUE; SIR00 = 7; SOE0 = 1; SS0 |= 0x01;  \
                          while ((SSR00_bit.no6 == TRUE)&&(SSR00_bit.no5 == TRUE));while((SE0&0x01)==0);        \
                          SDR00 = (_1000_CSI00_DIVISOR | ((byte)rab_SPI_WriteBuffer_mg[rb_SPI_WBPosition_mg])); CSIMK00 = FALSE
#define SPIStop()    ST0 |= _0001_SAU_CH0_STOP_TRG_ON;               /* disable CSI00 */                      \
                     SOE0 &= ~_0001_SAU_CH0_OUTPUT_ENABLE;           /* disable CSI00 output */               \
                     CSIMK00 = 1U;                                   /* disable INTCSI00 interrupt */         \
                     CSIIF00 = 0U                                    /* clear INTCSI00 interrupt flag */

                       
                       
void set_rb_ASIC_SPI_ErrorFlag_g(byte a)
{
  DisableRamGuard();
  rb_ASIC_SPI_ErrorFlag_g = a;
  EnableRamGuard();
}
void set_rab_SPI_WriteBuffer_mg(byte rb_position_l, byte rb_Value_l)
{
  DisableRamGuard();
  rab_SPI_WriteBuffer_mg[rb_position_l] = rb_Value_l;
  EnableRamGuard();
}
void set_rab_SPI_ReadBuffer_mg(byte rb_position_l, byte rb_Value_l)
{
  DisableRamGuard();
  rab_SPI_ReadBuffer_mg[rb_position_l] = rb_Value_l;
  EnableRamGuard();
}
/*****************************************************************************************************************
Syntax   : void  spi_init(void)
Object   : spi_init()
Parameters : none
Return  : none
Calls   : in main.c at initialisation
******************************************************************************************************************
Inputs validation conditions:
none
*****************************************************************************************************************/
/**
* \brief
* This function initialises the SPI for data transmission to the E101.12
* The SPI is initialised as Master with a clock of 259KHz at 8Mzh controller clock.
*/

void spi_init(void)
{
  po_Slave_Select_g = 1;
  rbi_SPI_activ_g = FALSE;                // Set SPI Active Bit to TRUE
    
  po_SPI_MasterOut_g = TRUE;             //SPI MasterOut FALSE
  po_SPIClock_g = TRUE;                   //SPI CLOCK TRUE
  
  R_CSI00_Start();
}
/*****************************************************************************************************************
Syntax   : void  SPI_Write_Byte(void)
Object   : SPI_Write_Byte()
Parameters : byte to write on SPI to ASIC
Return  : none
Calls   : in ASIC Control.c
******************************************************************************************************************
Inputs validation conditions:
none
******************************************************************************************************************
Pseudo-code : Waits till SPI is free and Writes single byte to ASIC
*****************************************************************************************************************/
/**
* \brief
* This function checks if the SPI is free for new communication.
* If the SPI is used it waits and triggers the interrupt function
* If the SPI is free the datas will be written into the write buffer and the
* Communication started.
*/
__callt void SPI_Write_Byte(byte rb_byteToWrite_l)
{
  rab_SPI_ASICWriteBuffer_mg[0] = rb_byteToWrite_l;
  rb_SPI_Data_to_send_g = 1;
  SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
  rb_SPI_Data_to_send_g = 0;
}

/*****************************************************************************************************************
Syntax   : void  SPI_WriteBlock(void)
Object   : SPI_WriteBlock()
Parameters : byte to write on SPI to ASIC
Return  : none
Calls   : in ASIC Control.c
******************************************************************************************************************
Inputs validation conditions:
none
******************************************************************************************************************
Pseudo-code : Waits till SPI is free and Writes block to ASIC
*****************************************************************************************************************/
/**
* \brief
* This function checks if the SPI is free for new communication.
* If the SPI is used it waits and triggers the interrupt function
* If the SPI is free the datas will be written into the write buffer and the
* Communication started.
*/
__callt void SPI_WriteBlock(byte *rb_FirstbyteToWrite_l,byte rb_lenghtOfBlock)
{
  
  word rw_timoutCounter_l;
  byte i;
  
  rw_timoutCounter_l = 600;
  while ((rw_timoutCounter_l > 0)&&( rbi_SPI_activ_g == TRUE))
  {
    //    P0_bit.no0 = 1;
    if (SSR00_bit.no6 == FALSE )        /*SPI-Interrupt abfragen*/
    {
      SPI_int();          /*Interruptfunktion aufrufen*/
    }
    else if ((CSIMK00 == TRUE)|| (SAU0EN  == FALSE)) /*CSI Off ?*/
    {
      rbi_SPI_activ_g = FALSE;
    }
    if (rb_SPI_Active_ProblemCounter_g < 255)
    {
      rb_SPI_Active_ProblemCounter_g++;
    }
    rw_timoutCounter_l--;
    /*    P0_bit.no0 = 0;*/
  }
  rbi_SPI_activ_g = TRUE;
  po_Slave_Select_g=0;           // set earlier not to have Problems in Temperature
  for (i=0; i<rb_lenghtOfBlock; i++ )     // Copy data in Write buffer
  {
    set_rab_SPI_WriteBuffer_mg(i, (byte)(*rb_FirstbyteToWrite_l));
#pragma diag_suppress=Pm088 /*VDR_87 switch on Misra Warning for MISRA Rule 101*/
    rb_FirstbyteToWrite_l++;
#pragma diag_default=Pm088 /*VDR_87 switch on Misra Warning for MISRA Rule 101*/
  }
  rb_SPI_WBPosition_mg = 0;
  rb_SPI_bytes_to_send_mg = rb_lenghtOfBlock;
  
  SPIStart();
  rb_SPI_Data_to_send_g = 0;
}

/*****************************************************************************************************************
*    ROUTINE NAME : SPI_Interrupt
*    Description: Software-Interface between SPI and software sends datas via SPI
*                 and writes input datas into target variables
*
*    Parameters: none
*     ModulGlobal or Global:
*            input: rab_SPI_WriteBuffer_mg
*                   rb_SPI_WBPosition_mg	: Pointer in buffer for output data
*           output: rbi_ASIC_Communication_not_possible_g, rb_ASIC_EEPROM1_g,
*                   rb_ASIC_EEPROM2_g, rb_ASIC_EEPROM3_g, rb_IRLight_low_g,
*                   rb_IRLight_high_g, rb_real_ASIC_mode_g, rb_AminusB_g,
*                   rw_SPINoCommCounter_g, rbi_SPI_activ_g
*         internal: rab_SPI_ReadBuffer_mg, rb_communication_retries_mg
*
*****************************************************************************************************************/
/**
* \brief
* This is the interrupt function of the SPI.
* This function writes the recieved byte into the read buffer.
* The next byte is written into the sending buffer
* for a complete data transfer, the recieved and transmitted datas are compared
* Errors and states are written into global variables
*/

#pragma bank = 3
#pragma vector= INTCSI00_vect
__interrupt void SPI_Interrupt(void)
{
  SPI_int();

}

void  SPI_int(void)
{
  byte rb_idx_cksum_l;
  byte rb_ID_idx_l;
  byte rb_idx_Max_l = (sizeof(ras_ASIC_CtrReg_g))/sizeof(ras_ASIC_CtrReg_g[0]);
  byte rab_SPI_RcvCmd_l;
  while ((SSR00_bit.no6 == TRUE)&&(SSR00_bit.no5 == TRUE));    /* wait till communication is ready*/
  
  set_rab_SPI_ReadBuffer_mg(rb_SPI_WBPosition_mg,(byte)(SDR00&0x0FF));
  rb_SPI_WBPosition_mg++;
  if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg)
  {
    SPIStart();
  }
  else
  {
    byte rb_SPI_error_l=0;
    byte rb_i_bytes_rcv_l=0;
    byte rb_read_cmd_l = FALSE;
    byte rb_SPI_WrCmdByte_l;
    byte rb_SPI_RcvCmdByte_l;
    po_Slave_Select_g = 1;
    rb_SPI_WBPosition_mg = 0;
    rab_SPI_RcvCmd_l = (~rab_SPI_ReadBuffer_mg[0])<<1;
    /*check for the data received, first byte or the 1 byte commands*/
    if(rab_SPI_RcvCmd_l == (rab_SPI_WriteBuffer_mg[0]&0xFE))
    {
      /*check the inverted bytes for all commands except for the reading commands*/
      /* SM221 - SPI_ComChk: Inverted and shifted SPI command (first 7 bits) is returned on MISO - LS, RS error*/
      if((rab_SPI_RcvCmd_l&0xF0)==0xD0)
      {
        /*ASIC's Read ID*/
        for(rb_ID_idx_l=0; rb_ID_idx_l<3; rb_ID_idx_l++)
        {
          rb_ASIC_ID_g[rb_ID_idx_l] = rab_SPI_ReadBuffer_mg[rb_ID_idx_l+1];
        }
      }
      /*is read, write or STMeas commands?*/
      else if (((rab_SPI_WriteBuffer_mg[0]&0xC0)==0x40)
               || ((rab_SPI_WriteBuffer_mg[0]&0xC0)==0x80)
                 || ((rab_SPI_WriteBuffer_mg[0]&0xF8)==0x10))
      {
        rb_SPI_WrCmdByte_l = rab_SPI_WriteBuffer_mg[0];
        
        //        if ((rb_SPI_WrCmdByte_l&0xF8)!=0x10)
        for(rb_i_bytes_rcv_l=0;(rb_i_bytes_rcv_l<(rb_SPI_bytes_to_send_mg-1));rb_i_bytes_rcv_l++)
        {
          rb_SPI_RcvCmdByte_l = ((byte)((~rab_SPI_ReadBuffer_mg[rb_i_bytes_rcv_l])<<1));
          rb_SPI_WrCmdByte_l = rab_SPI_WriteBuffer_mg[rb_i_bytes_rcv_l];
          /*write command or STMeas?*/
          if (((rb_SPI_WrCmdByte_l&0xC0)!=0x80))// || ((rb_SPI_WrCmdByte_l&0xF8)==0x10))
          {
            if ((rb_SPI_RcvCmdByte_l==(rb_SPI_WrCmdByte_l&0xFE)) || (TRUE==rb_read_cmd_l))
            {
              rb_read_cmd_l = FALSE;
              /*is write command?*/
              if ((rb_SPI_WrCmdByte_l&0xC0)==0x40)
              {
                rb_i_bytes_rcv_l++;
                
                if((rab_SPI_WriteBuffer_mg[rb_i_bytes_rcv_l]&0xFE)!=((byte)((~rab_SPI_ReadBuffer_mg[rb_i_bytes_rcv_l])<<1)))
                {
                  rb_SPI_error_l = TRUE;
                  break;
                }
                if ((rb_SPI_WrCmdByte_l&0xC1)==0x41)
                {
                  rb_i_bytes_rcv_l++;
                  if((rab_SPI_WriteBuffer_mg[rb_i_bytes_rcv_l]&0xFE)!=((byte)((~rab_SPI_ReadBuffer_mg[rb_i_bytes_rcv_l])<<1)))
                  {
                    rb_SPI_error_l = TRUE;
                    break;
                  }
                }
              }
              /*is STMeas command not the last command?*/
              else if (rb_i_bytes_rcv_l!=(rb_SPI_bytes_to_send_mg-1))
              {
                rb_SPI_error_l = TRUE;
                break;
              }
            }
            else
            {
              rb_SPI_error_l = TRUE;
              break;
            }
          }
          /*read command?*/
          else if ((rb_SPI_WrCmdByte_l&0x80)==0x80)
          {
            rb_idx_cksum_l = rb_i_bytes_rcv_l;
            rb_read_cmd_l = TRUE;
            /* SM223 - Operation mode is added to the SPI checksum (+ MODE[2:0])*/
            word rw_ChksumCalc_l = rab_SPI_WriteBuffer_mg[rb_idx_cksum_l];
            rw_ChksumCalc_l += rab_SPI_ReadBuffer_mg[rb_idx_cksum_l+1];
            rw_ChksumCalc_l += rb_CurMode_g;
            rw_ChksumCalc_l += 1;
            
            if(rab_SPI_WriteBuffer_mg[rb_idx_cksum_l]&0x01)
            {
              rw_ChksumCalc_l += rab_SPI_ReadBuffer_mg[rb_idx_cksum_l+2];
              rb_idx_cksum_l+=3;
            }
            else
            {
              rb_idx_cksum_l+=2;
            }
            
            /* SM222 - SPI error is added to the SPI checksum*/
            if(((rw_ChksumCalc_l&0xFF)!=rab_SPI_ReadBuffer_mg[rb_idx_cksum_l]) &&
               (((rw_ChksumCalc_l+0x55)&0xFF)!=rab_SPI_ReadBuffer_mg[rb_idx_cksum_l]) )
            {
              
              /*was the mode changed from LRAMP to the next mode?*/
              if (rb_CurMode_g != CB_ASIC_LRAMP_MD)
              {
                /*checksum recieved differs than the one calculated; set error flag*/
                rb_SPI_error_l = TRUE;
                break;
              }
              else
              {
                /* SM223 - Operation mode is added to the SPI checksum (+ MODE[2:0])*/
                /*calculate the checksum in case that the ramping is finished, considering the next valid mode*/
                rw_ChksumCalc_l -= rb_CurMode_g;
                rw_ChksumCalc_l += CB_ASIC_LOOP2_MD;
                
                /* SM222 - SPI error is added to the SPI checksum*/
                if( ((rw_ChksumCalc_l&0xFF)!=rab_SPI_ReadBuffer_mg[rb_idx_cksum_l]) &&
                   (((rw_ChksumCalc_l+0x55)&0xFF)!=rab_SPI_ReadBuffer_mg[rb_idx_cksum_l]) )
                {
                  /*checksum received differs than the one calculated; set error flag*/
                  rb_SPI_error_l = TRUE;
                  break;
                }
                else
                {
                  if(rab_SPI_ReadBuffer_mg[rb_idx_cksum_l] == ((rw_ChksumCalc_l+0x55)&0xFF))
                  {
                    rb_SPI_error_l = TRUE;
                    set_rb_ASIC_SPI_ErrorFlag_g(TRUE);
                    break;
                  }
                  else/*NOP*/
                  { }
                  /* SM223 - Operation mode is added to the SPI checksum (+ MODE[2:0])*/
                  rb_PrevMode_g = rb_CurMode_g;
                  rb_CurMode_g = CB_ASIC_LOOP2_MD;
                }
              }
            }
            else if(((rw_ChksumCalc_l+0x55)&0xFF) == rab_SPI_ReadBuffer_mg[rb_idx_cksum_l])
            {
              rb_SPI_error_l = TRUE;
              rw_ChksumCalc_l += 0x55;
              set_rb_ASIC_SPI_ErrorFlag_g(TRUE);
              break;
            }
            /*no errors while calculating the checksum*/
            if((FALSE==rb_SPI_error_l) && (FALSE==rb_ASIC_SPI_ErrorFlag_g))
            {
              byte j=0;
              /*store the registers' values for each read command*/
              for(j=0; j<rb_idx_Max_l; j++)
              {
                if(ras_ASIC_CtrReg_g[j].addr == ((rb_SPI_WrCmdByte_l>>1)&0x1F))
                {
                  rb_i_bytes_rcv_l++;
                  ras_ASIC_CtrReg_g[j].val = rab_SPI_ReadBuffer_mg[rb_i_bytes_rcv_l];
                  if(TRUE==(rb_SPI_WrCmdByte_l&0x01))
                  {
                    rb_i_bytes_rcv_l++;
                    ras_ASIC_CtrReg_g[j+1].val = rab_SPI_ReadBuffer_mg[rb_i_bytes_rcv_l];
                    /*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
                    if((IDX_INTVH_REG == j)||(IDX_INTVL_REG == j))
                    {
                      rb_newRSconvRcv_g = TRUE;
                      if((ras_ASIC_CtrReg_g[IDX_INTVL_REG].val&0x1)==1)
                      {
                        rb_LOpenIntegrationDone_g = TRUE;
                      }
                      else if(CB_ASIC_LOPEN_MD==rb_CurMode_g)
                      {
                        rb_NextSPI_Request_g = CB_STMEAS_RQ;
                      }
                      if (rw_INTV10bit_min_g > rw_INTV10bit_g)
                      {
                        rw_INTV10bit_min_g = rw_INTV10bit_g;
                      }
                      if (rw_INTV10bit_g > rw_INTV10bit_max_g)
                      {
                        rw_INTV10bit_max_g = rw_INTV10bit_g;
                      }
                      
                      if (rw_REGV_min_g > rw_REGV_Voltage_g)
                      {
                        rw_REGV_min_g = rw_REGV_Voltage_g;
                      }
                      if (rw_REGV_Voltage_g > rw_REGV_max_g)
                      {
                        rw_REGV_max_g = rw_REGV_Voltage_g;
                      }
                      
                      if(rw_LIN_INTV10bit_min_g > rw_INTV10bit_g)
                      {
                        rw_LIN_INTV10bit_min_g = rw_INTV10bit_g;
                      }
                      if (rw_INTV10bit_g > rw_LIN_INTV10bit_max_g)
                      {
                        rw_LIN_INTV10bit_max_g = rw_INTV10bit_g;
                      }
                    }
#endif /*_NO_RAIN_*/
                  }
                  
                  if((IDX_ADCVH_REG == j) || (IDX_AVGVH_REG == j))
                  {
                    if (rb_NextMUXCfg_g != NO_CURRENT_MEAS)
                    {
                      rb_newADconvRcv_g = TRUE;
                    }
                  }
                  if(IDX_STATH_REG == j)
                  {
                    rb_newAsicSTAT_g = TRUE;
                  }
                  break;
                }
              }
            }
          }
          else
          {
            rb_SPI_error_l = TRUE;
            break;
          }
        }
      }
      else
      {
        rb_SPI_RcvCmdByte_l = ((byte)((~rab_SPI_ReadBuffer_mg[rb_i_bytes_rcv_l])<<1));
        rb_SPI_WrCmdByte_l = rab_SPI_WriteBuffer_mg[rb_i_bytes_rcv_l];
        
        if (rb_SPI_RcvCmdByte_l==(rb_SPI_WrCmdByte_l&0xFE))
        {
          rb_read_cmd_l = FALSE;
          /*is one byte command?*/
          if (rb_i_bytes_rcv_l!=(rb_SPI_bytes_to_send_mg-1))
          {
            rb_SPI_error_l = TRUE;
          }
        }
        else
        {
          rb_SPI_error_l = TRUE;
        }
      }
    }
    else
    {
      /* SM221 - SPI_ComChk: Inverted and shifted SPI command (first 7 bits) is returned on MISO - LS, RS error*/
      /*set error flag*/
      rb_SPI_error_l = TRUE;
    }
    if((rb_SPI_error_l != TRUE)&&(rb_ASIC_SPI_ErrorFlag_g != TRUE))
    {
      if ((rab_SPI_RcvCmd_l&0xC0)!=0x80)
      {
        if ((rab_SPI_RcvCmd_l&0xD0) == 0xC0)
        {
          if(rab_SPI_WriteBuffer_mg[0] == CB_ASIC_LRETURN)
          {
            if ((rb_PrevMode_g != CB_ASIC_LSTOP_MD) && (rb_CurMode_g != CB_ASIC_LOOP1_MD)
                && (rb_CurMode_g != CB_ASIC_LOOP2_MD))
            {
              rb_CurMode_g = rb_PrevMode_g;
              rb_PrevMode_g = CB_ASIC_LSTOP_MD;
            }
            else
            {
              /*update the mode*/
              rb_PrevMode_g = rb_CurMode_g;
              rb_CurMode_g = ((rab_SPI_WriteBuffer_mg[0]>>1)&0x07);
            }
          }
          else
          {
            if(rb_CurMode_g != ((rab_SPI_WriteBuffer_mg[0]>>1)&0x07))
            {
              rb_PrevMode_g = rb_CurMode_g;
              rb_CurMode_g = ((rab_SPI_WriteBuffer_mg[0]>>1)&0x07);
            }
          }
        }
        else if(ASIC_MEAS_FREQ == rab_SPI_RcvCmd_l)
        {
          if((rab_SPI_WriteBuffer_mg[rb_SPI_bytes_to_send_mg-1]&0x07)==2)
          {
            R_TAU0_Channel6_Start();
          }
        }
      }
      
      ASIC_Control_ASIC_ErrFlags_Check();
      
      if(rw_SPINoCommCounter_g>0)
      {
        rw_SPINoCommCounter_g --;
      }
      else
      {
        rbi_Check_LS_NoCommunication_g = FALSE;
      }
      
      if(rb_NextSPI_Request_g == CB_STMEAS_RQ)
      {
        if((rb_ASIC_Sched_Config_g & 0x20) == 0)
        {
          /*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
          
          set_rab_SPI_WriteBuffer_mg(0,0x16);
          if (CB_ASIC_LOPEN_MD == rb_CurMode_g)
          {
            rbi_StandbyModulatorIntegrating_g = TRUE;
//            set_rab_SPI_WriteBuffer_mg(0,0x16);
          }
#else
          set_rab_SPI_WriteBuffer_mg(0,ASIC_START_MEAS);
#endif /*_NO_RAIN_*/
        }
        else
        {
          set_rab_SPI_WriteBuffer_mg(0,ASIC_START_MEAS);
        }
        //rb_SPI_Data_to_send_g = 1;
        rb_SPI_bytes_to_send_mg = 1;
        rb_NextSPI_Request_g = CB_NO_NEXT_RQ;
        SPIStart();
      }
      
      
    }
    else    /* SPI Error! */
    {
      if (rb_ASIC_SPI_ErrorFlag_g == FALSE)
      {
        spi_CommunicationFaultHandl();
      }
      else
      {
        set_rb_ASIC_SPI_ErrorFlag_g(FALSE);
        /*0x81 - Read2 Mask for writing the registers*/
        set_rab_SPI_WriteBuffer_mg(0,(byte)((ras_ASIC_CtrReg_g[IDX_STATH_REG].addr<<1)|0x81));
        /*NOP byte sent to ASIC during which the data and checksum are received*/
        set_rab_SPI_WriteBuffer_mg(1,0x2A);
        set_rab_SPI_WriteBuffer_mg(2,0x2A);
        set_rab_SPI_WriteBuffer_mg(3,0x2A);
        rb_SPI_bytes_to_send_mg = 4;
        
        if(CASE_ASIC_CNT_MD_STANDBY==rb_ASIC_ControlMode_g)
        {
//          set_rab_SPI_WriteBuffer_mg(3,0x16);
          rb_NextSPI_Request_g = CB_STMEAS_RQ;
        }
        SPIStart();
      }
      
      if (rw_SPINoCommCounter_g < (MAX_SPI_NO_COMM_CNT-SPI_NO_COMM_INCREMENT))
      {
        rw_SPINoCommCounter_g += SPI_NO_COMM_INCREMENT;
      }
      else
      {
        rbi_Check_LS_NoCommunication_g = TRUE;
      }
      
      if (rb_StaticNoCommunicationCounter_g<255)
      {
        rb_StaticNoCommunicationCounter_g++;
      }
      else
      {}
      
      if(TRUE==rb_firstReadComm_g)
      {
        rb_firstReadComm_g=FALSE;
        
        if(rb_StaticNoCommunicationCounter_g<255)
        {
          rb_StaticNoCommunicationCounter_g--;
        }
        else
        {}
        
        rw_SPINoCommCounter_g -= SPI_NO_COMM_INCREMENT;
        
      }
      else
      {}
    }
    if(SSR00_bit.no6 == FALSE)
    {
      CSIMK00 = 1U;                                   /* disable INTCSI00 interrupt */
      SOE0 &= (~_0001_SAU_CH0_OUTPUT_ENABLE);           /* disable CSI00 output */
      rbi_SPI_activ_g=0;
    }
  }
}

/*  Datum: Mittwoch, 23. August 2000 und File: spi.c
******************************************************************************************************************
*    Function: <spi_CommunicationFaultHandl>
******************************************************************************************************************
*
*    Description: Creates a read request for the ASIC see defined global controlconstans
*
*
*    Parameters: none
*
*     ModulGlobal: rab_SPI_WriteBuffer_mg : Buffer for output data on spi
*		 rb_SPI_WBPosition_mg	: Pointer in buffer for output data
*		 rb_SPI_bytes_to_send_mg : count of bytes to send (highest rb_SPI_WBPosition_mg+1)
*        rbi_SPI_activ_g : indicates if spi is active
*    Subroutines: ISR_spi_recieve, ISR_spi_transmit
*****************************************************************************************************************/
/**
* \brief
* This function tries to recover the communication on the SPI.
*/
void spi_CommunicationFaultHandl(void)
{
  if (rb_communication_retries_mg < 3)
  {
    SPIStart();
    rb_communication_retries_mg++;
  }
  else if (rb_communication_retries_mg == 3)
  {
    spi_init();
    SPIStart();
    rb_communication_retries_mg++;
  }
  else
  {
    rbi_SPI_activ_g=0;
  }
}