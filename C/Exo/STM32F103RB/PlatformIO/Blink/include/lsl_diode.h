#ifndef __LSL_DIODE_H
#define __LSL_DIODE_H

#include "stm32f103xb.h"
#include <math.h>

#include "lsl_pinouts.h"

#define LOW     0
#define HIGH    1
#define TOGGLE  2

#define DIODE_NB    7

void LSL_DIODE_Write(LSL_Pinout *diode, unsigned char mode);
void LSL_DIODE_SetDiode(LSL_Pinout *diode);
void LSL_DIODE_ClearDiode(LSL_Pinout *diode);
void LSL_DIODE_ToggleDiode(LSL_Pinout *diode);

unsigned char LSL_DIODE_Get7Seg(unsigned char number);
void LSL_DIODE_Display7Seg(LSL_Pinout *diode, unsigned char number);

#endif // __LSL_DIODE_H