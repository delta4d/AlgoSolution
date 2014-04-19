#include <cstdio>
#include <algorithm>
using namespace std;

const int d[] = {0, 2, 4, 4};

int main() {
	int tc, cn = 0, m, n, x;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &m, &n);
		if (m > n) swap(m, n);
		if (m == 1) x = n;
		else if (m == 2) x = n / 4 * 4 + d[n&3];
		else x = (m * n + 1) >> 1;
		printf("Case %d: %d\n", ++cn, x);
	}
	return 0;
}

// 252586	2013-08-17 19:42:07	 1010 - Knights in Chessboard	 C++	 0.028	 1088	Accepted
