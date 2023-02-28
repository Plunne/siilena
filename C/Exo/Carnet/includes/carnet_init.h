#ifndef _CARNET_INIT_H
#define _CARNET_INIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOM         50
#define MAX_ADRESSE     100

static const char default_name[MAX_NOM]         = "Jean Dupont";
static const char default_adress[MAX_ADRESSE]   = "1 rue de la paix";

void initialiser_personne(char *nom, char *adresse);
void copier_personne(char *nom1, char *adresse1, char *nom2, char *adresse2);

void setValeurCarnet(char *output, char *input);

#endif // _CARNET_H