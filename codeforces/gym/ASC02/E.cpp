#include <bits/stdc++.h>
using namespace std;

int const INF = 0x3f3f3f3f;
int x[1001];
int y[128][128], f[1001][128], pi[1001][128], pj[1001][128];
vector <int> p;

int main() {
#ifdef ONLINE_JUDGE
	freopen("quant.in", "r", stdin);
	freopen("quant.out", "w", stdout);
#endif
	int m, n, s;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	scanf("%d%d", &m, &s);
	for (int i=0; i<m; ++i) for (int j=0; j<s; ++j) scanf("%d", y[i]+j);
	memset(f, 0x3f, sizeof(f));
	memset(pi, 0xff, sizeof(pi));
	memset(pj, 0xff, sizeof(pj));
	for (int i=0; i<s; ++i) {
		int cc = abs(y[0][i] - x[0]), j = i & (m - 1);
		if (cc < f[0][j]) f[0][j] = cc, pi[0][j] = 0, pj[0][j] = i;
	}
	for (int k=1; k<n; ++k) {
		for (int i=0; i<m; ++i) for (int j=0; j<s; ++j) {
			int cc = abs(x[k] - y[i][j]) + f[k-1][i], t = j & (m - 1);
			if (cc < f[k][t]) f[k][t] = cc, pi[k][t] = i, pj[k][t] = j;
		}
	}
	int mn = INF, r = -1;
	for (int i=0; i<m; ++i) if (f[n-1][i] < mn) mn = f[n-1][i], r = i;
	printf("%d\n", mn);
	for (int k=n-1; k>=0; --k) {
		p.push_back(pj[k][r]);
		r = pi[k][r];
	}
	for (int i=n-1; i>=0; --i) printf("%d%s", p[i], i?" ":"\n");
	return 0;
}

// 6983740	 2014-06-30 09:09:45	delta_4d	 E - Quantization Problem	 GNU C++0x	Accepted	92 ms	1764 KB
