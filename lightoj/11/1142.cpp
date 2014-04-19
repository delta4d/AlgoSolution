#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 10;
const int MAXN = 100;

int A[MAXN][MAXN], mat[MAXN][MAXN], res[MAXN][MAXN];

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

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int main() {
	int tc, cn = 0, n, k;
	for (scanf("%d", &tc); tc--; ) {
		memset(A, 0, sizeof(A));
		memset(mat, 0, sizeof(mat));
		memset(res, 0, sizeof(res));
		scanf("%d%d", &n, &k);
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) scanf("%d", A[i]+j), A[i][j] %= MOD;
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) mat[i][j] = mat[i][j+n] = A[i][j];
		for (int i=0; i<n; ++i) mat[i+n][i+n] = 1, A[i+n][i] = 1;
		matrix_binary_exp(n<<1, mat, k-1);
		for (int i=0; i<2*n; ++i) for (int j=0; j<n; ++j) {
			for (int k=0; k<2*n; ++k) add(res[i][j], mat[i][k]*A[k][j]%MOD);
		}
		printf("Case %d:\n", ++cn);
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) printf("%d%s", res[i][j], j==n-1?"\n":"");
	}
	return 0;
}

// 299140	2013-12-13 17:38:00	 1142 - Summing up Powers (II)	 C++	 0.340	 1204	Accepted
