#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1 << 10;
const ll M = 2000000000 + 86;

int x[N], y[N];
ll z[N*N], p;

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d%d", x+i, y+i);
		p = 0;
		for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
			ll cc = (x[i] + x[j]) * M + (y[i] + y[j]);
			z[p++] = cc;
		}
		sort(z, z+p); z[p] = -1;
		ll tot = 0, cc = 1;
		for (int i=0; i<p; ++i) {
			if (z[i] != z[i+1]) tot += cc * (cc - 1) >> 1, cc = 1;
			else ++cc;
		}
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 255803	2013-08-25 18:35:30	 1058 - Parallelogram Counting	 C++	 0.436	 9288	Accepted
