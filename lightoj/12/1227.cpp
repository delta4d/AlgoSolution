#include <cstdio>
using namespace std;

int x[50];

int main() {
	int tc, cn = 0, n, P, Q;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &n, &P, &Q);
		for (int i=0; i<n; ++i) scanf("%d", x+i);
		int tot = 0, t = 0;
		for (t=0; t<n&&t<P; ++t) {
			tot += x[t];
			if (tot > Q) break;
		}
		printf("Case %d: %d\n", ++cn, t);
	}
	return 0;
}

// 252590	2013-08-17 19:54:36	 1227 - Boiled Eggs	 C++	 0.000	 1088	Accepted
