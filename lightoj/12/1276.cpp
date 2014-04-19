#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
const ll INF = 1e12 + 10;
const ll D = 20;

vector <ll> p, lucky, x, y;

void dfs(ll c) {
	if (c > INF) return;
	if (c) p.push_back(c);
	dfs(c*10+4);
	dfs(c*10+7);
}

void uniq(vector <ll> &a) {
	sort(all(a));
	a.erase(unique(all(a)), a.end());
}

void init() {
	dfs(0);
	uniq(p);
	lucky.insert(lucky.end(), all(p));
	x = p;
	while (true) {
		y.clear();
		for (int i=0; i<(int)p.size(); ++i) {
			ll lim = INF / p[i] + 1;
			if (x[0] >= lim) break;
			for (int j=0; j<(int)x.size(); ++j) {
				if (x[j] >= lim) break;
				y.push_back(p[i] * x[j]);
			}
		}
		if (y.size() == 0) break;
		x = y;
		uniq(x);
		lucky.insert(lucky.end(), all(x));
	}
	uniq(lucky);
}

int gao(ll a, ll b) {
	return max(0, (int)(upper_bound(all(lucky), b)-upper_bound(all(lucky), a-1)));
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		printf("Case %d: %d\n", ++cn, max(0, gao(a, b)));
	}
	return 0;
}

// 260035	2013-09-05 21:55:18	 1276 - Very Lucky Numbers	 C++	 0.144	 14332	Accepted
