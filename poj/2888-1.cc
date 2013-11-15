#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 1000000;
const int MAXN = 16;
const int P = 9973;
const int MOD = 9973;

bool isp[MAXL];
int p[MAXL], tot;
int f[16][16];

inline void init() {
	for (int i=2; i<MAXL; ++i) if (!isp[i]) {
		p[tot++] = i;
		for (int j=i<<1; j<MAXL; j+=i) isp[i] = true;
	}
}

int phi(int n) {
	int ret(n);
	for (int i=0; p[i]*p[i]<=n; ++i) {
		if (n % p[i] == 0) {
			ret -= ret / p[i];
			for (; n % p[i] == 0; n /= p[i]);
		}
	}
	if (n > 1) ret -= ret / n;
	return ret % P;
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

int gao(int n, int e) {
	int i, j, k;
	int a[16][16];
	int ret(0);
	
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) a[i][j] = f[i][j];
	matrix_binary_exp(n, a, e);
	for (i=0; i<n; ++i) ret = (ret + a[i][i]) % P;
	return ret;
}

int exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {x = 1; y = 0; return a;}
	int ret(exgcd(b, a%b, x, y));
	int t(x);
	x = y;
	y = t - a / b * y;
	return ret;
}

int rev(int a) {
	int x, y;
	exgcd(a, P, x, y);
	x %= P;
	return x < 0 ? x + P : x;
}

int main() {
	int i, j, k;
	int c, n, m;
	int tot;
	int tc;
	
//	freopen("in.txt", "r", stdin);
	init();
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &n, &m, &k);
		for (i=0; i<m; ++i) for (j=0; j<m; ++j) f[i][j] = 1;
		for (c=0; c<k; ++c) {
			scanf("%d %d", &i, &j);
			--i, --j;
			f[i][j] = f[j][i] = 0;
		}
		tot = 0;
		for (i=1; i*i<=n; ++i) {
			if (n % i == 0) {
				tot = (tot + gao(m, i) * phi(n / i)) % P;
				if (i * i != n) tot = (tot + gao(m, n/i) * phi(i)) % P;
			}
		}
		printf("%d\n", tot*rev(n)%P);
	}
	return 0;
}