#include<stdio.h>
#include<stdlib.h>

long f[5];

int cmp(const void *a, const void *b)
{
	return *(long *)a - *(long *)b;
}

int main(void)
{
	long i;
	long j;
	long k;
	long l;
	long n;
	long flag;
	
	scanf("%ld", &n);
	
	while (n != 0)
	{
		for (i=0; i<n; ++i)
		{
			scanf("%ld", f + i);
		}
		
		qsort(f, n, sizeof(f[0]), cmp);
		
		flag = 0;
		
		for (i=n-1; i>=0; --i)
		{
			for (j=n-1; j>=0; --j)
			{
				if (j == i)
				{
					continue;
				}
				
				for (k=j-1; k>=0; --k)
				{
					if (k == i)
					{
						continue;
					}
					
					for (l=k-1; l>=0; --l)
					{
						if (l == i)
						{
							continue;
						}
						
						if (f[i] == f[j] + f[k] + f[l])
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
				
				if (flag == 1)
				{
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
			printf("no solution\n");
		}
		else
		{
			printf("%ld\n", f[i]);
		}
		
		scanf("%ld", &n);
	}
	
	return 0;
}
