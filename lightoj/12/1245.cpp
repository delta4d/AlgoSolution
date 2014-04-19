#include <cmath>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	ll tc, cn = 0, n;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld", &n);
		ll m = (ll)floor(sqrt(1.0 * n)), tot = 0;
		for (int i=1; i<=m; ++i) tot += n / i;
		tot <<= 1;
		printf("Case %lld: %lld\n", ++cn, tot-m*m);
	}
	return 0;
}

// 249657	2013-08-09 14:19:05	 1245 - Harmonic Number (II)	 C++	 0.476	 1100	Accepted
