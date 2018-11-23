#ifndef __VEHICULE_H_
#define __VEHICULE_H_

struct vehicule{
	char nom_modele[20];
	int puissance;
	float vitesse_max;
};

typedef struct vehicule vehicule;

void affiche_vehicule(vehicule *);
vehicule *init_vehicule();
void supprime_vehicule(vehicule *);

#endif
