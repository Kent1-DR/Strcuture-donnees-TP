#include "pile.h"
#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX_PILE 100
struct str_pile {
    int s;
    type_element_pile valeurs[TAILLE_MAX_PILE];
};






// Primitives
pile * creerPile(void) {
    pile * p = malloc(sizeof(*p));
    p->s = 0;
    return p;
}


void empiler(pile * p, type_element_pile e) {
    if (p->s<TAILLE_MAX_PILE) {
        p->valeurs[p->s++] = e;
    } else {
        printf("ERREUR : dépassement de capacité de la pile\n");
        exit(EXIT_FAILURE);
    }
}



type_element_pile depiler(pile * p) {
    if (!pileVide(p)) {
        return p->valeurs[--p->s];
    } else {
        printf("ERREUR : dépilement d'une pile vide\n");
        exit(EXIT_FAILURE);
    }
}


type_element_pile sommet(pile * p ) {
    if (!pileVide(p)) {
    return p->valeurs[p->s-1];
    } else {
        printf("ERREUR : sommet d'une pile vide\n");
        exit(EXIT_FAILURE);
    }
}


bool pileVide(pile * p) {
    return p->s == 0;
}

int taillePile(pile * p ) {
    return p->s;
}
