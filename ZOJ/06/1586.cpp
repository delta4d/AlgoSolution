#include<stdio.h>
#include<memory.h>

#define MaxN 1000
#define Inf 999999999

long net[MaxN][MaxN];
long visit[MaxN];
long dis[MaxN];
long adp[MaxN];
long res;
long n;

void mst()
{
	long i;
	long j;
	long k;
	long min;
	long index;
	
	memset(visit, 0, sizeof(visit));
	for (i=1; i<n; ++i)
	{
		dis[i] = Inf;
	}
	dis[0] = 0;
	
	for (j=0; j<n; ++j)
	{
		min = Inf;
		
		for (i=0; i<n; ++i)
		{
			if ((visit[i] == 0) && (dis[i] < min))
			{
				min = dis[i];
				index = i;
			}
		}
		
		visit[index] = 1;
		
		for (i=0; i<n; ++i)
		{
			if ((visit[i] == 0) && (dis[i] > net[index][i]))
			{
				dis[i] = net[index][i];
			}
		}
	}
	
	res = 0;
	
	for (i=0; i<n; ++i)
	{
		res += dis[i];
	}
	
	printf("%ld\n", res);
}

int main(void)
{
	long test_case;
	long i;
	long j;
	long k;
	
	scanf("%d", &test_case);
	
	for (k=0; k<test_case; ++k)
	{
		scanf("%ld", &n);
		
		for (i=0; i<n; ++i)
		{
			scanf("%ld", adp + i);
		}
		
		for (i=0; i<n; ++i)
		{
			for (j=0; j<n; ++j)
			{
				scanf("%ld", &net[i][j]);
				
				if (i == j)
				{
					net[i][j] = Inf;
				}
				else
				{
					net[i][j] += (adp[i] + adp[j]);
				}
			}
		}
		
		mst();
	}
	
	return 0;
}
