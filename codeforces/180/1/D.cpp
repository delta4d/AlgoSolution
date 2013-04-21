#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

char r[MAXN][MAXN], c[MAXN][MAXN];
char f[MAXN][MAXN];

void rcolor(int k, int cc) {
	f[k][0] = cc + '1';
	for (int i=0; r[k][i]; ++i) {
		if (r[k][i] == 'E') f[k][i+1] = cc + '1';
		else cc ^= 1, f[k][i+1] = cc + '1';
	}
}

bool rdiff(int i, int j) {
	return f[i-1][j] == f[i][j] && c[i-1][j] == 'N' || f[i-1][j] != f[i][j] && c[i-1][j] == 'E';
}

void ccolor(int k, int cc) {
	f[0][k] = cc + '1';
	for (int i=0; c[i][k]; ++i) {
		if (c[i][k] == 'E') f[i+1][k] = cc + '1';
		else cc ^= 1, f[i+1][k] = cc + '1';
	}
}

bool cdiff(int i, int j) {
	return f[i][j-1] == f[i][j] && r[i][j-1] == 'N' || f[i][j-1] != f[i][j] && r[i][j-1] == 'E';
}

int main() {
	int h, w, k;
	int eq = 0;

	scanf("%d%d%d", &h, &w, &k);
	for (int i=0; i<h; ++i) {
		scanf("%s", r[i]);
		if (i + 1 < h) scanf("%s", c[i]);
		for (int j=0; r[i][j]; ++j) eq += r[i][j] == 'E';
		for (int j=0; c[i][j]; ++j) eq += c[i][j] == 'E';
	}
	if (k == 1) {
		if (4 * eq >= 3 * ( 2 * w * h - w - h )) {
			puts("YES");
			for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) printf("1%s", j==w-1?"\n":" ");
		} else {
			puts("NO");
		}
		return 0;
	}
	if (h <= w) {
		rcolor(0, 0);
		for (int i=1; i<h; ++i) {
			rcolor(i, 0); int c = 0; for (int j=0; j<w; ++j) c += rdiff(i, j);
			if (c > w - c) rcolor(i, 1);
		}
	} else {
		ccolor(0, 0);
		for (int j=1; j<w; ++j) {
			ccolor(j, 0); int c = 0; for (int i=0; i<h; ++i) c += cdiff(i, j);
			if (c > h - c) ccolor(j, 1);
		}
	}
	puts("YES");
	for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) printf("%c%s", f[i][j], j==w-1?"\n":" ");

	return 0;
}

// 3583366	 Apr 21, 2013 8:19:33 AM	delta_4d	 D - Color the Carpet	 GNU C++	Accepted	 265 ms	 3100 KB
