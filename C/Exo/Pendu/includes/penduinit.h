#ifndef __PENDUINIT_H
#define __PENDUINIT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define PENDU_MAX_WORD	30	// Approximatively, lenght of the longest dictionnary word
#define PENDU_MAX_TRY	27	// Alphabet + '\0'

typedef struct {

	/* Letters */
	char letter;
	char try[PENDU_MAX_TRY];
	char nbTry;

	/* Word */
	char PENDU[PENDU_MAX_WORD];
	char word[PENDU_MAX_WORD];
	char missedCpt;
	char missedFlag;

	/* File */
	FILE* file;

	/* Quit */
	char running;

}PenduGame;

typedef struct {
	PenduGame *Game;
	char *wordList;
}PenduList;

void initPendu(PenduGame* Pendu);
void initWord(PenduGame* Pendu);

#endif // __PENDUINIT_H