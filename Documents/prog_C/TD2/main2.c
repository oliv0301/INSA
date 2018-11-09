#include "pile.h"
#include <stdio.h>
#include "vehicule.h"
int main(void)
{
	vehicule *v1, *v2, *v3;
	PileVehicule *pv;

	v1= init_vehicule("v1");
	v2= init_vehicule("v2");

//	saisie_vehicule(v1);
//	saisie_vehicule(v2);

	/*-------------------PILE-----------------*/
	printf("\n creation de la pile\n");
	//initialiser nbVehicule à zero et allouer de l'espace mémoire à pv
	pv = init_pilevehicule();
	empile_vehicule(pv,v1);
	empile_vehicule(pv,v2);
	printf("\n\n Affichage de la pile\n");
	affiche_pilevehicule(pv);
	
	printf("\n\nSupression d'un element de la pile\n\n");
	v3= depile_vehicule(pv);
	affiche_vehicule(v2);
	printf("\n\nPile après suppression\n\n");
	affiche_pilevehicule(pv);

	supprime_pilevehicule(pv);
	affiche_pilevehicule(pv);
	
	return 0;
}

