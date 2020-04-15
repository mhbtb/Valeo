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

/*12.05.16   VCO_325     NB      FCA:Integration VCO to merge the changes from Audi 002 baseline to FCA 004 baseline*/

#ifndef I_LINCONF_H
#define I_LINCONF_H

/******************************************************************************/
/*                         Defines for LIN Configuration                      */
/******************************************************************************/

#define LINBAUDRATE  19200
#define LIN20CHECKSUM
#define NODECONFIGURATION
#define _SUPPORTASSIGNNAD_


#define kLinProtocolMainVersion       2
#define kLinProtocolSubVersion        0

#define kLinNumberOfConfFlags         7
#define kLinNumberOfIndFlags          4

#define kLinNumberOfTxObjects         7
#define kLinNumberOfRxObjects         4
#define kLinNumberOfObjects           11





/******************************************************************************/
/* END Source:   */
/******************************************************************************/

//#define cw_SupplierID_g               0x0000U
//#define cw_FunctionID_g               0x0000U
//#define cb_VARIANTE_g                 0x00
//
//#define CB_DIAG_DEF_NAD               0x09

/* 8X ------------------------------------------------------------------------*/


#endif  /* I_LINCONF_H */
