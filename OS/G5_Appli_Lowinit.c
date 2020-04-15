/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/
/* PRQA S 0434,0436,0781,4130 EOF */ /* << 0434,0436 usage of SFR >> */
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 274 EOF *//*<< 274: use of ~ required, generated from applilet tool >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/* PRQA S 1006 EOF *//*<< NOPs used for delay >>*/
/* PRQA S 0602 EOF *//*<< automatic generated code from applilet  >>*/
/*-------------------------------------------------------------------------
*                            - LOWINIT.C -
*
*
*      Low-level initialisation function
*
*      To be tailored by user
*
*-------------------------------------------------------------------------*/
/****************************************************************************/
/* Date      VDR_Number     Description                                       */
/* 08.12.2014 VCO_151  NB  Implement IC test */
/* 24.03.2015 VCO_237  MP  Supplyvoltage should not be monitored on no rain variants*/
/* 25.03.2015 VDR_863  NB  The port P11 used for MISO configured as OUTPUT */
/* 19.06.2015 VDR_870  NB  Set all unused IO ports of microcontroller to Output low */
/* 13.07.2015 VDR_868  NB  QAC and Polyspace fixing for SW009 Release  */
/* 03.09.2015 VDR_904    NB    Response error is set when invalid LIN header is received  */
/* 16.1.2015 VDR_927    NB    Wiper speed is valid on the bus only after 1.35 sec  */
/****************************************************************************/



#include "ior5f109be.h"
#include "ior5f109be_ext.h"
#include <intrinsics.h>
#include "G5_Appli_Lowinit.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
static void R_SAU0_Create(void);
static void R_CSI00_Create(void);
static void R_PORT_Create(void);
static void R_TAU0_Create(void);
static void R_UARTF0_Create(void);
static void R_CGC_Create(void);
static void R_ADC_Create(void);
static void R_WDT_Create(void);
static void R_Systeminit(void);
static void R_IT_Create(void);

static void R_PORT_Create(void)
{
  P0 = _00_Pn0_OUTPUT_0;
  P1 = _01_Pn0_OUTPUT_1 | _00_Pn7_OUTPUT_0 | _08_Pn3_OUTPUT_1;
  P14 = _00_Pn7_OUTPUT_0;
  PMC0 = _00_PMCn0_DI_ON | _02_PMCn1_NOT_USE | _FC_PMC0_DEFAULT;
  PMC12 = _00_PMCn0_DI_ON | _FE_PMC12_DEFAULT;
  PMC14 = _00_PMCn7_DI_ON | _7F_PMC14_DEFAULT;
  PM0 = _00_PMn0_MODE_OUTPUT | _02_PMn1_NOT_USE | _FC_PM0_DEFAULT;
  PM1 = _00_PMn0_MODE_OUTPUT | _02_PMn1_MODE_INPUT  | _04_PMn2_NOT_USE | _00_PMn3_MODE_OUTPUT  | _10_PMn4_NOT_USE |
    _20_PMn5_NOT_USE | _40_PMn6_NOT_USE | _00_PMn7_MODE_OUTPUT; /* VDR_863 */
  PM3 = _00_PMn0_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT | _FC_PM3_DEFAULT;
  PM12 = _00_PMn0_MODE_OUTPUT | _FE_PM12_DEFAULT;
  PM14 = _00_PMn7_MODE_OUTPUT | _7F_PM14_DEFAULT;
  PU14 = 0x80;
  
  PU12 = 0;
}


static void R_TAU0_Create(void)
{
  TAU0EN = 1U;    /* supplies input clock */
  TPS0 = _0000_TAU_CKM0_FCLK_0 | _0000_TAU_CKM1_FCLK_0 | _0000_TAU_CKM2_FCLK_1 | _0000_TAU_CKM3_FCLK_8;
  /* Stop all channels */
  TT0 = _0001_TAU_CH0_STOP_TRG_ON | _0002_TAU_CH1_STOP_TRG_ON | _0004_TAU_CH2_STOP_TRG_ON |
    _0008_TAU_CH3_STOP_TRG_ON | _0010_TAU_CH4_STOP_TRG_ON | _0020_TAU_CH5_STOP_TRG_ON |
      _0040_TAU_CH6_STOP_TRG_ON | _0080_TAU_CH7_STOP_TRG_ON | _0200_TAU_CH1_H8_STOP_TRG_ON |
        _0800_TAU_CH3_H8_STOP_TRG_ON;
  /* Mask channel 0 interrupt */
  TMMK00 = 1U;    /* disable INTTM00 interrupt */
  TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
  /* Mask channel 1 interrupt */
  TMMK01 = 1U;    /* disable INTTM01 interrupt */
  TMIF01 = 0U;    /* clear INTTM01 interrupt flag */
  /* Mask channel 1 higher 8 bits interrupt */
  TMMK01H = 1U;    /* disable INTTM01H interrupt */
  TMIF01H = 0U;    /* clear INTTM01H interrupt flag */
  /* Mask channel 2 interrupt */
  TMMK02 = 1U;    /* disable INTTM02 interrupt */
  TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
  /* Mask channel 3 interrupt */
  TMMK03 = 1U;    /* disable INTTM03 interrupt */
  TMIF03 = 0U;    /* clear INTTM03 interrupt flag */
  /* Mask channel 3 higher 8 bits interrupt */
  TMMK03H = 1U;    /* disable INTTM03H interrupt */
  TMIF03H = 0U;    /* clear INTTM03H interrupt flag */
  /* Mask channel 4 interrupt */
  TMMK04 = 1U;    /* disable INTTM04 interrupt */
  TMIF04 = 0U;    /* clear INTTM04 interrupt flag */
  /* Mask channel 5 interrupt */
  TMMK05 = 1U;    /* disable INTTM05 interrupt */
  TMIF05 = 0U;    /* clear INTTM05 interrupt flag */
  /* Mask channel 6 interrupt */
  TMMK06 = 1U;    /* disable INTTM06 interrupt */
  TMIF06 = 0U;    /* clear INTTM06 interrupt flag */
  /* Mask channel 7 interrupt */
  TMMK07 = 1U;    /* disable INTTM07 interrupt */
  TMIF07 = 0U;    /* clear INTTM07 interrupt flag */
  /* Set INTTM00 low priority */
  TMPR100 = 1U;
  TMPR000 = 1U;
  /* Set INTTM05 low priority */
  TMPR105 = 1U;
  TMPR005 = 1U;
  
  /* Set INTTM06 low priority */
  TMPR106 = 1U;
  TMPR006 = 1U;
  
  /* Channel 0 used as interval timer */
  TMR00 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
    _0000_TAU_TRIGGER_SOFTWARE | _0000_TAU_MODE_INTERVAL_TIMER | _0000_TAU_START_INT_UNUSED;
  TDR00 = _1F3F_TAU_TDR00_VALUE;
  TO0 &= ~_0001_TAU_CH0_OUTPUT_VALUE_1;
  TOE0 &= ~_0001_TAU_CH0_OUTPUT_ENABLE;
  /* Channel 5 is used to measure input pulse interval */
  TIS0 = _04_TAU_CH5_INPUT_FIL;
  TMR05 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
    _0100_TAU_TRIGGER_TIMN_VALID | _0000_TAU_TIMN_EDGE_FALLING | _0004_TAU_MODE_CAPTURE |
      _0000_TAU_START_INT_UNUSED;
  TOM0 &= ~_0020_TAU_CH5_OUTPUT_COMBIN;
  TOL0 &= ~_0020_TAU_CH5_OUTPUT_LEVEL_L;
  TO0 &= ~_0020_TAU_CH5_OUTPUT_VALUE_1;
  TOE0 &= ~_0020_TAU_CH5_OUTPUT_ENABLE;  
  
  /* Channel 6 used as interval timer */
  TMR06 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
    _0100_TAU_TRIGGER_TIMN_VALID | _0000_TAU_TIMN_EDGE_FALLING | _0004_TAU_MODE_CAPTURE | _0000_TAU_START_INT_UNUSED;
  TDR06 = _0000_TAU_TDR06_VALUE;
  TOM0 &= ~_0040_TAU_CH6_OUTPUT_COMBIN;
  TOL0 &= ~_0040_TAU_CH6_OUTPUT_LEVEL_L;
  TO0 &= ~_0040_TAU_CH6_OUTPUT_VALUE_1;
  TOE0 &= ~_0040_TAU_CH6_OUTPUT_ENABLE;
  
}
void R_TAU0_Channel0_Start(void)
{
  TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
  TMMK00 = 0U;    /* enable INTTM00 interrupt */
  TS0 |= _0001_TAU_CH0_START_TRG_ON;
}

void R_TAU0_Channel0_Stop(void)
{
  TT0 |= _0001_TAU_CH0_STOP_TRG_ON;
  /* Mask channel 0 interrupt */
  TMMK00 = 1U;    /* disable INTTM00 interrupt */
  TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel5_Start
* Description  : This function starts TAU0 channel 5 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel5_Start(void)
{
  TMIF05 = 0U;    /* clear INTTM05 interrupt flag */
  TMMK05 = 0U;    /* enable INTTM05 interrupt */
  TS0 |= _0020_TAU_CH5_START_TRG_ON;
}

void R_TAU0_Channel5_Stop(void)
{
  TT0 |= _0020_TAU_CH5_STOP_TRG_ON;
  /* Mask channel 5 interrupt */
  TMMK05 = 1U;    /* disable INTTM05 interrupt */
  TMIF05 = 0U;    /* clear INTTM05 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_IT_Create
* Description  : This function initializes the IT module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void R_IT_Create(void)
{
  RTCEN = 1U;    /* supply IT clock */
  ITMC = _0000_IT_OPERATION_DISABLE;    /* disable IT operation */
  ITMK = 1U;    /* disable INTIT interrupt */
  ITIF = 0U;    /* clear INTIT interrupt flag */
  /* Set INTIT low priority */
  ITPR1 = 1U;
  ITPR0 = 1U;
  ITMC = _02ED_ITMCMP_VALUE;
}

/***********************************************************************************************************************
* Function Name: R_IT_Start
* Description  : This function starts IT module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

void R_IT_Start(void)
{
  ITIF = 0U;    /* clear INTIT interrupt flag */
  ITMK = 0U;    /* enable INTIT interrupt */
  ITMC = _02ED_ITMCMP_VALUE;
  ITMC |= _8000_IT_OPERATION_ENABLE;    /* enable IT operation */
}
#endif /*_NO_RAIN_*/

/***********************************************************************************************************************
* Function Name: R_IT_Stop
* Description  : This function stops IT module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

void R_IT_Stop(void)
{
  ITMK = 1U;    /* disable INTIT interrupt */
  ITIF = 0U;    /* clear INTIT interrupt flag */
  ITMC &= (word)(~_0000_IT_OPERATION_DISABLE);    /* disable IT operation */
}
#endif /*_NO_RAIN_*/

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel6_Start
* Description  : This function starts TAU0 channel 6 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel6_Start(void)
{
  PIOR = 0x01U;
  TMIF06 = 0U;    /* clear INTTM06 interrupt flag */
  TMMK06 = 0U;    /* enable INTTM06 interrupt */
  TS0 |= _0040_TAU_CH6_START_TRG_ON;
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel6_Stop
* Description  : This function stops TAU0 channel 6 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel6_Stop(void)
{
  TT0 |= _0040_TAU_CH6_STOP_TRG_ON;
  PIOR = 0x00U;
  /* Mask channel 6 interrupt */
  TMMK06 = 1U;    /* disable INTTM06 interrupt */
  TMIF06 = 0U;    /* clear INTTM06 interrupt flag */
}

static void R_UARTF0_Create(void)
{
  UF0EN = 1U;
  UF0CTL0 &= (unsigned int)(~_40_UARTF_TRANSMISSION_ENABLE & ~_20_UARTF_RECEPTION_ENABLE);/* disable UARTF0 operation */
  LTMK0 = 1U;  /* disable INTLT interrupt */
  LTIF0 = 0U;  /* clear INTLT interrupt flag */
  LRMK0 = 1U;  /* disable INTLR interrupt */
  LRIF0 = 0U;  /* clear INTLR interrupt flag */
  LSMK0 = 1U;  /* disable INTLS interrupt */
  LSIF0 = 0U;  /* clear INTLS interrupt flag */
  /* Set INTLT low priority */
  LTPR10 = 1U;
  LTPR00 = 1U;
  /* Set INTLR low priority */
  LRPR10 = 1U;
  LRPR00 = 1U;
  /* Set INTLS low priority */
  LSPR10 = 1U;
  LSPR00 = 1U;
  //    UF0CTL1 = _2000_UARTF_BASECLK_2 | 0x00D0; /*set the uart clock to 8 Mhz */
  UF0CTL1 = _0000_UARTF_BASECLK_1 | _01A1_UARTF0_K_VALUE;
  UF0OPT0 = _14_UARTF_UFNOPT0_INITIALVALUE | _00_UARTF_TRAN_DATALEVEL_NORMAL | _00_UARTF_REC_DATALEVEL_NORMAL;
  /* enable Auto checksum and data consistancy check*/
  UF0OPT1 = _00_UARTF_EXPANSIONBIT_UNUSE | _00_UARTF_AUTOMATIC_BAUD_MODE |0x19; 
  UF0OPT2 = _01_UARTF_LT_INT_GENTIME_1 | _00_UARTF_DATA_NOISE_FILTER_USED;
  UF0CTL0 = _10_UARTF_TRANSFDIR_LSB | _00_UARTF_PARITY_NONE | _02_UARTF_DATALENGTH_8BIT | _00_UARTF_STOPLENGTH_1BIT;
  /* Set LTXD0 pin */
  PM5 |= 0x02U;
  PMX2 = 0xFEU;
  /* Set LRXD0 pin */
  PM5 |= 0x01U;
}
void R_UARTF0_Start(void)
{
  LTIF0 = 0U;  /* clear INTLT interrupt flag */
  LTMK0 = 0U;  /* disable INTLT interrupt */
  LRIF0 = 0U;  /* clear INTLR interrupt flag */
  LRMK0 = 0U;  /* enable INTLR interrupt */
  LSIF0 = 0U;  /* clear INTLS interrupt flag */
  LSMK0 = 0U;  /* enable INTLS interrupt */
  UF0CTL0 |= _40_UARTF_TRANSMISSION_ENABLE | _20_UARTF_RECEPTION_ENABLE; /* enable UARTF0 operation */
}



static void R_CGC_Create(void)
{
  /* Set fMX */
  CMC = _00_CGC_HISYS_PORT | _00_CGC_SYSOSC_DEFAULT;
  MSTOP = 1U;
  /* Set fMAIN */
  MCM0 = 0U;
  OSMC = _10_CGC_RTC_CLK_FIL;
  /* Set fIH */
  HIOSTOP = 0U;
}


/***********************************************************************************************************************
* Function Name: R_SAU0_Create
* Description  : This function initializes the SAU0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void R_SAU0_Create(void)
{
  SAU0EN = 1U;    /* supply SAU0 clock; Enable peripheral clock for the CSI00 */
  /* After setting PER0, PER1 to 1, be sure to wait 4 or more clocks before setting SPSm Register (See Caution in UM)*/
  NOP();
  NOP();
  NOP();
  NOP();
  /*Select a serial clock of (fCLK/4) for the Unit 0  (CKS0 and CKS1).*/  
  SPS0 = _0000_SAU_CK00_FCLK_0 | _0000_SAU_CK01_FCLK_0;    
  /*Here:  890kHz at 16MHz for CK00*/
  R_CSI00_Create();
}

/***********************************************************************************************************************
* Function Name: R_CSI00_Create
* Description  : This function initializes the CSI00 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void R_CSI00_Create(void)
{
  ST0 |= _0001_SAU_CH0_STOP_TRG_ON;             /* disable CSI00 */
  CSIMK00 = 1U;                                 /* disable INTCSI00 interrupt */
  CSIIF00 = 0U;                                 /* clear INTCSI00 interrupt flag */
  CSIPR100 = 0U;                                /* Set INTCSI00 High priority */
  CSIPR000 = 0U;
  SIR00 = _0004_SAU_SIRMN_FECTMN | _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;    /* clear error flag */
  SMR00 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_CLOCK_MODE_CKS |
    _0000_SAU_TRIGGER_SOFTWARE | _0000_SAU_MODE_CSI | _0000_SAU_TRANSFER_END;   /*Interrupt source selection*/
  /*Setting of data length in CSI mode*/
  SCR00 = _C000_SAU_RECEPTION_TRANSMISSION | _3000_SAU_TIMING_4 | _0000_SAU_MSB | _0007_SAU_LENGTH_8;
  SDR00 = _1000_CSI00_DIVISOR;                            /*Setting of division ration of operation clock (MCK)*/
  SOL0 = 0x0000;                                          /*Selects inversion of the level of the transmit data*/
  SO0 &= ~_0100_SAU_CH0_CLOCK_OUTPUT_1;                   /* CSI00 clock initial level */
  SO0 &= ~_0001_SAU_CH0_DATA_OUTPUT_1;                    /* CSI00 SO initial level */
  SO0 &= 0x0F0F;
  SOE0 |= _0001_SAU_CH0_OUTPUT_ENABLE;                    /* enable CSI00 output */
  
}

/***********************************************************************************************************************
* Function Name: R_CSI00_Start
* Description  : This function starts the CSI00 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CSI00_Start(void)
{
  CSIIF00 = 0U;                                  /* clear INTCSI00 interrupt flag */
  CSIMK00 = 0U;                                  /* enable INTCSI00 */
  SO0 &= ~_0100_SAU_CH0_CLOCK_OUTPUT_1;          /* CSI00 clock initial level */
  SO0 &= ~_0001_SAU_CH0_DATA_OUTPUT_1;           /* CSI00 SO initial level */
  SO0 &= 0x0F0F;
  SOE0 |= _0001_SAU_CH0_OUTPUT_ENABLE;           /* enable CSI00 output */
  SS0 |= _0001_SAU_CH0_START_TRG_ON;             /* enable CSI00 */
  
  P1_bit.no0 = 1;           /*Set port latch of /SCK00 to 1*/
  POM1 &= (~0x05);          /*P1.0 and P1.2 pin output mode selection*/
  PM1_bit.no0 = 0;          /*Set port bit direction of /SCK00 to Output*/
  PU1_bit.no1 = 1;          /*Set the SW Pull-up for SI00 to have defined level at SI00*/
  PM1_bit.no1 = 1;          /*Set port bit direction of SI00 to input*/
  P1_bit.no2 = 1;           /*Set port latch of SO00 to 1*/
  PM1_bit.no2 = 0;          /*Set port bit direction of SO00 to output*/
  PMX0 = 1;                 /*Select the alternate function of P10/SCK00/SCKS0/SCL00 pin*/
  PMX1 = 1;                 /*Select the alternate function of P12/SO00/TxD0/SOS0/TxDS0/TOOLTxD pin*/
}


static void R_ADC_Create(void)
{
  ADCEN = 1U;  /* supply AD clock */
  ADM0 = _00_AD_ADM0_INITIALVALUE;  /* disable AD conversion and clear ADM0 register */
  ADMK = 1U;  /* disable INTAD interrupt */
  ADIF = 0U;  /* clear INTAD interrupt flag */
  /* Set INTAD low priority */
  ADPR1 = 1U;
  ADPR0 = 1U;
  /* Set ANI0 - ANI2 pin as analog input */
  PM2 |= 0x07U;
  ADM0 = _18_AD_CONVERSION_CLOCK_8 | _00_AD_TIME_MODE_NORMAL_1 | _00_AD_OPERMODE_SELECT;
  ADM1 = _00_AD_TRIGGER_SOFTWARE | _00_AD_CONVMODE_CONSELECT;
  ADM2 = _40_AD_POSITIVE_AVREFP | _20_AD_NEGATIVE_AVREFM | _08_AD_AREA_MODE_2_3 | _01_AD_RESOLUTION_8BIT;
  ADUL = _FF_AD_ADUL_VALUE;
  ADLL = _00_AD_ADLL_VALUE;
  ADS = _02_AD_INPUT_CHANNEL_2;
  ADCE = 1U;  /* enable AD comparator */
}

void R_ADC_Start(void)
{
  ADIF = 0U;  /* clear INTAD interrupt flag */
  ADMK = 0U;  /* enable INTAD interrupt */
  ADCS = 1U;  /* enable AD conversion */
}

void R_ADC_Stop(void)
{
  ADCS = 0U;  /* disable AD conversion */
  ADMK = 1U;  /* disable INTAD interrupt */
  ADIF = 0U;  /* clear INTAD interrupt flag */
}

static void R_WDT_Create(void)
{
  WDTIMK = 1U;    /* disable INTWDTI interrupt */
  WDTIIF = 0U;    /* clear INTWDTI interrupt flag */
}

static void R_Systeminit(void)
{
  PIOR = 0x00U;
  
  R_CGC_Create();
  R_TAU0_Create();
  R_WDT_Create();
  
  CRC0CTL = 0x00U;
  IAWCTL = 0x80U;       /* Enables the detection of invalid memory access.*/ 
}

void Peripheral_Init(void)
{
  R_PORT_Create();
  R_SAU0_Create();
  R_UARTF0_Create();
  R_ADC_Create();
  R_IT_Create();
}




#pragma location="RCODE"
int __low_level_init ( void )
{
  
  R_Systeminit();
  return ( 1 );
}
