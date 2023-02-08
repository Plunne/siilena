#include <stdio.h>

int main() {

	/* Exo 1 */
	int entier = 0;
	while (entier < 99) {
		printf("%d\n", entier);
		entier++;
	}

	/* Exo 2 */
	int nombres[10];
	
	int i = 0;
	while (i < 10) {
		printf("Nombre : ");
		scanf("%d", &nombres[0]);
		if (nombres[0] == 51) {
			printf("Arret de l'optention (51)\n");
			break;
		}
		i++;
	}

	/* Exo 3 */

	#define TAILLE 5
	int entiers[TAILLE];

	for (int i = 0; i < TAILLE; i++) {
		// Force la case du tableau a etre dans la condition du while pour y rentrer
		entiers[i] = 0;
		// Tant qu'on est pas entre 1 et 10
		while ((entiers[i] < 1) || (entiers[i] > 10)) {
			// Saisie d'un entier
			printf("Entier : ");
			scanf("%d", &entiers[i]);
		}
		// Affichage
		printf("%d : %d\n\n", i+1, entiers[i]);
	}

	return 0;
}