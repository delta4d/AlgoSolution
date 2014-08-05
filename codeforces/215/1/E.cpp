#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int const M = 1e9 + 7;
int const N = sqrt(1e5) + 3;

int f[2][N][N][2], p[N];

void init() {
	p[0] = 1;
	for (int i=1; i<N; ++i) p[i] = (ll)p[i-1] * i % M;
}

void add(int &x, int o) {
	x += o;
	if (x > M) x -= M;
}

int main() {
	int n, m, x;
	scanf("%d%d%d", &n, &m, &x);
	if (n > m) return puts("0"), 0;
	init();
	auto cur = f[0], nxt = f[1];
	cur[0][0][0] = 1;
	for (int i=0; i<m; ++i) {
		int y = i + 1;
		for (int j=0; j<=n; ++j) for (int k=0; k<=n; ++k) {
			int &a0 = cur[j][k][0], &a1 = cur[j][k][1];
			if (y == x) {
				add(nxt[j+1][k+1][1], a0);
				add(nxt[j+1][k][1], a0);
				add(nxt[j][k][0], a0);
				if (k) add(nxt[j][k-1][0], a0);
			} else {
				add(nxt[j+1][k+1][0], a0);
				add(nxt[j+1][k][0], a0);
				add(nxt[j][k][0], a0);
				if (k) add(nxt[j][k-1][0], a0);
				add(nxt[j+1][k+1][1], a1);
				add(nxt[j+1][k][1], a1);
				add(nxt[j][k][1], a1);
				if (k) add(nxt[j][k-1][1], a1);
			}
			a0 = 0, a1 = 0;
		}
		swap(cur, nxt);
	}
	int tot = (ll)cur[n][0][1] * p[n] % M;
	printf("%d\n", tot);
	return 0;
}

// 7350191	2014-08-05 11:43:01	delta_4d	E - Sereja and Intervals	GNU C++0x	Accepted	218 ms	1600 KB
