#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 480;

char buff[3];
char f[7][MAXL];

inline void input(int &k) {
	int i;
	k = 0;
	scanf("%s", buff);
	for (i=0; i<2; ++i) {
		k <<= 4;
		if (buff[i] <= '9' && buff[i] >= '0') k += buff[i] - '0';
		else k += buff[i] - 'A' + 10;
	}
}

inline void draw(int x, int s) {
	int i, j, k(1);
	for (i=0; i<7; ++i) {
		j = k & x;
		f[i][s] = (j ? '#' : ' ');
		k <<= 1;
	}
}

int main() {
	int i, j, k;
	int tc, cn(0);
	int m, n;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
		memset(f, ' ', sizeof(f));
		scanf("%d", &n);
		for (j=0; j<n; ++j) {
			for (i=0; i<5; ++i) {
				input(k);
				draw(k, 6*j+i);
			}
		}
		for (i=0,j=6*n-1; i<7; ++i) f[i][j] = '\0';
		printf("Case %d:\n\n", ++cn);
		for (i=0; i<7; ++i) puts(f[i]);
		puts("");
	}
	return 0;
}