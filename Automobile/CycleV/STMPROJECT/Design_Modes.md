# Document de Design

- Fonctions de modes
- Formation POEI
- Travaux Pratique STM
- V1.0

# TABLE DES MATIERES
- [Document de Design](#document-de-design)
- [TABLE DES MATIERES](#table-des-matieres)
- [Fonction STMPROJECT\_Mode\_ButtonPressed](#fonction-stmproject_mode_buttonpressed)
- [Type Changement de Mode](#type-changement-de-mode)
- [Variable Mode par defaut](#variable-mode-par-defaut)


# Fonction STMPROJECT_Mode_ButtonPressed

- Ref Spécification : b001 (Specification.md)
- Entrées : `BP_Mode`
- Sorties : T/F

```
if BP_Mode == PRESSED
|-- Then
|   | mode = mode++ % NB_MODES
|
return mode
```

# Type Changement de Mode

- Ref Spécification : b002 (Specification.md)
- Entrées : `STMPROJECT_Mode_t`
- Sorties :

```
STMPROJECT_Mode_t = { MODE_SCALE, MODE_TIMER }
```

# Variable Mode par defaut

- Ref Spécification : b003 (Specification.md)
- Entrées : `mode`, `MODE_SCALE`
- Sorties :

```
mode = MODE_SCALE
```
