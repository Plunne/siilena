---
author: Lena SAVY-LARIGALDIE
title: COURS 1 - Les bases du langage C
---

# COURS 1 - Les bases du langage C

Formateur : Paul ERNEST

## TABLE DES MATIERES
- [COURS 1 - Les bases du langage C](#cours-1---les-bases-du-langage-c)
  - [TABLE DES MATIERES](#table-des-matieres)
- [ENVIRONEMENT DE TRAVAIL](#environement-de-travail)
  - [INSTALLATION DES OUTILS](#installation-des-outils)
  - [CL (equivalent de make sur windows)](#cl-equivalent-de-make-sur-windows)
  - [CMAKE](#cmake-1)
- [ETAPES DE LA REALISATION D'UN PROGRAMME](#etapes-de-la-realisation-dun-programme)
  - [Developpement](#developpement)
  - [Compilation](#compilation-1)
  - [Linkage](#linkage)
  - [Execution](#execution-1)
- [3 TYPES D'ERREUR](#3-types-derreur)
- [DEBUG \& RELEASE](#debug--release)
  - [Debug](#debug)
  - [Release](#release)
- [STRUCTURE D'UN PROGRAMME](#structure-dun-programme)
  - [Inclusions](#inclusions)
  - [Declaration de fonction](#declaration-de-fonction)
  - [La fonction main()](#la-fonction-main)
  - [Accolades, blocs d'instructions](#accolades-blocs-dinstructions)
  - [Declaration de variable](#declaration-de-variable)
  - [Definition de fonction](#definition-de-fonction)
  - [Commentaires](#commentaires)
- [POURQUOI LE LANGAGE C ?](#pourquoi-le-langage-c-)
- [CODAGES NUMERIQUES](#codages-numeriques)
- [VARIABLES](#variables)
  - [RAM (Random Acces Memory)](#ram-random-acces-memory)
  - [Regles de nommage](#regles-de-nommage)
  - [Syntaxe](#syntaxe)
  - [Les Types](#les-types)
  - [Bases numeriques](#bases-numeriques)
  - [Constantes](#constantes)
  - [Valeurs negative](#valeurs-negative)
- [OPERATEURS](#operateurs)
  - [Operateurs arithmetiques](#operateurs-arithmetiques)
  - [Operateurs de comparaison](#operateurs-de-comparaison)
  - [Operateurs logiques](#operateurs-logiques)
  - [Operateurs d'affectation](#operateurs-daffectation)
  - [Operateur ternaire](#operateur-ternaire)
- [CHAINES DE CARACTERES](#chaines-de-caracteres)
  - [Table ASCII](#table-ascii)
  - [Caracteres de controle](#caracteres-de-controle)
  - [Echappement de caractere](#echappement-de-caractere)
  - [Specificateurs de conversion](#specificateurs-de-conversion)
- [ENTREE/SORTIE](#entreesortie)
  - [Insertion (scanf)](#insertion-scanf)
  - [Affichage (printf)](#affichage-printf)
  - [Affichage (puts)](#affichage-puts)
- [LES TABLEAUX](#les-tableaux)
  - [A simple dimension](#a-simple-dimension)
  - [A double dimensions](#a-double-dimensions)
- [LES FONCTIONS](#les-fonctions)
  - [LES FONCTIONS EN 3 ETAPES](#les-fonctions-en-3-etapes)
  - [LES FONCTIONS VOID](#les-fonctions-void)
  - [RECURSIVITE](#recursivite)
- [LES STRUCTURES CONDITIONNELLES](#les-structures-conditionnelles)
  - [IF, ELSE, ELSE IF](#if-else-else-if)
  - [BREAK](#break)
  - [SWITCH](#switch)
- [LES BOUCLES CONDITIONNELLES](#les-boucles-conditionnelles)
  - [WHILE](#while)
  - [DO WHILE](#do-while)
  - [FOR](#for)
  - [BREAK](#break-1)
  - [LES BOUCLES INFINIES](#les-boucles-infinies)
- [LES POINTEURS](#les-pointeurs)
  - [Declaration](#declaration-4)
  - [Valeur de la variable](#valeur-de-la-variable)
  - [Adresse de la variable](#adresse-de-la-variable)
  - [Adresse du pointeur](#adresse-du-pointeur)
  - [Incrementation](#incrementation)
  - [Equivalence avec les crochets de tableau](#equivalence-avec-les-crochets-de-tableau)
  - [Soustraction d'adresses](#soustraction-dadresses)
- [PORTEE DES VARIABLES](#portee-des-variables)
  - [Variables Globales](#variables-globales)
  - [Variables Locales](#variables-locales)
  - [Variables Externes](#variables-externes)
- [VARIABLES STATIQUES](#variables-statiques)
- [ALLOCATION DYNAMIQUE](#allocation-dynamique)
  - [Malloc](#malloc)
  - [Free](#free)
- [LEXIQUE](#lexique)

# ENVIRONEMENT DE TRAVAIL

## INSTALLATION DES OUTILS

### CMake

Metalanguage

Permet de generer une chaine de compilation.

- Installer CMake (cmake.org)
- Lors de l'installation, ajouter la variable d'environnement (System PATH)

### Visual Studio Community

IDE

- Installer Visual Studio Community
- Lors de l'installation, cocher la suite Developpement C/C++.
- Ajouter `cl` aux variables d'environement.
  
## CL (equivalent de make sur windows)

### Compilation

Creer un fichier objet de `HelloWorld.c` en `HelloWorld.obj` .
Cree aussi un executable `HelloWorld.exe` .

```sh
cl HelloWorld.c
```

### Execution

Executer l'application `HelloWorld.exe` .

```sh
HelloWorld.exe
```

### Recompiler

**IMPORTANT!** Il est important de recompiler le code apres chaque modification afin de verifier le bon fonctionnement.


## CMAKE

Cree un environement pour developper sur n'importe quel systeme d'exploitation.

### CMakeLists.txt

Fichier de configuration minimaliste.

```
cmake_minimum_required(VERSION 3.14)

project(Projet_Langage_C)

set(CMAKE_C_STANDARD 11)

add_executable(HelloWorld HelloWorld.c)
```

Le code ci-dessus :
- Choisit la version de CMake
- Choisit le nom du projet
- Choisit le langage
- Choisit le nom de l'executable et le fichier source

### Dossier build

Creer un dossier `build` .

### Generer le projet

![](https://raw.githubusercontent.com/Plunne/siilena/main/C/Cours/images/cmake1.PNG)

### Ouvrir le projet dans Visual Studio

Les projets Visual Studio ont comme extension `.sln` .

Aller dans le dossier build et lancer avec Visual Studio le fichier `Projet_Langage_C.sln` .


# ETAPES DE LA REALISATION D'UN PROGRAMME 

`(1) DEVELOPPEMENT` -> `(2) COMPILATION` -> `(3) LINKAGE` -> `(4) EXECUTION`

## Developpement

Developpement du programme en code interpretable par l'humain.

## Compilation

Convertir le code interpretable (ASM, C, C++, etc.) en un code machine (binaire, fichiers objet ".o").

## Linkage

Cherche les fichiers objets contenant les fonctions externes utlisees dans le programme.

## Execution

Application executable.

# 3 TYPES D'ERREUR

- Erreur de code
- Erreur de compilation
- Erreur de linkage

# DEBUG & RELEASE

## Debug

Le mode Debug permet de debugguer l'executable. Pour cela, l'executable doit contenir les informations supplementaires necessaires au debug et donc l'executable est plus lourd.

## Release

A contrariot, le mode release ne permet pas de debugguer, en revanche ne contenant pas les informations de debug il est beaucoup leger.
C'est le mode que l'on utilise pour le deploiement final de notre executable car plus optimise.

# STRUCTURE D'UN PROGRAMME

## Inclusions

Importation de fichiers d'en-tete. Ces fichiers contiennent des declarations de fonctions et variables externes.

## Declaration de fonction 

Prototype de fonction.

## La fonction main()

Entree du programme.

- Il y en a **obligatoirement 1!**
- Il faut une accolade ouvrant et une fermante.

## Accolades, blocs d'instructions

Les instructions se codent dans des accolades.

## Declaration de variable

Allocation memoire pour stocker une valeur et attribution de son alias.

## Definition de fonction

Portion de code independante (sous-programme).

## Commentaires

Code non interprete a la compilation aidant a la comprehension d'un programme.

# POURQUOI LE LANGAGE C ?

- Souple et Puissant
- Facile a porter d'une plateforme a l'autre
- Syntaxe legere (contient peu de mots-cles)
- Langage modulaire

# CODAGES NUMERIQUES

A venir...

# VARIABLES

Une variable est un emplacement memoire de la RAM reserve pour stocker une valeur.

## RAM (Random Acces Memory)

Partie de la memoire de l'ordinateur ou l'on peut stocker des informations temporaires (variables par exemple).
Les donnees/informations sont rangees/organisees avec un systeme d'adresses.

## Regles de nommage

- Lettres et Chiffres uniquement
- Commence par une lettre minuscule
- Sensible a la casse (Majuscule != Minuscule)
- Pas de mot cle

## Syntaxe

```c
type nom = valeur;
```

## Les Types

Les types determinent le type et la taille du contenu des variables.

### Le signe

Le signe determine l'interpretation de la valeur, si on la veut strictement positive ou si l'on a besoin de valeurs negatives.

- `signed` : valeur signee, le signe +/- est determine grace au MSB (bit de poids fort)
- `unsigned` : valeur non-signee, le nombre se determine sur l'entierete des bits

#### Types signed

| Type                           | Octets | Valeur Minimale -> Valeur Maximale                           |
|:-------------------------------|:------:|:------------------------------------------------------------:|
| `signed char`                  | 1      | `-128` -> `127`                                              |
| `signed short`                 | 2      | `-32 768` -> `32 767`                                        |
| `signed int` (>=16 bits)       | 2      | `-32 768` -> `32 767`                                        |
| `signed int` (>=32 bits)       | 4      | `-2 147 483 648` -> `-2 147 483 647`                         |
| `signed long` (>=32 bits)      | 4      | `-2 147 483 648` -> `-2 147 483 647`                         |
| `signed long long` (>=64 bits) | 8      | `−9 223 372 036 854 776 000` -> `9 223 372 036 854 776 000`  |

#### Types unsigned

| Type                             | Octets | Valeur Minimale -> Valeur Maximale   |
|:---------------------------------|:------:|:-------------------------------------|
| `unsigned char`                  | 1      | `0` -> `255`                         |
| `unsigned short`                 | 2      | `0` -> `65 535`                      |
| `unsigned int` (>=16 bits)       | 2      | `0` -> `65 535`                      |
| `unsigned int` (>=32 bits)       | 4      | `0` -> `4 294 967 295`               |
| `unsigned long` (>=32 bits)      | 4      | `0` -> `4 294 967 295`               |
| `unsigned long long` (>=64 bits) | 8      | `0` -> `18 446 744 073 709 552 000`  |

### Types flottants

Les types flottants permettent d'utiliser de stocker des valeurs a virgule.

| Type          | Octets | Precision                  |
|:--------------|:------:|:---------------------------|
| `float`       | 4      | Simple precision           |
| `double`      | 8      | Double precision           |
| `long double` | 10     | Double precision etendue   |

Precisions sur la structure d'un `float` :

- 1 bit - Signe : Positif ou Negatif
- 8 bits - Exposant : Valeur de l'exposant de la puissance 10 (emplacement de la virgule)
- 23 bits - Mantisse : Valeur a afficher

## Bases numeriques

Prefixes des bases numeriques lors de l'affectation d'une valeur a une variable.

- Decimal (par defaut) : `0d`
- Hexadecimal : `0x`
- Binaire : `0b`
- Octal : `0`

## Constantes

### Constantes symboliques

Evite de declarer une variable pour une valeur reutilisee qui ne changera pas a l'execution.

``` c
#define NOM valeur 
```

### Constantes litterales

Empeche la modification.

- Pour la securite, s'assurer que personne puisse l'affecter.
- Par convention, pour ameliorer la comprehension du code.

``` c
const type nom = valeur;
```

> *Une constante symbolique prendra moins de place dans la pile mais en prendra plus dans le fichier objet
> tandis qu'une constante litterale prendra plus de place dans la pile mais n'en prendra moins dans le fichier objet.*

## Valeurs negative

La valeur d'une variable evolue d'un maniere speciale.

Elle part de `0` jusqu'a la valeur `maximale` puis redescend d'un coup a la valeur `minimale` jusqu'a rejoindre `-1`.

Pour un char :

`0` -> `127` -> `-128` -> `-1`

# OPERATEURS

## Operateurs arithmetiques

### Classiques

- Addition : `+`
- Soustraction : `-`
- Multiplication : `*`
- Division : `!=`
- Modulo : `%`

### Incrementation/Decrementation
  
#### Incrementation :

`i++` -> instruction puis i+1

`++i` -> i+1 puis instruction

#### Decremenation :

`i--` -> instruction puis i-1

`--i` -> i-1 puis instruction 

**Exemple :**

``` c
int a, b;
a = b = 5;
printf("%d %d", --i, i--);
printf("%d %d", --i, i--);
printf("%d %d", --i, i--);
printf("%d %d", --i, i--);
printf("%d %d", --i, i--);
```

-> `5 4`

a=4, b=4

-> `4 3`

a=3, b=3

-> `3 2`

a=2, b=2

-> `2 1`

a=1, b=1

-> `1 0`

a=0, b=0

### Hierarchie des operateurs

1. Incrementation, Decrementation
2. Produit, Division, Modulo
3. Addition, Soustraction

## Operateurs de comparaison

Operateurs pour comparer 2 valeurs.

Retourne `1` si la comparaison est `vraie` sinon retourne `0` .

### Inferieur/Superieur

- Inferieur : `<`
- Superieur : `>`
- Inferieur ou egal : `<=`
- Superieur ou egal : `>=`

### Egalite/Difference

- Egalite : `==`
- Difference : `!=`

### ET & OU Logique

Operateurs logiques permettant de comparer 2 condtions.

- ET : `&&` (SI **les 2 conditions** sont vraies ALORS retourne 1)
- OU : `||` (SI **au moins une** condition est vraie ALORS retourne 1)

### NON Logique

Retourne `1` si la condtion est `fausse` ou le resultat `=0` .

- NON : `!`

## Operateurs logiques

## Operateurs d'affectation

Affecte une variable en realisant une operation sur elle meme.

- Addition : `+=`
- Soustraction : `-=`
- Multiplication : `*=`
- Division : `/=`
- Modulo : `%=`

## Operateur ternaire

`variable` = `expression` ? `si` : `sinon`

``` c
z = (x > y) ? x : y
```

Equivaut a :
``` c
if (x > y)
    z=x;
else
    z=y;
```

# CHAINES DE CARACTERES

Une chaine de caracteres est un tableau de caracteres (char) pour gerer du texte aisement.

**IMPORTANT!** Elles se finissent toujours (dernier element du tableau) par le caractere `\0` .

## Table ASCII

A Venir...

## Caracteres de controle

Les ordres de controle sont des caracteres predefinis pour controler des chaines de caracteres.

| Caractere | Utilite                                    |
|:---------:|--------------------------------------------|
| `\n`      | Retour a la ligne                          |
| `\t`      | Tabulation                                 |
| `\b`      | Retour arriere (Backspace)                 |
| `\0`      | Fin de chaine                              |
| `\r`      | Retour chariot (deplace en debut de ligne) |

## Echappement de caractere

Les caracteres speciaux relatifs aux chaines doivent etre echapes avec un `\` .

| Caractere | Caractere a afficher     | Affiche |
|:---------:|:------------------------:|:-------:|
| `\\`        | Antislash              | `\`     |
| `\"`        | Guillemet              | `"`     |
| `\'`        | Apostrophe             | `'`     |
| `\?`        | Point d'interrogation  | `?`     |

## Specificateurs de conversion

Pour prendre en compte des donnees de variables dans une chaine de caracteres il nous faut specifier le type de celles-ci.

### Types de donnees

| Caractere | Type/Format                    |
|:---------:|--------------------------------|
| `%d`      | Entier signe                   |
| `%u`      | Entier non-signe (unsigned)    |
| `%f`      | Flottant                       |
| `%c`      | Caractere (char)               |
| `%s`      | Chaine de caractere (string)   |
| `%x`      | hexadecimal (minuscules)       |
| `%X`      | HEXADECIMAL (MAJUSCULES)       |
| `%o`      | Octal                          |
| `%p`      | Adresse (pointer)              |

### Prefixes de tailles

Certains types sont plus longs et juste des extensions de types ci-dessus.

Alors il existe des prefixes de taille a rajouter entre le `%` et le type de la donnee.

| Prefixe | Taille     |
|:-------:|------------|
| `l`     | long       |
| `ll`    | long long  |

**Exemple :**

Pour un entier long signe le specificateur sera `%ld` , pour un long long non-signe `%llu` .

# ENTREE/SORTIE

## Insertion (scanf)

Inserer des valeurs.

**Exemple :**

``` c
int variable1, variable2;               // Declaration de 2 variables
scanf("%d %d", &variable1, &variable2); // Insersion de la valeur de chaque variable au clavier 
```

## Affichage (printf)

Afficher du texte et/ou des valeurs.

**Exemple :**

- En reprennant les 2 variables que l'on a insere ci-dessus.
- En admettant que nous avons insere les valeurs `10` puis `20` .

``` c
printf("Deux nombres : %d %d", variable1, variable2); // Affichage des 2 variables
```

-> `Deux nombres : 10 20` 

## Affichage (puts)

Pour afficher seulement du texte, puts est preferable car :

- Utilise moins de ressources
- Retour a la ligne automatique
- Peut inserer un tableau de caracteres finissant par `\0` .

Cependant il n'accepte pas de valeurs en arguments.

``` c
puts("Chaine de texte uniquement.");
```

``` c
puts(chaine);
```

# LES TABLEAUX

Un tableau contient des elements d'un type definit.


## A simple dimension

### Declaration

Creation d'un tableau

> **A l'initialisation il faut imperativement une valeur constante (qui ne doit pas changer)!**

``` c
type tableau[TAILLE];
```

### Affectation a l'initialisation

``` c
type tableau[TAILLE] = { valeur0, valeur1, valeur2, ... };
```

### Index

``` c
tableau[index];
```

### Affectation a l'index

``` c
tableau[index] = valeur;
```

## A double dimensions

Un tableau qui contient 2 dimensions.

### Declaration

Creation d'un tableau a 2 dimensions

> **Tous comme le simple dimension, a l'initialisation il faut imperativement une valeur constante (qui ne doit pas changer)!**

``` c
type tableau[NOMBRE_LIGNES][NOMBRE_COLONNES];
```

### Affectation a l'initialisation

En prennant pour exemple un tableau a 2 lignes et 3 colonnes.

``` c
type tableau[2][3] = { valeur00, valeur01, valeur02, valeur10, valeur11, valeur12 };
```

L'ideal reste tout de meme d'initialiser avec une 2 boucles for imbriquees.

### Index

``` c
tableau[x][y];
```


### Affectation a l'index

``` c
tableau[x][y] = valeur;
```

### Passer de double dimension a simple dimension

`Ligne` * `Taille de la ligne` + `Colonne`

# LES FONCTIONS

Les fonctions sont des portions de code independantes (Sous-programmes).

> *main(), printf() et scanf() sont des fonctions.* 

## LES FONCTIONS EN 3 ETAPES

`(1) Declaration` -> `(2) Definition` -> `(3) Appel`

### Declaration

Creation du prototype qui determine :

- Le Nom
- Le Type de sa valeur de retour
- Les parametres qu'elle prendra

``` c
type_retour nomFonction(type_arg1 arg1, ..., type_arg2 arg2);
```

### Definition

Implementation du code de la fonction.

``` c
type_retour nomFonction(type_arg1 arg1, ..., type_arg2 arg2)
{
    /* Instructions */

    return valeur_retour; // Valeur de retour de meme type que la fonction (ici : type_retour)
}
```

### Appel

Utilisation de la fonction.

> *Elles doivent imperativement affecter un emplacement memoire du meme type qu'elles.*

``` c
type_retour variable = nomFonction(argument1, ..., argument2);
```

## LES FONCTIONS VOID

Les fonctions void sont des fonctions qui ne retournent aucune valeur, elle servent uniquement a executer des instructions.

### Declaration

``` c
void nomFonction(type_arg1 arg1, ..., type_arg2 arg2);
```

### Definition

Il n'y a donc pas besoin de retourner une valeur.

``` c
void nomFonction(type_arg1 arg1, ..., type_arg2 arg2)
{
    /* Instructions */
}
```

Mais il arrive cependant des fois ou l'on souhaite forcer la sortie d'une fonction void.

``` c
void nomFonction(type_arg1 arg1, ..., type_arg2 arg2)
{
    /* Instructions */

    return; // Alors dans ce cas on fait un return sans aucune valeur
}
```

### Appel

Utilisation de la fonction.

> *Elles s'utilisent seules et ne peuvent affecter un emplacement memoire.*

``` c
nomFonction(argument1, ..., argument2);
```

## RECURSIVITE

Les fonctions recurrentes : fonction qui s'appelle elle-meme.

> **IMPORTANT!**
> Dans une fonction recurrente il faut une condition d'arret.

**Exemple :**

``` c
float recurrence(int n) {
    if (n == 0) return 1;         // Condition d'arret
    return n * recurrence(--1);   // Recurrence
}
```

**Avec operateur ternaire :**

``` c
float recurrence(int n) {
    return (n == 0) ? 1 : n * recurrence(--n);
}
```

# LES STRUCTURES CONDITIONNELLES

## IF, ELSE, ELSE IF

### IF

- **SI** expression **ALORS** instructions

``` c
if (expression)
{
    // instructions
}
```

### ELSE

- **SI** expression **ALORS** instructions
- **SINON** instructions

``` c
if (expression)
{
    // instructions
}
else
{
    // instructions
}
```

### ELSE IF

- *SI* expression *ALORS* instructions
- *SINON SI* expression *ALORS* instructions
- *SINON* instructions

``` c
if (expression)
{
    // instructions
}
else if (expression)
{
    // instructions
}
else
{
    // instructions
}
```

## BREAK

Permet de sortir d'une structure conditionnelle pendant son execution.

``` c
break;
```

## SWITCH

Lorsque l'on a un choix a valeur multiple, il est preferable d'utiliser un `switch` .

A venir...

# LES BOUCLES CONDITIONNELLES

Les boucles sont des blocs de code qui se repetent.

Elle necessitent une condition d'arret. Celle ci est definie dans la syntaxe.

## WHILE

Boucle d'instructions qui se repetent **TANT QUE** sa condition est vrai.

**Declaration :**

- **TANT QUE** l'expression =expression= est vraie
- **FAIRE** les instructions

``` c
while (expression) {

    /* Instructions */

}
```

> *Si l'on souhaite sortir de la boucle a un moment donne en fonction de la valeur d'une variable,
> il faut declarer avec une valeur cette derniere en amont de la boucle.*

**Exemple :**

``` c
int i = 0;
while (i < 5) {
    printf("i : %d\n", i++);
}
```

-> `0`

-> `1`

-> `2`

-> `3`

-> `4`

## DO WHILE

Boucle d'instructions qui se repetent **TANT QUE** sa condition est vrai mais qui execute son code avant tout.

**Declaration :**

- **FAIRE** les instructions
- **PUIS TANT QUE** l'expression `expression` est vraie
- **FAIRE** les instructions

``` c
do
{

    /* Instructions */

}
while (expression);
```

> *Si l'on souhaite sortir de la boucle a un moment donne en fonction de la valeur d'une variable,
> il faut declarer avec une valeur cette derniere en amont de la boucle.*

**Exemple :**

``` c
int i = 0;
do
{
    printf("i : %d\n", i++);
}
while (i < 5);
```

-> `0` (Se passe avant de lire la condition)

-> `1`

-> `2`

-> `3`

-> `4`

## FOR

Fonctionne comme un while mais permet aussi de :

- Realiser une instruction a l'entree de la boucle (generalement pour declarer ou definir un compteur)
- Une expression
- Une instruction de fin de boucle (generalement pour incrementer le compteur)

**Declaration :**

- **POUR** un compteur nomme `compteur` de type `type_cpt` ayant pour valeur de depart `valeur`
- **TANT QUE** l'expression `expression` est vrai
- **ALORS EN FIN DE BOUCLE** executer l'instruction `instruction_de_fin_boucle`

> **Exception :** *Il est aussi possible d'ajouter plusieurs instructions separees par une virgule dans le for.*

``` c
for (type_cpt compteur = valeur; expression; instruction_de_fin_boucle) {

    /* Instructions */

}
```

**Exemple :**

``` c
for (int i = 0; i < 10; i++) {
    printf("i : %d\n", i);
}
```

-> `0`

-> `1`

-> `2`

-> `3`

-> `4`

-> `5`

-> `6`

-> `7`

-> `8`

-> `9`

## BREAK

Tout comme pour les structures conditionnelles, permet de sortir d'une boucle pendant son execution.

``` c
break;
```

## LES BOUCLES INFINIES

Les boucles infinies sont des boucles dont l'on ne sort jamais jusqu'a la fin de l'execution du programme.

### Avec WHILE

``` c
while (1) {

    /* Instructions a l'infinie */

}
```

### Avec FOR

``` c
for (;;) {

    /* Instructions a l'infinie */

}
```

### Vides

**Avec WHILE :**

``` c
while (1);
```

**Avec FOR :**

``` c
for (;;);
```

# LES POINTEURS

Variable contenant l'adresse d'une autre variable d'un type donne.

| Variable | Emplacement Memoire | Valeur         |
|:--------:|---------------------|----------------|
| `var`    | Adresse de var      | Valeur de var  |
| `ptr`    | Adresse de ptr      | Adresse de var |

**Syntaxe :**

| Syntaxe | Valeur         |
|:-------:|----------------|
| `var`   | Valeur de var  |
| `&var`  | Adresse de var |
| `ptr`   | Adresse de var |
| `*ptr`  | Valeur de var  |
| `&ptr`  | Adresse de ptr |

## Declaration

Declaration d'une variable pointeur qui pointe sur l'adresse d'une variable.

``` c
type *pointeur = &addresseVariable;
```

## Valeur de la variable

Valeur de la variable pointee.

``` c
*pointeur
```

## Adresse de la variable

Adresse de la variable pointee.

``` c
pointeur
```

## Adresse du pointeur

Adresse du pointeur.

``` c
&pointeur
```

## Incrementation

A venir...

## Equivalence avec les crochets de tableau

`tableau[n]` = `*(tableau + n)`

**Attention aux parentheses!**

`tableau[n]` != `*tableau + n` (Ici on interagit avec la valeur de l'element (0) du tableau)

## Soustraction d'adresses

# PORTEE DES VARIABLES

Une variable a une duree de vie, cette duree de vie est definie par sa portee, il s'agit de la zone dans laquelle elle existe.

## Variables Globales

Les variables globales sont accessibles dans l'entierete d'un fichier a partir de la ligne ou elle est declaree.

## Variables Locales

Les variables locales ne sont accessibles qu'a l'interieur du bloc d'instructions et a partir de la ligne ou elles sont declarees.

## Variables Externes

Les variables externes sont declarees dans un autre fichier, leur fichier doit etre importe pour qu'elles soient utilisees.

# VARIABLES STATIQUES

Lorsqu'un bloc d'instruction se termine, toutes ses variables locales sont detruites.

Pour palier a cela dans le cas ou l'on veuille conserver la valeur d'une variable au prochain appel de la fonction, il existe le mot-cle `static` .

Ce mot-cle permet a une variable locale de :

- persister en memoire a la fin du bloc
- initialiser la variable qu'au premier appel de la fonction

**Declaration :**

``` c
static type variable = valeur;
```

# ALLOCATION DYNAMIQUE

## Malloc

Dans certains cas on ne connait pas la place que va prendre notre variable en memoire,
alors on utilise `malloc` qui va nous trouver puis retourner l'adresse d'un emplacement memoire adapte.

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

# LEXIQUE

- API : Ensemble d'outils qui permettent de faire l'interface avec un service.
- IDE : Integrated Development Environnement (Environnement de Developpement Integre : Editeur de code avec Debogueur, Compilateur et plein d'outils, c'est notre environement de travail)
