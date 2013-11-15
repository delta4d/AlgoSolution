#include<stdio.h>
#include<memory.h>

int main(void)
{
	int graph[251][251];
	int fuwa[5];
	int m;
	int n;
	int i;
	int j;
	int k;
	int TestCase;
	int t;
	int res;
	char temp[255];
	
	scanf("%d", &TestCase);

	for (t=0; t<TestCase; ++t)
	{		
		scanf("%d %d", &m, &n);
		
		for (i=0; i<m; ++i)
		{
			scanf("%s", temp);
			
			for (j=0; j<n; ++j)
			{
				if (temp[j] == 'B')
				{
					graph[i][j] = 0;
				}
				else if (temp[j] == 'J')
				{
					graph[i][j] = 1;
				}
				else if (temp[j] == 'H')
				{
					graph[i][j] = 2;
				}
				else if (temp[j] == 'Y')
				{
					graph[i][j] = 3;
				}
				else
				{
					graph[i][j] = 4;
				}
			}
		}
		
		res = 0;
		
		for (i=0; i<m; ++i)
		{
			for (j=i+1; j<m; ++j)
			{
				memset(fuwa, 0, sizeof(fuwa));
				
				for (k=0; k<n; ++k)
				{
					if (graph[i][k] == graph[j][k])
					{
						++fuwa[graph[i][k]];
					}
				}
				
				for (k=0; k<5; ++k)
				{
					res += fuwa[k] * (fuwa[k] - 1) / 2;
				}
			}
		}		
		
		printf("%d\n", res);
	}	

	return 0;
}
