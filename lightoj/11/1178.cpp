#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double a, b, c, d;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		if (a < c) swap(a, c);
		double p = (d + b + a - c) / 2;
		double area = sqrt(p * (p - d) * (p - b) * (p - a + c));
		double h = area * 2 / (a - c);
		area = h * (a + c) / 2;
		printf("Case %d: %.10lf\n", ++cn, area);
	}
	return 0;
}

// 256812	2013-08-28 14:50:26	 1178 - Trapezium	 C++	 0.000	 1100	Accepted
