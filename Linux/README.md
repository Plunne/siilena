---
author: Lena SAVY-LARIGALDIE
title: COURS - Les commandes Linux
---

# COURS LINUX

Formateur : Paul-Ernest MARTIN

## TABLE DES MATIERES
- [COURS LINUX](#cours-linux)
  - [TABLE DES MATIERES](#table-des-matieres)
- [LINUX](#linux)
  - [Noyau](#noyau)
  - [OS](#os)
- [LICENCES](#licences)
  - [GPL](#gpl)
  - [MIT](#mit)
  - [BSD](#bsd)
  - [Apache](#apache)
- [OPEN SOURCE](#open-source)
- [GNU/Linux](#gnulinux)
- [DEMARRAGE](#demarrage)
- [UTILISATEURS](#utilisateurs)
  - [Identifiants](#identifiants)
  - [Creation](#creation)
  - [Suppression](#suppression)
  - [Changement d'utilisateur](#changement-dutilisateur)
- [CLI](#cli)
  - [Prompt](#prompt)
- [DOCUMENTATION](#documentation)
  - [Man](#man)
  - [Info](#info)
  - [HOWTO](#howto)
  - [Repertoire "doc"](#repertoire-doc)
  - [Sur Internet](#sur-internet)
  - [Help](#help)
- [COMMANDES](#commandes)
  - [Annuler une commande](#annuler-une-commande)
  - [Deplacement](#deplacement)
  - [Creation](#creation-1)
  - [Suppression](#suppression-1)
  - [Deplacer/Copier](#deplacercopier)
  - [Liens](#liens)
- [7 type de fichiers](#7-type-de-fichiers)
- [PERMISSIONS](#permissions)

# LINUX

Linux est un noyaux.

- Licence GPL
- Multi-utilisateurs
- Multi-taches
- Fonctionne sur de nombreuses plateformes
- Conforme a la norme POSIX

## Noyau

Couche basse du systeme d'exploitation, gere l'abstraction materielle (prend en compte n'importe quel peripherique),
gere la securite, les processus (taches) et leur priorite, la memoire, ... 

## OS

Abstraction du noyau.

# LICENCES

## GPL

Libertes :

- executer
- etudier le fonctionnement et l'adapter a ses besoins
- redistribuer des copies
- ameliorer et distribuer des ameliorations

## MIT

## BSD

## Apache

# OPEN SOURCE

Un logiciel Open-Source est un logiciel dont sa source/conception est accessible a sa possession.

# GNU/Linux

GNU/Linux est un systeme d'exploitation base sur le noyau Unix.

# DEMARRAGE

1. sous tension
2. bootstrap du systeme : cherche dans la ROM l'executable du noyau
3. verification des systemes de fichiers et montage des disques (fsck)
4. passage en multi-utilisateurs
5. lancement des services

# UTILISATEURS

## Identifiants

- UID : Identifiant utilisateur
- GID : Identifiant de groupe

## Creation

1. Utilisateur (avec home directory)
    ```shell
    sudo useradd -m nom_utilisateur
    ```

2. Mot de passe
   ```shell
   sudo passwd nom_utilisateur
   ```

3. Groupe (Fonctionnalite avancee)
    ```shell
    sudo usermod -aG groupe1,groupe2 nom_utilisateur
    ```

## Suppression

```shell
sudo userdel nom_utilisateur
```

## Changement d'utilisateur

```shell
su nom_utilisateur
```

# CLI

## Prompt

- `$` : Utilisateur
- `#` : Root

# DOCUMENTATION

## Man

La commande `man` permet d'acceder a la documentation d'une commande.

```shell
man commande
```

## Info

La commande `info` est comme `man` mais plus moderne avec un meilleur rendu de la documentation.

```shell
info commande
```

## HOWTO

La documentation HOWTO est une collection de guides Linux sur un site internet.

## Repertoire "doc"

Les createurs d'un logiciel peuvent fournir une documentation externe () d'un logiciel dans le repertoire `/usr/share/doc` .

## Sur Internet

Aller sur internet pour rechercher les informations est l'option la plus recommandable.

## Help

Generalement dans les arguments d'un programme en CLI, 
les arguments `-h` , `-help` ou `--help` peuvent fournir une liste des commandes avec une description legere.

```shell
commande -h
```

# COMMANDES

## Annuler une commande

Annuler (cancel) une commande.

Raccourcis : `Ctrl` + `C`

## Deplacement

| Commande     | Description                             |
|:-------------|:----------------------------------------|
| `ls -la`     | Lister les repertoires et fichiers      |
| `cd`         | Se deplacer dans le home (~)            |
| `cd dossier` | Changer de dossier                      |
| `cd -`       | Retourner dans le repertoire precedent  |
| `pwd`        | Repertoire courant                      |

## Creation

| Commande            | Description                   |
|:--------------------|:------------------------------|
| `touch fichier`     | Creer un fichier              |
| `mkdir -p dossier`  | Creer un repertoire           |

## Suppression

| Commande            | Description                   |
|:--------------------|:------------------------------|
| `rm fichier`        | Supprime un fichier           |
| `rm -rf dossier`    | Supprime un repertoire        |

## Deplacer/Copier

| Commande                    | Description                                                        |
|:----------------------------|:-------------------------------------------------------------------|
| `mv cible destination`      | Deplace une cible (Dossier/Fichier) dans un chemin de destination  |
| `cp fichier destination`    | Copie un fichier dans un chemin de destination                     |
| `cp -r dossier destination` | Copie un dossier dans un chemin de destination                     |

## Liens

| Commande                    | Description                                                        |
|:----------------------------|:-------------------------------------------------------------------|
| `A venir...`                | Description                                                        |

# 7 type de fichiers

- Fichier
- Repertoire
- Lien symboliques
- Dossier de peripheriques de type block (ex: disques de donnees)
- Peripheriques de type caracteres (ex: imprimantes)
- Peripheriques de type pile (ex: souris, clavier, ...)
- Socket

# PERMISSIONS

