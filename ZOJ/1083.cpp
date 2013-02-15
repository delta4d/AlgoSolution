#include <cstdio>
#include <memory>
using namespace std;

#define debug 0
const int INF = 10086;
const int MaxN = 32;
struct frame
{
	int l;
	int r;
	int u;
	int d;
}f[MaxN];
bool find[MaxN];
bool visit[MaxN];
char outs[MaxN];
char graph[MaxN][MaxN];
char tmap[MaxN][MaxN];
char tt[MaxN][MaxN];
int tot;
int m;
int n;

void init()
{
	int i;
	for (i=0; i<MaxN; ++i)
	{
		f[i].l = f[i].u = INF;
		f[i].r = f[i].d = -INF;
	}
	memset(find, false, sizeof(find));
	tot = 0;
}

bool same()
{
	int i;
	int j;
	for (i=0; i<m; ++i)
	{
		for (j=0; j<n; ++j)
		{
			if (graph[i][j] != tmap[i][j]) return false;
		}
	}
	return true;
}

void gao(int step)
{
	int i;
	int j;
	int k;
	if (step == tot && same())
	{
		for (i=0; i<tot; ++i) printf("%c", outs[i]);
		printf("\n");
		return;
	}
	for (i=0; i<26; ++i)
	{
		if (find[i] && !visit[i])
		{
			visit[i] = true;
			outs[step] = i + 'A';
			memcpy(tt, tmap, sizeof(tmap));
			for (k=f[i].l; k<=f[i].r; ++k) 
			{
				tmap[f[i].u][k] = tmap[f[i].d][k] = i + 'A';
				if (graph[f[i].u][k] - 'A' != i && visit[graph[f[i].u][k]-'A'])
				{
					memcpy(tmap, tt, sizeof(tt));
					visit[i] = false;
					return;
				}
				if (graph[f[i].d][k] - 'A' != i && visit[graph[f[i].d][k]-'A'])
				{
					memcpy(tmap, tt, sizeof(tt));
					visit[i] = false;
					return;
				}
			}
			for (k=f[i].u; k<=f[i].d; ++k)
			{
				tmap[k][f[i].l] = tmap[k][f[i].r] = i + 'A';
				if (graph[k][f[i].l] - 'A' != i && visit[graph[k][f[i].l]-'A'])
				{
					memcpy(tmap, tt, sizeof(tt));
					visit[i] = false;
					return;
				}
				if (graph[k][f[i].r] - 'A' != i && visit[graph[k][f[i].r]-'A'])
				{
					memcpy(tmap, tt, sizeof(tt));
					visit[i] = false;
					return;
				}
			}
			gao(step + 1);
			visit[i] = false;
			memcpy(tmap, tt, sizeof(tt));
		}
	}
}

int main()
{
	int i;
	int j;
	int k;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	while (scanf("%d %d", &m, &n) != EOF)
	{
		for (i=0; i<m; ++i) scanf("%s", graph[i]);		
		init();
		for (i=0; i<m; ++i)
		{
			for (j=0; j<n; ++j)
			{
				if (graph[i][j] != '.')
				{
					k = graph[i][j] - 'A';
					if (!find[k])
					{
						++tot;
						find[k] = true;
					}
					f[k].l = f[k].l < j ? f[k].l : j;
					f[k].r = f[k].r > j ? f[k].r : j;
					f[k].u = f[k].u < i ? f[k].u : i;
					f[k].d = f[k].d > i ? f[k].d : i;
				}
			}
		}
		memset(visit, false, sizeof(visit));
		memset(tmap, '.', sizeof(tmap));
		gao(0);
	}
	
	return 0;
}