// Algorithmie Avancee
// 3 - For_Each Valeur Commune
// Pre-requis
// Algorithmie1_Bases.c

#include <stdio.h>

int main()
{
    
    int tableau1[] = { 11, 22, 33, 44, 55 };	// Declaration d'un tableau avec des valeurs
    int tableau2[] = { 33, 44, 55, 66, 77 };	// Declaration d'un tableau avec des valeurs


    int tailleDuTableau1 = sizeof(tableau1)/sizeof(int); // Taille du tableau = Taille en binaire / Taille du type en binaire
    int tailleDuTableau2 = sizeof(tableau2)/sizeof(int); // Taille du tableau = Taille en binaire / Taille du type en binaire


	// Parcours du premier Tableau
    for(int i=0; i < tailleDuTableau1; i++)
    {
        // Parcours du second tableau pour chaque element du premier tableau
        for(int j=0; j < tailleDuTableau2; j++)
        {
			// On compare l'element du tableau2 avec l'element du tableau1
            if (tableau1[i] == tableau2[j]) // Si l'element du tableau1 est egal a l'element du tableau2
			{ 
                printf("%d est commun aux deux tableaux\n", tableau1[i]); // Alors on affiche la valeur commune
            }
        }
    }

    return 0;
}
