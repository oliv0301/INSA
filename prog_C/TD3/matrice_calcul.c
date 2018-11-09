#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"

matrice add_matrice(matrice m1, matrice m2)
{
	int i, j;
	matrice mat;
	if (m1.nb_lignes!=m2.nb_lignes || m1.colonnes!=m2.colonnes) printf ("addition impossible");
	mat = allouer_matrice(m1.nb_lignes, m1.nb_colonnes);
	for (i=0; i<mat.nb_lignes; i++)
	{
		for (j=0; i<mat.nb_colonnes; i++)
		{
			mat.m[i][j]=m1.m[i][j]+m2.m[i][j];
		}
	printf("matrice obtenue :\n");
	affiche_matrice(mat);
	return mat;
}
