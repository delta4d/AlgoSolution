#include <bits/stdc++.h>
using namespace std;

int const N = 100;

int f[N][N][11];
char x[N][N+1];

int main() {
	int m, n, K;
	scanf("%d%d%d", &m, &n, &K), ++K;
	for (int i=0; i<m; ++i) scanf("%s", x[i]);
	memset(f, -1, sizeof(f));
	for (int i=0; i<n; ++i) f[0][i][(x[0][i]-'0')%K] = x[0][i] - '0';
	for (int i=0; i+1<m; ++i) {
		for (int j=0; j<n; ++j) {
			for (int k=0; k<K; ++k) {
				int cc = f[i][j][k];
				if (cc == -1) continue;
				if (j > 0) {
					int pk = (k + x[i+1][j-1] - '0') % K;
					f[i+1][j-1][pk] = max(f[i+1][j-1][pk], cc+x[i+1][j-1]-'0');
				}
				if (j + 1 < n) {
					int pk  = (k + x[i+1][j+1] - '0') % K;
					f[i+1][j+1][pk] = max(f[i+1][j+1][pk], cc+x[i+1][j+1]-'0');
				}
			}
		}
	}
	int c = 0;
	for (int i=0; i<n; ++i) if (f[m-1][i][0] > f[m-1][c][0]) c = i;
	if (f[m-1][c][0] == -1) return puts("-1"), 0;
	assert(f[m-1][c][0] % K == 0);
	printf("%d\n", f[m-1][c][0]);
	printf("%d\n", c+1);
	for (int i=m-1,k=0; i>0; --i) {
		int y = x[i][c] - '0', pk = (k - y) % K;
		if (pk < 0) pk += K;
		if (c > 0 && f[i-1][c-1][pk] + y == f[i][c][k]) printf("L"), --c;
		else printf("R"), ++c;
		k = pk;
	}
	return 0;
}

-- 7214461	2014-07-24 11:26:14	delta_4d	D - Pawn	GNU C++0x	Accepted	62 ms	400 KB
