/*************************************************************************

Company : Valeo Schalter und Sensoren

Project : RLT Sensor Generation 5 (16 bit microController)

Component : ASIC_Control.c
*************************************************************************/

/*! \file G5_ASIC_CONTROL.c
 * Code should be included if it is non-safety relevant only.
 * This module organises the interface to the ASIC
 * the following functions are included:
 *  -Rain functionality
 *  -Configuration of rain interface, integrator and regulator
 *  -Standby measurements
 * Documentation reference : ASIC_Specification
 */ 


/* History                                                                                     */
/*---------------------------------------------------------------------------------------------*/
/* Date      VDR_Number  Name    Description                                                   */
/*---------------------------------------------------------------------------------------------*/
/*07.11.13    VCO_090     MPI       Split of non-safety from saftey relevant functionalities      */
/*14.11.14    VCO_195     MPI       QAC correction and checkin of Hex and map files for X007 release */
/*27.11.14    VDR_825     MPI       Diagnostic pulse - change the wait time*/
/*23.01.15    VDR_836     MPI       Pulse counter not always incremented*/
/*16.03.15    VDR_855     MPI       Fix of the findings from the review of ASIC_Control_sr*/

/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/* PRQA S 1006 EOF *//*<< NOPs used  >>*/
/* PRQA S 5540,5560,5565,5900 EOF *//*<< Data needs to be verified  >>*/
/* PRQA S 3138 EOF */ /* << using of macros from automatic generated code >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/


#include "ior5f109be.h"    /*common header file*/
#include "G5_projectDefs.h"

#define _G5_ASIC_Control_c_             /*Define for Single include*/
#include "G5_ASIC_Control.h"         /*module specific header file for common include*/
/* PRQA S 0841 1 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef _G5_ASIC_Control_c_

#include "G5_flashe2.h"
#include "G5_spi_sr.h"
#include "G5_io.h"
#include "G5_E2ProjectConfig.h"
#include "G5_diagnose.h"
#include "G5_rainsens.h"
#include "G5_ASIC_Control_sr.h"      /*module specific header file for common include*/



/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/

word rw_INTV10bit_min_g = 0x3FF;
word rw_INTV10bit_max_g = 0;
word rw_REGV_min_g = 0x0FFF;
word rw_REGV_max_g = 0;

/* Rain intensity Signal voltage: VCO_423 */ 
#ifdef RAIN_INTENSITY
byte rb_RS_SigVoltage_neg_g;
byte rb_RS_SigVoltage_abs_g;
#endif

/*! 3 microSec cycles to integrate Modulator in standby mode*/
const byte cab_STANDBY_INTEGRATION_TIME[4] = {150,135,120,110};/*VCO_028 reduce sample time if not stable*/

/*************************************************************************
**                   Declaration of local module functions              **
**************************************************************************/
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
#if 0
static void ASIC_Control_StandbyDecision(void);
#endif
static void ASIC_Control_ASICstepResponse(void);
#endif /*_NO_RAIN_*/

/*!
* \fn    void ASIC_Control_RS_Meas(void)
* \brief  Reads INTV, REGV. Called from main.c 
* \param  void 
* \return void 
*/
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
void ASIC_Control_RS_Meas(void)
{
  static byte rb_wait_2_settle_l=0;
  if(rbi_UnderVoltage_g == FALSE)
  {
    if((rb_CurMode_g == CB_ASIC_LOPEN_MD) || (rb_CurMode_g == CB_ASIC_LOOP1_MD) || (rb_CurMode_g == CB_ASIC_LOOP2_MD))
    {
      if(rb_wait_2_settle_l < 15)
      {
        rb_wait_2_settle_l++;
      }

      if (rbi_SPI_activ_g == FALSE)
      {
        rb_RainMeas_cnt_g ++;
        rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_INTVH_REG].addr<<1)|0x81); /*0x81 - Read2 Mask for writing the registers*/
        rab_SPI_ASICWriteBuffer_mg[1] = 0x2A;
        rab_SPI_ASICWriteBuffer_mg[2] = 0x2A;
        rab_SPI_ASICWriteBuffer_mg[3] = 0x2A;
        rb_SPI_Data_to_send_g = 4;
        if(CB_ASIC_LOPEN_MD != rb_CurMode_g)
        {
          /*0x81 - Read2 Mask for writing the registers*/
          rab_SPI_ASICWriteBuffer_mg[3] = (byte)((ras_ASIC_CtrReg_g[IDX_REGVH_REG].addr<<1)|0x81);
          rab_SPI_ASICWriteBuffer_mg[4] = 0x2A;
          rab_SPI_ASICWriteBuffer_mg[5] = 0x2A;
          rab_SPI_ASICWriteBuffer_mg[6] = 0x2A;/*NOP byte sent to ASIC during which the last checksum is received*/
          rb_SPI_Data_to_send_g = 7;
        }
        
        SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
        rb_SPI_Data_to_send_g = 0;
      }
    }
    else
    {
      rb_wait_2_settle_l=0;
    }
  }
  else
  {
    rbi_Modulator_On_g = FALSE;
    ASIC_Control_ChangeModeCmd(CB_ASIC_LSTOP_MD);
  }
}
#endif /*_NO_RAIN_*/


/*!
* \fn   void ASIC_Control_MeasureStandbyMode(void)
* \brief  -> organices the standby Mode
* -> calls standby decision
* -> enables wake up source and switches the microController in stop mode
* -> reinitialises the Watchdog and the voltage regulator
* -> checks for LIN activity
* \param  void
* \return void 
*/

#ifndef _NO_RAIN_
#if defined BYD_HC
void ASIC_Control_MeasureStandbyMode(void)
{
  word rb_StbWait4Integr_l=5000;
  /** \brief Counter to increment the time-timout of the standby mode*/
  word rw_StandbyCorrectLoopCounter_l;
  /** \brief Counter for incorrect trys to find a stable point*/
  word rw_StbyIncorrectLoopTimoutCnt_l;
  /** \brief Array with timout of standby mode (minutes)*/
  const word raw_StandbyTimoutBoarders[8] ={0xffffU,240,2*240,3*240,4*240,5*240,6*240,7*240};
  

  /*20190709_Add_variables_HU*/
  static byte add_Counter = 0,Rain_Drop_Counter = 0,Three_Second_Time_Counter = 0,Time_Counter = 0;
  static word rw_REGV_Voltage_old_g = 0;
  static word rw_REGV_Voltage_Delta_l = 0;
  static word rw_REGV_Voltage_Average_l = 0;
  static word rw_REGV_Voltage_One_l = 0;
  static word rw_REGV_Voltage_Two_l = 0;
  static word rw_REGV_Voltage_Three_l = 0;
  
  if(CB_ASIC_SLEEP_MD == rb_CurMode_g)
  {
	STANDBY_WAIT_FOR_FREE_SPI();
	ASIC_Control_ChangeModeCmd(CB_ASIC_WAKEUP_MD);
	rb_firstReadComm_g = TRUE;
  }

  
  STANDBY_WAIT_FOR_FREE_SPI();
  ASIC_Control_ChangeModeCmd(CB_ASIC_INIT_MD);
  STANDBY_WAIT_FOR_FREE_SPI();
  
  
#if 0
  rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_REGVH_REG].addr<<1)|0x41);
  rab_SPI_ASICWriteBuffer_mg[1] = ras_ASIC_CtrReg_g[IDX_REGVH_REG].val;
  rab_SPI_ASICWriteBuffer_mg[2] = ras_ASIC_CtrReg_g[IDX_REGVL_REG].val;
  rab_SPI_ASICWriteBuffer_mg[3] = (byte)((ras_ASIC_CtrReg_g[IDX_INTVH_REG].addr<<1)|0x41);
  rab_SPI_ASICWriteBuffer_mg[4] = 0x80;
  rab_SPI_ASICWriteBuffer_mg[5] = 0;
  rb_SPI_Data_to_send_g = 6;
  SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
  rb_SPI_Data_to_send_g = 0;
#endif
  
  
  STANDBY_WAIT_FOR_FREE_SPI();
  ASIC_Control_ChangeModeCmd(CB_ASIC_LOOP1_MD);
  STANDBY_WAIT_FOR_FREE_SPI();
  
  //rbi_StandbyModulatorIntegrating_g = FALSE;	  /*clear status flag used in SPI.c*/
  //rb_NextSPI_Request_g = CB_STMEAS_RQ;


  ASIC_Control_AsicStatus();
  STANDBY_WAIT_FOR_FREE_SPI();
  

  /*20190709_Set_Flag_HU*/
  rb_newRSconvRcv_g = FALSE;
  rw_StandbyCorrectLoopCounter_l = 0;
  rw_StbyIncorrectLoopTimoutCnt_l = 0;
  /* try to start with maximum measurement time*/
  //rab_IntegrationTimePointer_mg = (ras_ASIC_CtrReg_g[IDX_ACTR_REG].val&0x0F);
  

  /*20190709_Change_Flag_HU*/
  if (rw_REGV_Voltage_old_g > 0)  //loop initialised?
  {
	rw_StbyIncorrectLoopTimoutCnt_l = 0; //clear timoutcounter for stable point
	rb_StandbyTimeOutSecCnt_g += UCONTROLLER_STANDBY_SLEEP_TIME;			 // increment Timout to close windows !
	
	if (rb_StandbyTimeOutSecCnt_g > 118) /*timer is incremented every 1/2 sec.*/
	{
	  rb_StandbyTimeOutSecCnt_g -= 118; 
	  rw_StandbyTimeOutCnt_g ++;		/*increased every minute*/
	}
	
	if (rw_StandbyTimeOutCnt_g > raw_StandbyTimoutBoarders[rb_StandbyTimout_g])//raw_StandbyTimoutBoarders[rb_StandbyTimout_g]) /*timeout reached*/
	{
	  rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;  /*close windows*/
	  rb_CloseTypeStandby_g = 1;
	}
  }
  else	  /* do same to reset Wdg without window function!*/
  {
	rw_TimeOutCounter_s = CW_WAIT_FOR_STANDBY;
	
	if (rw_StandbyCorrectLoopCounter_l < 434)
	{
	  rw_StandbyCorrectLoopCounter_l ++;
	}
	else
	{
	  rb_StandbyTimeOutSecCnt_g++;
	  rw_StandbyCorrectLoopCounter_l = 0;
	}
	
	if (rw_StbyIncorrectLoopTimoutCnt_l < 900) /* is it possible to find a stable point*/
	{
	  rw_StbyIncorrectLoopTimoutCnt_l ++;
	}
	else
	{
	  rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;  /*close windows*/
	  rb_CloseTypeStandby_g = 3;
	}
  }
  
  
  if (rbi_LIN_CommunicationEvent_g == FALSE)/* no LIN-Communication?*/
  {
	
#if 0
	/* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability	>>*/
	STANDBY_WAIT_FOR_FREE_SPI();				 /* wait till spi is free*/
	rw_TimeOutCounter_s = CW_WAIT_FOR_SPI_TIMOUT;				 /*set secure timeout*/
	while (((rbi_StandbyModulatorIntegrating_g == FALSE) && (rw_TimeOutCounter_s > 0))
		   || (rw_TimeOutCounter_s > 20)) /*wait till stb Mode is active*/
	{
	  rw_TimeOutCounter_s--;  /* decrease timeout*/
	  if (rw_TimeOutCounter_s == 1)  /*timout nearly complete?*/
	  {
		rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD; /*close windows*/
		rb_CloseTypeStandby_g = 4;
	  }
	}
#endif


	STANDBY_WAIT_FOR_FREE_SPI(); 
	/*initialise Wake up timer to about 400micros*/
	//rw_TimeOutCounter_s = cab_STANDBY_INTEGRATION_TIME[rab_IntegrationTimePointer_mg];
	while((--rb_StbWait4Integr_l)>0)
	{
	  NOP();NOP();NOP();NOP();NOP();
	}

	/* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability	>>*/  
	STANDBY_WAIT_FOR_FREE_SPI();				 /* wait till spi is free*/
	do
	{
	  ASIC_Control_RS_Meas();
	  /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
	  STANDBY_WAIT_FOR_FREE_SPI();				   /* wait till spi is free*/
	  /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
	  STANDBY_WAIT_FOR_FREE_SPI();				   /* wait till spi is free*/
	}while(rb_newRSconvRcv_g == FALSE);
	/* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability	>>*/
	STANDBY_WAIT_FOR_FREE_SPI();				 /* wait till spi is free*/
	
	
	  /*20190709_Calulate_delta_HU*/	
	  if (add_Counter == 0)
	  {
		  rw_REGV_Voltage_One_l = rw_REGV_Voltage_g;
		  add_Counter++;
	  }
	  else if(add_Counter == 1)
	  {
		  rw_REGV_Voltage_Two_l = rw_REGV_Voltage_g;
		  add_Counter++;
	  }
	  else
	  {
		rw_REGV_Voltage_Three_l = rw_REGV_Voltage_g;
		add_Counter = 0;
	  }
		  
		  
	  if(add_Counter == 2)
	  {
		rw_REGV_Voltage_Average_l = (rw_REGV_Voltage_One_l + rw_REGV_Voltage_Three_l) / 2;
	  }
	  else if(add_Counter == 1)
	  {
		rw_REGV_Voltage_Average_l = (rw_REGV_Voltage_Three_l + rw_REGV_Voltage_Two_l) / 2;
	  }
	  else if(add_Counter == 0)
	  {
		rw_REGV_Voltage_Average_l = (rw_REGV_Voltage_One_l + rw_REGV_Voltage_Two_l) / 2;
	  }


	if(rw_REGV_Voltage_g > rw_REGV_Voltage_Average_l)
	{
		rw_REGV_Voltage_Delta_l = rw_REGV_Voltage_g - rw_REGV_Voltage_Average_l;
	}
	else
	{
		rw_REGV_Voltage_Delta_l = rw_REGV_Voltage_Average_l - rw_REGV_Voltage_g;
	}

	

	if(Time_Counter < 3)
	{
	  Time_Counter++;
	}
	else
	{
		if (rw_REGV_Voltage_Delta_l >= Standby_threshold_g)
		{
			Rain_Drop_Counter++;
		}		
		if (Rain_Drop_Counter == 2)
		{
			rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_PRE_STANDBY;
			Time_Counter = 0;
			Rain_Drop_Counter = 0;
			Three_Second_Time_Counter = 0;
                        Enter_Prestandby_Flag = 1;
		}
		Three_Second_Time_Counter++;
		if (Three_Second_Time_Counter == 3)
		{
			Rain_Drop_Counter = 0;
			Three_Second_Time_Counter = 0;
		}
	}
	rw_REGV_Voltage_old_g = rw_REGV_Voltage_g; 
	STANDBY_WAIT_FOR_FREE_SPI(); 
  }
  else
  {
    rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;       /*set case CASE_ASIC_CNT_MD_RESET*/
    rb_CloseTypeStandby_g |= 0x80; /*VCO_028 debug information*/
  }
}
#else
void ASIC_Control_MeasureStandbyMode(void)
{
  word rb_StbWait4Integr_l=5000;
  /** \brief Counter to increment the time-timout of the standby mode*/
  word rw_StandbyCorrectLoopCounter_l;
  /** \brief Counter for incorrect trys to find a stable point*/
  word rw_StbyIncorrectLoopTimoutCnt_l;
  /** \brief Array with timout of standby mode (minutes)*/
  const word raw_StandbyTimoutBoarders[8] ={0xffffU,240,2*240,3*240,4*240,5*240,6*240,7*240};
  
  if(CB_ASIC_SLEEP_MD == rb_CurMode_g)
  {
    /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
    STANDBY_WAIT_FOR_FREE_SPI();                 /* wait till spi is free*/
    ASIC_Control_ChangeModeCmd(CB_ASIC_WAKEUP_MD);
    rb_firstReadComm_g = TRUE;
  }
  
  /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
  STANDBY_WAIT_FOR_FREE_SPI();                 /* wait till spi is free*/
  ASIC_Control_ChangeModeCmd(CB_ASIC_INIT_MD);
  /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
  STANDBY_WAIT_FOR_FREE_SPI();                 /* wait till spi is free*/
  
  rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_REGVH_REG].addr<<1)|0x41);
  rab_SPI_ASICWriteBuffer_mg[1] = ras_ASIC_CtrReg_g[IDX_REGVH_REG].val;
  rab_SPI_ASICWriteBuffer_mg[2] = ras_ASIC_CtrReg_g[IDX_REGVL_REG].val;
  rab_SPI_ASICWriteBuffer_mg[3] = (byte)((ras_ASIC_CtrReg_g[IDX_INTVH_REG].addr<<1)|0x41);
  rab_SPI_ASICWriteBuffer_mg[4] = 0x80;
  rab_SPI_ASICWriteBuffer_mg[5] = 0;
  rb_SPI_Data_to_send_g = 6;
  SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
  rb_SPI_Data_to_send_g = 0;
  
  /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
  STANDBY_WAIT_FOR_FREE_SPI();                 /* wait till spi is free*/
  ASIC_Control_ChangeModeCmd(CB_ASIC_LOPEN_MD);
  /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
  STANDBY_WAIT_FOR_FREE_SPI();                 /* wait till spi is free*/
  
  rbi_StandbyModulatorIntegrating_g = FALSE;    /*clear status flag used in SPI.c*/
  
  rb_NextSPI_Request_g = CB_STMEAS_RQ;
  ASIC_Control_AsicStatus();
  /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
  STANDBY_WAIT_FOR_FREE_SPI();                 /* wait till spi is free*/
  
  rb_LOpenIntegrationDone_g = FALSE;
  rw_StandbyCorrectLoopCounter_l = 0;
  rw_StbyIncorrectLoopTimoutCnt_l = 0;
  /* try to start with maximum measurement time*/
  rab_IntegrationTimePointer_mg = (ras_ASIC_CtrReg_g[IDX_ACTR_REG].val&0x0F);
  
  if (rb_STB_LoopIn_ASIC_old_g > 0)  //loop initialised?
  {
    //rb_StandbyTimerDelayCounter = UCONTROLLER_STANDBY_SLEEP_TIME;  // use 4 timer H1 Cycles for Standby Delay
    rw_StbyIncorrectLoopTimoutCnt_l = 0; //clear timoutcounter for stable point
    rb_StandbyTimeOutSecCnt_g += UCONTROLLER_STANDBY_SLEEP_TIME;             // increment Timout to close windows !
    
    if (rb_StandbyTimeOutSecCnt_g > 118) /*timer is incremented every 1/2 sec.*/
    {
      rb_StandbyTimeOutSecCnt_g -= 118; 
      rw_StandbyTimeOutCnt_g ++;        /*increased every minute*/
    }
    
    if (rw_StandbyTimeOutCnt_g > raw_StandbyTimoutBoarders[rb_StandbyTimout_g]) /*timeout reached*/
    {
      rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;  /*close windows*/
      rb_CloseTypeStandby_g = 1;
    }
  }
  else    /* do same to reset Wdg without window function!*/
  {
    rw_TimeOutCounter_s = CW_WAIT_FOR_STANDBY;
    
    if (rw_StandbyCorrectLoopCounter_l < 434)
    {
      rw_StandbyCorrectLoopCounter_l ++;
    }
    else
    {
      rb_StandbyTimeOutSecCnt_g++;
      rw_StandbyCorrectLoopCounter_l = 0;
    }
    
    if (rw_StbyIncorrectLoopTimoutCnt_l < 900) /* is it possible to find a stable point*/
    {
      rw_StbyIncorrectLoopTimoutCnt_l ++;
      /* is it possible to find a stable point*/
      if ((rw_StbyIncorrectLoopTimoutCnt_l == 20)||(rw_StbyIncorrectLoopTimoutCnt_l == 40)||
          (rw_StbyIncorrectLoopTimoutCnt_l == 60)||(rw_StbyIncorrectLoopTimoutCnt_l == 80))
      {
        if (rab_IntegrationTimePointer_mg>4) /*VCO_028 reduce integration time*/
        {
          rab_IntegrationTimePointer_mg--;
        }
      }
    }
    else
    {
      rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;  /*close windows*/
      rb_CloseTypeStandby_g = 3;
    }
  }
  
  if (rbi_LIN_CommunicationEvent_g == FALSE)/* no LIN-Communication?*/
  {
    /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
    STANDBY_WAIT_FOR_FREE_SPI();                 /* wait till spi is free*/
    rw_TimeOutCounter_s = CW_WAIT_FOR_SPI_TIMOUT;                /*set secure timeout*/
    while (((rbi_StandbyModulatorIntegrating_g == FALSE) && (rw_TimeOutCounter_s > 0))
           || (rw_TimeOutCounter_s > 20)) /*wait till stb Mode is active*/
    {
      rw_TimeOutCounter_s--;  /* decrease timeout*/
      if (rw_TimeOutCounter_s == 1)  /*timout nearly complete?*/
      {
        rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD; /*close windows*/
        rb_CloseTypeStandby_g = 4;
      }
    }
    /*initialise Wake up timer to about 400micros*/
    rw_TimeOutCounter_s = cab_STANDBY_INTEGRATION_TIME[rab_IntegrationTimePointer_mg];
    while((--rb_StbWait4Integr_l)>0)
    {
      NOP();NOP();NOP();NOP();NOP();
    }

    /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/  
    STANDBY_WAIT_FOR_FREE_SPI();                 /* wait till spi is free*/
    do
    {
      ASIC_Control_RS_Meas();
      /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
      STANDBY_WAIT_FOR_FREE_SPI();                 /* wait till spi is free*/
      /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
      STANDBY_WAIT_FOR_FREE_SPI();                 /* wait till spi is free*/
    }while(rb_LOpenIntegrationDone_g==FALSE);
    /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
    STANDBY_WAIT_FOR_FREE_SPI();                 /* wait till spi is free*/
    rb_STB_LoopIn_ASIC_g = (byte)(rw_INTV10bit_g>>2);
    
    if (rb_STB_LoopIn_ASIC_g < 1)
    {
      rb_STB_LoopIn_ASIC_g = 1;
    }
    /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
    STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
    ASIC_Control_StandbyDecision(); /* evaluate Standby Function*/
    /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
    STANDBY_WAIT_FOR_FREE_SPI(); /* wait till spi is free*/
  }
  else
  {
    rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET;       /*set case CASE_ASIC_CNT_MD_RESET*/
    rb_CloseTypeStandby_g |= 0x80; /*VCO_028 debug information*/
  }
}
#endif
#endif



/*!
* \fn   void ASIC_Control_StandbyDecision(void)
* \brief  Pseudo-code : Checks the standby status Decides if wake up raincheck is
*         required or not.Checks if signal is out of boarder and adapts DAC value
* \param  void
* \return void 
*/

/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
#if defined BYD_HC
#elif defined NL_5
static void ASIC_Control_StandbyDecision(void)                          /* evaluate Standby Function*/
{
  static word rw_Detect_Rain_Three_Times_Sum_s = 0;  
  static word rw_Detect_Rain_Four_Times_Sum_s = 0;  
  static word rw_Detect_Rain_Five_Times_Sum_s = 0;  
  static byte rb_Collect_Three_Times_s = 0;
  static byte rb_Collect_Four_Times_s = 0;
  static byte rb_Collect_Five_Times_s = 0;
  byte rb_Dizzle_Flow_Rain_Detect_Flag_l;
  static byte rb_Stable_Vale_Times_s = 0;
  static byte rb_STB_LoopIn_ASIC_difference_old_s = 0;
  static byte rb_Detect_Unnormal_Stable_Times_s = 0;
  static byte rb_Valid_Rain_Times_s = 0;
  
  if(rb_STB_LoopIn_ASIC_old_g > 0)
  {
    /***********************Last Two Seconds Differ********************/
    if (rb_STB_LoopIn_ASIC_g > rb_STB_LoopIn_ASIC_old_g)  /*Loopin > loopin old*/
    {
      rb_STB_LoopIn_ASIC_difference_g = rb_STB_LoopIn_ASIC_g - rb_STB_LoopIn_ASIC_old_g;   /*calc. difference*/
    }
    else
    {
      rb_STB_LoopIn_ASIC_difference_g = rb_STB_LoopIn_ASIC_old_g-rb_STB_LoopIn_ASIC_g;     /*calc. difference*/
    }
    
    if(rb_STB_LoopIn_ASIC_difference_g <=3)
    {
      rb_Detect_Unnormal_Stable_Times_s++; 
    }
    else
    {
      rb_Detect_Unnormal_Stable_Times_s = 0;
    }
    
    rb_Collect_Three_Times_s ++;
    rb_Collect_Four_Times_s ++;
    rb_Collect_Five_Times_s ++;
      
    if(rb_Collect_Three_Times_s <=3)
    {
      rw_Detect_Rain_Three_Times_Sum_s += rb_STB_LoopIn_ASIC_difference_g;   
    }
    else
    {
      rw_Detect_Rain_Three_Times_Sum_s = 0;
      rb_Collect_Three_Times_s = 0;
    }
    
    if(rb_Collect_Four_Times_s <=4)
    {
      rw_Detect_Rain_Four_Times_Sum_s += rb_STB_LoopIn_ASIC_difference_g;   
    }
    else
    {
      rb_Collect_Four_Times_s = 0;
      rw_Detect_Rain_Four_Times_Sum_s = 0;
    }
    
    if(rb_Collect_Five_Times_s <=5)
    {
      rw_Detect_Rain_Five_Times_Sum_s += rb_STB_LoopIn_ASIC_difference_g;   
    }
    else
    {
      rb_Collect_Five_Times_s = 0;
      rw_Detect_Rain_Five_Times_Sum_s = 0;
    }   
    
    if(rb_STB_LoopIn_ASIC_difference_g == rb_STB_LoopIn_ASIC_difference_old_s)
    {
      rb_Stable_Vale_Times_s ++;
    }
    else
    {
       rb_Stable_Vale_Times_s = 0;
    }
    
    if((rw_Detect_Rain_Five_Times_Sum_s >= 105)||(rw_Detect_Rain_Four_Times_Sum_s >= 88)||(rw_Detect_Rain_Three_Times_Sum_s >= 69))
    {
      rb_Dizzle_Flow_Rain_Detect_Flag_l = 1;
    }
    else
    {
      rb_Dizzle_Flow_Rain_Detect_Flag_l = 0;
    }
     
    if((rb_STB_LoopIn_ASIC_g > 155) || (rb_STB_LoopIn_ASIC_g < 115))
    {
      rb_Valid_Rain_Times_s ++;
    }
    else
    {
      rb_Valid_Rain_Times_s = 0;
    }
        
    if((rb_STB_LoopIn_ASIC_difference_g > CB_STANDBY_THRESHOLD) || (rb_STB_LoopIn_ASIC_g > 200) || (rb_STB_LoopIn_ASIC_g < 50) || (rb_Dizzle_Flow_Rain_Detect_Flag_l == 1) || (rb_Stable_Vale_Times_s > 11) || (rb_Detect_Unnormal_Stable_Times_s > 20) || (rb_Valid_Rain_Times_s > 1))               
    {
      rb_ASIC_ControlMode_g =  CASE_ASIC_CNT_MD_RESET;        /*look for rain in normal mode*/     
      rw_Detect_Rain_Three_Times_Sum_s = 0;
      rw_Detect_Rain_Four_Times_Sum_s = 0;
      rw_Detect_Rain_Five_Times_Sum_s = 0;
      rb_Dizzle_Flow_Rain_Detect_Flag_l = 0;
      rb_Stable_Vale_Times_s = 0;
      rb_Collect_Three_Times_s = 0;
      rb_Collect_Four_Times_s =0;
      rb_Collect_Five_Times_s = 0;
      rb_STB_LoopIn_ASIC_old_g = 0;
      rb_STB_LoopIn_ASIC_g = 0;
      rb_STB_LoopIn_ASIC_difference_g = 0;
      rb_STB_LoopIn_ASIC_difference_old_s = 0;
      rb_Detect_Unnormal_Stable_Times_s = 0;
      rb_Valid_Rain_Times_s = 0;
    }
    rb_STB_LoopIn_ASIC_difference_old_s = rb_STB_LoopIn_ASIC_difference_g;
  }
    rb_STB_LoopIn_ASIC_old_g = rb_STB_LoopIn_ASIC_g;
}
#else
static void ASIC_Control_StandbyDecision(void)                          /* evaluate Standby Function*/
{
  static byte rb_firstRunafterInit_g;
  word rb_REGV_temp_l=rw_REGV_Voltage_g;  
  
  if (rb_STB_LoopIn_ASIC_old_g> 0)                 /* Is loop initialised*/
  {  
    /***********************Last Two Seconds Differ********************/
    if (rb_STB_LoopIn_ASIC_g > rb_STB_LoopIn_ASIC_old_g)  /*Loopin > loopin old*/
    {
      rb_STB_LoopIn_ASIC_difference_g = rb_STB_LoopIn_ASIC_g - rb_STB_LoopIn_ASIC_old_g;   /*calc. difference*/
    }
    else
    {
      rb_STB_LoopIn_ASIC_difference_g = rb_STB_LoopIn_ASIC_old_g-rb_STB_LoopIn_ASIC_g;     /*calc. difference*/
    }
   /*****************************End***********************************/
 
 /*******************************************Contition Setting*********************/   
    if(rb_STB_LoopIn_ASIC_difference_g > CB_STANDBY_THRESHOLD)             
    {
      rb_ASIC_ControlMode_g =  CASE_ASIC_CNT_MD_PRE_STANDBY;        /*look for rain in normal mode*/     
    }
 /****************************************End**********************************/
    
    if (rb_firstRunafterInit_g < 0xff)
    {
      rb_firstRunafterInit_g ++;
    }
  }
  if ((((rb_STB_LoopIn_ASIC_g) > (byte)(CB_INREC_ABS_UPPER_LEVEL))||((rb_STB_LoopIn_ASIC_g) < (byte)(CB_INREC_ABS_LOWER_LEVEL)))||
      ((rb_STB_LoopIn_ASIC_old_g == 0) &&(((rb_STB_LoopIn_ASIC_g) > (CB_INREC_ABS_UPPER1_LEVEL))||((rb_STB_LoopIn_ASIC_g) < (CB_INREC_ABS_LOWER1_LEVEL))))) // is Loopvoltage out of boarders
  {
    if ((rb_STB_LoopIn_ASIC_g) > CB_INREC_ABS_UPPER1_LEVEL)    /* higher upper level?*/
    {
      if (rw_REGV_Voltage_g <3968)                          /* Loopvoltage out of range*/
      {
        rb_REGV_temp_l +=32;                            /* deccrement Loopvoltage*/
      }
      else
      {
        if (rab_IntegrationTimePointer_mg>4)
        {
          rab_IntegrationTimePointer_mg--; /*VCO_028 reduce integration time*/
          rb_ASIC_ControlMode_g =  CASE_ASIC_CNT_MD_PRE_STANDBY;        /*look for rain in normal mode*/
        }
        else
        {
          rb_ASIC_ControlMode_g =  CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;  /*close windows*/
        }
        rb_CloseTypeStandby_g = 5;
      }
    }
    else                                                      /*higher?*/
    {
      if (rw_REGV_Voltage_g > 128)                        /* Loopvoltage out of range*/
      {
        rb_REGV_temp_l -=32;                           /* increment Loopvoltage*/
      }
      else
      {
        if (rab_IntegrationTimePointer_mg>4)
        {
          rab_IntegrationTimePointer_mg--; /*VCO_028 reduce integration time*/
          rb_ASIC_ControlMode_g =  CASE_ASIC_CNT_MD_PRE_STANDBY;        /*look for rain in normal mode*/
        }
        else
        {
          rb_ASIC_ControlMode_g =  CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;  //close windows
        }
        rb_CloseTypeStandby_g = 6;
      }
      
    }

    if((rb_ACTR_Reg_g&0x0F)!=rab_IntegrationTimePointer_mg)
    {
//      ras_ASIC_CtrReg_g[IDX_ACTR_REG].val = (rb_ACTR_Reg_g&0xBF);
//      rab_ASIC_CtrReg_DEFAULT[IDX_ACTR_REG] = (rb_ACTR_Reg_g&0xBF);
      rab_SPI_ASICWriteBuffer_mg[0] = (byte)((ras_ASIC_CtrReg_g[IDX_ACTR_REG].addr<<1)|0x41);
      rab_SPI_ASICWriteBuffer_mg[1] = ((ras_ASIC_CtrReg_g[IDX_ACTR_REG].val&0xF0)|rab_IntegrationTimePointer_mg);
      rb_SPI_Data_to_send_g = 2;
      SPI_WriteBlock((pbyte)(&rab_SPI_ASICWriteBuffer_mg[0]),rb_SPI_Data_to_send_g);
      /* PRQA S 3390, 3397, 3400, 3138 3 *//*<< required for readability  >>*/
      STANDBY_WAIT_FOR_FREE_SPI();                 /* wait till spi is free*/
    }
    ras_ASIC_CtrReg_g[IDX_REGVH_REG].val = (rb_REGV_temp_l>>4);
    ras_ASIC_CtrReg_g[IDX_REGVL_REG].val = (rb_REGV_temp_l<<4);
    rb_firstRunafterInit_g = 1;
    rb_STB_LoopIn_ASIC_old_g = 0;           // reset old loopIn
  }
  else
  {
    
    rb_STB_LoopIn_ASIC_old_g = rb_STB_LoopIn_ASIC_g;       // store old loopin
  }
}
#endif
#endif /*_NO_RAIN*/


/*!
* \fn   void ASIC_Control_meas_Intout(void)
* \brief  Measure rainsensor function with software window Comparator
*         
* \param  void
* \return void 
*/
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

__callt void ASIC_Control_meas_Intout(void)
{
  byte WindowThreshold_l;
  byte SmallWindowThreshold_l;
  static byte rb_DiagHighTime_l;
  static word rw_DiagLowTime_l;
  
  
  WindowThreshold_l = (0x80+CB_RS_WINDOW_COMP_THRESHOLD);
  
  if (rbi_ASICgainAdjustRunning_g == TRUE)    /* Step Response Test? */
  {
    rb_DiagRain_HighTime_g = 0;
    ASIC_Control_ASICstepResponse();
  }
  else if (rb_DiagRain_HighTime_g>0)
  {
    rb_RS_SigVoltage_g = 0x80;
    if (rb_DiagHighTime_l>0)
    {
      rb_DiagHighTime_l --;
      rb_RS_SigVoltage_g = WindowThreshold_l+1;
    }
    else if (rw_DiagLowTime_l>0)
    {
      rw_DiagLowTime_l --;
    }
    else
    {
      rb_DiagHighTime_l = rb_DiagRain_HighTime_g;
      rw_DiagLowTime_l = rw_DiagRain_LowTime_g;
    }
  }
  
  if (rb_RS_SigVoltage_g > WindowThreshold_l)           /* Signal higher than window*/
  {
    rub_real_LengthCounter++;                                /* increment pulse length*/
    /*VDR_836 Pulse counter not always incremented*/
    if (rb_RS_SigVoltage_alt_g <= WindowThreshold_l)   /* old Signal was lower than window*/
    {
      rub_real_PulseCounter++;                          /* inkrement signal counter */
    }
    rbi_RainIsPresent_g = TRUE;
  }
  else
  {
    WindowThreshold_l = (0x80-CB_RS_WINDOW_COMP_THRESHOLD);
    if ((rb_RS_SigVoltage_g < WindowThreshold_l))  /* Signal is lower than window*/
    {
      rub_real_LengthCounter++;/* increment pulse length*/
      
      /*VDR_836 Pulse counter not always incremented*/
      if (rb_RS_SigVoltage_alt_g >= WindowThreshold_l)   /* old Signal was higher than window*/
      {
        rub_real_PulseCounter++;                          /* inkrement signal counter*/
      }
      rbi_RainIsPresent_g = TRUE;
    }
    else if ((0xFF == rub_RSIntermDelayInit) && (rw_WasRainingCounter_g > 5) && (rw_WasRainingCounter_g < 60))
    {
      SmallWindowThreshold_l = (0x80+(2*CB_RS_WINDOW_COMP_THRESHOLD/3));
      if (rb_RS_SigVoltage_g > SmallWindowThreshold_l)
      {
        rub_real_LengthCounter++;
        rbi_RainIsPresent_g = TRUE;
        if (rb_RS_SigVoltage_alt_g <= SmallWindowThreshold_l)
        {
          rub_real_PulseCounter++;
        }
      }
      else
      {
        SmallWindowThreshold_l = (0x80-(2*CB_RS_WINDOW_COMP_THRESHOLD/3));
        if (rb_RS_SigVoltage_g < SmallWindowThreshold_l)
        {
          rub_real_LengthCounter++;
          rbi_RainIsPresent_g = TRUE;
          if (rb_RS_SigVoltage_alt_g >= SmallWindowThreshold_l)
          {
            rub_real_PulseCounter++;
          }
        }
        else
        {
          rbi_RainIsPresent_g = FALSE;
        }
      }
    }
    else
    {
      rbi_RainIsPresent_g = FALSE;
    }
  }
  
  if((rbi_RainSensorEnable == TRUE) && (0xFF != rub_RSIntermDelayInit))
  {
    rw_WasRainingCounter_g = 0;
  }


  /* Rain intensity Signal voltage: VCO_423 */ 
  /* take the INTV and make negative values as positive */
#ifdef RAIN_INTENSITY
  if (rb_RS_SigVoltage_g < 0x80)
  {
    rb_RS_SigVoltage_neg_g = 0x80 + (0x80-rb_RS_SigVoltage_g);
  }
  else
  {
   rb_RS_SigVoltage_neg_g = rb_RS_SigVoltage_g;
  }
  
  rb_RS_SigVoltage_neg_g -= 0x80;                      /* we want that the values start from 0 and not from 128 */
  
  if (rb_RS_SigVoltage_neg_g == 1)                     /* filter for the very small changes during no rain  */
  {
    rb_RS_SigVoltage_neg_g = 0;
  }
  rb_RS_SigVoltage_abs_g = rb_RS_SigVoltage_neg_g;    /* save the calculated value to rb_RS_SigVoltage_abs_g, so we are safe of race condition */
#endif

  rb_RS_SigVoltage_alt_g = rb_RS_SigVoltage_g;        /* store old value*/
  
  
}
#endif /*_NO_RAIN_*/



/*!
* \fn   void ASIC_Control_ASICstepResponse(void)
* \brief  Pseudo-code : check step response of ASIC
*         
* \param  void
* \return void 
*/
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

static void ASIC_Control_ASICstepResponse(void)
{
  static word rw_DiagnosisRequestCounter_s;
  static byte rb_DiagnosticASICReqCount_s;
  static byte rb_DiagTimeWithoutPulset_s;
  static byte rb_Retry_s;
  
  byte rb_idx_l;
  byte rb_Cnt_l;
  
  /*SM231 - Check optical coupling by using diagnostic puls*/
  if (rbi_ASIC_DiagnosisRequest2_g == TRUE)                        /*Request freigegeben*/
  {
    if (rb_DiagnosticASICReqCount_s > CB_STEPRESPPERREQUEST_G)/* delay after normal mode command*/
    {
      if  (rw_DiagnosisRequestCounter_s > 0 )
      {
        rw_DiagnosisRequestCounter_s--; /* delay first puls*/
      }
      else
      {
        rb_DiagnosticASICReqCount_s = 0; /* start sequence*/
      }
    }
    else if (rw_DiagnosisRequestCounter_s > 0) /*Diagnose in progress*/
    {
      if (rw_DiagnosisRequestCounter_s > 0) /* go out if no rb_RS_SigVoltage_g for 50ms*/
      {
        rw_DiagnosisRequestCounter_s --;
      }
      else
      {
        /* VDR 590 retry once if step response is 0 */
        if ((rb_Retry_s > 0) && (rw_StepResponseRes_g[rb_DiagnosticASICReqCount_s-1] == 0))
        {
          rb_DiagnosticASICReqCount_s += rb_Retry_s;
          rb_Retry_s --;
        }
        rw_DiagnosisRequestCounter_s = 0;
      }
      Rainsensor_inactive();
      if (rw_StepResponseRes_g[rb_DiagnosticASICReqCount_s-1] < 0xFF00U) /* VDR511_5 prevent Overflow*/
      {
        rw_StepResponseRes_g[rb_DiagnosticASICReqCount_s-1] += rub_real_LengthCounter;   /*prevent overflow*/
      }
      if (rub_real_LengthCounter == 0)
      {
        if (rb_DiagTimeWithoutPulset_s < 0xff) /*VDR511_1*/
        {
          rb_DiagTimeWithoutPulset_s++;                     /*increase rb_RS_SigVoltage_g time*/
        }
      }
      else
      {
        rb_DiagTimeWithoutPulset_s = 0;
        rub_real_LengthCounter = 0;                             /*save time !*/
      }
    }
    else if (rb_DiagnosticASICReqCount_s > 1)                      /*neuer Request*/
    {
      if (rbi_SPI_activ_g == FALSE)
      {
        SPI_Write_Byte(CB_ASIC_CLEAR_DIAG);      /*request step*/
        rb_DiagnosticASICReqCount_s--;
        rb_DiagTimeWithoutPulset_s = 0;
        rw_DiagnosisRequestCounter_s = rw_DiagRequestCounter_g; /*Maximale Zeit fuer einen Request*/
      }
    }
    
    else if (rb_DiagnosticASICReqCount_s > 0) /* after 4 Tests!*/
      
    {
      rb_Cnt_l = 0;
      
      rw_DiagnoseStepResponseAnswer_g = 0;
      for (rb_idx_l = 0;rb_idx_l<CB_STEPRESPPERREQUEST_G;rb_idx_l++)
      {
        if (rw_StepResponseRes_g[rb_idx_l] > 0)
        {
          rb_Cnt_l ++;
          rw_DiagnoseStepResponseAnswer_g += rw_StepResponseRes_g[rb_idx_l];
        }
      }
      
      if (rb_Cnt_l > 0)
      {
        rw_DiagnoseStepResponseAnswer_g = (rw_DiagnoseStepResponseAnswer_g/rb_Cnt_l);
      }
      else
      {
        rw_DiagnoseStepResponseAnswer_g = 0;
      }
      
        rb_DiagnosticASICReqCount_s = 0;
        rbi_ASIC_DiagnosisRequest2_g = FALSE;
        rbi_ASIC_Step_Response_ready = TRUE;
        rbi_ASICgainAdjustRunning_g = FALSE; /*EXIT will be cleared after coding*/
    }
    else
    {
      
      if (rbi_SPI_activ_g == FALSE)
      {
        rb_DiagnosticASICReqCount_s = CB_STEPRESPPERREQUEST_G;
        rb_DiagTimeWithoutPulset_s = 0;
        rw_DiagnosisRequestCounter_s = rw_DiagRequestCounter_g;
        rub_real_LengthCounter = 0;            /* reset variables*/
        rub_real_PulseCounter = 0;
        rw_DiagnoseStepResponseAnswer_g = 0;
        rb_Retry_s = 1;
        
        for (rb_idx_l = 0;rb_idx_l<CB_STEPRESPPERREQUEST_G;rb_idx_l++)
        {
          rw_StepResponseRes_g[rb_idx_l] = 0;
        }
        
        SPI_Write_Byte(CB_ASIC_SET_DIAG);
      }
      
    }
  }
  else
  {
      rb_DiagnosticASICReqCount_s = 55;        /* higher than needed*/
      rw_DiagnosisRequestCounter_s = rw_DiagRequestCounter_g;
      rbi_ASIC_DiagnosisRequest2_g = TRUE;
  }
}
#endif /*_NO_RAIN_*/



/*!
* \fn   void ASIC_Control_CalcRSGain(void)
* \brief  Pseudo-code : Calculates the ASIC Frontendgain with the information of
* the coding
* \param  void
* \return void 
*/
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

void ASIC_Control_CalcRSGain(void)
{
  byte rb_ArrayOffset_l=0;
  byte rb_Result_l;
  byte rb_laufvariable_l;
  /** \brief  boarders to used next gainsetup*/
  byte CAB_TRANS_GAIN_INCR_BOARDERS[11]= {82,76,70,64,58,52,46,40,35,30,0}; /*Transmission rate boarders to adapt frontend gain of ASIC*/
  rb_laufvariable_l = 0;
  rb_Result_l = 0xff;
  do  // calculation of gain
  {
    if (rb_880nm_Transmission_g >= CAB_TRANS_GAIN_INCR_BOARDERS[rb_laufvariable_l])
    {
      rb_Result_l = rab_RS_GainSetupArray(rb_laufvariable_l);
    }
    rb_laufvariable_l++;
  }while(rb_Result_l == 0xff);
  
  rb_ArrayOffset_l = rb_laufvariable_l-1;
  
  if((rb_ASIC_Sched_Config_g & 0x4) == 4)
  {
    rb_GainOffset_g=0;
  }
  
  if((rb_GainOffset_g&0x80)!=0x80)
  {
    if((rb_ArrayOffset_l + (rb_GainOffset_g&0x0F))<=10)
    {
      rb_ArrayOffset_l += (rb_GainOffset_g&0x0F);
    }
    else
    {
      rb_ArrayOffset_l=10;
    }
  }
  else
  {
    if((rb_ArrayOffset_l >= (rb_GainOffset_g&0x0F)))
    {
      rb_ArrayOffset_l -= (rb_GainOffset_g&0x0F);
    }
    else
    {
      rb_ArrayOffset_l=0;
    }
  }
  
  rb_ASICGainSetup_g = rab_RS_GainSetupArray(rb_ArrayOffset_l);
  
}

/*!
* \fn   byte ASIC_Control_STBCheckRain(void)
* \brief  ASIC Control STBCheckRain
*         
* \param  void
* \return byte 
*/
byte ASIC_Control_STBCheckRain(void)
{
 
  if (rb_LastLengthCounter_s < rub_LengthCounter) // LengthCounter > Stored LengthCounter?
  {
    rw_LengthSum_s = rw_LengthSum_s + (rub_LengthCounter - rb_LastLengthCounter_s); // add difference to LengthSum
  }
  else if (rb_LastLengthCounter_s > rub_LengthCounter) // LengthCounter < Stored LengthCounter?
  {
    rw_LengthSum_s = rw_LengthSum_s + (255 - rb_LastLengthCounter_s) + rub_LengthCounter;  // add difference to LengthSum
  }
  else {} /*Misra Rule 14.10*/
  return  (rw_LengthSum_s >= (cb_THRES_RSACTION_mg * 10)) ; // LengthSum > Threshold?
 
}
#endif /*_NO_RAIN_*/
