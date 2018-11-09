#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
//FILE
struct elementFile
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
typedef struct file file;

//ARBRE
 struct noeud
 {
    int valeur;
    int niveau;
    int position;
    struct noeud* Fgauche;
    struct noeud* Fdroit;
 };
 typedef struct noeud arbre;
 typedef struct noeud noeud;

void shiftEspace(double delta, int niveaumax, int niveau, int width);
#endif // STRUCTURES_H_INCLUDED
