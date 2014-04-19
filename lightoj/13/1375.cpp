#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long llu;
const llu MAXN = 3000000 + 86;

bool v[MAXN];
llu phi[MAXN], f[MAXN];

void init() {
	for (llu i=2; i<MAXN; ++i) phi[i] = i;
	for (llu i=2; i<MAXN; ++i) if (!v[i]) {
		phi[i] = i - 1;
		for (llu j=i<<1; j<MAXN; j+=i) v[j] = true, phi[j] -= phi[j] / i;
	}
	for (llu i=2; i<MAXN; ++i) {
		phi[i] = i * phi[i] / 2;
		for (llu j=i; j<MAXN; j+=i) f[j] += phi[i];
	}
	for (llu i=2; i<MAXN; ++i) f[i] *= i, f[i] += f[i-1];
}

int main() {
	init();
	llu tc, cn = 0, n;
	for (scanf("%llu", &tc); tc--; ) {
		scanf("%llu", &n);
		printf("Case %llu: %llu\n", ++cn, f[n]);
	}
	return 0;
}

// 251075	2013-08-13 14:23:09	 1375 - LCM Extreme	 C++	 1.060	 50892	Accepted
