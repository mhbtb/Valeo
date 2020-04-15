
#ifndef G5_RS_SIGNAL_H 
#define G5_RS_SIGNAL_H
/******************************************************************************
*******************************************************************************
**
** Funktion:   Signal()
**
**
** Bearbeiter: Bernd Schmid
**             Abt. TKW
**             ITT Automotive Europe GmbH
**
** Datum:      09.03.98
** geaendert:  21.02.2007
**
** Funktion:   1. Berechnung der Signallaenge und Signalanzahl aus den
**                durchlaufenden Zaehlern
**
*******************************************************************************
******************************************************************************/
/*
Changes on Nov. 09, 2001
- order of includes changed
*/

/* Changes on Feb 21,2007
Metrik Optimization for STPTH
*/

// Defines for rainsensor-constants

/* Rain intensity VCO_423: Number of element for average and threshold */  
#define CB_INTERVALARRAYSIZE_S 10
#define CB_IDLETIMEINTERVAL_S  60  // number of seconds when the rain intensity values will be set to 0 (no rain occured for that time).
                                   // it corresponds to R = 0 mm/h using trendline which was measured

//External declared variables
/** Rain intensity VCO_423 */  
#ifdef RAIN_INTENSITY
extern word rw_RS_SigVoltage_neg_int_g;
static word rw_old_1msTimer_g; 
extern word rw_1msTimer_g;
extern word rb_overWipeCoef;

/* Output value on LIN*/
extern byte rb_RainInt_IntensityOutput_g; //init value is 14 according to DOORS VW req
extern word cb_RainInt_TransformArray_g[13];

/* Intervall time, average, compensation and conversion */
extern word rw_Interval_g;
#endif

// Defines for WiperPositionOn windshield
#define CB_INPARKPOSITION_S 0
#define CB_PARKTOWENDELAGEOBEN_S 1
#define CB_WENDELAGEOBENTOPARK_S 2



#define cw_SINGLEDROPCOUNTEROFFSET_g 40000      //Threshold for Single drop depressing
#endif