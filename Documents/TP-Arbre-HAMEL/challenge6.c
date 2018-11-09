#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arbre.h"


int main()
{
    printf("=====\nBEGIN [OHAMEL] C#=6\n");

    arbre * noeud0 = NULL;
    printf("=> Calling rechercherDerniereLettre and comparing the value\n");
    noeud0 = creerNoeud(51);
    int * tableau = calloc( 18, sizeof(int));
    tableau[0] = 84;
    tableau[1] = 48;
    tableau[2] = 20;
    tableau[3] = 55;
    tableau[4] = 30;
    tableau[5] = 76;
    tableau[6] = 89;
    tableau[7] = 58;
    tableau[8] = 35;
    tableau[9] = 75;
    tableau[10] = 55;
    tableau[11] = 106;
    tableau[12] = 94;
    tableau[13] = 68;
    tableau[14] = 50;
    tableau[15] = 95;
    tableau[16] = 80;
    tableau[17] = 16;
    insererTableau(noeud0, tableau, 18);
    noeud * n5 = rechercherDerniereLettre(noeud0);
    printf("Node found for your final letter: %i (%c) =? 76 (L) \n", n5->valeur, n5->valeur); 
    printf("\nEND [OHAMEL]\n===\n");
    return 0;
}
