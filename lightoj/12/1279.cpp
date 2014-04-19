#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 100;
const ll MOD = 1000000007;

ll mat[MAXN][MAXN], N, M, K;

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}	
	ll ret = ext_gcd(b, a%b, x, y);
	ll t = x;
	x = y, y = t - a / b * y;
	return ret;
}

ll mod_inv(ll a, ll n) {
	ll x, y;
	ext_gcd(a, n, x, y);
	x %= n;
	if (x < 0) x += n;
	return x;
}

ll powermod(ll x, ll e) {
	ll r = 1;
	for (x%=MOD; e; x=x*x%MOD,e>>=1) if (e & 1) r = r * x % MOD;
	return r;
}

ll gao() {
	ll rank = 0;
	for (ll i=0,j,k; i<N; ++i) {
		j = -1;
		for (k=rank; j==-1&&k<N; ++k) if (mat[k][i]) j = k;
		if (j == -1) continue;
		for (k=0; k<N; ++k) swap(mat[rank][k], mat[j][k]);
		for (j=rank+1; j<N; ++j) {
			ll x = mat[j][i] * mod_inv(mat[rank][i], K) % K;
			for (k=i; k<N; ++k) {
				mat[j][k] = (mat[j][k] - mat[rank][k] * x) % K;
				if (mat[j][k] < 0) mat[j][k] += K;
			}
		}
		++rank;
	}
	return powermod(K, N-rank);
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%lld%lld%lld", &N, &M, &K);
		memset(mat, 0, sizeof(mat));
		for (ll i=0,a,b; i<M; ++i) {
			scanf("%lld%lld", &a, &b), --a, --b;
			mat[a][b] = K - 1, mat[b][a] = K - 1;
		}
		for (ll i=0; i<N; ++i) mat[i][i] = 1;
		printf("Case %d: %lld\n", ++cn, gao());
	}
	return 0;
}

// 320969	2014-02-06 18:38:41	 1279 - Graph Coloring	 C++	 0.428	 1164	Accepted
