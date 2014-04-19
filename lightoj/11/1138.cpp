#include <cstdio>
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

inline ll gao(ll n, ll x) {
	ll tot = 0;
	for (; n; tot+=n/=x);
	return tot;
}

int main() {
	ll tc, cn = 0, q;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld", &q);
		ll left = 1, right = INF, mid, x = -1;
		while (left <= right) {
			mid = (left + right) >> 1;
			ll cc = gao(mid, 5);
			if (cc < q) left = mid + 1;
			else if (cc > q) right = mid - 1;
			else x = mid, right = mid - 1;
		}
		printf("Case %lld: ", ++cn);
		if (x == -1) puts("impossible");
		else printf("%lld\n", x);
	}
	return 0;
}

// 249387	2013-08-08 22:39:10	 1138 - Trailing Zeroes (III)	 C++	 0.052	 1088	Accepted
