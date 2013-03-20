#include<stdio.h>
#include<math.h>

long long phi(long long n)
{
	long long i;
	long long res = n;
	
	for (i=2; i<=sqrt((double)n); ++i)
	{
		if (n % i == 0)
		{
			res = (res / i) * (i - 1);
			
			while (n % i == 0)
			{
				n /= i;
			}
		}
	}
	
	if (n != 1)
	{
		res = (res / n) * (n - 1);
	}
	
	return res;
}

long long mod(long long base, long long exp, long long m)
{
	long long res = 1;
	
	while (exp != 0)
	{
		if (exp % 2 == 1)
		{
			res = ((res % m) * (base % m)) % m;
		}
		
		base = ((base % m) * (base % m)) % m;
		
		exp /= 2;
	}
	
	return res;
}

int main(void)
{
	long long TestCase;
	long long i;
	long long k;
	long long a;
	long long z;
	long long EulerNum;
	long long op;
	
	scanf("%lld", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		scanf("%lld %lld", &a, &z);
		
		EulerNum = phi(z);
		
		for (i=1; i<=sqrt((double)EulerNum); ++i)
		{
			if (EulerNum % i == 0)
			{
				if (mod(a, i, z) == 1)
				{
					op = i;
					break;
				}
				else if (mod(a, EulerNum/i, z) == 1)
				{
					op = EulerNum / i;
				}
			}
		}
		
		if (a == 1 || z == 1)
		{
			op = 1;
		}
		
		printf("%lld\n", 6 * op + 3);
	}
	
	return 0;
}
