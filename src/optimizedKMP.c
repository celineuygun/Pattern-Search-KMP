#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "optimizedKMP.h"

Key **computePiTable(int *pi, char *pattern, char *pat_alphabet) {
    if(!pi) return NULL;
    Key **tablePi = calloc(ALPHABET_SIZE, sizeof(Key *));
    memset(tablePi, 0, ALPHABET_SIZE);
    int M = strlen(pattern), patAlphSize = strlen(pat_alphabet);
    for(int i = 0; i < patAlphSize; ++i) {
        unsigned long hash = 0;
        int len = 0;
        while(len < M) {
            int retVal = isSameChar(pattern[pi[len]], pat_alphabet[i]);
            if(len == 0) {
                insertKey(tablePi, pat_alphabet[i], M);
                hash = hashCompute(pat_alphabet[i]);
            } 
            if(retVal == 1)
                tablePi[hash]->arr[len] = pi[len] + 1;
            else if(retVal == 0) {
                if(pi[len] == 0)
                    tablePi[hash]->arr[len] = 0;
                else
                    tablePi[hash]->arr[len] = tablePi[hash]->arr[pi[len] - 1];
            } else { // si ni l'un ni l'autre ne sont imprimibles
                free(tablePi);
                tablePi = NULL;
                break;
            } len++;
        }
    } return tablePi;
}

ArrDy *optimizedKMP(char *text, char *pattern, char *pat_alphabet) {
    int N = strlen(text), M = strlen(pattern);
    int *pi = computePi(pattern, M);
    Key **tablePi = computePiTable(pi, pattern, pat_alphabet);
    if(!tablePi) return NULL;
    ArrDy *foundPatterns = createArrDy(1);
    for(int i = 0, j = 0; i < N; ) {
        int retVal = isSameChar(text[i], pattern[j]);
        if(retVal == -1) { // si ni l'un ni l'autre ne sont imprimibles
            j = 0;
            i++;
            continue;
        } else if(retVal == 1) {
            i++; j++;
        }
        if(j == M) {
            pushBack(&foundPatterns, i - j);
            j = pi[j - 1];
        } else if(i < N && retVal == 0) {
            if(j > 0) {
                if(hashLookup(tablePi, text[i]) == NULL)
                    j = 0;
                else {
                    Key *node = hashLookup(tablePi, text[i]);
                    j = node->arr[j - 1];
                }
            } i++;
        }
    } free(pi);
    deleteTable(tablePi);
    return foundPatterns;
}

void printPiTable(Key **table, char *pattern, int M) {
    if(!table || !pattern) return;
    for(int i = 0; i < ALPHABET_SIZE; ++i) {
        if(table[i] == NULL) continue;
        printf("\n\t(%c)\n", table[i]->key);
        printPi(table[i]->arr, pattern, M);
    } printf("\n");
}