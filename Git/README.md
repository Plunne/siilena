---
author: Lena SAVY-LARIGALDIE
title: MEMO Git
---

# MEMO - Commandes Git

# Installer Git

Installer git normalement en fonction de votre Systeme d'Exploitation (OS).

Puis configurer un compte git global sur la machine locale.

```shell
git config --global user.email "<adresse@mail.com>"
git config --global user.name "<Identifiant>"
```

# Initialiser un depot

Initialise la mecanique de git dans le repertoire pour qu'il devienne un depot git.

> *Un fichier cache `.git` apparait.*

```shell
git init
```

# Vers depot distant

## Ajouter des fichiers (Stage)

Ajouter un/des fichier(s) au depot pour les commit.

```shell
git add <fichier(s)>
```

Ajouter tous les fichiers au depot pour les commit.

```shell
git add .
```

## Preparer l'Envoi (Commit)

Preparer les fichiers a l'envoi et assigner une description.

```shell
git commit -m "<message>"
```

## Envoyer les changements

Envoyer les modification sur le depot main distant.

```shell
git push origin main
```

Envoyer les modification sur un depot et une branche specifique a celui-ci.

```shell
git push <alias_depot_distant> <branche>
```

# Depot distant vers local

## Cloner un depot

Recuperer un depot distant non existant sur la machine locale.

```shell
git clone <url_du_depot>
```

## Pointer vers un depot

Connecter notre depot local vers un depot distant specifique.

```shell
git remote add <alias_depot_distant> <url_depot_distant>
```

## Restaurer des fichiers

Restaurer des fichiers supprimes en local, depuis le depot distant.

```shell
git restore <fichier>
```

## Recuperer des fichiers

Recuperer des fichiers distants sur la branche main n'ayant pas ete modifies sur le depot local entre-temps (depuis notre dernier push).

```shell
git fetch
```

Meme procedur mais avec toutes les branches.

```shell
git fetch -p
```

## Resolution de conflits

### Fusion de branches

> *Un conflit se produit lorsque l'on veut pousser des modifications de fichiers ayant ete egalement modifies sur le depot distant entre-temps (depuis notre dernier push).*

Merge permet de :
- Recuperer les modifications distantes pour les fichiers existants.
- Cela va alors modifier vos fichiers ayant un conflit en rajoutant les modifications distantes.
- Grace a cela vous pourrez directement dans votre code choisir quoi faire entre les deux modifications afin de resoudre les conflits.
- Fusionne la branche avec le main (Officialise les modifications/resolutions de conflits).

```shell
git merge --no-ff
```

Meme procedure avec une branche distante specifique.

```shell
git merge --no-ff <branche>
```

L'argument `--no-ff` est conseille comme bonne pratique pour les utilisateurs plus avances. Il n'est pas necessaire pour des petits projets.

### Fusion de branche locale

Meme chose que merge sauf que ca ne met pas a jour la branche distante, on ne fusionne que sur la branche locale.

```shell
git rebase <branche>
```

Pour le main distant.

```shell
git rebase origin/main
```

## Mise a jour radicale du depot local 

Fusion de `fetch + merge` .

Mettre a jour son depot local en se synchronisant avec les modifications distantes.

> **IMPORTANT!**
> 
> Toute modification locale sera remplacee pour les donnees distantes.

```shell
git pull
```

# Manipulation de branches

## Creer une branche

Creer une branche.

```shell
git checkout -b <branche>
```

## Changer de branche

Passer d'une branche a l'autre.

```shell
git checkout <branche>
```

## Supprimer une branche

Supprimer une branche.

```shell
git checkout -d <branche>
```

# Monitoring

## Voir les log

Voir l'historique des commits.

```shell
git log
```

## Voir l'etat du depot

Voir l'etat des modifications en cours sur le depot (rien, ajouts, commit a push).

```shell
git status
```

## Voir les difference

Voir les differences avec le dernier commit.

```shell
git diff
```
