#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int g = 34943;

char buff[1025];

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
	//freopen("f:\\in.txt", "r", stdin);
	gets(buff);
	while (buff[0] != '#') {
		x = 0;
		for (i=0; buff[i]; ++i) {
			x <<= 8;
			x += buff[i];
			x %= g;
		}
		x <<= 16;
		x *= -1;
		x %= g;
		x += g;
		x %= g;
		gao(x);
		gets(buff);
	}
	return 0;
}