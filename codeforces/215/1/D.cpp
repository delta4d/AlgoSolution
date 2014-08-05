#include <bits/stdc++.h>
using namespace std;

int const N = 1 << 21;

bool v[N];
int a[N];
int c[32];
vector <int> mask;

int f() {
	int ret = 0;
	for (int i=0; i<30; ++i) if (c[i]) ret |= 1 << i;
	return ret;
}

int main() {
	int n, m, d;
	scanf("%d%d%d", &n, &m, &d);
	for (int i=1,t; i<=m; ++i) {
		scanf("%d", &t);
		for (int j=0,x; j<t; ++j) {
			scanf("%d", &x);
			a[x] = i;
		}
	}
	for (int i=0; i<d; ++i) ++c[a[i]];
	mask.push_back(f());
	for (int i=d; i<=n+1; ++i) {
		--c[a[i-d]], ++c[a[i]];
		mask.push_back(f());
	}
	int all = (1 << (m + 1)) - 1;
	for (auto mm: mask) v[mm^all] = true;
	for (int i=0; i<=m; ++i) for (int j=0; j<N; ++j) {
		if (j & 1 << i) v[j^1<<i] |= v[j];
	}
	int mn = m + 1;
	for (int i=0; i<=all; ++i) if (!v[i]) mn = min(mn, __builtin_popcount(i)-(i&1));
	printf("%d\n", mn);
	return 0;
}

// 7349550	2014-08-05 09:52:00	delta_4d	D - Sereja and Sets	GNU C++0x	Accepted	77 ms	11300 KB
