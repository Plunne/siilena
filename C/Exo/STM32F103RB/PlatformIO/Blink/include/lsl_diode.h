#ifndef __LSL_DIODE_H
#define __LSL_DIODE_H

#include "stm32f103xb.h"
#include <math.h>

#define DIODE_NB    7

typedef struct {
    
    GPIO_TypeDef *OUT;
    char PIN;

}Diodes;

void LSL_DIODE_SetDiode(Diodes *diode);
void LSL_DIODE_ClearDiode(Diodes *diode);

unsigned char LSL_DIODE_Get7Seg(unsigned char number);
void LSL_DIODE_Display7Seg(Diodes *diode, unsigned char number);

#endif // __LSL_DIODE_H