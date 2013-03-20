#include<stdio.h>

int main(void)
{
	char s[12];
	char grid[12][12];
	int visit[12][12];
	int row;
	int col;
	int start;
	int len;
	int px;
	int py;
	int x;
	int y;
	int i;
	int j;
	int res;
	int loop;
	
	scanf("%d %d %d", &row, &col, &start);
	
	while (row !=0 || col != 0 || start != 0)
	{
		for (i=0; i<12; ++i)
		{
			for (j=0; j<12; ++j)
			{
				visit[i][j] = 0;
			}
		}
		
		for (i=1; i<=row; ++i)
		{
			scanf("%s", s);
			len = strlen(s);
			
			for (j=0; j<len; ++j)
			{
				grid[i][j+1] = s[j];
			}
		}
		
		x = 1;
		y = start;
		
		visit[x][y] = 1;
		
		while ((x >= 1) && (x <= row) && (y >= 1) && (y <= col))
		{
			px = x;
			py = y;
			
			if (grid[x][y] == 'N')
			{
				if (visit[x-1][y] == 0)
				{
					visit[x-1][y] = visit[x][y] + 1;
					--x;
				}
				else
				{
					--x;
					break;
				}
			}
			else if (grid[x][y] == 'S')
			{
				if (visit[x+1][y] == 0)
				{
					visit[x+1][y] = visit[x][y] + 1;
					++x;
				}
				else
				{
					++x;
					break;
				}
			}
			else if (grid[x][y] == 'E')
			{
				if (visit[x][y+1] == 0)
				{
					visit[x][y+1] = visit[x][y] + 1;
					++y;
				}
				else
				{
					++y;
					break;
				}
			}
			else
			{
				if (visit[x][y-1] == 0)
				{
					visit[x][y-1] = visit[x][y] + 1;
					--y;
				}
				else
				{
					--y;
					break;
				}
			}
		}
		
		if ((x >= 1) && (x <= row) && (y >= 1) && (y <= col))
		{
			loop = visit[px][py] - visit[x][y] + 1;
			res = visit[x][y] - 1;
			
			printf("%d step(s) before a loop of %d step(s)\n", res, loop);
		}
		else
		{
			res = visit[x][y] - 1;
			
			printf("%d step(s) to exit\n", res);
		}
		
		scanf("%d %d %d", &row, &col, &start);
	}
	
	return 0;
}
