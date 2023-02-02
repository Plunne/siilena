// Algorithmie Avancee
// 3 - For_Each Valeur Non Commune
// Pre-requis
// Algorithmie1_Bases.c
// Algorithmie3_ForEach1_ValeurCommune.c

#include <stdio.h>

int main()
{
    
    int tableau1[] = { 11, 22, 33, 44, 55 };	// Declaration d'un tableau avec des valeurs
    int tableau2[] = { 33, 44, 55, 66, 77 };	// Declaration d'un tableau avec des valeurs


    int tailleDuTableau1 = sizeof(tableau1)/sizeof(tableau1[0]); // Taille du tableau = Taille en binaire / Taille du type "d'un element du tableau" en binaire
    int tailleDuTableau2 = sizeof(tableau2)/sizeof(tableau1[0]); // Taille du tableau = Taille en binaire / Taille du type "d'un element du tableau" en binaire


	// Parcours du premier Tableau
    for(int i=0; i < tailleDuTableau1; i++)
    {
		// Declaration d'une variable d'etat
        int trouve = 0;
		
        // Parcours du second tableau pour chaque element du premier tableau
        for(int j=0; j < tailleDuTableau2; j++)
        {
			// On compare l'element du tableau2 avec l'element du tableau1
            if (tableau1[i] == tableau2[j]) // Si l'element du tableau1 est egal a l'element du tableau2
			{
				trouve = 1; // On change l'etat de notre variable a 1
				break;		// On sort de la boucle For avec Break (casser la boucle)
            }
        }
        if (trouve == 0) // Si la valeur n'est pas commune
		{
			printf("%d n'est pas commun aux deux tableaux\n", tableau1[i]); // Alors on affiche la valeur non commune
		}
    }

	// Parcours du premier Tableau
    for(int i=0; i < tailleDuTableau2; i++)
    {
		// Declaration d'une variable d'etat
        int trouve = 0;
		
        // Parcours du second tableau pour chaque element du premier tableau
        for(int j=0; j < tailleDuTableau1; j++)
        {
			// On compare l'element du tableau2 avec l'element du tableau1
            if (tableau2[i] == tableau1[j]) // Si l'element du tableau1 est egal a l'element du tableau2
			{
				trouve = 1; // On change l'etat de notre variable a 1
				break;		// On sort de la boucle For avec Break (casser la boucle)
            }
        }
        if (trouve == 0) // Si la valeur n'est pas commune
		{
			printf("%d n'est pas commun aux deux tableaux\n", tableau2[i]); // Alors on affiche la valeur non commune
		}
    }

    return 0;
}
