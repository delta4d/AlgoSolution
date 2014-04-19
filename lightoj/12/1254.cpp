#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 101;

int d[N][N], c[N];
bool inq[N][N];
queue <pair<int, int> > q;
vector <pair<int, int> > e[N];

int gao(int cc, int s, int t) {
	memset(d, 0x3f, sizeof(d));
	memset(inq, false, sizeof(inq));
	while (!q.empty()) q.pop();
	q.push(make_pair(s, 0));
	d[s][0] = 0, inq[s][0] = true;
	while (!q.empty()) {
		int u = q.front().first, f = q.front().second; q.pop();
		inq[u][f] = false;
		if (d[u][f] + c[u] < d[u][f+1] && f + 1 <= cc) {
			d[u][f+1] = d[u][f] + c[u];
			if (!inq[u][f+1]) {
				inq[u][f+1] = true;
				q.push(make_pair(u, f+1));
			}
		}
		for (int i=0; i<(int)e[u].size(); ++i) {
			int v = e[u][i].first, w = e[u][i].second;
			if (f < w) continue;
			if (d[u][f] < d[v][f-w]) {
				d[v][f-w] = d[u][f];
				if (!inq[v][f-w]) {
					inq[v][f-w] = true;
					q.push(make_pair(v, f-w));
				}
			}
		}
	}
	int mn = INF;
	for (int i=0; i<=cc; ++i) mn = min(mn, d[t][i]);
	return mn;
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		for (int i=0; i<N; ++i) e[i].clear();
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) scanf("%d", c+i);
		for (int i=0,u,v,w; i<m; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			e[u].push_back(make_pair(v, w));
			e[v].push_back(make_pair(u, w));
		}
		printf("Case %d:\n", ++cn);
		int cc, s, t;
		for (scanf("%d", &m); m--; ) {
			scanf("%d%d%d", &cc, &s, &t);
			int r = gao(cc, s, t);
			if (r == INF) puts("impossible");
			else printf("%d\n", r);
		}
	}
	return 0;
}

// 317349	2014-01-26 23:10:38	 1254 - Prison Break	 C++	 1.036	 1304	Accepted
