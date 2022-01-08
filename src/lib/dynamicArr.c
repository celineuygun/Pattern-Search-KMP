#include <stdio.h>
#include <stdlib.h>
#include "dynamicArr.h"

/*
 * cree et renvoie un nouveau tableau dynamique
 * avec une capacite donnee (capacity)
 * complexite temp: O(1)
 */
ArrDy *createArrDy(int capacity) {
    ArrDy *new = calloc(1, sizeof(ArrDy));
    if(new) {
        new->capacity = capacity;
        new->size = 0;
        new->arr = calloc(capacity, sizeof(int));
        if(!new->arr) exit(1);
    } return new;
}

/*
 * supprime le tableau dynamique
 * complexite temp: O(1)
 */
void deleteArrDy(ArrDy **arrDy) {
    if(!arrDy || !(*arrDy)) return;
    free((*arrDy)->arr);
    free(*arrDy);
    *arrDy = NULL;
}

/*
 * renvoie l'element a l'indice donne (i)
 * complexite temp: O(1)
 */
int get(ArrDy *arrDy, int i) {
    if(!arrDy) printf("\nLe tableau dynamique est vide.\n");
    else if(i < 0 || i >= arrDy->size) printf("\nL'indice %d n'est pas valable.\n", i);
    else return arrDy->arr[i];
    return -1;
}

/*
 * remplace la valeur d'un element a l'indice donne (i)
 * par la valeur donnee (val)
 * complexite temp: O(1)
 */
void set(ArrDy *arrDy, int i, int val) {
    if(!arrDy) printf("\nLe tableau dynamique est vide.\n");
    else if(i < 0 || i >= arrDy->size) printf("\nL'indice %d n'est pas valable.\n", i);
    else arrDy->arr[i] = val;
}

/*
 * repousse un element (val) dans le tableau dynamique
 * complexite temp: O(n)
 */
void pushBack(ArrDy **arrDy, int val) {
    if(!(*arrDy)) {
        (*arrDy) = createArrDy(10);
    } else if((*arrDy)->size == (*arrDy)->capacity) {
        ArrDy *tmp = createArrDy(2 * (*arrDy)->capacity);
        for(int i = 0; i < (*arrDy)->size; ++i) tmp->arr[i] = (*arrDy)->arr[i];
        free((*arrDy)->arr);
        (*arrDy)->capacity *= 2;
        (*arrDy)->arr = tmp->arr;
        free(tmp);
    } (*arrDy)->arr[(*arrDy)->size++] = val;
}

/*
 * renvoie la taille du tableau dynamique
 * complexite temp: O(1)
 */
int getSize(ArrDy *arrDy) {
    if(!arrDy) return -1;
    return arrDy->size;
}

/*
 * renvoie la capacite du tableau dynamique
 * complexite temp: O(1)
 */
int getCapacity(ArrDy *arrDy) {
    if(!arrDy) return -1;
    return arrDy->capacity;
}

/*
 * imprime le tableau dynamique
 * complexite temp: O(n)
 */
void printArrDy(ArrDy *arrDy) {
    if(!arrDy) {
        printf("[]\n");
        return;
    } printf("[ ");
    for(int i = 0; i < arrDy->size; ++i) printf("%d ", arrDy->arr[i]);
    printf("]\n");
}