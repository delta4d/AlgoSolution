#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct point {
	double x;
	double y;
	
	bool input() {
		return scanf("%lf %lf", &x, &y) == 2;
	}
};

inline double xmult(point &a0, point &a1, point &a2) {
	//return ((a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y)) / 2.0;
	return a0.x * a1.y + a1.x * a2.y + a2.x * a0.y -
           a1.x * a0.y - a2.x * a1.y - a0.x * a2.y;
}

inline void gravitity_point(point &a, point &b, point &c, double &x, double	&y) {
	x = a.x + b.x + c.x;
	y = a.y + b.y + c.y;
}

int main() {
	int i, j, k;
	int tc;
	int m, n;
	double x, y;
	double sumx, sumy, summ;
	double area;
	point p0, p1, p2;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		p0.input(), p1.input();
		sumx = sumy = summ = 0;
		for (i=2; i<n; ++i) {
			p2.input();
			area = xmult(p0, p1, p2);
			gravitity_point(p0, p1, p2, x, y);
			sumx += x * area;
			sumy += y * area;
			summ += area;
			p1 = p2;
		}
		printf("%.2lf %.2lf\n", sumx/(3.0*summ), sumy/(3.0*summ));
	}
	return 0;
}