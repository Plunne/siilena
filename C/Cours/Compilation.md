---
author: Lena SAVY-LARIGALDIE
title: COURS 1 - Les bases du langage C
---

# TABLE DES MATIERES
- [TABLE DES MATIERES](#table-des-matieres)
- [PRE-PROCESSEUR](#pre-processeur)
  - [Parametres](#parametres)
  - [Define](#define)
  - [Include](#include)
  - [Compilation Conditionnelle](#compilation-conditionnelle)
  - [Inclusion multiple](#inclusion-multiple)
  - [\_\_DATE\_\_ \& \_\_LINE\_\_](#__date__--__line__)
- [CMAKE](#cmake)
  - [Edition de Liens](#edition-de-liens)


# PRE-PROCESSEUR

Le pre-processeur copie les valeurs des constante symboliques dans le code du programme a la place de leur nom.

**Fichier source `.c` :**

![](https://raw.githubusercontent.com/Plunne/siilena/main/C/Cours/images/preproctest1.PNG)

**Fichier pre_processeur `.i` :**

![](https://raw.githubusercontent.com/Plunne/siilena/main/C/Cours/images/preproctest2.PNG)

> Il gere egalement les inclusions de headers en remplaceant les chemins relatifs par les chemins absolus.

## Parametres

Pour avoir acces aux `.i` il faut activer l'option de pre-traitement d'un fichier.

![](https://raw.githubusercontent.com/Plunne/siilena/main/C/Cours/images/preprocsettings.PNG)

## Define

Avec la directive `#define` il est possible de faire des instructions.

**Exemple :**
```c
#define CARRE(x) (x) * (x)
```

> **INCONVENIANTS!**  
> Cependant cela prend plus de place en memoire (ROM) car cela execute plus d'instruction.

## Include

### Chevrons <>

Cherche les fichiers dans les repertoires d'environnement en priorite.
Si il ne trouve pas, cherche dans le repertoire courant.

> Utilise pour les bibliotheques installees dans le systeme. (Exemple : Bibliotheques Standard)

### Guillemets ""

Cherche les fichiers dans le repertoire courant en priorite.
Si il ne trouve pas, cherche dans les repertoires d'environnement.

> Utilise pour les bibliotheques locales au projet.

## Compilation Conditionnelle

Les structures de controles `#if` `#else` `#elif` `#endif` sont disponibles pour
controler les directives qui seront traitees par le preprocesseur.

**Exemple :**

Par exemple pour l'OS. *(Ces includes sont fictifs pour l'exemple)*

```c
#ifdef LINUX
    #include <linux.h>
#elif WINDOWS
    #include <windows.h>
#endif
```

## Inclusion multiple

- **SI** pas defini
- **ALORS** definit

    ```c
    #ifndef PI
        #define PI 3.14
    #endif
    ```

- **SI** defini
- **ALORS** definit

    ```c
    #ifdef EXP
        #define EXP 2.72
    #endif
    ```

**Ceci est utilise pour les headers :**

```c
#ifndef _HEADER_H
#define _HEADER_H

/* Contenu Header.h */

#endif // _HEADER_H
```

**Alternative plus moderne :**

```c
#pragma once

/* Contenu Header.h */
```

## \_\_DATE\_\_ & \_\_LINE\_\_

- **\_\_DATE\_\_** : Valeur de la date au moment de la compilation.

- **\_\_LINE\_\_**  :Valeur de la ligne de code au moment de la compilation.

# CMAKE

## Edition de Liens

Au moment du lien on indique au programme comment fonctionnent les fonctions en liant les bibliotheques objet.

```cmake
add_library(MyLib mylib.c)

add_executable(executable main.c mylib.h)

target_link_libraries(executable PUBLIC MyLib)
```

> *Les headers sont renseignes a la compilation. Ils disent a l'executable qu'elle aura besoin de fonctions mais c'est qu'a l'edition des liens que le corps de celles-ci seront connues par l'executable en liant les fichiers objets.*
