#include "listes.h"

// Fonction interne au module
cellule* creerCellule(Element);

void init(liste* maListe)
 {
	 maListe->pt_tete =NULL;
 }

int estVide(liste maListe)
{
	return (maListe.pt_tete==NULL);
}

cellule* creerCellule(Element x)
{
    cellule* cell;
    cell=(cellule*) malloc(sizeof(cellule));
    cell->valeur=x;
    cell->suivant=NULL;
    return cell;
}

void ajouteEnTete(liste* maListe,Element x)
{
    cellule* p=creerCellule(x);
    p->suivant=maListe->pt_tete;
    maListe->pt_tete=p;
}


void affiche(liste deb)
{
    cellule* p= deb.pt_tete;

    if(!estVide(deb))
    {
      while (p!=NULL)
        {
          printf("%i ", p -> valeur);
          p=p->suivant;
        }
      printf("\n");
    }
    else
        printf("\n rien a afficher !!!\n");
    }

int tailleListe(liste maListe)
{
cellule* p=maListe.pt_tete;
int taille=0;
	while(p!=NULL )
	{
		taille++;
		p=p->suivant;
	}
return taille;

}

void detruire(liste* maListe)
{
cellule* p;
	if(!estVide(*maListe))
	{
	  while (maListe->pt_tete!=NULL)
	  {
		p=maListe->pt_tete;
		maListe->pt_tete=maListe->pt_tete->suivant;
		free(p);
	  }
	}
init(&maListe);
}

void ajoutePos(liste* maListe,Element x,int pos )
{
cellule* p,*prec,*ajout;
int i;
	if(!estVide(*maListe))
	{
		if((pos>=1) && (pos<=tailleListe(*maListe)+1))
		{
			if(pos==1)
                ajouteEnTete(maListe,x);
			else
			{
				p=maListe->pt_tete;
					for(i=1;i<pos;i++)
					{
						prec=p;
						p=p->suivant;
					}
				ajout=(cellule*)malloc(sizeof(cellule));
				ajout->valeur=x;
				prec->suivant=ajout;
				ajout->suivant=p;
			}
		}
	}
	else
    {
        ajouteEnTete(maListe,x);
    }

}

Element getValeur(liste maListe,int pos )
{
        int i = 1;
        cellule * p=maListe.pt_tete;
        if((pos>=1) && (pos<=tailleListe(maListe)))
		{
			while(i<pos)
            {
                p=p->suivant;
                i++;
            }
            return p->valeur;
		}
		return-1;
}

void setValeur(liste maListe,Element x,int pos )
{
        int i = 1;
        cellule * p=maListe.pt_tete;
        if((pos>=1) && (pos<=tailleListe(maListe)))
		{
			while(i<pos)
            {
                p=p->suivant;
                i++;
            }
            p->valeur=x;
		}
}
