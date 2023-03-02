#ifndef __PENDUIO_H
#define __PENDUIO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define MAX_TRY 27 // Alphabet + '\0'

typedef struct {

	/* Letters */
	char letter;
	char try[MAX_TRY];
	char nbTry;

	/* Word */
	char *PENDU;
	char *word;
	char missedCpt;
	char missedFlag;

}PenduGame;

void displayPendu(PenduGame* Pendu);
void insertLetter(PenduGame* Pendu);
void checkInWord(PenduGame* Pendu);
void compareWords(PenduGame* Pendu);
void checkMissed(PenduGame* Pendu);
char checkUsed(PenduGame* Pendu);

#endif // __PENDUIO_H