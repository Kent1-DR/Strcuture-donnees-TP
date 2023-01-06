
#include "pile.h"
#include "file.h"
#include "npi.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Indique si le caractère c est un opérateur
bool estOperateur(char c) {
    return c == '*' || c == '+';
}
// Indique si l'opérateur op1 est prioritaire sur lopérateur op2
bool estPrioritaire(char op1, char op2) {
    return op1 == '*' && op2 == '+';
}

// Evaluation d'une expression sous forme postfixée
int npiEval(char * exp) {
    pile * p = creerPile();
    int i=0;
    char c;
    while ((c = exp[i]) != '\0') {
        if (c >= '0' && c <= '9') {
            empiler(p, c - '0');
        } else if (c == '+') {
            empiler(p,depiler(p) + depiler(p));
        } else if (c == '*') {
            empiler(p, depiler(p) * depiler(p));
        }
        i++;
    }
    int res = depiler(p);
    free(p);
    return res;
}

// Traduction d'une expression infixée en expression postfixée
file * npiTraduire(char * exp) {
    pile * p = creerPile();
    file * f = creerFile();
    int i=0;
    char c;
    while ((c = exp[i]) != '\0') {
        if ((c >= '0' && c <= '9')) {
            enfiler(f, c);
        } else if (c == '(') {
            empiler(p, c);
        } else if (estOperateur(c)) {
            while (!pileVide(p) && estOperateur(sommet(p)) && estPrioritaire(sommet(p), c)) {
                enfiler(f, depiler(p));
            }
            empiler(p, c);
        } else if (c == ')') {
            while (sommet(p) != '(') {
                enfiler(f, depiler(p));
            }
            depiler(p);
        }
        i++;
    }
    while (!pileVide(p)) {
        enfiler(f, depiler(p));
    }
    free(p);
    return f;
}

