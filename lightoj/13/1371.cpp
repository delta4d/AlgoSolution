#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 1 << 10;
const int MOD = 1000000007;

int x[MAXN], y[MAXN];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d", x+i); sort(x, x+n);
		for (int i=0; i<n; ++i) scanf("%d", y+i); sort(y, y+n);
		ll tot = 1;
		for (int i=0,j=0; i<n; ++i) {
			for (; j<n&&x[j]<=y[i]; ++j); --j;
			tot = tot * max(0ll, j + 1ll - i) % MOD;
			if (!tot) break;
		}
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 254050	2013-08-21 19:05:12	 1371 - Energetic Pandas	 C++	 0.060	 1096	Accepted
