#include <stdio.h>
#include <stdlib.h>
#include "Element.h"
#include "File.h"

File initFile(int taille)
{
    File f;
    f.taille=taille;
    f.tete=f.queue;
    f.queue=taille;
    f.tab=(element*) malloc(taille*sizeof(element));
    f.estPleine=0;
    return f;
}

int estVideFile(File f)
{
    return (f.estPleine==0);
}

int estPleineFile(File f)
{
    return (f.estPleine==1);
}

