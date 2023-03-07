---
author: Lena SAVY-LARIGALDIE
title: COURS - Les micro-controleurs STM32
---

# COURS - STM32

Formateur : Paul-Ernest MARTIN

## TABLE DES MATIERES
- [COURS - STM32](#cours---stm32)
  - [TABLE DES MATIERES](#table-des-matieres)
- [KEIL uVISION](#keil-uvision)
  - [Packages](#packages)
- [RCC](#rcc)
  - [Enable](#enable)
- [GPIO](#gpio)
  - [CRL \& CRH](#crl--crh)
  - [ODR](#odr)
  - [IDR](#idr)

# KEIL uVISION

## Packages

- STMicroelectronics
  - STM32F1 Series
    - STM32F103
      - STM32F103RB
        - [x] Keil::STM32F1xx_DFP
        - [x] ARM CMSIS
        - [x] Keil::ARM_COmpiler

# RCC

Reset & Clock Control register


## Enable

Avant de commencer a utiliser des fonctionnalites, il faut d'abord activer les horloges par chacune d'entre-elles.

**RCC->APB2ENR**

| 31    | 30    | 29    | 28    | 27    | 26    | 25    | 24    | 23    | 22    | 21    | 20    | 19    | 18    | 17    | 16    |
|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
|       |       |       |       |       |       |       |       |       |       | TIM11 | TIM10 | TIM9  |       |       |       |

| 15    | 14    | 13    | 12    | 11    | 10    | 9     | 8     | 7     | 6     | 5     | 4     | 3     | 2     | 1     | 0     |
|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
| ADC3  | USART | TIM8  | SPI1  | TIM1  | ADC2  | ADC1  | IOPG  | IOPF  | IOPE  | IOPD  | IOPC  | IOPB  | IOPA  |       | AFIO  |

# GPIO

General Purpose Inputs/Outputs

## CRL & CRH

Configuration Register

Pour utiliser des GPIO il faut configurer leur fonctionnalite.

### MODE & CNF

Chaque port se configure sur 4 bits divises en 2 parties MODE & CNF.

#### MODE

La partie configuration du mode est sur 2 bits.

Cette partie permet de configurer si la direction du pin est en entree ou sortie.

| Valeur | Fonction      |
|:------:|---------------|
| `00`   | Input         |
| `01`   | Output 10MHz  |
| `10`   | Output 2MHz   |
| `11`   | Output 50MHz  |

#### CNF

La partie configuration de la fonction est sur 2 bits.

Cette partie permet de configurer la fonctionnalite du pin.

> En fonction de si c'est en mode entree ou sortie.

##### Input

| Valeur | Fonction           |
|:------:|--------------------|
| `00`   | Analog             |
| `01`   | Floating           |
| `10`   | Pull-up/Pull-down  |
| `11`   | *reserved*         |

##### Output

| Valeur | Fonction              |
|:------:|-----------------------|
| `00`   | Push-pull             |
| `01`   | Open-Drain            |
| `10`   | Alternate Push-pull   |
| `11`   | Alternate Open-Drain  |

### CRL

Le registre CRL permet de configurer les pins 0 -> 7 sur un port GPIO.

| 31 - 30 | 29 - 28 | 27 - 26 | 25 - 24 | 23 - 22 | 21 - 20 | 19 - 18 | 17 - 16 |
|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
| CNF7    | MODE7   | CNF6    | MODE6   | CNF5    | MODE5   | CNF4    | MODE4   |

| 15 - 14 | 13 - 12 | 11 - 10 | 9 - 8   | 7 - 6   | 5 - 4   | 3 - 2   | 1 - 0   |
|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
| CNF3    | MODE3   | CNF2    | MODE2   | CNF1    | MODE1   | CNF0    | MODE0   |

### CRH

Le registre CRH permet de configurer les pins 8 -> 15 sur un port GPIO.

| 31 - 30 | 29 - 28 | 27 - 26 | 25 - 24 | 23 - 22 | 21 - 20 | 19 - 18 | 17 - 16 |
|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
| CNF15   | MODE15  | CNF14   | MODE14  | CNF13   | MODE13  | CNF12   | MODE12  |

| 15 - 14 | 13 - 12 | 11 - 10 | 9 - 8   | 7 - 6   | 5 - 4   | 3 - 2   | 1 - 0   |
|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
| CNF11   | MODE11  | CNF10   | MODE10  | CNF9    | MODE9   | CNF8    | MODE8   |

## ODR

Output Data Register

Ce registre permet d'ecrire un etat sur un GPIO en mode sortie.

| Valeur | Etat  |
|:------:|-------|
| `0`    | LOW   |
| `1`    | HIGH  |

| 31    | 30    | 29    | 28    | 27    | 26    | 25    | 24    | 23    | 22    | 21    | 20    | 19    | 18    | 17    | 16    |
|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
|       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |

| 15    | 14    | 13    | 12    | 11    | 10    | 9     | 8     | 7     | 6     | 5     | 4     | 3     | 2     | 1     | 0     |
|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
| ODR15 | ODR14 | ODR13 | ODR12 | ODR11 | ODR10 | ODR9  | ODR8  | ODR7  | ODR6  | ODR5  | ODR4  | ODR3  | ODR2  | ODR1  | ODR0  |

## IDR

Output Data Register

Ce registre permet de lire un etat sur un GPIO en mode sortie.

| Valeur | Etat  |
|:------:|-------|
| `0`    | LOW   |
| `1`    | HIGH  |

| 31    | 30    | 29    | 28    | 27    | 26    | 25    | 24    | 23    | 22    | 21    | 20    | 19    | 18    | 17    | 16    |
|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
|       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |

| 15    | 14    | 13    | 12    | 11    | 10    | 9     | 8     | 7     | 6     | 5     | 4     | 3     | 2     | 1     | 0     |
|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
| IDR15 | IDR14 | IDR13 | IDR12 | IDR11 | IDR10 | IDR9  | IDR8  | IDR7  | IDR6  | IDR5  | IDR4  | IDR3  | IDR2  | IDR1  | IDR0  |

