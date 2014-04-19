#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll x[32], y[32];

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n, k, tot = 1;
		scanf("%lld%lld", &n, &k);
		printf("Case %d: ", ++cn);
		if (n < k) {
			puts("0");
		} else {
			for (ll i=0,m=n*n,r=0,cc=2*n-1; i<k; ++i,r+=cc,cc-=2) x[i] = m - r, y[i] = i + 1;
			for (int i=0; i<k; ++i) for (int j=0; j<k; ++j) {
				ll d = __gcd(x[i], y[j]);
				x[i] /= d, y[j] /= d;
			}
			for (int i=0; i<k; ++i) tot *= x[i];
			printf("%lld\n", tot);
		}
	}
	return 0;
}

// 253394	2013-08-19 22:11:21	 1005 - Rooks	 C++	 0.000	 1088	Accepted
