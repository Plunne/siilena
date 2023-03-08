#ifndef __LSL_PINOUTS_H
#define __LSL_PINOUTS_H

#include "stm32f103xb.h"

#define INPUT_MODE   0x8
#define OUTPUT_MODE  0x1

enum PINOUT_STATE {LOW, HIGH, TOGGLE};

typedef struct {
    GPIO_TypeDef *PORTx;
    unsigned char pin;
    unsigned char mode;
}LSL_Pinout;

/* Mode */
void LSL_PINOUTS_SetMode(GPIO_TypeDef *PORTx, unsigned char pin, unsigned char mode);
void LSL_PINOUTS_ClearMode(GPIO_TypeDef *PORTx, unsigned char pin);

/* Output */
void LSL_PINOUT_Write(LSL_Pinout *pinout, unsigned char mode);
void LSL_PINOUT_Set(LSL_Pinout *pinout);
void LSL_PINOUT_Clear(LSL_Pinout *pinout);
void LSL_PINOUT_Toggle(LSL_Pinout *pinout);

/* Input */
unsigned char LSL_PINOUT_Read(LSL_Pinout *pinout);

/* Digital */
void LSL_PINOUTS_SetInputDigital(GPIO_TypeDef *PORTx, unsigned char pin);
void LSL_PINOUTS_SetOutputDigital(GPIO_TypeDef *PORTx, unsigned char pin);

/* Pinout */
void LSL_PINOUTS_SetPinout(GPIO_TypeDef *PORTx, unsigned char pin, unsigned char mode);
void LSL_PINOUTS_InitPinout(LSL_Pinout *pinout);

#endif // __LSL_PINOUTS_H