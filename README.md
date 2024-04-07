# Dynamic Programming - Problème de eendre la monnaie | Give change back problem

*** English section below ***

## Introduction
Élaborez un algorithme de programmation dynamique pour résoudre le problème « rendre la monnaie ». L'objectif est de trouver le plus petit nombre de pièces permettant d'obtenir une somme donnée, en utilisant une quantité suffisante de pièces pour chaque dénomination.

## Description du Problème
Étant donné un montant et une quantité suffisante de pièces pour chacune des valeurs D[1], D[2], ..., D[m], l'algorithme doit calculer le nombre de pièces de la solution optimale, puis retourner le nombre de pièces de chaque type utilisé dans cette solution.

## Algorithme de Programmation Dynamique
Nous disposons des tableaux M[j] pour les montants et D[i] pour les valeurs des pièces i. Pour chaque montant M[j] et chaque première dénomination i, nous définissons C[i, j] comme étant le plus petit nombre de pièces nécessaires pour rendre le montant M[j].

### Cas à Considérer
- Si j est égal à 0 (C[0, j]), alors le nombre minimal de pièces est infini.
- Si i est égal à 0 (C[i, 0]), alors le nombre minimal de pièces est 0.
- Si la valeur de la pièce D[i] est supérieure au montant M[j] (D[i] > M[j]), alors le nombre minimal de pièces reste le même que pour le montant précédent : C[i, j] = C[i-1, j].
- Sinon, le nombre minimal de pièces est le minimum entre le nombre de pièces pour le montant précédent (C[i-1, j]) et 1 ajouté au nombre de pièces pour le montant obtenu en retirant la valeur de la pièce D[i] du montant actuel et en divisant le résultat par 5 (C[i, (M[j] - D[i])/5]). Cela est dû au fait que les pièces minimales ont une valeur de 5c, donc on divise par 5 pour obtenir la valeur de j.

### Formule
C[i, j] = 0 si j = 0  
C[i, j] = ∞ si i = 0  
C[i, j] = C[i-1, j] si D[i] > M[j]  
C[i, j] = min(C[i-1, j], 1 + C[i, (M[j] - D[i])/5]) sinon, a noter que nous divisons ici par 5 puisqu’on a des pièces minimales de 5c, on divise par 5 pour avoir la valeur de j.

---

## Introduction
Develop a dynamic programming algorithm to solve the "give change back" problem. The goal is to find the smallest number of coins needed to reach a given amount, using a sufficient quantity of coins for each denomination.

## Problem Description
Given an amount and a sufficient quantity of coins for each value D[1], D[2], ..., D[m], the algorithm should calculate the number of coins in the optimal solution and return the number of coins of each type used in that solution.

## Dynamic Programming Algorithm
We have arrays M[j] for amounts and D[i] for coin values i. For each amount M[j] and each first denomination i, we define C[i, j] as the smallest number of coins needed to reach amount M[j].

### Cases to Consider
- If j is equal to 0 (C[0, j]), then the minimum number of coins is infinity.
- If i is equal to 0 (C[i, 0]), then the minimum number of coins is 0.
- If the value of coin D[i] is greater than amount M[j] (D[i] > M[j]), then the minimum number of coins remains the same as for the previous amount: C[i, j] = C[i-1, j].
- Otherwise, the minimum number of coins is the minimum between the number of coins for the previous amount (C[i-1, j]) and 1 added to the number of coins for the amount obtained by subtracting the value of coin D[i] from the current amount and dividing the result by 5 (C[i, (M[j] - D[i])/5]). This is because the minimum coins have a value of 5c, so we divide by 5 to get the value of j.

### Formula
C[i, j] = 0 if j = 0  
C[i, j] = ∞ if i = 0  
C[i, j] = C[i-1, j] if D[i] > M[j]  
C[i, j] = min(C[i-1, j], 1 + C[i, (M[j] - D[i])/5]) otherwise, noting that we divide by 5 here because we have minimum coins of 5c, we divide by 5 to get the value of j.
