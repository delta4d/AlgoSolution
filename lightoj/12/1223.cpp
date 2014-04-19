#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 101;

int f[N][N][N];

void init() {
	for (int i=1; i<N; ++i) for (int j=i; j<N; ++j) f[1][i][j] = (i + j) * (j - i + 1) >> 1;
	for (int i=2; i<N; ++i) for (int k=0; k<N; ++k) for (int s=1; s+k<N; ++s) if (!f[i][s][s+k]) {
		int mn = INF, t = s + k;
		for (int k=s; k<=t; ++k) mn = min(mn, k + max(f[i-1][s][k-1], f[i][k+1][t]));
		f[i][s][t] = mn;
	}
}

int main() {
	init();
	int tc, cn = 0, k, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &k, &m);
		printf("Case %d: %d\n", ++cn, f[k][1][m]);
	}
	return 0;
}

// 317130	2014-01-26 16:19:21	 1223 - Testing Mailboxes	 C++	 0.096	 5112	Accepted
