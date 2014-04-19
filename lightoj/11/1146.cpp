#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const double INF = 1e100;
const double eps = 1e-8;

inline bool zero(const double x) {
	return fabs(x) < eps;
}

inline double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double ax, ay, bx, by, cx, cy, dx, dy, d = INF;
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
		double dab = dis(ax, ay, bx, by), dcd = dis(cx, cy, dx, dy);
		double dabx = (bx - ax) / dab, daby = (by - ay) / dab;
		double dcdx = (dx - cx) / dab, dcdy = (dy - cy) / dab;
		double l = 0, r = dab, m1, m2;
		for (int i=0; i<50; ++i) {
			m1 = l + (r - l) / 3, m2 = m1 + (r - l) / 3;
			double d1 = dis(ax+m1*dabx, ay+m1*daby, cx+m1*dcdx, cy+m1*dcdy);
			double d2 = dis(ax+m2*dabx, ay+m2*daby, cx+m2*dcdx, cy+m2*dcdy);
			d = min(d, min(d1, d2));
			if (d1 < d2) r = m2;
			else l = m1;
		}
		printf("Case %d: %.10lf\n", ++cn, d);
	}
	return 0;
}

// 257599	2013-08-30 17:05:46	 1146 - Closest Distance	 C++	 0.004	 1100	Accepted
