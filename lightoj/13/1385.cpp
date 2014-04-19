#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-8;

inline bool zero(const double x) { return fabs(x) < eps; }

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double a, b, c, d, e;
		scanf("%lf%lf%lf", &a, &b, &c);
		d = (a + b) * a - (a + b + c) * (b + c) * a / b;
		e = a * c / b - b;
		if (zero(e) || d * e < 0) printf("Case %d: -1\n", ++cn);
		else printf("Case %d: %.10lf\n", ++cn, d/e);
	}
	return 0;
}

// 256947	2013-08-28 20:30:44	 1385 - Kingdom Division	 C++	 0.000	 1088	Accepted
