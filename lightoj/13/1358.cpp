#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 5000 + 86;
const double INF = 1000;
const double eps = 1e-7;

inline bool zero(const double x) { return fabs(x) < eps; }

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	T sgn = 1;
	while (c < '0' || c > '9') {
		c = getchar();
		if (c == '-') sgn = -1;
	}
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return sgn * a;
}

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
	void readin() { x = fastin<int>(), y = fastin<int>(); }
	void to_s() { printf("point(%lf, %lf)\n", x, y); }
} p[MAXN];

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
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		for (int i=0; i<n; ++i) p[i].readin();
		double rx, ry, P;
		rx = fastin<int>(), ry = fastin<int>(), P = fastin<int>();
		for (int i=0; i<n; ++i) p[i].x -= rx, p[i].y -= ry;
		double left = 0, right = INF, mid, s = poly_area(n), t;
		P = s * P / 100;
		for (int i=0; i<50; ++i) {
			mid = (left + right) / 2;
			if (gao(mid, n) + eps >= P) right = mid, t = mid;
			else left = mid;
		}
		printf("Case %d: %d\n", ++cn, (int)rint(t));
	}
	return 0;
}

// 260771	2013-09-09 18:10:49	 1358 - Fukushima Nuclear Blast	 C++	 0.176	 1308	Accepted
