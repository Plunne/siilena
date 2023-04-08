---
author: Lena SAVY-LARIGALDIE
title: Le protocole Ethernet TCP/IP
---

# COURS - ETHERNET TCP/IP

Formateur : Paul-Ernest MARTIN

# TABLE DES MATIERES
- [COURS - ETHERNET TCP/IP](#cours---ethernet-tcpip)
- [TABLE DES MATIERES](#table-des-matieres)
- [LAN \& WAN](#lan--wan)
- [TOPOLOGIES](#topologies)
  - [Physique \& Logique](#physique--logique)
  - [Etoile](#etoile)
  - [Token-ring](#token-ring)
  - [Maille](#maille)
- [ICMP](#icmp)
- [MODELE OSI](#modele-osi)
- [SOCKET](#socket)
- [OUTILS](#outils)
  - [Wireshark](#wireshark)
  - [Netstat (WIN)](#netstat-win)
  - [Ncat (WIN)](#ncat-win)
  - [Taskkill](#taskkill)
- [ROUTEUR \& PASSERELLE](#routeur--passerelle)
  - [Routeur](#routeur)
  - [Passerelle](#passerelle)
- [SUBNETING](#subneting)
- [VLSM](#vlsm)
- [TCP/UDP](#tcpudp)
  - [UDP](#udp)
  - [TCP](#tcp)
- [DHCP](#dhcp)

# LAN & WAN

- LAN (Local Area Network) : Reseau interne local/prive (intranet)
- WAN (Worldwide Area Network) : Reseau externe au reseau local (internet)

# TOPOLOGIES

## Physique & Logique

- Topologie physique : liaison materielle (facon de transmettre des donnees)
- Topologie logique : liaison logicielle (facon d'echanger des donnees)

## Etoile

Les unites communiquent via une interface centrale.

## Token-ring

Les unites communiquent en anneau en se faisant passer les message jusqu'au destinataire.

## Maille

Chaque unite est reliee a toutes les autres.

# ICMP

Le protocole ICMP (Internet Controle Message Protocol) est utilise pour envoyer des messages d'erreurs dans un reseau. Il travaille en partenariat avec le protocole IP.

# MODELE OSI

L'Ethernet est base sur le modele OSI.

# SOCKET

Fait le lien entre une application et son port.

# OUTILS

## Wireshark

### Filtres

```
<protocol>.port == <port> && <protocol>
```

## Netstat (WIN)

Lister tous les ports utilises.

```
netstat -ano
```

## Ncat (WIN)

Permet de gerer des sockets.

### Ecoute

Ecouter un port particulier.

```
ncat -l -u <port>
```

### Creation

Creer un socket.

```
ncat -u <ip_dest> 8080
```

## Taskkill

Tuer un socket.

```
taskkill /pid <PID> /f
```

# ROUTEUR & PASSERELLE

## Routeur

Interface entre un reseau parent et un reseau enfant d'un meme reseau (meme adresse reseau sans CIDR).

**Exemple :**

|      Masque       | Adresse de base |  Reseau Parent   |   Reseau Enfant    |
|:-----------------:|:---------------:|:----------------:|:------------------:|
| `255.255.255.128` |  `192.168.1.x`  | `192.168.1.0/25` | `192.168.1.128/25` |


## Passerelle

Interface entre 2 reseaux (adresses de base differentes).

**Exemple :**

|  Reseau A   |   Reseau B    |
|:-----------:|:-------------:|
| `76.43.x.x` | `192.168.1.x` |

# SUBNETING

Fusion de sous-reseaux.

| Reseau   | Adresse de sous-reseau |     Masque      | Adresse de broadcast |
|:---------|:----------------------:|:---------------:|:--------------------:|
| Reseau 1 |    `192.168.0.0/24`    | `255.255.255.0` |   `192.168.0.255`    |
| Reseau 2 |    `192.168.1.0/24`    | `255.255.255.0` |   `192.168.1.255`    |
| Reseau 3 |    `192.168.2.0/24`    | `255.255.255.0` |   `192.168.2.255`    |
| Fusion   |    `192.168.0.0/22`    | `255.255.252.0` |   `192.168.3.255`    |

**Exercice :**

Adresse reseau de base des reseaux : `120.12.0.0/18`

77 machines max sur le reseau le plus peuple -> `7 hosts bits`

- Masque attendu par SSR : `255.255.255.128.0`
- Adresse net attendue par SSR : `120.12.0.0/25`

|     @net/cidr     |    @host first    |    @host last     |    @broadcast     |
|:-----------------:|:-----------------:|:-----------------:|:-----------------:|
| `120.12.0.128/25` | `120.12.0.129/25` | `120.12.0.254/25` | `120.12.0.255/25` |
|  `120.12.1.0/25`  |  `120.12.1.1/25`  | `120.12.1.126/25` | `120.12.1.127/25` |
| `120.12.1.128/25` | `120.12.1.129/25` | `120.12.1.254/25` | `120.12.1.255/25` |
|  `120.12.2.0/25`  |  `120.12.2.1/25`  | `120.12.2.126/25` | `120.12.2.127/25` |
|  `120.12.0.0/23`  |  `120.12.0.1/23`  | `120.12.3.254/23` | `120.12.3.255/23` |

> Masque du reseau fusionne : `255.255.240.0`

# VLSM

Variable Lenght Subnet Mask

Sous-reseaux de sous-reseau.

A partir d'un sous-reseau on va remasquer par dessus pour en faire des sous-reseaux. Cela permet par exemple d'avoir des reseaux avec des masques de taille differente ou alors de subdiviser des sous-reseaux pour demultiplier le nombre de reseaux.

# TCP/UDP

## UDP

Protocole de transport qui ne demande pas de reponse, permet de transmettre de donnees utiles a l'instant et dont leur sauvegarde n'est pas critique.

> *Tres utilise pour la transmission de commande, si une commande n'est pas recue, vu qu'il y en a d'autres ce n'est pas grave, c'est quand le recepteur est interesse uniquement par de l'acquisition temps reel, ex: commandes de Jeux-Videos, Streams video, Mesures, etc.*

### Trame UDP

8 octets

## TCP

Protocole de transport qui demande une reponse d'acquitement avant l'envoi.

> *Important lorsque l'on doit s'assurer de l'integrite de donnees, ex: messages, fichiers, etc.*

### Echange

1. `SYN` : Envoi d'une requete d'acquitement (A -> B : "Es-tu la?")
2. `SYN ACK` : Reponse d'acquitement (B -> A : "Je suis la.")
2. `ACK` : Prevention d'envoi (A -> B : "Parfait je t'envoie la donnee.")
3. `PSH ACK` : Envoi de la donnee (A -> B : "Voici la donnee.")
2. `ACK` : Reponse d'envoi (B -> A : "J'ai recu la donnee.")

### Fermeture session

1. A `---[FIN]-->` B : "Il faut fermer la connection."
2. A `<--[ACK]---` B : "J'ai compris qu'il faut fermer."
3. A `<--[FIN]---` B : "J'ai ferme de mon cote."
4. A `---[ACK]-->` B : "Bien recu, aurevoir."

### Trame TCP

20 octets

# DHCP

Dynamic Host Configuration Protocol

Permet de configurer des IP dynamiquement en fonction de celles disponibles.

> **IMPORTANT!**  
> Le protocole DHCP utilise le protocole UDP.

