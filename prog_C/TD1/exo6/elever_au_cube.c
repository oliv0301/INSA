void elever_au_cube(int *p)
{
	pile *p;
	p=malloc(sizeof(pile));
	if(p==NULL) return NULL;
	p->curseur=0;
	return p;
}

 void libere_pile(pile *p)
{
	free(p);
}

void ajoute_pile(pile *p, int n)
{
	if (pile_pleine==0)
	{
		p->tab[p->curseur]= n;
		p->curseur ++;
	}
}

int retire_pile(pile *p)
{
	p->curseur --;
	return p->tab[p->curseur];
}

int sommet_pile(pile *p)
{
	return p->tab[p->(curseur)-1];
}

int pile_vide(pile *p)
{
	return (p->curseur==0);	
}

int pile_pleine(pile *p)
{
        return (p->curseur==TMAX);
}

void affiche_pile(pile *p)
{
	int a= p->curseur;
	printf("(");
	while(pile_vide!=0)
	{
		printf("%d", retire_pile)
		if(pile_vide==0) printf(",");
	}
	printf(")");
	p->curseur =a;
}

