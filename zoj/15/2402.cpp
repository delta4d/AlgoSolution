#include<stdio.h>

long long f[11][2001];

int main(void)
{
	long long n;
	long long m;
	long long i;
	long long j;
	long long k;
	long long TestCase;
	long long sum;
	
	for (i=0; i<11; ++i)
	{
		for (j=0; j<2001; ++j)
		{
			f[i][j] = 0;
		}
	}
	
	for (i=1; i<2001; ++i)
	{
		f[1][i] = i;
	}
	
	for (i=2; i<11; ++i)
	{
		for (j=2; j<2001; ++j)
		{
			sum = 0;
			
			for (k=j; k>1; --k)
			{
				sum += f[i-1][k/2];
			}
			
			f[i][j] = sum;
		}
	}
	
	scanf("%lld", &TestCase);
	
	for (k=1; k<=TestCase; ++k)
	{
		scanf("%lld %lld", &n, &m);
		
		printf("Case %lld: n = %lld, m = %lld, # lists = %lld\n", k, n, m, f[n][m]);
	}
	
	return 0;
}
