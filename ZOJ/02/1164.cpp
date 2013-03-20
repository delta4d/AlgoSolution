#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

inline void gao(LL x) {
	LL i(3), j, k;
	char s[4];
	for (i=3; i>=0; --i) {
		k = x % 16;
		s[i] = k > 9 ? k - 10 + 'A' : k + '0';
		x >>= 4;
	}
	printf("%c%c %c%c\n", s[0], s[1], s[2], s[3]);
}

int main() {
	int i, j, k;
	LL x;
	char ch;
	const int g = 34943;
	//freopen("f:\\in.txt", "r", stdin);
	while ((ch = getchar()) != '#') {
		if (ch == '\n') x = 0;
		else x = ch;
		if (ch != '\n')
		while ((ch = getchar()) != '\n') {
			x <<= 8;
			x += ch;
			x %= g;
		}
		x <<= 16;
		x *= -1;
		x %= g;
		x += g;
		x %= g;
		gao(x);
	}
	return 0;
}