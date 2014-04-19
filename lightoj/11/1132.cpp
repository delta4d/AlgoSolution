#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned int uint;
const int N = 100;
const int MAXN = 100;

uint C[N][N];

void matrix_mul(const int n, uint x[][MAXN], uint y[][MAXN]) {
	int i, j, k;
	uint tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) for (k=0; k<n; ++k) {
		tmp[i][j] = tmp[i][j] + x[i][k] * y[k][j];
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

void matrix_binary_exp(const int n, uint x[][MAXN], long long exp) {
	int i, j, k;
	uint tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) tmp[i][i] = 1;
	while (exp) {
		if (exp & 1) matrix_mul(n, tmp, x);
		matrix_mul(n, x, x);
		exp >>= 1;
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

void init() {
	for (int i=0; i<N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j=1; j<i; ++j) C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
}

uint gao(const long long n, const int K) {
	uint mat[N][N] = {0};
	for (int i=0; i<=K+1; ++i) {
		for (int j=i; j<=K; ++j) mat[i][j] = C[K-i][K-j];
		mat[i][K+1] = 1;
	}
	matrix_binary_exp(K+2, mat, n-1);
	uint ret = 0;
	for (int i=0; i<=K+1; ++i) ret += mat[0][i];
	return ret;
}

int main() {
	init();
	int tc, cn = 0, K;
	long long N;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%lld%d", &N, &K);
		printf("Case %d: %u\n", ++cn, gao(N, K));
	}
	return 0;
}

// 298945	2013-12-12 23:52:02	 1132 - Summing up Powers	 C++	 0.756	 1124	Accepted
