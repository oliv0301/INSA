#ifndef __PILE_H_
#define __PILE_H_
#define T_MAX 50
#include "vehicule.h"
typedef struct{
	int nbVehicule;
	vehicule **tpv;
}PileVehicule;

PileVehicule *init_pilevehicule();
void empile_vehicule(PileVehicule *, vehicule *);
vehicule * depile_vehicule(PileVehicule*);
void affiche_pilevehicule(PileVehicule *);
void supprime_pilevehicule(PileVehicule *)
#endif
