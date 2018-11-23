#ifndef __MATRICE_IO_H__
#define __MATRICE_IO_H__
#include "matrice.h"
#include <stdlib.h>
#include <stdio.h>
matrice read_matrice(FILE *);
void write_matrice(FILE *, matrice m);
void affiche_matrice(matrice);
#endif

