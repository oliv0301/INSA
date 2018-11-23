#include <math.h>
#define ZERO pow(1, -100)
#define EPSILON pow(1, -10)
int proche(double a, double b)
{
	return (fabs(a-b)<=EPSILON); 		
}
