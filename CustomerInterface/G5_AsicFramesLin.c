/******************************************************************************/
/*                                                                            */
/*   Valeo Schalter und Sensoren GmbH                                         */
/*   Laiernstrasse 12                                                         */
/*   74321 Bietigheim-Bissingen                                               */
/*                                                                            */
/*   All rights reserved. Distribution or duplication without previous        */
/*   written agreement of the owner prohibited.                               */
/*                                                                            */
/******************************************************************************/

/** \file
 *
 * This file is responsible for creation of ASIC test frames.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: G5_AsicFramesLin.c %    </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.0 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %          </td></tr>
 * <tr> <td> Author:   </td> <td> <name>, <department>  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:23 %   </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> Customer interface              </td></tr>
 * <tr> <td> TARGET:    </td> <td> All</td></tr>
 * </table>
 */

/****************************************************************************/
/* Date      VDR_Number     Description                                     */
/* 13.07.2015 VDR_868  NB  QAC and Polyspace fixing for SW009 Release       */
/****************************************************************************/

/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 3138 EOF */ /* << using of macros from automatic generated code >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 5900,5565,5540 EOF *//*<< Data needs to be verified  >>*/
/******************************************************************************/
/*                Include common and project definition header                */
/******************************************************************************/
#include "ior5f109be.h"
#include "G5_projectDefs.h"
#include "G5_E2ProjectConfig.h"
#include "G5_lininclude.h"
#include "G5_ASIC_Control.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_io.h"
#include "G5_spi_sr.h"
#include "G5_HumTemp.h"
#include "G5_AsicFramesLin.h"
#ifdef ASIC_TEST

/******************************************************************************/
/*                       Definition of local functions                        */
/******************************************************************************/

void CopyRLSDataAsic(void){
  
  if (l_flg_tst_ASIC_Frame_01() )
  {
   
    rbi_ConnectedToMaster_g = 1;                   /* set connected to Master */
    l_flg_clr_ASIC_Frame_01();
  } 
  if (l_flg_tst_ASIC_Frame_02() )
  {
    
    rbi_ConnectedToMaster_g = 1;                   /* set connected to Master */
    l_flg_clr_ASIC_Frame_02();
    rw_LIN_INTV10bit_max_g = 0;
    rw_LIN_INTV10bit_min_g = 1023;
    rb_LIN_STATH_Reg_g = 0;
    
  } 
  if (l_flg_tst_ASIC_Frame_03() )
  {
    
    rbi_ConnectedToMaster_g = 1;                   /* set connected to Master */
    l_flg_clr_ASIC_Frame_03();
  } 
  
  if (l_flg_tst_ASIC_Frame_04() )
  {
    
    rbi_ConnectedToMaster_g = 1;                   /* set connected to Master */
    l_flg_clr_ASIC_Frame_04();
  } 
  
  l_u16_wr_LIN_rw_FW_light16bit_g(get_rw_FW_light16bit_g());
  l_u16_wr_LIN_rw_IR_light16bit_g(get_rw_IR_light16bit_g());
  
  if(get_rw_Amb_light16bit_g() > 0x3FF)
  {
    /*   compiler warning with this  l_u16_wr_LIN_rw_Amb_light16bit_g(0x3FF);*/
    {
      LIN_rw_Amb_light16bit_g_0 = 0xF;
      LIN_rw_Amb_light16bit_g_1 = 0x3F;
    }
  }
  else
  {
    l_u16_wr_LIN_rw_Amb_light16bit_g(get_rw_Amb_light16bit_g());
  }
 
  l_u16_wr_LIN_rw_Solar_light16bit_1_g(rw_Solar_light16bit_1_g);
  l_u16_wr_LIN_rw_Solar_light16bit_2_g(rw_Solar_light16bit_2_g);
  l_u16_wr_LIN_rw_ALS2_ASIC_g(get_rw_ALS2_ASIC_g());
  l_u16_wr_LIN_rw_ALS5_ASIC_g(get_rw_ALS5_ASIC_g());
  l_u16_wr_LIN_rw_INREC_ASIC_g(get_rw_INREC_ASIC_g());
  l_u8_wr_LIN_rb_SupplyVoltage_mg(rb_SupplyVoltage_mg);   
  l_u16_wr_LIN_rw_REGV_Voltage_g(rw_REGV_Voltage_g);
  l_u8_wr_LIN_rb_MaxLightSignalErrorCnt_g(get_rb_MaxLightSignalErrorCnt_g());
  l_u8_wr_LIN_rb_StaticNoCommunicationCounter(rb_StaticNoCommunicationCounter_g);
  l_u8_wr_LIN_rb_SPI_Active_ProblemCounter_g(rb_SPI_Active_ProblemCounter_g);
  l_u8_wr_LIN_rb_StaticHumTempErrorCounter_g(rb_StaticHumTempErrorCounter_g);
  l_u16_wr_LIN_rw_VTEMP_ASIC_g(rw_VTEMP_ASIC_g);
  l_u16_wr_LIN_rw_Vref_ASIC_g(rw_Vref_ASIC_g);
  l_u16_wr_LIN_rw_VDDA_ASIC_g(rw_VDDA_ASIC_g);
  l_u16_wr_LIN_rw_VDDD_ASIC_g(rw_VDDD_ASIC_g);
  l_u16_wr_LW_rw_VILO_ICALLO_GHI_ASIC_g(get_rw_VILO_ICALLO_GHI_ASIC_g());
  l_u16_wr_LIN_rw_VICALLO_ILO_GHI_ASIC_g(get_rw_VICALLO_ILO_GHI_ASIC_g());
  l_u8_wr_LIN_rb_STATH_Reg_g(rb_LIN_STATH_Reg_g);
  l_u8_wr_LIN_rb_ASICReg_NoValidVals_cnt_g(get_rb_ASICReg_NoValidVals_cnt_g());
  
  l_u16_wr_LIN_rw_INTV10bit_max_g(rw_LIN_INTV10bit_max_g);
  l_u16_wr_LIN_rw_INTV10bit_min_g(rw_LIN_INTV10bit_min_g);  
 
}

void ApplTableInitAsic(void){
  
  if (rb_ASIC_Frame_01_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_ASIC_Frame_01_g) != TRUE)
    {
      rb_ASIC_Frame_01_g = CB_DEF_ASIC_FRAME_01;
    }
    rabRAMLinMsgIDToHandleTbl[rb_ASIC_Frame_01_g & 0x3F] = cb_HANDLE_ASIC_Frame_01_g;
  }
  
  if (rb_ASIC_Frame_02_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_ASIC_Frame_02_g) != TRUE)
    {
      rb_ASIC_Frame_02_g = CB_DEF_ASIC_FRAME_02;
    }
    rabRAMLinMsgIDToHandleTbl[rb_ASIC_Frame_02_g & 0x3F] = cb_HANDLE_ASIC_Frame_02_g;
  }
  
  if (rb_ASIC_Frame_03_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_ASIC_Frame_03_g) != TRUE)
    {
      rb_ASIC_Frame_03_g = CB_DEF_ASIC_FRAME_03;
    }
    rabRAMLinMsgIDToHandleTbl[rb_ASIC_Frame_03_g & 0x3F] = cb_HANDLE_ASIC_Frame_03_g;
  }
  
  if (rb_ASIC_Frame_04_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_ASIC_Frame_04_g) != TRUE)
    {
      rb_ASIC_Frame_04_g = CB_DEF_ASIC_FRAME_04;
    }
    rabRAMLinMsgIDToHandleTbl[rb_ASIC_Frame_04_g & 0x3F] = cb_HANDLE_ASIC_Frame_04_g;
  }
}
#endif /* ASIC_TEST */
