// Algorithmie
// 1 - Les bases de l'Algorithmie en C
// Pre-requis
// Aucun

#include <stdio.h>

int main()
{

	/* Nombre Entier */
    int entier = 10;							// Declaration d'un Nombre entier relatif
    printf("Nombre entier : %d\n", entier);		// Afficher le nombre entier

	/* Nombre Flottant */
	float flottant = 10.10;						// Declaration d'un Nombre à virgule
    printf("Nombre flottant : %f\n", flottant);	// Afficher le nombre flottant

	/* Tableau */
	int tableau [] = {11, 22, 33, 44};							// Declaration d'un tableau avec des valeurs
    printf("Tableau indice 0 (valeur 1) : %d\n", tableau[0]);	// Affichage de la premiere valeur du tableau (A l'indice 0)
    printf("Tableau indice 2 (valeur 3) : %d\n", tableau[2]);	// Affichage de la troisieme valeur du tableau (A l'indice 2)

	/* Affectation d'un tableau */
    tableau[2] = 123;											// Affectation de la valeur 123 a l'indice 2 du tableau
    printf("Tableau indice 2 (valeur 3) : %d\n", tableau[2]);	// Affichage de la troisieme valeur du tableau (A l'indice 2)

	/* Connaitre la taille d'une variable */
    printf("Taille de l'entier : %d\n", sizeof(entier));						// Affichage en decimal (%d) de la taille de la variable entier
    printf("Taille du flottant : %d\n", sizeof(flottant));						// Affichage en decimal (%d) de la taille de la variable flottante
    printf("Taille du tableau  : %d\n", sizeof(tableau)/sizeof(tableau[0]));	// Affichage en decimal (%d) de la taille du tableau

	/* Operateurs Logiques */
    printf("%d\n", 10 % 3);		// Modulo :		Affiche le reste de 10/3=9 reste 1
    printf("%d\n", 10 == 3);	// Egalite :	Compare deux valeurs/variables et affiche vrai (1) si 10 est egal a 3
    printf("%d\n", 10 != 3);	// Inegalite :	Compare deux valeurs/variables et affiche vrai (1) si 10 est different de 3
    printf("%d\n", 1 & 3);		// Et Logique : 0001 and 0011 => 0001 => 1
    printf("%d\n", 1 | 3);		// Ou Logique : 0001 ou 0011 => 0011 => 3

	/* Condition Si...Alors... */
    if (entier % 2 == 0)	// Si la valeur de la variable entier (10) modulo 2 (=0) est egale a 0
    {
        printf("oui\n");	// Alors affiche "oui"
    }
    else					// Sinon...
    {
        printf("non\n");	// ...affiche "non"
    }
	
	/* Recuperation de la taille d'un tableau automatiquement */
	// Rappel :
	// int = 32bits (4octets)
	// Soit :
	// nombre de valeurs en int dans le tableau (ici 4)
	// ce qui donne 4 * 32 = 128bits
	// Donc :
	// 128/32 = 4 variables contenues dans le tableau
    int tailleDuTableau = sizeof(tableau)/sizeof(int); // Taille du tableau = Taille en binaire / Taille du type en binaire

	/* Boucle d'incrementation */
	// Boucle For
	// (initialisation d'un compteur; comparaison; incrementation)
	// Arg1 : Initialisation du compteur
	// Arg2 : Condition Tant que
	// Arg3 : Instruction d'incrementation
	for (int i=0; i < tailleDuTableau; i++) // POUR (a partir de) i=0, TANT QUE i est < a la taille du tableau, A CHAQUE FIN DE BOUCLE incrementer i de +1
    {
        printf("Indice %d = %d\n", i, tableau[i]); // Afficher "Indice i = valeur du tableau a l'indice i"
    }
	
    return 0;
}
