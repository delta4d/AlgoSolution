#include<cstdio>
#include<memory>

using namespace std;

const int MaxN = 21;

bool state[MaxN];
int cpy[MaxN];

int main(void)
{
	int i;
	int j;
	int n;
	int m;
	int c;
	int op;
	int cur;
	int max;
	int case_num = 1;
	bool blown;
	
	scanf("%d %d %d", &n, &m, &c);
	
	while (n != 0 || m != 0 || c != 0)
	{
		cur = 0;
		max = -1;
		blown = false;
		memset(state, false, sizeof(state));
		
		for (i=1; i<=n; ++i)
		{
			scanf ("%d", cpy + i);
		}
		
		for (i=0; i<m; ++i)
		{
			scanf ("%d", &op);
			
			if (!blown)
			{
				if (!state[op])
				{
					cur += cpy[op];
					if (cur > max)
					{
						max = cur;
					}
					if (cur > c)
					{
						blown = true;
					}
					
					state[op] = true;
				}
				else
				{
					cur -= cpy[op];
					state[op] = false;
				}
			}
		}
		
		printf("Sequence %d\n", case_num);
		
		if (blown)
		{
			printf("Fuse was blown.\n");
		}
		else
		{
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n", max);
		}
		
		++case_num;
		printf("\n");
		scanf("%d %d %d", &n, &m, &c);
	}
	
	return 0;
}
