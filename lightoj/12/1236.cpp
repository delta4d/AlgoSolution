#include <cstdio>
using namespace std;

typedef long long ll;
const int MAXN = 10000000 + 86;

bool v[MAXN];
ll p[MAXN/10], c;

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
		for (int i=0; p[i]*p[i]<=n; ++i) if (n % p[i] == 0) {
			ll t = 0;
			for (; n%p[i]==0; n/=p[i],++t);
			tot *= 2 * t + 1;
		}
		if (n != 1) tot *= 3;
		tot = (tot + 1) >> 1;
		printf("Case %lld: %lld\n", ++cn, tot);
	}
	return 0;
}

// 249647	2013-08-09 14:07:37	 1236 - Pairs Forming LCM	 C++	 0.484	 18664	Accepted
