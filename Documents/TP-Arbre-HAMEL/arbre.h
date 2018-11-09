#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED
#include "structures.h"

int imprimerChiffre;

/*struct noeud
 {
    int valeur;
    struct noeud* Fgauche;
    struct noeud* Fdroit;
 };
 typedef struct noeud arbre;
 typedef struct noeud noeud;*/



/**
*@brief : cette fonction permet de creer un noeud, met son champ valeur égale a v, et met le pointeur Fgauche et FDroit a NULL
*@param : v (valeur du champ)
*@return : cette fonction retourne un pointeur sur noeud
*/
noeud* creerNoeud(int v);
/**
*@brief : cette fonction permet d'accrocher le noeud n comme sous noeud fils avec la règle établie dans l'énoncé
*@param : *r (arbre), *n (noeud)
*@return : void
*/
void accroche(noeud *r, noeud *n);
/**
*@brief : cette fonction permet d'insérer un noeud dans l'arbre binaire
*@param : *r (arbre), *n (noeud)
*@return : void
*/
void insererDansArbre(arbre *r, noeud *n);
/**
*@brief : cette fonction permet de creer et d'inserer tous les noeuds d'un arbre
*@param : *r (arbre), *tableau (valeur), taille (du tableau, int)
*@return : void
*/
void insererTableau(arbre *r, int* tableau, int taille);
/**
*@brief : cette fonction affiche un arbre
*@param : *r (arbre), decalage(int)
*@return : void
*/
void afficher(arbre *r, int decalage);
/**
*@brief : cette fonction permet d'afficher un noeud en remplacant les chiffres par des lettres ou pas
*@param : n(int)
*@return : void
*/
void printNoeud(int n);
/**
*@brief : cette fonction retrouve un noeud dont la valeur est val si il existe dans l'arbre
*@param : *r (arbre), val (int)
*@return : adresse du noeud ou NULL
*/
noeud* rechercher(arbre *r, int v);
/**
*@brief : cette fonction recherche la derniere lettre d'un login INSA dans l'arbre
*@param : *unArbre (arbre)
*@return : le noeud qui possède la derniere lettre si il existe sinon NULL;
*/
noeud* rechercherDerniereLettre(arbre *unArbre);
/**
*@brief : cette fonction permet de couper les fils d'un noeud
*@param : *n (noeud)
*@return : void
*/
void deforestationSauvage(noeud *n);
/**
*@brief : cette fonction deforeste tout les fils d'un noeud en désallouant recursivement la mémoire de tout les sous fils de ce noeud
*@param : *n(noeud)
*@return : void
*/
void deforestation(noeud *n);
/**
*@brief : cette fonction fais la somme de tout les noeuds d'un arbre
*@param : *r(arbre)
*@return : la somme (int)
*/
int somme(arbre *r);
/**
*@brief : cette fonction affiche sur une ligne le parcour en profondeur de l'arbre
*@param : *r (arbre)
*@return : retourne le niveau max
*/
int parcoursProfondeur(arbre *r);
/**
*@brief : cette fonction coupe tous les noeud ayant une valeur inférieur a la valeur donné en paramètre, cette valeur est inferieur a la racine
*@param : *a (arbre), hauteur (int)
*@return : void
*/
void couperPetits(arbre *a, int hauteur);
/**
*@brief : cette fonction affiche une file correspondant à un abre en défiler le noeud à afficher et en enfilant ses fils si il en a
*@param : *f (file), niveaumax (int)
*@return : void
*/
void parcoursLargeurRecursif(file *f, int niveaumax);
/**
*@brief : calcul la profondeur maximum de l'arbre
*@param : *r (arbre), niveau (int), position (int)
*@return
*/
int parcoursProfondeurNiveau(arbre *r, int niveau, int position);


#endif // ARBRE_H_INCLUDED
