#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 111;

ll f[MAXN][MAXN], g[MAXN][MAXN];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) for (int j=0; j<=i; ++j) scanf("%lld", f[i]+j);
		for (int i=n-2; i>=0; --i) for (int j=0; j<=i; ++j) scanf("%lld", g[i]+j);
		for (int i=1; i<n; ++i) {
			f[i][0] += f[i-1][0];
			f[i][i] += f[i-1][i-1];
			for (int j=1; j<i; ++j) {
				f[i][j] += max(f[i-1][j-1], f[i-1][j]);
			}
		}
		for (int i=0; i<n; ++i) g[n-1][i] = f[n-1][i];
		for (int i=n-2; i>=0; --i) {
			for (int j=0; j<=i; ++j) {
				g[i][j] += max(g[i+1][j], g[i+1][j+1]);
			}
		}
		printf("Case %d: %lld\n", ++cn, g[0][0]);
	}
	return 0;
}

// 273512	2013-10-13 20:30:38	 1004 - Monkey Banana Problem	 C++	 0.108	 1280	Accepted
