#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double strips[100];

int cmp(const void *a, const void *b)
{
	double * c = (double *)a;
	double * d = (double *)b;
	
	if (*c < *d)
	{
		return -1;
	} 
	else
	{
		return 1;
	}
}

int main(void)
{
	int k;
	int i;
	int n;
	double res;

	while (scanf("%d", &n) != EOF)
	{
		for (i=0; i<n; ++i)
		{
			scanf("%lf", strips+i);
		}
		
		qsort(strips, n, sizeof(strips[0]), cmp);
		
		for (k=n-1; k>0; --k)
		{
			strips[k-1] = 2.0 * sqrt(strips[k] * strips[k-1]);
			
			qsort(strips, k, sizeof(strips[0]), cmp);
		}
		
		res = strips[0];
		
		printf("%.3lf\n", res);
	}

	return 0;
}
