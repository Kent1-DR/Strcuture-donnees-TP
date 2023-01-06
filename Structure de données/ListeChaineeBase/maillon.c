// Implantation du type abstrait maillon tel que définit dans liste.h
#include <stdlib.h>
#include <stdio.h>
#include "maillon.h"

// Implantation du type maillon
struct maillon 
{
    type_cle cle;
    maillon * suivant;
};



maillon * creerMaillonVide(void) 
{
    maillon * m = (maillon *) malloc(sizeof(maillon));
    m->suivant = m;
    return m;
}




maillon * creerMaillon(maillon * suivant, type_cle cle) 
{
    maillon * m = (maillon *) malloc(sizeof(maillon));
    m->cle = cle;
    m->suivant = suivant;
    return m;
}


maillon * insererApres(maillon * m, type_cle cle) 
{
    maillon * nm = creerMaillon(m->suivant, cle);
    m->suivant = nm;
    return nm;
}

type_cle supprimerSuivant(maillon * m) 
{
    type_cle cle = m->suivant->cle;
    maillon * suivant = m->suivant->suivant;
    free(m->suivant);
    m->suivant = suivant;
    return cle;
}







void setSuivant(maillon * m, maillon * suivant) 
{
    m->suivant = suivant;
}

maillon * getSuivant(maillon * m) 
{
    return m->suivant;
}

type_cle getCle(maillon * m) 
{
    return m->cle;
}

void setCle(maillon * m, type_cle cle) 
{
    m->cle = cle;
}
