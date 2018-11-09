#include "matrice.h"
#include <stdlib.h>
#include <stdio.h>
#include "alloc.h"
matrice allouer_matrice(int nb_ligne,int nb_colonne)
{
	int i;
	matrice mat;
	mat.nb_lignes=nb_ligne;
	mat.nb_colonnes=nb_colonne;
	mat.m=malloc(nb_ligne*sizeof(mat.m));
	if (mat.m==NULL) printf("allocation impossible");
	for (i=0; i<nb_colonne; i++)
	{
		mat.m[i]=malloc(nb_colonne*sizeof(mat.m[i]));
		if (mat.m[i]==NULL) printf("erreur allocation");
	}
	printf("\n allocation fini\n");
	return mat;	
}

void detruire_matrice(matrice *m)
{
	int i;
	for (i=0; i<m->nb_colonnes; i++)
	{
		free(m->m[i]);
	}
	free(m->m);
	printf("\n destruction fini\n");
}	  
