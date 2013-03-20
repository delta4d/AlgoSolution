#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

#define MaxL 6
#define MaxN 10001

char price[MaxN][MaxL];
int visit[MaxN];

int main(void)
{
	int i;
	int k;
	int test_case;
	int cur;
	int u;
	int m;
	int min;
	int index;
	int unique;
	char buff[MaxL];
	
	scanf("%d", &test_case);
	
	for (k=1; k<=test_case; ++k)
	{
		memset(visit, 0, sizeof(visit));
		scanf("%d %d", &u, &m);
		
		for (i=0; i<m; ++i)
		{
			scanf("%s %d", buff, &cur);
			
			if (cur <= u)
			{				
				if (visit[cur] == 0)
				{
					strcpy(price[cur], buff);
				}
				
				++visit[cur];
			}
		}
		
		unique = 0;
		for (i=1; i<=u; ++i)
		{
			if (visit[i] == 1)
			{
				unique = 1;
				index = i;
				break;
			}
		}
		
		if (unique == 0)
		{
			min = m + 1;
			for (i=1; i<=u; ++i)
			{
				if ((min > visit[i]) && (visit[i] != 0))
				{
					min = visit[i];
					index = i;
				}
			}
		}
		
		printf("Case %d:\n", k);
	 	printf("The winner is %s.\n", price[index]);
		printf("The price is %d.\n", index);
		
		if (k < test_case)
		{
			printf("\n");
		}
	}
	
	return 0;
}
