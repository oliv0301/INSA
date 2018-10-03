#include <limits.h>
int factorielle_iter(const int n)
{
	int i, p=1;
	for(i=1; i<=n;++i)
	{ 
		p = p*i;
		if (INT_MAX/i<p) return -1;
	}
	return p;
}

int factorielle_rec(int n)
{
	if (n<=0) return 1;
	else return n*factorielle_rec(n-1);
}
