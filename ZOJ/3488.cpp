#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const double eps = 1e-7;

inline bool gao(double x, double y) {
	return fabs(x-y) < eps;
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	double a, b, c, d, e, f;
	
	scanf("%d", &tc);
	while (tc--) {
		scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
		if (gao(a, 0.0) || gao(c, 0.0)) {
			puts("parabola");
		} else if (a > 0 && c < 0 || a < 0 && c > 0) {
			puts("hyperbola");
		} else if (a > 0 && c > 0 || a < 0 && c < 0) {
			if (gao(a, c)) puts("circle");
			else puts("ellipse");
		}
	}

	return 0;
}
