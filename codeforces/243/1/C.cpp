#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;
int const INF = 0x3f3f3f3f;

vector <int> x[N];
int a[N];
int f[N][301];

int id(int v, int l) {
	auto it = upper_bound(begin(x[v]), end(x[v]), l);
	if (it == end(x[v])) return INF;
	return *it;
}

int main() {
	int m, n, s, e, mx = 0;
	scanf("%d%d%d%d", &m, &n, &s, &e);
	for (int i=1; i<=m; ++i) scanf("%d", a+i);
	for (int i=1,k; i<=n; ++i) scanf("%d", &k), x[k].push_back(i);
	for (int i=0; i<N; ++i) sort(begin(x[i]), end(x[i]));
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for (int i=0; i<m; ++i) for (int j=0; j<300; ++j) if (f[i][j] < INF) {
		f[i+1][j] = min(f[i][j], f[i+1][j]);
		f[i+1][j+1] = min(f[i+1][j+1], id(a[i+1], f[i][j]));
	}
	for (int i=1; i<=m; ++i) for (int j=1; j<=300; ++j) if (f[i][j] < INF) {
		int rem = s - j * e;
		if (rem >= i + f[i][j]) mx = max(mx, j);
	}
	printf("%d\n", mx);
	return 0;
}

// 7305164	2014-08-01 11:33:42	delta_4d	C - Sereja and Two Sequences	GNU C++0x	Accepted	811 ms	121108 KB
