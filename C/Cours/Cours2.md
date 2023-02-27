---
author: Lena SAVY-LARIGALDIE
title: COURS 2 - Le langage C (Partie 2)
---

# COURS 2 - Le Langage C (Partie 2)

Formateur : Paul-Ernest MARTIN

## TABLE DES MATIERES
- [COURS 2 - Le Langage C (Partie 2)](#cours-2---le-langage-c-partie-2)
  - [TABLE DES MATIERES](#table-des-matieres)
- [ARGUMENTS](#arguments)
- [ALLOCATION DYNAMIQUE 2](#allocation-dynamique-2)
  - [Dependance](#dependance)
  - [Calloc](#calloc)
  - [Realloc](#realloc)
- [BLOCS MEMOIRE](#blocs-memoire)
  - [Dependance](#dependance-1)
  - [Memset](#memset)
  - [Memcpy](#memcpy)
  - [Memove](#memove)

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

# ALLOCATION DYNAMIQUE 2

[Premiere partie](https://github.com/Plunne/siilena/blob/main/C/Cours/Cours1.md#allocation-dynamique)

## Dependance

```c
#include <stdlib.h>
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

## Dependance

```c
#include <string.h>
```

## Memset

Permet d'initialiser une partie de la memoire par une valeur sur une taille definie.

```c
memset(*dest, caractere, taille);
```

## Memcpy

Copier la memoire d'un tableau dans un autre sur une taille definie.

```c
memcpy(*destination, *source, taille);
```

## Memove

Copier la memoire d'un tableau dans un autre sur une taille definie en verifiant le recouvrement (permet d'eviter de se copier mutuellement si les adresses sont proches car le resultat peut etre degrade)

```c
memmove(*destination, *source, taille);
```

