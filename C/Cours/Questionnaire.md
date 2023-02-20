---
author: Lena SAVY-LARIGALDIE
title: Questionnaire Cours C
---

# Questionnaire Cours C

Formateur : Paul-Ernest MARTIN

## TABLE DES MATIERES
- [Questionnaire Cours C](#questionnaire-cours-c)
  - [TABLE DES MATIERES](#table-des-matieres)
- [PARTIE 1](#partie-1)
- [PARTIE 2](#partie-2)
- [PARTIE 3](#partie-3)
- [PARTIE 4](#partie-4)
- [PARTIE 5](#partie-5)
- [PARTIE 6](#partie-6)
- [PARTIE 7](#partie-7)
- [PARTIE 8](#partie-8)
- [PARTIE 9](#partie-9)
- [PARTIE 10](#partie-10)
- [PARTIE 11](#partie-11)
- [PARTIE 12](#partie-12)
- [PARTIE 13](#partie-13)

# PARTIE 1

1. Donnez 3 raisons d'apprendre le C :
   ```
   Langage bas niveau, souple, puissant, tres rependu dans le hardware, syntaxe legere
   ```

2. Role du compilateur :
   ```
   Convertir le langage C (interpretable) en langage machine (objet)
   ```

3. Que faut-il faire en cas d'erreurs ? :
   ```
   Lire les erreurs sinon relire le code pour trouver les erreurs
   ```

4. Qu'est ce que le langage machine? :
   ```
   Langage binaire representant le signal electrique (Etat haut/Etat bas)
   ```

5. Que fait l'editeur de liens ? :
   ```
   Cherche les fichiers objets contenant les fonctions externes utlisees dans le programme
   ```

# PARTIE 2

1. Comment appelle-t-on un groupe d'une ou plusieurs instructions entre accolades?
   ```
   Bloc de code
   ```

2. Quel element obligatoire d'un programme en C?
   ```
   La fonction main()
   ```

3. Pour quelles raisons commenter?
   ```
   Se retrouver, revenir sur un programme plus tard, comprendre le code pour soi et pour les autres.
   ```

4. Qu'est-ce qu'une fonction?
   ```
   Portion de code independante (sous-programme).
   ```

5. Quels sont les deux types de fonctions disponibles en langage C et quelles sont leurs difference?
   ```
   Fonctions internes (Fonctions de l'utilisateur) et externes (Fonctions de bibliotheque).
   ```

6. A quoi sert l'appel #include ?
   ```
   Importer une bibliotheque qui permettent d'avoir acces a des declarations externes.
   ```

7. Qu'est-ce au'un fichier inclus?
   ```
   Une bibliotheque (La ou on declare des fonctions ou variables).
   ```

8. Quelle est la difference entre une instruction et un bloc de code?
   ```
   Un bloc de code contient des instructions.
   ```

# PARTIE 3

**Exercice:**

   > Quelles sont les lignes avec :
   > 
   > - Instructions? `5`, `6`, `7`, `8`, `13`, `14`, `15`
   > - Definition de variable? `13`
   > - Declaration de fonction? `1 (indirectement)`, `2`
   > - Commentaires? `10`
   > - Definition de fonction? `3 -> 9` et `11 -> 16`

# PARTIE 4

1. Quelle est a difference avec une variable entiere et une variable a virgule flottante?
   ```
   Une variable flottante a une virgule alors qu'une valeur entiere ne peux pas avoir de virgule.
   ```

2. Donner deux raisons d'utiliser une variable a virgule flottante double precision plutot que le meme variable simple precision?
   ```
   La double sera plus precise, les valeurs pourront etre plus grandes avant et apres la virgule.
   ```

3. Quels sont les deux avantages a utiliser une constante symbolique plutot qu'une constante litterale?  
   ```
   La place en memoire (pas de variable declaree) et l'interpretation (3.14 dans un int -> 3; 3.14 dans un float -> 3.14) 
   ```

4. Trouver deux methodes pour definir une constante appelee MAXIMUM qui aurait une valeur de 100.   
   ``` c
   #define MAXIMUM 100
   const char MAXIMUM = 100;
   ```

5. Quels sont les characteres autorises dans le nom d'une variable en C?
     
   > - Lettres et Chiffres uniquement
   > - Commence par une lettre minuscule
   > - Sensible a la casse (Majuscule != Minuscule)
   > - Pas de mot cle

6. Quelles sont les regles a suivre pour creer des noms de variables et de constantes litterales?

   > - Lettres et Chiffres uniquement
   > - Commence par une lettre minuscule
   > - Sensible a la casse (Majuscule != Minuscule)
   > - Pas de mot cle

7. Quelle difference y a-t-il entre une constante symbolique et une constante litterale?
   ```
   L'interpretation de la valeur, la litterale a un type force alors que la symbolique est flexible.
   ```

8. Quelle valeur minimum peut prendre une variable de type short ?
   ```
   -32 768 (ou 0 en unsigned).
   ```

# PARTIE 5

1. Que fait l'instruction suivante? `x = 5 + 8;`
   ```
   Elle affecte 13 (5 + 8) a une variable nommee x.
   ```

2. Qu'est ce qu'une expression?
   ```
   Il s'agit generalement d'une condition ou de la verification d'une valeur nulle ou existante.
   ```

3. Qu'est ce qui determine l'ordre de realisation des operations dans une expression qui contient plusieurs operateurs?
   ```
   La priorite des operateurs.
   ```

4. Si une variable `x` a pour valeur `10`, quelles sont les valeurs stockees dans `x` et `a` apres l'execution de chacune de ces instructions (separement) ? `a = x++;` `a = ++x;`
   ```
   10 puis 12
   ```

5. Quelle est la valeur de l'expression `10 % 3` ?
   ```
   1
   ```

6. Quelle est la valeur de l'expression `5 + 3 * 8 / 2 + 2` ?
   ```
   19
   ```

7. Ecrivez l'expression de la question 6 avec des parentheses pour obtenir le resultat `16` .
   ``` c
   5 + (((3 * 8) / (2 + 2)))
   ```

8. Quelle valeur prend une expression fausse?
   ```
   0
   ```

# PARTIE 6

1. Comment fonctionne la programmation structuree et pourquoi ?
   ```
   Avec les fonctions, cela permet de reutiliser du code definit qu'a un seul endroit pour eviter la repetition de code.
   ```

2. Quelle est la premiere ligne de la definition de fonction et quelles informations contient-elle ?
   ```
   L'en-tete : prototype sans point virgule.
   ```

3. Combien de valeurs peut retourner une fonction?
   ```
   0 pour une void ou 1 seule pour les autres.
   ```

4. Si une fonction ne retourne pas de valeur, quel type doit elle avoir dans la declaration?
   ``` c
   void
   ```

5. Quelle est la difference entre la definition et le prototype d'une fonction?
   ```
   La definition est la ou l'on definit le corps de la fonction et le prototype la ou on declare la fonction.   
   ```

6. Quelle est la particularite des variables locales?
   ```
   D'etre locale.   
   ```

# PARTIE 7

1. Ecrivez l'en-tete de la fonction `fais_le()` qui a `3 arguments` de type `char` et qui revoie une valeur de type `float` au programme.
   ``` c
   float fais_le(char val1, char val2, char val3);
   ```

2. Ecrivez l'en-tete de la fonction `affiche_un_nombre()` qui a `1 seul argument` de type `int` et qui ne revoie `rien` .
   ``` c
   void affiche_un_nombre(int n);
   ```

3. Quel type de valeur revoient les fonctions suivantes?
   
   a) `int affiche_erreur(float err_nbr);` 
   
   > `int`
   
   b) `long lit_enreg(int rec, int size);` 
   
   > `long`

# PARTIE 8

1. Ecrivez une fonction qui recoit deux nombres en arguments et qui renvoie la valeur correspondant au produit de ces deux nombres.
   ``` c
   int produit(int a, int b) {
      return a * b;
   }
   ```

2. Ecrivez une fonction qui recoit deux nombres en arguments et qui divise le premier par le second si celui-ci est different de 0.
   ``` c
   int division(int a, int b) {
      return (b != 0) ? a/b : 0;
   }
   ```

3. Ecrivez une fonction qui permet de calculer la moyenne de 2 valeurs de type float, donnees par l'utilisateur.
   ``` c
   float moyenne(float a, float b) {
      return (a + b) / 2;
   }
   ```

4. Ecrivez une fonction recurrente qui calcule le resultat de la valeur 3 a la puissance du nombre choisit par l'utilisateur.
   Par exemple, si le nombre 4 est tape par l'utilisateur, le resultat sera 81.
   ``` c
   float recurrence(int n) {
      return (n == 0) ? 1 : 3 * recurrence(--n);
   }
   ```

# PARTIE 9

1. Ecrivez la declaration correspondant a un tableau qui contiendra 50 valeurs de type long.
   ``` c
   long tableau[50];
   ```

2. Quelle est la valeur de x apres l'execution de l'instruction suivante? `for (x=0; x < 100; x++);`
   ```
   100
   ```

3. Quelle est la valeur de ctr apres l'execution de l'instruction suivante? `for (ctr=0; ctr < 10; ctr+=3);`
   ```
   12
   ```

4. Combien de caracteres `X` la boucle for suivante affiche-t-elle?

   **Question :**
   ``` c
   for (x=0; x < 10; x++)
       for (y=5; y > 0; y--)
          puts("X");
   ```
   **Reponse :**
   ```
   1ere boucle 10
   2eme boucle 5
   10 * 5 = 50
   ```

5. Comptez de 1 a 100 de 3 en 3 avec une boucle for, une boucle while, et une boucle do while.
   
   **Avec for :**
   ``` c
   for (int ctr=1; ctr <= 100; ctr += 3);
   ```
   
   **Avec while :**
   ``` c
   int ctr = 1;
   while (ctr <= 100) {
      ctr += 3;
   }
   ```

   **Avec do while :**
   ``` c
   int ctr = 1;
   do
   {
      ctr += 3;
   }
   while (ctr <= 100)
   ```

# PARTIE 10

1. Quel operateur faut-il utiliser pour obtenir l'adresse d'une variable?
   ```
   &
   ```

2. Quel operateur faut-il utiliser pour obtenir la valeur de la variable pointee?
   ```
   *
   ```

3. Qu'est ce qu'un pointeur?
   ```
   Variable contenant l'adresse d'une autre variable d'un type donne.
   ```

4. Qu'est ce qu'un acces indirect?
   ```
   Acceder a la valeur en passant par une variable pointeur.
   ```

5. Commment les element d'un tableau sont-ils stockes en memoire?
   ```
   Sequetiellement/A la suite.
   ```

6. Trouver deux methodes pour obtenir l'adresse du premier element du tableau data[].
   ``` c
   tableau[0]
   *tableau   
   ```

7. Trouver deux methodes pour passer un tableau en argument d'une fonction.
   ``` c
   void fonction(int * tableau, int taille_tableau); // Il faut absolument passer le nombre d'elements du tableau
   void fonction(int tableau[], int taille_tableau); // Il faut absolument passer le nombre d'elements du tableau
   ```

# PARTIE 11

1. Supposons que l'on ait deux pointeurs. Le premier pointe sur le 3eme element et le second sur le 4eme.
   Quelle valeur obtiendrez-vous en soustrayant le premier pointeur du second? (En prennant int comme type d'exemple)
   ```
   -1
   ```

2. Meme question en remplacant le type int par le type double.
   ```
   -1
   ```

1. Ecrivez l'instruction qui attribue l'adresse de la variable radius de type float a un pointeur.
   ``` c
   float *ptr = &radius;
   ```

1. Trouvez deux methodes pour attribuer la valeur 100 au troisieme element du tableau data[].
   ``` c
   data[2] = 100;
   *(data + 2) = 100;
   ```

1. Ecrivez la fonction `somtabs()` qui, recevant deux tableaux en argument, additionne la valeur des elements des deux tableaux,
   puis qui renvoie le resultat au programme appelant.
   ``` c
   void sumtabs(int *tableau1, int *tableau2, int taille) {
      for (int i=0; i < taille; i++) {
         tableau1[i] += tableau2[i];
         print("%d", tableau1[i]);
      }
   }
   ```

# PARTIE 12

1. Quelles sont les valeurs numeriques correspondant aux caracteres ASCII?
   ```
   0 a 255
   ```

2. Comment le compilateur C interprete-t-il un caractere entoure de guillemets simples?
   ```
   Un char
   ```

3. Quelle est la definition C d'une chaine? 
   ``` c
   char chaine[] = "chaine de caracteres";
   ```

4. Qu'est-ce qu'une chaine litterale?
   ```
   Un tableau de caracteres.
   ```

5. Pourquoi faut-il declarer un tableau de n + 1 elements pour stocker une chaine de longueur n?
   ```
   Car il y a le caractere nul '\0' de fin de chaine.
   ```

6. Comment le compilateur C interprete-t-il une chaine litterale?
   ```
   Comme une sequence de code ASCII correspondant suivi d'un '\0'.
   ```

# PARTIE 13

1. Qu'est ce que la portee ?
```
```