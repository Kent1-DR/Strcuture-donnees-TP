// Implantation du type abstrait liste tel que définit dans  liste.h
#include "liste.h"
#include "maillon.h"
#include <stdlib.h>
#include <stdio.h>

// Implantation du type liste
struct liste {
    // A COMPLETER
};

liste * lcCreerListe(void) {
    
    // A COMPLETER/CORRIGER
    return NULL;
}

bool lcEstVide(liste * l) {
    
    // A CORRIGER
    return false;
}

void lcFreeListe(liste* l) {
    // A COMPLETER
}

void lcParcourir(liste* l) {
    // A COMPLETER/CORRIGER
    printf("PARCOURS\n");
}

void lcInsererOrdonne(liste* l, unsigned char cle) {
    
    // A COMPLETER/CORRIGER
}

bool lcContient(liste* l, unsigned char cle) {
    
    // A COMPLETER/CORRIGER
    return false;
}

bool lcSupprimerCle(liste* l, unsigned char cle) {
    
    // A COMPLETER/CORRIGER
    return true;
}
