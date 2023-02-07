#include <stdio.h>

float calculCube(float lCube, float hCube, float pCube) {
	return lCube * hCube * pCube;
}

int main() {

	/* Initialisations des variables */
	float largeurCube = 0.0;
	float hauteurCube = 0.0;
	float profondeurCube = 0.0;

	/***** Calcul du volume d'un cube *****/
	printf("***** Calcul du volume d'un cube *****\n\n");

	/* Largeur */
	printf("Largeur (L) : ");		// Affichage de la saisie Largeur
	scanf("%f", &largeurCube);		// Saisie de la Largeur
	
	/* Hauteur */
	printf("Hauteur (h) : ");		// Affichage de la saisie Hauteur
	scanf("%f", &hauteurCube);		// Saisie de la Hauteur
	
	/* Profondeur */
	printf("Profondeur (p) : ");	// Affichage de la saisie Profondeur
	scanf("%f", &profondeurCube);	// Saisie de la Profondeur
	
	/* Affichage du volume du cube */
	printf("Volume du cube : %f\n", calculCube(largeurCube, hauteurCube, profondeurCube));

	return 0;
}