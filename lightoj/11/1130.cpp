#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const double eps = 1e-7;

inline bool zero(const double x) { return fabs(x) < eps; }

struct point {
	double x, y;

	point(double _x=0, double _y=0):x(_x), y(_y) {}
	double operator^(const point &a) const { return x * a.y - y * a.x; }
	double operator*(const point &a) const { return x * a.x + y * a.y; }
	point operator*(const double t) const { return point(x*t, y*t); }
	point operator+(const point &a) const { return point(x+a.x, y+a.y); }
	point operator-(const point &a) const { return point(x-a.x, y-a.y); }
	point operator/(const double t) const { return point(x/t, y/t); }
	double sqr2() { return x * x + y * y; }
	double sqr() { return sqrt(sqr2()); }
	void init(int _x=0, int _y=0) { x = _x, y = _y; }
	void to_s() { printf("point(%lf, %lf)\n", x, y); }
} p[4];

double poly_area(const int n) {
	double tot = 0;
	for (int i=1; i+1<n; ++i) tot += (p[i] - p[0]) ^ (p[i+1] - p[0]);
	return fabs(tot) / 2;
}

double angle(point &a, point &b) {
	double s = (a.sqr2() + b.sqr2() - (a - b).sqr2()) / (2 * a.sqr() * b.sqr());
	return acos(s);
}

double area(point &a, point &b) {
	double da = a.sqr(), db = b.sqr(), dc = (a - b).sqr(), dp = (da + db + dc) / 2;
	return sqrt(dp * (dp - da) * (dp - db) * (dp - dc));
}

double gao(point a, point b, const double r) {
	double da = a.sqr(), db = b.sqr(), xab = a ^ b, ret;
	double dc = (a - b).sqr(), dp = (da + db + dc) / 2;
	if (zero(xab)) return 0;
	int sgn = xab >= 0 ? 1 : -1;
	if (da > db) swap(a, b), swap(da, db);
	if (db <= r) {
		ret = sqrt(dp * (dp - da) * (dp - db) * (dp - dc));
	} else {
		double dab = (a - b).sqr();
		point d = (b - a) / dab;
		double A = d.sqr2(), B = (a * d) * 2, C = a.sqr2() - r * r;
		double delta = B * B - 4 * A * C;
		if (delta >= 0) {
			double t1 = (-B - sqrt(delta)) / (2 * A), t2 = (-B + sqrt(delta)) / (2 * A);
			if (0 <= t1 && t1 <= dab || 0 <= t2 && t2 <= dab) {
				point u = a + d * t1, v = a + d * t2;
				double s = angle(v, b);
				ret = s * r * r / 2;
				if (da <= r) {
					ret += area(v, a);
				} else {
					s = angle(u, a);
					ret += s * r * r / 2;
					ret += area(u, v);
				}
			} else {
				double s = angle(a, b);
				ret = s * r * r / 2;
			}
		} else {
			double s = angle(a, b);
			ret = s * r * r / 2;
		}
	}
	return sgn * ret;
}

double gao(const double r, const int n) {
	double tot = 0;
	for (int i=0; i<n; ++i) tot += gao(p[i], p[i==n-1?0:i+1], r);
	return fabs(tot);
}

int main() {
	int tc, cn = 0, n = 4;
	for (scanf("%d", &tc); tc--; ) {
		int x, y, r, x1, y1, x2, y2;
		scanf("%d%d%d%d%d%d%d", &x, &y, &r, &x1, &y1, &x2, &y2);
		p[0].init(x1-x, y1-y);
		p[1].init(x2-x, y1-y);
		p[2].init(x2-x, y2-y);
		p[3].init(x1-x, y2-y);
		printf("Case %d: %.10lf\n", ++cn, gao(r, 4));
	}
	return 0;
}

// 260769	2013-09-09 18:08:40	 1130 - Intersection between Circle and Rectangle	 C++	 0.012	 1224	Accepted

