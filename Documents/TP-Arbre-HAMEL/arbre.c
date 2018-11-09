#include "arbre.h"
#include "file.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

noeud* creerNoeud(int v)
{
    noeud* n=malloc(sizeof(noeud));
    printf(" ");
    n->Fdroit=NULL;
    n->Fgauche=NULL;
    n->valeur=v;
    return n;

}

void accroche(noeud *r, noeud *n)
{
    if(r->valeur > n->valeur)
    {
        printf("j'accroche a gauche de %i, le noeud %i\n", r->valeur, n->valeur);
        r->Fgauche=creerNoeud(n->valeur);
    }
    else
    {
        printf("j'accroche a droite de %i, le noeud %i\n", r->valeur, n->valeur);
        r->Fdroit=creerNoeud(n->valeur);
    }
}

void insererDansArbre(arbre *r, noeud *n)
{
    noeud *fils=malloc(sizeof(noeud));
    if(r->valeur>n->valeur)
    {
        if(r->Fgauche==NULL)
        {
            accroche(r, n);
        }
        else
        {
            fils=r->Fgauche;
            insererDansArbre(fils, n);
        }
    }
    else
    {
        if(r->Fdroit==NULL)
        {
            accroche(r, n);
        }
        else
        {
            fils=r->Fdroit;
            insererDansArbre(fils, n);
        }
    }
}

void insererTableau(arbre *r, int* tableau, int taille)
{
    int i;
    for(i=0; i<taille; i++)
    {
        insererDansArbre(r, creerNoeud(tableau[i]));
    }
}

void afficher(arbre *r, int decalage)
{
    int i;
    if(r==NULL) return;
    //printf("%-6i", r->valeur); //affichage du noeud
    printNoeud(r->valeur);
    if(r->Fdroit!=NULL) afficher(r->Fdroit, decalage+6); //afichage du noeud a droite, appel recursif

    //affichage du noeud gauche
    if(r->Fgauche!=NULL)
    {
        printf("\n");
        for(i=0; i<=decalage-1; i++)
        {
            printf(" ");
        }
        printf("|\n");
        for(i=0; i<=decalage-1; i++)
        {
            printf(" ");
        }
        afficher(r->Fgauche, decalage);
    }
}

void printNoeud(int n)
{
    /*if(imprimerChiffre==0)*/ printf("%-6i", n);
    //else if(imprimerChiffre==1) printf("%c", n);
    //else printf("valeur imprimerChiffre invalide");
}

noeud* rechercher(arbre *r, int v)
{
    if(v==r->valeur) return r;
    else if (r->valeur>v)
    {
        if (r->Fgauche!=NULL)

        return rechercher(r->Fgauche, v);

        else return NULL;
    }
    else if (r->Fdroit!=NULL)

    return rechercher(r->Fdroit, v);

    else return NULL;
}

noeud* rechercherDerniereLettre(arbre *unArbre)
{
    return rechercher(unArbre, 76);
}

void deforestationSauvage(noeud *n)
{
    n->Fgauche=NULL;
    n->Fdroit=NULL;
}

void deforestation(noeud *n)
{
    if(n==NULL) return;
    else
    {

        deforestation(n->Fgauche);
        deforestation(n->Fdroit);
        free(n->Fgauche);
        free(n->Fdroit);
        n->Fgauche=NULL;
        n->Fdroit=NULL;
    }
}

int somme(arbre *r)
{
    if(r!=NULL)
    {
        int s=r->valeur;
        return (s+somme(r->Fdroit)+somme(r->Fgauche));
    }
    else return 0;

}

int parcoursProfondeur(arbre *r)
{
    return parcoursProfondeurNiveau(r, 1, 0);
}

void couperPetits(arbre *a, int hauteur)
{
    if(a->Fgauche!=NULL)
    {
        if(a->Fgauche->valeur<hauteur)
        {
            if(a->Fgauche->Fdroit!=NULL)
            {
                a->Fgauche=a->Fgauche->Fdroit;
                couperPetits(a->Fgauche, hauteur);
            }
            else a->Fgauche=NULL;
        }
        else couperPetits(a->Fgauche, hauteur);
    }
}

void parcoursLargeur(arbre *r, int niveaumax)
{
    //Notre file vide:
    file *f = malloc(sizeof(file));
    f->taille=0;
    f->premier=NULL;
    f->dernier=NULL;


    //test enfiler
    /*enfiler(f, creerNoeud(1000));
    enfiler(f, creerNoeud(5));
    enfiler(f, creerNoeud(1));
    printFile(f);
    printf("\n");

    //test defiler

    noeud *dernier=defiler(f);
    printf("Defile : %i\n", dernier->valeur);
    printFile(f);*/

    enfiler(f, r);
    shiftEspace(0.5, niveaumax, 1, 0);
    parcoursLargeurRecursif(f, niveaumax);
    printf("\n");
}

void parcoursLargeurRecursif(file *f, int niveaumax)
{
    if(fileVide(f) == 1) return;
    noeud *n = defiler(f);
    printf("%i", n->valeur);
    if(n->Fgauche != NULL) enfiler(f, n->Fgauche);
    if(n->Fdroit != NULL) enfiler(f, n->Fdroit);
    if(fileVide(f) || (f->taille > 0 && f->dernier->n->niveau > n->niveau))
    {
        printf("\n");
        if (!fileVide(f))
        {
            int position_suivant = f->dernier->n->position;
            shiftEspace(position_suivant+0.5, niveaumax, f->dernier->n->niveau, 0);

        }
    }
    else
    {
        //printf("-");
        int position_courant = n->position;
        int position_suivant = f->dernier->n->position;
        int width = floor(log10(abs(n->valeur)))+1;
        shiftEspace(position_suivant - position_courant, niveaumax, n->niveau, width);
    }

    parcoursLargeurRecursif(f, niveaumax);
}

int parcoursProfondeurNiveau(arbre *r, int niveau, int position)
{
    if(r!=NULL)
    {
    int niveaumaxg = niveau;
    int niveaumaxd = niveau;
    printf("%i ", r->valeur);
    r->niveau = niveau;
    r->position = position;
    if(r->Fgauche != NULL)
    {
        niveaumaxg =  parcoursProfondeurNiveau(r->Fgauche, niveau+1, position*2);
    }
    if(r->Fdroit != NULL)
    {
        niveaumaxd = parcoursProfondeurNiveau(r->Fdroit, niveau+1, position*2+1);
    }
    return niveaumaxg > niveaumaxd ? niveaumaxg : niveaumaxd;
    }
    return 0;
}

void shiftEspace(double delta, int niveaumax, int niveau, int width)
{
    int i;
    int nb_espace = delta * pow(2, niveaumax-niveau)*4 - width;
    for(i=0; i<nb_espace; i++) printf(" ");
}






