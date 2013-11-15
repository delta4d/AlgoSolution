#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct circle {
	double x, y, r;
	void _set(double _x, double _y, double _r) {
		x = _x, y = _y, r = _r;
	}
	double square() {
		return x * x + y * y - r * r;
	}
} c[3];

inline bool input() {
	double x[3], y[3], r[3];
	if (scanf("%lf %lf %lf", x, y, r) == EOF) return false;
	scanf("%lf %lf %lf %lf", x+1, y+1, r+2, r+1);
	x[2] = x[1], y[2] = y[1];
	for (int i=0; i<3; ++i) c[i]._set(x[i], y[i], r[i]);
	return true;
}

double dis(double x1, double y1, double	x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double intersect(circle &c1, circle &c2) {
	double a, b, c;
	double d1, d2, alpha1, alpha2;
	double temp;
	double sum1, sum2;
	double d;
	d = dis(c1.x, c1.y, c2.x, c2.y);
	if (c1.r + c2.r <= d) return 0;
	if (fabs(c1.r - c2.r) >= d) return M_PI * min(c1.r, c2.r) * min(c1.r, c2.r);
	a = 2 * (c2.x - c1.x), b = 2 * (c2.y - c1.y), c = c1.square() - c2.square();
	temp = sqrt(a * a + b * b);
	d1 = (a * c1.x + b * c1.y + c) / temp;
	d2 = (a * c2.x + b * c2.y + c) / temp;
	alpha1 = acos(fabs(d1)/c1.r);
	alpha2 = acos(fabs(d2)/c2.r);
	if (d1 * d2 > 0) {
		d1 = fabs(d1);
		d2 = fabs(d2);
		if (d1 < d2) {
			alpha1 = M_PI - alpha1;
			sum1 = alpha1 * c1.r * c1.r + sqrt(c1.r*c1.r-d1*d1) * d1;
			sum2 = alpha2 * c2.r * c2.r - sqrt(c2.r*c2.r-d2*d2) * d2; 
		} else {
			alpha2 = M_PI - alpha2;
			sum1 = alpha1 * c1.r * c1.r - sqrt(c1.r*c1.r-d1*d1) * d1;
			sum2 = alpha2 * c2.r * c2.r + sqrt(c2.r*c2.r-d2*d2) * d2;
		}
	} else {
		d1 = fabs(d1), d2 = fabs(d2);
		sum1 = alpha1 * c1.r * c1.r - sqrt(c1.r*c1.r-d1*d1) * d1;
		sum2 = alpha2 * c2.r * c2.r - sqrt(c2.r*c2.r-d2*d2) * d2;
	}
	return sum1 + sum2;
}

void gao() {
	double s1, s2;
	s1 = intersect(c[0], c[1]);
	s2 = intersect(c[0], c[2]);
	printf("%.3lf\n", fabs(s1-s2));
}

int main() {
	//freopen("f:\\in.txt", "r", stdin);
	while (input()) gao();
	return 0;
}