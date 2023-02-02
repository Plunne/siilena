// Algorithmie Avancee
// 2 - Decrementation
// Pre-requis
// Algorithmie1_Bases.c

#include <stdio.h>

int main()
{
    
    int entier = 10;					// Declaration d'un Nombre entier relatif
	float flottant = 10.10;				// Declaration d'un Nombre à virgule
	int tableau [] = {11, 22, 33, 44};	// Declaration d'un tableau avec des valeurs

    int tailleDuTableau = sizeof(tableau)/sizeof(int); // Taille du tableau = Taille en binaire / Taille du type en binaire
	
    /* Boucle d'incrementation inversee */
    // POUR i = Taille du tableau -1 (Car taille=4 Mais incrementation de 3->0 et pas 4->1)
	// TANT QUE i est > 0
	// EN FIN DE BOUCLE decrementer i de -1
    for (int i=tailleDuTableau-1; i>=0; i--) // Au lieu d'aller de 0->3 on va de 3->0
    {
        printf("Indice %d = %d\n", i, tableau[i]); // Afficher "Indice i = valeur du tableau a l'indice i" 
    }

    return 0;
}
