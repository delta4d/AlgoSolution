#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<ll,ll> a[100];
int m, n;

int gao() {
	int k = m;
	for (; !(k&1); k>>=1) {
		for (int i=0; (i<<1)<k; ++i) if (a[i] != a[k-i-1]) return k;
	}
	return k;
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i=0; i<m; ++i) {
		ll x = 0, y = 0;
		for (int j=0,k; j<50&&j<n; ++j) scanf("%d", &k), x = x * 10 + k;
		for (int j=50,k; j<100&&j<n; ++j) scanf("%d", &k), y = y * 10 + k;
		a[i] = {x, y};
	}
	printf("%d\n", gao());
	return 0;
}

// 7243963	2014-07-25 20:26:51	delta_4d	B - Sereja and Mirroring	GNU C++0x	Accepted	15 ms	0 KB
