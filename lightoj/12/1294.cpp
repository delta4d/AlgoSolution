#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n, m;
		scanf("%lld%lld", &n, &m);
		printf("Case %d: %lld\n", ++cn, n/2*m);
	}
	return 0;
}

// 252276	2013-08-16 19:49:16	 1294 - Positive Negative Sign	 C++	 0.008	 1088	Accepted
