#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll N = 110000 + 86;
const ll MAXN = N * N;
const ll MOD = 100000007;

bool v[N];
ll p[N], c;
ll f[N], r[N];

void init() {
	for (ll i=2; i*i<MAXN; ++i) if (!v[i]) {
		for (ll j=i*i; j<MAXN; j*=i) {
			if (j < N) v[j] = true;
			p[c++] = j;
		}
	}
	sort(p, p+c);
	r[1] = 1;
	for(ll i=2; i<N; ++i) r[i] = r[MOD % i] * (MOD - MOD / i) % MOD;
	f[0] = 1;
	for (ll i=1; i<N; ++i) f[i] = (f[i-1] * (4 * i - 2) % MOD) * r[i + 1] % MOD;
	f[0] = 0;
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		ll n = upper_bound(p, p+c, b) - lower_bound(p, p+c, a);
		printf("Case %d: %lld\n", ++cn, f[n]);
	}
	return 0;
}

// 256830	2013-08-28 15:19:02	 1170 - Counting Perfect BST	 C++	 0.048	 3776	Accepted
