# Document de Design

- Fonctions générales
- Formation POEI
- Travaux Pratique STM
- V1.0

# TABLE DES MATIERES
- [Document de Design](#document-de-design)
- [TABLE DES MATIERES](#table-des-matieres)
- [Fonction Main](#fonction-main)

# Fonction Main

- Ref Spécification : a001 (Specification.md)
- Entrées :  `STMPROJECT_Mode_ButtonPressed()`, `mode`
- Sorties : `STMPROJECT_Mode_Scale()`, `STMPROJECT_Mode_Timer()`

```
while (1)
|
|-- if STMPROJECT_Mode_ButtonPressed()
|   |-- Then
|   |-- if mode == MODE_SCALE
|   |   |-- Then
|   |   | STMPROJECT_Mode_Scale()
|
|   |-- else if mode == MODE_TIMER
|   |   |-- Then
|   |   | STMPROJECT_Mode_Timer()
```
