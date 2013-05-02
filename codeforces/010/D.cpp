#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 512;

int f[MAXN][MAXN];
int p[MAXN][MAXN];
int x[MAXN], y[MAXN];
int out[MAXN];

int LCIS(int m, int x[], int n, int y[]) {
	int mm = 0, tx, ty;
	memset(f, 0, sizeof(f));
	memset(p, -1, sizeof(p));
	for (int i=1; i<=m; ++i) {
		int mx = 0, k = 0;
		for (int j=1; j<=n; ++j) {
			f[i][j] = f[i-1][j];
			if (x[i] == y[j]) f[i][j] = mx + 1, p[i][j] = k;	
			else if (x[i] > y[j] && f[i-1][j] > mx) mx = f[i-1][j], k = j;
			if (mm < f[i][j]) mm = f[i][j], tx = i, ty = j;	
		}
	}
	for (int i=mm; i; --tx) {
		if (p[tx][ty] >= 0) out[--i] = y[ty], ty = p[tx][ty];
	}
	return mm;
}

int main() {
	int m, n;
	int mm = 0;
	
	scanf("%d", &m); for (int i=1; i<=m; ++i) scanf("%d", x+i);
	scanf("%d", &n); for (int i=1; i<=n; ++i) scanf("%d", y+i);
	mm = LCIS(m, x, n, y);
	printf("%d\n", mm);
	for (int i=0; i<mm; ++i) printf("%d%s", out[i], i-mm+1?" ":"\n");

	return 0;
}

// 3660115	 May 2, 2013 3:49:07 PM	delta_4d	 D - LCIS	 GNU C++	Accepted	31 ms	2040 KB
