#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "originalKMP.h"
#include "optimizedKMP.h"

#define TEXT_SIZE 5000
#define PATTERN_SIZE 100


int main() {
    int stop = 0, response = 0, response2 = 0, rep = 0;
    char *text = calloc(TEXT_SIZE, sizeof(char)), *pattern = calloc(PATTERN_SIZE, sizeof(char));
    ArrDy *patterns = NULL;
    char *alph = NULL;

    printf("\nVoulez-vous transferer des donnees depuis un fichier [1] ou en tant qu'entree [2]?\n>> ");
    scanf(" %d", &response2);
    while(!(response2 == 1 || response2 == 2)) {
        printf("\nMerci de faire un choix valable. Entrez seulement [1] ou [2].\n>> ");
        scanf(" %d", &response2);
    } if(response2 == 1)
        readFile(&text);
    else {
        printf("\nEntez le texte.\n>> ");
        scanf(" %[^\n]%*c", text);
    }
    printf("\nEntrez un motif a chercher (caracteres alphabetiques uniquement)\n>> ");
    scanf(" %[^\n]%*c", pattern);

    while(!stop) {
        printf("\nVeuillez selectionner l'action que vous souhaitez effectuer:\n");
        printf("[0] Quitter\n");
        printf("[1] Afficher le texte\n");
        printf("[2] Afficher le motif\n");
        printf("[3] Rechercher le motif dans un document avec l'algorithme KMP\n");
        printf("[4] Rechercher le motif dans un document avec l'algorithme KMP optimise en temps reel\n");
        printf("[5] Comparer les temps d'exécution des deux algorithmes\n");
        printf("[6] Faire une nouvelle entree de donnees\n");
        printf("[7] Entrer une nouvelle motif a chercher\n>> ");
        scanf(" %d", &response);

        deleteArrDy(&patterns);
        switch(response) {
            case 0:
                stop = 1;
                deleteArrDy(&patterns);
                free(text);
                free(pattern);
                break;

            case 1:
                printf("\n%s\n", text);
                break;

            case 2:
                printf("\n%s\n", pattern);
                break;
        
            case 3:
                patterns = originalKMP(text, pattern);
                printf("\nUne occurrence du motif aux positions: ");
                printArrDy(patterns);
                break;

            case 4:
                if(!alph) alph = makeAlphabet(pattern);
                patterns = optimizedKMP(text, pattern, alph);
                printf("\nUne occurrence du motif aux positions: ");
                printArrDy(patterns);
                break;
            
            case 5:
                printf("\nCombien de fois voulez-vous répéter l'exécution des algorithmes?\n>> ");
                scanf(" %d", &rep);
                if(!alph) alph = makeAlphabet(pattern);
                printf("\n");
                TIMEIT(originalKMP(text, pattern), rep);
                TIMEIT(optimizedKMP(text, pattern, alph), rep);
                break;

            case 6:
                printf("\nVoulez-vous transferer des donnees depuis un fichier [1] ou en tant qu'entree [2]?\n>> ");
                scanf(" %d", &response2);
                while(!(response2 == 1 || response2 == 2)) {
                    printf("\nMerci de faire un choix valable. Entrez seulement [1] ou [2].\n>> ");
                    scanf(" %d", &response2);
                } if(response2 == 1)
                    readFile(&text);
                else {
                    printf("\nEntez le texte.\n>> ");
                    scanf(" %[^\n]%*c", text);
                } break;

            case 7:
                if(alph) {
                    free(alph);
                    alph = NULL;
                }
                printf("\nEntrez un motif a chercher (caracteres alphabetiques uniquement)\n>> ");
                scanf(" %[^\n]%*c", pattern);
                break;

            default:
                printf("\nMerci de faire un choix valable.\n");
                break;
        }
    } return 0;
}