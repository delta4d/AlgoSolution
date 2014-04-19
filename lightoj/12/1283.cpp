#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 102;
const int INF = 0x3f3f3f;

int x[N] = {-INF, INF};
int f[2][N][N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int main() {
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		for (int i=0; i<n; ++i) x[i+2] = fastin<int>();
		memset(f, -1, sizeof(f));
		f[0][0][1] = 0;
		int cur = 0, nxt = 1;
		for (int k=1; k<n+1; ++k) {
			nxt = cur ^ 1;
			for (int i=0; i<=k; ++i) for (int j=0; j<=k; ++j) {
				int cc = f[cur][i][j];
				f[cur][i][j] = -1;
				if (cc == -1) continue;
				if (x[k+1] >= x[i] && x[j] >= x[k+1]) {
					f[nxt][k+1][j] = max(f[nxt][k+1][j], cc+1);
					f[nxt][i][k+1] = max(f[nxt][i][k+1], cc+1);
				}
				f[nxt][i][j] = max(f[nxt][i][j], cc);
			}
			cur = nxt;
		}
		int mx = 0;
		for (int i=0; i<=n+1; ++i) for (int j=0; j<=n+1; ++j) mx = max(mx, f[cur][i][j]);
		printf("Case %d: %d\n", ++cn, mx);
	}
	return 0;
}

// 295027	2013-12-03 19:45:05	 1283 - Shelving Books	 C++	 0.228	 1168	Accepted
