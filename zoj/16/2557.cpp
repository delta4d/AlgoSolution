#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const double g = 9.81;

inline bool is_zero(const double x) {
	return fabs(x) < 1e-6;
}

int main() {
	double k, l, s, w;
	double v2;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	while (scanf("%lf %lf %lf %lf", &k, &l, &s, &w), !is_zero(k)||!is_zero(l)||!is_zero(s)||!is_zero(w)) {
		v2 = 2 * g * s - k * max(s - l, 0.0) * max(s - l, 0.0) / w;
		//printf("%.2lf\n", v2);
		if (v2 < 0) puts("Stuck in the air.");
		else if (v2 < 100) puts("James Bond survives.");
		else puts("Killed by the impact.");
	}
	return 0;
}