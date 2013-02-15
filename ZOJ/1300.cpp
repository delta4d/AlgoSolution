#include<stdio.h>
#include<memory.h>

char graph[32][32];

int main(void)
{
	int TestCase;
	int k;
	int i;
	int j;
	int len;
	int x;
	int y;
	char order[1000];

	scanf("%d", &TestCase);
	
	for (k=1; k<=TestCase; ++k)
	{
		scanf("%d %d", &x, &y);
		scanf("%s", order);
		
		memset(graph, '.', sizeof(graph));
		len = strlen(order);
		
		for (i=0; i<len-1; ++i)
		{
			if (order[i] == 'E')
			{
				graph[32-y][x] = 'X';
				++x;
			}
			else if (order[i] == 'N')
			{
				graph[31-y][x] = 'X';
				++y;
			}
			else if (order[i] == 'W')
			{
				graph[31-y][x-1] = 'X';
				--x;
			}
			else
			{
				graph[32-y][x-1] = 'X';
				--y;
			}			
		}
		
		printf("Bitmap #%d\n", k);
		
		for (i=0; i<32; ++i)
		{
			for (j=0; j<32; j++)
			{
				printf("%c", graph[i][j]);
			}
			
			printf("\n");
		}
		
		printf("\n");		
	}

	return 0;
}
