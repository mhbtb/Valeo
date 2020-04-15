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
 * Template of header file for LIN configuration
 * used with RLT-DIagnose.exe
 *
 * 
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> template_linconf.h                  </td></tr>
 * <tr> <td> Revision: </td> <td> 1.0                  </td></tr>
 * <tr> <td> Status:   </td> <td> STORED                  </td></tr>
 * <tr> <td> Author:   </td> <td> Jochen Schenk, VDS-E-PUS  </td></tr>
 * <tr> <td> Date:     </td> <td> 07-APR-2014 07:47:15                 </td></tr>
 * </table>
 * 
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> RLS_LIN     </td></tr>
 * <tr> <td> SCOPE:     </td> <td> Public      </td></tr>
 * <tr> <td> TARGET:    </td> <td> NEC         </td></tr>
 * </table>
 */

#ifndef I_LINCONF_H
#define I_LINCONF_H

/******************************************************************************/
/*                         Defines for LIN Configuration                      */
/******************************************************************************/

#define LINBAUDRATE                   19200
#define LIN20CHECKSUM
#define NODECONFIGURATION
#define TFRAMEMAX_with_TIMER
#undef  BUS_IDLE_DETECTION_ENABLED

#define kLinProtocolMainVersion       2
#define kLinProtocolSubVersion        0

#define kLinNumberOfConfFlags         7
#define kLinNumberOfIndFlags          2

#define kLinNumberOfTxObjects         7
#define kLinNumberOfRxObjects         2
#define kLinNumberOfObjects           9



/* 8X ------------- Move this part to diagnose_xxx.h -------------------------*/

/******************************************************************************/
/*                         Defines for node configuration                     */
/******************************************************************************/

//#define cw_SupplierID_g               0x0000U
#define cw_FunctionID_g               0x0000U
#define cb_VARIANTE_g                 0x00

#define CB_DIAG_DEF_NAD               0x5B

/* 8X ------------------------------------------------------------------------*/


#endif  /* I_LINCONF_H */
