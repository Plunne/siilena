#ifndef __PENDUDRAW_H
#define __PENDUDRAW_H

#include "penduinit.h"

#define PENDU_CARACTER_NB	7
#define PENDU_CARACTER_Y	8
#define PENDU_CARACTER_X	15

static char penduCaracter[PENDU_CARACTER_NB][PENDU_CARACTER_Y][PENDU_CARACTER_X] = {
	{
		"    __________",
		"    |        |",
		"    O        |",
		"  -----      |",
		"    |        |",
	    "   / \\      /|",
		"           / |",
		"--------------"
	},
	{
		"    __________",
		"    |        |",
		"    O        |",
		"  -----      |",
		"    |        |",
		"   /        /|",
		"           / |",
		"--------------"
	},
	{
		"    __________",
		"    |        |",
		"    O        |",
		"  -----      |",
		"    |        |",
		"            /|",
		"           / |",
		"--------------"
	},
	{
		"    __________",
		"    |        |",
		"    O        |",
		"  ---        |",
		"    |        |",
		"            /|",
		"           / |",
		"--------------"
	},
	{
		"    __________",
		"    |        |",
		"    O        |",
		"    -        |",
		"    |        |",
		"            /|",
		"           / |",
		"--------------"
	},
	{
		"    __________",
		"    |        |",
		"    O        |",
		"             |",
		"             |",
		"            /|",
		"           / |",
		"--------------"
	},
	{
		"    __________",
		"    |        |",
		"             |",
		"             |",
		"             |",
		"            /|",
		"           / |",
		"--------------"
	}
};

void drawPenduCaracter(PenduGame* Pendu);

#endif // __PENDUDRAW_H
