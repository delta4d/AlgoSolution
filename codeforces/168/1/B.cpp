#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;

vector <vector<int> > t;
vector <LL> v;

void dfs(int r, int p, LL &mn, LL &mx) {
	mn = INF, mx = -INF;
	bool leaf = true;
	for (int i=0; i<(int)t[r].size(); ++i) if (t[r][i] != p) {
		leaf = false;
		LL tmn, tmx;
		dfs(t[r][i], r, tmn, tmx);
		mn = min(mn, tmn), mx = max(mx, tmx);
	}
	if (leaf) {
		mn = mx = 0;
		v[r] > 0 ? mn = -v[r] : mx = -v[r];	
	} else {
		LL rm = v[r] + mx + mn;
		rm > 0 ? mn -= rm : mx -= rm;
	}
//	printf("%d: %d %d\n", r, mn, mx);
}

int main() {
	int n;
	LL a, b;

	cin >> n;
	t.resize(n); v.resize(n);
	for (int i=1; i<n; ++i) {
		cin >> a >> b;
		--a, --b;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	for (int i=0; i<n; ++i) cin >> v[i];
	dfs(0, -1, a, b);
	cout << b - a << endl;

	return 0;
}

// 3324161	 Mar 16, 2013 11:04:41 AM	delta_4d	 274B - Zero Tree	 GNU C++	Accepted	453 ms	11400 KB
