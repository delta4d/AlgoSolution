#include<cstdio>
#include<memory>
#include<queue>

using namespace std;

struct Cor
{
	int x;
	int step;	
};

const int MaxN = 21;
const int Inf = 30000;

bool graph[MaxN][MaxN];
bool cmap[MaxN][MaxN];

int bfs(int s, int t)
{
	queue<Cor>f;
	Cor temp;
	Cor cur;
	int i;
	int j;
	
	memcpy(cmap, graph, sizeof(graph));
	temp.x = s;
	temp.step = 0;
	f.push(temp);
	
	while (!f.empty())
	{
		temp = f.front();
		f.pop();
		
		if (temp.x == t)
		{
			return temp.step;
		}
		
		for (i=1; i<=20; ++i)
		{
			if (cmap[temp.x][i])
			{
				cur.x = i;
				cur.step = temp.step + 1;
				cmap[temp.x][i] = cmap[i][temp.x] = false;
				f.push(cur);
			}
		}
	}
}

int main(void)
{
	int i;
	int j;
	int t;
	int n;
	int S;
	int T;
	int len;
	int order = 1;
	
	while (scanf("%d", &n) != EOF)
	{
		memset(graph, false, sizeof(graph));
		
		for (i=0; i<n; ++i)
		{
			scanf("%d", &t);
			graph[1][t] = graph[t][1] = true;
		}
		
		for (j=2; j<20; ++j)
		{
			scanf("%d", &n);
			
			for (i=0; i<n; ++i)
			{
				scanf("%d", &t);
				graph[j][t] = graph[t][j] = true;
			}
		}
		
		scanf("%d", &n);
		printf("Test Set #%d\n", order);
		++order;
		
		for (i=0; i<n; ++i)
		{
			scanf("%d %d", &S, &T);
			len = bfs(S, T);
			
			printf("%d to %d: %d\n", S, T, len);
		}
		
		printf("\n");
	}
	
	return 0;
}
