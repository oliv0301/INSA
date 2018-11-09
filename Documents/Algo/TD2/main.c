#include <stdio.h>
#include <stdlib.h>
#include "Element.h"
#include "Pile.h"
#include "File.h"


int main()
{
    element i;
    Pile pile = initPile(4);
    File file = initFile(4);
    for(i=1; i<=4; i++)
    {
        empiler(&pile, i);
        printf("valeur : %i\n", pile.tab[i-1]);
        printf("La pile est-elle vide ?\n %i\n", estVidePile(pile));
        printf("La pile est-elle pleine ?\n %i\n", estPleinePile(pile));
    }

    /*printf("La pile est-elle vide ?\n %i\n", estVidePile(pile));
    printf("La pile est-elle pleine ?\n %i\n", estPleinePile(pile));

    printf("La liste est-elle vide ?\n %i\n", estVideFile(file));
    printf("La liste est-elle pleine ?\n %i\n", estPleineFile(file));

    printf("1==1 ? %i\n", 1==1);
    printf("1==2 ? %i\n", 1==2);
    printf("1==3 ? %i\n", 1==3);*/

    return 0;
}
