#include <cstdio>
using namespace std;

int x[20]={2};

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		int tot = 0;
		for (int i=1; i<=n; ++i) scanf("%d", x+i);
		for (int i=1; i<=n; ++i) tot += (x[i] - x[i-1] + 4) / 5;
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 252305	2013-08-16 20:53:34	 1241 - Pinocchio	 C++	 0.000	 1088	Accepted
