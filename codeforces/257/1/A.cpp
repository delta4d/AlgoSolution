#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline ll f(ll n, ll m) {
	return n / m;
}

int main() {
	ll m, n, k;

	cin >> m >> n >> k;

	if (k > (m - 1) + (n - 1)) return puts("-1"), 0;

	ll mx = 0;
	if (k < m) mx = max(mx, f(m, k+1) * n);
	else mx = max(mx, f(m, m) * f(n, k-m+2));
	if (k < n) mx = max(mx, f(n, k+1) * m);
	else mx = max(mx, f(n, n) * f(m, k-n+2));
	
	cout << mx << endl;

	return 0;
}

// 7165731	2014-07-19 17:53:10	delta_4d	A - Jzzhu and Chocolate	GNU C++0x	Accepted	15 ms	0 KB
