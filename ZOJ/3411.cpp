#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x[55], y[55];
int f[55][55];

inline int gcd(int x, int y) {
	int z;
	if (x < y) swap(x, y);
	while (y != 0) {
		z = x % y;
		x = y;
		y = z;
	}
	return x;
}

inline void gao(int &a, int &b) {
	int t(gcd(a, b));
	a /= t, b /= t;
}

int main() {
	int i, j, k;
	int m, n, a, b;
	int tc;
	int sum, tot;

	while (scanf("%d %d %d %d", &n, &m, &a, &b) == 4) {
		tot = 1;
		for (i=1; i<=n; ++i) {
			scanf("%d", &k);
			x[i] = a - k;
			y[i] = b - k;
			tot *= b - a + 1;
		}
		for (i=0; i<=m; ++i) f[0][i] = 1;
		for (i=1; i<=n; ++i) {
			for (j=0; j<=m; ++j) {
				for (k=0; k<=j; ++k) {
					if (x[i] <= j - k && j - k <= y[i]) {
						f[i][j] += f[i-1][j-k];
					}
				}
			}
		}
		sum = 0;
		for (i=0; i<=m; ++i) sum += f[n][i];
		gao(sum, tot);
		printf("%d/%d\n", sum, tot);
	}

	return 0;
}
