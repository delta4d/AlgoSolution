#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

const int N = 10000 + 86;
const int INF = 0x3f3f3f3f;

struct edge {
	int x, y, z;
	edge(int _x=0, int _y=0, int _z=0):x(_x), y(_y), z(_z) {}
	bool operator<(const edge &a) const {
		return z < a.z;
	}
	void to_s() {
		printf("edge: %d -> %d cost: %d\n", x, y, z);
	}
};
struct DS {
	int r[N];

	void init() {
		memset(r, 0xff, sizeof(r));
	}

	int find_root(int x) {
		return r[x] < 0 ? x : r[x] = find_root(r[x]);
	}

	bool unite(int x, int y) {
		int rx = find_root(x), ry = find_root(y);
		if (rx == ry) return false;
		if (r[rx] < r[ry]) r[rx] += r[ry], r[ry] = rx;
		else r[ry] += r[rx], r[rx] = ry;
		return true;
	}
} ds;
vector <edge> e;
vector <int> p[N];
int d[N], n, m, A, mn, mx;

void gao() {
	int cnt = 0;
	ds.init();
	sort(e.begin(), e.end());
	for (int i=0; i<(int)e.size(); ++i) {
		if (!ds.unite(e[i].x, e[i].y)) continue;
		d[cnt++] = i;
	}

//	for (int i=0; i<cnt; ++i) e[d[i]].to_s();
	mn = 0, mx = 0;
	for (int i=0; i<n; ++i) p[i].clear();
	for (int i=0; i<cnt; ++i) p[ds.find_root(e[d[i]].x)].push_back(e[d[i]].z);
	for (int i=0; i<n; ++i) if (ds.r[i] == -1) ++mx, mn += A;
	for (int i=0; i<n; ++i) if (!p[i].empty()) {
		sort(p[i].begin(), p[i].end(), greater<int>());
		int sz = (int)p[i].size(), cmn = A * (sz + 1), cmx = sz + 1, tot = 0;
		for (int k=0; k<sz; ++k) tot += p[i][k];
//		printf("== size %d, tot %d\n", sz, tot);
		for (int k=1,c=0; k<=sz; ++k) {
			int cc = (tot - c) + k * A;
//			printf("%d airports, save edge cost %d, total %d\n", k, c, cc);
			if (cc < cmn || cc == cmn && k > cmx) cmn = cc, cmx = k;
			c += p[i][k-1];
		}
		mn += cmn, mx += cmx;
	}
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		e.clear();
		scanf("%d%d%d", &n, &m, &A);
		for (int i=0,a,b,c; i<m; ++i) {
			scanf("%d%d%d", &a, &b, &c), --a, --b;
			e.push_back(edge(a, b, c));
		}
		gao();
		printf("Case %d: %d %d\n", ++cn, mn, mx);
	}
	return 0;
}

// 309513	2014-01-09 14:01:48	 1059 - Air Ports	 C++	 0.140	 3848	Accepted
