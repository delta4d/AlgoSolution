#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
const double eps = 1e-8;
struct node {
	double l;
	double r;
	node(double l=0, double r=0):l(l), r(r) {}
} f[MAXN];

bool cmp(const node &a, const node &b) {
	if (a.l != b.l) return a.l < b.l;
	return a.r < b.r;
}

inline bool intersect(const node &a, const node &b) {
	return a.r >= b.l && a.r <= b.r || b.r >= a.l && b.r <= a.r;
}

inline int gao(const int n) {
	int i, j, k;
	int r(1);
	sort(f, f+n, cmp);
	for (i=0; i<n-1; ++i) {
		if (intersect(f[i], f[i+1])) {
			f[i+1].r = min(f[i].r, f[i+1].r);
			f[i+1].l = max(f[i].l, f[i+1].l);
		} else {
			++r;
		}
	}
	return r;
}

int main() {
	int i, j, k;
	int n, cn(0);
	double x, y, d;
	double offset;
	bool kegao;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %lf", &n, &d);
	while (n != 0) {
		kegao = true;
		for (i=0; i<n; ++i) {
			scanf("%lf %lf", &x, &y);
			if (kegao) {
				if (y > d) {
					kegao = false;
					continue;
				} else {
					offset = sqrt(d*d-y*y);
					f[i].l = x - offset, f[i].r = x + offset;
				}
			}
		}
		printf("Case %d: ", ++cn);
		printf("%d\n", kegao?gao(n):-1);
		scanf("%d %lf", &n, &d);
	}
	return 0;
}