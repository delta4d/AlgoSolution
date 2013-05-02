#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const int INF = 0x3f3f3f3f;

bool f[MAXN][MAXN];
int k;
int xc, yc;

inline int D(const int x, const int y) {
	return abs(x - xc) + abs(y - yc);
}

bool put(const int m, int &x, int &l, int &r) {
	int mn = INF;
	for (int i=1; i<=k; ++i) {
		for (int j=1,c=0,cc=0; j<=k; ++j) {
			if (f[i][j]) {
				c = cc = 0;
			} else {
				if (c < m) cc += D(i, j), ++c;
				else cc += D(i, j) - D(i, j-m);
			}
			if (c == m && cc < mn) mn = cc, x = i, l = j - m + 1, r = j;
		}		
	}
	if (mn == INF) return false;
	for (int i=l; i<=r; ++i) f[x][i] = true;
	return true;
}

int main() {
	int n, m;

	scanf("%d%d", &n, &k);
	xc = yc = k / 2 + 1;
	while (n--) {
		scanf("%d", &m);
		int x, l, r;
		if (put(m, x, l, r)) printf("%d %d %d\n", x, l, r);
		else puts("-1");
	}

	return 0;
}

// 3660677	 May 2, 2013 6:39:39 PM	delta_4d	 B - Cinema Cashier	 GNU C++	Accepted	31 ms	0 KB
