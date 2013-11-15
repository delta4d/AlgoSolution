#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 9973;
const int MAXN = 16;
const int MAXL = 1000000;

int f[MAXN][MAXN];
int m, n;
int p[MAXL];
bool isp[MAXL];

void init() {
	int i, j, k(0);
	memset(isp, true, sizeof(isp));
	for (i=2; i<MAXL; ++i) {
		if (isp[i]) {
			p[k++] = i;
			for (j=i<<1; j<MAXL; j+=i) isp[j] = false;
		}
	}
}

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

int trace(int e) {
	int mat[MAXN][MAXN];
	int ret(0);
	for (int i=0; i<m; ++i) for (int j=0; j<m; ++j) mat[i][j] = f[i][j];
	matrix_binary_exp(m, mat, e);
	for (int i=0; i<m; ++i) ret = (ret + mat[i][i]) % MOD;
	return ret % MOD;
}

int phi(const int x) {
	int ret(x), t(x);
	for (int i=0; p[i]*p[i]<=t; ++i) {
		if (t % p[i] == 0) {
			ret -= ret / p[i];
			for (; t % p[i] == 0; t /= p[i]);
		}
	}
	if (t != 1) ret -= ret / t;
	return ret % MOD;
}

int ex_gcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int ret(ex_gcd(b, a%b, x, y));
	int t(x);
	x = y;
	y = t - a / b * y;
	return ret;
}

int rev(int a) {
	int x, y;
	ex_gcd(a, MOD, x, y);
	x %= MOD;
	return x < 0 ? x + MOD : x;
}

int main() {
	int i, j, k;
	int tc;
	int x, y;
	int tot;
	
//	freopen("d:\\in.txt", "r", stdin);
	init();
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &n, &m, &k);
		for (i=0; i<MAXN; ++i) for (j=0; j<MAXN; ++j) f[i][j] = 1;
		for (i=0; i<k; ++i) {
			scanf("%d %d", &x, &y);
			--x, --y;
			f[x][y] = f[y][x] = 0;
		}
		for (tot=0,i=1; i*i<=n; ++i) {
			if (n % i == 0) {
				tot = (tot + phi(n / i) * trace(i)) % MOD;
				if (i * i != n) tot = (tot + phi(i) * trace(n / i)) % MOD;
			}
		}
//		printf("%d\n", tot);
		printf("%d\n", tot*rev(n)%MOD);
	}
	return 0;
}