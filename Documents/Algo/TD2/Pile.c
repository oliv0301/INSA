#include <stdio.h>
#include <stdlib.h>
#include "Element.h"
#include "Pile.h"


Pile initPile (int taille)
{
    Pile p;
    p.taille=taille;
    p.sommet=0;
    p.tab=(element*) malloc(taille*sizeof(element));
    return p;

}

int estVidePile (Pile p)
{
    return (p.sommet==0);
}

int estPleinePile (Pile p)
{
     return (p.sommet==p.taille);
}

void empiler(Pile* pile, element x)
{
    if(((pile->sommet)+1) != pile->taille)
    {
        /*if(estVidePile(*pile)==1)
        {
        pile->tab[(pile->sommet)]=x;
        }
        else
        {*/
        pile->sommet++;
        pile->tab[(pile->sommet)]=x;

    }
    else printf("Pile pleine\n");
}
