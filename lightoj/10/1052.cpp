#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const ll MAXN = 2;

void matrix_mul(const ll n, ll x[][MAXN], ll y[][MAXN]) {
	ll i, j, k;
	ll tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) for (k=0; k<n; ++k) {
		tmp[i][j] = (tmp[i][j] + x[i][k] * y[k][j]) % MOD;
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

void matrix_binary_exp(const ll n, ll x[][MAXN], ll exp) {
	ll i, j, k;
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

void gao(ll N, ll X, ll &a, ll &b, ll &c) {
	ll mat[2][2] = {1, 1, 1, 0};
	matrix_binary_exp(2, mat, N-2);
	a = mat[0][0], b = mat[0][1], c = X;
}

bool gao(ll a1, ll b1, ll c1, ll a2, ll b2, ll c2, ll &x, ll &y) {
	ll X, Y, R;
	X = a1 * b2 - a2 * b1, R = c1 * b2 - c2 * b1;
	if (X == 0 || R % X != 0) return false;
	if ((x = R / X) <= 0) return false;
	Y = b2 * a1 - b1 * a2, R = c2 * a1 - c1 * a2;
	if (Y == 0 || R % Y != 0) return false;
	if ((y = R / Y) < 0) return false;
	return x >= y;
}

int main() {
	ll tc, cn = 0, N, X, M, Y, K;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld%lld%lld%lld", &N, &X, &M, &Y, &K), ++N, ++M, ++K;
		ll a1, b1, c1, a2, b2, c2, L2, L1;
		gao(N, X, a1, b1, c1);
		gao(M, Y, a2, b2, c2);
		printf("Case %lld: ", ++cn);
		if (!gao(a1, b1, c1, a2, b2, c2, L2, L1)) {
			puts("Impossible");
		} else {
			ll mat[2][2] = {1, 1, 1, 0};
			matrix_binary_exp(2, mat, K-2);
			ll res = (mat[0][0] * L2 + mat[0][1] * L1) % MOD;
			if (res < 0) res += MOD;
			printf("%lld\n", res);
		}
	}
	return 0;
}

// 299158	2013-12-13 18:41:00	 1052 - String Growth	 C++	 0.004	 1088	Accepted
