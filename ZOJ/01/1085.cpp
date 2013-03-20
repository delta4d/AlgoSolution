#include <queue>
#include <cstdio>
#include <memory>
#include <cstdlib>
using namespace std;

#define debug 0
const int MaxL = 10;
const int MaxN = 100;
const int INF = 0x7fffffff;
struct D
{
	int dis;
	int index;
	D(int d=INF, int i=-1) : dis(d), index(i){}
};
int cmp(const void *a, const void *b)
{
	D *c = (D *)a;
	D *d = (D *)b;
	return c->dis - d->dis;
}
int n;
int t;
bool find;
bool visit[MaxN];
bool graph[MaxN][MaxN];
D d[MaxN];
char buff[MaxL];

inline void init()
{
	for (int i=0; i<MaxN; ++i) d[i].index = i;
}

void input()
{
	int i;
	int j;
	int k;
	int x;
	int y;
	memset(graph, false, sizeof(graph));
	scanf("%d %d", &n, &t);
	getchar();
	gets(buff);
	while (strcmp(buff, "") != 0)
	{
		x = y = 0;
		for (i=0; buff[i]!=' '; ++i) x = x * 10 + buff[i] - '0';
		while (buff[i] == ' ') ++i;
		for (; buff[i]!=' '&&buff[i]!='\0'; ++i) y = y * 10 + buff[i] - '0';
		graph[x][y] = true;
		if (!gets(buff)) break;
	}
}

void bfs()
{
	int i;
	int j;
	D p;
	queue<D>q;
	d[t].index = t;
	d[t].dis = 0;
	q.push(d[t]);
	memset(visit, false, sizeof(visit));
	visit[d[t].index] = true;
	init();
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		for (i=0; i<n; ++i)
		{
			if (graph[i][p.index] && !visit[i])
			{
				d[i].dis = p.dis + 1;
				visit[i] = true;
				q.push(d[i]);
			}
		}
	}
	qsort(d, n, sizeof(d[0]), cmp);
}

void dfs(int cur, int &na)
{
	int i;
	int j;
	if (cur == t)
	{
		find = true;
		return;
	}
	for (i=0; i<n; ++i)
	{
		if (graph[cur][i] && i != na && !visit[i])
		{
			visit[i] = true;
			dfs(i, na);
			if (find) return;
			visit[i] = false;
		}
	}
}

void gao()
{
	int i;
	int j;
	
	bfs();
	for (i=1; i<n; ++i)
	{
		find = false;
		memset(visit, false, sizeof(visit));
		dfs(0, d[i].index);
		if (!find)
		{
			printf("Put guards in room %d.\n", d[i].index);
			return;
		}
	}
	printf("Put guards in room 0.\n");
}

int main()
{
	int tc;
	int test_case;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	scanf("%d", &test_case);
	for (tc=0; tc<test_case; ++tc)
	{
		input();
		gao();
		if (tc != test_case - 1) printf("\n");
	}
	
	return 0;
}