#include <stdio.h>

int main() {

	/* Exo 3 While version Do While */
	#define TAILLE 5
	int entiers[TAILLE];

	for (int i = 0; i < TAILLE; i++) {
		// Tant qu'on est pas entre 1 et 10
		do
		{
			// Saisie d'un entier
			printf("Entier : ");
			scanf("%d", &entiers[i]);
		}
		while ((entiers[i] < 1) || (entiers[i] > 10));
		// Affichage
		printf("%d : %d\n\n", i+1, entiers[i]);
	}

	/* Demo de cas d'utilisation */
	char choix = 0;
	do
	{
		printf("***** Menu *****\n\n");
		printf("1 - Choix A\n");
		printf("2 - Choix B\n");
		printf("3 - Choix C\n");
		printf("4 - Choix D\n");
		printf("5 - Choix E\n");
		printf("Saisie du choix : ");
		scanf("%c", &choix);
	}
	while ((choix < 1) ||(choix > 4));

	return 0;
}