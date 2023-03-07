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
    
    LSL_GPIO_ClearModes();
    LSL_GPIO_SetInputs();
    LSL_GPIO_SetOutputs();

}

void LSL_GPIO_ClearModes(void) {

	// GPIOA
	GPIOA->CRL &= ~(0xF << 20); // PA5
	
	// GPIOB
	GPIOB->CRL &= ~(0xF << (DIODE_A * 4));          // PB0
	GPIOB->CRL &= ~(0xF << (DIODE_B * 4));          // PB1
	GPIOB->CRL &= ~(0xF << (DIODE_C * 4));          // PB2
	GPIOB->CRL &= ~(0xF << (DIODE_F * 4));          // PB5
	GPIOB->CRL &= ~(0xF << (DIODE_G * 4));          // PB6
	GPIOB->CRL &= ~(0xF << (DIODE_D * 4));          // PB7
	GPIOB->CRH &= ~(0xF << ((DIODE_E * 4) - 32));   // PB8
	
	// GPIOC
	GPIOC->CRH &= ~(0xF << 20); // PC13

}

void LSL_GPIO_SetOutputs(void) {

    /* Outputs GPIOA */
	GPIOA->CRL |= GPIO_CRL_MODE5_0; // Set PA5 MODE (01 : output)
    
    /* Outputs GPIOB */
	GPIOB->CRL |= (0x1 << (DIODE_A * 4)); // Set PB0 MODE (01 : output)
	GPIOB->CRL |= (0x1 << (DIODE_B * 4)); // Set PB1 MODE (01 : output)
	GPIOB->CRL |= (0x1 << (DIODE_C * 4)); // Set PB2 MODE (01 : output)
	GPIOB->CRL |= (0x1 << (DIODE_F * 4)); // Set PB5 MODE (01 : output)
	GPIOB->CRL |= (0x1 << (DIODE_G * 4)); // Set PB6 MODE (01 : output)
	GPIOB->CRL |= (0x1 << (DIODE_D * 4)); // Set PB7 MODE (01 : output)
	GPIOB->CRH |= (0x1 << ((DIODE_E * 4) - 32)); // Set PB8 MODE (01 : output)

}

void LSL_GPIO_SetInputs(void) {

    /* Inputs GPIOC */    
	GPIOC->CRH |= GPIO_CRH_CNF13_1; // Set PC13 CNF (10 : input)

}
