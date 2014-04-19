#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll MAXN = 300;

vector <int> p;
bool np[MAXN];
int f[62][1000], sz;

ll power(ll x, ll e) {
	ll r = 1;
	for (x%=MOD; e; e>>=1,x=x*x%MOD) if (e & 1) r = r * x % MOD;
	return r;
}

ll gao(ll n) {
	int rank = 0;
	for (int i=0,j,k; rank<sz&&i<n; ++i) {
		j = -1;
		for (k=rank; j==-1&&k<sz; ++k) if (f[k][i]) j = k;
		if (j == -1) continue;
		for (k=0; k<n; ++k) swap(f[rank][k], f[j][k]);
		for (j=rank+1; j<sz; ++j) if (f[j][i]) {
			for (k=i; k<n; ++k) f[j][k] ^= f[rank][k];
		}
		++rank;
	}
	return (power(2, n-rank) - 1 + MOD) % MOD;
}

void init() {
	for (int i=2; i<MAXN; ++i) if (!np[i]) {
		p.push_back(i);
		for (int j=i*i; j<MAXN; j+=i) np[j] = true;
	}
	sz = (int)p.size();
}

int main() {
	init();
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		memset(f, 0, sizeof(f));
		scanf("%d", &n);
		for (ll i=0,x; i<n; ++i) {
			scanf("%lld", &x);
			for (ll j=0; j<sz; ++j) {
				for (; x%p[j]==0; x/=p[j], f[j][i]^=1);
			}
		}
		printf("Case %d: %lld\n", ++cn, gao(n));
	}
	return 0;
}

// 321453	2014-02-07 22:25:29	 1288 - Subsets Forming Perfect Squares	 C++	 0.228	 1456	Accepted
