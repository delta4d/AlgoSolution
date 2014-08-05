#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector <int> e;

int f(int n) {
	int ret = n * (n - 1) >> 1;
	if (n & 1) return ret + 1;
	return ret + (n >> 1);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=0,q,w; i<m; ++i) {
		scanf("%d%d", &q, &w);
		e.push_back(w);
	}
	sort(begin(e), end(e), greater<int>());
	int k = 1;
	for (; k<=m&&f(k)<=n; ++k); --k;
	ll sum = 0;
	for (int i=0; i<k; ++i) sum += e[i];
	printf("%I64d\n", sum);
	return 0;
}

// 7345024	2014-08-04 17:06:42	delta_4d	C - Sereja and the Arrangement of Numbers	GNU C++0x	Accepted	46 ms	1060 KB
