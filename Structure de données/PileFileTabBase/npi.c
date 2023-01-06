
#include "pile.h"
#include "file.h"
#include "npi.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Indique si un caractère représente un opérateur
bool estOperateur(char c) {
    return c == '*' || c == '+';
}
// Indique si l'opérateur op1 est prioritaire sur l'opérateur op2
bool estPrioritaire(char op1, char op2) {
    return op1 == '*' && op2 == '+';
}

int npiEval(char * expPostfixee) {
    // .... A MODIFIER ...
    return -1;
}

file * npiTraduire(char * expInfixee) {
    // .... A MODIFIER ...
    return NULL;
}

