#include <cstdio>
using namespace std;

const int MAXN = 10000;
double x[MAXN], y[MAXN];

int main() {
	int n;
	int i, j, k;
	int s;
	double tx, ty;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		printf("%d", n);
		tx = ty = 0;
		s = 0;
		for (i=0; i<n; ++i) {
			scanf("%lf %lf", x+i, y+i);
			x[i] *= 2.0, y[i] *= 2.0;
			if (s == 0) {
				tx += x[i], ty += y[i];
			} else {
				tx -= x[i], ty -= y[i];
			}
			s ^= 1;
		}
		tx /= 2.0, ty /= 2.0;
		printf(" %.6lf %.6lf", tx, ty);
		for (i=0; i<n-1; ++i) {
			tx = x[i] - tx, ty = y[i] - ty;
			printf(" %.6lf %.6lf", tx, ty);
		}
		puts("");
	}
	return 0;
}