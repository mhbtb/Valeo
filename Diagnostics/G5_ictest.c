/*************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : iCtest.c

Documentation reference : Hardware Software Interface File
Overview of the component : interface to the electronics

Evolution of the component : see PVCS Version control system

Initials   date   modification

*************************************************************************/
/* 26.05.10  VDR_523     AL      reomve compiler warnings*/
/*************************************************************************/
/**                   Common and module include-file                     **/
/* 08.12.2014 VCO_151  NB  Implement IC test */
/* 09.03.2015 VDR_854  NB  QAC Findings */
/**************************************************************************/

/* PRQA S 0781,434,436 EOF */ /* << 0781 unions needed  >> */

/** Include Files **/
#define _ictest_c_             //Define for Single include of Global Header G5_io.h
#include "ior5f109be.h"
#include "ior5f109be_ext.h"
/*************************************************************************
**                   Other files included                               **
**************************************************************************/
#include "G5_Appli_Lowinit.h"
#include "G5_ictest.h"
#include "G5_io_sen.h"
#include "G5_Appli_main.h"
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef _ictest_c_



/*************************************************************************
**                   Compile options                                    **
**************************************************************************/

/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/


/*************************************************************************
**                   Declaration of local module functions              **
**************************************************************************/

/*************************************************************************
**                   Declaration of local module macros                 **
**************************************************************************/
#define CB_ICTEST_PATTERN0_S 1
#define CB_ICTEST_PATTERN1_S 2
#define CB_ICTEST_PATTERN2_S 3
#define CB_ICTEST_PATTERN3_S 4
#define CB_ICTEST_PATTERN4_S 5
#define CB_ICTEST_PATTERN5_S 6
#define CB_ICTEST_PATTERN6_S 7
#define CB_ICTEST_PATTERN7_S 8
#define CB_ICTEST_PATTERN8_S 9
#define CB_ICTEST_PATTERN9_S 10
#define CB_ICTEST_PATTERN10_S 11
#define CB_ICTEST_PATTERN11_S 12
#define CB_ICTEST_PATTERN12_S 13
#define CB_ICTEST_PATTERN13_S 14
#define CB_ICTEST_PATTERN14_S 15
#define CB_ICTEST_PATTERN15_S 16
#define CB_ICTEST_PATTERN16_S 17
#define CB_ICTEST_PATTERN17_S 18
#define CB_ICTEST_PATTERN18_S 19
#define CB_ICTEST_PATTERN19_S 20






/**************************************************************************
Syntax   : void  ICTEST_init(void)
Object   : ICTEST_init()
Parameters : none
Return  : none
Calls   : in main.c after ADC_init
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Initialize all ports of the Micro Controller for ICT
**************************************************************************/


void ICTEST_init(void)
{
  rb_ICTest_state_g =CB_NO_ICTEST_S;
  P0 = _01_Pn0_OUTPUT_1;
  P1 = _01_Pn0_OUTPUT_1 | _04_Pn2_OUTPUT_1 | _08_Pn3_OUTPUT_1 | _20_Pn5_OUTPUT_1;
  P3 = _01_Pn0_OUTPUT_1 | _02_Pn1_OUTPUT_1;
  P4 = _01_Pn0_OUTPUT_1;
  P5 = _02_Pn1_OUTPUT_1;
  P14 = _80_Pn7_OUTPUT_1;
  PMC0 = _00_PMCn0_DI_ON | _00_PMCn1_DI_ON | _FC_PMC0_DEFAULT;
  PMC14 = _00_PMCn7_DI_ON | _7F_PMC14_DEFAULT;
  ADPC = _03_ADPC_DI_ON;
  PM0 = _00_PMn0_MODE_OUTPUT | _02_PMn1_MODE_INPUT | _FC_PM0_DEFAULT;
  PM1 = _00_PMn0_MODE_OUTPUT | _02_PMn1_MODE_INPUT | _00_PMn2_MODE_OUTPUT | _00_PMn3_MODE_OUTPUT |
    _10_PMn4_MODE_INPUT | _00_PMn5_MODE_OUTPUT | _40_PMn6_NOT_USE | _80_PMn7_NOT_USE;
  PM2 = _01_PMn0_NOT_USE | _02_PMn1_NOT_USE | _04_PMn2_MODE_INPUT | _08_PMn3_NOT_USE | _F0_PM2_DEFAULT;
  PM3 = _00_PMn0_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT | _FC_PM3_DEFAULT;
  PM4 = _00_PMn0_MODE_OUTPUT | _FE_PM4_DEFAULT;
  PM5 = _01_PMn0_MODE_INPUT | _00_PMn1_MODE_OUTPUT | _FC_PM5_DEFAULT;
  PM6 = _01_PMn0_MODE_INPUT | _02_PMn1_MODE_INPUT | _04_PMn2_NOT_USE | _F8_PM6_DEFAULT;
  PM14 = _00_PMn7_MODE_OUTPUT | _7F_PM14_DEFAULT; 
  
  
  if  ( 
       (po_unused6_1_g == TRUE)&&		
         (po_RXD0_g == FALSE) &&	      
           (po_SHT71_1_DATA_g == TRUE) &&
             (po_SPI_MasterIn_g == TRUE)&&          
               (po_PowerSupplyAna_g == TRUE)&&   
                 (po_PS_SHT1_g == TRUE) )    
  {
    
    /* set the next Outputs! */
    
    
    po_TOOL0_g  = TRUE;
    po_VoltageRegulatorEnable_g = TRUE;
    po_ExternalWDG_g = TRUE;
    po_TXD0_g = TRUE;
    po_SHT71_1_CLK_g = FALSE;
    po_PS_SHT2_g = FALSE;
    po_SPI_MasterOut_g = FALSE;
    po_SPIClock_g = FALSE;
    po_Slave_Select_g  = TRUE;
    po_Div_ON_g  = FALSE;
    rb_ICTest_state_g = CB_ICTEST_PATTERN1_S;    /* next pattern */
  }
  
  
  rbi_ICClock_old_g = TRUE;
  
}

/**************************************************************************
Syntax   : void  ICTEST_1msTask(void)
Object   : ICTEST_1msTask()
Parameters : none
Return  : none
Calls   : in main.c
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Task for ICT
**************************************************************************/

void ICTEST_Task(void)
{
  
  
  switch (rb_ICTest_state_g)
  {
  case CB_NO_ICTEST_S:
    SOFTWARE_RESET();
    break;
    
    
  case  CB_ICTEST_PATTERN1_S:
    
    
    if    ( (po_unused6_0_g == TRUE)&&
           (po_unused6_1_g == TRUE)&&		
             (po_RXD0_g == TRUE) &&	      
               (po_SHT71_1_DATA_g == FALSE) &&
                 (po_SPI_MasterIn_g == TRUE)&&
                   (po_PowerSupplyAna_g == TRUE)&&   
                     (po_PS_SHT1_g == TRUE) )    
    {
      
      /* set the next Outputs! */
      
      
      po_TOOL0_g  = TRUE;
      po_VoltageRegulatorEnable_g = FALSE;
      po_ExternalWDG_g = TRUE;
      po_TXD0_g = FALSE;
      po_SHT71_1_CLK_g = TRUE;
      po_PS_SHT2_g = TRUE;
      po_SPI_MasterOut_g = FALSE;
      po_SPIClock_g = FALSE;
      po_Slave_Select_g  = TRUE;
      po_Div_ON_g  = FALSE;
      
    }
    rb_ICTest_state_g = CB_ICTEST_PATTERN2_S;/* next pattern */
    
    break;
  case  CB_ICTEST_PATTERN2_S:
    
    if    ( (po_unused6_0_g == TRUE)&&
           (po_unused6_1_g == TRUE)&&		
             (po_RXD0_g == TRUE) &&	      
               (po_SHT71_1_DATA_g == TRUE) &&
                 (po_SPI_MasterIn_g == FALSE)&&          
                   (po_PowerSupplyAna_g == TRUE)&&   
                     (po_PS_SHT1_g == TRUE) )    
    {
      
      /* set the next Outputs! */
      
      
      po_TOOL0_g  = TRUE;
      po_VoltageRegulatorEnable_g = FALSE;
      po_ExternalWDG_g = FALSE;
      po_TXD0_g = FALSE;
      po_SHT71_1_CLK_g = FALSE;
      po_PS_SHT2_g = FALSE;
      po_SPI_MasterOut_g = FALSE;
      po_SPIClock_g = TRUE;
      po_Slave_Select_g  = FALSE;
      po_Div_ON_g  = FALSE;
      
      
    }
    rb_ICTest_state_g = CB_ICTEST_PATTERN3_S;
    
    break;
  case  CB_ICTEST_PATTERN3_S:
    
    if    (  (po_unused6_0_g == TRUE)&&
           (po_unused6_1_g == TRUE)&&		
             (po_RXD0_g == TRUE) &&	      
               (po_SHT71_1_DATA_g == FALSE) &&
                 (po_SPI_MasterIn_g == FALSE)&&          
                   (po_PowerSupplyAna_g == FALSE)&&   
                     (po_PS_SHT1_g == TRUE) )    
    {
      
      /* set the next Outputs! */
      
      
      po_TOOL0_g  = TRUE;
      po_VoltageRegulatorEnable_g = TRUE;
      po_ExternalWDG_g = FALSE;
      po_TXD0_g = TRUE;
      po_SHT71_1_CLK_g = FALSE;
      po_PS_SHT2_g = FALSE;
      po_SPI_MasterOut_g = TRUE;
      po_SPIClock_g = FALSE;
      po_Slave_Select_g  = TRUE;
      po_Div_ON_g  = TRUE;
      
    }
    rb_ICTest_state_g = CB_ICTEST_PATTERN4_S;
    
    break;
  case  CB_ICTEST_PATTERN4_S:
    
    if    (  (po_unused6_0_g == TRUE)&&
           (po_unused6_1_g == TRUE)&&		
             (po_RXD0_g == FALSE) &&	      
               (po_SHT71_1_DATA_g == TRUE) &&
                 (po_SPI_MasterIn_g == TRUE)&&         
                   (po_PowerSupplyAna_g == TRUE)&&   
                     (po_PS_SHT1_g == FALSE) )    
    {
      
      /* set the next Outputs! */
      
      
      po_TOOL0_g  = TRUE;
      po_VoltageRegulatorEnable_g = FALSE;
      po_ExternalWDG_g = FALSE;
      po_TXD0_g = TRUE;
      po_SHT71_1_CLK_g = TRUE;
      po_PS_SHT2_g = FALSE;
      po_SPI_MasterOut_g = TRUE;
      po_SPIClock_g = FALSE;
      po_Slave_Select_g  = FALSE;
      po_Div_ON_g  = FALSE;
    }
    rb_ICTest_state_g = CB_ICTEST_PATTERN5_S;
    
    break;
    
    
    
  default:
    
    rb_ICTest_state_g = CB_NO_ICTEST_S;
    
    break;
  } 
}
