#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 101;

int x[N][N], f[N][N][N];

int main() {
	int tc, cn = 0, m, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &m, &n);
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) scanf("%d", x[i]+j);
		memset(f, -1, sizeof(f));
		f[0][0][0] = x[0][0];
		for (int i=1; i<n; ++i) f[0][0][i] = f[0][0][i-1] + x[0][i];
		for (int i=1; i<n; ++i) f[1][0][i] = f[0][0][i] + x[1][0] + x[1][i];
		for (int k=1; k<m; ++k) {
			for (int j=0; j<n; ++j) for (int i=0; i<j; ++i) if (f[k][i][j] != -1) {
				if (i + 1 < j) f[k][i+1][j] = max(f[k][i+1][j], f[k][i][j]+x[k][i+1]);
			}
			for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) if (f[k][i][j] != -1) {
				if (j + 1 < n) f[k][i][j+1] = max(f[k][i][j+1], f[k][i][j]+x[k][j+1]);
			}
			for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) if (f[k][i][j] != -1) {
				f[k+1][i][j] = f[k][i][j] + x[k+1][i] + x[k+1][j];
			}
		}
		printf("Case %d: %d\n", ++cn, f[m-1][n-2][n-1]);
	}
	return 0;
}

// 292166	2013-11-27 18:53:00	 1071 - Baker Vai	 C++	 0.048	 5152	Accepted
