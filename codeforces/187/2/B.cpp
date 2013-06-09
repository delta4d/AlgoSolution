#include <cstdio>
using namespace std;

typedef long long LL;
const int MAXN = 100000 + 86;

struct BIT {
	int x[MAXN], n;

	void init(int _n=MAXN) { n = _n; }
	LL sum(int p) {
		LL r = 0;
		for (int i=p; i>0; i-=i&-i) r += x[i];
		return r;
	}
	LL add(int p, const LL off) {
		for (int i=p; i<=n; i+=i&-i) x[i] += off;
		return 0;
	}
} x;

int main() {
	int n, m;
	x.init();

	scanf("%d%d", &n, &m);
	for (int i=0,j; i<n; ++i) scanf("%d", &j), x.add(i+1, j), x.add(i+2, -j);
	for (int t,a,b; m--; ) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d", &a, &b);
			LL y = x.sum(a);
			x.add(a, b-y), x.add(a+1, y-b);
		} else if (t == 2) {
			scanf("%d", &a);
			x.add(1, a), x.add(n+1, -a);
		} else {
			scanf("%d", &a);
			printf("%I64d\n", x.sum(a));
		}
	}

	return 0;
}

// 3845913	 Jun 8, 2013 12:02:11 PM	delta_4d	 B - Sereja and Array	 GNU C++	Accepted	140 ms	400 KB
