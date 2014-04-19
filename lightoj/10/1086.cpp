#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int d[15], odd[15], p;
int f[1<<15], e[15][15], dis[15][15];

int gao(int mask) {
	if (f[mask] != -1) return f[mask];
	int mn = INF;
	for (int i=0; i<p; ++i) if (mask & 1 << i) {
		for (int j=i+1; j<p; ++j) if (mask & 1 << j) {
			int next_mask = mask ^ (1 << i) ^ (1 << j);
			mn = min(mn, gao(next_mask) + dis[i][j]);
		}
		return f[mask] = mn;
	}
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		int tot = 0;
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) fill(e[i], e[i]+n, INF);
		memset(d, 0, sizeof(d));
		for (int i=0,u,v,w; i<m; ++i) {
			scanf("%d%d%d", &u, &v, &w), --u, --v;
			e[u][v] = e[v][u] = min(e[u][v], w);
			tot += w;
			++d[u], ++d[v];
		}
		for (int k=0; k<n; ++k) {
			for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
				e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
			}
		}
		p = 0;
		for (int i=0; i<n; ++i) if (d[i] & 1) odd[p++] = i;
		for (int i=0; i<p; ++i) for (int j=0; j<p; ++j) {
			dis[i][j] = e[odd[i]][odd[j]];
		}
		memset(f, -1, sizeof(f));
		f[0] = 0;
		printf("Case %d: %d\n", ++cn, tot+gao((1<<p)-1));
	}
	return 0;
}

// 304942	2013-12-27 17:27:04	 1086 - Jogging Trails	 C++	 0.024	 1216	Accepted
