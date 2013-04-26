#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const long double INF = 99999999999.9;
const long double EPS = 1e-8;

struct Point {
	long double x, y;
	Point(long double _x=0, long double _y=0):x(_x), y(_y) {}
};

inline long double xmult(const Point & p1, const Point & p2, const Point & p0) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

inline long double dis(const Point & p1, const Point & p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

long double disptoline(const Point & p, const Point & l1, const Point & l2) {
	return fabs(xmult(p, l1, l2)) / dis(l1, l2);
}

Point intersection(const Point & u1, const Point & u2, const Point & v1, const Point & v2) {
	Point ret = u1;
	long double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) / ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
	ret.x += (u2.x - u1.x) * t;
	ret.y += (u2.y - u1.y) * t;
	return ret;
}

int inCircleCircle(const Point & c1, long double r1, const Point & c2, long double r2) {
	return r1 < r2 + EPS && dis(c1, c2) < fabs(r1 - r2) + EPS;
}

int intersectLineCircle(const Point & c, long double r, const Point & l1, const Point & l2) {
	return disptoline(c, l1, l2) < r + EPS;
}

int intersectCircleCircle(const Point & c1, long double r1, const Point & c2, long double r2) {
	return dis(c1, c2) < r1 + r2 + EPS && dis(c1, c2) > fabs(r1 - r2) - EPS;
}

void intersectionLineCircle(const Point & c, long double r, const Point & l1, const Point & l2, Point & p1, Point & p2) {
	Point p = c;
	p.x += l1.y - l2.y;
	p.y += l2.x - l1.x;
	p = intersection(p, c, l1, l2);
	long double tt = r * r - dis(p, c) * dis(p, c);
	if (fabs(tt) < EPS) tt = 0;
//	long double t = sqrt(r * r - dis(p, c) * dis(p, c) + EPS) / dis(l1, l2);
	long double t = sqrt(tt) / dis(l1, l2);
	p1.x = p.x + (l2.x - l1.x) * t;
	p1.y = p.y + (l2.y - l1.y) * t;
	p2.x = p.x - (l2.x - l1.x) * t;
	p2.y = p.y - (l2.y - l1.y) * t;
}

void intersectionCircleCircle(const Point & c1, long double r1, const Point & c2, long double r2, Point & p1, Point & p2) {
	Point u, v;
	long double t = (1 + (r1 * r1 - r2 * r2) / dis(c1, c2) / dis(c1, c2)) / 2;
	u.x = c1.x + (c2.x - c1.x) * t;
	u.y = c1.y + (c2.y - c1.y) * t;
	v.x = u.x + c1.y - c2.y;
	v.y = u.y - c1.x + c2.x;
	intersectionLineCircle(c1, r1, u, v, p1, p2);
}

int main() {
	long double ts, th;
	long double x, y, xs, ys, xh, yh;

	cin >> ts >> th >> x >> y >> xh >> yh >> xs >> ys;
	xh -= x, xs -= x, yh -= y, ys -= y;

	long double ds = hypot(xs, ys), dh = hypot(xh, yh);
	long double dsh = hypot(xs-xh, ys-yh);
	long double r;

	if (ds + dsh <= th + dh) {
		r = min(th+dh-ds-dsh, (long double)ts) + ds + dsh;
	} else {
		int tc = 50;
		long double left = 0, right = min(th+dh, ts+ds), mid;
		while (tc--) {
			mid = (left + right) / 2.0;	
			long double x[3], y[3], r[3];
			Point p[3];
			x[0] = 0, y[0] = 0, r[0] = mid;
			x[1] = xh, y[1] = yh, r[1] = th + dh - mid;
			x[2] = xs, y[2] = ys, r[2] = ts + ds - mid;
			for (int i=0; i<3; ++i) p[i].x = x[i], p[i].y = y[i];
//			for (int i=0; i<3; ++i) cout << p[i].x << ' ' << p[i].y << ' ' << r[i] << endl;

			bool v[3]={false};
			for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) {
				if (j == i) continue;
				if (inCircleCircle(p[j], r[j], p[i], r[i])) {
					v[i] = true;
					break;
				}
			}

			Point pp[3];
			long double rr[3];
			int sz = 0;
			for (int i=0; i<3; ++i) if (!v[i]) {
				pp[sz] = p[i];
				rr[sz++] = r[i];
			}
//			printf("sz: %d\n", sz);
			bool ok;
			if (sz == 1) {
				ok = true;	
			} else if (sz == 2) {
				ok = intersectCircleCircle(pp[0], rr[0], pp[1], rr[1]);
			} else {
				ok = false;
				for (int i=0; i<3; ++i) {
					int j = i == 2 ? 0 : i + 1, k = j == 2 ? 0 : j + 1;
					if (intersectCircleCircle(p[i], r[i], p[j], r[j])) {
						Point a, b;
						intersectionCircleCircle(p[i], r[i], p[j], r[j], a, b);
						if (dis(a, p[k]) < r[k] - EPS || dis(b, p[k]) < r[k] - EPS) {
							ok = true;
							break;
						}
					} else {
						ok = false;
						break;
					}
				}
			}
			if (ok) left = mid;
			else right = mid;
//			cout << "ok?" << ok << ' '<< mid << endl;
		}
		r = mid;
	}

//	cout << r << endl;
	printf("%.16Lf\n", r);

	return 0;
}

// 3633674	 Apr 26, 2013 7:43:25 AM	delta_4d	 D - Two Friends	 MS C++	Accepted	 15 ms	 0 KB
