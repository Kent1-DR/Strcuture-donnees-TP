// Implantation du type abstrait maillon tel que définit dans liste.h
#include <stdlib.h>
#include <stdio.h>
#include "maillon.h"

// Implantation du type maillon
struct maillon {
    // A COMPLETER
};

maillon * creerMaillonVide(void) {
    // A COMPLETER/CORRIGER
    return NULL;

}

maillon * creerMaillon(maillon * suivant, type_cle cle) {
    
    // A COMPLETER/CORRIGER
    return NULL;
}


maillon * insererApres(maillon * m, type_cle cle) {
    
    // A COMPLETER/CORRIGER
    return NULL;
    
}

type_cle supprimerSuivant(maillon * m) {
    
    // A COMPLETER/CORRIGER
    return 123;
}

void setSuivant(maillon * m, maillon * suivant) {
    
    // A COMPLETER
}

maillon * getSuivant(maillon * m) {
    
    // A COMPLETER/CORRIGER
    return NULL;
}

type_cle getCle(maillon * m) {
    
    // A CORRIGER
    return 123;
}

void setCle(maillon * m, type_cle cle) {
    
    // A COMPLETER
}
