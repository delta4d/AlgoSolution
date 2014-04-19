#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double a, b, c, k;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &k);
		k = sqrt(k / (k + 1));
		a *= k;
		printf("Case %d: %.10lf\n", ++cn, a);
	}
	return 0;
}

// 256809	2013-08-28 14:43:10	 1043 - Triangle Partitioning	 C++	 0.000	 1100	Accepted
