#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1000000 + 86;

bool v[N];
int sgn[N];
int p[N], c;

void init() {
	fill(sgn, sgn+N, 1);
	for (ll i=2,i2; i<N; ++i) if (!v[i]) {
		sgn[i] = -1, i2 = i * i;
		for (ll j=i2; j<N; j+=i2) sgn[j] = 0;
		for (ll j=i<<1; j<N; j+=i) v[j] = true, sgn[j] = -sgn[j];
	}
	p[0] = 1, sgn[0] = 1, c = 1;
	for (ll i=2; i<N; ++i) if (sgn[i]) p[c] = i, sgn[c++] = sgn[i];
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n, m, tot;
		scanf("%lld%lld", &m, &n);
		if (m > n) swap(m, n);
		tot = !!m + !!n;
		for (int i=0; i<c&&p[i]<=m; ++i) tot += sgn[i] * (m / p[i]) * (n / p[i]);
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 256604	2013-08-27 22:59:36	 1144 - Ray Gun	 C++	 0.452	 9876	Accepted
