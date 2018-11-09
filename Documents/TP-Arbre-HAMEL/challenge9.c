#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arbre.h"


int main()
{
    printf("=====\nBEGIN [OHAMEL] C#=9\n");

    arbre * noeud0 = NULL;
    printf("=> Calling parcoursProfondeur\n");
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
    afficher(noeud0, 0);
    printf("\nDepth-first traversal: \n");    parcoursProfondeur(noeud0);
    printf("\nSum: %i (should be %i) \n", somme(noeud0), 1185);
    printf("\nEND [OHAMEL]\n===\n");
    return 0;
}
