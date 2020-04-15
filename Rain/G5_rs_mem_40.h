#ifndef G5_RS_MEM_40_H
#define G5_RS_MEM_40_H

/******************************************************************************
*******************************************************************************
**
** Funktion:   Mem_40()
**
**
** Bearbeiter: Bernd Schmid Abt. TKW
** Datum:      25.03.98
** geaendert:  21.04.98
**
** Funktion:   Laden und Entladen der Speicher in Abhaengigkeit von der
**             Schwelle und der aufintegrierten Signallaenge.
**             (rub_Sig_Ok_Count)
**
**             Intervallspeicher: Speicher mit langen Lade-und Entladezeiten
**                                stark integrierendes Verhalten
**                                Verantworlich fuer den harmonischen Betrieb
**
**             Overridespeicher:  Speicher mit kurzen Lade-und Entladezeiten
**                                Verantworlich fuer kurze Anspruchzeiten
**
**             Mit Hilfe des Zaehlers fuer gueltige Signale "rub_Sig_Ok_Count"
**             koennen Signalaenderungen zwischen den 40ms Task Aufrufen
**             nachgearbeitet werden.
**             Der Zaehler wird in der Routine "Signal()" bearbeitet und wird
**             nach der Auswertung, in mem_40() geloescht.
**
**
*******************************************************************************
******************************************************************************/
/*
Changes on Nov. 09, 2001
- order of includes changed
*/

// Defines for rainsensor-constants




#endif