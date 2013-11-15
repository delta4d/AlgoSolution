#include <cmath>
#include <cstdio>
using namespace std;

const double c = 2 * sqrt(2.0);

inline void swap(double &x, double &y) {
	double temp;
	temp = x, x = y, y = temp;
}

bool gao(double a, double b, double r, double R) {
	if (a > b) swap(a, b);
	if (r > R) swap(r, R);
	if (R > a) return false;
	if (b - 2 * R >= 2 * r) return true;
	double t = a + b - sqrt(2*a*b) - R - r;
	if (t >= 0) return true;
	return false;
}

int main() {
	double a, b, r1, r2;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%lf %lf %lf %lf", &a, &b, &r1, &r2) != EOF) {
		printf("%s\n", gao(a, b, r1, r2)?"Yes":"No");
	}
	return 0;
}