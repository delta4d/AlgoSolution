#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		ll x1=-INF, x2=INF, y1=-INF, y2=INF, z1=-INF, z2=INF;
		ll cx1, cx2, cy1, cy2, cz1, cz2;
		while (n--) {
			scanf("%lld%lld%lld%lld%lld%lld", &cx1, &cy1, &cz1, &cx2, &cy2, &cz2);
			x1 = max(x1, cx1), x2 = min(x2, cx2);
			y1 = max(y1, cy1), y2 = min(y2, cy2);
			z1 = max(z1, cz1), z2 = min(z2, cz2);
		}
		ll x = max(x2 - x1, 0ll), y = max(y2 - y1, 0ll), z = max(z2 - z1, 0ll);
		printf("Case %d: %lld\n", ++cn, x*y*z);
	}
	return 0;
}

// 252469	2013-08-17 11:27:15	 1211 - Intersection of Cubes	 C++	 0.004	 1088	Accepted
