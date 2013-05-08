#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	int n, m, x;
	int tot = 0, mn = INF, minus = 0;

	scanf("%d", &n), m = (n << 1) - 1;
	for (int i=0; i<m; ++i) {
		scanf("%d", &x);
		if (x < 0) ++minus, x = -x;
		tot += x;
		if (x < mn) mn = x;
	}
	if (n % 2 == 0 && minus % 2 == 1) tot -= (mn << 1);
	printf("%d\n", tot);

	return 0;
}

// 3684538	 May 6, 2013 9:17:20 AM	delta_4d	 A - Yaroslav and Sequence	 GNU C++	Accepted	15 ms	0 KB
