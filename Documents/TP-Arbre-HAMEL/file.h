#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "structures.h"

/*struct elementFile
{
    struct noeud *n;
    struct elementFile *precedent;
};
typedef struct elementFile elementFile;

struct file
{
    int taille;
    elementFile *premier;
    elementFile *dernier;
};
typedef struct file file;*/
/**
*@brief : fait appel a parcourLargeurRecursif apres avoir creer la file correspond a l'abre donné en parametre
*@param : *r (arbre), niveaumax (int)
*@return : void
*/
void parcoursLargeur(arbre *r, int niveaumax);
/**
*@brief : test si une file est vide ou non
*@param : *f (file)
*@return : int (1 si vide 0 sinon)
*/
int fileVide(file *f);
/**
*@brief : permet d'ajouter un element a la file, cette element ayant un noeud donner en parametre
*@param : *f(file), *n (noeud a ajouter)
*@return : void
*/
void enfiler(file *f, noeud *n);
/**
*@brief : affiche une file
*@param : *f (file a afficher)
*@return : void
*/
void printFile (file *f);
/**
*@brief : affiche un element d'une file passé en parametre
*@param : *f (element de la file)
*@return : void
*/
void printElementFile(elementFile *f);
/**
*@brief : permet de defiler le dernier element de la file et change le pointeur sur le dernier element de la file
*@param : *f (file)
*@return : noeud*
*/
noeud * defiler(file *f);

#endif // FILE_H_INCLUDED
