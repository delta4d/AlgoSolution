#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 512;

int f[MAXN][MAXN];

struct point {
	int x, y;
	point(int _x=0, int _y=0):x(_x), y(_y) {}
	bool operator<(const point &a) const { return x != a.x ? x < a.x : y < a.y; }
} p[MAXN<<1];

bool left(const point &a, const point &b, const point &c) {
	return (LL)(b.x - a.x) * (c.y - a.y) - (LL)(c.x - a.x) * (b.y - a.y) < 0;
}

bool in(const point &a, const point &b, const point &c) {
	return a.x < c.x && c.x <= b.x;
}

int main() {
	int m, n;

	scanf("%d%d", &n, &m), m += n;
	for (int i=0; i<m; ++i) scanf("%d%d", &p[i].x, &p[i].y);
	sort(p, p+n);
	for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) for (int k=n; k<m; ++k) {
		f[i][j] += left(p[i], p[j], p[k]) && in(p[i], p[j], p[k]);		
	}
	int tot = 0;
	for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) for (int k=j+1; k<n; ++k) {
		tot += (f[i][j] + f[j][k] == f[i][k]);
//		if (f[i][j] + f[j][k] == f[i][k]) printf("%d %d %d\n", i, j, k);
	}
	printf("%d\n", tot);

	return 0;
}

// 3668086	 May 4, 2013 3:42:51 PM	delta_4d	 D - Triangles	 GNU C++	Accepted	920 ms	1012 KB
