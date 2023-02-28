#include "carnet_init.h"

void initialiser_personne(char *nom, char *adresse) {
    
    memcpy(nom, default_name, MAX_NOM);
    memcpy(adresse, default_adress, MAX_ADRESSE);
}

void copier_personne(char *nom1, char *adresse1, char *nom2, char *adresse2) {

    memcpy(nom1, nom2, MAX_NOM);
    memcpy(adresse1, adresse2, MAX_ADRESSE);
}


void setValeurCarnet(char *output, char *input) {
    output = (char *) realloc(output, sizeof(input));
    memcpy(output, input, sizeof(input));
}