/*************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : io.c

Documentation reference : Hardware Software Interface File
Overview of the component : interface to the electronics

Evolution of the component : see PVCS Version control system

Initials   date   modification

*************************************************************************/
/* History                                                              */
/*----------------------------------------------------------------------*/
/* Date     VDR_Nr    Name    Description                               */
/*----------------------------------------------------------------------*/
/* 30.08.10  VCO_74           make file compatible with old versions*/
/* 16.02.10  VDR_438          adapt voltage level for Hardware H02 avoid Problems at short voltage interrupts*/ 
/* 02.02.10  VDR_436    AL    solve Problem with undervoltage detection*/
/* 18.10.10  VCO_23           new function to react at undervoltge event using the interrupt*/
/* 20.11.09  VDR_405    AL    use only 4 AD-Ports for B3 Dsign*/
/* 26.10.09  VDR_390	AL    deactivate NTC for undervoltage */
/* 24.09.09  VDR_372	AL    Mesurment of NTC and usage of new Micro Controller Ports
                               PWM could be switched to portpin by EEPROM 
                               Usage of EEPROM Cell for Amb Night and DayThreshold
                               Remove EEPROM valeo for IR and FW scaling for VWK*/
/* 18.07.2014 VCO_149   NB    Measurement of HT supply using ADC */
/* 16.01.2015 VDR_833   MP    Previous value of wiper speed not stored when a under voltage applied*/
/* 24.03.2015 VCO_237   MP    Supplyvoltage should not be monitored on no rain variants*/
/* 08.04.2015 VDR_870   NB    Set all unused IO ports of microcontroller to Output low */ 
/* 16.1.2015 VDR_927    NB    Wiper speed is valid on the bus only after 1.35 sec  */
/* 30.03.2016 VDR_967   NB    Set the supply of SHT module to output low if SHT module not used  */

/*************************************************************************
**                   Common and module include-file                     **
**************************************************************************/
/** Include Files **/

/* PRQA S 0781,759,436,434 EOF */ /* << 0781,436 03 03, unions needed >> */

#include "ior5f109be.h"
#include "ior5f109be_ext.h"
#define _io_c_             //Define for Single include of Global Header G5_io.h

#include "G5_io.h"
#include "G5_Appli_timer.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_rainsens.h"
#include "G5_Appli_Lowinit.h"
#include "G5_DiagE2_projectconfig.h"
#include "G5_E2Handler.h"
/*************************************************************************
**                   Other files included                               **
**************************************************************************/
#include "G5_rls_linst.h"
/*************************************************************************
**                   Compile options                                    **
**************************************************************************/

/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/
/*VCO_237 Supplyvoltage should not be monitored on no rain variants*/
/*is rain function enabled?*/
#ifndef _NO_RAIN_
static byte rb_To_LowVoltage_Counter_mg;
#endif /*_NO_RAIN_*/

/*************************************************************************
**                   Declaration of local module functions              **
**************************************************************************/



/*************************************************************************
**                   Declaration of local module macros                 **
**************************************************************************/



/**************************************************************************
Syntax   : void  IO_Ports_init(void)
Object   : IO_Ports_init()
Parameters : none
Return  : none
Calls   : in main.c
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Initialize all ports of the Microcontroller
**************************************************************************/


void IO_Ports_init(void)
{
  /* switch Voltage Regulator ON */
  po_VoltageRegulatorEnable_g	 = TRUE;
  po_DVoltageRegulatorEnable_g = OUTPUT;
  
  rb_SupplyVoltage_mg = cb_SUPPLYVOLTAGE_DEF_g;/* set the supply volatage to default value */
  
 /* switch Voltage divider ON */
  po_Div_ON_g = TRUE;
  po_D_Div_ON_g  = OUTPUT;
  PM1_bit.no6=OUTPUT;
  
}


/**************************************************************************
Syntax   : void  io_checkPowerSupply(void)
Object   : io_checkPowerSupply()
Parameters : none
Return  : none
Calls   : in timA.c (cyclic every 1ms)
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Checks the PowerSupply voltage and sets the ASIC in STOP
Mode under 8,5 Volt and Stops the Micro Controller under 6V...
Wakes the ASIC and the Micro Controller over 9V
**************************************************************************/
/*is rain function enabled?*/
#ifndef _NO_RAIN_
#ifdef GEELY2DOT0
__callt void io_checkPowerSupply(void)
{
  static word rw_overvoltageCounter_s;
  static byte rb_CheckSupplyMode_s;


  if (rb_SupplyVoltage_mg > cb_ASIC_RS_OVERVOLTAGE_HIGH_OFF_mg)

  {
    if (rw_overvoltageCounter_s > 10000)//Error will be reported after 10 seconds presence of over voltage
    {
      rbi_OverVoltage_g = TRUE;         // switching Modulator off is organised with Modulator Controll!

      ASIC_Control_PAUSE_RS_Function();
    }
    else
    {
      rw_overvoltageCounter_s ++;
    }

    rb_CheckSupplyMode_s = 0;
    rbi_UnderVoltage_g = FALSE;
    rbi_Powerfail_g = FALSE;
    rb_To_LowVoltage_Counter_mg = 0;
  }
  else // no Overvoltage !
  {
    
    if(rb_SupplyVoltage_mg >= 214)//17V
    {  
       if (rw_overvoltageCounter_s > 10000)
       {
          ASIC_Control_PAUSE_RS_Function();
       }
       else
       {
          rb_CheckSupplyMode_s = 0;
          rbi_UnderVoltage_g = FALSE;
          rbi_Powerfail_g = FALSE;
          rb_To_LowVoltage_Counter_mg = 0;
       }
    }
    else
    {
      rw_overvoltageCounter_s = 0;
      rbi_OverVoltage_g = FALSE;
      if (rb_SupplyVoltage_mg >= cb_START_RS_ASICVOLTAGE_mg)
      {
        rbi_WasInOperatingRange_g = TRUE;
        rbi_UnderVoltage_g = FALSE;
        rbi_Powerfail_g = FALSE;
        rb_CheckSupplyMode_s = 0;
        rb_To_LowVoltage_Counter_mg = 0;
      }
      else if (rb_SupplyVoltage_mg >= cb_STOP_RS_ASICVOLTAGE_mg)
      {
        // do not change undervoltage
        rb_To_LowVoltage_Counter_mg = 0;
        rbi_Powerfail_g = FALSE;
        rb_CheckSupplyMode_s = 0;
      }
      else  // undervoltage or powerfail!
      {

        rbi_UnderVoltage_g = TRUE;
        rbi_Powerfail_g = FALSE;

        if (rb_SupplyVoltage_mg < cb_VERYLOWVOLTAGE_mg)
        {
          if (rb_To_LowVoltage_Counter_mg < 255)
          {
            rb_To_LowVoltage_Counter_mg ++;
          }
          else
          {
            rbi_UnderVoltage_g = FALSE;
          }
        }
        else
        {
          rb_To_LowVoltage_Counter_mg = 0;
        }

        if (rb_To_LowVoltage_Counter_mg < 255)
        {
          ASIC_Control_PAUSE_RS_Function() ;

          if ((rb_SupplyVoltage_mg < cb_GOTOSLEEPVOLTAGE_mg)&&(rbi_WasInOperatingRange_g == TRUE)) // powerfail?)
          {
            rbi_Powerfail_g = TRUE;
            // set ASIC in Snozze Mode
            if (rb_CheckSupplyMode_s ==0 )
            {
              //SPI_Write_Byte(ASIC_TO_SNOOZE_MOD);                      // to switch in low power mode SNOZZE
              rb_CheckSupplyMode_s = 1;
              ASIC_Control_RESET_ASIC_ControlMode() ;
            }
            
          }
        }
       }
      }
      
  }
}
#else
__callt void io_checkPowerSupply(void)
{
  static word rw_overvoltageCounter_s;
  static byte rb_CheckSupplyMode_s;


  if (rb_SupplyVoltage_mg > cb_ASIC_RS_OVERVOLTAGE_OFF_mg  )

  {
    if (rw_overvoltageCounter_s > 2000)
    {
      rbi_OverVoltage_g = TRUE;                 // switching Modulator off is organised with Modulator Controll!

      ASIC_Control_PAUSE_RS_Function();
    }
    else
    {
      if (rb_SupplyVoltage_mg > cb_ASIC_RS_OVERVOLTAGE_HIGH_OFF_mg)
      {
        rw_overvoltageCounter_s ++;
      }
      rw_overvoltageCounter_s ++;
    }

    rb_CheckSupplyMode_s = 0;
    rbi_UnderVoltage_g = FALSE;
    rbi_Powerfail_g = FALSE;
    rb_To_LowVoltage_Counter_mg = 0;
  }
  else // no Overvoltage !
  {
    rw_overvoltageCounter_s = 0;
    rbi_OverVoltage_g = FALSE;
    if (rb_SupplyVoltage_mg >= cb_START_RS_ASICVOLTAGE_mg)
    {
      rbi_WasInOperatingRange_g = TRUE;
      rbi_UnderVoltage_g = FALSE;
      rbi_Powerfail_g = FALSE;
      rb_CheckSupplyMode_s = 0;
      rb_To_LowVoltage_Counter_mg = 0;
    }
    else if (rb_SupplyVoltage_mg >= cb_STOP_RS_ASICVOLTAGE_mg)
    {
      // do not change undervoltage
      rb_To_LowVoltage_Counter_mg = 0;
      rbi_Powerfail_g = FALSE;
      rb_CheckSupplyMode_s = 0;
    }
    else  // undervoltage or powerfail!
    {

      rbi_UnderVoltage_g = TRUE;
      rbi_Powerfail_g = FALSE;

      if (rb_SupplyVoltage_mg < cb_VERYLOWVOLTAGE_mg)
      {
        if (rb_To_LowVoltage_Counter_mg < 255)
        {
          rb_To_LowVoltage_Counter_mg ++;
        }
        else
        {
          rbi_UnderVoltage_g = FALSE;
        }
      }
      else
      {
        rb_To_LowVoltage_Counter_mg = 0;
      }

      if (rb_To_LowVoltage_Counter_mg < 255)
      {
        ASIC_Control_PAUSE_RS_Function() ;

        if ((rb_SupplyVoltage_mg < cb_GOTOSLEEPVOLTAGE_mg)&&(rbi_WasInOperatingRange_g == TRUE)) // powerfail?)
        {
          rbi_Powerfail_g = TRUE;
          // set ASIC in Snozze Mode
          if (rb_CheckSupplyMode_s ==0 )
          {
            //SPI_Write_Byte(ASIC_TO_SNOOZE_MOD);                      // to switch in low power mode SNOZZE
            rb_CheckSupplyMode_s = 1;
            ASIC_Control_RESET_ASIC_ControlMode() ;
          }
          
        }
      }
    }
  }
}
#endif
#endif /*_NO_RAIN_*/


/**************************************************************************
Syntax   : void  IO_ExternalUnderVoltageEvent(void)
Object   : IO_ExternalUnderVoltageEvent()
Parameters : none
Return  : none
Calls   : from interrupt to stop rain sensor 
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Sets the status if a external routin detects undervoltage
**************************************************************************/
/*is rain function enabled?*/
#ifndef _NO_RAIN_
void IO_ExternalUnderVoltageEvent(void) /*VCO_23 function to support undervoltage detection by interrupt*/
{
 
    rbi_UnderVoltage_g = TRUE; /*set status Flags*/
    rbi_Powerfail_g = FALSE;
    rb_ALInitTimer_g = 0;
    rw_InitTimer_mg = 0;
    /*VDR_833 Previous value of wiper speed not stored when a under voltage applied*/
    /*Rainsensor_inactive();*/
    if (rb_To_LowVoltage_Counter_mg < 255)
    {
      ASIC_Control_PAUSE_RS_Function();
    }
}
#endif /*_NO_RAIN_*/


/**************************************************************************
Syntax   : void  IO_RefreshPorts(void)
Object   : IO_RefreshPorts()
Parameters : none
Return  : none
Calls   : in main.c (cyclic every 10ms)
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Refreshs all Micro Controller Hardware Ports
**************************************************************************/
void IO_RefreshPorts(void)
{

  if ( rbi_GotoSleep_g == FALSE)
  {
    if(CASE_ASIC_CNT_MD_STANDBY != rb_ASIC_ControlMode_g)
    {
      po_VoltageRegulatorEnable_g = TRUE;
      po_DVoltageRegulatorEnable_g = OUTPUT;
    }
  }

if(rbi_HumTemp_Module_enabled_g == TRUE)  
{
  if(rbi_HumiSupply_OK_g == TRUE)
  {
  /*Power supply for SHT module */
  po_PS_SHT1_g = TRUE;      
  po_D_PS_SHT1_g = OUTPUT;
  po_PS_SHT2_g = TRUE;
  po_D_PS_SHT2_g = OUTPUT;
  } 
}
else
{
   /* Change the analog port to digital */
  
  PMC0 = _00_PMCn0_DI_ON | _00_PMCn1_DI_ON | _FC_PMC0_DEFAULT;
  
  /* set the port to output low */
  /* power supply */
  po_PS_SHT1_g = FALSE;      
  po_D_PS_SHT1_g = OUTPUT;
  po_PS_SHT2_g = FALSE;
  po_D_PS_SHT2_g = OUTPUT;
  
  /* SHT1x Data Line */
  po_SHT71_1_DATA_g = FALSE;
  po_DSHT71_1_DATA_g = OUTPUT;
  /* SHT1x Clock Line */
  po_SHT71_1_CLK_g = FALSE;
  po_DSHT71_1_CLK_g  = OUTPUT; 
  
}

if ((rb_I2C_Debug_Config_g == 0xFF)&&(rbi_EEPROMLoad_g == FALSE))/* Debug configuration disabled*/
{ 
  /* set the port to output low */
  IICA0EN = 0U; /* disable supply IICA0 clock */
  IICE0 = 0U; /* disable IICA0 operation */
  
  po_I2C_Debug_CLK_g = FALSE;
  po_D_I2C_Debug_CLK_g = OUTPUT;
  po_I2C_Debug_DATA_g = FALSE;
  po_D_I2C_Debug_DATA_g = OUTPUT;
  
}
  po_D_SPI_MasterIn_g = INPUT;         //SPI MasterIn to Input
  po_D_SPI_MasterOut_g = OUTPUT;       //SPI MasterOut to OUTPUT
  
  po_Div_ON_g = TRUE;
  po_D_Div_ON_g  = OUTPUT;


  /*  switch the unused ports to Gnd */
  
  po_unused6_2_g    = FALSE;
  po_D_unused6_2_g  = OUTPUT;
  po_unused7_0_g    = FALSE;
  po_D_unused7_0_g  = OUTPUT;
  po_unused1_7_g    = FALSE;
  po_D_unused1_7_g  = OUTPUT;
  po_unused1_6_g    = FALSE;
  po_D_unused1_6_g  = OUTPUT;
  po_unused2_3_g    = FALSE;
  po_D_unused2_3_g  = OUTPUT;  
  po_unused12_0_g    = FALSE;
  po_D_unused12_0_g  = OUTPUT;

  

  
  
  
}




