#include <cstdio>
using namespace std;

int main() {
	long long tc, cn = 0, x;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld", &x);
		long long p = __builtin_ctz(x);
		if (p == 0) printf("Case %lld: Impossible\n", ++cn);
		else printf("Case %lld: %lld %lld\n", ++cn, x>>p, 1ll<<p);
	}
	return 0;
}

// 252162	2013-08-16 11:12:41	 1116 - Ekka Dokka	 C++	 0.008	 1088	Accepted
