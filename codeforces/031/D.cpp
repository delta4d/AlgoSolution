#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 128;
const int INF = 0x3f3f3f3f;

int vx[MAXN], y1[MAXN], y2[MAXN], sv;
int hy[MAXN], x1[MAXN], x2[MAXN], sh;
map <long long, int> cnt;

long long hash(int a, int b, int c, int d) {
	return a * 1367631ll + b * 12321ll + c * 111ll + d;
}

int main() {
	int w, h, n;

	scanf("%d%d%d", &w, &h, &n);
	for (int i=0,x1,y1,x2,y2; i<n; ++i) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 == x2) vx[sv] = x1, ::y1[sv] = y1, ::y2[sv] = y2, ++sv;
		else hy[sh] = y1, ::x1[sh] = x1, ::x2[sh] = x2, ++sh;
	}
	vx[sv] = 0, y1[sv] = 0, y2[sv] = h, ++sv; vx[sv] = w, y1[sv] = 0, y2[sv] = h, ++sv;
	hy[sh] = 0, x1[sh] = 0, x2[sh] = w, ++sh; hy[sh] = h, x1[sh] = 0, x2[sh] = w, ++sh;
	for (int x=0; x<w; ++x) for (int y=0; y<h; ++y) {
		int lx = -INF, rx = INF, dy = -INF, uy = INF;
		for (int i=0; i<sv; ++i) {
			if (vx[i] <= x && y1[i] <= y && y2[i] > y) lx = max(lx, vx[i]);
			if (vx[i] > x && y1[i] <= y && y2[i] > y) rx = min(rx, vx[i]);
		}
		for (int i=0; i<sh; ++i) {
			if (hy[i] <= y && x1[i] <= x && x2[i] > x) dy = max(dy, hy[i]);
			if (hy[i] > y && x1[i] <= x && x2[i] > x) uy = min(uy, hy[i]);
		}
		++cnt[hash(lx, rx, dy, uy)];
//		printf("(%d, %d) => %d %d %d %d\n", x, y, lx, rx, dy, uy);
	}
	vector <int> o;
	for (map<long long,int>::iterator it=cnt.begin(); it!=cnt.end(); ++it) o.push_back(it->second);
	sort(o.begin(), o.end());
	for (int i=0; i<o.size(); ++i) printf("%d ", o[i]);

	return 0;
}

// 3929350	 Jun 20, 2013 8:01:24 PM	delta_4d	 D - Chocolate	 GNU C++	Accepted	 15 ms	 100 KB
