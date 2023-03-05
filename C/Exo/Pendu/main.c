#include <stdio.h>
#include <stdlib.h>

#include "pendu.h"

int main(void) {
	
	/* New Pendu Game */
	PenduGame Pendu;

	/* Play the game */
	while (1)
	{
		playPendu(&Pendu, randomPendu);
	}

	exit(EXIT_SUCCESS);
}

