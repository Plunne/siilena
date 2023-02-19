# MORSE BEEP

Par : Lena SAVY-LARIGALDIE

# TABLE DES MATIERE
- [MORSE BEEP](#morse-beep)
- [TABLE DES MATIERE](#table-des-matiere)
- [I. Objectifs](#i-objectifs)
  - [1.1 - Objectif final](#11---objectif-final)
  - [1.2 - Faire beeper](#12---faire-beeper)
    - [1.2.1 - Connaitre le symbole morse](#121---connaitre-le-symbole-morse)
    - [1.2.2 - Detailler le morse](#122---detailler-le-morse)
    - [1.2.3 - Recuperer le symbole morse](#123---recuperer-le-symbole-morse)
    - [1.2.4 - Convertir le caractere en morse](#124---convertir-le-caractere-en-morse)
  - [1.3 - Connaitre le caractere](#13---connaitre-le-caractere)
    - [1.4 - Recuperer la chaine](#14---recuperer-la-chaine)
- [II. ORDRE DES OBJECTIFS](#ii-ordre-des-objectifs)
- [III. Fonctions ou Variables](#iii-fonctions-ou-variables)
  - [3.1 - Creer un message](#31---creer-un-message)
  - [3.2 - Recuperer un caractere](#32---recuperer-un-caractere)
  - [3.3 - Convertir en morse](#33---convertir-en-morse)
  - [3.4 - Separer le caractere morse](#34---separer-le-caractere-morse)
  - [3.5 - Assigner un timer et etat](#35---assigner-un-timer-et-etat)
  - [3.6 - Faire Beeper](#36---faire-beeper)

# I. Objectifs

## 1.1 - Objectif final

Faire beeper en morse chaque caractere provenant d'une chaine de caractere string.

## 1.2 - Faire beeper

Il faut une frequence et une duree.

Pour cela il faut savoir quel symbole morse transmettre.

### 1.2.1 - Connaitre le symbole morse

- Quels sont les symboles morse?
- Leur etat?
- Leur duree?
- Leur timer?

| Symbole | Etat | Duree    | Timer       |
|:-------:|:----:|:---------|:-----------:|
| `.`     | HIGH | Courte   | `timer1_ms` |
| `_`     | HIGH | Moyen    | `timer2_ms` |
| `/`     | LOW  | Long     | `timer3_ms` |
| ` `     | LOW  | Courte   | `timer1_ms` |

### 1.2.2 - Detailler le morse

Pour jouer le morse avec les timers il faut separer le caractere morse.

### 1.2.3 - Recuperer le symbole morse

Pour separer il faut deja recuperer le symbole morse.

### 1.2.4 - Convertir le caractere en morse

Le symbole morse est a l'origine un caractere.

Il faut donc le convertir en morse.

## 1.3 - Connaitre le caractere

Pour connaitre le caractere il faut le recuperer a partir d'une chaine.

### 1.4 - Recuperer la chaine

Pour pouvoir extraire le caractere d'une chaine il faut deja avoir la chaine.

Donc creation d'un message.

# II. ORDRE DES OBJECTIFS

1. Creer un message (chaine de caractere)
2. Recuperer un caractere depuis la chaine
3. Convertir ce caractere en morse
4. Separer le caractere morse en chaine de symboles
5. Assigner un etat et un timer aux symboles
6. Faire beeper chaque symboles

# III. Fonctions ou Variables

## 3.1 - Creer un message

```c
char * message = "message";
```

## 3.2 - Recuperer un caractere

```c
char character = message[i];
```

## 3.3 - Convertir en morse

```c
char * morse = charToMorse(message[i]);
```

## 3.4 - Separer le caractere morse

```c
char beep = morse[i];
```

## 3.5 - Assigner un timer et etat

```c
void morseToBeep(char beep);
```

```c
switch(beep) {
    case '.':
    case '_':
    case ' ':
}
```

## 3.6 - Faire Beeper

```c
void beepMorse(char * message);
```