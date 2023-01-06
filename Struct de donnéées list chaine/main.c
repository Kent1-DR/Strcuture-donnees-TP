#include <stdio.h>
#include "liste.h"


void testMaillon(void) {
    
    maillon * m = creerMaillonVide();
    // getSuivant(Maillon()) = Maillon()
    if (getSuivant(m) != m) {
        printf("TEST MAILLON : ERREUR sur getSuivant(Maillon()) = Maillon()\n");
    }
    type_cle cle = 'A';
    maillon * m2 = creerMaillon(m, cle);
    //getSuivant(Maillon(s, c)) = s
    if (getSuivant(m2) != m) {
        printf("TEST MAILLON : ERREUR sur getSuivant(Maillon(s, c)) = s\n");
    }
    // getCle(Maillon(s, c)) = c
    if (getCle(m2) != cle) {
        printf("TEST MAILLON : ERREUR sur getCle(Maillon(s, c)) = c\n");
    }

    setSuivant(m, m2);
    // getSuivant(setSuivant(m, s)) = s
    if (getSuivant(m) != m2) {
        printf("TEST MAILLON : ERREUR sur getSuivant(setSuivant(m, s)) = s\n");
    }
    
    cle = 'B';
    setCle(m, cle);
    // getCle(setCle(m, e)) = e
    if (getCle(m) != cle) {
        printf("TEST MAILLON : ERREUR sur getCle(setCle(m, c)) = c\n");
    }

    cle = 'C';
    maillon * m3 = insererApres(m, cle);
    // getCle(insererApres(m, c)) = c
    if (getCle(m3) != cle) {
        printf("TEST MAILLON : ERREUR sur getCle(insererApres(m, c)) = c\n");
    }
    // insererApres(m,e) = getSuivant(m)
    if (getSuivant(m) != m3) {
        printf("TEST MAILLON : ERREUR sur insererApres(m, c) = getSuivant(m)\n");
    }
    // getSuivant(insererApres(m,e)) = getSuivant(getSuivant(m))
    if (getSuivant(m3) != getSuivant(getSuivant(m))) {
        printf("TEST MAILLON : ERREUR sur getSuivant(insererApres(m, c)) = getSuivant(getSuivant(m))\n");
    }
    
    cle = getCle(getSuivant(m));
    maillon * s= getSuivant(getSuivant(m));
    type_cle cleSup = supprimerSuivant(m); // cle(m3) = 'C' = cle
    // supprimerSuivant(m) = getCle(getSuivant(m))
    if (cle != cleSup) {
        printf("TEST MAILLON : ERREUR sur supprimerSuivant(m) = getCle(getSuivant(m))\n");
    }
    // getSuivant(supprimerSuivant(m)) = getSuivant(getSuivant(m))
    if (s != getSuivant(m)) {
        printf("TEST MAILLON : ERREUR sur getSuivant(supprimerSuivant(m)) = getSuivant(getSuivant(m))\n");
    }
    printf("FIN TEST MAILLON\n");
}

void  testListe(void) {


    liste * l = lcCreerListe();
    if (!lcEstVide(l)) {
        printf("TEST LISTE : ERREUR - la liste devrait être vide\n");
    }

    printf("Parcours liste vide\n\t=> Devrait afficher une chaine vide : ");
    lcParcourir(l);

    lcInsererOrdonne(l, 'L');
    lcInsererOrdonne(l, 'I');
    lcInsererOrdonne(l, 'S');
    lcInsererOrdonne(l, 'T');
    lcInsererOrdonne(l, 'E');
    if (lcEstVide(l)) {
        printf("TEST LISTE : ERREUR - la liste ne devrait pas être vide\n");
    }
    printf("Parcours\n\t=> Devrait afficher E->I->L->S->T-> : ");
    lcParcourir(l);

    lcSupprimerCle(l, 'E');// au début
    lcSupprimerCle(l, 'T');// A la fin
    lcSupprimerCle(l, 'L');// au milieu
    printf("Parcours\n\t=> Devrait afficher I->S-> : ");
    lcParcourir(l);

    lcSupprimerCle(l, 'I');
    lcSupprimerCle(l, 'S');
    
    printf("Parcours\n\t=> Devrait afficher une chaine vide : \n");
    lcParcourir(l);
    if (!lcEstVide(l)) {
        printf("TEST LISTE : ERREUR - la liste devrait être vide\n");
    }
    if (lcSupprimerCle(l, 'X')) {
        printf("TEST LISTE : ERREUR - lors de la suppression d'une clé inexistante\n");
    }
    lcInsererOrdonne(l, 'B');
    lcInsererOrdonne(l, 'A');
    if (!lcContient(l, 'B')) {
        printf("TEST LISTE : ERREUR - sur contient B\n");
    }
    if (lcContient(l, 'E')) {
        printf("TEST LISTE : ERREUR - sur contient E\n");
    }

    lcFreeListe(l);
}

int main(int argc, const char * argv[]) {
    testMaillon();
    testListe();
    return 0;
}
