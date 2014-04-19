#include <cmath>
#include <cstdio>
using namespace std;

const double PI = acos(-1.0);

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		double R;
		scanf("%lf%d", &R, &n);
		printf("Case %d: %.10lf\n", ++cn, R/(1+1/sin(PI/n)));
	}
	return 0;
}

// 252180	2013-08-16 13:43:15	 1072 - Calm Down	 C++	 0.000	 1196	Accepted
