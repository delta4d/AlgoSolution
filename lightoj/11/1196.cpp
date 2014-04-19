#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100000 + 86;
const int INF = 0x3f3f3f3f;
typedef long long ll;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	T sgn = 1;
	while (c < '0' || c > '9') {
		c = getchar();
		if (c == '-') sgn = -1;
	}
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return sgn * a;
}

inline int sgn(ll x) { return x < 0 ? -1 : (x ? 1 : 0); }

struct point {
	int x, y;
	point(int x=0, int y=0):x(x), y(y) {}
	void readin() { scanf("%d%d", &x, &y); }
} p[N];

struct segment {
	point p1, p2;
	point tp1, tp2;
	segment(point p1=point(), point p2=point()):p1(p1), p2(p2) {}
	bool operator<(const segment &a) const {
		if (p1.y != a.p1.y) return p1.y < a.p1.y;
		return p2.y < a.p2.y;
	}
	void init(int a, int b) {
		p1 = p[a], p2 = p[b];
		tp1 = p1, tp2 = p2;
		if (p1.y > p2.y) swap(p1, p2);
	}
	int xxx(int x, int y) {
		ll z = (ll)(x - p1.x) * (ll)(p2.y - p1.y) - (ll)(p2.x - p1.x) * (ll)(y - p1.y);
		return sgn(z);
	}
} sg[N];

bool gao(int n, int x, int y) {
	int k = upper_bound(sg, sg+n, segment(point(0, y), point(0, INF))) - sg - 1;
	int cnt = 0;
	for (int i=k,j=10; i>=0&&j>=0; --i,--j) {
		if ((ll)(y - sg[i].p1.y) * (ll)(y - sg[i].p2.y) <= 0) {
			int xv = sg[i].xxx(x, y);
			if (xv == 0 && (ll)(x-sg[i].p1.x) * (ll)(x-sg[i].p2.x) <= 0) return true;
			if (y == sg[i].tp2.y) continue;
			if (xv > 0) ++cnt;
//			printf("== %d %d\n", i, xv);
		}
	}
//	printf("==sum %d %d\n", k, cnt);
	return cnt == 1;
}

int main() {
	int tc, cn = 0, n, q;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) p[i].readin();
		for (int i=0; i<n; ++i) sg[i].init(i, i==n-1?0:i+1);
		sort(sg, sg+n);
//		for (int i=0; i<n; ++i) printf("%d %d -- %d %d\n", sg[i].p1.x, sg[i].p1.y, sg[i].p2.x, sg[i].p2.y);
		scanf("%d", &q);
		printf("Case %d:\n", ++cn);
		for (int t=0,x,y; t<q; ++t) {
			scanf("%d%d", &x, &y);
			printf("%s\n", gao(n, x, y)?"y":"n");
		}
	}
	return 0;
}
