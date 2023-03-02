#include <stdio.h>
#include <stdlib.h>

#include "pendu.h"

int main(void) {
	
	/* New Pendu Game */
	PenduGame Pendu;

	/* Set Pendu with a Word */
	setPendu(&Pendu, "ALEATOIRE");

	/* Pendu Game*/
	while (Pendu.running) {
		runPendu(&Pendu);
	}

	return 0;
}
