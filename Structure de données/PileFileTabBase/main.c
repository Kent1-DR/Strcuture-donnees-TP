#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include "file.h"
#include "pile.h"
#include "npi.h"

#define NB_ELTS 5
#define FIRST_ELT 'A'
#define NB_LOOPS 5

void testFile(void) {
    file * f = creerFile();
    int i;
    for (i = 0; i < NB_LOOPS; i++) {
        if (!fileVide(f)) {
            printf("ERREUR TEST FILE : fileVide devrait renvoyer true\n");
        }
        for (int i = 0 ; i < NB_ELTS; i++) {
            type_element_file e = FIRST_ELT + i;
            enfiler(f, e);
            if (premier(f) != FIRST_ELT) {
                printf("ERREUR TEST FILE : premier devrait renvoyer %c\n", FIRST_ELT);
            }
            int taille = tailleFile(f);
            int tailleAttendue = i + 1;
            if (taille != tailleAttendue) {
                printf("ERREUR TEST FILE : taille attendue %d, taille retournée %d\n", tailleAttendue, taille);
            }
        }
        for (int i = 0; i <NB_ELTS; i++) {
            int taille = tailleFile(f);
            int tailleAttendue = NB_ELTS - i;
            if (taille != tailleAttendue) {
                printf("ERREUR TEST FILE : taille attendue %d, taille retournée %d\n", tailleAttendue, taille);
            }
            type_element_file e = defiler(f);
            type_element_file attendu = FIRST_ELT + i;
            if (e != attendu) {
                printf("ERREUR TEST FILE : defile %c, attendu %c\n", e, attendu);
            }
        }
        if (!fileVide(f)) {
            printf("ERREUR TEST FILE : la file devrait être vide\n");
        }
    }
    printf("TEST FILE TERMINE\n");
    free(f);
}

void testPile(void) {
    pile * p = creerPile();
    for (int i = 0; i<2; i++) {
        if (!pileVide(p)) {
            printf("ERREUR TEST PILE : pileVide devrait renvoyer true\n");
        }
        for (int i = 0 ; i < NB_ELTS; i++) {
            type_element_pile e = FIRST_ELT + i;
            empiler(p, e);
            if (sommet(p) != e) {
                printf("ERREUR TEST PILE : sommet devrait renvoyer %c\n", e);
            }
            int taille = taillePile(p);
            int tailleAttendue = i + 1;
            if (taille != tailleAttendue) {
                printf("ERREUR TEST PILE : taille attendue %d, taille retournée %d\n", tailleAttendue, taille);
            }
        }
        for (int i = 0; i < NB_ELTS; i++) {
            int taille = taillePile(p);
            int tailleAttendue = NB_ELTS - i;
            if (taille != tailleAttendue) {
                printf("ERREUR TEST PILE : taille attendue %d, taille retournée %d\n", tailleAttendue, taille);
            }
            type_element_pile e = depiler(p);
            type_element_pile attendu = FIRST_ELT + NB_ELTS -1 - i;
            if (e != attendu) {
                printf("ERREUR TEST PILE : depile %c, attendu %c\n", e, attendu);
            }
        }
        if (!pileVide(p)) {
            printf("ERREUR TEST PILE : la pile devrait être vide\n");
        }
    }
    free(p);
    printf("TEST PILE TERMINE\n");
}

void testNpiUnit(char * exp, int expectedResult) {
    char * trad=malloc(sizeof(exp));
    file * f = creerFile();
    f = npiTraduire(exp);
    if (f == NULL) {
        printf("ERREUR TEST NPI : NPI NULL\n");
        return;
    }
    int i=0;
    while (!fileVide(f)) {
        trad[i++] = defiler(f);
    }
    trad[i]= '\0';
    int result = npiEval(trad);
    if (result != expectedResult) {
        printf("ERREUR TEST NPI : %s = %d au lieu de %d. Votre NPI : %s\n", exp, result, expectedResult, trad );
    }
}
void testNpi(void) {
    testNpiUnit("2*(3*4*5+6*7)", 2*(3*4*5+6*7));
    testNpiUnit("(2+3)*(2+1)*((1+1)+1+2*3)", (2+3)*(2+1)*((1+1)+1+2*3));
    printf("FIN TEST NPI\n");
}

// Test des cas nominaux
int main(int argc, const char * argv[]) {
    testFile();
    testPile();
    testNpi();
    return EXIT_SUCCESS;
}
