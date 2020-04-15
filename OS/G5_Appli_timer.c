/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 0781,759,750,436 EOF */ /* << 0781,436 03 03, unions needed >> */
/* PRQA S 0434,436,0781,4130 EOF */ /* << 0434,0436 usage of SFR >> */
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/* PRQA S 5900,5565,5540 EOF *//*<< Data needs to be verified  >>*/
/* PRQA S 3458,3412 EOF *//*<< required for readability  >>*/
/* PRQA S 0861,0862,5560,5830 EOF */ /* << Compiler specific Includes cannot be analysed by QA-C>> */
/*************************************************************************

Company : Valeo Switches and Detection Systems

Project : RLT Sensor Generation 3.5

Component : Main.c

Documentation reference : System Architectur spec.
---------------------------------------------------------------------------
Overview of the component : This module includes the hardware specific
---------------------------------------------------------------------------
Evolution of the component : */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Name     Description                                */
/*----------------------------------------------------------------------------*/
/* 10.12.10  VCO_090      AL      remove rounding due to overflow*/
/* 02.08.10  RLS_VDR442   AL      VDR_442 change position of if*/  
/* 19.07.10  RLS_VDR550   AL      remove rounding due to overflow*/
/* 17.Jun.10 VDR_535      FS      Redo Baudrate Variation Adaptation from JS*/
/* 01.04.10  VDR_480      AL      delay rainsensor signals  */
/* 18.01.10  VCO_023      AL      undervoltage detection with interrupt*/
/* 06.10.09  VDR_372      AL      remove unused Testpin*/
/* 07.02.08  VDR_128      AL      provide all interrupt vectors */

/* 04.02.2014 VCO_111     NB      SM138:Saftey:Frequency detection function */
/* 04.02.2004 VCO_140     NB      SM150:Saftey:ADC test function */
/* 18.07.2014 VCO_149     NB      Measurement of HT supply using ADC */
/* 24.07.2014 VCO_149     NB      Measurement of HT supply using ADC */
/* 11.08.2014 VDR_800     NB      I2C debug Timeout implementation in case of error */
/* 19.08.2014 VDR_799     NB      LIN_ResponeError on LIN_NOResponse */
/* 24.09.2014 VCO_177     NB      LIN Conformance Test */
/* 19.11.2014 VCO_195     NB      QAC test */
/* 08.12.2014 VCO_151     NB      Implement IC test */
/* 06.02.2015 VDR_840     NB      Disable I2C interrupt if rb_I2C_Debug_Config_g is configured as 0xFF in EEPROM */
/* 17.02.2015 VDR_848     NB      Power supply is not measured above 20V  */
/* 03.03.2015 VCO_227     NB      Implement RAM Guard function */
/* 16.03.2015 VDR_855     MP      Fix of the findings from the review of ASIC_Control_sr*/
/* 24.03.2015 VCO_237     MP      Supplyvoltage should not be monitored on no rain variants*/
/* 13.05.2015 VDR_880     MP      Current consumption and wakeup fast response in standby mode*/
/* 24.06.2015 VDR_885     MP      Sleep mode reached late*/
/* 25.06.2015 VDR_870     NB      Set all unused IO ports of microcontroller to Output low */
/* 29.06.2015 VDR_886     NB      No Frequency errors are set when changing the system clock from 16 to 12 Mhz */
/* 01.07.2015 VDR_886     NB      No Frequency errors are set when changing the system clock from 16 to 12 Mhz */
/* 06.07.2015 VDR_887     NB       Change the thresholds for ADC test function */
/* 06.07.2015 VDR_886     NB      No Frequency errors are set when changing the system clock from 16 to 12 Mhz */
/* 09.07.2015 VDR_886     NB      No Frequency errors are set when changing the system clock from 16 to 12 Mhz */
/* 03.09.2015 VDR_904    NB       Response error is set when invalid LIN header is received  */
/******************************************************************************/
#include "ior5f109be.h"
#include "ior5f109be_ext.h"
#include <intrinsics.h>
#include "G5_projectDefs.h"
#define _timer_c_
#include "G5_Appli_timer.h"
#undef _timer_c_
#include "G5_Appli_lowinit.h"
#include "G5_rainsens.h"
#include "G5_io.h"
#include "G5_spi_sr.h"
#include "G5_E2ProjectConfig.h"
#include "G5_Appli_main.h"
#include "G5_ASIC_Control.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_lininclude.h"
#include "G5_ictest.h"
#include "G5_E2Handler.h"
#include "G5_i2cdebug.h"

/*********** module Global Variables ***********/
__interrupt void vTimer51(void)  ;

static void AD_ConversionSupplyVoltageUpdate(void);

#ifdef RAIN_INTENSITY
word rw_1msTimer_g; /* Rain intensity timer VCO_423  */ 
#endif

/******************************************************************************/
/*                   Definition of local module constants                     */
/******************************************************************************/


/* ============================================================================
**  Module name: vTimer51
**
**  Description:
**               This module is the Interrupt service routine for Timer51
**               The Timer interrupt is used to generate the 500 microSec base clock
**               and calls the needed routines.
**  Operation:
**               -
** ============================================================================
*/

#pragma bank = 2
#pragma vector = INTTM00_vect

__interrupt void vTimer51(void) 

{
  static byte rb_1sTimer_s;
  static byte rub_real_LengthCounter_alt_s;
  static byte rub_real_PulseCounter_alt_s;
  static byte rb_ICTest_WatchDogCounter;
  static byte rb_ICT_Timoutcounter;
  
  __asm("clr1 psw.1"); // priority set to high-level for the execution time
  __asm("clr1 psw.2"); // priority set to high-level for the execution time
  __enable_interrupt(); // nested interrupts allowed
  
  rb_10msTimer_s++;
  rb_ResponseTime_g++; /* VDR_799 */

#ifdef RAIN_INTENSITY
  /* Rain intensity timer: VCO_423 */ 
  if((rb_10msTimer_s&1) == 0)    /* 1ms Tasks */
  {  
    rw_1msTimer_g++;  // increment every 1 ms    
  } 
#endif
 
  if(rb_ICTest_state_g != CB_NO_ICTEST_S)   //are ICT-Tasks needed ?
  {
    if(rb_ICTest_WatchDogCounter > 140) /* 0.5ms x 140 = 70ms */
    { 
      REFRESH_INTERNAL_WATCHDOG(); /* Refresh the internal watch dog at every 70ms */
      rb_ICTest_WatchDogCounter = 0;
      
    }
    else
    {
      rb_ICTest_WatchDogCounter++;
    }
    
    rbi_ICTClkPinState_l = po_unused6_0_g; /* store clock pin state */
    
    if((rbi_ICClock_old_g == FALSE)&&(rbi_ICTClkPinState_l == TRUE)) /* rising Edge? -> Start Task? */
    {
      
      ICTEST_Task();      
      rb_ICT_Timoutcounter = 0;     /* clear timout */
      
    }
    else
    {
      if (rb_ICT_Timoutcounter < 255)   /* rb_ICT_Timoutcounter not reached? */
      {
        rb_ICT_Timoutcounter ++;       /* inkrement rb_ICT_Timoutcounter */
      }
      else
      {
        rb_ICTest_state_g = CB_NO_ICTEST_S;   /* clear ICT_Teststate */
      }
    }
    rbi_ICClock_old_g = rbi_ICTClkPinState_l;       /* set old state of ICT-Port */
  }
  else
  {     
      if(CASE_ASIC_CNT_MD_STANDBY != rb_ASIC_ControlMode_g)
      {
        ASIC_Control_dot5msTask();     // measure after Intout to avoid SPI Signals on Intout
      }
#ifdef _NO_RAIN_
      else
      {
        rbi_speedWasAbove10kmh_g = 0;
      }
#endif /*_NO_RAIN_*/

      if((rb_10msTimer_s&1) == 0)    /* 1ms Tasks */
      {        
/*VCO_237 Supplyvoltage should not be monitored on no rain variants*/
/*is rain function enabled?*/
#ifndef _NO_RAIN_
        io_checkPowerSupply(); 
#endif /*_NO_RAIN_*/
      }
      else
      {
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

        if ((rbi_Modulator_On_g == TRUE) && (rb_Start_STBY_Meas_g==FALSE))
        {
          ASIC_Control_meas_Intout();  /*RS_SigVoltage (Loopvoltage)*/
        }
        else
        {
          rb_DiagRain_HighTime_g = 0;
        }
#endif /*_NO_RAIN_*/

        if(rb_1sTimer_s >= 100)    /* 1s Task */
        {
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
          
          
          if((rbi_Modulator_On_g == TRUE)
             && (rbi_RainIsPresent_g == FALSE)
               && (rbi_speedWasAbove10kmh_g == TRUE)
                 && (rw_NoRainPresentCnt_g <= CW_NO_RAIN_PRESENT_THRSH_g))
          {
            rw_NoRainPresentCnt_g++;
          }
          
#endif /*_NO_RAIN_*/
          rbi_Timer1s_OK_g = TRUE;
          rb_1sTimer_s = 0;
          
          AD_ConversionPerIntStart(po_NTC_INPUT_g);   /* set to measure internal temperature */
          
        }
      }
      
      if((rbi_Modulator_On_g == FALSE)
         || (rbi_RainIsPresent_g == TRUE)
           || (rbi_speedWasAbove10kmh_g == FALSE))
      {
        rw_NoRainPresentCnt_g = 0;
      }
    
    if(rb_10msTimer_s >= 20)
    {
      
      rub_LengthCounter = rub_real_LengthCounter_alt_s;
      rub_PulseCounter= rub_real_PulseCounter_alt_s;
      rub_real_LengthCounter_alt_s = rub_real_LengthCounter;
      rub_real_PulseCounter_alt_s= rub_real_PulseCounter;
      
      if(rb_1sTimer_s != 0)
      { /* skip the supply measurement because already temperature measurement started above */
        AD_ConversionSupplyVoltageUpdate();
      }
      
      if((rb_I2CDebugTimeout_g == 0xFF)||(rb_I2C_Debug_Config_g == 0xFF)) /* VDR_800,840 */
      {
        /*do nothing*/
      }
      else if(rb_I2CDebugTimeout_g > 5)
      {
        LREL0 = 1;  /*  exits from the current communications and sets standby mode*/      
        IICE0 = 0; 
        I2CDbg_Init();
      }
      else
      {
        rb_I2CDebugTimeout_g++; 
      }
      
      rb_10msTimer_s = 0;
      rbi_Timer10ms_OK_g = TRUE;               // Set status flag Timer51
      rb_1sTimer_s++;
    }
    
    
    //                  po_5ms_LED_Ana_g = FALSE;
    
  }
  
  rb_WDG_500usTaskCounter_g++;
  if(CASE_ASIC_CNT_MD_STANDBY == rb_ASIC_ControlMode_g)
  {
    rw_Stby10msTimer_g++;
  }
}


/***********************************************************************************************************************
* Function Name: r_it_interrupt
* Description  : This function is INTIT interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

#pragma vector = INTIT_vect
__interrupt static void r_it_interrupt(void)
{
  /* Start user code. Do not edit comment generated here */
  __asm("clr1 psw.1"); /* priority set to high-level for the execution time*/
  __asm("clr1 psw.2"); /* priority set to high-level for the execution time*/
  __enable_interrupt(); /* nested interrupts allowed*/
  
  R_IT_Stop();
  R_TAU0_Channel0_Start();
  R_ADC_Stop();
  
  rw_Stby10msTimer_g+=101;
  
  rb_WDG_500usTaskCounter_g+=101;
  
  rb_SevenToZeroCounter_g=0;
  
  rb_WDG_IORefreshTaskCounter_g+=5;
  rb_WDG_BusTaskCounter_g+=5;
  rb_WDG_SCITaskCounter_g+=5;
  rb_WDG_LVITaskCounter_g+=5;
  
  po_DVoltageRegulatorEnable_g = OUTPUT;
  po_VoltageRegulatorEnable_g = FALSE;
  
  
  if ((rw_Stby10msTimer_g<((word)1000*(UCONTROLLER_STANDBY_SLEEP_TIME)))&&(rb_WDG_500usTaskCounter_g<100)&&
      (rbi_LIN_CommunicationEvent_g == FALSE))
  {
    ASIC_Control_ChangeModeCmd(CB_ASIC_SLEEP_MD); /* to switch in low power mode SLEEP*/
    
    R_TAU0_Channel5_Stop();
    R_TAU0_Channel6_Stop();
    R_ADC_Stop();
    R_IT_Start();
    R_TAU0_Channel0_Stop();
    STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
  }
  else
  {
    
    if ( rw_Stby10msTimer_g > ((word)1000*(UCONTROLLER_STANDBY_SLEEP_TIME))  )
    {
      po_VoltageRegulatorEnable_g = TRUE;
      
      rb_firstReadComm_g=TRUE;
      rw_Stby10msTimer_g = 0;
      R_TAU0_Channel5_Stop();
      ADS = po_PowerSupply_g;
      ADLL = AD_ADUL_VALUE;
//      AD_ConversionPerIntStart(po_PowerSupply_g);
      ADCE = TRUE;                   // Enables comparator operation (comparator: 1/2AVREF operation)
//      ADMK = FALSE;
      R_ADC_Start(); /*start ADC to measure Supply Voltage everytime the rain is monitored*/
      
      
      if (TRUE == rbi_UnderVoltage_g)
      {
        rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;  /*close windows*/
#ifdef CHANG_AN_S311
        rb_CloseTypeStandby_g = 7;    
#endif
      }
      else
      {
        ASIC_Control_MeasureStandbyMode(); /*call ASIC_Control_MeasureStandbyMode()*/
        STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
      }
      if(CASE_ASIC_CNT_MD_STANDBY == rb_ASIC_ControlMode_g)
      {
        ASIC_Control_ChangeModeCmd(CB_ASIC_SLEEP_MD); /* to switch in low power mode SLEEP*/
      }
      R_IT_Stop();
      R_TAU0_Channel0_Start();
    }
    else /*if (rb_WDG_500usTaskCounter_g>=100)*/
    {
      ASIC_Control_ChangeModeCmd(CB_ASIC_SLEEP_MD); /* to switch in low power mode SLEEP*/
      
      R_TAU0_Channel0_Start();
      R_IT_Stop();
      R_TAU0_Channel5_Start();
      R_ADC_Stop();
    }
    
    if((rb_ASIC_ControlMode_g != CASE_ASIC_CNT_MD_STANDBY)||(rbi_LIN_CommunicationEvent_g == TRUE))
    {
      rb_WDG_RainsensorTaskCounter_g += 7;
	  rb_WDG_LightsensorTaskCounter_g += 7;
      po_VoltageRegulatorEnable_g = TRUE;   /* Switch VR in normal Mode*/
      STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
      rw_Stby10msTimer_g = 0;
      
      R_TAU0_Channel6_Stop();    
      R_TAU0_Channel5_Start();
      R_ADC_Start();
      /*initialise for Wdg Window*/
      R_TAU0_Channel0_Start();
      R_IT_Stop();
      
      if(rbi_LIN_CommunicationEvent_g == TRUE)
      {
        rw_TimeOutCounter_s = TIME_FOR_STANDBY_NORMAL_MEASURE+50;
        ASIC_Control_ChangeModeCmd(CB_ASIC_WAKEUP_MD);
        rb_firstReadComm_g = TRUE;
        STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
        ASIC_Control_ChangeModeCmd(CB_ASIC_INIT_MD);
        STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
        ASIC_Control_AsicStatus();
        STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
        rb_newAsicSTAT_g=FALSE;
        set_rb_ASIC_SPI_ErrorFlag_g(FALSE);
//        rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;       /*set case CASE_ASIC_CNT_MD_RESET*/
      }
      else
      {
        rw_TimeOutCounter_s = TIME_FOR_STANDBY_NORMAL_MEASURE+50;
        rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_INTVH_REG].addr<<1)|0x41);
        rab_SPI_ASICWriteBuffer_mg[1] = 0x80;
        rab_SPI_ASICWriteBuffer_mg[2] = 0;
        rb_SPI_Data_to_send_g = 3;
        SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
        rb_SPI_Data_to_send_g = 0;
        STANDBY_WAIT_FOR_FREE_SPI();
        
        ASIC_Control_ChangeModeCmd(CB_ASIC_LOOP2_MD);
      }
    }
  }
  /* End user code. Do not edit comment generated here */
}
#endif /*_NO_RAIN_*/


/***********************************************************************************************************************
* Function Name: r_tau0_channel5_interrupt
* Description  : This function is INTTM05 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma vector = INTTM05_vect
__interrupt static void r_tau0_channel5_interrupt(void) /* RLS_VCO_111 */
{
  static byte rb_RetryAttempt_mg;
  word rw_Pulse_width_l;
  
  if(rb_RetryAttempt_mg == 0)
  {
    rb_RetryAttempt_mg++; /* discard the first value */
  }
  else
  {
    rb_RetryAttempt_mg = 0;
    
    if (0U == (TSR05 & _0001_TAU_OVERFLOW_OCCURS))    /* no overflow occurs */
      
    {
      rw_Pulse_width_l = (word)TDR05;
      rw_Pulse_width_l = rw_Pulse_width_l + 1;
    }
    else
    {
      rw_Pulse_width_l = 0xFFFFU; /* overflow occured*/
      
    }
    /* As per the data sheet 2% deviation for clock freq and 15% deviation for 15k clock,so 17% deviation is allowed*/
    /* for the safer side 20% deviation is considered */
    /* clock freq = rw_Pulse_width_g * 15000*/
    /* 20% of clock freq is 19.2 MHz - 12.8 MHz 
    count could vary from 1280 to 853*/
    
    R_TAU0_Channel5_Stop(); /* Stop Frequency measurement, it started once in 70ms */ 
    
    if((rw_Pulse_width_l < 853 )||(rw_Pulse_width_l > 1280)) /* +- 20% deviation */
    {
      if(rb_ClockFreq_Error_cnt_g < cb_CLOCKFREQ_ERROR_CNT_THRESHOLD_g)
      {
        rb_ClockFreq_Error_cnt_g++;
      }
      else
      {
        rbi_ClockFreq_Error_g = 1; /* Error in operatiing frequency */
      }
    }
    else 
    {
      if(rbi_EEPROMLoad_g == FALSE) /* EEPROM loaded*/ /*VDR_886*/
      {
        if(rb_ClockFreq_Error_cnt_g >0)
        {
          rb_ClockFreq_Error_cnt_g--;
        }
        else
        {
          rbi_ClockFreq_Error_g = 0; 
        }
      }
    }
    
  } 
  
}


/***********************************************************************************************************************
* Function Name: r_tau0_channel6_interrupt
* Description  : This function is INTTM06 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma vector = INTTM06_vect
__interrupt static void r_tau0_channel6_interrupt(void)
{
  TMIF06 = 0U;    /* clear INTTM06 interrupt flag */
  TMMK06 = 1U;    /* disable INTTM06 interrupt */
  
  rw_CDIV256_period_g = TDR06;
  rb_CDIV256_OVF_g = (byte)(TSR06);
  
}







/**************************************************************************
Syntax   : interrupt [INTAD_vect] void ADC_Interrupt(void)
Object   :
Parameters : none
Return  : none
Calls   : vector.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code : handles the ADC Converison
*************************************************************************/
/*
Temperature conversion
Example 1:
- Using an external reference voltage of 3.30V 
- Temperature would be 25 deg C  ---> Temperature sensor voltage should be 1050mV (as in usermanual table 31.7.2)
8 bit resolution
==> ADCR result:  1050mV / 3300mV x 256  = 81

Example 2:
- Using an external reference voltage of 3.30V 
- Temperature would be 85 deg C ---> Temperature sensor voltage should be:  1050mV - (3.6mV x 60) = 834mV
==> ADCR result:  834mV / 3300mV x 256  = 64
*/

#pragma vector=INTAD_vect /* interrupt vector*/
__interrupt void ADC_Interrupt(void)
{
  static byte rb_ADC_State_s;
  byte rb_ADC_Result_l;
  byte rb_ReferenceVoltage_l;
  
  rb_ADC_Result_l= (ADCRH); 
  ADUL = _FF_AD_ADUL_VALUE; /* set to default value */ /* VDR_848 */
#ifdef _NO_RAIN_/*for no rain variant, default value used for supply voltage*/
    rb_SupplyVoltage_mg = cb_SUPPLYVOLTAGE_DEF_g;
#endif /*_NO_RAIN_*/
  switch ( ADS )
  {
  case po_PowerSupply_g: //ADPort 7
/*VCO_237 Supplyvoltage should not be monitored on no rain variants*/
/*is rain function enabled?*/
#ifndef _NO_RAIN_
      rb_SupplyVoltage_mg = rb_ADC_Result_l;
      
      if(rb_SupplyVoltage_mg < AD_ADUL_VALUE) /* less than 8.0 v */
      {
        ADLL = _00_AD_ADLL_VALUE;
        IO_ExternalUnderVoltageEvent();
      }
      else
      {
        ADLL = AD_ADUL_VALUE;
      }
#else
    ADLL = _00_AD_ADLL_VALUE;
#endif /*_NO_RAIN_*/
    break;
    
  case po_NTC_INPUT_g: /*NTC-AD-Port*/
    if(rb_ADC_State_s >= 1 ) /* discard the first reading which is not correct */
    {
      rb_ADC_State_s = 0;
      rb_InternalTemperature_g = rb_ADC_Result_l ;
      AD_ConversionPerIntStart(po_ADC_TEST_g);
    }
    else
    {    
      rb_ADC_State_s ++;
    }
    
    break;
    
  case po_ADC_TEST_g: /*ADC Test-Port*/ /* VCO_140 */
    /* v = ADCRH/256 x 3.3v */
    rb_ReferenceVoltage_l = rb_ADC_Result_l ;
    /* As per the controller user manual the tolerance of the internal reference voltage is as below
 When 2.7V < VDD < 5.5V then  vref is 1.38(min) 1.45(Avg) 1.5 (max)
 And VDD output from SBC is varies from 3.23V to 3.37V
 by considering additional 7% tolerance the ADC test value varies from 97 to 127 */
    if((rb_ReferenceVoltage_l > 127)|| (rb_ReferenceVoltage_l < 97)) 
    { 
      if(rb_ADC_Error_cnt_g < cb_ADC_ERROR_CNT_THRESHOLD_g)
      {
        rb_ADC_Error_cnt_g++;
      }
      else
      {
        rbi_ADC_Error_g = 1;  /* ADC not working correctly */
      }
      
    }
    else
    {
      if(rb_ADC_Error_cnt_g > 0)
      {
        rb_ADC_Error_cnt_g--;
      }
      else
      {
        rbi_ADC_Error_g = 0;
      }
      
    }
    
    AD_ConversionPerIntStart(po_PowerSupply_g);
    break; 
    
  case po_SHT_Supply_g: /* channel ANI16 to measure the supply of SHT module */
    
    po_DSHT71_1_DATA_g = INPUT; /* set the direction of SHT data line to INPUT to check  short to GND */
    
    if(rb_ADC_Result_l >= 170 ) /* above 2.2 v is OK  */
    {
      /* set the analog port to digital*/
      Change_AnalogPortToDigital();
      /* Switch ON the second port */
      po_PS_SHT1_g = TRUE;
      po_D_PS_SHT1_g = OUTPUT;
      
      rbi_HumiSupply_OK_g = 1;
      rb_SHT_SupplyRetryCounter_g = 0;
    }
    else
    {
      
      /* switch off the supply for SHT module */
      po_PS_SHT2_g = FALSE;
      po_D_PS_SHT2_g = OUTPUT;
      /* Change the analog port to digital */
      Change_AnalogPortToDigital();
      
      /* switch off the second supply port */
      po_PS_SHT1_g = FALSE;      
      po_D_PS_SHT1_g = OUTPUT;
      rbi_HumiSupply_OK_g = 0;
      
    }
    
    
    if(po_SHT71_1_DATA_g == HIGH) /* shoud read high due to pull up */ 
    {
      /* no shortcut to GND */
      rbi_SHT_DataLine_OK_g  = 1;
      
    }
    else
    {
      /* shorted to ground */
      rbi_SHT_DataLine_OK_g  = 0;
    }
    
    AD_ConversionPerIntStart(po_PowerSupply_g);   
    break;
    
    
    
  default:
    ADS = po_PowerSupply_g;
    ADCS    = FALSE;                     // Stop AD-Conversion
    ADCE   = FALSE;                      // stop comparator operation
    ADMK=TRUE;  
    //   rb_SupplyVoltage_mg = IntTemp;//disable ADC interrupt
    break;
    
    
  }
  ADIF = FALSE;                 // Reset status flag ADC
  
}

/**************************************************************************
Syntax   : interrupt [INTAD_vect] void ADC_Interrupt(void)
Object   :
Parameters :
rb_channel_l: channel to start conversion
Return  :
returnvalue_l: conversion was running
Calls   : vector.c
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code : handles the ADC Converison
*************************************************************************/

__callt void AD_ConversionPerIntStart(byte rb_channel_l)
{
  ADCS    = FALSE;                   // Stop AD-Conversion     
  ADCE    = FALSE;                   // Disables comparator operation (comparator: 1/2AVREF operation)
/*VCO_237 Supplyvoltage should not be monitored on no rain variants*/
/*is rain function enabled?*/
#ifndef _NO_RAIN_
  if(rb_channel_l ==  po_PowerSupply_g)
  {
    ADLL = AD_ADUL_VALUE;
    ADUL = _FF_AD_ADUL_VALUE; /* set to default value */ /* VDR_848 */
  }
  else
#endif /*_NO_RAIN_*/
  {
    ADLL = _FE_AD_ADLL_VALUE;
    ADUL = _00_AD_ADLL_VALUE; /* VDR_848 */
  }

  
  ADS     = rb_channel_l;           // Set selected A/D channel

/*VCO_237 Supplyvoltage should not be monitored on no rain variants*/
/*is rain function enabled?*/
#ifdef _NO_RAIN_
  if(rb_channel_l !=  po_PowerSupply_g)
#endif /*_NO_RAIN_*/
  {
    if(CASE_ASIC_CNT_MD_STANDBY!=rb_ASIC_ControlMode_g)
    {
      ADCE     = TRUE;                   // Enables comparator operation (comparator: 1/2AVREF operation)
      ADCS    = TRUE;                   // Start AD-Conversion
    }
  }
  
}


static void AD_ConversionSupplyVoltageUpdate(void)
{
  ADUL = _00_AD_ADLL_VALUE ;/* VDR_848 */ /*  set the 0 value to get interrupt so that supply voltage can be measured */
}

void Change_AnalogPortToDigital(void)
{
  /* Change the analog port to digital */
  
  PMC0 = _00_PMCn0_DI_ON | _00_PMCn1_DI_ON | _FC_PMC0_DEFAULT;
  PM0 = _00_PMn0_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT | _FC_PM0_DEFAULT;
  
}

void Change_DigitalPortToAnalog(void)
{
  /* change digital port to analog */
  /* Set ANI16 pin */
  PMC0 |= 0x02U; /* analog mode */
  PM0 |= 0x02U; /* input mode */
  
}


/**************************************************************************
Syntax   : interrup tvectors unsused
Object   :
Parameters : none
Return  : none
Calls   : vector.c
***************************************************************************
Inputs validation conditions:
***************************************************************************
Pseudo-code :the following functions are to disable interrupt in an error
case that the system does not hang up
*************************************************************************/


#pragma vector=INTP1_vect /*VDR_128 interrupt vector*/
__interrupt void INTP1_vect_Int(void)
{
  /* wake up pattern is detected immediately after sleep command
  Avoid go to sleep and deactivate the external interrupt */
  
  rw_NoCommunicationCounter_g = 0;
  rbi_LIN_CommunicationEvent_g = TRUE;
#ifndef STANDBY_LIN_WAKE_UP_ISSUE //VC0_477 added this for can not be waked up when it is in standby mode at 2018.04.16
   PMK1 = 1; /* disable interrupt*/
#endif
  
}

#pragma vector=INTP2_vect /*VDR_128 interrupt vector*/
__interrupt void INTP2_vect_Int(void)
{
  PMK2 = 1; /* disable interrupt*/
}

#pragma vector=INTP3_vect /*VDR_128 interrupt vector*/
__interrupt void INTP3_vect_Int(void)
{
  PMK3 = 1; /* disable interrupt*/
}

#pragma vector=INTP4_vect /*VDR_128 interrupt vector*/
__interrupt void INTP4_vect_Int(void)
{
  PMK4 = 1; /* disable interrupt*/
}

#pragma vector=INTP5_vect /*VDR_128 interrupt vector*/
__interrupt void INTP5_vect_Int(void)
{
  PMK5 = 1; /* disable interrupt*/
}

#pragma vector=INTSR0_vect /*VDR_128 interrupt vector*/
__interrupt void INTSR0_vect_Int(void)
{
  SRMK0 = 1; /* disable interrupt*/
}

#pragma vector=INTLVI_vect /* interrupt vector*/
__interrupt static void INTLVI_vect_Int(void)
{
  LVIMK = 1U;     /* disable INTLVI interrupt */
}