#include <cstdio>
using namespace std;

const int N = 100000 + 86;

double f[N];

void init() {
	for (int i=1; i<N; ++i) f[i] = f[i-1] + 1.0 / i;
	for (int i=1; i<N; ++i) f[i] *= i;
}

int main() {
	init();
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		printf("Case %d: %.10lf\n", ++cn, f[n]);
	}
	return 0;
}

// 254630	2013-08-23 01:41:17	 1248 - Dice (III)	 C++	 0.004	 1868	Accepted
