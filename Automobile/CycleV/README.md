---
author: Lena SAVY-LARIGALDIE
title: Cours Automobile - Documentation de projet
---

# LA DOCUMENTATION EN CYCLE EN V

Formateur : Vincent Cinq-Fraix

## TABLE DES MATIERES
- [LA DOCUMENTATION EN CYCLE EN V](#la-documentation-en-cycle-en-v)
  - [TABLE DES MATIERES](#table-des-matieres)
- [INTRODUCTION](#introduction)
- [SPECIFICATION](#specification)
- [DESIGN](#design)
- [TEST D'INTEGRATION](#test-dintegration)
- [TEST UNITAIRE](#test-unitaire)

# INTRODUCTION

Pour transmettre les informations sur le projet et s'assurer que les personnes les comprennent, le cycle en V met en oeuvre une documentation.

L'importance derriere tout ca est d'optimiser l'organisation de projet en faisant en sorte de se retrouver plus facilement dans les fichiers sources et de reduire la quantite et la duree des tests ce qui reduit grandement les efforts a produire lors d'une modification.

# SPECIFICATION

La specification definie les besoins du client en plusieurs exigeances.

- Identifiant de l'exigence
- Version de l'exigence
- Description de l'exigence

*Les exigences peuvent etre regroupees en modules.*

# DESIGN

Chaque exigeance doit avoir un design associe.

Le design est detaille le fonctionnement de la fonctionnalite exigee en prennant en compte les entrees/sorties et un pseudo code a implementer.

- References de specification
- Entrees
- Sorites

# TEST D'INTEGRATION

Pour tester les fonctionnalites des designs on met en place des Tests d'Integration (TI) pour s'assurer que chaque fonctionnalite produit un resultat attendu.

Le Test d'Integration resume l'utilite du test et liste les etats initiaux avant lancement du test, les procedures de deroulement du test et les verifications a faire a chaque procedure.

- References de specification
- Resume du test
- Etats initiaux
- Procedures de test
- Verifications necessaires

# TEST UNITAIRE

Un test unitaire (TU) reprend les criteres du Test d'Integration mais ce dernier ne met pas en oeuvre le materiel et plonge un peu plus dans les details du code source (controle de division par Zero, classes d'equivalences, etc.).

Les Tests Unitaires sont generalement mis en place par des logiciels prevus a cet effet.
