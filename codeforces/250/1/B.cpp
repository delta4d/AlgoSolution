#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int const N = 1e5 + 10;

double tot = 0;
struct DSU {
	int r[N];

	DSU() {
		memset(r, -1, sizeof(r));
	}

	int find_root(int x) {
		return r[x] < 0 ? x : r[x] = find_root(r[x]);
	}

	bool unite(int x, int y, int w) {
		int rx = find_root(x), ry = find_root(y);
		if (rx == ry) return false;
		tot += 1.0 * r[rx] * r[ry] * w;
//		printf("-- %d %d %d\n", -r[rx], -r[ry], w);
		r[rx] += r[ry], r[ry] = rx;
		return true;
	}
} dsu;

struct edge {
	int x, y, w;
	
	edge(int x=0, int y=0, int w=0):x(x), y(y), w(w) {};
	bool operator<(const edge &a) const {
		return w > a.w;
	}
};
vector <edge> e;
int v[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) scanf("%d", v+i);
	for (int i=0,x,y; i<m; ++i) {
		scanf("%d%d", &x, &y), --x, --y;
		e.push_back(edge(x, y, min(v[x], v[y])));
	}
	sort(begin(e), end(e));
	for (auto &c: e) {
		dsu.unite(c.x, c.y, c.w);
	}
	tot = 2.0 * tot / n / (n - 1);
	printf("%.16lf\n", tot);
	return 0;
}

// 6773014	 2014-06-01 18:51:23	delta_4d	 B - The Child and Zoo	 GNU C++0x	Accepted	 77 ms	 3100 KB
