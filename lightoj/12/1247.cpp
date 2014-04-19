#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	int tc, cn = 0, m, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &m, &n);
		ll t = 0, x;
		for (int i=0; i<m; ++i) {
			ll cc = 0;
			for (int j=0; j<n; ++j) scanf("%lld", &x), cc += x;
			t ^= cc;
		}
		printf("Case %d: %s\n", ++cn, t?"Alice":"Bob");
	}
	return 0;
}

// 257730	2013-08-30 23:43:48	 1247 - Matrix Game	 C++	 0.036	 1088	Accepted
