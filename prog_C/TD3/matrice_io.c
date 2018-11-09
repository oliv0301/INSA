#include "matrice_io.h"
#include "alloc.h"
#include "matrice.h"
#include <stdlib.h>
#include <stdio.h>
matrice read_matrice(FILE *f)
{
	int nb_lignes, nb_colonnes, i, j;
	matrice mat;
	if(f!=NULL)
	{
		fscanf(f, "%d", &nb_lignes);
		printf("\n nb_lignes = %i", nb_lignes);
		fscanf(f, "%d", &nb_colonnes);
		printf("\n nb_colonnes = %i\n", nb_colonnes);
		mat = allouer_matrice(nb_lignes, nb_colonnes);
		for (i=0; i<nb_lignes; i++)
		{
			for (j=0; j<nb_colonnes; j++)
			{
				fscanf(f, "%d", &mat.m[i][j]);
			}
		} 
		affiche_matrice(mat);
		fclose(f);
		return mat;
	}
	else return mat;
}

void write_matrice(FILE *f, matrice mat)
{
	if(f!=NULL)
	{
		int i, j; 
		fprintf(f, "%i %i\n", mat.nb_lignes, mat.nb_colonnes);
		for (i=0; i<mat.nb_lignes; i++)
		{
			for (j=0; j<mat.nb_colonnes; j++)
			{
				fprintf(f, "%i ", mat.m[i][j]);
			}
		fprintf(f, "\n");
		}
	fclose(f);
	}
}

void affiche_matrice(matrice m)
{
	int i, j;
	for (i=0; i<m.nb_lignes; i++)
	{
		for(j=0; j<m.nb_colonnes; j++)
		{
			printf("%i ", m.m[i][j]);
		}
		printf("\n");
	}
}
