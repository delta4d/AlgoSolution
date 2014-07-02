#include <bits/stdc++.h>
using namespace std;

int const N = 1 << 10;
int const P = 1e9;

char buf[N];
int t[N];
int p[N][30], q[N][30], nxt[N][30];
struct BigInt {
	int d[200], n;
	BigInt(int x=0) {
		memset(d, 0, sizeof(d));
		n = 1, d[0] = x;
	}
	void add(const BigInt &rhs) {
		int m = max(n, rhs.n);
		for (int i=0; i<m; ++i) d[i] += rhs.d[i];
		for (int i=0; i<m; ++i) d[i+1] += d[i] / P, d[i] %= P;
		for (n=m; d[n]>=P; ++n) d[n+1] += d[n] / P, d[n] %= P;
		for (; d[n]; ++n);
	}
	void out() {
		printf("%d", d[n-1]);
		for (int i=n-2; i>=0; --i) printf("%09d", d[i]);
		puts("");
	}
} f[70][N], tot;

int dfs(int s, int c) {
	if (nxt[s][c] != -1) return nxt[s][c];
	if (q[s][c] == 0) return nxt[s][c] = p[s][c];
	nxt[s][c] = 0;
	return nxt[s][c] = dfs(p[s][c], c);
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("dfa.in", "r", stdin);
	freopen("dfa.out", "w", stdout);
#endif
	int n, m, K, S, L;
	scanf("%s", buf);
	n = (int)strlen(buf);
	scanf("%d%d%d", &K, &S, &L);
	for (int i=0; i<L; ++i) scanf("%d", t+i);
	for (int i=1; i<=K; ++i) for (int j=1; j<=n; ++j) scanf("%d", p[i]+j);
	for (int i=1; i<=K; ++i) for (int j=1; j<=n; ++j) scanf("%d", q[i]+j);
	memset(nxt, -1, sizeof(nxt));
	for (int i=1; i<=K; ++i) for (int j=1; j<=n; ++j) dfs(i, j);
	scanf("%d", &m);
	f[0][S] = BigInt(1);
	for (int i=0; i<m; ++i) for (int j=1; j<=K; ++j) {
		for (int k=1; k<=n; ++k) if (nxt[j][k]) {
			f[i+1][nxt[j][k]].add(f[i][j]);
		}
	}
	for (int i=0; i<L; ++i) tot.add(f[m][t[i]]);
	tot.out();
	return 0;
}

// 6979093	 2014-06-29 12:25:07	delta_4d	 A - Non Absorbing DFA	 GNU C++0x	Accepted	216 ms	56940 KB
