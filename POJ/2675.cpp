#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = (1 << 16) + 1;
const double eps = 1e-8;

struct node {
	int x;
	double l;
	double f;
} a[MAXN];

inline bool cmp(const node &a, const node &b) {
	if (fabs(a.f * b.l - b.f * a.l) > eps) return a.f * b.l > b.f * a.l;
	return a.x < b.x;
}

int main() {
	int m, n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<n; ++i) scanf("%d %lf %lf", &a[i].x, &a[i].l, &a[i].f);
		scanf("%d", &k);
		sort(a, a+n, cmp);
		printf("%d\n", a[k-1].x);
	}
	return 0;
}