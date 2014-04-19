#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const ll MAXN = 35;
ll mat[MAXN][MAXN], f[MAXN][MAXN];
vector <int> state;
int id[200];

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

void dfs(int d, int c, int r) {
	if (d == 7) {
		if (!r) state.push_back(c);
		return;
	}
	if (r + d < 7) dfs(d+1, 2*c, r);
	if (r) dfs(d+1, c*2+1, r-1);
}

void tran(int c, int d, int cc) {
	if (d == 7) {
		if (id[cc] != -1) mat[id[cc]][id[c]] = 1;
		return;
	}
	if (c & 1 << d) {
		if (d - 1 >= 0) tran(c, d+1, cc|(1<<(d-1)));
		if (d + 1 < 7) tran(c, d+1, cc|(1<<(d+1)));
	} else {
		tran(c, d+1, cc);
	}
}

void init() {
	dfs(0, 0, 4);
	sort(state.begin(), state.end());
	int n = (int)state.size();
	memset(id, -1, sizeof(id));
	for (int i=0; i<n; ++i) id[state[i]] = i;
	for (int i=0; i<n; ++i) tran(state[i], 0, 0);
}

int main() {
	init();
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		int cc = 0;
		for (int i=0,x; i<7; ++i) {
			scanf("%d", &x);
			cc <<= 1;
			if (x) ++cc;
		}
		cc = id[cc];
		for (int i=0; i<MAXN; ++i) for (int j=0; j<MAXN; ++j) f[i][j] = mat[i][j];
		matrix_binary_exp(MAXN, f, n-1);
		ll tot = 0;
		for (int i=0; i<MAXN; ++i) tot = (tot + f[i][cc]) % MOD;
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 321602	2014-02-08 17:20:15	 1160 - Discovering Paths in Grid	 C++	 1.080	 1236	Accepted
