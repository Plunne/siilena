---
author: Lena SAVY-LARIGALDIE
title: COURS - Les Tests
---

# COURS - Les Tests

Formateur : Paul-Ernest MARTIN

## TABLE DES MATIERES
- [COURS - Les Tests](#cours---les-tests)
  - [TABLE DES MATIERES](#table-des-matieres)
- [LOI DE PARETO](#loi-de-pareto)
- [TYPES D'ERREUR](#types-derreur)
- [7 PRINCIPES](#7-principes)
- [PROCESSUS \& PSYCHOLOGIE](#processus--psychologie)
- [TYPES DE TESTS](#types-de-tests)
  - [Test statiques](#test-statiques)
  - [Test dynamiques](#test-dynamiques)
- [SPECIFICATIONS DE JEUX DE TESTS](#specifications-de-jeux-de-tests)
  - [Test All Singles](#test-all-singles)
  - [Test All Pairs](#test-all-pairs)
  - [Classes d'Equivalences](#classes-dequivalences)

# LOI DE PARETO



# TYPES D'ERREUR

- Fonctionnnelle : Ce que doit faire le logiciel
- Non-Fonctionnnelle : La maniere dont le logiciel fait (perfs, temps, ...)

# 7 PRINCIPES

1. Tester la presence de defauts
2. Tests exhaustifs impossibles (coherence)
3. Tester tot (Ne pas tester peut couter plus cher)
4. Regrouper les defauts
5. Paradoxe des pesticides
6. Tester en fonction du contexte
7. Il y aura toujours des defauts

# PROCESSUS & PSYCHOLOGIE

1. Planifier les tests
2. Specifier les tests
3. Concevoir les tests
4. Etablir les conditions
5. Definir les conditions
6. Controler les resultats (Raports d'erreurs)

**Conseils :**

- Pessimiste
- Oeil Critique
- Attention aux details

# TYPES DE TESTS

## Test statiques

Test avant l'execution. (lecture du code source)

## Test dynamiques

Tests pendant l'execution.

# SPECIFICATIONS DE JEUX DE TESTS

## Test All Singles

Tout doit etre teste individuellement au moins une fois.

## Test All Pairs

Toutes les paires/interactions entre 2 fonctionnalites possibles doivent etre testes.

## Classes d'Equivalences

Regrouper les entrees de tests logiquement.

- Reduire le nombre de cas de tests en choisissant par logique
- Faire attention aux cas particuliers (ex: annees bisextiles)
- Tester les extremites : valeur negative, sup/inf. au valeurs limites
- Tester la taille des donnees avec des mauvaises tailles
- Decouper les problemes en sous categories
- En bref, tester les cas qui ne doivent pas marcher

**Bordures :**

```
v     v   vv       v       vv    v    v  
|----------[---------------]----------|
```
