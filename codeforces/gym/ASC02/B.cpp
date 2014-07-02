#include <cstdio>
#include <cstring>
using namespace std;

using ll = unsigned long long;
int const N = 70;
ll const INF = 0x3f3f3f3f3f3f3f3fll;

ll f[N][N];
int g[N][N], st[N][N], sz[N];

void init() {
	for (int i=0; i<N; ++i) f[i][3] = (1ll << i) - 1, f[1][i] = 1;
	for (int i=2; i<N; ++i) for (int j=4; j<N; ++j) {
		ll &mn = f[i][j];
		int &id = g[i][j];
		mn = INF;
		for (int k=1; k<i; ++k) {
			ll cc = (f[k][j] << 1) + f[i-k][j-1];
			if (cc < mn) mn = cc, id = k;
		}
	}
	for (int i=0; i<N; ++i) g[i][3] = i - 1;
}

inline void move(int s, int t) {
	printf("move %d from %d to %d", st[s][sz[s]-1], s, t);
	if (sz[t]) printf(" atop %d", st[t][sz[t]-1]); puts("");
	st[t][sz[t]++] = st[s][--sz[s]];
}

inline int free_peg(int x, int y) {
	for (int i=1,t=st[x][sz[x]-1]; ; ++i) {
		if (i != x && i != y && (!sz[i] || t < st[i][sz[i]-1])) return i;
	}
}

void pp(int n, int m, int cur, int nxt) {
	if (n == 1) {
		move(cur, nxt);
	} else {
		int t = free_peg(cur, nxt), x = g[n][m];
		pp(x, m, cur, t);
		pp(n-x, m-1, cur, nxt);
		pp(x, m, t, nxt);
	}
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("hanoi.in", "r", stdin);
	freopen("hanoi.out", "w", stdout);
#endif
	init();
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%I64u\n", f[n][m]);
	memset(sz, 0, sizeof(sz));
	for (int i=n; i>=1; --i) st[1][sz[1]++] = i;
	pp(n, m, 1, m);
	return 0;
}

// 6977204	 2014-06-29 00:19:14	delta_4d	 B - The Towers of Hanoi Revisited	 GNU C++0x	Accepted	62 ms	236 KB
