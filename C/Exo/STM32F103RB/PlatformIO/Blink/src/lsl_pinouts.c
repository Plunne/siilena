#include "lsl_pinouts.h"

/* Mode */
void LSL_PINOUTS_SetMode(GPIO_TypeDef *PORTx, unsigned char pin, unsigned char mode) {
    if (pin < 8) PORTx->CRL |= (mode << (pin * 4));
    else PORTx->CRH |= (mode << ((pin * 4) - 32));
}

void LSL_PINOUTS_ClearMode(GPIO_TypeDef *PORTx, unsigned char pin) {
    if (pin < 8) PORTx->CRL &= ~(0xF << (pin * 4));
    else PORTx->CRH &= ~(0xF << ((pin * 4) - 32));
}

/* Output */
void LSL_PINOUT_Write(LSL_Pinout *pinout, unsigned char mode) {
    
    switch (mode)
    {
    case 0:
        LSL_PINOUT_Clear(pinout);
        break;
    case 1:
        LSL_PINOUT_Set(pinout);
        break;
    case 2:
        LSL_PINOUT_Toggle(pinout);
        break;
    
    default:
        break;
    }

}

void LSL_PINOUT_Set(LSL_Pinout *pinout) {
    pinout->PORTx->ODR |= (1 << pinout->pin); 
}

void LSL_PINOUT_Clear(LSL_Pinout *pinout) {
    pinout->PORTx->ODR &= ~(1 << pinout->pin); 
}

void LSL_PINOUT_Toggle(LSL_Pinout *pinout) {
    pinout->PORTx->ODR ^= (1 << pinout->pin); 
}

/* Input */
unsigned char LSL_PINOUT_Read(LSL_Pinout *pinout) {
    return (pinout->PORTx->IDR & (1 << pinout->pin));
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

void LSL_PINOUTS_InitPinout(LSL_Pinout *pinout) {
    for (unsigned int i=0; i < sizeof(*pinout); i++) {
        LSL_PINOUTS_SetPinout(pinout[i].PORTx, pinout[i].pin, pinout[i].mode);
    }
}