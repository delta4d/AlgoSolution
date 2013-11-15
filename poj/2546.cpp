#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = 3.1415926535898;
inline double dis(double x1, double	y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	double x1, y1, r1, x2, y2, r2;
	double alpha, beta;
	double d;
	double area;
	double r;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2) != EOF) {
		d = dis(x1, y1, x2, y2);
		if (r1 + r2 <= d) {
			printf("0.000\n");
			continue;
		}
		if (fabs(r1-r2) >= d) {
			r = min(r1, r2);
			area = PI * r * r;
			printf("%.3lf\n", area);
			continue;
		}
		alpha = 2.0 * acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
		beta = 2.0 * acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));
		area = r1 * r1 * (alpha - sin(alpha)) / 2.0 + r2 * r2 * (beta - sin(beta)) / 2.0;
		printf("%.3lf\n", area);
	}
	return 0;
}