#include "lsl_init_regs.h"
#include "lsl_utils.h"
#include "lsl_diode.h"

int main(void) {

	/* Init Registers */
	LSL_Init_Registers();

	/* Init Variables */
	Diodes Diodes[DIODE_NB] = {
		{ GPIOB, DIODE_A },
		{ GPIOB, DIODE_B },
		{ GPIOB, DIODE_C },
		{ GPIOB, DIODE_D },
		{ GPIOB, DIODE_E },
		{ GPIOB, DIODE_F },
		{ GPIOB, DIODE_G },
	};

	/* Super Loop */
	while (1) {

		// 7 SEGMENTS	
		LSL_DIODE_Display7Seg(Diodes, 8); // 7seg Display 8

		// BUTTON
		while(!(GPIOC->IDR & (1 << 13))) {
		
			// LED TOGGLE
			GPIOA->ODR ^= (1 << 5);				// Reverse LED
			// 7 SEGMENTS
			LSL_DIODE_Display7Seg(Diodes, 5);	// 7seg Display 5
			// DELAY
			LSL_UTILS_DelayMs(500);				// Delay ~500ms
		
		}
		
	}
	
	return 0;
}