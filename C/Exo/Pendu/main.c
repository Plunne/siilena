#include <stdio.h>
#include <stdlib.h>

#include "pendu.h"

int main(void) {
	
	/* New Pendu Game */
	PenduGame Pendu;

	/* WIP */
	// getFileWord(&Pendu);
	
	/* Set Pendu with a Word */
	setPendu(&Pendu, "ALEATOIRE");
	setPendu(&Pendu, "COUCOU");

	return 0;
}
