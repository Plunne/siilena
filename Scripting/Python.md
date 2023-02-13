---
author: Lena SAVY-LARIGALDIE
title: COURS 1 - Le Scripting
---

# PYTHON

Formateur : [COLIN Matthias](https://github.com/matthcol/scripting202302)


> Python est un langage interprete Open Source cree en 1989 par Guido Van Rossum.

## TABLE DES MATIERES
- [PYTHON](#python)
  - [TABLE DES MATIERES](#table-des-matieres)
- [LANCER UN SCRIPT](#lancer-un-script)
- [AFFICHER DU TEXTE](#afficher-du-texte)
- [TRAITER DES ARGUMENTS](#traiter-des-arguments)
- [TABLEAUX (LISTES)](#tableaux-listes)
  - [Acces aux elements](#acces-aux-elements)
- [CLI EN FIN DE SCRIPT](#cli-en-fin-de-script)
- [BOOLEEN](#booleen)
- [NONE](#none)
- [INDENTATION](#indentation)
- [STRUCTURES CONDITIONNELLES](#structures-conditionnelles)
  - [IF, ELSE, ELIF](#if-else-elif)
    - [IF](#if)
    - [ELSE](#else)
    - [ELIF](#elif)
  - [MATCH CASE](#match-case)
- [BOUCLES CONDITIONNELLES](#boucles-conditionnelles)
  - [FOR EACH](#for-each)
  - [WHILE](#while)
- [OPERATEURS](#operateurs)
  - [Arithmetiques](#arithmetiques)
  - [Comparaison](#comparaison)
- [BREAK \& CONTINUE](#break--continue)
  - [Break](#break)
  - [Continue](#continue)
- [PASS](#pass)

# LANCER UN SCRIPT

```sh
python script.py
```

**Avec arguments :**

```sh
python script.py arg1 arg2 arg3
```

# AFFICHER DU TEXTE

``` python
print("test")
```

> **On peut aussi eviter de revenir a la ligne.**
> ``` python
> print("test", end=' ')
> ```

# TRAITER DES ARGUMENTS

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

# TABLEAUX (LISTES)

Les listes en python sont l'equivalent des tableaux en C, en revanche, les listes ont l'avantage d'etre extensibles.

## Acces aux elements

| Syntaxe      | Valeur de retour                         |
|:------------:|:-----------------------------------------|
| `tab[0]`     | Premier element                          |
| `tab[n]`     | Element n+1                              |
| `tab[-1]`    | Dernier element                          |
| `tab[-n]`    | Element n a partir de la fin             |
| `tab[:]`     | Liste tous les elements                  |
| `tab[n1:n2]` | Liste les elements de l'element n1 a n2  |

# CLI EN FIN DE SCRIPT

Entrer dans l'interprete de commande a la fin de l'execution de notre print.

```sh
python -i script.py
```

# BOOLEEN

Le booleen est un type a deux etats vrai/faux.

**Syntaxe :**

| Syntaxe | Valeur |
|:-------:|:------:|
| `True`  | 1      |
| `False` | 0      |

# NONE

Le type `None` est une constante attribuee pour une variable a valeur nulle.

# INDENTATION

> **IMPORTANT!**
>
> **En python l'indentation est cruciale, chaque bloc d'instructions est indente precisement d'une tabulation de 4 espaces.**

# STRUCTURES CONDITIONNELLES

## IF, ELSE, ELIF

### IF

- **SI** l'expression `expression` est vraie
- **FAIRE** les instructions

```python
if expression:
    # Instructions
```

### ELSE

- **SI** l'expression `expression` est vraie
- **FAIRE** les instructions
- **SINON**
- **FAIRE** les instructions

```python
if expression:
    # Instructions
else:
    # Instructions
```

### ELIF

- **SI** l'expression `expression` est vraie
- **FAIRE** les instructions
- **SINON SI** l'expression `expression` est vraie
- **FAIRE** les instructions
- **SINON**
- **FAIRE** les instructions

```python
if expression:
    # Instructions
elif:
    # Instructions
else:
    # Instructions
```

## MATCH CASE

```python
match variable:
    case valeur:
        # Instructions
    case _:
        # Instructions par defaut
```
> Il est possible de mettre des expressions dans les cases.

# BOUCLES CONDITIONNELLES

## FOR EACH

- **POUR** Chaque `element`
- **DANS** la variable parcourue `liste`
- **FAIRE** les instructions

```python
for element in liste:
    # Instructions
```

## WHILE

- **TANT QUE** l'expression `expression` est vraie
- **FAIRE** les instructions

```python
while expression:
    # Instructions
```

# OPERATEURS

## Arithmetiques

| Operateur | Description       |
|:---------:|-------------------|
| `+`       | Addition          |
| `-`       | Soustraction      |
| `*`       | Multiplication    |
| `/`       | Division          |
| `//`      | Division entiere  |
| `%`       | Modulo            |
| `**`      | Puissance         |

## Comparaison

| Operateur  | Description         |
|:----------:|---------------------|
| `==`       | Egalite             |
| `!=`       | Difference          |
| `is`       | Meme adresse        |
| `is not`   | Adresse differente  |
| `>`        | Superieur           |
| `<`        | Inferieur           |
| `>=`       | Superieur ou egal   |
| `<=`       | Inferieur ou egal   |
| `in`       | Est dedans?         |
| `not in`   | N'est pas dedans?   |
| `and`      | ET Logique          |
| `or`       | OU Logique          |
| `not`      | NON Logique         |

# BREAK & CONTINUE

## Break

Sortir d'une boucle en cours.

```python
break
```

## Continue

Ne rien faire et continuer la boucle

```python
continue
```

# PASS

Instruction vide.

En python, il est necessaire de marquer le passage dans un bloc avec `pass` .

```python
pass
```