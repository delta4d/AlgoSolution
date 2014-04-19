#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 101;

int e[N][N];

int main() {
	int tc, cn = 0, n, m, s, t;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) fill(e[i], e[i]+n, INF);
		for (int i=0; i<n; ++i) e[i][i] = 0;
		for (int i=0,u,v; i<m; ++i) scanf("%d%d", &u, &v), e[u][v] = e[v][u] = 1;
		for (int k=0; k<n; ++k) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
			e[i][j] = min(e[i][j], e[i][k]+e[k][j]);
		}
		scanf("%d%d", &s, &t);
		int mx = 0;
		for (int i=0; i<n; ++i) mx = max(mx, e[s][i]+e[i][t]);
		printf("Case %d: %d\n", ++cn, mx);
	}
	return 0;
}

// 287482	2013-11-14 21:01:55	 1174 - Commandos	 C++	 0.012	 1128	Accepted
