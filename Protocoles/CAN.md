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

