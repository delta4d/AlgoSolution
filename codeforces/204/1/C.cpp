#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll const INF = 0x3f3f3f3f3f3f3f3fll;
int const N = 21;

int a[N], b[N];
ll f[N][N], t[N][N];

void matrix_mul(ll A[][N], ll B[][N], const int n) {
	ll ret[N][N];
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
		ret[i][j] = INF;
		for (int k=0; k<n; ++k) ret[i][j] = min(ret[i][j], A[i][k]+B[k][j]);
	}
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) A[i][j] = ret[i][j];
}

void matrix_power(ll mat[][N], int e, const int n) {
	ll ret[N][N];
	memset(ret, 0x3f, sizeof(ret));
	ret[0][0] = 0;
	for (; e; e>>=1) {
		if (e & 1) matrix_mul(ret, mat, n);
		matrix_mul(mat, mat, n);
	}
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) mat[i][j] = ret[i][j];
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	for (int i=0; i<n; ++i) scanf("%d", b+i);
	for (int k=0; k<=n; ++k) {
		memset(t, 0x3f, sizeof(t));
		t[0][k] = 0;
		for (int i=0; i<n; ++i) for (int j=0; j<=n; ++j) if (t[i][j] < INF) {
			if (j + 1 <= n) t[i+1][j+1] = min(t[i+1][j+1], t[i][j]+a[i]);
			if (j >= 1) t[i+1][j-1] = min(t[i+1][j-1], t[i][j]+b[i]);
		}
		for (int i=0; i<=n; ++i) f[k][i] = t[n][i];
	}
	matrix_power(f, m, n+1);
	printf("%I64d\n", f[0][0]);
	return 0;
}

// 7361785	2014-08-06 18:58:57	delta_4d	C - Jeff and Brackets	GNU C++0x	Accepted	60 ms	0 KB
