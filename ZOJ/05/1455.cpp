#include <cstdio>
#include <vector>
#include <queue>
#include <memory>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define debug 1
const int INF = 0x7fffffff;
const int MaxN = 1024;
struct edge
{
	int u;
	int v;
	int w;
	edge(int u=0, int v=0, int w=0) : u(u), v(v), w(w) {}
};
int d[MaxN];
int t[MaxN];
string op;

int main()
{
	int n;
	int i;
	int j;
	int u;
	int v;
	int x;
	int y;
	int w;
	int cno(0);
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	
	while (n != 0)
	{
		vector<edge>e;
		vector<edge>::iterator it;
		for (i=1; i<=n; ++i) scanf("%d", t+i);
		cin >> op;
		while (op != "#")
		{
			scanf("%d %d", &x, &y);
			if (op == "FAS") e.push_back(edge(x, y, -t[x]));
			else if (op == "SAF") e.push_back(edge(x, y, t[y]));
			else if (op == "SAS") e.push_back(edge(x, y, 0));
			else if (op == "FAF")e.push_back(edge(x, y, -t[x]+t[y]));
			cin >> op;
		}
		
		//for (it=e.begin(); it!=e.end(); ++it)
		//printf("%d->%d(%d)\n", (*it).u, (*it).v, (*it).w);
		
		//Bellman-Ford
		memset(d, 0, sizeof(d));
		bool circle;
		for (i=0; i<n; ++i)
		{
			circle = false;
			for (it=e.begin(); it!=e.end(); ++it)
			{
				u = (*it).u;
				v = (*it).v;
				if (d[u] < d[v] + (*it).w)
				{
					d[u] = d[v] + (*it).w;
					circle = true;
				}
			}
		}
		
		printf("Case %d:\n", ++cno);
		if (circle) puts("impossible");
		else
		{
			//int off(INF);
			//for (i=1; i<=n; ++i) off = min(off, d[i]);
			for (i=1; i<=n; ++i) printf("%d %d\n", i, d[i]);
		}
		
		scanf("%d", &n);
		printf("\n");
	}
	
	return 0;
}
