#include <stdio.h>

int main() {

    unsigned char nombreSaisi = 0;
    unsigned char nombre = 9;

    /* 1ere saisie */
    printf("Deviner le nombre de 0 a 9 : ");                // 1. Affichage
    scanf("%d", &nombreSaisi);                              // 1. Saisie
    if (nombreSaisi == nombre) printf("BRAVO !\n");         // 1. Si == nombre
    else {                                                  // 1. Sinon
        /* 2nde saisie */
        printf("Reesayes encore\n");                        // 2. Affichage
		scanf("%d", &nombreSaisi);                          // 2. Saisie
        if (nombreSaisi == nombre) printf("BRAVO !\n");     // 2. Si == nombre
        else {                                              // 2. Sinon
            /* 3eme saisie */
            printf("Reesayes encore\n");                    // 3. Affichage
            scanf("%d", &nombreSaisi);                      // 3. Saisie
			if (nombreSaisi == nombre) printf("BRAVO !\n"); // 3. Si == nombre
            else {                                          // 3. Sinon
				/* Perdu ! */
				printf("PERDU ! :(\n");                     // PERDU !
			}
        }
    }

    return 0;
}