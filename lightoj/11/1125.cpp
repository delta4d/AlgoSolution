#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	T sgn = 1;
	while (c < '0' || c > '9') {
		c = getchar();
		if (c == '-') sgn = -1;
	}
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return sgn * a;
}

int main() {
	int tc, cn = 0, N, Q, D, M, x[201];
	for (tc=fastin<int>(); tc--; ) {
		N = fastin<int>(), Q = fastin<int>();
		for (int i=1; i<=N; ++i) x[i] = fastin<int>();
		printf("Case %d:\n", ++cn);
		while (Q--) {
			D = fastin<int>(), M = fastin<int>();
			int cur = 0, nxt = 1;
			long long f[2][11][20]={0};
			f[0][0][0] = 1;
			for (int i=1; i<=N; ++i) {
				nxt = cur ^ 1;
				for (int j=0; j<=M; ++j) for (int k=0; k<D; ++k) {
					int r = (k - x[i]) % D;
					if (r < 0) r += D;
					f[nxt][j][k] = f[cur][j][k] + (j > 0) * f[cur][j-1][r];
				}
				cur = nxt;
			}
			printf("%lld\n", f[cur][M][0]);
		}
	}
	return 0;
}

// 292971	2013-11-29 21:06:05	 1125 - Divisible Group Sums	 C++	 0.012	 1088	Accepted
