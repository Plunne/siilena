#include "main.h"
#include "lsl_init_regs.h"
#include "lsl_utils.h"
#include "lsl_display.h"
#include "lsl_pinouts.h"

int main(void) {

	/* Init Registers */
	LSL_Init_Registers();

	/* Init Variables */
	int number		= 0;
	int sw_cpt 		= 0;
	int mode_state 	= 0;

	/* Super Loop */
	while (1) {

		// Button		
		if (!LSL_PINOUTS_Read(&Button)) {			// If Button pressed
			LSL_UTILS_DelayMs(100); 				// Anti bouncing
			LSL_PINOUTS_Write(&LED, HIGH);			// LED ON
			sw_cpt++;								// Switch counter ++
		} else {									// If Button not pressed / released
			LSL_PINOUTS_Write(&LED, LOW);			// LED OFF
			sw_cpt = 0;								// Reset switch counter
		}

		if (sw_cpt == 3) mode_state = 1;			// If switch counter == 3 (> 3seconds), set Mode state to 1

		// Increment Number
		if (!mode_state) {							// If Mode state is default
			if (number == 9) number = 0;			// If number is 9 (maximum), reset to 0 (minimum)
			else number++;							// Else Increment number
		}
		else {										// If Mode state is reverse
			if (number == 0) number = 9;			// If number is 0 (minimum), reset to 9 (maximum)
			else number--;							// Else decrement number
		}

		// Display
		LSL_DISPLAY_Display7Seg(Diodes, number, anode); // Display number (i)

		// Delay
		LSL_UTILS_DelayMs(1000); 					// Delay (Be careful sw_cpt value depends of this delay)
	}
	
	return 0;
}