#include <stdio.h>
#include <stdlib.h>

#include "carnet.h"

int main(int argc, char const *argv[])
{
    char *name = (char *) malloc(MAX_NOM);
    char adress[MAX_ADRESSE];

    // initialiser_personne(name, adress);

    copier_personne(name, adress, "uwuwuwuwu", "1 rue machin");
    printf("%s - %s\n", name, adress);
    
    setValeurCarnet(name, "blabla");
    printf("%s\n", name);

    free(name);

    return 0;
}
