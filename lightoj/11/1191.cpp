#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 50;

unsigned long long f[2][N+1][N+1][N+1];
unsigned long long s[N+1][N+1][N+1];

void init() {
	int cur = 0, nxt = 1;
	f[cur][1][1][1] = 1, s[1][1][1] = 1;
	for (int n=1; n<N; ++n) {
		nxt = cur ^ 1;
		for (int k=1; k<=n; ++k) for (int m=1; m<=n; ++m) {
			for (int L=1; L<=m; ++L) if (f[cur][k][m][L]) {
				unsigned long long cc = f[cur][k][m][L];
				f[nxt][k+1][m][1] += cc, s[n+1][k+1][m] += cc;
				if (L + 1 <= m) f[nxt][k][m][L+1] += cc, s[n+1][k][m] += cc;
				else f[nxt][k][L+1][L+1] += cc, s[n+1][k][L+1] += cc;
				f[cur][k][m][L] = 0;
			}
		}
		cur = nxt;
	}
	for (int n=1; n<=N; ++n) for (int k=1; k<=n; ++k) for (int m=1; m<=n; ++m) {
		s[n][k][m] += s[n][k][m-1];
	}
}

int main() {
	init();
	int tc, cn = 0, n, k, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &n, &k, &m);
		printf("Case %d: %llu\n", ++cn, s[n][k][m]);
	}
	return 0;
}

// 292947	2013-11-29 19:05:55	 1191 - Bar Codes	 C++	 0.032	 4196	Accepted
