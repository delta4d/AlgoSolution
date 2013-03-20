#include<stdio.h>
#include<stdlib.h>

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
	double t;
	double max;
	double sum;
	double wire[20];
	int n;
	int i;
	
	scanf("%d", &n);

	while (n != 0)
	{
		for (i=0; i<n; ++i)
		{
			scanf("%lf", wire + i);
		}
		
		qsort(wire, n, sizeof(double), cmp);
		
		sum = 0;
		
		for (i=0; i<n; ++i)
		{
			if (wire[i] <= sum)
			{
				break;
			}
			else
			{
				sum += wire[i];
			}
		}
		
		if (i == n)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
		
		scanf("%d", &n);
	}

	return 0;
}
