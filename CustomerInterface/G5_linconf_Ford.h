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
 * <tr> <td> Source:   </td> <td> G5_linconf.h                  </td></tr>
 * <tr> <td> Revision: </td> <td> 1.4                  </td></tr>
 * <tr> <td> Status:   </td> <td> ACCEPTED                  </td></tr>
 * <tr> <td> Author:   </td> <td> Jochen Schenk, VDS-E-PUS  </td></tr>
 * <tr> <td> Date:     </td> <td> 30-SEP-2013 11:42:30                 </td></tr>
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
#define NODECONFIGURATION

#define kLinProtocolMainVersion       2
#define kLinProtocolSubVersion        0

#define kLinNumberOfConfFlags         8
#define kLinNumberOfIndFlags          4

#define kLinNumberOfTxObjects         8
#define kLinNumberOfRxObjects         4
#define kLinNumberOfObjects           12



/* 8X ------------- Move this part to diagnose_xxx.h -------------------------*/

/******************************************************************************/
/*                         Defines for node configuration                     */
/******************************************************************************/



#define CB_DIAG_DEF_NAD               0x02

/* 8X ------------------------------------------------------------------------*/


#endif  /* I_LINCONF_H */
