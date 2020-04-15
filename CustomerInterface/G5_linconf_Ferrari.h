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
/*   Source: D:/ldws/software/ecu/linconf.h  */
/*   Revision:   1.7   */
/*   Author:   SBA272   */
/*   Date:   Sep 08 2003 10:58:24   */
/******************************************************************************/
/*   MODULE:                                                                  */
/*   FILE:                                                                    */
/******************************************************************************/
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Author   Description                                       */
/*-DD.MM.YY-------------------------------------------------------------------*/

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


#define kLinProtocolMainVersion 2
#define kLinProtocolSubVersion 0

#define kLinNumberOfConfFlags         9
#define kLinNumberOfIndFlags          3

#define kLinNumberOfTxObjects         9
#define kLinNumberOfRxObjects         3
#define kLinNumberOfObjects           12



#endif // I_LINCONF_H

/******************************************************************************/
/* END Source:   */
/******************************************************************************/
