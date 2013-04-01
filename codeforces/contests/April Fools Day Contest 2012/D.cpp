#include <cstdio>
#include <cassert>

int main() {
	int x;
	scanf("%d", &x);
	if (x == 5) puts("1");
	else printf("%d\n", x%3+1);
	return 0;
}

// 1465127	 Apr 2, 2012 6:17:44 PM	delta_4d	 D - Broken checker	 GNU C++	Accepted	 10 ms	 1400 KB
