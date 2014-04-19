#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAXN = 1050000;
const ll INF = 0x3f3f3f3f;

bool v[MAXN];
int f[MAXN], mn[MAXN];
pair <int, int> p[MAXN];

void init() {
	for (int i=1; i<MAXN; ++i) p[i].first = p[i].second = i; p[0].first = p[1].first = 0;
	for (int i=2; i<MAXN; ++i) if (!v[i]) {
		--p[i].first;
		for (int j=i<<1; j<MAXN; j+=i) p[j].first -= p[j].first / i, v[j] = true;
	}
	sort(p, p+MAXN);
	for (int i=1; i<MAXN; ++i) mn[i] = INF;
	for (int i=MAXN-2; i>0; --i) mn[i] = min(mn[i+1], p[i].second);
	for (int i=1; i<MAXN; ++i) {
		f[i] = lower_bound(p, p+MAXN, make_pair(i, 0)) - p;
		f[i] = mn[f[i]];
	}
}

int main() {
	init();
	ll tc, cn = 0, n, x;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld", &n);
		ll tot = 0;
		for (ll i=0; i<n; ++i) scanf("%lld", &x), tot += f[x];
		printf("Case %lld: %lld Xukha\n", ++cn, tot);
	}
	return 0;
}

// 251116	2013-08-13 16:13:21	 1370 - Bi-shoe and Phi-shoe	 C++	 0.384	 18520	Accepted
