#include <cstdio>
using namespace std;

const int MAXN = 100000 + 86;

char s[MAXN];

int main() {
	scanf("%s", s);
	for (int i=0; s[i]; ++i) if (s[i] == '0') {
		for (int k=0; k<i; ++k) printf("%c", s[k]);
		for (int k=i+1; s[k]; ++k) printf("%c", s[k]);
		puts("");
		return 0;
	}
	puts(s+1);
	return 0;
}

// 3764205	 May 24, 2013 5:30:14 PM	delta_4d#	 A - Little Elephant and Bits	 GNU C++	Accepted	 15 ms	 100 KB
