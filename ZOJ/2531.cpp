#include<stdio.h>
#include<math.h>

#define MaxN 65536
long f[MaxN];

void gen()
{
	int i;
	int j;
	int off;
	int k = 1;
	
	f[0] = 0;
	
	for (i=1; i<17; ++i)
	{
		off = (long)pow(2, i-1);
		
		for (j=0; j<k; ++j)
		{
			f[2*off-j-1] = f[j] + off;
		}
		
		k += off;
	}
	
	return;
}

int main(void)
{
	long n;
	long p;
	long i;
	long k;
	
	gen();
	
	scanf("%ld %ld", &n, &p);
	
	while (n != 0 || p != 0)
	{
		k = (p - 1 + n) % n;
		
		for (i=p; i!=k ; i=(i+1>=n ? i+1-n : i+1))
		{
			printf("%ld ", f[i]);
		}
		
		printf("%ld\n", f[k]);
		
		scanf("%ld %ld", &n, &p);
	}
	
	return 0;
}
