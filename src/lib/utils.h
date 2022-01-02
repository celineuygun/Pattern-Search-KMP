#ifndef UTILS_H_
#define UTILS_H_

#include <sys/time.h>
#include "hash.h"

#define TIMEIT(FUNC, REP) do { \
    struct timeval t1, t2; \
    long i; \
    gettimeofday(&t1, NULL); \
    for(i = 0; i < REP; ++i) { \
        FUNC; \
    } \
    gettimeofday(&t2, NULL); \
    printf("Average execution time of '%s' (Repetition = %ld): %f ms\n", #FUNC, i, ((((t2.tv_sec - t1.tv_sec) * 1000.0) + ((t2.tv_usec - t1.tv_usec) / 1000.0)) / REP)); \
} while (0)

void readFile(char **text);
int isSameLetter(const char ch1, const char c2);
char *makeAlphabet(char *str);

#endif