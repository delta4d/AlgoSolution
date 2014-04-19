#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 86;

double x[MAXN];

void init() {
	for (int i=1; i<MAXN; ++i) x[i] = x[i-1] + log(1.0 * i);
}

int main() {
	init();
	int tc, cn = 0, n, b;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &b);
		double t = x[n] / log(1.0 * b);
		printf("Case %d: %d\n", ++cn, (int)floor(t) + 1);
	}
	return 0;
}

// 249389	2013-08-08 22:42:07	 1045 - Digits of Factorial	 C++	 0.128	 8996	Accepted
