#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll N = 100000 + 86;

bool v[N];
int p[N], c;
int f[10], t;
int cnt[N], sgn[N];
ll C[N];

void init() {
	for (ll i=2; i<N; ++i) if (!v[i]) {
		p[c++] = i;
		for (ll j=i*i; j<N; j+=i) v[j] = true;
	}
	for (ll i=4; i<N; ++i) C[i] = i * (i - 1) / 2 * (i - 2) / 3 * (i - 3) / 4;
}

int main() {
	init();
	int tc, cn = 0, n, x, mx;
	for (scanf("%d", &tc); tc--; ) {
		mx = 0;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			scanf("%d", &x);
			t = 0;
			for (int j=0; p[j]*p[j]<=x; ++j) if (x % p[j] == 0) {
				f[t++] = p[j];
				for (x/=p[j]; x%p[j]==0; x/=p[j]);
			}
			if (x != 1) f[t++] = x;
			for (int m=1,ms=1<<t; m<ms; ++m) {
				int cm = 1, cc = __builtin_popcount(m);
				for (int j=0; j<t; ++j) if (m & 1 << j) cm *= f[j];
				++cnt[cm], sgn[cm] = (cc & 1) ? -1 : 1;
				mx = max(mx, cm);
			}
		}
		ll tot = C[n];
		for (int i=1; i<=mx; ++i) tot += sgn[i] * C[cnt[i]];
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 255852	2013-08-25 20:08:21	 1161 - Extreme GCD	 C++	 0.032	 3140	Accepted
