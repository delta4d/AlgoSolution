#include <cmath>
#include <cstdio>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-8;

inline bool zero(double x) {
	return fabs(x) < eps;
}

inline double f(double x) {
	if (zero(x)) return 0;
	return x / sin(x);
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double L, n, C, R, h;
		scanf("%lf%lf%lf", &L, &n, &C);
		R = 1 + n * C;
		double left = 0, right = PI / 2, mid;
		for (int i=0; i<50; ++i) {
			mid = (left + right) / 2;
			double fx = f(mid);
			if (fx <= R) left = mid;
			else right = mid;
		}
		R = L / (2 * sin(mid));
		h = R * (1 - cos(mid));
		printf("Case %d: %.10lf\n", ++cn, h);
	}
	return 0;
}

// 259666	2013-09-04 21:25:23	 1137 - Expanding Rods	 C++	 0.000	 1196	Accepted
