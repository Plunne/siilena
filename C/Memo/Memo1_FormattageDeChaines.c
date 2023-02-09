// MEMO 1 - Formattage de chaines
// Pre-requis :
// Savoir faire un "Hello World" avec printf()
// \n = Retour a la ligne
// \t = Tabulation

#include <stdio.h>

int main(void) {

    /*
        %d : Entier signe
        %u : Entier non-signe
        %f : Flottant
        %c : Caractere 
        %s : Chaine de caracteres
        %x : hexadecimal
        %X : HEXADECIMAL
        %o : Octal
        %p : Adresse
    */

    /*
        Arguments a rajouter entre le % et la lettre du type pour etendre sa taille en long ou long long
        l   : long
        ll  : long long

        Ex. Pour un entier long signe "ld", pour un entier long long non-signe "lu"
    */

    printf("Entier court signed : %d\n", 1234);
    printf("Entier court unsigned : %d\n", 1234);
    printf("Nombre flottant : %f\n", 1234.56789);
    printf("Nombre flottant limite de (3) decimale : %.3f\n", 1234.56789);
    printf("Caractere : %c\n", 'c');
    printf("Chaine de caractere : %s\n", "Chaine");
    printf("Hexadecimal en minuscules : %x\n", 1234);
    printf("Hexadecimal en majuscules : %X\n", 1234);
    printf("Hexadecimal flottant en minuscules : %a\n", 1234.56789);
    printf("Hexadecimal flottant en majuscules : %A\n", 1234.56789);
    printf("Octal : %o\n", 1234);;

    return 0;
}