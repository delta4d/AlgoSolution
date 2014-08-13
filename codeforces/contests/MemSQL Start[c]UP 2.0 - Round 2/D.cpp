#include <bits/stdc++.h>
using namespace std;

using ld = long double;
int const N = 1e5 + 10;

ld lm[N];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<N; ++i) lm[i] = log(i) + lm[i-1];
	ld e = 0;
	for (int x=0; x<=n; ++x) for (int y=0; y<=n; ++y) {
		int z = n * x + n * y - x * y;
		if (z > k) continue;
		ld t = lm[n] + lm[n] + lm[m-z] + lm[k] - lm[n-x] - lm[n-y]- lm[x] - lm[y] - lm[k-z] - lm[m];
		e = min((ld)1e99, e+exp(t));
	}
	printf("%.20lf\n", (double)e);
	return 0;
}

// 7428028	2014-08-11 18:25:04	delta_4d	D - Bingo!	GNU C++0x	Accepted	30 ms	1200 KB
