#include <cstdio>

int main() {
	long long x, y, n, t;
	scanf("%I64d %I64d %I64d", &x, &y, &n);
	for (int i=0; i<n; ++i) {
		t = x + y;
		x = y, y = t;
	}
	printf("%I64d\n", x);
	return 0;
}

// 1465419	 Apr 2, 2012 7:24:12 PM	delta_4d	 G - Mysterious numbers - 2	 GNU C++	Accepted	 10 ms	 1400 KB
