---
author: Lena SAVY-LARIGALDIE
title: COURS 1 - Les bases du langage C
---

# TABLE DES MATIERES
- [TABLE DES MATIERES](#table-des-matieres)
- [PRE-PROCESSEUR](#pre-processeur)
  - [Parametres](#parametres)
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

# CMAKE

## Edition de Liens

Au moment du lien on indique au programme comment fonctionnent les fonctions en liant les bibliotheques objet.

```cmake
add_library(MyLib mylib.c)

add_executable(executable main.c mylib.h)

target_link_libraries(executable PUBLIC MyLib)
```

> *Les headers sont renseignes a la compilation. Ils disent a l'executable qu'elle aura besoin de fonctions mais c'est qu'a l'edition des liens que le corps de celles-ci seront connues par l'executable en liant les fichiers objets.*