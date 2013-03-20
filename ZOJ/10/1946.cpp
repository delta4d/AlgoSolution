#include<stdio.h>
#include<memory.h>

#define MaxN 20
#define MaxL 20

int n;
int m;
int balance[MaxN];
char buff[MaxL];
char name[MaxN][MaxL];

int min(int x, int y)
{
	return x < y ? x : y;
}

int find()
{
	int i;
	for (i=0; i<m; ++i)
	{
		if (strcmp(buff, name[i]) == 0)
		{
			return i;
		}
	}
}

int main(void)
{
	int s;
	int t;
	int k;
	int i;
	int a;
	int src;
	int dst;
	int tran;
	int case_num = 1;

	scanf("%d %d", &m, &n);
	
	while (m != 0 || n != 0)
	{
		memset(balance, 0, sizeof(balance));
		
		for (i=0; i<m; ++i)
		{
			scanf("%s", name[i]);
		}
		
		for (i=0; i<n; ++i)
		{
			scanf("%s", buff);
			s = find();
			scanf("%s", buff);
			t = find();
			scanf("%d", &a);
			
			balance[s] -= a;
			balance[t] += a;
		}
		
		printf("Case #%d\n", case_num);
		++case_num;
		
		while (1)
		{
			for (src=0; src<m; ++src)
			{
				if (balance[src] > 0)
				{
					break;
				}
			}
			
			for (dst=0; dst<m; ++dst)
			{
				if (balance[dst] < 0)
				{
					break;
				}
			}
			
			if (src == m && dst == m)
			{
				break;
			}
			
			tran = min(balance[src], -balance[dst]);
			printf("%s %s %d\n", name[src], name[dst], tran);
			balance[src] -= tran;
			balance[dst] += tran;
		}
		
		printf("\n");
		
		scanf("%d %d", &m, &n);
	}
	
	return 0;
}
