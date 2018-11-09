#include "listes.h"

int main()
{
    liste l;
    int i;
    int n=10;

    init(&l);
    for(i=0;i<n;i++)
        ajoutePos(&l,i,i+1);

    affiche(l);

    detruire(&l);
    return 0;
}
