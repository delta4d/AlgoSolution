#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-7;

inline bool iszero(const double x) { return fabs(x) < eps; }

double gao(double a, double b, double d) {
	if (iszero(d)) return a * b;
	if (iszero(2*d-PI)) return b * b;
	if (b * (1 + cos(d)) <= a * sin(d)) return b * b / sin(d);
	return a * b - (a * a + b * b - 2 * a * b * sin(d)) * (1 - cos(d)) / sin(2*d);
}

int main() {
	double a, b, d;

	scanf("%lf%lf%lf", &a, &b, &d);
	d *= PI / 180;
	d = min(d, PI-d);
	if (a < b) swap(a, b);
	printf("%.16lf\n", gao(a, b, d));

	return 0;
}

// 3381729	 Mar 22, 2013 8:29:07 PM	delta_4d	 A - Rectangle Puzzle	 GNU C++	Accepted	 15 ms	 0 KB
