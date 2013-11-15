#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int MOD;
const int MAXN = 256;

int mat[MAXN][MAXN];

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
	int i, j, k;
	int m, n;
	
//	freopen("d:\\in.txt", "r", stdin);
	while (3 == scanf("%d %d %d", &n, &k, &MOD)) {
		memset(mat, 0, sizeof(mat));
		for (i=0; i<n; ++i) for (j=0; j<n; ++j) scanf("%d", mat[i]+j), mat[i][j] %= MOD;
		for (i=0; i<n; ++i) mat[i][i+n] = mat[i+n][i+n] = 1;
		
		matrix_binary_exp(n<<1, mat, k+1);
		for (i=0; i<n; ++i) for (j=0; j<n; ++j) printf("%d%c", mat[i][j+n]-(i==j), j==n-1?'\n':' ');
	//	for (i=0; i<2*n; ++i) for (j=0; j<2*n; ++j) printf("%d%c", mat[i][j], j==2*n-1?'\n':' ');
	}

	return 0;
}