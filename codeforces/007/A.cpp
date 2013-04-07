nclude <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[16][16];

int main() {
	int i, j, k;
	int m, n;
	int tot(0);
	
	for (i=0; i<8; ++i) scanf("%s", s[i]);
	for (i=0; i<8; ++i) {
		for (j=0; j<8; ++j) if (s[i][j] != 'B') break;
		if (j == 8) {
			for (j=0; j<8; ++j) s[i][j] = '*';
			++tot;
		}
	}
	for (j=0; j<8; ++j) {
		for (k=i=0; i<8; ++i) if (s[i][j] == 'B') ++k;
		if (k != 0) ++tot;
	}
	printf("%d\n", tot);
	return 0;
}

// 935174	 Dec 8, 2011 9:41:44 AM	delta_4d	 A - Kalevitch and Chess	 GNU C++	Accepted	 30 ms	 1300 KB
