#ifndef __LSL_DISPLAY_H
#define __LSL_DISPLAY_H

#include "lsl_pinouts.h"

#define DIODE_NB    7

enum DiodeCOM { anode, cathode };

/* 7 Segments */
unsigned char LSL_DISPLAY_Get7Seg(unsigned char number);
void LSL_DISPLAY_Display7Seg(LSL_Pinout *diode, unsigned char number, enum DiodeCOM common);
void LSL_DISPLAY_Display7SegAnodeCathode(LSL_Pinout *diode, unsigned char number, enum PINOUT_STATE stateA, enum PINOUT_STATE stateB);

#endif // __LSL_DISPLAY_H