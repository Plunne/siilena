---
author: Lena SAVY-LARIGALDIE
title: COURS - Xml
---

# COURS XML

Formateur : [COLIN Matthias](https://github.com/matthcol/scripting202302)

## TABLE DES MATIERES
- [COURS XML](#cours-xml)
  - [TABLE DES MATIERES](#table-des-matieres)
- [STRUCTURE](#structure)
  - [Document](#document)
  - [Element (Tag)](#element-tag)
  - [Attributs](#attributs)
  - [L'Arbre (Tree)](#larbre-tree)
  - [Commentaires](#commentaires)
- [FORMAT](#format)
  - [Methodes de declaration](#methodes-de-declaration)
- [BIBLIOTHEQUES](#bibliotheques)
  - [En Python](#en-python)
- [EN-TETE](#en-tete)

# STRUCTURE

## Document

L'ensemble d'un fichier `.xml` contenant l'arbre des elements.

## Element (Tag)

Contient des attributs, ils sont delimites par une balise ouvrante et une fermante.

## Attributs

Information

## L'Arbre (Tree)

Arborescence des elements.

## Commentaires

```xml
<!-- Commentaire -->
```

# FORMAT

Il est possible d'inventer son propre format xml.

## Methodes de declaration

Liste des methodes pour declarer ses propres formats :

- DTD
- XSD

# BIBLIOTHEQUES

Des bibliotheques pour manipuler du xml sont disponibles dans divers langages.

## En Python

- xml.etree (built-in)
- lxml (basee sur xml.etree)
- beautiful soup

# EN-TETE

En debut de fichier XML, il faut toujours placer cette en-tete qui definit la version xml et l'encodage.

```xml
<?xml version="1.0" encoding="UTF-8"?>
```
