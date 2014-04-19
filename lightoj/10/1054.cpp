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

ll p(ll x, ll e) {
	ll r = 1;
	for (x%=MOD; e; e>>=1,x=x*x%MOD) if (e & 1) r = r * x % MOD;
	return r;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n, m, tot = 1;
		scanf("%lld%lld", &n, &m);
		for (ll i=2; i*i<=n; ++i) if (n % i == 0) {
			ll t = 0;
			for (; n%i==0; n/=i,++t);
			t *= m;
			tot = tot * (p(i, t+1) - 1) % MOD;
			tot = tot * mod_inv(i-1, MOD) % MOD;
		}
		if (n != 1) tot = tot * (p(n, m+1) - 1) % MOD, tot = tot * mod_inv(n-1, MOD) % MOD;
		if (tot < 0) tot += MOD;
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 251587	2013-08-14 18:28:48	 1054 - Efficient Pseudo Code	 C++	 0.256	 1088	Accepted
