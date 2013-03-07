#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

struct node {
	int x, y;
	node(int _x=0, int _y=0):x(_x), y(_y) {} 
	void input() {scanf("%d %d", &x, &y); }
} sx[MAXN], sy[MAXN];
int n, R;

inline bool cmpx(const node &a, const node &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

inline bool cmpy(const node &a, const node &b) {
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}

int gao() {
	int i, j, k;
	int ret(0), cc;
	int xmin, xmax, ymin, ymax;
	
	for (xmin=xmax=0; xmax<n; ++xmax) {
		if (sx[xmax].x - sx[xmin].x > R) while (sx[xmax].x - sx[xmin].x > R) ++xmin;
		for (cc=ymin=ymax=0; ymax<n; ++ymax) {
			if (sx[xmin].x <= sy[ymax].x && sy[ymax].x <= sx[xmax].x) ++cc;
			if (sy[ymax].y - sy[ymin].y > R) while (sy[ymax].y - sy[ymin].y > R) {
				if (sx[xmin].x <= sy[ymin].x && sy[ymin].x <= sx[xmax].x) --cc;
				++ymin;
			}
			ret = max(ret, cc);
		}
	}
	return ret;
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (2 == scanf("%d %d", &n, &R)) {
		for (int i=0; i<n; ++i) {
			sx[i].input();
			sy[i] = sx[i];
		}
		sort(sx, sx+n, cmpx);
		sort(sy, sy+n, cmpy);
		printf("%d\n", gao());
	}
	return 0;
}