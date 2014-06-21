#include <bits/stdc++.h>
using namespace std;

double const eps = 1e-12;
double const INF = 1e22;
double const PI = acos(-1.0);
double const alpha = 0.99;
int const N = 1 << 10;
int const M = 10;

double random() { return (rand() % 100) / 100.0; }
struct point {
	double x, y;
	point(double x=0, double y=0):x(x), y(y) {}
	double norm() { return sqrt(x * x + y * y); }
	point operator-(const point &rhs) const { return point(x-rhs.x, y-rhs.y); }
	void random_init(int w, int h) { x = random() * w, y = random() * h; }
	bool legal(int w, int h) { return 0 <= x && x <= w && 0 <= y && y <= h; }
	point random_walk(double d) {
		double delta = random() * 2 * PI;
		return point(x+d*cos(delta), y+d*sin(delta));
	} 
} a[N], p[M];
double d[M];
double min2(const point &x, const int n) {
	double mn1 = INF, mn2 = INF;
	for (int i=0; i<n; ++i) {
		double cc = (x - a[i]).norm();
		if (cc + eps < mn1) mn2 = mn1, mn1 = cc;
		else if (cc + eps < mn2) mn2 = cc;
	}
	return mn2;
}

int main() {
	srand((int)time(NULL));
	int w, h, n;
	scanf("%d%d%d", &w, &h, &n);
	for (int i=0; i<n; ++i) scanf("%lf%lf", &a[i].x, &a[i].y);
	for (int i=0; i<M; ++i) p[i].random_init(w, h), d[i] = min2(p[i], n);
	for (double D=point(w,h).norm(); D>eps; D*=alpha) {
		for (int i=0; i<M; ++i) {
			point pt = p[i];
			double dt = d[i];
			for (int j=0; j<8; ++j) {
				point cc = p[i].random_walk(D);
				if (!cc.legal(w, h)) continue;
				double dd = min2(cc, n);
				if (dd > dt + eps) dt = dd, pt = cc;
			}
			p[i] = pt, d[i] = dt;
		}
	}
	printf("%.20lf\n", *max_element(d, d+M));
	return 0;
}

// 6937498	 2014-06-21 17:03:59	delta_4d	 E - Gena and Second Distance	 GNU C++0x	Accepted	 1996 ms	 0 KB
