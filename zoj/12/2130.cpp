#include<stdio.h>

char graph[61][61];
char spot[61][61];

struct Dot
{
	int x;
	int y;
	char color;
}f[3601];

int main(void)
{
	int H;
	int W;
	int h;
	int w;
	int i;
	int j;
	int k;
	int n;
	int flag;
	int res;
	
	while (scanf("%d %d %d %d", &H, &W, &h, &w) != EOF)
	{
		for (i=0; i<H; ++i)
		{
			scanf("%s", graph[i]);
		}
		
		for (i=0; i<h; ++i)
		{
			scanf("%s", spot[i]);
		}
		
		n = 0;
		
		for (i=0; i<h; ++i)
		{
			for (j=0; j<w; ++j)
			{				
				if (spot[i][j] != '.')
				{
					f[n].x = i;
					f[n].y = j;
					f[n].color = spot[i][j];
					++n;
				}
			}
		}
		
		res = 0;
		
		for (i=0; i<=H-h; ++i)
		{
			for (j=0; j<=W-w; ++j)
			{
				flag = 1;
				
				for (k=0; k<n; ++k)
				{
					if (graph[f[k].x + i][f[k].y + j] != f[k].color)
					{
						flag = 0;
						break;
					}
				}
				
				if (flag == 1)
				{
					++res;
				}
			}
		}
		
		printf("%d\n", res);
		
	}
	
	return 0;
}
