---
author: Lena SAVY-LARIGALDIE
title: COURS 1 - Le Scripting
---

Formateur : COLIN Matthias

# COURS SCRIPTING

## TABLE DES MATIERES

# SCRIPTING

Un script permet de :
- Automatiser des taches
- Manipuler le systeme de fichiers

> *Il est generalement protable d'une plateforme a l'autre.*

# TACHES A AUTOMATISER

- Lancer des programmes
- CI (Continuous Intergration) :  Compiler & Effectuer des test
- Gerer des parametres, l'environnement
- Administration (Base de donnees, Machines)
- Installation/Deploiement (OS, Applications)

> *En soit, un script ne fait pas de calculs.*

# LANGAGES

Un script est generalement ecrit en langage interprete.

## Langage Compile

Un langage compile est compile pour creer un executable utilisable sur une plateforme en particulier.

> **IMPORTANT!** Il necessite d'etre compile sur chaque plateforme.

## Langage Interprete

Un langage interprete n'est pas compile, le script est le programme lui meme ce qui le rend plus portable.

## Quelques langages

- Python
- Shell
- Batch
- Powershell

# PYTHON

Python est un langage interprete Open Source cree en 1989 par Guido Van Rossum.

## Lancer un script

```sh
python script.py
```

**Avec arguments :**

```sh
python script.py arg1 arg2 arg3
```

## Afficher du texte


``` python
print("test")
```

## Traiter des argument

1. Importer la bibliotheque `sys`
    ``` python
    import sys
    ```

2. Manipuler les argument

    2.1 - Tous les arguments
    ``` python
    sys.argv
    ```

    2.2 - Un arguments particulier
    ``` python
    sys.argv[index]
    ```

 > **IMPORTANT!**
> 
> Le premier argument d'un script python est le nom du fichier du script.
> ```
> Arguments ['.\\script.py', 'un', 'deux', 'trois']
> ```

## Tableaux (listes)

Les listes en python sont l'equivalent des tableaux en C, en revanche, les listes ont l'avantage d'etre extensibles.

### Acces aux elements

| Syntaxe   | Valeur de retour              |
|:---------:|:------------------------------|
| `tab[0]`  | Premier element               |
| `tab[n]`  | Element n+1                   |
| `tab[-1]` | Dernier element               |
| `tab[-n]` | Element n a partir de la fin  |

## CLI en fin de Script

Entrer dans l'interprete de commande a la fin de l'execution de notre print.

```sh
python -i script.py
```
