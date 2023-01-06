#ifndef abr_h
#define abr_h

#include <stdbool.h> // pour le type bool
#include "arbreBinaire.h" // pour typeElement

typedef struct str_abr abr;

abr * abrCreerVide(void);
bool abrEstVide(abr *);
void abrAjouter(abr *, typeElement);
bool abrContient(abr *, typeElement);
void abrAfficher(abr *);
void abrFree(abr *);

#endif /* abr_h */
