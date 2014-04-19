#include <cstdio>
using namespace std;

typedef long long ll;
const int MAXN = 10000100;

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
	ll tc, cn = 0, n, tot;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld", &n);
		for (; !(n&1); n>>=1);
		tot = 1;
		for (int i=0; p[i]*p[i]<=n; ++i) if (n % p[i] == 0) {
			ll t = 0;
			for (; n % p[i] == 0; n /= p[i], ++t);
			tot *= t + 1;
		}
		if (n != 1) tot <<= 1;
		printf("Case %lld: %lld\n", ++cn, tot-1);
	}
	return 0;
}

// 249380	2013-08-08 22:16:59	 1278 - Sum of Consecutive Integers	 C++	 0.420	 18664	Accepted
