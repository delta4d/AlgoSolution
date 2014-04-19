#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 111;
const double eps = 1e-8;
const double PI2 = 2 * atan2(0, -1);

double x[MAXN], y[MAXN];

inline bool zero(const double x) { return fabs(x) < eps; }
inline int sgn(const double x) { return x > eps ? 1 : (x + eps < 0 ? -1 : 0); }

double angle(double x1, double y1, double x2, double y2) {
	double xm = x1 * y2 - x2 * y1;
	double d1 = sqrt(x1 * x1 + y1 * y1), d2 = sqrt(x2 * x2 + y2 * y2);
	double t = (x1 * x2 + y1 * y2) / (d1 * d2);
	t = acos(t);
	return sgn(xm) * t;
}

bool online(double x1, double y1, double x2, double y2) {
	return zero(x1*y2-x2*y1) && x1*x2<eps && y1*y2<eps;
}

bool in(int cx, int cy, const int n) {
	double tot = 0;
	for (int i=0; i<n; ++i) {
		if (online(x[i]-cx, y[i]-cy, x[i+1]-cx, y[i+1]-cy)) return true;
		tot += angle(x[i]-cx, y[i]-cy, x[i+1]-cx, y[i+1]-cy);
	}
	tot = fabs(tot);
	tot = fmod(tot, PI2);
	return zero(tot);
}

int main() {
	int tc, cn = 0, n, q;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%lf%lf", x+i, y+i);
		x[n] = x[0], y[n] = y[0];
		printf("Case %d:\n", ++cn);
		for (scanf("%d", &q); q--; ) {
			double cx, cy;
			scanf("%lf%lf", &cx, &cy);
			printf("%s\n", in(cx, cy, n)?"Yes":"No");
		}
	}
	return 0;
}
