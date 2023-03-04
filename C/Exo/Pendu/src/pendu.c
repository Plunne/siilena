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

void playPendu(PenduGame* Pendu, void (*setupPendu)(PenduGame* P)) {
	
	initPendu(Pendu);	// Init Pendu common default values
	setupPendu(Pendu);	// Setup a game mode (play mode function as parameter)
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
	Pendu->word[i] = '\0';					// Put the last string caracter into the word to find
}

