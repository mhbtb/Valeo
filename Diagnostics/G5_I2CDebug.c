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
/*   Source: d:/workset/gen3_5/i2cdebug.c  */
/*   Revision:   1.6   */
/*   Author:   SBA272   */
/*   Date:   Mar 29 2006 14:20:52   */
/******************************************************************************/
/*   MODULE: I2C Handler to send Debug information as a slave device
FILE:                                                                    */
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Name    Description                                       */
/*----------------------------------------------------------------------------*/
/* 15.Mar11   VSC_4        FS    Implement compiler defines project related, also QAC-defines*/
/* 26.05.10   VDR_523      AL      reomve compiler warnings*/
/* 20.01.10   VDR_409      AL    allow nested interrupt for LIN-synchrinisation*/
/* 11.06.08   VDR_227      FS    Prepare Files for Lada-Project                */
/* 11.08.2014 VDR_800     NB      I2C debug Timeout implementation in case of error */
/* 15.10.2014 VCO_189     MPi/RFi      I2C debug configuration 2 */
/* 18.11.2014 VCO_189      DEBUG:Change the I2C debug data mapping            */
/* 18.11.2014 VCO_195      QAC correction            */
/* 03.03.15   VCO_227    NB     Implement RAM Guard function */
/* 13.07.15   VDR_868   NB      QAC and Polyspace fixing for SW009 Release    */
/* 30.07.2018 VCO_496   AS      Dummy comment to overcome serena problem */




/* PRQA S 0436,0781,434 EOF */ /* << have to be used this way to access the ports>> */
/* PRQA S 0759 EOF */ /* << union is sopported by this compiler>>*/
/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 5540,5560,5565,5900 EOF *//*<< Data needs to be verified  >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/* PRQA S 3138 EOF */ /* << using of macros from automatic generated code >>*/
/******************************************************************************/
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                      Common and module include file                        */
/******************************************************************************/


#include "ior5f109be.h"
#include "ior5f109be_ext.h"
#include "G5_projectDefs.h"
#include <intrinsics.h>

#define _i2cdebug_c_
#include "G5_i2cdebug.h"
#undef _i2cdebug_c_
#include "G5_E2ProjectConfig.h"
#include "G5_HumTemp.h"

/******************************************************************************/
/*                           Other files included                             */
/******************************************************************************/

#include "G5_IRlight.h"
#include "G5_lininclude.h"

#include "G5_diagnose.h"
#include "G5_Check_sr.h"
#include "G5_rainsens.h"
#include "G5_io.h"
#include "G5_ASIC_Control.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_DippedBeam_sr.h"
#include "G5_spi_sr.h"
#include "G5_rs_task.h"
#include "G5_rs_signal.h"


/******************************************************************************/
/*                     Declaration of local module macros                     */
/******************************************************************************/

/******************************************************************************/
/*                   Declaration of local module variables                    */
/******************************************************************************/


static  Flag uF_I2CDBGFlag_g;
#define rbi_ComActive_mg        uF_I2CDBGFlag_g.Bit.B0

#define rbi_ComDirection_mg     uF_I2CDBGFlag_g.Bit.B1


#define po_EEProm_SCL_l             P6_bit.no0
#define po_EEProm_SCL_OUT_DIRECTION_l      PM6_bit.no0 //GEN 3.5

#define po_EEProm_SDA_l              P6_bit.no1
#define po_EEProm_SDA_OUT_DIRECTION_l      PM6_bit.no1 //GEN 3.5


#define cb_I2CRECEIVE_mg         0
#define cb_I2CTRANSMITT_mg       1



static byte rb_I2CData_mg;
static byte rb_AddrHighByte_mg;
static byte rb_AddrLowByte_mg;
static byte rb_WriteResult_mg;
static byte rb_FirstCall_mg;
                                //0123456789012345678901234567890 
static const byte cab_Debug_ID_g[]    ="SW:     ;HW:  ;SN:        ;DC: ;"; /*"SW:X005D;HW:04;SN:4216;DC:2;";*/


/******************************************************************************/
/*                     Prototypes of local functions                          */
/******************************************************************************/

static byte I2CDbg_GetValue(byte rb_Address_l);
static byte ReadMemoryData(void);
static void WriteMemoryData(void);
static int getI2CDbg(int index);
static int nextI2CDebugIdx(void);

/**************************************************************************
Syntax   :    void EEProm_Init(void)
Object   :    EEProm_Init()
Parameters :  none
Return  :     none
Calls   :     eeprom.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code :
*************************************************************************/
#define _55_IICA0_IICWH_VALUE                    (0x55U)
#define _4C_IICA0_IICWL_VALUE                    (0x4CU)
#define _01_IICA_fCLK_HALF                       (0x01U)   /* 2 clock of dividing frequency operation (fCLK/2) */

#define cb_ADDR_CONTROL     0
#define cb_ADDR_HIGH_BYTE   1
#define cb_ADDR_LOW_BYTE    2
#define cb_WRITE_RESULT     3
#define cb_WRITE_DATA       4
#define cb_READ_DATA        5
void I2CDbg_Init(void)
{
  
  
  rbi_ComActive_mg = FALSE;  // no transmission
  
  IICA0EN = 1U; /* supply IICA0 clock */
  IICE0 = 0U; /* disable IICA0 operation */
  IICAMK0 = 1U; /* disable INTIICA0 interrupt */
  IICAIF0 = 0U; /* clear INTIICA0 interrupt flag */
  /* Set INTIICA0 low priority */
  IICAPR10 = 1U;
  IICAPR00 = 1U; 
  /* Set SCLA0, SDAA0 pin */
  P6 &= 0xFCU;
  PM6 |= 0x03U;
  SMC0 = 0U;
  IICWL0 = _4C_IICA0_IICWL_VALUE;
  IICWH0 = _55_IICA0_IICWH_VALUE;
  IICCTL01 &= (byte)~_01_IICA_fCLK_HALF;
  SVA0 = cb_I2CSLAVEADDRESS_g;
  STCEN0 = 1U;
  IICRSV0 = 1U;
  SPIE0 = 0U;
  WTIM0 = 1U;
  ACKE0 = 1U;
  IICAMK0 = 0U;
  IICE0 = 1U;
  LREL0 = 1U;
  /* Set SCLA0, SDAA0 pin */
  PM6 &= 0xFCU;
  
  rb_I2CDebugTimeout_g = 0xFF; /* VDR_800 */
}

#pragma vector = INTIICA0_vect
__interrupt void vI2CDbg(void)
{
  static byte rb_I2CAddress_mg;
  static byte rb_NextState_mg;
  static byte rb_AddressControl_mg;
  
  rb_I2CDebugTimeout_g = 0; /* VDR_800 */
  //  __asm("clr1 psw.1"); /*VDR_409 priority set to high-level for the execution time*/
  __enable_interrupt(); /*VDR_409 nested interrupts allowed*/
  
  if (SPD0 == 1)    // Stop condition detected?
  {
    rbi_ComActive_mg = FALSE;  // end transmission
    IICA0 = 0xFF;
  }
  else if (STD0 == 1)  // Start condition detected?
  {
    if (COI0 == 1)    // Address match?
    {
      rbi_ComDirection_mg = TRC0;      // get Communication direction
      rbi_ComActive_mg = TRUE;         // start communication
      if (rbi_ComDirection_mg == cb_I2CRECEIVE_mg)    // in receive mode?
      {
        rb_NextState_mg = cb_ADDR_CONTROL;    
        IICA0 = 0xFF;
      }
      else
      {
        if((rb_AddressControl_mg == 0x83))
        {
          rb_I2CData_mg = rb_WriteResult_mg;
        }
        IICA0 = rb_I2CData_mg; // I2CDbg_GetValue(rb_I2CAddress_mg); // send first data byte rb_I2CAddress_mg
        
        // rb_I2CAddress_mg++;     // increase Address
      }
    }
    else
    {
      rbi_ComActive_mg = FALSE;  // end transmission
      IICA0 = 0xFF;
    }
  }
  else
  {
    if (rbi_ComActive_mg == TRUE) // transmission started with this node?
    {
      if ((rbi_ComDirection_mg == cb_I2CTRANSMITT_mg) // in receive mode? //
          && (ACKD0 == 1)) // Acknowledge was detected?
      {
        if((rb_AddressControl_mg & 0x80) == 0)
        {
          IICA0 = I2CDbg_GetValue(rb_I2CAddress_mg); // send next data byte
          rb_I2CAddress_mg++;     // increase Address
          
        }
        else if((rb_AddressControl_mg == 0x83))
        {
          rb_FirstCall_mg = 0;
          WriteMemoryData();
          IICA0 = rb_I2CData_mg;
        }
        else if((rb_AddressControl_mg == 0x80))
        {
          if(ReadMemoryData() == 0xFF )
          {
            IICA0 = 0xFF;
          }
          else
          {
            IICA0 = rb_I2CData_mg;
          }
          
          
          
        }
        else
        {
          /* For QAC */
        }
      }
      else if (rbi_ComDirection_mg == cb_I2CRECEIVE_mg) // in receive mode?
      {
        
        switch(rb_NextState_mg)
        {
        case cb_ADDR_CONTROL:
          {
            rb_AddressControl_mg = IICA0; 
            if((rb_AddressControl_mg & 0x80) == 0)
            {
              rb_I2CAddress_mg = IICA0;     // read address
              rb_I2CData_mg = rb_I2CAddress_mg;
              IICA0 = 0xFF;  // SDA High impedance
            }
            else if((rb_AddressControl_mg == 0x80)||(rb_AddressControl_mg == 0x81)||(rb_AddressControl_mg == 0x83))
            {
              rb_NextState_mg = cb_ADDR_HIGH_BYTE;
              
            }
            
            else{}
          }
          break;
        case cb_ADDR_HIGH_BYTE:
          {
            rb_AddrHighByte_mg = IICA0;
            rb_NextState_mg = cb_ADDR_LOW_BYTE;
            
          }
          break;
        case cb_ADDR_LOW_BYTE:
          {
            rb_AddrLowByte_mg = IICA0;
            if((rb_AddressControl_mg == 0x81))
            {
              rb_NextState_mg = cb_WRITE_DATA;
            }
            else if((rb_AddressControl_mg == 0x80))
            {
              rb_NextState_mg = cb_READ_DATA;
              (void)ReadMemoryData();
              
            }
            else if((rb_AddressControl_mg == 0x83))
            {
              
              rb_NextState_mg = cb_WRITE_RESULT;
              rb_FirstCall_mg = 0;
              if(rb_WriteResult_mg == 0x78)
              {
                WriteMemoryData();
              }
            }
            else{}
          }
          break;       
        case cb_WRITE_DATA:
          {
            rb_I2CData_mg = IICA0;
            rb_FirstCall_mg = 1;
            WriteMemoryData();
          }
          
          break; 
          
        default:
          
          break;
          
        } 
        IICA0 = 0xFF;  // SDA High impedance
      }
      else
      {
        rbi_ComActive_mg = FALSE;  // end transmission
        IICA0 = 0xFF;
      }
    }
    else
    {
      IICA0 = 0xFF;
    }
  }
  
  
}

static byte ReadMemoryData(void)
{
  byte rb_Status_l;
  word rw_TempAddr_l;
  
  rb_Status_l = 0;
  l_u8_wr_MasterReqB0(cb_TA_DEVELOPEMENT_s);
  l_u8_wr_MasterReqB1(5);
  l_u8_wr_MasterReqB2(cb_REQUEST_UPLOAD_s);
  l_u8_wr_MasterReqB3(rb_AddrHighByte_mg);
  l_u8_wr_MasterReqB4(rb_AddrLowByte_mg);
  l_u8_wr_MasterReqB5(0);
  l_u8_wr_MasterReqB6(5);
  ApplLinMasterReqFrmFct();
  (void)ApplLinSlaveCmdFrmFct();
  rb_ResponseToSend_g = 0;
  rb_Diagnosticstate_g = 0;
  l_u8_wr_MasterReqB0(0xff);/* send nothing */
  if(l_u8_rd_SlaveRespB2() == 0x75)
  {
    l_u8_wr_MasterReqB0(cb_TA_DEVELOPEMENT_s);
    l_u8_wr_MasterReqB1(5);
    l_u8_wr_MasterReqB2(cb_TRANSFER_DATA_REQUEST_s);
    ApplLinMasterReqFrmFct();
    (void)ApplLinSlaveCmdFrmFct();
    rb_ResponseToSend_g = 0;
    rb_Diagnosticstate_g = 0;
    l_u8_wr_MasterReqB0(0xff);/* send nothing */
    if(l_u8_rd_SlaveRespB2() == 0x76)
    {
      rb_I2CData_mg = l_u8_rd_SlaveRespB3();
    }
    else
    {
      rb_Status_l = 0xFF;
      ACKE0 = 0U; /* Disable ACK for control byte */
    }
  }
  else
  {
    rb_Status_l = 0xFF;
    ACKE0 = 0U; /* Disable ACK for control byte */
  }
  
  rw_TempAddr_l = (((word)rb_AddrHighByte_mg << 8) | (rb_AddrLowByte_mg)); 
  rw_TempAddr_l++;
  rb_AddrHighByte_mg = (byte)(rw_TempAddr_l >> 8);
  rb_AddrLowByte_mg =  (byte)(rw_TempAddr_l); 
  
  return(rb_Status_l); 
}

static void WriteMemoryData(void)
{
  if(rb_FirstCall_mg == 1)
  {
    
    l_u8_wr_MasterReqB0(cb_TA_DEVELOPEMENT_s);
    l_u8_wr_MasterReqB1(5);
    l_u8_wr_MasterReqB2(cb_REQUEST_DOWNLOAD_s);
    l_u8_wr_MasterReqB3(rb_AddrHighByte_mg);
    l_u8_wr_MasterReqB4(rb_AddrLowByte_mg);
    l_u8_wr_MasterReqB5(0);
    l_u8_wr_MasterReqB6(1);
    ApplLinMasterReqFrmFct();
    (void)ApplLinSlaveCmdFrmFct();
    rb_ResponseToSend_g = 0;
    rb_Diagnosticstate_g = 0;
    l_u8_wr_MasterReqB0(0xff);/* send nothing */ 
    
    if(l_u8_rd_SlaveRespB2() == 0x74)
    {
      l_u8_wr_MasterReqB0(cb_TA_DEVELOPEMENT_s);
      l_u8_wr_MasterReqB1(2);
      l_u8_wr_MasterReqB2(cb_TRANSFER_DATA_REQUEST_s);
      l_u8_wr_MasterReqB3(rb_I2CData_mg);
      ApplLinMasterReqFrmFct();
      (void)ApplLinSlaveCmdFrmFct();
      l_u8_wr_MasterReqB0(0xff);/* send nothing */ 
      
      if(l_u8_rd_SlaveRespB2() == 0x76)
      {
        rb_WriteResult_mg = 0;
      }
      else
      {
        rb_WriteResult_mg = l_u8_rd_SlaveRespB4();
      }
    }
    else
    {
      rb_WriteResult_mg = l_u8_rd_SlaveRespB4();
    }
  }
  else
  { 
    l_u8_wr_MasterReqB0(cb_TA_DEVELOPEMENT_s);
    l_u8_wr_MasterReqB1(2);
    l_u8_wr_MasterReqB2(cb_TRANSFER_DATA_REQUEST_s);
    l_u8_wr_MasterReqB3(rb_I2CData_mg);
    (void)ApplLinSlaveCmdFrmFct();
    rb_ResponseToSend_g = 0;
    rb_Diagnosticstate_g = 0;
    l_u8_wr_MasterReqB0(0xff);/* send nothing */ 
    
    if(l_u8_rd_SlaveRespB2() == 0x76)
    {
      rb_WriteResult_mg = 0;
    }
    else
    {
      rb_WriteResult_mg = l_u8_rd_SlaveRespB4();
    }  
  } 
}


static byte I2CDbg_GetValue(byte rb_Address_l) {
#ifdef ASIC_TEST
  static word rw_INTV10bit_min_g_temp;
  static word rw_INTV10bit_max_g_temp;
#endif
  byte rb_Data_l = 0;
  //  static word rw_REGV_min_g_temp;
  //  static word rw_REGV_max_g_temp;
  
  if (rb_I2C_Debug_Config_g == 0) /*0 :new configuration 1:old configuration */
  {
    switch (rb_Address_l)
    {
#ifdef ASIC_TEST
      
      // Block 0
    case 0:
      //    rw_REGV_min_g_temp = rw_REGV_min_g;
      //    rw_REGV_max_g_temp = rw_REGV_max_g;
      rw_REGV_min_g = 0xFFF;
      rw_REGV_max_g = 0;
      rb_Data_l = (byte) (get_rw_FW_light16bit_g()/*rw_REGV_min_g_temp*/>> 8);
      break;
    case 1:
      rb_Data_l = (byte) (get_rw_FW_light16bit_g()/*rw_REGV_min_g_temp*/);
      break;
    case 2:
      rb_Data_l = (byte) (get_rw_IR_light16bit_g()/*rw_REGV_max_g_temp*/>> 8);
      break;
    case 3:
      rb_Data_l = (byte) (get_rw_IR_light16bit_g()/*rw_REGV_max_g_temp */);
      break;
    case 4:
      rb_Data_l = (byte) (get_rw_Amb_light16bit_g() >> 8);
      break;
    case 5:
      rb_Data_l = (byte) (get_rw_Amb_light16bit_g());
      break;
    case 6:
      rb_Data_l = (byte) (rw_Solar_light16bit_1_g >> 8);
      break;
    case 7:
      rb_Data_l = (byte) (rw_Solar_light16bit_1_g);
      break;
      
      // Block 1
      
    case 8:
      rb_Data_l = (byte) (rw_Solar_light16bit_2_g >> 8);
      break;
    case 9:
      rb_Data_l = (byte) (rw_Solar_light16bit_2_g);
      break;
    case 10:
      rb_Data_l = (byte) (get_rw_ALS6_ASIC_g() >> 2);
      break;
    case 11:
      rb_Data_l = (byte) (get_rw_ALS6_ASIC_g() << 6) | (byte) (get_rw_INREC_ASIC_g() >> 4);
      break;
    case 12:
      rb_Data_l = (byte) (get_rw_INREC_ASIC_g() << 4) | (byte) (get_rw_INREC_INC_ASIC_g() >> 6);
      break;
    case 13:
      rb_Data_l = (byte) (get_rw_INREC_INC_ASIC_g() << 2);
      break;
    case 14:
      rb_Data_l = rb_StaticNoCommunicationCounter_g /*rub_LengthCounter*/;
      break;
    case 15:
      rb_Data_l = (byte)(rw_SPINoCommCounter_g>>8) /*rub_PulseCounter*/;
      break;
      
      // Block 2
      
    case 16:
      rb_Data_l = (byte) (get_rw_ALS1_ASIC_g() >> 2);
      break;
    case 17:
      rb_Data_l = (byte) (get_rw_ALS1_ASIC_g() << 6) | (byte) (get_rw_ALS2_ASIC_g() >> 4);
      break;
    case 18:
      rb_Data_l = (byte) (get_rw_ALS2_ASIC_g() << 4) | (byte) (get_rw_ALS2_INC_ASIC_g() >> 6);
      break;
    case 19:
      rb_Data_l = (byte) (get_rw_ALS2_INC_ASIC_g() << 2) | (byte) (/*get_rw_ALS3_ASIC_g()*/ 0x3FF>> 8);
      break;
    case 20:
      rb_Data_l = (byte) (0x3FF /*get_rw_ALS3_ASIC_g()*/);
      break;
    case 21:
      rb_Data_l = (byte) (0x3FF /*get_rw_ALS4_ASIC_g()*/ >> 2);
      break;
    case 22:
      rb_Data_l = (byte) (0x3FF /*get_rw_ALS4_ASIC_g()*/ << 6) | (byte) (get_rw_ALS5_ASIC_g() >> 4);
      break;
    case 23:
      rb_Data_l = (byte) (get_rw_ALS5_ASIC_g() << 4);
      break;
      
      // Block 3
    case 24:
      rb_Data_l = (byte) (rw_REGV_Voltage_g >> 8);
      break;
    case 25:
      rb_Data_l = (byte) (rw_REGV_Voltage_g);
      break;
    case 26:
      rb_Data_l = (byte) (rw_INTV10bit_g >> 2);
      break;
    case 27:
      rw_INTV10bit_min_g_temp = rw_INTV10bit_min_g;
      rw_INTV10bit_max_g_temp = rw_INTV10bit_max_g;
      rw_INTV10bit_max_g = 0;
      rw_INTV10bit_min_g = 1023;
      rb_Data_l = (byte) (rw_INTV10bit_g << 6) | (byte) (rw_INTV10bit_max_g_temp >> 4);
      break;
      
    case 28:
      rb_Data_l = (byte) (rw_INTV10bit_max_g_temp << 4) | (byte) ((rw_INTV10bit_min_g_temp >> 6));
      break;
    case 29:
      rb_Data_l = (byte) ((rw_INTV10bit_min_g_temp << 2));
      break;
      
    case 30:
      rb_Data_l = rb_STATH_Reg_g;
      rb_STATH_Reg_g = 0;
      break;
    case 31:
      rb_Data_l = rb_STATL_Reg_g;
      rb_STATL_Reg_g = 0;
      break;
      // Block 4
    case 32:
      rb_Data_l = (byte) (get_rw_VICALHI_IHI_GHI_INC_ASIC_g()>>2);
      break;
    case 33: 
      rb_Data_l = (byte)(get_rw_VICALHI_IHI_GHI_INC_ASIC_g() << 6) | (byte) (get_rw_VICALLO_ILO_GHI_ASIC_g() >> 4); 
      break;
    case 34: 
      rb_Data_l = (byte)(get_rw_VICALLO_ILO_GHI_ASIC_g() << 4) | (byte) (get_rw_VIHI_ICALHI_GHI_ASIC_g() >> 6); 
      break;
    case 35: 
      rb_Data_l = (byte)(get_rw_VIHI_ICALHI_GHI_ASIC_g() << 2) | (byte) (get_rw_VIHI_ICALHI_GHI_INC_ASIC_g() >> 8); 
      break;
    case 36: 
      rb_Data_l = (byte)(get_rw_VIHI_ICALHI_GHI_INC_ASIC_g());
      break;
    case 37: 
      rb_Data_l = (byte)(get_rw_VIHI_ILO_GLO_ASIC_g() >>2); 
      break;
    case 38:
      rb_Data_l = (byte)(get_rw_VIHI_ILO_GLO_ASIC_g() << 6) | (byte) (get_rw_VIHI_ILO_GLO_INC_ASIC_g() >> 4); 
      break;
    case 39:
      rb_Data_l = (byte)(get_rw_VIHI_ILO_GLO_INC_ASIC_g() << 4); 
      break;
      // Block 5
    case 40: 
      rb_Data_l = (byte)(get_rw_VILO_ICALLO_GHI_ASIC_g() >>2);
      break;
    case 41: 
      rb_Data_l = (byte)(get_rw_VILO_ICALLO_GHI_ASIC_g() << 6) | (byte) (0/*rw_VILO_ICALLO_GHI_INC_ASIC_g*/ >> 4);
      break;
    case 42: 
      rb_Data_l = (byte)(0/*rw_VILO_ICALLO_GHI_INC_ASIC_g*/ << 4) | (byte) (get_rw_VILO_IHI_GLO_ASIC_g() >> 6);
      break;
    case 43:
      rb_Data_l = (byte)(get_rw_VILO_IHI_GLO_ASIC_g() << 2) | (byte) (get_rw_VILO_IHI_GLO_INC_ASIC_g() >> 8);
      break;
    case 44: 
      rb_Data_l = (byte)(get_rw_VILO_IHI_GLO_INC_ASIC_g()); 
      break;
    case 45: 
      rb_Data_l = (byte)(rw_VIrefHi_ASIC_g >>2);
      break;
    case 46: 
      rb_Data_l = (byte)(rw_VIrefHi_ASIC_g << 6) | (byte) (rw_VIrefLo_ASIC_g >> 4);
      break;
    case 47: 
      rb_Data_l = (byte)(rw_VIrefLo_ASIC_g << 4); 
      break;
      
      // Block 6 HighSpeedblock on Demand
    case 48: 
      rb_Data_l = (byte)(rw_VLEDA_ASIC_g >>2); 
      break;
    case 49: 
      rb_Data_l = (byte)(rw_VLEDA_ASIC_g << 6) | (byte) (rw_VLEDB_ASIC_g >> 4);
      break;
    case 50: 
      rb_Data_l = (byte)(rw_VLEDB_ASIC_g << 4) | (byte) (rw_Vref_ASIC_g >> 6); 
      break;
    case 51: 
      rb_Data_l = (byte)(rw_Vref_ASIC_g << 2) | (byte) (rw_VRSI_ASIC_g >> 8);
      break;
    case 52:
      rb_Data_l = (byte)(rw_VRSI_ASIC_g); 
      break;
    case 53:
      rb_Data_l = (byte)(rw_VTEMP_ASIC_g >>2);
      break;
    case 54: 
      rb_Data_l = (byte)(rw_VTEMP_ASIC_g << 6) | (byte) (rw_VDDA_ASIC_g >> 4); 
      break;
    case 55:
      rb_Data_l = (byte)(rw_VDDA_ASIC_g << 4);
      break;
      
      // Block 7  optional Light Block
    case 56: 
      rb_Data_l = rb_ASICGainSetup_g; 
      break;
    case 57: 
      rb_Data_l = get_rb_ASICReg_NoValidVals_cnt_g(); 
      break;
    case 58: 
      rb_Data_l = get_rb_LightSignalErrorCnt_g();
      break;
    case 59: 
      rb_Data_l = get_rb_MaxLightSignalErrorCnt_g();
      break;
    case 60: 
      rb_Data_l = (byte)(rw_SPINoCommCounter_g>>8);
      break;
    case 61:
      rb_Data_l = rb_StaticNoCommunicationCounter_g;
      break;
    case 62: 
      rb_Data_l = (byte)(rw_VDDD_ASIC_g >>2); 
      break;
    case 63:
      rb_Data_l = (byte)(rw_VDDD_ASIC_g << 6);
      break;
#endif
      
    default:
      rb_Data_l = 0xFE;
      break;
    }
    
  }
  else if (rb_I2C_Debug_Config_g == 1)
  {
    switch(rb_Address_l)
    {
      // Block 0
    case 0: 
      rb_Data_l = rb_speed_in_kmh_g; 
      break;
    case 1: 
      rb_Data_l = rb_Sig_DownWipe_to_upWipe_g;
      break;
    case 2: 
      rb_Data_l = rb_LoopVoltage_ASIC_g; 
      break;
    case 3: 
      rb_Data_l = rb_IR_DeltaModON_g; 
      break;
#pragma diag_suppress=Pa082 /*VDR_523*/
    case 4: 
      rb_Data_l = (byte)(((byte) (((bi_ROM_CHECK_FAILURE_g|bi_RAM_CHECK_FAILURE_g)) << 7) |
                          ((byte)rbi_ASIC_StandByModeOn_g << 5)) |
                         (((byte)(rbi_LightSensorError_g||rbi_UnderVoltage_g) << 4) |
                          ((byte)((uF_modi_lightsens_g.AllBit&0x0F)))));
      break;
    case 5: 
      rb_Data_l = (byte)((
                          (((byte)(rbi_RainSensorEnable>0)) << 6))
                         | (((byte)((rbi_RainSensorError>0)||(rbi_UnderVoltage_g>0)) << 5)
                            | (rb_WiperSpeed_g & 0x07)));
#pragma diag_default=Pa082 /*VDR_523*/
      break;
    case 6:
      rb_Data_l = (byte) (rw_IR_light16bit_Mod_On_g >> 8); 
      break;
    case 7:
      
      rb_Data_l = (byte) (rw_IR_light16bit_Mod_On_g & 0xFF);
      break;
      
      // Block 1
      
    case 8: 
      rb_Data_l = (byte)(get_rw_IR_light16bit_g() >>8); 
      break;
    case 9: 
      rb_Data_l = (byte)(get_rw_IR_light16bit_g() & 0x00FF);
      break;
    case 10: 
      rb_Data_l = (byte)(get_rw_FW_light16bit_g() >>8); 
      break;
    case 11: 
      rb_Data_l = (byte)(get_rw_FW_light16bit_g() & 0x00FF);
      break;
    case 12: 
      rb_Data_l = rb_IrLightTunnelThreshDyn_g; 
      break;
    case 13: 
      rb_Data_l = uF_modi_lightsens_g.AllBit |(rbi_Regulation48LightOnFlag_g <<3); 
      break;
    case 14: 
      rb_Data_l = (byte)(rw_InTunnelDistance_mg>>1);
      break;
    case 15: 
      rb_Data_l = rb_FW_tunnel_threshold_mg; 
      break;
      
      // Block 2
    case 16:
      rb_Data_l = (byte)(rw_Solar_light16bit_1_g >>8); 
      break;
    case 17:
      rb_Data_l = (byte)(rw_Solar_light16bit_1_g ); 
      break;
    case 18: 
      rb_Data_l = (byte)(rw_Solar_light16bit_2_g >>8);
      break;
    case 19:
      rb_Data_l = (byte)(rw_Solar_light16bit_2_g );
      break;
    case 20: 
      rb_Data_l = (byte)(rw_dayCounter_mg >> 5);
      break;
    case 21:
      rb_Data_l = (byte)(rw_nightCounter_mg >> 5); 
      break;
    case 22: 
      rb_Data_l = (byte)(get_rw_Amb_light16bit_g() >>8); 
      break;
    case 23: 
      rb_Data_l = (byte)(get_rw_Amb_light16bit_g() & 0x00FF); 
      break;
      
      // Block 3
    case 24: 
      rb_Data_l = rb_FW_Tunnel_high_TempThresh_l; 
      break;
#pragma diag_suppress=Pa082 /*VDR_523*/
    case 25:
      rb_Data_l = ((byte)(rbi_RSWipeSlowDmd)|(((byte)(rbi_RSWipeFastDmd))<<1)|(rb_WiperSpeed_g<<4));
      break;
#pragma diag_default=Pa082 /*VDR_523*/
    case 26:
      rb_Data_l = rub_PulseCounter; 
      break;
    case 27: 
      rb_Data_l = rub_LengthCounter; 
      break;
    case 28: 
      rb_Data_l = rub_IntermDelayTime;
      break;
    case 29: 
      rb_Data_l = rub_RSIntermDelayInit; 
      break;
    case 30: 
      rb_Data_l = rub_WiperMotorTime;
      break;
    case 31: 
      rb_Data_l = rub_IntermDelayTime_LalstWipe_g;
      break;
      // Block 4
    case 32:
      rb_Data_l = (byte)(ruw_Signal >> 8); 
      break;
    case 33:
      rb_Data_l = (byte)(ruw_Signal & 0x00FF); 
      break;
    case 34:
      rb_Data_l = (byte)(ruw_SigInt >> 8);
      break;
    case 35:
      rb_Data_l = (byte)(ruw_SigInt & 0x00FF); 
      break;
    case 36: 
      rb_Data_l = (byte)(ruw_Schwelle >> 8);
      break;
    case 37:
      rb_Data_l = (byte)(ruw_Schwelle & 0x00FF); 
      break;
    case 38: 
      rb_Data_l = rub_Int_Speicher; 
      break;
    case 39: 
      rb_Data_l = rub_Ovr_Speicher;
      break;
      // Block 5
    case 40: 
      rb_Data_l = ((ruw_St2_Speicher >>6)>255)? 255:((byte)(ruw_St2_Speicher >>6));
      break;
    case 41:
      rb_Data_l = (byte)rub_St2_Epr;
      break;
    case 42: 
      rb_Data_l = rub_Nachwisch_Count; 
      break;
    case 43: 
      rb_Data_l = rub_Trock_Wisch; 
      break;
    case 44: 
      rb_Data_l = (byte)(ruw_StX_Speicher>>8); 
      break;
    case 45: 
      rb_Data_l = rub_Tropf_Anzahl; 
      break;
    case 46:
      rb_Data_l = rub_Empf_Faktor;
      break;
    case 47:
      rb_Data_l = rub_Sig_Anzahl;
      break;
      
      // Block 6 HighSpeedblock on Demand
    case 48: 
      rb_Data_l = rb_RS_SigVoltage_g; 
      break;
    case 49: 
      rb_Data_l = rub_PulseCounter;
      break;
    case 50: 
      rb_Data_l = rub_LengthCounter;
      break;
    case 51: 
      rb_Data_l = rub_Int_Speicher;
      break;
    case 52: 
      rb_Data_l = (byte)((rw_FW_DayHigh_Threshold_g>255)? 255: rw_FW_DayHigh_Threshold_g);
      break;//rub_Ovr_Speicher; break;
    case 53: 
      rb_Data_l = rb_IR_Day_Threshold_g; 
      break;
    case 54: 
      rb_Data_l = rb_FW_Night_Threshold_g; 
      break;
    case 55: 
      rb_Data_l = rb_IR_Night_Threshold_g; 
      break;
      
      // Block 7  optional Light Block
    case 56: 
      rb_Data_l = (byte)(rw_Temperature_g >> 8);
      break;
    case 57: 
      rb_Data_l = (byte)(rw_Temperature_g & 0x00FF);
      break;
    case 58: 
      rb_Data_l = (byte)(rw_DewPoint_g >> 8);
      break;
    case 59: 
      rb_Data_l = (byte)(rw_DewPoint_g & 0x00FF);
      break;
    case 60: 
      rb_Data_l = (byte)(rb_Humidity_g);
      break;
    case 61: 
      rb_Data_l = (byte)(rb_Humidity_raw_g); 
      break;
    case 62: 
      rb_Data_l = (byte)get_rb_LightVetoCounter_g(); 
      break;
    case 63: 
      rb_Data_l = (byte)(rb_HumTemp_ErrorCode_g);
      break;
      
    default: 
      rb_Data_l = 0xFE;
      break;
    }
    
  }
  else if (rb_I2C_Debug_Config_g == 2)
  {
    static int  cab_Debug_Index =0;
    switch(rb_Address_l)
    {
      /* Block 0*/
    case 0: 
      rb_Data_l = rb_speed_in_kmh_g;
      break;
    case 1: 
      rb_Data_l = get_rb_LightVetoCounter_g();
      break;
    case 2: 
      rb_Data_l = (byte)(get_rw_IR_light16bit_g()>>8); 
      break;
    case 3:
      rb_Data_l = (byte)(get_rw_IR_light16bit_g());
      break;
    case 4: 
      rb_Data_l = (byte)(get_rw_IR_INC_light16bit_g()>>8);
      break;
    case 5: 
      rb_Data_l = (byte)(get_rw_IR_INC_light16bit_g());
      break;
    case 6: 
      rb_Data_l = (byte)(get_rw_IR_INC_light16bit_thrs_g()>>8);
      break;      
    case 7:
      rb_Data_l = (byte)(get_rw_IR_INC_light16bit_thrs_g());
      break;
      
      /* Block 1*/
      
    case 8: 
      rb_Data_l = (byte)(get_rw_FW_light16bit_g()>>8);
      break;
    case 9:
      rb_Data_l = (byte)(get_rw_FW_light16bit_g());
      break;
    case 10: 
      rb_Data_l = (byte)(get_rw_FW_INC_light16bit_g()>>8);
      break;
    case 11:
      rb_Data_l = (byte)(get_rw_FW_INC_light16bit_g());
      break;
    case 12: 
      rb_Data_l = (byte)(get_rw_FW_INC_light16bit_thrs_g()>>8);
      break;
    case 13:
      rb_Data_l = (byte)(get_rw_FW_INC_light16bit_thrs_g()); 
      break;
    case 14:
      rb_Data_l = rb_FW_tunnel_threshold_mg;
      break;
    case 15: 
      rb_Data_l = rb_FW_Tunnel_high_TempThresh_l;
      break;
      
      /* Block 2*/
    case 16: 
      rb_Data_l = (byte)(get_rw_Amb_light16bit_g() >>8);
      break;
    case 17:
      rb_Data_l = (byte)(get_rw_Amb_light16bit_g()); 
      break;
    case 18: 
      rb_Data_l = (byte)(get_rw_Amb_INC_light16bit_g()>>8);
      break;
    case 19: 
      rb_Data_l = (byte)(get_rw_Amb_INC_light16bit_g());
      break;
    case 20: 
      rb_Data_l = (byte)(get_rw_Amb_INC_light16bit_thrs_g()>>8);
      break;
    case 21: 
      rb_Data_l = (byte)(get_rw_Amb_INC_light16bit_thrs_g());
      break;
    case 22: 
      rb_Data_l = rb_IrLightTunnelThreshDyn_g;
      break;
    case 23: rb_Data_l = rb_ASIC_ALSx_ShortDetected_Max_cnt_g;
    rb_ASIC_ALSx_ShortDetected_Max_cnt_g=0;
    break;
    
    /* Block 3*/
    case 24: 
      rb_Data_l = (byte)(rw_Solar_light16bit_1_g>>8);
      break;
    case 25:
      rb_Data_l = (byte)(rw_Solar_light16bit_1_g); 
      break;
    case 26: 
      rb_Data_l = (byte)(rw_Solar_light16bit_2_g>>8);
      break;
    case 27: 
      rb_Data_l = (byte)(rw_Solar_light16bit_2_g);
      break;
    case 28:
      rb_Data_l = rb_IR_Day_Threshold_g;
      break;
    case 29:
      rb_Data_l = rb_IR_Night_Threshold_g; 
      break;
    case 30:
      rb_Data_l = rb_FW_Night_Threshold_g;
      break;
    case 31: 
      rb_Data_l = (byte)(rw_InTunnelDistance_mg>>1);
      break;
      
      /* Block 4*/
    case 32: 
      rb_Data_l = (byte)(ruw_Signal >> 8);
      break;
    case 33:
      rb_Data_l = (byte)(ruw_Signal & 0x00FF); 
      break;
    case 34: 
      rb_Data_l = (byte)(ruw_SigInt >> 8);
      break;
    case 35: 
      rb_Data_l = (byte)(ruw_SigInt & 0x00FF);
      break;
    case 36: 
      rb_Data_l = (byte)(ruw_Schwelle >> 8); 
      break;
    case 37: 
      rb_Data_l = (byte)(ruw_Schwelle & 0x00FF);
      break;
    case 38:
      rb_Data_l = rub_Int_Speicher; 
      break;
    case 39:
      rb_Data_l = rub_Ovr_Speicher; 
      break;
      
      /* Block 5*/
#pragma diag_suppress=Pa082 /*VDR_523*/
    case 40: 
      rb_Data_l = (byte)((uF_modi_lightsens_g.AllBit & 0x0F) | (rbi_modi_lightsens_rain_g<<3)
                         | (rbi_Regulation48LightOnFlag_g<<4)
                           | (rbi_UnderVoltage_g<<5)
                             | (rbi_RSWipeSlowDmd<<6)
                               | (rbi_RainSensorEnable<<7));
      break;
#pragma diag_default=Pa082 /*VDR_523*/
    case 41: 
      rb_Data_l = (byte)(rw_REGV_Voltage_g>>4); 
      break;
    case 42: 
      rb_Data_l = (byte)((rw_REGV_Voltage_g<<4)
                         | (rbi_RSWipeFastDmd<<3)
                           | (rb_WiperSpeed_g&0x7)); 
      break;
    case 43: 
      rb_Data_l = rub_PulseCounter; 
      break;
    case 44:
      rb_Data_l = rub_LengthCounter;
      break;
    case 45:
      rb_Data_l = rub_IntermDelayTime;
      break;
    case 46: 
      rb_Data_l = rub_RSIntermDelayInit;
      break;
    case 47: 
      rb_Data_l = (byte)((rw_FW_DayHigh_Threshold_g>255)? 255: rw_FW_DayHigh_Threshold_g); 
      break;
      
      /* Block 6*/
    case 48: 
      rb_Data_l = rub_WiperMotorTime; 
      break;
    case 49: 
      rb_Data_l = rub_IntermDelayTime_LalstWipe_g;
      break;
    case 50: 
      rb_Data_l = (byte)((ruw_St2_Speicher >>6)>255)? 255:((byte)(ruw_St2_Speicher >>6));
      break;
    case 51: 
      rb_Data_l = rub_St2_Epr;
      break;
    case 52: 
      rb_Data_l = rub_Tropf_Anzahl; 
      break;
    case 53: 
      rb_Data_l = rub_Empf_Faktor;
      break;
    case 54:
      rb_Data_l = rub_Sig_Anzahl;
      break;
    case 55: 
      rb_Data_l = rb_RS_SigVoltage_g; 
      break;
      
      /* Block 7*/
    case 56: 
      cab_Debug_Index = nextI2CDebugIdx();
      rb_Data_l = (byte)( (cab_Debug_Index&0x3F)
                         | ((bi_ROM_CHECK_FAILURE_g|bi_RAM_CHECK_FAILURE_g)<<6)
                           | ((rbi_LightSensorError_g|rbi_RainSensorError)<<7) );
      break;
    case 57:
      rb_Data_l = (byte)(getI2CDbg(cab_Debug_Index));
      break;
    case 58:
      rb_Data_l = (byte)(rw_dayCounter_mg >> 5);
      break;
    case 59: 
      rb_Data_l = (byte)(rw_nightCounter_mg >> 5);
      break;
    case 60: 
      rb_Data_l = rb_Sig_DownWipe_to_upWipe_g; 
      break;
    case 61:
      rb_Data_l = rub_Nachwisch_Count;
      break;
    case 62:
      rb_Data_l = rub_Trock_Wisch; 
      break;
    case 63: 
      rb_Data_l = (byte)(ruw_StX_Speicher>>8); 
      break;
      
      /* Block 8*/
    case 64: 
      rb_Data_l = rb_GainOffset_g;
      break;
    case 65:
      rb_Data_l = (byte)(rw_Temperature_g >> 8);
      break;
    case 66: 
      rb_Data_l = (byte)(rw_Temperature_g & 0x00FF); 
      break;
    case 67: 
      rb_Data_l = (byte)(rw_DewPoint_g >> 8);
      break;
    case 68: 
      rb_Data_l = (byte)(rw_DewPoint_g & 0x00FF);
      break;
    case 69:
      rb_Data_l = (byte)(rb_Humidity_g); 
      break;
    case 70: 
      rb_Data_l = (byte)(rub_Trockwisch_memory);
      break;
    case 71:
      rb_Data_l = (byte)(rb_HumTemp_ErrorCode_g); 
      break;
      
    default: 
      rb_Data_l = 0xFE;
      break;
    }
    
  }
#ifdef STARTUP_WIPE
#ifdef RAIN_INTENSITY
  else if (rb_I2C_Debug_Config_g == 3)
  {
    static int  cab_Debug_Index =0;
    switch(rb_Address_l)
    {
      /* Block 0*/
    case 0: 
      rb_Data_l = rb_speed_in_kmh_g;
      break;
    case 1: 
      rb_Data_l = get_rb_LightVetoCounter_g();
      break;
    case 2: 
      rb_Data_l = (byte)(get_rw_IR_light16bit_g()>>8); 
      break;
    case 3:
      rb_Data_l = (byte)(get_rw_IR_light16bit_g());
      break;
    case 4: 
      rb_Data_l = (byte)(get_rw_IR_INC_light16bit_g()>>8);
      break;
    case 5: 
      rb_Data_l = (byte)(get_rw_IR_INC_light16bit_g());
      break;
    case 6: 
      rb_Data_l = (byte)(get_rw_IR_INC_light16bit_thrs_g()>>8);
      break;      
    case 7:
      rb_Data_l = (byte)(get_rw_IR_INC_light16bit_thrs_g());
      break;
      
      /* Block 1*/
      
    case 8: 
      rb_Data_l = (byte)(get_rw_FW_light16bit_g()>>8);
      break;
    case 9:
      rb_Data_l = (byte)(get_rw_FW_light16bit_g());
      break;
    case 10: 
      rb_Data_l = (byte)(get_rw_FW_INC_light16bit_g()>>8);
      break;
    case 11:
      rb_Data_l = (byte)(get_rw_FW_INC_light16bit_g());
      break;
    case 12: 
      rb_Data_l = (byte)(get_rw_FW_INC_light16bit_thrs_g()>>8);
      break;
    case 13:
      rb_Data_l = (byte)(get_rw_FW_INC_light16bit_thrs_g()); 
      break;
    case 14:
      rb_Data_l = rb_FW_tunnel_threshold_mg;
      break;
    case 15: 
      rb_Data_l = rb_FW_Tunnel_high_TempThresh_l;
      break;
      
      /* Block 2*/
    case 16: 
      rb_Data_l = (byte)(get_rw_Amb_light16bit_g() >>8);
      break;
    case 17:
      rb_Data_l = (byte)(get_rw_Amb_light16bit_g()); 
      break;
    case 18: 
      rb_Data_l = (byte)(get_rw_Amb_INC_light16bit_g()>>8);
      break;
    case 19: 
      rb_Data_l = (byte)(get_rw_Amb_INC_light16bit_g());
      break;
    case 20: 
      rb_Data_l = (byte)(get_rw_Amb_INC_light16bit_thrs_g()>>8);
      break;
    case 21: 
      rb_Data_l = (byte)(get_rw_Amb_INC_light16bit_thrs_g());
      break;
    case 22: 
      rb_Data_l = rb_IrLightTunnelThreshDyn_g;
      break;
    case 23: rb_Data_l = rb_ASIC_ALSx_ShortDetected_Max_cnt_g;
    rb_ASIC_ALSx_ShortDetected_Max_cnt_g=0;
    break;
    
    /* Block 3*/
    case 24: 
      rb_Data_l = (byte)(rw_Solar_light16bit_1_g>>8);
      break;
    case 25:
      rb_Data_l = (byte)(rw_Solar_light16bit_1_g); 
      break;
    case 26: 
      rb_Data_l = (byte)(rw_Solar_light16bit_2_g>>8);
      break;
    case 27: 
      rb_Data_l = (byte)(rw_Solar_light16bit_2_g);
      break;
    case 28:
      rb_Data_l = rb_IR_Day_Threshold_g;
      break;
    case 29:
      rb_Data_l = rb_IR_Night_Threshold_g; 
      break;
    case 30:
      rb_Data_l = rb_RS_SigVoltage_abs_g;
      break;
    case 31: 
      
      rb_Data_l = (rw_ref_deltaINTV_cnt_l <<4) +(rb_Startup_Wipe_detected_g << 2) +rb_Startup_Wipe_g;
      break;
    
      /* Block 4*/
     case 32: 
      rb_Data_l = (byte)(rw_Interval_g >> 8);
      break;
    case 33:
      rb_Data_l = (byte)(rw_Interval_g & 0x00FF); 
      break;
    case 34: 
      rb_Data_l = (byte)(rw_deltaINTV_Comp_l >> 8);
      break;
    case 35: 
      rb_Data_l = (byte)(rw_deltaINTV_Comp_l & 0x00FF);
      break;
    case 36: 
      rb_Data_l = (byte)(rw_StartupWipeCommandTimOut_mg) ; 
      break;
    case 37: 
      rb_Data_l = (byte)(rb_deltaINTV_g & 0x00FF);
      break;
    case 38:
      rb_Data_l = (byte)(rw_RS_SigVoltage_neg_int_g >> 8);
      break;
    case 39:
      rb_Data_l = (rw_RS_SigVoltage_neg_int_g & 0x00FF); 
      break;
      /* Block 5*/
#pragma diag_suppress=Pa082 /*VDR_523*/
    case 40: 
      rb_Data_l = (byte)((uF_modi_lightsens_g.AllBit & 0x0F) | (rbi_modi_lightsens_rain_g<<3)
                         | (rbi_Regulation48LightOnFlag_g<<4)
                           | (rbi_UnderVoltage_g<<5)
                             | (rbi_RSWipeSlowDmd<<6)
                               | (rbi_RainSensorEnable<<7));
      break;
#pragma diag_default=Pa082 /*VDR_523*/
    case 41: 
      rb_Data_l = (byte)(rw_REGV_Voltage_g>>4); 
      break;
    case 42: 
      rb_Data_l = (byte)((rw_REGV_Voltage_g<<4)
                         | (rbi_RSWipeFastDmd<<3)
                           | (rb_WiperSpeed_g&0x7)); 
      break;
    case 43: 
      rb_Data_l = rub_PulseCounter; 
      break;
    case 44:
      rb_Data_l = rub_LengthCounter;
      break;
    case 45:
      rb_Data_l = rub_IntermDelayTime;
      break;
    case 46: 
      rb_Data_l = rub_RSIntermDelayInit;
      break;
    case 47: 
      rb_Data_l = (byte)((rw_FW_DayHigh_Threshold_g>255)? 255: rw_FW_DayHigh_Threshold_g); 
      break;
      
      /* Block 6*/
    case 48: 
      rb_Data_l = rub_WiperMotorTime; 
      break;
    case 49: 
      rb_Data_l = rub_IntermDelayTime_LalstWipe_g;
      break;
    case 50: 
      rb_Data_l = (byte)((ruw_St2_Speicher >>6)>255)? 255:((byte)(ruw_St2_Speicher >>6));
      break;
    case 51: 
      rb_Data_l = rub_St2_Epr;
      break;
    case 52: 
      rb_Data_l = rub_Tropf_Anzahl; 
      break;
    case 53: 
      rb_Data_l = rub_Empf_Faktor;
      break;
    case 54:
      rb_Data_l = rub_Sig_Anzahl;
      break;
    case 55: 
      rb_Data_l = rb_RS_SigVoltage_g; 
      break;
      
      /* Block 7*/
    case 56: 
      cab_Debug_Index = nextI2CDebugIdx();
      rb_Data_l = (byte)( (cab_Debug_Index&0x3F)
                         | ((bi_ROM_CHECK_FAILURE_g|bi_RAM_CHECK_FAILURE_g)<<6)
                           | ((rbi_LightSensorError_g|rbi_RainSensorError)<<7) );
      break;
    case 57:
      rb_Data_l = (byte)(getI2CDbg(cab_Debug_Index));
      break;
    case 58:
      rb_Data_l = (byte)(rw_dayCounter_mg >> 5);
      break;
    case 59: 
      rb_Data_l = (byte)(rw_nightCounter_mg >> 5);
      break;
    case 60: 
      rb_Data_l = rb_Sig_DownWipe_to_upWipe_g; 
      break;
    case 61:
      rb_Data_l = rub_Nachwisch_Count;
      break;
    case 62:
      rb_Data_l = rub_Trock_Wisch; 
      break;
    case 63: 
      rb_Data_l = (byte)(ruw_StX_Speicher>>8); 
      break;
      
      /* Block 8*/
    case 64: 
      rb_Data_l = rb_GainOffset_g;
      break;
    case 65:
      rb_Data_l = (byte)(rw_Temperature_g >> 8);
      break;
    case 66: 
      rb_Data_l = (byte)(rw_Temperature_g & 0x00FF); 
      break;
    case 67: 
      rb_Data_l = (byte)(rw_DewPoint_g >> 8);
      break;
    case 68: 
      rb_Data_l = (byte)(rw_DewPoint_g & 0x00FF);
      break;
    case 69:
      rb_Data_l = (byte)(rb_Humidity_g); 
      break;
    case 70: 
      rb_Data_l = (byte)(rub_Trockwisch_memory);
      break;
    case 71:
      rb_Data_l = (byte)(rb_HumTemp_ErrorCode_g); 
      break;
      
    default: 
      rb_Data_l = 0xFE;
      break;
    }
    
  } 
#endif // RAIN_INTENSITY
#endif // STARTUP_WIPE
  else
  {
    /* Disable I2C debug configuration in case of invalid configuration */
  IICA0EN = 0U; /* disable supply IICA0 clock */
  IICE0 = 0U; /* disable IICA0 operation */
  IICAMK0 = 1U; /* disable INTIICA0 interrupt */
 
  }
  return (rb_Data_l);
}

static int getI2CDbg(int index){
  //01234567890123456789012345678901 
  //static byte cab_Debug_ID_g[]    ="SW:     ;HW:  ;SN:        ;DC: ;"; /*"SW:X005D;HW:04;SN:4216;DC:2;";*/
  int retval = 0;
  switch(index)
  {
  case 3 :
    retval = rab_SoftwareStand_g(0);
    break;
  case 4 : 
    retval = rab_SoftwareStand_g(1);
    break;
  case 5 :
    retval = rab_SoftwareStand_g(3) + '0';
    break;
  case 6 : 
    retval = cb_SWSTAND_ADD_ON_g;
    break;
    
  case 12 : 
    retval = rab_HardwareStand_g(0);
    break;
  case 13 :
    retval = rab_HardwareStand_g(1);
    break;
    
  case 18 : 
    retval = Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(0)>>4);
    break;
  case 19 :
    retval = Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(0)&0x0F);
    break;
  case 20 : 
    retval = Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(1)>>4);
    break;
  case 21 :
    retval = Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(1)&0x0F);
    break;
  case 22 : 
    retval = Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(2)>>4);
    break;
  case 23 : 
    retval = Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(2)&0x0F);
    break;
  case 24 : 
    retval = Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(3)>>4);
    break;
  case 25 : 
    retval = Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(3)&0x0F);
    break;
    
  case 30 : 
    retval = rb_I2C_Debug_Config_g + '0';
    break;
  default :
    retval = cab_Debug_ID_g[index&0x3F];
    break;
  }
  return retval;
}


#pragma inline=forced
static int nextI2CDebugIdx(void){
  static byte I2CDebug_index = 0;

  I2CDebug_index ++;
  if(I2CDebug_index >= (sizeof(cab_Debug_ID_g) -1))
  {
    I2CDebug_index = 0;
  }
  return I2CDebug_index;
} 