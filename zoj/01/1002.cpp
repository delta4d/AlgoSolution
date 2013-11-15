#include<stdio.h>

#define MaxN 5 

char graph[MaxN][MaxN];
int n;
int max;

int CouldPut(int x, int y)
{
	int i;
	
	if (graph[x][y] != '.')
	{
		return 0;
	}
	
	for (i=y-1; i>=0; --i)
	{
		if (graph[x][i] == 'X')
		{
			break;
		}
		
		if (graph[x][i] == 'A')
		{
			return 0;
		}
	}
	
	for (i=y+1; i<n; ++i)
	{
		if (graph[x][i] == 'X')
		{
			break;
		}
		
		if (graph[x][i] == 'A')
		{
			return 0;
		}
	}
	
	for (i=x-1; i>=0; --i)
	{
		if (graph[i][y] == 'X')
		{
			break;
		}
		
		if (graph[i][y] == 'A')
		{
			return 0;
		}
	}
	
	for (i=x+1; i<n; ++i)
	{
		if (graph[i][y] == 'X')
		{
			break;
		}
		
		if (graph[i][y] == 'A')
		{
			return 0;
		}
	}
	
	return 1;
}

void dfs(int pos, int cnt)
{
	int x;
	int y;
	
	if (pos == n * n)
	{
		if (cnt > max)
		{
			max = cnt;
		}
		
		return;
	}
	
	x = pos / n;
	y = pos % n;
	
	if (CouldPut(x, y))
	{
		graph[x][y] = 'A';
		
		dfs(pos + 1, cnt + 1);
		
		graph[x][y] = '.';
	}
	
	dfs(pos + 1, cnt);
}

int main(void)
{
	int i;
	
	scanf("%d", &n);
	
	while (n != 0)
	{
		for (i=0; i<n; ++i)
		{
			scanf("%s", graph[i]);
		}
		
		max = 0;
		
		dfs(0, 0);
		
		printf("%d\n", max);
		
		scanf("%d", &n);
	}
	
	return 0;
}
