#include "penducheck.h"

/*****************
 *     Check     *
 *****************/

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
	if (!strcmp(Pendu->word, Pendu->PENDU)) {			// If both words are equals
		drawPenduCaracter(Pendu);
		puts("\n***** BRAVO! *****\n");					// YOU WON THE GAME!!!
		printf("You found \"%s\" UwU\n", Pendu->word);	// YOU FOUND THE WORD!!! UwU
		Pendu->running = 0;								// Pendu finished
	}
}

void checkMissed(PenduGame* Pendu) {

	/* Check missed */
	if (Pendu->missedFlag) (Pendu->missedCpt)--;			// Decrement missed counter
	
	/* Game Over */
	if (!(Pendu->missedCpt)) {								// Check if game lost
		drawPenduCaracter(Pendu);
		puts("\n***** GAME OVER *****\n");					// Try Again :(
		printf("The word was : \"%s\"\n", Pendu->PENDU);	// Display the word
		Pendu->running = 0;									// Pendu finished
	}
	
	/* Reset Missed Flag */
	Pendu->missedFlag = 1;									// Set Missed Flag back to HIGH

}

char checkUsed(PenduGame* Pendu) {

	/* Check Letter */
	if (!checkLetter(Pendu)) {						// If not a letter
		puts("\nIt's not a letter!\n");				// Show Warning
		return 1;									// Return 1 to stay in insert loop
	}

	/* Check Used */
	for (int i = 0; Pendu->try[i] != '\0'; i++) {	// While not '\0' (end of string)
		if (Pendu->letter == Pendu->try[i]) {		// If letter already sent
			puts("\nLetter already sent.\n");		// Show Warning
			return 1;								// Return 1 to stay in insert loop
		}
	}

	return 0; // However return 0 to leave the insert loop
}

char checkLetter(PenduGame *Pendu) {
	
	/* Lowercase */
	if ((Pendu->letter >= 'a') && (Pendu->letter <= 'z')) {		// If Lowercase
		Pendu->letter -= 32;									// Convert to Uppercase
		return Pendu->letter;									// Return letter
	}
	
	/* Uppercase */
	else if ((Pendu->letter >= 'A') && (Pendu->letter <= 'Z')) return Pendu->letter; // Return letter because Uppercase

	/* Not a letter */
	else return 0; // Return 0 (Null signal to inform that's not a letter)
}

