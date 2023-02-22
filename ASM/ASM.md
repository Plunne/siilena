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
  - [SRAM](#sram)
    - [Pins d'une SRAM](#pins-dune-sram)
  - [Calculs](#calculs)
    - [Calcul pins d'adresses](#calcul-pins-dadresses)
- [pins](#pins)
    - [Calcul bits de donnees](#calcul-bits-de-donnees)
- [data](#data)
    - [Calcul des emplacements memoire](#calcul-des-emplacements-memoire)
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
- [LABEL](#label)
- [INSTRUCTIONS](#instructions)
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
- [DIRECTIVES](#directives)
  - [EQU](#equ)
  - [INCLUDE](#include)
- [EN LANGAGE MACHINE](#en-langage-machine)
  - [LDI](#ldi-1)
  - [ADD](#add-1)
- [LITTLE/BIG ENDIAN](#littlebig-endian)
  - [Little Endian](#little-endian)
  - [Big Endian](#big-endian)
- [RISC VS CISC](#risc-vs-cisc)
  - [RISC](#risc)
  - [CISC](#cisc)
- [BRANCH, CALL et Stack pointer](#branch-call-et-stack-pointer)
  - [BNRE](#bnre)

# RAM

## SRAM

### Pins d'une SRAM

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


## Calculs

n = nombre d'emplacement

pins = pins d'adresses

data = bit de donnees

### Calcul pins d'adresses

$$
pins
=
\frac {ln(n)}{ln(2)}
$$

**Exemple :**

> 16k emplacement * 4 data = 14 pins d'adresses
>
> 16k = 2^14
>
> exposant = 14
>
> soit il y a 14 pins

### Calcul bits de donnees

$$
data
=
\frac{n}{2 ^ {pins}}
$$

### Calcul des emplacements memoire

$$
n = 2^{pins} \times data
$$

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

# LABEL

Les etiquettes font reference a une instruction afin de pouvoir revenir dessus a l'aide d'un jump (jmp).

```asm
label: ;instruction
```
# INSTRUCTIONS

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

> *On peut aussi additionner directement une valeur.*
>
> ```asm
> ADD Rd, 0x34 ; Additionne 0x34 au registre d
> ```

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
label:
    ;instructions
    jmp label
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

Registre d'etat (SREG : Status Register)

## Carry (C)

retenue entre bit 7 et bit 8. (nouvel octet)

## Half carry (H)

retenue entre bit 3 et bit 4. (nouveau demi-octet)

## Zero Flag (Z)

1 quand resultat == 0
0 quand resultat != 0

3)
9F
61

1001 1111
0110 0001
0000 0000
CZH

4)
82
22

1000 0010
0010 0010
1000 0100
Aucun

5)
67
99

0110 0111
1001 1001
0000 0000
CZH

# DIRECTIVES

Les directive sont un peu similaires aux directives de pre-processeur en C
a la difference que l'on communique avec l'assembleur et non pas le preprocesseur.

## EQU

Principe un peu similaire aux `#defines` en C.

```asm
.EQU COUNT=0x25
ldi r21, COUNT
```
On peut aussi le faire avec des adresses :

```asm
ldi r16, 0x25
.EQU COUNT=0x200
sds COUNT, r16
```

## INCLUDE

Principe un peu similaire aux `#include` en C.

```asm
.INCLUDE "M32DEF.inc"
```

# EN LANGAGE MACHINE


## LDI

```asm
LDI rd, 0xXY
```

`LDI` - `Valeur de X` - `Id du Registre` - `Valeur de Y`

> LDI en binaire vaut `1110`

= 1110 XXXX dddd YYYY

**Exemple :**

Pour l'instruction `LDI r16, 0x56`

> Le registre 16 est a l'indice 0 car les registres 0 a 15 sont reserves.

`LDI` - `0x5` - `0` - `0x6`

= 1110 - 0101 - 0000 - 0110

= 0xE506

## ADD

```asm
add Rd, Rr
```

r : valeur du registre r
d : valeur du registre d

= 0000 11rd dddd rrrr

Pour add, tous les registres 0 a 31 sont admis.

Exemple :

add r16, r17

r16 : 16 = 1 0000
r17 : 17 = 1 0001

= `0000 11` - `bit 4 r16 = 1` - `bit 4 r17 = 1` - `bits[0;3] r16 = 0000` - `bits[0;3] r17 = 0001`

= 0000 1111 0000 0001

# LITTLE/BIG ENDIAN

## Little Endian

Les valeurs les plus hautes sont stockees a l'adresse la plus haute.

## Big Endian

Les valeurs les plus hautes sont stockees a l'adresse la plus basse.

# RISC VS CISC

- CISC : Complex Instruction Set Computer
- RISC : Reduced Instruction Set Computer

## RISC

- Instrctions <= 3Bytes
- Grand nombre de registres
- Prend moins de temps car les instructions sont plus courtes donc leur traduction est plus rapide.

Avantages en depend du poids du programme dans la memoire car la memoire etant moins chere, autant augmenter la memoire.

## CISC

Le CISC est plus cher car il effectue des instructions plus complexes donc une architecture processeur plus complexe.

Il y a differentes tailles de registres d'instructions.

> *Etant donne qu'en embarque on souhaite effectuer des instructions simples,
> On prefere utiliser du RISC car les instructions CISC sont overkill et pas interessantes
> pour leur cout etant donne qu'on comble les lacunes du RISC en ajoutant de la memoire peu chere.*

# BRANCH, CALL et Stack pointer

## BNRE

Jump a un label si la valeur du drapeau Z de la derniere instruction = 0

> Soit si apres la derniere instruction le resultat valait 0 alors on retourne a l'etiquette.

```asm
label:
      ; instructions
      BRNE label ; Branch (goto) to label if Z = 0
```

**Exemple :**

```asm
    ldi r16, 0x05 ; mets 0x05 dans Rd
again:
    dec r16
    BRNE again ; revient a l'etiquette again tant que r16 != 0
```

-> r16 sera decremente 0x50 fois.

