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

/* Enable */
void LSL_PINOUTS_Enable(GPIO_TypeDef *PORTx);

/* Mode */
void LSL_PINOUTS_SetMode(GPIO_TypeDef *PORTx, unsigned char pin, unsigned char mode);
void LSL_PINOUTS_ClearMode(GPIO_TypeDef *PORTx, unsigned char pin);

/* Input */
unsigned char LSL_PINOUTS_Read(LSL_Pinout *pinout);

/* Output */
void LSL_PINOUTS_Write(LSL_Pinout *pinout, enum PINOUT_STATE mode);
void LSL_PINOUTS_Set(LSL_Pinout *pinout);
void LSL_PINOUTS_Clear(LSL_Pinout *pinout);
void LSL_PINOUTS_Toggle(LSL_Pinout *pinout);

/* Pinout */
void LSL_PINOUTS_SetPinout(GPIO_TypeDef *PORTx, unsigned char pin, unsigned char mode);
void LSL_PINOUTS_InitPinout(LSL_Pinout *pinout);

#endif // __LSL_PINOUTS_H