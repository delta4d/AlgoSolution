#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 100000007;

int f[2][15000+86];

int main() {
	int tc, cn = 0, N, K, S;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &N, &K, &S);
		int cur = 0, nxt = 1;
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (int i=0; i<N; ++i) {
			nxt = cur ^ 1;
			for (int j=1; j<=S; ++j) {
				f[nxt][j] = (f[nxt][j-1] + f[cur][j-1]) % MOD;
				if (j - K - 1 >= 0) f[nxt][j] = (f[nxt][j] - f[cur][j-K-1]) % MOD;
			}
			for (int j=0; j<=S; ++j) f[cur][j] = 0;
			cur = nxt;
		}
		if (f[cur][S] < 0) f[cur][S] += MOD;
		printf("Case %d: %d\n", ++cn, f[cur][S]);
	}
	return 0;
}

// 294588	2013-12-02 18:09:54	 1145 - Dice (I)	 C++	 0.360	 1204	Accepted
