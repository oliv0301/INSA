#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arbre.h"


int main()
{
    printf("=====\nBEGIN [OHAMEL] C#=1\n");

    arbre * noeud0 = NULL;
    printf("=> Calling accroche\n");
noeud0 = creerNoeud(51);
    noeud * noeud1 = creerNoeud(84);
    accroche(noeud0, noeud1);
    noeud * noeud2 = creerNoeud(48);
    accroche(noeud0, noeud2);
    noeud * noeud3 = creerNoeud(20);
    accroche(noeud2, noeud3);
    noeud * noeud4 = creerNoeud(55);
    accroche(noeud1, noeud4);
    noeud * noeud5 = creerNoeud(30);
    accroche(noeud3, noeud5);
    noeud * noeud6 = creerNoeud(76);
    accroche(noeud4, noeud6);

    printf("\nEND [OHAMEL]\n===\n");
    return 0;
}
