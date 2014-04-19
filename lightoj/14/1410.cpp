#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 700 * 700 + 86;

ll d[MAXN];
ll x[700], y[700];

inline ll dis(int a, int b) {
	return (x[a]- x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%lld%lld", x+i, y+i);
		int c = 0;
		for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) d[c++] = dis(i, j);
		sort(d, d+c);
		c = unique(d, d+c) - d;
		printf("Case %d: %d\n", ++cn, c+1);
	}
	return 0;
}

// 254008	2013-08-21 17:42:17	 1410 - Consistent Verdicts	 C++	 2.620	 4928	Accepted
