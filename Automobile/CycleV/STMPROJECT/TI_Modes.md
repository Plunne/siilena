# Document de Tests d'Integration

- Fonctions de modes
- Formation POEI
- Travaux Pratique STM
- V1.0

# TABLE DES MATIERES
- [Document de Tests d'Integration](#document-de-tests-dintegration)
- [TABLE DES MATIERES](#table-des-matieres)
- [Fonction STMPROJECT\_Mode\_ButtonPressed](#fonction-stmproject_mode_buttonpressed)

# Fonction STMPROJECT_Mode_ButtonPressed

Ref Spécification : b001, b002, b003 (Specification.md)

**Resume du test :**  

Tester que l'appui sur le bouton declenche le changement du mode et l'appel de la fonction.

**Etat initial :**

- On instrumente le code de facon a forcer l'etat du bouton a `PRESSED`
- La valeur de `BP_Mode` vaut `PRESSED`
- Avoir positionne un Breakpoint avant la fonction `STMPROJECT_Mode_ButtonPressed()`

**Procedure d'execution :**

1. Lancer le programme avec `PRESSED` = 1
2. Refaire un tour de boucle
3. Arreter le programme
4. Reproduire les etape 1 & 2 apres avoir modifie `PRESSED` = 0

**Verifications necessaires :**

1. Au breakpoint de la fonction `STMPROJECT_Mode_ButtonPressed()` , la variable `mode` vaut `MODE_SCALE`
2. Au breakpoint de la fonction `STMPROJECT_Mode_ButtonPressed()` , la variable `mode` vaut `MODE_TIMER`
3. Rien a verifier
4.1. Au breakpoint de la fonction `STMPROJECT_Mode_ButtonPressed()` , la variable `mode` vaut `MODE_SCALE`
4.2. Au breakpoint de la fonction `STMPROJECT_Mode_ButtonPressed()` , la variable `mode` vaut `MODE_SCALE`
