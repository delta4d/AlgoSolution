#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define INIT for (i=0; i<MAXN; ++i) f[0][i].y = 1.0; \
			 for (i=0; i<MAXN; ++i) f[0][i].x = x[i]
const double eps = 1e-10;
const int MAXN = 11;
struct point {
	double x;
	double y;
}f[MAXN][MAXN];
double x[MAXN];

inline void gao(const int n) {
	int i, j;
	double a, b, c;
	for (i=0; i<n-1; ++i) {
		a = (f[0][i+1].x - f[0][i].x) / 2.0;
		b = sqrt(4.0 - a * a);
		f[1][i].y = b + 1.0;
	}
	for (i=1; i<n-1; ++i) {
		for (j=0; j<n-i-1; ++j) {
			f[i+1][j].y = f[i][j].y + f[i][j+1].y - f[i-1][j+1].y;
		}
	}
}

int main() {
	int n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &n);
	while (n != 0) {
		for (i=0; i<n; ++i) scanf("%lf", x+i);
		sort(x, x+n);
		INIT;
		gao(n);
		printf("%.4lf %.4lf\n", (f[0][0].x+f[0][n-1].x)/2.0, f[n-1][0].y);
		scanf("%d", &n);
	}
	return 0;
}