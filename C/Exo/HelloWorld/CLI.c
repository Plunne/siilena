#include <stdio.h>

#define NB_ELEVES 5
#define NB_NOTES 5

float notes[NB_ELEVES][NB_NOTES];

void menu();
void addNote();
void displayNote();
void selectEleve(int id);
int continuer();

int main() {

	menu();
	
	return 0;
}

void menu() {

	for (int x = 0; x < NB_ELEVES; x++)
		for (int y = 0; y < NB_NOTES; y++)
			notes[x][y] = 0.0;

	while (1) {

		int choix = 0;
		do
		{
			printf("\n\n***** Menu *****\n\n");
			printf("1 - Ajouter une note\n");
			printf("2 - Afficher la moyenne\n");
			printf("3 - Quitter\n");
			printf("Saisir un choix : ");
			scanf("%d", &choix);
		} while ((choix < 1) || (choix > 3));

		if (choix == 1) addNote();
		else if (choix == 2) displayNote();
		else if (choix == 3) break;
	}

}

void addNote() {
	
	int idEleve = 0;
	float noteEleve = 0;

	printf("\n-- AJOUTER NOTE --\n");
	while (1) {
		selectEleve(idEleve);

		printf("Inserer la note de l'eleve : ");
		scanf("%f", &noteEleve);

		int i = 0;
		while ((notes[idEleve][i] != 0) && (i < NB_NOTES)) i++;

		notes[idEleve][i] = noteEleve;

		/* Continuer ? */
		if (!continuer()) break;
	}
}

void displayNote() {
	
	int idEleve = 0;
	
	printf("\n-- MOYENNE --\n");
	selectEleve(idEleve);

	float moyenne = 0;
	for (int i=0; i < NB_NOTES; i++) moyenne += notes[idEleve][i];
	moyenne /= NB_NOTES;
	
	printf("La moyenne de l'eleve %d est %f\n", idEleve, moyenne);
}

void selectEleve(int id) {
	printf("\nSelectionner l'eleve : ");
	scanf("%d", &id);
}


int continuer() {
	char continuer = '0';
	while (!((continuer == 'y') || (continuer == 'n')))
	{
		printf("Continuer ? (y/n) : ");
		scanf("%c", &continuer);
	}
	if (continuer == 'n') return 0;
	else return 1;
}
