#include <cstdio>
using namespace std;

typedef long long ll;
const int M = 1000003;

ll x[M], y[M];

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
	x[0] = 1, y[0] = 1;
	for (int i=1; i<M; ++i) x[i] = i * x[i-1] % M;
	for (int i=1; i<M; ++i) y[i] = mod_inv(x[i], M);
}

int main() {
	init();
	ll tc, cn = 0, n, k;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld", &n, &k);
		ll cc = x[n] * y[k] % M;
		cc = cc * y[n - k] % M;
		printf("Case %lld: %lld\n", ++cn, cc);
	}
	return 0;
}

// 249745	2013-08-09 18:16:42	 1067 - Combinations	 C++	 0.428	 16712	Accepted
