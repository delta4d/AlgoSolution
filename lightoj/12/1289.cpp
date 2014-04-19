#include <bitset>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
const int MAXN = 100000000 + 1;
const int P = 5761455 + 10;

bitset <MAXN> v;
uint p[P], pp[P], c;

void init() {
	for (ll i=2; i<MAXN; ++i) if (!v.test(i)) {
		p[c++] = i;
		for (ll j=i*i; j<MAXN; j+=i) v.set(j);
	}
	pp[0] = p[0];
	for (int i=1; i<c; ++i) pp[i] = pp[i-1] * p[i];
}

int main() {
	init();
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		uint tot = pp[upper_bound(p, p+c, n) - p - 1];
		for (int i=0; p[i]*p[i]<=n; ++i) {
			ll x = p[i];
			for (; x<=n; x*=p[i]);
			x /= p[i];
			uint y = (uint)x;
			if (y % p[i] == 0) tot *= y / p[i];
		}
		printf("Case %d: %u\n", ++cn, tot);
	}
	return 0;
}

// 251245	2013-08-13 20:47:46	 1289 - LCM from 1 to n	 C++	 1.660	 58304	Accepted
