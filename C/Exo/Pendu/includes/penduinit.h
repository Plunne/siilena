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
	char *PENDU;
	char *word;
	char missedCpt;
	char missedFlag;

	/* Quit */
	char running;

}PenduGame;

#endif // __PENDUINIT_H