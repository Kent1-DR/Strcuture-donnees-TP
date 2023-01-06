#ifndef npi_h
#define npi_h

#include "file.h"

// Pour simplifier, on se limite à des expressions limitées aux operateur * et +,
// aux parenthèses et à des nombres à un seul chiffre

// Evaluation d'une expression polonaise inversée
int npiEval(char * expPostfixee);

// Traduction d'un expression infixée en notation postfixée (notation polonaise inversée
file * npiTraduire(char * expInfixee);

#endif /* npi_h */
