#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int const N = 101;

int m, n, p;
ll a[N][2];
int t[N][N], tmp[N][N];

int f(ll mask0, ll mask1) {
	int ret = 0;
	for (int i=0; i<m; ++i) {
		int j = __builtin_popcountll(mask0^a[i][0]) + __builtin_popcountll(mask1^a[i][1]);
		ret += min(n-j, j);
	}
	return ret;
}

int main() {
	scanf("%d%d%d", &m, &n, &p);
	for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) scanf("%d", tmp[i]+j), t[i][j] = tmp[i][j];
	if (m < n) {
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) t[j][i] = tmp[i][j];
		swap(m, n);
	}
	for (int i=0; i<m; ++i) {
		for (int j=0; j<50&&j<n; ++j) a[i][0] = (a[i][0] << 1) + t[i][j];
		for (int j=50; j<100&&j<n; ++j) a[i][1] = (a[i][1] << 1) + t[i][j];
	}
	int mn = INT_MAX;
	if (m <= p) for (int mask=(1<<n)-1; mask>=0; --mask) mn = min(mn, f(mask, 0));
	else for (int i=0; i<m; ++i) mn = min(mn, f(a[i][0], a[i][1]));
	printf("%d\n", mn<=p?mn:-1);
	return 0;
}

// 7297772	2014-07-31 11:55:31	delta_4d	B - Sereja and Table	GNU C++0x	Accepted	31 ms	92 KB
