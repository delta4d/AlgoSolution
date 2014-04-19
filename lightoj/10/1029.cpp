#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 111;

struct DSU {
	int f[N];

	void init(int n=N) {
		memset(f, -1, n*sizeof(int));
	}

	int find_root(int x) {
		return f[x] < 0 ? x : f[x] = find_root(f[x]);
	}

	bool unite(int x, int y) {
		int rx = find_root(x), ry = find_root(y);
		if (rx == ry) return false;
		if (f[rx] < f[ry]) f[ry] += f[rx], f[rx] = ry;
		else f[rx] += f[ry], f[ry] = rx;
		return true;
	}
} dsu;

struct edge {
	int u, v, w;

	edge(int _u=0, int _v=0, int _w=0):u(_u), v(_v), w(_w) {}
	bool operator<(const edge &a) const {
		return w < a.w;
	}
};

vector <edge> e;

int gao(const int n, bool rev) {
	int ret = 0;
	dsu.init();
	int st = 0, off = 1;
	if (rev) st = (int)e.size() - 1, off = -1;
	for (int i=st,j=n; j; i+=off) {
		int u = e[i].u, v = e[i].v, w = e[i].w; 
		if (!dsu.unite(u, v)) continue;
		ret += w, --j;
	}
	return ret;
}

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		e.clear();
		int u, v, w;
		while (scanf("%d%d%d", &u, &v, &w), u+v+w) e.push_back(edge(u, v, w));
		sort(e.begin(), e.end());
		int tot = gao(n, false) + gao(n, true);
		printf("Case %d: %d%s\n", ++cn, (tot&1)?tot:(tot>>1), (tot&1)?"/2":"");
	}
	return 0;
}

// 296275	2013-12-06 22:56:37	 1029 - Civil and Evil Engineer	 C++	 0.084	 1608	Accepted
