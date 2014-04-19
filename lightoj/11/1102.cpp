#include <cstdio>
using namespace std;

typedef long long ll;
const int MAXN = 2000000 + 86;
const int MOD = 1000000007;

ll x[MAXN], y[MAXN];

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

void init() {
	x[0] = y[0] = 1;
	for (int i=1; i<MAXN; ++i) x[i] = i * x[i-1] % MOD;
	y[MAXN-1] = mod_inv(x[MAXN-1], MOD);
	for (int i=MAXN-2; i>0; --i) y[i] = (i + 1) * y[i+1] % MOD;
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n, k, tot = 0;
		scanf("%lld%lld", &n, &k);
		n += --k;
		if (n - k < k) k = n - k;
		tot = x[n] * (y[k] * y[n-k] % MOD) % MOD;
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 253228	2013-08-19 14:58:10	 1102 - Problem Makes Problem	 C++	 0.100	 32340	Accepted
