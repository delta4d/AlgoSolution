#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 1 << 11;

int x[MAXN];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d", x+i);
		sort(x, x+n);
		ll tot = 0;
		for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
			int cc = x[i] + x[j];
			ll k = lower_bound(x+j+1, x+n, cc) - (x + j + 1);
			tot += max(k, 0ll);
		}
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 257653	2013-08-30 19:46:00	 1307 - Counting Triangles	 C++	 0.596	 1096	Accepted
