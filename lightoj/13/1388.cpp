#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-8;

inline bool zero(const double x) { return fabs(x) < eps; }

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double ax, ay, bx, by, cx, cy, dx, dy, a, b, c, d, t;
		scanf("%lf%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &b, &c, &d);
		a = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
		double tx = (ax - bx) / a, ty = (ay - by) / a;
		if (zero(a-c)) t = 0;
		else t = (a - c - (d * d - b * b) / (a - c)) / 2;
		double xcos = t / b, xsin = -sqrt(1 - xcos * xcos);
		double ttx = tx * xcos - ty * xsin, tty = tx * xsin + ty * xcos;
		cx = bx + b * ttx, cy = by + b * tty;
		tx = -tx, ty = -ty;
		xcos = (a - c - t) / d, xsin = sqrt(1 - xcos * xcos);
		ttx = tx * xcos - ty * xsin, tty = tx * xsin + ty * xcos;
		dx = ax + d * ttx, dy = ay + d * tty;
		printf("Case %d:\n", ++cn);
		printf("%.10lf %.10lf %.10lf %.10lf\n", cx, cy, dx, dy);
	}
	return 0;
}

// 259508	2013-09-04 15:40:29	 1388 - Trapezium Drawing	 C++	 0.004	 1100	Accepted
