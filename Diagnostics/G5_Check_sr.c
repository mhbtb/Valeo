
/*************************************************************************

Company : Valeo Switches and Detection System

Project : RLT Sensor, RDN Sensor

Component : check.c

Documentation reference : Software Requirements

DESCRIPTION      : This module includes the selftests of the
uController this includes
+ cyclic ROM Test                                  *
+ cyclic RAM Test
+ ADC TEst at Start with the Voltages
of the RS ASIC
Evolution of the component : see PVCS Version control system


*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 22.03.11  VDR_638   AL   MISRA OPTIMISATION with corrections in Source code */
/* 22.Mar11  VCO_95      AL   Increase Flash Range */
/* 13.12.10  RLS_VCO_90  AL   more memory*/
/* 16.07.10  RLS_VCO_62  AL   move const section in Boot Cluster 1 and adapt
checksum range*/
/* 27.05.19  VCO_051     AL   Use _Callt functions to speed up initialisation*/
/* 26.05.10  VCO_055     AL   reomve debouncing of RAM and ROM error*/
/* 29.04.10  VDR511_5    AL   Polyspace error 1 Correction*/
/* 01.04.10  VDR_479          use more Flash memory*/ 
/* 18.01.10  VCO_024          Interval table adapt link file has to be adapted use actuall xcl file Version >= 1.3!*/
/* 03.02.08  VDR_135          Misra Warning for MISRA Rule 101*/

/******************************************************************************/
/* 02.09.14  VCO_180    NB      code Optimization */
/* 19.09.2014 VCO_184   NB  Checksum for calibration data */
/* 29.09.2014 VCO_154   MP Safety:SM139,SM140:Implement RS_Error_Aktiv,LS_Error_Aktiv flag  to 
                           check after Reset if a error was active before the sensor goes to sleep or reset */
/* 08.12.2014 VCO_151  NB  Implement IC test */
/*03.03.15    VCO_227    NB     Implement RAM Guard function */
/*10.03.15    VCO_227    NB     Implement RAM Guard function */
/*19.03.15    VDR_858    NB     RAM Guard area initialized with 0xaa instead of 0x00 */
/*09.04.2015 VCO_241    NB      Implement test function for RAM Guard with one dedicated cell */
/*10.04.2015 VCO_241    NB      Implement test function for RAM Guard with one dedicated cell */
/*10.06.2015 VCO_254    NB      Checking of CRC over light area shall be done cyclically  */
/*16.06.2015 VCO_254    NB      Enable RAM parity Error  */
/* 25.06.2015 VCO_254    NB      Disable RAM parity Error  */
/* 01.07.2015 VCO_241    NB      Implement test function for RAM Guard with one dedicated cell */
/******************************************************************************/
/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA, 0750:union needed to reduce RAM usage >>*/
/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
/* PRQA S 781,759,436,434 EOF */ /* << 0781,436 03 03, unions needed >> */
/* PRQA S 306,310 EOF *//*<< pointer cast required ! >>*/ 
/* PRQA S 489 EOF *//*<< 0489:pointer increment is needed here! >>*/  
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/*************************************************************************
**                   Common and module include-file                     **
**************************************************************************/
#include "ior5f109be.h" 
#include "ior5f109be_ext.h" 
#include <intrinsics.h>

#define _check_c_       /* Define for Single include of Global Header G5_check_sr.h */
#include "G5_Check_sr.h"
#undef _check_c_ 
#include "G5_E2ProjectConfig.h"
#include "G5_diagnose.h"
#include "G5_Appli_lowinit.h"

/* **************************************/
/* RAM Check Address Range */



#define cb_NumberOF_CRC_CALIB_Byte_s  21

#pragma dataseg="RAM_GUARD"
static __no_init byte rb_RamGuardTestCell_mg;
#pragma dataseg=default


static __callt word crc_calc(byte rb_InputByte_l, word rw_CRC_Init_Value_l);



#define __SLOWCRC
/**************************************************************************
Syntax   : void  crc_calc(void)
Object   : crc_calc()
Parameters : rb_InputByte_l next byte in ROM to calculate the Checksum
CRC16 ->IAR Compiler
Return  : Global Variable rw_CRC16_g present Checksum CRC16
Calls   : check_crc16()
***************************************************************************
Inputs validation conditions: Tested with correct and incorrect ROM
***************************************************************************
Pseudo-code : Calculates the CRC16 Checksum
with the input bytes step by step
**************************************************************************/
#ifndef __SLOWCRC

static __callt word crc_calc (byte rb_InputByte_l, word rw_CRC_Init_Value_l) /*VCO_051*/
{
  /* PRQA S 1281 50*//*<< 1281:Table from IAR Standard code ! >>*/    
#pragma constseg="END_BOOTSEG_TWO"               /*RLS_VCO_62 move constant to cluster 1*/
  static const unsigned int crc16_table[256] =
  {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7, 0x8108,
    0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef, 0x1231, 0x0210,
    0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6, 0x9339, 0x8318, 0xb37b,
    0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de, 0x2462, 0x3443, 0x0420, 0x1401,
    0x64e6, 0x74c7, 0x44a4, 0x5485, 0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee,
    0xf5cf, 0xc5ac, 0xd58d, 0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6,
    0x5695, 0x46b4, 0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d,
    0xc7bc, 0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b, 0x5af5,
    0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12, 0xdbfd, 0xcbdc,
    0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a, 0x6ca6, 0x7c87, 0x4ce4,
    0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41, 0xedae, 0xfd8f, 0xcdec, 0xddcd,
    0xad2a, 0xbd0b, 0x8d68, 0x9d49, 0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13,
    0x2e32, 0x1e51, 0x0e70, 0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a,
    0x9f59, 0x8f78, 0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e,
    0xe16f, 0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e, 0x02b1,
    0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256, 0xb5ea, 0xa5cb,
    0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d, 0x34e2, 0x24c3, 0x14a0,
    0x0481, 0x7466, 0x6447, 0x5424, 0x4405, 0xa7db, 0xb7fa, 0x8799, 0x97b8,
    0xe75f, 0xf77e, 0xc71d, 0xd73c, 0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657,
    0x7676, 0x4615, 0x5634, 0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9,
    0xb98a, 0xa9ab, 0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882,
    0x28a3, 0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
    0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92, 0xfd2e,
    0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9, 0x7c26, 0x6c07,
    0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1, 0xef1f, 0xff3e, 0xcf5d,
    0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8, 0x6e17, 0x7e36, 0x4e55, 0x5e74,
    0x2e93, 0x3eb2, 0x0ed1, 0x1ef0,
  };
#pragma constseg=default               /* IAR 4xx part*/
  rw_CRC16_g = crc16_table[(byte)((rw_CRC16_g >> 8) ^ rb_InputByte_l)] ^ (rw_CRC16_g << 8);
}

#else

static __callt word crc_calc(byte rb_InputByte_l, word rw_CRC_Init_Value_l) /*VCO_051*/
{
  /* Local Variable Declaration */
  byte rb_i_l;
  word rw_newcrc_l;
  word rw_CRC_Result_l;
  
  rw_CRC_Result_l = rw_CRC_Init_Value_l;
  for (rb_i_l=0;rb_i_l<8;++rb_i_l)         /* loop to Calculate the CRC 16 Checksum */
  {
    rw_newcrc_l=(rw_CRC_Result_l<<1);
    if ((rb_InputByte_l & 0x80) > 0)            /* MSB first */
    {
      rw_newcrc_l |=1;/* calculate Checksum with next bit */
    }
    if ((rw_CRC_Result_l & 0x8000U) > 0)              /* use Polynom for CRC16? */
    {
      rw_newcrc_l^=0x1021;
    }
    rw_CRC_Result_l=rw_newcrc_l;               /* local Variable to Global */
    
    rb_InputByte_l <<= 1;                 /* shift the input byte */
  }
  return(rw_CRC_Result_l);
}
#endif

/**************************************************************************
Syntax   : void  check_crc16(void)
Object   : check_crc16()
Parameters :none
Return  : bi_ROM_CHECK_FAILURE_g :  TRUE -> ROM Defect
FALSE -> ROM OK
Calls   : main()
***************************************************************************
Inputs validation conditions: Tested with correct and incorrect ROM
***************************************************************************
Pseudo-code : Organize the Checksum check and compares the result
sets/resets the failure bit in case of error/no error
**************************************************************************/
/* PRQA S 3356,3359,3201 10*//*<< 3356,3359,3201: Variable is changin on runtime  >>*/   

#pragma optimize=low
__callt void check_crc16(void) /*VCO_051*/
{
  static byte __far *pAdr_s = 0;
  
  
  if(pAdr_s < (unsigned char *)CW_chksum2000_FEEF_START) /* Initialire pointer */
  {
    pAdr_s=(unsigned char *)CW_chksum2000_FEEF_START;                           /* set adress pinter */
    rw_CRC16_g =0x0000;                      /* reset Checksum */
    CRCIN = 0x00;  /* checksum calculation using controller register */
    CRCD = 0x00;   /* result stored in CRCD register */
  }
  else if (pAdr_s < (unsigned char *)((CW_chksum2000_FEEF_END)-8)) /* do Calculation for the complete ROM */
  {
    /* PRQA S 0489 30*//*<< 0489:pointer increment is needed here! >>*/  
    rw_CRC16_g = crc_calc(*pAdr_s,rw_CRC16_g);
    CRCIN = *pAdr_s;
    pAdr_s++;                       /* Increment ROM Pointer */
    rw_CRC16_g = crc_calc(*pAdr_s,rw_CRC16_g);
    CRCIN = *pAdr_s;
    pAdr_s++;                       /* Increment ROM Pointer */
    rw_CRC16_g = crc_calc(*pAdr_s,rw_CRC16_g);
    CRCIN = *pAdr_s;
    pAdr_s++;                       /* Increment ROM Pointer */
    rw_CRC16_g = crc_calc(*pAdr_s,rw_CRC16_g);
    CRCIN = *pAdr_s;
    pAdr_s++;                       /* Increment ROM Pointer */
    rw_CRC16_g = crc_calc(*pAdr_s,rw_CRC16_g);
    CRCIN = *pAdr_s;
    pAdr_s++;                       /* Increment ROM Pointer */
    rw_CRC16_g = crc_calc(*pAdr_s,rw_CRC16_g);
    CRCIN = *pAdr_s;
    pAdr_s++;                       /* Increment ROM Pointer */
    rw_CRC16_g = crc_calc(*pAdr_s,rw_CRC16_g);
    CRCIN = *pAdr_s;
    pAdr_s++;                       /* Increment ROM Pointer */
    rw_CRC16_g = crc_calc(*pAdr_s,rw_CRC16_g);
    CRCIN = *pAdr_s;
    pAdr_s++;                       /* Increment ROM Pointer */
    
    
  }
  else if (pAdr_s < (unsigned char *)CW_chksum2000_FEEF_END) /* do Calculation for the Remaining ROM */
  {
    rw_CRC16_g = crc_calc(*pAdr_s,rw_CRC16_g);
    CRCIN = *pAdr_s;
    pAdr_s++;                       /* Increment ROM Pointer */
  }
  else if (pAdr_s == (unsigned char *)CW_chksum2000_FEEF_END) /* do Calculation for the last byte of ROM */
    
  {
    rw_CRC16_g = crc_calc(*pAdr_s,rw_CRC16_g);            /* calc for last cell! */
    CRCIN = *pAdr_s;
    /* PRQA S 0489 1*//*<< 0489:pointer increment is needed here! >>*/  
    
#ifdef __SLOWCRC
    rw_CRC16_g = crc_calc(0,rw_CRC16_g);                   /* call two times with 0 */
    rw_CRC16_g = crc_calc(0,rw_CRC16_g);                   /* because 2 Byte Checksum */
#endif
    /* crc complete*/
    /*compare the mirrored checksum  and Check calculated and build checksum are same ? */
    if ((rw_CRC16_g!= chksum2000_FEEF ) || ((CRCD)!= chksum_mirror2000_FEEF ))
    {
#ifndef _DEBUG_ /*error not used when in debug mode*/
      bi_ROM_CHECK_FAILURE_g = TRUE;   /* ROM Error ! */
    }
    else
    {
#endif /*_DEBUG_*/
      bi_ROM_CHECK_FAILURE_g = FALSE;   /* ROM No Error ! */
    }
    
    bi_First_ROM_CHECK_Done_g = TRUE;
    pAdr_s=(unsigned char *)CW_chksum2000_FEEF_START;        /* reset adress pinter */
    rw_CRC16_g =0x0000;                      /* reset Checksum */
    CRCIN = 0x00;
    CRCD = 0x00;
  }
  else
  {
    /*For QAC*/
  }
  
}




/**************************************************************************
Syntax   : void  CheckRAM(void)
Object   : CheckRAM()
Parameters :none
Return  : bi_RAM_CHECK_FAILURE_g :  TRUE -> RAM Defect
FALSE -> RAM OK
Calls   : main()
***************************************************************************
Inputs validation conditions: Tested with correct and incorrect RAM
***************************************************************************
Pseudo-code :  Writes in every
RAM cell (without pb_PointerRAMCheckAddress_mg)
0x00, 0x55 ,0xAA and compares if 0x55 and 0xAA are set
correct. Reloads the old value into the memory
The interrupts are disabled during the test.
! do not perform any function call in this routine (STACK!)
**************************************************************************/
__callt void CheckRAM(void)
{
  /* Local Variable Declaration */
  static byte __far *pb_PointerRAMCheckAddress_mg;    /* Pointer for the RAM check */
  static byte rb_Current_RAM_CHECK_FAILURE_mg;
  
  byte rb_ram_dummy_l;                           /* Dummy byte to save RAM contens */
  
  
  /* check the lower RAM boarder of  RAM */
  if (pb_PointerRAMCheckAddress_mg<(unsigned char __far *)cb_LOWER_RAM_BOARDER_s)              
  {
    /* set pointer to the beginning of the RAM */
    pb_PointerRAMCheckAddress_mg = (unsigned char __far *)cb_LOWER_RAM_BOARDER_s;               
  }
  
  else if (pb_PointerRAMCheckAddress_mg > (unsigned char __far *)cb_UPPER_RAM_BOARDER_s)/* check the upper RAM boarder*/
  {
    /* set pinter to the beginning of the RAM */
    pb_PointerRAMCheckAddress_mg = (unsigned char __far *)cb_LOWER_RAM_BOARDER_s;       
    bi_FIRST_RAM_CHECK_DONE_g = TRUE;                                   /* set bit for initial RAM test complete */
    /* RPERDIS = 0; Enable RAM parity error */
    
    bi_RAM_CHECK_FAILURE_g = rb_Current_RAM_CHECK_FAILURE_mg;
    
  }
  else {} /*Misra Rule 14.10*/
  
  
  if ((rb_Current_RAM_CHECK_FAILURE_mg == FALSE) )     /* Is no RAM failure Detected? */
  {
    /* Check if the pointer has the adress of itself */
    if (pb_PointerRAMCheckAddress_mg == (unsigned char __far*) (&pb_PointerRAMCheckAddress_mg)) 
    {
      /* PRQA S 273,488 2*//*<< 273:pointer increment is needed here! >>*/  
      pb_PointerRAMCheckAddress_mg +=4;    /*step over pointer adress in RAM. 3 byte Addressing so increment by 4 */
    }
    else
    {
      DisableRamGuard();           /* disable all interrupts and RAM Guard */
      
      {
        rb_ram_dummy_l = *pb_PointerRAMCheckAddress_mg;           /* save RAM cell */
        *pb_PointerRAMCheckAddress_mg = 0;                        /* delete RAM content */
        *pb_PointerRAMCheckAddress_mg = 0xAA;                     /* set content to 0xAA */
                
        if (*pb_PointerRAMCheckAddress_mg == 0xAA)                /* is content 0xAA */
        {
          *pb_PointerRAMCheckAddress_mg = 0x55;                   /* set content to 0x55 */
          if (*pb_PointerRAMCheckAddress_mg != 0x55)              /* is Address 0x55 */
          {
            *pb_PointerRAMCheckAddress_mg = rb_ram_dummy_l;       /* restore RAM cell */
            /* (have to be restored before setting failure in case the failure is the RAM cell!)*/
            
            rb_Current_RAM_CHECK_FAILURE_mg = TRUE;
            
            /* PRQA S 0309 10*//*<< 0309:OK for this adressrange! >>*/  
            rw_RAM_DefectCell_g = (word) ((byte *)pb_PointerRAMCheckAddress_mg);
          }
          else
          {
            *pb_PointerRAMCheckAddress_mg = rb_ram_dummy_l;      /* restore RAM cell */
          }
        }
        else
        {
          *pb_PointerRAMCheckAddress_mg = rb_ram_dummy_l;          /* restore RAM cell */
          /* (have to be restored before setting failure in case the failure is the RAM cell!)*/
          rb_Current_RAM_CHECK_FAILURE_mg = TRUE;
          
          /* PRQA S 0309 10*//*<< 0309:OK for this adressrange! >>*/  
          rw_RAM_DefectCell_g = (word) ((byte *)pb_PointerRAMCheckAddress_mg);
        }
      }
      EnableRamGuard();                                     /* Enable Interrupt and RAM guard */
      
      
      /* PRQA S 0489 1*//*<< 0489:pointer increment is needed here! >>*/  
      pb_PointerRAMCheckAddress_mg++;                            /* increse pointer in RAM */
    }
    
  }  
  else
  {
    bi_RAM_CHECK_FAILURE_g = rb_Current_RAM_CHECK_FAILURE_mg; 
  }
}


/**************************************************************************
Syntax   : void  check_crc16_calib(void)
Object   : check_crc16_calib()
Parameters :none
Return  : bi_CALIB_CHECK_FAILURE_g :  TRUE -> Calib CRC Defect
FALSE -> Calib CRC OK
Calls   : main()
***************************************************************************
Inputs validation conditions: Tested with correct and incorrect Calib CRC
***************************************************************************
Pseudo-code : Organize the Checksum check and compares the result
sets/resets the failure bit in case of error/no error
**************************************************************************/
/* PRQA S 3356,3359,3201 10*//*<< 3356,3359,3201: Variable is changin on runtime  >>*/ 

 void check_crc16_calib(void)
 {
   
   word rw_CRC16Calib_Stored_g;
   byte rb_loopCnt_l;
   word rw_CRC16_Calib_l = 0;
   for (rb_loopCnt_l = 0 ;rb_loopCnt_l < cb_NumberOF_CRC_CALIB_Byte_s ;rb_loopCnt_l++) /* Address 271 to 291 */
   {
     rw_CRC16_Calib_l = crc_calc((EEPROM_Struct_PD._c[(CW_CALIB_CRC_START-CW_EEPROM_PD_START_ADR) + rb_loopCnt_l ]),rw_CRC16_Calib_l);
   }
   rw_CRC16Calib_Stored_g = EEPROM_Struct_PD._c[(CW_CALIB_CRC_END-CW_EEPROM_PD_START_ADR) + 2]; /* CRC High Byte */
   rw_CRC16Calib_Stored_g = rw_CRC16Calib_Stored_g << 8;
   /* CRC Low Byte */
   rw_CRC16Calib_Stored_g = rw_CRC16Calib_Stored_g | EEPROM_Struct_PD._c[(CW_CALIB_CRC_END-CW_EEPROM_PD_START_ADR) + 1];
   if(rw_CRC16Calib_Stored_g == 0xFFFFU)
   {
     rbi_CRC_ChangedByDiagnostic_g = TRUE; /* Disable CRC calculation */
     
   }
   else if(rw_CRC16Calib_Stored_g != rw_CRC16_Calib_l)
   {
     bi_CALIB_CHECK_FAILURE_g = TRUE;   /* Calib Error ! */
   }
   else
   {
     bi_CALIB_CHECK_FAILURE_g = FALSE;   /* Calib No Error ! */
   }
   bi_First_CALIB_CHECK_Done_g = TRUE;
 }
  
 
void RamGuard_init(void)
{
  word rw_length_l;
  static byte __far *pAdr_Ramguard;
  pAdr_Ramguard = (unsigned char __far *) cb_RAM_GUARD_START_g;
  IAWCTL = _80_CGC_ILLEGAL_ACCESS_ON | _00_CGC_RAM_GUARD_OFF ; /*Disable RAM guard */
  
  for( rw_length_l= 0;rw_length_l < cb_RAM_GUARD_LENGTH_g; rw_length_l++)
  {
    *pAdr_Ramguard = 0x00; /* VDR_858*/
    pAdr_Ramguard++;
  }
  rb_RamGuardTestCell_mg = 0xAA; /* initialize with 0xAA to check in test function */
  IAWCTL = _80_CGC_ILLEGAL_ACCESS_ON | _30_CGC_RAM_GUARD_ARAE2 ; /* Enable RAM guard */
}

/* low optimization required ,otherwise skip the check and set to true all the time */
#pragma optimize=low 
void RamGuardTest(void)
{
  static byte rb_Current_RAM_GUARD_Error_mg;
  
  rb_RamGuardTestCell_mg = 0x55; /* write operation should fail because of  enabled RAM guard*/
  /* Test cell still should have value 0xAA as initialized */
  if(rb_RamGuardTestCell_mg == 0x55)
  {
    /* indicates RAM guard not disabled, this is an error*/
    /* set error and enable RAM guard */
    rb_Current_RAM_GUARD_Error_mg = TRUE;
    rb_RamGuardTestCell_mg = 0xAA;
    EnableRamGuard();
  }
  if( rb_Current_RAM_GUARD_Error_mg == TRUE)
  {
    bi_RAM_GUARD_Error_g = TRUE; 
  }
  else
  {
    bi_RAM_GUARD_Error_g = FALSE; 
  }
  
}

__callt void DisableRamGuard(void)
{
  __disable_interrupt();
  IAWCTL = _80_CGC_ILLEGAL_ACCESS_ON | _00_CGC_RAM_GUARD_OFF  ; /*Disable RAM guard */
}

__callt void EnableRamGuard(void)
{
  IAWCTL = _80_CGC_ILLEGAL_ACCESS_ON | _30_CGC_RAM_GUARD_ARAE2 ; /* Enable RAM guard */ 
  __enable_interrupt();
}
