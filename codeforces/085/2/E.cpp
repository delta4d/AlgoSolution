#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int f[40][1<<6][1<<6];

bool ok(const int m, int p2, int p1, int p0) {
	int p = 0;
	for (int i=0; i<m; ++i) {
		if (p1 & 1 << i) {
			p |= 1 << i;
			if (i) p |= 1 << (i - 1);
			if (i + 1 < m) p |= 1 << (i + 1);
		}
	}
	p |= p0 | p2;
	return p + 1 == (1 << m);
}

int gao(int m, int n) {
	if (m == 1) return n - (n + 2) / 3;
	if (m == 2) return m * n - 1 - n / 2;
	int t = 1 << m;
	for (int i=0; i<=n; ++i) for (int j=0; j<t; ++j) for (int k=0; k<t; ++k) f[i][j][k] = INF;
	for (int i=0; i<t; ++i) f[0][0][i] = __builtin_popcount(i);
	for (int i=0; i<n; ++i) for (int j=0; j<t; ++j) for (int k=0; k<t; ++k) {
		if (f[i][j][k] == INF) continue;
		for (int mask=0; mask<t; ++mask) if (ok(m, j, k, mask)) {
			f[i+1][k][mask] = min(f[i+1][k][mask], f[i][j][k] + __builtin_popcount(mask));
		}
	}
	int r = INF;
	for (int i=0; i<t; ++i) for (int j=0; j<t; ++j) if (ok(m, i, j, 0)) r = min(r, f[n-1][i][j]);
	return m * n - r;
}

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	printf("%d\n", gao(min(n, m), max(n, m)));

	return 0;
}

// 3854353	 Jun 10, 2013 6:45:16 PM	delta_4d	 C - Petya and Spiders	 GNU C++	Accepted	 15 ms	 600 KB
