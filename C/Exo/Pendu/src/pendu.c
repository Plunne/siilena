#include "pendu.h"

/*****************
 *     Pendu     *
 *****************/

void runPendu(PenduGame* Pendu) {
	
	puts("\n\n");
	puts("**********************");
	puts("*     PENDU GAME     *");
	puts("**********************");

	while (Pendu->running)
	{
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

	playAgain();
}

/****************
 *     Play     *
 ****************/

void playPendu(PenduGame* Pendu, void (*penduMode)(PenduGame* P)) {
	
	initPendu(Pendu);	// Init Pendu common default values
	penduMode(Pendu);	// Setup a game mode (play mode function as parameter)
	runPendu(Pendu);	// Run the game
}

/********************
 *    Play Modes    *
 ********************/

void defaultPendu(PenduGame *Pendu) {

	/* Word */
	*Pendu->PENDU		= "PENDU";	// Init default PENDU name
	*Pendu->word		= "_____";	// Init default PENDU word to find
}

void randomPendu(PenduGame* Pendu) {

	/* Word */
	getFileWord(Pendu);	// Init default PENDU name
	initWord(Pendu);	// Init word to find

}

/************************
 *     Custom Pendu     *
 ************************/

void customPendu(PenduGame *Pendu, char *word) {

	/* Init */
	initPendu(Pendu);		// Init Pendu common default values

	/* Word */
	*Pendu->PENDU = word;	// Init default PENDU name with string parameter
	initWord(Pendu);		// Init word to find

	/* Run */
	runPendu(Pendu);		// Run the game
}

