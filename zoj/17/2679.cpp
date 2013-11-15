#include<stdio.h>

int main(void)
{
	long a;
	long b;
	long c;
	long i;
	long j;
	long k;
	long n;
	long t;
	long price;
	long TestCase;
	long flag;
	
	scanf("%ld", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		scanf("%ld", &n);
		scanf("%ld %ld %ld", &a, &b, &c);
		
		t = a * 1000 + b * 100 + c * 10;
		
		flag = 0;
		
		for (i=9; i>0; --i)
		{
			for (j=9; j>-1; --j)
			{
				price = (i * 10000 + t + j) / n;
				
				if (price * n == i * 10000 + t + j)
				{
					flag = 1;
					break;
				}
			}
			
			if (flag == 1)
			{
				break;
			}
		}
		
		if (flag == 0)
		{
			printf("0\n");
		}
		else
		{
			printf("%ld %ld %ld\n", i, j, price);
		}
	}
	
	return 0;
}
