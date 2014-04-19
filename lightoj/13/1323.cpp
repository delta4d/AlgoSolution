#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 1000 + 86;

struct node {
	int x, y;
	node(int _x=0, int _y=0):x(_x), y(_y) {}
	bool operator<(const node &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
} c[MAXN];
char d[10];

int dx(const char x) {
	if (x == 'N' || x == 'S') return 0;
	return x == 'W' ? -1 : 1;
}

int dy(const char y) {
	if (y == 'W' || y == 'E') return 0;
	return y == 'N' ? 1 : -1;
}

ll gao(ll x, ll d, ll K, ll L) {
	x += d * K;
	if (d > 0) {
		if (x <= L) return x;
		x -= L;
		x %= 2 * L;
		if (x <= L) return L - x;
		return x - L;
	}
	if (x >= 0) return x;
	x = -x;
	x %= 2 * L;
	if (x <= L) return x;
	return 2 * L - x;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll L, W, n, K;
		scanf("%lld%lld%lld%lld", &L, &W, &n, &K);
		for (ll i=0,x,y; i<n; ++i) {
			scanf("%lld%lld%s", &x, &y, d);
			x = gao(x, dx(d[1]), K, L);
			y = gao(y, dy(d[0]), K, W);
			c[i].x = x, c[i].y = y;
		}
		sort(c, c+n);
		printf("Case %d:\n", ++cn);
		for (int i=0; i<n; ++i) printf("%d %d\n", c[i].x, c[i].y);
	}
	return 0;
}

// 253689	2013-08-21 00:25:36	 1323 - Billiard Balls	 C++	 0.020	 1096	Accepted
