#include "pile.h"
#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX_PILE 10
struct str_pile {
    int s;
    type_element_pile valeurs[TAILLE_MAX_PILE];
};

// Primitives
pile * creerPile(void) {
    pile * p = (pile *) malloc (sizeof(*p));
    p->s = 0;
    return p;
}
void empiler(pile * p, type_element_pile e) {
    p->s++;
    p->valeurs[p->s] = e;
}
type_element_pile depiler(pile * p) {
    p->s--;
    type_element_pile val = p->valeurs[p->s];
    p->valeurs[p->s] = NULL;
    return val;
}
type_element_pile sommet(pile * p ) {
    return p->valeurs[p->s - 1];
}
bool pileVide(pile * p) {
    return p->s == 0;
}
int taillePile(pile * p ) {
    return p->s;
}
