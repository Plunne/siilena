# AERONAUTIQUE VOL

# 1. PREPARATION DU VOL

## Objectif

Phase de preparation statique, organisation du personnel.

## Contraintes

Prise en compte des contraintes de l'avion (poids, meteo, etc.).

## Plan de vol

Preparation du plan de vol (determination de la ligne a suivre).

- Phase de Taxi : deplacement dans l'aeroport pour decollage
- SID : phase de depart/decollage
- Vol : Deroulement du vol

## MEL/CDL

- MEL (Minimum Equipement List) : Liste des equipements minimum requis pour le vol
  - Intervale de reparation : A (aucune), B (3j), C (10j), D (120j) 
- CDL : Liste des elements exterieurs de l'avion

## Limitations

- Prise en compte des vitesses de decollage et d'atterissage.
- Prise en compte des limites d'altitude par rapport a la temperature meterologique.
- Prise en compte des charges (nb passagers, qte carburant, O2, etc.)

## NOTAM

Status de chaque piste (fermee/ouverte/services en moins/etc.) a telle date.

## METEO

La meteo a un impact important sur l'organisation d'un vol.

Il faut prevoir en fonction de la meteo comment reagir lors du vol, anticiper l'evolution de celle-ci mais aussi ne pas ignorer la possibilite qu'elle ne se comporte pas comme prevu.

### METAR

Meteorological Aerodrome Report

Rapport (trame) d'observation a l'instant T toutes les 30 minutes.

> Le SPECI est comme le METAR mais ponctuel.

### TAF

Terminal Aerodrome Forecast

Rapport (trame) de prevision meterologique allant de 12 a 36 heures.

### TEMSI

Carte des evenements meterologiques dangereux remontes suite a des observations en vol ou par les stations meterologiques.

- |  (barre) : 10noeuds  
- \> (triangle) : 50 noeuds

## CARBURANT

Prevoir la bonne quantite de carburant.

- Prise en compte du traffic dans l'aeroport (plus de conso lors de l'attente pendant la phase de taxi si il y a beaucoup d'autres avions)
- Le trajet
- Prevoir l'eventualite de se poser dans un autre aeroport si celui de destination ne le permet plus.
- Prendre en compte les NOTAM
- Anticiper la conso par rapport a la meteo (deviations, vent de face, etc.)

`Taxi fuel` + `Trip fuel` + `Contingency fuel` (reserve de 5% du Trip fuel) + `Alternate fuel` + `Final fuel` (reserve reglementaire de 30 min de vol additionnelles) + `Extra fuel` (anticipation des contraintes lors du vol)

## EQUILIBRE

L'equilibre de chargement est crucial pour le bon deroulement du vol! (**DANGER DE CRASH**)
