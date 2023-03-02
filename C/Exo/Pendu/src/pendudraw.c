#include "pendudraw.h"

void drawPenduCaracter(PenduGame* Pendu) {
	for (int i=0; i < PENDU_CARACTER_Y; i++)
		printf("%s\n", penduCaracter[Pendu->missedCpt - 1][i]);
}