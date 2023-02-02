// Algorithmie Avancee
// 6 - Decalage de caracteres & Implementation d'une fonction
// Pre-requis
// Algorithmie1_Bases.c
// Notion de pointeurs

#include <stdio.h>

/***************************************
 * Creation de la fonction de decalage *
 ***************************************/
char *decaler(char *chaine, int longueur, int decalage)
{
    /*
        decalage 1 => YAZERT
        decalage 2 => TYAZER
        ....
        decalage 6 => AZERTY
    */
    for(int i=0; i < decalage; i++)
    {
        /* Sauvegarder le premier caractere */
        // 1 : Car il n'y a aucun caractere avant
        // 2 : Car il se fera remplacer par le suivant
        // 3 : Car il faudra le remettre a la fin de la chaine
        char dernier = chaine[longueur-2];
        
        /* Decaler les caracteres */
        // On commence par la fin sinon on aurait du creer une chaine de sauvegarde
        for (int j=longueur-2; j >= 1; j--)
        {
            chaine[j] = chaine[j-1]; // On copie le caractere de l'indice precedent a la place du caractere a l'indice i
        }
        chaine[0] = dernier; // Le premier caractere ayant ete remplace, on reinsere la sauvegarde faite precedement
    }    
    
    return chaine; // On retourne la chaine modifiee (pointeur)
}

/*****************
 * Fonction MAIN *
 *****************/
int main()
{
    /* Declaration de ma chaine de caracteres */
    char maChaine[] = "AZERTY";//  {'A','Z','E',..,'Y', '\0'};
    
    /* Recuperation de la taille de la chaine */
    int tailleDeMaChaine = sizeof(maChaine)/sizeof(maChaine[0]);
	
    /* Affichage de la sortie de la fonction */
    printf("Chaine apres decalage : %s\n", decaler(maChaine, tailleDeMaChaine, 2)); // La fonction retournant une chaine, il est possible de l'appeler simplement
        
    return 0;
}
