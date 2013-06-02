#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 311;
const LL INF = 0x3f3f3f3f3f3f3f3fll;

LL f[MAXN][MAXN], c[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false);

	int n, m, t;
	cin >> n >> m >> t;
	for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j) f[i][j] = c[i][j] = INF;
	for (int i=0,a,b,cc; i<m; ++i) {
		cin >> a >> b >> cc;
		c[a][b] = min(c[a][b], (LL)cc);
	}
	for (int k=n-2; k>=0; --k) {
		for (int i=1; i+k<=n; ++i) {
			int j = i + k;
			if (i > 1) c[i][j] = min(c[i][j], c[i-1][j]);
			if (j < n) c[i][j] = min(c[i][j], c[i][j+1]);
		}
	}
	for (int i=0; i<=n; ++i) for (int j=0; j<=i; ++j) {
		for (int k=1; i+k<=n; ++k) {
			f[i+k][j+k] = min(f[i+k][j+k], f[i][j] + c[i+1][i+k]);
			f[i+k][j] = min(f[i+k][j], f[i][j]);
		}
	}
	LL mn = INF;
	for (int i=t; i<=n; ++i) mn = min(mn, f[n][i]);
	if (mn == INF) mn = -1;
	cout << mn << endl;

	return 0;
}

// 3808034	 May 31, 2013 8:09:18 PM	delta_4d	 D - Ilya and Roads	 GNU C++	Accepted	140 ms	1516 KB
