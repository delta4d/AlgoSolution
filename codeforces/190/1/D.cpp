#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 34;

int n, m;
int f[MAXN][MAXN], s[MAXN][MAXN];

int gao(int j) {
	s[m][m+1+j] = s[m][j] * s[m][m];
	int tot = s[m][j] * f[m][j] + s[m][m+1+j] * f[m][m+1+j];
	for (int i=0; i<m; ++i) {
		int x = f[i][j] + s[i][m] * f[i][m+j+1] + s[m][j] * f[m+i+1][j] + s[i][m] * s[m][m+j+1] * f[m+i+1][m+j+1];
		tot += abs(x);
	}
	return tot;
}

int gao() {
	int tot = 0;
	for (int i=0,x1,x2; i<m; ++i) {
		s[m][i] = 1, x1 = gao(i);
		s[m][i] = -1, x2 = gao(i);
		tot += max(x1, x2);
	}
	return tot;
}

int main() {
	scanf("%d", &n), m = n >> 1;
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) scanf("%d", f[i]+j);
	int mx = 0;
	for (int mask=0,lim=1<<(m+1); mask<lim; ++mask) {
		for (int i=0; i<=m; ++i) s[i][m] = (mask & 1 << i) ? -1 : 1;
		for (int i=m+1; i<n; ++i) s[i][m] = s[m][m] * s[i-m-1][m];
		int cc = 0;
		for (int i=0; i<n; ++i) cc += s[i][m] * f[i][m];
		mx = max(mx, gao()+cc);
	}
	printf("%d\n", mx);
	return 0;
}

// 3996028	 Jun 30, 2013 6:06:29 PM	delta_4d	 D - Ciel and Flipboard	 GNU C++	Accepted	 656 ms	 0 KB
