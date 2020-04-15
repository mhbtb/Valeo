#ifndef G5_DIPPED_BEAM_SR_H
#define G5_DIPPED_BEAM_SR_H
/*************************************************************************

Company : Valeo Schalter und Sensoren GmbH

Project : G5 RLxS Sensor

Component : G5_DippedBeam_sr.h

Documentation reference :   Light Sensor Strategy
Overview of the component : Generates the control Signals for the
car's dipped beam headlamp. Safety relevant (sr) application logic is included
here only.


Evolution of the component : since generation 5

*************************************************************************/
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number Name     Description                                       */
/*-DD.MM.YY -----------------------------------------------------------------------*/
/* 25.09.13  -          RFI     initial version*/

#ifdef PC_simulation
#include "PcSimuTypes.h"
#endif

extern byte get_rb_LightVetoCounter_g(void);
extern void light_VetoForLightOff(void);
extern void light_evaluation(void);

#endif
