#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const double INF = 999999999999.0;
const double eps = 1e-8;
const int MAXN = 1001;
int d[MAXN];
struct point {
	double x;
	double y;
} stack[MAXN], p[MAXN];

inline void swap(point &a, point &b) {
	point t;
	t = a, a = b, b = t;
}

inline double dis(const point &a, const point &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

inline double cross_product(const point &a, const point &b, const point	&c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

inline int cmp(const void *a, const void *b) {
	point *c = (point *)a;
	point *d = (point *)b;
	double cp(cross_product(p[0], *c, *d));
	if (cp < 0) return 1;
	if (cp < eps && dis(p[0], *c) > dis(p[0], *d))  return 1;
	return -1;
}

inline bool gao(const int n) {
	int i, j, k;
	int top(3);
	double t;
	if (n <= 5) return false;
	qsort(p+1, n-1, sizeof(p[0]), cmp);
	for (i=0; i<3; ++i) stack[i] = p[i];
	for (i=3; i<n; ++i) {
		while (cross_product(stack[top-2], stack[top-1], p[i]) < 0) --top;
		stack[top] = p[i];
		++top;
	}
	memset(d, 0, sizeof(d));
	stack[top] = stack[0];
	for (i=0; i<top; ++i) {
		for (j=0; j<n; ++j) {
			if (fabs(cross_product(stack[i], stack[i+1], p[j])) < eps) ++d[i];
		}
		if (d[i] < 3 || d[i] == n) break;
	}
	return i == top;
}

int main() {
	int i, j, k;
	int n, t, tc;
	double x, y;
	int index;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (t=0; t<tc; ++t) {
		scanf("%d", &n);
		x = y = INF;
		for (i=0; i<n; ++i) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
			if (p[i].x < x) {
				x = p[i].x, y = p[i].y;
				index = i;
			} else if (p[i].x < x + eps && p[i].y < y) {
				x = p[i].x, y = p[i].y;
				index = i;
			}
		}
		swap(p[0], p[index]);
		printf("%s\n", gao(n)?"YES":"NO");
	}
	return 0;
}
