#ifndef G5_APPLI_LOWINIT_H
#define G5_APPLI_LOWINIT_H
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
/****************************************************************************/

#include "G5_projectDefs.h"


#define _NOP() __no_operation()
/* Control of timer array unit 0 input clock (TAU0EN) */
#define _00_TAU0_CLOCK_STOP                     (0x00U)   /* stops supply of input clock */
#define _01_TAU0_CLOCK_SUPPLY                   (0x01U)   /* supplies input clock */
/* Pmn pin I/O mode selection (PMm7 - PMm0) */
#define _01_PMn0_NOT_USE        (0x01U) /* not use Pn0 as digital I/O */
#define _01_PMn0_MODE_INPUT     (0x01U) /* use Pn0 as input mode */
#define _00_PMn0_MODE_OUTPUT    (0x00U) /* use Pn0 as output mode */
#define _02_PMn1_NOT_USE        (0x02U) /* not use Pn1 as digital I/O */
#define _02_PMn1_MODE_INPUT     (0x02U) /* use Pn1 as input mode */
#define _00_PMn1_MODE_OUTPUT    (0x00U) /* use Pn1 as output mode */
#define _04_PMn2_NOT_USE        (0x04U) /* not use Pn2 as digital I/O */
#define _04_PMn2_MODE_INPUT     (0x04U) /* use Pn2 as input mode */
#define _00_PMn2_MODE_OUTPUT    (0x00U) /* use Pn2 as output mode */
#define _08_PMn3_NOT_USE        (0x08U) /* not use Pn3 as digital I/O */
#define _08_PMn3_MODE_INPUT     (0x08U) /* use Pn3 as input mode */
#define _00_PMn3_MODE_OUTPUT    (0x00U) /* use Pn3 as output mode */
#define _10_PMn4_NOT_USE        (0x10U) /* not use Pn4 as digital I/O */
#define _10_PMn4_MODE_INPUT     (0x10U) /* use Pn4 as input mode */
#define _00_PMn4_MODE_OUTPUT    (0x00U) /* use Pn4 as output mode */
#define _20_PMn5_NOT_USE        (0x20U) /* not use Pn5 as digital I/O */
#define _20_PMn5_MODE_INPUT     (0x20U) /* use Pn5 as input mode */
#define _00_PMn5_MODE_OUTPUT    (0x00U) /* use Pn5 as output mode */
#define _40_PMn6_NOT_USE        (0x40U) /* not use Pn6 as digital I/O */
#define _40_PMn6_MODE_INPUT     (0x40U) /* use Pn6 as input mode */
#define _00_PMn6_MODE_OUTPUT    (0x00U) /* use Pn6 as output mode */
#define _80_PMn7_NOT_USE        (0x80U) /* not use Pn7 as digital I/O */
#define _80_PMn7_MODE_INPUT     (0x80U) /* use Pn7 as input mode */
#define _00_PMn7_MODE_OUTPUT    (0x00U) /* use Pn7 as output mode */

/*
  Port Register (Pm)
*/
/* Pmn pin data (Pm0 to Pm7) */
#define _00_Pn0_OUTPUT_0        (0x00U) /* Pn0 output 0 */
#define _01_Pn0_OUTPUT_1        (0x01U) /* Pn0 output 1 */
#define _00_Pn1_OUTPUT_0        (0x00U) /* Pn1 output 0 */
#define _02_Pn1_OUTPUT_1        (0x02U) /* Pn1 output 1 */
#define _00_Pn2_OUTPUT_0        (0x00U) /* Pn2 output 0 */
#define _04_Pn2_OUTPUT_1        (0x04U) /* Pn2 output 1 */
#define _00_Pn3_OUTPUT_0        (0x00U) /* Pn3 output 0 */
#define _08_Pn3_OUTPUT_1        (0x08U) /* Pn3 output 1 */
#define _00_Pn4_OUTPUT_0        (0x00U) /* Pn4 output 0 */
#define _10_Pn4_OUTPUT_1        (0x10U) /* Pn4 output 1 */
#define _00_Pn5_OUTPUT_0        (0x00U) /* Pn5 output 0 */
#define _20_Pn5_OUTPUT_1        (0x20U) /* Pn5 output 1 */
#define _00_Pn6_OUTPUT_0        (0x00U) /* Pn6 output 0 */
#define _40_Pn6_OUTPUT_1        (0x40U) /* Pn6 output 1 */
#define _00_Pn7_OUTPUT_0        (0x00U) /* Pn7 output 0 */
#define _80_Pn7_OUTPUT_1        (0x80U) /* Pn7 output 1 */

/*
  Pull-up Resistor Option Register (PUm)
*/
/* Pmn pin on-chip pull-up resistor selection (PUmn) */
#define _00_PUn0_PULLUP_OFF     (0x00U) /* Pn0 pull-up resistor not connected */
#define _01_PUn0_PULLUP_ON      (0x01U) /* Pn0 pull-up resistor connected */
#define _00_PUn1_PULLUP_OFF     (0x00U) /* Pn1 pull-up resistor not connected */
#define _02_PUn1_PULLUP_ON      (0x02U) /* Pn1 pull-up resistor connected */
#define _00_PUn2_PULLUP_OFF     (0x00U) /* Pn2 Pull-up resistor not connected */
#define _04_PUn2_PULLUP_ON      (0x04U) /* Pn2 pull-up resistor connected */
#define _00_PUn3_PULLUP_OFF     (0x00U) /* Pn3 pull-up resistor not connected */
#define _08_PUn3_PULLUP_ON      (0x08U) /* Pn3 pull-up resistor connected */
#define _00_PUn4_PULLUP_OFF     (0x00U) /* Pn4 pull-up resistor not connected */
#define _10_PUn4_PULLUP_ON      (0x10U) /* Pn4 pull-up resistor connected */
#define _00_PUn5_PULLUP_OFF     (0x00U) /* Pn5 pull-up resistor not connected */
#define _20_PUn5_PULLUP_ON      (0x20U) /* Pn5 pull-up resistor connected */
#define _00_PUn6_PULLUP_OFF     (0x00U) /* Pn6 pull-up resistor not connected */
#define _40_PUn6_PULLUP_ON      (0x40U) /* Pn6 pull-up resistor connected */
#define _00_PUn7_PULLUP_OFF     (0x00U) /* Pn7 pull-up resistor not connected */
#define _80_PUn7_PULLUP_ON      (0x80U) /* Pn7 pull-up resistor connected */

/*
  Port Input Mode Register (PIMm)
*/
/* Pmn pin input buffer selection (PIMmn) */
#define _00_PIMn0_TTL_OFF       (0x00U) /* set Pn0 normal input buffer */
#define _01_PIMn0_TTL_ON        (0x01U) /* set Pn0 TTL input buffer */
#define _00_PIMn1_TTL_OFF       (0x00U) /* set Pn1 normal input buffer */
#define _02_PIMn1_TTL_ON        (0x02U) /* set Pn1 TTL input buffer */
#define _00_PIMn2_TTL_OFF       (0x00U) /* set Pn2 normal input buffer */
#define _04_PIMn2_TTL_ON        (0x04U) /* set Pn2 TTL input buffer */
#define _00_PIMn3_TTL_OFF       (0x00U) /* set Pn3 normal input buffer */
#define _08_PIMn3_TTL_ON        (0x08U) /* set Pn3 TTL input buffer */
#define _00_PIMn4_TTL_OFF       (0x00U) /* set Pn4 normal input buffer */
#define _10_PIMn4_TTL_ON        (0x10U) /* set Pn4 TTL input buffer */
#define _00_PIMn5_TTL_OFF       (0x00U) /* set Pn5 normal input buffer */
#define _20_PIMn5_TTL_ON        (0x20U) /* set Pn5 TTL input buffer */
#define _00_PIMn6_TTL_OFF       (0x00U) /* set Pn6 normal input buffer */
#define _40_PIMn6_TTL_ON        (0x40U) /* set Pn6 TTL input buffer */
#define _00_PIMn7_TTL_OFF       (0x00U) /* set Pn7 normal input buffer */
#define _80_PIMn7_TTL_ON        (0x80U) /* set Pn7 TTL input buffer */

/*
  Port Output Mode Register (POMm)
*/
/* Pmn pin output mode selection (POMmn) */
#define _00_POMn0_NCH_OFF       (0x00U) /* set Pn0 output normal mode */
#define _01_POMn0_NCH_ON        (0x01U) /* set Pn0 output N-ch open-drain mode */
#define _00_POMn1_NCH_OFF       (0x00U) /* set Pn1 output normal mode */
#define _02_POMn1_NCH_ON        (0x02U) /* set Pn1 output N-ch open-drain mode */
#define _00_POMn2_NCH_OFF       (0x00U) /* set Pn2 output normal mode */
#define _04_POMn2_NCH_ON        (0x04U) /* set Pn2 output N-ch open-drain mode */
#define _00_POMn3_NCH_OFF       (0x00U) /* set Pn3 output normal mode */
#define _08_POMn3_NCH_ON        (0x08U) /* set Pn3 output N-ch open-drain mode */
#define _00_POMn4_NCH_OFF       (0x00U) /* set Pn4 output normal mode */
#define _10_POMn4_NCH_ON        (0x10U) /* set Pn4 output N-ch open-drain mode */
#define _00_POMn5_NCH_OFF       (0x00U) /* set Pn5 output normal mode */
#define _20_POMn5_NCH_ON        (0x20U) /* set Pn5 output N-ch open-drain mode */
#define _00_POMn6_NCH_OFF       (0x00U) /* set Pn6 output normal mode */
#define _40_POMn6_NCH_ON        (0x40U) /* set Pn6 output N-ch open-drain mode */
#define _00_POMn7_NCH_OFF       (0x00U) /* set Pn7 output normal mode */
#define _80_POMn7_NCH_ON        (0x80U) /* set Pn7 output N-ch open-drain mode */

/*
  Port Operation Mode Register (PMCm)
*/
/* Pmn pin digital input buffer selection (PMCmn) */
#define _01_PMCn0_NOT_USE       (0x01U) /* not use Pn0 digital input */
#define _00_PMCn0_DI_ON         (0x00U) /* enable Pn0 digital input */
#define _02_PMCn1_NOT_USE       (0x02U) /* not use Pn1 digital input */
#define _00_PMCn1_DI_ON         (0x00U) /* enable Pn1 digital input */
#define _04_PMCn2_NOT_USE       (0x04U) /* not use Pn2 digital input */
#define _00_PMCn2_DI_ON         (0x00U) /* enable Pn2 digital input */
#define _08_PMCn3_NOT_USE       (0x08U) /* not use Pn3 digital input */
#define _00_PMCn3_DI_ON         (0x00U) /* enable Pn3 digital input */
#define _10_PMCn4_NOT_USE       (0x10U) /* not use Pn4 digital input */
#define _00_PMCn4_DI_ON         (0x00U) /* enable Pn4 digital input */
#define _20_PMCn5_NOT_USE       (0x20U) /* not use Pn5 digital input */
#define _00_PMCn5_DI_ON         (0x00U) /* enable Pn5 digital input */
#define _40_PMCn6_NOT_USE       (0x40U) /* not use Pn6 digital input */
#define _00_PMCn6_DI_ON         (0x00U) /* enable Pn6 digital input */
#define _80_PMCn7_NOT_USE       (0x80U) /* not use Pn7 digital input */
#define _00_PMCn7_DI_ON         (0x00U) /* enable Pn7 digital input */

/*
  AD port configuration register (ADPC)
*/
/* Analog input/digital input switching (ADPC3 - ADPC0) */
#define _00_ADPC_DI_OFF         (0x00U) /* use P20 - P27 as analog input */
#define _08_ADPC_DI_ON          (0x08U) /* use P27 as digital input */
#define _07_ADPC_DI_ON          (0x07U) /* use P26 - P27 as digital input */
#define _06_ADPC_DI_ON          (0x06U) /* use P25 - P27 as digital input */
#define _05_ADPC_DI_ON          (0x05U) /* use P24 - P27 as digital input */
#define _04_ADPC_DI_ON          (0x04U) /* use P23 - P27 as digital input */
#define _03_ADPC_DI_ON          (0x03U) /* use P22 - P27 as digital input */
#define _02_ADPC_DI_ON          (0x02U) /* use P21 - P27 as digital input */
#define _01_ADPC_DI_ON          (0x01U) /* use P20 - P27 as digital input */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _FC_PM0_DEFAULT         (0xFCU) /* PM0 default value */
#define _F0_PM2_DEFAULT         (0xF0U) /* PM2 default value */
#define _FC_PM3_DEFAULT         (0xFCU) /* PM3 default value */
#define _FE_PM4_DEFAULT         (0xFEU) /* PM4 default value */
#define _FC_PM5_DEFAULT         (0xFCU) /* PM5 default value */
#define _F8_PM6_DEFAULT         (0xF8U) /* PM6 default value */
#define _FE_PM7_DEFAULT         (0xFEU) /* PM7 default value */
#define _FE_PM12_DEFAULT        (0xFEU) /* PM12 default value */
#define _7F_PM14_DEFAULT        (0x7FU) /* PM14 default value */
#define _FC_PMC0_DEFAULT        (0xFCU) /* PMC0 default value */
#define _FE_PMC12_DEFAULT       (0xFEU) /* PMC12 default value */
#define _7F_PMC14_DEFAULT       (0x7FU) /* PMC14 default value */

/*
    Interval timer control register (ITMC)
*/
/* Interval timer operation enable/disable specification (RINTE) */
#define _0000_IT_OPERATION_DISABLE    (0x0000U)    /* disable interval timer operation */
#define _8000_IT_OPERATION_ENABLE     (0x8000U)    /* enable interval timer operation */

/* Interval timer compare value (ITMCMP11 - 0) */
#define _02ED_ITMCMP_VALUE            (0x2EDU)

/*
    Timer Clock Select Register m (TPSm)
*/
/* Operating mode and clear mode selection (PRSm03 - PRSm00) */
#define _0000_TAU_CKM0_FCLK_0                   (0x0000U) /* ckm0 - fCLK */

/* Operating mode and clear mode selection (PRSm13 - PRSm10) */
#define _0000_TAU_CKM1_FCLK_0                   (0x0000U) /* ckm1 - fCLK */
#define _0020_TAU_CKM1_FCLK_2                   (0x0020U) /* ckm1 - fCLK/2^2 */

/* Operating mode and clear mode selection (PRSm21 - PRSm20) */
#define _0000_TAU_CKM2_FCLK_1                   (0x0000U) /* ckm2 - fCLK/2^1 */


/* Operating mode and clear mode selection (PRSm31 - PRSm30) */
#define _0000_TAU_CKM3_FCLK_8                   (0x0000U) /* ckm2 - fCLK/2^8 */

/* Selection of timer input used with channel 5 (TIS02 - TIS00) */
#define _04_TAU_CH5_INPUT_FIL                   (0x04U)   /* internal low speed oscillation colock (fIL) */
#define _05_TAU_CH5_INPUT_FSUB                  (0x05U)   /* sub colock (fSUB) */

/* Counter overflow status of channel n (OVF) */
#define _0000_TAU_OVERFLOW_NOT_OCCURS           (0x0000U) /* overflow does not occur */
#define _0001_TAU_OVERFLOW_OCCURS               (0x0001U) /* overflow occurs */
/*
    Timer Mode Register mn (TMRmn)
*/
/* Selection of macro clock (MCK) of channel n (CKSmn1 - CKSmn0) */
#define _0000_TAU_CLOCK_SELECT_CKM0             (0x0000U) /* operation clock CK0 set by PRS register */ 
#define _8000_TAU_CLOCK_SELECT_CKM1             (0x8000U) /* operation clock CK1 set by PRS register */

/* Selection of count clock (CCK) of channel n (CCSmn) */
#define _0000_TAU_CLOCK_MODE_CKS                (0x0000U) /* macro clock MCK specified by CKSmn bit */  
#define _1000_TAU_CLOCK_MODE_TIMN               (0x1000U) /* valid edge of input signal input from TImn pin */
/* Selection of slave/master of channel n (MASTERmn) */
#define _0000_TAU_COMBINATION_SLAVE             (0x0000U) /* operates as slave channel */
#define _0800_TAU_COMBINATION_MASTER            (0x0800U) /* operates as master channel */

/* Operation explanation of channel 1 or 3 (SPLIT) */
#define _0000_TAU_16BITS_MODE                   (0x0000U) /* operates as 16 bits timer */  

/* Setting of start trigger or capture trigger of channel n (STSmn2 - STSmn0) */
#define _0000_TAU_TRIGGER_SOFTWARE              (0x0000U) /* only software trigger start is valid */
#define _0100_TAU_TRIGGER_TIMN_VALID            (0x0100U) /* TImn input edge is used as a start/capture trigger */
#define _0200_TAU_TRIGGER_TIMN_BOTH             (0x0200U) /* TImn input edges are used as a start/capture trigger */
#define _0400_TAU_TRIGGER_MASTER_INT            (0x0400U) /* interrupt signal of the master channel is used */
/* Selection of TImn pin input valid edge (CISmn1 - CISmn0) */
#define _0000_TAU_TIMN_EDGE_FALLING             (0x0000U) /* falling edge */
#define _0040_TAU_TIMN_EDGE_RISING              (0x0040U) /* rising edge */
#define _0080_TAU_TIMN_EDGE_BOTH_LOW            (0x0080U) /* both edges (when low-level width is measured) */
#define _00C0_TAU_TIMN_EDGE_BOTH_HIGH           (0x00C0U) /* both edges (when high-level width is measured) */
/* Operation mode of channel n (MDmn3 - MDmn0) */
#define _0000_TAU_MODE_INTERVAL_TIMER           (0x0000U) /* interval timer mode */
#define _0004_TAU_MODE_CAPTURE                  (0x0004U) /* capture mode */

/* Setting of starting counting and interrupt (MDmn0) */
#define _0000_TAU_START_INT_UNUSED              (0x0000U) /* interrupt is not generated when counting is started */
#define _0001_TAU_START_INT_USED                (0x0001U) /* interrupt is generated when counting is started */


/*
    Timer Channel Start Register m (TSm)
*/
/* Operation enable (start) trigger of channel 0 (TSm0) */
#define _0000_TAU_CH0_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0001_TAU_CH0_START_TRG_ON              (0x0001U) /* operation is enabled (start trigger is generated) */

/* Operation enable (start) trigger of channel 1 (TSm1) */
#define _0000_TAU_CH1_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0002_TAU_CH1_START_TRG_ON              (0x0002U) /* operation is enabled (start trigger is generated) */

/* Operation enable (start) trigger of channel 5 (TSm5) */
#define _0000_TAU_CH5_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0020_TAU_CH5_START_TRG_ON              (0x0020U) /* operation is enabled (start trigger is generated) */

/* Operation enable (start) trigger of channel 6 (TSm6) */
#define _0000_TAU_CH6_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0040_TAU_CH6_START_TRG_ON              (0x0040U) /* operation is enabled (start trigger is generated) */


/*
    Timer Channel Stop Register m (TTm)
*/
/* Operation stop trigger of channel 0 (TTm0) */
#define _0000_TAU_CH0_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0001_TAU_CH0_STOP_TRG_ON               (0x0001U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 1 (TTm1) */
#define _0000_TAU_CH1_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0002_TAU_CH1_STOP_TRG_ON               (0x0002U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 2 (TTm2) */
#define _0000_TAU_CH2_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0004_TAU_CH2_STOP_TRG_ON               (0x0004U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 3 (TTm3) */
#define _0000_TAU_CH3_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0008_TAU_CH3_STOP_TRG_ON               (0x0008U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 4 (TTm4) */
#define _0000_TAU_CH4_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0010_TAU_CH4_STOP_TRG_ON               (0x0010U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 5 (TTm5) */
#define _0000_TAU_CH5_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0020_TAU_CH5_STOP_TRG_ON               (0x0020U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 6 (TTm6) */
#define _0000_TAU_CH6_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0040_TAU_CH6_STOP_TRG_ON               (0x0040U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 7 (TTm7) */
#define _0000_TAU_CH7_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0080_TAU_CH7_STOP_TRG_ON               (0x0080U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 1 higher 8 bits (TTHm1) */
#define _0000_TAU_CH1_H8_STOP_TRG_OFF           (0x0000U) /* no trigger operation */
#define _0200_TAU_CH1_H8_STOP_TRG_ON            (0x0200U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 3 higher 8 bits (TTHm3) */
#define _0000_TAU_CH3_H8_STOP_TRG_OFF           (0x0000U) /* no trigger operation */
#define _0800_TAU_CH3_H8_STOP_TRG_ON            (0x0800U) /* operation is stopped (stop trigger is generated) */

/*
    Timer Output Enable Register m (TOEm)
*/
/* Timer output enable/disable of channel 0 (TOEm0) */
#define _0001_TAU_CH0_OUTPUT_ENABLE             (0x0001U) /* the TOm0 operation enabled by count operation */
#define _0000_TAU_CH0_OUTPUT_DISABLE            (0x0000U) /* the TOm0 operation stopped by count operation */

/* Timer output enable/disable of channel 1 (TOEm1) */
#define _0002_TAU_CH1_OUTPUT_ENABLE             (0x0002U) /* the TOm1 operation enabled by count operation */
#define _0000_TAU_CH1_OUTPUT_DISABLE            (0x0000U) /* the TOm1 operation stopped by count operation */

/* Timer output enable/disable of channel 5 (TOEm5) */
#define _0020_TAU_CH5_OUTPUT_ENABLE             (0x0020U) /* the TOm5 operation enabled by count operation */
#define _0000_TAU_CH5_OUTPUT_DISABLE            (0x0000U) /* the TOm5 operation stopped by count operation */

/* Timer output enable/disable of channel 6 (TOEm6) */
#define _0040_TAU_CH6_OUTPUT_ENABLE             (0x0040U) /* the TOm6 operation enabled by count operation */
#define _0000_TAU_CH6_OUTPUT_DISABLE            (0x0000U) /* the TOm6 operation stopped by count operation */


/*
    Timer Output Register m (TOm)
*/
/* Timer output of channel 0 (TOm0) */
#define _0000_TAU_CH0_OUTPUT_VALUE_0            (0x0000U) /* timer output value is "0" */
#define _0001_TAU_CH0_OUTPUT_VALUE_1            (0x0001U) /* timer output value is "1" */

/* Timer output of channel 1 (TOm1) */
#define _0000_TAU_CH1_OUTPUT_VALUE_0            (0x0000U) /* timer output value is "0" */
#define _0002_TAU_CH1_OUTPUT_VALUE_1            (0x0002U) /* timer output value is "1" */

/* Timer output of channel 6 (TOm6) */
#define _0000_TAU_CH6_OUTPUT_VALUE_0            (0x0000U) /* timer output value is "0" */
#define _0040_TAU_CH6_OUTPUT_VALUE_1            (0x0040U) /* timer output value is "1" */

/*
    Timer Output Level Register 0 (TOLm)
*/

/* Control of timer output level of channel 1 (TOLm1) */
#define _0000_TAU_CH1_OUTPUT_LEVEL_H            (0x0000U) /* positive logic output (active-high) */
#define _0002_TAU_CH1_OUTPUT_LEVEL_L            (0x0002U) /* inverted output (active-low) */

/* Control of timer output level of channel 5 (TOLm5) */
#define _0000_TAU_CH5_OUTPUT_LEVEL_H            (0x0000U) /* positive logic output (active-high) */
#define _0020_TAU_CH5_OUTPUT_LEVEL_L            (0x0020U) /* inverted output (active-low) */


/* Control of timer output level of channel 6 (TOLm6) */
#define _0000_TAU_CH6_OUTPUT_LEVEL_H            (0x0000U) /* positive logic output (active-high) */
#define _0040_TAU_CH6_OUTPUT_LEVEL_L            (0x0040U) /* inverted output (active-low) */

/*
    Timer Output Mode Register m (TOMm)
*/

/* Control of timer output mode of channel 1 (TOMm1) */
#define _0000_TAU_CH1_OUTPUT_TOGGLE             (0x0000U) /* toggle operation mode */
#define _0002_TAU_CH1_OUTPUT_COMBIN             (0x0002U) /* combination operation mode */

/* Timer output of channel 5 (TOm5) */
#define _0000_TAU_CH5_OUTPUT_VALUE_0            (0x0000U) /* timer output value is "0" */
#define _0020_TAU_CH5_OUTPUT_VALUE_1            (0x0020U) /* timer output value is "1" */

/* Control of timer output mode of channel 5 (TOMm5) */
#define _0000_TAU_CH5_OUTPUT_TOGGLE             (0x0000U) /* toggle operation mode */
#define _0020_TAU_CH5_OUTPUT_COMBIN             (0x0020U) /* combination operation mode */


/* Control of timer output mode of channel 6 (TOMm6) */
#define _0000_TAU_CH6_OUTPUT_TOGGLE             (0x0000U) /* toggle operation mode */
#define _0040_TAU_CH6_OUTPUT_COMBIN             (0x0040U) /* combination operation mode */

/*
    Peripheral Enable Register 1 (PER1)
*/
/* Control of timer array unit input clock (WUTEN) */
#define _00_WUTM_CLOCK_STOP                     (0x00U)   /* stop supply of input clock */
#define _01_WUTM_CLOCK_SUPPLY                   (0x02U)   /* supply input clock */


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* 16-bit timer data register 00 (TDR00) */
#define _1F3F_TAU_TDR00_VALUE                   (0x1F3FU)
/* Clock divisor for TAU0 channel 0 */
#define _1_TAU0_CHANNEL0_DIVISOR                (1U)

/* 16-bit timer data register 01 (TDR01) */
#define _9C3F_TAU_TDR01_VALUE                   (0x9C3FU)
/* Clock divisor for TAU0 channel 1 */
#define _2_TAU0_CHANNEL1_DIVISOR                (2U)

/* 16-bit timer data register 06 (TDR06) */
#define _0000_TAU_TDR06_VALUE                   (0x0000U)
/* Clock divisor for TAU0 channel 6 */
#define TAU0_CHANNEL6_DIVISOR                   (1U)


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Operating mode and clear mode selection (PRSm03 - PRSm00) */
#define _0000_SAU_CK00_FCLK_0                    (0x0000U) /* ck00 - fCLK */

/* Operating mode and clear mode selection (PRSm13 - PRSm10) */
#define _0000_SAU_CK01_FCLK_0                    (0x0000U) /* ck01 - fCLK */


/*
    Serial Mode Register mn (SMRmn)
*/
#define _0020_SAU_SMRMN_INITIALVALUE             (0x0020U)
/* Selection of macro clock (MCK) of channel n (CKSmn) */
#define _0000_SAU_CLOCK_SELECT_CK00              (0x0000U) /* operation clock CK0 set by PRS register */ 
#define _8000_SAU_CLOCK_SELECT_CK01              (0x8000U) /* operation clock CK1 set by PRS register */
/* Selection of transfer clock (TCLK) of channel n (CCSmn) */
#define _0000_SAU_CLOCK_MODE_CKS                 (0x0000U) /* divided operation clock MCK specified by CKSmn bit */  
#define _4000_SAU_CLOCK_MODE_TI0N                (0x4000U) /* clock input from SCK pin (slave transfer in CSI mode) */
/* Selection of start trigger source (STSmn) */
#define _0000_SAU_TRIGGER_SOFTWARE               (0x0000U) /* only software trigger is valid */
#define _0100_SAU_TRIGGER_RXD                    (0x0100U) /* valid edge of RXD pin */
/* Controls inversion of level of receive data of channel n in UART mode (SISmn0) */
#define _0000_SAU_EDGE_FALL                      (0x0000U) /* falling edge is detected as the start bit */
#define _0040_SAU_EDGE_RISING                    (0x0040U) /* rising edge is detected as the start bit */
/* Setting of operation mode of channel n (MDmn2, MDmn1) */
#define _0000_SAU_MODE_CSI                       (0x0000U) /* CSI mode */
#define _0002_SAU_MODE_UART                      (0x0002U) /* UART mode */
#define _0004_SAU_MODE_IIC                       (0x0004U) /* simplified IIC mode */
/* Selection of interrupt source of channel n (MDmn0) */
#define _0000_SAU_TRANSFER_END                   (0x0000U) /* transfer end interrupt */
#define _0001_SAU_BUFFER_EMPTY                   (0x0001U) /* buffer empty interrupt */

/*
    Serial Communication Operation Setting Register mn (SCRmn)
*/
/* Setting of operation mode of channel n (TXEmn, RXEmn) */
#define _0000_SAU_NOT_COMMUNICATION              (0x0000U) /* does not start communication */
#define _4000_SAU_RECEPTION                      (0x4000U) /* reception only */
#define _8000_SAU_TRANSMISSION                   (0x8000U) /* transmission only */
#define _C000_SAU_RECEPTION_TRANSMISSION         (0xC000U) /* reception and transmission */
/* Selection of data and clock phase in CSI mode (DAPmn, CKPmn) */
#define _0000_SAU_TIMING_1                       (0x0000U) /* type 1 */
#define _1000_SAU_TIMING_2                       (0x1000U) /* type 2 */
#define _2000_SAU_TIMING_3                       (0x2000U) /* type 3 */
#define _3000_SAU_TIMING_4                       (0x3000U) /* type 4 */
/* Selection of masking of error interrupt signal (EOCmn) */
#define _0000_SAU_INTSRE_MASK                    (0x0000U) /* masks error interrupt INTSREx */
#define _0400_SAU_INTSRE_ENABLE                  (0x0400U) /* enables generation of error interrupt INTSREx */
/* Setting of parity bit in UART mode (PTCmn1 - PTCmn0) */
#define _0000_SAU_PARITY_NONE                    (0x0000U) /* none parity */
#define _0100_SAU_PARITY_ZERO                    (0x0100U) /* zero parity */
#define _0200_SAU_PARITY_EVEN                    (0x0200U) /* even parity */
#define _0300_SAU_PARITY_ODD                     (0x0300U) /* odd parity */
/* Selection of data transfer sequence in CSI and UART modes (DIRmn) */
#define _0000_SAU_MSB                            (0x0000U) /* MSB */
#define _0080_SAU_LSB                            (0x0080U) /* LSB */

/* Setting of data length in CSI and UART modes (DLSmn1 - DLSmn0) (m = 0, 1) */
#define _0005_SAU_LENGTH_9                       (0x0005U) /* 9-bit data length */
#define _0006_SAU_LENGTH_7                       (0x0006U) /* 7-bit data length */
#define _0007_SAU_LENGTH_8                       (0x0007U) /* 8-bit data length */

/*
    Serial Channel Start Register m (SSm)
*/
/* Operation start trigger of channel 0 (SSm0) */
#define _0000_SAU_CH0_START_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0001_SAU_CH0_START_TRG_ON               (0x0001U) /* sets SEm0 to 1 and enters the communication wait status */

/*
    Serial Channel Stop Register m (STm)
*/
/* Operation stop trigger of channel 0 (STm0) */
#define _0000_SAU_CH0_STOP_TRG_OFF               (0x0000U) /* no trigger operation */
#define _0001_SAU_CH0_STOP_TRG_ON                (0x0001U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 1 (STm1) */
#define _0000_SAU_CH1_STOP_TRG_OFF               (0x0000U) /* no trigger operation */
#define _0002_SAU_CH1_STOP_TRG_ON                (0x0002U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 2 (STm2) */
#define _0000_SAU_CH2_STOP_TRG_OFF               (0x0000U) /* no trigger operation */
#define _0004_SAU_CH2_STOP_TRG_ON                (0x0004U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 3 (STm3) */
#define _0000_SAU_CH3_STOP_TRG_OFF               (0x0000U) /* no trigger operation */
#define _0008_SAU_CH3_STOP_TRG_ON                (0x0008U) /* operation is stopped (stop trigger is generated) */

/*
    Format of Serial Flag Clear Trigger Register mn (SIRmn)
*/
/* Clear trigger of overrun error flag of channel n (OVCTmn) */
#define _0001_SAU_SIRMN_OVCTMN                   (0x0001U)
/* Clear trigger of parity error flag of channel n (PECTmn) */
#define _0002_SAU_SIRMN_PECTMN                   (0x0002U)
/* Clear trigger of framing error of channel n (FECTMN) */
#define _0004_SAU_SIRMN_FECTMN                   (0x0004U)

/*
    Serial Output Enable Register m (SOEm)
*/
/* Serial output enable/disable of channel 0 (SOEm0) */
#define _0001_SAU_CH0_OUTPUT_ENABLE              (byte)(0x0001U) /* stops output by serial communication operation */
#define _0000_SAU_CH0_OUTPUT_DISABLE             (0x0000U) /* enables output by serial communication operation */
/* Serial output enable/disable of channel 1 (SOEm1) */
#define _0002_SAU_CH1_OUTPUT_ENABLE              (0x0002U) /* stops output by serial communication operation */
#define _0000_SAU_CH1_OUTPUT_DISABLE             (0x0000U) /* enables output by serial communication operation */
/* Serial output enable/disable of channel 2 (SOEm2) */
#define _0004_SAU_CH2_OUTPUT_ENABLE              (0x0004U) /* stops output by serial communication operation */
#define _0000_SAU_CH2_OUTPUT_DISABLE             (0x0000U) /* enables output by serial communication operation */


/*
    Serial Output Register m (SOm)
*/
/* Serial data output of channel 0 (SOm0) */
#define _0000_SAU_CH0_DATA_OUTPUT_0              (0x0000U) /* Serial data output value is "0" */
#define _0001_SAU_CH0_DATA_OUTPUT_1              (0x0001U) /* Serial data output value is "1" */

/* Serial clock output of channel 0 (CKOm0) */
#define _0000_SAU_CH0_CLOCK_OUTPUT_0             (0x0000U) /* Serial clock output value is "0" */
#define _0100_SAU_CH0_CLOCK_OUTPUT_1             (0x0100U) /* Serial clock output value is "1" */


/*
    UARTFn control register 0 (UFnCTL0)
*/
#define _10_UARTF_UFNCTL0_INITIALVALUE           (0x10U)
/* Transmission operation enable (UFnTXE) */
#define _00_UARTF_TRANSMISSION_DISABLE           (0x00U)   /* disable transmission operation */
#define _40_UARTF_TRANSMISSION_ENABLE            (0x40U)   /* enable transmission operation */
/* Reception operation enable (UFnRXE) */
#define _00_UARTF_RECEPTION_DISABLE              (0x00U)   /* disable reception operation */
#define _20_UARTF_RECEPTION_ENABLE               (0x20U)   /* enable reception operation */
/* Transfer direction selection (UFnDIR) */
#define _00_UARTF_TRANSFDIR_MSB                  (0x00U)   /* MSB-first transfer */
#define _10_UARTF_TRANSFDIR_LSB                  (0x10U)   /* LSB-first transfer */
/* Parity selection during transmission/reception (UFnPS1, UFnPS0) */
#define _00_UARTF_PARITY_NONE                    (0x00U)   /* no parity */
#define _04_UARTF_PARITY_ZREO                    (0x04U)   /* 0 parity */
#define _08_UARTF_PARITY_ODD                     (0x08U)   /* odd parity */
#define _0C_UARTF_PARITY_EVEN                    (0x0CU)   /* even parity */
/* Specification of data character length of 1 frame of transmit/receive data (UFnCL) */
#define _00_UARTF_DATALENGTH_7BIT                (0x00U)   /* 7 bits */
#define _02_UARTF_DATALENGTH_8BIT                (0x02U)   /* 8 bits */
/* Specification of length of stop bit for transmit data (UFnSL) */
#define _00_UARTF_STOPLENGTH_1BIT                (0x00U)   /* 1 bit */
#define _01_UARTF_STOPLENGTH_2BIT                (0x01U)   /* 2 bits */

/*
    UARTFn control register (UFnCTL1)
*/
/* Prescaler clock frequency division value (UFnPRS2 - UFnPRS0)*/
#define _0000_UARTF_BASECLK_1                    (0x0000U) /* fXX */
#define _2000_UARTF_BASECLK_2                    (0x2000U) /* fXX/2^1 */


/*
    UARTFn option control register 0 (UFnOPT0)
*/
#define _14_UARTF_UFNOPT0_INITIALVALUE           (0x14U)
/* Transmit data level bit (UFnTDL) */
#define _00_UARTF_TRAN_DATALEVEL_NORMAL          (0x00U)   /* normal output of transfer data */
#define _02_UARTF_TRAN_DATALEVEL_INVERTED        (0x02U)   /* inverted output of transfer data */
/* Receive data level bit (UFnRDL) */
#define _00_UARTF_REC_DATALEVEL_NORMAL           (0x00U)   /* normal input of transfer data */
#define _01_UARTF_REC_DATALEVEL_INVERTED         (0x01U)   /* inverted input of transfer data */

/*
    UARTFn option control register 1 (UFnOPT1)
*/
/* Transmit data expansion bit enable bit (UFnEBE) */
#define _00_UARTF_EXPANSIONBIT_UNUSE             (0x00U)   /* disable expansion bit */
#define _80_UARTF_EXPANSIONBIT_USE               (0x80U)   /* enable expansion bit */

/* Communication mode (UFnMD1, UFnMD0) */
#define _00_UARTF_NORMAL_MODE                    (0x00U)   /* normal mode */
#define _00_UARTF_AUTOMATIC_BAUD_MODE            (0x06U)   /* Automatic baud rate mode */

/*
    UARTFn option control register 2 (UFnOPT2)
*/
/* Bit to select use of receive data noise filter (UFnRXFL) */
#define _00_UARTF_DATA_NOISE_FILTER_USED         (0x00U)   /* enables noise filter */
#define _02_UARTF_DATA_NOISE_FILTER_UNUSED       (0x02U)   /* disables noise filter */
/* Transmission interrupt (INTLTn) generation timing select bit (UFnITS) */
#define _00_UARTF_LT_INT_GENTIME_0               (0x00U)   /* output INTTn upon transmit completion */
#define _01_UARTF_LT_INT_GENTIME_1               (0x01U)   /* output INTTn upon transmit start */

/* Buffer address */
#define UARTF0_BUFFER_ADDRESSS                   (0x052FU) /* UARTF0 transmit buffer address in buffer mode */

#define _02_INTP1_EDGE_FALLING_SEL      (0x02U) /* falling edge selected for INTP1 pin */

/*
    AD converter mode register 0 (ADM0)
*/
#define _00_AD_ADM0_INITIALVALUE        (0x00U)

/* Specification of AD conversion operation mode (ADMD) */
#define _00_AD_OPERMODE_SELECT          (0x00U) /* select operation mode */
#define _40_AD_OPERMODE_SCAN            (0x40U) /* scan operation mode */
/* AD conversion clock selection (FR2 - FR0) */
#define _00_AD_CONVERSION_CLOCK_64      (0x00U) /* fCLK/64 */
#define _08_AD_CONVERSION_CLOCK_32      (0x08U) /* fCLK/32 */
#define _10_AD_CONVERSION_CLOCK_16      (0x10U) /* fCLK/16 */
#define _18_AD_CONVERSION_CLOCK_8       (0x18U) /* fCLK/8 */

/* Specification AD conversion time mode (LV1, LV0) */
#define _00_AD_TIME_MODE_NORMAL_1       (0x00U) /* normal 1 mode */
#define _02_AD_TIME_MODE_NORMAL_2       (0x02U) /* normal 2 mode */
#define _04_AD_TIME_MODE_LOWVOLTAGE_1   (0x04U) /* low-voltage 1 mode */
#define _06_AD_TIME_MODE_LOWVOLTAGE_2   (0x06U) /* low-voltage 2 mode */


/*
    Analog input channel specification register (ADS)
*/
/* Specification of analog input channel (ADISS, ADS4 - ADS0) */
/* Select mode */
#define _00_AD_INPUT_CHANNEL_0          (0x00U) /* ANI0 */
#define _01_AD_INPUT_CHANNEL_1          (0x01U) /* ANI1 */
#define _02_AD_INPUT_CHANNEL_2          (0x02U) /* ANI2 */


/*
    AD converter mode register 1 (ADM1)
*/
/* AD trigger mode selection (ADTMD1, ADTMD0) */
#define _00_AD_TRIGGER_SOFTWARE         (0x00U) /* software trigger mode */
#define _80_AD_TRIGGER_HARDWARE_NOWAIT  (0x80U) /* hardware trigger mode (no wait) */
#define _C0_AD_TRIGGER_HARDWARE_WAIT    (0xC0U) /* hardware trigger mode (wait) */
/* AD convertion mode selection (ADSCM) */
#define _00_AD_CONVMODE_CONSELECT       (0x00U) /* continuous convertion mode */
#define _20_AD_CONVMODE_ONESELECT       (0x20U) /* oneshot convertion mode */


/*
    AD converter mode register 2 (ADM2)
*/
/* AD VREF(+) selection (ADREFP1, ADREFP0) */
#define _00_AD_POSITIVE_VDD             (0x00U) /* use VDD as VREF(+) */
#define _40_AD_POSITIVE_AVREFP          (0x40U) /* use AVREFP as VREF(+) */
#define _80_AD_POSITIVE_INTERVOLT       (0x80U) /* use internal voltage as VREF(+) */
/* AD VREF(-) selection (ADREFM) */
#define _00_AD_NEGATIVE_VSS             (0x00U) /* use VSS as VREF(-) */
#define _20_AD_NEGATIVE_AVREFM          (0x20U) /* use AVREFM as VREF(-) */
/* AD conversion result upper/lower bound value selection (ADRCK) */
#define _00_AD_AREA_MODE_1              (0x00U) /* generates INTAD when ADLL <= ADCRH <= ADUL */
#define _08_AD_AREA_MODE_2_3            (0x08U) /* generates INTAD when ADUL < ADCRH or ADLL > ADCRH */
/* AD wakeup function selection (AWC) */
#define _00_AD_WAKEUP_OFF               (0x00U) /* stop wakeup function */
#define _04_AD_WAKEUP_ON                (0x04U) /* use wakeup function */
/* AD resolution selection (ADTYP) */
#define _00_AD_RESOLUTION_10BIT         (0x00U) /* 10 bits */
#define _01_AD_RESOLUTION_8BIT          (0x01U) /* 8 bits */


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Upper bound (ADUL) value */
#define _FF_AD_ADUL_VALUE               (0xFFU)
/* Lower bound (ADLL) value */
#define _00_AD_ADLL_VALUE               (0x00U)
   
/*VCO_237 Supplyvoltage should not be monitored on no rain variants*/
/*is rain function enabled?*/
#ifndef _NO_RAIN_

#define AD_ADUL_VALUE               (0x61U)

#else /*on no rain variants, the supply should not be monitored*/

#define AD_ADUL_VALUE               (0x0U)

#endif/*_NO_RAIN_*/
   
#define _FE_AD_ADLL_VALUE               (0xFEU)
/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Selection of 16-bit counter output clock (UF0BRS7 - UF0BRS0) */
#define _01A1_UARTF0_K_VALUE                     (0x01A1U)
/* High-speed system clock pin operation mode (EXCLK, OSCSEL) */
#define _C0_CGC_HISYS_PIN           (0xC0U)
#define _00_CGC_HISYS_PORT          (0x00U) /* X1, X2 as I/O port */

/* Control of X1 high-speed system clock oscillation frequency (AMPH) */
#define _00_CGC_SYSOSC_DEFAULT      (0x00U)

/*
    System clock control register (CKC)
*/
/* Status of CPU/peripheral hardware clock fCLK (CLS) */
#define _00_CGC_CPUCLK_MAIN         (0x00U) /* main system clock (fMAIN) */
#define _80_CGC_CPUCLK_SUB          (0x80U) /* subsystem clock (fSUB) */
/* Selection of CPU/peripheral hardware clock fCLK (CSS) */
#define _00_CGC_CPUCLK_SELMAIN      (0x00U) /* main system clock (fMAIN) */
#define _40_CGC_CPUCLK_SELSUB       (0x40U) /* subsystem clock (fSUB) */
/* Status of Main system clock fMAIN (MCS) */
#define _00_CGC_MAINCLK_HIO         (0x00U) /* high-speed OCO clock (fIH) */
#define _20_CGC_MAINCLK_HISYS       (0x20U) /* high-speed system clock (fMX) */


/*
    Operation speed mode control register (OSMC)
*/
/* Setting in subsystem clock HALT mode (RTCLPC) */
#define _00_CGC_SUBINHALT_ON        (0x00U) /* enables supply of subsystem clock to peripheral functions */
#define _80_CGC_SUBINHALT_OFF       (0x80U) /* stops supply to peripheral functions other than RTC and interval timer */
/* RTC macro operation clock (WUTMMCK0) */
#define _00_CGC_RTC_CLK_FSUB        (0x00U) /* use fSUB clock */
#define _10_CGC_RTC_CLK_FIL         (0x10U) /* use fIL clcok */

/*
    CRC control register (CRC0CTL)
*/
/* CRC calculation operation (CRC0EN) */
#define _00_CGC_CRC_OPERATION_OFF   (0x00U) /* stops operation */
#define _80_CGC_CRC_OPERATION_ON    (0x80U) /* CRC calculation is performed after enter HALT mode */
/* CRC calculation range (FEA5 - FEA0) */
#define _00_CGC_CRC_AREA0           (0x00U) /* 0 - 3FFBH (16K - 4byte) */
#define _01_CGC_CRC_AREA1           (0x01U) /* 0 - 7FFBH (32K - 4byte) */
#define _02_CGC_CRC_AREA2           (0x02U) /* 0 - BFFBH (48K - 4byte) */
#define _03_CGC_CRC_AREA3           (0x03U) /* 0 - FFFBH (64K - 4byte) */

/*
    Illegal memory access detection control register (IAWCTL)
*/
/* Illegal memory access detection control (IAWEN) */
#define _00_CGC_ILLEGAL_ACCESS_OFF  (0x00U) /* disables illegal memory access detection */
#define _80_CGC_ILLEGAL_ACCESS_ON   (0x80U) /* enables illegal memory access detection */
/* RAM guard area (GRAM1, GRAM0) */
#define _00_CGC_RAM_GUARD_OFF       (0x00U) /* invalid, it is possible to write RAM */
#define _10_CGC_RAM_GUARD_ARAE0     (0x10U) /* 128 bytes from RAM bottom address */
#define _20_CGC_RAM_GUARD_ARAE1     (0x20U) /* 256 bytes from RAM bottom address */
#define _30_CGC_RAM_GUARD_ARAE2     (0x30U) /* 512 bytes from RAM bottom address */
/* PORT register guard (GPORT) */
#define _00_CGC_PORT_GUARD_OFF      (0x00U) /* invalid, it is possible to write PORT register */
#define _04_CGC_PORT_GUARD_ON       (0x04U) /* valid, it is impossible to write PORT register, but possible for read */
/* Interrupt register guard (GINT) */
#define _00_CGC_INT_GUARD_OFF       (0x00U) /* invalid, it is possible to write interrupt register */
#define _02_CGC_INT_GUARD_ON        (0x02U) /* valid, it is impossible to write , but possible for read */
/* CSC register guard (GCSC) */
#define _00_CGC_CSC_GUARD_OFF       (0x00U) /* invalid, it is possible to write CSC register */
#define _01_CGC_CSC_GUARD_ON        (0x01U) /* valid, it is impossible to write CSC register, but possible for read */
/*-----------------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _1000_CSI00_DIVISOR                      (0x1000U)


/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

extern void     R_CSI00_Start(void);
extern void     R_TAU0_Channel0_Start(void);
extern void     R_TAU0_Channel0_Stop(void);
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_
extern void     R_IT_Start(void);
extern void     R_IT_Stop(void);
#endif /*_NO_RAIN_*/
extern void     R_TAU0_Channel5_Start(void);
extern void     R_TAU0_Channel5_Stop(void);
extern void     R_UARTF0_Start(void);
extern void     R_INTC0_Start(void);
extern void     sci_init_boot(void);
extern void     R_TAU0_Channel6_Start(void);
extern void     R_TAU0_Channel6_Stop(void);
extern void     R_ADC_Start(void);
extern void     R_ADC_Stop(void);
extern void     Peripheral_Init(void);
#endif