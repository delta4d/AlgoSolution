#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double a, b, d, r;
		scanf("%lf : %lf", &a, &b);
		r = sqrt(a * a + b * b);
		d = 2 * acos(a / r);
		double k = 400 / (2 * a + d * r);
		printf("Case %d: %.10lf %.10lf\n", ++cn, k*a, k*b);
	}
	return 0;
}

// 258831	2013-09-02 20:04:31	 1056 - Olympics	 C++	 0.004	 1224	Accepted
