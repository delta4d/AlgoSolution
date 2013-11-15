#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 100;

int w, h;

struct rectangular {
	int xl, yl;
	int xh, yh;
	
	rectangular(int _xl=0, int _yl=0, int _xh=0, int _yh=0):xl(_xl), yl(_yl), xh(_xh), yh(_yh) {}
	inline bool input() {
		return scanf("%d %d %d %d", &xl, &yl, &xh, &yh) == 4;
	} 
	inline bool in() {
		return xl >= 0 && xh <= w && yl >= 0 && yh <= h;
	}
	inline bool disjoint(rectangular &a) {
		return xl >= a.xh || xh <= a.xl || yl >= a.yh || yh <= a.yl;
	}
	inline int area() {
		return (xh - xl) * (yh - yl);
	}
} f[MAXN];

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int tot;
	int xl, yl, xh, yh;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &w, &h);
		scanf("%d", &n);
		tot = 0;
		xl = yl = INF;
		xh = yh = -INF;
		for (i=0; i<n; ++i) {
			f[i].input();
			xl = min(xl, f[i].xl);
			yl = min(yl, f[i].yl);
			xh = max(xh, f[i].xh);
			yh = max(yh, f[i].yh);
			tot += f[i].area();
		}
		k = -1;
		for (i=0; i<n; ++i) {
			for (j=i+1; j<n; ++j) {
				if (!f[i].disjoint(f[j])) {
					k = 1;
					goto next;
				}
			}
		}
		next:;
		if (k != -1) {
			puts("NONDISJOINT");
			continue;
		}
		for (i=0; i<n; ++i) if (!f[i].in()) break;
		if (i < n) {
			puts("NONCONTAINED");
			continue;
		}
		if (tot == w * h) puts("OK");
		else puts("NONCOVERING");
	}
	return 0;
}