#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	ll tc, cn = 0, n;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld", &n);
		ll tot = 0;
		if (n / 2 >= 2) tot -= (2 + n / 2) * (n / 2 - 1) / 2;
		for (ll x=2; x*x<=n; ++x) {
			ll a = (n + x + 1) / (x + 1), b = n / x;
			if (a == b && x == a) tot -= x * x;
			tot += (a + b) * (b - a + 1) / 2 * x + n / x * x;
		}
		printf("Case %lld: %lld\n", ++cn, tot);
	}
	return 0;
}

// 251569	2013-08-14 17:59:52	 1098 - A New Function	 C++	 1.152	 1088	Accepted
