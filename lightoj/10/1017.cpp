#include <cstdio>
#include <algorithm>
using namespace std;

int x[111], d[111];
int f[111][111];

int main() {
	int tc, cn = 0, n, w, K;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &n, &w, &K);
		for (int i=1; i<=n; ++i) scanf("%*d%d", x+i);
		sort(x+1, x+n+1);
		for (int i=n; i>0; ++d[i--]) for (d[i]=i; d[i]>0&&x[d[i]]+w>=x[i]; --d[i]);
		for (int i=1; i<=n; ++i) for (int j=1; j<=K; ++j) {
			f[i][j] = f[i][j-1];
			for (int k=i; k>0; --k) f[i][j] = max(f[d[k]-1][j-1] + k - d[k] + 1, f[i][j]);
		}
		printf("Case %d: %d\n", ++cn, f[n][K]);
	}
	return 0;
}

// 290676	2013-11-23 18:48:53	 1017 - Brush (III)	 C++	 0.032	 1136	Accepted
