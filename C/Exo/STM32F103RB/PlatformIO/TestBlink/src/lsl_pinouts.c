#include "lsl_pinouts.h"

/* Enable */
void LSL_PINOUTS_Enable(GPIO_TypeDef *PORTx) {
    if (PORTx == GPIOA) RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // Enable RCC for GPIOA
    else if (PORTx == GPIOB) RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; // Enable RCC for GPIOB
    else if (PORTx == GPIOC) RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; // Enable RCC for GPIOC
    else if (PORTx == GPIOD) RCC->APB2ENR |= RCC_APB2ENR_IOPDEN; // Enable RCC for GPIOD
    else if (PORTx == GPIOE) RCC->APB2ENR |= RCC_APB2ENR_IOPEEN; // Enable RCC for GPIOE
}

/* Mode */
void LSL_PINOUTS_SetMode(GPIO_TypeDef *PORTx, unsigned char pin, unsigned char mode) {
    if (pin < 8) PORTx->CRL |= (mode << (pin * 4)); // Set Mode for pins 0 -> 7
    else PORTx->CRH |= (mode << ((pin * 4) - 32));  // Set Mode for pins 8 -> 15
}

void LSL_PINOUTS_ClearMode(GPIO_TypeDef *PORTx, unsigned char pin) {
    if (pin < 8) PORTx->CRL &= ~(0xF << (pin * 4)); // Reset Mode for pins 0 -> 7
    else PORTx->CRH &= ~(0xF << ((pin * 4) - 32));  // Reset Mode for pins 8 -> 15
}

/* Input */
unsigned char LSL_PINOUTS_Read(LSL_Pinout *pinout) {
    return (pinout->PORTx->IDR & (1 << pinout->pin));   // Read a digital input
}

/* Output */
void LSL_PINOUTS_Write(LSL_Pinout *pinout, enum PINOUT_STATE mode) {
    
    switch (mode)
    {
    case LOW:
        LSL_PINOUTS_Clear(pinout);
        break;
    case HIGH:
        LSL_PINOUTS_Set(pinout);
        break;
    case TOGGLE:
        LSL_PINOUTS_Toggle(pinout);
        break;
    
    default:
        break;
    }
}

void LSL_PINOUTS_Set(LSL_Pinout *pinout) {
    pinout->PORTx->ODR |= (1 << pinout->pin);   // Set pinout HIGH
}

void LSL_PINOUTS_Clear(LSL_Pinout *pinout) {
    pinout->PORTx->ODR &= ~(1 << pinout->pin);  // Clear pinout LOW
}

void LSL_PINOUTS_Toggle(LSL_Pinout *pinout) {
    pinout->PORTx->ODR ^= (1 << pinout->pin);   // Toggle pinout (Swap HIGH/LOW)
}

/* Pinout */
void LSL_PINOUTS_SetPinout(GPIO_TypeDef *PORTx, unsigned char pin, unsigned char mode) {
    LSL_PINOUTS_Enable(PORTx);                      // Enable GPIO RCC
    LSL_PINOUTS_ClearMode(PORTx, pin);              // Reset GPIO Mode
    LSL_PINOUTS_SetMode(PORTx, pin, mode);          // Set GPIO Mode
}

void LSL_PINOUTS_InitPinout(LSL_Pinout *pinout) {
    for (unsigned int i=0; i < sizeof(*pinout); i++) { // For each Pinout from the array
        LSL_PINOUTS_SetPinout(pinout[i].PORTx, pinout[i].pin, pinout[i].mode); // Set GPIO RCC & Mode
    }
}