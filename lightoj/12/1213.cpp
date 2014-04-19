#include <cstdio>
using namespace std;

typedef long long ll;

ll p(ll x, ll e, ll m) {
	ll r = 1;
	for (x%=m; e; x=x*x%m,e>>=1) if (e & 1) r = r * x % m;
	return r;
}

int main() {
	ll tc, cn = 0, n, k, m;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld%lld", &n, &k, &m);
		ll tot = 0, x;
		for (int i=0; i<n; ++i) scanf("%lld", &x), tot = (tot + x) % m;
		tot = tot * k % m;
		tot = tot * p(n, k-1, m) % m;
		printf("Case %lld: %lld\n", ++cn, tot);
	}
	return 0;
}

// 251586	2013-08-14 18:17:10	 1213 - Fantasy of a Summation	 C++	 0.016	 1088	Accepted
