#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll M = 1000000000;

map <ll, ll> mp;
vector <ll> f[520];

ll p(ll x, ll e) {
	ll r = 1;
	for (x%=M; e; e>>=1,x=x*x%M) if (e & 1) r = r * x % M;
	return r;
}

ll gao(ll a, ll b, ll K) {
	return K * p(K-1, b-a) % M;
}

int main() {
	ll tc, cn = 0, M, N, K, B, x, y, cc;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld%lld%lld", &M, &N, &K, &B);
		mp.clear(); cc = 0;
		for (int i=0; i<B; ++i) f[i].clear();
		for (int i=0; i<B; ++i) {
			scanf("%lld%lld", &x, &y);
			if (!mp.count(y)) mp[y] = cc++;
			f[mp[y]].push_back(x);
		}
		ll tot = 1;
		for (int i=0; i<cc; ++i) {
			f[i].push_back(0), f[i].push_back(M+1);
			sort(f[i].begin(), f[i].end());
			for (int j=0; j+1<(int)f[i].size(); ++j) {
				ll a = f[i][j] + 1, b = f[i][j+1] - 1;
				if (a > b) continue;
				tot = tot * gao(a, b, K) % ::M;
			}
		}
		tot = tot * p(gao(1, M, K), N-cc) % ::M;
		printf("Case %lld: %lld\n", ++cn, tot);
	}
	return 0;
}

// 251554	2013-08-14 17:56:02	 1333 - Grid Coloring	 C++	 0.168	 1692	Accepted
