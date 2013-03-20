#include <cmath>
#include <cstdio>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-12;

double gao(const double l, const double n, const double c) {
	if (l == 0 || n == 0 || c == 0) return 0.0;
	double left(0);
	double right(PI);
	double mid;
	double L(l*(1.0+n*c));
	while (right - left > eps) {
		mid = (right + left) / 2.0;
		if (2 * L / l > mid / sin(mid/2.0)) left = mid;
		else right = mid;
	}
	return L  /mid * (1 - cos(mid / 2.0));
}

int main() {
	double n, l, c;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%lf %lf %lf", &l, &n, &c);
	while (n >= 0 || l >= 0 || c >= 0) {
		printf("%.3lf\n", gao(l, n, c));
		scanf("%lf %lf %lf", &l, &n, &c);
	}
	return 0;
}