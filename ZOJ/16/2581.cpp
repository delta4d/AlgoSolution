#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 128;

double x[MAXN], y[MAXN];

inline double xmult(const double x1, const double	y1, const double x2, const double y2) {
	return x1 * y2 - x2 * y1;
}

inline double dis(const double x1, const double	y1, const double x2, const double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	int m, n;
	int i, j, k;
	double x0, y0, x1, y1, x2, y2;
	double len;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<n; ++i) scanf("%lf %lf", x+i, y+i);
		len = 0;
		x0 = x[n-1] - x[0], y0 = y[n-1] - y[0];
		x1 = x[0], y1 = y[0];
		for (i=1; i<n; ++i) {
			if (xmult(x0, y0, x[i]-x[0], y[i]-y[0]) >= 0) {
				len += dis(x1, y1, x[i], y[i]);
				x1 = x[i], y1 = y[i];
			}
		}
		x1 = x[n-1], y1 = y[n-1];
		for (i=n-2; i>0; --i) {
			if (xmult(x0, y0, x[i]-x[0], y[i]-y[0]) < 0) {
				len += dis(x1, y1, x[i], y[i]);
				x1 = x[i], y1 = y[i];
			}
		}
		len += dis(x[0], y[0], x1, y1);
		printf("%.2lf\n", len);
	}
	return 0;
}