#include <cmath>
#include <cstdio>
using namespace std;

inline int f(int a, int b) { return 19 + (a + abs(a - b)) * 4; }

int main() {
	int tc, cn = 0, a, b;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &a, &b);
		printf("Case %d: %d\n", ++cn, f(a, b));
	}
	return 0;
}

// 252157	2013-08-16 10:30:59	 1069 - Lift	 C++	 0.000	 1088	Accepted
