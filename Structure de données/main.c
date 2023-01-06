#include <stdio.h>
#include "abr.h"

int main(int argc, const char * argv[]) {
    abr * a = abrCreerVide();
    printf(abrEstVide(a) ? "OK\n" : "KO\n");
    
    abrAjouter(a, 'D');
    abrAjouter(a, 'A');
    abrAjouter(a, 'J');
    abrAjouter(a, 'L');
    abrAjouter(a, 'K');
    abrAjouter(a, 'B');
    abrAjouter(a, 'X');
    abrAjouter(a, 'Z');
    abrAjouter(a, 'C');
    
    abrAfficher(a); // doit afficher dans l'ordre alphabétique : ABCDJKLXZ
    printf("\n");
    printf(abrContient(a, 'R') ? "KO\n" : "OK\n");
    printf(abrContient(a, 'C') ? "OK\n" : "KO\n");
    
    abrFree(a);
    printf("TERMINE\n");
    return 0;
}
