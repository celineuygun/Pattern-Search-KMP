#ifndef OPTIMIZEDKMP_H_
#define OPTIMIZEDKMP_H_
#include "originalKMP.h"
#include "lib/hash.h"

Key **computePiTable(int *pi, char *pattern, char *pat_alphabet);
ArrDy *optimizedKMP(char *text, char *pattern, char *pat_alphabet);
void printPiTable(Key **table, char *pattern, int M);

#endif