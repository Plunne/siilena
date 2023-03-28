---
author: Lena SAVY-LARIGALDIE
title: Les protocoles serie UART, I2C & SPI
---

# LES PROTOCOLES UART, I2C & SPI

Formateur : Fadhel SASSI

# TABLE DES MATIERES
- [LES PROTOCOLES UART, I2C \& SPI](#les-protocoles-uart-i2c--spi)
- [TABLE DES MATIERES](#table-des-matieres)
- [INTRODUCTION](#introduction)
  - [Communication serie](#communication-serie)
  - [Une communication peut etre](#une-communication-peut-etre)
  - [Serie VS Parallele](#serie-vs-parallele)
- [UART](#uart)
  - [Trame](#trame)
  - [Debit](#debit)
- [I2C](#i2c)
  - [Caracteristiques](#caracteristiques)
  - [2 Lignes SCL \& SDA](#2-lignes-scl--sda)
  - [Debits possibles](#debits-possibles)
  - [NACK](#nack)
  - [Trame](#trame-1)
- [SPI](#spi)
  - [Caracteristiques](#caracteristiques-1)
  - [4 Lignes](#4-lignes)
  - [Debit](#debit-1)
  - [Fonctionnement](#fonctionnement)
  - [Trame](#trame-2)

# INTRODUCTION

## Communication serie

- Sequentiel
- Unite de transmission : Bit
- Donnees auxiliaires pour la sync

## Une communication peut etre

### Synchronicite

- Synchrone : meme debit sur les deux unites
- Asynchrone : les deux lignes ont un debit different

### Direction

- Bi-directionnelle : dans les deux sens Tx1->Rx2 Rx1<-Tx2 
- uni-directionnelle : dans les deux sens Tx1->Rx2

### Simultaneite

- Full Duplex : communication bi-directionnelle simultanee
- Half Duplex : communication bi-directionnelle non-simultanee
- Simplex : communication uni-directionnelle

### Diffusion

- Unicast : communication avec 1 seule unite
- Multicast : communication avec plusieurs unites

## Serie VS Parallele

- Parallele : Donnee repartie sur autant de cable que de bits
- Serie : Donnee transmise sequentiellement sur une seule ligne

# UART

Universal Asynchronous Transmitter Receiver

| Unite A | Unite B |
|---------|---------|
| Tx      | Rx      |
| Rx      | Tx      |
| GND     | GND     |

## Trame 

1. Bit de START
2. Donnee (de 5 a 8 bits, generalement 8 ou 9 bits / 9bits uniquement en utilisant la parite comme donnee)
3. Bit de PARITE (si 1 nombres de bit a 1 doit etre pair, si 0 le nombre de bit a 0 doit etre pair)
4. Bits de STOP (1 ou 2)

|START|D0|D1|D2|D3|D4|D5|D6|D7|PARITY|STOP|
|-|-|-|-|-|-|-|-|-|-|-|

## Debit

Generalement 9600 Bauds (bit par seconde) ou 115200 Bauds pour le debit le plus rapide, il en existe d'autres.

# I2C

Inter Integrated Circuit

## Caracteristiques

- Bi-directionnel
- Multi-point
- Synchrone
- Half-Duplex

## 2 Lignes SCL & SDA

- SCL : Serial Clock
- SDA : Serial Data

## Debits possibles

- 100kb/s
- 400kb/s
- 1Mb/s
- 3.4Mb/s

## NACK

Le NACK est envoye pour terminer une transmission.

## Trame

### Lecture

1. Start
2. Adresse Slave
3. ACK Slave
4. Registre Slave
5. ACK Slave
6. Data

# SPI

Serial Peripheral Interface

## Caracteristiques

- Bi-directionnel
- Multi-point
- Synchrone
- Full-Duplex

## 4 Lignes

- SCK : Serial Clock
- CS : Chip Select
- MOSI : Master Out, Slave In
- MISO : Master In, Slave Out

## Debit

1 -> 20 MHz

## Fonctionnement

La ligne CS permet de selectinner un esclave en la mettant a l'etat haut.

> *Il faut autant de ligne CS que d'esclave.*

## Trame

C'est une donnee de 8 bits seulement.

