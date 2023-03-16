---
author: Lena SAVY-LARIGALDIE
title: COURS - Les Tests
---

# COURS - Les Tests

Formateur : Paul-Ernest MARTIN

## TABLE DES MATIERES
- [COURS - Les Tests](#cours---les-tests)
  - [TABLE DES MATIERES](#table-des-matieres)
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
  - [Diagramme d'etats](#diagramme-detats)
- [BOITE NOIRE, GRISE, BLANCHE](#boite-noire-grise-blanche)
  - [Boite Noire](#boite-noire)
  - [Boite Blanche](#boite-blanche)
  - [Boite Grise](#boite-grise)
- [TESTS ALEATOIRES](#tests-aleatoires)
- [JENKINS](#jenkins)
- [FURPSE](#furpse)
- [BOITE BLANCHE](#boite-blanche-1)
- [PILOTE \& BOUCHON](#pilote--bouchon)
  - [Pilote](#pilote)
  - [Bouchon](#bouchon)
- [MACROS ERRNO](#macros-errno)

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

Test avant l'execution. (examination du code source)

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

### Deroulement

On compare en fonction de la classe d'equivalence la plus nombreuse.

**Exemple :**

| Jour   | Mois        | Annee          |
|--------|-------------|----------------|
| [1,27] | {1,3,...}   | bissextile     |
| 28     | {4,6,9,...} | non-bissextile |
| 29     | 12          | 1999           |
| 30     | 2           | bissextile     |
| 31     | {1,3,...}   | non-bissextile |
| [1,27] | {4,6,9,...} | 1999           |
| 28     | 12          | bissextile     |
| 29     | 2           | non-bisextile  |
| ...    | ...         | ...            |

> Ici, le Jour a le plus de classe d'equivalence.

## Diagramme d'etats

Representation des differents etats d'un systeme et la transition de ces etats.

1. Initalisation (Affectation)
2. Demande/Requete (Condition)
3. Verification (SI Condition)
4. Validation (Condition VRAIE)
5. Refus (Condition FAUSSE)

# BOITE NOIRE, GRISE, BLANCHE

## Boite Noire

Outils/Procedures de tests dont on test les entrees et sorties quand on ne connait pas l'implementation. (Generalement pour les tests de validation)

## Boite Blanche

Outils/Procedures de tests dont on maitrise l'entierete des tests, deroulement du programme, tests des composants. On passe dans tous les chemins possibles. (Generalement pour les tests unitaires)

## Boite Grise

Hybride entre boite noire et boite blanche.

# TESTS ALEATOIRES

Permettent d'eviter les pesticides en ayant une plus grande variete de tests grace a des valeurs d'entree aleatoires.

# JENKINS

Systeme Open Source pour gerer la construction et l'integration continue.

Son objectif est de surveiller les modifications du code source et de lancer les tests en consequence des changements afin de generer des rapports d'erreurs pour nous informer des choses a revoir.


# FURPSE

Un bon logiciel est FURPSE.

- **F**unctionnality
- **U**sability
- **R**eliability
- **P**erformances
- **S**ervice Ability
- **E**volutive

Un programe doit etre Fonctionnel/Coherent, Utilisable/Ergonomique, Fiable, Performant, Maintenable et Evolutif.

# BOITE BLANCHE

Tests qui se concentrent sur la structure interne du programme.


**Quelques types/criteres de boite blanche :**

- Toutes le instructions
- Tous les chemins
- Toutes les conditions

# PILOTE & BOUCHON

## Pilote

Envoie des donnees au composant et recupere les sorties.

## Bouchon

Simule les composants auxquels le composant teste est connecte.

# MACROS ERRNO

Quelques macros pour errno dans le cadre des tests.

| Macro    | Definition                           |
|----------|--------------------------------------|
| `EDOM`   | Erreur de domaine (argument mauvais) |
| `EINVAL` | Erreur d'argument invalide           |
| `EPERM`  | Operation non permise                |
| `ENOMEM` | Plus de place en memoire disponible  |

> La fonction retourne une erreur, errno contient les infos sur l'erreur.

