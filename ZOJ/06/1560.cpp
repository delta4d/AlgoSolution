#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
const double PI = acos(-1.0);
const double PER = PI / 180.0;

struct point {
	double x;
	double y;
	
	point(double _x=0, double _y=0):x(_x), y(_y) {}
	bool input() {
		return scanf("%lf %lf", &x, &y) == 2;
	}
	void output() {
		printf("%.4lf %.4lf\n", x, y);
	}
	void set_a(double	_x, double _y) {
		x = _x, y = _y;
	}
};

struct line {
	double a, b, c;
	
	line(double _a=0, double _b=0, double _c=0):a(_a), b(_b), c(_c) {}
	bool input() {
		point re;
		double alpha;
		double k;
		if (!re.input()) return false;
		if (scanf("%lf", &alpha) != 1) return false;
		if (fabs(alpha) < eps) {
			a = 1.0;
			b = 0.0;
			c = re.x;
		} else {
			if (alpha < 90) alpha = 90.0 - alpha;
			else if (alpha < 270) alpha = 270 - alpha;
			else alpha = 450 - alpha;
			alpha *= PER;
			a = tan(alpha);
			b = -1.0;
			c = a * re.x - re.y;
		}
		return true;
	}
	double xmult(double	x11, double	x12, double	x21, double	x22) {
		return x11 * x22 - x12 * x21;
	}
	point intersect(line &r) {
		point ret;
		ret.x = xmult(c, b, r.c, r.b) / xmult(a, b, r.a, r.b);
		ret.y = xmult(a, c, r.a, r.c) / xmult(a, b, r.a, r.b);
		return ret;
	}
};

int main() {
	int i, j, k;
	int m, n;
	int tc;
	line a, b;
	point x;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		a.input();
		b.input();
		x = a.intersect(b);
		x.output();
	}
	return 0;
}