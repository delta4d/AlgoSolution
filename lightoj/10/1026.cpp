#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10000 + 86;
const int INF = 0x3f3f3f3f;

vector <int> e[N];
vector <pair<int,int> > cl;
int dfn[N], low[N], color[N];
int tot;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

void dfs(int root, int parent) {
	color[root] = 1;
	dfn[root] = low[root] = tot++;
	for (int i=0; i<(int)e[root].size(); ++i) {
		int child = e[root][i];
		if (child != parent && color[child] == 1) low[root] = min(low[root], dfn[child]);
		if (color[child] == 0) {
			dfs(child, root);
			low[root] = min(low[root], low[child]);
			if (low[child] > dfn[root]) {
				int u = min(child, root), v = child + root - u;
				cl.push_back(make_pair(u, v));
			}
		}
	}
	color[root] = 2;
}

int main() {
	int tc, cn = 0, n, m;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0,u,v; i<n; ++i) {
			scanf("%d (%d)", &u, &m);
			for (int j=0; j<m; ++j) {
				v = fastin<int>();
				e[u].push_back(v);
				e[v].push_back(u);
			}
		}
		cl.clear();
		fill(color, color+n, 0);
		fill(low, low+n, INF);
		fill(dfn, dfn+n, -1);
		tot = 0;
		for (int i=0; i<n; ++i) if (!color[i]) dfs(i, -1);
		printf("Case %d:\n", ++cn);
		printf("%d critical links\n", (int)cl.size());
		sort(cl.begin(), cl.end());
		for (int i=0; i<(int)cl.size(); ++i) printf("%d - %d\n", cl[i].first, cl[i].second);
	}
	return 0;
}

// 294684	2013-12-02 22:28:19	 1026 - Critical Links	 C++	 0.248	 5476	Accepted
