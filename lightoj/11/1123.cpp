#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 201;

struct edge {
	int u, v, w;
	edge(int u=0, int v=0, int w=0):u(u), v(v), w(w) {}
	bool operator<(const edge &a) const {
		return w < a.w;
	}
};

struct DSU {
	int r[N];

	void init() {
		memset(r, -1, sizeof(r));
	}

	int find_root(int x) {
		return r[x] < 0 ? x : r[x] = find_root(r[x]);
	}

	bool merge(int x, int y) {
		int rx = find_root(x), ry = find_root(y);
		if (rx == ry) return false;
		if (r[rx] < r[ry]) swap(rx, ry);
		r[ry] += r[rx], r[rx] = ry;
		return true;
	}
} dsu;

vector <edge> e, ee;

int gao(const int n) {
	int cnt = 0, tot = 0;
	dsu.init();
	sort(e.begin(), e.end());
	ee.clear();
	for (int k=0; k<(int)e.size(); ++k) {
		int u = e[k].u, v = e[k].v, w = e[k].w;
		if (dsu.merge(u, v)) {
			tot += w, ++cnt;
			ee.push_back(e[k]);
		}
	}
	e.swap(ee);
	return cnt == n - 1 ? tot : -1;
}

int main() {
	int tc, cn = 0, n, w;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &w);
		e.clear();
		printf("Case %d:\n", ++cn);
		for (int i=0,x,y,z; i<w; ++i) {
			scanf("%d%d%d", &x, &y, &z), --x, --y;
			e.push_back(edge(x, y, z));
			printf("%d\n", gao(n));
		}
	}
	return 0;
}

// 317723	2014-01-27 20:50:57	 1123 - Trail Maintenance	 C++	 0.188	 1220	Accepted
