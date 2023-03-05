#include "penduinit.h"

/****************
 *     Init     *
 ****************/

void initPendu(PenduGame* Pendu) {

	/* Letters */
	Pendu->letter		= ' ';		// Init first Try letter to 'A' character
	Pendu->try[0]		= '\0';		// Init first Try to 'A' character
	Pendu->nbTry		= 0;		// Init number of Try to zero

	/* Missed */
	Pendu->missedCpt	= 6;		// Init number of fail allowed
	Pendu->missedFlag	= 1;		// Init missed flag to 1

	/* Running */
	Pendu->running		= 1;		// Init Pendu running state
}

void initWord(PenduGame* Pendu) {

	*Pendu->word = "";						// Init the string of the word to find
	
	char i = 0;								// Create a word counter (word size is < 127/255)
	for (; Pendu->PENDU[i] != '\0'; i++) {	// For each letter of PENDU
		Pendu->word[i] = '_';				// Put an underscore to the word to find
	}
	Pendu->word[i] = '\0';					// Put the last string caracter into the word to fnd
}

