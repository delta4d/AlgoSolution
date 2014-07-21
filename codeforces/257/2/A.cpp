#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, mx = 0, idx = 0;
	scanf("%d%d", &n, &m);
	for (int i=0,a; i<n; ++i) {
		scanf("%d", &a);
		int cc = (a + m - 1) / m;
		if (cc >= mx) mx = cc, idx = i + 1;
	}
	printf("%d\n", idx);
	return 0;
}

// 7176895	2014-07-19 20:41:24	delta_4d	A - Jzzhu and Children	GNU C++0x	Accepted	31 ms	0 KB
