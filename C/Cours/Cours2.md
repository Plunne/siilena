---
author: Lena SAVY-LARIGALDIE
title: COURS 2 - Le langage C (Partie 2)
---

# COURS 2 - Le Langage C Avance

Formateur : Paul-Ernest MARTIN

## TABLE DES MATIERES
- [COURS 2 - Le Langage C Avance](#cours-2---le-langage-c-avance)
  - [TABLE DES MATIERES](#table-des-matieres)
- [MASQUES](#masques)
  - [Set Bit](#set-bit)
  - [Clear Bit](#clear-bit)
  - [Toggle Bit](#toggle-bit)
- [ARGUMENTS](#arguments)
- [VARIABLES SPECIALES](#variables-speciales)
  - [Variables Statiques](#variables-statiques)
  - [Variables Externes](#variables-externes)
- [ALLOCATION DYNAMIQUE](#allocation-dynamique)
  - [Dependance](#dependance)
  - [Malloc](#malloc)
  - [Free](#free)
  - [Calloc](#calloc)
  - [Realloc](#realloc)
- [BLOCS MEMOIRE](#blocs-memoire)
  - [Dependance](#dependance-1)
  - [Memory Set (memset)](#memory-set-memset)
  - [Memory Copy (memcpy)](#memory-copy-memcpy)
  - [Memory move (memmove)](#memory-move-memmove)
- [POINTEURS DE POINTEURS](#pointeurs-de-pointeurs)
- [POINTEURS DE FONCTION](#pointeurs-de-fonction)
  - [RETOUR DE FONCTION](#retour-de-fonction)
- [PASSAGE PAR ADRESSE](#passage-par-adresse)
- [EXIT](#exit)
- [SYSTEM](#system)
- [STRUCTURES](#structures)
  - [Definition](#definition)
  - [Declaration](#declaration)
  - [Affectation](#affectation)
  - [Acces membre](#acces-membre)
  - [Structures imbriquees](#structures-imbriquees)
  - [Cas particulier](#cas-particulier)
- [UNION](#union)
- [UNION \& STRUTURES](#union--strutures)
- [TYPEDEF](#typedef)
- [ARGUMENTS VARIABLES](#arguments-variables)
  - [Depedance](#depedance)
  - [Definition](#definition-2)
- [STRING.H](#stringh)
  - [strlen](#strlen)
  - [strcpy](#strcpy)
  - [strcmp](#strcmp)
  - [strcat](#strcat)
- [TRIAGE](#triage)
- [RECHERCHE](#recherche)
- [MATH](#math)
- [ERREURS](#erreurs)
  - [Assert](#assert)
  - [Errno](#errno)
- [Fichiers](#fichiers)
  - [Direction](#direction)
  - [Sorties](#sorties)
  - [Lecture/Ecriture](#lectureecriture)
  - [Lignes](#lignes)
- [Enum](#enum)
  - [Incrementation](#incrementation)

# MASQUES

## Set Bit

Forcer des bits a 1.

```c
REGISTRE |= (1 << rang_du_bit); // 1 seul bit
REGISTRE |= (1 << rang_du_bit_A) | (1 << rang_du_bit_B); // Plusieurs bits
```

## Clear Bit

Forcer des bits a 0.

```c
REGISTRE &= ~(1 << rang_du_bit); // 1 seul bit
REGISTRE &= ~((1 << rang_du_bit_A) | (1 << rang_du_bit_B)); // Plusieurs bits
```

## Toggle Bit

Alterner l'etat des bits.
```c
REGISTRE ^= (1 << rang_du_bit); // 1 seul bit
REGISTRE ^= (1 << rang_du_bit_A) | (1 << rang_du_bit_B); // Plusieurs bits
```

# ARGUMENTS

Passer des arguments au lancement d'un programme.

```c
int main(int argc, char const *argv[])
{
    if (argc > 1) { // Si il y a plus de 1 argument (progamme comme 1er arg)
        for (int i=1; i < argc; i++) {
            printf("Argument %d : %s\n", i, argv[i]); // La valeur d'un argument est une string
        }
    }

    printf("Conversion int : %d", atoi(argv[2]));

    return 0;
}
```

# VARIABLES SPECIALES

## Variables Statiques

Lorsqu'un bloc d'instruction se termine, toutes ses variables locales sont detruites.

Pour palier a cela dans le cas ou l'on veuille conserver la valeur d'une variable au prochain appel de la fonction, il existe le mot-cle `static` .

Ce mot-cle permet a une variable locale de :

- persister en memoire a la fin du bloc
- initialiser la variable qu'au premier appel de la fonction

**Declaration :**

``` c
static type variable = valeur;
```

## Variables Externes

Variable declaree dans un fichier externe.

**Declaration :**

Une variable exerne est declaree normalement dans un autre fichier.

```c
// fichier_externe.c
type variable = valeur;
```

**Acces :**

Pour acceder a une variable externe, il suffit d'ajouter le mot cle `extern` .

```c
// fichier_courant.c
extern type variable;
```

> *On ne fait que l'importer, on ne la redeclare pas.*


# ALLOCATION DYNAMIQUE

## Dependance

```c
#include <stdlib.h>
```

## Malloc

Dans certains cas on ne connait pas la place que va prendre notre variable en memoire,
alors on utilise `malloc` qui va nous trouver puis retourner l'adresse d'un emplacement memoire adapte.

**Void :**

Type qui retourne un pointeur dont l'adresse est inconnue a la compilation.

```c
void *pointeur = malloc(nb_octets);
```

*On peut directement saisir le nombre d'octets a allouer.* 

> **IMPORTANT!**  
> Un pointeur de type void s'incremente de 1 octet uniquement.

**Tableau dynamique :**

Allocation d'un tableau a taille dynamique.

``` c
int n = taille_dynamique;
type *pointeur = (type *) malloc(n * sizeof(type));
```

## Free

Malloc ne libere pas la memoire de lui meme la ou une allocation manuelle locale libere son emplacement a la fin de son bloc d'instructions. 

`free` sert donc a liberer celle-ci.

``` c
free(pointeur);
```

## Calloc

Comme `malloc()` mais gere la taille et le nombre pour initialiser.

```c
int n = taille_dynamique;
type *pointeur = (type *) calloc(n, sizeof(type));
```

## Realloc

Modifier la taille de la memoire allouee.

```c
int n = taille_dynamique;
pointeur = (type *) realloc(pointeur, n * sizeof(type));
```

> Evite de reallouer un emplacement avec `malloc()` .

# BLOCS MEMOIRE

> Pour les fonctions ci-dessous :
> - `*destination` : adresse du debut du tableau de destination
> - `*source` : adresse du debut du tableau source modifiant la destination
> - `*taille` : nombre d'octets sur lesquels la plage s'etend a partir des adresses

## Dependance

```c
#include <string.h>
```

## Memory Set (memset)

Permet d'initialiser une partie de la memoire par une valeur sur une plage avec taille definie.

```c
memset(*destination, caractere, taille);
```

## Memory Copy (memcpy)

Copier la memoire d'un tableau dans un autre sur une taille definie.

```c
memcpy(*destination, *source, taille);
```

## Memory move (memmove)

Copier la memoire d'un tableau dans un autre sur une taille definie en verifiant le recouvrement/chevauchement (permet d'eviter de se copier mutuellement si les adresses sont proches car le resultat peut etre degrade)

```c
memmove(*destination, *source, taille);
```

# POINTEURS DE POINTEURS

Il est possible de pointer vers l'adresse d'un pointeur.

**Syntaxe :**

```c
type **ptr2ptr = &ptr1;
```

**Exemple :**

```c
/* Declaration d'une variable */
int variable = valeur; 

/* Declaration d'un pointeur vers l'adresse de la variable */
int *ptr1 = &variable;

/* Declaration d'un pointeur vers l'adresse d'un pointeur */
int **ptr2ptr = &ptr1;
```

> Les pointeurs de pointeurs sont cumulables.

# POINTEURS DE FONCTION

Il est possible de pointer vers une fonction.

```c
/* Declaration */
type (*ptr)(type arg1, type arg2, ...) = &fonction;

/* Utilisation */
prt(arg1, arg2, ...);
```

> **IMPORTANT!**  
> Il faut que le prototype de la fonction a affecter soit le meme que la fonction affectee!

## RETOUR DE FONCTION

```c
/* Pointeur de fonction a retourner */
typeRetournee (*ptrFonction) (argsPtrFonction, ...)

/* Fonction qui retourne le pointeur de fonction */
typeRetournee (*nomFonction(argsNomFonction, ...))(argsPtrFonction, ...);
```

# PASSAGE PAR ADRESSE

Le passage par adresse consiste a passer l'adresse d'une variable en parametre pointeur,
cela permet ensuite de modifier directement le contenu de celle ci en deferencant le parametre.

```c
// main.c
type variable = valeur;

fonction(&variable);
```

Valeur de `variable` avant l'appel de la fonction : `valeur`

```c
// fonction()
void fonction(type *var) {
    *var = nouvelle_valeur;
}
```

Valeur de `variable` a la sortie de la fonction : `nouvelle_valeur`

# EXIT

La fonction `exit()` permet de terminer l'execution du programme.

Cette fonction peut prendre en argument un indice d'erreur.

```c
exit(INDICE);
```

# SYSTEM

La fonction `system()` permet d'executer une commande du systeme d'exploitation.

```c
system("commande");
```

# STRUCTURES

Les structures contiennent des variables (membres) de types differentes.

## Definition

```c
struct MaStructure {
    type_1 attribut1;
    type_2 attribut2;
};
```

> **IMPORTANT!**  
> Une structure ne peut avoir en attributs sa propre structure.

## Declaration

### Pendant la definition

```c
struct MaStructure {
  type_1 attribut1;
  type_2 attribut2;
} NomStructure, NomStructure2;
```

### Apres la definition

```c
struct MaStructure NomStructure1;
struct MaStructure NomStructure2;
```

## Affectation

### Sur la structure

#### Pendant la definition

```c
struct MaStructure {
  type_1 attribut1;
  type_2 attribut2;
} NomStructure = {valeur_attribut1, valeur_attribut2, ...};
```

> Peut se faire avec plusieures structures.
>
> **Exemple :**
>
> ```c
> struct MaStructure {
>     type_1 attribut1;
>     type_2 attribut2;
> } Struct1 = {1,2}, Struct2 = {4,5};
> ```

#### Apres la defnition

```c
NomStructure = {valeur_attribut1, valeur_attribut2, ...};
```

### Membre par membre

```c
NomStructure.attribut1 = valeur_attribut1;
NomStructure.attribut2 = valeur_attribut2;
```

## Acces membre

```c
NomStructure.attribut
```

## Structures imbriquees

Une structure peut contenir d'autres structures en tant que membre.

### Definition

```c
struct UneStructure {
    type_1 attribut1;
    type_2 attribut2;
}
struct MaStructure {
  struct UneStructure CetteStructure;
} NomStructure;
```

### Acces membre

```c
NomStructure.CetteStructure.attribut1
NomStructure.CetteStructure.attribut2
```

## Cas particulier

Dans le cas particulier des tableaux en attribut membre, lorsque l'on souhaite faire une initialisation d'un tableau de structures contenant des tableaux,
il faut initialiser l'integralite des octets avec memset.

**Exemple :**

```c
/* Definition d'une structure */
struct UneStructure {
    int attribut;
    char * tableau[TAILLE_TABLEAU];
}

/* Declaration d'une structure */
struct UneStructure MaStructure[NB_STRUCTURES];

/* Initialisation d'une structure */
for (int i=0; i < NB_STRUCTURES; i++) {
    Mastructure[i].attribut = 0;
    memset(Mastructure[i].tableau, 0, TAILLE_TABLEAU); // Remplir le tableau avec memset()
}
```

# UNION

Une union ressemble a une structure sauf que chaque membre est situe a la meme adresse afin d'interpreter un emplacement memoire de differentes manieres.

**Exemple :**

```c
union nomUnion {
    char c;
    int i;
}
```

|          | Octet 3  | Octet 2  | Octet 1  | Octet 0  |
|----------|----------|----------|----------|----------|
| `char c` |          |          | xxxxxxxx | xxxxxxxx |
| `int  i` | xxxxxxxx | xxxxxxxx | xxxxxxxx | xxxxxxxx |

> La taille maximale d'un union depend de son membre le plus grand.

# UNION & STRUTURES

Avoir des structures dans des unions peut s'averer tres pratique.

**Exemple explicite de struture dans un union :**

```c
union date {
    char date_complete[9];
    struct date_tab {
        char jour[2];
        char separateur1;
        char mois[2];
        char separateur2;
        char annee[4];
    }
}
```

| `char`            | 9   | 8   | 7   | 6   | 5   | 4   | 3   | 2   | 1   | 0   |
|-------------------|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| `date_complete`   | '3' | '2' | '0' | '2' | '/' | '3' | '0' | '/' | '1' | '0' |
|                   |     |     |     |     |     |     |     |     |     |     |
| `struct date_tab` | '3' | '2' | '0' | '2' | '/' | '3' | '0' | '/' | '1' | '0' |
| `jour[2]`         |     |     |     |     |     |     |     |     | '1' | '0' |
| `separateur1`     |     |     |     |     |     |     |     | '/' |     |     |
| `mois[2]`         |     |     |     |     |     | '3' | '0' |     |     |     |
| `separateur2`     |     |     |     |     | '/' |     |     |     |     |     |
| `annee[4]`        | '3' | '2' | '0' | '2' |     |     |     |     |     |     |

# TYPEDEF

Le mot cle `typedef` permet d'eviter de repeter `struct` et/ou `union` lors des declarations de structures/unions.

```c
typedef struct {
    
    /* Membres */

} NomStructure;
```

**Utilisation :**

```c
NomStructure MaStructure; // Le mot struct n'est plus necessaire
```

# ARGUMENTS VARIABLES

Il est possible de faire en sorte que le nombre d'arguments soit variables.

## Depedance

```c
#include <stdarg.h>
```

## Definition

On met `...` en arguments pour dire que les arguments seront variables.

```c
void fonction(int nb_args, ...); // Fonction qui contiendra nb_args arguments
```

> **IMPORTANT!**  
> Il faut indiquer en premier argument le nombre d'arguments possibles

```c
void fonction(int nb_args, ...) {

    va_list arg_ptr;  // Init une variable de type va_list
    // Ce cointeur va nous permettre de recuperer les arguments

    va_start(arg_ptr, nb_args); // Init arguments variables
    // Il faut tout de meme connaitre le nombre d'arguments
    // Donc on l'indique

    // Variable recuperant la valeur de l'argument dans son type
    type valeur = va_arg(arg_ptr, type); // retourne la valeur de l'argument
    // Il faut preciser le type, il doit etre identique au type de notre variable
    // Le pointeur va se deplacer pour le prochain argument a recuperer

    va_end(arg_ptr); // Fin de la recuperation d'arguments (Destruction de arg_ptr)

}
```

> Par convention on nomme la variable de type va_list `arg_ptr` .

**Exemple :**

```c
float moyenne(int nb_args, ...) {

    va_list arg_ptr;

    va_start(arg_ptr, nb_args);

    for(int i=0; i < nb_args; i++) total += va_arg(arg_ptr, int);

    va_end(arg_ptr);

    return ((float)total/nb_args);
}
```

# STRING.H

## strlen

Connaitre la longueur d'une chaine de caractere sans compter le caractere de fin `\0` .

```c
strlen(chaine);
```

## strcpy

Copie une chaine dans une autre.

```c
strcpy(chaineDest, chaineSrc);
```

> La chaine de destination doit etre plus grande que celle a copier.

## strcmp

Compare les chaines et retourne zero si les chaines sont identiques, -1 si la deuxieme est plus grande et 1 si la premiere est plus grande.

```c
strcmp(chaineDest, chaineSrc);
```

## strcat

Concatener des chaines de caracteres.

```c
strcpy(chaine1, chaine2);
```

# TRIAGE

La fonction `qsort()` permet de trier des elements par rapport a une comparaison.

```c
qsort...
void *qsort(const void *tab, size_t nb_elem, size_t sizeof_elem, int (*compare)(const void*, const void*));
```

| Parametre     | Description                                |
|---------------|--------------------------------------------|
| `*tab`        | Pointeur vers le debut du tableau          |
| `nb_elem`     | Nombre d'elements dans le tableau          |
| `sizeof_elem` | taille de chaque elements                  |
| `*compare`    | Pointeur pour une fonction de comparaison  |

# RECHERCHE

La fonction `bsearch()` permet de rechercher des elements.
Pour cela il divise le tableau en deux et a partir du milieu.
Il definit dans quelle partie l'element se trouve puis
dans cette enieme partie, il redivise en deux
et reproduit la meme etape jusqu'a trouver l'element.

```c
void *bsearch(const void *elem, const void *tab, size_t nb_elem, size_t sizeof_elem, int (*compare)(const void*, const void*));
```
| Parametre     | Description                                |
|---------------|--------------------------------------------|
| `*elem`       | Adresse de l'element a chercher            |
| `*tab`        | Pointeur vers le debut du tableau          |
| `nb_elem`     | Nombre d'elements dans le tableau          |
| `sizeof_elem` | taille de chaque elements                  |
| `*compare`    | Pointeur pour une fonction de comparaison  |

> Le tableau doit etre trie de facon a ce que la fonction de comparaison puis rendre le resultat attendu.

# MATH

La bibliotheque Math contient la plupart des fonctions mathematiques.

```c
#include <math.h>
```

**Quelques fonctions contenues :**

- `cos()` et `acos()`
- `sin()` et `asin()`
- `tan()` et `atan()`
- `exp()`, `log()`, `log10()`, `frexp()`, `ldexp()`
- `cosh()`, `sinh()`, `tanh()`
- `sqrt()`, `ceil()`, `abs()`, `labs()`, `floor()`
- `modf()`, `pow()`, `fmod()`

> *La majorite de ces fonctions retournent en type `double` .*

# ERREURS

## Assert

Assert est une fonction macro qui sert a detecter les problemes d'execution.

```c
#include <assert.h>
```

La fonction `assert()` n'est interpretee par le compilateur **uniquement en mode debug**. Donc est ignoree en mode release.

Elle prend en argument une expression que l'on souhaite traiter.

Si l'expression est fausse, affiche un message d'erreur sur stderr et termine le programme.

La constante symbolique `NDEBUG` desactive la macro `assert()` .

> Ajouter cette ligne dans le `CMakeLists.txt` :
> ```cmake
> add_definitions(-DNDEBUG)
> ```
>
> Sinon le flag pour gcc/g++ :
> ```make
> -DNDEBUG
> ```

## Errno

La bibliotheque `errno.h` definit des macros qui documente les erreurs lors de l'execution du programme.

```c
#include <errno.h>
```

La fonction `perror()` permet d'afficher la derniere erreur sur stderr.

# Fichiers

La bibliotheque `stdio.h` offre des fonctions de manipulation de fichiers.

```c
FILE *file = fopen("nom_fichier.txt", "r/w");

if (!file) {

    perror("Error opening file");
    printf("errno = %d\n", errno);

    if (errno == ENOENT) {
        perror("File not found\n");
    }
    else if (errno == EACCES) {
        perror("Permission denied\n");
    }
    else {
        perror("Unknown error\n");
    }
        
    exit(EXIT_FAILURE);
}

/* Manage file & other */

fclose(file);
```

## Direction

Mode | Signification
-|-
r | lecture
w | ecriture override
a | append, si n'existe pas, creer, si existe, ajoute a la fin
+b | binaire

## Sorties


## Lecture/Ecriture

### Ecriture

```c
fprintf(FILE *file, char *chaine);
```

```c
fputs(FILE *file, char *chaine);
```

```c
fputc(FILE *file, char caractere);
```

```c
fwrite(void *data, int size, int count, FILE *file)
```

### Lecture

```c
fscanf(FILE *file, char *chaine);
```

```c
fgets(FILE *file, char *chaine);
```

```c
fgetc(FILE *file, char caractere);
```

```c
fread(void *data, int size, FILE *file)
```

## Lignes

```c
while (fscanf(file, "%[^\n]\n", chaine) != EOF) {
    printf("%s", chaine);
}
```

# Enum

Enum permet de creer un type de valeurs avec un nom Lisible.

```c
enum type { NOM1, NOM2, ... };
```

Les valeurs sont respectivements assignees en partant de zero et de type `int` .

Il est egalement possible de choisir a partir de quelle valeur ca commence.

**Exemple :**

```c
typedef enum jour { LUNDI=1, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE };
```

> Lundi:1  Mardi : 2, Mercredi 3, etc.

## Incrementation

Pour se ballader numeriquement dans l'enum, on peut incremmenter le type.

**Exemple :**

```c
typedef enum jour { LUNDI=1, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE };

printf("%d", jour + 3);
```

-> `4` *(Valeur de JEUDI)*

