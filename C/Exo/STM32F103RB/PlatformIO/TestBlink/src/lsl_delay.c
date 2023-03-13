#include "lsl_utils.h"

void LSL_UTILS_DelayMs(unsigned int d) {
	for (unsigned int i=0; i < (d * 500); i++) {
		__asm("nop");
	};
}