#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arbre.h"


int main()
{
    printf("=====\nBEGIN [OHAMEL] C#=2\n");

    arbre * noeud0 = NULL;
    printf("=> Calling insererDansArbre\n");
    noeud0 = creerNoeud(51);
    noeud * noeud1 = creerNoeud(84);
    insererDansArbre(noeud0, noeud1);
    noeud * noeud2 = creerNoeud(48);
    insererDansArbre(noeud0, noeud2);
    noeud * noeud3 = creerNoeud(20);
    insererDansArbre(noeud0, noeud3);
    noeud * noeud4 = creerNoeud(55);
    insererDansArbre(noeud0, noeud4);
    noeud * noeud5 = creerNoeud(30);
    insererDansArbre(noeud0, noeud5);
    noeud * noeud6 = creerNoeud(76);
    insererDansArbre(noeud0, noeud6);
    noeud * noeud7 = creerNoeud(89);
    insererDansArbre(noeud0, noeud7);
    noeud * noeud8 = creerNoeud(58);
    insererDansArbre(noeud0, noeud8);
    noeud * noeud9 = creerNoeud(35);
    insererDansArbre(noeud0, noeud9);
    noeud * noeud10 = creerNoeud(75);
    insererDansArbre(noeud0, noeud10);
    noeud * noeud11 = creerNoeud(55);
    insererDansArbre(noeud0, noeud11);
    noeud * noeud12 = creerNoeud(106);
    insererDansArbre(noeud0, noeud12);
    noeud * noeud13 = creerNoeud(94);
    insererDansArbre(noeud0, noeud13);
    noeud * noeud14 = creerNoeud(68);
    insererDansArbre(noeud0, noeud14);
    noeud * noeud15 = creerNoeud(50);
    insererDansArbre(noeud0, noeud15);
    noeud * noeud16 = creerNoeud(95);
    insererDansArbre(noeud0, noeud16);
    noeud * noeud17 = creerNoeud(80);
    insererDansArbre(noeud0, noeud17);
    noeud * noeud18 = creerNoeud(16);
    insererDansArbre(noeud0, noeud18);

    printf("\nEND [OHAMEL]\n===\n");
    return 0;
}
