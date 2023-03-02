#include "pendu.h"

/*****************
 *     Pendu     *
 *****************/

void runPendu(PenduGame *Pendu) {

	/* Display */
	displayPendu(Pendu);

	/* Letter Input */
	insertLetter(Pendu);

	/* Check in word */
	checkInWord(Pendu);
	
	/* Compare words */
	compareWords(Pendu);
	
	/* Check missed */
	checkMissed(Pendu);
}


void defaultPendu(PenduGame *Pendu) {

	/* Letters */
	Pendu->letter		= 'A';		// Init first Try letter to 'A' character
	Pendu->try[0]		= '\0';		// Init first Try to 'A' character
	Pendu->nbTry		= 0;		// Init number of Try to zero

	/* Word */
	Pendu->PENDU		= "PENDU";	// Init default PENDU name
	Pendu->word			= "_____";	// Init default PENDU word to find
	Pendu->missedCpt	= 7;		// Init number of fail allowed
	Pendu->missedFlag	= 1;		// Init missed flag to 1

	/* Running */
	Pendu->running		= 1;		// Init Pendu running state

}

void setPendu(PenduGame *Pendu, char *word) {

	/* Letters */
	Pendu->letter		= 'A';		// Init first Try letter to 'A' character
	Pendu->try[0]		= '\0';		// Init first Try to 'A' character
	Pendu->nbTry		= 0;		// Init number of Try to zero

	/* Word */
	Pendu->PENDU		= word;		// Init default PENDU name
	Pendu->word			= "";		// Init the string of the word to find

	int i = 0;
	for (; Pendu->PENDU[i] != '\0'; i++) Pendu->word[i] = '_';
	Pendu->word[i] = '\0';

	Pendu->missedCpt	= 7;		// Init number of fail allowed
	Pendu->missedFlag	= 1;		// Init missed flag to 1

	/* Running */
	Pendu->running		= 1;		// Init Pendu running state

}
