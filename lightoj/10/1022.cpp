#include <cmath>
#include <cstdio>
using namespace std;

const double mm = 4 - acos(-1.0);

int main() {
	int tc, cn = 0;
	double r;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%lf", &r);
		printf("Case %d: %.2lf\n", ++cn, mm*r*r);
	}
	return 0;
}

// 252155	2013-08-16 10:16:26	 1022 - Circle in Square	 C++	 0.000	 1088	Accepted
