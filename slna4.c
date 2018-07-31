#include<stdio.h>
#include"ccmath.h"

#define N 4000000000
#define L 100000000

double queAns();
unsigned isUnder1(double);
double calDstSq(double, double);

void main ()
{
	setunfl(1);
	queAns();
}

double queAns()
{
	unsigned n, m = 0;

	for(n = 0; n < N; n++)
	{
		if(isUnder1(calDstSq(unfl(), unfl())))
			m++;

		if(n % L == 0)
			printf("PI = %lf\n", 4.0 * (double)m / (n + 1));
	}
}

unsigned isUnder1(double val)
{	return 1.0 < val ? 0 : 1; }

double calDstSq(double x, double y)
{	return x * x + y * y; }
