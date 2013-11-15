#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 2;

void matrix_mul(const int n, int x[][MAXN], int y[][MAXN]) {
	int i, j, k;
	int tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) for (k=0; k<n; ++k) {
		tmp[i][j] = (tmp[i][j] + (long long)x[i][k] * y[k][j]) % MOD;
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
	int n, m, k;
	while (3 == scanf("%d%d%d", &n, &m, &k)) {
		int x[][2]={m, -1, k, -1};
		matrix_binary_exp(2, x, n-1);
		int tot = ((long long)x[0][0] * m + (long long)x[0][1] * k) % MOD;
		printf("%d\n", tot<0?tot+MOD:tot);
	}
	return 0;
}
