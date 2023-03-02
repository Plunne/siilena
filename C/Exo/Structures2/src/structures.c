#include "structures.h"

/********************
 *     Personne     *
 ********************/

void InitPersonne(Personne* pers) {

	/* Init empty pers */
	memset(pers->nom, ' ', NOM_MAX);
	memset(pers->prenom, ' ', PRENOM_MAX);

	/* Set last string char */
	pers->nom[NOM_MAX - 1]			= '\0';
	pers->prenom[PRENOM_MAX - 1]	= '\0';

	/* Set Age to zero */
	pers->age = 0;
}

void setPersonne(Personne* pers, char *nom, char *prenom, int age) {

	InitPersonne(pers);								// Avoid overlap
	memcpy(pers->nom, nom, strlen(nom));			// Set Personne Last Name
	memcpy(pers->prenom, prenom, strlen(prenom));	// Set Personne First Name
	pers->age = age;								// Set Personne Age
}

void displayPersonne(Personne* pers) {

	printf("\n-- Personne %p --", pers);	// Display Personne Adress
	printf("\nNom : %s\n",	pers->nom);		// Display Personne Last Name
	printf("Prenom : %s\n",	pers->prenom);	// Display Personne First Name
	printf("Age : %d\n",	pers->age);		// Display Personne Age
}

void copyPersonne(Personne *pers1, Personne *pers2) {

	memcpy(pers1, pers2, sizeof(Personne));	// Copy Personne2 into Personne1
}

/**************************
 *     Age Difference     *
 **************************/

int diffAge(Personne *pers1, Personne *pers2) {
	
	if (pers1->age >= pers2->age) return pers1->age - pers2->age;
	else return pers2->age - pers1->age;
}

void displayDiffAge(int diff) {

	puts("\n-- Difference Age --");				// -- Difference Age --
	printf("\nDifference d'age : %d\n", diff);	// Display Age Difference
}
