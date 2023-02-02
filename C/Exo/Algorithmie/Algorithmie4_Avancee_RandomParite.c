// Algorithmie Avancee
// 4 - Nombres aleatoires avec tableau de nombres Pairs/Impairs
// Pre-requis
// Algorithmie1_Bases.c

#include <stdio.h>

int main()
{
    
    int tableau[10];	// Declaration d'un tableau avec des valeurs
    int tailleDuTableau = sizeof(tableau1)/sizeof(tableau[0]); // Taille du tableau = Taille en binaire / Taille du type "d'un element du tableau" en binaire

    // Initialiser la mecanique du random
    srand(time(NULL));

    // Remplir avec des val aleatoires [0,100]
    for (int i=0; i < tailleDuTableau; i++)
    {
        tableau[i] = rand() % 100;                      // Affecter une valeur aleatoire a l'element du tableau a l'indice i (% 100 -> [0;99] / ex. %10000 -> [0;9999])
        printf("Tableau %d <- %d\n", i, tableau[i]);    // Afficher la valeur du tableau a l'indice i
    }
    
    /* Compter les nombres pairs et impairs */
    int nbPair=0, nbImpair=0; // Initialisation des compteurs de nombres Pairs/Impairs a Zero
    
    // Comptage des nombres Pairs/Impairs
    for(int i=0; i < tailleDuTableau; i++)
    {
        tableau[i] % 2 == 0 ? nbPair++: nbImpair++; // SI le reste de tableau[i] /2 est nul, ALORS le compteur de nb Pairs +1, SINON le compteur de nb Impairs +1
    }
 
    printf("Nombre de pairs = %d // nombre de impairs =%d", nbPair, nbImpair); // Affichage du nombre de nombres Pairs et Impairs

    return 0;
}
