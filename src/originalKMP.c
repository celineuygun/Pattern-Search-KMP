#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "originalKMP.h"

int *computePi(char *pattern, int M) {
    int *pi = calloc(M, sizeof(int));
    int len = 0;
    pi[0] = 0;
    for(int i = 1; i < M; ) {
        int retVal = isSameChar(pattern[i], pattern[len]);
        if(retVal == 1) {
            pi[i] = ++len;
            i++;
        } else if(retVal == 0) {
            if(len == 0)
                pi[i++] = 0;
            else
                len = pi[len - 1];
        } else { // si ni l'un ni l'autre ne sont imprimibles
            free(pi);
            pi = NULL;
            break;
        }
    } return pi;
}

ArrDy *originalKMP(char *text, char *pattern) {
    int N = strlen(text), M = strlen(pattern);
    int *pi = computePi(pattern, M);
    if(!pi) return NULL;
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
            if(j != 0)
                j = pi[j - 1];
            else
                i++;
        }
    } free(pi);
    return foundPatterns;
}

void printPi(int *pi, char *pattern, int M) {
    if(!pattern || !pi) return;
    printf("\t");
    for(int i = 0; i < M; ++i) {
        printf("%2d ", i);
    } printf("\n\t");
    for(int i = 0; i < M; ++i) {
        printf("%2c ", pattern[i]);
    } printf("\n\t");
    for(int i = 0; i < M; ++i) {
        printf("%2d ", pi[i]);
    } printf("\n");
}