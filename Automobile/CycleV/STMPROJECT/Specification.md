# Exigences

Les exigences definissent les cas d'utilisation d'un produit.

> **IMPORTANT!** Il faut minimum un design par fonctionnalite.

# TABLE DES MATIERES
- [Exigences](#exigences)
- [TABLE DES MATIERES](#table-des-matieres)
- [Exigences A - General](#exigences-a---general)
- [Exigences B - Modes](#exigences-b---modes)
- [Exigences C - Timer](#exigences-c---timer)
- [Exigences D - Compteur](#exigences-d---compteur)
- [Exigences E - Scale](#exigences-e---scale)
- [Exigences F - Plage](#exigences-f---plage)

# Exigences A - General

| id   | version | description                                                                          |
|------|---------|--------------------------------------------------------------------------------------|
| a001 | v1.0    | La carte STM doit pouvoir transitionner entre plusieurs modes a l'appui d'un bouton. |

# Exigences B - Modes

| id   | version | description                                                |
|------|---------|------------------------------------------------------------|
| b001 | v1.0    | Le bouton doit declencher le changement de mode.           |
| b002 | v1.0    | Il doit y avoir les modes de fonctionnement Timer & Scale. |
| b003 | v1.0    | Le mode par defaut doit etre Scale.                        |

# Exigences C - Timer

| id   | version | description                                        |
|------|---------|----------------------------------------------------|
| c001 | v1.0    | Le mode Timer doit incrementer un compteur.        |
| c002 | v1.0    | Le mode Timer doit avoir une periode de 1 seconde. |

# Exigences D - Compteur

| id   | version | description                               |
|------|---------|-------------------------------------------|
| d001 | v1.0    | Le compteur doit avoir une plage definie. |
| d002 | v1.0    | La valeur du compteur doit etre affichee. |

# Exigences E - Scale

| id   | version | description                                                                                                     |
|------|---------|-----------------------------------------------------------------------------------------------------------------|
| e001 | v1.0    | Le potentiometre doit modifier la valeur affichee de maniere proprotionnelle a son intervale de fonctionnement. |
| e002 | v1.0    | Le potentiometre doit parcourir les valeurs sur une plage definie.                                              |

# Exigences F - Plage

| id   | version | description                                                             |
|------|---------|-------------------------------------------------------------------------|
| f001 | v1.0    | La plage definie va de 0 a 9 pour le mode scale.                        |
| f002 | v1.0    | La plage definie va de 0 a 9 puis de A a Z (0 a 35) pour le mode Timer. |
