#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MAXN = 333;
const LL MOD = 1000000007;

LL x[MAXN], v[MAXN], d[MAXN];
LL dp[100000+86];
LL n, q, t;
vector <LL> f[MAXN];
vector <LL> tmp, w;

bool dfs(LL r) {
	tmp.push_back(r);
	v[r] = 1;
	for (int i=0; i<(int)f[r].size(); ++i) {
		int u = f[r][i];
		if (v[u] == 1) return false;
		if (!v[u] && !dfs(u)) return false;
	}
	v[r] = 2;
	return true;
}

bool circle(LL r, const LL mm) {
	v[r] = mm;
	for (int i=0; i<(int)f[r].size(); ++i) {
		int u = f[r][i];
		if (v[u] == mm) return true;
		if (!v[u] && circle(u, mm)) return true;
	}
	return false;
}

int main() {
	LL b, c;

	cin >> n >> q >> t;
	for (int i=0; i<n; ++i) cin >> x[i];
	for (int i=0; i<q; ++i) {
		cin >> b >> c;
		--b, --c;
		f[b].push_back(c);
		++d[c];
	}
	for (int i=0; i<n; ++i) if (!v[i] && circle(i, i + 1)) { cout << 0 << endl; return 0; }
	memset(v, 0, sizeof(v));
	for (int i=0; i<n; ++i) if (!d[i]) {
			tmp.clear();
			if (!dfs(i)) { cout << 0 << endl; return 0; }
			for (int j=0,k=0; j<(int)tmp.size(); ++j) {
				w.push_back(k+=x[tmp[j]]);
				t -= k;
			}
			t += w[w.size()-1];
		}
	if (t < 0) { cout << 0 << endl; return 0; }
	dp[0] = 1;
	for (int k=w.size()-1; k>=0; --k) {
		for (int i=0; i<=t; ++i) if (dp[i] && i + w[k] <= t) {
			int j = i + w[k];
			dp[j] = (dp[j] + dp[i]) % MOD;
		}
	}
	cout << dp[t] << endl;

	return 0;
}

// 3352721	 Mar 18, 2013 7:53:14 PM	delta_4d	 283C - Coin Troubles	 GNU C++	Accepted	390 ms	900 KB
