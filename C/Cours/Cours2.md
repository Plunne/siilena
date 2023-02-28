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

> On peut directement saisir le nombre d'octets a allouer. 

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

