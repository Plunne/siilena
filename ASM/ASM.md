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
- [CPU](#cpu)
  - [ALU - Arithmetiaue Logic Unit](#alu---arithmetiaue-logic-unit)
  - [FLAG](#flag)
  - [Registres](#registres)
  - [Etapes](#etapes)
- [LES REGISTRES GENERAUX](#les-registres-generaux)
  - [General purpose registers](#general-purpose-registers)
  - [IO Registers (SFRs)](#io-registers-sfrs)
  - [General purpose RAM](#general-purpose-ram)
- [ASM](#asm)
  - [LDI](#ldi)
  - [ADD](#add)
  - [LDS](#lds)
  - [STS](#sts)
  - [IN](#in)
  - [OUT](#out)
  - [MOV](#mov)
  - [INC](#inc)
  - [DEC](#dec)
  - [SUB](#sub)
  - [COM](#com)
  - [JMP](#jmp)
- [FLAGS](#flags)
  - [Carry (C)](#carry-c)
  - [Half carry (H)](#half-carry-h)
  - [Zero Flag (Z)](#zero-flag-z)

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

    >  0x4000 -> 0x7FFF
    >
    > 0100 0000 0000  0000 -> 0111 1111 1111 1111
    >
    > 00xx xxxx xxxx xxxx -> 14bits
    >
    > 2^14 = 16 384

    Soustraction :

    > 0x4000 - 0x7FFF = 0x3FFF


# CPU

## ALU - Arithmetiaue Logic Unit

Se charge uniquement des fonctions arithmetiques et logiques.

## FLAG

Indique se qu'il se passe pendant une operation.

Suivant l'operation, il y a un flag, par exemple pour les retenues mais pas que.

## Registres

Memoire.

Registre d'instructions : lit le programme pour le decouper en petites actions.

Program counter : Compteur qui sait a quelle adresse l'instruction ou l'on est se situe pour savoir quelle instruction on fait ensuite.

Registres : Stocke les donnees temporaires.

## Etapes

Le CPU :

1. Connait l'adresse d'une instruction, place le program counter dans cette adresse d'instruction.

2. Active la memoire (CS) et active un etat Read (OE) ou Write (WE) et recupere l'instruction via le bus de donnees.

3. Place l'instruction dans son registre et la decode.

4. Execute l'instruction

5. Incrementation du program counter (Passe a l'instruction suivante)

# LES REGISTRES GENERAUX

## General purpose registers

Donnees temporaires du CPU.

## IO Registers (SFRs)

Configurer les GPIO.

## General purpose RAM

Donnees temporaires de la RAM.

# ASM

## LDI

Affectation (equivalent de `=`)

```asm
LDI Rd, K ; Stocke dans le registre Rd la valeur K
```

- LDI (Load Data Immediatly) :
- Rd : Registre d (entre 16 et 31, car la partie 0 a 15 est reservee)
- K : Valeur 0 a 255 (0 a 255 si registre 8 bits)

Exemple :

```asm
LDI R16, 0x50 ; place la valeur 0x50 dans le registre 16
```

Equivalent en C (PSEUDO CODE! Contexte DIFFERENT!) :

```c
R16 = 0x50; // Place la valeur 0x50 dans R16
```

## ADD

Addition (equivalent du `+=`)

```asm
ADD Rd,Rr ; Ajoute la valeur de Rr a la valeur de Rd
```

Exemple :

```asm
LDI R16, 0x25 ; Affecte le registre R16 avec la valeur 0x25
LDI R17, 0x34 ; Affecte le registre R17 avec la valeur 0x34
ADD R16, R17  ; Additionne la valeur du registre R17 dans le registre R16
```

Equivalent en C (PSEUDO CODE! Contexte DIFFERENT!) :

```c
R16 = 0x25; // Affecte R16 avec la valeur 0x25
R17 = 0x34; // Affecte R17 avec la valeur 0x34
R16 += R17; // Additionne la valeur de R17 dans R16
```

La valeur dans R16 est 0x25 + 0x34 = 0x59

## LDS

Load Direct from data Space

Affectation de valeur a partir d'une adresse.

```asm
LDS Rd, K ; Stocke dans le registre Rd la valeur de l'adresse K
```

Exemple :

```asm
LDI R16, 0x200 ; place la valeur a l'adresse 0x200 dans le registre 16
```

## STS

Store Direct to data Space

Affecte une valeur a un emplacement memoire de la RAM.

```asm
STS K, Rr
```

Exemple :

```asm
STS 0x200, R0 ; Copie la valeur de R0 a l'adresse 0x200 dans la RAM
```

## IN

Lecture d'entree.

```asm
IN R0, PINB ; Lit le PINB et affecte le registre R0 avec cette valeur
```

## OUT

Comme IN mais en sortie

```asm
OUT PORTB, R0 ; Ecrit sur PORTB la valeur du registre R0
```

## MOV

Copie un registre dans un autre

```asm
mov Rd, Rr ; copie Rr dans Rd
```

## INC

Incremente de `+1` le registre

```asm
inc rd ; incremente la valeur de rd de 1
```

## DEC

Decremente de `-1`

```asm
dec rd ; decremente la valeur de rd de 1
```

## SUB

Soustraction (abstraction d'addition complement a 1)

```asm
sub rd, rr ; rd -= rr
```

## COM

Inverse les bits

```asm
com rd ; si rd = 0x55, rd = 0xAA (0101 -> 1010)
```

## JMP

Revenir/Aller a une etiquette.

```asm
etiquette:
    ;instructions
    jmp etiquette
```

Exercices :

1. V/F, Aucune valeur ne peut etre chargee directement dans la RAM.

    Vrai, on ne peut pas car avec STS on passe par un registre.

2.
    ```asm
    ldi r16, 0x95
    out spl, r16
    ```

3.
    ```asm
    add r18, 0x02
    ```

4.
    ```asm
    ldi r16, 0x16
    ldi r17, 0xCD
    add r16, r17
    sts 0x400, r16
    ```

5.
    0xFF = 255

6.
    r16

7.
    Il ecrit la valeur de r23 dans le registre OCRO

8.
    On met une valeur dans un registre du cpu avec une instruction pour la ram du coup pas bon car moins opti que OUT vu que OCRO est un registre IO.


# FLAGS

## Carry (C)

retenue entre bit 7 et bit 8. (nouvel octet)

## Half carry (H)

retenue entre bit 3 et bit 4. (nouveau demi-octet)

## Zero Flag (Z)

1 quand resultat == 0
0 quand resultat != 0


