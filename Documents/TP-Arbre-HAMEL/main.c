#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "file.h"


int main(int argc, char** argv)
{
    arbre *unArbre = malloc(sizeof(arbre));
    arbre *arbre2 = malloc(sizeof(arbre));
    imprimerChiffre=0;
    int tableau[10]={1, 45, 800, -40, 300, 4, 5, 333, 1001, 700};
    int tab2[6]={1000, 5, 100, 1, 6, 200};
    int som;
    int niveaumax=0;
    /*noeud *noeud1=malloc(sizeof(noeud));
    noeud* noeud2=malloc(sizeof(noeud));
    noeud* noeud3=malloc(sizeof(noeud));*/

    unArbre = creerNoeud(666);
    arbre2 = creerNoeud(666);
    /*noeud1 = creerNoeud(5);
    printf("valeur de n = %i\n", noeud1->valeur);
    noeud2 = creerNoeud(1000);
    noeud3 = creerNoeud(100);

    accroche(unArbre, noeud1);
    accroche(unArbre, noeud2);
    accroche(noeud1, noeud3);*/

    insererDansArbre(unArbre, creerNoeud(5));
    insererDansArbre(unArbre, creerNoeud(1000));
    insererDansArbre(unArbre, creerNoeud(100));
    insererTableau(unArbre, tableau, 10);
    insererTableau(arbre2, tab2, 6);
    afficher(arbre2, 0);

    noeud *cherche100=rechercher(unArbre, 100);
    if(cherche100!=NULL) printf("\nj'ai trouve le noeud 100\n");
    noeud *cherche101=rechercher(unArbre, 101);
    if(cherche101!=NULL) printf("j'ai trouve le noeud 101\n");

    //deforestationSauvage(cherche100);
    deforestation(cherche100); //exerice26
    afficher(unArbre, 0);
    printf("\n\n");
    som=somme(arbre2);
    printf("somme arbre = %i\n\n", som);

    niveaumax = parcoursProfondeur(arbre2);
    printf("\n");

    //couperPetits(arbre2, 8); //exercice 31 et 32
    afficher(arbre2, 0);
    printf("\n\n");
    parcoursLargeur(arbre2, niveaumax);



    return 0;
}
