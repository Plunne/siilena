---
author: Lena SAVY-LARIGALDIE
title: COURS - Le Langage d'Assembleur (ASM)
---

# COURS - Le Langage d'Assembleur

Formateur : Paul-Ernest MARTIN

## TABLE DES MATIERES
- [COURS - Le Langage d'Assembleur](#cours---le-langage-dassembleur)
  - [TABLE DES MATIERES](#table-des-matieres)
- [RAM](#ram)
  - [SRAM](#sram)
  - [Calculs](#calculs)
  - [Etapes de communication avec la RAM](#etapes-de-communication-avec-la-ram)
  - [DRAM](#dram)
- [BUS](#bus)
- [CPU](#cpu)
  - [ALU - Arithmetiaue Logic Unit](#alu---arithmetiaue-logic-unit)
  - [FLAG](#flag)
  - [Registre d'instructions](#registre-dinstructions)
  - [Program Counter (PC)](#program-counter-pc)
  - [Etapes](#etapes)
- [LES REGISTRES GENERAUX](#les-registres-generaux)
  - [General purpose registers](#general-purpose-registers)
  - [IO Registers (SFRs)](#io-registers-sfrs)
  - [General purpose RAM](#general-purpose-ram)
- [LABEL](#label)
- [INSTRUCTIONS](#instructions)
  - [LDI](#ldi)
  - [ADD](#add)
  - [ADC](#adc)
  - [LDS](#lds)
  - [STS](#sts)
  - [IN](#in)
  - [OUT](#out)
  - [MOV](#mov)
  - [INC](#inc)
  - [DEC](#dec)
  - [SUB](#sub)
  - [SBC](#sbc)
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
- [BRANCH](#branch)
  - [BNRE](#bnre)
  - [BRSH](#brsh)
- [LA PILE (STACK)](#la-pile-stack)
  - [PUSH](#push)
  - [POP](#pop)
- [CALL \& RET](#call--ret)
  - [CALL](#call)
  - [RCALL](#rcall)
  - [RET](#ret)
  - [HARVARD VS VON NEUMANN](#harvard-vs-von-neumann)
- [DELAY](#delay)
  - [Cycle Machine](#cycle-machine)
  - [Calcul temps des instructions](#calcul-temps-des-instructions)
- [SIGNE](#signe)
- [SHIFT](#shift)
- [Decalage a droite](#decalage-a-droite)
- [Decalage a gauche](#decalage-a-gauche)

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

| Nom        | Definition                     |
|:-----------|--------------------------------|
| `nbReg`    | nombre d'emplacements memoire  |
| `pinsAdd`  | pins d'adresses                |
| `pinsData` | pins de donnees                |
| `nbBits`   | bits de donnees                |

### Calcul des bits de donnees

$$
nbBits = 2^{pinsAdd} \times pinsData
$$

### Calcul nombre d'emplacements

$$
n = \frac{nbBits}{pinsData}
$$

### Calcul pins d'adresses

$$
pinsAdd = \frac{ln(nbReg)}{ln(2)}
$$

**Exemple :**

> 16k emplacement * 4 data
>
> 16k = 2^14
>
> exposant = 14
>
> soit il y a 14 pins

### Calcul pins de donnees

$$
nbData = \frac{nbBits}{2 ^ {pinsAdd}}
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

Indique ce qu'il se passe pendant une operation.

Suivant l'operation, il y a un flag, par exemple pour les retenues mais pas que.

## Registre d'instructions

Lit le programme pour le decouper en petites actions.

## Program Counter (PC)

Compteur qui sait a quelle adresse l'instruction se situe pour savoir quelle instruction faire par la suite.

## Etapes

**Le CPU :**

1. Connait l'adresse d'une instruction, place le Program Counter a cette adresse.

2. Active la memoire (CS) et active un etat Read (OE) ou Write (WE) et recupere l'instruction via le bus de donnees.

3. Place l'instruction dans son registre et la decode.

4. Execute l'instruction

5. Incrementation du Program Counter (Passe a l'instruction suivante)

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

## ADC

Add with carry. ([Voir partie FLAGS](#carry-c))

Fait une addition puis additionne la valeur carry.

```asm
adc Rx, Ry
```

**Exemple :**

```asm
ldi r16, 0xE7
ldi r17, 0x8D
ldi r18, 0x3C
ldi r19, 0x3B

add r16, r17 ; 0xE7 + 0x8D = 0x74
adc r18, r19 ; 0x3C + 0x3B + C = 0x77 + 1 = 0x78
```

> Valeur contenue dans `r16` et `r18` : 0x74 + 0x77 = `0xEC`

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

## SBC

Sub without carry. ([Voir partie FLAGS](#carry-c))

Fait une soustraction puis soustrait la valeur du carry au resultat.

```asm
sbc Rx, Ry
```

**Exemple :**

0x0E1F - 0x0D2F dans r2

```asm
ldi r1, 0x1F
ldi r2, 0x0D
ldi r3, 0x2F
ldi r4, 0x0E

sub r1, r3 ; soustraction des LSB avec retenue (0x1F - 0x0D)
sbc r2, r4 ; soustraction des MSB moins la valeur du carry (0x0D - 0x0E - C)
```

> Valeur contenue dans `r1` et `r2` :

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

---

> **Exercices :**
> 
> 1. V/F, Aucune valeur ne peut etre chargee directement dans la RAM.
>
>    Vrai, on ne peut pas car avec STS on passe par un registre.
>
> 2.
>     ```asm
>     ldi r16, 0x95
>     ```
> 
> 3.
>     ```asm
>     add r18, 0x02
>     ```
> 
> 4.
>     ```asm
>     ldi r16, 0x16
>     ldi r17, 0xCD
>     add r16, r17
>     sts 0x400, r16
>     ```
> 
> 5.
>     0xFF = 255
> 
> 6.
>     r16
> 
> 7.
>     Il ecrit la valeur de r23 dans le registre OCRO
> 
> 8.
>     On met une valeur dans un registre du cpu avec une instruction pour la ram du coup pas bon car moins opti que OUT vu que OCRO est un registre IO.

# FLAGS

Registre d'etat (SREG : Status Register)

## Carry (C)

retenue entre bit 7 et bit 8. (nouvel octet)

## Half carry (H)

retenue entre bit 3 et bit 4. (nouveau demi-octet)

## Zero Flag (Z)

- 1 quand resultat == 0
- 0 quand resultat != 0

---

> **Exercice:**
> 
> 3)
> 9F
> 61
> 
> 1001 1111
> 0110 0001
> 0000 0000
> CZH
> 
> 4)
> 82
> 22
> 
> 1000 0010
> 0010 0010
> 1000 0100
> Aucun
> 
> 5)
> 67
> 99
> 
> 0110 0111
> 1001 1001
> 0000 0000
> CZH

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
add Rx, Ry
```

x : numero du registre Rx  
y : numero du registre Ry

| Valeur              | ADD     | bit 4 r | bit 4 d | bits 0:3 d | bits 0:3 r|
|:-------------------:|:-------:|:-------:|:-------:|:----------:|:---------:|
| 0000 11xy xxxx yyyy | 0000 11 | x       | y       | xxxx       | yyyy      |

Pour add, tous les registres 0 a 31 sont admis.

**Exemple :**

add r16, r17

r16 : 16 = 1 0000  
r17 : 17 = 1 0001

| Valeur              | ADD     | bit 4 16 | bit 4 17 | bits 0:3 16 | bits 0:3 17 |
|:-------------------:|:-------:|:--------:|:--------:|:-----------:|:-----------:|
| 0000 1111 0000 0001 | 0000 11 | 1        | 1        | 0000        | 0001        |


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

# BRANCH

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

-> r16 sera decremente 0x05 fois.

**Exercice :**

Alterner l'etat du PORTB 700 fois.

```asm
            ldi r16, 0x55   ; put 0x55 into r16
            out PORTB, r16  ; store r16 to PORTB
            
            ; init unitsLoop counter
            ldi r17, 0x07   ; put 7 into r17
unitsLoop:
            ; init deciLoop counter
            ldi r18, 0x64   ; put 100 into r17
deciLoop:
            out PORTB, r16  ; blink LED
            com r16         ; reverse LED
            dec r18         ; r18--
            BRNE deciLoop   ; end of deciLoop

            dec r17         ; r17--
            BRNE unitsLoop  ; end of units loop
```

**Equivalence en C :**

```c
char var = 0x55;    // Put 0x55 in var
PORTB = var;        // Store var into PORTB

/* Units Loop */
for (char i=7; i > 0; i--) {

    /* Deci Loop */
    for (char j=100; j > 0; j--) {
        PORTB ^= PORTB; // Reverse LED
    }
}
```

## BRSH

Jump a un label si la valeur du drapeau C de la derniere instruction = 0

> Soit si apres la derniere instruction le resultat depassait 255 alors on retourne a l'etiquette.

```asm
label:
      ; instructions
      BRSH label ; Branch (goto) to label if C = 0
```

**Exercice :**

```asm
            ldi r21, 0x00   ; r21 = 0x00
            ldi r20, 0x79   ; r20 = 0x79
            add r20, 0xF5   ; r20 += 0xF5
            BRLO carry      ; if carry go to add3

nocarry:
            add r20, 0xE2   ; if no carry r20 += 0xE2
            BRLO nocarry256 ; if carry go to carry256

nocarry256:
            ldi r21, 0x01   ; set the carry 256
            jmp end         ; end of program

carry:       
            ldi r21, 0x01   ; set the carry 256
            add r20, 0xE2   ; r20 += 0xE2
            BRLO carry512   ; if carry go to carry512
            jmp end         ; if not end of program

carry512:
            ldi r21, 0x02   ; set the carry 512

end:
```

**Correction :**

```asm
            ldi r20, 0x79   ; init r20 = 0x79
            ldi r21, 0x00   ; init r21 = 0

            ldi r22, 0xF5   ; init r22 = 0xF5
            ldi r23, 0xE2   ; init r23 = 0xE2

            add r20, r22    ; 0x79 + 0xF5 = 0x16E
            BRSH nocarry    ; if no carry go to nocarry
            inc r21         ; if carry, increment r21 (+256)

nocarry:
            add r20, r23    ; 0x16E + 0xE2
            BRSH nocarry2   ; if no carry go to nocarry2
            inc, r21        ; if carry, increment r21 (+512)

nocarry2:
            ; end of program
```

**Equivalence en C :**

```c
char valueLow  = 0x79;  // Put 0x55 in valueLow
char valueHigh = 0x79;  // Put 0x00 in valueHigh

char value2 = 0XF5; // Init value2 = 0xF5
char value3 = 0XE2; // Init value3 = 0xE2

/* Add Value 2 */
if ((valueLow + value2) < 256) {    // If no carry
    valueLow += value2;             // 0x79 + 0xF5 = 0x16E
} else {                            // If carry
    valueLow += value2;             // 0x79 + 0xF5 = 0x16E
    valueHigh++;                    // Increment Value High (+256)
}

/* Add Value 3 */
if ((valueLow + value3) < 512) {    // If no carry
    valueLow += value3;             // 0x16E + 0xE2
} else {                            // If carry
    valueLow += value3;             // 0x16E + 0xE2
    valueHigh++;                    // Increment Value High (+512)
}
```

# LA PILE (STACK)

- Stack Segment (SS) : Section de la RAM (Regitre) permettant de stocker temporairement les informations par le CPU.
- Stack Pointer (SP) : Pointeur qui permet de se deplacer d'adresse en adresse dans la stack.

> La stack fait la taille de la RAM moins les Registres de fonctionnalites propre au MCU. 

## PUSH

Stocke la valeur du registre dans l'emplacement de la stack ou se situe le Stack Pointer et deplace le Stack Pointer vers l'emplacement memoire suivant.

> *Les emplacements vont dans l'ordre decroissant des adresses, donc on decremente la valeur de l'adresse.*

```asm
push, Rd
```

**Exemple :**

```asm
ldi r16, 0xFF
```

**Avant push :**

| SP | Adresse   | Valeur   | Description                          |
|---:|:---------:|:--------:|:-------------------------------------|
|    | 1400      | ?        |                                      |
| >> | **1399**  | **?**    | **Stack Pointer a l'adresse 1399**   |
|    | 1398      | vide     |                                      |
|    | 1397      | vide     |                                      |
|    | 1396      | ...      |                                      |

**Apres push :**

| SP | Adresse   | Valeur   | Description                                          |
|---:|:---------:|:--------:|:-----------------------------------------------------|
|    | 1400      | ?        |                                                      |
|    | 1399      | 0xFF     | *La valeur de r16 est stockee a l'emplacement 1399*  |
| >> | **1398**  | **vide** | **Stack Pointer deplace a l'adresse 1398**           |
|    | 1397      | vide     |                                                      |
|    | 1396      | ...      |                                                      |

## POP

Vide/Libere l'emplacement RAM de sa valeur, decremente l'adresse du Stack Pointer,
stocke la valeur a cette adresse dans le registre CPU cible
puis ecrase cette valeur de la pile.

```asm
pop, Rd
```

**Exemple :**

```asm
ldi r16, 0xFF
push, r16
pop, r16
```

**Apres push et avant pop :**

| SP | Adresse   | Valeur   | Description                                                        |
|---:|:---------:|:--------:|:-------------------------------------------------------------------|
|    | 1400      | ?        |                                                                    |
|    | 1399      | 0xFF     | *La valeur de r16 est stockee a l'emplacement 1399 suite au push*  |
| >> | **1398**  | **vide** | **Stack Pointer a l'adresse 1398 suite au push**                   |
|    | 1397      | vide     |                                                                    |
|    | 1396      | ...      |                                                                    |

**Apres pop :**

| SP | Adresse   | Valeur   | Description                                                                                    |
|---:|:---------:|:--------:|:-----------------------------------------------------------------------------------------------|
|    | 1400      | ?        |                                                                                                |
| >> | **1399**  | **vide** | **Stack Pointer apres pop, stocke la valeur dans r16 puis ecrase la valeur a l'adresse 1399**  |
|    | 1398      | vide     |                                                                                                |
|    | 1397      | vide     |                                                                                                |
|    | 1396      | ...      |                                                                                                |

> **IMPORTANT!**
>
> Les valeurs contenus dans les registres CPU (r0-31) ne sont pas touchees,
> seule la valeur dans le SS ayant ete stockee dernierement est ecrasee suite au pop.

# CALL & RET

Meme mecanique que les fonctions.

## CALL

- Sauvegarde l'adresse suivante du Program Counter dans la RAM (a l'endroit du Stack Pointer) afin de revenir directement a l'instruction suivante apres le RET a la fin du CALL.
- Puis se deplace a une etiquette.

```asm
CALL label
```

> L'instruction CALL prend 4 octets.

## RCALL

Au lieu de sauvegarder une adresse absolue on sauvegarde des adresses allant de -2048 a 2047 par rapport au SP.

Grace a cela l'instruction RCALL ne prend que 2 octets.

## RET

Apres avoir effectue les instructions de l'etiquette appelee par CALL :

- Retourne a l'adresse du Program Counter sauvegardee precedement dans le Stack Segment *(Le PC prend donc cette valeur)* .
- Puis vide l'endroit ou elle etait stockee.

> *Donc continue le programme suite a notre CALL tout comme une fonction en C apres un return.*

```asm
RET
```

## HARVARD VS VON NEUMANN

- Harvard : Commence le fetch suivant apres le fetch.
- Von Neumann : Attend la fin de l'execution pour commencer le fetch suivant.

- Fetch : transformation de l'instruction en machine
- Exec : execution du code machine

| Nom         | t1        | t2        | t3        | t4       | t5        |
|:------------|:---------:|:---------:|:---------:|:--------:|:---------:|
| Von Neumann | `fetch 1` | `exec 1`  | `fetch 2` | `exec 2` | `fetch 3` |
|-            |-          |-          |-          |-         |-          |
| Harvard     | `fetch 1` | `exec 1`  |           |          |           |
|             |           | `fetch 2` | `exec 2`  |          |           |
|             |           |           | `fetch 3` | `exec 3` |           |

# DELAY

Instruction Cycle : temps pour faire une instructions

> *Le temps depend de la frequence de l'oscilateur.*

## Cycle Machine

$$
cycle (s) = \frac{1}{frequence (Hz)}
$$

## Calcul temps des instructions

- $T_{all}$ : Temps total des instructions
- $T_{instruction}$ : Temps de chaque instruction

$$
T_{all} = ( \sum{T_{instruction}} ) \times cycle
$$

# SIGNE

V : Overflow Flag pour nombre positif (carry entre Bit 6 -> Bit 7)
N : Negative Flag pour nombre negatif (si Bit 7 = 1 (bit de signe), alors N=1)

V = 1 si D6=1 & N=0 soit si D6=1 & D7=0
N = 1 si D7=1 & V=0 soit si D7=1 & D6=0

# SHIFT

Decalage de bits.

Operteurs qui decalent les bits d'un nombre de rang vers la gauche ou la droite.

# Decalage a droite

Operateur : `>>`

0000 0010 >> 1  
0000 0001

```asm
ldi r16, 0x02
lsr r16, 0x01
```

> r16 = `0x01`

# Decalage a gauche

Operateur : `<<`

0000 0010 << 1  
0000 0100

```asm
ldi r16, 0x02
lsl r16, 0x01
```

> r16 = `0x04`
