#include<cstdio>
#include<memory>

const int MaxP = 101;
const int MaxN = 301;

int p;
int n;
int m;
int match[MaxN];
bool visit[MaxN];
bool graph[MaxP][MaxN];

bool dfs(int k)
{
	int i;
	int temp;
	
	for (i=1; i<=n; ++i)
	{
		if (graph[k][i] && !visit[i])
		{
			visit[i] = true;
            temp = match[i];
            
            if (temp == 0 || dfs(temp))
            {
            	match[i] = k;
                return true;
            }
		}
	}
	
	return false;
}

int main(void)
{
	int i;
	int j;
	int k;
	int t;
	int cnt;
	int test_case;
	
	scanf("%d", &test_case);
	
	for (k=0; k<test_case; ++k)
	{
		scanf("%d %d", &p, &n);
		memset(graph, false, sizeof(graph));
		memset(match, 0, sizeof(match));
		
		for (i=1; i<=p; ++i)
		{
			scanf("%d", &cnt);
			
			for (j=0; j<cnt; ++j)
			{
				scanf("%d", &t);
				
				graph[i][t] = true;
			}
		}
				
		for (i=1; i<=p; ++i)
		{
			memset(visit, false, sizeof(visit));
			
			if (!dfs(i))
			{
				break;
			}
		}
		
		if (i <= p)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	
	return 0;
}
