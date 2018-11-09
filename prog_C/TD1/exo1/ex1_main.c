#include <stdio.h>
int main(void)
{
	int n;
	do {
		printf("Entrer un nombre entier (0 pour terminer):");
		scanf("%d",&n);
		printf("factorielle_ierative (%2d) = %15d\n", n, factorielle_iter(n));
		printf("factorielle_ierative (%2d) = %15d\n", n, factorielle_rec(n));
	}
	while (n!=0);
	return 0;
}		

