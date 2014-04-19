#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

inline double sqr(const double x) { return x * x; }

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double ox, oy, ax, ay, bx, by;
		scanf("%lf%lf%lf%lf%lf%lf", &ox, &oy, &ax, &ay, &bx, &by);
		double r = sqrt(sqr(ax - ox) + sqr(ay - oy)), d = sqrt(sqr(ax-bx)+sqr(ay-by)) / 2.0;
		double arc = r * asin(d / r) * 2;
		printf("Case %d: %lf\n", ++cn, arc);
	}
	return 0;
}

// 252158	2013-08-16 10:49:56	 1433 - Minimum Arc Distance	 C++	 0.000	 1224	Accepted
