#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 1000100;

bool v[MAXN];
ll p[MAXN/10], c;
ll x[MAXN/10], r[MAXN];

void init() {
	for (ll i=2; i<MAXN; ++i) if (!v[i]) {
		p[c++] = i, r[i] = c - 1;
		for (ll j=i*i; j<MAXN; j+=i) v[j] = true;
	}
}

int main() {
	init();
	ll tc, cn = 0, n, a, b, c, L;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld%lld", &a, &b, &L);
		a = a / __gcd(a, b) * b, c = 1;
		if (L % a) {
			printf("Case %lld: impossible\n", ++cn);
			continue;
		}
		memset(x, 0, sizeof(x));
		for (int i=0; p[i]*p[i]<=a; ++i) if (a % p[i] == 0) {
			for (; a%p[i]==0; a/=p[i],++x[i]);
		}
		if (a != 1) ++x[r[a]];
		for (int i=0; p[i]*p[i]<=L; ++i) if (L % p[i] == 0) {
			ll t = 0, xx = 1;
			for (; L%p[i]==0; L/=p[i],xx*=p[i],++t);
			if (x[i] < t) c *= xx;
		}
		if (L != 1 && x[r[L]] < 1) c *= L; 
		printf("Case %lld: %lld\n", ++cn, c);
	}
	return 0;
}

// 249382	2013-08-08 22:29:28	 1215 - Finding LCM	 C++	 0.036	 11440	Accepted 
