#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n, cc = 0;
		scanf("%lld", &n);
		for (int i=0; ; ++i) {
			if ((n & 1ll << i) && !(n & 1ll << (i + 1))) {
				n |= 1ll << (i + 1);
				for (int j=0; j<=i; ++j) n &= ~(1ll << j);
				for (int j=0; j<cc; ++j) n |= 1ll << j;
				break;
			}
			if (n & 1 << i) ++cc;
		}
		printf("Case %d: %lld\n", ++cn, n);
	}
	return 0;
}

// 252577	2013-08-17 19:01:16	 1042 - Secret Origins	 C++	 0.000	 1088	Accepted
