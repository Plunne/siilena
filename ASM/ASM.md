---
author: Lena SAVY-LARIGALDIE
title: COURS - Le Langage d'Assembleur (ASM)
---

# COURS - Le langage d'Assembleur

Formateur : Paul-Ernest MARTIN

## TABLE DES MATIERES
- [COURS - Le langage d'Assembleur](#cours---le-langage-dassembleur)
  - [TABLE DES MATIERES](#table-des-matieres)
- [RAM](#ram)
  - [Pins d'une SRAM](#pins-dune-sram)
  - [Etapes de communication avec la RAM](#etapes-de-communication-avec-la-ram)
    - [Ecriture](#ecriture)
    - [Lecture](#lecture)
  - [DRAM](#dram)
    - [Pins propre a la SRAM](#pins-propre-a-la-sram)
- [ASM](#asm)

# RAM

**Exercice :**

> 16k emplacement * 4 data = 14 pins d'adresses
>
> 16k = 2^14
>
> exposant = 14
>
> soit il y a 14 pins

## Pins d'une SRAM

| Pin           | Fonction                                                            |
|:-------------:|:--------------------------------------------------------------------|
| `A0` - `Ax`   | Pins pour coder l'Adresse                                           |
| `IO0` - `IOx` | Pin pour coder les donnees                                          |
| `VCC`         | Tension d'entree                                                    |
| `GND`         | Ground (Masse, 0V)                                                  |
| `CS`          | Chip Select (Selection de la puce memoire par rapport a une autre)  |
| `WE`          | Write Enable (Activation Mode Ecriture seule)                       |
| `OE`          | Output Enable (Activation Mode Lecture seule)                       |

> *WE & OE ne peuvent etre actives en meme temps.*

## Etapes de communication avec la RAM

### Ecriture

1. Selectionner Adresse
2. CS = 1
3. WE = 1

### Lecture

1. Selectionner Adresse
2. CS = 1
3. OE = 1

## DRAM

**Exercice :**

> 16k emplacements x 4 data = 9 pins d'adresses
>
> 16k = 2^14
>
> exposant = 14
>
> 14/2 = 7
>
> 7+2 = 9 pins

### Pins propre a la SRAM

| Pins  | Fonction                                  |
|:-----:|:------------------------------------------|
| `CAS` | Colonne d'adresses (COLUMN Adress Strobe) |
| `RAS` | Ligne d'adresses (ROW Adress Strobe)      |

> Plus simplement : CAS & RAS permettent de multiplexer

# ASM
