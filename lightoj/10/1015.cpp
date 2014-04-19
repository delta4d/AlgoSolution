#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		int tot = 0, x;
		for (int i=0; i<n; ++i) scanf("%d", &x), tot += max(0, x);
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 252153	2013-08-16 10:13:05	 1015 - Brush (I)	 C++	 0.008	 1088	Accepted
