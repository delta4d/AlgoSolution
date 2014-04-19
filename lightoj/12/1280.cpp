#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	double x, y;
	node(double _x=0, double _y=0):x(_x), y(_y) {}
	void readin() { scanf("%lf%lf", &x, &y); }
} f[20000 + 86];

double z;

inline bool cmp(const node &a, const node &b) {
	return a.x - z * a.y >= b.x - z * b.y;
}

int main() {
	int tc, cn = 0, n, d;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &d), d = n - d;
		for (int i=0; i<n; ++i) f[i].readin();
		double l = 0, r = 1;
		for (int k=0; k<30; ++k) {
			z = (l + r) / 2;
			double x = 0, y = 0;
			sort(f, f+n, cmp);
			for (int i=0; i<d; ++i) x += f[i].x, y += f[i].y;
			if (x >= y * z) l = z;
			else r = z;
		}
		printf("Case %d: %.10lf\n", ++cn, z*100);
	}
	return 0;
}

// 282801	2013-11-03 20:22:08	 1280 - Best Grade	 C++	 1.568	 1404	Accepted
