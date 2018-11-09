#include "pile.h"
#include "vehicule.h"
#include <stdlib.h>
#include <stdio.h>
PileVehicule *init_pilevehicule()
{
	PileVehicule *pv;
	pv = (PileVehicule *)malloc(sizeof(PileVehicule));
	pv->nbVehicule=0;
	pv->tpv=(vehicule **)malloc(sizeof(vehicule*)*50);
	return pv;
}

void empile_vehicule(PileVehicule *pv, vehicule *v)
{
	if(pv->nbVehicule<49){
	pv->tpv[pv->nbVehicule]=v;
	pv->nbVehicule ++;
	}
}

vehicule * depile_vehicule(PileVehicule *pv)
{
	if (pv->nbVehicule!=0){
		 pv->nbVehicule --;
		return pv->tpv[pv->nbVehicule];
	}
	else printf("pile vide");
	return NULL;
}	


void affiche_pilevehicule(PileVehicule *pv)
{
	int a=pv->nbVehicule;
	if (pv->nbVehicule!=0)
	{
	while (pv->nbVehicule>0)
		{	
		affiche_vehicule(depile_vehicule(pv));
		}
	pv->nbVehicule=a;
	}
	else printf("aucun vehicule a afficher");		
}

void supprime_pilevehicule(PileVehicule *pv)
{
	while (pv->nbVehicule !=0)
		{
		supprime_vehicule(depile(pv));	
		}
	free(pv->tpv);
	free(pv);	
}
