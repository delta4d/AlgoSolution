#include <cstdio>
using namespace std;

typedef long long ll;
const int MAXN = 1100000;

bool v[MAXN];
ll p[MAXN], c;

void init() {
	for (ll i=2; i<MAXN; ++i) if (!v[i]) {
		p[c++] = i;
		for (ll j=i*i; j<MAXN; j+=i) v[j] = true;
	}
}

int main() {
	init();
	ll tc, cn = 0, n, x;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld", &n, &x);
		ll tot = 0, m = n;
		if (x * x <= n) {
			tot = 1;
			for (ll i=0; p[i]*p[i]<=n; ++i) if (n % p[i] == 0) {
				ll t = 0;
				for (; n % p[i] == 0; n /= p[i], ++t);
				tot *= t + 1;
			}
			if (n != 1) tot <<= 1;
			tot >>= 1;
			for (ll i=1; i<x; ++i) if (m % i == 0)  --tot;
		}
		printf("Case %lld: %lld\n", ++cn, tot);
	}
	return 0;
}

// 251175	2013-08-13 18:27:30	 1341 - Aladdin and the Flying Carpet	 C++	 0.472	 10756	Accepted
