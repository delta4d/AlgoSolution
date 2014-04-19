#include <cstdio>
using namespace std;

typedef long long ll;

ll p[20], r[20];

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

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%lld%lld", p+i, r+i);
		ll M = 1, T = 0;
		for (int i=0; i<n; ++i) M *= p[i];
		for (int i=0; i<n; ++i) {
			ll MR = M / p[i] * mod_inv(M/p[i], p[i]);
			T = (T + MR * r[i]) % M;
		}
		printf("Case %d: %lld\n", ++cn, T);
	}
	return 0;
}

// 253381	2013-08-19 21:34:24	 1319 - Monkey Tradition	 C++	 0.040	 1088	Accepted
