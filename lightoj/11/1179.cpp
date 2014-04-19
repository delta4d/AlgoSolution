#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n, k, x = 0;
		scanf("%lld%lld", &n, &k);
		for (ll i=2; i<=n; ++i) {
			x = (x + k) % i;
		}
		printf("Case %d: %lld\n", ++cn, x+1);
	}
	return 0;
}

// 253639	2013-08-20 20:34:28	 1179 - Josephus Problem	 C++	 0.096	 1088	Accepted
