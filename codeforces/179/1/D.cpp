#include <cstdio>
using namespace std;

const int MAXN = 2000 + 86;
const int MOD = 1000000007;

int f[MAXN][MAXN], g[MAXN][MAXN];

int main() {
	int n, m;
	int tot = 0;

	scanf("%d%d", &n, &m);

	for (int i=1; i<=m; ++i) f[1][i] = g[1][i] = 1;
	for (int i=2; i<=n; ++i) {
		for (int j=2; j<=m; ++j) {
			f[i][j] = (2ll * f[i][j-1] - f[i][j-2] + f[i-1][j]) % MOD;
			g[i][j] = (g[i-1][j] + f[i][j]) % MOD;
		}
	}
	for (int t=1; t<=n; ++t) for (int k=2; k<=m; ++k) {
		int cc = g[t][k] * (0ll + f[n-t+1][k]) % MOD;
		tot = (tot + cc * (m - k + 1ll)) % MOD;
	}

	if (tot < 0) tot += MOD;
	printf("%d\n", tot);

	return 0;
}

// 3518558	 Apr 12, 2013 6:35:55 PM	delta_4d	 295D - Greg and Caves	 GNU C++	Accepted	265 ms	34000 KB
