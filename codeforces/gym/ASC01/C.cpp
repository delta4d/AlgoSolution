#include <bits/stdc++.h>
using namespace std;

int const N = 5e5 + 10;

vector <int> e[N], o;
int f[N][2], nxt[N];

void dfs(int r) {
	int mx = 0, idx = 0;
	for (auto c: e[r]) {
		dfs(c);
		f[r][0] += f[c][0], f[r][1] += f[c][0];
		if (f[c][1] - f[c][0] > mx) mx = f[c][1] - f[c][0], idx = c;
	}
	++f[r][1];
	if (mx > 0) f[r][0] += mx, nxt[r] = idx;
}

void dfs(int r, int k) {
	if (k) o.push_back(r);
	for (auto c: e[r]) {
		if (c == nxt[r]) dfs(c, 1);
		else dfs(c, 0);
	}
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("grant.in", "r", stdin);
	freopen("grant.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i=2,j; i<=n; ++i) {
		scanf("%d", &j);
		e[j].push_back(i);
	}
	dfs(1);
	printf("%d\n", f[1][0]*1000);
	dfs(1, 0);
	sort(begin(o), end(o));
	for (auto i: o) printf("%d ", i);
	return 0;
}

// 6962423	 2014-06-26 13:33:26	delta_4d	 C - New Year Bonus Grant	 GNU C++0x	Accepted	530 ms	53136 KB
