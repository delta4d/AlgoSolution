#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 55;

int x[N], y[N], f[N][N];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=1; i<=n; ++i) scanf("%d", x+i); sort(x+1, x+n+1);
		for (int i=1; i<=n; ++i) scanf("%d", y+i); sort(y+1, y+n+1);
		memset(f, 0, sizeof(f));
		for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j) {
			f[i][j] = f[i][j-1];
			if (x[i] > y[j]) f[i][j] = max(f[i][j], f[i-1][j-1]+2);
			if (x[i] == y[j]) f[i][j] = max(f[i][j], f[i-1][j-1]+1);
		}
		printf("Case %d: %d\n", ++cn, f[n][n]);
//		for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j) printf("(%d, %d) => %d\n", i, j, f[i][j]);
	}
	return 0;
}

// 279392	2013-10-27 19:26:06	 1198 - Karate Competition	 C++	 0.000	 1100	Accepted
