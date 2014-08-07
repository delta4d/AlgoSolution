#include <bits/stdc++.h>
using namespace std;

map <int, vector<int>> e;
map <int, int> o;

int f(vector<int> &p) {
	int n = (int)p.size();
	if (n == 1) return 0;
	int d = p[1] - p[0];
	for (int i=0; i+1<n; ++i) if (p[i+1] - p[i] != d) return -1;
	return d;
}

int main() {
	int n, d;
	scanf("%d", &n);
	for (int i=0,x; i<n; ++i) scanf("%d", &x), e[x].push_back(i);
	for (auto &p: e) {
		d = f(p.second);
		if (d >= 0) o[p.first] = d;
	}
	printf("%d\n", (int)o.size());
	for (auto &p: o) printf("%d %d\n", p.first, p.second);
	return 0;
}

// 7351653	2014-08-05 14:44:45	delta_4d	B - Jeff and Periods	GNU C++0x	Accepted	186 ms	8900 KB
