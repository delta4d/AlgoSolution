#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double L, W, x;
		scanf("%lf%lf", &L, &W);
		x = (W + L - sqrt(W * W + L * L - L * W)) / 6;
		printf("Case %d: %.10lf\n", ++cn, x*(L-2*x)*(W-2*x));
	}
	return 0;
}

// 253249	2013-08-19 16:13:44	 1297 - Largest Box	 C++	 0.024	 1100	Accepted
