#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long prime[35813];
long IsPrime[300001];
long factor[35900];

int cmp(const void * a, const void * b)
{
	return *(long *)a - *(long *)b;
}

void GenPrime()
{
	long i;
	long j;
	long k = 2;
	long t;
	long flag;
	
	for (i=2; 7*i+1<=300000; ++i)
	{
		t = 7 * i - 1;
		flag = 1;
		
		for (j=0; prime[j]<=sqrt(t); ++j)
		{
			if (t % prime[j] == 0)
			{
				flag = 0;
				break;
			}
		}
		
		if (flag == 1)
		{
			prime[k] = t;
			++k;
		}
		
		t = 7 * i + 1;
		flag = 1;
		
		for (j=0; prime[j]<=sqrt(t); ++j)
		{
			if (t % prime[j] == 0)
			{
				flag = 0;
				break;
			}
		}
		
		if (flag == 1)
		{
			prime[k] = t;
			++k;
		}
	}
	
	return; 
}

int main(void)
{
	long n;
	long i;
	long t;
	prime[0] = 6;
	prime[1] = 8;
	
	GenPrime();
	
	for (i=0; i<300001; ++i)
	{
		IsPrime[i] = 0;
	}
	
	for (i=0; i<35813; ++i)
	{
		IsPrime[prime[i]] = 1;
	}
	
	scanf("%ld", &n);
	
	while (n != 1)
	{	
		t = 0;
	
		for (i=1; i<=sqrt(n); ++i)
		{
			if (n % i == 0)
			{
				if (IsPrime[i] == 1)
				{
					factor[t] = i;
					++t;
				}
				if ((IsPrime[n/i] == 1) && ((n/i) != i))
				{
					factor[t] = n / i;
					++t;
				}	
			}	
		}
		
		qsort(factor, t, sizeof(factor[0]), cmp);
		
		printf("%ld: ", n);
		
		for (i=0; i<t-1; ++i)
		{
			printf("%ld ", factor[i]);
		}
		
		printf("%ld\n", factor[t-1]);
		
		scanf("%ld", &n);
	}
	
	return 0;
}
