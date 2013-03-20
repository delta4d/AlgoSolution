#include <cstdio>
#include <memory>
#include <vector>
using namespace std;

#define debug 0
const int INF = 0x7ffffff;
const int MaxN = 1111;
struct edge
{
	int u;
	int v;
	int w;
	edge(int u=0, int v=0, int w=0) : u(u), v(v), w(w) {}
};
int d[MaxN];
int c[MaxN];

int main()
{
	int n;
	int m;
	int i;
	int u;
	int v;
	int w;
#if	debug
	freopen("f:\\in.txt", "r", stdin);
#endif	
	while (scanf("%d %d", &n, &m) != EOF)
	{
		vector<edge>e;
		vector<edge>::iterator it;
		for (i=1; i<=n; ++i)
		{
			scanf("%d", &w);
			e.push_back(edge(i-1, i, w));
			e.push_back(edge(i, i-1, 0));
		}
		for (i=0; i<m; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			e.push_back(edge(v, u-1, -w));
		}
		//Bellman-Ford
		bool ss;
		fill(d, d+MaxN, INF);
		d[n] = 0;
		for (i=0; i<=n; ++i)
		{
			ss = false;
			for (it=e.begin(); it!=e.end(); ++it)
			{
				if (d[(*it).v] > d[(*it).u] + (*it).w)
				{
					d[(*it).v] = d[(*it).u] + (*it).w;
					ss = true;
				}
			}
		}
		if (ss) printf("Bad Estimations\n");
		else printf("%d\n", -d[0]);
	}
	return 0;
}
