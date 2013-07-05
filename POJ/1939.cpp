#include <cstdio>
using namespace std;

int main() {
	int i, j, k;
	int n;
	double x0, y0, x1, y1, x2, y2;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		printf("%d ", n);
		scanf("%lf %lf", &x0, &y0);
		x1 = x0, y1 = y0;
		for (i=1; i<n; ++i) {
			scanf("%lf %lf", &x2, &y2);
			printf("%.6lf %.6lf ", (x1+x2)/2, (y1+y2)/2);
			x1 = x2, y1 = y2;
		}
		printf("%.6lf %.6lf\n", (x0+x1)/2, (y0+y1)/2);
	}
	return 0;
}