#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

double f(double a, double b, double c) {
	return acos((b * b + c * c - a * a) / (2 * b * c));
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double r1, r2, r3;
		scanf("%lf%lf%lf", &r1, &r2, &r3);
		double x1 = r2 + r3, x2 = r1 + r3, x3 = r1 + r2;
		double a1 = f(x1, x2, x3), a2 = f(x2, x1, x3), a3 = f(x3, x1, x2);
		double area = sqrt((r1 + r2 + r3) * r1 * r2 * r3);
		area -= a1 * r1 * r1 / 2 + a2 * r2 * r2 / 2 + a3 * r3 * r3 / 2;
		printf("Case %d: %.10lf\n", ++cn, area);
	}
	return 0;
}

// 252579	2013-08-17 19:11:49	 1331 - Agent J	 C++	 0.004	 1224	Accepted
