#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

long f[1000001];

int cmp(const void * a, const void * b)
{
	return *(long *)a - *(long *)b;
}

int main(void)
{
	long m;
	long i;
	long j;
	long left;
	long right;
	long mid;
	
	memset(f, 0, 1000001*sizeof(long));
	
	for (i=1; i<1000001; ++i)
	{
		for (j=i*2; j<1000001; j+=i)
		{
			f[j] += i;
		}
	}
	
	qsort(f, 1000001, sizeof(f[1]), cmp);
	
	while (scanf("%ld", &m) != EOF)
	{
		left = 0;
		right = 1000000;
		mid = (left + right) / 2;
		
		while (left <= right)
		{
			if (f[mid] <= m)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
			
			mid = (left + right) / 2;
		}
		
		printf("%ld\n", left-1);
	}
	
	return 0;
}
