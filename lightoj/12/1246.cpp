#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int N = 55;
const int N2 = N * N;

ll C[60][60];
ll p[N][N2], xs[N][N2];

void init() {
	for (int i=0; i<60; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j=1; j<i; ++j) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
	}
	for (int i=1; i<N; ++i) {
		xs[i][0] = 1;
		for (int j=1; j<N2; ++j) xs[i][j] = xs[i][j-1] * i % MOD;
	}
	for (ll s=1; s<N2; ++s) {
		for (ll x=1; x<N; ++x) {
			ll sgn = 1;
			for (ll y=x; y>=0; --y) {
				p[x][s] = (p[x][s] + sgn * C[x][y] * xs[y][s]) % MOD;
				sgn = -sgn;
			}
			if (p[x][s] < 0) p[x][s] += MOD;
		}
	}
//	printf("%lld\n", p[2][2]);
}

int main() {
	init();
	int tc, cn = 0, m, n, k;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &m, &n, &k);
		++m, ++n;
		ll tot = 0, a = m * n / 2, b = m * n - a;
		if (a == 0) {
			tot = k;
		} else {
			for (int i=1; i<k; ++i) for (int j=1; j+i<=k; ++j) {
				ll c1 = C[k][i] * p[i][a] % MOD, c2 = C[k-i][j] * p[j][b] % MOD;
				ll cc = c1 * c2 % MOD;
//				printf("%d %d %lld %lld == %lld\n", i, j, c1, c2, cc);
				tot = (tot + cc) % MOD;
			}
		}
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 254087	2013-08-21 20:08:09	 1246 - Colorful Board	 C++	 0.152	 3716	Accepted
