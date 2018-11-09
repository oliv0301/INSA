#include <stdlib.h>
#include <stdio.h>
#include "produit.h"
int main(void){
int a,b,c;
scanf("%d",&a);
scanf("%d",&b);
c = produit(a,b);
printf("\nle produit vaut %d\n",c);
return EXIT_SUCCESS;
}

