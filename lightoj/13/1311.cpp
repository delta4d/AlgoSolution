#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		double v1, v2, v3, a1, a2;
		scanf("%lf%lf%lf%lf%lf", &v1, &v2, &v3, &a1, &a2);
		double d = (v1 * v1 / a1 + v2 * v2 / a2) / 2, db = max(v1/a1, v2/a2) * v3;
		printf("Case %d: %.10lf %.10lf\n", ++cn, d, db);
	}
	return 0;
}

// 253080	2013-08-18 23:13:40	 1311 - Unlucky Bird	 C++	 0.000	 1088	Accepted
