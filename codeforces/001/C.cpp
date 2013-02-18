#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 5e-6;
const double PI = acos(-1.0);

inline bool isint(const double x) {
	return fabs(int(ceil(x)) - x) < eps || fabs(int(floor(x)) - x) < eps;
}

inline double dis(const double x1, const double y1, const double x2, const double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

inline double angle(const double a, const double b, const double c) {
	return acos((b*b+c*c-a*a) / (2*b*c));
}

int main() {
	double x1, x2, x3, y1, y2, y3;
	double a, b, c;
	double A, B, C;
	double nA, nB, nC;
	double R, area, xx;
	int i;

	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);

	a = dis(x1, y1, x2, y2);
	b = dis(x2, y2, x3, y3);
	c = dis(x3, y3, x1, y1);
	A = angle(a, b, c);	
	B = angle(b, c, a);	
	C = angle(c, a, b);	
	R = a / (2 * sin(A));
	
//	printf("%lf %lf %lf\n", a, b, c);
//	printf("%lf %lf %lf %lf\n", A, B, C, R);

	for (i=3; ; ++i) {
		xx = PI / i;
		nA = A / xx, nB = B / xx, nC = C / xx;
//		printf("%d: %lf %lf %lf\n", i, nA, nB, nC);
		if (isint(nA) && isint(nB) && isint(nC)) break;
	}
	
	area = i * R * R * sin(xx*2) / 2;
	printf("%.8lf\n", area);

	return 0;
}
