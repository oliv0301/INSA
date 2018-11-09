int chaine_longueur_rec(char *s)
{
        if (*s == 0) return 0;
        else return (1 + chaine_longueur_rec(s+1)
}

int chaine_debute_par(char *s1, char *s2)
{
	if (*s2 == 0) return 1;
	if (*s2!=*s1) return 0;
	else return chaine_debute_par(s1+1, s2+1);
}

int chaine_index(char *s1, char *s2)
{
	int i;
	for(i=0; s1[i] != '\0')
	{
		if (chaine_commence_par(s1+i, s2) return i;
	}
	return -1
}
