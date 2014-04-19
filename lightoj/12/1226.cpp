#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll N = 1000000 + 86;
const ll M = 1000000007;

int f[N], r[N];

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
	f[0] = r[0] = 1;
	for (ll i=1; i<N; ++i) f[i] = i * f[i-1] % M;
	r[N-1] = mod_inv(f[N-1], M);
	for (ll i=N-2; i>0; --i) r[i] = (i + 1) * r[i + 1] % M;
}

ll C(ll n, ll k) {
	if (n < k || n <= 0 || k < 0) return 0;
	return (1ll * r[k] * r[n-k] % M) * f[n] % M;
}

int main() {
	init();
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		ll s = 0, k, tot = 1;
		scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			scanf("%lld", &k);
			tot = tot * C(k+s-1, s) % M;
			s += k;
		}
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 256870	2013-08-28 16:42:23	 1226 - One Unit Machine	 C++	 0.064	 8900	Accepted
