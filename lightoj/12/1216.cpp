#include <cmath>
#include <cstdio>
using namespace std;

const double PI = acos(-1.0);

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double r1, r2, h, p, H;
		scanf("%lf%lf%lf%lf", &r1, &r2, &h, &p);
		r1 = p / h * (r1 - r2) + r2;
		H = p / (1 - r2 / r1);
		double area = PI * (r1 * r1 * H - r2 * r2 * (H - p)) / 3;
		printf("Case %d: %.10lf\n", ++cn, area);
	}
	return 0;
}

// 252573	2013-08-17 18:48:08	 1216 - Juice in the Glass	 C++	 0.000	 1088	Accepted
