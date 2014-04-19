#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[101][101], x[101], s[101], L[101], R[101];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=1; i<=n; ++i) scanf("%d", x+i), s[i] = s[i-1] + x[i];
		for (int i=1; i<=n; ++i) L[i] = R[i] = f[i][i] = x[i];
		for (int k=1; k<n; ++k) for (int i=1; i+k<=n; ++i) {
			int j = i + k;
			f[i][j] = s[j] - s[i-1];
			f[i][j] = max(f[i][j], s[j]-s[i-1]-min(L[i], R[j]));
			L[i] = min(L[i], f[i][j]);
			R[j] = min(R[j], f[i][j]);
		}
		printf("Case %d: %d\n", ++cn, 2*f[1][n]-s[n]);
	}
	return 0;
}

// 291683	2013-11-26 16:22:45	 1031 - Easy Game	 C++	 0.000	 1128	Accepted
