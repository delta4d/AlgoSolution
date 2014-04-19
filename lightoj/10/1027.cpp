#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		ll a = 0, c = 0, x;
		scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			scanf("%lld", &x);
			if (x > 0) a += x, ++c;
			else a -= x;
		}
		printf("Case %d: ", ++cn);
		if (!c) {
			puts("inf");
		} else {
			ll d = __gcd(a, c);
			a /= d, c /= d;
			printf("%lld/%lld\n", a, c);
		}
	}
	return 0;
}

// 254608	2013-08-23 00:15:51	 1027 - A Dangerous Maze	 C++	 0.000	 1088	Accepted
