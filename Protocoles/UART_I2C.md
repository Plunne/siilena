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
2. Donnee (7, 8, 9 bits / 9bits uniquement en utilisant la parite comme donnee)
3. Bit de PARITE (si 1 nombres de bit a 1 doit etre pair, si 0 le nombre de bit a 0 doit etre pair)
4. Bits de STOP (1 ou 2)

|START|D0|D1|D2|D3|D4|D5|D6|D7|PARITY|STOP|
|-|-|-|-|-|-|-|-|-|-|-|

## Debit

Generalement 9600 Bauds (bit par seconde) ou 115200 Bauds pour le debit le plus rapide.

