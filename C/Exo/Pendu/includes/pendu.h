#ifndef __PENDU_H
#define __PENDU_H

#include "penduio.h"

/* Run */
void runPendu(PenduGame *Pendu);

/* Play */
void playPendu(PenduGame *Pendu, void (*penduMode)(PenduGame *P));

/* Play Modes */
void defaultPendu(PenduGame *Pendu);
void randomPendu(PenduGame *Pendu);

/* Custom word */
void customPendu(PenduGame *Pendu, char *word);

#endif // __PENDU_H