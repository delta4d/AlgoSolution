#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-2;

inline double dis(double x1, double	y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1- y2) * (y1 - y2));
}

inline double angle(double a, double b, double c) {
	return acos((a * a + b * b  - c * c) / (2 * a * b)) * 180.0 / M_PI;
}

inline bool is0(const double x) {
	return fabs(x) < eps;
}

inline double xmult(double x1, double y1, double x2, double	y2) {
	return x1 * y2 - x2 * y1;
}

int main() {
	int i, j, k;
	int en, an;
	double x[3], y[3];
	double e[3], a[3];
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	while (scanf("%lf %lf", x, y) == 2) {
		scanf("%lf %lf %lf %lf", x+1, y+1, x+2, y+2);
		if (is0(xmult(x[0]-x[1], y[0]-y[1], x[1]-x[2], y[1]-y[2]))) {
			puts("Not a Triangle");
		} else {
			e[0] = dis(x[0], y[0], x[1], y[1]);
			e[1] = dis(x[1], y[1], x[2], y[2]);
			e[2] = dis(x[2], y[2], x[0], y[0]);
			a[0] = angle(e[0], e[1], e[2]);
			a[1] = angle(e[1], e[2], e[0]);
			a[2] = angle(e[2], e[0], e[1]);
			an = en = 0;
			en = is0(e[0]-e[1]) + is0(e[1]-e[2]) + is0(e[2]-e[0]);
			for (i=0; i<3; ++i) {
				if (is0(a[i]-90)) {
					an = 1;
					break;
				} else if (a[i] > 90) {
					an = 2;
					break;
				}
			}
			if (en == 0) printf("Scalene");
			else if (en == 1) printf("Isosceles");
			else printf("Equilateral");
			if (an == 0) puts(" Acute");
			else if (an == 1) puts(" Right");
			else puts(" Obtuse");
		}
	}
	puts("End of Output");
	return 0;
}