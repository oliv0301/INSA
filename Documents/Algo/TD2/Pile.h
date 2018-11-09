#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

typedef struct
{
   int taille;
   element*tab;
   int sommet;
}Pile;

typedef Pile Pile;

Pile initPile(int taille);
int estVidePile (Pile p);
int estPleinePile (Pile p);
void empiler(Pile* pile, element x);

#endif // PILE_H_INCLUDED
