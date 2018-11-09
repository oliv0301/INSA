#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arbre.h"
#include "file.h" 

int main()
{
    printf("=====\nBEGIN [OHAMEL] C#=11\n");

    arbre * noeud0 = NULL;
    printf("=> Generating a queue of 5 elements\n");
    file * f = malloc(sizeof(file));
    f->taille=0;
    f->premier=NULL;
    f->dernier=NULL;
    noeud * noeud1 = creerNoeud(84);
    printf("Queuing 84\n");
    enfiler(f, noeud1);
    printf("Reverse print of the queue: ");
    printFile(f);
    noeud * noeud2 = creerNoeud(48);
    printf("Queuing 48\n");
    enfiler(f, noeud2);
    printf("Reverse print of the queue: ");
    printFile(f);
    noeud * noeud3 = creerNoeud(20);
    printf("Queuing 20\n");
    enfiler(f, noeud3);
    printf("Reverse print of the queue: ");
    printFile(f);
    noeud * noeud4 = creerNoeud(55);
    printf("Queuing 55\n");
    enfiler(f, noeud4);
    printf("Reverse print of the queue: ");
    printFile(f);
    noeud * noeud5 = creerNoeud(30);
    printf("Queuing 30\n");
    enfiler(f, noeud5);
    printf("Reverse print of the queue: ");
    printFile(f);

    printf("\nEND [OHAMEL]\n===\n");
    return 0;
}
