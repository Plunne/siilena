# Document de Tests

- Fonctions de modes
- Formation POEI
- Travaux Pratique STM
- V1.0

# TABLE DES MATIERES
- [Document de Tests](#document-de-tests)
- [TABLE DES MATIERES](#table-des-matieres)
- [Fonction STMPROJECT\_Mode\_ButtonPressed](#fonction-stmproject_mode_buttonpressed)
- [Type Changement de Mode](#type-changement-de-mode)
- [Variable Mode par defaut](#variable-mode-par-defaut)

# Fonction STMPROJECT_Mode_ButtonPressed

Ref Spécification : b001 (Specification.md)

**Resume du test :**  

Tester que l'appui sur le bouton declenche le changement entre le mode timer et le mode scale.

**Etat initial :**

- La carte est demarree
- La carte est dans l'etat timer

**Procedure d'execution :**

1. Appuyer sur le bouton une seule fois
2. Tourner le potentiometre

**Verifications necessaires :**

1. L'affichage ne s'incremente plus
2. L'affichage change lorsque l'on varie le potentiometre

# Type Changement de Mode

- Ref Spécification : b002 (Specification.md)

**Resume du test :**  

Tester que les modes Scale et Timer sont presents et se bouclent.

**Etat initial :**

- La carte est demarree
- La carte est dans l'etat scale

**Procedure d'execution :**

1. Appuyer sur le bouton une seule fois
2. Appuyer sur le bouton une deuxieme fois
3. Appuyer sur le bouton une troisieme fois

**Verifications necessaires :**

1. La valeur s'incremente (passage au mode Timer)
2. La valeur ne s'incremente plus (retour au mode Scale)
3. La valeur s'incremente (retour au mode Timer)

# Variable Mode par defaut

- Ref Spécification : b003 (Specification.md)

**Resume du test :**  

Tester que le mode Scale est le mode par defaut au demarrage.

**Etat initial :**

- La carte est eteinte

**Procedure d'execution :**

1. Allumer la carte
2. Tourner le potentiometre

**Verifications necessaires :**

1. L'affichage ne change pas
2. L'affichage change a la variation du potentiometre