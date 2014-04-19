#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-10;

inline bool zero(const double x) { return fabs(x) < eps; }

int main() {
	int tc, cn = 0, k1, k2;
	for (scanf("%d", &tc); tc--; ) {
		double p;
		scanf("%lf%d%d", &p, &k1, &k2);
		double q = 1 - p;
		long double a1 = 1 - pow((long double)q, k1-1);
		long double a2 = 1 - pow((long double)p, k2-1);
		double x;
		if (zero(p)) x = k1;
		else if (zero(q)) x = k2;
		else x = (2 * a1 * a2 - a1 - a2 + a1 / p + a2 / q) / (1 - a1 * a2) + 1;
		printf("Case %d: %.10lf\n", ++cn, x);
	}
	return 0;
}

// 275643	2013-10-19 10:05:34	 1408 - Batting Practice	 C++	 0.032	 1088	Accepted
