#include "stm32f103xb.h"

void delayMs(unsigned int d);

void delayMs(unsigned int d) {
	for (unsigned int i=0; i < (d * 2500); i++);
}

int main(void) {

	/* RCC */
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPAEN; // Enable RCC for GPIOC, GPIOA Pin/Port
	
	/* MODER */
	GPIOA->CRL &= ~(GPIO_CRL_CNF5 | GPIO_CRL_MODE5); // Clear GPIO PA5 MODE
	GPIOC->CRH &= ~(GPIO_CRH_CNF13 | GPIO_CRH_MODE13); // Clear GPIO PC13 MODE
	
	/* OUTPUT */
	GPIOA->CRL |= GPIO_CRL_MODE5_0; // Set GPIO PA5 MODE (01 : output)
	
	/* INPUT */
	GPIOC->CRH |= GPIO_CRH_MODE13_1; // Set GPIO PC13 MODE (10 : input)
	
	while (1) {
		
		/* BUTTON */
		while((GPIOC->IDR & (1 << 13))) { // If/While button PC13 not pressed
		
			/* LED HIGH */
			
			GPIOA->ODR ^= (1 << 5); // Toggle LED
			delayMs(500);
		
		}
		
	}
	
	return 0;
}