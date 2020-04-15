/******************************************************************************/
/*                                                                            */
/*   Valeo Schalter und Sensoren GmbH                                         */
/*   Stuttgarter Str. 119                                                     */
/*   74321 Bietigheim-Bissingen                                               */
/*                                                                            */
/*   All rights reserved. Distribution or duplication without previous        */
/*   written agreement of the owner prohibited.                               */
/*                                                                            */
/******************************************************************************/
/*   Source: D:/ldws/software/ecu/eeprom.h  */
/*   Revision:   1.5   */
/*   Author:   SBA272   */
/*   Date:   Apr 13 2004 13:51:52   */
/******************************************************************************/
/*   MODULE:                                                                  */
/*   FILE:                                                                    */
/******************************************************************************/
/*                                                                            */
/******************************************************************************/
#ifndef I_I2CDEBUG_H
#define I_I2CDEBUG_H
#ifdef _i2cdebug_c_
#define EXTERN /**/
#else
#define EXTERN  extern
#endif
/******************************************************************************/


EXTERN byte rb_I2CDebugTimeout_g; /* VDR_800 */
extern word rw_StartupWipeCommandTimOut_mg;
EXTERN void I2CDbg_Init(void);


/******************************************************************************/

#define cb_I2CSLAVEADDRESS_g        0xC0


/******************************************************************************/
#undef EXTERN
#endif /* I_FLASHE2_H */
/******************************************************************************/
/* END Source: D:/ldws/software/ecu/eeprom.h  */
/******************************************************************************/
