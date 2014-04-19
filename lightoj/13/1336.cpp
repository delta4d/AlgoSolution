#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAXN = 1e12 + 1e10;

ll x[3431213 + 100], c;

void init() {
	for (ll i=1; i*i<=MAXN; ++i) {
		for (ll j=i*i; j<=MAXN; j<<=1) x[c++] = j;
	}
	sort(x, x+c);
	c = unique(x, x+c) - x;
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n;
		scanf("%lld", &n);
		ll tot = n - (ll)(upper_bound(x, x+c, n) - x);
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 251624	2013-08-14 19:21:55	 1336 - Sigma Function	 C++	 0.360	 27892	Accepted
