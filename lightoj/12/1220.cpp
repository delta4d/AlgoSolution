#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

inline ll sgn(ll p, ll s) {
	if (s == 1) return 1;
	return p % 2 ? 1 : -1;
}

ll f(ll x, ll e) {
	ll r = 1;
	for (; e; e>>=1,x*=x) if (e & 1) r *= x;
	return r;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll x, b, p, s = 1;
		scanf("%lld", &x);
		if (x < 0) s = -1, x = -x;
		for (p=60; p>1; --p) {
			b = pow(1.0*x, 1.0/p);
			bool ok = false;
			for (int i=-1; i<=1; ++i) if (f(b+i, p) == sgn(p, s) * x) {
				ok = true;
				break;
			}
			if (ok) break;
		}
		printf("Case %d: %lld\n", ++cn, p);
	}
	return 0;
}

// 251583	2013-08-14 18:12:45	 1220 - Mysterious Bacteria	 C++	 0.000	 1268	Accepted
