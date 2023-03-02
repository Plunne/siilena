#include "pendu.h"

/*****************
 *     Pendu     *
 *****************/

void runPendu(PenduGame* Pendu) {

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


void defaultPendu(PenduGame* PenduDefault) {

	/* Letters */
	PenduDefault->letter		= 'A';		// Init first Try letter to 'A' character
	PenduDefault->try[0]		= '\0';		// Init first Try to 'A' character
	PenduDefault->nbTry			= 0;		// Init number of Try to zero

	/* Word */
	PenduDefault->PENDU			= "PENDU";	// Init default PENDU name
	PenduDefault->word			= "_____";	// Init default PENDU word to find
	PenduDefault->missedCpt		= 6;		// Init number of fail allowed
	PenduDefault->missedFlag	= 1;		// Init missed flag to 1

}

