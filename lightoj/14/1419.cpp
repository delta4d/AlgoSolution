#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}	
	ll ret = ext_gcd(b, a%b, x, y);
	ll t = x;
	x = y, y = t - a / b * y;
	return ret;
}

ll mod_inv(ll a, ll n) {
	ll x, y;
	ext_gcd(a, n, x, y);
	x %= n;
	if (x < 0) x += n;
	return x;
}

ll pm(ll x, ll e) {
	ll r = 1;
	for (x%=MOD; e; e>>=1,x=x*x%MOD) if (e & 1) r = r * x % MOD;
	return r;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n, k, tot = 0;
		scanf("%lld%lld", &n, &k);
		for (ll i=1; i<=n; ++i) tot = (tot + pm(k, __gcd(n, i))) % MOD;
		printf("Case %d: %lld\n", ++cn, tot*mod_inv(n,MOD)%MOD);
	}
	return 0;
}

// 253333	2013-08-19 19:31:47	 1419 - Necklace	 C++	 0.036	 1088	Accepted
