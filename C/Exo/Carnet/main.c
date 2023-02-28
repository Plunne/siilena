#include <stdio.h>
#include <stdlib.h>

#include "carnet.h"

int main(int argc, char const *argv[])
{
    // char name[MAX_NOM];
    char *name = (char *) malloc(MAX_NOM * sizeof(char));
    // char adress[MAX_ADRESSE];

    //initialiser_personne(name, adress);
    // printf("%s - %s\n", name, adress);

    //copier_personne(name, adress, "ududuh", "1 rue machin");
    setValeurCarnet(name, "blabla");
    printf("%s\n", name);

    free(name);

    return 0;
}
