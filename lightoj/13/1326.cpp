#include <cstdio>
using namespace std;

const int MAXN = 1 << 10;
const int MOD = 10056;

int f[MAXN][MAXN], x[MAXN];

void init() {
	f[0][0] = 1;
	for (int i=1; i<MAXN; ++i) f[i][1] = 1, f[i][i] = f[i-1][i-1] * i % MOD;
	for (int i=1; i<MAXN; ++i) {
		for (int j=2; j<i; ++j) {
			f[i][j] = j * (f[i-1][j] + f[i-1][j-1]) % MOD;
		}
	}
	for (int i=1; i<MAXN; ++i) for (int j=1; j<=i; ++j) x[i] = (x[i] + f[i][j]) % MOD;
}

int main() {
	init();
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		printf("Case %d: %d\n", ++cn, x[n]);
	}
	return 0;
}

// 254019	2013-08-21 18:01:08	 1326 - Race	 C++	 0.016	 5188	Accepted
