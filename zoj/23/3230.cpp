#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

const long MaxN = 1000001;

long match[MaxN];

struct problem
{
	long a;
	long b;
}d[MaxN];

int cmp(const void *a, const void *b)
{
	struct problem * c = (struct problem *)a;
	struct problem * d = (struct problem *)b;
	
	return c -> a - d -> a;
}

int main(void)
{
	long n;
	long m;
	long p;
	long i;
	long j;
	long k;
	long len;
	
	while (scanf("%ld %ld %ld", &n, &m, &p) != EOF)
	{
		for (i=0; i<n; ++i)
		{
			scanf("%ld %ld", &d[i].a, &d[i].b);
		} 
		
		qsort(d, n, sizeof(d[0]), cmp);
		
		k = 0;
		len = 0;
		make_heap(match, match+len);
		
		for (i=0; i<m; ++i)
		{
			while ((p >= d[k].a) && (k < n))
			{
				match[len] = d[k].b;
				++len;
				push_heap(match, match+len);
				++k;
			}
			
			if (len > 0)
			{
				pop_heap(match, match+len);	
				p += match[len - 1];
				--len;
			}
		}
		
		printf("%ld\n", p);
	}
	
	return 0;
}
