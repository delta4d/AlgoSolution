#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 100000007;
const ll MAXN = 1000000 + 86;

ll y[10];
ll f[MAXN], rf[MAXN];

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
	f[0] = rf[0] = 1;
	for (int i=1; i<MAXN; ++i) rf[i] = f[i] = f[i-1] * i % MOD;
	rf[MAXN-1] = mod_inv(f[MAXN-1], MOD);
	for (int i=MAXN-2; i>0; --i) rf[i] = rf[i+1] * (i + 1) % MOD;
}

ll C(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	ll ret = rf[n-k] * rf[k] % MOD;
	ret = ret * f[n] % MOD;
	return ret;
}

ll gao(const ll k, ll n) {
	ll tot = 0;
	for (ll m=0,ms=1<<k; m<ms; ++m) {
		ll nn = n, cc = __builtin_popcount(m) % 2;
		for (ll i=0; i<k; ++i) if (m & 1 << i) nn -= y[i];
		tot = (tot + (cc ? -1 : 1) * C(nn-1, k-1)) % MOD;
//		printf("C(%lld,%lld)=%lld\n", nn-1, k-1, C(nn-1,k-1));
	}
	if (tot < 0) tot += MOD;
	return tot;
}

int main() {
	init();
	int tc, cn = 0, k, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &k, &n);
		for (int i=0,a,b; i<k; ++i) {
			scanf("%d%d", &a, &b);
			y[i] = b - a + 1;
			n -= a - 1;
		}
		printf("Case %d: %lld\n", ++cn, gao(k, n));
	}
	return 0;
}

// 256616	2013-08-27 23:26:01	 1124 - Cricket Ranking	 C++	 0.040	 16712	Accepted
