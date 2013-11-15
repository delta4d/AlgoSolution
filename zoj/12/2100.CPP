#include<stdio.h>

int graph[8][8];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int flag;
int total;

void dfs(int x, int y, int cnt)
{
	int i;
	int newx;
	int newy;
	
	if (flag == 1)
	{
		return;
	}
	
	if (cnt == total)
	{
		flag = 1;
		return;
	}
	
	graph[x][y] = 2;
	
	for (i=0; i<4; ++i)
	{
		newx = x + dx[i];
		newy = y + dy[i];
		
		if (graph[newx][newy] == 1)
		{
			dfs(newx, newy, cnt + 1);
		}
	}
	
	graph[x][y] = 1;
}

int main(void)
{
	int i;
	int j;
	int k;
	int n;
	int m;
	char temp[8];
	
	scanf("%d %d", &n, &m);
	
	while (n != 0 || m != 0)
	{
		total = 0;
		
		for (i=0; i<=n+1; ++i)
		{
			for (j=0; j<=m+1; ++j)
			{
				graph[i][j] = 0;
			}
		}
		
		for (i=1; i<=n; ++i)
		{
			scanf("%s", temp);
			
			for (j=0; j<m; ++j)
			{
				if (temp[j] == '.')
				{
					graph[i][j+1] = 1;
					++total;
				}
			}
		}
		
		flag = 0;
		
		dfs(1, 1, 1);
		
		if (flag == 0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
		
		scanf("%d %d", &n, &m);
	}
	
	return 0;
}
