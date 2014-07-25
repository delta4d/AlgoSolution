#include <bits/stdc++.h>
using namespace std;

double const eps = 1e-8;
inline int sgn(int x) { return (x>eps)-(x<-eps); }
struct point {
	double x, y;
	point(double x=0, double y=0):x(x), y(y) {}
	void readin() { scanf("%lf%lf", &x, &y); }
	point operator-(const point &rhs) const { return point(x-rhs.x,y-rhs.y); }
	double operator*(const point &rhs) const { return x*rhs.x+y*rhs.y; }
	double operator^(const point &rhs) const { return x*rhs.y-y*rhs.x; }
	double norm2() { return x*x+y*y; }
	void to_s() { printf("(%lf,%lf)\n", x, y); }
};
struct line {
	point a, b;
	line() {}
	line(point a, point b):a(a), b(b) {}
	void readin() { a.readin(), b.readin(); }
	bool intersect(const line &l) const {
		int s1 = sgn((l.a-a)^(b-a)) * sgn((l.b-a)^(b-a));
		int	s2 = sgn((a-l.a)^(l.b-l.a)) * sgn((b-l.a)^(l.b-l.a));
		if (s1 < 0 && s2 < 0) return true;
		if (s1 > 0 || s2 > 0) return false;
		double xmin = min(a.x, b.x), xmax = max(a.x, b.x);
		double ymin = min(a.y, b.y), ymax = max(a.y, b.y);
		if (xmin <= l.a.x && l.a.x <= xmax && ymin <= l.a.y && l.a.y <= ymax) return true;
		if (xmin <= l.b.x && l.b.x <= xmax && ymin <= l.b.y && l.b.y <= ymax) return true;
		return false;
	}
	point reflect(const point &p) const {
		double x1 = a.x, x2 = b.x, y1 = a.y, y2 = b.y, x0 = p.x, y0 = p.y;
		double a1 = y2 - y1, b1 = x1 - x2, c1 = (y0-2*y1)*(x2-x1)-(x0-2*x1)*(y2-y1);
		double a2 = x2 - x1, b2 = y2 - y1, c2 = (x2-x1)*x0+(y2-y1)*y0;
		double rx = (c1*b2-c2*b1)/(a1*b2-a2*b1), ry = (a1*c2-a2*c1)/(a1*b2-a2*b1);
		return point(rx, ry);
	}
};

int main() {
	point victor, peter;
	line wall, mirror;
	victor.readin(), peter.readin(), wall.readin(), mirror.readin();
	line vp(victor, peter);
	if (!vp.intersect(wall) && !vp.intersect(mirror)) return puts("YES"), 0;
	line vpr(victor, mirror.reflect(peter)), vrp(mirror.reflect(victor), peter);
	if (vpr.intersect(mirror) && !vpr.intersect(wall) && 
	    vrp.intersect(mirror) && !vrp.intersect(wall)) puts("YES");
	else puts("NO");
	return 0;
}

// 7238778	2014-07-25 10:14:58	delta_4d	E - Hide-and-Seek	GNU C++0x	Accepted	30 ms	0 KB
