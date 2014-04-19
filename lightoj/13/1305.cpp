#include <cmath>
#include <cstdio>
using namespace std;

inline double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	int tc, cn = 0, ax, ay, bx, by, cx, cy, dx, dy;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
		dx = ax + cx - bx, dy = ay + cy - by;
		double x = dis(ax, ay, bx, by), y = dis(bx, by, cx, cy), z = dis(cx, cy, ax, ay), p = (x + y + z) / 2;
		double area = 2 * sqrt(p * (p - x) * (p - y) * (p - z));
		printf("Case %d: %d %d %d\n", ++cn, dx, dy, (int)rint(area));
	}
	return 0;
}

// 252284	2013-08-16 20:02:08	 1305 - Area of a Parallelogram	 C++	 0.000	 1100	Accepted
