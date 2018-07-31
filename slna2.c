//FORMAT
// ./cn B(double) n(int)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double pdf(double x);
double check(double o, double n);
double integral(double st, double en, int n, double(*f)(double));

int main (int argc, char** argv)
{
	double ans = integral(0, atof(argv[1]), atoi(argv[2]), pdf);
	printf("%lf\n", ans);

	return 0;
}

double integral(double st, double en, int n, double(*f)(double))
{
	double len, sum, s1, s2;
	double offset, interval, dx, gap;
	int i, div = 1; 

	printf("Integral Func %lf to %lf\n", st, en);
	len = en - st;

	sum = (f(st) + f(en)) * 0.5;
	s1 = sum * len;

	for (;;)
	{
		dx = len / (div << 1);
		offset = st + dx;
		interval = len / div;

		for(i = 0; i < div; i++)
			sum += f(offset + interval * i);
		s2 = sum * dx;

		gap = check(s1, s2);
		if (n < gap)
			break;

		s1 = s2;
		div = div << 1;
	}
	
	return s2;
}

double check(double o, double n)
{
	return -log10(fabs(n - o) / o);
}

double pdf(double x)
{
	return exp(-x * x / 2.0) / sqrt(2.0 * M_PI);
}

