#include<stdio.h>

int main(void)
{
	long coach[50010];
	long FrontMax[50010];
	long RearMax[50010];
	long TestCase;
	long k;
	long i;
	long j;
	long n;
	long m;
	long res;
	
	scanf("%ld", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		scanf("%ld", &n);
		
		for (i=0; i<n; ++i)
		{
			scanf("%ld", coach+i);
		}
		
		scanf("%ld", &m);
		
		for (i=0; i<n; ++i)
		{
			for (j=1; (j<m)&&(j+i<n); ++j)
			{
				coach[i] += coach[j+i];
			}
		}
		
		FrontMax[0] = coach[0];
		
		for (i=1; i<n; ++i)
		{
			FrontMax[i] = coach[i] > FrontMax[i-1] ? coach[i] : FrontMax[i-1];
		}
		
		RearMax[n-1] = coach[n-1];
		
		for (i=n-2; i>-1; --i)
		{
			RearMax[i] = coach[i] > RearMax[i+1] ? coach[i] : RearMax[i+1];
		}
		
		res = 0;
		
		for (i=m; i<n-m-m; ++i)
		{
			if (FrontMax[i-1] + coach[i] + RearMax[i+m] > res)
			{
				res = FrontMax[i-m] + coach[i] + RearMax[i+m];
			}
		}
		
		printf("%ld\n", res);
	}
	
	return 0;
}
