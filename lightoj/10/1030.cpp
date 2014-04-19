#include <cstdio>
#include <algorithm>
using namespace std;

double x[111], p[111];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%lf", x+i), p[i] = 0;
		p[0] = 1;
		for (int i=0; i<n; ++i) {
			int c = min(6, n-1-i);
			for (int j=0; j<c; ++j) p[i+j+1] += p[i] / c;
		}
		double tot = 0;
		for (int i=0; i<n; ++i) tot += p[i] * x[i];
		printf("Case %d: %.10lf\n", ++cn, tot);
	}
	return 0;
}

// 254618	2013-08-23 01:07:59	 1030 - Discovering Gold	 C++	 0.000	 1088	Accepted
