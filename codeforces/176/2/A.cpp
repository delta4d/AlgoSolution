#include <cstdio>
using namespace std;

int main() {
	char s[4][5];

	for (int i=0; i<4; ++i) scanf("%s", s[i]);
	for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) {
		int cc = (s[i][j] == '.') + (s[i][j+1] == '.') + (s[i+1][j] == '.') + (s[i+1][j+1] == '.');
		if (cc != 2) { puts("YES"); return 0; }
	}
	puts("NO");

	return 0;
}

// 3400159	 Mar 24, 2013 4:47:23 PM	delta_4d	 287A - IQ Test	 GNU C++	Accepted	 15 ms	 0 KB
