#ifndef __LSL_DIODE_H
#define __LSL_DIODE_H

#include "stm32f103xb.h"
#include <math.h>

#include "lsl_pinouts.h"

#define DIODE_NB    7

unsigned char LSL_DIODE_Get7Seg(unsigned char number);
void LSL_DIODE_Display7Seg(LSL_Pinout *diode, unsigned char number);

#endif // __LSL_DIODE_H