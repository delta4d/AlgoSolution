#include<stdio.h>

int main(void)
{
	char nation[30][30];
	char sour[30];
	char dest[30];
	double graph[30][30];
	double rate;
	int i;
	int j;
	int k;
	int n;
	int m;
	int order = 1;
	int flag;
	
	scanf("%d", &n);
	
	while (n != 0)
	{
		for (i=0; i<n; ++i)
		{
			scanf("%s", nation[i]);
		}
		
		for (i=0; i<n; ++i)
		{
			for (j=0; j<n; ++j)
			{
				graph[i][j] = 0;
			}
		}
		
		scanf("%d", &m);
		
		for (i=0; i<m; ++i)
		{
			scanf("%s %lf %s", sour, &rate, dest);
			
			for (j=0; j<n; ++j)
			{
				if (strcmp(sour, nation[j]) == 0)
				{
					break;
				}
			}
			
			for (k=0; k<n; ++k)
			{
				if (strcmp(dest, nation[k]) == 0)
				{
					break;
				}
			}
			
			graph[j][k] = rate;
		}
		
		for (k=0; k<n; ++k)
		{
			for (i=0; i<n; ++i)
			{
				for (j=0; j<n; ++j)
				{
					if (graph[i][k] * graph[k][j] > graph[i][j])
					{
						graph[i][j] = graph[i][k] * graph[k][j];
					}
				}
			}
		}
		
		flag = 0;
		
		for (i=0; i<n; ++i)
		{
			if (graph[i][i] > 1)
			{
				flag = 1;
				break;
			}
		}
		
		if (flag == 1)
		{
			printf("Case %d: Yes\n", order);
		}
		else
		{
			printf("Case %d: No\n", order);
		}
		
		++order;
		
		scanf("%d", &n);
	}
	
	return 0;
}
