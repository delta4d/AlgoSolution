#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 1000;
int x[MAXN];
int y[MAXN];
int d[MAXN];

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	int n, tc;
	int t, i, j;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (t=0; t<tc; ++t) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) scanf("%d %d", x+i, y+i);
		qsort(x, n, sizeof(x[0]), cmp);
		for (i=1; i<n-1; ++i) d[i] = x[i+1] - x[i-1];
		d[0] = x[1] - x[0];
		d[n-1] = x[n-1] - x[n-2];
		qsort(y, n, sizeof(y[0]), cmp);
		qsort(d, n, sizeof(d[0]), cmp);
		double area(0);
		for (i=0; i<n; ++i) area += (double)y[i] * (double)d[i];
		area /= 2.0;
		printf("%.1lf\n", area);
	}
	return 0;
}
