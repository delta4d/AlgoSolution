#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXN = 51;
struct point {
	int x;
	int y;
	void PRINT() {
		printf("(%d,%d)\n", x, y);
	}
}p[MAXN];
char buff[16];

inline void to_dec(const int n) {
	int len(strlen(buff));
	int i(0);
	int res(0);
	int sign(1);
	if (buff[0] == '-') {
		sign = -1;
		++i;
	}
	for (; buff[i]!=' '; ++i) res = res * 10 + buff[i] - '0';
	p[n].x = res * sign;
	++i;
	res = 0;
	if (buff[i] == '-') {
		sign = -1;
		++i;
	}
	for (; i<len; ++i) res = res * 10 + buff[i] - '0';
	p[n].y = res * sign;
}

inline int cross_product(const point &a, const point &b, const point &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int cmp(const void *a, const void *b) {
	point *c = (point *)a;
	point *d = (point *)b;
	if (cross_product(p[0], *c, *d) < 0) return 1;
	return -1;
}

int main() {
	int tc;
	int n(0);
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &p[n].x, &p[n].y) != EOF) ++n;
	qsort(p+1, n-1, sizeof(p[0]), cmp);
	for (i=0; i<n; ++i) p[i].PRINT();
	return 0;
}