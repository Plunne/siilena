#ifndef __PENDU_H
#define __PENDU_H

#include "penduio.h"

/* Run */
void runPendu(PenduGame *Pendu);

/* Play */
void playPendu(PenduGame *Pendu, void (*setupPendu)(PenduGame *P));

/* Play Modes */
void defaultPendu(PenduGame *Pendu);
void randomPendu(PenduGame *Pendu);

/* Custom word */
void customPendu(PenduGame *Pendu, char *word);

/* Init */
void initPendu(PenduGame* Pendu);
void initWord(PenduGame* Pendu);

#endif // __PENDU_H