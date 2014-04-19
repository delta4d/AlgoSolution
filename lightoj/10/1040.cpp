#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[50], v[50], f[50][50];

int gao(int n) {
	int tot = 0;
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) tot += f[i][j];
	fill(d, d+n, INF), d[0] = 0;
	memset(v, false, sizeof(v));
	for (int k=0; k<n; ++k) {
		int mn = INF, idx = -1;
		for (int i=0; i<n; ++i) if (!v[i] && d[i] < mn) mn = d[i], idx = i;
		if (idx == -1) break;
		v[idx] = true;
		for (int i=0; i<n; ++i) if (!v[i]) {
			if (f[idx][i] && f[idx][i] < d[i]) d[i] = f[idx][i];
			if (f[i][idx] && f[i][idx] < d[i]) d[i] = f[i][idx];
		}
	}
//	for (int i=0; i<n; ++i) printf("%d ", d[i]); puts("");
	for (int i=0; i<n; ++i) {
		if (d[i] == INF) return -1;
		tot -= d[i];
	}
	return tot;
}

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) scanf("%d", f[i]+j);
		printf("Case %d: %d\n", ++cn, gao(n));
	}
	return 0;
}

// 307929	2014-01-05 22:29:13	 1040 - Donation	 C++	 0.012	 1096	Accepted
