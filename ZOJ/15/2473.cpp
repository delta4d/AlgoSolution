#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 20000;

struct point {
	int x;
	int y;
	point(int _x=0, int _y=0):x(_x), y(_y) {}
} p[MAXN];

set<point> s;

inline bool operator<(const point &a, const point &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

int main() {
	int m, n;
	int i, j, k;
	int x, y;
	int tx, ty;
	int lx, ly, rx, ry;
	int sumx, sumy;
	int lp, rp;
	point temp;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		s.clear();
		sumx = sumy = 0;
		for (i=0; i<n; ++i) {
			scanf("%d %d", &p[i].x, &p[i].y);
			sumx += p[i].x, sumy += p[i].y;
			s.insert(p[i]);
		}
		sumx <<= 1, sumy <<= 1;
		x = sumx / n, y = sumy / n;
		if (x * n != sumx || y * n != sumy) goto next;
		k = (n >> 1) + 1;
		for (i=0; i<k; ++i) {
			tx = x - p[i].x, ty = y - p[i].y;
			if (s.find(point(tx, ty)) == s.end()) break;
		}
		if (i != k) next: puts("This is a dangerous situation!");
		else printf("V.I.P. should stay at (%.1lf,%.1lf).\n", x/2.0, y/2.0); 
		scanf("%d", &n);
	}
	return 0;
}