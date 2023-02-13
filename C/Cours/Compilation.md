#+TITLE: Compilation
#+AUTHOR: Lena SAVY-LARIGALDIE

# PRE-PROCESSEUR

Le pre-processeur copie les valeurs des constante symboliques dans le code du programme a la place de leur nom.

**Fichier source `.c` :**

![](https://raw.githubusercontent.com/Plunne/siilena/main/C/Cours/images/preproctest1.PNG)

**Fichier pre_processeur `.i` :**

![](https://raw.githubusercontent.com/Plunne/siilena/main/C/Cours/images/preproctest2.PNG)

> Il gere egalement les inclusions de headers en remplaceant les chemins relatifs par les chemins absolus.

## Parametres

Pour avoir acces aux `.i` il faut activer l'option de pre-traitement d'un fichier.

![](https://raw.githubusercontent.com/Plunne/siilena/main/C/Cours/images/preprocsettings.PNG)

