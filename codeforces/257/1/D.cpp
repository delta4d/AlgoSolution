#include <bits/stdc++.h>
using namespace std;

int const M = 1e9 + 7;
int const N = 1 << 20;

int f[N], p[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0,a; i<n; ++i) scanf("%d", &a), ++f[a];
	for (int i=19; i>=0; --i) for (int j=0; j<N; ++j) {
		if (j & 1 << i) f[j^1<<i] += f[j];
	}
	p[0] = 1;
	for (int i=1; i<N; ++i) p[i] = (p[i-1] << 1) % M;
	int tot = p[n] - 1;
	for (int i=1; i<N; ++i) {
		int k = __builtin_popcount(i), sgn = (k&1)?-1:1;
		tot = (tot + sgn * (p[f[i]] - 1)) % M;
	}
	if (tot < 0) tot += M;
	printf("%d\n", tot);
	return 0;
}

// 7187255	2014-07-20 18:39:03	delta_4d	D - Jzzhu and Numbers	GNU C++0x	Accepted	234 ms	8200 KB
