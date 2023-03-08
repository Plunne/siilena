#ifndef __LSL_PINOUTS_H
#define __LSL_PINOUTS_H

#include "stm32f103xb.h"

#define INPUT_MODE   0x8
#define OUTPUT_MODE  0x1

typedef struct {
    GPIO_TypeDef *PORTx;
    unsigned char pin;
    unsigned char mode;
}LSL_Pinout;

/* Mode */
void LSL_PINOUTS_SetMode(GPIO_TypeDef *PORTx, unsigned char pin, unsigned mode);
void LSL_PINOUTS_ClearMode(GPIO_TypeDef *PORTx, unsigned char pin);

/* Digital */
void LSL_PINOUTS_SetInputDigital(GPIO_TypeDef *PORTx, unsigned char pin);
void LSL_PINOUTS_SetOutputDigital(GPIO_TypeDef *PORTx, unsigned char pin);
void LSL_PINOUTS_SetPinoutDigital(GPIO_TypeDef *PORTx, unsigned char pin, unsigned char mode);

/* Init */
void LSL_PINOUTS_InitPinout(LSL_Pinout *pinout);

#endif // __LSL_PINOUTS_H