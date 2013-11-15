#include<stdio.h>

#define MaxN 151
#define debug 0

double cx;
double cy;
double r;
double x[MaxN];
double y[MaxN];

int cross_product(int i, int j)
{
	double n = (x[i] - cx) * (y[j] - cy) - (y[i] - cy) *(x[j] - cx);
	
	if (n <= 0)
	{
		return 1;
	}
	
	return 0;
}

int in(double tx, double ty)
{
	if ((tx - cx) * (tx - cx) + (ty - cy) * (ty - cy) <= r * r)
	{
		return 1;
	}
	
	return 0;
}

int main(void)
{
	int i;
	int j;
	int k;
	int n;
	int max;
	int cur;
	double tx;
	double ty;
	
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	
	while (scanf("%lf %lf %lf %d", &cx, &cy, &r, &n) != EOF)
	{
		if (r <= 0)
		{
			break;
		}
		k = 0;
		for (i=0; i<n; ++i)
		{
			scanf("%lf %lf", &tx, &ty);
			if (in(tx, ty))
			{
				x[k] = tx;
				y[k] = ty;
				++k;
			}
		}
		
		max = 0;
		
		for (i=0; i<k; ++i)
		{
			cur = 1;
			for (j=0; j<k; ++j)
			{
				if (i == j)
				{
					continue;
				}
				
				if (cross_product(i, j) == 1)
				{
					++cur;
				}
			}
			
			if (cur > max)
			{
				max = cur;
			}
		}
		
		printf("%d\n", max);
	}
	
	return 0;
}