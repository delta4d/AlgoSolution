#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const double g = 9.8;
const double INF = 999999999999.9;
const double per = 180.0 / acos(-1.0);

double h[MAXN], d[MAXN], p[MAXN+1];

inline double det(const double x00, const double x01, const double x10, const double x11) {
	return x00 * x11 - x01 * x10;
}

int main() {
	int m, n;
	int i, j;
	double v, alpha;
	double a, b, c1, c2, k;
	double tot;
	double x, y, t;
	double x1, x2, y1, y2;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	while (scanf("%d", &n) != EOF) {
		for (p[0]=0,i=0; i<n; p[i+1]=p[i]+d[i++]) scanf("%lf %lf", h+i, d+i);
		k = -INF;
		for (i=0; i<n; ++i) {
			c1 = h[i] / p[i], c2 = h[i] / (p[n] - p[i+1]);
			if (k < c1) {
				k = c1;
				x = p[i], y = h[i];
			}
			if (k < c2) {
				k = c2;
				x = p[i+1], y = h[i];
			}
		}
		x1 = x, y1 = y, x2 = p[n], y2 = 0;
		b = det(x1*x1, y1, x2*x2, y2) / det(x1*x1, x1, x2*x2, x2);
		alpha = atan(b) * per;
		//printf("%lf\n", alpha);
		m = alpha * 100.0 + 0.05;
		alpha = m / 100.0;
		v = sqrt(g * p[n] * (b * b + 1.0) / (2.0 * b));
		printf("%.2lf %.2lf\n", alpha, v);
	}
	return 0;
}