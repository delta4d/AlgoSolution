#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;

int lp[N], p[N], pp;
vector <pair<int,int>> o;
vector <int> t;
unordered_set <int> s;

void init(int n=N) {
	for (int i=0; i<n; ++i) lp[i] = i;
	for (int i=2; i<n; ++i) {
		if (lp[i] == i) p[pp++] = i;
		for (int j=0; p[j]<=lp[i]&&(long long)p[j]*i<n; ++j) {
			lp[p[j]*i] = p[j];
		}
	}
}

int main() {
	init();
	int n;
	scanf("%d", &n);
	for (int i=2; i<=n; ++i) {
		if (lp[i] == i && i * 2 > n) continue;
		s.insert(i);
	}
	for (int i=1; 2*p[i]<=n; ++i) {
		t.clear();
		for (auto j: s) if (j % p[i] == 0) t.push_back(j);
		if (t.empty()) continue;
		sort(begin(t), end(t));
		int sz = (int)t.size();
		if (sz > 1 && (sz & 1)) swap(t[1], t[sz-1]);
		for (int j=0; j+1<sz; ++j,++j) {
			s.erase(t[j]), s.erase(t[j+1]);
			o.push_back({t[j], t[j+1]});
		}
	}
	t.clear();
	for (auto i: s) if (!(i&1)) t.push_back(i);
	for (int i=0; i+1<(int)t.size(); ++i,++i) o.push_back({t[i], t[i+1]});
	printf("%d\n", (int)o.size());
	for (auto &p: o) printf("%d %d\n", p.first, p.second);
	return 0;
}

// 7190033	2014-07-21 06:11:43	delta_4d	C - Jzzhu and Apples	GNU C++0x	Accepted	280 ms	4400 KB
