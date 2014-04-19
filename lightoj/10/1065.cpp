#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int MOD;
const int MAXN = 2;
const int mm[] = {1, 10, 100, 1000, 10000};

void matrix_mul(const int n, int x[][MAXN], int y[][MAXN]) {
	int i, j, k;
	int tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) for (k=0; k<n; ++k) {
		tmp[i][j] = (tmp[i][j] + x[i][k] * y[k][j]) % MOD;
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

void matrix_binary_exp(const int n, int x[][MAXN], int exp) {
	int i, j, k;
	int tmp[MAXN][MAXN];

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
	int tc, cn = 0, a, b, m, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d%d", &a, &b, &n, &m);
		int mat[2][2] = {1, 1, 1, 0};
		MOD = mm[m];
		if (n) matrix_binary_exp(2, mat, n-1);
		int t = (mat[0][0] * b + mat[0][1] * a) % MOD;
		printf("Case %d: %d\n", ++cn, t);
	}
	return 0;
}

// 293439	2013-11-30 19:57:41	 1065 - Number Sequence	 C++	 0.040	 1088	Accepted
