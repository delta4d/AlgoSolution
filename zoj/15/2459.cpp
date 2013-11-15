#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

double x[6];

inline bool input() {
	int i, j, k;
	for (i=0; i<6; ++i) {
		if (scanf("%lf", x+i) == EOF) return false;
	}
	return true;
}

inline void gao() {
	double v;
	double a, b, c, w;
	a = acos((x[0] * x[0] + x[1] * x[1] - x[3] * x[3]) / (2.0 * x[0] * x[1]));
	b = acos((x[1] * x[1] + x[2] * x[2] - x[5] * x[5]) / (2.0 * x[1] * x[2]));
	c = acos((x[0] * x[0] + x[2] * x[2] - x[4] * x[4]) / (2.0 * x[0] * x[2]));
	w = (a + b + c) / 2.0;
	v = x[0] * x[1] * x[2] * sqrt(sin(w) * sin(w-a) * sin(w-b) * sin(w-c)) / 3.0;
	printf("%.4lf\n", v);
} 

int main() {
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (input()) gao();
	return 0;
}