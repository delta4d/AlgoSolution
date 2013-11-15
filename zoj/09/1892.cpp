#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const double INF = 9999999999999999.0;
const double PI = acos(-1.0);
const double eps = 1e-8;

double x[4], y[4];

inline double cross_product(double x1, double y1, double x2, double y2) {
	return x1 * y2 - x2 * y1;
} 

void get_intersect(double a11, double a12, double a13, double a21, double a22, double a23, double &x, double &y) {
	double d(cross_product(a11, a12, a21, a22)), d1(cross_product(a13, a12, a23, a22)), d2(cross_product(a11, a13, a21, a23));
	x = d1/ d, y = d2 / d;
}

int main() {
	int i, j, k;
	int n;
	int cn(0);
	double delta;
	double area;
	double tx, ty, rx, ry, xo, yo, r;
	double cd, sd;
	double minx, maxx, miny, maxy;
	double a11, a12, a13, a21, a22, a23;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=1; i<=3; ++i) scanf("%lf %lf", x+i, y+i);
		a11 = 2 * (x[2] - x[1]), a12 = 2 * (y[2] - y[1]), a13 = x[2] * x[2] - x[1] * x[1] + y[2] * y[2] - y[1] * y[1];
		a21 = 2 * (x[3] - x[2]), a22 = 2 * (y[3] - y[2]), a23 = x[3] * x[3] - x[2] * x[2] + y[3] * y[3] - y[2] * y[2];
		get_intersect(a11, a12, a13, a21, a22, a23, xo, yo);
		minx = miny = INF;
		maxx = maxy = -INF;
		tx = x[1], ty = y[1];
		//printf("%lf %lf\n", xo, yo);
		delta = 2.0 * PI / n;
		for (i=0; i<n; ++i) {
			cd = cos(delta*i), sd = sin(delta*i);
			rx = cross_product(tx-xo, ty-yo, sd, cd) + xo;
			ry = cross_product(tx-xo, ty-yo, -cd, sd) + yo;
			//printf("%lf %lf\n", rx, ry);
			minx = min(minx, rx), maxx = max(maxx, rx);
			miny = min(miny, ry), maxy = max(maxy, ry);
		}
		area = (maxx - minx) * (maxy - miny);
		printf("Polygon %d: %.3lf\n", ++cn, area);
		scanf("%d", &n);
	}
	return 0;
}