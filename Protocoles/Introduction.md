---
author: Lena SAVY-LARIGALDIE
title: Introduction sur les protocoles
---

# INTRODUCTION - LES PROTOCOLES

Formateur : Kamel SANAI

# TABLE DES MATIERES
- [INTRODUCTION - LES PROTOCOLES](#introduction---les-protocoles)
- [TABLE DES MATIERES](#table-des-matieres)
- [A QUOI CA SERT ?](#a-quoi-ca-sert-)
- [QUELQUES ORGANISMES](#quelques-organismes)
- [QU'EST-CE QUE C'EST ?](#quest-ce-que-cest-)
- [MODELE OSI](#modele-osi)
- [ANALOGIQUE/NUMERIQUE](#analogiquenumerique)
- [AQUITEMENT](#aquitement)
- [CLASSES DE PROTOCOLES](#classes-de-protocoles)

# A QUOI CA SERT ?

Les protocoles ont ete concus pour standardiser des moyens de communication dans l'optique d'avoir des points d'entente sur les facons de concevoir des reseaux.

# QUELQUES ORGANISMES

- **OSI :** Normes ISO
- **OASIS :** Normes OASIS
- **IETF :** Normes RFC

# QU'EST-CE QUE C'EST ?

Une norme est un echange entre un emmeteur et un recepteur d'un message a travers un support conformement a un protocole de communication.

# MODELE OSI

Le modele OSI definit les couches materielles et logicielles.

|   | Couches Applicatives |
|---|----------------------|
| 7 | application          |
| 6 | Presentation         |
| 5 | Session              |
| 4 | Transport            |

|   | Couches Physiques |
|---|-------------------|
| 3 | Reseau            |
| 2 | Liaison           |
| 1 | Physique          |

| 1       | 2         | 3        | 4         | 5            | 6           | 7      |
|---------|-----------|----------|-----------|--------------|-------------|--------|
| Support | @ machine | @ reseau | Transport | Session | Contenu | Application |

**Metaphore :**

- 7 : Lettre
- 6 : Redigaction de la lettre en francais
- 5 : En recommande, avec avis de reception, etc.
- 4 : Envelopper la lettre
- 3 : A telle adresse
- 2 : Chez telle personne
- 1 : Par un facteur
- 0 : Arrivee/Reception du courrier

> **Apres reception du courrier (cote destinataire) :**
> 
> Le destinateur recoit la lettre, verifie que c'est le bon destinataire et qui lui a envoye, que c'est bien son adresse et d'ou vient la lettre, ouvre la lettre, remarque qu'il s'agit d'un recommande, voit que la lettre est ecrite dans une de ses langues, lit la lettre.

# ANALOGIQUE/NUMERIQUE

Difference entre analogique et numerique.

W.I.P.

# AQUITEMENT

L'aquitement permet de controler l'integrite d'un message.

> *Il se peut que le destinataire informe l'emmeteur de la coherence ou non du contenu du message afin que ce dernier si la message est invalide, renvoit a nouveau le message.*

# CLASSES DE PROTOCOLES

### Protocoles de telecommunication

TCP/IP, SSH/SCP, SMTP, FTP, MQTT, NTP, HTTP, BLE, etc.

### Protocoles de communication

- **Protocoles parallele :** PATA, Parallele, etc.
- **Protocoles serie :** USB, UART, I2C, CAN, SPI, Ethernet, etc.


7 - Message
6 - contenu SMS
5 - ??
4 - SMS
3 - IP
2 - @mac
1 - Ethernet
0 - 4G