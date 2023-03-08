#include "lsl_init_regs.h"

void LSL_Init_Registers(void) {

    LSL_Init_RCC();
    LSL_Init_GPIO();

}

void LSL_Init_RCC(void) {

    /* ENABLE GPIOs */   
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // Enable RCC for GPIOA
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; // Enable RCC for GPIOB
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; // Enable RCC for GPIOC

}

void LSL_Init_GPIO(void) {
    
	LSL_PINOUTS_InitPinout(Diodes);
	// LSL_PINOUTS_InitPinout(&Button);
	// LSL_PINOUTS_InitPinout(&LED);

}
