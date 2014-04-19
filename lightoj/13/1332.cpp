#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned int uint;
const int MAXN = 36;
uint tr[MAXN][MAXN];
int x[MAXN], y[MAXN], p;

void matrix_mul(const uint n, uint x[][MAXN], uint y[][MAXN]) {
	uint i, j, k;
	uint tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) for (k=0; k<n; ++k) {
		tmp[i][j] = tmp[i][j] + x[i][k] * y[k][j];
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

void matrix_binary_exp(const uint n, uint x[][MAXN], uint exp) {
	uint i, j, k;
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

bool ok(int x, int y) {
	return abs(x - y) > 1;
}

bool ok(int x1, int x2, int y1, int y2) {
	return ok(x1, y1) && ok(x1, y2) && ok(x2, y1) && ok(x2, y2);
}

void init() {
	for (int i=0; i<10; ++i) for (int j=i+2; j<10; ++j) x[p] = i, y[p++] = j;
	for (int i=0; i<p; ++i) for (int j=0; j<p; ++j) if (ok(x[i], y[i], x[j], y[j])) {
		tr[i][j] = 1;
	}
}

uint gao(int n) {
	uint mat[MAXN][MAXN], ret = 0;
	for (int i=0; i<p; ++i) for (int j=0; j<p; ++j) mat[i][j] = tr[i][j];
	matrix_binary_exp(p, mat, n-1);
	for (int i=0; i<p; ++i) for (int j=0; j<p; ++j) ret += mat[i][j];
	return ret;
}

int main() {
	init();
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		printf("Case %d: %u\n", ++cn, gao(n));
	}
	return 0;
}

// 300576	2013-12-17 21:28:39	 1332 - Kings in Chessboard	 C++	 0.448	 1092	Accepted
