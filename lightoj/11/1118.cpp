#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const double PI = acos(-1.0);

inline double sqr(const double x) { return x * x; }

struct point {
	double x, y;

	point(double _x=0, double _y=0):x(_x), y(_y) {}
	double operator-(const point &a) const { return sqrt(sqr(x - a.x) + sqr(y - a.y)); }
};

struct circle {
	point c;
	double r;

	inline void readin() { scanf("%lf%lf%lf", &c.x, &c.y, &r); }
	inline int relation(const circle &a) const {
		double d = c - a.c, sr = r + a.r, mr = fabs(r - a.r);
		return d >= sr ? 1 : (d <= mr ? -1 : 0);
	}
	inline double iline(double a, double b, double e) {
		double d = (a * c.x + b * c.y + e) / sqrt(sqr(a) + sqr(b));
		double t = acos(fabs(d) / r);
		double area = (t - sin(2*t) / 2) * sqr(r);
		if (d < 0) area = -area;
		return area;
	}
	inline double area() { return PI * sqr(r); }
	inline void to_s() { printf("(%lf, %lf) %lf\n", c.x, c.y, r); }
} c1, c2;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		c1.readin(); c2.readin();
		if (c1.r < c2.r) swap(c1, c2);
		c2.c.x -= c1.c.x, c2.c.y -= c1.c.y;
		c1.c.x = 0, c1.c.y = 0;
		double area = 0;
		int t = c1.relation(c2);
		if (t == -1) {
			area = PI * sqr(c2.r);
		} else if (t == 0) {
			double a = 2 * c2.c.x, b = 2 * c2.c.y;
			double c = sqr(c2.r) - sqr(c1.r) - sqr(c2.c.x) - sqr(c2.c.y);
			double a1 = c1.iline(a, b, c), a2 = c2.iline(a, b, c);
			if (a1 * a2 <= 0) area = fabs(a1 - a2);
			else area = fabs(a1) + c2.area() - fabs(a2);
		}
		printf("Case %d: %.10lf\n", ++cn, area);
	}
	return 0;
}

// 260538	2013-09-08 19:41:45	 1118 - Incredible Molecules	 C++	 0.000	 1276	Accepted
