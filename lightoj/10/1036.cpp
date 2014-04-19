#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 501;

int f[N][N], R[N][N], U[N][N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int main() {
	int tc, cn = 0, m, n;
	for (tc=fastin<int>(); tc--; ) {
		m = fastin<int>(), n = fastin<int>();
		for (int i=1; i<=m; ++i) for (int j=1; j<=n; ++j) U[i][j] = fastin<int>() + U[i][j-1];
		for (int i=1; i<=m; ++i) for (int j=1; j<=n; ++j) R[i][j] = fastin<int>() + R[i-1][j];
		for (int i=1; i<=m; ++i) for (int j=1; j<=n; ++j) {
			f[i][j] = max(f[i-1][j] + U[i][j], f[i][j-1] + R[i][j]);
		}
		printf("Case %d: %d\n", ++cn, f[m][n]);
	}
	return 0;
}

// 294702	2013-12-02 23:06:30	 1036 - A Refining Company	 C++	 0.152	 4028	Accepted
