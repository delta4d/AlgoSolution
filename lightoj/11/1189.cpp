#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll x[30];
ll p[30];

void init() {
	x[0] = 1;
	for (int c=1; c<22; ++c) x[c] = x[c-1] * c;
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n, c = 0, d = 22;
		scanf("%lld", &n);
		while (n > 0 && d > 0) {
			int k = upper_bound(x, x+d, n) - x - 1;
			n -= x[k];
			p[c++] = k;
			d = k;
		}
		printf("Case %d: ", ++cn);
		if (n == 0) for (int i=c-1; i>=0; --i) printf("%lld!%s", p[i], i?"+":"\n");
		else puts("impossible");
	}
	return 0;
}

// 253006	2013-08-18 21:23:24	 1189 - Sum of Factorials	 C++	 0.012	 1088	Accepted
