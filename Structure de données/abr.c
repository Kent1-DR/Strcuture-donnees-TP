#include "abr.h"
#include "arbreBinaire.h"
#include <stdio.h> // printf
#include <stdlib.h> // malloc

struct str_abr {
    arbreBinaire * debut;
};

// Creation de l'abr vide : un arbreBinaire dans début donc les fils gauche et droit sont le même arbreBinaire vide (z).
abr * abrCreerVide(void) {
    abr * a = malloc(sizeof(*a));
    arbreBinaire * z = abCreerVide();
    a->debut = abCreer(z, 0, z);
    return a;
}

// Indique si a est vide, c'est à dire si le sous-arbre droit de debut est vide.
// On peut aussi utiliser le fait que le fils gauche de début est toujours z, le seul
// arbreBinaire vide dans notre abr
bool abrEstVide(abr * a) {
    return abEstVide(abFilsDroit(a->debut));
    // ou return abFilsDroit(a->debut) == abFilsGauche(a->debut);
}

// Ajouter une valeur dans l'abr dans une version itérative
void abrAjouter(abr * a, typeElement v) {
    arbreBinaire * p = a->debut;
    arbreBinaire * n = abFilsDroit(p);
    // On descend en conservant la référence p au parent de n
    while (!abEstVide(n)) {
        p = n;
        n = v >= abValeur(n) ? abFilsDroit(n) : abFilsGauche(n);
    }
    // ici n est vide (condition d'arrêt du while), donc n=z
    // et on doit insérer en dessous de p
    arbreBinaire * nouveau = abCreer(n, v, n);
    if (v >= abValeur(p)) {
        abSetFilsDroit(p, nouveau);
    } else {
        abSetFilsGauche(p, nouveau);
    }
}

// Indique si a contient la valeur v
bool abrContient(abr * a, typeElement v) {
    // On met la valeur v dans z (le fils gauche de a->debut)
    abSetValeur(abFilsGauche(a->debut), v);
    arbreBinaire *n = abFilsDroit(a->debut);
    while (abValeur(n) != v) {
        n = v >= abValeur(n) ? abFilsDroit(n) : abFilsGauche(n);
    }
    // On a trouvé si n ne vaut pas z
    return n != abFilsGauche(a->debut);
}

// Fonction "interne", pas présente dans le .h
void afficherInfixeRecurs(arbreBinaire * ab) {
    if (!abEstVide(ab)) {
        afficherInfixeRecurs(abFilsGauche(ab));
        printf("%c", abValeur(ab));
        afficherInfixeRecurs(abFilsDroit(ab));
    }
}

// Affiche les valeurs de l'abr dans l'ordre croissant
void abrAfficher(abr * a) {
    // Si on avait fait abParcoursInfixe on pourrait l'utiliser sur début. Ici on va faire sans
    // en récursif
    afficherInfixeRecurs(abFilsDroit(a->debut));
}

// fonction interne : free de ab et de ses fils, sans free de z !
void freeRecurs(arbreBinaire * ab) {
    if (!abEstVide(ab)) {
        freeRecurs(abFilsGauche(ab));
        freeRecurs(abFilsDroit(ab));
        free(ab);
    }
}

// Première idée : abFree(a->debut); puis free(a); Attention, ne fonctionne pas cela
// opère plusieurs fois un free sur z !
// => on doit refaire du spécifique ici
void abrFree(abr * a) {
    // Attention à l'ordre des free : on ne peut pas faire de free de z avant l'appel récursif
    // car il opère des tests sur z en bout de branche et on doit conserver a->debut pour
    // avoir la référence à z
    freeRecurs(abFilsDroit(a->debut));
    free(abFilsGauche(a->debut));
    free(a->debut);
    free(a);
}
