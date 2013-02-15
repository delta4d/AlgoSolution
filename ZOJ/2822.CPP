#include<stdio.h>
#include<math.h>

long long f[1121][15];
long long prime[187];

long long GenPrime()
{
	long long i;
	long long j;
	long long k = 1;
	long long flag = 1;
	
	for (i=3; i<=1120; ++i)
	{
		flag = 1;
		
		for (j=0; prime[j]<=sqrt(i); ++j)
		{
			if (i % prime[j] == 0)
			{
				flag = 0;
				break;
			}			
		}
		
		if (flag == 1)
		{
			prime[k] = i;
			++k;
		}
	}
	
	return k - 1;
}

int main(void)
{
	long long n;
	long long k;
	long long i;
	long long j;
	
	prime[0] = 2;
	
	for (i=0; i<1121; ++i)
	{
		for (j=0; j<15; ++j)
		{
			f[i][j] = 0;
		}
	}
	
	n = GenPrime();
	f[0][0] = 1;
	
	for (i=0; i<=n; ++i)
	{
		for (k=13; k>-1; --k)
		{
			for (j=1120; j>-1; --j)
			{
				if (j + prime[i] <= 1120)
				{
					f[j+prime[i]][k+1] += f[j][k];
				}
			}
		}
	}
	
	scanf("%lld %lld", &n, &k);
	
	while ((n !=0) || (k != 0))
	{
		printf("%lld\n", f[n][k]);
		
		scanf("%lld %lld", &n, &k);
	}
	
	return 0;
}
