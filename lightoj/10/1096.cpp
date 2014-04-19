#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 10007;
const int MAXN = 4;

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
	int tc, cn = 0, n, a, b, c;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d%d", &n, &a, &b, &c);
		int mat[4][4] = {a, 0, b, c, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1};
		if (n >= 2) matrix_binary_exp(4, mat, n-2);
		printf("Case %d: %d\n", ++cn, (n>=2)*mat[0][3]);
	}
	return 0;
}

// 293452	2013-11-30 20:11:25	 1096 - nth Term	 C++	 0.000	 1088	Accepted
