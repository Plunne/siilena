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

Ref Spécification : b001 (Specification.md)

**Resume du test :**  

Tester que l'appui sur le bouton declenche le changement du mode et l'appel de la fonction.

**Etat initial :**

- On instrumente le code de facon a forcer l'etat du bouton a `PRESSED`
- La valeur de `BP_Mode` vaut `PRESSED`
- Avoir positionne un Breakpoint a la fin de la fonction `STMPROJECT_Mode_ButtonPressed()`

**Procedure d'execution :**

1. Lancer l'execution avec `PRESSED` = 1
2. Relancer l'execution apres avoir modifie `PRESSED` = 0

**Verifications necessaires :**

1. La fonction `STMPROJECT_Mode_ButtonPressed()` retourne `True`
2. La fonction `STMPROJECT_Mode_ButtonPressed()` retourne `False`
