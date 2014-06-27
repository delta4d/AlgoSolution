#include <bits/stdc++.h>
using namespace std;

int d[10000];

int main() {
#ifdef ONLINE_JUDGE
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=0,a,b; i<m; ++i) {
		scanf("%d%d", &a, &b);
		++d[a-1], ++d[b-1];
	}
	long long tot = 0;
	for (int i=0; i<n; ++i) tot += d[i] * d[i];
	printf("%I64d\n", tot);
	return 0;
}

// 6959401	 2014-06-25 22:20:15	delta_4d	 D - Matrix Multiplication	 GNU C++0x	Accepted	92 ms	224 KB
