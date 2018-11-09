#include "matrice.h"
#include "alloc.h"
#include <stdio.h>
#include <stdlib.h>
#include "matrice_io.h"
#include "matrice_calcul.h"
int main()
{
	matrice mat1, mat2, mat3;
	FILE *fichier1=fopen("matrice.txt", "r");
	FILE *fichier2=fopen("test.txt", "r");
	FILE *fichier3=fopen("test2.txt", "w");
	mat1 = read_matrice(fichier);
	mat2 = read_matrice(fichier2);
	mat3 = add_matrice (m1, m2);
	write_matrice(fichier3, mat3);
			
	/*int a, b;
	printf("nb lignes:");
	scanf("%i", &a);
	printf("nb colonnes:");
        scanf("%i", &b);

	matrice mat;
	mat = allouer_matrice(a, b);
	detruire_matrice(&mat);*/
	return 0;
}
