#include "arbreBinaire.h"
#include <stdlib.h>


struct arbreBinaire {
    struct arbreBinaire * gauche;
    struct arbreBinaire * droit;
    typeElement valeur;
};


arbreBinaire * abCreerVide(void) {
    arbreBinaire * a = malloc(sizeof(*a));
    a->gauche = a;
    a->droit = a;
    return a;
}


arbreBinaire * abCreer(arbreBinaire * g, typeElement v, arbreBinaire * d) {
    arbreBinaire * a = malloc(sizeof(*a));
    a->gauche = g;
    a->droit = d;
    a-> valeur = v;
    return a;
}


arbreBinaire * abFilsGauche(arbreBinaire * a) {
    return a->gauche;
}
arbreBinaire * abFilsDroit(arbreBinaire * a) {
    return a->droit;
}
typeElement abValeur(arbreBinaire * a) {
    if (abEstVide(a)) {
        exit(3);
    }
    return a->valeur;
}

bool abEstVide(arbreBinaire * a) {
    return a->gauche == a && a->droit == a;
}

void abFree(arbreBinaire * a) {
    if (abFilsGauche(a) != a) {
        abFree(abFilsGauche(a));
    }
    if (abFilsDroit(a) != a) {
        abFree(abFilsDroit(a));
    }
    free(a);
}






void abSetFilsGauche(arbreBinaire * a, arbreBinaire * g) {
    a->gauche = g;
}

void abSetFilsDroit(arbreBinaire * a, arbreBinaire * d) {
    a->droit = d;
}

void abSetValeur(arbreBinaire * a, typeElement v) {
    a->valeur = v;
}
