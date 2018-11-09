#include <stdio.h>
#include <stdlib.h>

typedef int Element;

struct cellule
{
  Element valeur;//donnée
  char nom[255];//nom du joueur
  struct cellule* suivant;//pointeur sur la cellule suivante
};


typedef struct cellule cellule ;
typedef struct
{      cellule* pt_tete;
}liste;



void init(liste*); // initialisation de la liste. A appeler avant toute utilisation d'une liste
int estVide(liste); // Test si une liste est vide
void ajouteEnTete(liste* ,Element x, char nom[]); // ajout d'un élément en tête de liste
void affiche(liste); // Parcours et affichage d'une liste
int tailleListe(liste); // retourne le nombre de cellule dans une liste
void detruire(liste*); // Désalloue complètement tous les éléments d'une liste
void ajoutePos(liste* maListe,Element x,int pos, char nom[]); // ajout d'un élément à la position désirée dans la liste
Element getValeur(liste maListe,int pos ); // retourne la clé contenue dans la cellule à la position pos, -1 si la mosition n'est pas correcte
char* getNom(liste maListe,int pos);//retourne le nom du joueur dont le score est à la position pos, -1 si la position n'est pas correcte
void setValeur(liste maListe,Element x,int pos );// modifie la clé de la cellule en position pos. Ne fait rien si pos est incorrect


