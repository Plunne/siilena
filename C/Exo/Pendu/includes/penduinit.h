#ifndef __PENDUINIT_H
#define __PENDUINIT_H

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

#endif // __PENDUINIT_H