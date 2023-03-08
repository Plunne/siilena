#ifndef __MAIN_H
#define __MAIN_H

#include "lsl_pinouts.h"

#define DIODE_A     0
#define DIODE_B     1
#define DIODE_C     2
#define DIODE_D     7
#define DIODE_E     8
#define DIODE_F     5
#define DIODE_G     6

static LSL_Pinout Diodes[7] = {
    {GPIOB, DIODE_A, OUTPUT_MODE},
    {GPIOB, DIODE_B, OUTPUT_MODE},
    {GPIOB, DIODE_C, OUTPUT_MODE},
    {GPIOB, DIODE_D, OUTPUT_MODE},
    {GPIOB, DIODE_E, OUTPUT_MODE},
    {GPIOB, DIODE_F, OUTPUT_MODE},
    {GPIOB, DIODE_G, OUTPUT_MODE}
};

static LSL_Pinout Button = { GPIOC, 13, INPUT_MODE };
static LSL_Pinout LED = { GPIOA, 5, OUTPUT_MODE };

#endif // __MAIN_H