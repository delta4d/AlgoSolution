#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000007;
const int N = 1 << 10;

char s1[N], s2[N];
int f[N][N], g[N][N];

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int gao(int l1, char s1[], int l2, char s2[]) {
	for (int i=1; i<=l1; ++i) for (int j=1; j<=l2; ++j) {
		if (s1[i] == s2[j]) {
			f[i][j] = f[i-1][j-1] + 1;
			g[i][j] = g[i-1][j-1];
		} else {
			f[i][j] = max(f[i-1][j], f[i][j-1]);
			if (f[i-1][j] != f[i][j-1]) {
				g[i][j] = f[i-1][j] > f[i][j-1] ? g[i-1][j] : g[i][j-1];
			} else {
				g[i][j] = g[i-1][j];
				add(g[i][j], g[i][j-1]);
				if (f[i-1][j-1] == f[i-1][j]) add(g[i][j], -g[i-1][j-1]);
			}
		}
	}
	return g[l1][l2];
}

inline void init() {
	for (int i=0; i<N; ++i) g[0][i] = g[i][0] = 1;
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s%s", s1+1, s2+1);
		printf("Case %d: %d\n", ++cn, gao(strlen(s1+1), s1, strlen(s2+1), s2));
	}
	return 0;
}

// 297083	2013-12-09 16:24:03	 1157 - LCS Revisited	 C++	 0.624	 9280	Accepted
