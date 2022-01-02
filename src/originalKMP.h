#ifndef ORIGINALKMP_H_
#define ORIGINALKMP_H_
#include "lib/dynamicArr.h"
#include "lib/utils.h"

int *computePi(char *pattern, int M);
ArrDy *originalKMP(char *text, char *pattern);
void printPi(int *pi, char *pattern, int M);

#endif