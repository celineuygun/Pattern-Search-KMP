#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "utils.h"

#define BUFFER_SIZE 1000
#define FILENAME_SIZE 20

/*
 * lit le fichier et enregistre son contenu dans le parametre donne (text)
 */
void readFile(char **text) {
    int lenBuf = 0, first = 1;
    char buffer[BUFFER_SIZE], fileloc[] = "../data/";
    char *filename = calloc(FILENAME_SIZE, sizeof(char)), *file = calloc(strlen(fileloc) + FILENAME_SIZE + 1, sizeof(char));
    printf("\nEntrez le nom du fichier que vous souhaitez ouvrir.\n>> ");
    scanf(" %s", filename);
    strcpy(file, fileloc);
    strcat(file, filename);
    FILE *fp = fopen(file, "r");
    if(!fp){fprintf(stderr,"Erreur durant l'ouverture du fichier %s: %s\n", file, strerror(errno)); exit(EXIT_FAILURE);}
    while(fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        lenBuf = strlen(buffer);
        buffer[lenBuf - 1] = (buffer[lenBuf - 1] == '\n') ? '\0' : buffer[lenBuf - 1];                 
        if(first) {
            strcpy(*text, buffer);
            first = 0;
        } else strcat(*text, buffer);
    } fclose(fp);
    free(filename);
    free(file);
}

/*
 * verifie et renvoie 1 si deux caracteres donnes 
 * sont la meme lettre, sinon renvoie 0
 */
int isSameChar(const char ch1, const char ch2) {
    if(isalpha(ch1) && isalpha(ch2))
        if(ch1 == ch2 || toupper(ch1) == ch2 || toupper(ch2) == ch1)
            return 1;
        else return 0;
    else {
        if(ch1 == ch2) return 1;
        else return 0;
    }
}

/*
 * cree et renvoie un ensemble de caracteres avec la chaine donnee (str)
 */
char *makeAlphabet(char *str) {
    int len = strlen(str);
    char *alph = calloc(len, sizeof(char));
    Key **alphSet = calloc(ALPHABET_SIZE, sizeof(Key *));
    memset(alphSet, 0, ALPHABET_SIZE);
    for(int i = 0, j = 0; i < len; ++i) {
        if(hashLookup(alphSet, str[i])) continue;
        if(insertKey(alphSet, str[i], 0))
            alph[j++] = str[i];
    } deleteTable(alphSet);
    return alph;
}