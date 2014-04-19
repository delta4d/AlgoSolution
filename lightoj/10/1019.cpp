#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 101;
const int INF = 0x3f3f3f3f;

int d[N], e[N][N];
priority_queue<pair<int,int> > q;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int gao(int n) {
	fill(d, d+n, INF);
	d[0] = 0;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int c = -q.top().first, x = q.top().second;
		q.pop();
		if (c != d[x]) continue;
		for (int i=0; i<n; ++i) if (c + e[x][i] < d[i]) {
			d[i] = c + e[x][i];
			q.push(make_pair(-d[i], i));
		}
	}
	return d[n-1];
}

int main() {
	int tc, cn = 0, n, m;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), m = fastin<int>();
		for (int i=0; i<n; ++i) fill(e[i], e[i]+n, INF);
		for (int i=0,u,v,w; i<m; ++i) {
			u = fastin<int>() - 1, v = fastin<int>() - 1, w = fastin<int>();
			e[u][v] = e[v][u] = min(e[u][v], w);
		}
		int d = gao(n);
		printf("Case %d: ", ++cn);
		if (d == INF) puts("Impossible");
		else printf("%d\n", d);
	}
	return 0;
}

// 287472	2013-11-14 20:40:40	 1019 - Brush (V)	 C++	 0.008	 1260	Accepted
