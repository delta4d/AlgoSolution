#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const double INF = 1e100;

inline double dis(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double x1, y1, z1, x2, y2, z2, x, y, z;
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &z1, &x2, &y2, &z2, &x, &y, &z);
		double d = dis(x1, y1, z1, x2, y2, z2), dx = (x2 - x1) / d, dy = (y2 - y1) / d, dz = (z2 - z1) / d;
		double l = 0, r = d, m1, m2;
		d = INF;
		for (int i=0; i<50; ++i) {
			m1 = l + (r - l) / 3, m2 = m1 + (r - l) / 3;
			double d1 = dis(x, y, z, x1+m1*dx, y1+m1*dy, z1+m1*dz);
			double d2 = dis(x, y, z, x1+m2*dx, y1+m2*dy, z1+m2*dz);
			if (d1 > d2) l = m1;
			else r = m2;
			d = min(d, min(d1, d2));
		}
		printf("Case %d: %.10lf\n", ++cn, d);
	}
	return 0;
}

// 257606	2013-08-30 17:15:27	 1240 - Point Segment Distance (3D)	 C++	 0.048	 1100	Accepted
