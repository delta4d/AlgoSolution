#include<stdio.h>
#include<memory.h>

#define MaxN 101
#define MaxL 11
#define Inf 33333

int n;
int graph[MaxN][MaxN];
int dis[MaxN];
int visit[MaxN];
int power[MaxN];
char city[MaxN][MaxL];
char src[MaxL];
char dst[MaxL];

int find(int n, char *s)
{
	int i;
	
	for (i=0; i<n; ++i)
	{
		if (strcmp(s, city[i]) == 0)
		{
			return i;
		}
	}
	
	return -1;
}

void dijkstra()
{
	int s = find(n, src);
	int t = find(n, dst);
	int i;
	int j;
	int k;
	int temp;
	int min;
	int index;
	
	memset(visit, 0, sizeof(visit));
	memset(power, 0, sizeof(power));
	for (i=0; i<n; ++i)
	{
		dis[i] = Inf;
	}
	dis[s] = 0;
	
	for (j=0; j<n; ++j)
	{
		min = Inf;
		
		for (i=0; i<n; ++i)
		{
			if ((visit[i] == 0) && (min > dis[i] - power[i]))
			{
				min = dis[i] - power[i];
				index = i;
			}
		}
		
		visit[index] = 1;
		
		for (i=0; i<n; ++i)
		{
			if ((graph[index][i] != Inf) && (visit[i] == 0))
			{
				temp = power[index] > graph[index][i] ? power[index] : graph[index][i];
				
				if (dis[i] - power[i] > dis[index] +graph[index][i] - temp)
				{
					dis[i] = dis[index] +graph[index][i];
					power[i] = temp;
				}
			}
		}
	}
	
	printf("%d\n", dis[t] - power[t]);
}

int main(void)
{
	int i;
	int j;
	int k;
	int x;
	int y;
	int m;
	int cost;
	char st[MaxL];
	char tt[MaxL];
	
	while (scanf("%s %s", src, dst) != EOF)
	{
		for (i=0; i<MaxN; ++i)
		{
			for (j=0; j<MaxN; ++j)
			{
				graph[i][j] = Inf;
			}
		}
		
		k = 0;
		scanf("%d", &m);
		
		for (i=0; i<m; ++i)
		{
			scanf("%s %s %d", st, tt, &cost);
			
			x = find(k, st);
			if (x == -1)
			{
				strcpy(city[k], st);
				x = k;
				++k;
			}
			
			y = find(k, tt);
			if (y == -1)
			{
				strcpy(city[k], tt);
				y = k;
				++k;
			}
			
			graph[x][y] = cost;
		}
		
		n = k;
		
		dijkstra();
	}
	
	return 0;
}
