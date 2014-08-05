#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;

int a[N];
unordered_set <int> st;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i) scanf("%d", a+i);
	for (int i=n; i>0; --i) st.insert(a[i]), a[i] = (int)st.size();
	for (int x; m--; ) scanf("%d", &x), printf("%d\n", a[x]);
	return 0;
}

// 7343853	2014-08-04 14:18:18	delta_4d	B - Sereja and Suffixes	GNU C++0x	Accepted	62 ms	2800 KB
