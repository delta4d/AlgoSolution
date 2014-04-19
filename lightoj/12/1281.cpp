#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 10000 + 86;

struct node {
	int v, w;
	bool r;
	node(int _v=0, int _w=0, bool _r=false):v(_v), w(_w), r(_r) {}
};

vector <node> e[N];
int d[N][11];
bool inq[N][11];
queue <pair<int, int> > q;

int gao(const int n, const int m) {
	memset(d, 0x3f, sizeof(d));
	memset(inq, false, sizeof(inq));
	while (!q.empty()) q.pop();
	d[0][0] = 0, inq[0][0] = true;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int u = q.front().first, c = q.front().second; q.pop();
		inq[u][c] = false;
		for (int i=0; i<(int)e[u].size(); ++i) {
			int v = e[u][i].v, w = e[u][i].w;
			int r = e[u][i].r ? 0 : 1;
			if (d[u][c] + w < d[v][c+r] && c + r <= m) {
				d[v][c+r] = d[u][c] + w;
				if (!inq[v][c+r]) {
					inq[v][c+r] = true;
					q.push(make_pair(v, c+r));
				}
			}
		}
	}
	int mn = INF;
	for (int i=0; i<=m; ++i) mn = min(mn, d[n-1][i]);
	return mn;
}

int main() {
	int tc, cn = 0, n, m, k, d;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d%d", &n, &m, &k, &d);
		for (int i=0; i<N; ++i) e[i].clear();
		for (int i=0,u,v,w; i<m+k; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			bool r = i < m;
			e[u].push_back(node(v, w, r));
//			e[v].push_back(node(u, w, r));
		}
		int c = gao(n, d);
		printf("Case %d: ", ++cn);
		if (c == INF) puts("Impossible");
		else printf("%d\n", c);
	}
	return 0;
}

// 317235	2014-01-26 20:31:08	 1281 - New Traffic System	 C++	 0.424	 3844	Accepted
