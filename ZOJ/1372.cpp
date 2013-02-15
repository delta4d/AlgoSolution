#include<stdio.h>

#define Inf 30000

int dis[51];
int visit[51];
int graph[51][51];

int mst(int n)
{
	int i;
	int k;
	int min;
	int len;
	int index;
	
	for (i=1; i<=n; ++i)
	{
		dis[i] = Inf;
		visit[i] = 0;
	}
	
	dis[1] = 0;
	
	for (k=0; k<n; ++k)
	{
		min = Inf;
		
		for (i=1; i<=n; ++i)
		{
			if ((visit[i] == 0) && (dis[i] < min))
			{
				min = dis[i];
				index = i;
			}
		}
		
		visit[index] = 1;
		
		for (i=1; i<=n; ++i)
		{
			if ((visit[i] == 0) && (graph[index][i] < dis[i]))
			{
				dis[i] = graph[index][i];
			}
		}
	}
	
	len = 0;
	
	for (i=1; i<=n; ++i)
	{
		len += dis[i];
	}
	
	return len;
}

int main(void)
{
	int p;
	int r;
	int i;
	int j;
	int x;
	int y;
	int d;
	int len;
	
	scanf("%d", &p);
	
	while (p != 0)
	{
		for (i=1; i<=p; ++i)
		{
			for (j=1; j<=p; ++j)
			{
				graph[i][j] = Inf;
			}
		}
		
		scanf("%d", &r);
		
		for (i=0; i<r; ++i)
		{
			scanf("%d %d %d", &x, &y, &d);
			
			if (graph[x][y] > d)
			{
				graph[x][y] = graph[y][x] = d;
			}
		}
		
		len = mst(p);
		
		printf("%d\n", len);
		
		scanf("%d", &p);
	}

	return 0;
}
