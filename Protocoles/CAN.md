---
author: Lena SAVY-LARIGALDIE
title: Les bus CAN
---

# LE BUS CAN

Formateur : R. ELABED

# TABLE DES MATIERES
- [LE BUS CAN](#le-bus-can)
- [TABLE DES MATIERES](#table-des-matieres)
- [INTRODUCTION](#introduction)
- [COUCHES](#couches)
- [SERVICES](#services)
- [ISO](#iso)
- [ADRESSAGE](#adressage)
- [IDENTIFIANTS](#identifiants)
- [FILTRES](#filtres)
- [4 TYPES DE TRAMES](#4-types-de-trames)
  - [Remote Frame Standard](#remote-frame-standard)
  - [Remote Frame Extended](#remote-frame-extended)
  - [Data Frame](#data-frame)
  - [Data Frame Extended](#data-frame-extended)
- [TRAME](#trame)
  - [Standard](#standard)
  - [Extended](#extended)
  - [IDLE](#idle)
- [ARBITRAGE](#arbitrage)
- [DATA PROTECTION](#data-protection)
  - [Prevening bit errors](#prevening-bit-errors)
  - [Mecanismes anti-erreurs](#mecanismes-anti-erreurs)
  - [Fault Confinement](#fault-confinement)
- [CANFD](#canfd)

# INTRODUCTION

Controller Area Network

Le bus CAN est un reseau ou les unites communiquent en broadcast.

> **IMPORTANT!**  
> Qu'une seule trame est diffusee sur le bus a la fois.

# COUCHES

|   |      Couche      |
|---|:----------------:|
| 5 | ECU upper layers |
| 4 |    Transport     |
| 3 |     Network      |
| 2 |  CAN Controller  |
| 1 | CAN Transceiver  |

# SERVICES

- Physique
- Adressage
- Bus d'acces
- Segmentation
- Protection de donnees
- Synchronisation

# ISO

Le protocole CAN est standardise par l'ISO 11898.

# ADRESSAGE

Les bus CAN fonctionne grace a un systeme de filtrages.

Etant donne que les trames sont a chaque fois diffusees en broadcast, elles sont recues par toutes les ECU.
Cependant chaque ECU n'est pas toujours interesses par la trame en cours de diffusion.
Pour cela un filtre va filtrer les trames avec les identifiants qui l'interessent.

# IDENTIFIANTS

Les identifiants comme evoques precedemment sont des identifiants de messages, il est important de distinguer cela des ECU, l'important en CAN c'est de savoir a quoi correspondent les donnees et si on a besoin de les traiter dans l'ECU en question, donc on leur met un identifiant.

> *On ne cherche donc pas a connaitres les unites qui comuniquent entre-elles ce qui differe de la plus part des protocoles.*

# FILTRES

Le filtrage d'identifiants se base sur des masques suivant la formule ternaire suivante.

```c
((Frame_ID & (Filter_ID & Filter_Mask)) == (Filter_ID & Filter_Mask))? True : False;
```

**Exercice :**

- Filter_Mask = `0x1FFFFFFF0`
- Filter_ID = `0x00001567`

| Frame_ID   | True/False |
|------------|------------|
| 0xFFFFFFFF | true       |
| 0x00000000 | false      |
| 0x0F00156A | true       |
| 0xE0003F70 | true       |
| 0x1FFFFFF0 | true       |
| 0x0000FEFF | false      |
| 0xEFFE0FFF | false      |
| 0xABAB7777 | true       |

# 4 TYPES DE TRAMES

## Remote Frame Standard

Requete avant envoit de message standard

- Format : Standard
- ID : 11bits
- Data : Empty

## Remote Frame Extended

Requete avant envoit de message sur reseau etendu

- Format : Extended
- ID : 29bits
- Data : Empty

## Data Frame

Envoit de message standard

- Format : Standard
- ID : 11bits
- Data : Empty

## Data Frame Extended

Envoit de message sur reseau etendu

- Format : Extended
- ID : 29bits
- Data : Empty

> *Les reseaux etendus on des identifiants plus grands afin de pouvoir en avoir plus. Generalement pour les poids-lourds.*

# TRAME

## Standard

| SOF | ID | RTR | IDE | reserved | DLC |  Data Fields  | Checksum | DEL | ACK | EOF | ITM |
|:---:|:--:|:---:|:---:|:--------:|:---:|:-------------:|:--------:|:---:|:---:|:---:|:---:|
|  1  | 11 |  1  |  1  |    1     |  4  | 64 (8 octets) |    15    |  1  |  1  |  7  |  3  |

- SOF : Start of Frame
- RTR : Remote Transmission Request
- IDE : Identifier Extension
- DLC : Data Lenght Code
- CRC : Checksum
- DEL : Delimiter
- ACK : Acknowledge
- EOF : End of Frame

## Extended

| SOF | ID | SRR | IDE | Extended ID | RTR | reserved | DLC |  Data Fields  | Checksum | DEL | ACK | EOF | ITM |
|:---:|:--:|:---:|:---:|:-----------:|:---:|:--------:|:---:|:-------------:|:--------:|:---:|:---:|:---:|:---:|
|  1  | 11 |  1  |  1  |     16      |  1  |    2     |  4  | 64 (8 octets) |    15    |  1  |  1  |  7  |  3  |

- SRR : Substitude Remote Request (inutile, toujours a 1)

## IDLE

Lors de la phase de repos, pour le bus CAN, le repos est definit a partir de 11 bits a l'etat haut.

Pour eviter d'interpreter une trame ayant 11bits consecutifs a l'etat,
les controleurs CAN effectue un Bitstuffing.

> **Bitstuffing :**
> 
> Les bits (electriques) de la trame sont inverses sur une intervaale reguliaire.
> Generalement tous les 5 bits.

# ARBITRAGE

Lorsque plusieurs trames veulent etre transmises sur le bus en meme temps un mecanisme d'arbitrage definit une priorite.

Par defaut, le plus souvent, la trame en attente avec l'identifiant le plus faible est prioritaire.

**Exercices :**

1 - 0x01F  
2 - 0x021  
3 - 0x103  
4 - 0x7F1  

1 - 0x7AF  
2 - 0x7C0  
3 - 0x7F1  
4 - 0x800  

# DATA PROTECTION

- Prevent bit error
- Handling of remaining bit errors
- Fault confinement

## Prevening bit errors

On peut prevenir les erreurs de bit avec la qualite de la ligne.

- Fibre optique ou Isolation
- Paires torsadees
- Masse commune
- Plus faible debit
- Ligne plus courte
- Reduction de reflections

## Mecanismes anti-erreurs

- Bit monitoring (compare Tx & Rx)
- ACK
- 
- CRC
- Form check

## Fault Confinement

Limite le nombre d'attente d'un identifiant.

Le CAN controller dispose d'un compteur qui s'increment de 8 autant de fois qu'un identifiant n'est pas transmit.

Une fois arrive a son maximum, un drapeau est levee afin d'informer que l'identifiant doit passer.

# CANFD

Le CAN Flexible Data Rate

| SOF | ID | RTR | IDE | FDF | reserved | BRS | ESI | DLC | Data Fields | Checksum | DEL | ACK | EOF | ITM |
|:---:|:--:|:---:|:---:|:---:|:--------:|:---:|:---:|:---:|:-----------:|:--------:|:---:|:---:|:---:|:---:|
|  1  | 11 |  1  |  1  |  1  |    1     |  1  |  1  |  4  |  64 octets  |    15    |  1  |  1  |  7  |  3  |

FDF : FD Format
BRS : Bit Rate Switch
ESI : Error State Indicator

