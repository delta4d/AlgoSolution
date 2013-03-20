#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define RIGHT 1
#define STRAIGHT 0
#define LEFT -1

const int MAXN = 50;

struct point {
	int x, y;
	int index;
	point(int _x=0, int _y=0, int _index=0):x(_x), y(_y), index(_index) {}
	bool input() {
		return scanf("%d %d %d", &index, &x, &y) == 3;
	}
	int xmult(const point &o, const point &a) {
		return (x - o.x) * (a.y - o.y) - (a.x - o.x) * (y - o.y);
	}
	int dis2(const point &a) {
		return (a.x - x) * (a.x - x) + (a.y - y) * (a.y - y);
	}
	int righter(const point &o, const point &a) {
		int ret(xmult(o, x));
		if (ret > 0) return RIGHT;
		return ret == 0 ? STRAIGHT : LEFT;
	}
	void set_inf() {
		
	}
} f[MAXN];

bool visit[MAXN];
int out[MAXN];

inline int min(const int c, const int i, const int j) {
	int k(f[i].righter(f[c], f[j]));
	if (k == RIGHT) return i;
	if (k == LEFT) return j;
	return f[i].dis2(f[c]) < f[j].dis2(f[c]) ? i : j;
}

inline int min(const int i, const int j) {
	if (f[i].x < f[j].x) return i;
	if (f[j].x < f[i].x) return j;
	return f[i].y < f[j].y ? i : j;
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int src;
	int p;
	point temp;
	freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; visit[i++]=false) f[i].input();
		src = 0;
		for (i=1; i<n; ++i) src = min(src, i);
		p = 0;
		visit[out[p++] = src] = true;
		
	}
	return 0;
}