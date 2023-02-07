#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;

    printf("Inserer 2 entiers : ", a, b);
    scanf("%d %d", &a, &b);
    printf("Vous avez insere : %d %d\n", a, b);

    if (a == b) printf("Les valeurs sont egales.\n");
    else if (a < b) printf("A < B\n");
    else if (a > b) printf("A > B\n");
    else printf("Erreur d'insertion.\n");

    return 0;
}