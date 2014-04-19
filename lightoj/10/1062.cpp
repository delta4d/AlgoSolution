#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double x, y, c, w, l, r, m;
		scanf("%lf%lf%lf", &x, &y, &c);
		l = 0, r = min(x, y);
		for (int i=0; i<50; ++i) {
			m = (l + r) / 2;
			double ld = sqrt(x * x - m * m), rd = sqrt(y * y - m * m);
			double xx = x * rd / (ld + rd), yy = y * ld / (ld + rd);
			double p = (xx + yy + m) / 2, a = sqrt(p*(p-xx)*(p-yy)*(p-m));
			double h = 2 * a / m;
			if (h < c) r = m;
			else l = m;
		}
		printf("Case %d: %.10lf\n", ++cn, m);
	}
	return 0;
}

// 257667	2013-08-30 20:48:18	 1062 - Crossed Ladders	 C++	 0.000	 1100	Accepted
