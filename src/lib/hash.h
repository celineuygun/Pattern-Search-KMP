#ifndef HASH_H_
#define HASH_H_

#define ALPHABET_SIZE 70

typedef struct key {
    int index;
    char key;
    int *arr;
} Key;

unsigned long hashCompute(const char ch);
Key *hashLookup(Key **table, const char ch);
void deleteTable(Key **table);
int insertKey(Key **table, char ch, int size);

#endif