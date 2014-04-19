#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 6;
const int MOD = 10000007;

ll a, b, c, d, e, f;

void matrix_mul(const int n, ll x[][MAXN], ll y[][MAXN]) {
	int i, j, k;
	ll tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) for (k=0; k<n; ++k) {
		tmp[i][j] = (tmp[i][j] + x[i][k] * y[k][j]) % MOD;
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

void matrix_binary_exp(const int n, ll x[][MAXN], ll exp) {
	int i, j, k;
	ll tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) tmp[i][i] = 1;
	while (exp) {
		if (exp & 1) matrix_mul(n, tmp, x);
		matrix_mul(n, x, x);
		exp >>= 1;
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

ll fn( ll n ) {
	if( n == 0 ) return a;
	if( n == 1 ) return b;
	if( n == 2 ) return c;
	if( n == 3 ) return d;
	if( n == 4 ) return e;
	if( n == 5 ) return f;

	ll mat[6][6]={0}, v[6]={f,e,d,c,b,a}, x=0;
	for (int i=0; i<6; ++i) mat[0][i] = 1;
	for (int i=0; i<5; ++i) mat[i+1][i] = 1;
	matrix_binary_exp(6, mat, n-5);
	for (int i=0; i<6; ++i) x = (x + mat[0][i] * v[i]) % MOD;
	return (x + MOD) % MOD;
}

int main() {
	ll n, caseno = 0, cases;
	scanf("%lld", &cases);
	while( cases-- ) {
		scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
		a %= MOD, b %= MOD, c %= MOD, d %= MOD, e %= MOD, f %= MOD;
		printf("Case %lld: %lld\n", ++caseno, (fn(n) + MOD)% MOD);
	}
	return 0;
}

// 252192	2013-08-16 14:14:12	 1006 - Hex-a-bonacci	 C++	 0.000	 1088	Accepted
