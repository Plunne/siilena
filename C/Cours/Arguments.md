---
author: Lena SAVY-LARIGALDIE
title: COURS 2 - Le langage C plus loin
---

# COURS 2 - Le Langage C plus loin

Formateur : Paul-Ernest MARTIN

## TABLE DES MATIERES
- [COURS 2 - Le Langage C plus loin](#cours-2---le-langage-c-plus-loin)
  - [TABLE DES MATIERES](#table-des-matieres)
- [ARGUMENTS](#arguments)

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