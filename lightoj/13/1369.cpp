#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAXN =100000 + 86;

struct BIT {
	ll x[MAXN+10], n;

	BIT() { n = MAXN; }
	void init(ll _n=MAXN) {
		memset(x, 0, sizeof(x));
		n = _n;
	}
	void add(ll p, ll off) {
		for (ll i=p; i<=n; i+=i&-i) x[i] += off;
	}
	ll sum(ll p) {
		ll ret = 0;
		for (ll i=p; i>0; i-=i&-i) ret += x[i];
		return ret;
	}
} T;

int main() {
	int tc, cn = 0, n, q;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &q);
		T.init(n+5);
		for (ll i=1,x; i<=n; ++i) {
			scanf("%lld", &x);
			T.add(i, (n+1-2*i)*x);
		}
		printf("Case %d:\n", ++cn);
		for (ll op,x,v; q--; ) {
			scanf("%lld", &op);
			if (!op) {
				scanf("%lld%lld", &x, &v), ++x;
				ll ax = T.sum(x) - T.sum(x-1);
				v *= n + 1 - 2 * x;
				T.add(x, v-ax);
			} else {
				printf("%lld\n", T.sum(n));
			}
		}
	}
	return 0;
}

// 253653	2013-08-20 21:02:45	 1369 - Answering Queries	 C++	 0.384	 1868	Accepted
