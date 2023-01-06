#ifndef arbreBinaire_h
#define arbreBinaire_h

#include <stdbool.h>

typedef struct arbreBinaire arbreBinaire;
typedef unsigned char typeElement;

arbreBinaire * abCreerVide(void);
arbreBinaire * abCreer(arbreBinaire * g, typeElement v, arbreBinaire * d);
arbreBinaire * abFilsGauche(arbreBinaire *);
arbreBinaire * abFilsDroit(arbreBinaire *);
typeElement  abValeur(arbreBinaire *);
bool abEstVide(arbreBinaire *);

void abFree(arbreBinaire *);

void abSetFilsGauche(arbreBinaire *, arbreBinaire * g);
void abSetFilsDroit(arbreBinaire *, arbreBinaire * d);
void abSetValeur(arbreBinaire *, typeElement);

#endif /* arbreBinaire_h */
