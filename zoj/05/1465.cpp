#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const double PI = 3.1415926;
const double INF = 9876543210.0;
const double eps = 1e-10;
const int MAXN = 1001;
struct point {
	double x;
	double y;
};
point p[MAXN];
point stack[MAXN];

inline void swap(point &a, point &b) {
	point t;
	t = a; a = b; b = t;
}

inline double dis(const point &a, const point &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline double cross_product(const point &a, const point &b, const point &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline int cmp(const void *a, const void *b) {
	point *c = (point *)a;
	point *d = (point *)b;
	double cp(cross_product(p[0], *c, *d));
	if (cp < 0) return 1;
	if (cp < eps && dis(p[0], *c) < dis(p[0], *d)) return 1;
	return -1;
}

inline double gao(const int n, int l) {
	int i, j, k;
	int top(3);
	double len(0.0);
	qsort(p+1, n-1, sizeof(p[0]), cmp);
	for (i=0; i<3; ++i) stack[i] = p[i];
	for (; i<n; ++i) {
		while (cross_product(stack[top-2], stack[top-1], p[i]) < 0) --top;
		stack[top] = p[i];
		++top;
	}
	for (i=0; i<top-1; ++i) len += dis(stack[i], stack[i+1]);
	len += dis(stack[top-1], stack[0]);
	len += 2.0 * PI * (double)l;
	return len;
}

int main() {
	int i, j, k, t;
	int N, L;
	int tc;
	int index;
	double x, y;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (t=0; t<tc; ++t) {
		scanf("%d %d", &N, &L);
		x = INF, y = INF;
		for (i=0; i<N; ++i) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
			if (p[i].x < x || (p[i].x == x && p[i].y < y)) {
				x = p[i].x, y = p[i].y;
				index = i;
			}
		}
		swap(p[0], p[index]);
		printf("%.0lf\n", gao(N, L));
		if (t < tc - 1) puts("");
	}
	return 0;
}
