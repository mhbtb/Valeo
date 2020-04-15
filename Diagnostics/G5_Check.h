#ifndef G5_CHECK_H
#define G5_CHECK_H

/* PRQA S 0759 EOF */ /* << union is sopported by this compiler>>*/
/* 22.03.11  VDR_638   AL   MISRA OPTIMISATION with corrections in Source code */
#ifndef _main_
#define _main_
#endif

#ifdef _check_c_
/* PRQA S 0883 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#define EXTERN /**/
#else
#define EXTERN  extern
#endif
/* 27.05.19  VCO_051     AL   Use _Callt functions to speed up initialisation*/
/* 26.05.10  VCO_055     AL      reomve debouncing of RAM and ROM error*/

/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/

extern const unsigned int __far chksum0000_00C4;
#define CW_CHKSUM0000_00C4_START 0x0000U
#define CW_CHKSUM0000_00C4_END   0x00C4U

extern const unsigned int __far chksum2000_5FFF;
extern const unsigned int __far chksum_mirror2000_5FFF;
#define CW_chksum2000_5FFF_START 0x2000U
#define CW_chksum2000_5FFF_END   0x5FFFU /*RLS_VCO_62 and RLS_VCO_90 adapt checksum range*/

extern const unsigned int __far chksum6000_EFFF;
extern const unsigned int __far chksum_mirror6000_EFFF;
#define CW_chksum6000_EFFF_START 0x6000U
#define CW_chksum6000_EFFF_END   0xEFFFU //0xEFFFU /*VCO_024 Interval table adapt link file has to be adapted*/


/** Global Functions **/


EXTERN word rw_RAM_DefectCell_g;

EXTERN Flag uF_Diagnose_pre_Flag;
#define bi_RAM_CHECK_FAILURE_g (uF_Diagnose_pre_Flag.Bit.B0)
#define bi_ROM_CHECK_FAILURE_g (uF_Diagnose_pre_Flag.Bit.B1)

#define bi_FIRST_RAM_CHECK_DONE_g     (uF_Diagnose_pre_Flag.Bit.B5)
#define bi_First_ROM_CHECK_Done_g     (uF_Diagnose_pre_Flag.Bit.B6)


EXTERN word rw_CRC16_g;

EXTERN __callt void check_crc16(void); /*VCO_051*/
EXTERN __callt void CheckRAM(void);  /*VCO_051*/

/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN

#endif