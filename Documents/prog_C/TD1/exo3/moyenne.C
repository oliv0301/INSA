double moyenne(double t[], int n)
{
	double moy=0;
	for(i=0; i<n; i++)
	{
		moy = moy + t[i]	
	}
	return moy/n;
}

double moyenne_positif(double t[])
{
	double moy=0;
	i=0;
	while(t[i]!<0)
	{
		moy = t[i] +moy;
		i++;
	}
	if (moy!=0) return moy;
	else return 0;	
}
