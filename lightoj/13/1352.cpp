#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1 << 7;
const ll R[] = {0, 1, 0, 3};

ll p, q;
ll x[N], s2[N];
ll pre[N], suf[N];

void init() {
	s2[1] = 1, s2[2] = 3;
	for (int i=3; i<64; ++i) s2[i] = s2[i-1] << 1;
}

ll b2(ll n) {
	int len = 1;
	do { x[len++] = !!(n & 1), n >>= 1; } while (n); --len;
	for (int i=1; i+i<=len; ++i) swap(x[i], x[len-i+1]);
	suf[len+1] = 0;
	for (int i=1; i<=len; ++i) pre[i] = (pre[i-1] << 1) + x[i];
	for (int i=len; i>=1; --i) suf[i] = suf[i+1] + (x[i] << (len - i));
	return len;
}

ll gao(ll n) {
	if (n < 4) return R[n];
	ll cnt[N] = {0};
	n = b2(n);
	for (int i=1; i<=n; ++i) {
		ll pn = pre[i-1], sn = suf[i+1] + 1;
		if (pn) pn ^= 1ll << (i - 2);
		cnt[i] += pn * (1ll << (n - i));
		if (x[i] == 1) cnt[i] += sn;
	}
	ll ret = 0;
	for (int i=1; i<=n; ++i) ret = (ret << 1) + !!(cnt[i] & 1);
	ret ^= s2[n];
	return ret;
}

ll L(ll n) {
	ll ret = 0;
	do { ++ret, n >>= 1; } while (n);
	return ret;
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%lld%lld", &p, &q);
		printf("Case %d: %lld\n", ++cn, (gao(p-1) << (L(q) - L(p-1))) ^ gao(q));
	}
	return 0;
}

// 298894	2013-12-12 21:23:53	 1352 - Strange Summation	 C++	 0.024	 1092	Accepted
