---
author: Lena SAVY-LARIGALDIE
title: COURS 2 - Les Systemes d'Exploitation en Temps-Reel (RTOS)
---

# COURS - Les RTOS

Formateur : Paul-Ernest MARTIN

## TABLE DES MATIERES
- [COURS - Les RTOS](#cours---les-rtos)
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
- [TACHES](#taches)
  - [Dans un RTOS](#dans-un-rtos)
  - [QUEUES](#queues)
  - [EVENTS](#events)
  - [SEMAPHORES](#semaphores)
  - [ARCHITECTURES](#architectures)
  - [PARAMETRAGE](#parametrage)
- [CODE](#code)
- [TYPES DE NOYAUX](#types-de-noyaux)
  - [Premptif](#premptif)
  - [Non-Premptif (Collaboratif)](#non-premptif-collaboratif)
  - [Rotatif (Round-Robin)](#rotatif-round-robin)
- [PRIORITES](#priorites)
- [ORDONNANCEMENT](#ordonnancement)
  - [Ordonnanceur (Scheduler)](#ordonnanceur-scheduler)
  - [Repartiteur (Dispatcher)](#repartiteur-dispatcher)
- [ALGORITHMES D'ORDONNANCEMENT](#algorithmes-dordonnancement)
  - [RMA - Rate Monotonic Assignment](#rma---rate-monotonic-assignment)
  - [DMA - Deadline Monotonic priority Assignment](#dma---deadline-monotonic-priority-assignment)
  - [EDF - Earliest Deadline First](#edf---earliest-deadline-first)
- [MCU \& MPU](#mcu--mpu)
  - [CPU (Central Process Unit)](#cpu-central-process-unit)
  - [RAM (Random Acces Memory)](#ram-random-acces-memory)
  - [ROM (Read Only Memory)](#rom-read-only-memory)
  - [I/O Ports](#io-ports)
  - [Timer](#timer)
  - [Interrupt](#interrupt)
  - [Serie COM Ports](#serie-com-ports)
- [GPOS VS RTOS](#gpos-vs-rtos)
- [CHOISIR UN MICRO-CONTROLEUR](#choisir-un-micro-controleur)
- [ADDITION BINAIRE](#addition-binaire)
- [COMPLEMENT A 1](#complement-a-1)

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

La Superloop est une methode qui permet de gerer plusieurs taches sans utiliser un RTOS.

Chaque tache est executee dans la boucle principale de maniere sequentielle.

Ces taches sont generalement ecrites sous forme de fonctions et peuvent etre executees a intervales regulieres ou en reponse a des evenements externes.

Elle requiert peu de puissance et realisable a moindre cout tout en etant efficace.

# TACHES

## Dans un RTOS

- Taches simultanees
- Independantes (ont leur propre pile et contexte d'execution)
- Priorisees
- Planifiees
- Peuvent communiquer entre-elles (semaphores, evenementiel, file d'attente)
- Garantit une precision avec fiabilite

## QUEUES

File d'attente (diapo 19)

## EVENTS

Notifications (diapo 20)

## SEMAPHORES

Echanger les infos en ayant une zone de synchronisation en memoire.

Permet a deux taches differentes d'acceder a la meme ressource.

## ARCHITECTURES

- **Mono-tache :** suite de taches
- **Multi-taches :** taches en parallele, besoin d'un ordonnancement

## PARAMETRAGE

TCB : Task Control Block

- Identifiant
- Priorite
- Etat (prete, bloquee, active ou dormante)
- Contexte (compteur qui pointe vers le code, pointeur de pile SP : *Pour qu'un programme continue de s'execute il lui faut sa stack/pile pour savoir ou il en est dans la memoire et une sauvegarde de sa derniere execution pour savoir ou reprendre sa prochaine execution.*)

> C'est un peu comme la carte d'identite d'une tache.

# CODE

```c
#include <RTOS.h>

int x; // Les variables globales sont liees au data segment

void task1(void *pvParameters);
void task2(void *pvParameters);

void task1(void *pvParameters) {
    int i; // Les variables locales sont liees a la pile de la tache
    while(1){
        /* Tache 1 */
    }
}

void task2(void *pvParameters) {
    while(1){
        /* Tache 2 */
    }
}

int main(void) {

    // Creation de 2 taches 
    xTaskCreate(task1, "task 1", stack_size, prio1); // Cree un TCB
    xTaskCreate(task2, "task 2", stack_size, prio1); // Cree un TCB

    vStartScheduler(); // Lance l'ordonnanceur

    while(1);

    return 0;
}
```

# TYPES DE NOYAUX

## Premptif

Une tache prioritaire sur l'autre l'interrompt.

## Non-Premptif (Collaboratif)

Une tache prioritaire sur l'autre ne l'interrompt pas mais s'execute aussitot a la suite de celle-ci.

## Rotatif (Round-Robin)

Execute les taches avec un temps limite.

Quantum fixe : duree fixe pour toutes les taches

Le temps de chaque tache doit etre inferieur au quantum (duree de toutes les taches).

**Caracteristiques :**

- Long processus n'entraine pas de retard
- Pseudo parallele
- Choix du quantum important

> **Formule theorique :**
> 
> `alpha` >= 5
> 
> `Quantum` = `alpha` * `temps de changement de contexte`

# PRIORITES

Les priorites peuvent etre :

- Fixes
- Dynamiques

# ORDONNANCEMENT

## Ordonnanceur (Scheduler)

Choisit l'ordre d'execution grace aux informations du TCB.

## Repartiteur (Dispatcher)

Change le contexte.

- Conserver l'etat des registres quand une tache est suspendue
- Sauvegarder le contexte de la pile
- Restaurer le contexte depuis le TCB

# ALGORITHMES D'ORDONNANCEMENT

n = nombre de taches

C = Temps reel occupation CPU

P = Periode

D = Echeance

## RMA - Rate Monotonic Assignment

**Regle :** Plus la periode est courte, plus la priorite est haute

Somme du `Cout` / `Periode` de chaque tache...

Doit etre <= `nombre de taches` * ( ( `2 ^` ( `1` / `nombre de taches` ) ) `-1`)

$$
\sum_{i=1}^{n} \frac{C_i}{P_i}
\leqslant
n(2^{1/n}-1)
$$

## DMA - Deadline Monotonic priority Assignment

**Regle :** Plus l'echeance est courte, plus la priorite est haute

Somme du `Cout` / `Echeance` de chaque tache...

Doit etre <= `nombre de taches` * ( ( `2 ^` ( `1` / `nombre de taches` ) ) `-1`)

$$
\sum_{i=1}^{n} \frac{C_i}{D_i}
\leqslant
n(2^{1/n}-1)
$$

> Le cout doit etre strictement superieur a l'echeance.

## EDF - Earliest Deadline First

**Regle :** A chaque fois qu'une tache est reveillee, l'ordonnanceur reevalue les taches pretes et prend l'echeance la plus courte.

Somme du `Cout` / `Echeance` de chaque tache...

Doit etre <= `1`

$$
\sum_{i=1}^{n} \frac{C_i}{D_i}
\leqslant
1
$$

# MCU & MPU

## CPU (Central Process Unit)

Point central du systeme. Recupere les instructions dans la memoire et les execute.

## RAM (Random Acces Memory)

Stocke des donnees temporairement.

## ROM (Read Only Memory)

Donnees permanentes en lecture seule, principalement pour contenir le programme et l'amorceur.

## I/O Ports

Entrees/Sorties, pour communiquer avec le materiel exterieur au systeme (peripheriques).

## Timer

Avoir acces a une periode, gerer le temps, synchroniser, faire des delays, etc.

## Interrupt

Interruptions, permet de faire des instructions sans passer par le CPU, changement d'etat electronique.

## Serie COM Ports

Autres methodes de communication avec l'exterieur.

# GPOS VS RTOS

tableau diapo 47

# CHOISIR UN MICRO-CONTROLEUR

- Vitesse (Frequence)
- Encombrement (Taille, poids)
- Consommation
- RAM/ROM
- Peripheriques
- Nombre d'E/S + Horloge
- Adaptabilite
- Prix
- L'eco-systeme et son support (Ergonomie des Logiciels de Developpement)
- Disponibilite

# ADDITION BINAIRE

| A + B     | Carry | Sum |
|:---------:|:-----:|:---:|
| `0` + `0` | 0     | 0   |
| `0` + `1` | 0     | 1   |
| `1` + `0` | 0     | 1   |
| `1` + `1` | 1     | 0   |

# COMPLEMENT A 1

Soustraction par complement a 1.

