#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
const double PI2 = 2 * acos(-1.0);
const int MAXN = 128;

struct point {
	int x, y;
	point(int _x=0, int _y=0):x(_x), y(_y) {}
	bool input() {
		return scanf("%d %d",&x, &y) == 2;
	}
	bool equal(point &a) {
		return x == a.x && y == a.y;
	}
} f[MAXN], t;

inline double dis2(point &a, point &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

inline double dis(point &a, point &b) {
	return sqrt(dis2(a, b));
}

inline int xmult(point &o, point &a, point &b) {
	int t =  (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
	return t < 0 ? -1 : (t > 0 ? 1 : 0);
}

inline double angle(point &o, point &x, point &y) {
	return xmult(o,x,y)*acos((dis2(o,x)+dis2(o,y)-dis2(x,y))/(2.0*dis(o,x)*dis(o,y)));
}

inline bool gao(const int n) {
	int i, j, k;
	double sum(0.0), temp;
	for (i=0; i<n; ++i) if (xmult(t, f[i], f[i+1]) == 0 && t.x >= min(f[i].x, f[i+1].x) && t.x <= max(f[i].x, f[i+1].x)) return true;
	for (i=0; i<n; ++i) {
		sum += (temp = angle(t, f[i], f[i+1]));
	}
	sum = fabs(sum);
	return fabs(sum-PI2) < eps;
}

int main() {
	int i, j, k;
	int m, n;
	int cn(0);
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (true) {
		scanf("%d", &m);
		for (i=0; i<n; ++i) f[i].input();
		f[n] = f[0];
		printf("Problem %d:\n", ++cn);
		for (i=0; i<m; ++i) {
			t.input();
			puts(gao(n)?"Within":"Outside");
		}
		scanf("%d", &n);
		if (n == 0) break;
		puts("");
	}
	return 0;
}