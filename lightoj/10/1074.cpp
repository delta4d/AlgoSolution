#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXD = 20 * 20 * 20 * 200;
const int N = 201;
int e[N][N], w[N], d[N];
bool neg[N];

inline int tri(int x) { return x * x * x; }

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		fill(neg, neg+n, false);
		fill(d, d+n, INF), d[0] = 0;
		for (int i=0; i<n; ++i) fill(e[i], e[i]+n, INF);
		for (int i=0; i<n; ++i) scanf("%d", w+i);
		scanf("%d", &m);
		for (int i=0,u,v; i<m; ++i) scanf("%d%d", &u, &v), --u, --v, e[u][v] = tri(w[v]-w[u]);
		for (int q=n-1; q--; ) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) d[j] = min(d[j], d[i] + e[i][j]);
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (d[j] > d[i] + e[i][j]) neg[j] = true;
		printf("Case %d:\n", ++cn);
		int q, c;
		for (scanf("%d", &q); q--; ) {
			scanf("%d", &c), --c;
			if (neg[c] || d[c] >= MAXD || d[c] < 3) puts("?");
			else printf("%d\n", d[c]);
		}
	}
	return 0;
}

// 307806	2014-01-05 18:59:01	 1074 - Extended Traffic	 C++	 0.240	 1248	Accepted
