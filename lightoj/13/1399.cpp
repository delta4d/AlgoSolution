#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const double INF = 111111111111111111.1;
const ll MOD = 1000000007;
const ll MAXN = 5000;
const ll M = 40;

double f[MAXN][M], lp[100];
int path[MAXN][M];
ll p[MAXN], c, n;
ll pr[100], cn;
ll mx[MAXN][M];
bool v[100];

void init() {
	for (int i=2; i<100; ++i) if (!v[i]) {
		if (i > 2) lp[cn] = log(i), pr[cn++] = i;
		for (int j=i*i; j<100; j+=i) v[j] = true;
	}
}

ll pmod(ll x, ll e) {
	ll r = 1;
	for (x%=MOD; e; e>>=1,x=x*x%MOD) if (e & 1) r = r * x % MOD;
	return r;
}

int main() {
	init();
	int tc, cn = 0;
//	freopen("in.txt", "r", stdin);
	for (scanf("%d", &tc); tc--; ) {
		c = 0, scanf("%lld", &n), ++n;
		for (ll i=2; i*i<=n; ++i) if (n % i == 0) {
			p[c++] = i;
			if (i * i != n) p[c++] = n / i;
		}
		p[c++] = n;
		sort(p, p+c);
		for (ll i=0; i<c; ++i) {
			fill(f[i], f[i]+M, -1);
			fill(path[i], path[i]+M, -1);
		}
//		printf("c: %lld\n", c);
		for (ll i=0; i<c; ++i) f[i][0] = (p[i] - 1)* lp[0], mx[i][0] = p[i];
		for (ll i=0; i<c; ++i) for (ll j=0; j<M; ++j) if (f[i][j] > 0) {
			for (ll k=i+1; k<c; ++k) {
				ll cmx = p[k] / p[i];
				if (cmx > mx[i][j]) break;
				if (p[k] % p[i] == 0) {
					double cc = f[i][j] + (cmx - 1) * lp[j+1];
					if (f[k][j+1] < 0) path[k][j+1] = i, f[k][j+1] = cc, mx[k][j+1] = cmx;
					else if (cc < f[k][j+1]) path[k][j+1] = i, f[k][j+1] = cc, mx[k][j+1] = cmx;
				}
			}
		}
		//		puts("dp done");
		double mn = INF;
		int x = c - 1, y = -1;
		for (int i=0; i<M; ++i) if (f[c-1][i] > 0) {
			if (f[c-1][i] < mn) mn = f[c-1][i], y = i;
		}
		ll tot = 1;
		while (y >= 0) {
			int tx = path[x][y];
			ll e = tx < 0 ? p[x] - 1 : p[x] / p[tx] - 1;
			tot = tot * pmod(pr[y], e) % MOD;
//			printf("x:%d y:%d %lf ==== %lld^%lld\n", x, y, f[x][y], pr[y], e);
			--y, x = tx;
		}
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

