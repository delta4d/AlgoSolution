#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const double INF = 987654321.0;
const double eps = 1e-10;
const int MAXN = 101;
struct point {
	double x;
	double y;
	point(double x=0, double y=0):x(x), y(y) {}
}p[MAXN];
point stack[MAXN];

inline void swap(const int x, const int y) {
	point temp;
	temp = p[x], p[x] = p[y], p[y] = temp;
}

inline double dis(const point &a, const point &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline double cross_product(const point &a, const point &b, const point &c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int cmp(const void *a, const void *b) {
	point *c = (point *)a;
	point *d = (point *)b;
	double cp(cross_product(p[0], *c, *d));
	if (cp < 0) return 1;
	if (cp < eps && dis(p[0], *c) > dis(p[0], *d)) return 1;
	return -1;
}

double gao(const int &n) {
	int i, j, k;
	int top(0);
	double len(0.0);
	qsort(p+1, n-1, sizeof(p[0]), cmp);
	for (i=0; i<n; ++i) {
		if (i < 3) {
			stack[top] = p[i];
			++top;
			continue;
		}
		while (cross_product(stack[top-2], stack[top-1], p[i]) <= 0) 
			--top;
		stack[top] = p[i];
		++top;
	}
	for (i=0; i<top-1; ++i) len += dis(stack[i], stack[i+1]);
	len += dis(stack[0], stack[top-1]);
	return len;
}

int main() {
	int i, j, k;
	int n;
	int index;
	double x, y;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		x = INF, y = INF;
		for (i=0; i<n; ++i) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
			if (p[i].x < x || (p[i].x == x && p[i].y < p[index].y)) {
				x = p[i].x, y = p[i].y;
				index = i;
			}
		}
		swap(0, index); 
		if (n == 1) printf("0.00\n");
		else if (n == 2) printf("%.2lf\n", 2.0*dis(p[0], p[1]));
		else printf("%.2lf\n", gao(n));
		scanf("%d", &n);
	}
	return 0;
}
