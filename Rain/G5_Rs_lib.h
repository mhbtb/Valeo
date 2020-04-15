/******************************************************************************
*******************************************************************************
*******************************************************************************
**
** Datei:      RS_lib.h
**
**
** Bearbeiter: Bernd Schmid Abt. TKW
**
** Datum:      04.03.98
** geaendert:  25.06.98
**
** Inhalt:     Deklaration der Schnittstellenvariablen
**             und Funktionsprototypen.
**
**             Der Herstller des Steuergeraet muss dieses Header-File
**             zusaetzlich zur Regensensor-Libary einbinden.
**
*******************************************************************************
*******************************************************************************
******************************************************************************/

#ifndef __RS_LIB_H__
#define __RS_LIB_H__

/*
//Definition des Bitfeldes
//========================
typedef struct
{
unsigned  B7:1;
unsigned  B6:1;
unsigned  B5:1;
unsigned  B4:1;
unsigned  B3:1;
unsigned  B2:1;
unsigned  B1:1;
unsigned  B0:1;
} RS_Bit_Feld;


typedef union
{
RS_Bit_Feld Bit;
unsigned int AllBit;
} RS_Flag;



//Belegung des Bitfeldes
//======================

//Input Variables for Rain Sensor
#define rbi_RainSensorEnable	 RSStatus.Bit.B0
#define	rbi_WashingActive    	 RSStatus.Bit.B1
#define rbi_LowVoltage        RSStatus.Bit.B2
#define rbi_Night              RSStatus.Bit.B3 //!!!NICHT RSStatus.Bit.B2 !!

//Output Variables from Rain Sensor
#define	rbi_RainSensorError	     RSStatus.Bit.B4
#define	rbi_RSWipeSlowDmd        RSStatus.Bit.B5
#define	rbi_RSWipeFastDmd	     RSStatus.Bit.B6

*/





//Berechnete Intervallzeit
//========================

extern unsigned char rub_RSIntermDelayInit;      //interne Regensensosr Delay Time





//Funktionsprototypen
//===================
extern void wwrainse_Init(void);
extern void wwrainse_Task10ms(void);
extern void wwrainse_Task40ms(void);

#endif


