#ifndef __LSL_DISPLAY_H
#define __LSL_DISPLAY_H

#include "stm32f103xb.h"
#include <math.h>

#include "lsl_pinouts.h"

#define DIODE_NB    7

unsigned char LSL_DISPLAY_Get7Seg(unsigned char number);
void LSL_DISPLAY_Display7Seg(LSL_Pinout *diode, unsigned char number);

#endif // __LSL_DISPLAY_H