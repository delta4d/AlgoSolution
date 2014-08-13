#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
int const N = 1e5 + 10;

ll a[N], b[N];
ll sa[N], sb[N];

ll gao(ll a[], int m, ll b[], int n) {
	partial_sum(a, a+m, sa);
	partial_sum(b, b+n, sb);
	ll ret = ULLONG_MAX, rem = sa[m-1];
	for (int i=1; i<=m; ++i) {
		rem -= a[m-i];
		ll cc = sb[n-1] * i + rem;
		ret = min(ret, cc);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	ll mn = ULLONG_MAX;
	int n, m;
	cin >> m >> n;
	for (int i=0; i<m; ++i) cin >> a[i]; sort(a, a+m);
	for (int i=0; i<n; ++i) cin >> b[i]; sort(b, b+n);
	mn = min(mn, gao(a, m, b, n));
	mn = min(mn, gao(b, n, a, m));
	cout << mn << endl;
	return 0;
}

// 7425209	2014-08-11 12:36:29	delta_4d	B - Distributed Join	GNU C++0x	Accepted	62 ms	3100 KB
