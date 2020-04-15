/******************************************************************************
*******************************************************************************
*******************************************************************************
**
**
** Datei:      G5_rs_prog.c
**
** Bearbeiter: Bernd Schmid
**             Abt. WRS
**
**
** Datum:      17.06.98
** geaendert:  23.05.00
**
** Funktion:   Datei beinhaltet die einzelnen Regensensorfunktion.
**
**
**
*******************************************************************************
*******************************************************************************
******************************************************************************/
/*******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*-DD.MM.YY-------------------------------------------------------------------*/
/* 13.01.10  VDR_373   FS   QAC checked and analyzed*/
/******************************************************************************/
/*
Aenderung am 091101:
- Preprocessor-switches moved to "G5_rs_def.h"
- G5_rs_def.h-include deleted

Aenderungen am 260201:
Fuer x400 zwei neue Variablen eingefuehrt!
Weitere Aenderungen in rs_intber.c

Aenderungen am 19.02.01
Fehler mit Ansammlungszeit behoben:
- Umschalten auf Ansammlungszeit ist nur einmal pro Wischzyklus moeglich
- Ansammlungsbetrieb wird abgeschaltet, sobald die Schwelle zum ersten Mal ueberschritten wurde

 Aenderungen am 28.03.00
- Bei Stufe 2 Auswertung Abfrage des Overridespeichers verworfen

- //Abfrage, ob min. Pausenzeit bei letzter Wischung eingehalten wird
  Block um eine Ebene nach unten verschoben (keine Auswirkung auf Funktion)

- ueberpruefen, ob wiklich rbi_tropfenmerker abgefragt werden soll

  //void IntBer(void)
   {

   if (rbi_Tropfen_Merker==1)
   ...
   }


*/

#ifndef _RS_PROG_H_ /*QAC*/
#define _RS_PROG_H_ /*QAC*/

// externe Declaration der Variablen, die vom Steuergeraet deklariert werden
//
// ITT Schnittstellenvariablen werden als extern bekannt gemacht
//#include "G5_rs_lib.h"


// In "RS_Task.c" definierte Variablen werden hier als externe Variablen bekannt gemacht
//

#endif /*QAC*/
