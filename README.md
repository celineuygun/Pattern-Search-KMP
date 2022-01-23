# Pattern-Search-KMP
## Table des matières
```
1. Introduction
2. Architecture de projet
3. Analyse
4. Résultats
5. Références
```
## 1. Introduction
L'algorithme de Knuth-Morris-Pratt (KMP) est une technique de recherche adaptée à la recherche de chaînes.
L'étape de l'algorithme KMP commence par faire correspondre le motif au début du texte. De gauche à droite, 
cet algorithme fera correspondre les caractères du motif avec les caractères du texte correspondant, jusqu'à 
ce que toutes les conditions soient remplies. L'algorithme a été conçu en 1970 par Knuth et Pratt, et dans 
un autre contexte, par Morris, et publié conjointement en 1977. Cet algorithme utilise une complexité 
temporelle et spatiale O(m) pour le prétraitement, puis pour l’algorithme on a une complexité temporelle O(n).

## 2. Architecture de projet
Les différents fichiers à utiliser dans le programme peuvent être ajoutés au dossier data. 
Le programme peut être exécuté avec la commande « make » et puis « ./main » dans le terminal.

```
data/
  test.txt
src/ 
  lib/
    dynamicArr.c 
    dynamicArr.h 
    hash.c
    hash.h
    utils.c
    utils.h 
  main.c
  makefile 
  optimizedKMP.c 
  optimizedKMP.h 
  originalKMP.c 
  originalKMP.h
```
## 3. Analyse
### 3.1. L’algorithme KMP
L'algorithme KMP trouve toutes les occurrences d'un motif de longueur m dans le texte de longueur n avec 
la complexité temporelle de O(m + n). L'algorithme KMP n'a besoin que d'autant d'espace que le motif (O(m)) 
pour le fonction de prétraitement et que d’autant d’espace de mémoire que le texte (O(n)) si le texte est lu 
à partir d'un fichier externe. Toutes les quantités O ne dépendent pas de la taille de l'espace alphabétique. 
Dans l’algorithme, on a besoin d’un tableau auxiliaire π qui donne pour chaque indice i du tableau, la longueur 
du plus grand suffixe du sous-mot de P qui finit à l’indice i qui est aussi préfixe propre de P.

### 3.2. L’optimisation en temps réel de l’algorithme KMP
L'objectif est d'éliminer les décalages inefficaces et de ne pas vérifier à nouveau le caractère incompatible.
Si aucune discordance ne se produit, le comportement est exactement le même que celui de l'algorithme KMP.
On doit trouver les lettres uniques dans le motif et utiliser le hachage pour y accéder plus facilement.
Pour construire la table de π, nous aurons besoin de tableau auxiliaire π[] de l'algorithme KMP. S'il y a une 
lettre dans le texte qui ne correspond pas à la lettre du motif, nous effectuons des décalages en fonction de 
cette table que nous avons créé.

## 4. Résultats
Le problème de correspondance de chaînes peut être pertinent dans de nombreuses situations, y compris, mais 
sans s'y limiter, l'utilisation de la fonction de recherche dans les éditeurs de texte, la constitution d'une 
base de données pour un moteur de recherche ou le traitement de séquences génomiques. L'algorithme KMP est un 
algorithme efficace de correspondance de chaînes grâce à Donald Knuth, Vaughan Pratt et James H. Morris. 
Il s'agit d'un algorithme de temps linéaire qui exploite l'observation selon laquelle chaque fois qu'une 
correspondance (ou une discordance) se produit, le motif lui-même contient suffisamment d'informations pour 
dicter d'où doit commencer le nouvel examen.

Dans le scénario en ligne d'aujourd'hui, trouver le contenu approprié dans un minimum de temps est le plus important. 
Les algorithmes de chaîne jouent un rôle essentiel pour cela. Dans le tableau ci-dessous, nous pouvons voir certains
de ces algorithmes et nous pouvons aussi voir que l'algorithme KMP est l'un des algorithmes de recherche les plus 
efficaces et le plus utilisé en raison de sa capacité à être l'algorithme résistant aux pannes dans le pire des cas.

Étant donné que la fonction préfixe(π) nous dit déjà ce qui doit être fait sur les parties déjà mises en correspondance, 
nous n'avons pas besoin de vérifier à nouveau ces parties et, par conséquent, un seul passage sur la chaîne est suffisant. 
Donc, la complexité temporelle de l'appariement est O(n) et la complexité temporelle est O(m) pour le prétraitement. Nous 
n'avons besoin que d'autant d'espace que le motif. Donc, l'espace requis est O(m). Globalement, la complexité temporelle 
de KMP est O(m + n). Mais depuis m ≤ n, cela est borné par O(n). C'est certainement mieux que l'habituel O(n^2).

La complexité temporelle est O(|Σ| . m) où Σ est des lettres uniques, pour le prétraitement de l’algorithme KMP optimisé 
en temps réel. L’espace requis est O(|Σ| . m) et la complexité temporelle est O(n + |Σ| . m). Le temps d'exécution et 
l'utilisation de l'espace semblent « pires » que l'algorithme KMP. Cependant, si nous recherchons le même motif dans 
plusieurs textes ou si l'ensemble alphabétique du motif est petit, car l'étape de prétraitement ne doit être effectuée 
qu'une seule fois et chaque caractère du texte sera comparé au plus une fois. Il est donc plus efficace que l'algorithme 
KMP et bon en pratique.

## 5. Références
```
http://www.iro.umontreal.ca/~hamelsyl/RechercheExacte.pdf
https://www.geeksforgeeks.org/real-time-optimized-kmp-algorithm-for-pattern-searching/
https://fr.acervolima.com/algorithme-kmp-optimise-en-temps-reel-pour-la-recherche-de-modeles/

