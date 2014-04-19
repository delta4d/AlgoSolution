#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long llu;

const int MAXN = 2;

void matrix_mul(const int n, llu x[][MAXN], llu y[][MAXN]) {
	int i, j, k;
	llu tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) for (k=0; k<n; ++k) {
		tmp[i][j] = tmp[i][j] + x[i][k] * y[k][j];
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

void matrix_binary_exp(const int n, llu x[][MAXN], int exp) {
	int i, j, k;
	llu tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) tmp[i][i] = 1;
	while (exp) {
		if (exp & 1) matrix_mul(n, tmp, x);
		matrix_mul(n, x, x);
		exp >>= 1;
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

int main() {
	int tc, cn = 0, p, q, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &p, &q, &n);
		llu mat[2][2] = {p, -q, 1, 0};
		if (n) matrix_binary_exp(2, mat, n-1);
		llu fn = p * mat[0][0] + 2 * mat[0][1];
		if (n == 0) fn = 2;
		printf("Case %d: %llu\n", ++cn, fn);
	}
	return 0;
}

// 295112	2013-12-03 22:51:30	 1070 - Algebraic Problem	 C++	 0.032	 1088	Accepted
