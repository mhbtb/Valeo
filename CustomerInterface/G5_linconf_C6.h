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
/*   $Source: D:/ldws/software/ecu/linconf.h $ */
/*   $Revision:   1.7  $ */
/*   $Author:   SBA272  $ */
/*   $Date:   Sep 08 2003 10:58:24  $ */
/******************************************************************************/
/*   MODULE:                                                                  */
/*   FILE:                                                                    */
/******************************************************************************/
/*                                                                            */
/******************************************************************************/
#ifndef I_LINCONF_H
#define I_LINCONF_H
/******************************************************************************/
#define NODECONFIGURATION
// ------------------ defines for C6 Protocol --------------

#define LINBAUDRATE  19200
#undef LIN20CHECKSUM
//#define LIN20CHECKSUM
#define TFRAMEMAX_with_TIMER
#undef BUS_IDLE_DETECTION_ENABLED

#define kLinProtocolMainVersion 1
#define kLinProtocolSubVersion 2
#define kLinNumberOfConfFlags 3
#define kLinNumberOfIndFlags  3

#define kLinNumberOfTxObjects  3
#define kLinNumberOfRxObjects  3
#define kLinNumberOfNoObjects  0
#define kLinNumberOfObjects  6


#endif // I_LINCONF_H

/******************************************************************************/
/* END $Source: D:/ldws/software/ecu/linconf.h $ */
/******************************************************************************/
