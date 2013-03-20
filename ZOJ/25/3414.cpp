#include <cstdio>
#include <cmath>
using namespace std;

const double INF = 9999999999999.0;
const double eps = 1e-8;
const int MAXN = 1000;
double x[MAXN], y[MAXN];
double d[MAXN];

inline double dis(double x1, double	y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));	
}

int main() {
	int n, m, t;
	int i, j;
	int cn(0), cp;
	double seg, rem, cur;
	double cx, cy;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &n, &m) != EOF) {
		seg = 0;
		for (i=1; i<=n; ++i) {
			scanf("%lf %lf", x+i, y+i);
			d[i-1] = dis(x[i-1], y[i-1], x[i], y[i]);
			seg += d[i-1];
		}
		seg /= (double)(m + 1.0);
		cp = 0;
		cx = x[0], cy = y[0];
		printf("Route %d\n", ++cn);
		for (t=1; t<=m; ++t) {
			cur = dis(cx, cy, x[cp+1], y[cp+1]);
			++cp;
			while (cur < seg) {
				cur += d[cp];
				++cp;
			}
			cx = x[cp-1] + (x[cp] - x[cp - 1]) * (d[cp-1] - cur + seg) / d[cp-1];
			cy = y[cp-1] + (y[cp] - y[cp - 1]) * (d[cp-1] - cur + seg) / d[cp-1];
			if (fabs(cur - seg) > eps) --cp;
			printf("CP%d: (%.3lf, %.3lf)\n", t, cx, cy);
		}
	}
	return 0;
}