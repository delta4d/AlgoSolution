#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 100000 + 86;

vector <int> e[N];
int x[N], d[N], tot, idx, mx;
bool v[N];

void gao(int x, int y) {
	++tot;
	v[x] = true;
	for (int i=0; i<(int)e[x].size(); ++i) {
		int z = e[x][i];
		if (z == y) continue;
		d[z] = d[x] + 1;
		if (d[z] > mx) mx = d[z], idx = z;
		gao(z, x);
	}
}

int D(int u, int n) {
	mx = 0, d[u] = 1;
	gao(u, -1);
	return idx;
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0,u,v; i<m; ++i) {
			scanf("%d%d", &u, &v), --u, --v;
			e[u].push_back(v), e[v].push_back(u);
		}
		memset(v, false, sizeof(v));
		memset(x, 0x3f, sizeof(x));
		for (int i=0; i<n; ++i) if (!v[i]) {
			tot = 0;
			int k = d[D(D(i, n), n)];
			tot >>= 1;
			for (int i=1; i<=tot; ++i) x[i] = min(x[i], i<=k?i-1:2*i-k-1);
		}
		printf("Case %d:\n", ++cn);
		for (scanf("%d", &m); m--; ) {
			scanf("%d", &n);
			if (x[n] == INF) puts("impossible");
			else printf("%d\n", x[n]);
		}
	}
	return 0;
}

// 318170	2014-01-28 21:52:50	 1412 - Visiting Islands	 C++	 0.492	 12040	Accepted
