#include <cstdio>
using namespace std;

int x[100];

int main() {
	int tc, cn = 0, n, y;
	for (scanf("%d", &tc); tc--; ) {
		int t = 0;
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d", x+i);
		for (int i=0; i<n; ++i) scanf("%d", &y), t ^= y - x[i] - 1;
		printf("Case %d: %s wins\n", ++cn, t?"white":"black");
	}
	return 0;
}

// 257734	2013-08-31 00:02:54	 1186 - Incredible Chess	 C++	 0.004	 1088	Accepted
