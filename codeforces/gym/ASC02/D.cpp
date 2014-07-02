#include <bits/stdc++.h>
using namespace std;

double const eps = 1e-12;

double b1, t1, b2, t2, l, ds, df, g;

double f(double d1, double d2, double h1, double h2) {
	double dd = 1 / d1 + 1 / d2, gg = g * (d1 + d2) / 2;
	double t1 = h1 * dd, t2 = h2 * dd;
	if (t1 <= 1 && 1 <= t2) return 2 * gg;
	double v1 = gg * (1 / t1 + t1), v2 = gg * (1 / t2 + t2);
	return min(v1, v2);
}

double f(double x) {
	double v1 = f(ds, x, b1, t1), v2 = f(l-x, df, b2, t2);
	return max(v1, v2);
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("jumper.in", "r", stdin);
	freopen("jumper.out", "w", stdout);
#endif
	while (8 == scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &b1, &t1, &b2, &t2, &l, &ds, &df, &g)) {
		double left = eps, right = l, mid1, mid2, vmin = -1;
		for (int tc=100; tc--; ) {
			mid1 = left + (right - left) / 3, mid2 = mid1 + (right - left) / 3;
			double v1 = f(mid1), v2 = f(mid2), cv = min(v1, v2);
			if (vmin < 0) vmin = cv;
			else vmin = min(vmin, cv);
			if (v1 > v2) left = mid1;
			else right = mid2;
		}
		printf("%.4lf\n", sqrt(vmin));
	}
	return 0;
}

// 6980635	 2014-06-29 17:38:23	delta_4d	 D - Little Jumper	 GNU C++0x	Accepted	 62 ms	 200 KB
