#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
int const N = 2e5 + 10;
ull const SEED = 17;

vector <int> f[N], o;

ull e(ull n) {
	ull x = SEED, ret = 1;
	for (; n; n>>=1,x=x*x) if (n & 1) ret = ret * x;
	return ret;
}

int main() {
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	for (int i=0,x; i<n; ++i) scanf("%d", &x), f[i%p].push_back(x);
	ull hash = 0;
	for (int i=0,x; i<m; ++i) scanf("%d", &x), hash += x * e(x);
	for (int i=0; i<p; ++i) {
		int sz = (int)f[i].size();
		if (sz < m) continue;
		ull h = 0;
		for (int j=0; j<m; ++j) h += f[i][j] * e(f[i][j]);
		if (h == hash) o.push_back(i);
		for (int j=m; j<sz; ++j) {
			h += f[i][j] * e(f[i][j]);
			h -= f[i][j-m] * e(f[i][j-m]);
			if (h == hash) o.push_back((j-m+1)*p+i);
		}
	}
	sort(begin(o), end(o));
	printf("%d\n", (int)o.size());
	for (auto x: o) printf("%d ", x+1);
	return 0;
}

// 7344482	2014-08-04 16:00:30	delta_4d	B - Sereja ans Anagrams	GNU C++0x	Accepted	140 ms	5800 KB
