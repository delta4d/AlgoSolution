#include <cstdio>

int rev(int x) {
	int ret(0);
	while (x) ret = ret * 10 + x % 10, x /= 10;
	return ret;
}

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d\n", x+rev(y));
	return 0;
}

// 1465079	 Apr 2, 2012 6:08:05 PM	delta_4d	 A - Mysterious numbers - 1	 GNU C++	Accepted	 30 ms	 1400 KB
