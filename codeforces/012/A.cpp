#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int i, j, k;
	char s[4][4];
	
	for (i=0; i<3; ++i) scanf("%s", s[i]);
	for (i=0; i<3; ++i) for (j=0; j<3; ++j) {
		if (s[i][j] != s[2-i][2-j]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}

// 911534	 Nov 30, 2011 5:42:42 PM	delta_4d	 A - Super Agent	 GNU C++	Accepted	 30 ms	 1300 KB
