#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM_MAX			100
#define PRENOM_MAX		100
#define NB_PERSONNNES	10


int main(void) {

	struct Personne {
		char nom[NOM_MAX];
		char prenom[PRENOM_MAX];
		float montant;
	};

	struct Personne Moi = {
		"SAVY-LARIGALDIE",
		"Lena",
		520.05
	};

	printf("Nom : %s\n",		Moi.nom);
	printf("Prenom : %s\n",		Moi.prenom);
	printf("Montant : %f\n",	Moi.montant);
	
	struct Personne Personnes[NB_PERSONNNES];
	
	for (int i = 0; i < NB_PERSONNNES; i++) {
		memset(Personnes[i].nom, " ", NOM_MAX);
		memset(Personnes[i].prenom, " ", PRENOM_MAX);
		Personnes[i].montant = 0.0;
	}

	for (int i = 0; i < NB_PERSONNNES; i++) {
		puts("\nNom : ");
		scanf("%s", &Personnes[i].nom);
		puts("Prenom : ");
		scanf("%s", &Personnes[i].prenom);
		puts("Montant : ");
		scanf("%f", &Personnes[i].montant);
	}

	for (int i = 0; i < NB_PERSONNNES; i++) {
		printf("\n-- Personne %d --\n", i);
		printf("Nom : %s\n",		Personnes[i].nom);
		printf("Prenom : %s\n",		Personnes[i].prenom);
		printf("Montant : %f\n",	Personnes[i].montant);
	}

	return 0;
}