
/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/
/* PRQA S 0781,759,436 EOF */ /* << 0781,436 03 03, unions needed >> */
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 0434,0436,1015 EOF */ /* << 0434,0436 usage of SFR >> */  
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 5900,5565,5540,5560 EOF *//*<< Data needs to be verified  >>*/
/*************************************************************************

Company : Valeo Switches and Detection Systems

Project : RLT Sensor Generation 3.5

Component : Main.c

Documentation reference : System Architectur spec.
---------------------------------------------------------------------------
Overview of the component : This module organises the call of all
software routines it includes the 10ms Operating system.
---------------------------------------------------------------------------
Evolution of the component : see PVCS Version control system

*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  NAME Description                                       */
/*----------------------------------------------------------------------------*/
/* 10.Juni11 VDR664    AL   improve Bootloader security */
/* 26.May11  VSC_9     FS   New define ___PHYSICAL_STACK_CALC__ and code added*/
/* 31.03.11  VCO_092   AL   Add additional counters for SW-Watchdog */
/* 24.03.11  VDR_638   AL   MISRA OPTIMISATION with corrections in Source code PARTLY */
/* 22.Mar11  VCO_95    AL   Increase Flash Range */
/* 15.Mar11  VSC_4    FS    Implement compiler defines project related, also QAC-defines*/
/* 10.12.10  VCO_090     AL   store failure in EEPROM */
/* 22.10.10  VDR_594     JS   Write check for traceability data */
/* 15.10.10  VCO_79        Adaptation for BATC based on LADA */
/* 13.10.10  RLS_VDR_589  AL  adder to Adress for Production Data*/
/* 16.07.10  RLS_VCO_62       RLS_All:Use Boot Cluster 1 for ROM Code */
/* 27.05.19  VCO_051     AL   Use _Callt functions to speed up initialisation*/
/* 26.05.10  VCO_050     AL   switch light on for one cylce after watchdog reset*/
/* 05.05.10  VDR_505          rework function for flexible usage */
/* 29.04.10  VDR511_3    AL   correct timout of bootload*/
/* 01.04.10  VDR_479     AL   use more Flash memory*/
/* 23.03.10  VDR_446     FS   ASIC-Frequency work around*/
/* 23.02.10  VDR_465     AL   write only one EEPROM errorcode in LIN-Pause!*/
/* 23.02.10  VDR_349     FS   ASIC Frequency Trimming Switched Off*/
/* 23.02.10  VCO_34      AL   implementation of incident counters"*/
/* 02.02.10  VDR_436     AL   solve Problem with undervoltage detection*/
/* 18.01.10  VCO_023     AL   undervoltage detection with interrupt*/
/* 02.07.09  VDR_345     AL   HT-Function and partnumber configurable in EEPROM */
/* 26.01.09  VDR_306     FS   Frequency Default value to be set in main-Init, not in ASIC-Init in ASIC-Control.c*/
/* 11.06.08  VDR_227     FS   Update this file to Lada */
/* 13.02.08  VDR_197     FS   Include ReInit for LS-Algo */
/* 13.02.08  VDR_138     FS   No change, only to use latest revision (due to TMC445L-Project) */
/* 23.01.08  VDR_125     AL   deactivate debug operation                        */
/* 07.02.08  VDR_129     AL   Check of Sensitivity treatment*/
/* 08.02.08  VDR_143     AL   set location for option bytes*/


/* 12.08.14  VDR_797  NB        Watchdog reset due to High CPU load while erasing the EEPROM cluster */
/* 26.08.14  VDR_801  NB        Findings from Integration test               */
/* 15.09.14  VCO_184  NB        Checksum for calibration data */
/* 22.09.14  VCO_152  NB        Customenr part number shall be stored in EEPROM */
/* 18.11.14  VCO_193  NB        Enable Low voltage detection feature in microcontroller */
/* 08.12.14  VCO_151  NB        Implement IC test */
/* 03.03.15  VCO_227  NB        Implement RAM Guard function */
/* 09.03.15  VCO_227  NB        Implement RAM Guard function */
/* 01.04.15  VDR_866  MP        Remove of rainsens.c for no-rain-variants*/
/* 09.04.15  VCO_241  NB        Implement test function for RAM Guard with one dedicated cell */
/* 04.05.15  VDR_871  NB        Safety: all reset sources from RESF should be used except the voltage detector flag */
/* 13.05.15  VDR_880  MP        Current consumption and wakeup fast response in standby mode*/
/* 10.06.15  VDR_868  NB        All:QAC and Polyspace fixing for SW009 Release  */
/* 10.06.15 VCO_254   NB       Checking of CRC over light area shall be done cyclically  */
/* 01.07.15 VCO_241    NB      Implement test function for RAM Guard with one dedicated cell */
/* 09.07.2015 VDR_886     NB      No Frequency errors are set when changing the system clock from 16 to 12 Mhz */
/* 02.10.2015 VCO_276   NB      Initialise LIN ID's after loading PD section */
/* 02.12.2015 VDR_940   NB      write reset source in EEPROM                 */
/* 23.02.2016 VDR_949   NB      Watchdog reset while refreshing in the counter              */
/* 24.03.2016 VCO_316   NB   No_init RAM values shall be used to connect  bootload mode instead of EEPROM */
/*----------------------------------------------------------------------------*/
/* Description of Option Bytes */

/* PRQA S 3408 15 */ /* <<for easier declaration of variable -> proven mechanism>> */
/* Set option bytes */
/*  opbyte0 : Operation of watchdog timer
            bit0: counter operation in HALT/STOP mode   
            bit1-3: setting of overflow time 
            bit4: Enable/Disable watchdog 
            bit5-6: Window open period 
            bit7: Enable/Disable interrupt 
    opbyte1 : Setting of Low Voltage Detection operation mode
            bit0-1: Mode setting   
            bit2-7: voltage level setting   
    opbyte2 : Setting of Frequency and Flash operation mode
            bit0-3: Setting of frequency
            bit5: Setting of threshold voltage 
            bit6-7: Setting of Operation mode

    opbyte3 : On chip debug operation mode
            bit0 and 7: enable and disable of debug mode
*/
/* PRQA S 3408 15 */ /* << has external linkage >> */  
/* Set option bytes */
#pragma location = "OPTBYTE"
__root const unsigned char opbyte0 = 0x79U;  /*75% window open time */
#pragma location = "OPTBYTE"
__root const unsigned char opbyte1 = 0x7BU; /*Enable LVI in reset mode. Raise:2.92V, Fall: 2.86V */
#pragma location = "OPTBYTE"
__root const unsigned char opbyte2 = 0xE9U;
#pragma location = "OPTBYTE"
__root const unsigned char opbyte3 = 0x04U;

/* Set security ID */
#pragma location = "SECUID"
__root const unsigned char secuid[10] = 
{0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U};
/* ===========================================================================
** IDCODE segment definitions
** ===========================================================================
*/


/* ===========================================================================
** include
** ===========================================================================
*/


#include "ior5f109be.h"
#include "ior5f109be_ext.h"
#include <intrinsics.h>
#include "G5_projectDefs.h"
#define _main_c_               //Define for Single include of Global Header G5_Appli_main.h
#include "G5_Appli_main.h"
#include "G5_Appli_timer.h"
#include "G5_io.h"
#include "G5_rainsens.h"
#include "G5_IRlight.h"
#include "G5_DippedBeam_sr.h"
#include "G5_E2ProjectConfig.h"
#include "G5_diagnose.h"
#include "G5_Appli_lowinit.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_flashe2.h"
#include "G5_Check_sr.h"
#include "G5_lininclude.h"
#include "G5_spi_sr.h"
#include "G5_i2cdebug.h"
#include "G5_E2Handler.h"
#include "G5_ictest.h"

//****************************************************************************/
//              Module Global Contants and Makros
/****************************************************************************/
/* States of Main state machine */
#define cb_INITIALIZATION_mg   1 
#define cb_LOAD_VARIABLES_mg   2
#define cb_ERROR_HANDLER_mg    4
#define cb_NORMAL_mg           8
#define cb_STAND_BY_MODE_mg    16
#define cb_DIAGNOSTIC_mg       32
#define cb_SLEEP_MODE_mg       64
#define cb_WRITE_TO_EEPROM_mg  128
/* Internal Reset source 10010110 = TRAP,0,0,WDTRF,0,RPERF,IAWRF,LVIRF 
    Trap,internalwatchdog,RAM parity,and Illeagle meomory access are used. Low volatage not used */
#define cb_INTERNAL_RESET_SOURCE_MASK_mg   0x96
/* PRQA S 3408,1019 3 */ /* << has external linkage >> */  
unsigned char __far const cb_FingerPrintStart_g @ 0x2000U = 0xAA; 
unsigned char __far const cb_FingerPrintEnd_g @ 0xFEEFU = 0xBB; 

#ifdef ___PHYSICAL_STACK_CALC__
/*VDR_532: RAM Consumption in map file calculated with 569byte, ATA6617 can only have 512byte*/
#pragma segment="CSTACK"
byte *segment_start_address,*segment_end_address,*segment_start_address_margin2;
word segment_start_address_margin;
byte counter_address;
//static byte boot_RAM_init_done;
unsigned char message_checker;
#endif

/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/
// function prototypes
// -------------------
static  byte rb_MainState_mg;

static void main_Loop(void);
static void main_Watchdog_check(void);
/* PRQA S 198,199,1019,289 3 */ /* << 198,199,1019,289 needed for Boatloader  >> */
void main(void);

static void main_LVI_detection(void);
static void Get_ResetSource(void);

#ifdef ___PHYSICAL_STACK_CALC__
void runtime_stack_calc(void);


static void init_stack_calc(void)
{
  /***************************************/
  /*write fixed values in STACK */
  /*Anfangsadresse des CSTACK*/
  segment_start_address=__segment_begin("CSTACK");
  /* Stack + "Sicherheitsbereich"*/
  /*Endadresse des CSTACK*/
  segment_end_address=__segment_end("CSTACK");
  segment_start_address_margin2 = segment_start_address + 0x0000;
  segment_start_address_margin=(word)segment_start_address_margin2;
  
  while (segment_start_address_margin < 0xFBD0)
  {
    *segment_start_address_margin2=0xCC;
    segment_start_address_margin2++;
    segment_start_address_margin++;
  }
  //  boot_RAM_init_done=1;
  /***************************************/
  
}

#endif

static void Get_ResetSource(void)
{
  byte rb_ResetSource_l; /*local variable declaration */
  rb_ResetSource_l = RESF;      /* copy reset source */
  if( (rb_ResetSource_l & cb_INTERNAL_RESET_SOURCE_MASK_mg) != 0) /* VDR_871 */
  {
    rbi_InternalResetOccured_g = TRUE;  /* Set Bit to Light switch ON */
    rbi_ResetSourceWasInternal_g = TRUE;  /* Set Bit to Increase incident counter in EEPROM */
    
    rbi_WriteResetSource_g = TRUE;
    rb_ResetSource_g = rb_ResetSource_l;
    
    rab_InternalResetIndicator[0]=0xAA;
    rab_InternalResetIndicator[1]=0xBB;
    rab_InternalResetIndicator[2]=0xCC;
    rab_InternalResetIndicator[3]=0xDD;
  }
  else
  {
    if((rab_InternalResetIndicator[0]== 0xAA)&&(rab_InternalResetIndicator[1]== 0xBB)&&
       (rab_InternalResetIndicator[2]== 0xCC)&&(rab_InternalResetIndicator[3]== 0xDD))
    {
      rbi_InternalResetOccured_g = TRUE;  /* Set Bit to Light switch ON */
      rbi_ResetSourceWasInternal_g = TRUE;  /* Set Bit to Increase incident counter in EEPROM */
      rbi_WriteResetSource_g = TRUE; 
    }
    
  }
}

/* ===========================================================================
** main function
** ===========================================================================
*/

/* PRQA S 198,199 3 */ /* << 198,199 needed for Boatloader  >> */


void main(void) 

{
  
  
#ifdef ___PHYSICAL_STACK_CALC__
  init_stack_calc();
#warning Stack Measurement has been turned on!
#endif
  
  RPERDIS = 1;/* disable RAM parity error */
  
  rb_MainState_mg = cb_INITIALIZATION_mg;
  
  /*RLS_VCO_62 check last cell of Bootcluster 1 to be sure that all is programmed */
  /*check on known ROM boarders if Bootloadmode is active*/
  /* The finger prints are also checked in bootloader. If there is valid print then only program counter
  comes to Application. This additional check is for the compiler not to optimise and remove the fingerprints if they
  are not used anyware in the code  */
  
  if((cb_FingerPrintStart_g == 0xAA)&& (cb_FingerPrintEnd_g == 0xBB))
  {    
    main_Loop(); 
  }
  else
  {
    Enter_BootLoad_Mode();
  }
  
}


static void main_Loop(void) 
{
  
  rb_WDGFastTaskCounterMin_g = 255;  //intialise Variable
  rb_WDGFastTaskCounterMax_g = 0;  //intialise Variable
  uF_modi_lightsens_inv_g.AllBit = 0xff; // initialise Variable
  
  
  Get_ResetSource();
  ICTEST_init();       /* Evaluate IC-Test condition */
  
  if (rb_ICTest_state_g != CB_NO_ICTEST_S) /* Is IC-Test active? */
  {
    R_TAU0_Channel0_Start();  /*(initialise 500us base clock)*/
    __enable_interrupt();            /* enable interrupt */
    EEProm_PreInitDefault(); /* load EEPROM for ICT*/
    EEProm_LoadInit();     /* (intialise EEPROM parameters) */
    while(rb_ICTest_state_g != CB_NO_ICTEST_S)   /* wait till IC-TEst is complete */
    {                                            
      if (rbi_EEPROMLoad_g == TRUE)      /* Load EEPROM finished ? */
      {
        EEProm_Load();       /* Read next cell */
      }
    }
  }
  ClearValidateString();
  Peripheral_Init();
  EEProm_PreInitDefault();  //load default Parameters in RAM
  EEProm_LoadInit();     //EEProm_LoadInit(); (intialise EEPROM parameters)
  RamGuard_init();
  set_ASIC_ALSxADval_Init();
  do  //- Main-Loop
  {
    
    if (rb_SevenToZeroCounter_g == 0)    /* Watchdog cycle time complete? */
    {
      
      main_Watchdog_check();                   /*  call SW-Watchdog handler */
      rb_SevenToZeroCounter_g = (cb_WDGCALLCOUNTERCYCLE_mg-1); /* load cycle timer */
      CheckRAM();
      if(CASE_ASIC_CNT_MD_STANDBY != rb_ASIC_ControlMode_g)
      {
        R_TAU0_Channel5_Start(); /* start frequency measurement if not in standby mode */
      }
     
      if(rbi_CRC_ChangedByDiagnostic_g == FALSE) /* don't check CRC calib if there is write request from diagnostic */
      {
        if (rbi_EEPROMLoad_g == FALSE)
        {
          check_crc16_calib();
        }
      }
      
    }
    else
    {
      SETLOW_EXTERNAL_WATCHDOG();   /* set Watchdog port to FALSE */ /* VDR_801*/
      rb_SevenToZeroCounter_g--;        /* decrease cycle counter */
    }
    
    
    switch (rb_MainState_mg)                //switch rb_MainState_mg (schedule different modes)
    {
    case cb_INITIALIZATION_mg:          //case cb_INITIALIZATION_mg
      
      IO_Ports_init();
      R_TAU0_Channel0_Start();  /*(initialise 500us base clock)*/
      R_UARTF0_Start();
      spi_init();                       //spi_init(); (initialise SPI)
      R_ADC_Start();
      I2CDbg_Init();      // init I2C-Debug interface
      __enable_interrupt(); //enable interrupts
      HumTemp_Init();           //HumTemp_Init(); (initialise SHT module)
      ApplLinInit(0x00);               //ApplLinInit(0x00);  (initialise LIN)
      
      rbi_LS_reinit_init_g = 1;
      GetLeWWS();             //GetLeWWS(); (Copy LIN input message)
      light_init();           //light_init(); (initialise light sensor)
      rbi_WatchdogCheckEnabel_g = FALSE;    //Initialise watchdog counters
      rb_ReadActiveErrors_g = FALSE; /*read the active errors from EEPROM*/
      rb_MainState_mg = cb_NORMAL_mg;       //set rb_MainState_mg to normal mode
      break;
      
    case cb_NORMAL_mg:         //case cb_NORMAL_mg
      light_evaluation();                 //light_evaluation(); (light sensor algorithm)
#ifndef _NO_RAIN_
      Rainsensor_evaluation();            //Rainsensor_evaluation();(rain sensor algorithm)
#endif /*_NO_RAIN_*/
      
      /*VDR_345 deactivation of HT-function*/
      if ((rbi_HumTemp_Module_enabled_g == TRUE) && (rbi_EEPROMLoad_g == FALSE)) /*EEPROM read complete?*/
      {
        HumTemp_Handler();  /*HumTemp_Handler(); (handler and algorithm for hunidity and temperature))*/
      }
      else /*VDR_345 deactivation of HT-function*/
      {
        HumTemp_Init();    /* do not use HumTempFunction, but set init values */
      }
      if(CASE_ASIC_CNT_MD_STANDBY==rb_ASIC_ControlMode_g)
      {
        rb_MainState_mg = cb_STAND_BY_MODE_mg;
      }
      
      break;
    case cb_STAND_BY_MODE_mg:                   //case standby mode
      if(CASE_ASIC_CNT_MD_STANDBY!=rb_ASIC_ControlMode_g)
      {
        rb_MainState_mg = cb_NORMAL_mg;
        if(rb_SevenToZeroCounter_g == (cb_WDGCALLCOUNTERCYCLE_mg - 1))
        {
          rb_WDG_LightsensorTaskCounter_g ++;
          rb_WDG_RainsensorTaskCounter_g ++;
        }
      }
      
      break;
    default:                               //default   ->ERROR !!!?->Reset
      while(TRUE == TRUE){}                      //ERROR !!!?->Reset
      break;
    }
    IO_RefreshPorts();                             //Refresh ports
#ifdef NODECONFIGURATION
    if (rbi_ReInitTable_g == 1)          //request for LIN-Initialisation
    {
      ApplTableInit();                  //LIN init look-up table with new ID
      rbi_ReInitTable_g = 0;
    }
#endif
    GetLeWWS();
    GetLsWWS();
    CopyRLSData();                         //copy LIN input and output datas
    sci_Communication();
    main_LVI_detection();                       //recover from detected low Voltage 
    ASIC_Control_init_Caller(); 
    RamGuardTest();
    if((CASE_ASIC_CNT_MD_STANDBY!=rb_ASIC_ControlMode_g)&&(cb_STAND_BY_MODE_mg==rb_MainState_mg))
    {
      rb_MainState_mg = cb_NORMAL_mg;
    }
    
    //   No LIN Communication? && Request for Clear new cluster?
    if((rbi_ClearNewCluster_mg)  && (CASE_ASIC_CNT_MD_STANDBY!=rb_ASIC_ControlMode_g))
    {
      EEProm_ClearCluster();             // Clear Cluster
    }
    while( rbi_Timer10ms_OK_g == FALSE)              //10ms complete?
    {
      if(rb_EEPROM_EraseOngoing_g == TRUE)/* VDR_797 */
      {
        EEProm_ClearCluster();             // Clear Cluster 
      }
      main_EEPROM_Loader();           //call EEPROM loader
      if (rbi_EEPROMLoad_g == FALSE)  //first load EEPROM!
      {
        if (bi_FIRST_RAM_CHECK_DONE_g == FALSE)  // is first RAM check not done
        {
          
          CheckRAM();                             //CheckRAM();  (check some RAM cells)
        }
        else if(bi_First_CALIB_CHECK_Done_g == FALSE)
        {
          check_crc16_calib();
        }
        else
        {
          check_crc16();              //check_crc16(); (check ROM)
        }
      }
    } // Wait for 10ms bit
    
    rbi_Timer10ms_OK_g = FALSE;     // Clear 10ms bit
    
    
    
  } while(TRUE == TRUE);                  // Main-Loop..
  
} // end of main ..





/**************************************************************************
Syntax   : void  main_Watchdog_check(void)
Object   : main_Watchdog_check(void)
Parameters : none (use of module global variables)
Return  : none
Calls   : in main.c after 6 times the 10ms cycle
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Checks if all routines was called
correct before Watchdog is refresh
**************************************************************************/
static void main_Watchdog_check(void)
{
  if (rbi_WatchdogCheckEnabel_g == TRUE)
  {
    if (rb_WDG_500usTaskCounter_g > rb_WDGFastTaskCounterMax_g)   // check for max CPU load
    {
      rb_WDGFastTaskCounterMax_g = rb_WDG_500usTaskCounter_g;   // store max CPU load
    }
    if (rb_WDG_500usTaskCounter_g < rb_WDGFastTaskCounterMin_g)   // check for min CPU load
    {
      rb_WDGFastTaskCounterMin_g = rb_WDG_500usTaskCounter_g;   // store min CPU load
    }
  }
  
  
  if ((rb_WDG_IORefreshTaskCounter_g == cb_WDGCALLCOUNTERCYCLE_mg)    /*Input and Output Ports Refreshed 6 Times?*/
      && (rb_WDG_BusTaskCounter_g == cb_WDGCALLCOUNTERCYCLE_mg)       /*Bus Task called 6 Times?*/
        &&(rb_WDG_SCITaskCounter_g == cb_WDGCALLCOUNTERCYCLE_mg)      /* SCI- counter */
          &&(rb_WDG_LVITaskCounter_g == cb_WDGCALLCOUNTERCYCLE_mg)      /* SCI- counter */
            ||(rbi_WatchdogCheckEnabel_g == FALSE)) //Are Checks Enabled (initialisation)?
  {
    if (((rb_WDG_500usTaskCounter_g>=cb_FASTTASKCALLS_MIN_mg)                 //with 1ms buffer
         && (rb_WDG_500usTaskCounter_g <cb_FASTTASKCALLS_MAX_mg))          //1ms Task called correct and enabled?
        ||(rbi_WatchdogCheckEnabel_g == FALSE)) //Are Checks Enabled (initialisation)?
    {
      rb_WDG_500usTaskCounter_g = 0;                //Reset Counter for 1ms Task
      
      REFRESH_INTERNAL_WATCHDOG();
      REFRESH_EXTERNAL_WATCHDOG();
      
      rb_WDG_LVITaskCounter_g = 0;                //Reset the Counter for LVD
      rb_WDG_SCITaskCounter_g = 0;                //Reset the Counter for SCI
      rb_WDG_IORefreshTaskCounter_g =0;           //Reset the Counter for Refresh Ports
      rb_WDG_BusTaskCounter_g = 0;                //Reset the counter for the Bus Tasks
      rb_WDG_RainsensorTaskCounter_g = 0;         //Reset The Counter for the Rainsensor Task
      rb_WDG_LightsensorTaskCounter_g = 0;        //Reset the Counter for the Lightsensor Task
      rbi_WatchdogCheckEnabel_g = TRUE;           //Enable the Check of the Counters
    }
    else
    {
      
      if (rb_WDGIncidentCounter_g < 0x0F) /*VCO_34 write errorcode for SW-Watchdog*/
      {
        INREASE_WDG_INCIDENT();
        /* PRQA S 3200 1 */ /* << 3200 return Value not used >> */ 
        EEProm_WriteCodedByte(((rb_WDGIncidentCounter_g<<4)|rb_VoltSupplyIncidentCounter_g),CW_EEPROM_INCIDENT3_ADDRESS);
      }
      
      if ((rb_E2_Sensor_Error1_g & 0x80)==0)   // is trouble code for not enough resources new ?
      {
        /* store trouble code for not enough resources in EEPROM*/
        /* PRQA S 3200 1 */ /* << 3200 return Value not used >> */ 
        EEProm_WriteCodedByte((rb_E2_Sensor_Error1_g|0x80),CW_E2_SENSOR_ERROR1_ADRESS); 
      }
      SOFTWARE_RESET();                           //Software Reset of the Microcontroller
    }
  }
  else
  {
    
    if (rb_CntProSeqIncidentCounter_g < 0x0F) /*VCO_34 write errorcode for u to slow*/
    {
      INREASE_CNTPROSEQ_INCIDENT();
      /* PRQA S 3200 1 */ /* << 3200 return Value not used >> */ 
      EEProm_WriteCodedByte(((rb_CntMemoryIncidentCounter_g<<4)|rb_CntProSeqIncidentCounter_g),CW_EEPROM_INCIDENT2_ADDRESS);
    }
    
    if ((rb_E2_Sensor_Error1_g & 0x80)==0) // is trouble code for not enough resources new ?
    {
      /* store trouble code for not enough resources in EEPROM*/
      /* PRQA S 3200 1 */ /* << 3200 return Value not used >> */ 
      EEProm_WriteCodedByte((rb_E2_Sensor_Error1_g|0x80),CW_E2_SENSOR_ERROR1_ADRESS); 
    }
    SOFTWARE_RESET();                                  //Software Reset of the Microcontroller
  }
}




/**************************************************************************
Syntax   : void  main_LVI_detection(void)
Object   : main_LVI_detection()
Parameters : none
Return  : none
Calls   : in main.c   every 10ms
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : checks for Low Voltage condition and increments failure counter
**************************************************************************/

static void main_LVI_detection(void)
{
  /* PRQA S 0434,0436 20 */ /* << 0434,0436 usage of SFR >> */   
  /* PRQA S 3358,3355 20 */ /* <<  3358,3355 usage of SFR written from HW >> */          
  if ((get_rb_VDD_LightSignalErrorCnt_g() == 0))  //no Low Voltage ?
  {
    if (rb_AfterVddPowerFailDelay_g > 0)   // after low Voltge Delay > 0 ?
    {
      rb_AfterVddPowerFailDelay_g --;   // decrement Delay
    }
  }
  else
  {
    rb_AfterVddPowerFailDelay_g = cb_TIME_TO_WAIT_LONG_FOR_VDD_g; // Set after low Voltge Delay
  }
  
  rb_WDG_LVITaskCounter_g++;
}


#ifdef ___PHYSICAL_STACK_CALC__

void runtime_stack_calc(void)
{
  /***************************************/
  /*VDR_532: RAM Consumption in map file calculated with 473byte*/
  /*Anfangsadresse des CSTACK*/
  segment_start_address=__segment_begin("CSTACK");
  /*Endadresse des CSTACK*/
  segment_end_address=__segment_end("CSTACK");
  segment_start_address_margin2 += 0x0006;
  /*@TODO: Copy RAM-Address in normal variable, otherwise a Compiler error is produced*/
  segment_start_address_margin=(word)segment_start_address_margin2;
  
  if (segment_start_address_margin>0xFBF0)
  {
    segment_start_address_margin = 0xFB00;
    segment_start_address_margin2 = (byte *)0xFB00;
  }
  segment_start_address_margin = (word) segment_start_address_margin2;
}
#warning Stack Measurement has been turned on!
#endif


/* ===========================================================================
** end of file
** ===========================================================================
*/
