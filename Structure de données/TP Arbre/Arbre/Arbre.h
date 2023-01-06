#pragma once

#ifndef Arbre_h
#define Arbre_h
#include <stdbool.h>


typedef struct arbre arbre;
typedef unsigned char TypeElement;
arbre* LectureFG(arbre* Arbre);
arbre* LectureFD(arbre* Arbre);
TypeElement LectureValeur(arbre* Arbre);
bool EstVide(arbre* Arbre);
arbre* ParcourirLargeur(arbre* Arbre)

#endif Arbre.h