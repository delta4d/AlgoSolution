#include <cstdio>

int main() {
	int a, b, c, d;
	scanf("%d:%d%d:%d", &a, &b, &c, &d);
	a -= c, b -= d;
	if (b < 0) b += 60, --a;
	if (a < 0) a += 24;
	printf("%02d:%02d\n", a, b);
	return 0;
}

// 6571682	 May 8, 2014 2:53:35 PM	delta_4d	 A - George and Sleep	 GNU C++0x	Accepted	 15 ms	 0 KB
