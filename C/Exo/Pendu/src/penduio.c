#include "pendu.h"

void displayPendu(PenduGame* Pendu) {
	
	printf("\n-- %s --\n", Pendu->word);
	printf("Letters already sent : %s\n", Pendu->try);
	printf("Number of try remaining : %d\n", Pendu->missedCpt);

}

void insertLetter(PenduGame* Pendu) {

	printf("Insert a letter : ");				// Insert a letter
	scanf(" %c", &Pendu->letter);				// Get letter input
	
	if (!checkUsed(Pendu)) {						// If letter wasn't already sent

		Pendu->try[Pendu->nbTry] = Pendu->letter;	// Put Letter into try array
		Pendu->nbTry++;								// Increment try array indice
		Pendu->try[Pendu->nbTry] = '\0';			// Put last string char '\0' into try array
	}
	
}


void checkInWord(PenduGame* Pendu) {
	
	/* Check if letter is in word */
	for (int i = 0; i < strlen(Pendu->PENDU); i++) {
		if (Pendu->letter == Pendu->PENDU[i]) {			// Check if letter is into the Word
			Pendu->word[i] = Pendu->PENDU[i];			// Valid letter each time it's into the Word
			Pendu->missedFlag = 0;						// Set missed flag to zero (letter found)
		}
	}
}

void compareWords(PenduGame* Pendu) {
	
	/* Compare both words */
	if (!strcmp(Pendu->word, Pendu->PENDU)) {	// If both words are equals
		puts("***** BRAVO! *****");				// YOU WON THE GAME!!!
		exit(EXIT_SUCCESS);
	}
}


void checkMissed(PenduGame* Pendu) {

	/* Check missed */
	if (Pendu->missedFlag) (Pendu->missedCpt)--;	// Decrement missed counter
	
	/* Game Over */
	if (!(Pendu->missedCpt)) {						// Check if game lost
		puts("\n***** GAME OVER *****\n");			// Try Again :(
		exit(EXIT_SUCCESS);
	}
	
	/* Reset Missed Flag */
	Pendu->missedFlag = 1;							// Set Missed Flag back to HIGH

}


char checkUsed(PenduGame* Pendu) {
	for (int i = 0; Pendu->try[i] != '\0'; i++) {
		if (Pendu->letter == Pendu->try[i]) {
			puts("\nLetter already sent.\n");
			Pendu->missedFlag = 0;
			return 1;
		}

	}

	return 0;
}
