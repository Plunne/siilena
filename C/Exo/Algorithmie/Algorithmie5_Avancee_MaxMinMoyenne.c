// Algorithmie Avancee
// 5 - Nombre Maximum, Minimum et calcul de Moyenne
// Pre-requis
// Algorithmie1_Bases.c
// Algorithmie4_RandomParite.c

#include <stdio.h>

int main()
{

    /* Initialisation */ 
    int tableau[10];	// Declaration d'un tableau avec des valeurs
    int tailleDuTableau = sizeof(tableau)/sizeof(tableau[0]); // Taille du tableau = Taille en binaire / Taille du type "d'un element du tableau" en binaire
    
    /* Tirage Aleatoire */
    srand(time(NULL));  // Generate a random number in each case of the array
    
    for (int i=0; i < tailleDuTableau; i++) {
        tableau[i] = rand() %100;                  // Affecter une valeur aleatoire a l'element du tableau a l'indice i (% 100 -> [0;99] / ex. %10000 -> [0;9999])
        printf("Tab %d <= %d\n", i, tableau[i]);   // Afficher la valeur du tableau a l'indice i
    }
    
    /* Initialise Min et Max ainsi que la moyenne */
    int min = tableau[0];  // Par defaut prend la premiere valeur du tableau (Pour eviter de comparer 0 vu qu'il sera systematiauement inferieur)
    int max = tableau[0];  // Par defaut prend la premiere valeur du tableau
    int moy = 0;        // Par defaut a zero pour eviter des resultats inattendus
    
    /* Minimum */
    for (int i=0; i < tailleDuTableau; i++) {
        if (tableau[i] < min) min = tableau[i];   // SI une valeur est < a la valeur max ALORS remplace la valeur de max par celle-ci
        if (tableau[i] > max) max = tableau[i];   // SI une valeur est > a la valeur max ALORS remplace la valeur de max par celle-ci
        moy += tableau[i];                     // Additionne chaque element a la somme des elements
    }
    
    /* Calcul de la Moyenne */
    moy /= tailleDuTableau;    // Divise la somme obtenue par le nombre d'elements du tableau
    
    /* Affichage */
    printf("Minimum = %d\n", min);  // Afficher le nombre minimum
    printf("Minimum = %d\n", max);  // Afficher le nombre maximum
    printf("Moyenne = %d\n", moy);  // Afficher la moyenne
    
    return 0;
}
