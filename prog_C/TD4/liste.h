/* file name  : liste.h
 * authors    : Simon MORIN / JF Lalande
 * created    : dim 08 jan 2006 16:39:01 CET
 *
 * modifications:
 * - Renommage de quelques fonctions.
 *
 */
#ifndef __LISTE_H__
#define __LISTE_H__

#include "vehicule.h"

// Structure de gesion de la liste
typedef struct LISTE_VEHICULE{
	vehicule *v;
	struct LISTE_VEHICULE *next;
  int size;
} liste_vehicule;


// Initialise une liste vide
liste_vehicule * init_liste();

// Ajoute un vehicule en queue
void add_vehicule(vehicule *v, liste_vehicule * l);

// Ajoute un vehicule en tete
void add_vehicule_head(vehicule *v, liste_vehicule *l);

// Enleve le premier vehicule et le retourne
vehicule * remove_first_vehicule(liste_vehicule * l);

// Retourne la tete de la liste
vehicule * get_first_vehicule(liste_vehicule * l);

// Retourne le dernier element de la liste
vehicule *get_last_vehicule(liste_vehicule * l);

// Detruit la liste des vehicules et les vehicules
void destroy_list_and_vehicules(liste_vehicule * l);

// Taille de la liste
int size(liste_vehicule * l);

//cherche un vehicule dans la liste
vehicule* cherche_vehicule(char*, liste_vehicule*);

//enleve un vehicule dont on connait le nom
vehicule* enlever_vehicule(char*, liste_vehicule*);

//renverse la liste des vehicules
liste_vehicule* renverser_liste(liste_vehicule*);
#endif
