#include <cstdio>
using namespace std;

typedef long long ll;
const ll MAXN = 1100000;

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
	ll tc, cn = 0, n;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld", &n);
		ll tot = 1;
		for (ll i=0; p[i]*p[i]<=n; ++i) if (n % p[i] == 0) {
			ll t = 0;
			for (; n%p[i]==0; ++t,n/=p[i]);
			tot *= t + 1;
		}
		if (n != 1) tot <<= 1;
		--tot;
		printf("Case %lld: %lld\n", ++cn, tot);
	}
	return 0;
}

// 249374	2013-08-08 21:41:01	 1028 - Trailing Zeroes (I)	 C++	 0.440	 10756	Accepted
