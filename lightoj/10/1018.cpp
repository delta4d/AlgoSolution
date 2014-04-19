#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 16;

int x[N], y[N];
int f[1<<N];
int e[N][N];

int xmult(int i, int j, int k) {
	return (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
}

int gao(int mask, const int n) {
	if (!mask || f[mask]) return f[mask];
	if (__builtin_popcount(mask) <= 2) return f[mask] = 1;
	f[mask] = INF;
	for (int i=0; i<n; ++i) if (mask & 1 << i) {
		for (int j=0; j<n; ++j) if (j != i) if (mask & 1 << j) {
			f[mask] = min(f[mask], gao(mask&e[i][j], n)+1);
		}
		break;
	}
	return f[mask];
}

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d%d", x+i, y+i);
		int m = 1 << n;
		for (int i=0; i<n; ++i) fill(e[i], e[i]+n, m-1);
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (i != j) {
			for (int k=0; k<n; ++k) if (xmult(i, j, k) == 0) e[i][j] ^= 1 << k;
		}
		fill(f, f+m, 0);
		printf("Case %d: %d\n", ++cn, gao(m-1, n));
	}
	return 0;
}

// 290960	2013-11-24 19:48:00	 1018 - Brush (IV)	 C++	 0.300	 1344	Accepted
