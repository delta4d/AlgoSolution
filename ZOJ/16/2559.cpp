#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

inline double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

inline bool gao() {
	int i, j, k;
	double x[4], y[4];
	double d[3];
	double p;
	for (i=0; i<3; ++i) if (scanf("%lf %lf", x+i, y+i) == EOF) return false;
	x[3] = x[0], y[3] = y[0];
	for (i=0; i<3; ++i) d[i] = dis(x[i], y[i], x[i+1], y[i+1]);
	p = (d[0] + d[1] + d[2]) / 2.0;
	printf("%.6lf\n", p-d[1]);
	printf("%.6lf\n", p-d[2]);
	printf("%.6lf\n", p-d[0]);
	return true;
}

int main() {
	//freopen("f:\\in.txt", "r", stdin);
	while (gao());
	return 0;
}