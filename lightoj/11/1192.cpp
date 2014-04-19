#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		ll t = 0, x, y;
		for (int i=0; i<n; ++i) {
			scanf("%lld%lld", &x, &y);
			t ^= y - x - 1;
		}
		printf("Case %d: %s\n", ++cn, t?"Alice":"Bob");
	}
	return 0;
}

// 257732	2013-08-30 23:55:39	 1192 - Left Right	 C++	 0.008	 1088	Accepted
