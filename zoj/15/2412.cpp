#include<stdio.h>

int graph[200][200];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int res;

void floodfill(int x, int y)
{
	int i;
	int tx;
	int ty;
	
	for (i=0; i<4; ++i)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		
		if (graph[tx][ty] == 1)
		{
			graph[tx][ty] = 2;
			
			floodfill(tx, ty);
		}
	}
}

int main(void)
{
	char temp[100];
	int i;
	int j;
	int k;
	int m;
	int n;
	int x;
	int y;
	int len;
	
	scanf("%d %d", &m, &n);
	
	while (m != -1 || n != -1)
	{
		for (i=0; i<=3*m+1; ++i)
		{
			for (j=0; j<=3*n+1; ++j)
			{
				graph[i][j] = 0;
			}
		}
		
		for (i=0; i<m; ++i)
		{
			scanf("%s", temp);
			
			for (j=0; j<n; ++j)
			{
				x = 3 * i + 1;
				y = 3 * j + 1;
				
				if (temp[j] == 'A')
				{					
					graph[x][y+1] = 1;
					graph[x+1][y] = 1;
					graph[x+1][y+1] = 1;					
				}
				else if (temp[j] == 'B')
				{
					graph[x][y+1] = 1;
					graph[x+1][y+1] = 1;
					graph[x+1][y+2] = 1;
				}
				else if (temp[j] == 'C')
				{
					graph[x+1][y] = 1;
					graph[x+1][y+1] = 1;
					graph[x+2][y+1] = 1;
				}
				else if (temp[j] == 'D')
				{
					graph[x+1][y+1] = 1;
					graph[x+1][y+2] = 1;
					graph[x+2][y+1] = 1;
				}
				else if (temp[j] == 'E')
				{
					graph[x][y+1] = 1;
					graph[x+1][y+1] = 1;
					graph[x+2][y+1] = 1;
				}
				else if (temp[j] == 'F')
				{
					graph[x+1][y] = 1;
					graph[x+1][y+1] = 1;
					graph[x+1][y+2] = 1;
				}
				else if (temp[j] == 'G')
				{
					graph[x][y+1] = 1;
					graph[x+1][y] = 1;
					graph[x+1][y+1] = 1;
					graph[x+1][y+2] = 1;
				}
				else if (temp[j] == 'H')
				{
					graph[x][y+1] = 1;
					graph[x+1][y] = 1;
					graph[x+1][y+1] = 1;
					graph[x+2][y+1] = 1;
				}
				else if (temp[j] == 'I')
				{
					graph[x+1][y] = 1;
					graph[x+1][y+1] = 1;
					graph[x+1][y+2] = 1;
					graph[x+2][y+1] = 1;
				}
				else if (temp[j] == 'J')
				{
					graph[x][y+1] = 1;
					graph[x+1][y+1] = 1;
					graph[x+1][y+2] = 1;
					graph[x+2][y+1] = 1;
				}
				else
				{
					graph[x][y+1] = 1;
					graph[x+1][y] = 1;
					graph[x+1][y+1] = 1;
					graph[x+1][y+2] = 1;
					graph[x+2][y+1] = 1;
				}
			}
		}
		
		res = 0;
		
		for (i=1; i<=3*m; ++i)
		{
			for (j=1; j<=3*n; ++j)
			{
				if (graph[i][j] == 1)
				{
					++res;
					graph[i][j] = 2;
					floodfill(i, j);
				}
			}
		}
		
		printf("%d\n", res);
		
		scanf("%d %d", &m, &n);
	}
	
	return 0;
}
