#include "lsl_init_regs.h"
#include "lsl_utils.h"
#include "lsl_diode.h"

int main(void) {

	/* Init Registers */
	LSL_Init_Registers();

	/* Init Variables */

	int i = 0;
	int sw_state = 0;
	int mode_state = 0;

	/* Super Loop */
	while (1) {
		
		if (!LSL_PINOUT_Read(&Button)) {
			LSL_PINOUT_Write(&LED, TOGGLE);
			sw_state++;
		} else {
			LSL_PINOUT_Write(&LED, LOW);
			sw_state = 0;
		}

		if (sw_state == 25000) mode_state = 1;

		// INCREMENT STATE
		if (!mode_state) {
			if (i == 9) i = 0;
			else i++;
		}
		else {
			if (i == 0) i = 9;
			else i--;
		}

		LSL_DIODE_Display7Seg(Diodes, i);

		LSL_UTILS_DelayMs(1000);
	}
	
	return 0;
}