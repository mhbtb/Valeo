#ifndef G5_CHECK_SR_H
#define G5_CHECK_SR_H
/*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 27.05.19  VCO_051    AL      Use _Callt functions to speed up initialisation*/
/* 26.05.10  VCO_055    AL      remove debouncing of RAM and ROM error*/
/* 22.03.11  VDR_638    AL      MISRA OPTIMISATION with corrections in Source code */
/* 19.09.2014 VCO_184   NB      Checksum for calibration data */
/* 29.09.2014 VCO_154   MP      Safety:SM139,SM140:Implement RS_Error_Aktiv,LS_Error_Aktiv flag  to*/
/*******************************check after Reset if a error was active before the sensor goes to sleep or reset */
/* 08.12.2014 VCO_151   NB      Implement IC test */
/* 25.02.2015 VCO_225   MP      RS functionality detection - error when not available*/
/*03.03.15   VCO_227    NB     Implement RAM Guard function */
/* 10.03.15    VCO_227    NB     Implement RAM Guard function */
/* 02.12.15    VDR_938    NB     Exclude RAM test for the area used by selfprogramming library */
/* 03.12.15    VDR_938    NB     Exclude RAM test for the area used by selfprogramming library */
/* PRQA S 0759 EOF */ /* << union is sopported by this compiler>>*/

#ifndef _main_
#define _main_
#endif

#ifdef _check_c_
/* PRQA S 0883 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#define EXTERN /**/
#else
#define EXTERN  extern
#endif

#define cb_LOWER_RAM_BOARDER_s  0xFF30AU
#define cb_UPPER_RAM_BOARDER_s  0xFFE1FU

/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
#define cb_RAM_GUARD_START_g  0xFF000U
#define cb_RAM_GUARD_LENGTH_g  256

extern const unsigned int __far chksum2000_FEEF;
extern const unsigned int __far chksum_mirror2000_FEEF;
#define CW_chksum2000_FEEF_START 0x2000U
#define CW_chksum2000_FEEF_END   0xFEEFU 

/** Global Functions **/


EXTERN word rw_RAM_DefectCell_g;

EXTERN Flag uF_Diagnose_pre_Flag;
#define bi_RAM_CHECK_FAILURE_g          (uF_Diagnose_pre_Flag.Bit.B0)
#define bi_ROM_CHECK_FAILURE_g          (uF_Diagnose_pre_Flag.Bit.B1)
#define bi_CALIB_CHECK_FAILURE_g        (uF_Diagnose_pre_Flag.Bit.B2)
/*VCO_225 RS functionality detection - error when not available*/
#define bi_RS_VariantError_g            (uF_Diagnose_pre_Flag.Bit.B3)
#define bi_RAM_GUARD_Error_g            (uF_Diagnose_pre_Flag.Bit.B4)             /* RAM GUARD error */
#define bi_FIRST_RAM_CHECK_DONE_g       (uF_Diagnose_pre_Flag.Bit.B5)
#define bi_First_ROM_CHECK_Done_g       (uF_Diagnose_pre_Flag.Bit.B6)
#define bi_First_CALIB_CHECK_Done_g     (uF_Diagnose_pre_Flag.Bit.B7)

EXTERN word rw_CRC16_g;
EXTERN byte rb_ReadActiveErrors_g;


EXTERN  void check_crc16_calib(void); 
EXTERN __callt void check_crc16(void); /*VCO_051*/
EXTERN __callt void CheckRAM(void);  /*VCO_051*/


EXTERN void RamGuard_init(void);
EXTERN void RamGuardTest(void);
EXTERN __callt void DisableRamGuard(void);
EXTERN __callt void EnableRamGuard(void);
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN

#endif