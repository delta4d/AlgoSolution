#include<stdio.h>

double C(long n, long m, double res)
{
	long i;
	
	if (m > n - m)
	{
		m = n - m;
	}
	
	for (i=1; i<m+1; ++i)
	{
		res = res * (double)(n-m+i) / (double)i;
	}
	
	return res;
}

int main(void)
{
	long n;
	long k;
	long s;
	long c[60];
	long p[60];
	long i;
	long j;
	double res;
	
	scanf("%ld %ld", &n, &k);
	
	while ((n != -1) || (k != -1))
	{
		s = 0;
		
		for (i=0; i<n; ++i)
		{
			scanf("%ld", c+i);
			s += c[i];
		}
		
		for (i=0; i<n; ++i)
		{
			scanf("%ld", p+i);
		}
		
		res = 1;
		
		if (k > s-k)
		{
			k = s - k;
		}
		
		for (i=1; i<k+1; ++i)
		{
			res = res * (double)i / (double)(s-k+i);
		}
		
		for (i=0; i<n; ++i)
		{
			if (p[i] <= c[i])
			{
				res = C(c[i], p[i], res);
			}
			else
			{
				res = 0;
				break;
			}
		}
		
		printf("%.5lf\n", res);
		
		scanf("%ld %ld", &n, &k);
	}
	
	return 0;
}