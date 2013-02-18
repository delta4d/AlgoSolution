#include <cstdio>
using namespace std;

int main() {
	int i, j, k;
	int x, y;
	char s[2][3], a, b;

	scanf("%s%s", s[0], s[1]);
	x = s[0][0] - s[1][0], y = s[0][1] - s[1][1];
	a = x > 0 ? 'L' : 'R';
	b = y > 0 ? 'D' : 'U';
	x = x > 0 ? x : -x;
	y = y > 0 ? y : -y;
	printf("%d\n", x>y?x:y);
	while (x | y) {
		if (x) { printf("%c", a); --x; }
		if (y) { printf("%c", b); --y; }
		puts("");
	}

	return 0;
}

//#		When	Who	Problem	Lang	Verdict	Time	Memory
//2902822	 Jan 10, 2013 7:31:45 PM	delta_4d	 A - Shortest path of the king	 GNU C++	Accepted	15 ms	0 KB
