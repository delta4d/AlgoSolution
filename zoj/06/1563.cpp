#include<stdio.h>

long f[101];
long sum[101];
long price[101];

int main(void)
{
	long TestCase;
	long i;
	long j;
	long k;
	long a;
	long n;
	long t;

	scanf("%ld", &TestCase);

	for (k=0; k<TestCase; ++k)
	{
		sum[0] = 0;
		
		scanf("%ld", &n);
		
		for (i=1; i<n+1; ++i)
		{
			scanf("%ld %ld", &a, price+i);
			
			sum[i] = sum[i-1] + a;
		}
		
		f[0] = 0;
		
		for (i=1; i<=n; ++i)
		{
			f[i] = 0x7fffffff;
			
			for (j=i-1; j>-1; --j)
			{
				t = f[j] + (sum[i] - sum[j] + 10) * price[i];
				
				if (t < f[i])
				{
					f[i] = t;
				}
				
			}
			
		}
		
		printf("%ld\n", f[n]);
	}
	
	return 0;
}