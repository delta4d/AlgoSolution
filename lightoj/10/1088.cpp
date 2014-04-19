#include <cstdio>
#include <algorithm>
using namespace std;

int x[100000 + 86];

int main() {
	int tc, cn = 0, n, q, a, b;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &q);
		for (int i=0; i<n; ++i) scanf("%d", x+i);
		sort(x, x+n);
		printf("Case %d:\n", ++cn);
		while (q--) {
			scanf("%d%d", &a, &b);
			int k = upper_bound(x, x+n, b) - lower_bound(x, x+n, a);
			printf("%d\n", max(0, k));
		}
	}
	return 0;
}

// 257660	2013-08-30 19:53:30	 1088 - Points in Segments	 C++	 0.380	 1476	Accepted
