#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long MOD;
const int MAXN = 6;

void matrix_mul(const int n, long long x[][MAXN], long long y[][MAXN]) {
	int i, j, k;
	long long tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) for (k=0; k<n; ++k) {
		tmp[i][j] = (tmp[i][j] + x[i][k] * y[k][j]) % MOD;
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

void matrix_binary_exp(const int n, long long x[][MAXN], int exp) {
	int i, j, k;
	long long tmp[MAXN][MAXN];

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
	long long tc, cn = 0;
	long long a1, b1, c1, a2, b2, c2;
	long long f0, f1, f2, g0, g1, g2;
	long long M, Q, N;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld%lld", &a1, &b1, &c1);
		scanf("%lld%lld%lld", &a2, &b2, &c2);
		scanf("%lld%lld%lld", &f0, &f1, &f2);
		scanf("%lld%lld%lld", &g0, &g1, &g2);
		scanf("%lld", &M), MOD = M;
		f0 %= M, f1 %= M, f2 %= M;
		g0 %= M, g1 %= M, g2 %= M;
		printf("Case %lld:\n", ++cn);
		for (scanf("%lld", &Q); Q--; ) {
			scanf("%lld", &N);
			long long mat[6][6] = {0};
			mat[0][0] = a1, mat[0][1] = b1, mat[0][5] = c1;
			mat[1][0] = 1, mat[2][1] = 1;
			mat[3][2] = c2, mat[3][3] = a2, mat[3][4] = b2;
			mat[4][3] = 1, mat[5][4] = 1;
			if (N > 2) matrix_binary_exp(6, mat, N-2);
			long long fn, gn;
			if (N == 0) fn = f0, gn = g0;
			else if (N == 1) fn = f1, gn = g1;
			else if (N == 2) fn = f2, gn = g2;
			else fn = (mat[0][0] * f2 + mat[0][1] * f1 + mat[0][2] * f0 +
					mat[0][3] * g2 + mat[0][4] * g1 + mat[0][5] * g0) % M,
			gn = (mat[3][0] * f2 + mat[3][1] * f1 + mat[3][2] * f0 +
					mat[3][3] * g2 + mat[3][4] * g1 + mat[3][5] * g0) % M;
			printf("%lld %lld\n", fn, gn);
		}
	}
	return 0;
}

// 296875	2013-12-08 22:56:06	 1131 - Just Two Functions	 C++	 0.244	 1088	Accepted
