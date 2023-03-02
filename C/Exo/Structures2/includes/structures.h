#ifndef _STRUCTURES_H
#define _STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM_MAX			100
#define PRENOM_MAX		100

/* Personne */
typedef struct {
	char nom[NOM_MAX];
	char prenom[PRENOM_MAX];
	int age;
}Personne;

void InitPersonne(Personne* pers);
void setPersonne(Personne* pers, char* nom, char* prenom, int age);
void displayPersonne(Personne* pers);
void copyPersonne(Personne* pers1, Personne* pers2);

/* Age Difference */
int diffAge(Personne* pers1, Personne* pers2);
void displayDiffAge(int diff);

#endif // _STRUCTURES_H
