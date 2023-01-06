// Implantation du type abstrait liste tel que définit dans  liste.h
#include "liste.h"
#include "maillon.h"
#include <stdlib.h>
#include <stdio.h>

// Implantation du type liste
struct liste 
{
    maillon * debut;
    maillon * fin;
};

liste * lcCreerListe(void) 
{
    liste * l = (liste *) malloc(sizeof(liste));
    l->debut = creerMaillonVide();
    l->fin = creerMaillonVide();
    setSuivant(l->debut, l->fin);
    return l;
}

bool lcEstVide(liste * l) 
{
    return getSuivant(l->debut) == l->fin;
}

void lcFreeListe(liste* l) 
{
    while (! lcEstVide(l))
    {
        supprimerSuivant(l->debut);
    }
    free(l);
}

void lcParcourir(liste* l) 
{
    maillon * m = getSuivant(l->debut);
    printf("PARCOURS\n"); 
    while (m != getSuivant(m))
    {
        printf("%c\n", getCle(m));
        m = getSuivant(m);
    }
    printf("FIN PARCOURS\n");   
}



void lcInsererOrdonne(liste* l, unsigned char cle) 
{
    maillon * m = l->debut;
    maillon * s = getSuivant(l->debut);
    while (getCle(s) <= cle && s != getSuivant(s))
    {
        m = s;
        s = getSuivant(m);
    }
    insererApres(m, cle);
}



bool lcContient(liste* l, unsigned char cle) 
{
    bool test = false;
    if (! lcEstVide(l))
    {
        maillon * m = getSuivant(l->debut);
        while (m != getSuivant(m))
        {
            if (getCle(m) == cle)
            {
                test = true;
            }
            m = getSuivant(m);
        }
    }    
    return test;
}

bool lcSupprimerCle(liste* l, unsigned char cle) 
{
    bool test = false;
    if (! lcEstVide(l))
    {
        maillon * mp = l->debut;
        maillon * m = getSuivant(mp);
        while (m != getSuivant(m))
        {
            if (getCle(m) == cle)
            {
                supprimerSuivant(mp);
                test = true;
                m = l->fin;
            }
            else
            {
                mp = m;
                m = getSuivant(mp);
            }
        }
    }    
    return test;
}
