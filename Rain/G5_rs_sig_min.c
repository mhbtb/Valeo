/******************************************************************************
*******************************************************************************
**
** Funktion:   Sig_min()
**
**
** Bearbeiter: Bernd Schmid
**             Abt. TKW
**             ITT Automotive Europe GmbH
**
** Datum:      23.09.98
** geaendert:  25.09.98
**
** Funktion:   1. Bestimmung der min_Signaldauer in Abhaengigkeit von der
**                Intervallzeit
**
*******************************************************************************
******************************************************************************/
#include "G5_rs_sig_min.h"
#ifdef __SIGMIN

void Sig_min(void)
{
  
  if(rub_Nachwisch_Count>0)
  {
    //weitere Nachwischzyklen
    // -> rub_SigLength in Abhaengigkeit von der Intervallzeit setzen
    
    if(rub_RSIntermDelayInit_internal <= CB_INTERMDELAY_5)
    {
      //kurze Intervallzeit -> kleine Signale verwerfen
      //-> Wert fuer min. Signallaenge gross waehlen

        rub_SigLength_min = CB_SIG_MIN_WERT4;
    }
    else
      if(rub_RSIntermDelayInit_internal <= CB_INTERMDELAY_3)
      {
        //zwei Wischungen

          rub_SigLength_min = CB_SIG_MIN_WERT3;
      }
      else
        if(rub_RSIntermDelayInit_internal <= CB_INTERMDELAY_1)
        {

            
            rub_SigLength_min = CB_SIG_MIN_WERT2;
        }
        else
        {
          //lange Intervallzeit
          //-> Wert fuer min. Signallaenge klein waehlen

            rub_SigLength_min = CB_SIG_MIN_WERT1;
        }
  }
  else
  {
    //keine Nachwischzyklen -> rub_SigLength auf min. Wert setzen
      rub_SigLength_min = CB_SIG_MIN_WERT1;
  }
  
  //Anpassung des SigminWertes an Geschwindigkeit!
  rub_SigLength_min = 1;//(unsigned char) ((unsigned int)rub_SigLength_min*(450 + (unsigned int)rb_speed_in_kmh_g)>>9);
  
}
#endif



