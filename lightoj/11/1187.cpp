#include <cstdio>

int main() {
	int tc, cn = 0, n, rm;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n), rm = 0;
		for (int i=0,x; i<n; ++i) {
			scanf("%d", &x), x -= i;
			if (i && (x == 0 || x + rm >= 0)) ++rm;
		}
		printf("Case %d: %d\n", ++cn, rm+1);
	}
	return 0;
}

// 322701	2014-02-12 20:43:22	 1187 - Lining up Students	 C++	 0.156	 1088	Accepted
