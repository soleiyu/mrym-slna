#include <stdio.h>
#include <stdlib.h>
#include "ccmath.h"

double ELGET(double*, int, int, int);
void ELPUT(double*, int, int, int, double);
void fileLoad(char*, double*, double*, int);
void fileStore(char*, double*, int);

int main(int argc, char** argv)
{
	int n = atoi(argv[1]);
	double* a = (double*)malloc(sizeof(double) * n * n);
	double* b = (double*)malloc(sizeof(double) * n);

	fileLoad(argv[2], a, b, n);
	solv(a, b, n);
	fileStore(argv[3], b, n);
	
	return 0;
}

double ELGET(double* a, int m, int i, int j)
{
	return a[i * m + j];
}

void ELPUT(double* a, int m, int i, int j, double d)
{
	a[i * m + j] = d;
}

void fileLoad(char* fn, double* a, double* b, int n)
{
	FILE* fp = fopen(fn, "r");
	double val;
	int i, j;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			fscanf(fp, "%lf", &val);
			ELPUT(a, n, i, j, val);
		}

		fscanf(fp, "%lf", &val);
		ELPUT(b, 0, 0, i, val);
	}

	fclose(fp);
}

void fileStore(char* fn, double* b, int n)
{
	FILE* fp = fopen(fn, "w");
	int i;
	
	for (i = 0; i < n; i++)
		fprintf(fp, "%lf\n", ELGET(b, 0, 0, i)); 
		
	fclose(fp);
}
