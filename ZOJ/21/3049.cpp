#include<stdio.h>
#include<memory.h>

#define MaxN 1001
#define Inf 100000

struct price
{
	int p1;
	int p2;
}P[MaxN];

int f[MaxN];

int main(void)
{
	int i;
	int j;
	int k;
	int t;
	int p1;
	int p2;
	int sum;
	int cur;
	int n;
	int p0;
	int res;
	
	while (scanf("%d %d", &n, &p0) != EOF)
	{
		sum = 0;
		cur = 0;
		k = 0;
		
		for (i=0; i<n; ++i)
		{
			scanf("%d", &p1);
			
			if (getchar() != '\n')
			{
				scanf("%d", &p2);
				
				if (p2 - p0 <= p1)
				{
					cur += p1;
					sum += p1;
				}
				else
				{
					P[k].p1 = p1;
					P[k].p2 = p2;
					++k;
					sum += p2 - p0;
				}
			}
			else
			{
				sum += p1;
				cur += p1;
			}
		}
		
		if (cur >= p0)
		{
			printf("%d\n", sum);
		}
		else
		{
			for (i=1; i<=p0-cur; ++i)
			{
				f[i] = Inf;
			}
			
			f[0] = 0;
			
			for (i=0; i<k; ++i)
			{
				for (j=p0-cur; j>=0; --j)
				{
					if (f[j] != Inf)
					{
						t = j + P[i].p1;
						if (t > p0 - cur)
						{
							t = p0 - cur;
						}
						
						if (f[t] > f[j] + P[i].p2 - P[i].p1 - p0)
						{
							f[t] = f[j] + P[i].p2 - P[i].p1 - p0;
						}
					}
				}
			}
			
			if (f[p0-cur] == Inf)
			{
				for (i=0; i<k; ++i)
				{
					cur += P[i].p1;
				}
				
				res = cur;
			}
			else
			{
				res = sum - f[p0-cur];
			}
			
			printf("%d\n", res);
		}
	}
	
	return 0;
}
