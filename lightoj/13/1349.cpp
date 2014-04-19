#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct node {
	ll u, v, w;
	node(ll _u=0, ll _v=0, ll _w=0):u(_u), v(_v), w(_w) {}
} f[50000+86];

bool cmpx(const node &a, const node &b) {
	return a.u < b.u;
}

bool cmpy(const node &a, const node &b) {
	return a.v < b.v;
}

ll gao(ll q, ll n) {
	ll cc = 0;
	for (ll i=0; i<q; ++i) {
		cc += f[i].w;
		if (cc * 2 >= n) return i;
	}
}

ll sum(ll c, ll k, ll q) {
	ll ret = 0, cc = c ? f[k].v : f[k].u;
	for (ll i=0; i<q; ++i) ret += f[i].w * abs((c ? f[i].v : f[i].u) - cc);
	return ret;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll q, u, v, w, n = 0, x, y;
		scanf("%*lld%*lld%lld", &q);
		for (ll i=0; i<q; ++i) {
			scanf("%lld%lld%lld", &u, &v, &w);
			f[i] = node(u, v, w);
			n += w;
		}
		sort(f, f+q, cmpx);
		x = gao(q, n);
		if (x + 1 < q && sum(0, x, q) > sum(0, x+1, q)) ++x;
		x = f[x].u;
		sort(f, f+q, cmpy);
		y = gao(q, n);
		if (y + 1 < q && sum(1, y, q) > sum(1, y+1, q)) ++y;
		y = f[y].v;
		printf("Case %d: %lld %lld\n", ++cn, x, y);
	}
	return 0;
}

// 253539	2013-08-20 13:39:15	 1349 - Aladdin and the Optimal Invitation	 C++	 0.660	 2264	Accepted
