#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		ll t = 0, c = 0, x;
		for (int i=0; i<n; ++i) {
			scanf("%lld", &x);
			t ^= x;
			c += x > 1;
		}
		(c == 0) && (t &= 1, t ^= 1);
		printf("Case %d: %s\n", ++cn, t?"Alice":"Bob");
	}
	return 0;
}

// 257728	2013-08-30 23:32:55	 1253 - Misere Nim	 C++	 0.004	 1088	Accepted
