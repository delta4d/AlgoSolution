#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int tc, cn = 0, m, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &m, &n);
		int S[10], f[10][10]={0};
		for (int i=0; i<m; ++i) scanf("%d", S+i);
		for (int i=0; i<m; ++i) f[0][i] = 1;
		for (int i=1; i<n; ++i) for (int j=0; j<m; ++j) for (int k=0; k<m; ++k) {
			if (abs(S[j]-S[k]) <= 2) f[i][j] += f[i-1][k];
		}
		int tot = 0;
		for (int i=0; i<m; ++i) tot += f[n-1][i];
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 289673	2013-11-21 18:17:34	 1122 - Digit Count	 C++	 0.000	 1088	Accepted
