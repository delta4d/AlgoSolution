#include <cmath>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n, m, x, y;
		scanf("%lld", &n);
		m = sqrt(n * 1.0);
		for (; ; ++m) if (m * m >= n && (m - 1) * (m - 1) < n) break;
		ll r = m * m - n;
		if (m & 1) {
			if (r < m) x = m, y = r + 1;
			else x = 2 * m - r - 1, y = m;
		} else {
			if (r < m) x = r + 1, y = m;
			else x = m, y = 2 * m - r - 1;
		}
		printf("Case %d: %lld %lld\n", ++cn, y, x);
	}
	return 0;
}

// 252295	2013-08-16 20:41:47	 1008 - Fibsieve`s Fantabulous Birthday	 C++	 0.000	 1100	Accepted
