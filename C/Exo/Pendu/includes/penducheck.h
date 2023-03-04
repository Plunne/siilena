#ifndef __PENDUCHECK_H
#define __PENDUCHECK_H

#include "penduinit.h"
#include "pendudraw.h"

void checkInWord(PenduGame* Pendu);
void compareWords(PenduGame* Pendu);
void checkMissed(PenduGame* Pendu);
char checkUsed(PenduGame* Pendu);
char checkLetter(PenduGame* Pendu);

#endif // __PENDUCHECK_H