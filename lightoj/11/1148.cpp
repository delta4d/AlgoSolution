#include <cstdio>
#include <algorithm>
using namespace std;

int x[100];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d", x+i);
		sort(x, x+n); x[n] = -1;
		int tot = 0;
		for (int i=0,cc=1; i<n; ++i) {
			if (x[i] != x[i+1]) {
				tot += (cc + x[i]) / (x[i] + 1) * (x[i] + 1);
				cc = 1;
			} else {
				++cc;
			}
		}
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 253541	2013-08-20 14:08:28	 1148 - Mad Counting	 C++	 0.000	 1088	Accepted
