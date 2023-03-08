#include "lsl_pinouts.h"

/* Mode */
void LSL_PINOUTS_SetMode(GPIO_TypeDef *PORTx, unsigned char pin, unsigned mode) {
    if (pin < 8) PORTx->CRL |= (mode << (pin * 4));
    else PORTx->CRH |= (mode << ((pin * 4) - 32));
}

void LSL_PINOUTS_ClearMode(GPIO_TypeDef *PORTx, unsigned char pin) {
    if (pin < 8) PORTx->CRL &= ~(0xF << (pin * 4));
    else PORTx->CRH &= ~(0xF << ((pin * 4) - 32));
}

/* Digital */
void LSL_PINOUTS_SetInputDigital(GPIO_TypeDef *PORTx, unsigned char pin) {
    LSL_PINOUTS_ClearMode(PORTx, pin);
    LSL_PINOUTS_SetMode(PORTx, pin, INPUT_MODE);
}

void LSL_PINOUTS_SetOutputDigital(GPIO_TypeDef *PORTx, unsigned char pin) {
    LSL_PINOUTS_ClearMode(PORTx, pin);
    LSL_PINOUTS_SetMode(PORTx, pin, OUTPUT_MODE);
}

/* Pinout */
void LSL_PINOUTS_SetPinout(GPIO_TypeDef *PORTx, unsigned char pin, unsigned char mode) {
    LSL_PINOUTS_ClearMode(PORTx, pin);
    LSL_PINOUTS_SetMode(PORTx, pin, mode);
}

/* Init */
void LSL_PINOUTS_InitPinout(LSL_Pinout *pinout) {
    for (unsigned int i=0; i < sizeof(*pinout); i++) {
        LSL_PINOUTS_SetPinout(pinout[i].PORTx, pinout[i].pin, pinout[i].mode);
    }
}