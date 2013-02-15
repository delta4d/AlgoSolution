#include<stdio.h>

#define MaxN 33
#define Inf 30000

int path[MaxN][MaxN];
int dis[MaxN][MaxN];
int tax[MaxN];
int n;

void floyd()
{
	int i;
	int j;
	int k;
	int t;	
	
	for (k=1; k<=n; ++k)
	{
		for (i=1; i<=n; ++i)
		{
			for (j=1; j<=n; ++j)
			{
				t = dis[i][k] + dis[k][j] + tax[k];
				
				if (dis[i][j] > t)
				{
					dis[i][j] = t;
					path[i][j] = path[i][k];
				}
				else if (dis[i][j] == t)
				{
					if (path[i][j] > path[i][k])
					{
						path[i][j] = path[i][k];
					}
				}
			}
		}
	}
	
	return;
}

void print_path(int src, int dst)
{
	int i = src;
	int j = dst;
	int k = 1;
	
	printf("From %d to %d :\nPath: ", src, dst);
	
	printf("%d", i);
	
	while (j != i)
	{
		printf("-->%d", path[i][j]);
		i = path[i][j];
	}
	
	printf("\n");
	printf("Total cost : %d\n\n", dis[src][dst]);
	
	return;
}

int main(void)
{
	int i;
	int j;
	int k;
	int src;
	int dst;
	
	scanf("%d", &n);
	
	while (n != 0)
	{
		for (i=1; i<=n; ++i)
		{
			for (j=1; j<=n; ++j)
			{
				scanf("%d", &dis[i][j]);
				
				if (dis[i][j] == -1)
				{
					dis[i][j] = Inf;
				}
				
				path[i][j] = j;
			}
		}
		
		for (i=1; i<=n; ++i)
		{
			scanf("%d", tax + i);
		}
		
		floyd();
		
		scanf("%d %d", &src, &dst);
		
		while (src != -1 || dst != -1)
		{
			print_path(src, dst);
			
			scanf("%d %d", &src, &dst);
		}
		
		scanf("%d", &n);
	}
	
	return 0;
}
