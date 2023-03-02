#include <stdio.h>
#include <stdlib.h>

#include "pendu.h"

int main(void) {
	
	/* New Pendu Game */
	PenduGame Pendu;
	defaultPendu(&Pendu);

	while (1) {
		runPendu(&Pendu);
	}

	return 0;
}
