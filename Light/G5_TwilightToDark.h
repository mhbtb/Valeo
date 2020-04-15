#ifndef G5_TWILIGHT_TO_DARK_H
#define G5_TWILIGHT_TO_DARK_H
/*************************************************************************

Company : Valeo Schalter und Sensoren GmbH

Project : G5 RLxS Sensor

Component : G5_TwilightToDark.h

Documentation reference :   Light Sensor Strategy
Overview of the component : Generates the light states for twilight and
darkness. No safety relevant code shall be included here.


Evolution of the component : since generation 5

*************************************************************************/
/******************************************************************************/
/* History                                                                    */

#include "ior5f109be.h"

extern void initTwilightToDark(byte twilightIsOn);
extern void twilightToDark(void);
extern void darkToTwilight(void);
extern byte isDarkActive(void);

#endif // G5_TWILIGHT_TO_DARK_H
