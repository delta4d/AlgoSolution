#include<stdio.h>
#include<math.h>

int main(void)
{
	long TestCase;
	long m;
	long n;
	long i;
	long j;
	long k;
	long res;
	long order;
	long temp;
	
	scanf("%ld", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		scanf("%ld %ld", &n, &m);
		order = 1;
		
		while (n != 0 || m != 0)
		{
			res = 0;
			
			for (i=1; i<n; ++i)
			{
				for (j=i+1; j<n; ++j)
				{
					temp = (i * i + j * j + m) / (i * j);
					
					if (temp * i * j == i * i + j * j + m)
					{
						++res;
					}
				}
			}
			
			printf("Case %ld: %ld\n", order, res);
			
			++order;
			
			scanf("%ld %ld", &n, &m);
		}
		
		if (k < TestCase - 1)
		{
			printf("\n");
		}
	}
	
	return 0;
}
