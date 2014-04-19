#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 14;

int f[1<<N];
int c[N][N];

int gao(int mask, const int n) {
	if (f[mask] >= 0) return f[mask];
	f[mask] = INF;
	for (int i=0; i<n; ++i) if (mask & 1 << i) {
		int next_mask = mask ^ (1 << i);
		int cc = gao(next_mask, n) + c[i][i];
		for (int j=0; j<n; ++j) if (next_mask & 1 << j) cc += c[i][j];
		f[mask] = min(f[mask], cc);
	}
	return f[mask];
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n), m = 1 << n;
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) scanf("%d", c[i]+j);
		memset(f, -1, sizeof(f));
		f[0] = 0;
		printf("Case %d: %d\n", ++cn, gao(m-1, n));
	}
	return 0;
}

// 292709	2013-11-29 01:00:24	 1119 - Pimp My Ride	 C++	 0.428	 1152	Accepted
