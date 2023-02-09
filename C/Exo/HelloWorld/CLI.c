#include <stdio.h>

#define NB_ELEVES 5
#define NB_NOTES 5

#define NOTE_MIN 0
#define NOTE_MAX 20

float notes[NB_ELEVES][NB_NOTES];

void menu();
void addNote();
void displayNote();
int selectEleve();
int continuer();

int main() {

	menu();
	
	return 0;
}

void menu() {

	for (int x = 0; x < NB_ELEVES; x++)
		for (int y = 0; y < NB_NOTES; y++)
			notes[x][y] = -1;

	while (1) {

		int choix = 0;
		do
		{
			printf("\n***** Menu *****\n\n");
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
	float noteEleve = -1;

	printf("\n-- AJOUTER NOTE --\n");
	while (1)
	{
		idEleve = selectEleve();
		
		int i = 0;
		
		while (((notes[idEleve][i] > NOTE_MIN) && (notes[idEleve][i] < NOTE_MAX)) && (i < NB_NOTES)) i++;
		
		// TANT QUE la note inseree est entre 0 et 20
		do
		{
			printf("Inserer la note de l'eleve : ");
			scanf("%f", &noteEleve);
			notes[idEleve][i] = noteEleve;
		}
		while ((notes[idEleve][i] < NOTE_MIN) || (notes[idEleve][i] > NOTE_MAX));
		
		
		/* Continuer ? */
		if (!continuer()) break;
	}
}

void displayNote() {
	
	int idEleve = 0;
	
	printf("\n-- MOYENNE --\n");
	idEleve = selectEleve();

	float moyenne = 0;
	int i = 0;
	while (notes[idEleve][i] != -1) {
		moyenne += notes[idEleve][i];
		++i;
	}
	moyenne /= i;
	
	printf("La moyenne de l'eleve %d est %f\n", idEleve, moyenne);
}

int selectEleve() {
	
	int id = 0;

	// TANT QUE l'id n'est pas celui d'un eleve, Demander l'id d'un eleve
	do
	{
		printf("\nSelectionner l'eleve : ");
		scanf("%d", &id);
	}
	while ((id < 0) || (id >= NB_ELEVES));

	return id;
}


int continuer() {
	
	char continuer = '0';

	// TANT QUE l'on insere pas y ou n (yes/no)
	while (!((continuer == 'y') || (continuer == 'n')))
	{
		printf("Continuer ? (y/n) : ");
		scanf(" %c", &continuer); // Ajouter un espace avant le %c pour ne pas repeter
	}
	if (continuer == 'n') return 0; // SI (appui su n) on ne veut pas continuer quitter le sous programme
	else return 1;					// SINON (appui sur y) Continuer le sous programme
}
