#include<stdio.h>
#include<memory.h>

#define MaxL 10
#define MaxN 2222
#define Inf 999999999

long n;
long len;
long graph[MaxN][MaxN];
long visit[MaxN];
long d[MaxN];
char name[MaxN][MaxL];
char buff[MaxL];

int find(int k)
{
	int i;
	for (i=0; i<k; ++i)
	{
		if (strcmp(buff, name[i]) == 0)
		{
			return i;
		}
	}
	
	return k;
}

void mst(void)
{
	long i;
	long j;
	long k;
	long min;
	long index;
	
	memset(visit, 0, sizeof(visit));
	for (i=1; i<n; ++i)
	{
		d[i] = Inf;
	}
	d[0] = 0;
	
	for (k=0; k<n; ++k)
	{
		min = Inf;
		
		for (i=0; i<n; ++i)
		{
			if ((visit[i] == 0) && (d[i] < min))
			{
				min = d[i];
				index = i;
			}
		}
		
		visit[index] = 1;
		
		for (i=0; i<n; ++i)
		{
			if ((visit[i] == 0) && (d[i] > graph[index][i]))
			{
				d[i] = graph[index][i];
			}
		}
	}
	
	len = 0;
	for (i=1; i<n; ++i)
	{
		len += d[i];
	}
}

int main(void)
{
	long test_case;
	long k;
	long i;
	long j;
	long r;
	long ss;
	long tt;
	long dis;
	long num;
	
	scanf("%ld", &test_case);
	
	for (k=0; k<test_case; ++k)
	{
		scanf("%ld %ld", &n, &r);
		num = 0;
		for (i=0; i<n; ++i)
		{
			for (j=0; j<n; ++j)
			{
				graph[i][j] = Inf;
			}
		}
		
		for (i=0; i<r; ++i)
		{
			scanf("%s", buff);			
			ss = find(num);			
			if (ss == num)
			{
				strcpy(name[num], buff);
				++num;
			}
			
			scanf("%s", buff);
			tt = find(num);
			if (tt == num)
			{
				strcpy(name[num], buff);
				++num;
			}
			
			scanf("%ld", &dis);
			
			if (dis < graph[ss][tt])
			{
				graph[ss][tt] = dis;
				graph[tt][ss] = dis;
			}
		}
		n = num;
		mst();
		
		printf("%ld\n", len);
	}
	
	return 0;
}
