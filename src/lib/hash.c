#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash.h"
#include "../originalKMP.h"

/*
 * fonction de calcul de hachage pour des caracteres
 * renvoie -1 si la caractere donnee n'est pas imprimible
 * complexite temp: O(1)
 */
unsigned long hashCompute(const char ch) {
    if(ch >= 32 && ch <= 96) return ch - 32;
    else if(ch >= 'a' && ch <= 'z') return ch - 64;
    else if(ch >= 123 && ch <= 126) return ch - 58;
    else return -1;
}

/*
 * Cette fonction recherche une cle avec la valeur donnee (ch)
 * Si elle existe, la fonction renvoie la pointeur avec cette cle
 * sinon elle renvoie NULL
 * complexite temp: O(1)
 */
Key *hashLookup(Key **table, const char ch) {
    unsigned long hash = hashCompute(ch);
    if(hash == -1 || !table) return NULL;
    return table[hash];
}

/*
 * supprime la table de hachage
 * complexite temp: O(ALPHABET_SIZE)
 */
void deleteTable(Key **table) {
    if(!table) return;
    for(int i = 0; i < ALPHABET_SIZE; ++i) {
        if(table[i] == NULL) continue;
        free(table[i]->arr);
        free(table[i]);
        table[i] = NULL;
    } table = NULL;
}

/*
 * ajoute une nouvelle valeur a la table de hachage
 * complexite temp: O(1)
 */
int insertKey(Key **table, char ch, int size) {
    unsigned long hash = hashCompute(ch);
    if(hash != -1) {
        Key *new = calloc(1, sizeof(Key));
        if(new) {
            table[hash] = new;
            table[hash]->key = ch;
            table[hash]->arr = calloc(size, sizeof(int));
            return 1;
        }
    } return 0;
}