#include "pendudraw.h"

void drawPenduCaracter(PenduGame* Pendu) {
	for (int i=0; i < PENDU_CARACTER_Y; i++)					// For each line of matrix
		printf("%s\n", penduCaracter[Pendu->missedCpt][i]);		// Print the line of char depending of Pendu status
}