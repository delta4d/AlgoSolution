#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
const int MOD = 100000007;
const int N = 15000 + 86;

int f[2][N], g[2][N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int main() {
	int tc, cn = 0, N, K, S;
	for (tc=fastin<int>(); tc--; ) {
		N = fastin<int>(), K = fastin<int>(), S = fastin<int>();
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		for (int i=1; i<=K&&i<=S; ++i) f[0][i] = i;
		int cur = 1, nxt = 0;
		for (int k=1; k<N; ++k) {
			nxt = cur ^ 1;
			for (int i=1; i<=S; ++i) {
				g[cur][i] = g[cur][i-1] + f[nxt][i-1] - (i - 1 - K >= 0) * f[nxt][i-1-K];
				f[cur][i] = g[cur][i] + f[cur][i-1] - (i - 1 - K >= 0) * ((ll)K * f[nxt][i-1-K] % MOD);
				g[cur][i] %= MOD;
				f[cur][i] %= MOD;
			}
			cur = nxt;
		}
		int res = f[cur^1][S];
		if (res < 0) res += MOD;
		printf("Case %d: %d\n", ++cn, res);
	}
	return 0;
}

// 295068	2013-12-03 21:23:17	 1193 - Dice (II)	 C++	 0.260	 1324	Accepted
