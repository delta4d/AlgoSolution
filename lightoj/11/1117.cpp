#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll x[16];

int main() {
	int tc, cn = 0, m;
	for (scanf("%d", &tc); tc--; ) {
		ll n, tot = 0;
		scanf("%lld%d", &n, &m);
		for (int i=0; i<m; ++i) scanf("%lld", x+i);
		for (ll i=0,ms=1ll<<m; i<ms; ++i) {
			ll k = __builtin_popcount(i), cc = 1;
			for (ll j=0; j<m; ++j) if (i & 1ll << j) {
				cc = cc / __gcd(cc, x[j]) * x[j];
				if (cc > n) break;
			}
			tot += ((k & 1) ? -1 : 1) * (n / cc);
		}
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 256583	2013-08-27 22:22:04	 1117 - Helping Cicada	 C++	 0.140	 1088	Accepted
