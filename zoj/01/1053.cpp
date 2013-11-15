#include <cstdio>
#include <memory>
#include <cstring>
#include <cstdlib>
using namespace std;

#define debug 0
const int INF = 0x3f3f3f3f;
const int MaxN = 21;
const int MaxL = 80;
struct node
{
	int ss;
	int tt;
	int dis;
	int pn;
	int path[MaxN];
}res[MaxN];
int n;
int fsn;
int fire_add;
int fire_station[MaxN];
int pre[MaxN];
int d[MaxN];
int graph[MaxN][MaxN];
bool visit[MaxN];
char buff[MaxL];
char temp[MaxL];

int cmp(const void *a, const void *b)
{
	node *c = (node *)a;
	node *d = (node *)b;
	return c->dis - d->dis;
}

inline int to_int(int n)
{
	int res(0);
	for (int i=0; i<n; ++i) res = res * 10 + temp[i] - '0';
	return res;
}

inline bool is_integer(char c)
{
	return c <= '9' && c >= '0';
}

void input()
{
	int i;
	int j;
	int k;
	int len;
	scanf("%d", &n);
	for (i=1; i<=n; ++i)
	{
		for (j=1; j<=n; ++j)
		{
			scanf("%d", graph[j]+i);
			if (graph[j][i] == -1) graph[j][i] = INF;
		}
	}
	scanf("%d", &fire_add);
	gets(buff);
	len = strlen(buff);
	k = 0;
	i = 0;
	fsn = 0;
	while (!is_integer(buff[i])) ++i;
	for (; i<=len; ++i)
	{
		if (!is_integer(buff[i]))
		{
			if (k > 0)
			{
				fire_station[fsn] = to_int(k);
				++fsn;
				k = 0;
			}
		}
		else
		{
			temp[k] = buff[i];
			++k;
		}
	}
}

void solve()
{
	int i;
	int k;
	int index;
	int min;
	//dijkstra
	for (i=1; i<=n; ++i) if (graph[fire_add][i] == INF) d[i] = INF; else d[i] = fire_add;
	memset(visit, false, sizeof(visit));
	fill(d, d+MaxN, INF);
	d[fire_add] = 0;
	for (k=0; k<n; ++k)
	{
		min = INF;
		for (i=1; i<=n; ++i)
		{
			if (!visit[i] && d[i] < min)
			{
				min = d[i];
				index = i;
			}
		}
		visit[index] = true;
		for (i=1; i<=n; ++i)
		{
			if (!visit[i] && d[i] > d[index] + graph[index][i])
			{
				d[i] = d[index] + graph[index][i];
				pre[i] = index;
			}
		}
	}
	//???????
	for (i=0; i<fsn; ++i)
	{
		res[i].ss = fire_station[i];
		res[i].tt = fire_add;
		res[i].dis = d[res[i].ss];
		//construct path
		res[i].pn = 1;
		res[i].path[0] = res[i].ss;
		index = fire_station[i];
		while (index != fire_add)
		{
			res[i].path[res[i].pn] = pre[index];
			++res[i].pn;
			index = pre[index];
		}
	}
	qsort(res, fsn, sizeof(res[0]), cmp);
}

void output()
{
	int i;
	int j;
	printf("Org\tDest\tTime\tPath\n");
	for (i=0; i<fsn; ++i)
	{
		printf("%d\t%d\t%d", res[i].ss, res[i].tt, res[i].dis);
		for (j=0; j<res[i].pn; ++j) printf("\t%d", res[i].path[j]);
		printf("\n");
	}
}

int main()
{
	int i;
	int tc;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	scanf("%d", &tc);
	for (i=0; i<tc; ++i)
	{
		input();
		solve();
		output();
		if (i != tc - 1) printf("\n");
	}
	
	return 0;
}
