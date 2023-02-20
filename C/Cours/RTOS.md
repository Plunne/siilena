---
author: Lena SAVY-LARIGALDIE
title: COURS 2 - Les Systemes d'Exploitation en Temps-Reel (RTOS)
---

# COURS 2 - RTOS

Formateur : Paul-Ernest MARTIN

## TABLE DES MATIERES
- [COURS 2 - RTOS](#cours-2---rtos)
  - [TABLE DES MATIERES](#table-des-matieres)
- [Systemes d'Exploitation en Temps-Reel (RTOS)](#systemes-dexploitation-en-temps-reel-rtos)
  - [3 Familles de RTOS](#3-familles-de-rtos)
  - [Nature des traitements](#nature-des-traitements)
  - [Types d'interactions](#types-dinteractions)
  - [Exigences](#exigences)
  - [Les 3 Categories de RTOS](#les-3-categories-de-rtos)
- [MATERIEL](#materiel)
  - [Bare-metal firmware](#bare-metal-firmware)
  - [RTOS based firmware](#rtos-based-firmware)
  - [RTOS based software](#rtos-based-software)
- [AVANTAGES](#avantages)
- [SUPERLOOP VS RTOS](#superloop-vs-rtos)

# Systemes d'Exploitation en Temps-Reel (RTOS) 

- Repondre a des deadlines.
- Repondre efficacement, juste, sans erreurs, avec de la coherance.

## 3 Familles de RTOS

- **Reactifs :**

    Toujours a l'ecoute des capteurs et reagit lorsqu'il faut (quand la valeur atteint un certain seuil)

- **Transformationnels :**
  
    Ne s'interesse pas trop au monde exterieur mais prend compte des traitements internes (depend surtout des algorihmes)

- **Interactifs :**

    En relation directe avec un utilisateur, (ex: Les jeux-videos), sans intermediaire.

## Nature des traitements

- **Sporadiques :**

    Ponctuel/Spontane (ex: arret d'urgence, interruption)

- **Periodiques :**

    En boucle (ex: acquisition de capteurs)

## Types d'interactions

- **Evenements :** interation exterieure
- **Mesures :** 
- **Commandes :** interaction interne

## Exigences

- **Contraintes temps :** echeance
- **Parallelisme :** multi-tache
- **Previsibilite :** Pas de hasard
- **Surete :** fiabilite

## Les 3 Categories de RTOS

- **Hard Real-Time Systems :**

    > Tolerance Zero, respect des echeances obligatoires. Peut entrainer des pertes materielles importantes ou vivantes.

- **Firm Real-Time Systems :**

    > Tolerance Moyenne, respect de certaines echeances negligeable mais peut entrainer de consequences graves si multiples. Accumalation de deadlines dramatiques mais une peut passer.

- **Soft Real-Time Systems :**

    > Tolerance legere : le non respect d'echeances n'entraine pas de consequences graves, les consequences sont juste au niveau du service. (ex: un bug, des glitchs, ...)

# MATERIEL

Les RTOS sont deployes sur les materiels suivants.

- **ASIC :** Circuit integre specifique a une tache (Pas modifiable).
- **PLD :** Dispositifs de Logique Programmable (CPLD, FPGA)
- **MCU :** Micro-controleurs

## Bare-metal firmware

Coder sans OS, directement en relation avec le materiel, pas d'abstraction materielle (pas de noyaux), programme en boucle infinie, une tache apres l'autre.

## RTOS based firmware

Abstraction materielle minimaliste qui permet de gerer des taches qui peuvent s'effectuer en parallele.

## RTOS based software

Abstraction poussee permettant de gerer des Applications logicielles graphiques par exemple.

# AVANTAGES

Permet d'avoir une abstraction sur des fonctionnalites complexes a implementer.

Avant d'utiliser un RTOS il faut s'assurer d'en avoir un reel besoin, lorsqu'un programme est destine a faire des taches simples, autant s'en passer pour gagner en memoire et de ce fait en place mais aussi en logistique.

Leur point fort se trouve donc dans la capacite a realiser des systemes tres avances en tirant profit de l'abstraction.

**Exemples de fonctionnalites :**

Les Threads, Mutex, Semaphores, ...

# SUPERLOOP VS RTOS

