#include <bits/stdc++.h>
using namespace std;

double const eps = 1e-8;

inline bool z(double x) { return fabs(x) < eps; }

int main() {
	int n, m = 0;
	double x=0,y;
	scanf("%d", &n);
	for (int i=0; i<2*n; ++i) {
		scanf("%lf", &y);
		y -= floor(y);
		if (z(y)) ++m;
		x += y;
	}
	double mn = DBL_MAX;
	m = 2 * n - m;
	for (int i=0; i<=m&&i<=n; ++i) {
		if (m - i <= n) mn = min(mn, fabs(i-x));
	}
	printf("%.3lf\n", mn);
	return 0;
}

// 7352371	2014-08-05 16:11:43	delta_4d	A - Jeff and Rounding	GNU C++0x	Accepted	30 ms	0 KB
