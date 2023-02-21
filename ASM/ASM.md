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
    - [Pins propre a la DRAM](#pins-propre-a-la-dram)
- [BUS](#bus)
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

### Pins propre a la DRAM

| Pins  | Fonction                                  |
|:-----:|:------------------------------------------|
| `CAS` | Colonne d'adresses (COLUMN Adress Strobe) |
| `RAS` | Ligne d'adresses (ROW Adress Strobe)      |

> Plus simplement : CAS & RAS permettent de multiplexer

**Exercices :**

1.

a) 14add 8dt SRAM

> 2^14*8

b) 16add 8dt SRAM

> 2^16*8

c) 12add 8dt SRAM

> 2^12 *8

2.

a) 11add 1dt SRAM

> 2^11*1 = 2k

b) 13add 4dt SRAM

> 2^13*4 = 32k

c) 8add 4dt DRAM

> 8dt - CAS - RAS = 6dt
>
> Vu qu'on a 2x 6donnees
>
> 2^(6\*2) \* 4 = 2^12\*4 = 16k

d) 9add 1dt DRAM

> 9dt - CAS - RAS = 7dt
> 
> Vu qu'on a 2x 7donnees
>
> 2^(7\*2) \* 1 = 2^14 \* 1

3.

a) 16k 4dt SRAM

> 16k = 2^14
> 
> exposant 14
> 
> donc 14

b) 256k 4dt DRAM

> 256k = 2^18
> 
> exposant 18
> 
> donc 18
> 
> Mais vu que DRAM
> 
> 18/2 + CAS + RAS = 9 + 1 + 1

# BUS

- Bus de controle : signal pour controler les peripheriques
- Bus d'addresses : selectionner l'adresse
- Bus de donnees : stocker ou recuperer des donnees a l'adresse

**Exercice:**

1. 16pins 8bits

    > 2^16*8=524 288

2. 0x4000 - 0x7FFF Combien de ko dans cette plage d'adresse?

    >  0x4000 - 0x7FFF
    >
    > 0100 0000 0000  0000 - 0111 1111 1111 1111
    >
    > 00xx xxxx xxxx xxxx -> 14bits
    >
    > 2^14 = 16 384

0010 0000

# ASM

