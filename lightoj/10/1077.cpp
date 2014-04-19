#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ll tc, cn = 0, ax, ay, bx, by, tot;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld%lld%lld", &ax, &ay, &bx, &by);
		ll x = abs(ax - bx), y = abs(ay - by);
		if (x > y) swap(x, y);
		if (x == 0) tot = y + 1;
		else tot = __gcd(x, y) + 1;
		printf("Case %lld: %lld\n", ++cn, tot);
	}
	return 0;
}

// 249388	2013-08-08 22:40:59	 1077 - How Many Points?	 C++	 0.000	 1088	Accepted
