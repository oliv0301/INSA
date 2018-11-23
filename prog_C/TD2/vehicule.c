#include "vehicule.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
vehicule *init_vehicule()
{
	vehicule *v;
	v=(vehicule *)malloc(sizeof(vehicule));
	strcpy(v->nom_modele,"toto");
	v->puissance = rand()%200+10;
	v->vitesse_max = rand()%300+80;
	//v->vitesse_max = 100;
	//v->puissance = 50;
	return v;
}

void affiche_vehicule(vehicule *v)
{
	printf("nom : %s\npuissance : %d\nvitesse max : %f \n", v->nom_modele, v->puissance, v->vitesse_max);
}

void supprime_vehicule(vehicule *v)
{
	free(v);
}

