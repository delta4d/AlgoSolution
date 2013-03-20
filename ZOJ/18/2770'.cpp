#include <cstdio>
#include <vector>
#include <memory>
#include <queue>
using namespace std;

#define debug 0
const int INF = 0x7fffffff;
const int MaxN = 1111;
struct edge
{
	int index;
	int w;
	edge(int a=0, int b=0) : index(a), w(b) {}
};
bool visit[MaxN];
int in[MaxN];
int d[MaxN];

int main()
{
	int i;
	int j;
	int n;
	int m;
	int u;
	int v;
	int w;
	int s;
	int t;
	edge ss;
	bool circle;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	while (scanf("%d %d", &n, &m) != EOF)
	{
		vector<edge>e[MaxN];
		vector<edge>::iterator it;
		for (i=1; i<=n; ++i)
		{
			scanf("%d", &w);
			e[i-1].push_back(edge(i, w));
			e[i].push_back(edge(i-1, 0));
		}
		for (i=1; i<=m; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			e[v].push_back(edge(u-1, -w));
		}
		//SPFA
		queue<int>q;
		memset(visit, false, sizeof(visit));
		memset(in, 0, sizeof(in));
		fill(d, d+MaxN, INF);
		q.push(n);
		d[n] = 0;
		++in[n];
		visit[n] = true;
		circle = false;
		while (!q.empty())
		{
			s = q.front();
			q.pop();
			visit[s] = false;
			if (in[s] >= n + 2)
			{
				circle = true;
				break;
			}
			for (it=e[s].begin(); it!=e[s].end(); ++it)
			{
				t = (*it).index;
				if (d[t] > d[s] + (*it).w)
				{
					d[t] = d[s] + (*it).w;
					if (!visit[t])
					{
						visit[t] = true;
						++in[t];
						q.push(t);
					}
				}
			}
		}
		
		if (circle) puts("Bad Estimations");
		else printf("%d\n", -d[0]);
	}
	
	return 0;
}
