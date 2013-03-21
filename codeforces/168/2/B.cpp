#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 64;

char s[MAXN][MAXN];
int R[MAXN][MAXN], C[MAXN][MAXN];

bool ok(int a, int b, int x, int y) {
	if (b > y) { swap(a, x); swap(b, y); }
	if (a > x) return C[x][b] >= a && R[x][b] >= y || C[x][y] >= a && R[a][b] >= y;
	return R[a][b] >= y && C[a][y] >= x || C[a][b] >= x && R[x][b] >= y;
}

int main() {
	int m, n;

	scanf("%d%d", &m, &n);
	for (int i=0; i<m; ++i) scanf("%s", s[i]);
	for (int i=0,j; i<m; ++i) {
		R[i][n-1] = n - 1;
		for (j=n-2; j>=0; --j) {
			if (s[i][j+1] == 'B') R[i][j] = R[i][j+1];
			else R[i][j] = j;
		}
		for (j=n-1; j>=0; --j) if (s[i][j] == 'W') R[i][j] = -1;
	}
	for (int j=0,i; j<n; ++j) {
		C[m-1][j] = m - 1;
		for (i=m-2; i>=0; --i) {
			if (s[i+1][j] == 'B') C[i][j] = C[i+1][j];
			else C[i][j] = i;
		}
		for (i=m-1; i>=0; --i) if (s[i][j] == 'W') C[i][j] = -1;
	}
//	for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) printf("%d%s", R[i][j], j==n-1?"\n":" ");
//	for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) printf("%d%s", C[i][j], j==n-1?"\n":" ");
	for (int i=0,j,x,y; i<m; ++i) for (j=0; j<n; ++j) if (s[i][j] == 'B') {
		for (x=0; x<m; ++x) for (y=0; y<n; ++y) if (s[x][y] == 'B') if (!ok(i, j, x, y)) {
//			printf("%d %d %d %d\n", i, j, x, y);
			puts("NO");
			return 0;
		}
	}
	puts("YES");

	return 0;
}

// 3363263	 Mar 21, 2013 8:19:50 AM	delta_4d	 B - Convex Shape	 GNU C++	Accepted	 46 ms	 0 KB
