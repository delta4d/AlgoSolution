#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 100000 + 86;

int v[MAXN], c[MAXN];
LL f[MAXN];

struct MX {
	LL mx[2], x[2];

	void init() {
		mx[0] = mx[1] = -INF;
		x[0] = x[1] = -1;
	}

	LL cmax(const LL cx) {
		return mx[x[0] == cx];
	}

	void update(LL cc, LL cx) {
		for (int i=0; i<2; ++i) if (x[i] == cx) {
			mx[i] = max(mx[i], cc);	
			if (mx[0] < mx[1]) {
				swap(mx[0], mx[1]);
				swap(x[0], x[1]);
			}
			return;
		}
		if (cc > mx[0]) {
			mx[1] = mx[0], x[1] = x[0];
			mx[0] = cc, x[0] = cx;
			return;
		}
		if (cc > mx[1]) {
			mx[1] = cc, x[1] = cx;
		}
	}
} cc;

int main() {
	int n, q;
	int a, b;

	scanf("%d%d", &n, &q);
	for (int i=0; i<n; ++i) scanf("%d", v+i);
	for (int i=0; i<n; ++i) scanf("%d", c+i), --c[i];
	while (q--) {
		scanf("%d%d", &a, &b);	
		fill(f, f+n, -INF);
		cc.init();
		for (int i=0; i<n; ++i) {
			LL mx = (LL)b * v[i];
			for (int j=0; j<2; ++j) {
				if (cc.x[j] == c[i]) mx = max(mx, cc.mx[j] + (LL)a * v[i]);
				else mx = max(mx, cc.mx[j] + (LL)b * v[i]);
			}
			mx = max(mx, f[c[i]] + (LL)a * v[i]);
			cc.update(f[c[i]]=max(mx, f[c[i]]), c[i]);
		}
		LL mx = 0;
		for (int i=0; i<n; ++i) mx = max(mx, f[i]);
		printf("%I64d\n", mx);
	}

	return 0;
}

// 3699819	 May 10, 2013 7:58:48 PM	delta_4d	 C - Choosing Balls	 GNU C++	Accepted	2062 ms	1548 KB
