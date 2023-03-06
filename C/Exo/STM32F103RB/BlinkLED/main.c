#include "stm32f10x.h"

void delayMs(unsigned int d);

void delayMs(unsigned int d) {
	for (unsigned int i=0; i < (d * 2500); i++);
}

int main(void) {

	/* RCC */
	RCC->APB2ENR |= (1 << 4) | (1 << 2); // Enable RCC for GPIOC, GPIOA Pin/Port
	
	/* MODER */
	GPIOA->CRL &= ~((1 << 22) | (1 << 23) | (1 << 21) | (1 << 20)); // Clear GPIO PA5 MODE
	GPIOC->CRH &= ~((1 << 22) | (1 << 23) | (1 << 21) | (1 << 20)); // Clear GPIO PC13 MODE
	
	/* OUTPUT */
	GPIOA->CRL |= (1 << 21); // Set GPIO PA5 MODE (01 : output)
	
	/* INPUT */
	GPIOC->CRH |= (1 << 23); // Set GPIO PC13 MODE (10 : input)
	
	while (1) {
		
		/* BUTTON */
		while((GPIOC->IDR &= (1 << 13))) { // If/While button PC13 not pressed
		
			/* LED HIGH */
			GPIOA->ODR ^= (1 << 5); // Toggle LED
			delayMs(500);
		
		}
		
	}
	
	return 0;
}