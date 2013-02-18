/*
ID: delta 4d
PROG: milk2
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 5000;
struct interal {
	int x;
	int y;
	bool intersect(const interal a) {
		return (a.x >= x && a.x <= y) || (x >= a.x && x <= a.y);
	}
	int length() {
		return y - x;
	}
} f[MAXN];

inline int cmp(const void *a, const void *b) {
	interal *c = (interal *)a;
	interal *d = (interal *)b;
	if (c->x != d->x) return c->x - d->x;
	return c->y - d->y;
}

int main() {
	int i, j, k;
	int m, n;
	int busy_len, idle_len;
	interal cur;
	//freopen("f:\\in.txt", "r", stdin);
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<n; ++i) scanf("%d %d", &f[i].x, &f[i].y);
		qsort(f, n, sizeof(f[0]), cmp);
		cur = f[0];
		busy_len = cur.length(), idle_len = 0;
		for (i=1; i<n; ++i) {
			if (cur.intersect(f[i])) {
				cur.x = min(cur.x, f[i].x);
				cur.y = max(cur.y, f[i].y);
				busy_len = max(busy_len, cur.length());
			} else {
				idle_len = max(idle_len, f[i].x-cur.y);
				cur = f[i];
			}
		}
		printf("%d %d\n", busy_len, idle_len);
	}
	return 0;
}