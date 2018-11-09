#include <stdio.h>
#include <stdlib.h>

typedef int Element;

struct cellule
{
  Element valeur;//donn�e
  char nom[255];//nom du joueur
  struct cellule* suivant;//pointeur sur la cellule suivante
};


typedef struct cellule cellule ;
typedef struct
{      cellule* pt_tete;
}liste;



void init(liste*); // initialisation de la liste. A appeler avant toute utilisation d'une liste
int estVide(liste); // Test si une liste est vide
void ajouteEnTete(liste* ,Element x, char nom[]); // ajout d'un �l�ment en t�te de liste
void affiche(liste); // Parcours et affichage d'une liste
int tailleListe(liste); // retourne le nombre de cellule dans une liste
void detruire(liste*); // D�salloue compl�tement tous les �l�ments d'une liste
void ajoutePos(liste* maListe,Element x,int pos, char nom[]); // ajout d'un �l�ment � la position d�sir�e dans la liste
Element getValeur(liste maListe,int pos ); // retourne la cl� contenue dans la cellule � la position pos, -1 si la mosition n'est pas correcte
char* getNom(liste maListe,int pos);//retourne le nom du joueur dont le score est � la position pos, -1 si la position n'est pas correcte
void setValeur(liste maListe,Element x,int pos );// modifie la cl� de la cellule en position pos. Ne fait rien si pos est incorrect


