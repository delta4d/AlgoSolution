#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll phi(ll n) {
	ll m = n;
	for (ll i=2; i*i<=m; ++i) if (m % i == 0) {
		n -= n / i;
		for (m/=i; m%i==0; m/=i);
	}
	if (m > 1) n -= n / m;
	return n;
}

ll f(ll x, ll e, ll m) {
	ll r = 1;
	for (x%=m; e; x=x*x%m,e>>=1) if (e & 1) r = r * x % m;
	return r;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n, k;
		scanf("%lld%lld", &n, &k);
		n *= 9;
		n /= __gcd(n, k);
		ll p = phi(n), mn = p;
		for (ll i=1; i*i<=p; ++i) if (p % i == 0) {
			if (f(10, i, n) == 1) {
				mn = i;
				break;
			}
			if (f(10, p/i, n) == 1) mn = p / i;
		}
		printf("Case %d: %lld\n", ++cn, mn);
	}
	return 0;
}

// 253668	2013-08-20 21:54:59	 1078 - Integer Divisibility	 C++	 0.008	 1088	Accepted
