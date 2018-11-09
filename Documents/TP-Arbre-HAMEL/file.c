#include "arbre.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileVide(file *f)
{
    if(f->taille==0) return 1;
    else return 0;
}

void enfiler(file *f, noeud *n)
{
    if(fileVide(f)==1)
    {
        elementFile *fnew = malloc(sizeof(file));
        fnew->n=n;
        fnew->precedent=NULL;
        f->premier=fnew;
        f->dernier=fnew;
        f->taille ++;
    }
    else
    {
        elementFile *fnew = malloc(sizeof(file));
        fnew->n=n;
        fnew->precedent=NULL;
        f->premier->precedent = fnew;
        f->premier=fnew;
        f->taille ++;
    }
}

void printFile (file *f)
{
    printElementFile(f->dernier);
}

void printElementFile(elementFile *f)
{
        printf("%i->", f->n->valeur);
        if(f->precedent != NULL) printElementFile(f->precedent);
}

noeud * defiler(file *f)
{
    if(fileVide(f) != 1)
    {
        elementFile *dernier = malloc(sizeof(file));
        noeud *n = malloc(sizeof(noeud));
        dernier = f->dernier;
        n = dernier->n;
        f->dernier = dernier->precedent;
        free(dernier);
        f->taille --;
        return n;
    }
    return NULL;
}
