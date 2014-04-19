#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 100000 + 86;
const int MOD = 10000019;

bool v[MAXN];
int p[MAXN], c;

void init() {
	for (ll i=2; i<MAXN; ++i) if (!v[i]) {
		p[c++] = i;
		for (ll j=i*i; j<MAXN; j+=i) v[j] = true;
	}
}

int gao(ll n, ll x) {
	int r = 0;
	for (ll t=x; t<=n; t*=x) r += n / t;
	return r;
}

int main() {
	init();
	int tc, cn = 0, n, t;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &t);
		ll tot = 1;
		for (int i=0; i<c; ++i) {
			ll cc = gao(n, p[i]), k = cc / t;
			for (int j=0; j<k; ++j) tot = tot * p[i] % MOD;
		}
		if (tot == 1) tot = -1;
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 251391	2013-08-14 08:45:05	 1340 - Story of Tomisu Ghost	 C++	 1.208	 1576	Accepted
