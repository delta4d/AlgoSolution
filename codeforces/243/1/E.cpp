#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int const N = 1 << 9;
int const M = 1e9 + 7;

ll f[N][N], p[N*N]={1};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=1; i<N*N; ++i) p[i] = (p[i-1] << 1) % M;
	f[0][0] = 1;
	for (int i=0; i<=n; ++i) for (int j=0; j<m; ++j) {
		for (int k=i+1; k<=n; ++k) {
			f[k][j+1] = (f[k][j+1] + (f[i][j] * (p[k-i] - 1) % M) * p[(k-i)*i]) % M;
		}
	}
	ll tot = 0;
	for (int i=0; i<=n; ++i) tot = (tot + f[i][m] * p[(n-i)*i]) % M;
	printf("%I64d\n", tot);
	return 0;
}

// 7325647	2014-08-02 11:06:35	delta_4d	E - Sereja and Sets	GNU C++0x	Accepted	1123 ms	4100 KB
