#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

const int N = 500;
const int INF = 0x3f3f3f3f;
typedef pair <int, int> pii;
priority_queue <pii> q;
int e[N][N];
int d[N];

void dijkstra(int t, const int n) {
	fill(d, d+n, INF); d[t] = 0;
	while (!q.empty()) q.pop();
	q.push(make_pair(0, t));
	while (!q.empty()) {
		int w = -q.top().first, x = q.top().second;
		q.pop();
		if (d[x] != w) continue;
		for (int i=0; i<n; ++i) if (max(w, e[x][i]) < d[i]) {
			d[i] = max(w, e[x][i]);
			q.push(make_pair(-d[i], i));
		}
	}
}

int main() {
	int tc, cn = 0, n, m;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), m = fastin<int>();
		for (int i=0; i<n; ++i) fill(e[i], e[i]+n, INF);
		for (int i=0,u,v,w; i<m; ++i) {
			u = fastin<int>(), v = fastin<int>(), w = fastin<int>();
			e[u][v] = e[v][u] = min(e[u][v], w);
		}
		dijkstra(fastin<int>(), n);
		printf("Case %d:\n", ++cn);
		for (int i=0; i<n; ++i) {
			if (d[i] == INF) puts("Impossible");
			else printf("%d\n", d[i]);
		}
	}
	return 0;
}

// 286763	2013-11-12 23:06:06	 1002 - Country Roads	 C++	 0.128	 2196	Accepted
