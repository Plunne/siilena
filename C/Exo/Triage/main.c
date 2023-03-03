#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_PERSONNE         4

#define MAX_NOM_LENGTH      100
#define MAX_PRENOM_LENGTH   100

int comparer_entiers_decroissant(const void* a, const void* b);
int comparer_entiers_croissant(const void* a, const void* b);

typedef struct {
    char nom[MAX_NOM_LENGTH];
    char prenom[MAX_PRENOM_LENGTH];
    int age;
}Personne;

void afficher_personne(Personne *Pers);

/* Triage */
int comparer_nom_decroissant(const void* a, const void* b);
int comparer_nom_croissant(const void* a, const void* b);
int comparer_prenom_decroissant(const void* a, const void* b);
int comparer_prenom_croissant(const void* a, const void* b);

int main() {

    // Personne --------------------------------------------------

    Personne Personnes[NB_PERSONNE] = {
        {"SUPERNOM", "arene", 18}, 
        {"SUTERNOM", "gnome", 20}, 
        {"UUPERNOM", "Prenom", 15}, 
        {"TUPERNO", "renom", 23} 
    };
    
    for (int i=0; i < NB_PERSONNE; i++) afficher_personne(&Personnes[i]);

    qsort(&Personnes, NB_PERSONNE, sizeof(Personne), comparer_nom_croissant);
    printf("Tableau trie : ");
    for (int i = 0; i < NB_PERSONNE; i++) {
        printf("%s ", Personnes[i].nom);
    }
    printf("\n");

    char* searchName = "UUPERNOM";
    Personne* result = bsearch(searchName, &Personnes, NB_PERSONNE, sizeof(Personne), comparer_nom_croissant);
    if (result == NULL) {
        printf("L'element %s n'a pas ete trouve.\n", searchName);
    }
    else {
        printf("L'element %s a ete trouve a l'indice %lld.\n", searchName, result - Personnes);
    }
    
    // Tableau --------------------------------------------------------------

    int tableau[] = { 5, 3, 7, 1, 9, 2, 8, 4, 6, 0 };
    int n = sizeof(tableau) / sizeof(tableau[0]);

    qsort(tableau, n, sizeof(int), comparer_entiers_croissant);
    printf("Tableau trie : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

  
    int element = 7;
    result = bsearch(&element, tableau, n, sizeof(int), comparer_entiers_croissant);
    if (result == NULL) {
        printf("L'element %d n'a pas ete trouve.\n", element);
    }
    else {
        printf("L'element %d a ete trouve a l'indice %lld.\n", element, result - tableau);
    }

    return 0;
}

int comparer_entiers_decroissant(const void* a, const void* b) {
    const int* pa = (const int*)a;
    const int* pb = (const int*)b;
    return (*pb - *pa);
}

int comparer_entiers_croissant(const void* a, const void* b) {
    const int* pa = (const int*)a;
    const int* pb = (const int*)b;
    return (*pa - *pb);
}

void afficher_personne(Personne *Pers) {

    printf("\n%p\n", Pers);
    printf("%s\n", Pers->nom);
    printf("%s\n", Pers->prenom);
    printf("%d\n\n", Pers->age);
}

/* Trier Nom */

int comparer_nom_decroissant(const void* a, const void* b) {
    const Personne* pa = (const Personne*)a;
    const Personne* pb = (const Personne*)b;
    return strcmp(pb->nom, pa->nom);
}

int comparer_nom_croissant(const void* a, const void* b) {
    const Personne* pa = (const Personne*)a;
    const Personne* pb = (const Personne*)b;
    return strcmp(pa->nom, pb->nom);
}

/* Trier Prenoms */

int comparer_prenom_decroissant(const void* a, const void* b) {
    const Personne* pa = (const Personne*)a;
    const Personne* pb = (const Personne*)b;
    return strcmp(pb->nom, pa->nom);
}

int comparer_prenom_croissant(const void* a, const void* b) {
    const Personne* pa = (const Personne*)a;
    const Personne* pb = (const Personne*)b;
    return strcmp(pa->nom, pb->nom);
}

/* Chercher Nom */

