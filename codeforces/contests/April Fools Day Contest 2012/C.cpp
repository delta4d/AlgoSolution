#include <cstdio>

int main() {
	int x, n;
	int tot(0);

	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", &x), tot += i * x;
	printf("%d\n", tot);
	return 0;
}

// 1465434	 Apr 2, 2012 7:26:57 PM	delta_4d	 C - A Piece of Cake	 GNU C++	Accepted	 30 ms	 1400 KB
